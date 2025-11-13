#include "Util_Ficheiro.h"
#include "Queries.h"

#ifndef CMD_PARSER_H
#define CMD_PARSER_H

typedef struct cmd Cmd;

void processaComando(Manager_Aeroportos* aeroportos, GestorAviao* aeronaves, Manager_Voos* voos, Cmd* cmd, int n);
Cmd* parseLineCmd(char* line);
void readFileComandos(FILE* stream, Manager_Aeroportos* ma, Manager_Voos* mv, GestorAviao* mav);

#endif
