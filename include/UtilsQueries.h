#include "Manager_Aeroportos.h"
#include "Manager_Voos.h"
#include "Manager_Aeronaves.h"
#include "Manager_Passageiros.h"
#include "Manager_Reservas.h"

typedef struct listaContagem ListaContagem;

int procuraContagem(ListaContagem* ca,char* code);
void destruirLista(ListaContagem * l);
ListaContagem** criaAeronavesMaisVoos(GestorAviao* gestorAeronaves, Manager_Voos* gestorVoos);
ListaContagem** criaAirlinesMaisAtraso (Manager_Voos* gestorVoos);
