
%{
 
 #include <iostream> 
 

 using namespace std;
 static long long Cur_Mem_tmp=104;
 bool verbose;
 bool pre;
 bool ERROR_occurred=0;
 int out;
 int mid;
 int yylineNum=0;
 string lastScope;
 int localCount=2;
 string lastScope_BLOCK;
 int labelCnt=0;

 void yyerror(const char* error);
 void myerror(const char * er,int errCode)
 {
	 char temp[500];
	 sprintf(temp,"error occurred Code %d :\n\t%s\n> line number: #%d\n",-errCode,er,yylineNum+1);
	 yyerror(temp);	 
	 ERROR_occurred=1;

 }
 void warning(const char * warn)
 {
	 printf("warning :\n\t%s\n> line number: #%d\n",warn,yylineNum+1);
 }
 #define MAIN_OFFSET 200
 #define ARRAY_OFFSET 1000
 #define DYNAMIC_OFFSET_LOC 96
 static long long ARRAY_CNT=ARRAY_OFFSET;

 #include "myDef.h"
 
 extern FILE* yyin;
 extern int yylex();
 
 
 FILE* f1;

 extern long long PC; 
 

 int yyparse();
	
%}

%union{
	int iVal;
	char name[100];
	long long address;
}
%token <iVal> NUM
%token <name> ifKeyWord
%token <name> elseKeyWord
%token <name> whileKeyWord
%token <name> forKeyWord
%token <name> OperatorPP
%token <name> OperatorMM

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

%token <name> OpenBracket
%token <name> CloseBracket

%type <name> STMT_DECLARE STMT_DECLARE_L STMT_DECLARE_ASSL PGM TYPE STMT_WHILE STMT_FOR
%type <name> STMT STMTS matched unmatched other_statement IF IF_ELSE //STMT_CONDITIONAL
%type <name> STMT_ASSIGN STMT_RETURN
%type <name> IDS


%type <address> EXP 
%type <iVal> EXP_FUNCTIONCALL
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


//%left '+' '-' //'*' '/'
//%right '*' '/'
//%right OperatorPP OperatorMM
//%right ID

%%
PROGRAM:
	STMT_DECLARE {makeGolobal(); } PGM
	/*| PGM*/
 ;
 

;
PGM:
 TYPE ID OpenParenthesis CloseParenthesis 
 	 {declare_Function($2,0,$1);}
	  BLOCK_FUN{ functionFinished(0,$2);} PGM |
 TYPE ID OpenParenthesis ID CloseParenthesis 
 	 {declare_Function($2,1,$1);}{fun_var($4,1);}
	  BLOCK_FUN{ functionFinished(1,$2);} PGM |
 TYPE ID OpenParenthesis ID Comma ID CloseParenthesis 
 	 {declare_Function($2,2,$1);}{fun_var($4,1);fun_var($6,2);}
	  BLOCK_FUN{ functionFinished(2,$2);}PGM |
 TYPE ID OpenParenthesis ID Comma ID Comma ID CloseParenthesis 
 	 {declare_Function($2,3,$1);}{fun_var($4,1);fun_var($6,2);fun_var($8,3);}
	  BLOCK_FUN{ functionFinished(3,$2);}PGM |
 TYPE ID OpenParenthesis ID Comma ID Comma ID Comma ID  CloseParenthesis 
 	 {declare_Function($2,4,$1);}{fun_var($4,1);fun_var($6,2);fun_var($8,3);fun_var($10,4);}
	  BLOCK_FUN{ functionFinished(4,$2);}PGM |
  /*nothing!*/{}
 ;
STMTS:
 STMT STMTS | {}
 //| CloseBrace {myerror("} is extra!!",21);yyerrok;} 
 ;
STMT:
 matched
 | unmatched
;
other_statement:
 STMT_DECLARE | 
 STMT_ASSIGN |
 STMT_RETURN|
// STMT_CONDITIONAL|
 STMT_WHILE|
 STMT_FOR|
 Semicolon{semantic_stack.top();}
