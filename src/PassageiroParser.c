#include "PassageiroParser.h"

Passageiro* tokensToPassageiro (char** tokens) {
    Passageiro* x;
    x = criarPassageiro(atoi(tokens[0]),tokens[1], tokens[2], stringToDate(tokens[3]), tokens[4],tokens[5][0], tokens[6],tokens[7],tokens[8],tokens[9]);
    return x;
    
}

void readFilePassageiro(FILE* stream, GestorPassageiros* mp) {
    char* line = NULL;
    size_t read;
    size_t len; // Sera definido pela funcao getline quando alocar espaço para a string
    FILE* passengersErrors = abrirFicheiroEscrita("datasetErros/passengers.csv");
    if ((read = getline(&line, &len, stream)) != -1) {
        char** campos = parseLine(line);
        escreveFicheiro(tokensToString(campos), passengersErrors);
        while ((read = getline(&line, &len, stream)) != -1) {
            char** tokens = parseLine(line);
            if (validacaoSintaticaPassageiro(tokens)) {
                Passageiro* a = tokensToPassageiro(tokens);
                addPassageiro(mp,a);
            }
            else escreveFicheiro(tokensToString(tokens), passengersErrors);
        }
    }
        free(line); // preciso libertar a mem´oria alocada
        fecharFicheiro(passengersErrors);
}

