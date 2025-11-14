#include "UtilsParser.h"

// Função que elimina as aspas
char* eliminaAspasParagrafo(char* s){
    if (s[strlen(s)-1] == '\n') {
        int i = 0;
        for(;i<strlen(s)-3;i++) {
            s[i] = s[i+1];
        }
        s[i] = '\0';
    }
    else {
        int i = 0;
        for(;i<strlen(s)-2;i++) {
            s[i] = s[i+1];
        }
        s[i] = '\0';
    }
    return s;
}

/*Função parseLine que recebe uma linha e constroi um array de tokens*/

char** parseLine(char* line) {
    int n = 0;
    int tamanho = 15; 
    char** tokens = malloc(tamanho * sizeof(char*));
    char* token = strsep(&line, ",");
    while (token) {
        if (strlen(token) > 0) {  // para ignorar espaços consecutivos
            tokens[n] = eliminaAspasParagrafo(strdup(token));
            n++;
        }
        token = strsep(&line, ","); // obter proximo token
    }
    tokens[n] = NULL;
    return tokens;
}

