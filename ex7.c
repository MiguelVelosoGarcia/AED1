/*
    Miguel Veloso Garcia
    169.036
*/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int inicio, fim, valor;
} arco;

arco conexoes[250];
int raiz[70];

int comparar_arcos(arco *, arco *);
int encontrar_raiz(int);
int calcular_custo(int);

int main(int argc, char **argv) {
    int dispositivos, ligacoes, i;

    scanf("%d %d", &dispositivos, &ligacoes);

    for (i = 0; i < ligacoes; ++i)
        scanf("%d %d %d", &conexoes[i].inicio, &conexoes[i].fim, &conexoes[i].valor);

    qsort(conexoes, ligacoes, sizeof(arco), comparar_arcos);

    for (i = 1; i <= dispositivos; ++i)
        raiz[i] = i;

    printf("%d\n", calcular_custo(ligacoes));

    return 0;
}

int comparar_arcos(arco *a, arco *b) {
    return a->valor - b->valor;
}

int encontrar_raiz(int indice) {
    if (indice == raiz[indice])
        return indice;
    return encontrar_raiz(raiz[indice]);
}

int calcular_custo(int ligacoes) {
    int i, total, origem, destino;

    total = 0;

    for (i = 0; i < ligacoes; ++i) {
        origem = encontrar_raiz(conexoes[i].inicio);
        destino = encontrar_raiz(conexoes[i].fim);

        if (origem != destino) {
            raiz[origem] = raiz[destino];
            total += conexoes[i].valor;
        }
    }

    return total;
}