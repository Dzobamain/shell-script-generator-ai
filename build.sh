#!/bin/bash

OUT="program.out"

# Path to Python header and library files
CFLAGS="-I/Library/Frameworks/Python.framework/Versions/3.12/include/python3.12"
LDFLAGS="-L/Library/Frameworks/Python.framework/Versions/3.12/lib -lpython3.12"

SRC=$(find . -name "*.c")

gcc $SRC $CFLAGS $LDFLAGS -o $OUT

echo "Build complete. Executable is: $OUT"
