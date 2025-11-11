#include <stdio.h>
#include "passageiro.h"
#include "Manager_Passageiros.h"
#include "Util_Ficheiro.h"

Passageiro* tokensToPassageiro (char** tokens);
void readFilePassageiro(FILE* stream, Manager_Passageiros* mp);