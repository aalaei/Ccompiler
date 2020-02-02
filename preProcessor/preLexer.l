 
%{

 #include <stdlib.h>
 #include "preParser.tab.h"
 void yyerror(const char *);
 
 
%}
numbers ([0-9])+
%%
"#" {
    return SHARP;
}

"\n" {
    //printf("enter\n");
    //return NEXTLINE;
}

"#define ".*$ {
    strcpy(yylval.name,yytext);
    return defKeyWord;
    //printf("%s\n",yytext);
}
"#include ".* {
    strcpy(yylval.name,yytext);
    return includeKeyWord;
    //printf("%s\n",yytext);
};
[\t] ; /* skip whitespace */
"//".* ;

^[^"\n]* {strcpy(yylval.T,yytext);/*printf("AAAA:%s\n",yytext);*/return TEXT;}
\"(\\.|[^"\\])*\" {strcpy(yylval.name,yytext+1);/*printf("BB:%s\n",yytext);*/ return ID;}

[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]       ;
[/][*]                                    { yyerror("Unterminated comment"); }

. {printf("ZZ:%s\n",yytext);}
%%

int yywrap(void) {
 return 1;
 //\n.* EOF ; {printf("XX:%s\n",yytext);} 
}
