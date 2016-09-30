#include "Definicoes.h"

ListaLinks *inicializaListaLinks();

void inserirLink(ListaLinks *lista, Pagina *de, Pagina *para);

void removerLink(ListaLinks *lista, Link *l);

void RetiraLinksPorPagina(Pagina *pagina, ListaLinks *listaLinks);