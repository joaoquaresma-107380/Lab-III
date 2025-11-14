#include "Util_Ficheiro.h"
#include "ValidacaoAeroporto.h"

#ifndef AEROPORTO_PARSER_H
#define AEROPORTO_PARSER_H

Aeroporto* tokensToAeroporto (char** tokens);
void readFileAeroporto(FILE* stream, Manager_Aeroportos* mae);

#endif