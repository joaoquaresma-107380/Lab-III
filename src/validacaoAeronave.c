
int validacaoSintaticaAeronave(char** tokens) {
    int n = 0;
    // validar ano
    if (strlen(tokens[3]) != 4) n++;
    if (strlen(tokens[3]) == 4) {
        if (atoi(tokens[3])>2025) n++;
    }
    if (n>0) {
        return 0;
    }
    else {
        return 1;
    }
}
