#include <stdio.h>
#include "reserva.h"
#include "Manager_Reservas.h"
#include "Util_Ficheiro.h"
#include "utilsParser.h"

Reserva* tokensToReserva (char** tokens);
void readFileReserva(FILE* stream, Manager_Reservas* mr);