#include "ai_response.h"
#include <Python.h>
#include <stdlib.h>

void PrintGeminiResponse(const char *ai_text) {
    if (!ai_text) {
        printf("Error: Not text\n");
        PyErr_Print();
        return;
    } 

    printf("\033[0;35mGemini: \033[0m%s", ai_text);
}

