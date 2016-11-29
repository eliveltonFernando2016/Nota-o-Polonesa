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

char* PosFix(char* expressao){
    int i=0, aux=0, size=strlen(expressao);

    //declara p do tamanho da expressao, essa será minha variável de retorno
    char* p = (char*) calloc(1, (size*sizeof(char)));

    Pilha* pilha = criaPilha(size);

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
    
    //printf("%s\n", p);

    return p;
}

float Interpretador(char* expressao){
    Stack* stack = criaStack(strlen(expressao));
    char* p = (char*)calloc(1, sizeof(char)*strlen(expressao));
    char* charConcat = (char*)calloc(1, sizeof(char)*2);
    char* charAux = (char*)calloc(1, sizeof(char));

    float operacaoAux1 = 0, operacaoAux2 = 0;
    int i=0, aux=0, espaco=0;

    while (expressao[i] != '\0') {
        if(expressao[i] == ' '){//Se caso houver um espaço entre os caracter seta a variavel espaço para 1"true"
            espaco = 1;
        }
        else if(isdigit(expressao[i])){
            if(espaco){ //Se caso o espaço for verdadeiro quer dizer que não é um número é de somente 1 digito ou menor que 9
                if(charConcat != NULL){//Se o charConcat não estiver vazio ele esvazia adicionando conteúdo na pilha e esvaziando a variavel.
                    pushStack(stack, atof(charConcat));
                    charConcat = NULL;
                }
                charAux[0] = expressao[i];
                pushStack(stack, atof(charAux));
                espaco = 0;
            }
            else{//Se caso houver 2 ou mais numeros juntos sem espaço entre eles adiciono na variavel charConcat.
                charConcat[aux++] = expressao[i];
            }
        }
        else if(expressao[i] == '+'){
            operacaoAux1 = popStack(stack);
            operacaoAux2 = popStack(stack);

            operacaoAux1 += operacaoAux2;
            pushStack(stack, operacaoAux1);
        }
        else if(expressao[i] == '-'){
            operacaoAux1 = popStack(stack);
            operacaoAux2 = popStack(stack);

            operacaoAux2 -= operacaoAux1;
            pushStack(stack, operacaoAux2);
        }
        else if(expressao[i] == '*'){
            operacaoAux1 = popStack(stack);
            operacaoAux2 = popStack(stack);

            operacaoAux1 *= operacaoAux2;
            pushStack(stack, operacaoAux1);
        }
        else if(expressao[i] == '/'){
            operacaoAux1 = popStack(stack);
            operacaoAux2 = popStack(stack);

            operacaoAux2 /= operacaoAux1;
            pushStack(stack, operacaoAux2);
        }
        i++;
    }
    
    float res = popStack(stack);

    free(stack);
    free(charConcat);
    free(charAux);

    return res;
}