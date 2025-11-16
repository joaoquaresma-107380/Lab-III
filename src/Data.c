// Ficheiro Data.c

#include "Data.h"

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
void destroiData (Data* d) {
    free(d);
}

/**
 *  funçao de comparaçao de datasHoras que retorna 1 se a segunda data for mais recente,
 * -1 se a primeira data for mais recente e 0 se forem iguais 
 * */
int compararDataHora(Data* x, Data* y) {
    if (x->ano == y->ano) {
        if (x->mes == y->mes) {
            if (x->dia == y->dia) {
                if (x->hora == y->hora) {
                    if (x->min == y->min) {
                        return 0;
                    }
                    else {
                        if (x->min < y->min) return 1;
                        else return -1;
                    }
                }
                else {
                    if (x->hora < y->hora) return 1;
                    else return -1;
                }
            }
            else {
                if (x->dia < y->dia) return 1;
                else return -1;
            }
        }
        else {
            if (x->mes < y->mes) return 1;
            else return -1;
        }
    }
    else {
        if (x->ano < y->ano) return 1;
        else return -1;
    }   
}

/**
 * Função que transforma uma string numa data preenchendo todos os campos 
 */
Data* stringToDate(char* str){
    Data* data = createData(0000,00,00,0,0);
    if (strcmp(str, "N/A") == 0) return data;
    int ano, mes, dia, hora, min;
    int tamanho = strlen(str);

    if(tamanho == 10){
        sscanf(str,"%4d-%2d-%2d", &ano, &mes, &dia);
        data->ano = ano;
        data->mes = mes;
        data->dia = dia;
    }

    if(tamanho == 16){
        sscanf(str, "%4d-%2d-%2d %2d:%2d", &ano,&mes,&dia,&hora,&min);
        data->ano = ano;
        data->mes = mes;
        data->dia = dia;
        data->hora = hora;
        data->min = min;
    }

    return data;
}

/**
 * Função que valida uma data
 */

int validacaoData(char* token) {
    int n = 0;
    if (strlen(token) != 10 && strlen(token) != 16) {
        n++;
    }
    char* mes = malloc(3 * sizeof(char));
    char* ano = malloc(5 * sizeof(char));
    char* dia = malloc(3 * sizeof(char));
    char* hora = malloc(3 * sizeof(char));
    char* min = malloc(3 * sizeof(char));

    ano[0] = token[0];
    ano[1] = token[1];
    ano[2] = token[2];
    ano[3] = token[3];
    ano[4] = '\0';

    mes[0] = token[5];
    mes[1] = token[6];
    mes[2] = '\0';

    dia[0] = token[8];
    dia[1] = token[9];
    dia[2] = '\0';

    if (token[4] != '-' || token[7] != '-') {
            n++;
        }
        if (atoi(ano)>2025) n++;
        if(atoi(ano)==2025 && atoi(mes)>9) n++;
        if (atoi(mes)>12 || atoi(mes)<1) n++;
        if(atoi(dia)>31 || atoi(dia)<1) n++;
        
    if (strlen(token) == 16) {
        if (token[10] != ' ' || token[13] != ':') {
            n++;
        }
        hora[0] = token[11];
        hora[1] = token[12];
        hora[2] = '\0';

        min[0] = token[14];
        min[1] = token[15];
        min[2] = '\0';
        
        if(atoi(hora)>23 || atoi(hora)<0) n++;
        if(atoi(min)>59 || atoi(min)<0) n++;
    }
    free(mes);
    free(ano);
    free(dia);
    free(hora);
    free(min);
    return n;
}

