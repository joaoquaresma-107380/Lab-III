#include "VooParser.h"

Voo* tokensToVoo (char** tokens) {
    Voo* x = createVoo(tokens[0],stringToDate(tokens[2]), stringToDate(tokens[4]), stringToDate(tokens[6]), stringToDate(tokens[8]),atoi(tokens[10]),tokens[12],tokens[14],tokens[16], tokens[18],tokens[20],tokens[22]);
    return x;
    
}

void readFileVoo(FILE* stream, Manager_Voos* mv, GestorAviao* mae) {
    char* line = NULL;
    char* lineAux = NULL;
    size_t read;
    size_t len; // Sera definido pela funcao getline quando alocar espaço para a string
    FILE* flightsErrors = abrirFicheiroEscrita("dataset-errors/flights.csv");
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

            int length = tamanhoTokens(tokens);
            for(int i = 0; i < length; i++) free(tokens[i]);
            free(lineAux);
            free(tokens);
        }
    }

        free(line); // preciso libertar a mem´oria alocada
        fecharFicheiro(flightsErrors);
}

