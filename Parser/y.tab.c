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
#line 1 "1705060.y"

#include<bits/stdc++.h>
#include "Symbol_table.h"

using namespace std;
ofstream error;
int yyparse(void);
int yylex(void);
extern FILE *yyin;
FILE* fp;
SymbolTable *st = new SymbolTable(30);

int line_count=1;
int err=0;
void IncLine(){
	line_count++;}
int getline()
	{return line_count;}
void IncErr(){
	err++;}
int getErr()
	{return err;}

void yyerror(char *s)
{
	//write your code
	cout<<"Error at line "<<getline()<<": Syntax Error"<<endl;
	error<<"Error at line "<<getline()<<": Syntax Error"<<endl;
	IncErr();
}
bool func=false;
string type,name,namef,typef;
vector<param*>plist;
vector<string>arglist;
vector<SymbolInfo*>vlist;

#line 107 "y.tab.c"

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
#line 37 "1705060.y"

int ival;
SymbolInfo* siv;
vector<SymbolInfo*>* vecv;

#line 239 "y.tab.c"

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
#define YYLAST   164

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  125

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
       0,    55,    55,    69,    85,   100,   113,   126,   141,   174,
     208,   214,   220,   262,   324,   347,   369,   390,   408,   425,
     440,   461,   481,   510,   565,   573,   581,   591,   607,   628,
     640,   657,   670,   689,   702,   715,   728,   768,   798,   835,
     866,   892,   929,   939,   954,   982,  1032,  1050,  1111,  1129,
    1171,  1189,  1231,  1249,  1306,  1324,  1400,  1436,  1470,  1490,
    1510,  1580,  1601,  1611,  1621,  1652,  1683,  1694,  1706,  1730
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
  "$accept", "start", "program", "unit", "func_declaration", "id",
  "in_func", "lookup", "lookup1", "func_definition", "parameter_list",
  "compound_statement", "newScope", "var_declaration", "type_specifier",
  "declaration_list", "statements", "statement", "expression_statement",
  "variable", "expression", "logic_expression", "rel_expression",
  "simple_expression", "term", "unary_expression", "factor",
  "argument_list", "arguments", YY_NULLPTR
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

#define YYPACT_NINF (-75)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-14)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,   -75,   -75,   -75,    12,    13,   -75,   -75,   -75,   -75,
      22,   -75,   -75,   -75,   -16,     2,    25,    21,    22,   -75,
      41,    10,    53,   -75,    59,    -1,    22,    46,    58,    66,
      59,    13,   -75,    65,   -75,   -75,   -75,    62,    66,    22,
     -75,    64,   -75,   -75,   -75,    78,    80,    82,   123,    83,
     123,   123,   123,   -75,   -75,   -75,   -75,    27,   -75,   -75,
      22,    96,   -75,   -75,    39,    84,   -75,    89,     9,    94,
     -75,   -75,   123,    51,   123,    85,    22,    43,   -75,   -75,
      92,   123,   123,    86,   -75,   -75,   -75,   -75,   123,   -75,
     123,   123,   123,   123,    93,    51,    99,   -75,   100,   -75,
     -75,   101,    91,   105,   -75,   -75,    94,   120,   -75,   128,
     123,   128,   107,   -75,   123,   -75,   140,   124,   -75,   -75,
     -75,   128,   128,   -75,   -75
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    26,    24,    25,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    10,    29,     0,     0,     0,     0,    23,
       0,     0,    27,    30,    12,     0,    19,     0,     0,     0,
      12,     0,    18,     0,     9,    22,    15,     0,     0,    17,
      28,     0,     8,    14,    16,     0,     0,     0,     0,     0,
       0,     0,     0,    21,    42,    62,    63,    44,    35,    33,
       0,     0,    31,    34,    59,     0,    46,    48,    50,    52,
      54,    58,     0,     0,     0,     0,     0,    59,    56,    57,
       0,    67,     0,    29,    20,    32,    64,    65,     0,    43,
       0,     0,     0,     0,     0,     0,     0,    41,     0,    61,
      69,     0,    66,     0,    47,    49,    53,    51,    55,     0,
       0,     0,     0,    60,     0,    45,    37,     0,    39,    40,
      68,     0,     0,    38,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   -75,   -75,   141,   -75,   -10,   -75,   119,   121,   -75,
     -75,   -19,   -75,    49,    17,   -75,   -75,   -58,   -67,   -49,
     -37,   -74,    68,    71,    63,   -46,   -75,   -75,   -75
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    57,    17,    28,    29,     8,
      25,    58,    41,    59,    60,    15,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,   101,   102
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      14,    77,    77,    85,    78,    79,    95,   100,    22,   -11,
      36,    75,    11,    16,   104,    80,    32,    10,     1,    43,
       2,     1,    10,     2,     3,    30,    91,     3,   110,    44,
      31,    92,    77,    18,    19,    94,    24,    96,    26,    77,
     120,    77,    77,    77,    77,   103,    21,   108,    39,     9,
      83,   116,    81,   118,     9,    13,    82,    86,    87,    20,
      88,    86,    87,   123,   124,    77,    98,    45,    50,    46,
      47,    23,     1,   117,     2,    51,    52,    48,     3,    49,
      33,    50,    27,    54,    13,    55,   -13,    56,    51,    52,
      34,    35,    53,    35,    42,    40,    54,    13,    55,    45,
      56,    46,    47,    72,     1,    73,     2,    74,    76,    48,
       3,    49,    90,    50,    93,    16,    89,    97,    99,   109,
      51,    52,   114,    35,    84,   111,   112,   113,    54,    13,
      55,    45,    56,    46,    47,   115,     1,    91,     2,   119,
      50,    48,     3,    49,   121,    50,    12,    51,    52,    37,
     122,    38,    51,    52,   106,    35,    13,    55,   105,    56,
      54,    13,    55,   107,    56
};

