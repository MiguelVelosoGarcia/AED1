/*
    Miguel Veloso Garcia
    169.036
*/

#include <stdio.h>

int main() {

    int vetor[20], auxiliar, k, m;
    
    for(m = 0; m < 20; m++){
        scanf("%d", &vetor[m]);
    }
    
    for(m = 0, k = 19; m < 10; m++, k--){
        
        auxiliar = vetor[m];
        vetor[m] = vetor[k];
        vetor[k] = auxiliar;
    }    
    
    for(m = 0; m < 20; m++){
        printf("N[%d] = %d\n", m, vetor[m]);
    } 
        
    return 0;
}