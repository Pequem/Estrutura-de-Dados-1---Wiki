#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pagina.h"
#include "Editor.h"
#include "Contribuicao.h"
#include "Log.h"

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

int CheckExistencia(char *nomePagina, ListaPaginas *listaPaginas)
{
    Pagina *aux;
    
    if (listaPaginas->Primeiro == NULL)
        return 0;
        
    if (strcmp(listaPaginas->Primeiro->nomePagina, nomePagina) == 0)
        return 1;

    aux = listaPaginas->Primeiro;

    for(;;)
    {
        aux = aux->Prox;
        
        if (aux == NULL)
            break;
        
        if (strcmp(aux->nomePagina, nomePagina) == 0)
            return 1;
    }
	
    return 0;
}

ListaPaginas* InserePagina(char *nomePagina, char *nomeArquivo, ListaPaginas *lista)
{
    if (CheckExistencia(nomePagina, lista))
    {
        printf("Pagina ja existe\n");
        printLog3("Pagina", nomePagina, "ja existe");
        
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
	
    //printLog("Pagina", nomePagina, "inserida");
    return lista;
}

ListaPaginas* RetiraPagina(char *nomePagina, ListaPaginas *lista, ListaLinks *listaLinks, ListaContribuicoes *listaContribuicoes)
{
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
        printf("ERRO: não existe a pagina %s\n",nomePagina);
        printLog2("ERRO: não existe a pagina",nomePagina);
        return lista;
    }

    //PAGINA A SER RETIRADA EH A PRIMEIRA DA LISTA
    else if (atual == lista->Primeiro)
        lista->Primeiro = atual->Prox;
	
    //PAGINA A SER RETIRADA ESTA EM OUTRA POSICAO DA LISTA
    else
        anterior->Prox = atual->Prox;
	
    RetiraContribuicoesPorPagina(atual, listaContribuicoes);
    RetiraLinksPorPagina(atual, listaLinks);
    
    free(atual->nomeArquivo);
    free(atual->nomePagina);
    free(atual);
    
    //printLog("Pagina", nomePagina, "retirada");

    return lista;
}

void ImprimePagina(char *nomePagina, ListaPaginas *listaP, ListaEditores *listaE, ListaContribuicoes *listaC, ListaLinks *listaL)
{
    printf("Imprime Pagina\n");
    
    if (CheckExistencia(nomePagina, listaP) == 0)
    {
        printf("Pagina requisitada (%s) nao existe!\n", nomePagina);
        return;
    }
    
    Pagina *pagina = RecuperaPaginaPorNome(listaP, nomePagina);
    
    FILE *file = fopen(pagina->nomeArquivo, "w");
    
    if (file)
        printf("Arquivo criado\n");
    
    fprintf(file, "%s\n\n", nomePagina);
    fprintf(file, "--> Historico de contribuicoes\n");
    
    ImprimeHistorico(listaC, nomePagina, file);
    ImprimeLinks(listaL, nomePagina, file);
    ImprimeTextos(listaC, nomePagina, file);
    
    fclose(file);
    
    return;
}

void ImprimeWiked(ListaPaginas *listaP, ListaEditores *listaE, ListaContribuicoes *listaC, ListaLinks *listaL)
{
    FILE *file = fopen("wiked.txt", "w");
    
    Pagina *pagina = listaP->Primeiro;
    
    while (pagina != NULL)
    {
        fprintf(file, "%s\n\n", pagina->nomePagina);
        fprintf(file, "--> Historico de contribuicoes\n");
        
        ImprimeHistorico(listaC, pagina->nomePagina, file);
        ImprimeLinks(listaL, pagina->nomePagina, file);
        ImprimeTextos(listaC, pagina->nomePagina, file);
        
        pagina = pagina->Prox;
    }
    
    fclose(file);
    
    return;
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
        
        if (pagina == NULL)
            break;
        
    }while ((strcmp(nome,pagina->nomePagina) != 0));

    return pagina;
}

char* RecuperaNomePagina(Pagina *pagina)
{
    return (pagina->nomePagina);
}

char* RecuperaArquivoPagina(Pagina *pagina)
{
    return (pagina->nomeArquivo);
}

void FimPaginas(ListaPaginas *lista)
{
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