 
%{
 #include "parser.tab.h"
 #include <stdlib.h>

 #include <string.h>
 //#include "myDef.h"

 void yyerror(char *);
 //%option c++
%}

%%

"return" {
    return returnKeyWord;
}
"void" {
    return VoidKeyWord;
}
"int" {
    return IntKeyWord;
}
"{" {
    return OpenBrace;
}
"}" {
    return CloseBrace;
}
"\(" {
    return OpenParenthesis;
}
"\)" {
    return CloseParenthesis;
}
";" {
    return Semicolon;
}
"," {
    return Comma;
}
"<=" {
    return OperatorSmallEqual;
}
"<" {
    return OperatorSmall;
}
">=" {
    return OperatorBigEqual;
}
">" {
    return OperatorBig;
}

"!=" {
    return OperatorNotEqual;
}
"==" {
    return OperatorEqual;
}
"=" {
    return OperatorAssign;
}

"+" {
    return OperatorAdd;
}
"-" {
    return OperatorMinus;
}
"*" {
    return OperatorMult;
}
"/" {
    return OperatorDiv;
}
"|" {
    return OperatorOR;
}
"&" {
    return OperatorAnd;
}
"^" {
    return OperatorXOR;
}
"||" {
    return BinaryOR;
}
"&&" {
    return BinaryAnd;
}
"!" {
    return BinaryNot;
}
"~" {
    return UnaryNot;
}

[a-zA-Z]\w* {
 yylval.var = *yytext - 'a';
 return ID;
 }
[0-9]+ {
    yylval.iVal= atoi(yytext);    
    return NUM;
}
[-+()=/*\n] { return *yytext; }
[ \t] ; /* skip whitespace */
. yyerror("Unknown character");
%%
int yywrap(void) {
 return 1;
}
