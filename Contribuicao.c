#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Pagina.h"
#include "Editor.h"
#include "Contribuicao.h"

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
    Contribuicao *Primeiro;
    Contribuicao *Ultimo;
};

ListaContribuicoes* InicializaListaContribuicoes()
{
    ListaContribuicoes *lista = (ListaContribuicoes*)malloc(sizeof(ListaContribuicoes));
    lista->Primeiro = lista->Ultimo = NULL;

    return lista;
}

void InsereContribuicao(char *nomePagina, char *nomeEditor, char *nomeContribuicao, ListaEditores *listaE, ListaContribuicoes *listaC, ListaPaginas *listaP)
{
    Editor *editor = RecuperaEditorPorNome(nomeEditor, listaE);
    Pagina *pagina = RecuperaPaginaPorNome(listaP, nomePagina);

    if (editor == NULL)
    {
        printf("ERRO: EDITOR NAO EXISTE!\n");
        return;
    }
    
    if (pagina == NULL)
    {
        printf("ERRO: PAGINA NAO EXISTE!\n");
        return;
    }

    Contribuicao *c = (Contribuicao*)malloc(sizeof(Contribuicao));

    c->editor = editor;
    c->excluida = 0;

    c->nomeContribuicao = (char*)malloc(sizeof(char)*(strlen(nomeContribuicao) + 1));
    strcpy(c->nomeContribuicao, nomeContribuicao);

    c->Prox = NULL;
    c->pagina = pagina;

    if (listaC->Primeiro == NULL) 
    {
        listaC->Primeiro = listaC->Ultimo = c;
        return;
    }

    listaC->Ultimo->Prox = c;
    listaC->Ultimo = c;

    return;
}

void RetiraContribuicao(ListaContribuicoes *listaContribuicoes,char *nomeContribuicao)
{
    Contribuicao *aux;

    aux = listaContribuicoes->Primeiro;

    while (aux != NULL)
    {
        if (strcmp(aux->nomeContribuicao,nomeContribuicao) == 0)
            aux->excluida = 1;
            
        aux = aux->Prox;
    }

    return;
}

void ImprimeTextos(ListaContribuicoes *listaContribuicoes, char *nomePagina, FILE *file)
{
    Contribuicao *contribuicao = listaContribuicoes->Primeiro;
    int c;
    
    fprintf(file, "--> Textos\n\n");
    
    while (contribuicao != NULL)
    {
        FILE *arquivo = fopen(contribuicao->nomeContribuicao, "r");
        
        if (arquivo)
        {
            fprintf(file, "-------- %s (%s) --------\n\n", contribuicao->nomeContribuicao, RecuperaNomeEditor(contribuicao->editor));
            
            while ((c = getc(arquivo)) != EOF)
                fprintf(file, "%c", c);
            
            fprintf(file, "\n\n");
            
            fclose(arquivo);
        }
        
        contribuicao = contribuicao->Prox;
    }
}

void ImprimeHistorico(ListaContribuicoes *listaContribuicoes, char *nomePagina, FILE *file)
{
    Contribuicao *contribuicao = listaContribuicoes->Primeiro;
    
    while (contribuicao != NULL)
    {
        if (strcmp(RecuperaNomePagina(contribuicao->pagina), nomePagina) == 0)
        {
            fprintf(file, "%s %s\n", RecuperaNomeEditor(contribuicao->editor), contribuicao->nomeContribuicao);
        }
        
        contribuicao = contribuicao->Prox;
    }
    
    fprintf(file, "\n");
    
    return;
}

void RetiraContribuicoesPorPagina(Pagina *pagina, ListaContribuicoes *listaContribuicoes)
{
    Contribuicao *aux;
	
    aux = listaContribuicoes->Primeiro;

    while (aux != NULL)
    {
        if (aux->pagina == pagina)
            aux->excluida = 1;
            
        aux = aux->Prox;
    }
    
    return;
}

void FimContribuicoes(ListaContribuicoes * lista)
{
    Contribuicao *aux;
    Contribuicao *prox;
	
    aux = lista->Primeiro;

    do
    {
        prox = aux->Prox;
		
        free(aux->nomeContribuicao);
        free(aux);
        aux = prox;
    }while (prox != NULL);

    free(lista);
}