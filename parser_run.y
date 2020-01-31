
%{
 
 #include <iostream> 
 

 using namespace std;
 static long long Cur_Mem_tmp=100;
 
 #include "myDef.h"
 
 extern FILE* yyin;
 extern int yylex();
 void yyerror(const char* error);
 
 int yylineNum=0;
 FILE* f1;

 extern long long PC; 

 int yyparse();
	
%}

%union{
	int iVal;
	char name[100];
}
%token <iVal> NUM
%token <name> ifKeyWord
%token <name> elseKeyWord
%token <name> VoidKeyWord
%token <name> IntKeyWord
%token <name> returnKeyWord
%token <name> OpenBrace
%token <name> CloseBrace
%token <name> OpenParenthesis
%token <name> CloseParenthesis
%token <name> Semicolon
%token <name> Comma
%token <name> OperatorSmallEqual
%token <name> OperatorSmall
%token <name> OperatorBigEqual
%token <name> OperatorBig
%token <name> OperatorNotEqual
%token <name> OperatorEqual
%token <name> OperatorAssign
%token <name> OperatorAdd

%token <name> OperatorMinus
%token <name> OperatorMult
%token <name> OperatorDiv
%token <name> OperatorOR
%token <name> OperatorAnd
%token <name> OperatorXOR
%token <name> BinaryOR
%token <name> BinaryAnd
%token <name> BinaryNot
%token <name> UnaryNot

%token <name> ID

%type <name> STMT_DECLARE PGM TYPE
%type <name> STMT STMTS STMT_FUNCTIONCALL matched unmatched other_statement
%type <name> STMT_ASSIGN STMT_RETURN
%type <name> IDS


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

%type <name> VAL;

//%token FLOAT VARIABLE INTEGER expSym logSym sqrtSym


//%left '+' '-' //'*' '/'
//%right '*' '/'


%%
PROGRAM:
 STMT_DECLARE PGM 
 ;
PGM:
 TYPE ID OpenParenthesis CloseParenthesis 
 	 {declare_Function($2,0,$1);}
	  OpenBrace STMTS CloseBrace PGM |
 TYPE ID OpenParenthesis ID CloseParenthesis {}
 	 {declare_Function($2,1,$1);}
	  OpenBrace STMTS CloseBrace PGM |
 TYPE ID OpenParenthesis ID Comma ID CloseParenthesis {}
 	 {declare_Function($2,1,$1);}
	  OpenBrace STMTS CloseBrace PGM |
 TYPE ID OpenParenthesis ID Comma ID Comma ID CloseParenthesis {}
 	 {declare_Function($2,1,$1);}
	  OpenBrace STMTS CloseBrace PGM |
 TYPE ID OpenParenthesis ID Comma ID Comma ID Comma ID  CloseParenthesis {}
 	 {declare_Function($2,1,$1);}
	  OpenBrace STMTS CloseBrace PGM |
  /*nothing!*/{}
 ;
STMTS:
 STMT STMTS | {}
 ;
STMT:
 matched
 | unmatched
;
other_statement:
 STMT_DECLARE | 
 STMT_ASSIGN |
 STMT_RETURN|
 STMT_FUNCTIONCALL|
 Semicolon{semantic_stack.top();}
;
/*
STMT_CONDITIONAL:

 ifKeyWord OpenParenthesis EXP CloseParenthesis STMT
 | ifKeyWord OpenParenthesis EXP CloseParenthesis STMT elseKeyWord  STMT
 matched
 | unmatched
;
*/
matched:
  ifKeyWord OpenParenthesis EXP CloseParenthesis matched elseKeyWord matched
  | other_statement
;


unmatched:
  ifKeyWord OpenParenthesis EXP CloseParenthesis STMT
  |ifKeyWord OpenParenthesis EXP CloseParenthesis matched elseKeyWord unmatched
;
EXP:
 /*ID OperatorAssign EXP{ $$ = $3 ;}
 |*/ TERM9 {$$ = ($1);}
;

TERM9:
 TERM8 BinaryOR TERM8 
  {
	$$ = ($1)||($3);	 
	
 }
 | TERM8 {$$ = ($1);}
;

TERM8:
 TERM7 BinaryAnd TERM7
 {
	$$ = ($1)&&($3);	  
 }
 | TERM7 {$$ = ($1);}
;
TERM7:
 TERM6 OperatorOR TERM6
  {
	$$ = ($1) | ($3); 	
  }
 | TERM6 {$$ = ($1);}
 
;

TERM6:
 TERM5 OperatorXOR TERM5
  {
	$$ = ($1)^($3); 
	
	
 }
 | TERM5 {$$ = ($1);}
;
TERM5:
 TERM4 OperatorAnd TERM4
 {
	$$ = ($1)&($3); 
	
	
 }
 | TERM4 {$$ = ($1);}
;

