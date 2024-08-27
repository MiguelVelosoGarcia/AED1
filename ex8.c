/*
	Miguel Veloso Garcia
    169.036
*/

#include <stdio.h>
#include <stdlib.h> // Incluído para uso de malloc e free
#include <string.h>

typedef struct{
	char nomeEstudante[30];
} String;

void ordenar(String *, unsigned short quantidade);

int main() // O tipo da função main deve ser 'int' para retornar um valor.
{
	unsigned short indice;
	unsigned short totalEstudantes, estudanteSelecionado;

	scanf("%hu %hu", &totalEstudantes, &estudanteSelecionado);
	String *listaEstudantes = (String *)malloc(totalEstudantes * sizeof(String));

	if (listaEstudantes == NULL) { // Verifica se a alocação foi bem-sucedida
		printf("Erro na alocação de memória.\n");
		return 1;
	}

	for (indice = 0; indice < totalEstudantes; indice++)
		scanf("%s", listaEstudantes[indice].nomeEstudante);

	ordenar(listaEstudantes, totalEstudantes);
	
	printf("%s\n", listaEstudantes[estudanteSelecionado - 1].nomeEstudante);

	free(listaEstudantes); // Libera a memória alocada

	return 0; // Retorna 0 para indicar que o programa terminou corretamente
}

void ordenar(String *listaEstudantes, unsigned short quantidade)
{
	short indice = 1, posicao;
	String elementoTemporario;

	while (indice < quantidade)
	{
		posicao = indice - 1;
		elementoTemporario = listaEstudantes[indice];

		while (posicao >= 0 && strcmp(listaEstudantes[posicao].nomeEstudante, elementoTemporario.nomeEstudante) > 0)
		{
			listaEstudantes[posicao + 1] = listaEstudantes[posicao];
			posicao--;
		}

		listaEstudantes[posicao + 1] = elementoTemporario;
		indice++;
	}
}