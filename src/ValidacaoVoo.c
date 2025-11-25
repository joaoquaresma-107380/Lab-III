#include "ValidacaoVoo.h"

int validarVooId(char* token) {
    int n = 0;
    if(token == NULL) return 1;
    // validar identificador de voo
    if(strlen(token)!=7) n++;
    if((token[0]<65 || token[0]>90) || (token[1]<65 || token[1]>90)) n++;
    if(!((token[2]>=48 && token[2]<=57)
        && (token[3]>=48 && token[3]<=57)
        && (token[4]>=48 && token[4]<=57)
        && (token[5]>=48 && token[5]<=57)
        && (token[6]>=48 && token[6]<=57))) n++;
    return n;
}

int validacaoSintaticaVoo(char** tokens) {
    int n = 0;
    // validar identificador de voo
    if(validarVooId(tokens[0]) != 0) {
        n++;
    }
    // validaçao datas
    if ((validacaoData(tokens[2]) != 0)
        || (validacaoData(tokens[4]) != 0)
        || (validacaoData(tokens[6]) != 0)
        || (validacaoData(tokens[8]) != 0)) {
            n++;
        }
    return n;
}

int validacaoLogicaVoo(char** tokens, GestorAviao* mae) { // preciso manager aeronaves
    int n = 0;
    if (strcmp(tokens[14],tokens[16]) == 0) n++;

    Data* departure = stringToDate(tokens[2]);
    Data* arrival = stringToDate(tokens[6]);
    Data* actual_departure = stringToDate(tokens[4]);
    Data* actual_arrival = stringToDate(tokens[8]);
    
    if (compararDataHora(departure,arrival) != 1) n++;
    if (compararDataHora(actual_departure,actual_arrival) != 1) n++;
    if (encontrarAviao(mae,tokens[18]) == NULL) n++;
    if(strcmp(tokens[13],"Cancelled") == 0
        && (strcmp(tokens[7],"N/A") != 0
            || strcmp(tokens[9],"N/A") != 0)) n++;
    if(strcmp(tokens[13],"Delayed") == 0
        && (compararDataHora(departure,actual_departure) == -1
            || compararDataHora(arrival,actual_arrival) == -1)) n++;

            destroiData(departure);
            destroiData(arrival);
            destroiData(actual_departure);
            destroiData(actual_arrival);
            
    return n;
}

int validacaoVoo(char** tokens, GestorAviao* mae) { // preciso manager aeronaves
    int n = validacaoSintaticaVoo(tokens) + validacaoLogicaVoo(tokens,mae);
    return n;
}
