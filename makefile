bison: bison.l bison.y
	bison -d bison.y
	flex bison.l
	cc -o $@ bison.tab.c lex.yy.c -lfl

clean:
	rm bison.tab.c lex.yy.c bison bison.tab.h
