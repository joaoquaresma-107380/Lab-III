// Ficheiro Reserva.c

#include "Reserva.h"

/**
 * Definição do módulo Reserva
 * O campo reservation_id indica o identificador único da reserva
 * O campo num_flights_id indica o número de identificadores únicos dos voos associados à reserva
 * O campo flights_id indica uma lista com os identificadores únicos dos voos associados à reserva
 * O campo document_number indica o número do documento de identificação do passageiro 
 * O campo seat indica o número do lugar reservado
 * O campo price indica o preço da reserva
 * O campo extra_luggage indica se a reserva inclui bagagem extra
 * O campo priority_boarding indica se a reserva inclui embarque prioritário
 * O campo qr_code indica o QR code associado à reserva
 */

struct reserva{
    char* reservation_id; // falta mudar a reserva
    int num_flights_id;
    char** flights_id;
    int document_number;
    char* seat;
    double price;
    char* extra_luggage;
    char* priority_boarding;
    char* qr_code;
};

// Função de criação de uma Reserva

Reserva* createReserva (char* r_id, int num, char** f_id, int dnumber, char* lugar, float preco, char* boleano, char* b, char* qr) {
    Reserva* a = malloc(sizeof (Reserva));

    a->reservation_id = r_id;
    a->num_flights_id = num;
    a->flights_id = malloc(a->num_flights_id*sizeof(char*));

    for(int i = 0;i<num;i++) {
        a->flights_id[i] = strdup(f_id[i]);
    }
 
    a->document_number = dnumber;
    a->seat = strdup(lugar);
    a->price = preco;
    a->extra_luggage = strdup(boleano);
    a->priority_boarding = strdup(b);
    a->qr_code = strdup(qr);

    return a;
}

// Função que retorna o identificador único da reserva

char* getReservationId(Reserva* r) {
    char* aux = strdup(r->reservation_id);
    return aux;
}

// Função que retorna o número de identificadores únicos dos voos associados à reserva

int getNumFlightsId(Reserva* r) {
    return r->num_flights_id;
}

// Função que retorna a lista dos identificadores únicos dos voos associados à reserva

char** getFlightsId(Reserva* r) {
    char** aux = malloc(r->num_flights_id * sizeof(char*));
    for(int i = 0;i<r->num_flights_id;i++) {
        aux[i] = strdup(r->flights_id[i]);
    }
    return aux;
}

// Função que retorna o número do documento de identificação do passageiro associado à reserva

int getDocumentNumber(Reserva* r) {
    return r->document_number;
}

// Função que retorna o lugar da reserva

char* getSeat (Reserva* r) {
    char* aux = strdup(r->seat);
    return aux;
}

// Função que retorna o preço da reserva

float getPrice(Reserva* r) {
    return r->price;
}

// Função que retorna se uma reserva inclui bagagem extra (true ou false)

char* getExtraLuggage(Reserva* r) {
    char* aux = strdup(r->extra_luggage);
    return aux;
}

// Função que retorna se uma reserva inclui embarque prioritário

char* getPriorityBoarding(Reserva* r) {
    char* aux = strdup(r->priority_boarding);
    return aux;
}

// Função que retorna o QR code de uma reserva

char* getQrCode (Reserva* r) {
    char* aux = strdup(r->qr_code);
    return aux;
}

// Função que altera o valor do identificador único de uma reserva

void setReservationId(Reserva* r, char* id) {
    r->reservation_id = strdup(id);
}

// Função que altera o valor do número de identificadores únicos dos voos de uma reserva

void setNumFlightsId(Reserva* r, int num){
    r->num_flights_id = num;
}

// Função que altera a lista de identificadores únicos dos voos de uma reserva

void setFlightsId(Reserva* r, char** f_id, int num) {
    for(int i = 0;i<num;i++) {
        r->flights_id[i] = strdup(f_id[i]);
    }
}

// Função que altera o valor do documento único do passageiro associado a uma reserva

void setDocumentNumber(Reserva* r, int dnumber) {
    r->document_number = dnumber;
}

// Função que altera o lugar de uma reserva

void setSeat(Reserva* r, char* lugar) {
    r->seat= strdup(lugar);
}

// Função que altera o preço de uma reserva

void setPrice(Reserva* r, float preco) {
    r->price = preco;
}

// Função que altera o parâmetro de bagagem extra de uma reserva

void setExtraLuggage(Reserva* r, char* boleano) {
    r->extra_luggage = strdup(boleano);
}

// Função que altera o parâmetro de embarque prioritário de uma reserva

void setPriorityBoarding(Reserva* r, char* b) {
    r->priority_boarding = strdup(b);
}

// Função que altera o QR code associado a uma reserva

void setQrCode(Reserva* r, char* qr) {
    r->qr_code = strdup(qr);
}

// Função que destrói uma reserva

void destroiReserva(Reserva* r){
    free(r->flights_id);
    free(r->seat);
    free(r->extra_luggage);
    free(r->priority_boarding);
    free(r->qr_code);

    free(r);
}

