#include "Queries.h"

// Q1 - resumo de um aeroporto 
/*querie 1: fazer um increasePassageiroDeparture e um increasePassageiroArrival no aeroporto;
chamar essas duas funçoes nas no inserir reserva conforme o getOrigin(procuraVoo(idflight)) ou getDeparture(procuraVoo(idflight));*/

char** querie1 (Manager_Aeroportos *gestorAeroportos, Manager_Reservas* gestorReservas, const char *codigo){
    
    if (!gestorAeroportos || !codigo || !output )return;
    
    ListaContagem* contaPassAeroporto = malloc(sizeof(ListaContagem));
                    contaPassAeroporto->code = (char*) codigo;
                    contaPassAeroporto->cont = 0;
                    contaPassAeroporto->soma = 0;
                    contaPassAeroporto->next = NULL;

    for(int i = 0;i<getSp(gestorReservas);i++) {
        if (getNumFlightsId(gestorReservas) == 2) {
            if ((strcmp((char*)codigo,getOrigin(procuraVoo(getFlightsId(getValues(gestorReservas))[i])[0])) == 0) 
            || (strcmp((char*)codigo,getOrigin(procuraVoo(getFlightsId(getValues(gestorReservas))[i])[1])) == 0)) {
                contaPassAeroporto->cont++; 
            }
            if ((strcmp((char*)codigo,getDestination(procuraVoo(getFlightsId(getValues(gestorReservas))[i])[1])) == 0)
            || (strcmp((char*)codigo,getDestination(procuraVoo(getFlightsId(getValues(gestorReservas))[i])[1])) == 0)) {
                contaPassAeroporto->soma++;
            }
        }
        else {
            if (strcmp((char*)codigo,getOrigin(procuraVoo(getFlightsId(getValues(gestorReservas))[i])[0])) == 0) {
                contaPassAeroporto->cont++; 
            }
            if (strcmp((char*)codigo,getDestination(procuraVoo(getFlightsId(getValues(gestorReservas))[i])[1])) == 0) {
                contaPassAeroporto->soma++;
            }
        }
    }
    Aeroporto* a = procurarAeroporto(gestorAeroportos, contPassAeroporto->code);
    char** resultados = malloc(1 * sizeof(char*));
    resultados[1] = malloc(100 * sizeof(char));
        int r = snprintf (resultados[1],100,"%s;%s;%s;%s;%s;%d;%d\n",
        getCode(a),
        getName(a),
        getCity(a),
        getCountry(a),
        getType(a),
        contaPassAeroporto->soma, // destination ou seja arrivalCount
        contaPassAeroporto->cont); // origin ou seja departureCount
        if(r < 0){
        perror("Erro a imprimir a querie1\n");
        }
    resultados[2] = NULL;

    destruirLista(contaPassAeroporto);
    
    return resultados;
}

// Q2 -- Top N aeronaves com mais voos realizados -- ainda falta modificar esta querie
// fazer no manager_voos uma struct com a lista da querie 5 e da querie 2

char** querie2(GestorAviao* gestorAeronaves, Manager_Voos* gestorVoos,int n, const char* fabricante, ListaContagem** contaAeronaves) {
    

    char** resultados = malloc(n * sizeof(char*));
    for (int i = 0;i<n && (*contaAeronaves) != NULL;i++) {
        resultados[i] = malloc(100 * sizeof(char));
        if (fabricante == NULL) {
                snprintf(resultados[i], 100, "%s;%d;%d\n",
                        (*contaAeronaves)->code,
                        fabricante,
                        acederAeronaveModelo(encontrarAviao(gestorAeronaves,(*contaAeronaves)->code)),
                        (*contaAeronaves)->cont);   
        }
        else {
            if (acederAeronaveFabricante(encontrarAviao(gestorAeronaves,(*contaAeronaves)->code)) == (char*) fabricante) {
                snprintf(resultados[i], 100, "%s;%s;%s;%d\n",
                        (*contaAeronaves)->code,
                        fabricante,
                        acederAeronaveModelo(encontrarAviao(gestorAeronaves,(*contaAeronaves)->code)),
                        (*contaAeronaves)->cont);
            }
            (*contaAeronaves) = (*contaAeronaves)->next;
        }
    }
    resultados[n] = NULL;

    return resultados;
}

// Q3 - Listar aeroporto com mais partidas entre 2 datas

