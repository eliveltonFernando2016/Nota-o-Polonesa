#ifndef TRADUTOR_H
#define TRADUTOR_H

#include "Pilha.h"
#include "Stack.h"

char* PosFix(char* expressao);

void Interpretador(FILE* file, char* expressao);
#endif	// TRADUTOR_H

