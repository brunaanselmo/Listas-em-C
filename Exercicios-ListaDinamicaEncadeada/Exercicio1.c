#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Escreva uma rotina que retorne o número de elementos de uma lista.

struct No
{
	int num;
	struct No *prox;
};

typedef struct No Elemento;

struct lista
{
	Elemento *inicio;
	Elemento *fim;
};

typedef struct lista Lista;

void Cria(Lista *L1)
{
	L1->inicio = NULL;
	L1->fim = NULL;
	printf("\nLista inicializada com sucesso!!\n\n");
	return;
}

void Insere(Lista *L1)
{
	Elemento *novo;
	novo = (Elemento *)malloc(sizeof(Elemento));
	printf("\n\nInsira um elemento na lista:  ");
	scanf("%d", &novo->num);
	novo->prox = NULL;

	if (L1->inicio == NULL)
	{ //lista vazia
		L1->inicio = novo;
		L1->fim = novo;
	}
	else
	{
		L1->fim->prox = novo;
		L1->fim = novo;
	}
}

void Quant(Lista *L1)
{
	int cont = 0;
	Elemento *aux;
	aux = L1->inicio;
	while (aux != NULL)
	{
		cont++;
		aux = aux->prox;
	}
	printf("A quantidade de elementos na lista é: %d \n", cont);
	return;
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	Lista L1;
	int op;
	do
	{
		printf("Digite a opção que vc deseja: \n");
		printf("1 - Criar Lista\n");
		printf("2 - Inserir elementos na lista\n");
		printf("3 - Mostrar a quantidade de elementos na lista\n");
		printf("Digite 0 para sair\n");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			Cria(&L1);
			break;
		case 2:
			Insere(&L1);
			Insere(&L1);
			Insere(&L1);

			break;
		case 3:
			Quant(&L1);
			break;
		}
		system("PAUSE");
		system("cls");
	} while (op != 0);
}
