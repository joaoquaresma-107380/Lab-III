// Ficheiro Voo.h

#include "Data.h"

#ifndef Voo_H
#define Voo_H

typedef struct voo Voo;

Voo* createVoo(char* flight_id, Data* departure, Data* actual_departure, Data* arrival, Data* actual_arrival, int gate, char* status, char* origin, char* destination, char* aircraft, char* airline, char* tracking_URL);
char* getFlight_id(Voo* voo);
Data* getDeparture(Voo* voo);
Data* getActual_Departure(Voo* voo);
Data* getArrival(Voo* voo);
Data* getActual_Arrival(Voo* voo);
int getGate(Voo* voo);
char* getStatus(Voo* voo);
char* getOrigin(Voo* voo);
char* getDestination(Voo* voo);
char* getAircraft(Voo* voo);
char* getAirline(Voo* voo);
char* getTrackingURL(Voo* voo);
void setFlight_id(char* novoFlight_id, Voo* voo);
void setDeparture(Data* novoDeparture, Voo* voo);
void setActualDeparture(Data* novoActualDeparture, Voo* voo);
void setArrival(Data* novoArrival, Voo* voo);
void setActualArrival(Data* novoArrival, Voo* voo);
void setGate(int gt, Voo* voo);
void setStatus(char* st, Voo* voo);
void setOrigin(char* or, Voo* voo);
void setDestination(char* or, Voo* voo);
void setAircraft(char* or, Voo* voo);
void setAirline(char* or, Voo* voo);
void setTrackingURL(char* or, Voo* voo);
int compararVoo(Voo* a, Voo* b);
Voo* cloneVoo(Voo* v);
void destruirVoo(Voo* voo);

#endif
