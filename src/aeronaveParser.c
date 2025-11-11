#include "aeronave.h"
#include "stdio.h"

Aeronave* tokensToAeronave (char** tokens) {
    int n = 1;
    Aeronave* x;
    x = createAeronave(tokens[0],tokens[1], tokens[2], tokens[3], tokens[4],tokens[5],tokens[6],tokens[7]);
    return x; 
}

void readFileAeronave(FILE* stream, Manager_Aeroporto* ma) {
    char* line = NULL;
    size_t read;
    size_t len; // Sera definido pela funcao getline quando alocar espaço para a string
    FILE* aircraftsErrors;
    if ((read = getline(&line, &len, stream)) != -1) {
        char** campos = parseLine(line);
        aircraftsErrors = abrirFicheiroEscrita("datasetErros/aircrafts.csv");
        escreveFicheiro(campos, aircraftsErrors);
        while ((read = getline(&line, &len, stream)) != -1) {
            char** tokens = parseLine(line);
                if (validacaoSintaticaAeronave(tokens)) {
                    Aeronave* a = tokensToAeronave(tokens);
                    inserirAeronave(ma,a);
                }
                else escreveFicheiro(tokens, aircraftsErrors);
        }
    }
    free(line); // preciso libertar a mem´oria alocada
    fecharFicheiro(aircraftsErrors);
}