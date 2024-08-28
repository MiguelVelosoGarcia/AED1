/*
    Miguel Veloso Garcia
    169.036
*/

#include <stdio.h>

// Função para calcular a soma de números ímpares entre valor_inicial e valor_final
int calcularSomaImpares(int valor_inicial, int valor_final) {
    int soma = 0;
    // Garante que valor_inicial seja o menor e valor_final o maior
    if (valor_inicial > valor_final) {
        int temp = valor_inicial;
        valor_inicial = valor_final;
        valor_final = temp;
    }
    // Percorre os números de valor_inicial a valor_final e soma os ímpares
    for (int i = valor_inicial + 1; i < valor_final; i++) {
        if (i % 2 != 0) {
            soma += i;
        }
    }
    return soma;
}

int main() {
    int numero_casos;
    scanf("%d", &numero_casos); // Lê o número de casos de teste

    for (int caso_atual = 0; caso_atual < numero_casos; caso_atual++) {
        int valor_inicial, valor_final;
        scanf("%d %d", &valor_inicial, &valor_final); // Lê os valores valor_inicial e valor_final

        // Calcula a soma de ímpares entre valor_inicial e valor_final
        int resultado = calcularSomaImpares(valor_inicial, valor_final);

        // Imprime o resultado para este caso de teste
        printf("%d\n", resultado);
    }

    return 0;
}
