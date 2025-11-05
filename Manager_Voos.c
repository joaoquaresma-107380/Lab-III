// Ficheiro Manager_Voos.c

#include <stdio.h>
#include <stdlib.h>
#include "Manager_Voos.h"

#ifndef Manager_Voos_C
#define Manager_Voos_C



typedef struct manager_voos {
	int size;
	int sp;
	Voo* values;
} Manager_Voos;

// funçao que cria um array de voos
void createManager_Voos () {
    Manager_Voos* gestor = malloc(sizeof(Manager_Voos));
    gestor->sp = 0;
    gestor->size = 10;
    gestor->values = malloc(sizeof(int) * s->size);
}

// funçao que duplica o tamanho do array de voos
void dupVoos(Manager_Voos* s) {
  int r = 0, i;
  int* t = malloc(2 * s->size * sizeof(int));
  for (i = 0; i < s->size; i++) {
    t[i] = s->values[i];
    free(s->values);
    s->values = t;
    s->size *= 2;
  }
}

// funçao que testa se o manager está vazio
int ManagerVazio(Manager_Voos* s) { return s->sp == 0; }

// função para inserir um voo num array dinâmico de voos
void adicionaVoo(Manager_Voos* s, Voo* x) {
    if (s->sp == s->size) {
      dupVoos(s);
    }
    s->values[s->sp++] = x;
}

/**
 * função para procurar um voo num array dinâmico de voos
 * Retorna o índice do voo no array de voos
 * Caso não exista retorna -1
 */ 
int procuraVoo(Manager_Voos* v,Voo* a) {
    for (int i = 0;i<(v->size);i++) {
        if (v->values[i] == a) return i;
    }
    return -1;
}

// função para remover de um voo num array dinâmico de voos
int removerVoo(Manager_Voos* gestor, Voo* a) {
    int n = prucura(a);
    if (n<0 || ManagerVazio(gestor)) return -1;
    else {
        for(int i = n;i<(gestor->size)-1;i++) {
            gestor->values [i] = gestor->values [i+1];
        }
    }
    free(gestor->values[gestor->sp]);
    (gestor->sp)--;
    (gestor->size)--;
    return 0;
}

// Funçao que encaxa ordenadamente os arrays L e M no array arr
void merge(Voo* arr[], int p, int q, int r) {

  // Cria L[p..q] e M[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  Voo L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // enquanto nao estamos no fim de L ou M organizamos o array elemento a elemento
  while (i < n1 && j < n2) {
    if (compararDataHora(L[i->actual_departure],M[i->actual_departure]) >= 0 ) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // quando chegamos ao fim de um dos dois pomos o resto em L ou em M o que ainda nao tiver acabado
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide o array em 2 subarrays, ordena-os e encaxa-os ordenademente
void mergeSort(Voo* arr[], int l, int r) {
  if (l < r) {

    // m é o ponto onde o array vai ser dividido em 2 subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Encaxa ordenadamente os subarrays ordenados
    merge(arr, l, m, r);
  }
}

//função que chama o mergeSort para ordenar o array dos voos pelas datas das actual_partidas
void ordenaManager_Voos_Por_DataDeparture (Manager_Voos* v) {
    mergeSort(v->values,0,v->sp);
}

// funçao que mostra uma lista de voos
void ShowManager_Voos(Manager_Voos v) {
    int i;
    printf("%d Items: ", s->sp);
    for (i = 0; i <= v->sp; i++)
        printf("%d ", v->values[i]);
    putchar('\n');
}

#endif