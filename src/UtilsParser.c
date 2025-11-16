#include "UtilsParser.h"

/*Função parseLine que recebe uma linha e constroi um array de tokens*/

char** parseLine(char* line) {
    int n = 0;
    int tamanho = 30;
    char** tokens = malloc(tamanho * sizeof(char*));
    char* token = strsep(&line, "\"");
    while (token) {
        if (strlen(token) > 0) {  // para ignorar espaços consecutivos
            tokens[n] = strdup(token);
            n++;
        }
        token = strsep(&line, "\""); // obter proximo token
    }
    tokens[n] = NULL;
    return tokens;
}

// Função que indica o tamanho de um array de tokens

int tamanhoTokens(char** tokens){
    int n = 0;

    if(tokens == NULL) return n;

    while(tokens[n] != NULL) n++;

    return n;
}