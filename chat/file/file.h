#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

void SaveToFile(char *file_path, char *text);
void ClearFile(char *file_path);
void SaveScriptToFile(char *file_path, char *sript_text);
int FolderExists(const char *path);


#endif // FILE_H