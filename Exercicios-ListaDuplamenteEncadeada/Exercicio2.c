#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Escreva uma rotina recursiva para determinar o número de elementos de uma lista.

struct No
{
	int num;
	struct No *ante;
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
	printf("\nLista criada com sucesso!!!!\n");
	return;
}

void Insere(Lista *L1)
{
	Elemento *novo;
	novo = (Elemento *)malloc(sizeof(Elemento));
	printf("\nInsira um elemento na lista:  ");
	scanf("%d", &novo->num);
	novo->ante = NULL;
	novo->prox = NULL;
	if (L1->inicio == NULL)
	{
		L1->inicio = novo;
		L1->fim = novo;
	}
	else
	{
		L1->inicio->ante = novo;
		novo->prox = L1->inicio;
		L1->inicio = novo;
	}
}

int Quant(Elemento quant)
{
	if (quant->prox == NULL)
		return 0;
	return 1 + Quant(quant->prox);
}

int main()
{
	Lista L1;
	int op;
	Elemento quant;
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
			Quant(quant);
			printf("\nA quantidade de elementos na lista é %d\n", quant);
			break;
		}
		system("PAUSE");
		system("cls");
	} while (op != 0);
}
