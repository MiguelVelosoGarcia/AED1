/*
    Miguel Veloso Garcia
    169.036
*/

#include <stdio.h>
#include <stdlib.h>

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

int verificarParenteses(char expressao[]) {
    Celula *pilha = NULL;
    int i = 0;

    while (expressao[i] != '\0') {
        if (expressao[i] == '(') {
            empilhar(&pilha, '(');
        } else if (expressao[i] == ')') {
            if (pilha == NULL || desempilhar(&pilha) != '(') {
                return 0; // Encontrou um ')' sem '(' correspondente
            }
        }
        i++;
    }

    if (pilha != NULL) {
        return 0; // Ainda há '(' não fechados
    }

    return 1; // Todos os parênteses estão corretos
}

int main() {
    char expressao[1001];

    while (scanf("%[^\n]%*c", expressao) != EOF) {
        if (verificarParenteses(expressao)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
        if (expressao[0] == '\0') {
            break; // Parar ao encontrar uma linha em branco
        }
    }

    return 0;
}
