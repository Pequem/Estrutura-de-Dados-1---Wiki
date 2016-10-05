#
# Makefile
#
# EDI
# TRABALHO I
#

wiked: testador.c Pagina.c Editor.c Contribuicao.c Link.c Log.c
	gcc -ggdb -std=c99 -Wall -Werror -Wformat=0 -o wiked testador.c Pagina.c Editor.c Contribuicao.c Link.c Log.c