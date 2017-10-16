bison: main.o lex.yy.c grammar.tab.c
	cc -o $@ main.o grammar.tab.c lex.yy.c -lfl

main.o: main.c
	cc -c main.c

lex.yy.c: lexicon.l grammar.y
	bison -d grammar.y
	flex lexicon.l

clean:
	rm grammar.tab.h grammar.tab.c lex.yy.c bison grammar.tab.h
