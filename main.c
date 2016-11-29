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

    do{
        token = nextn(fileScanner);

        if(tipoServico == 1){
            fprintf(file, "%s\n", PosFix(token)); //chama a função FileWriter que escreve as informações em um novo arquivo,
                                                                               //tem como parametros um arquivo onde está sendo passado o newFile que cria um novo arquivo e o devolve,
                                                                               //e o conteúdo a ser gravado no arquivo, no caso Posfix que pega a expressão padrão e transforma para pós-fixada.
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
    /*FileScanner* fileScanner = newFileScanner("expressao.txt");
    Gerador(fileScanner, 1);
    free(fileScanner);*/

    // Para Interpretar!
    FileScanner* fileScanner2 = newFileScanner("ExpressaoTraduzida.txt");
    Gerador(fileScanner2, 2);
    free(fileScanner2);

    return (EXIT_SUCCESS);
}