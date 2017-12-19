%{
#include <math.h>

#include "parcer.tab.c"

#define YY_DECL int yylex()

int linha=1;
%}



%option yylineno
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
{ID} 			{ yylval.sval = malloc(strlen(yytext));	strncpy(yylval.sval, yytext, strlen(yytext)); return ID; }
{DEC}+ 			{ yylval.integer = atoi(yytext); return DEC;  }
" "+ 			{ linha++; out << linha; linha = out.str(); out.str("");}
\n  			{ linha++; out << linha; linha = out.str(); out.str(""); }
[ \t\n] {}
. { teste = teste + "ERROR"+" \"" + string(yytext) +"\" " +linha + "\n";  return 0; }
%%

/*%%

{DEC}+    										{fprintf(yyout, "DEC \"%s\" %d\n",yytext,linha);}
let|def|if|else|while|return|break|continue     					{fprintf(yyout, "KEY \"%s\" %d\n",yytext,linha);}
{ID}      										{fprintf(yyout, "ID \"%s\" %d\n",yytext,linha);}
[-+{}(),;=<>!]     									{fprintf(yyout, "SYM \"%s\" %d\n",yytext,linha);}
{COM}     										{fprintf(yyout, "SYM \"%s\" %d\n",yytext,linha);}
&&    											{fprintf(yyout, "SYM \"%s\" %d\n",yytext,linha);}
"||"    										{fprintf(yyout, "SYM \"%s\" %d\n",yytext,linha);}
\n		  									{linha++;}
" "+	  										{continue;}
\t+	  										{continue;}
\/\/.+											{continue;}
"_"		        								{fprintf(yyout, "ERROR \"%s\" %d\n",yytext,linha); return 0;}
.         										{fprintf(yyout, "ERROR \"%s\" %d\n",yytext,linha); return 0;}

%%


int main(int argc, char const *argv[])
{

    if(argc > 0) yyin = fopen(argv[1],"r");
      if(argc > 1) yyout = fopen(argv[2],"w");
    yylex();
    return 0;
}*/

