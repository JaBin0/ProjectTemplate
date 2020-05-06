echo off
cls
color 7
echo ==== BUILD Begin ====

:config
REM ==== CONFIGURATION ====
SET EXE_NAME=OpenGL-Engine.exe
SET PATH=C:\My_MinGW\bin;%PATH%
REM SET PATH=c:\MinGW\bin;%PATH%

mkdir build

REM Copy all assets
xcopy /I /Y libs\glfw3.dll build\
xcopy /E /I /Y assets build\assets

:build
REM ==== BUILD ====
SET OBJ=^
src\Game.cpp ^
src\OPPEngine\OOPEngine.cpp ^
external\glad\glad.c ^
src\Graphics\OGl.cpp ^
src\Assets\AssetLoader.cpp

SET CFLAGS=^
-std=c++14 ^
-w ^
-Isrc ^
-Isrc\OPPEngine ^
-Iexternal ^
-Isrc\Graphics ^
-Isrc\Assets ^
-Llibs

SET LFLAGS=^
-lopengl32 ^
-lglfw3dll

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