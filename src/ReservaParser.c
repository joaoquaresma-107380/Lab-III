#include "ReservaParser.h"

Reserva* tokensToReserva (char** tokens) {
    Reserva* r = createReserva(tokens[0],tamanhoArrayFlights(tokens[1]), tokenToArrayChar(tokens[1]), atoi(tokens[2]), tokens[3],atof(tokens[4]),tokens[5],tokens[6], tokens[7]);
    return r;
    
}

void readFileReserva(FILE* stream, Manager_Reservas* mr, Manager_Voos* mv, GestorPassageiros* mp) {
    char* line = NULL;
    char* lineAux = NULL;
    size_t read;
    size_t len; // Sera definido pela funcao getline quando alocar espaço para a string
    FILE* reservationsErrors = abrirFicheiroEscrita("datasetErros/reservations.csv");
    if ((read = getline(&line, &len, stream)) != -1) {
        if(escreveFicheiro(line, reservationsErrors) < 0) perror("Erro na escrita para reservationsErrors.csv");

        while ((read = getline(&line, &len, stream)) != -1) {
            lineAux = strdup(line);
            char** tokens = parseLine(lineAux);
            if (validacaoReserva(tokens,mv,mp) == 0) {
                Reserva* r = tokensToReserva(tokens);
                adicionaReserva(r,mr);
            }
            else escreveFicheiro(line, reservationsErrors);
        }
    }
        free(lineAux);
        free(line); // preciso libertar a mem´oria alocada
        fecharFicheiro(reservationsErrors);
}

