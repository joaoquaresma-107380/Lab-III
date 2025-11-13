// Ficheiro Data.h

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef Data_H
#define Data_H

typedef struct data Data;

Data* createData(int ano, int mes, int dia, int hora, int min);
Data* cloneData(Data* d);
int getAno(Data* data);
int getMes(Data* data);
int getDia(Data* data);
int getHora(Data* data);
int getMinutos(Data* data);
void setAno(int novAno, Data* data);
void setMes(int novMes, Data* data);
void setDia(int novDia, Data* data);
void setHora(int novHora, Data* data);
void setMinutos(int novMin, Data* data);
void destroiData (Data* d);
int compararDataHora(Data* x, Data* y);
Data* stringToDate(char* str);
int validacaoData(char* token);

#endif
