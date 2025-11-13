#include "ValidacaoReserva.h"

int tamanhoArrayFlights(char* token) {
    int n = 0;
    int tamanho = strlen(token);
    for(int i = 0;i<tamanho;i++) {
        if (token[i] == ',') n++; 
    }
    return n;
}

char** tokenToArrayChar(char* token) {
    int tamanho = tamanhoArrayFlights(token);
    char** aux = malloc(tamanho * sizeof(char*));
    int m = 0;
    int i = 0;
    int j = 2;
    while(j<strlen(token)-2) {
        if(token[j] != ',') {
            aux[m][i] = token[i];
            i++;
            j++;
        }
        else {
        m++;
        i = 0;
        j=j+2;
        }
    }
    return aux;
}

int validacaoSintaticaReserva(char** tokens) {
    int n = 0;
    // validar lista de flights id
    char** aux;
    if (tamanhoArrayFlights(tokens[1]) == 1) {
        aux = tokenToArrayChar(tokens[1]);
        if (validarVooId(aux[0]) == 0) {
            n++;
        }
    }
    if (tamanhoArrayFlights(tokens[1]) == 2) {
        aux = tokenToArrayChar(tokens[1]);
        if (validarVooId(aux[0]) == 0 || validarVooId(aux[1]) == 0) {
            n++;
        }
    }
    // validar identificador reserva
    if(!(strlen(tokens[0])==10 
            && tokens[0][0]=='R' 
            && ((tokens[0][1]>=48 && tokens[0][1]<=57)
                && (tokens[0][2]>=48 && tokens[0][2]<=57)
                && (tokens[0][3]>=48 && tokens[0][3]<=57)
                && (tokens[0][4]>=48 && tokens[0][4]<=57)
                && (tokens[0][5]>=48 && tokens[0][5]<=57)
                && (tokens[0][6]>=48 && tokens[0][6]<=57)
                && (tokens[0][7]>=48 && tokens[0][7]<=57)
                && (tokens[0][8]>=48 && tokens[0][8]<=57)
                && (tokens[0][9]>=48 && tokens[0][9]<=57)))) {
        n++;
    }
    // validar o número de documento
    if(!(strlen(tokens[2])==9  
            && ((tokens[2][1]>=48 && tokens[2][1]<=57)
                && (tokens[2][2]>=48 && tokens[2][2]<=57)
                && (tokens[2][3]>=48 && tokens[2][3]<=57)
                && (tokens[2][4]>=48 && tokens[2][4]<=57)
                && (tokens[2][5]>=48 && tokens[2][5]<=57)
                && (tokens[2][6]>=48 && tokens[2][6]<=57)
                && (tokens[2][7]>=48 && tokens[2][7]<=57)
                && (tokens[2][8]>=48 && tokens[2][8]<=57)))) {
        n++;
    }
    if (n>0) {
        return 0;
    }
    else {
        return 1;
    }
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
        if (strcmp(getOrigin(procuraVoo(mv,aux[1])),getDestination(procuraVoo(mv,aux[0]))) != 0) n++;
    }
    if (encontrarPassageiro(mp,atoi(tokens[2]))==NULL) n++;
    if (n>0) {
        return 0;
    }
    else {
        return 1;
    }
}

int validacaoReserva(char** tokens, Manager_Voos* mv, GestorPassageiros* mp) { // preciso receber manager voos e manager passageiros
    if ((!validacaoSintaticaReserva(tokens))
        || (!validacaoLogicaReserva(tokens, mv, mp))) return 0;
    else return 1;
}
