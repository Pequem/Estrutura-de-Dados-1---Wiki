#include "Definicoes.h"

/* CRIA UMA NOVA LISTA DE CONTRIBUICOES
* Inputs: Nenhum
* Outputs: Lista de contribuicoes
* Pre-Condicao:
* Pos-Condicao:
*/
ListaContribuicoes* InicializaListaContribuicoes();

/* INSERE A CONTRIBUICAO NO INICIO DA LISTA DE CONTRIBUICOES DO EDITOR
* Inputs: Nome da pagina, nome do editor, nome da contribuicao e lista de editores
* Outputs: Lista de contribuicoes do editor atualizada
* Pre-Condicao:
* Pos-Condicao:
*/
void InsereContribuicao(char *nomePagina, char *nomeEditor, char *nomeContribuicao, ListaEditores *listaE, ListaContribuicoes *listaC, ListaPaginas *listaP);

void RetiraContribuicoesPorPagina(Pagina *pagina, ListaContribuicoes *listaContribuicoes);

void FimContribuicoes(ListaContribuicoes *lista);

void RetiraContribuicao(ListaContribuicoes *listaContribuicoes,char *nomeContribuicao);