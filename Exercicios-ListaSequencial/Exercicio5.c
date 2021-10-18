#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 30

//Escreva  uma  rotina  que  receba  uma  lista  e  um  número  X  e  retorne  o  número  de  nós  da  lista  que possuem valores menores do que o número X.

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
	printf("Vc deseja inserir quantos números na lista? \n");
	scanf("%d", &quant);
	for (int i = 0; i < quant; i++)
	{
		printf("Insira um elemento na lista:\n");
		scanf("%d", &L1->elem[i]);
		L1->nElem++;
	}
	printf("\nDigite o número que vc deseja verificar quantos números existem na lista que são menores que ele:  ");
	scanf("%d", &numero);
	return (numero);
}

int Quant(Lista *L1, int numero)
{
	printf("\nA quantidade de elementos na lista é: %d \n\n", L1->nElem);
	//return(L1->nElem);
	int i, cont = 0;
	for (i = 0; i < L1->nElem; i++)
	{
		if (L1->elem[i] < numero)
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

		printf("Digite a opção que vc deseja: \n");
		printf("1- Criar Lista\n");
		printf("2 - Inserir elementos na lista\n");
		printf("3 - Mostrar a quantidade números na lista que são menores que o número X\n");
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
			//	printf("\nA quantidade de elementos na lista é %d\n\n",Quant(L1));
			printf("A quantidade de números menores que o número %d é: %d\n\n", numero, cont);
			break;
		}
		system("PAUSE");
		system("cls");
	} while (op != 0);
}
