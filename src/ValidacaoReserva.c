#include "ValidacaoReserva.h"

void eliminaCaracteres(char* s){
        int i = 0;
        for(;i<strlen(s)-2;i++) {
            s[i] = s[i+1];
        }
        s[i] = '\0';
}

int tamanhoArrayFlights(char* token) {
    if(token == NULL) return 0;
    int n = 1;
    for(int i = 0;i<strlen(token);i++) {
        if (token[i] == ',') n++; 
    }
    return n;
}

char** tokenToArrayChar(char* token) {
    int n = tamanhoArrayFlights(token);
    char** array = malloc(n*sizeof(char*));
    char* aux = strdup(token);
    eliminaCaracteres(aux);
    char* aux_free = aux;

    char* primeiro = strsep(&aux, ",");
    if(aux == NULL) {
        // so tem 1 voo
        eliminaCaracteres(primeiro);
        array[0] = primeiro;
    }
    else{ // tem 2 voos
        eliminaCaracteres(primeiro);
        eliminaCaracteres(aux);
        array[0] = primeiro;
        array[1] = aux;
    }

    free(aux_free);
    return array;
}

int validacaoSintaticaReserva(char** tokens) {
    int n = 0;

    
    // validar lista de flights id
    char* aux = strdup(tokens[1]);
    eliminaCaracteres(aux);
    char* aux_free = aux;

    char* primeiro = strsep(&aux, ",");
    if(aux == NULL) {
        // so tem 1 voo
        eliminaCaracteres(primeiro);
        if(validarVooId(primeiro) != 0) n++;
    }
    else{ // tem 2 voos
        eliminaCaracteres(primeiro);
        eliminaCaracteres(aux);
        if(validarVooId(primeiro) != 0 || validarVooId(aux) != 0) n++;
    }

    free(aux_free);


    // validar identificador reserva
    if(strlen(tokens[0])!=10) n++;

    if(tokens[0][0] != 'R') n++;
    if(!(tokens[0][1]>=48 && tokens[0][1]<=57)
            && (tokens[0][2]>=48 && tokens[0][2]<=57)
            && (tokens[0][3]>=48 && tokens[0][3]<=57)
            && (tokens[0][4]>=48 && tokens[0][4]<=57)
            && (tokens[0][5]>=48 && tokens[0][5]<=57)
            && (tokens[0][6]>=48 && tokens[0][6]<=57)
            && (tokens[0][7]>=48 && tokens[0][7]<=57)
            && (tokens[0][8]>=48 && tokens[0][8]<=57)
            && (tokens[0][9]>=48 && tokens[0][9]<=57)) n++;

    // validar o número de documento
    if(strlen(tokens[2])!=9) n++;
    if (!(tokens[2][0]>=48 && tokens[2][0]<=57)
                && (tokens[2][1]>=48 && tokens[2][1]<=57)
                && (tokens[2][2]>=48 && tokens[2][2]<=57)
                && (tokens[2][3]>=48 && tokens[2][3]<=57)
                && (tokens[2][4]>=48 && tokens[2][4]<=57)
                && (tokens[2][5]>=48 && tokens[2][5]<=57)
                && (tokens[2][6]>=48 && tokens[2][6]<=57)
                && (tokens[2][7]>=48 && tokens[2][7]<=57)
                && (tokens[2][8]>=48 && tokens[2][8]<=57)) n++;
    return n;
}


int validacaoLogicaReserva(char** tokens, Manager_Voos* mv, GestorPassageiros* mp) { // preciso receber manager voos e manager passageiros
    int n = 0;
    char** aux = tokenToArrayChar(tokens[1]);

    if (!(tamanhoArrayFlights(tokens[1]) == 1 || tamanhoArrayFlights(tokens[1]) == 2)) n++;
    if(tamanhoArrayFlights(tokens[1]) == 1) {
        if (procuraVoo(mv,aux[0]) == NULL) n++;
    }
    if(tamanhoArrayFlights(tokens[1]) == 2) {
        if ((procuraVoo(mv,aux[0]) == NULL)
            || (procuraVoo(mv,aux[1]) == NULL)) n++;
            printf("%s %s\n",aux[0],aux[1]);
        if (strcmp(getOrigin(procuraVoo(mv,aux[1])),getDestination(procuraVoo(mv,aux[0]))) != 0) n++;
    }
    if (encontrarPassageiro(mp,atoi(tokens[2]))==NULL) n++;
    return n;
}


int validacaoReserva(char** tokens, Manager_Voos* mv, GestorPassageiros* mp) { // preciso receber manager voos e manager passageiros
    int n = validacaoSintaticaReserva(tokens) + validacaoLogicaReserva(tokens,mv,mp);
    return n;
}
