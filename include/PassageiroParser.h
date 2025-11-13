
#include "Util_Ficheiro.h"
#include "UtilsParser.h"
#include "ValidacaoPassageiro.h"

#ifndef PASSAGEIRO_PARSER_H
#define PASSAGEIRO_PARSER_H

Passageiro* tokensToPassageiro (char** tokens);
void readFilePassageiro(FILE* stream, GestorPassageiros* mp);

#endif