#ifndef GESTOR_PASSAGEIRO_H
#define GESTOR_PASSAGEIRO_H

#include <glib.h>
#include "passageiro.h"

// Estrutura abstrata
typedef struct gestorPassageiros GestorPassageiros;

// Criação
GestorPassageiros* createGestorPassageiros();

// Destruiçao 
void destroiGestorPassageiros(GestorPassageiros *g);

// Operações 

void addPassageiro(GestorPassageiros *g, Passageiro *p);
Passageiro *encontrarPassageiro(GestorPassageiros *g, const char *doc);

#endif
