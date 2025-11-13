
#include "Data.h"

#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

// Estrutura 
typedef struct passageiro Passageiro;

// Criação

Passageiro *criarPassageiro(int doc, char *first, char *last , Data *birth, char *country,
                            char gender, char *email, char* phone, char* endereco, char* foto);

// Destruiçao 
void destruirPassageiro(Passageiro *p);

// Aceder aos dados
int acederPassageiroDoc(Passageiro *p);
char *acederPassageiroPrimeiro(Passageiro *p);
char *acederPassageiroUltimo(Passageiro *p);
Data *acederPassageiroData(Passageiro *p);
char *acederPassageiroPais(Passageiro *p);
char *acederPassageiroEmail(Passageiro *p);
char acederPassageiroGenero(Passageiro *p);
char *acederPassageiroTelefone(Passageiro *p);
char *acederPassageiroMorada(Passageiro *p);
char *acederPassageiroFoto(Passageiro *p);


// Atualizações dos dados 
void AtuaPassageiroDoc(Passageiro *p, int doc);
void AtuaPassageiroPrimeiro(Passageiro *p, char *first);
void AtuaPassageiroUltimo(Passageiro *p, char *last);
void AtuaPassageiroDataNascimento(Passageiro *p, Data *data);
void AtuaAPassageiroPais(Passageiro *p, char *pais);
void AtuaAPassageiroEmail(Passageiro *p, char *correio);
void AtuaPassageiroGenero(Passageiro *p, char g);
void AtuaPassageiroTelefone(Passageiro *p, char *t);
void AtuaPassageiroMorada(Passageiro *p, char *a);
void AtuaPassageiroFoto(Passageiro *p, char *f);




#endif