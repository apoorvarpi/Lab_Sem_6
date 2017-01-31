%{
#include <stdio.h>
int flag;
%}
%option noyywrap
%%

[0-9]+  {
            if(flag==-1)
	       flag=0;
            //printf("Integer\n");
        }

[0-9]+\.[0-9]+  {
	     flag=1;
            //printf("Float\n");
        }

\- { }

.	{
		flag=2;
		printf("Illegal expression\n");
		return 0;
	}

\n    {   return 0;  }


%%

int main(void)
{
    /* Call the lexer, then quit. */
    flag=-1;
    yylex();
    if(flag==0)
	printf("Integer\n");
    if(flag==1)
	printf("Float\n");
    return 0;
}
