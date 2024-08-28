/*
    Miguel Veloso Garcia
    169.036
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int valor;
    struct celula *proxima;
} Celula;

void empilhar(Celula **topo, int valor) {
    Celula *nova = malloc(sizeof(Celula));
    if (nova == NULL) {
        printf("Erro: falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    nova->valor = valor;
    nova->proxima = *topo;
    *topo = nova;
}

int desempilhar(Celula **topo) {
    if (*topo == NULL) {
        printf("Erro: pilha vazia.\n");
        exit(EXIT_FAILURE);
    }
    Celula *temp = *topo;
    int valor = temp->valor;
    *topo = temp->proxima;
    free(temp);
    return valor;
}

int verificarPermutacao(int *vagao, int tamanho) {
    Celula *pilha = NULL;
    int i = 0, j = 0;

    for (i = 1; i <= tamanho; i++) {
        empilhar(&pilha, i);

        while (pilha != NULL && pilha->valor == vagao[j]) {
            desempilhar(&pilha);
            j++;
        }
    }

    return (pilha == NULL);
}

int main() {
    int tamanho, i;
    int vagao[1000];

    while (scanf("%d", &tamanho) && tamanho != 0) {
        while (1) {
            for (i = 0; i < tamanho; i++) {
                scanf("%d", &vagao[i]);
                if (vagao[0] == 0) break;
            }
            if (vagao[0] == 0) break;

            if (verificarPermutacao(vagao, tamanho)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        printf("\n");
    }

    return 0;
}