static const yytype_int8 yycheck[] =
{
      10,    50,    51,    61,    50,    51,    73,    81,    18,    25,
      29,    48,     0,    29,    88,    52,    26,     0,     8,    38,
      10,     8,     5,    10,    14,    26,    17,    14,    95,    39,
      31,    22,    81,    31,    32,    72,    26,    74,    21,    88,
     114,    90,    91,    92,    93,    82,    25,    93,    31,     0,
      60,   109,    25,   111,     5,    33,    29,    18,    19,    34,
      21,    18,    19,   121,   122,   114,    76,     3,    17,     5,
       6,    30,     8,   110,    10,    24,    25,    13,    14,    15,
      34,    17,    29,    32,    33,    34,    27,    36,    24,    25,
      32,    27,    28,    27,    32,    30,    32,    33,    34,     3,
      36,     5,     6,    25,     8,    25,    10,    25,    25,    13,
      14,    15,    23,    17,    20,    29,    32,    32,    26,    26,
      24,    25,    31,    27,    28,    26,    26,    26,    32,    33,
      34,     3,    36,     5,     6,    30,     8,    17,    10,    32,
      17,    13,    14,    15,     4,    17,     5,    24,    25,    30,
      26,    30,    24,    25,    91,    27,    33,    34,    90,    36,
      32,    33,    34,    92,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    10,    14,    39,    40,    41,    42,    47,    51,
      52,     0,    41,    33,    43,    53,    29,    44,    31,    32,
      34,    25,    43,    30,    26,    48,    52,    29,    45,    46,
      26,    31,    43,    34,    32,    27,    49,    45,    46,    52,
      30,    50,    32,    49,    43,     3,     5,     6,    13,    15,
      17,    24,    25,    28,    32,    34,    36,    43,    49,    51,
      52,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    25,    25,    25,    58,    25,    57,    63,    63,
      58,    25,    29,    43,    28,    55,    18,    19,    21,    32,
      23,    17,    22,    20,    58,    56,    58,    32,    43,    26,
      59,    65,    66,    58,    59,    60,    62,    61,    63,    26,
      56,    26,    26,    26,    31,    30,    55,    58,    55,    32,
      59,     4,    26,    55,    55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    41,    42,    42,
      43,    44,    45,    46,    47,    47,    48,    48,    48,    48,
      49,    49,    50,    51,    52,    52,    52,    53,    53,    53,
      53,    54,    54,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    56,    56,    57,    57,    58,    58,    59,    59,
      60,    60,    61,    61,    62,    62,    63,    63,    63,    64,
      64,    64,    64,    64,    64,    64,    65,    65,    66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     8,     7,
       1,     0,     0,     0,     8,     7,     4,     3,     2,     1,
       4,     3,     0,     3,     1,     1,     1,     3,     6,     1,
       4,     1,     2,     1,     1,     1,     7,     5,     7,     5,
       5,     3,     1,     2,     1,     4,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     2,     2,     1,     1,
       4,     3,     1,     1,     2,     2,     1,     0,     3,     1
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
#line 56 "1705060.y"
        {
		(yyval.vecv)=new vector<SymbolInfo*>();
		vector<SymbolInfo*>::iterator i;
		for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
		(yyval.vecv)->push_back((*i));
		cout<<"Line "<<getline()<<":"<<" start : program"<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		(yyvsp[0].vecv)->clear();
	}
#line 1518 "y.tab.c"
    break;

  case 3:
#line 69 "1705060.y"
                        {
					vector<SymbolInfo*>::iterator i;
					(yyval.vecv)=new vector<SymbolInfo*>();
					for (i = (yyvsp[-1].vecv)->begin(); i != (yyvsp[-1].vecv)->end(); ++i) 
						(yyval.vecv)->push_back((*i));
					for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
						(yyval.vecv)->push_back(*i);
					cout<<"Line "<<getline()<<":"<<" program : program unit"<<endl;
					cout<<endl;
					for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
						cout<<(*i)->get_name();
					cout<<endl;
					cout<<endl;
					(yyvsp[-1].vecv)->clear();
					(yyvsp[0].vecv)->clear();
				}
#line 1539 "y.tab.c"
    break;

  case 4:
#line 85 "1705060.y"
                                {
					(yyval.vecv)=new vector<SymbolInfo*>();
					vector<SymbolInfo*>::iterator i;
					for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
						(yyval.vecv)->push_back((*i));
					cout<<"Line "<<getline()<<":"<<" program : unit"<<endl;
					cout<<endl;
					for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
						cout<<(*i)->get_name();
					cout<<endl;
					cout<<endl;
					(yyvsp[0].vecv)->clear();
				}
#line 1557 "y.tab.c"
    break;

  case 5:
#line 100 "1705060.y"
                                {
					(yyval.vecv)=new vector<SymbolInfo*>();
					vector<SymbolInfo*>::iterator i;
					for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
						(yyval.vecv)->push_back((*i));
					cout<<"Line "<<getline()<<":"<<" unit : var_declaration"<<endl;
					cout<<endl;
					for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
						cout<<(*i)->get_name();
					cout<<endl;
					cout<<endl;
					(yyvsp[0].vecv)->clear();
				}
#line 1575 "y.tab.c"
    break;

  case 6:
#line 113 "1705060.y"
                        {
     					(yyval.vecv)=new vector<SymbolInfo*>();
					vector<SymbolInfo*>::iterator i;
					for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
						(yyval.vecv)->push_back((*i));
					cout<<"Line "<<getline()<<":"<<" unit : func_declaration"<<endl;
					cout<<endl;
					for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
						cout<<(*i)->get_name();
					cout<<endl;
					cout<<endl;
					(yyvsp[0].vecv)->clear();
     				}
#line 1593 "y.tab.c"
    break;

  case 7:
#line 126 "1705060.y"
                                {
     					(yyval.vecv)=new vector<SymbolInfo*>();
					vector<SymbolInfo*>::iterator i;
					for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
						(yyval.vecv)->push_back((*i));
					cout<<"Line "<<getline()<<":"<<" unit : func_definition"<<endl;
					cout<<endl;
					for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
						cout<<(*i)->get_name();
					cout<<endl;
					cout<<endl;
					(yyvsp[0].vecv)->clear();
     				}
#line 1611 "y.tab.c"
    break;

  case 8:
#line 141 "1705060.y"
                                                                                                {
											cout<<"Line "<<getline()<<":"<<" func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON"<<endl;
											cout<<endl;
											vector<param*>::iterator j;
											(yyval.vecv)=new vector<SymbolInfo*>();
											(yyval.vecv)->push_back((yyvsp[-7].siv));
											(yyval.vecv)->push_back(new SymbolInfo(" ","space"));
											(yyval.vecv)->push_back((yyvsp[-6].siv));
											(yyval.vecv)->push_back(new SymbolInfo("(","LPAREN"));
											vector<SymbolInfo*>::iterator i;
											for (i = (yyvsp[-3].vecv)->begin(); i != (yyvsp[-3].vecv)->end(); ++i) 
												(yyval.vecv)->push_back((*i));
											(yyval.vecv)->push_back(new SymbolInfo(")","RPAREN"));
											(yyval.vecv)->push_back(new SymbolInfo(";","SEMICOLON"));
											(yyval.vecv)->push_back(new SymbolInfo("\n","newline"));
											for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
												cout<<(*i)->get_name();
      											cout<<endl;
      											cout<<endl;
      											func=false;
											for (j = plist.begin(); j != plist.end(); ++j)
											{
											delete (*j);
											}
											plist.clear();
											for (i= vlist.begin(); i != vlist.end(); ++i)
											{
											delete (*i);
											}
											vlist.clear();
											(yyvsp[-3].vecv)->clear();
		
										}
#line 1649 "y.tab.c"
    break;

  case 9:
#line 174 "1705060.y"
                                                                                                {
											cout<<"Line "<<getline()<<":"<<" func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON"<<endl;
											cout<<endl;
											
											vector<SymbolInfo*>::iterator i;
											vector<param*>::iterator j;
											(yyval.vecv)=new vector<SymbolInfo*>();
											(yyval.vecv)->push_back((yyvsp[-6].siv));
											(yyval.vecv)->push_back(new SymbolInfo(" ","space"));
											(yyval.vecv)->push_back((yyvsp[-5].siv));
											(yyval.vecv)->push_back(new SymbolInfo("(","LPAREN"));
											(yyval.vecv)->push_back(new SymbolInfo(")","RPAREN"));
											(yyval.vecv)->push_back(new SymbolInfo(";","SEMICOLON"));
											(yyval.vecv)->push_back(new SymbolInfo("\n","newline"));
											for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
											cout<<(*i)->get_name();
											func=false;
											for (j = plist.begin(); j != plist.end(); ++j)
											{
											delete (*j);
											}
											plist.clear();
											for (i= vlist.begin(); i != vlist.end(); ++i)
											{
											delete (*i);
											}
											vlist.clear();
											
      											cout<<endl;
											cout<<endl;
		
										}
#line 1686 "y.tab.c"
    break;

  case 10:
#line 208 "1705060.y"
        {
		(yyval.siv)=new SymbolInfo((yyvsp[0].siv)->get_name(),"ID");
		name=(yyvsp[0].siv)->get_name();
		//func=true;
	}
#line 1696 "y.tab.c"
    break;

  case 11:
#line 214 "1705060.y"
          {
		func=true;
		namef=name;
		typef=type;	
	  }
#line 1706 "y.tab.c"
    break;

  case 12:
#line 220 "1705060.y"
        {
		vector<param*>::iterator j;
	 	if(st->lookup_symbol(namef)==NULL)
		{
		SymbolInfo* si=new SymbolInfo(namef,"ID",typef);
		si->set_func();
		
		for (j = plist.begin(); j != plist.end(); ++j)
		{
		si->addParam((*j)->get_ptype(),(*j)->get_pname());
		delete (*j);
		}
		si->set_func();
		st->insert_symbol(si);
		plist.clear();
		typef.clear();
		namef.clear();
		}
		else
		{
		SymbolInfo* f=st->lookup_symbol(namef);
		if(!f->isFunc())
		{
		cout<<"Error at line "<<getline()<<":  function  with non-function type identifier "<<namef<<endl<<endl;
		error<<"Error at line "<<getline()<<": function  with non-function type identifier "<<namef<<endl<<endl;
		IncErr();
		}
		else
		{
		cout<<"Error at line "<<getline()<<": Multiple declaration of function "<<namef<<" in parameter"<<endl<<endl;
		error<<"Error at line "<<getline()<<": Multiple declaration of function"<<namef<<" in parameter"<<endl<<endl;
		IncErr();
		}
		for (j = plist.begin(); j != plist.end(); ++j)
		{
		delete (*j);
		}
		plist.clear();
		}
		
	}
#line 1752 "y.tab.c"
    break;

  case 13:
#line 262 "1705060.y"
         {
	 	vector<param*>::iterator j;
	 	if(st->lookup_symbol(namef)==NULL)
		{
		SymbolInfo* si=new SymbolInfo(namef,"ID",typef);
		si->set_func();
		
		for (j = plist.begin(); j != plist.end(); ++j)
		{
		si->addParam((*j)->get_ptype(),(*j)->get_pname());
		
		delete (*j);
		}
		si->set_func();
		//error<<namef<<" "<<si->get_listSize()<<endl;
		st->insert_symbol(si);
		plist.clear();
		
		}
		else
		{
		SymbolInfo* f=st->lookup_symbol(namef);
		if(!f->isFunc())
		{
		cout<<"Error at line "<<getline()<<":  Multiple declaration of "<<namef<<endl<<endl;
		error<<"Error at line "<<getline()<<": Multiple declaration of "<<namef<<endl<<endl;
		IncErr();
		}
		else if(f->get_listSize()!=plist.size())
		{
		cout<<"Error at line "<<getline()<<":  Total number of arguments mismatch with declaration in function "<<namef<<endl<<endl;
		error<<"Error at line "<<getline()<<": Total number of arguments mismatch with declaration in function "<<namef<<endl<<endl;
		IncErr();
		}
		else {
		for(int k=0;k<plist.size();k++)
		{
		if((f->getParam(k))->get_ptype()!=plist[k]->get_ptype())
		{
		cout<<"Error at line "<<getline()<<":  Argument mismatch with declaration in function "<<namef<<endl<<endl;
		error<<"Error at line "<<getline()<<" : Argument mismatch with declaration in function "<<namef<<endl<<endl;
		IncErr();
		break;
		}
		}
		}
		if(typef!=f->get_dType())
		{
		cout<<"Error at line "<<getline()<<":  Return type mismatch with function declaration in function "<<namef<<endl<<endl;
		error<<"Error at line "<<getline()<<": Return type mismatch with function declaration in function "<<namef<<endl<<endl;
		IncErr();
		}
		for (j = plist.begin(); j != plist.end(); ++j)
		{
		delete (*j);
		}
		plist.clear();
		//error<<namef<<" "<<f->get_listSize();
		}
		
	}
#line 1818 "y.tab.c"
    break;

  case 14:
#line 324 "1705060.y"
                                                                                                        {
												cout<<"Line "<<getline()<<":"<<" func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement"<<endl;
											cout<<endl;
											(yyval.vecv)=new vector<SymbolInfo*>();
											(yyval.vecv)->push_back((yyvsp[-7].siv));
											(yyval.vecv)->push_back(new SymbolInfo(" ","space"));
											(yyval.vecv)->push_back((yyvsp[-6].siv));
											
											(yyval.vecv)->push_back(new SymbolInfo("(","LPAREN"));
											vector<SymbolInfo*>::iterator i;
											for (i = (yyvsp[-3].vecv)->begin(); i != (yyvsp[-3].vecv)->end(); ++i) 
												(yyval.vecv)->push_back((*i));
											
											(yyval.vecv)->push_back(new SymbolInfo(")","RPAREN"));
											for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
												(yyval.vecv)->push_back((*i));
											for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
												cout<<(*i)->get_name();
      											cout<<endl;
      											cout<<endl;
      											(yyvsp[-3].vecv)->clear();
      											(yyvsp[0].vecv)->clear();
											}
#line 1846 "y.tab.c"
    break;

  case 15:
#line 347 "1705060.y"
                                                                                                        {
											cout<<"Line "<<getline()<<":"<<" func_definition : type_specifier ID LPAREN RPAREN compound_statement"<<endl;
											cout<<endl;
											(yyval.vecv)=new vector<SymbolInfo*>();
											(yyval.vecv)->push_back((yyvsp[-6].siv));
											(yyval.vecv)->push_back(new SymbolInfo(" ","space"));
											(yyval.vecv)->push_back((yyvsp[-5].siv));
											
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
#line 1870 "y.tab.c"
    break;

  case 16:
#line 369 "1705060.y"
                                                                {
									cout<<"Line "<<getline()<<":"<<" parameter_list : parameter_list COMMA type_specifier ID"<<endl;
									cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[-3].vecv)->begin(); i != (yyvsp[-3].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									(yyval.vecv)->push_back(new SymbolInfo(",","COMMA"));
									(yyval.vecv)->push_back((yyvsp[-1].siv));
									(yyval.vecv)->push_back(new SymbolInfo(" ","space"));
									(yyval.vecv)->push_back((yyvsp[0].siv));
									param* p=new param((yyvsp[-1].siv)->get_name(),(yyvsp[0].siv)->get_name());
									plist.push_back(p);
									SymbolInfo* si=new SymbolInfo((yyvsp[0].siv)->get_name(),"ID",(yyvsp[-1].siv)->get_name());
									vlist.push_back(si);
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									(yyvsp[-3].vecv)->clear();	
								}
#line 1896 "y.tab.c"
    break;

  case 17:
#line 390 "1705060.y"
                                                                {
									cout<<"Line "<<getline()<<":"<<" parameter_list : parameter_list COMMA type_specifier"<<endl;
									cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									param* p=new param((yyvsp[0].siv)->get_name(),"");
									plist.push_back(p);
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
#line 1919 "y.tab.c"
    break;

  case 18:
#line 408 "1705060.y"
                                                                {
									cout<<"Line "<<getline()<<":"<<" parameter_list : type_specifier ID"<<endl;
									cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									param* p=new param((yyvsp[-1].siv)->get_name(),(yyvsp[0].siv)->get_name());
									plist.push_back(p);
									SymbolInfo* si=new SymbolInfo((yyvsp[0].siv)->get_name(),"ID",(yyvsp[-1].siv)->get_name());
									vlist.push_back(si);
									(yyval.vecv)->push_back((yyvsp[-1].siv));
									(yyval.vecv)->push_back(new SymbolInfo(" ","space"));
									(yyval.vecv)->push_back((yyvsp[0].siv));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
									cout<<endl;
								}
#line 1941 "y.tab.c"
    break;

  case 19:
#line 425 "1705060.y"
                                                                {
									cout<<"Line "<<getline()<<":"<<" parameter_list : type_specifier"<<endl;
									param* p=new param((yyvsp[0].siv)->get_name(),"");
									plist.push_back(p);
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									(yyval.vecv)->push_back((yyvsp[0].siv));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
										
								}
#line 1958 "y.tab.c"
    break;

  case 20:
#line 440 "1705060.y"
                                                                        {
									cout<<"Line "<<getline()<<":"<<" compound_statement : LCURL statements RCURL"<<endl;
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
#line 1984 "y.tab.c"
    break;

  case 21:
#line 461 "1705060.y"
                                                                        {
									cout<<"Line "<<getline()<<":"<<" compound_statement : LCURL  RCURL"<<endl;
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
#line 2008 "y.tab.c"
    break;

  case 22:
#line 481 "1705060.y"
                {
			(yyval.ival)=-1;
			st->enterScope();
			if(func)
			{
		
			  vector<SymbolInfo*>::iterator j;
			  for ( j=vlist.begin(); j !=vlist.end(); ++j) 
			  {
			  	
			  	SymbolInfo* si=new SymbolInfo((*j)->get_name(),(*j)->get_type(),(*j)->get_dType());
			  	
			  	if(st->insert_symbol(si))
			  	{}
			  	else
			  	{
			  	cout<<"Error at line "<<getline()<<": Multiple declaration of "<<(*j)->get_name()<<" in parameter"<<endl<<endl;
				error<<"Error at line "<<getline()<<": Multiple declaration of "<<(*j)->get_name()<<" in parameter"<<endl<<endl;
				IncErr();
			  	}
			  	delete (*j);
			  }
			  vlist.clear();
			  func=false;
			}
			
			
		}
#line 2041 "y.tab.c"
    break;

  case 23:
#line 510 "1705060.y"
                                                                {
									cout<<"Line "<<getline()<<":"<<" var_declaration : type_specifier declaration_list SEMICOLON"<<endl;
									cout<<endl;
									bool a=true;
									(yyval.vecv)=new vector<SymbolInfo*>();
									(yyval.vecv)->push_back((yyvsp[-2].siv));
									type=(yyvsp[-2].siv)->get_name();
									(yyval.vecv)->push_back(new SymbolInfo(" ","space"));
									vector<SymbolInfo*>::iterator i;
									if(type=="void")
									{
										cout<<"Error at line "<<getline()<<": Variable type cannot be void"<<endl<<endl;
										error<<"Error at line "<<getline()<<": Variable type cannot be void"<<endl<<endl;
									
										IncErr();
										a=false;
										
									}
									for (i = (yyvsp[-1].vecv)->begin(); i != (yyvsp[-1].vecv)->end(); ++i) 
									{
										
										
										if(((*i)->get_type()=="ID")&&a)
										{
											//(*i)->set_dType(type);
											
											SymbolInfo* si=new SymbolInfo((*i)->get_name(),"ID",type);
											if(st->insert_symbol(si))
											{
											if((*i)->get_varSize()!=-1)
											   si->set_varSize((*i)->get_varSize());
											}
											else
											{
											cout<<"Error at line "<<getline()<<": Multiple declaration of "<<(*i)->get_name()<<endl<<endl;
											error<<"Error at line "<<getline()<<": Multiple declaration of "<<(*i)->get_name()<<endl<<endl;
									
											IncErr();
											}
											
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
#line 2099 "y.tab.c"
    break;

  case 24:
#line 565 "1705060.y"
                                {
					cout<<"Line "<<getline()<<":"<<" type_specifier : INT"<<endl;
					cout<<endl;
					(yyval.siv)=new SymbolInfo("int","INT");
					cout<<(yyval.siv)->get_name()<<endl;
					cout<<endl;
					type="int";
				}
#line 2112 "y.tab.c"
    break;

  case 25:
#line 573 "1705060.y"
                        {
					cout<<"Line "<<getline()<<":"<<" type_specifier : FLOAT"<<endl;
					cout<<endl;
					(yyval.siv)=new SymbolInfo("float","FLOAT");
					cout<<(yyval.siv)->get_name()<<endl;
					cout<<endl;
					type="float";
				}
#line 2125 "y.tab.c"
    break;

  case 26:
#line 581 "1705060.y"
                                {
					cout<<"Line "<<getline()<<":"<<" type_specifier : VOID"<<endl;
					cout<<endl;
					(yyval.siv)=new SymbolInfo("void","VOID");
					cout<<(yyval.siv)->get_name()<<endl;
					cout<<endl;
					type="void";
				}
#line 2138 "y.tab.c"
    break;

  case 27:
#line 591 "1705060.y"
                                                                {
									cout<<"Line "<<getline()<<":"<<" declaration_list : declaration_list COMMA ID"<<endl;
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
#line 2159 "y.tab.c"
    break;

  case 28:
#line 607 "1705060.y"
                                                                        {
										cout<<"Line "<<getline()<<":"<<" declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD"<<endl;
										cout<<endl;
										(yyval.vecv)=new vector<SymbolInfo*>();
										vector<SymbolInfo*>::iterator i;
										for (i = (yyvsp[-5].vecv)->begin(); i != (yyvsp[-5].vecv)->end(); ++i) 
											(yyval.vecv)->push_back((*i));
      										(yyval.vecv)->push_back(new SymbolInfo(",","COMMA"));
      										(yyvsp[-3].siv)->set_varSize(stoi((yyvsp[-1].siv)->get_name()));
      										//cout<<$3->get_varSize()<<endl;;
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
#line 2185 "y.tab.c"
    break;

  case 29:
#line 628 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" declaration_list : ID"<<endl;
 		  							cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									
									(yyval.vecv)->push_back((yyvsp[0].siv));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
 		  						}
#line 2202 "y.tab.c"
    break;

  case 30:
#line 640 "1705060.y"
                                                        {
 		  							cout<<"Line "<<getline()<<":"<<" declaration_list : ID LTHIRD CONST_INT RTHIRD"<<endl;
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
#line 2222 "y.tab.c"
    break;

  case 31:
#line 657 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" statements : statement"<<endl;
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
#line 2240 "y.tab.c"
    break;

  case 32:
#line 670 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" statements : statements statement"<<endl;
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
#line 2262 "y.tab.c"
    break;

  case 33:
#line 689 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" statement : var_declaration"<<endl;
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
#line 2280 "y.tab.c"
    break;

  case 34:
#line 702 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" statement : expression_statement"<<endl;
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
#line 2298 "y.tab.c"
    break;

  case 35:
#line 715 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" statement : compound_statement"<<endl;
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
#line 2316 "y.tab.c"
    break;

  case 36:
#line 728 "1705060.y"
                                                                                                {
	  													cout<<"Line "<<getline()<<":"<<" statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement"<<endl;
	  													cout<<endl;
														(yyval.vecv)=new vector<SymbolInfo*>();
														(yyval.vecv)->push_back(new SymbolInfo("for","FOR"));
														(yyval.vecv)->push_back(new SymbolInfo("(","LPAREN"));
														vector<SymbolInfo*>::iterator i;
														for (i = (yyvsp[-4].vecv)->begin(); i != (yyvsp[-4].vecv)->end(); ++i) 
														if((*i)->get_name()!="\n")
															(yyval.vecv)->push_back((*i));
      														
														for (i = (yyvsp[-3].vecv)->begin(); i != (yyvsp[-3].vecv)->end(); ++i) 
														if((*i)->get_name()!="\n")
															(yyval.vecv)->push_back((*i));
      														string t;
									for (i = (yyvsp[-2].vecv)->begin(); i != (yyvsp[-2].vecv)->end(); ++i) 
									{
										t=(*i)->get_dType();
										if((*i)->get_name()!="\n")
										(yyval.vecv)->push_back((*i));
									}
									if(t=="void")
									{
									cout<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									IncErr();
									}
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
#line 2361 "y.tab.c"
    break;

  case 37:
#line 768 "1705060.y"
                                                                        {
 		  							cout<<"Line "<<getline()<<":"<<" statement : IF LPAREN expression RPAREN statement"<<endl;
 		  							cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									(yyval.vecv)->push_back(new SymbolInfo("if","IF"));
									(yyval.vecv)->push_back(new SymbolInfo(" ","newline"));
									(yyval.vecv)->push_back(new SymbolInfo("(","LPAREN"));
									vector<SymbolInfo*>::iterator i;
									string t;
									for (i = (yyvsp[-2].vecv)->begin(); i != (yyvsp[-2].vecv)->end(); ++i) 
									{
										t=(*i)->get_dType();
										(yyval.vecv)->push_back((*i));
									}
									if(t=="void")
									{
									cout<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									IncErr();
									}
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
#line 2396 "y.tab.c"
    break;

  case 38:
#line 798 "1705060.y"
                                                                        {
 		  							cout<<"Line "<<getline()<<":"<<" statement : IF LPAREN expression RPAREN statement ELSE statement"<<endl;
 		  							cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									(yyval.vecv)->push_back(new SymbolInfo("if","IF"));
									(yyval.vecv)->push_back(new SymbolInfo(" ","newline"));
									(yyval.vecv)->push_back(new SymbolInfo("(","LPAREN"));
									vector<SymbolInfo*>::iterator i;
									string t;
									for (i = (yyvsp[-4].vecv)->begin(); i != (yyvsp[-4].vecv)->end(); ++i) 
									{
										t=(*i)->get_dType();
										(yyval.vecv)->push_back((*i));
									}
									if(t=="void")
									{
									cout<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									IncErr();
									}
      									(yyval.vecv)->push_back(new SymbolInfo(")","RPAREN"));
      									
									for (i = (yyvsp[-2].vecv)->begin(); i != (yyvsp[-2].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
      									(yyval.vecv)->push_back(new SymbolInfo("else","ELSE"));
      									(yyval.vecv)->push_back(new SymbolInfo("\n","newline"));
      									
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
#line 2438 "y.tab.c"
    break;

  case 39:
#line 835 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" statement : WHILE LPAREN expression RPAREN statement"<<endl;
 		  							cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									string t;
									(yyval.vecv)->push_back(new SymbolInfo("while","WHILE"));
									(yyval.vecv)->push_back(new SymbolInfo(" ","space"));
									(yyval.vecv)->push_back(new SymbolInfo("(","LPAREN"));
									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[-2].vecv)->begin(); i != (yyvsp[-2].vecv)->end(); ++i) 
									{
										t=(*i)->get_dType();
										(yyval.vecv)->push_back((*i));
									}
									if(t=="void")
									{
									cout<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									IncErr();
									}
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
#line 2474 "y.tab.c"
    break;

  case 40:
#line 866 "1705060.y"
                                                        {
 		  							cout<<"Line "<<getline()<<":"<<" statement : PRINTLN LPAREN ID RPAREN SEMICOLON"<<endl;
 		  							cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									SymbolInfo* v=st->lookup_symbol((yyvsp[-2].siv)->get_name());
      									if(v==NULL)
      									{
      									cout<<"Error at line "<<getline()<<": Undeclared variable  "<<(yyvsp[-2].siv)->get_name()<<endl<<endl;
									error<<"Error at line "<<getline()<<": Undeclared variable "<<(yyvsp[-2].siv)->get_name()<<endl<<endl;
									
									IncErr();
      									}
      						
									(yyval.vecv)->push_back(new SymbolInfo("printf","PRINTLN"));
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
#line 2505 "y.tab.c"
    break;

  case 41:
#line 892 "1705060.y"
                                                        {
 		  							cout<<"Line "<<getline()<<":"<<" statement : RETURN expression SEMICOLON"<<endl;
 		  							cout<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									(yyval.vecv)->push_back(new SymbolInfo("return","RETURN"));
									(yyval.vecv)->push_back(new SymbolInfo(" ","space"));
									vector<SymbolInfo*>::iterator i;
									string t;
									for (i = (yyvsp[-1].vecv)->begin(); i != (yyvsp[-1].vecv)->end(); ++i)
									{ 
										(yyval.vecv)->push_back((*i));
										t=(*i)->get_dType();
									}
									//error<<t<<" "<<typef;
									
									if(t=="void")
									{
									cout<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									IncErr();
									}
									else if(t!=typef)
									{
									cout<<"Error at line "<<getline()<<":  Return type mismatch with function declaration in function "<<namef<<endl<<endl;
									error<<"Error at line "<<getline()<<": Return type mismatch with function declaration in function "<<namef<<endl<<endl;
									IncErr();
									}
      									(yyval.vecv)->push_back(new SymbolInfo(";","SEMICOLON"));
      									(yyval.vecv)->push_back(new SymbolInfo("\n","newline"));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									(yyvsp[-1].vecv)->clear();
 		  						}
#line 2545 "y.tab.c"
    break;

  case 42:
#line 929 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" expression_statement : SEMICOLON"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
      									(yyval.vecv)->push_back(new SymbolInfo(";","SEMICOLON"));
      									(yyval.vecv)->push_back(new SymbolInfo("\n","newline"));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
 		  						}
#line 2560 "y.tab.c"
    break;

  case 43:
#line 939 "1705060.y"
                                                        {
 		  							cout<<"Line "<<getline()<<":"<<" expression_statement : expression SEMICOLON"<<endl<<endl;
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
#line 2578 "y.tab.c"
    break;

  case 44:
#line 954 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" variable : ID"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									SymbolInfo* v=st->lookup_symbol((yyvsp[0].siv)->get_name());
      									if(v!=NULL)
      									{
      									(yyvsp[0].siv)->set_dType(v->get_dType());
      									//cout<<v->get_dType()<<" ";
      									(yyvsp[0].siv)->set_varSize(v->get_varSize());
      									if(v->get_varSize()>-1)
      									{
      									(yyvsp[0].siv)->set_dType(v->get_dType()+"arr");
      									}
      									}
      									else
      									{
      									cout<<"Error at line "<<getline()<<": Undeclared variable "<<(yyvsp[0].siv)->get_name()<<endl<<endl;
									error<<"Error at line "<<getline()<<": Undeclared variable "<<(yyvsp[0].siv)->get_name()<<endl<<endl;
									
									IncErr();
									(yyvsp[0].siv)->set_dType("int");
      									}
      									(yyval.vecv)->push_back((yyvsp[0].siv));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
 		  						}
#line 2611 "y.tab.c"
    break;

  case 45:
#line 982 "1705060.y"
                                                        {
 		  							cout<<"Line "<<getline()<<":"<<" variable : ID LTHIRD expression RTHIRD "<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									SymbolInfo* v=st->lookup_symbol((yyvsp[-3].siv)->get_name());
      									
      									if(v!=NULL)
      									{
      									(yyvsp[-3].siv)->set_dType(v->get_dType());
      									(yyvsp[-3].siv)->set_varSize(v->get_varSize());
      									if((yyvsp[-3].siv)->get_varSize()==-1)
      									{
      									cout<<"Error at line "<<getline()<<": "<<(yyvsp[-3].siv)->get_name()<<" not an array"<<endl<<endl;
									error<<"Error at line "<<getline()<<": "<<(yyvsp[-3].siv)->get_name()<<" not an array"<<endl<<endl;
									
									IncErr();
      									}
      									}
      									else
      									{
      									cout<<"Error at line "<<getline()<<": Undeclared variable  "<<(yyvsp[-3].siv)->get_name()<<endl<<endl;
									error<<"Error at line "<<getline()<<": Undeclared variable "<<(yyvsp[-3].siv)->get_name()<<endl<<endl;
									
									IncErr();
									(yyvsp[-3].siv)->set_dType("int");
      									}
      									
      									(yyval.vecv)->push_back((yyvsp[-3].siv));
      									(yyval.vecv)->push_back(new SymbolInfo("[","LTHIRD"));
      									vector<SymbolInfo*>::iterator i;
									string t;
									for (i = (yyvsp[-1].vecv)->begin(); i != (yyvsp[-1].vecv)->end(); ++i) 
									{
									 (yyval.vecv)->push_back((*i));
									 t=(*i)->get_dType();
									 }
									if(t!="int")
									{
									cout<<"Error at line "<<getline()<<": Expression inside third brackets not an integer"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Expression inside third brackets not an integer"<<endl<<endl;
									
									IncErr();
									}
      									(yyval.vecv)->push_back(new SymbolInfo("]","RTHIRD"));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(yyvsp[-1].vecv)->clear();
 		  						}
#line 2664 "y.tab.c"
    break;

  case 46:
#line 1032 "1705060.y"
                                                        {
 		  							cout<<"Line "<<getline()<<":"<<" expression : logic expression"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
      									string t;
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
									{
									 (yyval.vecv)->push_back((*i));
									  t=(*i)->get_dType();
									}
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType(t);
									}
      									cout<<endl<<endl;
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2687 "y.tab.c"
    break;

  case 47:
#line 1050 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" expression : variable ASSIGNOP logic_expression"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
      									SymbolInfo* v;
      									SymbolInfo* e;
									string t,t1;
									for (i = (yyvsp[-2].vecv)->begin(); i != (yyvsp[-2].vecv)->end(); ++i) 
									{
									 (yyval.vecv)->push_back((*i));
									}
									i=(yyvsp[-2].vecv)->begin();
									t=(*i)->get_dType();
									v=(*i);
      									(yyval.vecv)->push_back((yyvsp[-1].siv));
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
									{
									 (yyval.vecv)->push_back((*i));
									  t1=(*i)->get_dType();
									}
									i=(yyvsp[0].vecv)->begin();
									e=(*i);
									if(t1=="void")
									{
									 	cout<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
										error<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									
										IncErr();
									}
									else if(t!=t1&&t=="int")
									{
									cout<<"Error at line "<<getline()<<": Type Mismatch"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Type Mismatch"<<endl<<endl;
									
									IncErr();
									}
									else if(t!=t1&&(t1=="intarr"||t1=="floatarr"))
									{
										cout<<"Error at line "<<getline()<<": Type mismatch, "<<e->get_name()<<" is an array"<<endl<<endl;
										error<<"Error at line "<<getline()<<": Type mismatch, "<<e->get_name()<<" is an array"<<endl<<endl;
									
										IncErr();
									}
									else if(t!=t1&&(t=="intarr"||t=="floatarr"))
									{
										cout<<"Error at line "<<getline()<<": Type mismatch, "<<v->get_name()<<" is an array"<<endl<<endl;
										error<<"Error at line "<<getline()<<": Type mismatch, "<<v->get_name()<<" is an array"<<endl<<endl;
									
										IncErr();
									}
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType("int");
									}
      									cout<<endl<<endl;
      									(yyvsp[-2].vecv)->clear();
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2751 "y.tab.c"
    break;

  case 48:
#line 1111 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" logic_expression : rel_expression "<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									string t;
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
									{
									 (yyval.vecv)->push_back((*i));
									  t=(*i)->get_dType();
									}
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType(t);
									}
      									cout<<endl<<endl;
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2774 "y.tab.c"
    break;

  case 49:
#line 1129 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" logic_expression : rel_expression LOGICOP rel_expression"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									string t,t1;
									for (i = (yyvsp[-2].vecv)->begin(); i != (yyvsp[-2].vecv)->end(); ++i) 
									{
									 (yyval.vecv)->push_back((*i));
									  t=(*i)->get_dType();
									}
      									(yyval.vecv)->push_back((yyvsp[-1].siv));
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
									{
									 (yyval.vecv)->push_back((*i));
									  t1=(*i)->get_dType();
									}
									if((t1=="void")||(t=="void"))
									{
									cout<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									IncErr();
									}
									else if(t=="intarr"||t=="floatarr"||t1=="intarr"||t1=="floatarr")
									{
									
									cout<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									//tf=t1;
									
									IncErr();
									}
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType("int");
									}
      									cout<<endl<<endl;
      									(yyvsp[-2].vecv)->clear();
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2819 "y.tab.c"
    break;

  case 50:
#line 1171 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" rel_expression : simple_expression"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									string t;
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
									{
									 (yyval.vecv)->push_back((*i));
									  t=(*i)->get_dType();
									}
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType(t);
									}
      									cout<<endl<<endl;
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2842 "y.tab.c"
    break;

  case 51:
#line 1189 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" rel_expression : simple_expression RELOP simple_expression"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									string t,t1;
									for (i = (yyvsp[-2].vecv)->begin(); i != (yyvsp[-2].vecv)->end(); ++i) 
									{
									 (yyval.vecv)->push_back((*i));
									  t=(*i)->get_dType();
									}
      									(yyval.vecv)->push_back((yyvsp[-1].siv));
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
									{
									 (yyval.vecv)->push_back((*i));
									  t1=(*i)->get_dType();
									}
									if((t1=="void")||(t=="void"))
									{
									cout<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									IncErr();
									}
									else if(t=="intarr"||t=="floatarr"||t1=="intarr"||t1=="floatarr")
									{
									
									cout<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									//tf=t1;
									
									IncErr();
									}
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType("int");
									}
      									cout<<endl<<endl;
      									(yyvsp[-2].vecv)->clear();
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2887 "y.tab.c"
    break;

  case 52:
#line 1231 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" simple_expression : term "<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									string t;
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
									{
									 (yyval.vecv)->push_back((*i));
									  t=(*i)->get_dType();
									}
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType(t);
									}
      									cout<<endl<<endl;
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2910 "y.tab.c"
    break;

  case 53:
#line 1249 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" simple_expression : simple_expression ADDOP term "<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									string t,t1,tf;
									for (i = (yyvsp[-2].vecv)->begin(); i != (yyvsp[-2].vecv)->end(); ++i) 
									{
									 (yyval.vecv)->push_back((*i));
									  t=(*i)->get_dType();
									}
      									(yyval.vecv)->push_back((yyvsp[-1].siv));
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
									{
									 (yyval.vecv)->push_back((*i));
									  t1=(*i)->get_dType();
									}
									if((t=="void")||(t1=="void"))
									{
									 cout<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									IncErr();
									tf="int";
									}
									
									else if(t=="intarr"||t=="floatarr")
									{
									
									cout<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									tf=t1;
									
									IncErr();
									}
									else if(t1=="intarr"||t1=="floatarr")
									{
									
									cout<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									tf=t;
									
									IncErr();
									}
									else if(t1==t)
									tf=t;
									else 
									tf="float";
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType(tf);
									}
      									cout<<endl<<endl;
      									(yyvsp[-2].vecv)->clear();
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2970 "y.tab.c"
    break;

  case 54:
#line 1306 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" term : unary_expression"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									string t;
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
									{
									 (yyval.vecv)->push_back((*i));
									  t=(*i)->get_dType();
									}
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType(t);
									}
      									cout<<endl<<endl;
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 2993 "y.tab.c"
    break;

  case 55:
#line 1324 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" term : term MULOP unary_expression"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									string t,t1,tf;
									for (i = (yyvsp[-2].vecv)->begin(); i != (yyvsp[-2].vecv)->end(); ++i) 
									{
									 (yyval.vecv)->push_back((*i));
									  t=(*i)->get_dType();
									}
      									(yyval.vecv)->push_back((yyvsp[-1].siv));
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
									{
									 (yyval.vecv)->push_back((*i));
									  t1=(*i)->get_dType();
									}
									
									if((t=="void")||(t1=="void"))
									{
									 cout<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									IncErr();
									tf="int";
									}
									
									else if(t=="intarr"||t=="floatarr")
									{
									
									cout<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									tf=t1;
									
									IncErr();
									}
									else if(t1=="intarr"||t1=="floatarr")
									{
									
									cout<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									tf=t;
									
									IncErr();
									}
									else if(t1==t)
									tf=t;
									else 
									tf="float";
									if(((yyvsp[-1].siv)->get_name()=="%")&&(tf=="float"))
									{
									cout<<"Error at line "<<getline()<<": Non-Integer operand on modulus operator"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Non-Integer operand on modulus operator"<<endl<<endl;
									tf="int";
									IncErr();
									}
									if(((yyvsp[0].vecv)->size()==1))
									{
									 i=(yyvsp[0].vecv)->begin();
									 if((*i)->get_name()=="0")
									 {
									 cout<<"Error at line "<<getline()<<": Modulus by Zero"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Modulus by Zero"<<endl<<endl;
									tf="int";
									IncErr();
									 }
									}
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType(tf);
									}
      									cout<<endl<<endl;
      									(yyvsp[-2].vecv)->clear();
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 3072 "y.tab.c"
    break;

  case 56:
#line 1400 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" unary_expression : ADDOP unary_expression"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									(yyval.vecv)->push_back((yyvsp[-1].siv));
      									vector<SymbolInfo*>::iterator i;
									string t;
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
									{
									 (yyval.vecv)->push_back((*i));
									  t=(*i)->get_dType();
									}
									if(t=="void")
									{
									 cout<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									t="int";
									IncErr();
									}
									else if(t=="intarr"||t=="floatarr")
									{
									
									cout<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									t="int";
									
									IncErr();
									}
									
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType(t);
									}
      									cout<<endl<<endl;
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 3113 "y.tab.c"
    break;

  case 57:
#line 1436 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" unary_expression : NOT unary expression"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									(yyval.vecv)->push_back(new SymbolInfo("!","NOT"));
      									vector<SymbolInfo*>::iterator i;
									string t;
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
									{
									 (yyval.vecv)->push_back((*i));
									  t=(*i)->get_dType();
									}
									if(t=="void")
									{
									 cout<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									t="int";
									IncErr();
									}
									else if(t=="intarr"||t=="floatarr")
									{
									
									cout<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									
									IncErr();
									}
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType("int");
									}
      									cout<<endl<<endl;
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 3152 "y.tab.c"
    break;

  case 58:
#line 1470 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" unary_expression : factor"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									string t;
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
									{
									 (yyval.vecv)->push_back((*i));
									  t=(*i)->get_dType();
									}
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType(t);
									}
      									cout<<endl<<endl;
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 3175 "y.tab.c"
    break;

  case 59:
#line 1490 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" factor : variable "<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
      									string t;
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
									{
									 (yyval.vecv)->push_back((*i));
									 
									}
									i=(yyvsp[0].vecv)->begin();
									t=(*i)->get_dType();
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType(t);
									}
      									cout<<endl<<endl;
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 3200 "y.tab.c"
    break;

  case 60:
