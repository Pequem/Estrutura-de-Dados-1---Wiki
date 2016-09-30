
typedef struct link Link;
typedef struct listaLinks ListaLinks;

ListaLinks inicializaListaLinks();

void inserirLink(ListaLinks *lista, Pagina *de, Pagina *para);

void removerLink(ListaLinks *lista, Link *l);
