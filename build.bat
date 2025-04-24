@echo off
setlocal enabledelayedexpansion

set OUT=ssg.exe

set "CFLAGS=-IC:\Python312\include"
set "LDFLAGS=-LC:\Python312\libs -lpython312"

set SRC=

for /r %%f in (*.c) do (
    set "SRC=!SRC! %%f"
)

if "%SRC%"=="" (
    echo No .c files found.
    exit /b 1
)

gcc %SRC% %CFLAGS% %LDFLAGS% -o %OUT%
if errorlevel 1 (
    echo ❌ Build failed.
    exit /b 1
)

echo ✅ Build complete. Executable is: %OUT%
pause
