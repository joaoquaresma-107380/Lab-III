// Ficheiro Util_Ficheiro.c para lidar com os ficheiros (Abrir e Escrever)
#include "Util_Ficheiro.h"

// Função para abrir ficheiros mas só de leitura
FILE* abrirFicheiroLeitura(const char* filename){
    if(filename == NULL){
        return NULL;
    }
    FILE* file = fopen(filename, "r");
    return file;
}

// Função para abrir ficheiros mas só de escrita (Cria um novo ficheiro se não existir)
FILE* abrirFicheiroEscrita(const char* filename){
    FILE* stream = fopen(filename,"a");
    return stream;
}

// Função para fechar uma stream associada a um ficheiro
void fecharFicheiro(FILE* stream){
    fclose(stream);
}

char* tokensToString(char** tokens) {
    char* aux = tokens[0];
    for(int i = 1;tokens[i]!=NULL;i++) {
        aux = strcat(strcat(aux,", "),tokens[i]);
    }
    return aux;
}

// Função que escrever num ficheiro
void escreveFicheiro(char* str, FILE* stream){
    int r = fputs(str,stream);
    if(r != 0){
        perror("Erro na escrita");
    }
}

