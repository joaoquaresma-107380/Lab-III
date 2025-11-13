#include "Queries.h"

// Q1 - resumo de um aeroporto 

void querie1 (Manager_Aeroportos *gestorAeroportos, const char *codigo , FILE *output){
    if (!gestorAeroportos || !codigo || !output )return;

    Aeroporto *a = procurarAeroporto(gestorAeroportos, (char*)codigo);
    if (!a){
        fprintf(output, "\n"); // nao encontrou o aeroporto
        return;

    }

    fprintf (output, "%s;%s;%s;%s;%s\n",
        getCode(a),
        getName(a),
        getCity(a),
        getCountry(a),
        getType(a));

}

// Q2 -- Top N aeronaves com mais voos realizados 

// Estrutura para guardar contagem
typedef struct {
    Aeronave *a;
    int total;
} AviaoCount;


// Função de comparação para ordenar
static gint ordenarAvioes(gconstpointer a, gconstpointer b) {
    const AviaoCount* aa = a;
    const AviaoCount* bb = b;

    // Primeiro por total 
    if (bb->total > aa->total) return 1;
    if (bb->total < aa->total) return -1;


    // Depois por ID
    return strcmp(acederAeronaveId(aa->a), acederAeronaveId(bb->a));
}

void querie2(GestorAviao *gestorAeronaves, Manager_Voos *gestorVoos, int n, const char* fabricante, FILE *output) {
    if (!gestorAeronaves || !gestorVoos || !output) return;

    if (n <= 0) return;

    Voo** aux = getValues(gestorVoos);

    // hash table: idAeronave -> contador
    GHashTable *contador = g_hash_table_new_full(g_str_hash, g_str_equal, free, free);

    // contar voos válidos 
    for (int i = 0; i <= getSp(gestorVoos); i++) {

        Voo *v = cloneVoo(aux[i]);
        if (!v) continue;

        const char *status = getStatus(v);
        if (status && strcmp(status, "Cancelado") == 0)
            continue;

        // Obter ID da aeronave
        const char *idAeronave = getAircraft(v);
        if (!idAeronave) continue;

        int *count = g_hash_table_lookup(contador, idAeronave);
        if (!count) {
            int *novo = malloc(sizeof(int));
            *novo = 1;
            g_hash_table_insert(contador, strdup(idAeronave), novo);
        } else {
            (*count)++;
        }
    }

    // Construir lista de aeronaves 
    GList *lista = todasOsAvioes(gestorAeronaves);
    GList *listaContagem = NULL;

    for (GList *l = lista; l; l = l->next) {
        Aeronave *a = l->data;
        if (!a) continue;

        // Filtro de fabricante 
        if (fabricante && strcmp(acederAeronaveFabricante(a), fabricante) != 0)
            continue;

        const char *id = acederAeronaveId(a);
        int *valor = g_hash_table_lookup(contador, id);
        int total = valor ? *valor : 0;

        AviaoCount *item = malloc(sizeof(AviaoCount));
        item->a = a;
        item->total = total;

    
        listaContagem = g_list_prepend(listaContagem, item);
    }

    // Inverter devido ao uso de prepend
    listaContagem = g_list_reverse(listaContagem);

    // ordenar a lista 
    listaContagem = g_list_sort(listaContagem, ordenarAvioes);

    // output
    int printed = 0;
    for (GList *l = listaContagem; l && printed < n; l = l->next) {
        AviaoCount *item = l->data;
        fprintf(output, "%s;%s;%s;%d\n",
            acederAeronaveId(item->a),
            acederAeronaveFabricante(item->a),
            acederAeronaveModelo(item->a),
            item->total);
        printed++;
    }

    // libertar memória
    g_list_free(lista); // aeronaves são geridas pelo gestor
    g_list_free_full(listaContagem, free);
    g_hash_table_destroy(contador);
}


// Q3 - Listar aeroporto com mais partidas entre 2 datas

void querie3 (Manager_Voos* gestorVoos,Manager_Aeroportos* gestorAeroportos,Data* dataInicio,Data* dataFim,FILE* output){

    if (!gestorVoos || !gestorAeroportos || !dataInicio || !dataFim || !output)
        return;

    // contar partidas:
    GHashTable *contagem = g_hash_table_new_full(g_str_hash ,g_str_equal, free, free);

    Voo** aux = getValues(gestorVoos);
    // percorrer todos os voos
    for (int i = 0; i <= getSp(gestorVoos); i++){
        Voo *v = cloneVoo(aux[i]);
        if (!v) continue;
        if (strcmp (getStatus(v), "Cancelado") == 0 ) continue;

        Data *partida = getActual_Departure(v);

        // verificar se a data esta dentro do intervalo

        if (compararDataHora(partida, dataInicio) < 0 ||
            compararDataHora(partida, dataFim) > 0)
            continue;

        char *origem = getOrigin(v);

        // Atualizar contagem
        int* count = g_hash_table_lookup(contagem, origem);
        if (!count) {
            int* novo = malloc(sizeof(int));
            *novo = 1;
            g_hash_table_insert(contagem, strdup(origem), novo);
    } else {
        (*count)++;
    }

}

// Encontrar o aerporto com mais partidas 
GList* keys = g_hash_table_get_keys(contagem);
char* melhor = NULL;
int max = 0;

for (GList* l = keys; l; l = l->next) {
    char* codigo = (char*)l->data;
    int* valor = g_hash_table_lookup(contagem, codigo);

    if (*valor > max || (*valor == max && (!melhor || strcmp(codigo, melhor) < 0))) {
        melhor = codigo;
        max = *valor;
    }
}
    
// Resultado 
if (melhor) {
        Aeroporto* a = procurarAeroporto(gestorAeroportos, melhor);
        if (a) {
            fprintf(output, "%s,%s,%s,%s,%d\n",
                getCode(a),
                getName(a),
                getCity(a),
                getCountry(a),
                max);
        } else {
            fprintf(output, "\n"); // caso não encontre o aeroporto
        }
    } else {
        fprintf(output, "\n"); // sem resultados
    }

    // libertar memoria 

    g_list_free(keys);
    g_hash_table_destroy(contagem);
}