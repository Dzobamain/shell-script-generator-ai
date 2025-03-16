#include <Python.h>
#include <stdlib.h>
#include <stdbool.h>

#include "chat/ai_response.h"
#include "ai/send_to_gemini.h"
#include "chat/user_input.h"

int main() 
{
    Py_Initialize();

    bool isStart = true;
    char* text;
    PyObject *pResult;

    while (isStart)
    {
        text = GetUserResponse();
        if (text == NULL || strcmp(text, "q") == 0) {
            isStart = false;
            break;
        }
        
        pResult = SendToGemini(text);
        PrintGeminiResponse(pResult);
    }

    Py_DECREF(pResult);
    free(text);

    Py_Finalize();

    return 0;
}

