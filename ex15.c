/*
    Miguel Veloso Garcia
    169.036
*/

#include <stdio.h>

int main() {
    char entrada[100001];
    fgets(entrada, sizeof(entrada), stdin);
    int pendencias = 0;
    for (int posicao = 0; entrada[posicao] != '\0' && entrada[posicao] != '\n'; posicao++) {
        if (entrada[posicao] == '(') {
            pendencias++;
        } else if (entrada[posicao] == ')') {
            if (pendencias > 0) {
                pendencias--;
            }
        }
    }
    if (pendencias == 0) {
        printf("Partiu RU!\n");
    } else {
        printf("Ainda temos %d assunto(s) pendente(s)!\n", pendencias);
    }
}