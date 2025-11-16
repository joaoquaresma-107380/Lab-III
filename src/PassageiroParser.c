#include "PassageiroParser.h"

Passageiro* tokensToPassageiro (char** tokens) {
    Passageiro* x = criarPassageiro(atoi(tokens[0]),tokens[2], tokens[4], stringToDate(tokens[6]), tokens[8],tokens[10][0], tokens[12],tokens[14],tokens[16],tokens[18]);
    return x;
    
}

void readFilePassageiro(FILE* stream, GestorPassageiros* mp) {
    char* line = NULL;
    char* lineAux = NULL;
    size_t read;
    size_t len; // Sera definido pela funcao getline quando alocar espaço para a string
    FILE* passengersErrors = abrirFicheiroEscrita("dataset-errors/passengers.csv");
    if ((read = getline(&line, &len, stream)) != -1) {
        if(escreveFicheiro(line, passengersErrors) < 0) perror("Erro na escrita para passengersErrors.csv");
        while ((read = getline(&line, &len, stream)) != -1) {
            lineAux = strdup(line);
            char** tokens = parseLine(lineAux);
            if (validacaoSintaticaPassageiro(tokens)==0) {
                Passageiro* a = tokensToPassageiro(tokens);
                addPassageiro(mp,a);
            }
            else escreveFicheiro(line, passengersErrors);

            int length = tamanhoTokens(tokens);
            for(int i = 0; i < length; i++) free(tokens[i]);
            free(lineAux);
            free(tokens);
        }
    }

        free(line); // preciso libertar a mem´oria alocada
        fecharFicheiro(passengersErrors);
}

