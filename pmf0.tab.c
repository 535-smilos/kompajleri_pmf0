
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "pmf0.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>

    struct Promjenljiva{
        char* id;
        int val;
        struct Promjenljiva* next;
    };

    void yyerror(const char* s);

    struct Promjenljiva* glava_tabele=0;

    void addNewNode(char* id, int val){
        struct Promjenljiva* new_node=(struct Promjenljiva*)malloc(sizeof(struct Promjenljiva));
        new_node->id=(char*)strdup(id);
        new_node->val=val;
        new_node->next=glava_tabele;
        glava_tabele=new_node;
    }

    struct Promjenljiva* findVariable(char* id){
        struct Promjenljiva* curr=glava_tabele;
        while(curr!=0){
            if(strcmp(id, curr->id)==0){
                return curr;
            }
            curr=curr->next;
        }
        return 0;
    }
    
    void setVariableValue(struct Promjenljiva* prom, char* id, int val){
        if(prom==0){
            addNewNode(id, val);
        } else{
            prom->val=val;
        }
    }

    int getVariableValue(char* id){
        struct Promjenljiva* prom=findVariable(id);
        if(prom==0) return 0;
        return prom->val;
    }




/* Line 189 of yacc.c  */
#line 126 "pmf0.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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
     T_EQ = 299,
     T_SKIP = 300,
     T_LET = 301,
     T_FI = 302,
     T_READ = 303,
     T_IN = 304,
     T_THEN = 305,
     T_WRITE = 306
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 53 "pmf0.y"

    int int_value;
    char* string_value;
    double double_value;
    double double_exp;
    int hex_value;
    bool bool_value;
    char* ident;



