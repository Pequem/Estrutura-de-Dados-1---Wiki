#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Pagina.h"
#include "Editor.h"
#include "Contribuicao.h"
#include "Link.h"
#include "Log.h"

struct link
{
    Pagina *de;
    Pagina *para;
    Link *Prox;
};

struct listaLinks
{
    Link *Primeiro;
    Link *Ultimo;
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

    if (l->de == NULL)
    {
        printLog3("ERRO: A PAGINA",deNome,"NAO EXISTE");
        return;
    }
    
    if(l->para == NULL){
        printLog3("ERRO: A PAGINA",paraNome,"NAO EXISTE");
        return;
    }
    
    if (l->de == l->para){
        printLog2("ERRO","UMA PAGINA NAO PODE APONTAR PARA ELA MESMA");
        return;
    }
    
    if(lista->Primeiro != NULL){
        Link *aux;
        
        aux = lista->Primeiro;
        
        if(aux->de == l->de){
            if(aux->para == l->para){
                printLog4("ERRO: JA EXISTE O LINK DE",deNome,"PARA",paraNome);
                return;
            }
        }
        for(;;){
                if(aux == NULL) break;
                if(aux->de == l->de){
                    if(aux->para == l->para){
                        printLog4("ERRO: JA EXISTE O LINK DE",deNome,"PARA",paraNome);
                        return;
                    }
                }
                aux = aux->Prox;
            }
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

    for(;;)
    {
        if(aux->Prox == NULL) break;
        if(aux->Prox == l) break;
        aux = aux->Prox;
    }
	
    if (aux->Prox != NULL)
    {
        aux->Prox = aux->Prox->Prox;
        free(l);
    }

    return;
}

void RetiraLink(ListaLinks *listaLinks,ListaPaginas *listaPaginas, char *deNome, char *paraNome){
    Link *aux;
    Pagina *de = RecuperaPaginaPorNome(listaPaginas, deNome);
    Pagina *para = RecuperaPaginaPorNome(listaPaginas, paraNome);

    if (de == NULL)
    {
        printLog3("ERRO: A PAGINA",deNome,"NAO EXISTE");
        return;
    }
    
    if(para == NULL){
        printLog3("ERRO: A PAGINA",paraNome,"NAO EXISTE");
        return;
    }
    
    aux = listaLinks->Primeiro;

    if((aux->de == de) && (aux->para == para)){
        RemoverLink(listaLinks, aux);
        return;
    }
    
    do
    {
        if(aux->Prox == NULL) break;
        if((aux->de == de) && (aux->para == para)) break;
        aux = aux->Prox;
    } while (1);
	
    if (aux->Prox != NULL)
    {
        RemoverLink(listaLinks, aux);
    }
    else
    {
        printLog4("ERRO: NAO EXISTE LINK DE",deNome,"PARA",paraNome);
    }

    return;
}

void ImprimeLinks(ListaLinks *listaLinks, char *nomePagina, FILE *file)
{
    Link *link = listaLinks->Primeiro;
    
    fprintf(file, "--> Links\n");
    
    while (link != NULL)
    {
        if (strcmp(RecuperaNomePagina(link->de), nomePagina) == 0)
            fprintf(file, "%s %s\n", RecuperaNomePagina(link->para), RecuperaArquivoPagina(link->para));
        
        link = link->Prox;
    }
    
    fprintf(file, "\n");
    
    return;
}

void CheckLink(ListaLinks * listaLinks, ListaPaginas * listaPaginas, char * nomeDe, char * nomePara)
{
    Link *aux = listaLinks->Primeiro;
    Pagina *de = RecuperaPaginaPorNome(listaPaginas, nomeDe);
    Pagina *para = RecuperaPaginaPorNome(listaPaginas, nomePara);

    if (de == NULL)
    {
        printLog3("ERRO: A PAGINA",nomeDe,"NAO EXISTE");
        return;
    }
    
    if(para == NULL){
        printLog3("ERRO: A PAGINA",nomePara,"NAO EXISTE");
        return;
    }
    
    while (aux != NULL)
    {
        if ((aux->de == de) && (aux->para == para))
        {
            printLog4("HA CAMINHO DA PAGINA ",nomeDe," PARA ",nomePara);
            return;
        }
		
        aux = aux->Prox;
    }
    
    printLog4("NAO HA CAMINHO DA PAGINA",nomeDe,"PARA",nomePara);
    
    return;
}

void RetiraLinksPorPagina(Pagina * pagina, ListaLinks *listaLinks)
{
    Link *link = listaLinks->Primeiro;
    Link *prox;

    do
    {
        prox = link->Prox;
        
        if ((link->de == pagina) || (link->para == pagina))
            RemoverLink(listaLinks, link);
        
        link = prox;
    } while (link == NULL);
}

void FimLinks(ListaLinks *lista)
{
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