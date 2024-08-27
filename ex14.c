/*
    Miguel Veloso Garcia
    169.036
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_ESTUDANTES 1000

int comparar(const void *x, const void *y) {
    return (*(int *)y - *(int *)x);
}

int main() {
    int total_turmas; 
    scanf("%d", &total_turmas);
    while (total_turmas--) {
        int qtd_estudantes;
        scanf("%d", &qtd_estudantes);
        int notas_originais[MAX_ESTUDANTES];
        int notas_classificadas[MAX_ESTUDANTES];
        for (int indice = 0; indice < qtd_estudantes; indice++) {
            scanf("%d", &notas_originais[indice]);
            notas_classificadas[indice] = notas_originais[indice];
        }
        qsort(notas_classificadas, qtd_estudantes, sizeof(int), comparar);
        int contagem_corretos = 0;
        for (int indice = 0; indice < qtd_estudantes; indice++) {
            if (notas_originais[indice] == notas_classificadas[indice]) {
                contagem_corretos++;
            }
        }
        printf("%d\n", contagem_corretos);
    }
}