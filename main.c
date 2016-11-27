/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: elivelton
 *
 * Created on 19 de Novembro de 2016, 12:06
 */

#include "Tradutor.h"

void Gerador(FileScanner* fileScanner, char* NomeArquivo, int tipoServico){ //Gera uma tradução ou uma interpretação de expressão
    char* token;

    char* fileName = (char*)calloc(1, sizeof(char)*strlen(NomeArquivo));
    fileName = NomeArquivo;

    do{
        token = nextn(fileScanner);
        if(tipoServico == 1){
            FileWriter(fileName, PosFix(token));
        }
        else{
            FileWriter(fileName, Interpretador(token));
        }
        free(token);
    } while (hasNext(fileScanner));
}

int main() {
    FileScanner* fileScanner = newFileScanner("expressao.txt");

    Gerador(fileScanner, 1); //Para traduzir!

    newFile("ExpressaoTraduzida.txt");
    Gerador("ExpressaoTraduzida.txt", 2); // Para Interpretar!

    return (EXIT_SUCCESS);
}