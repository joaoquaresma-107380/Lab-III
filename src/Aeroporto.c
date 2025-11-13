// Ficheiro Aeroporto.c

#include "Aeroporto.h"

/**
 * Definição do módulo Aeroporto
 * O campo code indica o códifo IATA do aeroporto
 * O campo name indica o nome do aeroporto
 * O campo city indica a cidade onde se localiza o aeroporto
 * O campo country indica o país onde se localiza o aeroporto
 * O campo latitude indica a latitude do aeroporto em graus decimais
 * O campo longitude indica a longitude do aeroporto em graus decimais
 * O campo icao indica o código ICAO do aeroporto
 * O campo type indica o tipo de aeroporto
 */

struct aeroporto{
    char* code;
    char* name;
    char* city;
    char* country;
    double latitude;
    double longitude;
    char* icao;
    char* type;
};

// Função de criação de um aeroporto

Aeroporto* createAeroporto(char* code, char* name, char* city, char* country, double latitude, double longitude, char* icao, char* type){
    Aeroporto* new = malloc(sizeof(Aeroporto));

    new->code = strdup(code);
    new->name = strdup(name);
    new->city = strdup(city);
    new->country = strdup(country);
    new->latitude = latitude;
    new->longitude = longitude;
    new->icao = strdup(icao);
    new->type = strdup(type);

    return new;
}

// Função que retorn o código IATA do aeroporto

char* getCode(Aeroporto* a) {
    char* aux = strdup(a->code);
    return aux;
}

// Função que retorna o nome do aeroporto

char* getName (Aeroporto* a) {
    char* aux = strdup(a->name);
    return aux;
}

// Função que retorna a cidade do aeroporto

char* getCity (Aeroporto* a) {
    char* aux = strdup(a->city);
    return aux;
}

// Função que retorna o país do aeroporto

char* getCountry (Aeroporto* a) {
    char* aux = strdup(a->country);
    return aux;
}

// Função que retorna a latitude do aeroporto

double getLatitude (Aeroporto* a) {
    float aux = a->latitude;
    return aux;
}

// Função que retorna a longitude do aeroporto

double getLongitude (Aeroporto* a) {
    float aux = a->latitude;
    return aux;
}

// Função que retorna o código ICAO do aeroporto

char* getIcao (Aeroporto* a) {
    char* aux = strdup(a->icao);
    return aux;
}

// Função que retorna o tipo do aeroporto

char* getType (Aeroporto* a) {
    char* aux = strdup(a->type);
    return aux;
}

// Função que altera o código IATA de um aeroporto

void setCode(Aeroporto* a, char* codigo) {
    char* data = strdup(codigo);
    a->code = data;
}

// Função que altera o nome de um aeroporto

void setName(Aeroporto* a, char* n) {
    char* data = strdup(n);
    a->name = data;
}

// Função que altera a cidade de um aeroporto

void setCity(Aeroporto* a, char* cidade) {
    char* data = strdup(cidade);
    a->city = data;
}

// Função que altera o país de um aeroporto

void setCountry(Aeroporto* a, char* pais) {
    char* data = strdup(pais);
    a->country = data;
}

// Função que altera a latitude de um aeroporto

void setLatitude(Aeroporto* a, double lat) {
    a->latitude = lat;
}

// Função que altera a longitude de um aeroporto

void setLongitude(Aeroporto* a, double lon) {
    a->longitude = lon;
}

// Função que altera o código ICAO de um aeroporto

void setIcao(Aeroporto* a, char* ic) {
    char* data = strdup(ic);
    a->icao = data;
}

// Função que altera o tipo de um aeroporto

void setType(Aeroporto* a, char* tipo) {
    char* data = strdup(tipo);
    a->type = data;
}

// Função que destrói um aeroporto

void destroiAeroporto(Aeroporto* arp){
    free(arp->code);
    free(arp->name);
    free(arp->city);
    free(arp->country);
    free(arp->icao);
    free(arp->type);

    free(arp);
}


