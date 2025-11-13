#include "Manager_Reservas.h"
#include "ValidacaoVoo.h"
#include "ValidacaoPassageiro.h"

#ifndef VALIDACAO_RESERVA_H
#define VALIDACAO_RESERVA_H

int tamanhoArrayFlights(char* token);
char** tokenToArrayChar(char* token);
int validacaoSintaticaReserva(char** tokens);
int validacaoLogicaReserva(char** tokens, Manager_Voos* mv, GestorPassageiros* mp);
int validacaoReserva(char** tokens, Manager_Voos* mv, GestorPassageiros* mp);

#endif