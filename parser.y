
%{
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>
 #include "myDef.h"


 void yyerror(char *);
 int yylex(void);
 float sym[30];
 double ((*op[20])(double));
 int i=0;
 
%}

%union{
	int iVal;
    float fVal;
    char var;
	char* ID;
}
%token <iVal> NUM
%token <keyword> ifKeyWord
%token <keyword> elseKeyWord
%token <keyword> VoidKeyWord
%token <keyword> IntKeyWord
%token <keyword> returnKeyWord
%token <keyword> OpenBrace
%token <keyword> CloseBrace
%token <keyword> OpenParenthesis
%token <keyword> CloseParenthesis
%token <keyword> Semicolon
%token <keyword> Comma
%token <keyword> OperatorSmallEqual
%token <keyword> OperatorSmall
%token <keyword> OperatorBigEqual
%token <keyword> OperatorBig
%token <keyword> OperatorNotEqual
%token <keyword> OperatorEqual
%token <keyword> OperatorAssign
%token <keyword> OperatorAdd
%token <keyword> OperatorMinus
%token <keyword> OperatorMult
%token <keyword> OperatorDiv
%token <keyword> OperatorOR
%token <keyword> OperatorAnd
%token <keyword> OperatorXOR
%token <keyword> BinaryOR
%token <keyword> BinaryAnd
%token <keyword> BinaryNot
%token <keyword> UnaryNot

%token <var> ID

%type <keyword> STMT_DECLARE PGM TYPE
%type <keyword> STMT STMTS STMT_CONDITIONAL
%type <keyword> STMT_ASSIGN STMT_RETURN
%type <keyword> IDS
%type <iVal> EXP
%type <iVal> TERM
%type <iVal> FACTOR
%type <iVal> TERM2
%type <iVal> TERM3
%type <iVal> TERM4
%type <iVal> TERM5
%type <iVal> TERM6
%type <iVal> TERM7
%type <iVal> TERM8
%type <iVal> TERM9

//%token FLOAT VARIABLE INTEGER expSym logSym sqrtSym


%left '+' '-' //'*' '/'
%right '*' '/'
%%
program:
 STMT_DECLARE PGM 
 ;
PGM:
 TYPE ID OpenParenthesis CloseParenthesis OpenBrace STMTS CloseBrace PGM |
  /*nothing!*/{}
 ;
STMTS:
 STMT STMTS | {}
 ;
STMT:
 STMT_DECLARE | 
 STMT_ASSIGN |
 STMT_RETURN|
 STMT_CONDITIONAL|
 Semicolon
;
STMT_CONDITIONAL:
 ifKeyWord OpenParenthesis EXP CloseParenthesis STMT
 | ifKeyWord OpenParenthesis EXP CloseParenthesis elseKeyWord  STMT

 

EXP:
 ID OperatorAssign EXP{ $$ = sym[$1]; }
 | TERM9
;

TERM9:
 TERM8 BinaryOR TERM8 {$$ = ($1)||($3);}
;

TERM8:
 TERM7 BinaryAnd TERM7 {$$ = ($1)&&($3);}
;
TERM7:
 TERM6 OperatorOR TERM6 {$$ = ($1)|($3);}
 
;

TERM6:
 TERM5 OperatorXOR TERM5 {$$ = ($1)^($3);}
;
TERM5:
 TERM4 OperatorAnd TERM4 {$$ = ($1)&($3);}
 
;

TERM4:
 TERM3 OperatorEqual TERM3 {$$ = ($1)==($3);}
 | TERM3 OperatorNotEqual TERM3 {$$ = ($1)!=($3);}
;

TERM3:
 TERM2 OperatorSmall TERM2 {$$ = ($1)<($3);}
 | TERM2 OperatorSmallEqual TERM2 {$$ = ($1)<=($3);}
 | TERM2 OperatorBig TERM2 {$$ = ($1)>($3);}
 | TERM2 OperatorBigEqual TERM2 {$$ = ($1)>=($3);}
 
;
 
TERM2:
 TERM OperatorAdd TERM { $$ = ($1) + ($3); }
 | TERM OperatorMinus TERM { $$ = ($1) - ($3); }
;
 
TERM:
 FACTOR OperatorMult FACTOR { $$ = ($1) * ($3); }
 | FACTOR OperatorDiv FACTOR { $$ = ($1) / ($3); }
;
FACTOR:
 NUM
 | OperatorMinus FACTOR { $$ = -($2); }
 | UnaryNot FACTOR { $$ = ~($2); }
 | BinaryNot FACTOR { $$ = !($2); }
 | OpenParenthesis EXP CloseParenthesis { $$ = $2; }
;
STMT_DECLARE:
 TYPE
 ID
 IDS
;
IDS:
 Semicolon |
 Comma ID IDS
;
STMT_ASSIGN:
 ID OperatorAssign EXP Semicolon
;
STMT_RETURN:
 returnKeyWord EXP Semicolon
;
TYPE:
 IntKeyWord |
 VoidKeyWord
;
%%

void yyerror(char *s) {
 fprintf(stderr, "%s\n", s);
}
int main(void) {
 yyparse();
}