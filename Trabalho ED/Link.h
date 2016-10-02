#include "Definicoes.h"

ListaLinks *InicializaListaLinks();

void InsereLink(ListaLinks *listaLinks, ListaPaginas *listaPaginas, char *deNome, char *paraNome);

void RemoverLink(ListaLinks *lista, Link *l);

void RetiraLinksPorPagina(Pagina *pagina, ListaLinks *listaLinks);

void FimLinks(ListaLinks *lista);

void CheckLink(ListaLinks *listaLinks, ListaPaginas *listaPaginas, char *nomeDe, char *nomePara);