
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
     T_HEX = 261,
     T_STR = 262,
     T_BOOLT = 263,
     T_BOOLF = 264,
     T_ID = 265,
     T_PLUS = 266,
     T_MINUS = 267,
     T_MUL = 268,
     T_DIV = 269,
     T_MOD = 270,
     T_DIV2 = 271,
     T_MANJE = 272,
     T_VISE = 273,
     T_JEDNAKO = 274,
     T_MANJEJEDNAKO = 275,
     T_VISEJEDNAKO = 276,
     T_JEJEDNAKO = 277,
     T_RAZLICITO = 278,
     T_AND = 279,
     T_OR = 280,
     T_NEGACIJA = 281,
     T_ZAREZ = 282,
     T_TACKA = 283,
     T_LEFTP = 284,
     T_RIGHTP = 285,
     T_FOR = 286,
     T_WHILE = 287,
     T_BREAK = 288,
     T_IF = 289,
     T_ELSE = 290,
     T_INTID = 291,
     T_STRID = 292,
     T_BOOLID = 293,
     T_DOUBLEID = 294,
     T_RETURN = 295,
     T_DO = 296,
     T_END = 297,
     T_EQ = 298
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
    long hex_value;
    bool bool_value;
    char* ident;



/* Line 1676 of yacc.c  */
#line 106 "pmf0.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