#line 1510 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" factor : ID LPAREN argument_list RPAREN"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									(yyval.vecv)->push_back((yyvsp[-3].siv));
									SymbolInfo* f=st->lookup_symbol((yyvsp[-3].siv)->get_name());
									string t;
									t="int";
									if(f==NULL)
									{
									cout<<"Error at line "<<getline()<<":  Undeclared function "<<(yyvsp[-3].siv)->get_name()<<endl<<endl;
									error<<"Error at line "<<getline()<<": Undeclared function "<<(yyvsp[-3].siv)->get_name()<<endl<<endl;
									IncErr();
									
									}
									else{
									if(f->isFunc())
									{
										t=f->get_dType();
										if(f->get_listSize()!=arglist.size())
										{
										//error<<f->get_name()<<" ";
										//error<<f->get_listSize()<<" "<<arglist.size()<<endl;
										cout<<"Error at line "<<getline()<<": Total number of arguments mismatch in function "<<(yyvsp[-3].siv)->get_name()<<endl<<endl;
										error<<"Error at line "<<getline()<<": Total number of arguments mismatch in function "<<(yyvsp[-3].siv)->get_name()<<endl<<endl;
										IncErr();
										}
									
										else
										{
										for(int j=0;j<arglist.size();j++)
										if((f->getParam(j))->get_ptype()!=arglist[j])
										{
										cout<<"Error at line "<<getline()<<":  Argument mismatch in function "<<(yyvsp[-3].siv)->get_name()<<endl<<endl;
										error<<"Error at line "<<getline()<<":  Argument mismatch in function "<<(yyvsp[-3].siv)->get_name()<<endl<<endl;
										
										IncErr();
										break;
										}
										
										}
										
										
										
									}
									else
									{
									cout<<"Error at line "<<getline()<<":  function  with non-function type identifier"<<endl<<endl;
									error<<"Error at line "<<getline()<<": function  with non-function type identifier"<<endl<<endl;
									IncErr();
									}
									}
      									(yyval.vecv)->push_back(new SymbolInfo("(","LPAREN"));
									
      									vector<SymbolInfo*>::iterator i;
      									
									for (i = (yyvsp[-1].vecv)->begin(); i != (yyvsp[-1].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
      									
      									(yyval.vecv)->push_back(new SymbolInfo(")","RPAREN"));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType(t);
									}
									for(int j=0;j<arglist.size();j++)
										arglist[j].clear();
										arglist.clear();
      									cout<<endl<<endl;
      									(yyvsp[-1].vecv)->clear();
 		  						}
