#include "stdio.h"
#include "Data.h"
#include "Manager_Aeronaves.h"

int validarVooId(char* token);
int validacaoSintaticaVoo(char** tokens);
int validacaoLogicaVoo(char** tokens, Manager_Aeronaves* mae);
int validacaoVoo(char** tokens, Manager_Aeronaves* mae);