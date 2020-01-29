all: compiler

parser.tab.c parser.tab.h:	parser.y
	bison -d parser.y

lex.yy.c: lexer.l parser.tab.h
	flex lexer.l

compiler: lex.yy.c parser.tab.c parser.tab.h
	gcc -o compiler parser.tab.c lex.yy.c -lm

clean:
	rm compiler parser.tab.c lex.yy.c parser.tab.h