#line 3275 "y.tab.c"
    break;

  case 61:
#line 1580 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" factor : LPAREN expression RPAREN"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									(yyval.vecv)->push_back(new SymbolInfo("(","LPAREN"));
									
      									vector<SymbolInfo*>::iterator i;
									string t;
									for (i = (yyvsp[-1].vecv)->begin(); i != (yyvsp[-1].vecv)->end(); ++i) 
									{
									 (yyval.vecv)->push_back((*i));
									 t=(*i)->get_dType();
									}
      									(yyval.vecv)->push_back(new SymbolInfo(")","RPAREN"));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType(t);
									}
      									cout<<endl<<endl;
      									(yyvsp[-1].vecv)->clear();
 		  						}
#line 3301 "y.tab.c"
    break;

  case 62:
#line 1601 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" factor : CONST_INT"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									(yyvsp[0].siv)->set_dType("int");
      									(yyval.vecv)->push_back((yyvsp[0].siv));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
 		  						}
#line 3316 "y.tab.c"
    break;

  case 63:
#line 1611 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" factor : CONST_FLOAT "<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									(yyvsp[0].siv)->set_dType("float");
      									(yyval.vecv)->push_back((yyvsp[0].siv));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
 		  						}
#line 3331 "y.tab.c"
    break;

  case 64:
