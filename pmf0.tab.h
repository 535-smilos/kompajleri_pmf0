
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_SC = 258,
     T_INT = 259,
     T_DOUBLE = 260,
     T_DBLEXP = 261,
     T_HEX = 262,
     T_STR = 263,
     T_ID = 264,
     INT_ID = 265,
     STR_ID = 266,
     BOOL_ID = 267,
     HEX_ID = 268,
     DOUBLE_ID = 269,
     T_DODJELA = 270,
     T_PLUS = 271,
     T_MINUS = 272,
     T_MUL = 273,
     T_DIV = 274,
     T_MOD = 275,
     T_LESS = 276,
     T_GREAT = 277,
     T_LEQ = 278,
     T_GEQ = 279,
     T_ISEQ = 280,
     T_NOTEQ = 281,
     T_AND = 282,
     T_OR = 283,
     T_NOT = 284,
     T_ZAREZ = 285,
     T_TACKA = 286,
     T_LEFTP = 287,
     T_RIGHTP = 288,
     T_FOR = 289,
     T_WHILE = 290,
     T_BREAK = 291,
     T_IF = 292,
     T_ELSE = 293,
     T_THEN = 294,
     T_RETURN = 295,
     T_FI = 296,
     T_DO = 297,
     T_END = 298,
     T_EQ = 299,
     T_SKIP = 300,
     T_LET = 301,
     T_READ = 302,
     T_WRITE = 303,
     T_IN = 304,
     T_TO = 305,
     T_BOOL = 306,
     T_TRUE = 307,
     T_FALSE = 308
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 10 "pmf0.y"

    int int_value;
    char* string_value;
    double double_value;
    double double_exp;
    int hex_value;
    char* ident;
    BCF *cvor;



/* Line 1676 of yacc.c  */
#line 117 "pmf0.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


