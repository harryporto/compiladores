%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern FILE *yyout;


%}

%union
{
  char valor[100];
  int inteiro;
};


%token MAIS
%token MENOS
%token VEZES
%token DIVISAO
%token ABRE_PAREN
%token FECHA_PAREN
%token PONTO_VIRGULA
%token MAIOR
%token MAIOR_IGUAL
%token MENOR
%token MENOR_IGUAL
%token IGUAL_IGUAL
%token DIFERENTE_IGUAL
%token AND
%token OR
%token NOT
%token ABRE_CHAVE
%token FECHA_CHAVE
%token ABRE_COLCHETE
%token FECHA_COLCHETE
%token VIRGULA
%token IGUAL
%token ID
%token DEC
%token BREAK
%token CONTINUE
%token IF
%token WHILE
%token RETURN
%token DEF
%token ELSE
%token LET

%left  "||"
%left  "&&"
%right "==" "!="
%left  '<'  "<="  ">="  '>'
%left  '+'  '-'
%left  '*'  '/'
%left UNA


%%

Expr 	: Expr BinOp Expr ';' 
	| 
	;
BinOp 	: '+' 
	| '-' 
	| '*' 
	| '/' 
	| '<' 
	| "<=" 
	| '>' 
	| ">=" 
	| "==" 
	| "!=" 
	| "&&" 
	| "||"
	;

%%

int main(int argc, char** argv){

	yyin = fopen(argv[1], "r");
	yyout = fopen(argv[2], "w");

	if(!yyin) printf("Arquivo nao pode ser aberto!\n");
	else{
		yyparse();
		fprintf(yyout,"]\n");
	}
	fclose(yyin);
	fclose(yyout);
	return 0;
}