TERM4:
 TERM3 OperatorEqual TERM3 
 {
	$$ = ($1)==($3);
	pb.push_back("lw $s0, 0($sp)"); 
	
	
 }
 | TERM3 OperatorNotEqual TERM3
  {
	$$ = ($1)!=($3);
	
 }
 |TERM3 {$$= ($1);}
;

TERM3:
 TERM2 OperatorSmall TERM2
 {							//    s1 < s0
	$$ = ($1)<($3); 					 
	
 }
	 
 | TERM2 OperatorSmallEqual TERM2
 {								//          s1  > s0 => false
								//          s0  < s1 => false
    $$ = ($1)<=($3);	 					 
	
 }
 | TERM2 OperatorBig TERM2
  {						   // 		 s1 > s0
  						   // 		 s0 < s1
    $$ = ($1)>($3);	 					 
	
  }
 | TERM2 OperatorBigEqual TERM2
 {								//          s1  < s0 => false
								 
	$$ = ($1)>=($3);
	
 }
 | TERM2 {$$ = ($1);}
 
;
 
TERM2:
 TERM OperatorAdd TERM
  {
	$$ = ($1) + ($3); 
	
  }
 | TERM OperatorMinus TERM
  {								//    s1     s0
	$$ = ($1) - ($3);	
  }
 | TERM {$$= ($1);}
;
 
TERM:
 FACTOR OperatorMult FACTOR
 {								//    s1     s0
	$$ = ($1) * ($3);
	
 }
 | FACTOR OperatorDiv FACTOR
 {								  //    s1     s0
	if($3==0)
	{
		printf("divide by zero error!!\n");
		exit(-100);
	}
 	$$ = ($1) / ($3);
	
 }
 | FACTOR {$$ = ($1);}
;
FACTOR:
 NUM {
	 $$ = $1;
	 }
 | OperatorMinus FACTOR
   {								//   
    $$ = -($2);
   }
   | UnaryNot FACTOR
   {								//   
	$$ = ~($2);
	
    }
    | BinaryNot FACTOR
    {								//   
	$$ = !($2);
    }
    | OpenParenthesis EXP CloseParenthesis
	 {
		$$ = $2;
		 //not thing
	 }
;
STMT_DECLARE:
 IntKeyWord ID {declare_IntVariable($2);} IDS
;
STMT_FUNCTIONCALL:
 ID OpenParenthesis  CloseParenthesis Semicolon {functionCall($1,0);}
 | ID OpenParenthesis VAL CloseParenthesis Semicolon {functionCall($1,1,$3);}
 | ID OpenParenthesis VAL Comma VAL CloseParenthesis Semicolon {functionCall($1,2,$3,$5);}
 | ID OpenParenthesis VAL Comma VAL Comma VAL CloseParenthesis Semicolon {functionCall($1,3,$3,$5,$7);}
 | ID OpenParenthesis VAL Comma VAL Comma VAL Comma VAL CloseParenthesis Semicolon {functionCall($1,4,$3,$5,$7,$9);}
 
;
IDS:
 Semicolon |
 Comma ID {declare_IntVariable($2);} IDS
;
STMT_ASSIGN:
 ID OperatorAssign EXP Semicolon {}
 |ID OperatorAssign ID Semicolon {}
 |ID OperatorAssign ID OpenParenthesis CloseParenthesis Semicolon {functionCall($3,0);}
 |ID OperatorAssign ID OpenParenthesis VAL CloseParenthesis Semicolon {functionCall($3,1,$5);}
 |ID OperatorAssign ID OpenParenthesis VAL Comma VAL CloseParenthesis Semicolon {functionCall($3,2,$5,$7);}
 |ID OperatorAssign ID OpenParenthesis VAL Comma VAL Comma VAL CloseParenthesis Semicolon {functionCall($3,3,$5,$7,$9);}
 |ID OperatorAssign ID OpenParenthesis VAL Comma VAL Comma VAL Comma VAL CloseParenthesis Semicolon {functionCall($3,4,$5,$7,$9,$11);}
;
STMT_RETURN:
 returnKeyWord EXP Semicolon{pb.push_back("ret");}
;
TYPE:
 IntKeyWord {strcpy($$,"int"); }
 |VoidKeyWord {strcpy($$,"void");}
;
%%


void yyerror(const char *s) {
 fprintf(stderr, "%s\n", s);
}
int main(int argc, char *argv[])
{
	yyin = fopen(argv[1], "r");
	f1=fopen("output","w");

    if(!yyparse())
		printf("\nParsing complete\n");
	else
	{
		printf("\nParsing failed\n");
		exit(-1);
	}
	printf("MIPS CODE is saves in output file!\n");
	for(int j=0;j<pb.size();j++)
	{
		fprintf(f1,"%s\n",pb[j].c_str());
		//printf("%s\n",pb[j].c_str());
	}
    fprintf(f1,"\n");
    
	fclose(yyin);
	fclose(f1);
    return 0;
}
