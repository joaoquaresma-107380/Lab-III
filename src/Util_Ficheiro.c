// Ficheiro Util_Ficheiro.c para lidar com os ficheiros (Abrir e Escrever)

#include "Util_Ficheiro.h"

#ifndef Util_Ficheiro_C
#define Util_Ficheiro_C

// Função para abrir ficheiros mas só de leitura
FILE* abrirFicheiroLeitura(const char* filename){
    if(filename == NULL){
        return NULL;
    }
    FILE* file = fopen(filename, r);
    return file;
}

// Função para abrir ficheiros mas só de escrita (Cria um novo ficheiro se não existir)
FILE* abrirFicheiroEscrita(const char* filename){
    FILE* stream = fopen(filename,a);
    return stream;
}

// Função para fechar uma stream associada a um ficheiro
void fecharFicheiro(FILE* stream){
    fclose(stream);
}

// Função que escrever num ficheiro
int escreveFicheiro(char* str, FILE* stream){
    int r = fputs(str,stream);
    if(r != 0){
        perror("Erro na escrita");
        return 1;
    }
    return 0;
}

#endif