/* Line 214 of yacc.c  */
#line 225 "pmf0.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 237 "pmf0.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   397

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNRULES -- Number of states.  */
#define YYNSTATES  138

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    12,    15,    18,    21,    22,
      25,    30,    33,    38,    41,    46,    49,    54,    57,    62,
      65,    70,    74,    78,    82,    86,    90,    94,    98,   102,
     106,   110,   114,   118,   120,   122,   126,   130,   134,   138,
     142,   146,   150,   154,   158,   162,   166,   168,   172,   176,
     180,   184,   188,   192,   196,   200,   204,   208,   212,   214,
     218,   222,   226,   230,   234,   238,   242,   246,   250,   254,
     258,   260,   262,   264
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    53,    54,    -1,    53,    55,    -1,    53,
      56,    -1,    53,    57,    -1,    53,    58,    -1,    53,    59,
      -1,    -1,    60,     3,    -1,    11,    44,    60,     3,    -1,
      61,     3,    -1,    11,    44,    61,     3,    -1,    62,     3,
      -1,    11,    44,    62,     3,    -1,    63,     3,    -1,    11,
      44,    63,     3,    -1,    64,     3,    -1,    11,    44,    64,
       3,    -1,    65,     3,    -1,    11,    44,    65,     3,    -1,
      60,    16,    60,    -1,    60,    17,    60,    -1,    60,    18,
      60,    -1,    60,    19,    60,    -1,    60,    20,    60,    -1,
      60,    27,    60,    -1,    60,    22,    60,    -1,    60,    23,
      60,    -1,    60,    25,    60,    -1,    60,    26,    60,    -1,
      60,    28,    60,    -1,    34,    60,    35,    -1,     4,    -1,
      11,    -1,    61,    16,    61,    -1,    61,    17,    61,    -1,
      61,    18,    61,    -1,    61,    19,    61,    -1,    61,    27,
      61,    -1,    61,    22,    61,    -1,    61,    23,    61,    -1,
      61,    25,    61,    -1,    61,    26,    61,    -1,    61,    28,
      61,    -1,    34,    61,    35,    -1,     5,    -1,    62,    16,
      62,    -1,    62,    17,    62,    -1,    62,    18,    62,    -1,
      62,    19,    62,    -1,    62,    27,    62,    -1,    62,    22,
      62,    -1,    62,    23,    62,    -1,    62,    25,    62,    -1,
      62,    26,    62,    -1,    62,    28,    62,    -1,    34,    62,
      35,    -1,     6,    -1,    63,    16,    63,    -1,    63,    17,
      63,    -1,    63,    18,    63,    -1,    63,    19,    63,    -1,
      63,    27,    63,    -1,    63,    22,    63,    -1,    63,    23,
      63,    -1,    63,    25,    63,    -1,    63,    26,    63,    -1,
      63,    28,    63,    -1,    34,    63,    35,    -1,     7,    -1,
       9,    -1,    10,    -1,     8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   126,   126,   127,   128,   129,   130,   131,   132,   135,
     136,   142,   143,   146,   147,   150,   151,   154,   155,   158,
     159,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   225,   226,   230
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_SC", "T_INT", "T_DOUBLE", "T_DBLEXP",
  "T_HEX", "T_STR", "T_BOOLT", "T_BOOLF", "T_ID", "T_INTID", "T_BOOLID",
  "T_STRID", "T_DOUBLEID", "T_PLUS", "T_MINUS", "T_MUL", "T_DIV", "T_MOD",
  "T_DIV2", "T_MANJE", "T_VISE", "T_JEDNAKO", "T_MANJEJEDNAKO",
  "T_VISEJEDNAKO", "T_JEJEDNAKO", "T_RAZLICITO", "T_AND", "T_OR",
  "T_NEGACIJA", "T_ZAREZ", "T_TACKA", "T_LEFTP", "T_RIGHTP", "T_FOR",
  "T_WHILE", "T_BREAK", "T_IF", "T_ELSE", "T_RETURN", "T_DO", "T_END",
  "T_EQ", "T_SKIP", "T_LET", "T_FI", "T_READ", "T_IN", "T_THEN", "T_WRITE",
  "$accept", "S", "stat", "stat2", "stat3", "stat4", "stat5", "stat6",
  "exp", "exp2", "exp3", "exp4", "exp5", "exp6", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    53,    53,    53,    53,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    64,    64,    65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     0,     2,
       4,     2,     4,     2,     4,     2,     4,     2,     4,     2,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     1,    33,    46,    58,    70,    73,    71,    72,
      34,     0,     2,     3,     4,     5,     6,     7,     0,     0,
       0,     0,     0,     0,     0,    34,     0,     0,     0,     0,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    19,     0,     0,     0,
       0,     0,     0,    32,    45,    57,    69,     0,    21,    22,
      23,    24,    25,    27,    28,    29,    30,    26,    31,     0,
      35,    36,    37,    38,    40,    41,    42,    43,    39,    44,
       0,    47,    48,    49,    50,    52,    53,    54,    55,    51,
      56,     0,    59,    60,    61,    62,    64,    65,    66,    67,
      63,    68,    10,    12,    14,    16,    18,    20
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    12,    13,    14,    15,    16,    17,    26,    27,
      28,    29,    22,    23
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -40
static const yytype_int16 yypact[] =
{
     -40,    74,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
     -39,    90,   -40,   -40,   -40,   -40,   -40,   -40,   114,   150,
     167,   184,     3,     4,    82,   -40,    -8,   248,   262,   276,
     -40,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,   -40,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,   -40,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,   -40,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,   -40,   -40,   132,   201,   218,
     235,    10,    13,   -40,   -40,   -40,   -40,    94,   287,   287,
      84,    84,    84,   -40,   -40,   -40,   -40,   327,   327,    70,
     298,   298,   334,   334,   -40,   -40,   -40,   -40,   341,   341,
      -2,   309,   309,   348,   348,   -40,   -40,   -40,   -40,   355,
     355,    69,   320,   320,   362,   362,   -40,   -40,   -40,   -40,
     369,   369,   -40,   -40,   -40,   -40,   -40,   -40
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,     2,     1,
       0,    -1,    -3,     5
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      21,    20,    19,    18,     5,    24,    75,    76,    31,    32,
      33,    34,    35,   136,    36,    37,   137,    38,    39,    40,
      41,    81,     0,    80,    79,    78,    77,    83,     0,    82,
       0,     0,   110,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,     2,     4,     6,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     3,     4,     5,     6,
       7,     8,     9,    25,     3,     4,     5,     6,     3,     0,
       0,    25,     0,   121,    99,    25,    36,    37,    11,    38,
      39,    40,    41,     0,     0,     0,    11,    30,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,    87,     0,
      31,    32,    33,    34,    35,   132,    36,    37,     0,    38,
      39,    40,    41,     0,     0,     0,     0,     0,    31,    32,
      33,    34,    35,    42,    36,    37,     0,    38,    39,    40,
      41,     0,     0,     0,     0,     0,    43,    44,    45,    46,
      53,     0,    47,    48,     0,    49,    50,    51,    52,     0,
       0,     0,     0,    54,    55,    56,    57,    64,     0,    58,
      59,     0,    60,    61,    62,    63,     0,     0,     0,     0,
      65,    66,    67,    68,   133,     0,    69,    70,     0,    71,
      72,    73,    74,     0,     0,     0,     0,    43,    44,    45,
      46,   134,     0,    47,    48,     0,    49,    50,    51,    52,
       0,     0,     0,     0,    54,    55,    56,    57,   135,     0,
      58,    59,     0,    60,    61,    62,    63,     0,     0,     0,
       0,    65,    66,    67,    68,     0,     0,    69,    70,     0,
      71,    72,    73,    74,    43,    44,    45,    46,     0,     0,
      47,    48,     0,    49,    50,    51,    52,     0,    54,    55,
      56,    57,     0,    84,    58,    59,     0,    60,    61,    62,
      63,     0,    65,    66,    67,    68,     0,    85,    69,    70,
       0,    71,    72,    73,    74,    33,    34,    35,     0,    36,
      37,    86,    38,    39,    40,    41,    45,    46,     0,     0,
      47,    48,     0,    49,    50,    51,    52,    56,    57,     0,
       0,    58,    59,     0,    60,    61,    62,    63,    67,    68,
       0,     0,    69,    70,     0,    71,    72,    73,    74,    36,
      37,     0,    38,    39,    -1,    -1,    47,    48,     0,    49,
      50,    51,    52,    47,    48,     0,    49,    50,    -1,    -1,
      58,    59,     0,    60,    61,    62,    63,    58,    59,     0,
      60,    61,    -1,    -1,    69,    70,     0,    71,    72,    73,
      74,    69,    70,     0,    71,    72,    -1,    -1
};

