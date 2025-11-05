#include "aeronave.h"

#include <stdio.h>

// Criação de uma estrutura para as aeronaves 

typedef struct aeronave {
    char *id;
    char *manufacter; // fabricante
    char *model;  // modelo 
    int year;  // ano 
    int capacity; // capacidade
    int range;  // alcane maximo 
    int totalFlights; // voos totais feito pelo avião 

} Aeronave;

//Cria o avião

Aeronave *criarAviao(const char *id, const char *manufacter, const char *model , int year, int capacity, int range , int totalFlights) {

    Aeronave *a = malloc (sizeof(Aeronave));
    if (!a) return NULL;

    a->id = strdup(id);
    a->manufacter = strdup(manufacter);
    a->model = strdup (model);
    a->year = year;
    a->capacity = capacity;
    a->range = range;
    a->totalFlights = 0;
	
    
    return a;
}

// libertar a memoria 

void destruirAviao(Aeronave *a){
    if (!a) return;

    free (a->id);
    free (a->manufacter);
    free (a-> model);
    free (a);
}

// Aceder aos dados

const char *acederAeronaveId (const Aeronave *a){
    if (a)
        return a->id;
    else 
        return NULL;

}
const char *acederAeronaveFabricante(const Aeronave *a){
    if (a)
        return a->manufacter;
    else 
        return NULL;
}
const char *acederAeronaveModelo (const Aeronave *a){
    if (a)
        return a->model;
    else 
        return NULL;
}
int acederAeronaveAno (const Aeronave *a){
    if (a)
        return a->year;
    else 
        return 0;
}
int acederAeronaveCapacidade (const Aeronave *a){
    if (a)
        return a->capacity;
    else 
        return 0;
}
int acederAeronaveAlcance (const Aeronave *a){
    if (a)
        return a->range;
    else 
        return 0;
}

int acederVoosTotais (const Aeronave *a){
    if (a)
        return a->totalFlights;
    else 
        return 0;
}

// Atualizações dos dados 

void AtuaAeronaveID (Aeronave *a, const char* id){
    if (!a) return;

    free(a->id);
    a->id = strdup (id);
}

void AtuaAeronaveFabricante (Aeronave *a ,const char *fabricante){
    if (!a) return;

    free(a->manufacter);
    a->manufacter = strdup (fabricante);
}

void AtuaAeronaveModelo (Aeronave *a, const char* modelo){
    if (!a) return;

    free (a->model);
    a->model = strdup (modelo);

}

void AtuaAeronaveAno (Aeronave *a , int ano){  
    if (a == NULL) return;
    a->year = ano; 

}

void AtuaAeronaveCapacidade (Aeronave *a, int capacidade){
    if (a == NULL) return;
    a->capacity = capacidade; 

}

void AtuaAeronaveAlcance (Aeronave *a, int alcance){
    if (a == NULL) return;
    a->range = alcance; 

}

// incrementar o total de voos 

void incrementarVoosTotaisAviao (Aeronave *a){
    if (a == NULL) return;

    a->totalFlights++;
}
