#include "ReservaParser.h"

Reserva* tokensToReserva (char** tokens) {
    Reserva* r = createReserva(tokens[0],tamanhoArrayFlights(tokens[2]), tokenToArrayChar(tokens[2]), atoi(tokens[4]), tokens[6],atof(tokens[8]),tokens[10],tokens[12], tokens[14]);
    return r;
    
}

void readFileReserva(FILE* stream, Manager_Reservas* mr, Manager_Voos* mv, GestorPassageiros* mp) {
    char* line = NULL;
    char* lineAux = NULL;
    size_t read;
    size_t len; // Sera definido pela funcao getline quando alocar espaço para a string
    FILE* reservationsErrors = abrirFicheiroEscrita("dataset-errors/reservations.csv");
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

            int length = tamanhoTokens(tokens);
            for(int i = 0; i < length; i++) free(tokens[i]);
            free(lineAux);
            free(tokens);
        }
    }

        free(line); // preciso libertar a mem´oria alocada
        fecharFicheiro(reservationsErrors);
}

