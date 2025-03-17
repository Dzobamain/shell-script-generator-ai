#include <stdio.h>
#include "file.h"

void SaveToFile(char* text)
{
    #ifdef _WIN32
        FILE *file = fopen("chat_history\\chat_history.txt", "a");
    #else
        FILE *file = fopen("chat_history/chat_history.txt", "a");
    #endif

    if (!file) {
        printf("Error: File opening failed\n");
        return;
    }

    fprintf(file, "%s\n", text);
    fclose(file);
}