#include "Manager_Aeronaves.h"

struct gestorAviao {
    GHashTable* tabela;

};

static GHashTable* criarTabelaAviao(){
    return g_hash_table_new_full(
        g_str_hash,
        g_str_equal,
        free,
        (GDestroyNotify)destruirAviao
    );
}

GestorAviao* criarGestorAviao(){
    GestorAviao* g = malloc(sizeof(GestorAviao));
    if (!g) return NULL;
    
    g->tabela = criarTabelaAviao();
    if (!g->tabela){
        free(g);
        return NULL;
    }
    return g;
}

void destruirGestorAeronaves (GestorAviao* g){
    if (!g) return;

    if(g->tabela)
       g_hash_table_destroy(g->tabela);
    
    free (g);
}

// adicionar um aviao ao gestor 

void addAviao(GestorAviao* g, Aeronave* a){
    if (!g || !a) return;

    char* id = acederAeronaveId(a);
    
    if (g_hash_table_lookup(g->tabela, id)){
        g_hash_table_remove(g->tabela, id);
    }

    g_hash_table_insert (g->tabela,strdup(id), a);
}

// procurar um aviao pelo o ID

Aeronave *encontrarAviao(GestorAviao* g, char* id){
    if (!g || !id) return NULL;

    return g_hash_table_lookup(g->tabela, id);
}

// retornar todos os avioes 

GList * todasOsAvioes (GestorAviao *g){
    if (!g) return NULL;

    return g_hash_table_get_values(g->tabela);

}

// Comparar para depois ordenar 

static gint compararAvioes (gconstpointer a, gconstpointer b){
    Aeronave* aa = (Aeronave*)a;
    Aeronave* bb = (Aeronave*)b;

    int diff = acederVoosTotais(bb) - acederVoosTotais (aa);

    if (diff == 0) return strcmp (acederAeronaveId(aa),acederAeronaveId(bb));

    return diff;
}

// ordenar os avioes por voos 

void ordenarAvioesPorVoos(GList** lista){
    if (!lista || !*lista) return;
    *lista = g_list_sort(*lista,compararAvioes);

}

// remover uma aeronave do manager

void removeAeronave(Aeronave* a, GestorAviao* manager){
    char* codigo = acederAeronaveId(a);
    g_hash_table_remove(manager->tabela,codigo);
}
