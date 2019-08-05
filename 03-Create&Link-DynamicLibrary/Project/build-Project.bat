echo off
if NOT %ERROR_CODE% == 0 (
    echo ==== BUILD FAILD ==== 
    goto :end
) 

REM ==== CONFIGURATION ====
SET EXE_NAME=Project.exe
SET PATH=C:\My_MinGW\bin;%PATH%
REM SET PATH=c:\MinGW\bin;%PATH%
mkdir build

REM ==== BUILD ====
SET OBJ=^
src\main.cpp

SET CFLAGS=^
-std=c++14 ^
-w 

SET LFLAGS=^
-Isrc ^
-Llib\ ^
-lDynamicLib

echo on
g++ %CFLAGS% %OBJ% -o build\%EXE_NAME% %LFLAGS%

echo off
if NOT %errorlevel%==0 (
    color 4 
    echo ==== BUILD FAILD ==== 
    goto :end
)

color 2 
echo ==== BUILD SUCCESS ==== 
:run
REM ==== RUN PROGRAM ====
cd build
echo ==== RUN ====
echo.
%EXE_NAME%
echo.
echo ==== END ====

:end
echo off