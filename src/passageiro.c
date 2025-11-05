#include "passageiro.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Criação de uma estrutura para as aeronaves 

typedef struct passageiro {
    char *nrDocument;
    char *firstName;   // primeiro nome
    char *secondName;  // apelido 
    char *birthDate;   // data de nascimento 
    char *country;     // país
    char *email;       // email 
} Passageiro;

// Cria um passageiro

Passageiro *criarPassageiro (const char *doc, const char *first, const char *last , const char *birth, const char *country, const char *email) {

    Passageiro *p = malloc(sizeof(Passageiro));
    if (!p) return NULL;

    p->nrDocument = strdup(doc);
    p->firstName = strdup(first);
    p->secondName = strdup(last);
    p->birthDate = strdup(birth);
    p->country = strdup(country);
    p->email = strdup(email);
    
    return p;
}

// libertar a memoria 

void destruirPassageiro(Passageiro *p){
    if (!p) return;

    free(p->nrDocument);
    free(p->firstName);
    free(p->secondName);
    free(p->birthDate);
    free(p->country);
    free(p->email);
    free(p);
}

// Aceder aos dados

const char *acederPassageiroDoc(const Passageiro *p){
    if (p)
        return p->nrDocument;
    else 
        return NULL;
}

const char *acederPassageiroPrimeiro(const Passageiro *p){
    if (p)
        return p->firstName;
    else 
        return NULL;
}

const char *acederPassageiroUltimo(const Passageiro *p){
    if (p)
        return p->secondName;
    else 
        return NULL;
}

const char *acederPassageiroData(const Passageiro *p){
    if (p)
        return p->birthDate;
    else 
        return NULL;
}

const char *acederPassageiroPais(const Passageiro *p){
    if (p)
        return p->country;
    else 
        return NULL;
}

const char *acederPassageiroEmail(const Passageiro *p){
    if (p)
        return p->email;
    else 
        return NULL;
}

// Atualizações dos dados 

void AtuaPassageiroDoc(Passageiro *p, const char  *doc){
    if (!p) return;

    free(p->nrDocument);
    p->nrDocument = strdup(doc);
}

void AtuaPassageiroPrimeiro(Passageiro *p, const char *first){
    if (!p) return;

    free(p->firstName);
    p->firstName = strdup(first);
}

void AtuaPassageiroUltimo(Passageiro *p, const char *last){
    if (!p) return;

    free(p->secondName);
    p->secondName = strdup(last);
}

void AtuaPassageiroDataNascimento(Passageiro *p, const char *data){  
    if (!p) return;

    free(p->birthDate);
    p->birthDate = strdup(data);
}

void AtuaAPassageiroPais(Passageiro *p, const char *pais){
    if (!p) return;

    free(p->country);
    p->country = strdup(pais);
}

void AtuaAPassageiroEmail(Passageiro *p, const char *correio){
    if (!p) return;

    free(p->email);
    p->email = strdup(correio);
}