#line 1621 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" factor : variable INCOP"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[-1].vecv)->begin(); i != (yyvsp[-1].vecv)->end(); ++i) 
									{
									(yyval.vecv)->push_back((*i));
									}
									i=(yyvsp[-1].vecv)->begin();
									if(((*i)->get_type()=="ID")&&((*i)->get_dType()=="float")){
									cout<<"Error at line "<<getline()<<": Can't increment float number"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Can't increment float number"<<endl<<endl;
									IncErr();
									}
									else if(((*i)->get_type()=="ID")&&((*i)->get_dType()!="int")){
									cout<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									
									IncErr();
									}
										
      									(yyval.vecv)->push_back((yyvsp[0].siv));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType("int");
									}
										
      									cout<<endl<<endl;
      									(yyvsp[-1].vecv)->clear();
 		  						}
#line 3367 "y.tab.c"
    break;

  case 65:
#line 1652 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" factor : variable DECOP"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[-1].vecv)->begin(); i != (yyvsp[-1].vecv)->end(); ++i) 
									{
									(yyval.vecv)->push_back((*i));
									}
									i=(yyvsp[-1].vecv)->begin();
									if(((*i)->get_type()=="ID")&&((*i)->get_dType()=="float")){
									cout<<"Error at line "<<getline()<<": Can't decrement float number"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Can't decrement float number"<<endl<<endl;
									IncErr();
									}
									else if(((*i)->get_type()=="ID")&&((*i)->get_dType()!="int")){
									cout<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									
									IncErr();
									}
      									(yyval.vecv)->push_back((yyvsp[0].siv));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType("int");
									}
      									cout<<endl<<endl;
      									(yyvsp[-1].vecv)->clear();
 		  						}
