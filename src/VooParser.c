#include "VooParser.h"

Voo* tokensToVoo (char** tokens) {
    Voo* x;
    x = createVoo(tokens[0],stringToDate(tokens[1]), stringToDate(tokens[2]), stringToDate(tokens[3]), stringToDate(tokens[4]),atoi(tokens[5]),tokens[6],tokens[7],tokens[8], tokens[9],tokens[10],tokens[11]);
    return x;
    
}

void readFileVoo(FILE* stream, Manager_Voos* mv, GestorAviao* mae) {
    char* line = NULL;
    size_t read;
    size_t len; // Sera definido pela funcao getline quando alocar espaço para a string
    FILE* flightsErrors = abrirFicheiroEscrita("datasetErros/flights.csv");
    if ((read = getline(&line, &len, stream)) != -1) {
        char** campos = parseLine(line);
        escreveFicheiro(tokensToString(campos), flightsErrors);
        while ((read = getline(&line, &len, stream)) != -1) {
            char** tokens = parseLine(line);
            if (validacaoVoo(tokens, mae)) {
                Voo* a = tokensToVoo(tokens);
                adicionaVoo(mv,a);
            }
            else escreveFicheiro(tokensToString(tokens), flightsErrors);
        }
    }
        free(line); // preciso libertar a mem´oria alocada
        fecharFicheiro(flightsErrors);
}

