#include <Python.h>
#include <stdlib.h>
#include <stdbool.h>

#include "chat/ai_response.h"
#include "ai/send_to_gemini.h"
#include "chat/user_input.h"


int main() 
{
    Py_Initialize();

    char* text;

    text = GetUserResponse();

    PyObject *pResult = SendToGemini(text);
    PrintGeminiResponse(pResult);
    Py_DECREF(pResult);

    free(text);
    Py_Finalize();

    return 0;
}