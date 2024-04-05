@echo off

REM Set variables
set CXX=g++
set CXXFLAGS=-Wall -g
set TARGET=main
set OBJS=main.o

REM Compilation and linking commands
if "%1"=="all" goto :all
if "%1"=="clean" goto :clean
echo Invalid argument. Use 'all' or 'clean'.
goto :end

:all
echo Building target...
%CXX% %CXXFLAGS% -c main.cpp
%CXX% %CXXFLAGS% -o %TARGET% %OBJS%
goto :end

:clean
echo Cleaning...
del main.o
del %TARGET%
goto :end

:end
