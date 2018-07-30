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

#ifndef YY_YY_PARCER_TAB_H_INCLUDED
# define YY_YY_PARCER_TAB_H_INCLUDED
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
    MAIS = 258,
    MENOS = 259,
    VEZES = 260,
    DIV = 261,
    ABRE_PAR = 262,
    FECHA_PAR = 263,
    MAIOR = 264,
    MAIOR_IGUAL = 265,
    MENOR = 266,
    MENOR_IGUAL = 267,
    IGUAL_IGUAL = 268,
    DIFERENTE = 269,
    ABRE_CHA = 270,
    FECHA_CHA = 271,
    ABRE_COL = 272,
    FECHA_COL = 273,
    VIRG = 274,
    PVIRG = 275,
    IGUAL = 276,
    ID = 277,
    NUM = 278,
    IF = 279,
    INT = 280,
    WHILE = 281,
    RETURN = 282,
    ELSE = 283,
    VOID = 284,
    P = 285,
    D = 286,
    LD = 287,
    C = 288,
    AR = 289,
    SL = 290,
    PVIRGs = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 28 "parcer.y" /* yacc.c:1909  */

  char valor[100];
  int inteiro;
  noAst *ast;

#line 97 "parcer.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARCER_TAB_H_INCLUDED  */
