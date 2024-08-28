/*
    Miguel Veloso Garcia
    169.036
*/

#include <stdio.h>

int main() {
    char O;
    double M[12][12];
    double resultado = 0.0;
    int contador = 0;

    scanf(" %c", &O);

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%lf", &M[i][j]);
        }
    }

    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 12 - i - 1; j++) {
            resultado += M[i][j];
            contador++;
        }
    }

    if (O == 'M') {
        resultado /= contador;
    }

    printf("%.1f\n", resultado);

    return 0;
}
