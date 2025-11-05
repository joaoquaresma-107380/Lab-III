// Ficheiro Aeroporto.h

#include <string.h>

#ifndef Aeroporto_H
#define Aeroporto_H

typedef struct aeroporto Aeroporto;

Aeroporto* createAeroporto(char* code, char* name, char* city, char* country, float latitude, float longitude, char* icao, char* type);
char* getCode(Aeroporto* a);
char* getName (Aeroporto* a);
char* getCity (Aeroporto* a);
char* getCountry (Aeroporto* a);
float getLatitude (Aeroporto* a);
float getLongitude (Aeroporto* a);
char* getIcao (Aeroporto* a);
char* getType (Aeroporto* a);
void setCode(Aeroporto* a, char* codigo);
void setName(Aeroporto* a, char* n);
void setCity(Aeroporto* a, char* cidade);
void setCountry(Aeroporto* a, char* pais);
void setLatitude(Aeroporto* a, float lat);
void setLongitude(Aeroporto* a, float lon);
void setIcao(Aeroporto* a, char* ic);
void setType(Aeroporto* a, char* tipo);
void destroiAeroporto(Aeroporto* arp);

#endif
