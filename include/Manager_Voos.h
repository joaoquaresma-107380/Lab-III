// Ficheiro Manager_Voos.h

#include <Voo.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef Manager_Voos_H
#define Manager_Voos_H

typedef struct manager Manager_Voos;
void createManager_Voos();
void dupVoos(Manager_Voos* s);
int ManagerVazio(Manager_Voos* s);
void adicionaVoo(Manager_Voos* s, Voo* x);
int procuraVoo(Manager_Voos* v,Voo* a);
int removerVoo(Manager_Voos* gestor, Voo* a);
void merge(Voo* arr[], int p, int q, int r);
void mergeSort(Voo* arr[], int l, int r);
void ordenaManager_Voos_Por_DataDeparture (Manager_Voos* v);
void ShowManager_Voos(Manager_Voos* v);

#endif
