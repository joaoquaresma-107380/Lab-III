#ifndef COMANDO_PARSER_C
#define COMANDO_PARSER_C

#include "comandoParser.h"

void processaCommando(Manager_Aeroportos* aeroportos, GestorAviao* aeronaves, Manager_Voos* voos, Cmd* cmd, File* resultados) {
    if(cmd->comando==1) {
        if(c->nargs>1) printf("Comando incorreto");
        querie1 (aeroportos, c->args[0] , resultados);
    }
    if(cmd->comando == 2) {
        if(c->nargs>2) printf("Comando incorreto");
        querie2(aeronaves, voos, atoi(c->args[0]), c->args[1], resultados);
    }
    if(cmd->comando == 3) {
        if(c->nargs>2) printf("Comando incorreto");
        querie3 (voos, aeroportos,StringToDate(c->args[0]),StringToDate(c->args[1]), resultados);
    }
}

Cmd* parseLineCmd(char* line) {
    int n = 0;
    Cmd* c;
    char* token = strsep(&line, " ");
    c->comando = strcpy(token);
    while (token) {
        if (strlen(token) > 0) {  // para ignorar espaços consecutivos
            c->args[n] = strcpy(token);
            n++;
        }
        token = strsep(&line, " "); // obter proximo token
    }
    c->nargs = n;
    return c;
}

void readFileComandos(FILE* stream, Manager_Aeroportos* ma, Manager_Voos* mv, GestorAviao* mav) {
    char* line = NULL;
    size_t read;
    size_t len; // Sera definido pela funcao getline quando alocar espaço para a string
    FILE* resultados;
    resultados = abrirFicheiroEscrita("input.txt");
    while ((read = getline(&line, &len, stream)) != -1) {
        Cmd* comando = parseLine(line);
        processaComando(ma,mav,mv,comando,resultados);  
    }
    free(line); // preciso libertar a mem´oria alocada
    fecharFicheiro(resultados);
}

#endif