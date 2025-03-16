#include "ai_response.h"

#include <Python.h>
#include <stdlib.h>

void PrintGeminiResponse(PyObject *pResult)
{
    if (pResult) {
        printf("\033[0;35mGemini: \033[0m%s\n", PyUnicode_AsUTF8(pResult));
        Py_DECREF(pResult);
    } else {
        printf("Error: No result returned from Python function\n");
        PyErr_Print();
    }
}