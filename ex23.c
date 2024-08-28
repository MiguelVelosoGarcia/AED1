/*
    Miguel Veloso Garcia
    169.036
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    int hours_per_present;
} Group;

// Função para calcular a quantidade de presentes por dia
int calculatePresents(int num_workers, char workers[][20], char worker_groups[][20], 
                     int working_hours[], Group groups[], int num_groups) {
    int total_presents = 0;
    int remaining_hours[num_groups];

    // Inicializar o array de horas não utilizadas
    for (int i = 0; i < num_groups; i++) {
        remaining_hours[i] = 0;
    }

    // Para cada trabalhador
    for (int i = 0; i < num_workers; i++) {
        int presents_per_worker = 0;
        // Procurar o grupo correspondente na lista de grupos
        for (int j = 0; j < num_groups; j++) {
            if (strcmp(worker_groups[i], groups[j].name) == 0) {
                // Calcular quantos presentes ele contribui
                presents_per_worker = (working_hours[i] / groups[j].hours_per_present);
                total_presents += presents_per_worker;

                // Calcular horas não utilizadas e acumular
                int hours_remaining = working_hours[i] % groups[j].hours_per_present;
                remaining_hours[j] += hours_remaining;

                break; // Encontrou o grupo, pode parar de procurar
            }
        }
    }

    // Calcular presentes adicionais a partir das horas não utilizadas
    for (int i = 0; i < num_groups; i++) {
        total_presents += (remaining_hours[i] / groups[i].hours_per_present);
    }

    return total_presents;
}

int main() {
    int N;
    scanf("%d", &N);

    char elfos[N][20]; // Array de nomes dos elfos
    char grupos_elfos[N][20]; // Array de grupos dos elfos
    int horas[N]; // Array de horas dos elfos

    // Leitura dos elfos
    for (int i = 0; i < N; i++) {
        scanf("%s %s %d", elfos[i], grupos_elfos[i], &horas[i]);
    }

    // Inicializar os grupos de trabalho e suas horas necessárias por presente
    Group grupos[] = {
        {"bonecos", 8},
        {"arquitetos", 4},
        {"musicos", 6},
        {"desenhistas", 12}
    };
    int num_groups = sizeof(grupos) / sizeof(Group);

    // Calcular a quantidade de presentes por dia
    int presentes_por_dia = calculatePresents(N, elfos, grupos_elfos, horas, grupos, num_groups);

    // Imprimir o resultado
    printf("%d\n", presentes_por_dia);

    return 0;
}