#line 3401 "y.tab.c"
    break;

  case 66:
#line 1683 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" argument_list : arguments"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 3417 "y.tab.c"
    break;

  case 67:
#line 1694 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" argument_list : "<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
      									(yyval.vecv)->push_back(new SymbolInfo("","EMPTY"));
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									
 		  						}
#line 3432 "y.tab.c"
    break;

  case 68:
#line 1706 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" arguments : arguments COMMA logic_expression"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
      									string t;
      									
									for (i = (yyvsp[-2].vecv)->begin(); i != (yyvsp[-2].vecv)->end(); ++i) 
										(yyval.vecv)->push_back((*i));
      									(yyval.vecv)->push_back(new SymbolInfo(",","COMMA"));
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
									{
									(yyval.vecv)->push_back((*i));
									t=(*i)->get_dType();
									
									}
									
									arglist.push_back(t);
									
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(yyvsp[-2].vecv)->clear();
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 3461 "y.tab.c"
    break;

  case 69:
#line 1730 "1705060.y"
                                                                {
 		  							cout<<"Line "<<getline()<<":"<<" arguments : logic_expression"<<endl<<endl;
									(yyval.vecv)=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
      									string t;
      									
									for (i = (yyvsp[0].vecv)->begin(); i != (yyvsp[0].vecv)->end(); ++i) 
									{
									(yyval.vecv)->push_back((*i));
									t=(*i)->get_dType();
									}
									arglist.push_back(t);	
									for (i = (yyval.vecv)->begin(); i != (yyval.vecv)->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(yyvsp[0].vecv)->clear();
 		  						}
#line 3483 "y.tab.c"
    break;


#line 3487 "y.tab.c"

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
#line 1750 "1705060.y"

int main(int argc,char *argv[])
{

	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}
	error.open("error.txt",ios::out);
	freopen("log.txt","w",stdout);
	yyin=fp;
	yyparse();
	st->print_all();
	cout<<endl;
	cout<<"Total lines: "<<getline()<<endl;
	cout<<"Total errors: "<<getErr()<<endl;

	
	return 0;
}

