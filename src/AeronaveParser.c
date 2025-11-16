#include "AeronaveParser.h"
#include "ValidacaoAeronave.h"

Aeronave* tokensToAeronave (char** tokens) {
    Aeronave* x = criarAviao(tokens[0],tokens[2], tokens[4], atoi(tokens[6]), atoi(tokens[8]),atoi(tokens[10]),0);
    return x; 
}

void readFileAeronave(FILE* stream, GestorAviao* ma) {
    char* line = NULL;
    char* lineAux = NULL;
    size_t read;
    size_t len; // Sera definido pela funcao getline quando alocar espaço para a string
    FILE* aircraftsErrors = abrirFicheiroEscrita("dataset-errors/aircrafts.csv");
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

                 int length = tamanhoTokens(tokens);
                for(int i = 0; i < length; i++) free(tokens[i]);
                free(lineAux);
                free(tokens);
            }

    }

    free(line); // preciso libertar a mem´oria alocada
    fecharFicheiro(aircraftsErrors);
}