;
STMT_WHILE:
 whileKeyWord OpenParenthesis{push(pb.size());} EXP CloseParenthesis {save();} BLOCK {whileJump();}

;
/*
ONLY_ONE_STMT:
 ID OperatorAssign EXP { assignto($1);}
 | ID OperatorPP {plusPlus($1,1);}
 | ID OperatorMM {plusPlus($1,-1);}
 | EXP {pb.push_back("lw $v1, 0($sp)");pb.push_back("addi $sp, $sp,4");warning("useless epression!");} // pop use less result!!
 | {pb.push_back("NOP");}
;
*/
STMT_FOR:
 forKeyWord OpenParenthesis STMT_DECLARE {push(pb.size());} EXP Semicolon 
 {	
	 save();
	 pb.push_back("");
 }/*ONLY_ONE_STMT*/EXP
 {
	 pb.push_back("lw $v1, 0($sp)");pb.push_back("addi $sp, $sp,4");	

	 int a=pop();
	 pb[a+1]="j a"+to_string(pb.size()+2);
	 instJump.push(pb.size()+2);
	 int b=pop()+1;
	 pb.push_back("j a"+to_string(b));
	 instJump.push(b);
	 push(a);
  }  CloseParenthesis BLOCK
  {forJump();}
  | forKeyWord OpenParenthesis STMT_ASSIGN {push(pb.size());} EXP Semicolon 
 {	
	 save();
	 pb.push_back("");
 }EXP
 {
	 pb.push_back("lw $v1, 0($sp)");pb.push_back("addi $sp, $sp,4");	

	 int a=pop();
	 pb[a+1]="j a"+to_string(pb.size()+2);
	 instJump.push(pb.size()+2);
	 int b=pop()+1;
	 pb.push_back("j a"+to_string(b));
	 instJump.push(b);
	 push(a);
  }  CloseParenthesis BLOCK
  {forJump();}
  
;
/*
STMT_CONDITIONAL:

 IF OpenBrace STMTS CloseBrace {pb[pop()]="beq $s0,$zero, a"+to_string(pb.size()+1);instJump.push(pb.size()+1);}
 | IF OpenBrace STMTS CloseBrace elseKeyWord {saveJump();} OpenBrace STMTS CloseBrace{saveJump();}
 
;
*/
matched:
  IF_ELSE matched{jump();}
  |other_statement
;

unmatched:
  IF STMT {
	  pb[pop()]="beq $s0,$zero, a"+to_string(pb.size()+1);
	  instJump.push(pb.size()+1);
  }
  |IF BLOCK{
	  pb[pop()]="beq $s0,$zero, a"+to_string(pb.size()+1);
	  instJump.push(pb.size()+1);
  }
  |IF_ELSE unmatched{jump();}
  |IF_ELSE BLOCK {jump();}
;
IF_ELSE:
	IF matched elseKeyWord {saveJump();}
	| IF BLOCK elseKeyWord {saveJump();}
;
IF:
	ifKeyWord OpenParenthesis EXP CloseParenthesis {save();}
;
BLOCK:
  BLOCK_L CloseBrace{lastScope_BLOCK=lastScope;removeLocal();localCount--;}
 | BLOCK_L error {myerror("} is missing!!",21);lastScope_BLOCK=lastScope;removeLocal();localCount--;} CloseBrace
;
BLOCK_FUN:
  OpenBrace  STMTS CloseBrace
 | OpenBrace STMTS error {myerror("} is missing!!",21);} CloseBrace
;
BLOCK_L:
OpenBrace {lastScope_BLOCK="BLK";localCount++;} STMTS
;


EXP:
  TERM9 {
	  char tmp[500];
	  $$ = ($1);
	  
      //$$=getFree();
	  //pb.push_back("lw $s0,0($sp)");
	  //pb.push_back("laddi $sp,$sp,4");
	  //sprintf(tmp,"sw $s0,%llu($gp)",$$);
	  //pb.push_back(tmp);

	  
	  }
