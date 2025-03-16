@echo off
set OUT=program.exe

:: Path to Python header and library files
set CFLAGS=-I"C:\Python312\include"
set LDFLAGS=-L"C:\Python312\libs" -lpython312

for /r %%f in (*.c) do (
    set SRC=%%f
)

if not defined SRC (
    echo No .c files found.
    exit /b 1
)

gcc %CFLAGS% %LDFLAGS% %SRC% -o %OUT%

echo Build complete. Executable is: %OUT%
pause
