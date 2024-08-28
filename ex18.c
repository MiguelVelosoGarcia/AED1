/*
    Miguel Veloso Garcia
    169.036
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAMANHO 15
int status_primeiro = 0;

struct Celula {
  char nome[50];
  struct Celula *proxima;
};

struct Celula* novaCelula(char* nome){
  struct Celula* nova_celula = (struct Celula*)malloc(sizeof(struct Celula));
  strcpy(nova_celula->nome, nome);
  nova_celula->proxima = NULL;
  return nova_celula;
}

void adicionar(struct Celula** referencia_cabeca, char* nome);
void mesclarListas(struct Celula** lista1, struct Celula* lista2);
void mesclarEncontrado(struct Celula** encontrado, struct Celula* lista1, struct Celula* lista2);
struct Celula* procurarCelula(struct Celula* cabeca, char* nome);
void imprimirLista(struct Celula *celula);

int main(void){
  char linha1[500], linha2[500], nome_procura[50];
  char *tokenizador;

  struct Celula* cabeca1 = NULL;
  struct Celula* cabeca2 = NULL;

  fgets(linha1, sizeof(linha1), stdin);
  fgets(linha2, sizeof(linha1), stdin);
  fgets(nome_procura, sizeof(nome_procura), stdin);
  nome_procura[strcspn(nome_procura, "\n")] = 0;

  tokenizador = strtok(linha1, " ");
  while(tokenizador != NULL){
    adicionar(&cabeca1, tokenizador);
    tokenizador = strtok(NULL, " ");
  }
  tokenizador = strtok(linha2, " ");
  while(tokenizador != NULL){
    adicionar(&cabeca2, tokenizador);
    tokenizador = strtok(NULL, " ");
  }
  struct Celula* celula_encontrada = procurarCelula(cabeca1, nome_procura);
  if (celula_encontrada != NULL){
    mesclarEncontrado(&(celula_encontrada), cabeca1, cabeca2);
  } else if(strcmp(nome_procura, "nao") == 0){
    mesclarListas(&cabeca1, cabeca2);
  }

  (!status_primeiro || status_primeiro == 2) ? imprimirLista(cabeca1) : imprimirLista(cabeca2);

  return 0;
}

void adicionar(struct Celula** referencia_cabeca, char* nome){
  nome[strcspn(nome, "\n")] = 0;

  struct Celula* nova_celula = novaCelula(nome);
  struct Celula *ultima = *referencia_cabeca;

  if (*referencia_cabeca == NULL){
    *referencia_cabeca = nova_celula;
    return;
  }

  while (ultima->proxima != NULL)
    ultima = ultima->proxima;

  ultima->proxima = nova_celula;
  return;
}

void mesclarListas(struct Celula** lista1, struct Celula* lista2){
  if (*lista1 == NULL){
    *lista1 = lista2;
    return;
  }

  struct Celula* ultima = *lista1;
  while (ultima->proxima != NULL){
    ultima = ultima->proxima;
  }
  ultima->proxima = lista2;
}

void mesclarEncontrado(struct Celula** encontrado, struct Celula* lista1, struct Celula* lista2){
  if (status_primeiro == 1){
    mesclarListas(&lista2, lista1);
    return;
  }
  struct Celula* ultima = *encontrado;
  struct Celula* resto = ultima->proxima;
  ultima->proxima = lista2;
  while (lista2->proxima != NULL){
    lista2 = lista2->proxima;
  }
  lista2->proxima = resto;
}

struct Celula* procurarCelula(struct Celula* cabeca, char* nome){
  struct Celula* anterior = cabeca;
  int contador = 0;
  while(cabeca != NULL){
    if (strcmp(cabeca->nome, nome) == 0){
      cabeca = anterior;
      if(!contador) status_primeiro = 1;
      else if (contador == 1) status_primeiro = 2;
      return cabeca;
    }
    anterior = cabeca;
    cabeca = cabeca->proxima;
    contador++;
  }
  return NULL;
}

void imprimirLista(struct Celula *celula){
  while (celula != NULL){
    printf("%s", celula->nome);
    if (celula->proxima != NULL)
      printf(" ");
    celula = celula->proxima;
  }
  printf("\n");
}