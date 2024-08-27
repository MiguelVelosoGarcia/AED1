/*
    Miguel Veloso Garcia
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Cliente {
    int codigo;
    int quantidade_itens;
    struct Cliente* proximo;
} Cliente;

typedef struct {
    int codigo;
    int disponibilidade;
} Funcionario;

void adicionar_na_fila(Cliente **inicio_fila, Cliente **fim_fila, int codigo, int quantidade_itens) {
    Cliente* novo_cliente = (Cliente*)malloc(sizeof(Cliente));
    novo_cliente->codigo = codigo;
    novo_cliente->quantidade_itens = quantidade_itens;
    novo_cliente->proximo = NULL;

    if (*fim_fila == NULL) {
        *fim_fila = *inicio_fila = novo_cliente;
    } else {
        (*fim_fila)->proximo = novo_cliente;
        *fim_fila = novo_cliente;
    }
}

void remover_da_fila(Cliente **inicio_fila, Cliente **fim_fila) {
    Cliente *primeiro_cliente = *inicio_fila;
    *inicio_fila = primeiro_cliente->proximo;
    free(primeiro_cliente);
    if (*inicio_fila == NULL) {
        *fim_fila = NULL;
    }
}

void configurar_funcionarios(Funcionario* funcionarios, int* tempos_atendimento, int total_funcionarios) {
    for (int indice = 0; indice < total_funcionarios; indice++) {
        scanf("%d", &tempos_atendimento[indice]);
        if (tempos_atendimento[indice] < 1 || tempos_atendimento[indice] > 100) {
            printf("Tempo de processamento inválido para o funcionário %d.\n", indice + 1);
            exit(1);
        }
        funcionarios[indice].codigo = indice + 1;
        funcionarios[indice].disponibilidade = 0;
    }
}

int calcular_tempo_total(Cliente** inicio_fila, Cliente** fim_fila, Funcionario* funcionarios, int* tempos_atendimento, int total_funcionarios) {
    int tempo_total_fila = 0;
    while (*inicio_fila != NULL) {
        Cliente* cliente_atual = *inicio_fila;
        int itens_cliente = cliente_atual->quantidade_itens;
        remover_da_fila(inicio_fila, fim_fila);
        int indice_min_tempo = 0;
        for (int indice = 1; indice < total_funcionarios; indice++) {
            if (funcionarios[indice].disponibilidade < funcionarios[indice_min_tempo].disponibilidade) {
                indice_min_tempo = indice;
            }
        }
        if (funcionarios[indice_min_tempo].disponibilidade + itens_cliente * tempos_atendimento[indice_min_tempo] > tempo_total_fila) {
            tempo_total_fila = funcionarios[indice_min_tempo].disponibilidade + itens_cliente * tempos_atendimento[indice_min_tempo];
        }
        funcionarios[indice_min_tempo].disponibilidade += itens_cliente * tempos_atendimento[indice_min_tempo];
    }

    return tempo_total_fila;
}

int main () {
    int total_funcionarios, total_clientes;
    Cliente *inicio_fila, *fim_fila;
    inicio_fila = NULL; 
    fim_fila = NULL;

    scanf("%d %d", &total_funcionarios, &total_clientes);
    
    if (total_funcionarios < 1 || total_funcionarios > 10000 || total_clientes < total_funcionarios || total_clientes > 10000) {
        return 1;
    }

    int* tempos_atendimento = (int*)malloc(total_funcionarios * sizeof(int));
    Funcionario* funcionarios = (Funcionario*)malloc(total_funcionarios * sizeof(Funcionario));

    configurar_funcionarios(funcionarios, tempos_atendimento, total_funcionarios);

    for (int indice_cliente = 0; indice_cliente < total_clientes; indice_cliente++) {
        int quantidade_itens;
        scanf("%d", &quantidade_itens);
        if (quantidade_itens < 1 || quantidade_itens > 100) {
            printf("Número de itens inválido para o cliente %d.\n", indice_cliente + 1);
            return 1;
        }
        adicionar_na_fila(&inicio_fila, &fim_fila, indice_cliente + 1, quantidade_itens);
    }

    int tempo_total_fila = calcular_tempo_total(&inicio_fila, &fim_fila, funcionarios, tempos_atendimento, total_funcionarios);
    printf("%d\n", tempo_total_fila);

    free(tempos_atendimento);
    free(funcionarios);
    return 0;
}