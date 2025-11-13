#include "Manager_Passageiros.h"

struct gestorPassageiros {
    GHashTable* tabela;
};

// Criar o gestor
GestorPassageiros* createGestorPassageiros() {
    GestorPassageiros *g = malloc(sizeof(GestorPassageiros));
    if (!g) return NULL;

    g->tabela = g_hash_table_new_full(g_int_hash, g_int_equal, free, (GDestroyNotify)destruirPassageiro);
    if (!g->tabela) {
        free(g);
        return NULL;
    }

    return g;
}

// Destruir o gestor
void destroiGestorPassageiros(GestorPassageiros *g) {
    if (!g) return;

    if (g->tabela)
        g_hash_table_destroy(g->tabela);

    free(g);
}

// Adicionar passageiro
void addPassageiro(GestorPassageiros *g, Passageiro *p) {
    if (!g || !p) return;

    int id = acederPassageiroDoc(p);
    int* key = malloc(sizeof(int));
    key = &id;
    g_hash_table_insert(g->tabela, key, p);
}

// Procurar passageiro pelo documento
Passageiro *encontrarPassageiro(GestorPassageiros *g, int doc) {
    if (!g) return NULL;
    int* key = malloc(sizeof(int));
    key = &doc;
    return g_hash_table_lookup(g->tabela, key);
}

// remover um passageiro do manager

void removePassageiro(Passageiro* a, GestorPassageiros* manager){
    int codigo = acederPassageiroDoc(a);
    int* key = malloc(sizeof(int));
    key = &codigo;
    g_hash_table_remove(manager->tabela,key);
}
