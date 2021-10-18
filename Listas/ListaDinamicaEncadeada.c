#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#define MAX 30

//LISTA DINÂMICA ENCADEADA  *.*

typedef struct no Elemento;

struct no
{
	int num;
	struct no *prox; //ponteiro prox tem que ser do mesmo tipo do elemento
};

typedef struct lista Lista;

struct lista
{
	Elemento *inicio;
	Elemento *fim;
};

void Inicializa(Lista *lista);
int Insere(Lista *lista);
void Imprime(Lista *lista);
void Quant(Lista *lista);
void Remove(Lista *lista);

void Inicializa(Lista *lista)
{ //do tipo No* porque o vai retornar um ponteiro
	lista->inicio = NULL;
	lista->fim = NULL;
	printf("\nLista inicializada com sucesso!!!! \n");
}

int Insere(Lista *lista)
{
	Elemento *novo;
	novo = (Elemento *)malloc(sizeof(Elemento));
	printf("\n\nInsira o número que vc deseja:");
	scanf("%d", novo->num);
	novo->prox = NULL;

	if (lista->inicio == NULL)
	{
		lista->inicio = novo;
		lista->fim = novo;
	}
	else
	{

		lista->fim->prox = novo; //encadeamento da lista
		lista->fim = novo;
	}
}

void Imprime(Lista *lista)
{
	Elemento *aux;
	aux = lista->inicio;
	if (aux == NULL)
	{
		printf("\n \n LISTA VAZIA!!!!");
	}
	else
	{

		printf("Imprimindo lista: \n");
		while (aux != NULL)
		{
			printf("\n %d \n", aux->num);
			aux = aux->prox;
		}
		return;
	}
}

void Quant(Lista *lista)
{
	Elemento *aux = lista->inicio;
	int cont = 0;
	while (aux != NULL)
	{
		cont++;
		aux = aux->prox;
	}
	printf("\n A quantidade de elementos na lista é: %d \n \n", cont);
	return;
}

void Remove(Lista *lista)
{
	int valor;
	Elemento *anterior, *atual;
	printf("\nInforme o elemento a ser excluído:  ");
	scanf("%d", &valor);
	if (lista->inicio == NULL)
	{
		printf("\nLISTA VAZIA!!!");
	}
	else
	{

		anterior = lista->inicio;
		atual = lista->inicio;
		while (atual != NULL)
		{
			if (atual->num == valor) //encontrei o elemento
			{
				if (atual == lista->inicio)
				{
					lista->inicio = lista->inicio->prox;
					free(atual);
					break;
				}
				else
				{
					if (atual == lista->fim)
					{
						lista->fim = anterior;
					}

					//refazendo encadeamento
					anterior->prox = atual->prox;
					free(atual);
					break;
				}
			}
			else
			{
				anterior = atual;
				atual = atual->prox;
			}
		}
	}
	return;
}

int main()
{

	setlocale(LC_ALL, "Portuguese");
	int op;
	Lista L1;

	do
	{

		printf("Bem vindoooo!!!!!!!! \n \n");
		printf("Escolha a opção que você deseja:\n \n");
		printf("1- Inicializar lista \n \n");
		printf("2- Inserir elementos\n \n");
		printf("3- Mostrar a quantidade de elementos que a lista possui \n \n");
		printf("4- Imprimir a lista \n \n");
		printf("5- Remover algum elemento \n \n");
		printf("6- Ordenar lista \n \n");
		printf("Digite 0 para sair\n");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			Inicializa(&L1);
			break;
		case 2:
			Insere(&L1);
			break;
		case 3:
			Quant(&L1);
			break;
		case 4:
			Imprime(&L1);
			break;
		case 5:
			Remove(&L1);
			break;
			//	case 6:
			//		Ordena();
			//		break;
		}
		system("PAUSE");
		system("cls");

	} while (op != 0);
}
