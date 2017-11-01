%{
#include <math.h>
int linha=1;
%}


%option noyywrap
DEC [0-9]
ID  [a-zA-Z][a-zA-Z0-9_]*
COM [<|>|!|=][=]
SYM ["+"|"-"|"*"|"/"|"{"|"}"|"("|")"|","|";"|"="|"<"|">"|"!"]

%%

{DEC}+    										{fprintf(yyout, "DEC \"%s\" %d\n",yytext,linha);}
let|def|if|else|while|return|break|continue     					{fprintf(yyout, "KEY \"%s\" %d\n",yytext,linha);}
{ID}      										{fprintf(yyout, "ID \"%s\" %d\n",yytext,linha);}
{SYM}     										{fprintf(yyout, "SYM \"%s\" %d\n",yytext,linha);}
{COM}     										{fprintf(yyout, "SYM \"%s\" %d\n",yytext,linha);}
\&{2}     										{fprintf(yyout, "SYM \"%s\" %d\n",yytext,linha);}
\|{2}     										{fprintf(yyout, "SYM \"%s\" %d\n",yytext,linha);}
\n+		  									{linha++;}
" "+	  										{continue;}
\t+	  										{continue;}
\/\/.+											{continue;}
"_"[a-zA-Z0-9_]*         								{fprintf(yyout, "ERROR \"%s\" %d\n",yytext,linha); return 0;}
.         										{fprintf(yyout, "ERROR \"%s\" %d\n",yytext,linha); return 0;}

%%


int main(int argc, char const *argv[])
{

    if(argc > 0) yyin = fopen(argv[1],"r");
      if(argc > 1) yyout = fopen(argv[2],"w");
    yylex();
    return 0;
}

