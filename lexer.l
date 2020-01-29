 
%{
 #include "parser.tab.h"
 #include <stdlib.h>

 void yyerror(const char *);
 //%option c++
%}
numbers ([0-9])+
alpha ([a-zA-Z])+
%%
"if" {
    return ifKeyWord;
}
"else" {
    return elseKeyWord;
}
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

{alpha} {
 //yylval.name = *yytext;
 strcpy(yylval.name,yytext);
 return ID;
 }
{numbers} {
    yylval.iVal= atoi(yytext);    
    return NUM;
}

[ \t] ; /* skip whitespace */
. yyerror("Unknown character");
%%
int yywrap(void) {
 return 1;
}
