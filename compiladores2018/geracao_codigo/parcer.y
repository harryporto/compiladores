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
//int yyerror(char *s){fprintf(yyout,"yyerror : %s\n",s);}
void yyerror(char *s){return ;}

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
%token P D LD C AR SL

%left  ID INT
%left  MAIS  MENOS
%left  ABRE_PAR  ABRE_COL ABRE_CHA PAR
%left  FECHA_PAR  FECHA_COL FECHA_CHA
%left  MAIOR MENOR MAIOR_IGUAL MENOR_IGUAL DIFERENTE IGUAL_IGUAL
%left  VEZES  DIV
%right  PVIRGs VIRG
%right VOID
%left  IF ELSE 

%type <ast> Program Decl_list Decl Var_decl  Type_esp Params Param_list Param Comp Local_decl Stat_list Statement Expr_stmt Selection Iteration Return Expr Var SimExpr  AddExpr Term  Factor Call Args Arg_list

%start Program
%%
Program	:
	Decl_list {raiz = $$;}
	;
Decl_list : Decl_list Decl 					{$$ = insertAst(D,2,$1,$2);}
	| Decl							{$$ = $1;}
	;
Decl : Var_decl							{$$ = $1;}
	| Type_esp ID ABRE_PAR Params FECHA_PAR Comp		{$$ = insertAst(ABRE_PAR,4,$1,ident($2),$4,$6);}
	;
Var_decl : Type_esp ID PVIRG  					{$$ = insertAst(PVIRG,2,$1,ident($2));}
	| Type_esp ID ABRE_COL NUM FECHA_COL PVIRG		{$$ = insertAst(ABRE_COL,3,$1,ident($2),$4);}
	;
Type_esp : INT							{$$ = insertAst(INT,0);}
	| VOID							{$$ = insertAst(VOID,0);}
	;
Params : Param_list						{$$ = $1;}
	| VOID							{$$ = insertAst(VOID,0);}
	;
Param_list : Param_list VIRG Param				{$$ = insertAst(VIRG,2,$1,$3);}
	| Param							{$$ = $1;}
	;
Param : Type_esp ID						{$$ = insertAst(P,2,$1,ident($2));}	
	| Type_esp ID ABRE_COL FECHA_COL			{$$ = insertAst(PAR,2,$1,ident($2));}
	;
Comp : ABRE_CHA Local_decl Stat_list FECHA_CHA			{$$ = insertAst(ABRE_CHA,2,$2,$3);}
	;
Local_decl : Local_decl Var_decl				{$$ = insertAst(LD,2,$1,$2);}
	|							{$$ = NULL;}
	;
Stat_list : Stat_list Statement					{$$ = insertAst(SL,2,$1,$2);} 
	| 							{$$ = NULL;}
	;
Statement : Expr_stmt						{$$ = $1;}
	| Comp							{$$ = $1;}
	| Selection						{$$ = $1;}
	| Iteration						{$$ = $1;}
 	| Return						{$$ = $1;}
	;
Expr_stmt : Expr PVIRG						{$$ = $1;}
	| PVIRG							{$$ = NULL;}
	;
Selection : IF ABRE_PAR Expr FECHA_PAR Statement		{$$ = insertAst(IF,2,$3,$5);}
	| IF ABRE_PAR Expr FECHA_PAR Statement ELSE Statement	{$$ = insertAst(ELSE,3,$3,$5,$7);}
	;
Iteration : WHILE ABRE_PAR Expr FECHA_PAR Statement		{$$ = insertAst(WHILE,1,$3);}
	;
Return : RETURN PVIRG						{$$ = insertAst(RETURN,0);}	
	| RETURN Expr						{$$ = insertAst(RETURN,1,$2);}
	;
Expr : Var IGUAL Expr 						{$$ = insertAst(IGUAL,2,$1,$3);}
	| SimExpr						{$$ = $1;}
	;
Var  : ID							{$$ = insertAst(ID,1,ident($1));} 		
	| ID ABRE_COL Expr FECHA_COL 				{$$ = insertAst(ID,2,ident($1),$3);} 
	;
