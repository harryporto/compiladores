%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE *yyin;

void yyerror(char *s);

%}

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


int main() {
  return yyparse();
}
