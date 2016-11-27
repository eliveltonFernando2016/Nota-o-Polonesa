/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FileOutPut.c
 * Author: elivelton
 *
 * Created on 26 de Novembro de 2016, 23:53
 */
#include "FileOutPut.h"

FileScanner* newFileScanner(char* arquivo){
    FileScanner* fileScanner = (FileScanner*)calloc(1, sizeof(FileScanner));
    fileScanner->arquivo = fopen(arquivo,"r");
    if(!fileScanner->arquivo){
        printf("Erro na abertura do arquivo!");
        return NULL;
    }

    fileScanner->buffer = NULL;
    fileScanner->tamBufferToken = SIZE;

    return fileScanner;
}

char* nextn(FileScanner* leitor){
    char* Linha = (char*)calloc(1, sizeof(char)*MAX);

    while (!feof(leitor->arquivo)){
        fgets(Linha, MAX, leitor->arquivo);
        if(Linha) return Linha;
    }
}

int hasNext(FileScanner* leitor){
    while (!feof(leitor->arquivo)) {
        return 1;
    }

    return 0;
}