SimExpr :
	AddExpr MENOR_IGUAL AddExpr				{$$ = insertAst(MENOR_IGUAL,2,$1,$3);}
	|AddExpr MENOR AddExpr					{$$ = insertAst(MENOR,2,$1,$3);}
	|AddExpr MAIOR AddExpr					{$$ = insertAst(MAIOR,2,$1,$3);}
	|AddExpr MAIOR_IGUAL AddExpr				{$$ = insertAst(MAIOR_IGUAL,2,$1,$3);}
	|AddExpr IGUAL_IGUAL AddExpr				{$$ = insertAst(IGUAL_IGUAL,2,$1,$3);}
	|AddExpr DIFERENTE AddExpr				{$$ = insertAst(DIFERENTE,2,$1,$3);}
	| AddExpr						{$$ = $1;}
	;
AddExpr :
	AddExpr MAIS Term 					{$$ = insertAst(MAIS,2,$1,$3);}
	| AddExpr MENOS Term					{$$ = insertAst(MENOS,2,$1,$3);}
	| Term							{$$ = $1;}
	;
Term  : Term VEZES Factor 					{$$ = insertAst(VEZES,2,$1,$3);}
	| Term DIV Factor					{$$ = insertAst(DIV,2,$1,$3);}
	| Factor						{$$ = $1;}
	;
Factor	 :ABRE_PAR Expr FECHA_PAR 				{$$ = $2;}
	| Var 							{$$ = $1;}
	| Call							{$$ = $1;}
	| NUM 							{$$ = insertAst(NUM,1,constante($1));}
	;
Call : ID ABRE_PAR Args FECHA_PAR				{$$ = insertAst(C,2,ident($1),$3);}
	;
Args : Arg_list							{$$ = $1;}
	|							{$$ = NULL;}
	;
Arg_list : Arg_list PVIRG Expr					{$$ = insertAst(AR,2,$1,$3);}
 	| Expr							{$$ = $1;}
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
    fprintf(yyout, "token  %d:\n",valor_constante);
    an->token.val = valor_constante;

    return an;
}

noAst *ident(char value[50]) {
    noAst *an = malloc(sizeof(noAst));

     an->tipoNodo = Ident;
     strcpy(an->constant.val, value);

    return an;
}

