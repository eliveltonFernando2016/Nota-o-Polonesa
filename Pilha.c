/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pilha.c
 * Author: elivelton
 *
 * Created on 26 de Novembro de 2016, 23:48
 */
#include "Pilha.h"

//inicializa uma pilha
Pilha* criaPilha(int size){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));

    p->qtde = 0;
    p->tamanhoVet = size;
    p->vetor = (char*)calloc(size, sizeof(char*));

    return p;
}

//insiro 1 item na pilha
void push(Pilha* p, char elemento){
    p->vetor[p->qtde++] = elemento;
}

//retira item do topo da pilha, e devolve o item
char pop(Pilha* p){
    char* e = (char*)calloc(1,sizeof(char));
    if(p->qtde == 0){
        return *e;
    }

    *e = p->vetor[p->qtde-1];
    p->qtde--;

    return *e;
}

//devolve uma cópia do valor do topo da pilha
char top(Pilha* p){
    char* e = (char*)calloc(1,sizeof(char));
    if(p->qtde == 0){
        return *e;
    }

    *e = p->vetor[p->qtde-1];

    return *e;
}

//devolve o valor de itens na pilha
int tamanhoPilha(Pilha* p){
    int qtde;
    qtde = p->qtde;
    return qtde;
}

//imprime a pilha
void printPilha(Pilha* p){
    int i;
    for(i=0; i < p->qtde; i++){
        printf("%c, ", p->vetor[i]);
    }
}