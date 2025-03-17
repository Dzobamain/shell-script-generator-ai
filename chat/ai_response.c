#include "ai_response.h"
#include <Python.h>
#include <stdlib.h>

void PrintGeminiResponse(PyObject *pResult)
{
    if (!pResult) {
        printf("Error: No result returned from Python function\n");
        PyErr_Print();
        return;
    } 

    printf("\033[0;35mGemini: \033[0m%s\n", PyUnicode_AsUTF8(pResult));
}

char* GetGeminiResponse(PyObject *pResult)
{
    const char *result_str = PyUnicode_AsUTF8(pResult);
    if (!result_str) {
        printf("Error: Unable to convert Python object to UTF-8\n");
        PyErr_Print();
        return NULL;
    }

    char *result_copy = strdup(result_str);
    if (!result_copy) {
        printf("Error: Memory allocation for result failed\n");
        return NULL;
    }

    return result_copy;
}

