bison: bison.l bison.y
	bison -d bison.y
	flex bison.l
	cc -o $@ bison.tab.c lex.yy.c -lfl
