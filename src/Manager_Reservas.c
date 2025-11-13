// Ficheiro Manager_Reservas.c

#include <Manager_Reservas.h>

struct manager_Reservas{
    GHashTable* tabela;
    int elems;
};

void value_destroy_func_Reserva(gpointer p){
    Reserva* new = (Reserva*) p;
    destroiReserva(new);
};

// criar um manager de reserva

Manager_Reservas* createManagerReservas(){
    Manager_Reservas* manager = malloc(sizeof(Manager_Reservas));
    GHashTable* tabela = g_hash_table_new_full(g_str_hash,g_str_equal,free,value_destroy_func_Reserva);
    manager->tabela = tabela;
    manager->elems = 0;
    return manager;
}

// adicionar uma reserva ao manager

void adicionaReserva(Reserva* reserva, Manager_Reservas* manager){
    char* id = getReservationId(reserva);
    g_hash_table_insert(manager->tabela,id,reserva);
    manager->elems++;
}

// procurar uma reserva pelo reservation_id

Reserva* procurarReserva(Manager_Reservas* gestor, char* id){
    return g_hash_table_lookup(gestor->tabela, id);
}

// retornar todas as reservas 

GList * todasReservas (Manager_Reservas* gestor){
    return g_hash_table_get_values(gestor->tabela);

}

// remover uma reserva do manager

void removeReserva(Reserva* reserva, Manager_Reservas* manager){
    char* id = getReservationId(reserva);
    g_hash_table_remove(manager->tabela,id);
    manager->elems--;
}

