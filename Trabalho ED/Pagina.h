#ifndef PAGINA_H_
#define PAGINA_H_

#include "Definicoes.h"

/* CRIA UMA NOVA LISTA DE PAGINAS
* Inputs: Nenhum
* Outputs: Lista de paginas
* Pre-Condicao:
* Pos-Condicao:
*/
ListaPaginas* InicializaListaPaginas();

/* INSERE A PAGINA NO INICIO DA LISTA DE PAGINAS
* Inputs: Nome da pagina, o nome do arquivo da pagina e a lista de paginas
* Outputs: Lista de paginas atualizada
* Pre-Condicao:
* Pos-Condicao:
*/
ListaPaginas* InserePagina(char *nomePagina, char *nomeArquivo, ListaPaginas* lista);

/* RETIRA PAGINA DA LISTA
* Inputs: Nome da pagina
* Outputs: Lista de paginas atualizada
* Pre-Condicao:
* Pos-Condicao:
*/
ListaPaginas* RetiraPagina(char *nomePagina, ListaPaginas *lista, ListaLinks *listaLinks, ListaContribuicoes *listaContribuicoes);

/* LIBERA O ESPACO ALOCADO PELA LISTA DE PAGINAS
* Inputs: Lista de paginas
* Outputs: Lista de paginas liberada
* Pre-Condicao:
* Pos-Condicao:
*/
void FimPaginas(ListaPaginas* lista);

Pagina* RecuperaPaginaPorNome(ListaPaginas *listaPaginas, char *nome);

int CheckExistencia(char *nomePagina, ListaPaginas *listaPaginas);

void ImprimePagina(ListaPaginas *listaPaginas, ListaContribuicoes *listaContribuicoes, ListaLinks *listaLinks, ListaEditores *listaEditores, char *nomePagina);

#endif /*PAGINA_H_*/