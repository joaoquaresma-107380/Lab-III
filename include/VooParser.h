
#include "ValidacaoVoo.h"
#include "Util_Ficheiro.h"
#include "UtilsParser.h"

#ifndef VOO_PARSER_H
#define VOO_PARSER_H

Voo* tokensToVoo (char** tokens);
void readFileVoo(FILE* stream, Manager_Voos* mv, GestorAviao* mae);

#endif