char** querie3 (Manager_Voos* gestorVoos,Manager_Aeroportos* gestorAeroportos,Data* dataInicio,Data* dataFim) {
    int inicio = 0;
    int fim = 0;
    // ordenaManager_Voos_Por_DataDeparture(gestorVoos);

    int sp = getSp(gestorVoos);

    for(int i = 0;i<sp;i++) {
        while (compararDataHora(dataInicio,getActual_Departure((getValues(gestorVoos))[i])) == -1) {
            inicio++;
        }
        fim = inicio;
        while (compararDataHora(getActual_Departure((getValues(gestorVoos))[i]),dataFim) != -1) fim++;
    }
    if ((fim-inicio)<=0) {
        // nao encontrou nenhum aeroporto entre essas datas
        return;
    }

    ListaContagem* contaAeroportos = malloc(sizeof(ListaContagem));
            contaAeroportos->code = getOrigin((getValues(gestorVoos))[inicio]);
            contaAeroportos->cont = 1;
            contaAeroportos->soma = 0;
            contaAeroportos->next = NULL;
    
    for(int j = inicio+1;j<=fim;j++) {
        if(procuraContagem(contaAeroportos,getOrigin((getValues(gestorVoos))[j])) == -1) {
            struct listaContagem* celula = malloc(sizeof(struct listaContagem));
            celula->code = getOrigin((getValues(gestorVoos))[j]);
            celula->cont = 1;
            contaAeroportos->soma = 0;
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
    Aeroporto* a = procurarAeroporto(gestorAeroportos, (*apMax)->code);
    char** resultados = malloc(1 * sizeof(char*));
    resultados[1] = malloc(100 * sizeof(char));
        int r = snprintf (resultados[1],100,"%s;%s;%s;%s;%s;%d;%d\n",
        getCode(a),
        getName(a),
        getCity(a),
        getCountry(a),
        getType(a),
        (*apMax)->soma, // destination ou seja arrivalCount
        (*apMax)->cont); // origin ou seja departureCount
        if(r < 0){
        perror("Erro a imprimir a querie3\n");
        }
    resultados[2] = NULL;


    destruirLista(contaAeroportos);
    
    return resultados;
    
}

// Q4 - Qual o passageiro que esteve mais tempo no top 10 de passageiros que mais gastaram em viagens durante um período?
/*querie 4: Usar o managerReservas Ordenado pelo getDeparture(idFlight) para poder ir buscar uma altura no tempo pelas datas, somar os price nos
documentNumber que forem iguais e tirar os dez preços mais altos;*/




// Q5 - Top N companhias aéreas com mais tempo de atraso médio por voo
/*querie 5: Ir aos voos e ir guardando, quando a airline é igual, a quantidade de voos delayed e ir somando os minutos de delay,
 no fim dividir um pelo outro para dar o tempo médio;*/

char** querie5 (Manager_Voos* gestorVoos, int n, ListaContagem* contaAirlines) {
    char** resultados = malloc(n * sizeof(char*));
    for (int i = 0;i < n && (*contaAirlines) != NULL; i++) {
        resultados[i] = malloc(100 * sizeof(char));
        snprintf(resultados[i], 100, "%s;%d;%d\n",
            (*contaAirlines)->code,
            (*contaAirlines)->cont,
            ((*contaAirlines)->soma / (*contaAirlines)->cont));
        (*contaAirlines) = (*contaAirlines)->next
    }
    resultados[n] = NULL;

    return resultados;
    
}

// Q6 - Listar o aerporto de destino mais comum para passageiros de uma determinada nacionalidade
/*querie 6: ir às reservas com o getCountry(procuraPassageiro(documentNumber)) e guardar os que forem iguais à nacionalidade incerida,
ver getdestino(idFlight) da reserva e ir contando o que aparece mais vezes;*/

char** querie6 (Manager_Reservas* gestorReservas, char* nationality) {
    

    ListaContagem* contaPassageiros = malloc(sizeof(ListaContagem));
    contaPassageiros = NULL;
    
    for(int j = inicio+1;j<=fim;j++) { // falta mudar este ciclo quando as reservas forem uma arvore
        if (strcmp(nationality,getCountry(procuraPassageiro(getDocumentNumber(gestorReservas->reserva)))) == 0) {
            if(getNumFlightsId(gestorReservas->reserva) == 2) {
                if(procuraContagem(contaPassageirosos,getDestination((getFlightsId(gestorReservas->reserva))[1])) == -1) {
                    struct listaContagem* celula = malloc(sizeof(struct listaContagem));
                    celula->code = getDestination((getFlightsId(gestorReservas->reserva))[1]);
                    celula->cont = 1;
                    contaAeroportos->soma = 0;
                    celula->next = contaPassageiros;
                    contaPassageiros = celula;
                }
                else {
                    int ind = procuraContagem(contaPassageiros,getDestination((getFlightsId(gestorReservas->reserva))[1]));
                    ListaContagem** apontador = &contaPassageiros;
                    while((*apontador) != NULL && ind>0) {
                        (*apontador) = (*apontador)->next;
                        ind--;
                    }
                    (*apontador)->cont++;
                }
            }
            else {
                if(procuraContagem(contaPassageirosos,getDestination((getFlightsId(gestorReservas->reserva))[0])) == -1) {
                    struct listaContagem* celula = malloc(sizeof(struct listaContagem));
                    celula->code = getDestination((getFlightsId(gestorReservas->reserva))[0]);
                    celula->cont = 1;
                    contaAeroportos->soma = 0;
                    celula->next = contaPassageiros;
                    contaPassageiros = celula;
                }
                else {
                    int ind = procuraContagem(contaPassageiros,getDestination((getFlightsId(gestorReservas->reserva))[0]));
                    ListaContagem** apontador = &contaPassageiros;
                    while((*apontador) != NULL && ind>0) {
                        (*apontador) = (*apontador)->next;
                        ind--;
                    }
                    (*apontador)->cont++;
                }
            }
        }
    }
    ListaContagem** apMax = &contaPassageiros;
    ListaContagem** aux = &contaPassageiros;

    while(*aux != NULL) {
        if((*aux)->cont > (*apMax)->cont) *apMax = *aux;
        *aux=(*aux)->next;
    }

    char** resultados = malloc(1 * sizeof(char*));
    resultados[1] = malloc(100 * sizeof(char));
    int r = snprintf (resultados[1], 100, "%s;%d\n",(*apMax)->code,(*apMax)->cont);
        if(r < 0){
        perror("Erro a imprimir a querie1\n");
        }
    resultados[2] = NULL;

    destruirLista(contaPassageiros);

    return resultados;
    
}