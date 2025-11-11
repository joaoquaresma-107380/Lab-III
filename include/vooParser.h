#include <stdio.h>
#include "voo.h"
#include "Manager_Voos.h"
#include "Util_Ficheiro.h"

Voo* tokensToVoo (char** tokens);
void readFileVoo(FILE* stream, Manager_Voos* mv);