// Ficheiro Voo.c

#include "Voo.h"

#ifndef Voo_C
#define Voo_C

/**
 * Definição do módulo Voo
 * O campo flight_id indica o identificador único do voo
 * O campo departure indica a data e hora de partida estimada do voo
 * O campo actual_departure indica a data e hora de partida real do voo
 * O campo arrival indica a data e hora de chegada estimada do voo
 * O campo actual_arrival indica a data e hora de chegada real do voo
 * O campo gate indica a porta de embarque do voo
 * O campo status indica o estado do voo
 * O campo origin indica o código IATA do aeroporto de origem
 * O campo destination indica o código IATA do aeroporto de destino
 * O campo aircraft indica o identificador único da aeronave utilizada no voo
 * O campo airline indica a companhia aérea responsável pelo voo
 * O campo tracking_URL indica o URL de rastreamento do voo
 */

struct voo{
    int flight_id;
    Data* departure;
    Data* actual_departure;
    Data* arrival;
    Data* actual_arrival;
    char* gate;
    char* status;
    char* origin;
    char* destination;
    int aircraft;
    char* airline;
    char* tracking_URL;
};

/**
 * Funcão de criação de um Voo
 */

 Voo* createVoo(int f, Data* d, Data* ad, Data* a, Data* aa, char* g, char* s, char* o, char* dest, int airc, char* airl, char* t_URL){
    Voo* voo = malloc(sizeof(Voo));

    voo->flight_id = f;
    voo->departure = cloneData(d);
    voo->actual_departure = cloneData(ad);
    voo->arrival = cloneData(a);
    voo->actual_arrival = cloneData(aa);
    voo->gate = strdup(g);
    voo->status = strdup(s);
    voo->origin = strdup(o);
    voo->destination = strdup(dest);
    voo->aircraft = airc;
    voo->airline = strdup(airl);
    voo->tracking_URL = strdup(t_URL);

    return voo;
 }

/**
 * Função que retorna o identificador único do voo
 */
int getFlight_id(Voo* voo){
    return voo->flight_id;
}

/**
 * Função que retorna a data e hora de partida estimada do voo
 */
Data* getDeparture(Voo* voo){
    Data* aux = cloneData(voo->departure);
    return aux;
}

/**
 * Função que retorna a data e hora de partida real do voo
 */
Data* getActual_Departure(Voo* voo){
    Data* aux = cloneData(voo->actual_departure);
    return aux;
}

/**
 * Função que retorna a data e hora de chegada estimada do voo
 */
Data* getArrival(Voo* voo){
    Data* aux = cloneData(voo->arrival);
    return aux;
}

/**
 * Função que retorna a data e hora de chegada real do voo
 */
Data* getActual_Arrival(Voo* voo){
    Data* aux = cloneData(voo->actual_arrival);
    return aux;
}

/**
 * Função que retorna a porta de embarque do voo
 */
char* getGate(Voo* voo){
    char* aux = strdup(voo->gate);
    return aux;
}

/**
 * Função que retorna ao estado do voo, i.e., On Time, Delayed ou Cancelled
 */
char* getStatus(Voo* voo){
    char* aux = strdup(voo->status);
    return aux;
}

/**
 * Função que retorna o código IATA do aeroporto de origem
 */
char* getOrigin(Voo* voo){
    char* aux = strdup(voo->origin);
    return aux;
}

/**
 * Função que retorna o código IATA do aeroporto de destino
 */
char* getDestination(Voo* voo){
    char* aux = strdup(voo->destination);
    return aux;
}

/**
 * Função que retorna o identificador único da aeronave utilizada no voo, i.e., tail
number
 */
int getAircraft(Voo* voo){
    return voo->aircraft;
}

/**
 * Função que retorna o nome da companhia aérea responsável pelo voo
 */
char* getAirline(Voo* voo){
    char* aux = strdup(voo->airline);
    return aux;
}

/**
 * Função que retorna o URL para o rastreamento do voo
 */
char* getTrackingURL(Voo* voo){
    char* aux = strdup(voo->tracking_URL);
    return aux;
}

/**
 * Função que altera o valor do campo flight_id de um voo
 */
void setFlight_id(int novoFlight_id, Voo* voo){
    voo->flight_id = novoFlight_id;
}

/**
 * Função que altera o valor do campo departure de um voo
 */
void setDeparture(Data* novoDeparture, Voo* voo){
    Data* data = cloneData(novoDeparture);
    voo->departure = data;
}

/**
 * Função que altera o valor do campo actual_departure de um voo
 */
void setActualDeparture(Data* novoActualDeparture, Voo* voo){
    Data* data = cloneData(novoActualDeparture);
    voo->actual_departure = data;
}

/**
 * Função que altera o valor do campo arrival de um voo
 */
void setArrival(Data* novoArrival, Voo* voo){
    Data* data = cloneData(novoArrival);
    voo->arrival = data;
}

/**
 * Função que altera o valor do campo actual_arrival de um voo
 */
void setActualArrival(Data* novoArrival, Voo* voo){
    Data* data = cloneData(novoArrival);
    voo->actual_arrival = data;
}

/**
 * Função que altera o valor do campo gate de um voo
 */
void setGate(char* gt, Voo* voo){
    char* data = strdup(gt);
    voo->gate = data;
}

/**
 * Função que altera o valor do campo status de um voo
 */
void setStatus(char* st, Voo* voo){
    char* data = strdup(st);
    voo->status = data;
}

/**
 * Função que altera o valor do campo origin de um voo
 */
void setOrigin(char* or, Voo* voo){
    char* data = strdup(or);
    voo->origin = data;
}

/**
 * Função que altera o valor do campo destination de um voo
 */
void setDestination(char* or, Voo* voo){
    char* data = strdup(or);
    voo->destination = data;
}

/**
 * Função que altera o valor do campo aircraft de um voo
 */
void setAircraft(int or, Voo* voo){
    voo->aircraft = or;
}

/**
 * Função que altera o valor do campo airline de um voo
 */
void setAirline(char* or, Voo* voo){
    char* data = strdup(or);
    voo->airline = data;
}

/**
 * Função que altera o valor do campo tracking_URL de um voo
 */
void setTrackingURL(char* or, Voo* voo){
    char* data = strdup(or);
    voo->tracking_URL = data;
}

/**
 *  funçao de comparaçao de voos que retorna 1 se a data de partida do segundo voo for mais recente,
 * 1 se data de partida do primeiro voo for mais recente e 0 se forem iguais 
 * */
int compararVoo(Voo* a, Voo* b) {
    if (compararDataHora(a->actual_departure,b->actual_departure) == 0) return 0;
    else {
        if (compararDataHora(a->actual_departure,b->actual_departure) > 0 ) return 1;
        else return -1;
    }
}

/**
 * Função que apaga um Voo
 */
void destruirVoo(Voo* voo){
    destroiData(voo->departure);
    free(voo->departure);
    destroiData(voo->actual_departure);
    free(voo->actual_departure);
    destroiData(voo->arrival);
    free(voo->arrival);
    destroiData(voo->actual_arrival);
    free(voo->actual_arrival);
    free(voo->gate);
    free(voo->status);
    free(voo->origin);
    free(voo->destination);
    free(voo->airline);
    free(voo->tracking_URL);
    free(voo);
}

#endif
