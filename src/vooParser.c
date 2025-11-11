#include "voo.h"
#include "stdio.h"

Voo* tokensToVoo (char** tokens) {
    int n = 1;
    Voo* x;
    x = createVoo(tokens[0],tokens[1], tokens[2], tokens[3], tokens[4],tokens[5],tokens[6],tokens[7]);
    return x;
    
}

int validacaoLogicaVoo(Voo* v) {
    int n = 0;
    // validar o destination e origin
   if (strcmp(v->departure,v->origin) == 0) n++;
   if (compararDataHora(v->departure,v->arrival) != -1) n++;
   if (compararDataHora(v->actual_departure,v->actual_arrival) != -1) n++;
   // if (procuraAeronave(v->aircraft) == -1) n++; -- nao sei se da para procurar pq ainda nao estam inseridas as aeronaves
   // if((strcmp(v->status,"Cancelled") == 0)
   // && (strcmp(v->actual_arrival,"N/A")!=0 || strcmp(v->actual_derpature,"N/A")!=0)) n++;

    if (n>0) {
        return 0;
    }
    else {
        return 1;
    }
}

void readFileVoo(FILE* stream, Manager_Voos* mv, Manager_Aeronaves* mae) {
    char* line = NULL;
    size_t read;
    size_t len; // Sera definido pela funcao getline quando alocar espaço para a string
    FILE* flightsErrors;
    if ((read = getline(&line, &len, stream)) != -1) {
        char** campos = parseLine(line);
        flightsErrors = abrirFicheiroEscrita("datasetErros/flights.csv");
        escreveFicheiro(campos, flightsErrors);
        while ((read = getline(&line, &len, stream)) != -1) {
            char** tokens = parseLine(line);
            if (validacaoVoo(tokens)) {
                Voo* a = tokensToVoo(tokens);
                inserirVoo(mv,a);
            }
            else escreveFicheiro(tokens, flightsErrors);
        }
    }
        free(line); // preciso libertar a mem´oria alocada
        fecharFicheiro(flightsErrors);
}