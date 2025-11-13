#include "Manager_Voos.h"
#include "ValidacaoAeronave.h"

#ifndef VALIDACAO_VOO_H
#define VALIDACAO_VOO_H

int validarVooId(char* token);
int validacaoSintaticaVoo(char** tokens);
int validacaoLogicaVoo(char** tokens, GestorAviao* mae);
int validacaoVoo(char** tokens, GestorAviao* mae);

#endif