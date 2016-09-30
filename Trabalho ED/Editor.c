#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Definicoes.h"
#include "Editor.h"

struct editor
{
	char *nomeEditor;
	Editor *Prox;
};

struct listaEditores
{
	Editor *Primeiro;
	Editor *Ultimo;
};

ListaEditores* InicializaListaEditores()
{
	ListaEditores *lista = (ListaEditores*)malloc(sizeof(ListaEditores));

	lista->Primeiro = lista->Ultimo = NULL;

	return lista;
}

void ImprimeEditores(ListaEditores* lista)
{
	printf("ImprimeEditores\n");

	Editor *aux = lista->Primeiro;

	if (aux == NULL)
	{
		printf("Nao ha editores");
		return;
	}

	do
	{
		printf("%s->", aux->nomeEditor);
		aux = aux->Prox;
	} while (aux != NULL);

	return;
}

ListaEditores* InsereEditor(char *nomeEditor, ListaEditores *lista)
{
	printf("InsereEditor\n");

	Editor *novoEditor = (Editor*)malloc(sizeof(Editor));
	novoEditor->Prox = NULL;

	novoEditor->nomeEditor = (char*)malloc(sizeof(char)*(strlen(nomeEditor) + 1));
	strcpy(novoEditor->nomeEditor, nomeEditor);

	//SE A LISTA ESTIVER VAZIA
	if (lista->Primeiro == NULL)
		lista->Primeiro = novoEditor;

	//SE A LISTA JA TIVER ELEMENTOS
	else
	{
		novoEditor->Prox = lista->Primeiro;
		lista->Primeiro = novoEditor;
	}

	return lista;
}

ListaEditores* RetiraEditor(char *nomeEditor, ListaEditores *lista)
{
	printf("RetiraEditor\n");

	Editor *atual = lista->Primeiro;
	Editor *anterior = lista->Primeiro;

	//PROCURANDO EDITOR A SER RETIRADO
	while (atual != NULL)
	{
		if (strcmp(atual->nomeEditor, nomeEditor) == 0)
			break;

		anterior = atual;
		atual = atual->Prox;
	}

	//CASO O EDITOR NAO EXISTA
	if (atual == NULL)
		printf("ERRO: EDITOR NAO EXISTE!\n");

	//EDITOR A SER RETIRADO EH O PRIMEIRO DA LISTA
	else if (atual == lista->Primeiro)
	{
		lista->Primeiro = atual->Prox;

		//LIBERA LISTA DE CONTRIBUICOES DO EDITOR
		//FimContribuicoes_Editor(atual);
		free(atual->nomeEditor);
		free(atual);
	}

	//EDITOR A SER RETIRADO ESTA EM OUTRA POSICAO DA LISTA
	else
	{
		anterior->Prox = atual->Prox;

		free(atual->nomeEditor);
		free(atual);
	}

	return lista;
}

Editor* recuperaEditorPorNome(char *nome, ListaEditores *lista)
{
	Editor *aux;

	if (lista->Primeiro == NULL)
	{
		return NULL;
	}

	if (strcmp(lista->Primeiro->nomeEditor, nome) == 0)
	{
		return lista->Primeiro;
	}

	aux = lista->Primeiro;

	for (;;)
	{
		aux = aux->Prox;
		if (aux == NULL) {
			break;
		}
		if (strcmp(aux->nomeEditor, nome) == 0) {
			break;
		}
	}

	return aux;
}

void FimEditores(ListaEditores *lista)
{
	printf("FimEditores\n");

	Editor *aux = lista->Primeiro;

	while (aux != NULL)
	{
		Editor *aux1 = aux;

		free(aux1->nomeEditor);

		aux = aux->Prox;

		free(aux1);
	}

	free(lista);

	return;
}