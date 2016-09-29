#include "Pagina.h"
#include "Link.h"

struct link
{
	Pagina *de, *para;
	Link *Prox;
};

struct listaLinks
{
	Link *Primeiro, *Ultimo;
};
