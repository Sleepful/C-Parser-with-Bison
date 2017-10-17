bison: main.o lex.yy.c grammar.tab.c macros.yy.c
	cc -o $@ main.o grammar.tab.c lex.yy.c -lfl

main.o: main.c
	cc -c main.c

lex.yy.c: lexicon.l grammar.y
	bison -d grammar.y
	flex lexicon.l

macros.yy.c: macros.l
	flex macros.l

clean:
	rm grammar.tab.c lex.yy.c bison grammar.tab.h
