#include "Pagina.h"
#include "Link.h"
#include <stdlib.h>

struct link
{
	Pagina *de, *para;
	Link *Prox;
};

struct listaLinks
{
	Link *Primeiro, *Ultimo;
};

ListaLinks inicializaListaLinks()
{
	ListaLinks *lista = (ListaLinks*)malloc(sizeof(ListaLinks));

	lista->Primeiro = lista->Ultimo = NULL;

	return ListaLinks();
}

void inserirLink(ListaLinks * lista, Pagina *de, Pagina *para)
{
	Link *l = (Link*)malloc(sizeof(Link));

	l->de = de;
	l->para = para;

	if (lista->Primeiro == NULL)
	{
		lista->Primeiro = lista->Ultimo = l;
		return;
	}

	l->Prox = lista->Ultimo;
	lista->Ultimo = l;

	return;
}

void removerLink(ListaLinks * lista, Link * l)
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
		aux->Prox;
	} while (aux->Prox != l);

	aux->Prox = aux->Prox->Prox;
	free(l);

	return;
}
