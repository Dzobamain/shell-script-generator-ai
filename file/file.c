#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

void SaveToFile(char* file_path, char* text)
{
    FILE *file = fopen(file_path, "a");

    if (!file) {
        printf("Error: File opening failed\n");
        return;
    }

    fprintf(file, "%s\n", text);
    fclose(file);
}

void ClearFile(char* file_path)
{
    FILE *file = fopen(file_path, "w");

    if (!file) {
        printf("Error: File opening failed\n");
        return;
    }

    fclose(file);
}