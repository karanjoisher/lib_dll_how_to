REM +------- Building a static LIB ----------------+

cl -nologo /c /DBUILD_STATIC_LIB /DPLATFORM_WINDOWS /DCALL_CONVENTION_STDCALL -nologo  ../../vectors.cpp
lib -nologo vectors.obj /out:vectors_static.lib