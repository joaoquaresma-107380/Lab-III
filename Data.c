// Ficheiro Data.c

#include "Data.h"

#ifndef Data_C
#define Data_C

/**
 * Definição do módulo Data
 */
struct data{
    int ano;
    int mes;
    int dia;
    int hora;
    int min;
};

/**
 * Função de criação de uma Data
 */

Data* createData(int ano, int mes, int dia, int hora, int min){
    Data* data = malloc(sizeof(Data));
    data->ano = ano;
    data->mes = mes;
    data->dia = dia;
    data->hora = hora;
    data->min = min;

return data;
}

/**
 * Função que clona uma Data 
 */
Data* cloneData(Data* d){
    Data* data = createData(0,0,0,0,0);
    data->ano = d->ano;
    data->mes = d->mes;
    data->dia = d->dia;
    data->hora = d->hora;
    data->min = d->min;

return data;
}

/**
 * Função que retorna o ano de uma data
 */
int getAno(Data* data){
    return data->ano;
}

/**
 * Função que retorna o mês de uma data
 */
int getMes(Data* data){
    return data->mes;
}

/**
 * Função que retorna o dia de uma data
 */
int getDia(Data* data){
    return data->dia;
}

/**
 * Função que retorna a hora de uma data
 */
int getHora(Data* data){
    return data->hora;
}

/**
 * Função que retorna os minutos de uma data
 */
int getMinutos(Data* data){
    return data->min;
}

/**
 * Altera o valor do campo ano numa data
 */
void setAno(int novAno, Data* data){
    data->ano = novAno;
}

/**
 * Altera o valor do campo mês numa data
 */
void setMes(int novMes, Data* data){
    data->mes = novMes;
}

/**
 * Altera o valor do campo dia numa data
 */
void setDia(int novDia, Data* data){
    data->dia = novDia;
}

/**
 * Altera o valor do campo hora numa data
 */
void setHora(int novHora, Data* data){
    data->hora = novHora;
}

/**
 * Altera o valor do campo min numa data
 */
void setMinutos(int novMin, Data* data){
    data->min = novMin;
}

/**
 * Função que valida uma data
 */
void destruirData (Data* d) {
    free(d);
}

/**
 * Função que valida uma data
 */

int validacaoData(char* token) {
    int n = 0;
    if (strlen(token) != 10 && strlen(token) != 18 && strlen(token) != 4) {
        n++;
    }
    char* mes;
    char* ano;
    char* dia;
    char* hora;
    char* min;
    if (strlen(token) == 4) {
        if (atoi(token)>2025) n++;
    }
    if (strlen(token) == 10) {
        if (token[4] != '-' || token[7] != '-') {
            n++;
        }
        for(int i = 0;i<strlen(token);i++) {
            if(i<4) {
                ano[i] = token[i];
            }
            if(i>4 && i<7) {
                mes[i] = token[i];
            }
            if(i>7) {
                dia[i] = token[i];
            }
        }
        if (atoi(ano)>2025) n++;
        if(atoi(ano)==2025 && atoi(mes)>9) n++;
        if (atoi(mes)>12 || atoi(mes)<1) n++;
        if(atoi(dia)>31 || atoi(dia)<1) n++;
    }
    if (strlen(token) == 18) {
        if (token[4] != '-' || token[7] != '-' 
        || token[10] != ' ' || token[13] != ' '
        || token[14] != ':' || token[15] != ' ') {
            n++;
        }
        for(int i = 0;i<strlen(token);i++) {
            if(i<4) {
                ano[i] = token[i];
            }
            if(i>4 && i<7) {
                mes[i] = token[i];
            }
            if(i>7 && i<10) {
                dia[i] = token[i];
            }
            if(i>10 && i<13) {
                hora[i] = token[i];
            }
            if(i>15 && i<18) {
                min[i] = token[i];
            }
        }
        if (atoi(ano)>2025) n++;
        if (atoi(mes)>12 || atoi(mes)<1) n++;
        if(atoi(dia)>31 || atoi(dia)<1) n++;
        if(atoi(hora)>23 || atoi(hora)<0) n++;
        if(atoi(min)>59 || atoi(min)<0) n++;
    }
    if (n>0) {
        return 0;
    }
    else {
        return 1;
    }
}

/**
 *  funçao de comparaçao de datasHoras que retorna 1 se a segunda data for mais recente,
 * 1 se a primeira data for mais recente e 0 se forem iguais 
 * */
int compararDataHora(Data* x, Data* y) {
    if (x->ano > y->ano) return 1;
    if (x->ano < y->ano) return -1;
    if (x->ano == y->ano) {
        if (x->mes > y->mes) return 1;
        if (x->mes < y->mes) return -1;
        if (x->mes == y->mes) {
            if (x->dia > y->dia) return 1;
            if (x->dia < y->dia) return -1;
            if (x->dia == y->dia) {
                if (x->hora > y->hora) return 1;
                if (x->hora < y->hora) return -1;
                if (x->hora == y->hora) {
                    if (x->min > y->min) return 1;
                    if (x->min < y->min) return -1;
                    if (x->min == y->min) {
                        return 0;
                    }
                }
            }
        }
    }
}

/**
 * Função que transforma uma string numa data preenchendo todos os campos 
 */
Data* stringToDate(char* str){
  
    Data* data = createData(0000,00,00,0,0);
    int ano, mes, dia, hora, min;
    int tamanho = strlen(str), j = 0;

    if(strlen(str) == 10){
        sscanf(str,"%4d-%2d-%2d", &ano, &mes, &dia);
        data->ano = ano;
        data->mes = mes;
        data->dia = dia;
    }

    if(strlen(str) == 18){
        sscanf(str, "%4d-%2d-%2d %2d : %2d", &ano,&mes,&dia,&hora,&min);
        data->ano = ano;
        data->mes = mes;
        data->dia = dia;
        data->hora = hora;
        data->min = min;
    }

    return data;
}

#endif
