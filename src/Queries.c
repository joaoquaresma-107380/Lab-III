#include "Queries.h"

struct listaContagem {
    char* code;
    int cont;
    struct listaContagem* next;
};

// Q1 - resumo de um aeroporto 

void querie1 (Manager_Aeroportos *gestorAeroportos, const char *codigo , FILE *output){
    if (!gestorAeroportos || !codigo || !output )return;
    Aeroporto *a = procurarAeroporto(gestorAeroportos, (char*)codigo);
    if (!a){
        fprintf(output, "\n"); // nao encontrou o aeroporto
        return;
    }
    else {
        int r = fprintf (output, "%s;%s;%s;%s;%s\n",
        getCode(a),
        getName(a),
        getCity(a),
        getCountry(a),
        getType(a));
        if(r < 0){
        perror("Erro a imprimir a querie1\n");
        }
    }
}

// Q2 -- Top N aeronaves com mais voos realizados 

void querie2(GestorAviao* gestorAeronaves, Manager_Voos* gestorVoos,int n, const char* fabricante,FILE* output) {
    if (!gestorVoos || !gestorAeronaves || !output) return;

    if (n <= 0) return;

    GList* lista_Aeronaves = todasOsAvioes(gestorAeronaves);

   int tamanho_voos = getSp(gestorVoos);
   Voo** voos = getValues(gestorVoos);
   if(!voos) return;

   for(int i = 0; i < tamanho_voos;i++){

        char* aeronave = getAircraft(voos[i]);
        Aeronave* a = encontrarAviao(gestorAeronaves,aeronave);
        if(!a) continue;;

    if(!fabricante){

        if(strcmp(getStatus(voos[i]),"Cancelled") != 0) {
        incrementarVoosTotaisAviao(a);
    }
    }

    else{

        
        if((strcmp(getStatus(voos[i]),"Cancelled") != 0) && strcmp(acederAeronaveFabricante(a),fabricante) == 0) {
        incrementarVoosTotaisAviao(a);
    }
    } 
   }

   for(int i = 0; i < tamanho_voos;i++){
    destruirVoo(voos[i]);
   }
   free(voos);

   ordenarAvioesPorVoos(lista_Aeronaves);

   // output
    int printed = 0;
    for (;printed < n && lista_Aeronaves; lista_Aeronaves = lista_Aeronaves->next) {
        Aeronave* a = lista_Aeronaves->data;
        if(!a) continue;
        fprintf(output, "%s;%s;%s;%d\n",
            acederAeronaveId(a),
            acederAeronaveFabricante(a),
            acederAeronaveModelo(a),
            acederVoosTotais(a));
        printed++;
    }

    g_list_free(lista_Aeronaves);

}

// Q3 - Listar aeroporto com mais partidas entre 2 datas

int procuraContagem(ListaContagem* ca,char* code) {
    int n = 0;
    ListaContagem** apontador = &ca;
    while(*apontador != NULL) {
        if (strcmp(code,(*apontador)->code) == 0) return n;
        else{
            *apontador = (*apontador)->next;
            n++;
        }
    }
    return -1;
}

void destruirLista(ListaContagem * l){
    while(l){
        free(l->code);
        ListaContagem* aux = l;
        l = l->next;
        free(aux);
    }
}

void querie3 (Manager_Voos* gestorVoos,Manager_Aeroportos* gestorAeroportos,Data* dataInicio,Data* dataFim,FILE* output) {
    int inicio = 0;
    int fim = 0;
    ordenaManager_Voos_Por_DataDeparture(gestorVoos);

    int sp = getSp(gestorVoos);

    for(int i = 0;i<sp;i++) {
        while (compararDataHora(dataInicio,getActual_Departure((getValues(gestorVoos))[i])) == -1) {
            inicio++;
        }
        fim = inicio;
        while (compararDataHora(getActual_Departure((getValues(gestorVoos))[i]),dataFim) != -1) fim++;
    }
    if ((fim-inicio)<=0) {
        fprintf(output, "Não encontrou nenhum aeroporto entre essas datas\n"); // nao encontrou nenhum aeroporto entre essas datas
        return;
    }
    else {

    ListaContagem* contaAeroportos = malloc(sizeof(ListaContagem));
            contaAeroportos->code = getOrigin((getValues(gestorVoos))[inicio]);
            contaAeroportos->cont = 1;
            contaAeroportos->next = NULL;
    
    for(int j = inicio+1;j<=fim;j++) {
        if(procuraContagem(contaAeroportos,getOrigin((getValues(gestorVoos))[j])) == -1) {
            struct listaContagem* celula = malloc(sizeof(struct listaContagem));
            celula->code = getOrigin((getValues(gestorVoos))[j]);
            celula->cont = 1;
            celula->next = contaAeroportos;
            contaAeroportos = celula;
        }
        else {
            int ind = procuraContagem(contaAeroportos,getOrigin((getValues(gestorVoos))[j]));
            ListaContagem** apontador = &contaAeroportos;
            while((*apontador) != NULL && ind>0) {
                (*apontador) = (*apontador)->next;
                ind--;
            }
            (*apontador)->cont++;
        }
    }
    ListaContagem** apMax = &contaAeroportos;
    ListaContagem** aux = &contaAeroportos;

    while(*aux != NULL) {
        if((*aux)->cont > (*apMax)->cont) *apMax = *aux;
        *aux=(*aux)->next;
    }
    char* max = (*apMax)->code;
    const char* cmax = max;
    querie1(gestorAeroportos,cmax,output);

    destruirLista(contaAeroportos);
    }
    
}