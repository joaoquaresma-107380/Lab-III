#include "string.h"
#include "stdio.h"
#include <Manager_Aeroportos.h>
#include <Manager_Reservas.h>
#include <Manager_Voos.h>
#include <gestorAeronave.h>
#include <gestorPassageiro.h>
#include <aeroportoParser.h>
#include <aeronaveParser.h>
#include <reservaParser.h>
#include <vooParser.h>
#include <passageirosParser.h>

int main(int argc,char args[]) {
    if(argc < 3){
        perror("Número de argumentos inválido!");
    }

    Manager_Reservas* reversas = createManagerReservas();
    Manager_Aeroportos* aeroportos = createManagerAeroportos();
    Manager_Voos* voos = createManager_Voos();
    gestorAviao* avioes = criarGestorAviao();
    gestorPassageiros* passageiros = createGestorPassageiros();
    
    return 0;
}
