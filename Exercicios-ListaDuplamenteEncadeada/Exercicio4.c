#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Escreva  uma  rotina  que  receba  uma  lista  e  um  número  X  e  retorne  o  número  de  nós  da  lista  que possuem valores maiores do que o número X

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
		printf("Digite a opção que vc deseja: \n");
		printf("1 - Criar Lista\n");
		printf("2 - Inserir elementos na lista\n");
		printf("3 - Mostrar a quantidade de números maiores que o número X existem na lista\n");
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
			printf("\nDigite o número que vc deseja ver a quantidade de números maiores que ele:  ");
			scanf("%d", &numero);
			cont = Quant(&L1, numero);
			printf("\nA quantidade de números maiores que o número %d é: %d\n\n", numero, cont);
			break;
		}
		system("PAUSE");
		system("cls");
	} while (op != 0);
}
