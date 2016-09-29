#include "Contribuicao.h"
#include "Editor.h"
#include "Pagina.h"
#include <stdio.h>
#include <string>
//
struct contribuicao
{
	char *nomeContribuicao;
	Contribuicao *Prox;
	int excluida;
	Pagina *pagina;
	Editor *editor;
};

struct listaContribuicoes
{
	Contribuicao *Primeiro, *Ultimo;
};

ListaContribuicoes* InicializaListaContribuicoes()
{
	ListaContribuicoes *lista = (ListaContribuicoes*)malloc(sizeof(ListaContribuicoes));

	lista->Primeiro = lista->Ultimo = NULL;

	return lista;
}

void ImprimeContribuicoes(ListaContribuicoes* lista)
{
	printf("ImprimeContribuicoes\n");

	Contribuicao *aux = lista->Primeiro;

	if (aux == NULL)
	{
		printf("Nao ha contribuicoes");
		return;
	}

	do
	{
		printf("%s->", aux->nomeContribuicao);
		aux = aux->Prox;
	} while (aux != NULL);

	return;
}

void InsereContribuicao(char *nomePagina, char *nomeEditor, char *nomeContribuicao, ListaEditores *listaE, ListaContribuicoes *listaC, ListaPaginas *listaP)
{
	printf("InsereContribuicao\n");

	Editor *editor = recuperaEditorPorNome(nomeEditor, listaE);
	Pagina *pagina = recuperaPaginaPorNome(listaP, nomePagina);

	if (editor == NULL)
	{
		printf("ERRO: EDITOR NAO EXISTE!\n");
	}

	Contribuicao *c = (Contribuicao*) malloc(sizeof(Contribuicao));
	c->editor = editor;
	c->excluida = 0;
	c->nomeContribuicao = (char*)malloc((strlen(nomeContribuicao)+1) * sizeof(char));
	strcpy(c->nomeContribuicao, nomeContribuicao);

	c->Prox = listaC->Ultimo;
	listaC->Ultimo = c;

}
