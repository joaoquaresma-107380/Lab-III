#ifndef AERONAVE_H
#define AERONAVE_H

#include <stdlib.h>
#include <string.h>

// Estrutura da aeronave

typedef struct aeronave Aeronave;


// "Criar" um avião

Aeronave *criarAviao (const char *id, const char *manufacter,const char *model, int year,int capacity,int range,int totalFlights);

// "Destruir" Aviao

void destruirAviao(Aeronave *a);


// Para aceder 

const char *acederAeronaveId (const Aeronave *a);
const char *acederAeronaveFabricante (const Aeronave *a);
const char *acederAeronaveModelo (const Aeronave *a);
int acederAeronaveAno (const Aeronave *a);
int acederAeronaveCapacidade (const Aeronave *a);
int acederAeronaveAlcance (const Aeronave *a);
int acederVoosTotais (const Aeronave *a);


// Atualizações 

void AtuaAeronaveID (Aeronave *a, const char* id);
void AtuaAeronaveFabricante (Aeronave *a ,const char *fabricante);
void AtuaAeronaveModelo (Aeronave *a, const char* modelo);
void AtuaAeronaveAno (Aeronave *a , int ano);
void AtuaAeronaveCapacidade (Aeronave *a, int capacidade);
void AtuaAeronaveAlcance (Aeronave *a, int alcance);

void incrementarVoosTotaisAviao (Aeronave *a);


  




#endif
