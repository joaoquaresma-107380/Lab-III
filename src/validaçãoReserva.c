#include "stdio.h"

int validacaoSintaticaReserva(char** tokens) {
    int n = 0;
    // validar lista de flights id
    int tamanho = strlen(tokens[1]);
    if(tokens[1][0] != '[' || tokens[1][tamanho-1] != ']') {
        n++;
    }
    int i = 1;
    int j = 0;
    int m = 0;
    char** aux;
    while(i<tamanho-1) {
        if(tokens[1][i] != ',') {
            aux[m][j] = tokens[1][j];
            j++;
        }
        else {
            m++;
            j = 0;
        }
        i++;
    }
    for(int r = 0;r<=m;r++) {
        if (validarVooId(tokens[0]) == 0) {
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

int validacaoLogicaReserva(char** tokens, Manager_Voos* mv, Manager_Passageiros* mp) { // preciso receber manager voos e manager passageiros
    int n = 0;
    if (strlen(tokens[1])>2 || strlen(tokens[1])<1) n++;
    if(strlen(tokens[1])==1) {
        if (procuraVoo(mv,tokens[1][0]) == NULL) n++;
    }
    if(strlen(tokens[1])==2) {
        if ((procuraVoo(mv,tokens[1][0]) == NULL)
            || (procuraVoo(mv,tokens[1][1]) == NULL)) n++;
        if (strcmp(getOrigin(procuraVoo(mv,tokens[1][1])),getDestination(procuraVoo(mv,tokens[1][0]))) != 0) n++;
    }
    if (encontrarPassageiro(mp,tokens[2])==NULL) n++;
    if (n>0) {
        return 0;
    }
    else {
        return 1;
    }
}

int validacaoReserva(char** tokens, Manager_Voos* mv, Manager_Passageiros* mp) { // preciso receber manager voos e manager passageiros
    if ((!validacaoSitaticaReserva(tokens))
        || (!validacaoLogicaReserva(tokens, mv, mp))) return 0;
    else return 1;
}