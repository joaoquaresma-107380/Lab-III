// Ficheiro programa-testes.c 

#include <time.h>
#include <stdio.h>
#include <sys/resource.h>

#ifndef Programa-Testes_C

struct timespec start, end;

int main(int argc,char** argv){

    if(argc != 4){
        perror("Número errado de argumentos");
        printf("Experimente algo deste género: ./programa-testes nome_da_pasta_erros/ input.txt nome_da_pasta_resultados_esperados");
    }

    // Algumas coisas aqui por causa das queires e assim

    // Start time
    clock_gettime(CLOCK_REALTIME, &start);

    // Querie 1

    clock_gettime(CLOCK_REALTIME, &end);

    double tempo_Querie1 = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec);



    printf("Tempo de execução:\n");
    printf("Q1: %.6f segundos\n",tempo_Querie1);

}

#endif