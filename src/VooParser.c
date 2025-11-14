#include "VooParser.h"

Voo* tokensToVoo (char** tokens) {
    Voo* x = createVoo(tokens[0],stringToDate(tokens[1]), stringToDate(tokens[2]), stringToDate(tokens[3]), stringToDate(tokens[4]),atoi(tokens[5]),tokens[6],tokens[7],tokens[8], tokens[9],tokens[10],tokens[11]);
    return x;
    
}

void readFileVoo(FILE* stream, Manager_Voos* mv, GestorAviao* mae) {
    char* line = NULL;
    char* lineAux = NULL;
    size_t read;
    size_t len; // Sera definido pela funcao getline quando alocar espaço para a string
    FILE* flightsErrors = abrirFicheiroEscrita("datasetErros/flights.csv");
    if ((read = getline(&line, &len, stream)) != -1) {
        if(escreveFicheiro(line, flightsErrors) < 0) perror("Erro na escrita para fligthsErrors.csv");
        while ((read = getline(&line, &len, stream)) != -1) {
            lineAux = strdup(line);
            char** tokens = parseLine(lineAux);
            if (validacaoVoo(tokens, mae)==0) {
                Voo* a = tokensToVoo(tokens);
                adicionaVoo(mv,a);
            }
            else escreveFicheiro(line, flightsErrors);
        }
    }
        free(lineAux);
        free(line); // preciso libertar a mem´oria alocada
        fecharFicheiro(flightsErrors);
}