;

TERM9:
 TERM8 BinaryOR TERM8 
  {
	//$$ = ($1)||($3);	 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4");

	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4");  
	
	pb.push_back("bne $s0,$zero,BinaryOR_True"+to_string(labelCnt)); //age sefr nabood boro be true
	
	pb.push_back("bne $s1,$zero,BinaryOR_True"+to_string(labelCnt)); //age sefr nabood boro be true
	//age false shod
	pb.push_back("li $s0,0");  
	pb.push_back("j BinaryOR_write"+to_string(labelCnt));  
	
	//age true shod
	pb.push_back("BinaryOR_True"+to_string(labelCnt)+": li $s0,1");  
	 
	 
	pb.push_back("BinaryOR_write"+to_string(labelCnt++)+": addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	
 }
 | TERM8 {$$ = ($1);}
;

TERM8:
 TERM7 BinaryAnd TERM7
 {
	//$$ = ($1)&&($3);	 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 

			 					 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("beq $s0,$zero,BinaryAnd_False"+to_string(labelCnt)); //age sefr bood boro be false
	
	
	pb.push_back("beq $s1,$zero,BinaryAnd_False"+to_string(labelCnt)); //age sefr bood boro be false
	
	//age hardo sefr naboodan yani javab true mishod					 
	
	 
	pb.push_back("li $s0,1");  
	pb.push_back("j BinaryAnd_write"+to_string(labelCnt));  
	
	//age true shod
	pb.push_back("BinaryAnd_False"+to_string(labelCnt)+": li $s0,0");  
	 
	 
	pb.push_back("BinaryAnd_write"+to_string(labelCnt++)+": addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	
 }
 | TERM7 {$$ = ($1);}
;
TERM7:
 TERM6 OperatorOR TERM6
  {
	//$$ = ($1) | ($3); 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("or $s2,$s1,$s0"); 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
 }
 | TERM6 {$$ = ($1);}
 
;

TERM6:
 TERM5 OperatorXOR TERM5
  {
	//$$ = ($1)^($3); 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("xor $s2,$s1,$s0"); 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
 }
 | TERM5 {$$ = ($1);}
;
TERM5:
 TERM4 OperatorAnd TERM4
 {
	//$$ = ($1)&($3); 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("and $s2,$s1,$s0"); 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
 }
 | TERM4 {$$ = ($1);}
;

TERM4:
 TERM3 OperatorEqual TERM3 
 {
	//$$ = ($1)==($3);
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("beq $s0,$s1,OperatorEqual_true"+to_string(labelCnt)); 
	
	//age false bood
	pb.push_back("li $s0, 0"); 
	pb.push_back("j OperatorEqual_write"+to_string(labelCnt)); 
	
	//true bood
	pb.push_back("OperatorEqual_true"+to_string(labelCnt)+": li $s0, 1"); 
	pb.push_back("OperatorEqual_write"+to_string(labelCnt++)+": addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	
 }
 | TERM3 OperatorNotEqual TERM3
  {
	//$$ = ($1)!=($3);
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("bne $s0,$s1,OperatorNotEqual_true"+to_string(labelCnt)); 
	
	//age false bood
	pb.push_back("li $s0, 0"); 
	pb.push_back("j OperatorNotEqual_write"+to_string(labelCnt)); 
	
	//true bood
	pb.push_back("OperatorNotEqual_true"+to_string(labelCnt)+": li $s0, 1"); 
	pb.push_back("OperatorNotEqual_write"+to_string(labelCnt++)+": addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	
 }
 |TERM3 {$$= ($1);}
;

TERM3:
 TERM2 OperatorSmall TERM2
 {							//    s1 < s0
	//$$ = ($1)<($3); 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	 //blt $t0, $t4, VIP_LESS  # if $t0 < $t4 then VIP
	pb.push_back("slt $s0,$s1, $s0");  
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 

	/*
	pb.push_back("blt $s1, $s0,OperatorSmall_true"+to_string(labelCnt)); 
	
	//age false bood
	pb.push_back("li $s0, 0"); 
	pb.push_back("j OperatorSmall_write"+to_string(labelCnt)); 
	
	//true bood
	pb.push_back("OperatorSmall_true"+to_string(labelCnt)+": li $s0, 1"); 
	pb.push_back("OperatorSmall_write"+to_string(labelCnt++)+": addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	*/
 }
	 
 | TERM2 OperatorSmallEqual TERM2
 {								//          s1  > s0 => false
								//          s0  < s1 => false
    //$$ = ($1)<=($3);	 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 

	pb.push_back("slt $s0,$s0, $s1");  
	pb.push_back("neg $s0,$s0");  
	pb.push_back("addi $s0,$s0,1");  

	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 

	/*
	 //blt $t0, $t4, VIP_LESS  # if $t0 < $t4 then VIP
	pb.push_back("blt $s0, $s1,OperatorSmallEqual_false"+to_string(labelCnt)); 
	
	//age true bood
	pb.push_back("li $s0, 1"); 
	pb.push_back("j OperatorSmallEqual_write"+to_string(labelCnt)); 
	
	//false bood
	pb.push_back("OperatorSmallEqual_false"+to_string(labelCnt)+": li $s0, 0"); 
	pb.push_back("OperatorSmallEqual_write"+to_string(labelCnt++)+": addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 

	*/
	
 }
 | TERM2 OperatorBig TERM2
  {						   // 		 s1 > s0
  						   // 		 s0 < s1
    //$$ = ($1)>($3);	 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	 //blt $t0, $t4, VIP_LESS  # if $t0 < $t4 then VIP
	
	pb.push_back("slt $s0,$s0, $s1");  
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	
	/*pb.push_back("blt $s0, $s1,OperatorBig_true"+to_string(labelCnt)); 
	
	//age false bood
	pb.push_back("li $s0, 0"); 
	pb.push_back("j OperatorBig_write"+to_string(labelCnt)); 
	
	//true bood
	pb.push_back("OperatorBig_true"+to_string(labelCnt)+": li $s0, 1"); 
	pb.push_back("OperatorBig_write"+to_string(labelCnt++)+": addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); */
	
 }
 | TERM2 OperatorBigEqual TERM2
 {								//          s1  < s0 => false
								 
	//$$ = ($1)>=($3);
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 


	pb.push_back("slt $s0,$s1, $s0");  
	pb.push_back("neg $s0,$s0");  
	pb.push_back("addi $s0,$s0,1");  

	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 

	/*
	 //blt $t0, $t4, VIP_LESS  # if $t0 < $t4 then VIP
	pb.push_back("blt $s1, $s0,OperatorBigEqual_false"+to_string(labelCnt)); 
	
	//age true bood
	pb.push_back("li $s0, 1"); 
	pb.push_back("j OperatorBigEqual_write"+to_string(labelCnt)); 
	
	//false bood
	pb.push_back("OperatorBigEqual_false"+to_string(labelCnt)+": li $s0, 0"); 
	pb.push_back("OperatorBigEqual_write"+to_string(labelCnt++)+": addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	*/
 }
 | TERM2 {$$ = ($1);}
 
;
 
TERM2:
 TERM OperatorAdd TERM
  {
	$$ = ($1) + ($3); 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("add $s2,$s1,$s0"); 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
 }
 | TERM OperatorMinus TERM
  {								//    s1     s0
	$$ = ($1) - ($3);
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("sub $s2,$s1,$s0"); 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
 }
 | TERM {$$= ($1);}
;
 
TERM:
 FACTOR OperatorMult FACTOR
 {								//    s1     s0
	$$ = ($1) * ($3);
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("mul $s2,$s1,$s0"); 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
 }
 | FACTOR OperatorDiv FACTOR
 {								  //    s1     s0

	if($3==0)
	{
		myerror("divide by zero error!!",100);
		
	}
 	$$ = ($1) / ($3);
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("bne $s0,$zero,skip"+to_string(labelCnt));
	pb.push_back("li $v0,4");
	pb.push_back("la $a0,err_string");
	pb.push_back("syscall");
	pb.push_back("li $v0, 10");
	pb.push_back("syscall");
	pb.push_back("skip"+to_string(labelCnt++)+":lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("div $s1,$s0"); 
	pb.push_back("mflo $s2"); 
	 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
 }
 | FACTOR {$$ = ($1);}
;

FACTOR:

 NUM {
	 $$ = $1;
	 char tmp[500];
	 //sprintf(tmp,"movl $%d, %%eax",$1);
	 sprintf(tmp,"li $s0 , %d",$1);
	 pb.push_back(string(tmp));
	 pb.push_back("addi $sp,$sp,-4");
	 pb.push_back("sw $s0,0($sp)");
	 }
 | OperatorMinus FACTOR
   {								//   
    $$ = -($2);
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("li $s1,-1"); 
	
	
	pb.push_back("mul $s2,$s1,$s0"); 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
   }
   | UnaryNot FACTOR
   {								//   
	$$ = ~($2);
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	 
	
	pb.push_back("not $s2,$s0"); 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
    }
    | BinaryNot FACTOR
    {								//   
	$$ = !($2);
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("beq $s0,$zero,BinaryNot_return"+to_string(labelCnt)); 
	pb.push_back("li $s2,0"); 
	
	pb.push_back("j BinaryNot_save"+to_string(labelCnt)); 
	
	pb.push_back("BinaryNot_return"+to_string(labelCnt)+" : li $s2,1"); 
	
	
	
	pb.push_back("BinaryNot_save"+to_string(labelCnt++)+": addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
    }
    | OpenParenthesis EXP CloseParenthesis
	 {
		$$ = $2;
		 //not thing
	 }
	|ID 
	{
		$$ = 123; 
		char temp[500];
		if(symbolTable[$1].TYPE != SEM_TYPE_VARIABLE_INT)
		{
			sprintf(temp,"variable \"%s\" has not been declared properly!",$1);
			
        	myerror(temp,10);
			
		}
		if(symbolTable[$1].scope==0)
		{
			pb.push_back("li $s1,0");
		}else
			pb.push_back("lw $s1,"+to_string(DYNAMIC_OFFSET_LOC)+"($gp)");
		pb.push_back("addi $s2,$s1,"+to_string(symbolTable[$1].address));
		pb.push_back("add $s2,$s2,$gp");
		pb.push_back("lw $s0,0($s2)");
		//sprintf(temp,"lw $s0,%llu($gp)",symbolTable[$1].address);
		//pb.push_back(temp);
		pb.push_back("addi $sp, $sp,-4"); 
		pb.push_back("sw $s0,0($sp)");
		
	}
	| ID OpenBracket EXP CloseBracket {
		$$ = 123; 
		char temp[500];
		if(symbolTable[$1].TYPE != SEM_TYPE_VARIABLE_ARRAY_INT)
		{
			sprintf(temp,"variable \"%s\" has not been declared properly!",$1);
        	myerror(temp,10);
		}
		pb.push_back("lw $s0,0($sp)");
		pb.push_back("addi $sp, $sp,4"); 

		pb.push_back("li $s4, 4"); //4
		pb.push_back("mul $s0,$s0, $s4");

		pb.push_back("add $s1,$s0,$gp");

		pb.push_back("lw $s0,"+to_string(symbolTable[$1].address)+"($s1)");


		pb.push_back("addi $sp, $sp,-4"); 
		pb.push_back("sw $s0,0($sp)");
	}
	| ID OperatorPP {$$=-10;plusPlus($1,1,1);}
	| ID OperatorMM {$$=-10;plusPlus($1,-1,1);}
	| ID OpenBracket EXP CloseBracket OperatorPP{$$=-10;plusPlusar($1,1,1);}
	| ID OpenBracket EXP CloseBracket OperatorMM{$$=-10;plusPlusar($1,-1,1);}
	| EXP_FUNCTIONCALL{};
;

STMT_DECLARE:
STMT_DECLARE_L Semicolon
|STMT_DECLARE_L error {myerror("error after declaration!",30);}
 //IntKeyWord ID {declare_IntVariable($2);} IDS Semicolon
 //|IntKeyWord ID {declare_IntVariable($2);} IDS error {myerror("; after variable declaration is missed!",20);}

 |IntKeyWord ID OpenBracket NUM CloseBracket {declare_IntArray($2,$4);}  Semicolon
 |IntKeyWord ID OpenBracket NUM CloseBracket  error {myerror("; after array declaration is missed!",20);}
 |STMT_DECLARE_ASSL Semicolon
 |STMT_DECLARE_ASSL error {myerror("; after array declaration is missed!",20);}
;
STMT_DECLARE_ASSL:
IntKeyWord ID {declare_IntVariable($2);} OperatorAssign EXP  {assignto($2);}
;
STMT_DECLARE_L:
IntKeyWord ID {declare_IntVariable($2);} IDS
;

EXP_FUNCTIONCALL:
 ID OpenParenthesis  CloseParenthesis {$$=functionCall($1,0);}
 | ID OpenParenthesis EXP CloseParenthesis {$$=functionCall($1,1,$3);}
 | ID OpenParenthesis EXP Comma EXP CloseParenthesis  {$$=functionCall($1,2,$3,$5);}
 | ID OpenParenthesis EXP Comma EXP Comma EXP CloseParenthesis  {$$=functionCall($1,3,$3,$5,$7);}
 | ID OpenParenthesis EXP Comma EXP Comma EXP Comma EXP CloseParenthesis  {$$=functionCall($1,4,$3,$5,$7,$9);}
 
;
IDS:
  {} |
 Comma ID {declare_IntVariable($2);} IDS 
;
STMT_ASSIGN:

 ID OperatorAssign EXP Semicolon { assignto($1);}
 | ID OperatorAssign EXP error { myerror("; after assignment is missed!",20);}
 | ID OpenBracket EXP CloseBracket OperatorAssign EXP Semicolon { assigntoar($1);}
 | ID OpenBracket EXP CloseBracket OperatorAssign EXP error{ myerror("; after assinment is missed!",20);}
 //| ID OperatorPP  Semicolon {plusPlus($1,1);}
 //| ID OperatorMM  Semicolon {plusPlus($1,-1);}
 | EXP Semicolon 
 {
	pb.push_back("lw $v1, 0($sp)");
	pb.push_back("addi $sp, $sp,4");
	if($1!=-10)
		warning("useless epression!");
  } // pop useless result!!
  | EXP error {myerror("; is missed!",20);}
 
;
STMT_RETURN:
 returnKeyWord EXP Semicolon{returnHandle(lastScope);}
 |returnKeyWord Semicolon{voidReturn(lastScope);}
 | returnKeyWord error {myerror("probably ; is missed after return",20);}
;
TYPE:
 IntKeyWord {strcpy($$,"int"); }
 |VoidKeyWord {strcpy($$,"void");}
;
%%


void yyerror(const char *s) {
 fprintf(stderr, "%s\n", s);
}
void help()
{
	printf("compiler help!\n\n\tenjoy own compiler!\n\n");
			cout<<"\tfirst argument is source file path\n";
			cout<<"\t--show enable some log in each compile step\n";
			cout<<"\t--pre first pre process the source then compile it"<<endl;
			cout<<"\t--def enable define output for processor"<<endl;
			cout<<"\t-p name of preProcessor c source output"<<endl;
			cout<<"\t-o name of mips code output"<<endl;
			cout<<"\t-h show help(this page!)"<<endl;

}
int main(int argc, char *argv[])
{
	char cmd[100];
	char def[10];
	strcpy(def," NoDef");
	pre=0;
	out=0;
	mid=0;
	if(argc<=1)
	{
		help();
		return(0);
	}
	for(int i=2;i<argc;i++)
	{
		if(strcmp("--show",argv[i])==0)
		{
			verbose=1;
		}
		if(strcmp("--pre",argv[i])==0)
		{
			pre=1;
		}
		if(strcmp("-o",argv[i])==0 && (i+1<argc))
		{
			out=i+1;
		}
		if(strcmp("-p",argv[i])==0 && (i+1<argc))
		{
			mid=i+1;
		}
		if(strcmp("--def",argv[i])==0)
		{
			def[0]=0;
		}
		if(strcmp("-h",argv[i])==0)
		{
			help();
			return(0);
		}
		
	}
	if(pre)
	{
		if(mid)
		{
			sprintf(cmd,"./pre %s %s %s",argv[1],argv[mid],def);
		}else
			sprintf(cmd,"./pre %s output_pre.c %s",argv[1],def);
		system(cmd);
		if(mid)
			yyin = fopen(argv[mid], "r");
		else
			yyin = fopen("output_pre.c", "r");
	}else
		yyin = fopen(argv[1], "r");
	if(out)
	{
		f1=fopen(argv[out],"w");
	}else
		f1=fopen("output.mips","w");

	/* print built in function*/
	Node tmp=Node();
    tmp.address=-10;
    tmp.scope=-1;
	tmp.numOfArguments=1;
	tmp.TYPE=SEM_TYPE_FUNCTION_VOID;
	tmp.output=1;
    symbolTable["print"]=tmp;
	tmp.numOfArguments=0;
	tmp.TYPE=SEM_TYPE_FUNCTION_INT;
	symbolTable["scan"]=tmp;
	/**/

	/*initial codes */

	pb.push_back(".data");
    pb.push_back("err_string: .asciiz \"\\ndivide by zero error!\\n\"");
    pb.push_back("nextline_string: .asciiz \"\\n\"");
    pb.push_back(".text");
	/*pb.push_back("li $s0, 200");
	pb.push_back("sw $s0, 100($gp)");*/
	pb.push_back("li $s0, 0");
	pb.push_back("sw $s0, "+to_string(DYNAMIC_OFFSET_LOC)+"($gp)");

	/*finished!!*/
    if(!yyparse())
		printf("\nParsing complete\n");
	else
	{
		myerror("\nParsing failed\n",1);
	}
	int return_address;
	if(PC!=0)
	{
		return_address=pop();
		pb[return_address]="li $s0,"+to_string(MAIN_OFFSET);
		pb[return_address+1]="sw $s0, "+to_string(DYNAMIC_OFFSET_LOC)+"($gp)";
		pb[return_address+2]="jal main";
		pb[return_address+3]="li $v0, 17";
		pb[return_address+4]="lw $a0, 0($sp)";
		pb[return_address+5]="addi $sp, $sp,4";
		pb[return_address+6]="syscall";
	}	
	else{
		myerror("main function Not Found!",4);
		
	}
	symbolTableShow();
	if(ERROR_occurred)
		return -1;
	while(!instJump.empty())
	{
		int top=instJump.top();
		string ap="a"+to_string(top)+":";
		
		if (pb[top-1].rfind(ap, 0) != 0) {
			pb[top-1]="a"+to_string(top)+": "+pb[top-1];
		}
		instJump.pop();
	}
	
	printf("MIPS CODE is saved in output file!\n");
	if(verbose)
		printf("Code:\n");
	for(int j=0;j<pb.size();j++)
	{
		fprintf(f1,"%s\n",pb[j].c_str());
		if(verbose)
			printf("%s\n",pb[j].c_str());
	}
    fprintf(f1,"\n");
    
	fclose(yyin);
	fclose(f1);
	
	cout<<"PC is: "<<PC<<endl;

	if(verbose)
	{
		cout<<"starting program:"<<endl;
		if(out)
		{
			sprintf(cmd,"spim  -file %s",argv[out]);
			system(cmd);
		}
		else
			system("spim  -file output.mips");
	}
	
    return 0;
}
