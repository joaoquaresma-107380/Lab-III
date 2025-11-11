
/*Função parseLine que recebe uma linha e constroi um array de tokens*/

char** parseLine(char* line) {
    int n = 0;
    char** tokens;
    char* token = strsep(&line, ";");
    tokens[0] = strcpy(token);
    while (token) {
        if (strlen(token) > 0) {  // para ignorar espaços consecutivos
            n++;
            tokens[1] = strcpy(token);
        }
        token = strsep(&line, ","); // obter proximo token
    }
    return tokens;
}