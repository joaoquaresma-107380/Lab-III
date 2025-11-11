#include "stdio.h"
#include "utilsParser.h"

int validacaoSintaticaPassageiro(char** tokens) {
    int n = 0;
    // validar email
    int i = 0; int j = 0;int r = 0;
    for(tokens[6][i]!='@';i++) {
        if(!((tokens[6][i]>=97 && tokens[6][i]<=122) || (tokens[6][i]>=48 && tokens[6][i]<=57))) {
        n++;
        }
    }
    if (i>=strlen(tokens[6])) n++;
    for(tokens[6][j]!='.';j++) {
        if(!(tokens[6][j]>=97 && tokens[6][j]<=122)) {
        n++;
        }
    }
    if (j<0 || j>=strlen(tokens[6])-i) n++;

    for(tokens[6][r]!=(strlen(tokens[6])-i-j);r++) {
        if(!(tokens[6][r]>=97 && tokens[6][r]<=122)) {
        n++;
        }
    }
    if (r<(1) || r>(2)) n++;
    // validaçao data
    if ((validacaoData(tokens[3]) == 0)) {
            n++;
        }
    if (n>0) {
        return 0;
    }
    else {
        return 1;
    }
}