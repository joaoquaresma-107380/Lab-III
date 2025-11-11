#include "stdio.h"
#include "utilsParser.h"

int validacaoSintaticaAeronave(char** tokens) {
    int n = 0;
    // validar ano
    if(validacaoData(tokens[3]) == 0) {
        n++;
    }
    if (n>0) {
        return 0;
    }
    else {
        return 1;
    }
}
