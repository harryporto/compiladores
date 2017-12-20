all: compilador

parcer.tab.c parcer.tab.h:	parcer.y
	bison -d parcer.y

lex.yy.c: lexico.lex parcer.tab.h
	flex lexico.lex

compilador: lex.yy.c parcer.tab.c parcer.tab.h
	gcc -o compilador parcer.tab.c lex.yy.c

clean:
	rm compilador parcer.tab.c lex.yy.c parcer.tab.h