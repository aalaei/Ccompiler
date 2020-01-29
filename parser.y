
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


%type <ID> STMT_DECLARE PGM TYPE
%type <ID> STMT STMTS
%type <ID> STMT_ASSIGN STMT_RETURN
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

//%token FLOAT VARIABLE INTEGER expSym logSym sqrtSym


%left '+' '-' //'*' '/'
%right '*' '/'
%%
program:
 STMT_DECLARE PGM 
 ;
PGM:
 TYPE ID OpenParenthesis CloseParenthesis OpenBrace STMTS CloseBrace PGM |
  /*nothing!*/
 ;
STMTS:
 STMT STMTS |
 ;
STMT:
 STMT_DECLARE | 
 STMT_ASSIGN |
 STMT_RETURN|
 Semicolon;

EXP:
 EXP BinaryOR EXP {$$ = ($1)||($3);}
 | TERM8
;

TERM8:
 TERM8 BinaryAnd TERM8 {$$ = ($1)&&($3);}
 | TERM7
;
TERM7:
 TERM7 OperatorOR TERM7 {$$ = ($1)|($3);}
 | TERM6
;

TERM6:
 TERM6 OperatorXOR TERM6 {$$ = ($1)^($3);}
 | TERM5
;
TERM5:
 TERM5 OperatorAnd TERM5 {$$ = ($1)&($3);}
 | TERM4
;

TERM4:
 | TERM4 OperatorEqual TERM4 {$$ = ($1)==($3);}
 | TERM4 OperatorNotEqual TERM4 {$$ = ($1)!=($3);}
 | TERM3
 ;

TERM3:
 TERM3 OperatorSmall TERM3 {$$ = ($1)<($3);}
 | TERM3 OperatorSmallEqual TERM3 {$$ = ($1)<=($3);}
 | TERM3 OperatorBig TERM3 {$$ = ($1)>($3);}
 | TERM3 OperatorBigEqual TERM3 {$$ = ($1)>=($3);}
 | TERM2
;
 
TERM2:
 TERM2 OperatorAdd TERM2 { $$ = ($1) + ($3); }
 | TERM2 OperatorMinus TERM2 { $$ = ($1) - ($3); }
 | TERM
;
 
TERM:
 TERM OperatorMult TERM { $$ = ($1) * ($3); }
 | TERM OperatorDiv TERM { $$ = ($1) / ($3); }
 | FACTOR
;
FACTOR:
 NUM
 | ID { $$ = sym[$1]; }
 | OperatorMinus FACTOR { $$ = -($2); }
 | UnaryNot FACTOR { $$ = ~($2); }
 | BinaryNot FACTOR { $$ = !($2); }
 | OpenParenthesis EXP CloseParenthesis { $$ = $2; }

STMT_DECLARE:
TYPE |
ID |
IDS;
IDS:
 Semicolon |
 Comma ID IDS
;
STMT_ASSIGN:
ID OperatorAssign EXP Semicolon;
STMT_RETURN:
returnKeyWord EXP Semicolon;
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