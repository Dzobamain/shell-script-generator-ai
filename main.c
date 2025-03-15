#include <Python.h>
#include <stdlib.h>

#include "program_config.h"
#include "chat/ai_response.h"
#include "ai/send_to_gemini.h"

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
