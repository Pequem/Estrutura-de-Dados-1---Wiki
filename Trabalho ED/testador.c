#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contribuicao.h"
#include "Editor.h"
#include "Link.h"
#include "Pagina.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Modelo: %s nome_do_arquivo.txt\n", argv[0]);
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r");
	
    if (file == 0)
    {
    	printf("Arquivo nao existe!\n");
    	return 2;
    }
    
    ListaPaginas* listaPaginas = InicializaListaPaginas();
    ListaEditores* listaEditores = InicializaListaEditores();
    
    char funcao[20], nomePagina[20], nomeArquivo[20], nomeEditor[20], nomeContribuicao[20];
    
    do
    {
        fscanf(file, "%s", funcao);
        
        if (strcmp(funcao, "INSEREPAGINA") == 0)
        {
            fscanf(file, "%s %s", nomePagina, nomeArquivo);
            listaPaginas = InserePagina(nomePagina, nomeArquivo, listaPaginas);
        }
        
        if (strcmp(funcao, "RETIRAPAGINA") == 0)
        {
            fscanf(file, "%s", nomePagina);
            listaPaginas = RetiraPagina(nomePagina, listaPaginas);
        }
        
        if (strcmp(funcao, "INSEREEDITOR")== 0)
        {
            fscanf(file, "%s", nomeEditor);
            listaEditores = InsereEditor(nomeEditor, listaEditores);
        }
        
        if (strcmp(funcao, "RETIRAEDITOR")== 0)
        {
            fscanf(file, "%s", nomeEditor);
            listaEditores = RetiraEditor(nomeEditor, listaEditores);
        }
        
        if (strcmp(funcao, "INSERECONTRIBUICAO")== 0)
        {
            fscanf(file, "%s %s %s", nomePagina, nomeEditor, nomeContribuicao);
            //InsereContribuicao(nomePagina, nomeEditor, nomeContribuicao, listaEditores);
        }
    }
    while (strcmp(funcao,"FIM") != 0);
    
    ImprimePaginas(listaPaginas);
    ImprimeEditores(listaEditores);
    
    listaPaginas = FimPaginas(listaPaginas);
    //listaEditores = FimEditores(listaEditores);
    
    fclose(file);
    
    return 3;            
}