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

#include "infix.h"

int main() {
    FileScanner* fileScanner = newFileScanner("expressao.txt");

    char* token;

    do{
        token = nextn(fileScanner);
        //inFix(token);
        printf("%s", token);
        free(token);
        //printf("entrei main!\n");
    }
    while(hasNext(fileScanner));

    return (EXIT_SUCCESS);
}

