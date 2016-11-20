#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50;

typedef struct{
    FILE *arquivo;
    char* buffer;
    int tamBufferToken;
}FileScanner;

//PROTOTIPOS
FileScanner* newFileScanner(char* arquivo);
char* nextn(FileScanner* leitor);
int hasNext(FileScanner* leitor);

//IMPLEMENTACAO
FileScanner* newFileScanner(char* arquivo){
    FileScanner* fileScanner = (FileScanner*)calloc(1, sizeof(FileScanner));
    fileScanner->arquivo = fopen(arquivo,"r");
    if(!fileScanner->arquivo){
        return NULL;
    }

    fileScanner->buffer = NULL;
    fileScanner->tamBufferToken = SIZE;

    return fileScanner;
}

char* nextn(FileScanner* leitor){
    char c;
    int i=0;
    char* palavra = (char*)calloc(leitor->tamBufferToken, sizeof(char));

    while (!feof(leitor->arquivo) && c != '\n') {
        c = getc(leitor->arquivo);
        palavra[i++] = c;
    }

    i = i-2;

    palavra[i] = '\0';
    char* token = (char*) calloc(i+1, sizeof(char));
    strcpy(token, palavra);
    free(palavra);
    return token;
}

int hasNext(FileScanner* leitor){
    while (!feof(leitor->arquivo)) {
        return 1;
    }

    return 0;
}