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

Program : DecVar S| DecFunc S;
DecVar : LET ID AA;
DecFunc : DEF ID '(' BB;
ParamList : ID P;
Block : '{' N O '}';
Stmt : Assign ';' | FuncCall ';' | IF '(' Expr ')' Block FF | WHILE '(' Expr ')' Block | RETURN FFF | BREAK ';' | CONTINUE ';';
Assign : ID '=' Expr;
FuncCall : ID '(' HH;
ArgList : Expr II;
Expr : Expr BinOp Expr ';' | UnOp Expr ';' %prec UNA | '(' Expr ')' | FuncCall | DEC | ID ;
BinOp : '+' | '-' | '*' | '/' | '<' | "<=" | '>' | ">=" | "==" | "!=" | "&&" | "||";
UnOp : '-' | '!';

AA : '=' Expr ';' | ';';
BB : ParamList ')' Block | ')' Block ;
P : ',' ID P | /* empty */;
N : DecVar N | /* empty */;
O : Stmt O | /* empty */;
FF :  ELSE Block | /* empty */;
FFF : Expr ';' | ';';
HH : ArgList ')' | ')';
II : ','  | /* empty */;
S : Program | /* empty */;

%%

void yyerror (char *s) {
	printf("erro - Mudar essa mensagem.");
}

int main() {
  return yyparse();
}
