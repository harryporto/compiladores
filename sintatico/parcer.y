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
%token <valor> ID
%token <inteiro> DEC
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


%type <inteiro> Expr
%type <valor> Bin_Ope Una_Ope Programa Var_decl Def_decl Lista_parametros Bloco Stmt Assign Funcao Argumentos
%%

Start: Programa			{fprintf(yyout, "[ " );}

Programa : Var_decl Programa 
      | Def_decl Programa 
      | 
      ;

Var_decl : LET ID PONTO_VIRGULA
	| LET ID IGUAL Expr PONTO_VIRGULA
	;

Def_decl : DEF ID ABRE_PAREN FECHA_PAREN Bloco
	| DEF ID ABRE_PAREN Lista_parametros FECHA_PAREN Bloco
	;

Lista_parametros : ID VIRGULA ID 		//aqui esta errado
	|ID
	;	

Bloco : ABRE_CHAVE Var_decl Stmt FECHA_CHAVE
	;

Stmt : Assign PONTO_VIRGULA
	| Funcao PONTO_VIRGULA
	| IF  ABRE_PAREN Expr FECHA_PAREN Bloco
	| WHILE ABRE_PAREN Expr FECHA_PAREN Bloco
	| RETURN Expr PONTO_VIRGULA
	| BREAK PONTO_VIRGULA
	| CONTINUE PONTO_VIRGULA

Assign : ID IGUAL Expr

Funcao : ID ABRE_PAREN Argumentos FECHA_PAREN	

Argumentos : Expr
	| Expr , Argumentos

Expr     : Expr MAIS Expr 			{fprintf(yyout,"+ [%d] [%d]",$1,$3);}
	| Expr MENOS Expr 				{fprintf(yyout,"- [%d] [%d]",$1,$3);}
	| Expr VEZES Expr 				{fprintf(yyout,"* [%d] [%d]",$1,$3);}
	| Expr DIVISAO Expr 			{fprintf(yyout,"/ [%d] [%d]",$1,$3);}
	| Expr MENOR Expr 				{fprintf(yyout,"< [%d] [%d]",$1,$3);}
	| Expr MENOR_IGUAL Expr 		{fprintf(yyout,"<= [%d] [%d]",$1,$3);}
	| Expr MAIOR Expr 				{fprintf(yyout,"> [%d] [%d]",$1,$3);}
	| Expr MAIOR_IGUAL Expr 		{fprintf(yyout,">= [%d] [%d]",$1,$3);}
	| Expr IGUAL_IGUAL Expr 		{fprintf(yyout,"== [%d] [%d]",$1,$3);}
	| Expr DIFERENTE_IGUAL Expr 	{fprintf(yyout,"!= [%d] [%d]",$1,$3);}
	| Expr AND Expr 				{fprintf(yyout,"&& [%d] [%d]",$1,$3);}
	| Expr OR Expr 					{fprintf(yyout,"|| [%d] [%d]",$1,$3);}
	| MENOS Expr 					{fprintf(yyout,"- [%d]",$2);}
	| NOT Expr 						{fprintf(yyout,"! [%d]",$2);}
	| ABRE_PAREN Expr FECHA_PAREN 	{fprintf(yyout,"%d", $2);}
	| DEC
	| ID
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




