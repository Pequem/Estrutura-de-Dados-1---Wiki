#ifndef LINK_H_
#define LINK_H_

/* CELULA DA LISTA DE LINKS
 * Campos:
 * - de (struct listaPagina*)
 * - para (struct listaPaginas*)
 * - Prox (struct listaLinks*)
 */
typedef struct link Link;

// LISTA DE LINKS
typedef struct listaLinks ListaLinks;

#include "Pagina.h"
#include "Link.h"

/* INICIALIZA A LISTA DE LINKS
 * Inputs: Nenhum
 * Outputs: Lista inicializada e vazia
 */
ListaLinks *InicializaListaLinks();

/* INSERE LINK NA LISTA
 * Inputs: Lista de links, lista de paginas e nome das paginas
 * Outputs: Nenhum
 */
void InsereLink(ListaLinks *listaLinks, ListaPaginas *listaPaginas, char *deNome, char *paraNome);

/* REMOVE LINK DA LISTA
 * Inputs: Lista de links e link a ser retirado
 * Outputs: Nenhum
 */
void RemoverLink(ListaLinks *lista, Link *l);

/* RETIRA LINK DA PAGINA
 * Inputs: Pagina e lista de links
 * Outputs: Nenhum
 */
void RetiraLinksPorPagina(Pagina *pagina, ListaLinks *listaLinks);

/* LIBERA ESPACO ALOCADO PELA LISTA DE LINKS
 * Inputs: Lista de links
 * Outputs: Nenhum
 */
void FimLinks(ListaLinks *lista);

/* VERIFICA SE EXISTE LINK ENTRE DUAS PAGINAS
 * Inputs: Lista de links, lista de paginas, nome das paginas
 * Outputs: Nenhum
 */
void CheckLink(ListaLinks *listaLinks, ListaPaginas *listaPaginas, char *nomeDe, char *nomePara);

/* IMPRIME OS LINKS PARA CERTA PAGINA EM UM ARQUIVO
 * Inputs: Lista de links, nome da pagina e arquivo
 * Outputs: Nenhum
 */
void ImprimeLinks(ListaLinks *listaLinks, char *nomePagina, FILE *file);

#endif