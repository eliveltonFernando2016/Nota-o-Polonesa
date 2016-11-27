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

#include "FileManager.h"

typedef struct{
    char* vetor;
    int tamanhoVet; //Tamanho Total
    int qtde;       //Quantidade Atual
} Pilha;

Pilha* criaPilha(int size);
void push(Pilha* p, char elemento);
char pop(Pilha* p);
char top(Pilha* p);
int tamanhoPilha(Pilha* p);

#endif	// PILHA_H