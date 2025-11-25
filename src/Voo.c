// Ficheiro Voo.c

#include "Voo.h"

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
    char* flight_id;
    Data* departure;
    Data* actual_departure;
    Data* arrival;
    Data* actual_arrival;
    int gate;
    char* status;
    char* origin;
    char* destination;
    char* aircraft;
    char* airline;
    char* tracking_URL;
};

/**
 * Funcão de criação de um Voo
 */

 Voo* createVoo(char* f, Data* d, Data* ad, Data* a, Data* aa, int g, char* s, char* o, char* dest, char* airc, char* airl, char* t_URL){
    Voo* voo = malloc(sizeof(Voo));

    voo->flight_id = f;
    voo->departure = cloneData(d);
    voo->actual_departure = cloneData(ad);
    voo->arrival = cloneData(a);
    voo->actual_arrival = cloneData(aa);
    voo->gate = g;
    voo->status = strdup(s);
    voo->origin = strdup(o);
    voo->destination = strdup(dest);
    voo->aircraft = strdup(airc);
    voo->airline = strdup(airl);
    voo->tracking_URL = strdup(t_URL);

    return voo;
 }

/**
 * Função que retorna o identificador único do voo
 */
char* getFlight_id(Voo* voo){
    char* aux = strdup(voo->flight_id);
    return aux;
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
int getGate(Voo* voo){
    return voo->gate;
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
char* getAircraft(Voo* voo){
    char* aux = strdup(voo->aircraft);
    return aux;
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
void setFlight_id(char* novoFlight_id, Voo* voo){
    char* aux = strdup(novoFlight_id);
    voo->flight_id = aux;
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
void setGate(int gt, Voo* voo){
    voo->gate = gt;
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
void setAircraft(char* or, Voo* voo){
    char* aux = strdup(or);
    voo->aircraft = aux;
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

// Função de clone de um Voo
Voo* cloneVoo(Voo* v){
    Voo* new = malloc(sizeof(Voo));

    new->flight_id = strdup(v->flight_id);
    new->departure = cloneData(v->departure);
    new->actual_departure = cloneData(v->actual_departure);
    new->arrival = cloneData(v->arrival);
    new->actual_arrival = cloneData(v->actual_arrival);
    new->gate = v->gate;
    new->status = strdup(v->status);
    new->origin = strdup(v->origin);
    new->destination = strdup(v->destination);
    new->aircraft = strdup(v->aircraft);
    new->airline = strdup(v->airline);
    new->tracking_URL = strdup(v->tracking_URL);

    return new;
}

/**
 * Função que apaga um Voo
 */
void destruirVoo(Voo* voo){
    if(voo){

    free(voo->flight_id);
    destroiData(voo->departure);
    destroiData(voo->actual_departure);
    destroiData(voo->arrival);
    destroiData(voo->actual_arrival);
    free(voo->status);
    free(voo->origin);
    free(voo->destination);
    free(voo->aircraft);
    free(voo->airline);
    free(voo->tracking_URL);
    free(voo);
    }
}


