#include "PassageiroParser.h"

Passageiro* tokensToPassageiro (char** tokens) {
    Passageiro* x = criarPassageiro(atoi(tokens[0]),tokens[1], tokens[2], stringToDate(tokens[3]), tokens[4],tokens[5][0], tokens[6],tokens[7],tokens[8],tokens[9]);
    return x;
    
}

void readFilePassageiro(FILE* stream, GestorPassageiros* mp) {
    char* line = NULL;
    char* lineAux = NULL;
    size_t read;
    size_t len; // Sera definido pela funcao getline quando alocar espaço para a string
    FILE* passengersErrors = abrirFicheiroEscrita("datasetErros/passengers.csv");
    if ((read = getline(&line, &len, stream)) != -1) {
        if(escreveFicheiro(line, passengersErrors) < 0) perror("Erro na escrita para passengersErrors.csv");
        while ((read = getline(&line, &len, stream)) != -1) {
            lineAux = strdup(line);
            char** tokens = parseLine(line);
            if (validacaoSintaticaPassageiro(tokens)==0) {
                Passageiro* a = tokensToPassageiro(tokens);
                addPassageiro(mp,a);
            }
            else escreveFicheiro(line, passengersErrors);
        }
    }
        free(lineAux);
        free(line); // preciso libertar a mem´oria alocada
        fecharFicheiro(passengersErrors);
}

