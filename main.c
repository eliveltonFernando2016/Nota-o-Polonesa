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

    while(hasNext(fileScanner)){
        token = nextn(fileScanner);
        inFix(token);
        free(token);
    }

    return (EXIT_SUCCESS);
}

