#ifndef CONTRIBUICAO_H_
#define CONTRIBUICAO_H_

#include "Editor.h"
#include "Pagina.h"

// LISTA DE CONTRIBUICOES
typedef struct listaContribuicoes ListaContribuicoes;

/* CELULA DA LISTA DE CONTRIBUICOES
 * Campos:
 * - nomeContribuicao (char*)
 * - Prox (struct listaContribuicoes*)
 * - excluida (int)
 * - pagina (struct listaPaginas*)
 * - editor (struct listaEditores*)
 */
typedef struct contribuicao Contribuicao;

/* CRIA UMA NOVA LISTA DE CONTRIBUICOES
* Inputs: Nenhum
* Outputs: Lista de contribuicoes
*/
ListaContribuicoes* InicializaListaContribuicoes();

/* INSERE A CONTRIBUICAO NO INICIO DA LISTA DE CONTRIBUICOES DO EDITOR
* Inputs: Nome da pagina, nome do editor, nome da contribuicao e lista de editores
* Outputs: Lista de contribuicoes do editor atualizada
*/
void InsereContribuicao(char *nomePagina, char *nomeEditor, char *nomeContribuicao, ListaEditores *listaE, ListaContribuicoes *listaC, ListaPaginas *listaP);

/* RETIRA CONTRIBUICAO DA LISTA
* Inputs: Lista de contribuicoes e nome da contribuicao
* Outputs: Nenhum
*/
void RetiraContribuicao(ListaContribuicoes *listaContribuicoes, ListaPaginas *listaPaginas, ListaEditores *listaEditores, char *nomePagina, char* nomeEditor, char *nomeContribuicao);

/* RETIRA TODAS AS CONTRIBUICOES DE DADA PAGINA
* Inputs: Pagina e lista de contribuicoes
* Outputs: Nenhum
*/
void RetiraContribuicoesPorPagina(Pagina *pagina, ListaContribuicoes *listaContribuicoes);

/* LIBERA ESPACO ALOCADO PELA LISTA DE CONTRIBUICOES
* Inputs: Nome da pagina, nome do editor, nome da contribuicao e lista de editores
* Outputs: Lista de contribuicoes do editor atualizada
*/
void FimContribuicoes(ListaContribuicoes *lista);

/* IMPRIME O HISTORICO DE CONTRIBUICOES PARA DADA PAGINA (EDITOR E RESPECTIVA CONTRIBUICAO)
* Inputs: Lista de contribuicoes, nome da pagina, arquivo onde sera imprimido o historico
* Outputs: Nenhum
*/
void ImprimeHistorico(ListaContribuicoes *listaContribuicoes, char *nomePagina, FILE *file);

/* IMPRIME OS TEXTOS DAS CONTRIBUICOES DE UMA PAGINA
* Inputs: Lista de contribuicoes, nome da pagina e arquivo onde serao imprimidos os textos
* Outputs: Nenhum
*/
void ImprimeTextos(ListaContribuicoes *listaContribuicoes, char *nomePagina, FILE *file);

#endif