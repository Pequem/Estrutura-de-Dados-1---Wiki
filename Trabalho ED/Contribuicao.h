
#include "Editor.h";
#include "Pagina.h"

typedef struct contribuicao Contribuicao;

/* ESTRUTURA LISTA DE CONTRIBUICOES (TIPO OPACO)
* Campos da celula da lista:
* - Prox (struct listaContribuicoes*)
* - nomeContribuicao (char*)
* - pagina (Pagina*) - A contribuicao foi feita a esta pagina
*/
typedef struct listaContribuicoes ListaContribuicoes;

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
void InsereContribuicao(char *nomePagina, char *nomeEditor, char *nomeContribuicao, ListaEditores *listaE, ListaContribuicoes *listaC, ListaContribuicoes *listaP);

void RetiraContribuicoesPorPagina(Pagina *pagina, ListaContribuicoes *listaC);