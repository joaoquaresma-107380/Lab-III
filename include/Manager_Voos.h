// Ficheiro Manager_Voos.h

#include "Voo.h"

#ifndef MANAGER_VOOS_H
#define MANAGER_VOOS_H

typedef struct manager_Voos Manager_Voos;

Manager_Voos* createManager_Voos ();
void dupVoos(Manager_Voos* s);
void destruirManager_Voos(Manager_Voos* voos);
int getSp(Manager_Voos* s);
int getSize(Manager_Voos* s);
Voo** getValues(Manager_Voos* s);
int ManagerVazio(Manager_Voos* s);
void adicionaVoo(Manager_Voos* s, Voo* x);
Voo* procuraVoo(Manager_Voos* v,char* id);
int removerVoo(Manager_Voos* gestor, Voo* a);
void merge(Voo* arr[], int p, int q, int r);
void mergeSort(Voo* arr[], int l, int r);
void ordenaManager_Voos_Por_DataDeparture (Manager_Voos* v);
void ShowManager_Voos(Manager_Voos* v);

#endif
