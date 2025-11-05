// Ficheiro Voo.h

#include "Data.h"
#include <string.h>

#ifndef Voo_H
#define Voo_H

typedef struct voo Voo;

Voo* createVoo(int flight_id, Data* departure, Data* actual_departure, Data* arrival, Data* actual_arrival, char* gate, char* status, char* origin, char* destination, int aircraft, char* airline, char* tracking_URL);
int getFlight_id(Voo* voo);
Data* getDeparture(Voo* voo);
Data* getActual_Departure(Voo* voo);
Data* getArrival(Voo* voo);
Data* getActual_Arrival(Voo* voo);
char* getGate(Voo* voo);
char* getStatus(Voo* voo);
char* getOrigin(Voo* voo);
char* getDestination(Voo* voo);
int getAircraft(Voo* voo);
char* getAirline(Voo* voo);
char* getTrackingURL(Voo* voo);
void setFlight_id(int novoFlight_id, Voo* voo);
void setDeparture(Data* novoDeparture, Voo* voo);
void setActualDeparture(Data* novoActualDeparture, Voo* voo);
void setArrival(Data* novoArrival, Voo* voo);
void setActualArrival(Data* novoArrival, Voo* voo);
void setGate(char* gt, Voo* voo);
void setStatus(char* st, Voo* voo);
void setOrigin(char* or, Voo* voo);
void setDestination(char* or, Voo* voo);
void setAircraft(int or, Voo* voo);
void setAirline(char* or, Voo* voo);
void setTrackingURL(char* or, Voo* voo);
int compararVoo(Voo* a, Voo* b);
void destruirVoo(Voo* voo);

#endif
