#include "ComandoParser.h"

struct cmd {
    int comando;
    char** args; // NULL se nao houver
    int nargs; // numero de argumentos
};

void processaComando(Manager_Aeroportos* aeroportos, GestorAviao* aeronaves, Manager_Voos* voos, Cmd* cmd, int n) {
    char aux[20];
    if (snprintf(aux,20,"comando%d_output.txt",n)<0) perror("Erro na copia para abertura do ficheiro de comandos");
    char aux_resultados[40] = "resultados/";
    const char* filename_resultados = strcat(aux_resultados, aux);

    FILE* resultados = abrirFicheiroEscrita(filename_resultados);

    if(cmd->comando==1) {
        if(cmd->nargs>1) printf("Comando incorreto\n");
        querie1 (aeroportos, cmd->args[0] , resultados);
    }

    if(cmd->comando == 2) {
        if(cmd->nargs>2) printf("Comando incorreto\n");
        querie2(aeronaves, voos, atoi(cmd->args[0]), cmd->args[1], resultados);
    }

    /*
    if(cmd->comando == 3) {
        if(cmd->nargs>2) printf("Comando incorreto\n");
        querie3 (voos, aeroportos,stringToDate(cmd->args[0]),stringToDate(cmd->args[1]), resultados);
    }*/
    

    fecharFicheiro(resultados);
}

Cmd* parseLineCmd(char* line) {
    int n = 0;
    Cmd* c = malloc(sizeof(Cmd));
    c->args = malloc(10*sizeof(char*));

    char* token = strsep(&line, " ");
    if(!token){
        c->comando = -1;
        c->args = NULL;
        c-> nargs = n;
        return c;
    }

    char* aux = strdup(token);
    c->comando = atoi(aux); // Primeiro token é o tipo da querie

    while ((token = strsep(&line, " ")) != NULL) {
        if (strlen(token) > 0) {  // para ignorar espaços consecutivos
            
            c->args[n] = strdup(token);
            n++;
    
        }
    }
    for(int j=0;j<strlen(c->args[n-1]);j++) {
            if(c->args[n-1][j] == '\n') c->args[n-1][j] = '\0';
    }
    c->args[n] = NULL;
    c->nargs = n;
    return c;
}

void readFileComandos(FILE* stream, Manager_Aeroportos* ma, Manager_Voos* mv, GestorAviao* mav) {
    char* line = NULL;
    size_t read;
    size_t len; // Sera definido pela funcao getline quando alocar espaço para a string
    int n = 0; 
    while ((read = getline(&line, &len, stream)) != -1) {
        char* lineAux = strdup(line);
        Cmd* comando = parseLineCmd(lineAux);
        n++;
        processaComando(ma,mav,mv,comando,n);

        for(int i = 0; i < comando->nargs;i++){
        free(comando->args[i]);
        }
        free(comando->args);
        free(comando);
        free(lineAux);
    }
    free(line); // preciso libertar a mem´oria alocada
}

