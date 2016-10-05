#ifndef PAGINA_H_
#define PAGINA_H_

// LISTA DE PAGINAS
typedef struct listaPaginas ListaPaginas;

/* CELULA DA LISTA DE PAGINAS
 * Campos:
 * - nomePagina (char*)
 * - nomeArquivo (char*)
 * - Prox (struct listaPaginas*)
 */
typedef struct pagina Pagina;

#include "Link.h"
#include "Contribuicao.h"

/* CRIA UMA NOVA LISTA DE PAGINAS
* Inputs: Nenhum
* Outputs: Lista de paginas
*/
ListaPaginas* InicializaListaPaginas();

/* INSERE A PAGINA NO INICIO DA LISTA DE PAGINAS
* Inputs: Nome da pagina, o nome do arquivo da pagina e a lista de paginas
* Outputs: Lista de paginas atualizada
*/
ListaPaginas* InserePagina(char *nomePagina, char *nomeArquivo, ListaPaginas* lista);

/* RETIRA PAGINA DA LISTA
* Inputs: Nome da pagina
* Outputs: Lista de paginas atualizada
*/
ListaPaginas* RetiraPagina(char *nomePagina, ListaPaginas *lista, ListaLinks *listaLinks, ListaContribuicoes *listaContribuicoes);

/* LIBERA O ESPACO ALOCADO PELA LISTA DE PAGINAS
* Inputs: Lista de paginas
* Outputs: Lista de paginas liberada
*/
void FimPaginas(ListaPaginas* lista);

/* VERIFICA SE A PAGINA EXISTE
* Inputs: Nome da pagina e lista de paginas
* Outputs: 0 (falso) ou 1 (verdadeiro)
*/
int CheckExistencia(char *nomePagina, ListaPaginas *listaPaginas);

/* CRIA UM ARQUIVO COM TODAS AS INFORMACOES DA PAGINA
* Inputs: Nome da pagina, lista de paginas, lista de editores, lista de contribuicoes e lista de links
* Outputs: Nenhum
*/
void ImprimePagina(char *nomePagina, ListaPaginas *listaP, ListaEditores *listaE, ListaContribuicoes *listaC, ListaLinks *listaL);

/* DADO O NOME DA PAGINA, RETORNA A ESTRUTURA
* Inputs: Lista de paginas e nome da pagina
* Outputs: Pagina
*/
Pagina *RecuperaPaginaPorNome(ListaPaginas *listaPaginas, char *nomePagina);

/* DADA A ESTRUTURA PAGINA, RETORNA O NOME
* Inputs: Pagina
* Outputs: Nome da pagina
*/
char *RecuperaNomePagina(Pagina *pagina);

/* DADA A ESTRUTURA PAGINA, RETORNA O NOME DO ARQUIVO
* Inputs: Pagina
* Outputs: Nome do arquivo da pagina
*/
char *RecuperaArquivoPagina(Pagina *pagina);

/* CRIA UM ARQUIVO COM AS INFORMACOES DE TODAS AS PAGINAS
* Inputs: Lista de paginas, lista de editores, lista de contribuicoes e lista de links
* Outputs: Nenhum
*/
void ImprimeWiked(ListaPaginas *listaP, ListaEditores *listaE, ListaContribuicoes *listaC, ListaLinks *listaL);

#endif