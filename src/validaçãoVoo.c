#include "stdio.h"
#include "data.h"

int validarVooId(char* token) {
    // validar identificador de voo
    if((strlen(token)==7) 
            && ((token[0]>=65 && token[0]<=90)
                && (token[1]>=65 && token[1]<=90))
            && ((token[2]>=48 && token[2]<=57)
                && (token[3]>=48 && token[3]<=57)
                && (token[4]>=48 && token[4]<=57)
                && (token[5]>=48 && token[5]<=57)
                && (token[6]>=48 && token[6]<=57)
                && (token[7]>=48 && token[7]<=57))) {
        return 1;
    }
    else return 0;
}

int validacaoSintaticaVoo(char** tokens) {
    int n = 0;
    // validar identificador de voo
    if(validarVooId(tokens[0]) == 0) {
        n++;
    }
    // validaçao datas
    if ((validacaoData(tokens[1]) == 0)
        || (validacaoData(tokens[2]) == 0)
        || (validacaoData(tokens[3]) == 0)
        || (validacaoData(tokens[4]) == 0)) {
            n++;
        }
    if (n>0) {
        return 0;
    }
    else {
        return 1;
    }
}

int validacaoLogicaVoo(char** tokens, Manager_Aeronaves* mae) { // preciso manager aeronaves
    int n = 0;
    if (atoi(tokens[7]) == atoi(tokens[8])) n++;
    if (compararDataHora(tokens[1],tokens[3]) != 1) n++;
    if (compararDataHora(tokens[2],tokens[4]) != 1) n++;
    if (encontrarAviao(mae,tokens[9]) == NULL) n++;
    if(strcmp(tokens[6],"Cancelled") == 0
        && (strcmp(tokens[3],"N/A") != 0
            || strcmp(tokens[4],"N/A") != 0)) n++;
    if(strcmp(tokens[6],"Delayed") == 0
        && (compararDataHora(tokens[1],tokens[2]) == -1
            || compararDataHora(tokens[3],tokens[4]) == -1)) n++;
    if (n>0) {
        return 0;
    }
    else {
        return 1;
    }
}

int validacaoVoo(char** tokens, Manager_Aeronaves* mae) { // preciso manager aeronaves
    if ((!validacaoSitaticaVoo(tokens))
        || (!validacaoLogicaVoo(tokens))) return 0;
    else return 1;
}