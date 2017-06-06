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

//Gera uma tradução ou uma interpretação de expressão
void Gerador(FileScanner* fileScanner, int tipoServico){
    char* token;

    FILE* file;
    if(tipoServico == 1){
        file = fopen("ExpressaoTraduzida.txt", "w");
    }
    else{
        file = fopen("Resultado.txt", "w");
    }

    if (file == NULL) {
        printf("Erro ao abrir arquivo!\n");
    }

    do{
        token = nextn(fileScanner);

        if(tipoServico == 1){
            fprintf(file, "%s\n", PosFix(token));
        }
        else{
            fprintf(file, "%f\n", Interpretador(token));
        }

        free(token);
    } while (hasNext(fileScanner));
    fclose(file);
}

int main() {
    //Para traduzir!
    FileScanner* fileScanner = newFileScanner("expressao.txt");
    Gerador(fileScanner, 1);
    free(fileScanner);

    // Para Interpretar!
    FileScanner* fileScanner2 = newFileScanner("ExpressaoTraduzida.txt");
    Gerador(fileScanner2, 2);
    free(fileScanner2);

    return (EXIT_SUCCESS);
}