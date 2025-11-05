// Ficheiro Manager_Voos.h

#include <Voo.h>

#ifndef Manager_Voos_H
#define Manager_Voos_H

typedef struct manager Manager_Voos;
void inserirVoo(Voo a, Manager_Voos* v);
int procuraVoo(Voo a);
void removerVoo(Voo a);
void merge(int arr[], int p, int q, int r);
void mergeSort(int arr[], int l, int r);
void ordenaManager_Voos(Manager_Voos* v);

#endif