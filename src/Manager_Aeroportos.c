// Ficheiro Manager_Aeroportos.c

#include <Manager_Aeroportos.h>

struct manager_Aeroportos{
    GHashTable* tabela;
    int elems;
};

void value_destroy_func_Aeroporto(gpointer p){
    Aeroporto* new = (Aeroporto*) p;
    destroiAeroporto(new);
};

// criar um manager de aeroporto

Manager_Aeroportos* createManagerAeroportos(){
    Manager_Aeroportos* manager = malloc(sizeof(Manager_Aeroportos));
    GHashTable* tabela = g_hash_table_new_full(g_str_hash,g_str_equal,free,value_destroy_func_Aeroporto);
    manager->tabela = tabela;
    manager->elems = 0;
    return manager;
}

// adicionar um aeroporto ao manager

void adicionaAeroporto(Aeroporto* a, Manager_Aeroportos* manager){
    char* codigo = getCode(a);
    g_hash_table_insert(manager->tabela, codigo,a);
    manager->elems++;
}

// procurar um aeroporto pelo code

Aeroporto* procurarAeroporto(Manager_Aeroportos* gestor, char* code){
    return g_hash_table_lookup(gestor->tabela, code);
}

// liberta toda a memória alocada para os aeroportos

void destruirManager_Aeroportos(Manager_Aeroportos* map){
    if (map == NULL) return;

    if(map->tabela != NULL) g_hash_table_destroy(map->tabela);
    
    free (map);
}

// remover um aeroporto do manager

void removeAeroporto(Aeroporto* a, Manager_Aeroportos* manager){
    char* codigo = getCode(a);
    g_hash_table_remove(manager->tabela,codigo);
    manager->elems--;
}
