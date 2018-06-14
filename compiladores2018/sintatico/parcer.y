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


%type <inteiro> Expr Result
//%type <valor> Bin_Ope Una_Ope Programa Var_decl Def_decl Lista_parametros Bloco Stmt Assign Funcao Argumentos
%start Program
%%
Program	: 
	{fprintf(yyout,"[ ");} Expr {fprintf(yyout,"] ");}
	;

Expr : 
	Expr MAIS Result {fprintf(yyout,"+ [%d] [%d]",$1,$3);}
	| Result {$$ =$1;}
	;
Result	 : NUM {$$ =$1;}
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




