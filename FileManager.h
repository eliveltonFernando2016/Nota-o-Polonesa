/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FileManager.h
 * Author: elivelton
 *
 * Created on 27 de Novembro de 2016, 02:10
 */

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

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
FILE* newFile(char* arquivo);
void FileWriter(FILE* arquivo, float conteudo);
#endif /* FILEMANAGER_H */
