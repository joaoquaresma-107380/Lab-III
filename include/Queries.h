#include "UtilsQueries.h"

#ifndef QUERIES_H
#define QUERIES_H

char** querie1 (Manager_Aeroportos *gestorAeroportos, Manager_Reservas* gestorReservas, const char *codigo);

char** querie2(GestorAviao* gestorAeronaves, Manager_Voos* gestorVoos,int n, const char* fabricante, ListaContagem** contaAeronaves);

char** querie3 (Manager_Voos* gestorVoos,Manager_Aeroportos* gestorAeroportos,Data* dataInicio,Data* dataFim);

char** querie5 (Manager_Voos* gestorVoos, int n, ListaContagem* contaAirlines);

char** querie6 (Manager_Reservas* gestorReservas, char* nationality);

#endif 
