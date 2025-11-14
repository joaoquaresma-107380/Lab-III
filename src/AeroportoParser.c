#include "AeroportoParser.h"

Aeroporto* tokensToAeroporto (char** tokens) {
    Aeroporto* a = createAeroporto(tokens[0],tokens[1], tokens[2], tokens[3], atof(tokens[4]), atof(tokens[5]),tokens[6],tokens[7]);
    return a;
    
}

void readFileAeroporto(FILE* stream,Manager_Aeroportos* mae) {
    char* line = NULL;
    char* lineAux = NULL;
    size_t read;
    size_t len; // Sera definido pela funcao getline quando alocar espaço para a string
    FILE* airportsErrors = abrirFicheiroEscrita("datasetErros/airports.csv");

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
        }
    }
    free(lineAux);
    free(line); // preciso libertar a mem´oria alocada
    fecharFicheiro(airportsErrors);
}
