%{
#include <math.h>
int linha=1;
%}


%option noyywrap
NUM [0-9]
ID  [a-zA-Z][a-zA-Z0-9]*
COM [<>!=][=]

%%

\/\*[^"*\"]+\*\\										{continue;}//comentario
{NUM}+    										{fprintf(yyout, "(%d,NUM,\"%s\")\n",linha,yytext);}
void|int|if|else|while|return     							{fprintf(yyout, "(%d,KEY,\"%s\")\n",linha,yytext);}
{ID}      										{fprintf(yyout, "(%d,ID,\"%s\")\n",linha,yytext);}
[-+*/{}(),;=<>!]     									{fprintf(yyout, "(%d,SYM,\"%s\")\n",linha,yytext);}
{COM}     										{fprintf(yyout, "(%d,SYM,\"%s\")\n",linha,yytext);}
"["    											{fprintf(yyout, "(%d,SYM,\"%s\")\n",linha,yytext);}
"]"    											{fprintf(yyout, "(%d,SYM,\"%s\")\n",linha,yytext);}
\n		  										{linha++;}
" "+	  										{continue;}
\t+	  											{continue;}
"_"		        								{fprintf(yyout, "(%d,ERROR,\"%s\")\n",linha,yytext); return 0;}
.         										{fprintf(yyout, "(%d,ERROR,\"%s\")\n",linha,yytext); return 0;}

%%


int main(int argc, char const *argv[])
{

    if(argc > 0) yyin = fopen(argv[1],"r");
      if(argc > 1) yyout = fopen(argv[2],"w");
    yylex();
    return 0;
}

