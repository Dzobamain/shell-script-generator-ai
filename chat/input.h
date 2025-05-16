#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <stdlib.h>
#include <string.h>
#include <Python.h>

extern char* GetUserResponse();
extern int CheckInput(const char* text, const char* sumbol);
extern char* GetScriptSavePath();

#endif // USER_INPUT_H