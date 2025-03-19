#include <Python.h>
#include <stdlib.h>
#include <stdbool.h>

#include "chat/ai_response.h"
#include "ai/send_to_gemini.h"
#include "chat/user_input.h"
#include "chat_history/file.h"
#include "program_config.h"

int main() 
{
    Py_Initialize();

    bool isStart = true;
    char* user_text;
    char* ai_text;

    PyObject *pResult;

    while (isStart)
    {
        user_text = GetUserResponse();

        if (user_text == NULL || strcmp(user_text, "q") == 0) {
            isStart = false;
            break;
        }

        pResult = SendToGemini(user_text);
        ai_text = GetGeminiResponse(pResult);
        PrintGeminiResponse(pResult);

        if (ai_text == NULL) {
            isStart = false;
            break;
        }

        SaveToFile(CHAT_HISTORY_PATH, user_text);
        SaveToFile(CHAT_HISTORY_PATH, ai_text);
    }

    ClearFile(CHAT_HISTORY_PATH);

    Py_DECREF(pResult);
    free(ai_text);
    free(user_text);

    Py_Finalize();

    return 0;
}

