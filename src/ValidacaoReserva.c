#include "ValidacaoReserva.h"

// Função que elimina as pontas
void eliminaCaracteresPontas(char* s){
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
    char* aux_free = aux;

    eliminaCaracteresPontas(aux);
    
    char* primeiro = strsep(&aux, ",");

    if(aux == NULL) {
        // so tem 1 voo
        eliminaCaracteresPontas(primeiro);
        array[0] = strdup(primeiro);

        printf("PrimeiroPrint:%s tamanho array 0: %ld e %d\n",array[0],strlen(array[0]),tamanhoArrayFlights(token));
    }
    else{ // tem 2 voos
        eliminaCaracteresPontas(primeiro);
        eliminaCaracteresPontas(aux);
        int i = 0;
        for(;i<strlen(aux)-1;i++) {
            aux[i] = aux[i+1];
        }
        aux[i] = '\0';
        array[0] = strdup(primeiro);
        array[1] = strdup(aux);

        printf("PrimeiroPrint:%s %s tamanho array 0: %ld tamanho array 1: %ld e %d\n",array[0],array[1],strlen(array[0]),strlen(array[1]),tamanhoArrayFlights(token));
    }
    free(aux_free);
    return array;
}

int validacaoSintaticaReserva(char** tokens) {
    int n = 0;

    
    // validar lista de flights id
    char* aux = strdup(tokens[2]);
    eliminaCaracteresPontas(aux);
    char* aux_free = aux;

    char* primeiro = strsep(&aux, ",");
    if(aux == NULL) {
        // so tem 1 voo
        eliminaCaracteresPontas(primeiro);
        if(validarVooId(primeiro) != 0) n++;
    }
    else{ // tem 2 voos
        eliminaCaracteresPontas(primeiro);
        eliminaCaracteresPontas(aux);
        int i = 0;
        for(;i<strlen(aux)-1;i++) {
            aux[i] = aux[i+1];
        }
        aux[i] = '\0';
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
    if(strlen(tokens[4])!=9) n++;
    if (!(tokens[4][0]>=48 && tokens[4][0]<=57)
                && (tokens[4][1]>=48 && tokens[4][1]<=57)
                && (tokens[4][2]>=48 && tokens[4][2]<=57)
                && (tokens[4][3]>=48 && tokens[4][3]<=57)
                && (tokens[4][4]>=48 && tokens[4][4]<=57)
                && (tokens[4][5]>=48 && tokens[4][5]<=57)
                && (tokens[4][6]>=48 && tokens[4][6]<=57)
                && (tokens[4][7]>=48 && tokens[4][7]<=57)
                && (tokens[4][8]>=48 && tokens[4][8]<=57)) n++;
    return n;
}


int validacaoLogicaReserva(char** tokens, Manager_Voos* mv, GestorPassageiros* mp) { // preciso receber manager voos e manager passageiros
    int n = 0;
    int length = tamanhoArrayFlights(tokens[2]);
    char** aux = tokenToArrayChar(tokens[2]);

    printf("%s %s %d\n",aux[0],aux[1],tamanhoArrayFlights(tokens[2]));
    if (!(length == 1 || length == 2)) n++;
    if(length == 1) {
        if (procuraVoo(mv,aux[0]) == NULL) n++;
    }
    if(length == 2) {
        if ((procuraVoo(mv,aux[0]) == NULL)
            || (procuraVoo(mv,aux[1]) == NULL)) n++;
        else {
            if (strcmp(getOrigin(procuraVoo(mv,aux[1])),getDestination(procuraVoo(mv,aux[0]))) != 0) n++;
        }
    }   
    if (encontrarPassageiro(mp,atoi(tokens[4]))==NULL) n++;
    return n;
}


int validacaoReserva(char** tokens, Manager_Voos* mv, GestorPassageiros* mp) { // preciso receber manager voos e manager passageiros
    int n = validacaoSintaticaReserva(tokens); // + validacaoLogicaReserva(tokens,mv,mp);
    return n;
}
