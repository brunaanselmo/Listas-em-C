#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 30

//Escreva  uma  rotina que  receba  uma  lista  e  um  n?mero  X  e  retorne  o  n?mero  de  n?s  da  lista  que possuem o n?mero X

struct lista
{
	int elem[MAX];
	int nElem;
};

typedef struct lista Lista;

Lista *L1;

void Cria();
int Insere(Lista *L1);
int Quant(Lista *L1, int numero);

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

int Insere(Lista *L1)
{
	int quant, numero;
	printf("Vc deseja inserir quantos n?meros na lista? \n");
	scanf("%d", &quant);
	for (int i = 0; i < quant; i++)
	{
		printf("Insira um elemento na lista:\n");
		scanf("%d", &L1->elem[i]);
		L1->nElem++;
	}
	printf("\nDigite o n?mero que vc deseja ver quantas vezes ele aparece na lista:  ");
	scanf("%d", &numero);
	return (numero);
}

int Quant(Lista *L1, int numero)
{
	printf("\nA quantidade de elementos na lista ?: %d \n\n", L1->nElem);
	//return(L1->nElem);
	int i, cont = 0;
	for (i = 0; i < L1->nElem; i++)
	{
		if (L1->elem[i] == numero)
			cont++;
	}
	return (cont);
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int numero, cont;
	int op;
	do
	{

		printf("Digite a op??o que vc deseja: \n");
		printf("1- Criar Lista\n");
		printf("2 - Inserir elementos na lista\n");
		printf("3 - Mostrar a quantidade de vezes que o n?mero X aparece na lista\n");
		printf("Digite 0 para sair\n");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			Cria();
			break;
		case 2:
			numero = Insere(L1);
			break;
		case 3:
			cont = Quant(L1, numero);
			//	printf("\nA quantidade de elementosn na lista ?: %d\n\n",Quant(L1));
			printf("A quantidade de vezes que o n?mero %d aparece na lista ?: %d\n\n", numero, cont);
			break;
		}
		system("PAUSE");
		system("cls");
	} while (op != 0);
}
