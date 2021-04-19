/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include<bits/stdc++.h>
#include "Symbol_table.h"

using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;
FILE* fp;
SymbolTable *st = new SymbolTable(31);

int line_count=1;
int error=0;
void IncLine(){
	line_count++;}
int getline()
	{return line_count;}
void IncErr(){
	error++;}
int getErr()
	{return error;}

void yyerror(char *s)
{
	//write your code
	cout<<"At line no: "<<getline()<<"Syntax Error"<<endl;
}

string type;

#line 102 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    IF = 258,
    ELSE = 259,
    FOR = 260,
    WHILE = 261,
    DEFAULT = 262,
    VOID = 263,
    CHAR = 264,
    INT = 265,
    DOUBLE = 266,
    MAIN = 267,
    RETURN = 268,
    FLOAT = 269,
    PRINTLN = 270,
    DO = 271,
    ADDOP = 272,
    INCOP = 273,
    DECOP = 274,
    MULOP = 275,
    ASSIGNOP = 276,
    RELOP = 277,
    LOGICOP = 278,
    NOT = 279,
    LPAREN = 280,
    RPAREN = 281,
    LCURL = 282,
    RCURL = 283,
    LTHIRD = 284,
    RTHIRD = 285,
    COMMA = 286,
    SEMICOLON = 287,
    ID = 288,
    CONST_INT = 289,
    CONST_CHAR = 290,
    CONST_FLOAT = 291,
    nothing = 292
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define DEFAULT 262
#define VOID 263
#define CHAR 264
#define INT 265
#define DOUBLE 266
#define MAIN 267
#define RETURN 268
#define FLOAT 269
#define PRINTLN 270
#define DO 271
#define ADDOP 272
#define INCOP 273
#define DECOP 274
#define MULOP 275
#define ASSIGNOP 276
#define RELOP 277
#define LOGICOP 278
#define NOT 279
#define LPAREN 280
#define RPAREN 281
#define LCURL 282
#define RCURL 283
#define LTHIRD 284
#define RTHIRD 285
#define COMMA 286
#define SEMICOLON 287
#define ID 288
#define CONST_INT 289
#define CONST_CHAR 290
#define CONST_FLOAT 291
#define nothing 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 32 "parser.y"

int ival;
SymbolInfo* siv;
vector<SymbolInfo*>* vecv;

#line 234 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   163

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  119

#define YYUNDEFTOK  2
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    50,    50,    66,    82,    97,   110,   123,   138,   159,
     180,   202,   224,   241,   257,   271,   284,   305,   325,   330,
     364,   371,   378,   387,   403,   423,   435,   452,   465,   484,
     497,   510,   523,   549,   568,   593,   613,   630,   649,   659,
     674,   683,   699,   710,   727,   738,   755,   766,   783,   794,
     811,   822,   839,   851,   863,   876,   887,   903,   918,   927,
     936,   948,   962,   973,   984,   999
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "FOR", "WHILE", "DEFAULT",
  "VOID", "CHAR", "INT", "DOUBLE", "MAIN", "RETURN", "FLOAT", "PRINTLN",
  "DO", "ADDOP", "INCOP", "DECOP", "MULOP", "ASSIGNOP", "RELOP", "LOGICOP",
  "NOT", "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "COMMA",
  "SEMICOLON", "ID", "CONST_INT", "CONST_CHAR", "CONST_FLOAT", "nothing",
  "$accept", "start", "program", "unit", "func_declaration",
  "func_definition", "parameter_list", "compound_statement", "newScope",
  "var_declaration", "type_specifier", "declaration_list", "statements",
  "statement", "expression_statement", "variable", "expression",
  "logic_expression", "rel_expression", "simple_expression", "term",
  "unary_expression", "factor", "argument_list", "arguments", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292
};
# endif

