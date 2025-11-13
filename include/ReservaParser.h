
#include "Util_Ficheiro.h"
#include "UtilsParser.h"
#include "ValidacaoReserva.h"

#ifndef RESERVA_PARSER_H
#define RESERVA_PARSER_H

Reserva* tokensToReserva (char** tokens);
void readFileReserva(FILE* stream, Manager_Reservas* mr, Manager_Voos* mv, GestorPassageiros* mp);

#endif