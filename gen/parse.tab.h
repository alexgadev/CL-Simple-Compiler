/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_GEN_PARSE_TAB_H_INCLUDED
# define YY_YY_GEN_PARSE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_INT = 258,                   /* T_INT  */
    T_FLOAT = 259,                 /* T_FLOAT  */
    T_STRING = 260,                /* T_STRING  */
    T_IDEN = 261,                  /* T_IDEN  */
    T_BOOL = 262,                  /* T_BOOL  */
    ASSIG = 263,                   /* ASSIG  */
    SYM_OB = 264,                  /* SYM_OB  */
    SYM_CB = 265,                  /* SYM_CB  */
    OP_ADD = 266,                  /* OP_ADD  */
    OP_SUB = 267,                  /* OP_SUB  */
    OP_MUL = 268,                  /* OP_MUL  */
    OP_DIV = 269,                  /* OP_DIV  */
    OP_MOD = 270,                  /* OP_MOD  */
    OP_POW = 271,                  /* OP_POW  */
    OP_LT = 272,                   /* OP_LT  */
    OP_LE = 273,                   /* OP_LE  */
    OP_GT = 274,                   /* OP_GT  */
    OP_GE = 275,                   /* OP_GE  */
    OP_EQ = 276,                   /* OP_EQ  */
    OP_INEQ = 277,                 /* OP_INEQ  */
    BOOL_OP_NOT = 278,             /* BOOL_OP_NOT  */
    BOOL_OP_AND = 279,             /* BOOL_OP_AND  */
    BOOL_OP_OR = 280,              /* BOOL_OP_OR  */
    CONST_PI = 281,                /* CONST_PI  */
    EOL = 282,                     /* EOL  */
    CMD_EXIT = 283                 /* CMD_EXIT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 39 "source/parse.y"

  //int type;
  atributs attrs;

#line 97 "gen/parse.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_GEN_PARSE_TAB_H_INCLUDED  */
