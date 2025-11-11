#include "stdio.h"
#include "aeroporto.h"

Aeroporto* tokensToAeroporto (char** tokens) {
    int n = 1;
    Aeroporto* a;
    a = createAeroporto(tokens[0],tokens[1], tokens[2], tokens[3], tokens[4],tokens[5],tokens[6],tokens[7]);
    return a;
    
}

void readFileAeroporto(FILE* stream,Manager_Aeroportos* mae) {
    char* line = NULL;
    size_t read;
    size_t len; // Sera definido pela funcao getline quando alocar espaço para a string
    FILE* airportsErrors;
    if ((read = getline(&line, &len, stream)) != -1) {
        char** campos = parseLine(line);
        airportsErrors = abrirFicheiroEscrita("datasetErros/airports.csv");
        escreveFicheiro(campos, airportsErrors);
        while ((read = getline(&line, &len, stream)) != -1) {
            char** tokens = parseLine(line);
            if (validacaoSintaticaAeroporto(tokens)) {
                Aeroporto* a = tokensToAeroporto(tokens);
                inserirAeroporto(mae,a);
            }
            else escreveFicheiro(tokens, airportsErrors);
        }
    }
    free(line); // preciso libertar a mem´oria alocada
    fecharFicheiro(airportsErrors);
}