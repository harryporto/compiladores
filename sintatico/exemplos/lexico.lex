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

{DEC}+    										{printf( "DEC \"%s\" %d\n",yytext,linha);}
let|def|if|else|while|return|break|continue     {printf( "KEY \"%s\" %d\n",yytext,linha);}
{ID}      										{printf( "ID \"%s\" %d\n",yytext,linha);}
{SYM}     										{printf( "SYM \"%s\" %d\n",yytext,linha);}
{COM}     										{printf( "SYM \"%s\" %d\n",yytext,linha);}
\&{2}     										{printf( "SYM \"%s\" %d\n",yytext,linha);}
\|{2}     										{printf( "SYM \"%s\" %d\n",yytext,linha);}
\n+		  										{linha++;}
" "+	  										{continue;}
\t+	  											{continue;}
\/\/.+											{continue;}
"_"[a-zA-Z0-9_]*         						{printf( "ERROR \"%s\" %d\n",yytext,linha); return 0;}
.         										{printf( "ERROR \"%s\" %d\n",yytext,linha); return 0;}

%%
