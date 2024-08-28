/*
    Miguel Veloso Garcia
    169.036
*/

#include <stdio.h>

int main() {
    int A, N;

    scanf("%d", &A);

    while (1) {
        scanf("%d", &N);
        if (N > 0) {
            break;
        }
    }

    int soma = 0;
    for (int i = 0; i < N; i++) {
        soma += (A + i);
    }

    printf("%d\n", soma);

    return 0;
}
