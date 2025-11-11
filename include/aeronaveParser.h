#include <stdio.h>
#include "aeronave.h"
#include "Manager_Aeronaves.h"
#include "Util_Ficheiro.h"
#include "utilsParser.h"

Aeronave* tokensToAeronave (char** tokens);
void readFileAeronave(FILE* stream, Manager_Aeronaves* ma);