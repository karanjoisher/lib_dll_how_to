REM +------------------------------- Building a DLL and Import LIB with __declspec(dllexport) ---------------------+
REM | You need to have `extern "C"` and `__cdecl` calling convention to avoid name mangling						| 																	  
REM +--------------------------------------------------------------------------------------------------------------+

cl -nologo  /LD /DBUILD_DLL /DPLATFORM_WINDOWS /DCALL_CONVENTION_CDECL ../../vectors.cpp