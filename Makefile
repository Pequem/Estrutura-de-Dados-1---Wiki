#
# Makefile
#
# EDI
# TRABALHO I
#

all: wiked

wiked: testador.o Pagina.o Editor.o Contribuicao.o Link.o Log.o
	gcc -ggdb -std=c99 -Wall -Werror -Wformat=0 -o wiked testador.o Pagina.o Editor.o Contribuicao.o Link.o Log.o

testador.o: testador.c
	gcc -ggdb -std=c99 -Wall -Werror -Wformat=0 -c testador.c

Pagina.o: Pagina.c
	gcc -ggdb -std=c99 -Wall -Werror -Wformat=0 -c Pagina.c

Editor.o: Editor.c
	gcc -ggdb -std=c99 -Wall -Werror -Wformat=0 -c Editor.c

Link.o: Link.c
	gcc -ggdb -std=c99 -Wall -Werror -Wformat=0 -c Link.c

Log.o: Log.c
	gcc -ggdb -std=c99 -Wall -Werror -Wformat=0 -c Log.c

clean:
	rm -rf *.o

run: wiked
	./wiked entrada.txt