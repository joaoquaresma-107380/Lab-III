#include <glib.h>
#include "AeroportoParser.h"
#include "AeronaveParser.h"
#include "ReservaParser.h"
#include "VooParser.h"
#include "PassageiroParser.h"
#include "ComandoParser.h"


int main(int argc, char* argv[]) {

    if(argc != 3){
        perror("Número de argumentos incorreto");
        return 1;
    }

    char* dataSet = argv[1];
    char* comandos_exe = argv[2];

    const char* filename_airports = strcat(dataSet, "/airports.csv");
    FILE* airports = abrirFicheiroLeitura(filename_airports);
    
    const char* filename_aircrafts = strcat(dataSet, "/aircrafts.csv");
    FILE* aircrafts = abrirFicheiroLeitura(filename_aircrafts);
    
    const char* filename_passengers = strcat(dataSet, "/passengers.csv");
    FILE* passengers = abrirFicheiroLeitura(filename_passengers);
    
    const char* filename_flights = strcat(dataSet, "/flights.csv");
    FILE* flights = abrirFicheiroLeitura(filename_flights);

    const char* filename_reservations = strcat(dataSet, "/reservations.csv");
    FILE* reservations = abrirFicheiroLeitura(filename_reservations);

    Manager_Aeroportos* aeroportos = createManagerAeroportos();
    readFileAeroporto(airports, aeroportos);
    fecharFicheiro(airports);

    GestorAviao* aeronaves = criarGestorAviao();
    readFileAeronave(aircrafts, aeronaves);
    fecharFicheiro(aircrafts);

    GestorPassageiros* passageiros = createGestorPassageiros();
    readFilePassageiro(passengers, passageiros);
    fecharFicheiro(passengers);

    Manager_Voos* voos = createManager_Voos();
    readFileVoo(flights, voos, aeronaves);
    fecharFicheiro(flights);

    Manager_Reservas* reservas = createManagerReservas();
    readFileReserva(reservations, reservas, voos, passageiros);
    fecharFicheiro(reservations);

    FILE* comandos = abrirFicheiroLeitura(comandos_exe);
    readFileComandos(comandos, aeroportos,voos, aeronaves);
    fecharFicheiro(comandos);
    return 0;
}

