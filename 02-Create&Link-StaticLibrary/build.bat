echo off
cls
color 7

SET STATICLIB_DIR="StaticLibrary"
SET STATICLIB_BUILD=build-StaticLib.bat
SET PROJECT_DIR="Project"
SET PROJECT_BUILD=build-Project.bat

echo == BUILD Begin:
echo ===== BUILD STATIC_LIB
cd %STATICLIB_DIR%
call %STATICLIB_BUILD%
echo ===== BUILD PROJECT
cd ..\%PROJECT_DIR%
call %PROJECT_BUILD%
cd ..
echo on