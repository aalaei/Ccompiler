all: pre

preParser.tab.c preParser.tab.h:	preParser.y
	bison -d preParser.y

lex.yy.c: preLexer.l preParser.tab.h
	flex preLexer.l

pre: lex.yy.c preParser.tab.c preParser.tab.h
	g++ -o pre preParser.tab.c lex.yy.c -lm

clean:
	rm pre preParser.tab.c lex.yy.c preParser.tab.h
