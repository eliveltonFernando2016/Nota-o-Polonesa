/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FileOutPut.h
 * Author: elivelton
 *
 * Created on 26 de Novembro de 2016, 22:32
 */

#ifndef FILEOUTPUT_H
#define FILEOUTPUT_H

#include "FileOutPut.h"

void FileOutPut(char* nomeArquivo, char* conteudo);

void FileOutPut(char* nomeArquivo, char* conteudo){
    FILE *file;
    
    file = fopen(nomeArquivo, "wt");
    
    if(file == NULL){
        printf("Problema na criação do arquivo!\n");
        return NULL;
    }

}
#endif /* FILEOUTPUT_H */