#define YYPACT_NINF (-68)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      85,   -68,   -68,   -68,    13,    85,   -68,   -68,   -68,   -68,
     -13,   -68,   -68,    71,    -9,     4,     3,    24,   -68,    29,
      37,    41,    56,    46,   -68,   -68,   -68,    44,    85,   -68,
     -68,    54,    45,   -68,   -68,    64,    76,    82,    83,    93,
     104,   100,   104,   104,   104,   -68,   -68,    91,   -68,   -68,
     -68,   -68,    94,    77,   -68,   -68,    17,    99,   -68,   107,
      67,   112,   -68,   -68,   -68,   -68,   104,    -8,   104,   103,
     106,    28,   -68,   -68,   118,   104,   104,   117,   -68,   -68,
     -68,   -68,   104,   -68,   104,   104,   104,   104,   121,    -8,
     122,   -68,   123,   -68,   -68,   124,   120,   125,   -68,   -68,
     112,   135,   -68,   109,   104,   109,   126,   -68,   104,   -68,
     149,   128,   -68,   -68,   -68,   109,   109,   -68,   -68
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    22,    20,    21,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    25,     0,     0,     0,     0,    19,     0,
       0,    15,     0,    23,    18,     9,    11,     0,     0,    14,
      26,     0,     0,     8,    10,    13,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    38,    40,    58,    59,
      31,    29,     0,     0,    27,    30,    55,     0,    42,    44,
      46,    48,    50,    54,    12,    24,     0,     0,     0,     0,
       0,    55,    52,    53,     0,    63,     0,    25,    16,    28,
      60,    61,     0,    39,     0,     0,     0,     0,     0,     0,
       0,    37,     0,    57,    65,     0,    62,     0,    43,    45,
      49,    47,    51,     0,     0,     0,     0,    56,     0,    41,
      33,     0,    35,    36,    64,     0,     0,    34,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   -68,   151,   -68,   -68,   -68,     0,   -68,    98,
       6,   -68,   -68,   -51,   -57,   -42,   -37,   -67,    73,    74,
      78,   -38,   -68,   -68,   -68
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    20,    50,    32,    51,
      52,    14,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    95,    96
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      71,    71,    79,    69,    72,    73,    10,    74,    94,    42,
      89,    10,     1,    11,     2,    98,    43,    44,     3,    26,
      13,    21,    17,    18,    46,    47,    48,    34,    49,    88,
      19,    90,   104,    71,    35,    80,    81,    22,    82,    97,
      71,   114,    71,    71,    71,    71,    80,    81,    37,   102,
      38,    39,   110,     1,   112,     2,    24,    23,    40,     3,
      41,    25,    42,    27,   117,   118,    71,   111,    28,    43,
      44,    24,    24,    45,    29,    31,    33,    46,    47,    48,
      37,    49,    38,    39,    85,     1,    30,     2,    36,    86,
      40,     3,    41,     1,    42,     2,    15,    64,     9,     3,
      16,    43,    44,     9,    24,    78,    65,    66,    67,    46,
      47,    48,    37,    49,    38,    39,    75,     1,    68,     2,
      76,    42,    40,     3,    41,    70,    42,    77,    43,    44,
      84,    83,    87,    43,    44,    91,    24,    47,    48,    92,
      49,    46,    47,    48,    93,    49,    16,   103,   105,   106,
     107,   108,    85,   115,   116,   109,    12,    99,   113,     0,
     101,     0,     0,   100
};