static const yytype_int8 yycheck[] =
{
       1,     1,     1,     1,     6,    44,     3,     3,    16,    17,
      18,    19,    20,     3,    22,    23,     3,    25,    26,    27,
      28,    24,    -1,    24,    24,    24,    24,    35,    -1,    24,
      -1,    -1,    34,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,     0,     5,     7,    -1,     4,     5,
       6,     7,     8,     9,    10,    11,     4,     5,     6,     7,
       8,     9,    10,    11,     4,     5,     6,     7,     4,    -1,
      -1,    11,    -1,    34,    34,    11,    22,    23,    34,    25,
      26,    27,    28,    -1,    -1,    -1,    34,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    34,    -1,
      16,    17,    18,    19,    20,     3,    22,    23,    -1,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    16,    17,
      18,    19,    20,     3,    22,    23,    -1,    25,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,
       3,    -1,    22,    23,    -1,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    16,    17,    18,    19,     3,    -1,    22,
      23,    -1,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      16,    17,    18,    19,     3,    -1,    22,    23,    -1,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    16,    17,    18,
      19,     3,    -1,    22,    23,    -1,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    16,    17,    18,    19,     3,    -1,
      22,    23,    -1,    25,    26,    27,    28,    -1,    -1,    -1,
      -1,    16,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      25,    26,    27,    28,    16,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    25,    26,    27,    28,    -1,    16,    17,
      18,    19,    -1,    35,    22,    23,    -1,    25,    26,    27,
      28,    -1,    16,    17,    18,    19,    -1,    35,    22,    23,
      -1,    25,    26,    27,    28,    18,    19,    20,    -1,    22,
      23,    35,    25,    26,    27,    28,    18,    19,    -1,    -1,
      22,    23,    -1,    25,    26,    27,    28,    18,    19,    -1,
      -1,    22,    23,    -1,    25,    26,    27,    28,    18,    19,
      -1,    -1,    22,    23,    -1,    25,    26,    27,    28,    22,
      23,    -1,    25,    26,    27,    28,    22,    23,    -1,    25,
      26,    27,    28,    22,    23,    -1,    25,    26,    27,    28,
      22,    23,    -1,    25,    26,    27,    28,    22,    23,    -1,
      25,    26,    27,    28,    22,    23,    -1,    25,    26,    27,
      28,    22,    23,    -1,    25,    26,    27,    28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    53,     0,     4,     5,     6,     7,     8,     9,    10,
      11,    34,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    44,    11,    60,    61,    62,    63,
       3,    16,    17,    18,    19,    20,    22,    23,    25,    26,
      27,    28,     3,    16,    17,    18,    19,    22,    23,    25,
      26,    27,    28,     3,    16,    17,    18,    19,    22,    23,
      25,    26,    27,    28,     3,    16,    17,    18,    19,    22,
      23,    25,    26,    27,    28,     3,     3,    60,    61,    62,
      63,    64,    65,    35,    35,    35,    35,    34,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    34,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      34,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    34,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,     3,     3,     3,     3,     3,     3
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 126 "pmf0.y"
    { ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 127 "pmf0.y"
    { ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 128 "pmf0.y"
    { ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 129 "pmf0.y"
    { ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 130 "pmf0.y"
    { ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 131 "pmf0.y"
    { ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 135 "pmf0.y"
    {printf("%d\n", (yyvsp[(1) - (2)].int_value));;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 136 "pmf0.y"
    {/*printf("%s=%d\n", $1, $3);*/
                            struct Promjenljiva* prom=findVariable((yyvsp[(1) - (4)].ident));
                            setVariableValue(prom, (yyvsp[(1) - (4)].ident), (yyvsp[(3) - (4)].int_value));
                         ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 142 "pmf0.y"
    {printf("%f\n", (yyvsp[(1) - (2)].double_value));;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 143 "pmf0.y"
    {printf("%s=%f\n", (yyvsp[(1) - (4)].ident), (yyvsp[(3) - (4)].double_value));;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 146 "pmf0.y"
    {printf("%e\n", (yyvsp[(1) - (2)].double_exp));;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 147 "pmf0.y"
    {printf("%s=%e\n", (yyvsp[(1) - (4)].ident), (yyvsp[(3) - (4)].double_exp));;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 150 "pmf0.y"
    {printf("%x\n", (yyvsp[(1) - (2)].hex_value));;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 151 "pmf0.y"
    {printf("%s=%x\n", (yyvsp[(1) - (4)].ident), (yyvsp[(3) - (4)].hex_value));;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 154 "pmf0.y"
    {printf("%d\n", (yyvsp[(1) - (2)].bool_value));;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 155 "pmf0.y"
    {printf("%s=%d\n", (yyvsp[(1) - (4)].ident), (yyvsp[(3) - (4)].bool_value));;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 158 "pmf0.y"
    {printf("%s\n", (yyvsp[(1) - (2)].string_value));;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 159 "pmf0.y"
    {printf("%s=%s\n", (yyvsp[(1) - (4)].ident), (yyvsp[(3) - (4)].string_value));;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 163 "pmf0.y"
    { (yyval.int_value)=(yyvsp[(1) - (3)].int_value)+(yyvsp[(3) - (3)].int_value); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 164 "pmf0.y"
    { (yyval.int_value)=(yyvsp[(1) - (3)].int_value)-(yyvsp[(3) - (3)].int_value); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 165 "pmf0.y"
    { (yyval.int_value)=(yyvsp[(1) - (3)].int_value)*(yyvsp[(3) - (3)].int_value); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 166 "pmf0.y"
    { (yyval.int_value)=(yyvsp[(1) - (3)].int_value)/(yyvsp[(3) - (3)].int_value); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 167 "pmf0.y"
    { (yyval.int_value)=(yyvsp[(1) - (3)].int_value)%(yyvsp[(3) - (3)].int_value); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 168 "pmf0.y"
    { (yyval.int_value)=(yyvsp[(1) - (3)].int_value)==(yyvsp[(3) - (3)].int_value); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 169 "pmf0.y"
    { (yyval.int_value)=(yyvsp[(1) - (3)].int_value)<(yyvsp[(3) - (3)].int_value); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 170 "pmf0.y"
    { (yyval.int_value)=(yyvsp[(1) - (3)].int_value)>(yyvsp[(3) - (3)].int_value); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 171 "pmf0.y"
    { (yyval.int_value)=(yyvsp[(1) - (3)].int_value)<=(yyvsp[(3) - (3)].int_value); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 172 "pmf0.y"
    { (yyval.int_value)=(yyvsp[(1) - (3)].int_value)>=(yyvsp[(3) - (3)].int_value); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 173 "pmf0.y"
    { (yyval.int_value)=(yyvsp[(1) - (3)].int_value)!=(yyvsp[(3) - (3)].int_value); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 174 "pmf0.y"
    { (yyval.int_value)=(yyvsp[(2) - (3)].int_value);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 175 "pmf0.y"
    { (yyval.int_value)=(yyvsp[(1) - (1)].int_value);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 176 "pmf0.y"
    { (yyval.int_value)=getVariableValue((yyvsp[(1) - (1)].ident)); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 180 "pmf0.y"
    { (yyval.double_value)=(yyvsp[(1) - (3)].double_value)+(yyvsp[(3) - (3)].double_value); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 181 "pmf0.y"
    { (yyval.double_value)=(yyvsp[(1) - (3)].double_value)-(yyvsp[(3) - (3)].double_value); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 182 "pmf0.y"
    { (yyval.double_value)=(yyvsp[(1) - (3)].double_value)*(yyvsp[(3) - (3)].double_value); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 183 "pmf0.y"
    { (yyval.double_value)=(yyvsp[(1) - (3)].double_value)/(yyvsp[(3) - (3)].double_value); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 184 "pmf0.y"
    { (yyval.double_value)=(yyvsp[(1) - (3)].double_value)==(yyvsp[(3) - (3)].double_value); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 185 "pmf0.y"
    { (yyval.double_value)=(yyvsp[(1) - (3)].double_value)<(yyvsp[(3) - (3)].double_value); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 186 "pmf0.y"
    { (yyval.double_value)=(yyvsp[(1) - (3)].double_value)>(yyvsp[(3) - (3)].double_value); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 187 "pmf0.y"
    { (yyval.double_value)=(yyvsp[(1) - (3)].double_value)<=(yyvsp[(3) - (3)].double_value); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 188 "pmf0.y"
    { (yyval.double_value)=(yyvsp[(1) - (3)].double_value)>=(yyvsp[(3) - (3)].double_value); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 189 "pmf0.y"
    { (yyval.double_value)=(yyvsp[(1) - (3)].double_value)!=(yyvsp[(3) - (3)].double_value); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 190 "pmf0.y"
    { (yyval.double_value)=(yyvsp[(2) - (3)].double_value);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 191 "pmf0.y"
    { (yyval.double_value)=(yyvsp[(1) - (1)].double_value);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 195 "pmf0.y"
    { (yyval.double_exp)=(yyvsp[(1) - (3)].double_exp)+(yyvsp[(3) - (3)].double_exp); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 196 "pmf0.y"
    { (yyval.double_exp)=(yyvsp[(1) - (3)].double_exp)-(yyvsp[(3) - (3)].double_exp); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 197 "pmf0.y"
    { (yyval.double_exp)=(yyvsp[(1) - (3)].double_exp)*(yyvsp[(3) - (3)].double_exp); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 198 "pmf0.y"
    { (yyval.double_exp)=(yyvsp[(1) - (3)].double_exp)/(yyvsp[(3) - (3)].double_exp); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 199 "pmf0.y"
    { (yyval.double_exp)=(yyvsp[(1) - (3)].double_exp)==(yyvsp[(3) - (3)].double_exp); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 200 "pmf0.y"
    { (yyval.double_exp)=(yyvsp[(1) - (3)].double_exp)<(yyvsp[(3) - (3)].double_exp); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 201 "pmf0.y"
    { (yyval.double_exp)=(yyvsp[(1) - (3)].double_exp)>(yyvsp[(3) - (3)].double_exp); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 202 "pmf0.y"
    { (yyval.double_exp)=(yyvsp[(1) - (3)].double_exp)<=(yyvsp[(3) - (3)].double_exp); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 203 "pmf0.y"
    { (yyval.double_exp)=(yyvsp[(1) - (3)].double_exp)>=(yyvsp[(3) - (3)].double_exp); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 204 "pmf0.y"
    { (yyval.double_exp)=(yyvsp[(1) - (3)].double_exp)!=(yyvsp[(3) - (3)].double_exp); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 205 "pmf0.y"
    { (yyval.double_exp)=(yyvsp[(2) - (3)].double_exp);;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 206 "pmf0.y"
    { (yyval.double_exp)=(yyvsp[(1) - (1)].double_exp);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 210 "pmf0.y"
    { (yyval.hex_value)=(yyvsp[(1) - (3)].hex_value)+(yyvsp[(3) - (3)].hex_value); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 211 "pmf0.y"
    { (yyval.hex_value)=(yyvsp[(1) - (3)].hex_value)-(yyvsp[(3) - (3)].hex_value); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 212 "pmf0.y"
    { (yyval.hex_value)=(yyvsp[(1) - (3)].hex_value)*(yyvsp[(3) - (3)].hex_value); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 213 "pmf0.y"
    { (yyval.hex_value)=(yyvsp[(1) - (3)].hex_value)/(yyvsp[(3) - (3)].hex_value); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 214 "pmf0.y"
    { (yyval.hex_value)=(yyvsp[(1) - (3)].hex_value)==(yyvsp[(3) - (3)].hex_value); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 215 "pmf0.y"
    { (yyval.hex_value)=(yyvsp[(1) - (3)].hex_value)<(yyvsp[(3) - (3)].hex_value); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 216 "pmf0.y"
    { (yyval.hex_value)=(yyvsp[(1) - (3)].hex_value)>(yyvsp[(3) - (3)].hex_value); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 217 "pmf0.y"
    { (yyval.hex_value)=(yyvsp[(1) - (3)].hex_value)<=(yyvsp[(3) - (3)].hex_value); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 218 "pmf0.y"
    { (yyval.hex_value)=(yyvsp[(1) - (3)].hex_value)>=(yyvsp[(3) - (3)].hex_value); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 219 "pmf0.y"
    { (yyval.hex_value)=(yyvsp[(1) - (3)].hex_value)!=(yyvsp[(3) - (3)].hex_value); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 220 "pmf0.y"
    { (yyval.hex_value)=(yyvsp[(2) - (3)].hex_value);;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 221 "pmf0.y"
    { (yyval.hex_value)=(yyvsp[(1) - (1)].hex_value);;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 225 "pmf0.y"
    { (yyval.bool_value)=(yyvsp[(1) - (1)].bool_value); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 226 "pmf0.y"
    { (yyval.bool_value)=(yyvsp[(1) - (1)].bool_value); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 230 "pmf0.y"
    { (yyval.string_value)=strdup((yyvsp[(1) - (1)].string_value)); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2105 "pmf0.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 233 "pmf0.y"


void yyerror(const char* s){
    printf("%s\n", s);
}

int main(){
    int res=yyparse();

    if(res==0){
        printf("Ulaz ispravan\n");
    } else printf("NEispravan\n");
    
    return 0;
}
