// Ficheiro Manager_Reservas.c
#include <glib.h>
#include <Reservas.h>

#ifndef Manager_Reservas_C
#define Manager_Reservas_C

struct manager_Reservas{
    GHashTable* tabela;
    int elems;
};

void value_destroy_func(gpoint p){
    Reserva* new = (Reserva*) p;
    destruirReserva(new);
};

// criar um manager de reserva

Manager_Reservas* createManagerReservas(){
    Manager_Reservas* manager = malloc(sizeof(Manager_Reservas));
    GHashTable* tabela = g_hash_table_new_full(g_str_hash,g_str_equal,free,value_destroy_func);
    manager->tabela = tabela;
    manager->elems = 0;
    return manager;
}

// adicionar uma reserva ao manager

gboolean adicionaReserva(Reserva* reserva, Manager_Reservas* manager){
    gboolean g = g_hash_table_add(manager->tabela,reserva->reservation_id);
    manager->elems++;
    return g;
}

// procurar uma reserva pelo reservation_id

Reserva* procurarReserva(Manager_Reservas* gestor, int id){
    return g_hash_table_lookup(g->tabela, id);
}

// retornar todas as reservas 

GList * todasReservas (Manager_Reservas* gestor){
    return g_hash_table_get_values(g->tabela);

}

// remover uma reserva do manager

gboolean removeReserva(Reserva* reserva, Manager_Reservas* manager){
    gboolena g = g_hash_table_remove(manager,reserva->reservation_id);
    manager->elems--;
    return g;
}

#endif
