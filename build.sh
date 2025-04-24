#!/bin/bash

OUT="ssg"

# Path to Python header and library files
CFLAGS="-I/Library/Frameworks/Python.framework/Versions/3.12/include/python3.12"
LDFLAGS="-L/Library/Frameworks/Python.framework/Versions/3.12/lib -lpython3.12"

SRC=$(find . -name "*.c")

if gcc $SRC $CFLAGS $LDFLAGS -o $OUT; then
    echo "Build complete. Executable is: $OUT"
else
    echo "❌ Build failed."
fi

