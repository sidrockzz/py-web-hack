%{
int wc=0,cc=0,lc=0,bc=0;
char infile[25];
%}
word [^ \t\n]+
eol [\n]
%%
{word} {wc++;cc+=yyleng;}
{eol} {lc++;cc++;}
[ ] {bc++;cc++;}
[\t] {bc+=8;cc++;}
. {cc++;}
%%
main()
{
printf("Read the Input File name\n");
scanf("%s",infile);
yyin=fopen(infile,"r");
yylex();
fclose(yyin);
printf("No. of Char:%d\n No. of Words:%d\n No. of Lines:%d\nNo. of Blanks:%d\n",cc,wc,lc,bc);
}
int yywrap()
{
}
