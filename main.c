#include <Python.h>
#include <stdlib.h>

#include "chat/ai_response.h"
#include "ai/send_to_gemini.h"
#include "chat/user_input.h"
#include "file/file.h"
#include "program_config.h"

int CheckInput(const char* text, const char* sumbol);

int main() 
{
    Py_Initialize();

    int isStart = 1;
    char* user_text;
    char* ai_text;

    while (isStart) {
        user_text = GetUserResponse();
        isStart = CheckInput(user_text, "q");
        if (isStart == 0)
            break;

        ai_text = SendToGemini(user_text);
        isStart = CheckInput(user_text, "q");
        PrintGeminiResponse(ai_text);

        SaveToFile(CHAT_HISTORY_PATH, user_text);
        SaveToFile(CHAT_HISTORY_PATH, ai_text);
    }
    ClearFile(CHAT_HISTORY_PATH);

    Py_Finalize();

    return 0;
}

int CheckInput(const char* text, const char* sumbol)
{
    int check = 1;

    if (text == NULL || strcmp(text, sumbol) == 0) {
        check = 0;
    }

    return check;
}