#include "string.h"
#include "stdio.h"
#include <aeroportoParser.c>
#include <aeronaveParser.c>
#include <reservaParser.c>
#include <vooParser.c>
#include <passageirosParser.c>

void programa_principal(const char* dataSet, const char* comandos_exe) {
    FILE* aircrafts = fopen(strcat(dataSet, "/aircrafts.csv"),"r");
    FILE* airports = fopen(strcat(dataSet, "/airports.csv"),"r");
    FILE* flights = fopen(strcat(dataSet, "/flights.csv"),"r");
    FILE* passengers = fopen(strcat(dataSet, "/passengers.csv"),"r");
    FILE* reservations = fopen(strcat(dataSet, "/reservations.csv"),"r");
    Manager_Reservas* reservas = createManagerReservas();
    Manager_Passageiros* passageiros = createManagerPassageiros();
    Manager_Aeroportos* aeroportos = createManagerAeroportos();
    Manager_Aeronaves* aeronaves = createManagerAeronaves();
    Manager_Voos* voos = createManagerVoos();
    
}




int main(char args[],int argc) {
    if (args[0] == "progrma_principal") {
        programa_principal(args[1],args[2]);
    }
    if(args[0] == "programa_iterativo") {

    }
    if()
    return 0;
}
