#include "stdio.h"

int validacaoSintaticaAeroporto(char** tokens) {
    int n = 0;
    // validar tipo do aeroporto
    if((strcmp(tokens[7],"small_airport")!=0) 
    || (strcmp(tokens[7],"medium_airport")!=0) 
    || (strcmp(tokens[7],"large_airport")!=0)
    || (strcmp(tokens[7],"heliport")!=0)
    || (strcmp(tokens[7],"seaplane_base")!=0)) {
        n++;
    }
    // validar longitude do aeroporto
    if((atof(tokens[6])<-180 || atof(tokens[6])> 180)
    || (!(strlen(tokens[6])==8 
            && tokens[6][0]=='-' 
            && ((tokens[6][1]>=48 && tokens[6][1]<=57)
                && (tokens[6][2]>=48 && tokens[6][2]<=57)
                && (tokens[6][3]>=48 && tokens[6][3]<=57)
                && (tokens[6][4]>=48 && tokens[6][4]<=57)
                && (tokens[6][5]>=48 && tokens[6][5]<=57)
                && (tokens[6][6]>=48 && tokens[6][6]<=57)
                && (tokens[6][7]>=48 && tokens[6][7]<=57))) 
        || (strlen(tokens[6])==7 
            && ((tokens[6][0]>=48 && tokens[6][0]<=57)
                && (tokens[6][1]>=48 && tokens[6][1]<=57)
                && (tokens[6][2]>=48 && tokens[6][2]<=57)
                && (tokens[6][3]>=48 && tokens[6][3]<=57)
                && (tokens[6][4]>=48 && tokens[6][4]<=57)
                && (tokens[6][5]>=48 && tokens[6][5]<=57)
                && (tokens[6][6]>=48 && tokens[6][6]<=57))))) {
        n++;
    }
    // validar latitude do aeroporto
    if((atof(tokens[5])<-90 || atof(tokens[5]) > 90)
    || (!(strlen(tokens[5])<=8 
            && tokens[5][0]=='-' 
            && ((tokens[5][1]>=48 && tokens[5][1]<=57)
                && (tokens[5][2]>=48 && tokens[5][2]<=57)
                && (tokens[5][3]>=48 && tokens[5][3]<=57)
                && (tokens[5][4]>=48 && tokens[5][4]<=57)
                && (tokens[5][5]>=48 && tokens[5][5]<=57)
                && (tokens[5][6]>=48 && tokens[5][6]<=57)
                && (tokens[5][7]>=48 && tokens[5][7]<=57))) 
        || (strlen(tokens[5])<=7 
            && ((tokens[5][0]>=48 && tokens[5][0]<=57)
                && (tokens[5][1]>=48 && tokens[5][1]<=57)
                && (tokens[5][2]>=48 && tokens[5][2]<=57)
                && (tokens[5][3]>=48 && tokens[5][3]<=57)
                && (tokens[5][4]>=48 && tokens[5][4]<=57)
                && (tokens[5][5]>=48 && tokens[5][5]<=57)
                && (tokens[5][6]>=48 && tokens[5][6]<=57))))) {
        n++;
    }
    // validar codigo do aeroporto
    if(strlen(tokens[0])!=3 
    || (tokens[0][0]<65 || tokens[0][0]>90)
    || (tokens[0][1]<65 || tokens[0][1]>90)
    || (tokens[0][2]<65 || tokens[0][2]>90)) {
        n++;
    }
    if (n>0) {
        return 0;
    }
    else {
        return 1;
    }
}