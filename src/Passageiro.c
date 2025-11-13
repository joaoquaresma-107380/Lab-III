#include "Passageiro.h"

// Criação de uma estrutura para as aeronaves 

typedef struct passageiro {
    int nrDocument;
    char *firstName;   // primeiro nome
    char *secondName;  // apelido 
    Data *birthDate;   // data de nascimento 
    char *country;     // país
    char gender;       // genero 
    char *email;      // email 
    char *phone;
    char *address;
    char *photo;
} Passageiro;

// Cria um passageiro
Passageiro *criarPassageiro(int doc,char *first,char *last,
                            Data *birth, char *country, char gender,char* email,
                            char *phone, char *address, char *photo) {
    
    Passageiro *p = malloc(sizeof(Passageiro));
    if (!p) return NULL;

    p->nrDocument = doc;
    p->firstName = strdup(first);
    p->secondName = strdup(last);
    p->birthDate = cloneData(birth);
    p->country = strdup(country);
    p->email = strdup(email);
    p->gender = gender;
    p->phone = strdup(phone);
    p->address = strdup(address);
    p->photo = strdup(photo);
    return p;
}

// libertar a memoria 

void destruirPassageiro(Passageiro *p){
    if (!p) return;

    free(p->firstName);
    free(p->secondName);
    destroiData(p->birthDate);
    free(p->country);
    free(p->email);
    free(p->phone);
    free(p->address);
    free(p->photo);
    free(p);
}

// Aceder aos dados

int acederPassageiroDoc(Passageiro *p){
        return p->nrDocument;
}

char *acederPassageiroPrimeiro(Passageiro *p){
    if (p)
        return p->firstName;
    else 
        return NULL;
}

char *acederPassageiroUltimo(Passageiro *p){
    if (p)
        return p->secondName;
    else 
        return NULL;
}

Data *acederPassageiroData(Passageiro *p){
    if (p)
        return cloneData(p->birthDate);
    else 
        return NULL;
}

char *acederPassageiroPais(Passageiro *p){
    if (p)
        return p->country;
    else 
        return NULL;
}

char *acederPassageiroEmail(Passageiro *p){
    if (p)
        return p->email;
    else 
        return NULL;
}

char acederPassageiroGenero(Passageiro *p){
        return p->gender;
}

char *acederPassageiroTelefone(Passageiro *p){
    if (p)
        return p->phone;
    else
        return NULL;
}

char *acederPassageiroMorada(Passageiro *p){
    if (p)
        return p->address;
    else
        return NULL;
}

char *acederPassageiroFoto(Passageiro *p){
    if (p)
        return p->photo;
    else
        return NULL;
}


// Atualizações dos dados 

void AtuaPassageiroDoc(Passageiro *p, int doc){
    p->nrDocument = doc;
}

void AtuaPassageiroPrimeiro(Passageiro *p, char *first){
    if (!p) return;

    free(p->firstName);
    p->firstName = strdup(first);
}

void AtuaPassageiroUltimo(Passageiro *p, char *last){
    if (!p) return;

    free(p->secondName);
    p->secondName = strdup(last);
}

void AtuaPassageiroDataNascimento(Passageiro *p, Data *data){  
    if (!p) return;

    free(p->birthDate);
    p->birthDate = cloneData(data);
}

void AtuaAPassageiroPais(Passageiro *p, char *pais){
    if (!p) return;

    free(p->country);
    p->country = strdup(pais);
}

void AtuaAPassageiroEmail(Passageiro *p, char *correio){
    if (!p) return;

    free(p->email);
    p->email = strdup(correio);
}

void AtuaPassageiroGenero(Passageiro *p, char g){
    if (!p) return;
    p->gender = g;
}

void AtuaPassageiroTelefone(Passageiro *p, char *t){
    if (!p) return;
    free(p->phone);
    p->phone = strdup(t);
}

void AtuaPassageiroMorada(Passageiro *p, char *a){
    if (!p) return;
    free(p->address);
    p->address = strdup(a);
}

void AtuaPassageiroFoto(Passageiro *p, char *f){
    if (!p) return;
    free(p->photo);
    p->photo = strdup(f);
}