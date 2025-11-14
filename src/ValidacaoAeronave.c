#include "ValidacaoAeronave.h"

int validacaoSintaticaAeronave(char** tokens) {
    int n = 0;
    // validar ano
    if (strlen(tokens[3]) != 4) n++;
    else {
        if (atoi(tokens[3])>2025 || atoi(tokens[3])<1970) n++;
    }
    return n;
}
