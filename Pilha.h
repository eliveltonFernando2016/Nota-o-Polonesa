/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pilha.h
 * Author: elivelton
 *
 * Created on 19 de Novembro de 2016, 12:23
 */
#ifndef PILHA_H
#define PILHA_H

#include "FileScanner.h"

typedef struct{
    char* vetor;
    int tamanhoVet; //Tamanho Total
    int qtde;       //Quantidade Atual
} Pilha;

Pilha* criaPilha(int size);
int push(Pilha* p, char elemento);
char* pop(Pilha* p);
char* top(Pilha* p);
int tamanhoPilha(Pilha* p);

//inicializa uma pilha
Pilha* criaPilha(int size){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));

    p->qtde = 0;
    p->tamanhoVet = size;
    p->vetor = (char*)calloc(10, sizeof(char*));

    return p;
}

//insiro 1 item na pilha
int push(Pilha* p, char elemento){
     /*char* e = (char*)malloc(sizeof(char));
    *e = elemento;*/
    p->vetor[p->qtde++] = elemento;

    return 1;
}

//retira item do topo da pilha, e devolve o item
char* pop(Pilha* p){
    if(p->qtde == 0){
        return NULL;
    }

    char* e = (char*)calloc(1, sizeof(char));
    *e = p->vetor[p->qtde];

    p->qtde--;

    return e;
}

//devolve uma cópia do valor do topo da pilha
char* top(Pilha* p){
    if(p->qtde == 0){
        return NULL;
    }

    char* e = (char*)calloc(1, sizeof(char));
    *e = p->vetor[p->qtde];

    return e;
}

//devolve o valor de itens na pilha
int tamanhoPilha(Pilha* p){
    int qtde;
    qtde = p->qtde;
    return qtde;
}

#endif	// PILHA_H

