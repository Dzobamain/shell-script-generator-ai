#include <stdlib.h>
#include <string.h>
#include <Python.h>
#include "input.h"
#include "../program_config.h"
#include "file/file.h"

char* GetUserResponse() {
    char* text = (char*)malloc(LENGHT_USER_TEXT * sizeof(char));
    if (!text) {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }

    printf("\033[0;34mUser: \033[0m");
    fgets(text, LENGHT_USER_TEXT, stdin);
    text[strcspn(text, "\n")] = '\0';

    return text;
}

char* GetScriptSavePath() {
    char* text = (char*)malloc(LENGHT_USER_TEXT * sizeof(char));
    if (!text) {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }

    printf("\033[0;31mEnter where to save the script: \033[0m");
    if (fgets(text, LENGHT_USER_TEXT, stdin) == NULL) {
        free(text);
        return NULL;
    }
    text[strcspn(text, "\n")] = '\0';

    if (!FolderExists(text)) {
        printf("Folder does not exist.\n");
        free(text);
        return NULL;
    }

    return text;
}

int CheckInput(const char* text, const char* sumbol) {
    int check = 1;

    if (text == NULL || strcmp(text, sumbol) == 0) {
        check = 0;
    }

    return check;
}