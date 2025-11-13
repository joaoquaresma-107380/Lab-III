
#include "ValidacaoAeronave.h"
#include "Util_Ficheiro.h"
#include "UtilsParser.h"

#ifndef AERONAVE_PARSER_H
#define AERONAVE_PARSER_H

Aeronave* tokensToAeronave (char** tokens);
void readFileAeronave(FILE* stream, GestorAviao* ma);

#endif