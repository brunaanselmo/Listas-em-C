#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#define MAX 30

//LISTA SEQUENCIAL :)

struct lista
{

	int elem[MAX];
	int nElem;
};

typedef struct lista Lista;

Lista *L1;

void CriaLista();
void Insere(Lista *L1);
void Imprime(Lista *L1);
int NumElem(Lista *L1);
void RemovePos(Lista *L1);
void RemoveElem(Lista *L1);
void Ordena(Lista *L1);
//void QuickSort(Lista *L1);

void CriaLista()
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
	int i, quant;
	printf("Vc deseja inserir quantos elementos? \n ");
	scanf("%d", &quant);
	for (i = 0; i < quant; i++)
	{
		printf("Insira um elemento na lista:    ");
		scanf("%d", &L1->elem[i]);
		L1->nElem++;
	}

	return;
}

void Imprime(Lista *L1)
{
	int i;
	printf(" \n  \n \n Imprimindo Lista: \n \n");
	for (i = 0; i < MAX; i++)
	{
		if (L1->elem[i] != -1)
		{
			printf(" %d  \n", L1->elem[i]);
		}
	}
	return;
}

int NumElem(Lista *L1)
{
	if (L1 == NULL)
		return (-1);
	else
	{
		printf("Quantidade de elementos na lista : %d \n ", L1->nElem);
		return (L1->nElem);
	}
}

void RemovePos(Lista *L1)
{
	int pos, i, k;
	printf("Insira a posição que deseja excluir :  ");
	scanf("%d", &pos);
	for (i = 0; i < L1->nElem; i++)
	{
		if (i == (pos - 1))
		{
			L1->elem[i] = -1;
		}
	}
	for (k = i; k < L1->nElem - 1; k++)
	{
		L1->elem[k] = L1->elem[k + 1];
	}
	L1->nElem--;

	printf(" \nElemento removido!! \n");
	return;
}

void RemoveElem(Lista *L1)
{
	int i, k, elem;
	printf(" \n Digite o elemento que vc deseja remover:    ");
	scanf("%d", &elem);
	for (i = 0; i < L1->nElem; i++)
	{
		if (L1->elem[i] == elem)
		{
			L1->elem[i] = -1;
		}
	}
	for (k = i; k < L1->nElem - 1; k++)
	{
		L1->elem[k] = L1->elem[k + 1];
	}
	L1->nElem--;

	printf(" \nElemento removido!! \n");
	return;
}

void Remove(Lista *L1)
{
	int op;
	printf("Vc deseja remover passando alguma posição ou algum elemento da lista?? \n\n");
	printf("1- Posição \n \n");
	printf("2- Elemento \n \n");
	scanf("%d", &op);
	switch (op)
	{
	case 1:
		RemovePos(L1);
		break;
	case 2:
		RemoveElem(L1);
		break;
	}
	return;
	system("cls");
}

/*void Ordena(Lista *L1){
		
	int j, i, k, aux;

    for( j=0; j<(L1->nElem+1); j++ ){
        for( i=0; i<(L1->nElem+1); i++ ){
            if( L1->elem[i] > L1->elem[i+1] ){
                aux = L1->elem[i];
                L1->elem[i] = L1->elem[i+1];
                L1->elem[i+1]=aux;
                if( i == L1->nElem )
                	break;
            }
        }
    }
		printf(" \n Lista ordenada : \n ");
	    for(int k=0; k<L1->nElem; k++)
	    	printf("%d \n ", L1->elem[k]);
	    return;
		
	}
	
		
void QuickSort(Lista *L1){
  int i, j, meio, aux;
  int inicio=L1->elem;
  int fim=L1->nElem;

  i = inicio;
  j = fim;
  meio = L1->elem[(inicio + fim)] / 2;

  do
  {
    while ( L1->elem[i] < meio)
      i++;
      
    while ( L1->elem[j] > meio)
      j--;
      
    if (i <= j)
    {
      aux =  L1->elem[i];
       L1->elem[i] =  L1->elem[j];
       L1->elem[j] = aux;
      i++;
      j--;
    }
  } while (i <= j);
  	

  if (inicio < j){
      QuickSort(L1);
}
   
  if (i < fim){
      QuickSort(L1);
  }

	printf(" \n Lista ordenada : \n ");
	    for(int k=0; k<L1->nElem; k++)
	    	printf("%d \n ", L1->elem[k]);
	    	
}
*/

void Ordena(Lista *L1)
{
	int i, j, k, aux;
	for (i = 1; i < L1->nElem; i++)
	{
		for (j = 0; j < L1->nElem; j++)
		{
			if (L1->elem[i] < L1->elem[j])
			{
				aux = L1->elem[i];
				L1->elem[i] = L1->elem[j];
				L1->elem[j] = aux;
			}
		}
	}

	printf("Lista ordenada:\n");
	for (k = 0; k < L1->nElem; k++)
	{
		if (L1->elem[k] != -1)
			printf("  %d \n", L1->elem[k]);
	}
	return;
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int op;
	do
	{
		printf(" \n Bem vindo usuário!! \n  \nEscolha a opção que você deseja: \n");
		printf("1 - Criar lista  \n \n");
		printf("2 - Inserir elementos na lista \n \n");
		printf("3 - Mostrar o número de elementos \n \n");
		printf("4 - Remover um elemento  \n \n");
		printf("5 - Imprime lista \n \n");
		printf("6 - Ordenar lista \n \n");
		printf(" Digite 0 para sair \n \n");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			CriaLista(L1);
			break;
		case 2:
			Insere(L1);
			break;
		case 3:
			NumElem(L1);
			break;
		case 4:
			Remove(L1);
			break;
		case 5:
			Imprime(L1);
			break;
		case 6:
			Ordena(L1);
			//	QuickSort(L1);
			break;
		}
		system("pause");
		system("cls");
	} while (op != 0);
}
