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
    if (compararDataHora(stringToDate(tokens[2]),stringToDate(tokens[6])) != 1) n++;
    if (compararDataHora(stringToDate(tokens[4]),stringToDate(tokens[8])) != 1) n++;
    if (encontrarAviao(mae,tokens[18]) == NULL) n++;
    if(strcmp(tokens[13],"Cancelled") == 0
        && (strcmp(tokens[7],"N/A") != 0
            || strcmp(tokens[9],"N/A") != 0)) n++;
    if(strcmp(tokens[13],"Delayed") == 0
        && (compararDataHora(stringToDate(tokens[2]),stringToDate(tokens[4])) == -1
            || compararDataHora(stringToDate(tokens[6]),stringToDate(tokens[8])) == -1)) n++;
    return n;
}

int validacaoVoo(char** tokens, GestorAviao* mae) { // preciso manager aeronaves
    int n = validacaoSintaticaVoo(tokens) + validacaoLogicaVoo(tokens,mae);
    return n;
}
