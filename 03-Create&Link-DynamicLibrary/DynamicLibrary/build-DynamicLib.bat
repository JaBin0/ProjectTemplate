echo off
color 7

REM xcopy:
REM   /Y - Suppress prompt to confirm overwriting a file.

REM ==== CONFIGURATION ====
SET LIB_NAME=DynamicLib.dll
SET PATH=C:\My_MinGW\bin;%PATH%
REM SET PATH=c:\MinGW\bin;%PATH%
mkdir build

REM ==== BUILD ====
SET SOURCE=src\DynamicLib.cpp 
SET OBJ=build\DynamicLib.o

SET CFLAGS=^
-std=c++14 ^
-w ^
-shared ^
-fPIC

SET LFLAGS=^
-Isrc

echo on
g++ %CFLAGS% %SOURCE% -o build\%LIB_NAME% %LFLAGS%

echo off
if NOT %errorlevel%==0 (
    color 4 
    SET ERROR_CODE=%errorlevel%
    echo ==== CREATING STATIC LIB - FAILD ==== 

    goto :end
)

echo ==== CREATING STATIC LIB - SUCCESS ==== 
echo on
xcopy /Y src\DynamicLib.h ..\Project\src\
xcopy /Y build\%LIB_NAME% ..\Project\lib\
xcopy /Y build\%LIB_NAME% ..\Project\build\
echo off

:end