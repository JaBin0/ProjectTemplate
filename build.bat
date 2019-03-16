echo off
cls
color 7
echo ==== BUILD Begin ====

:config
REM ==== CONFIGURATION ====
SET EXE_NAME=Makak.exe
SET PATH=C:\My_MinGW\bin;%PATH%
REM SET PATH=c:\MinGW\bin;%PATH%

mkdir build

:build
REM ==== BUILD ====
SET OBJ= ^
src\main.cpp 

SET CFLAGS= ^
-std=c++11 ^
-w 

SET LFLAGS= 

echo on
g++ %OBJ% %CFLAGS% -o build\%EXE_NAME% %LFLAGS%
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
echo on