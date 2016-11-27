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
    char teste;

    //declara p do tamanho da expressao, essa será minha variável de retorno
    char* p = (char*) calloc(1, (size*sizeof(char)));

    Pilha* pilha = criaPilha(size);
    
    //printf("Exp. Original: %s", expressao);

    while (expressao[i] != '\0'){
        if (isdigit(expressao[i])){
            p[aux++] = expressao[i];
        }
        else{
            if(expressao[i] == '('){ //empilha um '('
                push(pilha, expressao[i]);
            }
            else if(expressao[i] == '+' || expressao[i] == '-'){
                if(isdigit(p[aux-1])){ //verifica se há um número anterior e adiciona espaço.
                    p[aux++] = ' ';
                }
                if(top(pilha) == '+' || top(pilha) == '-'){ //verifica se no topo da pilha existe um item de mesma prioridade que na expressão
                    p[aux++] = pop(pilha);
                    if(p[aux-1] != ' '){ //verifica se há um espaço anterior e adiciona somente se não houver.
                        p[aux++] = ' ';
                    }
                }
                push(pilha, expressao[i]);
            }
            else if(expressao[i] == ')'){
                if(isdigit(p[aux-1])){ //verifica se há um número anterior e adiciona espaço.
                    p[aux++] = ' ';
                }
                while (top(pilha) != '(') { //desempilha todos os itens da pilha até encontrar o ')'
                    p[aux++] = pop(pilha);
                    if(p[aux-1] != ' '){ //verifica se há um número anterior e adiciona espaço.
                        p[aux++] = ' ';
                    }
                }
                pop(pilha);//retira o '(' da pilha
            }
            else if(expressao[i] == '*' || expressao[i] == '/'){
                if(isdigit(p[aux-1])){ //verifica se há um número anterior e adiciona espaço.
                    p[aux++] = ' ';
                }
                if(top(pilha) == '*' || top(pilha) == '/'){ //verifica se no topo da pilha existe um item de mesma prioridade que na expressão
                    p[aux++] = pop(pilha);
                    if(p[aux-1] != ' '){ //verifica se há um espaço anterior e adiciona somente se não houver.
                        p[aux++] = ' ';
                    }
                }
                push(pilha, expressao[i]);
            }
        }
        i++;
    }

    if(tamanhoPilha(pilha)){ //Verifica se ainda há mais itens na pilha.
        while (tamanhoPilha(pilha)) {
            if(p[aux-1] != ' '){ //verifica se há um espaço anterior e adiciona somente se não houver.
                p[aux++] = ' ';
            }
            if(top(pilha) != '('){
                p[aux++] = pop(pilha);
            }
        }
    }

    printf("%s\n", p);
}