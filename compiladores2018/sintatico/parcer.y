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

// para erros
bool error = false;
bool errorMain = true;
extern int linha;	//saber qual linha deu erro

void yyerror(char* s) {
	fprintf(stderr, "Parse error: %s, linha %d\n", s,linha);
	exit(1);
}


void arvore(no_ast *eixo);
int i=0,j=0,x,y,m=0,f=0;

no_ast *token(char C_token[20]);
no_ast *inserir_ast(int tokenodo, int nfilhos, ...);
no_ast *raiz;
node *met;

%}

%union
{
  char valor[100];
  int inteiro;
  no_ast 	*ast;
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


%type <ast> Program Expr Var SimExpr  AddExpr Term MultOp Factor
%type <valor> AddOp Relop
%start Program
%%
Program	:
	Expr {arvore($1);root = $$;}
	;

Expr : Var IGUAL Expr 	{$$ = insertAst(IGUAL, 3, token($2),$1,$3);}
	| SimExpr
	;
Var  : ID 		{$$ = insertAst(ID, 1, token($1);}
	| ID ABRE_CHA Expr FECHA_CHA 	{$$ = insertAst(VAR, 2, token($1),$3;}
	;
SimExpr :
	AddExpr Relop AddExpr	{$$ = insertAst(RELOP, 3, $2,$1,$3);}
	| AddExpr
	;
Relop  : MENOR_IGUAL	{$$ = insertAst(MENOR_IGUAL, 1, $1);}
	| MENOR 			{$$ = insertAst(MENOR, 1, $1);}
	| MAIOR 			{$$ = insertAst(MAIOR, 1, $1);}
	| MAIOR_IGUAL 		{$$ = insertAst(MAIOR_IGUAL, 1, $1);}
	| IGUAL_IGUAL 		{$$ = insertAst(IGUAL_IGUAL, 1, $1);}
	| DIFERENTE 		{$$ = insertAst(DIFERENTE, 1, $1);}
	;
AddExpr :
	AddExpr AddOp Term {$$ = insertAst(ADDOP, 3, $2,$1,$3);}
	| Term
	;
AddOp  : MAIS		{$$ = insertAst(MAIS, 1, token($1));}
	| MENOS 		{$$ = insertAst(MENOS, 1, token($1));}
	;
Term  : Term MultOp Factor 	{$$ = insertAst(MULTOP, 3, $2,$1,$3);}
	| Factor
	;
MultOp  : VEZES 	{$$ = insertAst(VEZES, 1, token($1));}
	| DIV			{$$ = insertAst(DIV, 1, token($1));}
	;
Factor	 :ABRE_PAR Expr FECHA_PAR {$$ = insertAst(VAR, 2, token($1),$3);}
	| Var 	{$$ = insertAst(VAR, 1, token($1));}
	| NUM 	{$$ = insertAst(NUM, 1, token($1));}
	;

%%

no_ast *insertAst(int tok, int numf, ...) {
    va_list ap;
    no_ast *eixo = malloc(sizeof(no_ast));
    int i;

	eixo->no.percorre = malloc(numf * sizeof(no_ast *));
	va_start(ap, numf);

    eixo->tipoNodo = Ramo;
    eixo->no.tokenop = tok;
    eixo->no.qt_filho = numf;

    i = 0;
    while (i < numf) {
		eixo->no.percorre[i] = va_arg(ap, no_ast*);
		i++;
    }

    va_end(ap);
    return eixo;
}

void inicializa(node *LISTA){
	LISTA->prox = NULL;
}

bool local (char *x, node *li){
	if(li->prox==NULL){
	   return false;
	}
	else{
	   node *p;
	   p = li->prox;
	   while (p != NULL && strcmp(p->str,x))
	     p = p->prox;
	     if (p==NULL){
		return false;
	     }
	     else{
		return true;}
   	}
}

void inserir(char *x, node *LISTA)
{
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		exit(1);
	}
	if (!local(x,LISTA)){
		strcpy(novo->str,x);
		node *oldHead = LISTA->prox;
		LISTA->prox = novo;
		novo->prox = oldHead;
	}
}

void exibir(node *LISTA)
{
	if(LISTA->prox==NULL){
		return ;
	}
	node *tmp;
	tmp = LISTA->prox;
	while( tmp != NULL){
		tmp = tmp->prox;
	}
}

void libera(node *LISTA)
{
	if(LISTA->prox!=NULL){
		node *proxNode,*atual;
		atual = LISTA->prox;
		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
		inicializa(LISTA);
	}
}

no_ast *token(char tok[20]) {
    no_ast *no = malloc(sizeof(no_ast));
     no->tipoNodo = TokenChar;
     strcpy(no->folha.str_tokken, tok);
    return no;
}

int main(int argc, char** argv){

	node *met = (node *) malloc(sizeof(node));
 	if(!met){
		exit(1);
	}
	inicializa(met);
	inserir("print",met);
	yyin = fopen(argv[1], "r");
	yyout = fopen(argv[2], "w");
	do{
		yyparse();
	}while(!feof(yyin));
	exibir(met);
		fprintf(yyout,"]");
	if (error||errorMain) {
		fclose(yyout);
		yyout = fopen(argv[2], "w");
	}
	fclose(yyin);
	fclose(yyout);
	return 0;
}


