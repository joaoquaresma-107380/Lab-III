// Ficheiro Util_Ficheiro.h

#include <stdio.h>

#ifndef Util_Ficheiro_H
#define Util_Ficheiro_H

FILE* abrirFicheiroLeitura(const char* filename);
FILE* abrirFicheiroEscrita(const char* filename)
void fecharFicheiro(FILE* stream);

#endif 
