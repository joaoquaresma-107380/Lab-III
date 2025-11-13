#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef AERONAVE_H
#define AERONAVE_H

// Estrutura da aeronave

typedef struct aeronave Aeronave;


// "Criar" um avião

Aeronave *criarAviao(char *id, char *manufacter,char *model, int year,int capacity,int range,int totalFlights);

// "Destruir" Aviao

void destruirAviao(Aeronave *a);


// Para aceder 

char *acederAeronaveId (Aeronave *a);
char *acederAeronaveFabricante (Aeronave *a);
char *acederAeronaveModelo (Aeronave *a);
int acederAeronaveAno (Aeronave *a);
int acederAeronaveCapacidade (Aeronave *a);
int acederAeronaveAlcance (Aeronave *a);
int acederVoosTotais (Aeronave *a);


// Atualizações 

void AtuaAeronaveID (Aeronave *a, char* id);
void AtuaAeronaveFabricante (Aeronave *a ,char *fabricante);
void AtuaAeronaveModelo (Aeronave *a, char* modelo);
void AtuaAeronaveAno (Aeronave *a , int ano);
void AtuaAeronaveCapacidade (Aeronave *a, int capacidade);
void AtuaAeronaveAlcance (Aeronave *a, int alcance);

void incrementarVoosTotaisAviao (Aeronave *a);

#endif
