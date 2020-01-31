
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
VAL:
	EXP {}
	|ID {}
EXP:
 /*ID OperatorAssign EXP{ $$ = $3 ;}
 |*/ TERM9
;

TERM9:
 TERM8 BinaryOR TERM8 // {$$ = ($1)||($3);}
  {
	 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("bne $s0,$zero,BinaryOR_True"); //age sefr nabood boro be true
	
						 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("bne $s0,$zero,True"); //age sefr nabood boro be true
	//age false shod
	pb.push_back("li $s0,0");  
	pb.push_back("j BinaryOR_write");  
	
	//age true shod
	pb.push_back("BinaryOR_True: li $s0,1");  
	 
	 
	pb.push_back("BinaryOR_write: addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	
 }
 | TERM8
;

TERM8:
 TERM7 BinaryAnd TERM7 //{$$ = ($1)&&($3);}
 {
	 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("beq $s0,$zero,BinaryAnd_False"); //age sefr bood boro be false
	
	
		 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("beq $s0,$zero,BinaryAnd_False"); //age sefr bood boro be false
	
	//age hardo sefr naboodan yani javab true mishod					 
	
	 
	pb.push_back("li $s0,1");  
	pb.push_back("j BinaryAnd_write");  
	
	//age true shod
	pb.push_back("BinaryAnd_False: li $s0,0");  
	 
	 
	pb.push_back("BinaryAnd_write: addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	
 }
 | TERM7
;
TERM7:
 TERM6 OperatorOR TERM6 // {$$ = ($1)|($3);}
  {
	 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("or $s2,$s1,$s0"); 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
 }
 | TERM6
 
;

TERM6:
 TERM5 OperatorXOR TERM5 // {$$ = ($1)^($3);}
  {
	 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("xor $s2,$s1,$s0"); 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
 }
 | TERM5
;
TERM5:
 TERM4 OperatorAnd TERM4 // {$$ = ($1)&($3);}
 {
	 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("and $s2,$s1,$s0"); 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
 }
 | TERM4
;

TERM4:
 TERM3 OperatorEqual TERM3 // {$$ = ($1)==($3);}
 {
	 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("beq $s0,$s1,OperatorEqual_true"); 
	
	//age false bood
	pb.push_back("li $s0, 0"); 
	pb.push_back("j OperatorEqual_write"); 
	
	//true bood
	pb.push_back("OperatorEqual_true: li $s0, 1"); 
	pb.push_back("OperatorEqual_write: addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	
 }
 | TERM3 OperatorNotEqual TERM3 // {$$ = ($1)!=($3);}
  {
	 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("bnq $s0,$s1,OperatorNotEqual_true"); 
	
	//age false bood
	pb.push_back("li $s0, 0"); 
	pb.push_back("j OperatorNotEqual_write"); 
	
	//true bood
	pb.push_back("OperatorNotEqual_true: li $s0, 1"); 
	pb.push_back("OperatorNotEqual_write: addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	
 }
 |TERM3
;

TERM3:
 TERM2 OperatorSmall TERM2 //{$$ = ($1)<($3);}
 {							//    s1 < s0
	 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	 //blt $t0, $t4, VIP_LESS  # if $t0 < $t4 then VIP
	pb.push_back("blt $s1, $s0,OperatorSmall_true"); 
	
	//age false bood
	pb.push_back("li $s0, 0"); 
	pb.push_back("j OperatorSmall_write"); 
	
	//true bood
	pb.push_back("OperatorSmall_true: li $s0, 1"); 
	pb.push_back("OperatorSmall_write: addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	
 }
	 
 | TERM2 OperatorSmallEqual TERM2 // {$$ = ($1)<=($3);}
 {								//          s1  > s0 => false
								//          s0  < s1 => false
	 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	 //blt $t0, $t4, VIP_LESS  # if $t0 < $t4 then VIP
	pb.push_back("blt $s0, $s1,OperatorSmallEqual_false"); 
	
	//age true bood
	pb.push_back("li $s0, 1"); 
	pb.push_back("j OperatorSmallEqual_write"); 
	
	//false bood
	pb.push_back("OperatorSmallEqual_false: li $s0, 0"); 
	pb.push_back("OperatorSmallEqual_write: addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	
 }
 | TERM2 OperatorBig TERM2 // {$$ = ($1)>($3);}
  {						   // 		 s1 > s0
  						   // 		 s0 < s1
	 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	 //blt $t0, $t4, VIP_LESS  # if $t0 < $t4 then VIP
	pb.push_back("blt $s0, $s1,OperatorBig_true"); 
	
	//age false bood
	pb.push_back("li $s0, 0"); 
	pb.push_back("j OperatorBig_write"); 
	
	//true bood
	pb.push_back("OperatorBig_true: li $s0, 1"); 
	pb.push_back("OperatorBig_write: addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	
 }
 | TERM2 OperatorBigEqual TERM2 //   {$$ = ($1)>=($3);}
 {								//          s1  < s0 => false
								 
	 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	 //blt $t0, $t4, VIP_LESS  # if $t0 < $t4 then VIP
	pb.push_back("blt $s1, $s0,OperatorBigEqual_false"); 
	
	//age true bood
	pb.push_back("li $s0, 1"); 
	pb.push_back("j OperatorBigEqual_write"); 
	
	//false bood
	pb.push_back("OperatorBigEqual_false: li $s0, 0"); 
	pb.push_back("OperatorBigEqual_write: addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	
 }
 | TERM2
 
;
 
TERM2:
 TERM OperatorAdd TERM // { $$ = ($1) + ($3); }
  {
	 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("add $s2,$s1,$s0"); 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
 }
 | TERM OperatorMinus TERM // { $$ = ($1) - ($3); }
  {								//    s1     s0
	 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("sub $s2,$s1,$s0"); 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
 }
 | TERM
;
 
TERM:
 FACTOR OperatorMult FACTOR //{ $$ = ($1) * ($3); }
 {								//    s1     s0
	 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("mul $s2,$s1,$s0"); 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
 }
 | FACTOR OperatorDiv FACTOR // { $$ = ($1) / ($3); }
 {								  //    s1     s0
	 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("div $s1,$s0"); 
	pb.push_back("mflo $s2"); 
	 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
 }
 | FACTOR
;
FACTOR:
 NUM {
	 char tmp[500];
	 sprintf(tmp,"movl $%d, %%eax",$1);
	 pb.push_back(string(tmp));
	 pb.push_back("push %eax");
	 }
 | OperatorMinus FACTOR // { $$ = -($2); }
   {								//   
	 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("li $1,-1"); 
	
	
	
	pb.push_back("mul $s2,$s1,$s0"); 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
   }
   | UnaryNot FACTOR //{ $$ = ~($2); }
   {								//   
	 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	 
	
	pb.push_back("not $s2,$s0"); 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
    }
    | BinaryNot FACTOR //{ $$ = !($2); }
    {								//   
	 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("beq $s0,$zero,BinaryNot_return1"); 
	pb.push_back("li s2,0"); 
	
	pb.push_back("j BinaryNot_save"); 
	
	pb.push_back("BinaryNot_return1 : li s2,1"); 
	
	
	
	pb.push_back("BinaryNot_save: addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
    }
    | OpenParenthesis EXP CloseParenthesis //{ $$ = $2; }
	 {
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
