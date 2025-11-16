#include "AeroportoParser.h"

Aeroporto* tokensToAeroporto (char** tokens) {
    Aeroporto* a = createAeroporto(tokens[0],tokens[2], tokens[4], tokens[6], atof(tokens[8]), atof(tokens[10]),tokens[12],tokens[14]);
    return a;
    
}

void readFileAeroporto(FILE* stream,Manager_Aeroportos* mae) {
    char* line = NULL;
    char* lineAux = NULL;
    size_t read;
    size_t len; // Sera definido pela funcao getline quando alocar espaço para a string
    FILE* airportsErrors = abrirFicheiroEscrita("dataset-errors/airports.csv");

    if ((read = getline(&line, &len, stream)) != -1) {
        if (escreveFicheiro(line, airportsErrors) < 0) perror("Erro na escrita para airportsErrors.csv");
        
        while ((read = getline(&line, &len, stream)) != -1) {
            lineAux = strdup(line);
            char** tokens = parseLine(lineAux);
            if (validacaoSintaticaAeroporto(tokens) == 0) {
                Aeroporto* a = tokensToAeroporto(tokens);
                adicionaAeroporto(a, mae);
            }
            else escreveFicheiro(line, airportsErrors);

            int length = tamanhoTokens(tokens);
            for(int i = 0; i < length; i++) free(tokens[i]);
            free(lineAux);
            free(tokens);
        }
    }
    
    free(line); // preciso libertar a mem´oria alocada
    fecharFicheiro(airportsErrors);
}
