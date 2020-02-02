
%{
 
 #include <iostream> 
 

 using namespace std;
 static long long Cur_Mem_tmp=100;
 bool verbose;
 int yylineNum=0;
 string lastScope;

 void yyerror(const char* error);
 void error(const char * error)
 {
	 char temp[500];
	 sprintf(temp,"error :\n\t%s\n> line number: #%d",error,yylineNum+1);
	 yyerror(temp);
 }
 void warning(const char * warn)
 {
	 printf("warning :\n\t%s\n> line number: #%d",warn,yylineNum+1);
 }
 
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

%type <name> STMT_DECLARE PGM TYPE STMT_WHILE STMT_FOR
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


%%
PROGRAM:
 STMT_DECLARE {makeGolobal(); } PGM 
 ;
PGM:
 TYPE ID OpenParenthesis CloseParenthesis 
 	 {declare_Function($2,0,$1);}
	  OpenBrace STMTS CloseBrace{ functionFinished(0,$2);} PGM |
 TYPE ID OpenParenthesis ID CloseParenthesis 
 	 {declare_Function($2,1,$1);}{fun_var($4,1);}
	  OpenBrace STMTS CloseBrace{ functionFinished(1,$2);} PGM |
 TYPE ID OpenParenthesis ID Comma ID CloseParenthesis 
 	 {declare_Function($2,2,$1);}{fun_var($4,1);fun_var($6,2);}
	  OpenBrace STMTS CloseBrace{ functionFinished(2,$2);}PGM |
 TYPE ID OpenParenthesis ID Comma ID Comma ID CloseParenthesis 
 	 {declare_Function($2,3,$1);}{fun_var($4,1);fun_var($6,2);fun_var($8,3);}
	  OpenBrace STMTS CloseBrace { functionFinished(3,$2);}PGM |
 TYPE ID OpenParenthesis ID Comma ID Comma ID Comma ID  CloseParenthesis 
 	 {declare_Function($2,4,$1);}{fun_var($4,1);fun_var($6,2);fun_var($8,3);fun_var($10,4);}
	  OpenBrace STMTS CloseBrace { functionFinished(4,$2);}PGM |
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
// STMT_CONDITIONAL|
 STMT_WHILE|
 STMT_FOR|
 Semicolon{semantic_stack.top();}
;
STMT_WHILE:
 whileKeyWord OpenParenthesis{push(pb.size());} EXP CloseParenthesis {save();} OpenBrace STMTS CloseBrace {whileJump();}

;
ONLY_ONE_STMT:
 ID OperatorAssign EXP { assignto($1);}
 | ID OperatorPP {plusPlus($1,1);}
 | ID OperatorMM {plusPlus($1,-1);}
 | EXP {pb.push_back("lw $v1, 0($sp)");pb.push_back("addi $sp, $sp,4");warning("useless epression!");} // pop use less result!!
 | {pb.push_back("NOP");}
;
STMT_FOR:
 forKeyWord OpenParenthesis STMT_DECLARE {push(pb.size());} EXP Semicolon {save();pb.push_back("");}ONLY_ONE_STMT{int a=pop();pb[a+1]="j "+to_string(pb.size()+2);pb.push_back("j "+to_string(pop()+1));push(a);}  CloseParenthesis OpenBrace STMTS CloseBrace
  {forJump();}

;
/*
STMT_CONDITIONAL:

 IF OpenBrace STMTS CloseBrace {pb[pop()]="be $s0,$zero, "+to_string(pb.size()+1);}
 | IF OpenBrace STMTS CloseBrace elseKeyWord {saveJump();} OpenBrace STMTS CloseBrace{saveJump();}
 
;
*/
matched:
  IF_ELSE matched{jump();}
  |other_statement
;

unmatched:
  IF STMT {
	  pb[pop()]="be $s0,$zero, "+to_string(pb.size()+1);
  }
  |IF BLOCK{
	  pb[pop()]="be $s0,$zero, "+to_string(pb.size()+1);
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
BLOCK :
 OpenBrace STMTS CloseBrace
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
	
	pb.push_back("bne $s0,$zero,BinaryOR_True"); //age sefr nabood boro be true
	
						 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("bne $s0,$zero,BinaryOR_True"); //age sefr nabood boro be true
	//age false shod
	pb.push_back("li $s0,0");  
	pb.push_back("j BinaryOR_write");  
	
	//age true shod
	pb.push_back("BinaryOR_True: li $s0,1");  
	 
	 
	pb.push_back("BinaryOR_write: addi $sp, $sp,-4"); 
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
	
	pb.push_back("beq $s0,$s1,OperatorEqual_true"); 
	
	//age false bood
	pb.push_back("li $s0, 0"); 
	pb.push_back("j OperatorEqual_write"); 
	
	//true bood
	pb.push_back("OperatorEqual_true: li $s0, 1"); 
	pb.push_back("OperatorEqual_write: addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	
 }
 | TERM3 OperatorNotEqual TERM3
  {
	//$$ = ($1)!=($3);
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
	pb.push_back("blt $s1, $s0,OperatorSmall_true"); 
	
	//age false bood
	pb.push_back("li $s0, 0"); 
	pb.push_back("j OperatorSmall_write"); 
	
	//true bood
	pb.push_back("OperatorSmall_true: li $s0, 1"); 
	pb.push_back("OperatorSmall_write: addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	
 }
	 
 | TERM2 OperatorSmallEqual TERM2
 {								//          s1  > s0 => false
								//          s0  < s1 => false
    //$$ = ($1)<=($3);	 					 
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
 | TERM2 OperatorBig TERM2
  {						   // 		 s1 > s0
  						   // 		 s0 < s1
    //$$ = ($1)>($3);	 					 
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
 | TERM2 OperatorBigEqual TERM2
 {								//          s1  < s0 => false
								 
	//$$ = ($1)>=($3);
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
	//????????????????????????????????????
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
 }
 | FACTOR OperatorDiv FACTOR
 {								  //    s1     s0

	if($3==0)
	{
		error("divide by zero error!!");
		exit(-100);
	}
 	$$ = ($1) / ($3);
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("bne $s0,$zero,skip");
	pb.push_back("li $v0,4");
	pb.push_back("la $a0,err_string");
	pb.push_back("syscall");
	pb.push_back("li $v0, 10");
	pb.push_back("syscall");
	pb.push_back("skip:lw $s1, 0($sp)"); 
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
	
						 
	pb.push_back("beq $s0,$zero,BinaryNot_return1"); 
	pb.push_back("li $s2,0"); 
	
	pb.push_back("j BinaryNot_save"); 
	
	pb.push_back("BinaryNot_return1 : li $s2,1"); 
	
	
	
	pb.push_back("BinaryNot_save: addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
    }
    | OpenParenthesis EXP CloseParenthesis
	 {
		$$ = $2;
		 //not thing
	 }
	| ID 
	{
		$$ = 123; 
		char temp[500];
		if(symbolTable[$1].TYPE != SEM_TYPE_VARIABLE_INT)
		{
			error("variable has not been declared properly!");
			exit(-10);
		}
		sprintf(temp,"lw $s0,%llu($gp)",symbolTable[$1].address);
		pb.push_back(temp);
		pb.push_back("addi $sp, $sp,-4"); 
		pb.push_back("sw $s0,0($sp)");
	}
	| EXP_FUNCTIONCALL{};
;
STMT_DECLARE:
 IntKeyWord ID {declare_IntVariable($2);} IDS Semicolon
 |IntKeyWord ID {declare_IntVariable($2);} OperatorAssign EXP Semicolon {assignto($2);}
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
 | ID OperatorPP  Semicolon {plusPlus($1,1);}
 | ID OperatorMM  Semicolon {plusPlus($1,-1);}
 | EXP Semicolon {pb.push_back("lw $v1, 0($sp)");pb.push_back("addi $sp, $sp,4");warning("useless epression!");} // pop use less result!!
 
;
STMT_RETURN:
 returnKeyWord EXP Semicolon{returnHandle();}
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
	f1=fopen("output.mips","w");
	if(argc>2 && strcmp("--show",argv[2])==0)
		verbose=1;

    if(!yyparse())
		printf("\nParsing complete\n");
	else
	{
		printf("\nParsing failed\n");
		exit(-1);
	}
	int return_address;
	if(PC!=0)
	{
		return_address=pop();
		pb[return_address]="jal main";
		pb[return_address+1]="li $v0, 10";
		pb[return_address+2]="syscall";
	}	
	else{
		error("main function Not Found!");
		exit(-4);
	}
	printf("MIPS CODE is saves in output file!\n");
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
	symbolTableShow();
	cout<<"PC is: "<<PC<<endl;
	
    return 0;
}
