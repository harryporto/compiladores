%{
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "parcer.tab.h"

#define YY_DECL int yylex()

int linha=1;
%}



%option  noyywrap 
DEC [0-9]
ID  [a-zA-Z][a-zA-Z0-9_]*
COM [<>!=][=]


%%
"+"      		{  return MAIS; }
"-"       		{  return MENOS; } 
"*"      		{  return VEZES; }
"/"      		{  return DIVISAO; }
"("      		{  return ABRE_PAREN;  }
")"      		{  return FECHA_PAREN;  }
";"      		{  return PONTO_VIRGULA;  }
">"      		{  return MAIOR;  }
">="    		{  return MAIOR_IGUAL;  }
"<"     		{  return MENOR;  }
"<="    		{  return MENOR_IGUAL;  }
"=="		     	{  return IGUAL_IGUAL;  }
"!="		     	{  return DIFERENTE_IGUAL;  }
"&&"		     	{  return AND;  }
"||" 		    	{  return OR;  }
"!" 		    	{  return NOT;  }
"{"  		    	{  return ABRE_CHAVE;  }
"}" 		    	{  return FECHA_CHAVE;  }
"["  		    	{  return ABRE_COLCHETE;  }
"]" 		    	{  return FECHA_COLCHETE;  }
"," 		    	{  return VIRGULA;  }
"="     		{  return IGUAL;  }
"def"     		{  return DEF;  }
"if"     		{  return IF;  }
"else"    		{  return ELSE;  }
"while"    		{  return WHILE;  }
"return"    		{  return RETURN;  }
"break"    		{  return BREAK;  }
"continue"    		{  return CONTINUE;  }
"let"   		{  return LET;  }
{ID} 			{ strcpy(yylval.valor, yytext); return ID; }
{DEC}+ 			{ yylval.inteiro  = atoi(yytext); return DEC;  }
" "+ 			{ linha++; }
\n  			{ linha++; }
[ \t\n] {}
"_"		        								{fprintf(yyout, "ERROR \"%s\" %d\n",yytext,linha); return 0;}
.         										{fprintf(yyout, "ERROR \"%s\" %d\n",yytext,linha); return 0;}
%%


