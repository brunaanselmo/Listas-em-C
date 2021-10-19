#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Escreva uma rotina que retorne o número de elementos de uma lista.

typedef struct no Elemento;

struct no
{
	int num;
	struct no *ante;
	struct no *prox;
};

typedef struct lista Lista;

struct lista
{
	Elemento *inicio;
	Elemento *fim;
};

void Cria(Lista *L1)
{
	L1->inicio = NULL;
	L1->fim = NULL;
	printf("\nLista criada com sucesso!!!\n");
	return;
}

void Insere(Lista *L1)
{
	Elemento *novo;
	novo = (Elemento *)malloc(sizeof(Elemento));
	printf("\nInsira um elemento na lista:   ");
	scanf("%d", &novo->num);
	novo->prox = NULL;
	novo->ante = NULL;
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

void Quant(Lista *L1)
{
	Elemento *aux;
	int cont = 0;
	aux = L1->inicio;
	while (aux != NULL)
	{
		cont++;
		aux = aux->prox;
	}
	printf("A quantidade de elementos é %d \n", cont);
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
