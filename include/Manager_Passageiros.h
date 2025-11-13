#include <glib.h>
#include "Passageiro.h"

#ifndef MANAGER_PASSAGEIROS_H
#define MANAGER_PASSAGEIROS_H

// Estrutura abstrata
typedef struct gestorPassageiros GestorPassageiros;

// Criação
GestorPassageiros* createGestorPassageiros();

// Destruiçao 
void destroiGestorPassageiros(GestorPassageiros *g);

// Operações 

void addPassageiro(GestorPassageiros *g, Passageiro *p);
Passageiro *encontrarPassageiro(GestorPassageiros *g, int doc);
void removePassageiro(Passageiro* a, GestorPassageiros* manager);

#endif
