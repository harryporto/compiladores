%{
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdarg.h>
#include "tokens.h"

extern int yylex();
extern FILE *yyin;
extern FILE *yyout;


int i=0,j=0,x,y,m=0,f=0;
void arvore(noAst *eixo);
noAst *constante(int valor_constante);
noAst *ident(char id[20]);
noAst *insertAst(int tok, int nunf, ...);
noAst *raiz;
int yyerror(char *s){fprintf(yyout,"yyerror : %s\n",s);}

%}

%union
{
  char valor[100];
  int inteiro;
  noAst *ast;
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

%left  ELSE
%left  MAIS  MENOS
%left  MAIOR MENOR MAIOR_IGUAL MENOR_IGUAL DIFERENTE IGULA_IGUAL
%left  VEZES  DIV
 
%start Program
%%
Program	:
	Decl_list 
	;
Decl_list : Decl_list Decl
	| Decl
	;
Decl : Var_decl
	| Fun_decl
	;
Var_decl : Type_esp ID PVIRG
	| Type_esp ID ABRE_COL NUM FECHA_COL PVIRG
	;
Type_esp : INT
	| VOID
	;
Fun_decl : Type_esp ID ABRE_PAR Params FECHA_PAR Comp
	;
Params : Param_list
	| VOID
	;
Param_list : Param_list VIRG Param
	| Param
	;
Param : Type_esp ID
	| Type_esp ID ABRE_COL FECHA_COL
	;
Comp : ABRE_CHA Local_decl Stat_list FECHA_CHA
	;
Local_decl : Local_decl Var_decl
	|
	;
Stat_list : Stat_list Statement 
	| 
	;
Statement : Expr_stmt
	| Comp
	| Selection
	| Iteration
 	| Return
	;
Expr_stmt : Expr PVIRG
	| PVIRG
	;
Selection : IF ABRE_PAR Expr FECHA_PAR Statement
	| IF ABRE_PAR Expr FECHA_PAR Statement ELSE Statement
	;
Iteration : WHILE ABRE_PAR Expr FECHA_PAR Statement
	;
Return : RETURN PVIRG
	| RETURN Expr
	;
Expr : Var IGUAL Expr 	
	| SimExpr	
	;
Var  : ID 		
	| ID ABRE_COL Expr FECHA_COL 	
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
	AddExpr AddOp Term 	
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
	| Call
	| NUM 	
	;
Call : ID ABRE_PAR Args FECHA_PAR
	;
Args : Arg_list
	|
	;
Arg_list : Arg_list PVIRG Expr
 	| Expr
	;
%%

noAst *insertAst(int tok, int numf, ...) {
   va_list ap;
    noAst *an = malloc(sizeof(noAst));
    int i;
	
	an->astn.filhos = malloc(numf * sizeof(noAst *));
	va_start(ap, numf);
    
    an->tipoNodo = Ast;
    an->astn.tokenOpr = tok;
    an->astn.n_filhos = numf;
    //fprintf(yyout, "token  %c:\n",tok);

    i = 0;
    while (i < numf) {
		an->astn.filhos[i] = va_arg(ap, noAst*);
		i++;
    }
         
    va_end(ap);
    return an;
}

noAst *constante(int valor_constante) {
    noAst *an = malloc(sizeof(noAst));

    an->tipoNodo = Tok;
    //fprintf(yyout, "token  %d:\n",valor_constante);
    an->token.val = valor_constante;

    return an;
}

void arvore (noAst *eixo){
char op[2];
  
if(eixo != NULL) {
    switch(eixo->astn.tokenOpr) {
	 fprintf(yyout," %d , ",eixo->astn.tokenOpr);
        case IGUAL:
            fprintf(yyout," [=");
            arvore(eixo->astn.filhos[0]);
            arvore(eixo->astn.filhos[1]);
          fprintf(yyout,"]x");
        break;
        case ABRE_PAR:
          fprintf(yyout," [<");
          arvore(eixo->astn.filhos[0]);
  	  arvore(eixo->astn.filhos[2]);
  	  fprintf(yyout,"]xx");
        break;
        case FECHA_PAR:
	fprintf(yyout, "token  %d / %d:\n",eixo->astn.filhos[1]->token.val,MENOS);
	switch(eixo->astn.filhos[1]->token.val){
	case MAIS : strcpy(op, "+"); break;
	case MENOS : strcpy(op, "-"); break;
	}
          fprintf(yyout," [%s",op);
          arvore(eixo->astn.filhos[0]);
  	  arvore(eixo->astn.filhos[2]);
  	  fprintf(yyout,"]xxx");
        break;
       // case ID:
       //   fprintf(yyout," [%s]", eixo->astn.filhos[0]->token.val);
      //  break;
 	case NUM:
          fprintf(yyout," [%d]", eixo->astn.filhos[0]->token.val);
        break;
        }
    }
}

int main(int argc, char** argv){

	yyin = fopen(argv[1], "r");
	yyout = fopen(argv[2], "w");
	fprintf(yyout,"[program");
	do{
		yyparse();
	}while(!feof(yyin));
	arvore(raiz);
	//fprintf(yyout,"]");
	fclose(yyin);
	fclose(yyout);
	return 0;
}


