%{
#include<stdio.h>
%}
%%
if|else|while|int|switch|char|for|auto|break|case|const|continue|default|do|double|enum|extern|float|goto|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile {printf("Keyword");}
[0-9]* {printf("Number");}
([a-z]|[A-Z]|[0-9])* {printf("Identifier");}
(.)* {printf("Invalid");}
%%
main()
{
yylex();
return 0;
}
int yywrap()
{

}
