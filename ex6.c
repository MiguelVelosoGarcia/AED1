/*
    @autor: Malbolge;
    @data: 14/06/2019;
    @nome: Itinerário do Papai Noel;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define verdadeiro 1
#define falso 0
#define TAMANHO_MAX 40050
#define TAMANHO_MAX_P 40000

typedef struct {
    int origem, destino, peso;
} aresta;

aresta grafo[TAMANHO_MAX];
int pais[TAMANHO_MAX_P];

int comparar(aresta *, aresta *);
int executarKruskal(int);
int encontrarComponente(int);

int main(int argc, char **argv) {

    int numVertices, numArestas, i;

    while (scanf("%d %d", &numVertices, &numArestas), numVertices && numArestas) {

        memset(grafo, 0, sizeof(grafo));
        memset(pais, 0, sizeof(pais));

        for (i = 0; i < numArestas; ++i)
            scanf("%d %d %d", &grafo[i].destino, &grafo[i].origem, &grafo[i].peso);

        qsort(grafo, numArestas, sizeof(aresta), comparar);

        for (i = 1; i <= numVertices; ++i)
            pais[i] = i;

        printf("%d\n", executarKruskal(numArestas));
    }

    return 0;
}

int comparar(aresta *a, aresta *b) {
    return a->peso - b->peso;
}

int encontrarComponente(int index) {

    if (index == pais[index])
        return index;

    return encontrarComponente(pais[index]);
}

int executarKruskal(int numComponentes) {

    int i, somaPesos, componenteOrigem, componenteDestino;

    for (i = 0, somaPesos = 0; i < numComponentes; ++i) {

        componenteOrigem = encontrarComponente(grafo[i].destino);
        componenteDestino = encontrarComponente(grafo[i].origem);

        if (componenteOrigem != componenteDestino)
            pais[componenteOrigem] = pais[componenteDestino], somaPesos += grafo[i].peso;
    }

    return somaPesos;
}