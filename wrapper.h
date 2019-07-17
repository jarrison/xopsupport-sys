/*This wrapper file is useful when not compiling on windows. */
typedef unsigned int DWORD;
typedef unsigned int UINT;
typedef void *PVOID;
typedef PVOID HANDLE;
typedef HANDLE HWND;
typedef HANDLE HMODULE;
typedef UINT *WPARAM;
typedef long LONG_PTR;
typedef LONG_PTR LPARAM;

typedef struct RECT {			// Windows RECT required for WinRectToMacRect and MacRectToWinRect in XOPSupport.c.
    long left;
    long top;
    long right;
    long bottom;
} RECT;

typedef struct _iobuf
{
    void* _Placeholder;
} FILE;

#define XOP_STANDARD_HEADERS 1
#define _IGORXOP_ 1
#define XOP_TOOLKIT_VERSION 703					// 703 means XOP Toolkit 7.03


#if (defined(_WIN32) || defined(_WIN64))
    #define WINIGOR			// Defined for 32-bit and 64-bit Igor on Macintosh
    #ifdef _WIN64
        #define IGOR64		// Defined for 64-bit Igor only
        #define WINIGOR64	// Defined for 64-bit Igor on Windows only
    #else
        #define IGOR32		// Defined for 32-bit Igor only
        #define WINIGOR32	// Defined for 32-bit Igor on Windows only
    #endif
#endif

#ifdef SetPort				// SetPort is defined in WinSpool.h
    #undef SetPort			// But we use SetPort in the Macintosh sense.
#endif
		
#define XOP_LITTLE_ENDIAN	// HR, 030130: Was LITTLE_ENDIAN but Apple stole that from us (see endian.h).

#undef DUPLICATE		// This is defined in XOP.h but also in NB30 for use with NetBios 3.0.

#ifdef __cplusplus
    #define HOST_EXPORT extern "C" __declspec(dllimport)	// Declares function or variable as being exported from IGOR to XOPs.
    #define HOST_IMPORT extern "C" __declspec(dllexport)	// Declares function or variable as being imported by IGOR from an XOP.
#else
    #define HOST_EXPORT __declspec(dllimport)				// Declares function or variable as being exported from IGOR to XOPs.
    #define HOST_IMPORT __declspec(dllexport)				// Declares function or variable as being imported by IGOR from an XOP.
#endif		

#include "WMTypes.h"		// Data types defined by WaveMetrics


#include "XOPWinMacSupport.h"

#include "IgorXOP.h"
#include "IgorErrors.h"
#include "XOP.h"
#include "XOPWindows.h"
#include "XOPContainers.h"
#include "XOPSupport.h"

#include "XOPSupportWin.h"



