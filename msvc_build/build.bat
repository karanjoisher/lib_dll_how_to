@echo off

IF NOT EXIST build mkdir build
cd build

REM -------------------------------- Unity build ----------------------------------------------------------  
REM cl  -nologo /DPLATFORM_WINDOWS /DUNITY_BUILD /DCALL_CONVENTION_STDCALL ../../main.cpp /Femain_unity_build.exe
REM --------------------------------------------------------------------------------------------------------

REM ----------------------------------------- Link with static library ----------------------------------------------------------
REM call ../build_static_lib.bat
REM del vectors.dll
REM del vectors.lib
REM cl -nologo /DPLATFORM_WINDOWS /DCALL_CONVENTION_STDCALL ../../main.cpp  /Femain_static_lib_build.exe /link vectors_static.lib 
REM -----------------------------------------------------------------------------------------------------------------------------

REM ------------------------------------- Link with dll (def version) -------------------------------------------
REM del vectors.dll
REM del vectors.lib
REM call ../build_dll_using_def.bat
REM cl -nologo /DUSING_DLL /DPLATFORM_WINDOWS /DCALL_CONVENTION_STDCALL ../../main.cpp  /Femain_dll_def_build.exe 
REM -------------------------------------------------------------------------------------------------------------


REM ------------------------------------- Link with dll (declspec version) ----------------------------------------
REM This doesn't prevent name mangling when you use __stdcall convention
REM Better to use the def version in such case

REM del vectors.dll
REM del vectors.lib
REM call ../build_dll_using_declspec.bat
REM cl -nologo /DUSING_DLL /DPLATFORM_WINDOWS /DCALL_CONVENTION_CDECL ../../main.cpp  /Femain_dll_declspec_build.exe 
REM ----------------------------------------------------------------------------------------------------------------

cd ..