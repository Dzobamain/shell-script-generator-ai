#include <Python.h>
#include <stdlib.h>

#include "program_config.h"

PyObject* SendToGemini(char* text);
void PrintGeminiResponse(PyObject *pResult);

int main() 
{
    Py_Initialize();

    char* text = (char*)malloc(LENGHT_USER_TEXT * sizeof(char));
    if (!text) {
        printf("Error: Memory allocation failed\n");
        Py_Finalize();
        return 1;
    }

    printf("User: ");
    fgets(text, LENGHT_USER_TEXT, stdin);
    text[strcspn(text, "\n")] = '\0';

    PyObject *pResult = SendToGemini(text);
    PrintGeminiResponse(pResult);

    free(text);
    Py_Finalize();

    return 0;
}

PyObject* SendToGemini(char* text) 
{
    if (!Py_IsInitialized()) {
        printf("Error: Python is not initialized\n");
        return NULL;
    }

    PyRun_SimpleString("import sys; sys.path.append('.')");

    PyObject *pText = Py_BuildValue("s", text);
    if (!pText) {
        PyErr_Print();
        return NULL;
    }

    PyObject *pModule = PyImport_ImportModule("ai.gemini_client");
    if (!pModule) {
        PyErr_Print();
        Py_DECREF(pText);
        return NULL;
    }
    
    PyObject *pFunc = PyObject_GetAttrString(pModule, "get_gemini_response");
    if (!pFunc || !PyCallable_Check(pFunc)) {
        PyErr_Print();
        Py_DECREF(pModule);
        Py_DECREF(pText);
        return NULL;
    }

    PyObject *pArgs = PyTuple_Pack(1, pText);
    Py_DECREF(pText);
    if (!pArgs) {
        PyErr_Print();
        Py_DECREF(pFunc);
        Py_DECREF(pModule);
        return NULL;
    }

    PyObject *pResult = PyObject_CallObject(pFunc, pArgs);
    Py_DECREF(pArgs);
    Py_DECREF(pFunc);
    Py_DECREF(pModule);

    if (!pResult) {
        PyErr_Print();
    }

    return pResult;
}

void PrintGeminiResponse(PyObject *pResult)
{
    if (pResult) {
        printf("GEMINI: %s\n", PyUnicode_AsUTF8(pResult));
        Py_DECREF(pResult);
    } else {
        printf("Error: No result returned from Python function\n");
        PyErr_Print();
    }
}
