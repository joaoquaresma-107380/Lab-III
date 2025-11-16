#include "ValidacaoAeroporto.h"

int validacaoSintaticaAeroporto(char** tokens) {
    int n = 0;

    // Validar tipo do aeroporto
   
    if((strcmp(tokens[14],"small_airport")!=0) 
    && (strcmp(tokens[14],"medium_airport")!=0) 
    && (strcmp(tokens[14],"large_airport")!=0)
    && (strcmp(tokens[14],"heliport")!=0)
    && (strcmp(tokens[14],"seaplane_base")!=0)) n++;


    // Validar longitude do aeroporto
    char* aux_longitude = strdup(tokens[10]);
    char* aux_longitude_original = aux_longitude;

    // Verifica se a longitude está entre -180 e 180
    if (atof(tokens[10])<-180 || atof(tokens[10])> 180) n++; 
    
    // Verifica os dígitos antes do ponto
    char* pr_parte = strsep(&aux_longitude,".");
    if(pr_parte == NULL) n++;
    else{
        int tamanho_pr_parte = strlen(pr_parte);
        if (!(pr_parte[0] == '-' || (pr_parte[0]>=48 && pr_parte[0] <=57))) n++;
        for(int i = 1;i < tamanho_pr_parte;i++){
            if(pr_parte[i] < 48 || pr_parte[i] > 57) n++;
        }
    }

    // Verifica os dígitos depois do ponto
    if(aux_longitude == NULL) n++;
    else {
        int tamanho_aux_longitude = strlen(aux_longitude);
        if(tamanho_aux_longitude > 8) n++;
        for(int i = 0; i < tamanho_aux_longitude;i++){
            if(aux_longitude[i] < 48 || aux_longitude[i] > 57) n++;
        }
    }
    
    free(aux_longitude_original);

    // Validar latitude do aeroporto
    char* aux_latitude = strdup(tokens[8]);
    char* aux_latitude_original = aux_latitude;

    // Verifica se a latitude está entre -90 e 90
    if(atof(tokens[8])<-90 || atof(tokens[8]) > 90) n++;

    // Verifica os dígitos antes do ponto
    char* pr_parte_latitude = strsep(&aux_latitude,".");
    if(pr_parte_latitude == NULL) n++;
    else {
        int tamanho_pr_parte_latitude = strlen(pr_parte_latitude);
        if (!(pr_parte_latitude[0] == '-' || (pr_parte_latitude[0]>=48 && pr_parte_latitude[0] <=57))) n++;
        for(int i = 1;i < tamanho_pr_parte_latitude;i++){
            if(pr_parte_latitude[i] < 48 || pr_parte_latitude[i] > 57) n++;
        }
    }

    // Verifica os dígitos depois do ponto
    if(aux_latitude == NULL) n++;
    else {
        int tamanho_aux_latitude = strlen(aux_latitude);
        if(tamanho_aux_latitude > 8) n++;

        for(int i = 0; i < tamanho_aux_latitude;i++){
            if(aux_latitude[i] < 48 || aux_latitude[i] > 57) n++;
        }
    }

    free(aux_latitude_original);

    // Validar código do aeroporto

    // O código só pode ter 3 letras
    if(strlen(tokens[0])!=3) n++;

    if(tokens[0][0] < 65 || tokens[0][0] > 90
    || tokens[0][1] < 65 || tokens[0][1] > 90
    || tokens[0][2] < 65 || tokens[0][2] > 90) n++;
    
    return n;
}
