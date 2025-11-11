#include <string.h>
#include "AeroportoParser.h"
#include "AeronaveParser.h"
#include "ReservaParser.h"
#include "VooParser.h"
#include "PassageirosParser.h"


void programa_principal(const char* dataSet, const char* comandos_exe) {
    FILE* airports = abrirFicheiroLeitura(strcat(dataSet, "/airports.csv"));
    FILE* aircrafts = abrirFicheiroLeitura(strcat(dataSet, "/aircrafts.csv"));
    FILE* passengers = abrirFicheiroLeitura(strcat(dataSet, "/passengers.csv"));
    FILE* flights = abrirFicheiroLeitura(strcat(dataSet, "/flights.csv"));
    FILE* reservations = abrirFicheiroLeitura(strcat(dataSet, "/reservations.csv"));
    Manager_Aeroportos* aeroportos = createManagerAeroportos();
    readFileAeroporto(airports, aeroportos);
    fecharFicheiro(airports);
    Manager_Aeronaves* aeronaves = createManagerAeronaves();
    readFileAeronave(aircrafts, aeronaves);
    fecharFicheiro(aircrafts);
    Manager_Passageiros* passageiros = createManagerPassageiros();
    readFilePassageiro(passengers, passageiros);
    fecharFicheiro(passengers);
    Manager_Voos* voos = createManagerVoos();
    readFileVoo(flights, voos, aeronaves);
    fecharFicheiro(flights);
    Manager_Reservas* reservas = createManagerReservas();
    readFileReserva(reservations, reservas, voos, passageiros);
    fecharFicheiro(reservations);

    // ja esta tudo na base de dados e corrigiddo
    // agora é passar os comandos para as queries
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
