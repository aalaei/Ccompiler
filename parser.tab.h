/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    ifKeyWord = 259,
    elseKeyWord = 260,
    whileKeyWord = 261,
    forKeyWord = 262,
    OperatorPP = 263,
    OperatorMM = 264,
    VoidKeyWord = 265,
    IntKeyWord = 266,
    returnKeyWord = 267,
    OpenBrace = 268,
    CloseBrace = 269,
    OpenParenthesis = 270,
    CloseParenthesis = 271,
    Semicolon = 272,
    Comma = 273,
    OperatorSmallEqual = 274,
    OperatorSmall = 275,
    OperatorBigEqual = 276,
    OperatorBig = 277,
    OperatorNotEqual = 278,
    OperatorEqual = 279,
    OperatorAssign = 280,
    OperatorAdd = 281,
    OperatorMinus = 282,
    OperatorMult = 283,
    OperatorDiv = 284,
    OperatorOR = 285,
    OperatorAnd = 286,
    OperatorXOR = 287,
    BinaryOR = 288,
    BinaryAnd = 289,
    BinaryNot = 290,
    UnaryNot = 291,
    ID = 292,
    OpenBracket = 293,
    CloseBracket = 294
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 53 "parser.y" /* yacc.c:1909  */

	int iVal;
	char name[100];
	long long address;

#line 100 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
