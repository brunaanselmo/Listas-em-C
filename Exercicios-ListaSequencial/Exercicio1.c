#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 30

//Escreva uma rotina que retorne o número de elementos de uma lista.

struct lista
{
	int elem[MAX];
	int nElem;
};

typedef struct lista Lista;

Lista *L1;

void Cria();
void Insere(Lista *L1);
int Quant(Lista *L1);

void Cria()
{
	L1 = (Lista *)malloc(sizeof(struct lista));
	if (L1 != NULL)
		L1->nElem = 0;
	for (int i = 0; i < MAX; i++)
	{
		L1->elem[i] = -1;
	}
	printf(" \n Lista criada com sucesso!!!  \n");
	return;
}

void Insere(Lista *L1)
{
	int quant;
	printf("Vc deseja inserir quantos números na lista? \n");
	scanf("%d", &quant);
	for (int i = 0; i < quant; i++)
	{
		printf("Insira um elemento na lista:\n");
		scanf("%d", &L1->elem[i]);
		L1->nElem++;
	}
	return;
}

int Quant(Lista *L1)
{
	//printf("\nA quantidade de elementos na lista é: %d \n\n", L1->nElem);
	return (L1->nElem);
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int op;
	do
	{

		printf("Digite a opção que vc deseja: \n");
		printf("1- Criar Lista\n");
		printf("2 - Inserir elementos na lista\n");
		printf("3 - Mostrar a quantidade de elementos na lista\n");
		printf("Digite 0 para sair\n");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			Cria();
			break;
		case 2:
			Insere(L1);
			break;
		case 3:
			//	Quant(L1);
			printf("\nA quantidade de elementosn na lista é: %d\n\n", Quant(L1));
			break;
		}
		system("PAUSE");
		system("cls");
	} while (op != 0);
}