static const yytype_int8 yycheck[] =
{
      42,    43,    53,    40,    42,    43,     0,    44,    75,    17,
      67,     5,     8,     0,    10,    82,    24,    25,    14,    19,
      33,    15,    31,    32,    32,    33,    34,    27,    36,    66,
      26,    68,    89,    75,    28,    18,    19,    34,    21,    76,
      82,   108,    84,    85,    86,    87,    18,    19,     3,    87,
       5,     6,   103,     8,   105,    10,    27,    33,    13,    14,
      15,    32,    17,    26,   115,   116,   108,   104,    31,    24,
      25,    27,    27,    28,    33,    29,    32,    32,    33,    34,
       3,    36,     5,     6,    17,     8,    30,    10,    34,    22,
      13,    14,    15,     8,    17,    10,    25,    33,     0,    14,
      29,    24,    25,     5,    27,    28,    30,    25,    25,    32,
      33,    34,     3,    36,     5,     6,    25,     8,    25,    10,
      29,    17,    13,    14,    15,    25,    17,    33,    24,    25,
      23,    32,    20,    24,    25,    32,    27,    33,    34,    33,
      36,    32,    33,    34,    26,    36,    29,    26,    26,    26,
      26,    31,    17,     4,    26,    30,     5,    84,    32,    -1,
      86,    -1,    -1,    85
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    10,    14,    39,    40,    41,    42,    43,    47,
      48,     0,    41,    33,    49,    25,    29,    31,    32,    26,
      44,    48,    34,    33,    27,    32,    45,    26,    31,    33,
      30,    29,    46,    32,    45,    48,    34,     3,     5,     6,
      13,    15,    17,    24,    25,    28,    32,    33,    34,    36,
      45,    47,    48,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    33,    30,    25,    25,    25,    54,
      25,    53,    59,    59,    54,    25,    29,    33,    28,    51,
      18,    19,    21,    32,    23,    17,    22,    20,    54,    52,
      54,    32,    33,    26,    55,    61,    62,    54,    55,    56,
      58,    57,    59,    26,    52,    26,    26,    26,    31,    30,
      51,    54,    51,    32,    55,     4,    26,    51,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    41,    42,    42,
      43,    43,    44,    44,    44,    44,    45,    45,    46,    47,
      48,    48,    48,    49,    49,    49,    49,    50,    50,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    52,    52,
      53,    53,    54,    54,    55,    55,    56,    56,    57,    57,
      58,    58,    59,    59,    59,    60,    60,    60,    60,    60,
      60,    60,    61,    61,    62,    62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       6,     5,     4,     3,     2,     1,     4,     3,     0,     3,
       1,     1,     1,     3,     6,     1,     4,     1,     2,     1,
       1,     1,     7,     5,     7,     5,     5,     3,     1,     2,
       1,     4,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     2,     2,     1,     1,     4,     3,     1,     1,
       2,     2,     1,     0,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

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
#line 51 "parser.y"
        {
		(yyval.vecv)=new vector<SymbolInfo*>();
		vector<SymbolInfo*>::iterator i;
		for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
		(yyval.vecv)->push_back((*i));
		cout<<"At line no: "<<getline()<<" start : program"<<endl;
		cout<<endl;
		for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
			cout<<(*i)->get_name();
		cout<<endl;
		cout<<endl;
		(yyvsp[0].vecv)->clear();
	}
#line 1511 "y.tab.c"
    break;

  case 3:
#line 66 "parser.y"
                        {
					vector<SymbolInfo*>::iterator i;
					(yyval.vecv)=new vector<SymbolInfo*>();
					for (i = (yyvsp[-1].vecv)->begin(); i != (yyvsp[-1].vecv)->end(); ++i) 
						(yyval.vecv)->push_back((*i));
					for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
						(yyval.vecv)->push_back(*i);
					cout<<"At line no: "<<getline()<<" program : program unit"<<endl;
					cout<<endl;
					for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
						cout<<(*i)->get_name();
					cout<<endl;
					cout<<endl;
					(yyvsp[-1].vecv)->clear();
					(yyvsp[0].vecv)->clear();
				}
#line 1532 "y.tab.c"
    break;

  case 4:
#line 82 "parser.y"
                                {
					(yyval.vecv)=new vector<SymbolInfo*>();
					vector<SymbolInfo*>::iterator i;
					for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
						(yyval.vecv)->push_back((*i));
					cout<<"At line no: "<<getline()<<" program : unit"<<endl;
					cout<<endl;
					for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
						cout<<(*i)->get_name();
					cout<<endl;
					cout<<endl;
					(yyvsp[0].vecv)->clear();
				}
#line 1550 "y.tab.c"
    break;

  case 5:
#line 97 "parser.y"
                                {
					(yyval.vecv)=new vector<SymbolInfo*>();
					vector<SymbolInfo*>::iterator i;
					for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
						(yyval.vecv)->push_back((*i));
					cout<<"At line no: "<<getline()<<" unit : var_declaration"<<endl;
					cout<<endl;
					for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
						cout<<(*i)->get_name();
					cout<<endl;
					cout<<endl;
					(yyvsp[0].vecv)->clear();
				}
#line 1568 "y.tab.c"
    break;

  case 6:
#line 110 "parser.y"
                        {
     					(yyval.vecv)=new vector<SymbolInfo*>();
					vector<SymbolInfo*>::iterator i;
					for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
						(yyval.vecv)->push_back((*i));
					cout<<"At line no: "<<getline()<<" unit : func_declaration"<<endl;
					cout<<endl;
					for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
						cout<<(*i)->get_name();
					cout<<endl;
					cout<<endl;
					(yyvsp[0].vecv)->clear();
     				}
#line 1586 "y.tab.c"
    break;

  case 7:
#line 123 "parser.y"
                                {
     					(yyval.vecv)=new vector<SymbolInfo*>();
					vector<SymbolInfo*>::iterator i;
					for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
						(yyval.vecv)->push_back((*i));
					cout<<"At line no: "<<getline()<<" unit : func_definition"<<endl;
					cout<<endl;
					for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
						cout<<(*i)->get_name();
					cout<<endl;
					cout<<endl;
					(yyvsp[0].vecv)->clear();
     				}
#line 1604 "y.tab.c"
    break;

  case 8:
#line 138 "parser.y"
                                                                                {
											cout<<"At line no: "<<getline()<<" func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON"<<endl;
											cout<<endl;
											(yyval.vecv)=new vector<SymbolInfo*>();
											(yyval.vecv)->push_back((yyvsp[-5].siv));
											(yyval.vecv)->push_back(new SymbolInfo(" ","space"));
											(yyval.vecv)->push_back((yyvsp[-4].siv));
											(yyval.vecv)->push_back(new SymbolInfo("(","LPAREN"));
											vector<SymbolInfo*>::iterator i;
											for (i = (yyvsp[-2].vecv)->begin(); i != (yyvsp[-2].vecv)->end(); ++i) 
												(yyval.vecv)->push_back((*i));
											(yyval.vecv)->push_back(new SymbolInfo(")","RPAREN"));
											(yyval.vecv)->push_back(new SymbolInfo(";","SEMICOLON"));
											(yyval.vecv)->push_back(new SymbolInfo("\n","newline"));
											for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
												cout<<(*i)->get_name();
      											cout<<endl;
      											cout<<endl;
											(yyvsp[-2].vecv)->clear();
		
										}
#line 1630 "y.tab.c"
    break;

  case 9:
#line 159 "parser.y"
                                                                                {
											cout<<"At line no: "<<getline()<<" func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON"<<endl;
											cout<<endl;
											vector<SymbolInfo*>::iterator i;
					
											(yyval.vecv)=new vector<SymbolInfo*>();
											(yyval.vecv)->push_back((yyvsp[-4].siv));
											(yyval.vecv)->push_back(new SymbolInfo(" ","space"));
											(yyval.vecv)->push_back((yyvsp[-3].siv));
											(yyval.vecv)->push_back(new SymbolInfo("(","LPAREN"));
											(yyval.vecv)->push_back(new SymbolInfo(")","RPAREN"));
											(yyval.vecv)->push_back(new SymbolInfo(";","SEMICOLON"));
											(yyval.vecv)->push_back(new SymbolInfo("\n","newline"));
											for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
											cout<<(*i)->get_name();
      											cout<<endl;
											cout<<endl;
		
										}
#line 1654 "y.tab.c"
    break;

  case 10:
#line 180 "parser.y"
                                                                                        {
												cout<<"At line no: "<<getline()<<" func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement"<<endl;
											cout<<endl;
											(yyval.vecv)=new vector<SymbolInfo*>();
											(yyval.vecv)->push_back((yyvsp[-5].siv));
											(yyval.vecv)->push_back(new SymbolInfo(" ","space"));
											(yyval.vecv)->push_back((yyvsp[-4].siv));
											
											(yyval.vecv)->push_back(new SymbolInfo("(","LPAREN"));
											vector<SymbolInfo*>::iterator i;
											for (i = (yyvsp[-2].vecv)->begin(); i != (yyvsp[-2].vecv)->end(); ++i) 
												(yyval.vecv)->push_back((*i));
											(yyval.vecv)->push_back(new SymbolInfo(")","RPAREN"));
											for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
												(yyval.vecv)->push_back((*i));
											for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
												cout<<(*i)->get_name();
      											cout<<endl;
      											cout<<endl;
      											(yyvsp[-2].vecv)->clear();
      											(yyvsp[0].vecv)->clear();
											}
#line 1681 "y.tab.c"
    break;

  case 11:
#line 202 "parser.y"
                                                                                        {
											cout<<"At line no: "<<getline()<<" func_definition : type_specifier ID LPAREN RPAREN compound_statement"<<endl;
											cout<<endl;
											(yyval.vecv)=new vector<SymbolInfo*>();
											(yyval.vecv)->push_back((yyvsp[-4].siv));
											(yyval.vecv)->push_back(new SymbolInfo(" ","space"));
											(yyval.vecv)->push_back((yyvsp[-3].siv));
											
											(yyval.vecv)->push_back(new SymbolInfo("(","LPAREN"));
											(yyval.vecv)->push_back(new SymbolInfo(")","RPAREN"));
											vector<SymbolInfo*>::iterator i;
											for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
												(yyval.vecv)->push_back((*i));
											(yyvsp[0].vecv)->clear();
											for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
												cout<<(*i)->get_name();
      											cout<<endl;
      											cout<<endl;
											}
#line 1705 "y.tab.c"
    break;

  case 12:
#line 224 "parser.y"
                                                                {
									cout<<"At line no: "<<getline()<<" parameter_list  : parameter_list COMMA type_specifier ID"<<endl;
									cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[-3].vecv)->begin(); i != (yyvsp[-3].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									(yyval.vecv)->push_back(new SymbolInfo(",","COMMA"));
									(yyval.vecv)->push_back((yyvsp[-1].siv));
									(yyval.vecv)->push_back(new SymbolInfo(" ","space"));
									(yyval.vecv)->push_back((yyvsp[0].siv));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									(yyvsp[-3].vecv)->clear();	
								}
#line 1727 "y.tab.c"
    break;

  case 13:
#line 241 "parser.y"
                                                                {
									cout<<"At line no: "<<getline()<<" parameter_list  : parameter_list COMMA type_specifier"<<endl;
									cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[-2].vecv)->begin(); i != (yyvsp[-2].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									(yyval.vecv)->push_back(new SymbolInfo(",","COMMA"));
									(yyval.vecv)->push_back((yyvsp[0].siv));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									(yyvsp[-2].vecv)->clear();
										
								}
#line 1748 "y.tab.c"
    break;

  case 14:
#line 257 "parser.y"
                                                                {
									cout<<"At line no: "<<getline()<<" parameter_list  : type_specifier ID"<<endl;
									cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									
									(yyval.vecv)->push_back((yyvsp[-1].siv));
									(yyval.vecv)->push_back(new SymbolInfo(" ","space"));
									(yyval.vecv)->push_back((yyvsp[0].siv));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
									cout<<endl;
								}
#line 1767 "y.tab.c"
    break;

  case 15:
#line 271 "parser.y"
                                                                {
									cout<<"At line no: "<<getline()<<" parameter_list  : type_specifier"<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									(yyval.vecv)->push_back((yyvsp[0].siv));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
										
								}
#line 1782 "y.tab.c"
    break;

  case 16:
#line 284 "parser.y"
                                                                        {
									cout<<"At line no: "<<getline()<<" compound_statement : LCURL statements RCURL"<<endl;
									cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									(yyval.vecv)->push_back(new SymbolInfo("{","LCURL"));
									
									(yyval.vecv)->push_back(new SymbolInfo("\n","newline"));
									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[-1].vecv)->begin(); i != (yyvsp[-1].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
      									(yyval.vecv)->push_back(new SymbolInfo("}","RCURL"));
      									(yyval.vecv)->push_back(new SymbolInfo("\n","newline"));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									st->print_all();
      									st->exitScope();
      									(yyvsp[-1].vecv)->clear();
										
								}
#line 1808 "y.tab.c"
    break;

  case 17:
#line 305 "parser.y"
                                                                        {
									cout<<"At line no: "<<getline()<<" compound_statement : LCURL  RCURL"<<endl;
									cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;

									(yyval.vecv)->push_back(new SymbolInfo("{","LCURL"));
									
									(yyval.vecv)->push_back(new SymbolInfo("\n","newline"));
      									(yyval.vecv)->push_back(new SymbolInfo("}","RCURL"));
      									(yyval.vecv)->push_back(new SymbolInfo("\n","newline"));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									st->print_all();
      									st->exitScope();
										
								}
#line 1832 "y.tab.c"
    break;

  case 18:
#line 325 "parser.y"
                {
			(yyval.ival)=-1;
			st->enterScope();
		}
#line 1841 "y.tab.c"
    break;

  case 19:
#line 330 "parser.y"
                                                                {
									cout<<"At line no: "<<getline()<<" var_declaration : type_specifier declaration_list SEMICOLON"<<endl;
									cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									(yyval.vecv)->push_back((yyvsp[-2].siv));
									type=(yyvsp[-2].siv)->get_name();
									(yyval.vecv)->push_back(new SymbolInfo(" ","space"));
									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[-1].vecv)->begin(); i != (yyvsp[-1].vecv)->end(); ++i) 
									{
										if((*i)->get_type()=="ID")
										{
											//(*i)->set_dType(type);
											SymbolInfo* si=new SymbolInfo((*i)->get_name(),"ID",type);
											if((*i)->get_varSize()!=-1)
											   si->set_varSize((*i)->get_varSize());
											st->insert_symbol(si);
											
											
										}
										(yyval.vecv)->push_back((*i));
									}
									type.clear();
      									(yyval.vecv)->push_back(new SymbolInfo(";","SEMICOLON"));
      									(yyval.vecv)->push_back(new SymbolInfo("\n","newline"));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									(yyvsp[-1].vecv)->clear();
										
								}
