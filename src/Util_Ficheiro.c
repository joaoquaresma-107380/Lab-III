// Ficheiro Util_Ficheiro.c para lidar com os ficheiros (Abrir e Escrever)
#include "Util_Ficheiro.h"

// Função para abrir ficheiros mas só de leitura
FILE* abrirFicheiroLeitura(const char* filename){
    if(filename == NULL){
        perror("Erro na diretoria para abrir o ficheiro para leitura");
        return NULL;
    }
    FILE* file = fopen(filename, "r");
    if(file == NULL){
        perror("Erro ao abrir o ficheiro para leitura");
    }
    return file;
}

// Função para abrir ficheiros mas só de escrita (Cria um novo ficheiro se não existir)
FILE* abrirFicheiroEscrita(const char* filename){
    FILE* stream = fopen(filename,"w");
    if(stream == NULL){
        perror("Erro ao abrir o ficheiro para escrita");
    }
    return stream;
}

// Função para fechar uma stream associada a um ficheiro
void fecharFicheiro(FILE* stream){
    if(stream != NULL) fclose(stream);
}

/*char* tokensToString(char** tokens) {
    if(tokens == NULL) return;

    char* aux = strdup(tokens[0]);
    for(int i = 1;tokens[i]!=NULL;i++) {
        aux = strcat(strcat(aux,", "),tokens[i]);
    }
    return aux;
}*/

// Função que escrever num ficheiro
int escreveFicheiro(char* str, FILE* stream){
    int r = fputs(str,stream);
    if(r < 0){
        perror("Erro na função fputs");
    }
    return r;
}

