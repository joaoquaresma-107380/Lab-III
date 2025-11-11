#include "reserva.h"
#include "stdio.h"

Reserva* tokensToReserva (char** tokens) {
    int n = 1;
    Reserva* r;
    r = createReserva(tokens[0],tokens[1], tokens[2], tokens[3], tokens[4],tokens[5],tokens[6],tokens[7]);
    return r;
    
}

void readFileReserva(FILE* stream, Manager_Reservas* mr, Manager_Voos* mv, Manager_Passageiros* mp) {
    char* line = NULL;
    size_t read;
    size_t len; // Sera definido pela funcao getline quando alocar espaço para a string
    FILE* reservationsErrors;
    if ((read = getline(&line, &len, stream)) != -1) {
        char** campos = parseLine(line);
        reservationsErrors = abrirFicheiroEscrita("datasetErros/reservationss.csv");
        escreveFicheiro(campos, reservationsErrors);
        while ((read = getline(&line, &len, stream)) != -1) {
            char** tokens = parseLine(line);
            if (validacaoReserva(tokens)) {
                Reserva* r = tokensToReserva(tokens);
                inserirReserva(mr,r);
            }
            else escreveFicheiro(tokens, reservationsErrors);
        }
    }
        free(line); // preciso libertar a mem´oria alocada
        fecharFicheiro(reservationsErrors);
}