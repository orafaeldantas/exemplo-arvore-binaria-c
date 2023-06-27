/*
 ============================================================================
 Name        : Arvore_Binaria.c
 Author      : Rafael Dantas
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Struct que contém os dados da árvore
struct stArvore
{
	int Valor;
	struct stArvore *SubArvoreDireita;
	struct stArvore *SubArvoreEsquerda;
};

typedef struct stArvore Arvore;

// Função que cria a árvore e retorna NULL
Arvore *CriaArvore()
{
	return NULL;
}

// Funçao que verifica se a árvore está vazia
int ArvoreEstaVazia(Arvore *x)
{
	return x == NULL;
}

// Função que mostra os dados da árvore
void MostraArvore(Arvore *x)
{

	if(!ArvoreEstaVazia(x))
	{
		printf("%d ", x->Valor);
		MostraArvore(x->SubArvoreEsquerda);
		MostraArvore(x->SubArvoreDireita);
	}

}

// Função que insere dados na árvore
void InsereDadoArvore(Arvore** x, int ValorInserido)
{
	if(*x == NULL){
		*x = (Arvore*)malloc(sizeof(Arvore));
		(*x)->SubArvoreEsquerda = NULL;   //(*(*x)).SubArvoreEsquerda
		(*x)->SubArvoreDireita = NULL;
		(*x)->Valor = ValorInserido;
	}
	else
	{
		if(ValorInserido < (*x)->Valor)
		{
			InsereDadoArvore(&(*x)->SubArvoreEsquerda, ValorInserido);
		}
		if(ValorInserido > (*x)->Valor)
		{
			InsereDadoArvore(&(*x)->SubArvoreDireita, ValorInserido);
		}
	}
}

// Função que verifica se algum valor está na árvore
int EstaNaArvore(Arvore* t, int ValorEstaNaArvore)
{
	if(ArvoreEstaVazia(t))
	{
		return 0;
	}

	return t->Valor == ValorEstaNaArvore ||
		   EstaNaArvore(t->SubArvoreEsquerda, ValorEstaNaArvore) ||
		   EstaNaArvore(t->SubArvoreDireita, ValorEstaNaArvore);
}

// Função principal
int main()
{

	int OpcaoMenu = 0, OpcaoNovaOperacao = 0;
	int ValorNaArvore = 0;

	Arvore* x = CriaArvore();

	do
	{
		printf("\n==================================\n");
		printf("    Arvore Binaria   \n\n");
		printf("   1 - Inserir Valor na Arvore   \n");
		printf("   2 - Mostrar Arvore   \n");
		printf("   3 - Verificar valor   \n");
		printf("   4 - Sair   \n");
		printf("\n==================================\n");

		printf("\n\nDigite a opcao desejada: ");
		scanf("%d", &OpcaoMenu);

		if(OpcaoMenu == 1)
		{
			printf("\nDigite um valor para inserir na arvore: ");
			scanf("%d", &ValorNaArvore);
			InsereDadoArvore(&x, ValorNaArvore);
		}
		else if (OpcaoMenu == 2)
		{
			MostraArvore(x);
		}
		else if (OpcaoMenu == 3)
		{
			printf("\nDigite um valor para verificar na arvore: ");
			scanf("%d", &ValorNaArvore);

			if(EstaNaArvore(x, ValorNaArvore))
			{
				printf("\nO elemento %d pertence a arvore!\n", ValorNaArvore);
			}
			else
			{
				printf("\nO elemento %d nao pertence a arvore!\n", ValorNaArvore);
			}
		}
		else if (OpcaoMenu == 4)
		{
			free(x);
			break;
		}

		printf("\n\nDeseja fazer uma nova operacao? (0 - Sim, 1 - Nao)");
		scanf("%d", &OpcaoNovaOperacao);

	} while (OpcaoNovaOperacao == 0);


	free(x);

	return 0;
}