#line 1878 "y.tab.c"
    break;

  case 20:
#line 364 "parser.y"
                                {
					cout<<"At line no: "<<getline()<<" type_specifier : INT"<<endl;
					cout<<endl;
					(yyval.siv)=new SymbolInfo("int","INT");
					cout<<(yyval.siv)->get_name()<<endl;
					cout<<endl;
				}
#line 1890 "y.tab.c"
    break;

  case 21:
#line 371 "parser.y"
                        {
					cout<<"At line no: "<<getline()<<" type_specifier : FLOAT"<<endl;
					cout<<endl;
					(yyval.siv)=new SymbolInfo("float","FLOAT");
					cout<<(yyval.siv)->get_name()<<endl;
					cout<<endl;
				}
#line 1902 "y.tab.c"
    break;

  case 22:
#line 378 "parser.y"
                                {
					cout<<"At line no: "<<getline()<<" type_specifier : VOID"<<endl;
					cout<<endl;
					(yyval.siv)=new SymbolInfo("void","VOID");
					cout<<(yyval.siv)->get_name()<<endl;
					cout<<endl;
				}
#line 1914 "y.tab.c"
    break;

  case 23:
#line 387 "parser.y"
                                                                {
									cout<<"At line no: "<<getline()<<" declaration_list : declaration_list COMMA ID"<<endl;
									cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[-2].vecv)->begin(); i != (yyvsp[-2].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
      									(yyval.vecv)->push_back(new SymbolInfo(",","COMMA"));
      									(yyval.vecv)->push_back((yyvsp[0].siv));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									(yyvsp[-2].vecv)->clear();
										
								}
