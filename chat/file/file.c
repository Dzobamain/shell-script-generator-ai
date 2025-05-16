#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "file.h"

int FolderExists(const char *path) {
    struct stat info;

    if (stat(path, &info) != 0) {
        return 0;
    } 
    else if (info.st_mode & S_IFDIR) {
        return 1;
    } 
    else {
        return 0;
    }
}

void SaveToFile(const char* file_path, const char* text) {
    FILE *file = fopen(file_path, "a");

    if (!file) {
        printf("Error: File opening failed\n");
        return;
    }

    fprintf(file, "%s\n", text);
    fclose(file);
}

void ClearFile(const char* file_path) {
    FILE *file = fopen(file_path, "w");

    if (!file) {
        printf("Error: File opening failed\n");
        return;
    }

    fclose(file);
}