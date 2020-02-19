@echo off
title Source File Auto-Executable Program
color 0F

:runtime
set /p firstrun=<runtime.dfx
set /p mode=<config.dfx
if "%firstrun%"=="y" goto changelog
if "%firstrun%"=="n" goto start

:changelog
cls
type changelog.dfx
echo.
echo.
pause
if "%firstrun%"=="y" goto setup
cls
goto start

:setup
cls
echo Type (or paste) in the path for your compilers.
echo.
echo JAVA :
set /p dir="> "
echo %dir%>javac.dfx
echo.
echo C    :
set /p dir="> "
echo %dir%>gcc.dfx
echo.
echo C++  :
set /p dir="> "
echo %dir%>g++.dfx
echo n>runtime.dfx
goto start

:start
cls
type gui.dfx
echo.
echo.
echo  Last Command : %name%
echo  Current mode : %mode%
echo.
echo.

set /p name="> "
if "%name%"=="-l" goto changelog
if "%name%"=="-c" goto compile
if "%name%"=="-s" goto settings
if "%name%"=="-p" goto setup

goto run

:settings
cls
echo Current mode : %mode%
echo Type to change to another mode.
echo.
echo [1] : JAVA
echo [2] : C
echo [3] : C++
echo.
echo.
set /p change="> "

if "%change%"=="1" , set mode=JAVA
if "%change%"=="2" , set mode=C
if "%change%"=="3" , set mode=C++
echo %mode%>config.dfx
goto start

:compile
cls
echo Type the name of the file to compile.
echo.
echo Current mode : %mode%
echo.
echo.

set /p name="> "

if "%mode%"=="JAVA" goto javac
if "%mode%"=="C" goto gcc
if "%mode%"=="C++" goto g++

:run
cls
echo Type the arguments to supply your program (Multiple arguments are
echo separated by whitespace. Type a whitespace for no arguments).
echo.
echo.
set /p args="> "
if "%args%"==" " , set args=
if "%mode%"=="JAVA" goto java
if "%mode%"=="C" goto c
if "%mode%"=="C++" goto c++
goto start

:javac
set /p dir=<javac.dfx
set path=%dir%
cls
javac %name%.java
pause
cls
goto start

:java
cls
java %name% %args%
echo.
echo This is the end of your %name%.java
pause
cls
goto start

:g++
set /p dir=<g++.dfx
set path=%dir%
cls
g++ %name%.cpp -o %name%.exe
pause
cls
goto start

:c++
cls
%name%.exe %args%
echo.
echo This is the end of your %name%.exe
pause
cls
goto start

:gcc
set /p dir=<gcc.dfx
set path=%dir%
cls
echo Type in the name of your .exe file (Type a whitespace for default name).
echo.
set /p exe="> "
if "%exe%"==" ", set exe=%name%
gcc %name%.c -o %exe%.exe
pause
cls
goto start

:c
cls
%name%.exe %args%
echo.
echo This is the end of your %name%.exe
pause
cls
goto start