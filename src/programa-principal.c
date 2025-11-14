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
    // char* comandos_exe = argv[2];
    
    char auxAirports[50];
    if (snprintf(auxAirports,50,"%sairports.csv",dataSet)<0) perror("Erro no nome do ficheiro de leitura airports");
    const char* filename_airports = strdup(auxAirports); // isto está a funcionar
    FILE* airports = abrirFicheiroLeitura(filename_airports);
    
    char auxAircrafts[50];
    if (snprintf(auxAircrafts,50,"%saircrafts.csv",dataSet)<0) perror("Erro no nome do ficheiro de leitura aircrafts");
    const char* filename_aircrafts = strdup(auxAircrafts); // isto está a funcionar
    FILE* aircrafts = abrirFicheiroLeitura(filename_aircrafts);

    char auxPassengers[50];
    if (snprintf(auxPassengers,50,"%spassengers.csv",dataSet)<0) perror("Erro no nome do ficheiro de leitura passengers");
    const char* filename_passengers = strdup(auxPassengers); // isto está a funcionar
    FILE* passengers = abrirFicheiroLeitura(filename_passengers);

    char auxFlights[50];
    if (snprintf(auxFlights,50,"%sflights.csv",dataSet)<0) perror("Erro no nome do ficheiro de leitura flights");
    const char* filename_flights = strdup(auxFlights); // isto está a funcionar
    FILE* flights = abrirFicheiroLeitura(filename_flights);

    char auxReservations[50];
    if (snprintf(auxReservations,50,"%sreservations.csv",dataSet)<0) perror("Erro no nome do ficheiro de leitura reservations");
    const char* filename_reservations = strdup(auxReservations); // isto está a funcionar
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
    return 0;


    /*FILE* comandos = abrirFicheiroLeitura(comandos_exe);
    readFileComandos(comandos, aeroportos,voos, aeronaves);
    fecharFicheiro(comandos);*/
    // return 0;
}

