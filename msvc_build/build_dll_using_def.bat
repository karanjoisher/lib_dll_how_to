@echo off

REM +-------------------------------- Building a DLL and Import LIB using DEF file ----------------------------------+
REM | It helps us to give custom export names to the functions(useful for overloaded functions)                      |
REM | However it failed to export 'operator overloaded' functions													|
REM | On 64bit, the standard calling convention is __stdcall, which causes name mangling irrespective of 'extern "c"'|
REM | Thus on 64bit, DEF files can help avoid name mangling														  |
REM | However this approach is not portable, as the name mangling will change from compiler to compiler,or		   |	
REM | even between compiler versions. 																			   |							
REM +----------------------------------------------------------------------------------------------------------------+

cl -nologo /LD /DBUILD_DLL /DPLATFORM_WINDOWS /DCALL_CONVENTION_STDCALL ../../vectors.cpp /link /DEF:../export_interface.def





