// Ficheiro Manager_Aeroportos.c

#include <Aeroportos.h>

#ifndef Manager_Aeroportos_C
#define Manager_Aeroportos_C

struct manager_Aeroportos{
    GHashTable* tabela;
    int elems;
};

void value_destroy_func(gpoint p){
    Aeroporto* new = (Aeroporto*) p;
    destruirAeroporto(new);
};

// criar um manager de aeroporto

Manager_Aeroportos* createManagerAeroportos(){
    Manager_Aeroportos* manager = malloc(sizeof(Manager_Aeroportos));
    GHashTable* tabela = g_hash_table_new_full(g_str_hash,g_str_equal,free,value_destroy_func);
    manager->tabela = tabela;
    manager->elems = 0;
    return manager;
}

// adicionar um aeroporto ao manager

gboolean adicionaAeroporto(Aeroporto* aeroporto, Manager_Aeroportos* manager){
    gboolean g = g_hash_table_add(manager->tabela,aeroporto->code);
    manager->elems++;
    return g;
}

// procurar um aeroporto pelo code

Aeroporto* procurarReserva(Manager_Aeroportos* gestor, char* code){
    return g_hash_table_lookup(g->tabela, code);
}

// retornar todos os aeroportos

GList * todasReservas (Manager_Aeroportos* gestor){
    return g_hash_table_get_values(g->tabela);

}

// remover um aeroporto do manager

gboolean removeAeroporto(Aeroporto* aeroporto, Manager_Aeroportos* manager){
    gboolena g = g_hash_table_remove(manager,aeroporto->code);
    manager->elems--;
    return g;
}

#endif
