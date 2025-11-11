#ifndef CMD_PARSER_H
#define CMD_PARSER_H

#include <stdio.h>
#include "Manager_Aeroportos.h"
#include "Manager_Aeronaves.h"
#include "Manager_Voos.h"

typedef struct cmd {
    int comando;
    int* args; // NULL se nao houver
    int nargs; // numero de argumentos
} Cmd;

void processaCommando(Deque* deque, Cmd* cmd);

Cmd* parseLineCmd(char* line);

#endif