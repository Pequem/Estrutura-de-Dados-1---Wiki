

/* ESTRUTURA LISTA DE PAGINAS (TIPO OPACO)
* Campos da celula da lista:
* - Prox (struct listaPaginas*)
* - nomePagina (char*)
* - nomeArquivo (char*)
*/
typedef struct pagina Pagina;


typedef struct listaPaginas ListaPaginas;

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
ListaPaginas* RetiraPagina(char *nomePagina, ListaPaginas *lista);

/* LIBERA O ESPACO ALOCADO PELA LISTA DE PAGINAS
* Inputs: Lista de paginas
* Outputs: Lista de paginas liberada
* Pre-Condicao:
* Pos-Condicao:
*/
void FimPaginas(ListaPaginas* lista);

void ImprimePaginas(ListaPaginas* lista);

Pagina* recuperaPaginaPorNome(ListaPaginas *listaPaginas, char *nome);

