#include "Pagina.h"
#include "Link.h"
#include <stdlib.h>
#include <stdio.h>

struct link
{
	Pagina *de, *para;
	Link *Prox;
};

struct listaLinks
{
	Link *Primeiro, *Ultimo;
};

ListaLinks *InicializaListaLinks()
{
	ListaLinks *lista = (ListaLinks*)malloc(sizeof(ListaLinks));

	lista->Primeiro = lista->Ultimo = NULL;

	return lista;
}

void InsereLink(ListaLinks * lista, ListaPaginas *listaPaginas, char *deNome, char *paraNome)
{
	Link *l = (Link*)malloc(sizeof(Link));

	l->de = RecuperaPaginaPorNome(listaPaginas, deNome);;
	l->para = RecuperaPaginaPorNome(listaPaginas, paraNome);
	l->Prox = NULL;

	if (l->de == NULL || l->para == NULL) {
		printf("ERRO: PAGINA NAO EXISTE (INSERELINK)\n");
		return;
	}

	if (lista->Primeiro == NULL)
	{
		lista->Primeiro = lista->Ultimo = l;
		return;
	}

	lista->Ultimo->Prox = l;
	lista->Ultimo = l;

	return;
}

void RemoverLink(ListaLinks * lista, Link * l)
{
	Link *aux;

	if (lista->Primeiro == l)
	{
		lista->Primeiro = l->Prox;
		free(l);
		return;
	}

	aux = lista->Primeiro;

	do
	{
		aux = aux->Prox;
	} while (aux->Prox != l || aux->Prox == NULL);
	if (aux->Prox != NULL) {
		aux->Prox = aux->Prox->Prox;
		free(l);
	}

	return;
}

void RetiraLinksPorPagina(Pagina * pagina, ListaLinks *listaLinks)
{
	Link *link = listaLinks->Primeiro;
	Link *prox;

	do {
		prox = link->Prox;
		if (link->de == pagina) {
			RemoverLink(listaLinks, link);
		}
		link = prox;
	} while (link == NULL);
}

void FimLinks(ListaLinks *lista) {
	Link *aux = lista->Primeiro;
	Link *aux1;

	while (aux != NULL)
	{
		aux1 = aux;
		aux = aux->Prox;

		free(aux1);
	}

	free(lista);

	return;
}

void CheckLink(ListaLinks * listaLinks, ListaPaginas * listaPaginas, char * nomeDe, char * nomePara)
{
	Link *aux = listaLinks->Primeiro;
	Pagina *de = RecuperaPaginaPorNome(listaPaginas, nomeDe);
	Pagina *para = RecuperaPaginaPorNome(listaPaginas, nomePara);

	while (aux != NULL) {
		if ((aux->de == de) && (aux->para == para)) {
			printf("CAMINHA VALIDO\n");
			return;
		};
		aux = aux->Prox;
	};
	printf("CAMINHO INVALIDO\n");
}
