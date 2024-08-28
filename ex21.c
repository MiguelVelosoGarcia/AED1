/*
    Miguel Veloso Garcia
    169.036
*/

#include <stdio.h>
#include <string.h>

#define TAMANHO_MAX 1000

int minLetrasParaAdicionar(char sequencia[]) {
    int frequencia[26] = {0}; // Array para contar a frequência de cada letra
    int contagemImpar = 0; // Contador para letras com frequência ímpar

    // Contagem da frequência de cada letra na sequência
    for (int i = 0; i < strlen(sequencia); i++) {
        frequencia[sequencia[i] - 'a']++;
    }

    // Contagem de letras com frequência ímpar
    for (int i = 0; i < 26; i++) {
        if (frequencia[i] % 2 != 0) {
            contagemImpar++;
        }
    }

    // O número de letras a serem adicionadas é o máximo entre 0 e (número de letras com frequência ímpar - 1)
    return (contagemImpar == 0) ? 0 : contagemImpar - 1;
}

int main() {
    char sequencia[TAMANHO_MAX];

    // Loop para processar múltiplos casos de teste
    while (scanf("%s", sequencia) != EOF) {
        printf("%d\n", minLetrasParaAdicionar(sequencia));
    }

    return 0;
}