#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Escreva  uma  rotina  que  receba  uma  lista  e  um  n�mero  X  e  retorne  o  n�mero  de  n�s  da  lista  que possuem valores maiores do que o n�mero X.

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

int Insere(Lista *L1)
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
int Quant(Lista *L1, int numero)
{
	int cont = 0;
	Elemento *aux;
	aux = L1->inicio;
	while (aux != NULL)
	{
		if (aux->num > numero)
			cont++;
		aux = aux->prox;
	}
	//printf("A quantidade de vezes que o n�mero %d aparece na lista � %d\n",numero, cont);
	return (cont);
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	Lista L1;
	int numero, cont = 0;
	int op;
	do
	{
		printf("Digite a op��o que vc deseja: \n");
		printf("1 - Criar Lista\n");
		printf("2 - Inserir elementos na lista\n");
		printf("3 - Mostrar a quantidade de n�meros na lista que s�o maiores que o n�mero X\n");
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
			Insere(&L1);
			Insere(&L1);
			break;
		case 3:
			printf("\nDigite o n�mero que vc deseja ver a quantidade de n�meros maiores que ele \n");
			scanf("%d", &numero);
			cont = Quant(&L1, numero);
			printf("\nA quantidade de n�meros maiores que o n�mero %d �: %d\n\n", numero, cont);
			break;
		}
		system("PAUSE");
		system("cls");
	} while (op != 0);
}
