#include "Aeronave.h"

// Criação de uma estrutura para as aeronaves 

struct aeronave {
    char *id;
    char *manufacter; // fabricante
    char *model;  // modelo 
    int year;  // ano 
    int capacity; // capacidade
    int range;  // alcane maximo 
    int totalFlights; // voos totais feito pelo avião 

};

//Cria o avião

Aeronave *criarAviao(char *id, char *manufacter, char *model , int year, int capacity, int range , int totalFlights) {

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

char *acederAeronaveId (Aeronave* a){
    if (a)
        return a->id;
    else 
        return NULL;

}
char *acederAeronaveFabricante(Aeronave *a){
    if (a)
        return a->manufacter;
    else 
        return NULL;
}
char *acederAeronaveModelo (Aeronave *a){
    if (a)
        return a->model;
    else 
        return NULL;
}
int acederAeronaveAno (Aeronave *a){
    if (a)
        return a->year;
    else 
        return 0;
}
int acederAeronaveCapacidade (Aeronave *a){
    if (a)
        return a->capacity;
    else 
        return 0;
}
int acederAeronaveAlcance (Aeronave *a){
    if (a)
        return a->range;
    else 
        return 0;
}

int acederVoosTotais (Aeronave *a){
    if (a)
        return a->totalFlights;
    else 
        return 0;
}

// Atualizações dos dados 

void AtuaAeronaveID (Aeronave *a, char* id){
    if (!a) return;

    free(a->id);
    a->id = strdup (id);
}

void AtuaAeronaveFabricante (Aeronave *a , char *fabricante){
    if (!a) return;

    free(a->manufacter);
    a->manufacter = strdup (fabricante);
}

void AtuaAeronaveModelo (Aeronave *a, char* modelo){
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
