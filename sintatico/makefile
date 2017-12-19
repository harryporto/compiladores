all:

	bison parcer.y
	gcc -c parcer.tab.c	
	flex lexico.lex 
	gcc -o compilador parcer.tab.o lex.yy.c
