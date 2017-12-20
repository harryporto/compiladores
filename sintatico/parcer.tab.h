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
    DIVISAO = 261,
    ABRE_PAREN = 262,
    FECHA_PAREN = 263,
    PONTO_VIRGULA = 264,
    MAIOR = 265,
    MAIOR_IGUAL = 266,
    MENOR = 267,
    MENOR_IGUAL = 268,
    IGUAL_IGUAL = 269,
    DIFERENTE_IGUAL = 270,
    AND = 271,
    OR = 272,
    NOT = 273,
    ABRE_CHAVE = 274,
    FECHA_CHAVE = 275,
    ABRE_COLCHETE = 276,
    FECHA_COLCHETE = 277,
    VIRGULA = 278,
    IGUAL = 279,
    ID = 280,
    DEC = 281,
    BREAK = 282,
    CONTINUE = 283,
    IF = 284,
    WHILE = 285,
    RETURN = 286,
    DEF = 287,
    ELSE = 288,
    LET = 289,
    UNA = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 21 "parcer.y" /* yacc.c:1909  */

  char valor[100];
  int inteiro;

#line 95 "parcer.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARCER_TAB_H_INCLUDED  */
