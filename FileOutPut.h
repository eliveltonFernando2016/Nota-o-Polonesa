#ifndef FILESCANNER_H
#define FILESCANNER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 50
#define MAX 100

typedef struct{
    FILE *arquivo;
    char* buffer;
    int tamBufferToken;
}FileScanner;

//PROTOTIPOS
FileScanner* newFileScanner(char* arquivo);
char* nextn(FileScanner* leitor);
int hasNext(FileScanner* leitor);

#endif	// FILESCANNER_H

