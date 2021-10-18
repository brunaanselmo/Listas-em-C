#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 30

//Escreva uma rotina recursiva para determinar o número de elementos de uma lista.

struct lista
{
	int num[MAX];
	int nElem;
};

typedef struct lista Lista;
Lista *L1;

void Cria(Lista *L1);
void Insere(Lista *L1);
int Quant(Lista *L1);

void Cria(Lista *L1)
{
	L1 = (Lista *)malloc(sizeof(struct lista));
	if (L1 != NULL)
	{
		L1->nElem = 0;
		printf("\nLista criada com sucesso!!!\n");
	}
	return;
}

void Insere(Lista *L1)
{
	int i, quant;
	printf("Vc deseja inserir quantos elementos? \n ");
	scanf("%d", &quant);
	for (i = 0; i < quant; i++)
	{
		printf("Insira um elemento na lista:    ");
		scanf("%d", &L1->num[i]);
		L1->nElem++;
	}

	return;
}

int Quant(Lista *L1)
{
	if (L1 != NULL)
	{
		return (1 + Quant(L1));
	}
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
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
			Cria(L1);
			break;
		case 2:
			Insere(L1);
			break;
		case 3:
			printf("\nA quantidade de elementos na lista é %d\n\n", Quant(L1));
			break;
		}
		system("PAUSE");
		system("cls");
	} while (op != 0);
}
