#include "passageiro.h"
#include "stdio.h"

Passageiro* tokensToPassageiro (char** tokens) {
    int n = 1;
    Passageiro* x;
    x = createPassageiro(tokens[0],tokens[1], tokens[2], stringToDate(tokens[3]), tokens[4],tokens[5],tokens[6],tokens[7]);
    return x;
    
}

void readFilePassageiro(FILE* stream, Manager_Passageiros* mp) {
    char* line = NULL;
    size_t read;
    size_t len; // Sera definido pela funcao getline quando alocar espaço para a string
    FILE* passengersErrors;
    if ((read = getline(&line, &len, stream)) != -1) {
        char** campos = parseLine(line);
        passengersErrors = abrirFicheiroEscrita("datasetErros/passengers.csv");
        escreveFicheiro(campos, passengersErrors);
        while ((read = getline(&line, &len, stream)) != -1) {
            char** tokens = parseLine(line);
            if (validacaoSintaticaPassageiro(tokens)) {
                Passageiro* a = tokensToPassageiro(tokens);
                inserirPassageiro(mp,a);
            }
            else escreveFicheiro(tokens, passengersErrors);
        }
    }
        free(line); // preciso libertar a mem´oria alocada
        fecharFicheiro(passengersErrors);
}