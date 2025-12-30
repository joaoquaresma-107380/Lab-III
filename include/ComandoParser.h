#include "Util_Ficheiro.h"
#include "Queries.h"

#ifndef CMD_PARSER_H
#define CMD_PARSER_H

typedef struct cmd Cmd;

char** parseLineQuerie(char* line);
void escreveOutput(char** resultados,Cmd* cmd, int n, int flagInterativo);
void processaComando(Manager_Aeroportos* aeroportos, GestorAviao* aeronaves, Manager_Voos* voos,  Manager_Reservas* gestorReservas, Cmd* cmd, int n, ListaContagem** aeronavesVoos, ListaContagem** airlinesAtrasos);
Cmd* parseLineCmd(char* line);
void readFileComandos(FILE* stream, Manager_Aeroportos* ma, GestorAviao* mav, Manager_Voos* mv, Manager_Reservas* gestorReservas, ListaContagem** aeronavesVoos, ListaContagem** airlinesAtrasos);

#endif
