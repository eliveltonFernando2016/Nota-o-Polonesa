/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tradutor.c
 * Author: elivelton
 *
 * Created on 26 de Novembro de 2016, 23:58
 */
#include "Tradutor.h"

void PosFix(char* expressao){
    int i=0, aux=0, size=strlen(expressao);

    //declara p do tamanho da expressao, essa será minha variável de retorno
    char* p = (char*) calloc(1, (size*sizeof(char)));

    Pilha* pilha = criaPilha(size);

    while (expressao[i] != '\0'){
        if (expressao[i] == '0' ||
            expressao[i] == '1' ||
            expressao[i] == '2' ||
            expressao[i] == '3' ||
            expressao[i] == '4' ||
            expressao[i] == '5' ||
            expressao[i] == '6' ||
            expressao[i] == '7' ||
            expressao[i] == '8' ||
            expressao[i] == '9'){
                p[aux++] = expressao[i];
        }
        else{
            if(expressao[i] == '('){ //empilha um '('
                push(pilha, expressao[i]);
            }
            else if(expressao[i] == '+' || expressao[i] == '-'){
                if(top(pilha) == '+' || top(pilha) == '-'){ //verifica se no topo da pilha existe um item de mesma prioridade que na expressão
                    p[aux++] = pop(pilha);
                }
                push(pilha, expressao[i]);
            }
            else if(expressao[i] == ')'){
                while (top(pilha) != '(' && tamanhoPilha(pilha) > 0) { //desempilha todos os itens da pilha até encontrar o ')'
                    p[aux++] = pop(pilha);
                }
                pop(pilha);//retira o '(' da pilha
            }
            else if(expressao[i] == '*' || expressao['/']){
                if(top(pilha) == '*' || top(pilha) == '/'){ //verifica se no topo da pilha existe um item de mesma prioridade que na expressão
                    p[aux++] = pop(pilha);
                }
                push(pilha, expressao[i]);
            }
        }
        i++;
    }

    if(tamanhoPilha(pilha)){ //Verifica se ainda há mais itens na pilha.
        while (tamanhoPilha(pilha)) {
            p[aux++] = pop(pilha);
        }
    }

    printf("%s\n", p);
}

