
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
     T_BOOLT = 264,
     T_BOOLF = 265,
     T_ID = 266,
     T_INTID = 267,
     T_BOOLID = 268,
     T_STRID = 269,
     T_DOUBLEID = 270,
     T_PLUS = 271,
     T_MINUS = 272,
     T_MUL = 273,
     T_DIV = 274,
     T_MOD = 275,
     T_DIV2 = 276,
     T_MANJE = 277,
     T_VISE = 278,
     T_JEDNAKO = 279,
     T_MANJEJEDNAKO = 280,
     T_VISEJEDNAKO = 281,
     T_JEJEDNAKO = 282,
     T_RAZLICITO = 283,
     T_AND = 284,
     T_OR = 285,
     T_NEGACIJA = 286,
     T_ZAREZ = 287,
     T_TACKA = 288,
     T_LEFTP = 289,
     T_RIGHTP = 290,
     T_FOR = 291,
     T_WHILE = 292,
     T_BREAK = 293,
     T_IF = 294,
     T_ELSE = 295,
     T_RETURN = 296,
     T_DO = 297,
     T_END = 298,
     T_EQ = 299
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 53 "pmf0.y"

    int int_value;
    char* string_value;
    double double_value;
    double double_exp;
    int hex_value;
    bool bool_value;
    char* ident;



/* Line 1676 of yacc.c  */
#line 108 "pmf0.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


