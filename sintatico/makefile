all:

	bison parcer.y
	gcc -c parcer.tab.c	
	lex lexico.lex 
	gcc -o compilador parcer.tab.o lex.yy.c
