echo off

REM Used commands and parameters
REM ar rcs:
REM   r - Insert the files member... into archive (with replacement). This operation differs from q in that any,    
REM     previously existing members are deleted if their names match those being added. By default, new members 
REM     are added at the end of the file, but you may use one of the modifiers a, b, or i to request placement
REM     relative to some existing member.
REM   c - Create the archive. The specified archive is always created if it did not exist, when you request an update.
REM     But a warning is issued unless you specify in advance that you expect to create it, by using this modifier.
REM   s - Write an object-file index into the archive, or update an existing one, even if no other change
REM     is made to the archive. You may use this modifier flag either with any operation, or alone.
REM     Running ar s on an archive is equivalent to running ranlib on it.
REM xcopy:
REM   /Y - Suppress prompt to confirm overwriting a file.

REM ==== CONFIGURATION ====
SET LIB_NAME=libStaticLib.a
SET PATH=C:\My_MinGW\bin;%PATH%
REM SET PATH=c:\MinGW\bin;%PATH%
mkdir build

REM ==== BUILD ====
SET SOURCE=src\StaticLib.cpp 
SET OBJ=build\StaticLib.o

SET CFLAGS=^
-std=c++14 ^
-w 

SET LFLAGS=

echo on
g++ %CFLAGS% -c %SOURCE% -o %OBJ% -Isrc
ar rcs build\%LIB_NAME% %OBJ% %LFLAGS%

echo off
if NOT %errorlevel%==0 (
    color 4 
    echo ==== CREATING STATIC LIB - FAILD ==== 
    goto :end
)

echo ==== CREATING STATIC LIB - SUCCESS ==== 
echo on
xcopy /Y src\StaticLib.h ..\Project\src\
xcopy /Y build\%LIB_NAME% ..\Project\lib\
echo off

:end