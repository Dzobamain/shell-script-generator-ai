#include <Python.h>
#include <iostream>
#include <string>

int main() {
    char text[] = "Hi gemini";

    Py_Initialize();

    PyRun_SimpleString("import sys; sys.path.append('.')");

    PyObject* moduleName = PyUnicode_DecodeFSDefault("ai.gemeini_client");
    PyObject* module = PyImport_Import(moduleName);
    Py_XDECREF(moduleName);

    if (module != nullptr) {
        PyObject* func = PyObject_GetAttrString(module, "get_chatgpt_response");

        if (func && PyCallable_Check(func)) {
            PyObject* arg = PyUnicode_FromString(text);

            PyObject* args = PyTuple_Pack(1, arg);
            Py_XDECREF(arg);

            PyObject* result = PyObject_CallObject(func, args);
            Py_XDECREF(args);

            if (result != nullptr) {
                const char* strResult = PyUnicode_AsUTF8(result);
                std::cout << strResult << std::endl;
                Py_XDECREF(result);
            } else {
                PyErr_Print();
            }

            Py_XDECREF(func);
        } else {
            PyErr_Print();
        }

        Py_XDECREF(module);
    } else {
        PyErr_Print();
    }

    Py_Finalize();

    return 0;
}
