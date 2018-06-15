%{
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

extern int yylex();
extern FILE *yyin;
extern FILE *yyout;


void yyerror(char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}

%}

%union
{
  char valor[100];
  int inteiro;
};


%token MAIS
%token MENOS
%token VEZES
%token DIV
%token ABRE_PAR
%token FECHA_PAR
%token PONTO_VIRGULA
%token MAIOR
%token MAIOR_IGUAL
%token MENOR
%token MENOR_IGUAL
%token IGUAL_IGUAL
%token DIFERENTE
%token ABRE_CHA
%token FECHA_CHA
%token ABRE_COL
%token FECHA_COL
%token VIRG
%token PVIRG
%token IGUAL
%token <valor> ID
%token <inteiro> NUM
%token IF
%token INT
%token WHILE
%token RETURN
%token ELSE
%token VOID

%left  "||"
%left  "&&"
%right "==" "!="
%left  '<'  "<="  ">="  '>'
%left  MAIS  MENOS
%left  '*'  '/'
%left UNA


%type <inteiro> Expr Factor SimExpr
%type <valor> Var  Relop AddOp
%start Program
%%
Program	: 
	{fprintf(yyout,"[ ");} Expr {fprintf(yyout,"] ");}
	;

Expr : Var IGUAL Expr 	{fprintf(yyout,"= [1] [1]");}
	| SimExpr
	;
Var  : ID
	| ID ABRE_CHA Expr FECHA_CHA
	;
SimExpr : 
	AddExpr Relop AddExpr 
	| AddExpr
	;
Relop  : MENOR_IGUAL
	| MENOR
	| MAIOR
	| MAIOR_IGUAL
	| IGUAL_IGUAL
	| DIFERENTE
	;
AddExpr : 
	AddExpr AddOp Term {fprintf(yyout,"%s [1] [1]",$2);}
	| Term 
	;
AddOp  : MAIS 	
	| MENOS 
	;
Term  : Term MultOp Factor
	| Factor
	;
MultOp  : VEZES
	| DIV
	;
Factor	 :ABRE_PAR Expr FECHA_PAR
	| Var 
	| NUM 
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




