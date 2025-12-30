#include "ComandoParser.h"

struct cmd {
    char* comando;
    char** args; // NULL se nao houver
    int nargs; // numero de argumentos
};

char** parseLineQuerie(char* line) {
    int n = 0;
    int tamanho = 30;
    char** tokens = malloc(tamanho * sizeof(char*));
    char* token = strsep(&line, ";");
    while (token) {
        if (strlen(token) > 0) {  // para ignorar espaços consecutivos
            tokens[n] = strdup(token);
            n++;
        }
        token = strsep(&line, ";"); // obter proximo token
    }
    tokens[n] = NULL;
    return tokens;
}

void escreveOutput(char** resultados,Cmd* cmd, int n, int flagInterativo) {
    if (flagInterativo == 0) {
        char aux[20];
        if (snprintf(aux,20,"comando%d_output.txt",n)<0) perror("Erro na copia para abertura do ficheiro de comandos");
        char aux_output[40] = "resultados/";
        const char* filename_output = strcat(aux_output, aux);
        FILE* output = abrirFicheiroEscrita(filename_output);
    }
    for (int j = 0;resultado[j] != NULL;j++) {
            char** tokens = parseLineQuerie(resultado[j]);
            for(int i = 0;tokens[i+1] != NULL;i++) {
                if (strlen(cmd->comando) == 1) {
                    if (flagInterativo == 0) fprintf (output, "%s;",tokens[i]);
                    else printf ("%s;",tokens[i]);
                }
                else {
                    if (flagInterativo == 0) fprintf (output, "%s=",tokens[i]);
                    else printf ("%s=",tokens[i]);
                }
            }
            if (flagInterativo == 0) fprintf (output,"%s\n");
            else printf ("%s\n");
    }
}

void processaComando(Manager_Aeroportos* aeroportos, GestorAviao* aeronaves, Manager_Voos* voos,  Manager_Reservas* gestorReservas, Cmd* cmd, int n, ListaContagem** aeronavesVoos, ListaContagem** airlinesAtrasos) {
    

    if(cmd->comando=="1" || cmd->comando=="1S") {
        if(cmd->nargs>1) printf("Comando incorreto\n");
        // printf("Comando 1 nao incrementado\n");
        char** resultados = querie1 (aeroportos, cmd->args[0]);
        escreveOutput(resultados,cmd,n,0);
    }

    if(cmd->comando == 2) {
        if(cmd->nargs>2) printf("Comando incorreto\n");
        printf("Comando 2 nao incrementado\n");
        char** resultados = querie2(aeronaves, voos, atoi(cmd->args[0]), cmd->args[1], aeronavesVoos, airlinesAtrasos);
        escreveOutput(resultados,cmd,n,0);
    }

    if(cmd->comando == 3) {
        if(cmd->nargs!=2) printf("Comando incorreto\n");
        printf("Comando 3 nao incrementado\n");
        char** resultados = querie3 (voos, aeroportos,stringToDate(cmd->args[0]),stringToDate(cmd->args[1]));
        escreveOutput(resultados,cmd,n,0);
    }
    
    if(cmd->comando == 4) {
        printf("Comando 4 nao incrementado\n");
    }

    if(cmd->comando == 5) {
        if(cmd->nargs>1) printf("Comando incorreto\n");
        char** resultados = querie5 (Manager_Voos* gestorVoos, int n, ListaContagem* contaAirlines);
        escreveOutput(resultados,cmd,n,0);
        
    }

    if(cmd->comando == 6) {
        if(cmd->nargs>1) printf("Comando incorreto\n");
        char** resultados = querie6 (Manager_Reservas* gestorReservas, char* nationality)
        escreveOutput(resultados,cmd,n,0);
    }

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

    c->comando = strdup(token); // Primeiro token é o tipo da querie

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

void readFileComandos(FILE* stream, Manager_Aeroportos* ma, GestorAviao* mav, Manager_Voos* mv, Manager_Reservas* gestorReservas, ListaContagem** aeronavesVoos, ListaContagem** airlinesAtrasos) {
    char* line = NULL;
    size_t read;
    size_t len; // Sera definido pela funcao getline quando alocar espaço para a string
    int n = 0;
    int flag2 = 0;
    int flag5 = 0; 
    while ((read = getline(&line, &len, stream)) != -1) {
        char* lineAux = strdup(line);
        Cmd* c = parseLineCmd(lineAux);
        n++;
        processaComando(ma,mav,mv,c,n,flag2,flag5);
        if (c->comando == 2) flag2++;
        if (c->comando == 5) flag5++;

        for(int i = 0; i < comando->nargs;i++){
        free(comando->args[i]);
        }
        free(comando->args);
        free(comando);
        free(lineAux);
    }
    free(line); // preciso libertar a mem´oria alocada
}
