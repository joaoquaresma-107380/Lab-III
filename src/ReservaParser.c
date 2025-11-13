#include "ReservaParser.h"

Reserva* tokensToReserva (char** tokens) {
    Reserva* r;
    r = createReserva(tokens[0],tamanhoArrayFlights(tokens[1]), tokenToArrayChar(tokens[2]), atoi(tokens[3]), tokens[4],atof(tokens[5]),tokens[6],tokens[7], tokens[8]);
    return r;
    
}

void readFileReserva(FILE* stream, Manager_Reservas* mr, Manager_Voos* mv, GestorPassageiros* mp) {
    char* line = NULL;
    size_t read;
    size_t len; // Sera definido pela funcao getline quando alocar espaço para a string
    FILE* reservationsErrors = abrirFicheiroEscrita("datasetErros/reservations.csv");
    if ((read = getline(&line, &len, stream)) != -1) {
        char** campos = parseLine(line);
        escreveFicheiro(tokensToString(campos), reservationsErrors);
        while ((read = getline(&line, &len, stream)) != -1) {
            char** tokens = parseLine(line);
            if (validacaoReserva(tokens,mv,mp)) {
                Reserva* r = tokensToReserva(tokens);
                adicionaReserva(r,mr);
            }
            else escreveFicheiro(tokensToString(tokens), reservationsErrors);
        }
    }
        free(line); // preciso libertar a mem´oria alocada
        fecharFicheiro(reservationsErrors);
}

