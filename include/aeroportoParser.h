#include <stdio.h>
#include "aeroporto.h"
#include "Manager_Aeroportos.h"
#include "Util_Ficheiro.h"

Aeroporto* tokensToAeroporto (char** tokens);
void readFileAeroporto(FILE* stream, Manager_Aeroportos* mae);
