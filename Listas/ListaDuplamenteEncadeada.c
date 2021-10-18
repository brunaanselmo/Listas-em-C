#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

//LISTA DUPLAMENTE ENCADEADA

typedef struct no Elemento;

struct no
{
	int num;
	struct no *prox;
	struct no *ante;
};

typedef struct lista Lista;

struct lista
{
	Elemento *inicio;
	Elemento *fim;
};

void Inicializa(Lista *lista)
{
	lista->inicio = NULL;
	lista->fim = NULL;
	printf("\nLista inicializada com sucesso!!!!\n \n");
}

void Insere(Lista *lista)
{
	Elemento *novo;
	novo = (Elemento *)malloc(sizeof(Elemento));
	printf("\n\nInsira o número que vc deseja: \n");
	scanf("%d", &novo->num);
	novo->prox = NULL;
	novo->ante = NULL;

	if (lista->inicio == NULL)
	{
		lista->inicio = novo;
		lista->fim = novo;
	}
	else
	{
		lista->inicio->ante = novo;
		novo->prox = lista->inicio;
		lista->inicio = novo;
	}
	return;
}

void Imprime(Lista *lista)
{
	Elemento *aux;
	aux = lista->inicio;
	printf(" \n Imprimindo lista: \n");
	while (aux != NULL)
	{
		printf(" %d \n", aux->num);
		aux = aux->prox;
	}
}

void Quant(Lista *lista)
{
	Elemento *aux;
	aux = lista->inicio;
	int cont = 0;
	while (aux != NULL)
	{
		cont++;
		aux = aux->prox;
	}
	printf("\n A quantidade de elementos na lista é: %d \n", cont);
}

void Remove(Lista *lista)
{
	Elemento *atual, *proximo, *anterior;
	int dado;

	printf("\nDigite o número que vc deseja excluir: \n");
	scanf("%d", &dado);

	if (lista->inicio == NULL)
	{
		printf("\nLISTA VAZIA!!! \n");
	}
	else
	{
		atual = lista->inicio;
		while (atual != NULL)
		{

			proximo = atual->prox;
			anterior = atual->ante;
			if (atual->num == dado) //achou!!!
				if (anterior != NULL)
					if (proximo != NULL)
					{
						anterior->prox = proximo;
						proximo->ante = anterior;
						free(atual);
						break;
					}
					else
					{
						anterior->prox = NULL;
						lista->fim = anterior;
						free(atual);
						break;
					}
				else if (proximo != NULL)
				{
					proximo->ante = NULL;
					lista->inicio = proximo;
					free(atual);
					break;
				}
				else
				{

					free(atual);
				}

			else

				atual = atual->prox;
		}
		printf("\n Elemento excluído \n\n");
	}
}

void Ordena(Lista *lista)
{
	Elemento *aux, *aux2, *i;

	for (aux = lista->inicio; aux != NULL; aux = aux->prox)
	{
		Elemento *menor = aux;
		for (aux2 = aux->prox; aux2 != NULL; aux2 = aux2->prox)
		{

			if (aux2->num < menor->num)
				menor = aux2;
		}
		int k = aux->num; //faz a troca pq sï¿½ vai sobrar 2 elementos no fim
		aux->num = menor->num;
		menor->num = k;
	}
	printf("\nLista ordenada!!!\n");
	return;
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	Lista L2;
	int op;
	do
	{

		printf("Bem vindoooooooo <3 :) !!! \n\n");
		printf("Escolha a opção que você deseja: \n\n");
		printf("1- Inicializar lista\n\n");
		printf("2- Inserir elementos na lista\n\n");
		printf("3- Mostrar a quantidade de elementos que a lista possui\n\n");
		printf("4- Imprimir lista\n\n");
		printf("5- Remover um elemento \n\n");
		printf("6- Ordenar lista\n\n");
		printf("Digite 0 para sair\n\n");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			Inicializa(&L2);
			break;
		case 2:
			Insere(&L2);
			Insere(&L2);
			Insere(&L2);
			Insere(&L2);
			Insere(&L2);
			Insere(&L2);
			Insere(&L2);
			break;
		case 3:
			Quant(&L2);
			break;
		case 4:
			Imprime(&L2);
			break;
		case 5:
			Remove(&L2);
			break;
		case 6:
			Ordena(&L2);
			break;
		}

		system("PAUSE");
		system("cls");

	} while (op != 0);
}
