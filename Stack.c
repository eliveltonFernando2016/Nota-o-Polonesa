/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Stack.c
 * Author: elivelton
 *
 * Created on 27 de Novembro de 2016, 11:51
 */
#include "Stack.h"

//inicializa uma pilha
Stack* criaStack(int size){
    Stack* stack = (Stack*)calloc(1, sizeof(Stack));
    stack->tamanhoVet = size;
    stack->qtde = 0;
    stack->vetor = (float*)calloc(size, sizeof(float));

    return stack;
}

//insiro 1 item na pilha
void pushStack(Stack* p, float elemento){
    p->vetor[p->qtde++] = elemento;
}

//retira item do topo da pilha, e devolve o item
float popStack(Stack* p){
    float* e = (float*)calloc(1,sizeof(float));
    if(p->qtde == 0){
        return *e;
    }

    *e = p->vetor[p->qtde-1];
    p->qtde--;

    return *e;
}

//devolve uma cópia do valor do topo da pilha
float topStack(Stack* p){
    float* e = (float*)calloc(1,sizeof(float));
    if(p->qtde == 0){
        return *e;
    }

    *e = p->vetor[p->qtde-1];

    return *e;
}

//devolve o valor de itens na pilha
int StackSize(Stack* p){
    int qtde;
    qtde = p->qtde;
    return qtde;
}

//imprime a pilha
void printStack(Stack* p){
    int i;
    for(i=0; i < p->qtde; i++){
        printf("%f, ", p->vetor[i]);
    }
}