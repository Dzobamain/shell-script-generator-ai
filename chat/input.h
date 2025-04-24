#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <stdlib.h>
#include <string.h>
#include <Python.h>

char* GetUserResponse();
int CheckInput(const char* text, const char* sumbol);

#endif // USER_INPUT_H