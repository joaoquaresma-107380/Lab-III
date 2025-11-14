#include "AeronaveParser.h"
#include "ValidacaoAeronave.h"

Aeronave* tokensToAeronave (char** tokens) {
    Aeronave* x = criarAviao(tokens[0],tokens[1], tokens[2], atoi(tokens[3]), atoi(tokens[4]),atoi(tokens[5]),0);
    return x; 
}

void readFileAeronave(FILE* stream, GestorAviao* ma) {
    char* line = NULL;
    char* lineAux = NULL;
    size_t read;
    size_t len; // Sera definido pela funcao getline quando alocar espaço para a string
    FILE* aircraftsErrors = abrirFicheiroEscrita("datasetErros/aircrafts.csv");
    if ((read = getline(&line, &len, stream)) != -1) {
        if(escreveFicheiro(line, aircraftsErrors) < 0) perror("Erro na escrita para aircraftsErrors.csv");
           
            while ((read = getline(&line, &len, stream)) != -1) {
                lineAux = strdup(line);
                char** tokens = parseLine(lineAux);
                if (validacaoSintaticaAeronave(tokens) == 0) {
                    Aeronave* a = tokensToAeronave(tokens);
                    addAviao(ma,a);
                }
                else escreveFicheiro(line, aircraftsErrors);
            }

    }
    free(lineAux);
    free(line); // preciso libertar a mem´oria alocada
    fecharFicheiro(aircraftsErrors);
}

