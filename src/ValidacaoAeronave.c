#include "ValidacaoAeronave.h"

int validacaoSintaticaAeronave(char** tokens) {
    int n = 0;
    // validar ano
    if (strlen(tokens[6]) != 4) n++;
    else {
        if (atoi(tokens[6])>2025 || atoi(tokens[6])<1970) n++;
    }
    return n;
}
