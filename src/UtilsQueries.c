#include "UtilsQueries.h"

struct listaContagem {
    char* code;
    int cont;
    int soma;
    struct listaContagem* next;
};

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

ListaContagem** criaAeronavesMaisVoos(GestorAviao* gestorAeronaves, Manager_Voos* gestorVoos) {
    ListaContagem* contaAeronaves = malloc(sizeof(ListaContagem));
    contaAeronaves->code = getAircraft(getValues(gestorVoos[0]));
    contaAeronaves->cont = 1;
    contaAeronaves->soma = 0;
    contaAeronaves->next = NULL;
    for(int i = 1; i<sp;i++) {
        if(procuraContagem(contaAeronaves,getAircraft((getValues(gestorVoos))[i])) == -1) {
            struct listaContagem* celula = malloc(sizeof(struct listaContagem));
            celula->code = getOrigin((getValues(gestorVoos))[i]);
            celula->cont = 1;
            celula->soma = 0;
            celula->next = contaAeronaves;
            contaAeronaves = celula;
        }
        else {
            int ind = procuraContagem(contaAeronaves,getAircraft((getValues(gestorVoos))[i]));
            ListaContagem** apontador = &contaAirlines;
            while((*apontador) != NULL && ind>0) {
                (*apontador) = (*apontador)->next;
                ind--;
            }
            (*apontador)->cont++;
            (*apontador)->soma = 0;
        }
    }
    
    ListaContagem** init = &contaAeronaves;
    ListaContagem** apMax = &contaAeronaves;
    ListaContagem** aux = &contaAeronaves;

    //ordena a contaAeronaves ainda falta fazer bem esta funçao

    while(*init != NULL) {
        while(*aux != NULL) {
            if((*aux)->cont > (*apMax)->cont) *apMax = *aux;
        }
        *aux=(*aux)->next;
        char* codeAux = (*init)->code;
        int contAux = (*init)->cont;
        int somaAux = (*init)->soma;

        (*init)->code = (*apMax)->code;
        (*init)->cont = (*apMax)->cont;
        (*init)->soma = (apMax*)->soma;

        (*init) = (*init)->next;
    }
    
    return &contaAeronaves;
}

ListaContagem** criaAirlinesMaisAtraso (Manager_Voos* gestorVoos) {
    int notOrd = 0;

    int sp = getSp(gestorVoos);
    /*Voo** arrayVoos = getValues(gestorVoos);

    for(int i = 1;i<sp;i++) {
        if (arrayVoos[i] < arrayVoos[i-1]) notOrd++;
    }
    if(notOrd > 0) ordenaManager_Voos_Por_DataDeparture(gestorVoos);*/

    ListaContagem* contaAirlines = malloc(sizeof(ListaContagem));
    contaAirlines = NULL;
    for(int i = 0; i<sp;i++) {
        if(strcmp(getStatus(getValues(gestorVoos)[i]),"Delayed") == 0) {
            if(procuraContagem(contaAirlines,getAirline((getValues(gestorVoos))[i])) == -1) {
            struct listaContagem* celula = malloc(sizeof(struct listaContagem));
            celula->code = getOrigin((getValues(gestorVoos))[i]);
            celula->cont = 1;
            contaAeroportos->soma = 0;
            celula->next = contaAirlines;
            contaAirlines = celula;
            }
            else {
            int ind = procuraContagem(contaAirlines,getAirlines((getValues(gestorVoos))[i]));
            ListaContagem** apontador = &contaAirlines;
            while((*apontador) != NULL && ind>0) {
                (*apontador) = (*apontador)->next;
                ind--;
            }
            (*apontador)->cont++;
            (*apontador)->soma += diferençaDatas(getActual_Departure((getValues(gestorVoos))[i]), getActual_Arrival((getValues(gestorVoos))[i]));
            }
        }
    }
    
    ListaContagem** init = &contaAirlines;
    ListaContagem** apMax = &contaAirlines;
    ListaContagem** aux = &contaAirlines;

    //ordena a contaAirlines

    while(*init != NULL) {
        while(*aux != NULL) {
            if(((*aux)->soma/(*aux)->cont) > ((*apMax)->soma/(*apMax)->cont)) *apMax = *aux;
            *aux=(*aux)->next;
        }
        char* codeAux = (*init)->code;
        int contAux = (*init)->cont;
        int somaAux = (*init)->soma;

        (*init)->code = (*apMax)->code;
        (*init)->cont = (*apMax)->cont;
        (*init)->soma = (apMax*)->soma;

        (*init) = (*init)->next;
    }

    return &contaAirlines;
}

