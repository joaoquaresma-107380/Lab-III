// Ficheiro Manager_Aeroportos.h

#include <glib.h>
#include <Aeroporto.h>

#ifndef MANAGER_AEROPORTOS_H
#define MANAGER_AEROPORTOS_H

typedef struct manager_Aeroportos Manager_Aeroportos;

void value_destroy_func_Aeroporto(gpointer p);
Manager_Aeroportos* createManagerAeroportos();
void adicionaAeroporto(Aeroporto* a, Manager_Aeroportos* manager);
Aeroporto* procurarAeroporto(Manager_Aeroportos* gestor, char* code);
void destruirManager_Aeroportos(Manager_Aeroportos* map);
void removeAeroporto(Aeroporto* a, Manager_Aeroportos* manager);

#endif
