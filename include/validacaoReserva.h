#include "stdio.h"
#include "validacaoVoo.h"
#include "Manager_Voos.h"
#include "voo.h"
#include "Manager_Passageiros.h"


int validacaoSintaticaReserva(char** tokens);
int validacaoLogicaReserva(char** tokens, Manager_Voos* mv, Manager_Passageiros* mp);
int validacaoReserva(char** tokens, Manager_Voos* mv, Manager_Passageiros* mp);