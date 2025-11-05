// Ficheiro Manager_Reservas.h

#include <glib.h>
#include <Reserva.h>

#ifndef Manager_Reservas_H
#define Manager_Reservas_H

typedef struct manager_Reservas Manager_Reservas;

void value_destroy_func(gpoint p);
Manager_Reservas* createManagerReservas();
gboolean adicionaReserva(Reserva* r, Manager_Reservas* manager);
gboolean removeAeroporto(Reserva* r, Manager_Reservas* manager);

#endif