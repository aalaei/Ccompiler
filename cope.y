EXP:
 

 ;
 
TERM9:
 TERM9 BinaryOR TERM9 {$$ = ($1)||($3);}
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


