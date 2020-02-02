 
%{
 #include "parser.tab.h"
 #include <stdlib.h>
 extern int yylineNum;
 void yyerror(const char *);
 //%option c++
 int findNexLine(char * txt)
 {
     int res=0;
     while(*txt)
     {
        if(*txt == '\n')
            res++;
         txt++;
     }
     return res;
 }
%}
numbers ([0-9])+
alpha ([a-zA-Z])([a-zA-Z0-9]*)

%%
"if" {
    return ifKeyWord;
}
"else" {
    return elseKeyWord;
}
"while" {
    return whileKeyWord;
}
"for" {
    return forKeyWord;
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
"++" {
    return OperatorPP;
}
"--" {
    return OperatorMM;
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
"//".* ;
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]       {yylineNum+=findNexLine(yytext);}
[/][*]                                    { yyerror("Unterminated comment"); }
[\n] {yylineNum++;}
. yyerror("Unknown character");
%%
int yywrap(void) {
 return 1;
}
