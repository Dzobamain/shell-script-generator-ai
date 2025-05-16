#include "send_to_gemini.h"

#include <Python.h>

char* SendToGemini(const char* text) {
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