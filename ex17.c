/*
    Miguel Veloso Garcia
    169.036
*/

#include <stdio.h>
#include <math.h>

typedef struct {
    int coordenada_x, coordenada_y, coordenada_z;
    double distancia_proxima; // Distância para a nave mais próxima
    char nivel_intensidade; // Intensidade do sinal: 'A', 'M' ou 'B'
} Nave;

double calcular_distancia(Nave nave1, Nave nave2) {
    return sqrt(pow(nave1.coordenada_x - nave2.coordenada_x, 2) + pow(nave1.coordenada_y - nave2.coordenada_y, 2) + pow(nave1.coordenada_z - nave2.coordenada_z, 2));
}

int main() {
    int total_naves;
    scanf("%d", &total_naves);

    Nave naves[total_naves];
    for (int indice_nave = 0; indice_nave < total_naves; indice_nave++) {
        scanf("%d %d %d", &naves[indice_nave].coordenada_x, &naves[indice_nave].coordenada_y, &naves[indice_nave].coordenada_z);
        naves[indice_nave].distancia_proxima = INFINITY; // Inicializa com um valor muito grande
    }

    for (int indice_nave = 0; indice_nave < total_naves; indice_nave++) {
        double menor_distancia_encontrada = INFINITY; // Começa com um valor muito grande
        int indice_nave_proxima = -1;

        for (int outra_nave = 0; outra_nave < total_naves; outra_nave++) {
            if (indice_nave != outra_nave) {
                double distancia_atual = calcular_distancia(naves[indice_nave], naves[outra_nave]);
                if (distancia_atual < menor_distancia_encontrada) {
                    menor_distancia_encontrada = distancia_atual;
                    indice_nave_proxima = outra_nave;
                }
            }
        }

        // Atualiza os campos da nave atual com a menor distância encontrada
        naves[indice_nave].distancia_proxima = menor_distancia_encontrada;

        // Determina a intensidade de sinal entre a nave atual e a mais próxima
        if (menor_distancia_encontrada <= 20) {
            naves[indice_nave].nivel_intensidade = 'A'; // Alta
        } else if (menor_distancia_encontrada <= 50) {
            naves[indice_nave].nivel_intensidade = 'M'; // Média
        } else {
            naves[indice_nave].nivel_intensidade = 'B'; // Baixa
        }
    }

    // Saída
    for (int indice_nave = 0; indice_nave < total_naves; indice_nave++) {
        printf("%c\n", naves[indice_nave].nivel_intensidade);
    }

    return 0;
}