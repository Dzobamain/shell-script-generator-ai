#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

extern void SaveToFile(const char* file_path, const char* text);
extern void ClearFile(const char* file_path);
extern void SaveScriptToFile(const char *file_path, const char *sript_text);
extern int FolderExists(const char *path);


#endif // FILE_H