#line 1935 "y.tab.c"
    break;

  case 24:
#line 403 "parser.y"
                                                                        {
										cout<<"At line no: "<<getline()<<" declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD"<<endl;
										cout<<endl;
										(yyval.vecv)=new vector<SymbolInfo*>();
										vector<SymbolInfo*>::iterator i;
										for (i = (yyvsp[-5].vecv)->begin(); i != (yyvsp[-5].vecv)->end(); ++i) 
											(yyval.vecv)->push_back((*i));
      										(yyval.vecv)->push_back(new SymbolInfo(",","COMMA"));
      										(yyvsp[-3].siv)->set_varSize(stoi((yyvsp[-1].siv)->get_name()));
      										(yyval.vecv)->push_back((yyvsp[-3].siv));
      										(yyval.vecv)->push_back(new SymbolInfo("[","LTHIRD"));
      										(yyval.vecv)->push_back((yyvsp[-1].siv));
      										(yyval.vecv)->push_back(new SymbolInfo("]","RTHIRD"));
										for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      										cout<<endl;
      										cout<<endl;
      										(yyvsp[-5].vecv)->clear();
										
										}
#line 1960 "y.tab.c"
    break;

  case 25:
#line 423 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" declaration_list : ID"<<endl;
 		  							cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									
									(yyval.vecv)->push_back((yyvsp[0].siv));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
 		  						}
