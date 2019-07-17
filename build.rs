use bindgen::builder;
use std::env;
use std::path::PathBuf;

fn main() {
    let root_dir = PathBuf::from(env::var("CARGO_MANIFEST_DIR").unwrap());
    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());
    let library_dir: PathBuf = root_dir.join("cxop");
    println!(
        "cargo:rustc-link-search=native={}",
        library_dir.to_str().unwrap()
    );
    println!("cargo:rustc-link-search=native=C:/Windows/System32");
    
    // Link the static XOPSupport and dynamically link the imported Igor functions.
    // Note: We also need to link in some standard windows libraries.
    println!("cargo:rustc-link-lib=dylib=version");
    println!("cargo:rustc-link-lib=dylib=Comdlg32");
    println!("cargo:rustc-link-lib=dylib=User32");
    println!("cargo:rustc-link-lib=static=XOPSupport64");
    println!("cargo:rustc-link-lib=dylib=IGOR64");

    // Stop the host from rebuilding when not needed.
    println!("cargo:rerun-if-changed=build.rs");
    let bindings = builder()
        .header("wrapper.h")
        .clang_args(vec!["-DWINIGOR","-DIGOR64","-D_WIN64","-xc++","-Icxop"])
        .detect_include_paths(true)
        .layout_tests(false)
        .ctypes_prefix("libc")
        .raw_line("use libc;")
        .generate()
        .expect("Failed to generate bindings.");
    //

    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .expect("Couldn't write bindings!");
}