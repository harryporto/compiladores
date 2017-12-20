
compilador: lex.yy.c parcer.tab.c parcer.tab.h
	gcc -o compilador parcer.tab.c lex.yy.c

lex.yy.c: lexico.lex parcer.tab.c
	flex lexico.lex

parcer.tab.c:	parcer.y
	bison -d parcer.y

clean:
	rm compilador parcer.tab.c lex.yy.c parcer.tab.h
