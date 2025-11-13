#include "AeronaveParser.h"
#include "ValidacaoAeronave.h"

Aeronave* tokensToAeronave (char** tokens) {
    Aeronave* x = criarAviao(tokens[0],tokens[1], tokens[2], atoi(tokens[3]), atoi(tokens[4]),atoi(tokens[5]),atoi(tokens[6]));
    return x; 
}

void readFileAeronave(FILE* stream, GestorAviao* ma) {
    char* line = NULL;
    size_t read;
    size_t len; // Sera definido pela funcao getline quando alocar espaço para a string
    FILE* aircraftsErrors = abrirFicheiroEscrita("datasetErros/aircrafts.csv");
    if ((read = getline(&line, &len, stream)) != -1) {
        char** campos = parseLine(line);
        escreveFicheiro(tokensToString(campos), aircraftsErrors);
        while ((read = getline(&line, &len, stream)) != -1) {
            char** tokens = parseLine(line);
                if (validacaoSintaticaAeronave(tokens)) {
                    Aeronave* a = tokensToAeronave(tokens);
                    addAviao(ma,a);
                }
                else escreveFicheiro(tokensToString(tokens), aircraftsErrors);
        }
    }
    free(line); // preciso libertar a mem´oria alocada
    fecharFicheiro(aircraftsErrors);
}

