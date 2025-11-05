#ifndef GESTORAERONAVE_H
#define GESTORAERONAVE_H

#include "aeronave.h"
#include <glib.h>

typedef struct gestorAviao GestorAviao;

// criaçao e destruiçao

GestorAviao* criarGestorAviao();
void destruirGestorAeronaves(GestorAviao* g);

// Operaçoes 

void addAviao(GestorAviao* g, Aeronave* a);
Aeronave* encontrarAviao(GestorAviao* g,const char* id);
GList * todasOsAvioes (GestorAviao *g);
void ordenarAvioesPorVoos(GList** lista);

#endif
