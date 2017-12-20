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

%type<inteiro> DEC
%type<valor> ID

%%

/*Expr 	: Expr BinOp Expr ';' 
	| 
	;*/
BinOp 	: DEC MAIS DEC  BinOp{fprintf(yyout,"%d + %d", $1,$3);}
	| DEC MENOS DEC BinOp	{fprintf(yyout,"%d - %d", $1,$3);}
	| DEC VEZES DEC	BinOp {fprintf(yyout,"%d * %d", $1,$3);}
	| DEC DIVISAO DEC BinOp	{fprintf(yyout,"%d / %d", $1,$3);}
	| DEC MENOR DEC	{fprintf(yyout,"%d < %d", $1,$3);}
	| DEC MENOR_IGUAL DEC 	{fprintf(yyout,"%d <= %d", $1,$3);}
	| DEC MAIOR DEC	{fprintf(yyout,"%d > %d", $1,$3);}
	| DEC MAIOR_IGUAL DEC 	{fprintf(yyout,"%d >= %d", $1,$3);}
	| DEC IGUAL_IGUAL DEC 	{fprintf(yyout,"%d == %d", $1,$3);}
	| DEC DIFERENTE_IGUAL DEC 	{fprintf(yyout,"%d != %d", $1,$3);}
	| DEC AND DEC	{fprintf(yyout,"%d && %d", $1,$3);}
	| DEC OR DEC	{fprintf(yyout,"%d || %d", $1,$3);}
	| 
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




