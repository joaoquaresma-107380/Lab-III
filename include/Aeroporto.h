// Ficheiro Aeroporto.h

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef Aeroporto_H
#define Aeroporto_H

typedef struct aeroporto Aeroporto;

Aeroporto* createAeroporto(char* code, char* name, char* city, char* country, double latitude, double longitude, char* icao, char* type);
char* getCode(Aeroporto* a);
char* getName (Aeroporto* a);
char* getCity (Aeroporto* a);
char* getCountry (Aeroporto* a);
double getLatitude (Aeroporto* a);
double getLongitude (Aeroporto* a);
char* getIcao (Aeroporto* a);
char* getType (Aeroporto* a);
void setCode(Aeroporto* a, char* codigo);
void setName(Aeroporto* a, char* n);
void setCity(Aeroporto* a, char* cidade);
void setCountry(Aeroporto* a, char* pais);
void setLatitude(Aeroporto* a, double lat);
void setLongitude(Aeroporto* a, double lon);
void setIcao(Aeroporto* a, char* ic);
void setType(Aeroporto* a, char* tipo);
void destroiAeroporto(Aeroporto* arp);

#endif
