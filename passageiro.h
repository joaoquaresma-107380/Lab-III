#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include <stdlib.h>
#include <string.h>

// Estrutura 
typedef struct passageiro Passageiro;

// Criação

Passageiro *criarAviao(const char *doc, const char *first, const char *last , const char *birth, const char *country, const char *email);

// Destruiçao 
void destruirAviao(Passageiro *p);

// Aceder aos dados
const char *acederPassageiroDoc(const Passageiro *p);
const char *acederPassageiroPrimeiro(const Passageiro *p);
const char *acederPassageiroUltimo(const Passageiro *p);
const char *acederPassageiroData(const Passageiro *p);
const char *acederPassageiroPais(const Passageiro *p);
const char *acederPassageiroEmail(const Passageiro *p);

// Atualizações dos dados 
void AtuaPassageiroDoc(Passageiro *p, const char* doc);
void AtuaPassageiroPrimeiro(Passageiro *p, const char *first);
void AtuaPassageiroUltimo(Passageiro *p, const char *last);
void AtuaPassageiroDataNascimento(Passageiro *p, const char *data);
void AtuaAPassageiroPais(Passageiro *p, const char *pais);
void AtuaAPassageiroEmail(Passageiro *p, const char *correio);

#endif