#line 1977 "y.tab.c"
    break;

  case 26:
#line 435 "parser.y"
                                                        {
 		  							cout<<"At line no: "<<getline()<<" declaration_list : ID LTHIRD CONST_INT RTHIRD"<<endl;
 		  							cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									(yyvsp[-3].siv)->set_varSize(stoi((yyvsp[-1].siv)->get_name()));
									(yyval.vecv)->push_back((yyvsp[-3].siv));
									(yyval.vecv)->push_back(new SymbolInfo("[","LTHIRD"));
      									(yyval.vecv)->push_back((yyvsp[-1].siv));
      									(yyval.vecv)->push_back(new SymbolInfo("]","RTHIRD"));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
 		  						}
#line 1997 "y.tab.c"
    break;

  case 27:
#line 452 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" statements : statement"<<endl;
 		  							cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2015 "y.tab.c"
    break;

  case 28:
#line 465 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" statements : statements statement"<<endl;
 		  							cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[-1].vecv)->begin(); i != (yyvsp[-1].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
      									
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									(yyvsp[-1].vecv)->clear();
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2037 "y.tab.c"
    break;

  case 29:
#line 484 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" statement : var_declaration"<<endl;
 		  							cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2055 "y.tab.c"
    break;

  case 30:
#line 497 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" statement : expression_statement"<<endl;
 		  							cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2073 "y.tab.c"
    break;

  case 31:
#line 510 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" statement : compound_statement"<<endl;
 		  							cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2091 "y.tab.c"
    break;

  case 32:
#line 523 "parser.y"
                                                                                                {
	  													cout<<"At line no: "<<getline()<<" statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement"<<endl;
	  													cout<<endl;
														(yyval.vecv)=new vector<SymbolInfo*>();
														(yyval.vecv)->push_back(new SymbolInfo("for","FOR"));
														(yyval.vecv)->push_back(new SymbolInfo("(","LPAREN"));
														vector<SymbolInfo*>::iterator i;
														for (i = (yyvsp[-4].vecv)->begin(); i != (yyvsp[-4].vecv)->end(); ++i) 
															(yyval.vecv)->push_back((*i));
      														
														for (i = (yyvsp[-3].vecv)->begin(); i != (yyvsp[-3].vecv)->end(); ++i) 
															(yyval.vecv)->push_back((*i));
      														for (i = (yyvsp[-2].vecv)->begin(); i != (yyvsp[-2].vecv)->end(); ++i) 
															(yyval.vecv)->push_back((*i));
      														(yyval.vecv)->push_back(new SymbolInfo(")","RPAREN"));
      														
														for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
														(yyval.vecv)->push_back((*i));
														for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
														cout<<(*i)->get_name();
      														cout<<endl;
      														cout<<endl;
      														(yyvsp[-4].vecv)->clear();
      														(yyvsp[-3].vecv)->clear();
      														(yyvsp[-2].vecv)->clear();	
	  												}
#line 2122 "y.tab.c"
    break;

  case 33:
#line 549 "parser.y"
                                                                        {
 		  							cout<<"At line no: "<<getline()<<" statement : IF LPAREN expression RPAREN statement"<<endl;
 		  							cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									(yyval.vecv)->push_back(new SymbolInfo("if","IF"));
									(yyval.vecv)->push_back(new SymbolInfo("(","LPAREN"));
									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[-2].vecv)->begin(); i != (yyvsp[-2].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
      									(yyval.vecv)->push_back(new SymbolInfo(")","RPAREN"));
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									(yyvsp[-2].vecv)->clear();
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2146 "y.tab.c"
    break;

  case 34:
#line 568 "parser.y"
                                                                        {
 		  							cout<<"At line no: "<<getline()<<" statement : IF LPAREN expression RPAREN statement ELSE statement"<<endl;
 		  							cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									(yyval.vecv)->push_back(new SymbolInfo("if","IF"));
									(yyval.vecv)->push_back(new SymbolInfo("(","LPAREN"));
									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[-4].vecv)->begin(); i != (yyvsp[-4].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
      									(yyval.vecv)->push_back(new SymbolInfo(")","RPAREN"));
      									
									for (i = (yyvsp[-2].vecv)->begin(); i != (yyvsp[-2].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
      									(yyval.vecv)->push_back(new SymbolInfo("else","ELSE"));
      									
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									(yyvsp[-4].vecv)->clear();
      									(yyvsp[-2].vecv)->clear();
      									(yyvsp[0].vecv)->clear();
 		  							}
#line 2176 "y.tab.c"
    break;

  case 35:
#line 593 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" statement : WHILE LPAREN expression RPAREN statement"<<endl;
 		  							cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									(yyval.vecv)->push_back(new SymbolInfo("while","WHILE"));
									(yyval.vecv)->push_back(new SymbolInfo("(","LPAREN"));
									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[-2].vecv)->begin(); i != (yyvsp[-2].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
      									(yyval.vecv)->push_back(new SymbolInfo(")","RPAREN"));
      									
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									(yyvsp[-2].vecv)->clear();
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2201 "y.tab.c"
    break;

  case 36:
#line 613 "parser.y"
                                                        {
 		  							cout<<"At line no: "<<getline()<<" statement : PRINTLN LPAREN ID RPAREN SEMICOLON"<<endl;
 		  							cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									(yyval.vecv)->push_back(new SymbolInfo("print","PRINTLN"));
									(yyval.vecv)->push_back(new SymbolInfo("(","LPAREN"));
									
      									(yyval.vecv)->push_back((yyvsp[-2].siv));
      									vector<SymbolInfo*>::iterator i;
      									(yyval.vecv)->push_back(new SymbolInfo(")","RPAREN"));
      									(yyval.vecv)->push_back(new SymbolInfo(";","SEMICOLON"));
      									(yyval.vecv)->push_back(new SymbolInfo("\n","newline"));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
 		  						}
#line 2223 "y.tab.c"
    break;

  case 37:
#line 630 "parser.y"
                                                        {
 		  							cout<<"At line no: "<<getline()<<" statement : RETURN expression SEMICOLON"<<endl;
 		  							cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									(yyval.vecv)->push_back(new SymbolInfo("return","RETURN"));
									(yyval.vecv)->push_back(new SymbolInfo(" ","space"));
									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[-1].vecv)->begin(); i != (yyvsp[-1].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
      									(yyval.vecv)->push_back(new SymbolInfo(";","SEMICOLON"));
      									(yyval.vecv)->push_back(new SymbolInfo("\n","newline"));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									(yyvsp[-1].vecv)->clear();
 		  						}
#line 2245 "y.tab.c"
    break;

  case 38:
#line 649 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" expression_statement : SEMICOLON"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
      									(yyval.vecv)->push_back(new SymbolInfo(";","SEMICOLON"));
      									(yyval.vecv)->push_back(new SymbolInfo("\n","newline"));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
 		  						}
#line 2260 "y.tab.c"
    break;

  case 39:
#line 659 "parser.y"
                                                        {
 		  							cout<<"At line no: "<<getline()<<" expression_statement : expression SEMICOLON"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[-1].vecv)->begin(); i != (yyvsp[-1].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
      									(yyval.vecv)->push_back(new SymbolInfo(";","SEMICOLON"));
      									(yyval.vecv)->push_back(new SymbolInfo("\n","newline"));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(yyvsp[-1].vecv)->clear();
 		  						}
#line 2278 "y.tab.c"
    break;

  case 40:
#line 674 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" variable : ID"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
      									(yyval.vecv)->push_back((yyvsp[0].siv));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
 		  						}
#line 2292 "y.tab.c"
    break;

  case 41:
#line 683 "parser.y"
                                                        {
 		  							cout<<"At line no: "<<getline()<<" variable : ID LTHIRD expression RTHIRD "<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									(yyval.vecv)->push_back((yyvsp[-3].siv));
      									(yyval.vecv)->push_back(new SymbolInfo("[","LTHIRD"));
      									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[-1].vecv)->begin(); i != (yyvsp[-1].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
      									(yyval.vecv)->push_back(new SymbolInfo("]","RTHIRD"));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(yyvsp[-1].vecv)->clear();
 		  						}
#line 2311 "y.tab.c"
    break;

  case 42:
#line 699 "parser.y"
                                                        {
 		  							cout<<"At line no: "<<getline()<<" expression : logic_expression"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2327 "y.tab.c"
    break;

  case 43:
#line 710 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" expression : variable ASSIGNOP logic_expression"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[-2].vecv)->begin(); i != (yyvsp[-2].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
      									(yyval.vecv)->push_back((yyvsp[-1].siv));
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(yyvsp[-2].vecv)->clear();
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2347 "y.tab.c"
    break;

  case 44:
#line 727 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" logic_expression : rel_expression "<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2363 "y.tab.c"
    break;

  case 45:
#line 738 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" logic_expression : rel_expression "<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[-2].vecv)->begin(); i != (yyvsp[-2].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
      									(yyval.vecv)->push_back((yyvsp[-1].siv));
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(yyvsp[-2].vecv)->clear();
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2383 "y.tab.c"
    break;

  case 46:
#line 755 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" rel_expression : simple_expression"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2399 "y.tab.c"
    break;

  case 47:
#line 766 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" rel_expression : simple_expression RELOP simple_expression"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[-2].vecv)->begin(); i != (yyvsp[-2].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
      									(yyval.vecv)->push_back((yyvsp[-1].siv));
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(yyvsp[-2].vecv)->clear();
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2419 "y.tab.c"
    break;

  case 48:
#line 783 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" simple_expression : term "<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2435 "y.tab.c"
    break;

  case 49:
#line 794 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" simple_expression : simple_expression ADDOP term "<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[-2].vecv)->begin(); i != (yyvsp[-2].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
      									(yyval.vecv)->push_back((yyvsp[-1].siv));
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(yyvsp[-2].vecv)->clear();
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2455 "y.tab.c"
    break;

  case 50:
#line 811 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" term : unary_expression"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2471 "y.tab.c"
    break;

  case 51:
#line 822 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" term : term MULOP unary_expression"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[-2].vecv)->begin(); i != (yyvsp[-2].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
      									(yyval.vecv)->push_back((yyvsp[-1].siv));
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(yyvsp[-2].vecv)->clear();
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2491 "y.tab.c"
    break;

  case 52:
#line 839 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" unary_expression : ADDOP unary_expression"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									(yyval.vecv)->push_back((yyvsp[-1].siv));
      									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2508 "y.tab.c"
    break;

  case 53:
#line 851 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" unary_expression : NOT unary_expression"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									(yyval.vecv)->push_back(new SymbolInfo("!","NOT"));
      									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2525 "y.tab.c"
    break;

  case 54:
#line 863 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" unary_expression : factor"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2541 "y.tab.c"
    break;

  case 55:
#line 876 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" factor : variable "<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2557 "y.tab.c"
    break;

  case 56:
#line 887 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" factor : ID LPAREN argument_list RPAREN"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									(yyval.vecv)->push_back((yyvsp[-3].siv));
      									(yyval.vecv)->push_back(new SymbolInfo("(","LPAREN"));
									
      									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[-1].vecv)->begin(); i != (yyvsp[-1].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
      									
      									(yyval.vecv)->push_back(new SymbolInfo(")","RPAREN"));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(yyvsp[-1].vecv)->clear();
 		  						}
#line 2578 "y.tab.c"
    break;

  case 57:
#line 903 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" factor : LPAREN expression RPAREN"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									(yyval.vecv)->push_back(new SymbolInfo("(","LPAREN"));
									
      									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[-1].vecv)->begin(); i != (yyvsp[-1].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
      									
      									(yyval.vecv)->push_back(new SymbolInfo(")","RPAREN"));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(yyvsp[-1].vecv)->clear();
 		  						}
#line 2598 "y.tab.c"
    break;

  case 58:
#line 918 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" factor : CONST_INT"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
      									(yyval.vecv)->push_back((yyvsp[0].siv));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
 		  						}
