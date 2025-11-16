#include "ValidacaoPassageiro.h"

int validacaoSintaticaPassageiro(char** tokens) {
    int n = 0;
    // validar email
    int i = 0; int j = 1;int r = 1;

    for(;tokens[12][i]!='@' && i<strlen(tokens[12]);i++) {
        if(!((tokens[12][i]>=97 && tokens[12][i]<=122) || (tokens[12][i]>=48 && tokens[12][i]<=57) || tokens[12][i] == '.')) {
        n++;
        }
    }
    if (i>=strlen(tokens[12])) {
        n++;
    }
    else {
        for(;tokens[12][j+i]!='.' && j+i<strlen(tokens[12]);j++) {
            if(!(tokens[12][j+i]>=97 && tokens[12][j+i]<=122)) n++;
        }
        if (j<2 || j+i>=strlen(tokens[12])) {
            n++;
        }
        else {
            for(;r+i+j!=(strlen(tokens[12]));r++) {
                if(!(tokens[12][r+i+j]>=97 && tokens[12][r+i+j]<=122)) n++;
            }
            if (r!=3 && r!=4) n++;
        }
    }
    // validaçao data
    if ((validacaoData(tokens[6]) == 0)) {
            n++;
        }
    return n;
}
