#include "Pagina.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

struct pagina
{
	char *nomePagina;
	char *nomeArquivo;
	Pagina *Prox;
};

struct listaPaginas
{
	Pagina *Primeiro;
};

ListaPaginas* InicializaListaPaginas()
{
	ListaPaginas *lista = (ListaPaginas*)malloc(sizeof(ListaPaginas));

	lista->Primeiro = NULL;

	return lista;
}

void ImprimePaginas(ListaPaginas* lista)
{
	printf("ImprimePaginas\n");

	Pagina *aux = lista->Primeiro;

	if (aux == NULL)
	{
		printf("Nao ha paginas");
		return;
	}

	do
	{
		printf("%s->", aux->nomePagina);
		aux = aux->Prox;
	} while (aux != NULL);

	return;
}

Pagina * recuperaPaginaPorNome(ListaPaginas * listaPaginas, char * nome)
{
	Pagina *aux;
	if (listaPaginas->Primeiro == NULL) {
		return NULL;
	}
	if (listaPaginas->Primeiro->nomePagina == nome) {
		return listaPaginas->Primeiro;
	}
	aux = listaPaginas->Primeiro;
	do {
		aux->Prox;
	} while (nome == aux->nomePagina || aux == NULL);
	return aux;
}

ListaPaginas* InserePagina(char *nomePagina, char *nomeArquivo, ListaPaginas *lista)
{
	printf("InserePagina\n");

	Pagina *novaPagina = (Pagina*)malloc(sizeof(Pagina));
	novaPagina->Prox = NULL;

	int tamNomePagina = strlen(nomePagina) + 1;
	int tamNomeArquivo = strlen(nomeArquivo) + 1;

	novaPagina->nomePagina = (char*)malloc(tamNomePagina * sizeof(char));
	novaPagina->nomeArquivo = (char*)malloc(tamNomeArquivo * sizeof(char));

	strcpy(novaPagina->nomePagina, nomePagina);
	strcpy(novaPagina->nomeArquivo, nomeArquivo);

	//SE A LISTA ESTIVER VAZIA
	if (lista->Primeiro == NULL)
		lista->Primeiro = novaPagina;

	//SE A LISTA JA TIVER ELEMENTOS
	else
	{
		novaPagina->Prox = lista->Primeiro;
		lista->Primeiro = novaPagina;
	}

	return lista;
}

ListaPaginas* RetiraPagina(char *nomePagina, ListaPaginas *lista)
{
	printf("RetiraPagina\n");

	Pagina *atual = lista->Primeiro;
	Pagina *anterior = lista->Primeiro;

	//PROCURANDO PAGINA A SER RETIRADA
	while (atual != NULL)
	{
		if (strcmp(atual->nomePagina, nomePagina) == 0)
			break;

		anterior = atual;
		atual = atual->Prox;
	}

	//CASO A PAGINA NAO EXISTA
	if (atual == NULL)
		printf("ERRO: PAGINA NAO EXISTE!\n");

	//PAGINA A SER RETIRADA EH A PRIMEIRA DA LISTA
	else if (atual == lista->Primeiro)
	{
		//RetiraContribuicoes_Pagina(atual); <- implementar
		lista->Primeiro = atual->Prox;

		free(atual->nomeArquivo);
		free(atual->nomePagina);
		free(atual);
	}

	//PAGINA A SER RETIRADA ESTA EM OUTRA POSICAO DA LISTA
	else
	{
		//RetiraContribuicoes_Pagina(atual); <- implementar
		anterior->Prox = atual->Prox;

		free(atual->nomeArquivo);
		free(atual->nomePagina);
		free(atual);
	}

	return lista;
}

ListaPaginas* FimPaginas(ListaPaginas *lista)
{
	printf("FimPaginas\n");

	Pagina *aux = lista->Primeiro;

	while (aux != NULL)
	{
		Pagina *aux1 = aux;

		free(aux1->nomeArquivo);
		free(aux1->nomePagina);

		aux = aux->Prox;

		free(aux1);
	}

	free(lista);

	return lista;
}