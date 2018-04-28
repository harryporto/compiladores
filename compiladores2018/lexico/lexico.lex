%{
#include <math.h>
int linha=1;
%}


%option noyywrap
NUM [0-9][0-9]*
ID  [a-zA-Z][a-zA-Z0-9]*
COM [<>!=]=

%%

"/*"								{if(comment()){continue;}else{fprintf(yyout, "(%d,ERROR,\"/*\")\n",linha); return 0;};}//comentario
void|int|if|else|while|return     							{fprintf(yyout, "(%d,KEY,\"%s\")\n",linha,yytext);}
{ID}      										{fprintf(yyout, "(%d,ID,\"%s\")\n",linha,yytext);}
{NUM}    										{fprintf(yyout, "(%d,NUM,\"%s\")\n",linha,yytext);}
[-+*/{}(),;=<>]     									{fprintf(yyout, "(%d,SYM,\"%s\")\n",linha,yytext);}
{COM}     										{fprintf(yyout, "(%d,SYM,\"%s\")\n",linha,yytext);}
"["    											{fprintf(yyout, "(%d,SYM,\"%s\")\n",linha,yytext);}
"]"    											{fprintf(yyout, "(%d,SYM,\"%s\")\n",linha,yytext);}
{NUM}{ID}										{fprintf(yyout, "(%d,ERROR,\"%s\")\n",linha,yytext); return 0;}
[a-zA-Z]^[a-zA-Z0-9]									{fprintf(yyout, "(%d,ERROR,\"%s\")\n",linha,yytext); return 0;}
\n		  										{linha++;}
" "+	  										{continue;}
\t+	  											{continue;}
.         										{fprintf(yyout, "(%d,ERROR,\"%s\")\n",linha,yytext); return 0;}

%%


int main(int argc, char const *argv[])
{

    if(argc > 0) yyin = fopen(argv[1],"r");
      if(argc > 1) yyout = fopen(argv[2],"w");
    yylex();
    return 0;
}

int comment(void)
{
	char c, prev = 0;
  
	while ((c = input()) != EOF)      /* (EOF maps to 0) */
	{
		
		if(c == '\n'){
			linha++;
		}else if(c == '/' && prev == '*'){
			return 1 ;
		}
		prev = c;
		//fprintf(yyout,"%d \n",linha);
	}
	linha--;
	return 0;
}
