all:  lexico.lex parcer.y
	bison -d parcer.y
	flex -l lexico.lex
	gcc lex.yy.c parcer.tab.c -o compilador