#line 2612 "y.tab.c"
    break;

  case 59:
#line 927 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" factor : CONST_FLOAT "<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
      									(yyval.vecv)->push_back((yyvsp[0].siv));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
 		  						}
#line 2626 "y.tab.c"
    break;

  case 60:
#line 936 "parser.y"
                                                                {
 		  							cout<<"At line no : "<<getline()<<" factor : variable INCOP"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[-1].vecv)->begin(); i != (yyvsp[-1].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
      									(yyval.vecv)->push_back((yyvsp[0].siv));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(yyvsp[-1].vecv)->clear();
 		  						}
#line 2643 "y.tab.c"
    break;

  case 61:
#line 948 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" factor : variable DECOP"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[-1].vecv)->begin(); i != (yyvsp[-1].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
      									(yyval.vecv)->push_back((yyvsp[0].siv));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(yyvsp[-1].vecv)->clear();
 		  						}
#line 2660 "y.tab.c"
    break;

  case 62:
#line 962 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" argument_list : arguments"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2676 "y.tab.c"
    break;

  case 63:
#line 973 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" argument_list : "<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
      									(yyval.vecv)->push_back(new SymbolInfo("","EMPTY"));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
 		  						}
#line 2690 "y.tab.c"
    break;

  case 64:
#line 984 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" arguments : arguments COMMA logic_expression"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[-2].vecv)->begin(); i != (yyvsp[-2].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
      									(yyval.vecv)->push_back(new SymbolInfo(",","COMMA"));
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(yyvsp[-2].vecv)->clear();
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2710 "y.tab.c"
    break;

  case 65:
#line 999 "parser.y"
                                                                {
 		  							cout<<"At line no: "<<getline()<<" arguments : logic_expression"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2726 "y.tab.c"
    break;


#line 2730 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 1013 "parser.y"

int main(int argc,char *argv[])
{

	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	freopen("log.txt","w",stdout);
	yyin=fp;
	yyparse();
	

	
	return 0;
}

