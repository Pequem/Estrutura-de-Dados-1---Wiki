#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Definicoes.h"
#include "Pagina.h"
#include "Log.h"
#include "Contribuicao.h"
#include "Link.h"

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

Pagina* RecuperaPaginaPorNome(ListaPaginas *listaPaginas, char *nome)
{
    Pagina *pagina;

    if (listaPaginas->Primeiro == NULL)
        return NULL;

    if (strcmp(listaPaginas->Primeiro->nomePagina, nome) == 0)
        return listaPaginas->Primeiro;

    pagina = listaPaginas->Primeiro;

    do
    {
        pagina = pagina->Prox;
		if (pagina == NULL) {
			break;
		}
    }while ((strcmp(nome,pagina->nomePagina) != 0));

    return pagina;
}

int CheckExistencia(char * nomePagina, ListaPaginas * listaPaginas)
{
	Pagina *aux;
	if (listaPaginas->Primeiro == NULL) {
		return 0;
	}
	if (strcmp(listaPaginas->Primeiro->nomePagina, nomePagina) == 0) {
		return 1;
	}

	aux = listaPaginas->Primeiro;

	for(;;) {
		aux = aux->Prox;
		if (aux == NULL) {
			break;
		}
		if (strcmp(aux->nomePagina, nomePagina) == 0) {
			return 1;
		}
	}
	return 0;
}

ListaPaginas* InserePagina(char *nomePagina, char *nomeArquivo, ListaPaginas *lista)
{
	printf("InserePagina\n");

	if (CheckExistencia(nomePagina, lista)) {
		printf("Pagina ja existe\n");
		printLog("Pagina", nomePagina, "ja existe");
		return lista;
	}

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
	printLog("Pagina", nomePagina, "inserida");
	return lista;
}

ListaPaginas* RetiraPagina(char *nomePagina, ListaPaginas *lista, ListaLinks *listaLinks, ListaContribuicoes *listaContribuicoes)
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
	{
		printf("ERRO: PAGINA NAO EXISTE!\n");
		printLog("ERRO: PAGINA",nomePagina,"NAO EXISTE!");
		return lista;
	}

	//PAGINA A SER RETIRADA EH A PRIMEIRA DA LISTA
	else if (atual == lista->Primeiro)
	{
		lista->Primeiro = atual->Prox;
	}
	//PAGINA A SER RETIRADA ESTA EM OUTRA POSICAO DA LISTA
	else
	{
		anterior->Prox = atual->Prox;
	}
	RetiraContribuicoesPorPagina(atual, listaContribuicoes);
	RetiraLinksPorPagina(atual, listaLinks);
	free(atual->nomeArquivo);
	free(atual->nomePagina);
	free(atual);
	printLog("Pagina", nomePagina, "retirada");

	return lista;
}

void FimPaginas(ListaPaginas *lista)
{
	printf("FimPaginas\n");

	Pagina *aux1, *aux = lista->Primeiro;

	while (aux != NULL)
	{
		aux1 = aux;

		free(aux1->nomeArquivo);
		free(aux1->nomePagina);

		aux = aux->Prox;

		free(aux1);
	}

	free(lista);
}