.SUFFIXES:

all: bison

bison: main parser
	cc -o $@ main.o bison.tab.c lex.yy.c -lfl

main: main.c
	cc -c main.c

parser: bison.l bison.y
	bison -d bison.y
	flex bison.l

clean:
	rm bison.tab.c lex.yy.c bison bison.tab.h
