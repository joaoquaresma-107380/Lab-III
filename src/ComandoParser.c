#include "ComandoParser.h"

struct cmd {
    int comando;
    char** args; // NULL se nao houver
    int nargs; // numero de argumentos
};

void processaComando(Manager_Aeroportos* aeroportos, GestorAviao* aeronaves, Manager_Voos* voos, Cmd* cmd, int n) {
    char aux[20];
    if (snprintf(aux,20,"comando%d_output.txt",n)<0) perror("Erro na copia para abertura do ficheiro de comandos");
    FILE* resultados = abrirFicheiroEscrita(aux);
    if(cmd->comando==1) {
        if(cmd->nargs>1) printf("Comando incorreto");
        querie1 (aeroportos, cmd->args[0] , resultados);
    }
    if(cmd->comando == 2) {
        if(cmd->nargs>2) printf("Comando incorreto");
        querie2(aeronaves, voos, atoi(cmd->args[0]), cmd->args[1], resultados);
    }
    if(cmd->comando == 3) {
        if(cmd->nargs>2) printf("Comando incorreto");
        querie3 (voos, aeroportos,stringToDate(cmd->args[0]),stringToDate(cmd->args[1]), resultados);
    }
    fecharFicheiro(resultados);
}

Cmd* parseLineCmd(char* line) {
    int n = 0;
    Cmd* c = malloc(sizeof(Cmd));
    char* token = strsep(&line, " ");
    char* aux = strdup(token);
    c->comando = atoi(aux);
    while (token) {
        if (strlen(token) > 0) {  // para ignorar espaços consecutivos
            c->args[n] = strdup(token);
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
    int n = 0; 
    while ((read = getline(&line, &len, stream)) != -1) {
        Cmd* comando = parseLineCmd(line);
        n++;
        processaComando(ma,mav,mv,comando,n);  
    }
    free(line); // preciso libertar a mem´oria alocada
}

