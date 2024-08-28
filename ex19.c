/*
    Miguel Veloso Garcia
    169.036
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_MAX_PALAVRA 21 // 20 caracteres + 1 para o caractere nulo

struct Palavra {
    char texto[TAMANHO_MAX_PALAVRA];
    struct Palavra* proxima;
};

struct Palavra* novaPalavra(char* texto);
void inserir(struct Palavra** ref_inicio, char* texto);
void imprimir(struct Palavra* celula);

int main(void) {
    int quantidade_listas;
    char *entrada;
    size_t tamanho_max_entrada = 1000 * (TAMANHO_MAX_PALAVRA + 1); // Tamanho máximo da linha considerando 1000 palavras de até 20 caracteres cada

    entrada = (char*)malloc(tamanho_max_entrada * sizeof(char)); // Aloca memória para a linha de entrada
    if (entrada == NULL) {
        printf("Erro: Falha ao alocar memória para entrada.\n");
        return 1;
    }

    struct Palavra* inicio = NULL;

    scanf("%d\n", &quantidade_listas);
    for (int i = 0; i < quantidade_listas; i++) {
        fgets(entrada, tamanho_max_entrada, stdin);
        entrada[strcspn(entrada, "\n")] = 0;

        // Limpa a lista para cada nova linha
        inicio = NULL;

        char *tokenizador = strtok(entrada, " ");
        while (tokenizador != NULL) {
            inserir(&inicio, tokenizador);
            tokenizador = strtok(NULL, " ");
        }
        imprimir(inicio);
    }

    free(entrada); // Libera a memória alocada para a linha de entrada
    return 0;
}

struct Palavra* novaPalavra(char* texto) {
    struct Palavra* nova_palavra = (struct Palavra*)malloc(sizeof(struct Palavra));
    if (nova_palavra == NULL) {
        printf("Erro: Falha ao alocar memória para novaPalavra.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(nova_palavra->texto, texto); // Usando strcpy para copiar a palavra completa
    nova_palavra->proxima = NULL;
    return nova_palavra;
}

void inserir(struct Palavra** ref_inicio, char* texto) {
    struct Palavra* nova_palavra = novaPalavra(texto);
    struct Palavra* anterior = NULL;
    struct Palavra* atual = *ref_inicio;

    if (*ref_inicio == NULL || strcmp(nova_palavra->texto, atual->texto) < 0) {
        nova_palavra->proxima = *ref_inicio;
        *ref_inicio = nova_palavra;
        return;
    }

    while (atual != NULL && strcmp(atual->texto, nova_palavra->texto) < 0) {
        anterior = atual;
        atual = atual->proxima;
    }

    if (anterior == NULL) {
        nova_palavra->proxima = *ref_inicio;
        *ref_inicio = nova_palavra;
    } else {
        anterior->proxima = nova_palavra;
        nova_palavra->proxima = atual;
    }
}

void imprimir(struct Palavra* celula) {
    struct Palavra* atual = celula;
    struct Palavra* proximo;

    while (atual != NULL) {
        printf("%s", atual->texto);
        proximo = atual->proxima;

        // Avança até o próximo item diferente
        while (proximo != NULL && strcmp(atual->texto, proximo->texto) == 0) {
            proximo = proximo->proxima;
        }

        atual = proximo;

        if (atual != NULL) {
            printf(" ");
        }
    }
    printf("\n");
}