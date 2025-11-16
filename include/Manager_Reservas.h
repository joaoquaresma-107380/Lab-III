// Ficheiro Manager_Reservas.h

#include <glib.h>
#include "Reserva.h"

#ifndef MANAGER_RESERVAS_H
#define MANAGER_RESERVAS_H

typedef struct manager_Reservas Manager_Reservas;

void value_destroy_func_Reserva(gpointer p);
Manager_Reservas* createManagerReservas();
void adicionaReserva(Reserva* r, Manager_Reservas* manager);
Reserva* procurarReserva(Manager_Reservas* gestor, char* id);
void destruirManager_Reservas(Manager_Reservas* mr);
void removeReserva(Reserva* r, Manager_Reservas* manager);

#endif
