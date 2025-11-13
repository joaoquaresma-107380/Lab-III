// Ficheiro Reserva.h

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef RESERVA_H
#define RESERVA_H

typedef struct reserva Reserva;

Reserva* createReserva (char* r_id, int num, char** f_id, int dnumber, char* lugar, float preco, char* boleano, char* b, char* qr);
char* getReservationId(Reserva* r);
int getNumFlightsId(Reserva* r);
char** getFlightsId(Reserva* r);
int getDocumentNumber(Reserva* r);
char* getSeat (Reserva* r);
float getPrice(Reserva* r);
char* getExtraLuggage(Reserva* r);
char* getPriorityBoarding(Reserva* r);
char* getQrCode (Reserva* r);
void setReservationId(Reserva* r, char* r_id);
void setNumFlightsId(Reserva* r, int num);
void setFlightsId(Reserva* r, char** f_id, int num);
void setDocumentNumber(Reserva* r, int dnumber);
void setSeat(Reserva* r, char* lugar);
void setPrice(Reserva* r, float preco);
void setExtraLuggage(Reserva* r, char* boleano);
void setPriorityBoarding(Reserva* r, char* b);
void setQrCode(Reserva* r, char* qr);
void destroiReserva(Reserva* r);

#endif
