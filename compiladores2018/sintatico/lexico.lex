%{
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "parcer.tab.h"

int linha=1;


%}


%option noyywrap
NUM [0-9][0-9]*
ID  [a-zA-Z][a-zA-Z0-9]*
COM [<>!=]=

%%

void     						{return VOID;}
int    							{return INT;}
if    							{return IF;}
else     						{return ELSE;}
while     						{return WHILE;}
return     						{return RETURN;}
{ID}  							{strcpy(yylval.valor, yytext);return ID;}
{NUM}    						{ yylval.inteiro  = atoi(yytext);return NUM;}
"+"   							{return MENOS;}
"-"    							{return MAIS;}
"*"     						{return VEZES;}
"/"     						{return DIV;}
"{"      						{return ABRE_CHA;}
"}"     						{return FECHA_CHA;}
"("     						{return ABRE_PAR;}
")"    							{return FECHA_PAR;}
","   							{return VIRG;}
";"   							{return PVIRG;}
"="     						{return IGUAL;}
"<"     						{return MENOR;}
">"    							{return MAIOR;}
"<="    						{return MENOR_IGUAL;}
">="    						{return MAIOR_IGUAL;}
"!="    						{return DIFERENTE;}
"=="    						{return IGUAL_IGUAL;}
"["    							{return ABRE_COL;}
"]"    							{return FECHA_COL;}
{NUM}{ID}						{fprintf(yyout, "(%d,ERROR,\"%s\")\n",linha,yytext); return 0;}
[a-zA-Z]^[a-zA-Z0-9]					{fprintf(yyout, "(%d,ERROR,\"%s\")\n",linha,yytext); return 0;}
\n		  					{linha++;}
" "+	  						{continue;}
\t+	  						{continue;}
.         						{fprintf(yyout, "(%d,ERROR,\"%s\")\n",linha,yytext); return 0;}