void arvore (noAst *eixo){
char op[2];
fprintf(yyout,"X %i : %i \n",eixo->astn.tokenOpr,eixo->astn.n_filhos);  
if(eixo != NULL) {
    switch(eixo->astn.tokenOpr) {
	 fprintf(yyout," %d , ",eixo->astn.tokenOpr);
	case D:
            arvore(eixo->astn.filhos[0]);
            arvore(eixo->astn.filhos[1]);
        break;
	case ABRE_PAR:
            fprintf(yyout," [var-declaration1");
            arvore(eixo->astn.filhos[0]);
            arvore(eixo->astn.filhos[1]);
            arvore(eixo->astn.filhos[2]);
            arvore(eixo->astn.filhos[3]);
          fprintf(yyout,"]");
        break;
	case PVIRG:
            fprintf(yyout," [var-declaration2");
            arvore(eixo->astn.filhos[0]);
            arvore(eixo->astn.filhos[1]);
          fprintf(yyout,"]");
        break;
	case ABRE_COL:
            fprintf(yyout," [var-declaration3");
            arvore(eixo->astn.filhos[0]);
            arvore(eixo->astn.filhos[1]);
            arvore(eixo->astn.filhos[2]);
          fprintf(yyout,"]");
        break;
	case VIRG:
            fprintf(yyout," funcao:");
            arvore(eixo->astn.filhos[0]);
            arvore(eixo->astn.filhos[1]);
        break; 
	case P:
            fprintf(yyout," [parametros: ");
            arvore(eixo->astn.filhos[0]);
            arvore(eixo->astn.filhos[1]);
          fprintf(yyout,"]");
        break;
	case PAR:
            fprintf(yyout," [parametros2: ");
            arvore(eixo->astn.filhos[0]);
            arvore(eixo->astn.filhos[1]);
          fprintf(yyout,"]");
        break;
	case ABRE_CHA:
            fprintf(yyout," funcao:");
            arvore(eixo->astn.filhos[0]);
            arvore(eixo->astn.filhos[1]);
        break;
	case LD:
            fprintf(yyout," declaracao local:");
            arvore(eixo->astn.filhos[0]);
            arvore(eixo->astn.filhos[1]);
        break;
	case SL:
            fprintf(yyout," lista:");
            arvore(eixo->astn.filhos[0]);
            arvore(eixo->astn.filhos[1]);
        break;
	case IF:
            fprintf(yyout," If: ");
            arvore(eixo->astn.filhos[0]);
            arvore(eixo->astn.filhos[1]);
        break;
	case ELSE:
            fprintf(yyout," else: ");
            arvore(eixo->astn.filhos[0]);
            arvore(eixo->astn.filhos[1]);
            arvore(eixo->astn.filhos[2]);
        break;
	case WHILE:
            fprintf(yyout," while: ");
            arvore(eixo->astn.filhos[0]);
        break; 
	case RETURN:
            fprintf(yyout," return: ");
	    if(eixo->astn.filhos[0]){
            	arvore(eixo->astn.filhos[0]);
	    }
        break;	        
	case IGUAL:
            fprintf(yyout," [=");
            arvore(eixo->astn.filhos[0]);
            arvore(eixo->astn.filhos[1]);
          fprintf(yyout,"]");
        break;
        case MAIS:
          fprintf(yyout," [+");
          arvore(eixo->astn.filhos[0]);
  	  arvore(eixo->astn.filhos[1]);
  	  fprintf(yyout,"]");
        break;
	case MENOS:
          fprintf(yyout," [-");
          arvore(eixo->astn.filhos[0]);
  	  arvore(eixo->astn.filhos[1]);
  	  fprintf(yyout,"]");
        break;
	case VEZES:
          fprintf(yyout," [*");
          arvore(eixo->astn.filhos[0]);
  	  arvore(eixo->astn.filhos[1]);
  	  fprintf(yyout,"]");
        break;
	case DIV:
          fprintf(yyout," [/");
          arvore(eixo->astn.filhos[0]);
  	  arvore(eixo->astn.filhos[1]);
  	  fprintf(yyout,"]");
        break;
	case MAIOR:
          fprintf(yyout," [>");
          arvore(eixo->astn.filhos[0]);
  	  arvore(eixo->astn.filhos[1]);
  	  fprintf(yyout,"]");
        break;
	case MENOR:
          fprintf(yyout," [<");
          arvore(eixo->astn.filhos[0]);
  	  arvore(eixo->astn.filhos[1]);
  	  fprintf(yyout,"]");
        break;
	case MAIOR_IGUAL:
          fprintf(yyout," [>=");
          arvore(eixo->astn.filhos[0]);
  	  arvore(eixo->astn.filhos[1]);
  	  fprintf(yyout,"]");
        break;
	case MENOR_IGUAL:
          fprintf(yyout," [<=");
          arvore(eixo->astn.filhos[0]);
  	  arvore(eixo->astn.filhos[1]);
  	  fprintf(yyout,"]");
        break;
	case IGUAL_IGUAL:
          fprintf(yyout," [==");
          arvore(eixo->astn.filhos[0]);
  	  arvore(eixo->astn.filhos[1]);
  	  fprintf(yyout,"]");
        break;
	case DIFERENTE:
          fprintf(yyout," [!=");
          arvore(eixo->astn.filhos[0]);
  	  arvore(eixo->astn.filhos[1]);
  	  fprintf(yyout,"]");
        break;
        case ID:
          fprintf(yyout," [%d]", eixo->astn.filhos[0]->token.val);
        break;
 	case NUM:
          fprintf(yyout,"li $a0, %d /n", eixo->astn.filhos[0]->token.val);
        break;
	case C:
          fprintf(yyout," chamada:");
          arvore(eixo->astn.filhos[0]);
  	  arvore(eixo->astn.filhos[1]);
        break;
	case AR:
          fprintf(yyout," argumentos:");
          arvore(eixo->astn.filhos[0]);
  	  arvore(eixo->astn.filhos[1]);
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
	fprintf(yyout,"]");
	fclose(yyin);
	fclose(yyout);
	return 0;
}


