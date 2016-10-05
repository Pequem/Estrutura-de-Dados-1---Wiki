#ifndef EDITOR_H_
#define EDITOR_H_

// LISTA DE EDITORES
typedef struct listaEditores ListaEditores;

/* CELULA DA LISTA DE EDITORES
 * Campos:
 * - nomeEditor (char*)
 * - Prox (struct listaEditores*)
 */
typedef struct editor Editor;

/* CRIA UMA NOVA LISTA DE EDITORES
* Inputs: Nenhum
* Outputs: Lista de editores
*/
ListaEditores* InicializaListaEditores();

/* INSERE O EDITOR NO INICIO DA LISTA DE EDITORES
* Inputs: Nome do editor e lista de editores
* Outputs: Lista de editores atualizada
*/
ListaEditores* InsereEditor(char *nomeEditor, ListaEditores* lista);

/* RETIRA EDITOR DA LISTA
* Inputs: Nome do editor
* Outputs: Lista de editores atualizada
*/
ListaEditores* RetiraEditor(char *nomeEditor, ListaEditores *lista);

/* LIBERA O ESPACO ALOCADO PELA LISTA DE EDITORES
* Inputs: Lista de editores
* Outputs: Lista de editores liberada
*/
void FimEditores(ListaEditores* lista);

/* RETORNA O EDITOR PEDIDO
* Inputs: Nome do editor e lista de editores
* Outputs: Editor
*/
Editor* RecuperaEditorPorNome(char *nome, ListaEditores *lista);

/* DADA A ESTRUTURA EDITOR, RETORNA O NOME
 * Inputs: Editor
 * Outputs: Nome do editor
 */
char *RecuperaNomeEditor(Editor *editor);

/* RETORNA O TAMANHO DO NOME DO EDITOR
 * Inputs: Editor
 * Outputs: Tamanho do nome do editor
 */
int RecuperaTamNomeEditor(Editor *editor);

#endif