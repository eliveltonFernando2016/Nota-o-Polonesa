#ifndef INFIX_H
#define INFIX_H

#include "Pilha.h"

void inFix(char* expressao);

void inFix(char* expressao){
    int i=0, aux=0, size=0;

    //verifica tamanho da expressão
    while (expressao[size] != '\0') {
        size++;
    }

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
            if(tamanhoPilha(pilha) == 0){ //verifica se a pilha está vazia, então empilha
                push(pilha, expressao[i]);
            }
            else{
                if(expressao[i] == '+' || expressao[i] == '-' || expressao[i] == '('){
                    if(top(pilha) == '+' || top(pilha) == '-'){ //verifica se no topo da pilha existe um item de mesma prioridade que na expressão
                        p[aux++] = pop(pilha);
                    }
                    push(pilha, expressao[i]);
                }
                else if(expressao[i] == ')'){
                    while (top(pilha) != '(') {
                        p[aux++] = pop(pilha);
                    }
                    pop(pilha);
                }
                else if(expressao[i] == '*' || expressao['/']){
                    if(top(pilha) == '*' || top(pilha) == '/'){ //verifica se no topo da pilha existe um item de mesma prioridade que na expressão
                        p[aux++] = pop(pilha);
                    }
                }
            }
        }
    }

    printf("%s", p);
}

#endif	// INFIX_H

