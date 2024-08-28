/*
    Miguel Veloso Garcia
    169.036
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int numerador;
    int denominador;
    struct celula *proxima;
} Celula;

typedef struct {
    Celula *inicio;
    Celula *fim;
} Fila;

// Função para inicializar a fila
void inicializarFila(Fila *f) {
    f->inicio = f->fim = NULL;
}

// Função para verificar se a fila está vazia
int filaVazia(Fila *f) {
    return f->inicio == NULL;
}

// Função para enfileirar um elemento
void enfileirar(Fila *f, int numerador, int denominador) {
    Celula *nova = (Celula*) malloc(sizeof(Celula));
    if (nova == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }

    nova->numerador = numerador;
    nova->denominador = denominador;
    nova->proxima = NULL;

    if (filaVazia(f)) {
        f->inicio = f->fim = nova;
    } else {
        f->fim->proxima = nova;
        f->fim = nova;
    }
}

// Função para desenfileirar um elemento
void desenfileirar(Fila *f, int *numerador, int *denominador) {
    if (filaVazia(f)) {
        printf("Fila vazia.\n");
        exit(1);
    }

    Celula *temp = f->inicio;
    *numerador = temp->numerador;
    *denominador = temp->denominador;

    f->inicio = temp->proxima;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(temp);
}

// Função para calcular o máximo divisor comum (MDC) usando o algoritmo de Euclides
int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Função para simplificar uma fração
void simplificar(int *numerador, int *denominador) {
    int divisor = mdc(abs(*numerador), abs(*denominador));
    *numerador /= divisor;
    *denominador /= divisor;
}

// Função principal para processar a entrada e realizar as operações
int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int num1, den1, num2, den2;
        char operador;

        scanf("%d / %d %c %d / %d", &num1, &den1, &operador, &num2, &den2);

        int resultado_numerador, resultado_denominador;

        switch (operador) {
            case '+':
                resultado_numerador = num1 * den2 + num2 * den1;
                resultado_denominador = den1 * den2;
                break;
            case '-':
                resultado_numerador = num1 * den2 - num2 * den1;
                resultado_denominador = den1 * den2;
                break;
            case '*':
                resultado_numerador = num1 * num2;
                resultado_denominador = den1 * den2;
                break;
            case '/':
                resultado_numerador = num1 * den2;
                resultado_denominador = num2 * den1;
                break;
        }

        int num_original = resultado_numerador;
        int den_original = resultado_denominador;

        simplificar(&resultado_numerador, &resultado_denominador);

        printf("%d/%d = %d/%d\n", num_original, den_original, resultado_numerador, resultado_denominador);
    }

    return 0;
}
