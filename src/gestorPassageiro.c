#include "gestorPassageiro.h"

#include <string.h>
#include <stdlib.h>

struct gestorPassageiros {
    GHashTable* tabela;
};

// Criar o gestor
GestorPassageiros* createGestorPassageiros() {
    GestorPassageiros *g = malloc(sizeof(GestorPassageiros));
    if (!g) return NULL;

    g->tabela = g_hash_table_new_full(g_str_hash, g_str_equal, free, (GDestroyNotify)destruirPassageiro);
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

    g_hash_table_insert(g->tabela, strdup(acederPassageiroDoc(p)), p);
}

// Procurar passageiro pelo documento
Passageiro *encontrarPassageiro(GestorPassageiros *g, const char *doc) {
    if (!g || !doc) return NULL;

    return g_hash_table_lookup(g->tabela, doc);
}
