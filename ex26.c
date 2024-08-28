/*
    Miguel Veloso Garcia
    169.036
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char caractere;
    struct celula *proxima;
} Celula;

void empilhar(Celula **topo, char caractere) {
    Celula *nova = malloc(sizeof(Celula));
    if (nova == NULL) {
        printf("Erro: falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    nova->caractere = caractere;
    nova->proxima = *topo;
    *topo = nova;
}

char desempilhar(Celula **topo) {
    if (*topo == NULL) {
        printf("Erro: pilha vazia.\n");
        exit(EXIT_FAILURE);
    }
    Celula *temp = *topo;
    char caractere = temp->caractere;
    *topo = temp->proxima;
    free(temp);
    return caractere;
}

int main() {
    int tamanho, i, j;
    char entrada[27], saida[27];
    Celula *pilha;

    while (scanf("%d", &tamanho) && tamanho != 0) {
        for (i = 0; i < tamanho; i++) {
            scanf(" %c", &entrada[i]); // Corrigido para ler um caractere
        }
        for (i = 0; i < tamanho; i++) {
            scanf(" %c", &saida[i]); // Corrigido para ler um caractere
        }

        char movimentos[2 * tamanho + 1];
        int indiceMovimentos = 0;
        int impossivel = 0;

        pilha = NULL;
        i = 0;
        j = 0;

        while (i < tamanho) {
            empilhar(&pilha, entrada[i]);
            movimentos[indiceMovimentos++] = 'I';
            while (pilha != NULL && pilha->caractere == saida[j]) {
                desempilhar(&pilha);
                movimentos[indiceMovimentos++] = 'R';
                j++;
            }
            i++;
        }

        while (pilha != NULL && pilha->caractere == saida[j]) {
            desempilhar(&pilha);
            movimentos[indiceMovimentos++] = 'R';
            j++;
        }

        movimentos[indiceMovimentos] = '\0';

        if (j == tamanho) {
            printf("%s\n", movimentos);
        } else {
            printf("%s Impossible\n", movimentos);
        }
    }

    return 0;
}
