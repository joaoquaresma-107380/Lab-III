#include "Aeronave.h"
#include <glib.h>

#ifndef MANAGER_AERONAVES_H
#define MANAGER_AERONAVES_H

typedef struct gestorAviao GestorAviao;

// criaçao e destruiçao

GestorAviao* criarGestorAviao();
void destruirGestorAeronaves(GestorAviao* g);

// Operaçoes 

void addAviao(GestorAviao* g, Aeronave* a);
Aeronave* encontrarAviao(GestorAviao* g,char* id);
GList * todasOsAvioes (GestorAviao *g);
GList * ordenarAvioesPorVoos(GList* lista);
void removeAeronave(Aeronave* a, GestorAviao* manager);

#endif
