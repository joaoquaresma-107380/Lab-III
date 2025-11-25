#include "Manager_Aeroportos.h"
#include "Manager_Voos.h"
#include "Manager_Aeronaves.h"
#include "Manager_Passageiros.h"

#ifndef QUERIES_H
#define QUERIES_H

typedef struct listaContagem ListaContagem;

void querie1 (Manager_Aeroportos *gestorAeroportos, const char *codigo , FILE *output);

void querie2(GestorAviao *gestorAeronaves, Manager_Voos *gestorVoos, int n, const char* fabricante, FILE *output);

int procuraContagem(ListaContagem* ca,char* code);
void destruirLista(ListaContagem * l);

void querie3 (Manager_Voos* gestorVoos,Manager_Aeroportos* gestorAeroportos,Data* dataInicio,Data* dataFim,FILE* output);

#endif 
