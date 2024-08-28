/*
    Miguel Veloso Garcia
    169.036
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura de pilha
typedef struct {
    int topo;
    int capacidade;
    char *array;
} Pilha;

// Função para criar uma nova pilha
Pilha *criarPilha(int capacidade) {
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->capacidade = capacidade;
    pilha->topo = -1;
    pilha->array = (char *)malloc(pilha->capacidade * sizeof(char));
    return pilha;
}

// Função para verificar se a pilha está vazia
int estaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

// Função para empurrar um elemento para a pilha
void empurrar(Pilha *pilha, char item) {
    pilha->array[++pilha->topo] = item;
}

// Função para remover um elemento do topo da pilha
char remover(Pilha *pilha) {
    if (!estaVazia(pilha))
        return pilha->array[pilha->topo--];
    return '\0';
}

// Função para contar os diamantes possíveis
int contarDiamantes(char *s) {
    Pilha *pilha = criarPilha(strlen(s));
    int diamantes = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '<') {
            empurrar(pilha, '<');
        } else if (s[i] == '>') {
            if (!estaVazia(pilha) && pilha->array[pilha->topo] == '<') {
                diamantes++;
                remover(pilha);
            }
        }
    }

    free(pilha->array);
    free(pilha);
    return diamantes;
}

int main() {
    int numeroDeEntradas;
    scanf("%d", &numeroDeEntradas);
    getchar(); // Limpar o buffer

    char **entradas = (char **)malloc(numeroDeEntradas * sizeof(char *));
    int *resultados = (int *)malloc(numeroDeEntradas * sizeof(int));

    // Ler todas as entradas
    for (int i = 0; i < numeroDeEntradas; i++) {
        char *s = (char *)malloc(1001 * sizeof(char));
        fgets(s, 1001, stdin);
        entradas[i] = s;
        resultados[i] = contarDiamantes(s);
    }

    // Imprimir as saídas
    for (int i = 0; i < numeroDeEntradas; i++) {
        printf("%d\n", resultados[i]);
        free(entradas[i]); // Liberar memória alocada para cada entrada
    }

    free(entradas); // Liberar memória alocada para a matriz de entradas
    free(resultados); // Liberar memória alocada para o array de resultados

    return 0;
}