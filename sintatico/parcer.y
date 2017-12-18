%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void yyerror(char *s);
int yylex(void);

%}

%token DEC
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
