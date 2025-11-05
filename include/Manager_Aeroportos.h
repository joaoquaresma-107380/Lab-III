// Ficheiro Manager_Aeroportos.h

#include <glib.h>
#include <Aeroporto.h>

#ifndef Manager_Aeroportos_H
#define Manager_Aeroportos_H

typedef struct manager_Aeroportos Manager_Aeroportos;

void value_destroy_func(gpoint p);
Manager_Aeroportos* createManagerAeroportos();
void adicionaAeroporto(Aeroporto* aeroporto, Manager_Aeroportos* manager);
Aeroporto* procurarReserva(Manager_Aeroportos* gestor, char* code);
GList * todasReservas (Manager_Aeroportos* gestor);
void removeAeroporto(Aeroporto* aeroporto, Manager_Aeroportos* manager);

#endif
