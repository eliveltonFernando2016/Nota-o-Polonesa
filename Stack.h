/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Stack.h
 * Author: elivelton
 *
 * Created on 27 de Novembro de 2016, 11:50
 */
#ifndef STACK_H
#define STACK_H

#include "FileManager.h"

typedef struct{
    float* vetor;
    int tamanhoVet;
    int qtde;
} Stack;

Stack* criaStack(int size);
void pushStack(Stack* p, float elemento);
float popStack(Stack* p);
float topStack(Stack* p);
int StackSize(Stack* p);
void printStack(Stack* p);

#endif /* STACK_H */

