#ifndef CMD_PARSER_H
#define CMD_PARSER_H

#include <stdio.h>
#include "Manager_Aeroportos.h"
#include "Manager_Aeronaves.h"
#include "Manager_Voos.h"
#include "Queries.h"
#include "Data.h"

typedef struct cmd {
    int comando;
    char** args; // NULL se nao houver
    int nargs; // numero de argumentos
} Cmd;

void processaCommando(Manager_Aeroportos* aeroportos, GestorAviao* aeronaves, Manager_Voos* voos, Cmd* cmd, File* resultados);
Cmd* parseLineCmd(char* line);
void readFileComandos(FILE* stream, Manager_Aeroportos* ma, Manager_Voos* mv, GestorAviao* mav);

#endif
