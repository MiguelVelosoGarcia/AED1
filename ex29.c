/*
    Miguel Veloso Garcia
    169.036
*/

#include <stdio.h>

int main() {
    int X, Y;
    scanf("%d %d", &X, &Y);

    int count = 1;

    while (count <= Y) {
        for (int i = 0; i < X; i++) {
            if (count > Y) break;
            printf("%d", count);
            if (i < X - 1) {
                printf(" ");
            }
            count++;
        }
        printf("\n");
    }

    return 0;
}
