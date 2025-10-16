/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "ex2.y"

	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include "ex2.h"
	#include "ex2.c"
	int yylex(void);
    extern FILE *yyin;
    FILE *fp;
    FILE *intermediate;
    void print(int);
    int yyerror(char const *s);

#line 85 "y.tab.c"

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

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    START = 258,                   /* START  */
    END = 259,                     /* END  */
    READ = 260,                    /* READ  */
    WRITE = 261,                   /* WRITE  */
    PLUS = 262,                    /* PLUS  */
    MINUS = 263,                   /* MINUS  */
    MUL = 264,                     /* MUL  */
    DIV = 265,                     /* DIV  */
    MOD = 266,                     /* MOD  */
    ASSGN = 267,                   /* ASSGN  */
    ID = 268,                      /* ID  */
    NUM = 269,                     /* NUM  */
    STRVAL = 270,                  /* STRVAL  */
    IF = 271,                      /* IF  */
    THEN = 272,                    /* THEN  */
    ELSE = 273,                    /* ELSE  */
    ENDIF = 274,                   /* ENDIF  */
    WHILE = 275,                   /* WHILE  */
    DO = 276,                      /* DO  */
    ENDWHILE = 277,                /* ENDWHILE  */
    EQ = 278,                      /* EQ  */
    NEQ = 279,                     /* NEQ  */
    LE = 280,                      /* LE  */
    GE = 281,                      /* GE  */
    LT = 282,                      /* LT  */
    GT = 283,                      /* GT  */
    BREAK = 284,                   /* BREAK  */
    CONT = 285,                    /* CONT  */
    DECL = 286,                    /* DECL  */
    ENDDECL = 287,                 /* ENDDECL  */
    INT = 288,                     /* INT  */
    STR = 289                      /* STR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define START 258
#define END 259
#define READ 260
#define WRITE 261
#define PLUS 262
#define MINUS 263
#define MUL 264
#define DIV 265
#define MOD 266
#define ASSGN 267
#define ID 268
#define NUM 269
#define STRVAL 270
#define IF 271
#define THEN 272
#define ELSE 273
#define ENDIF 274
#define WHILE 275
#define DO 276
#define ENDWHILE 277
#define EQ 278
#define NEQ 279
#define LE 280
#define GE 281
#define LT 282
#define GT 283
#define BREAK 284
#define CONT 285
#define DECL 286
#define ENDDECL 287
#define INT 288
#define STR 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "ex2.y"

    struct tnode *nptr;

#line 210 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_START = 3,                      /* START  */
  YYSYMBOL_END = 4,                        /* END  */
  YYSYMBOL_READ = 5,                       /* READ  */
  YYSYMBOL_WRITE = 6,                      /* WRITE  */
  YYSYMBOL_PLUS = 7,                       /* PLUS  */
  YYSYMBOL_MINUS = 8,                      /* MINUS  */
  YYSYMBOL_MUL = 9,                        /* MUL  */
  YYSYMBOL_DIV = 10,                       /* DIV  */
  YYSYMBOL_MOD = 11,                       /* MOD  */
  YYSYMBOL_ASSGN = 12,                     /* ASSGN  */
  YYSYMBOL_ID = 13,                        /* ID  */
  YYSYMBOL_NUM = 14,                       /* NUM  */
  YYSYMBOL_STRVAL = 15,                    /* STRVAL  */
  YYSYMBOL_IF = 16,                        /* IF  */
  YYSYMBOL_THEN = 17,                      /* THEN  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_ENDIF = 19,                     /* ENDIF  */
  YYSYMBOL_WHILE = 20,                     /* WHILE  */
  YYSYMBOL_DO = 21,                        /* DO  */
  YYSYMBOL_ENDWHILE = 22,                  /* ENDWHILE  */
  YYSYMBOL_EQ = 23,                        /* EQ  */
  YYSYMBOL_NEQ = 24,                       /* NEQ  */
  YYSYMBOL_LE = 25,                        /* LE  */
  YYSYMBOL_GE = 26,                        /* GE  */
  YYSYMBOL_LT = 27,                        /* LT  */
  YYSYMBOL_GT = 28,                        /* GT  */
  YYSYMBOL_BREAK = 29,                     /* BREAK  */
  YYSYMBOL_CONT = 30,                      /* CONT  */
  YYSYMBOL_DECL = 31,                      /* DECL  */
  YYSYMBOL_ENDDECL = 32,                   /* ENDDECL  */
  YYSYMBOL_INT = 33,                       /* INT  */
  YYSYMBOL_STR = 34,                       /* STR  */
  YYSYMBOL_35_ = 35,                       /* ';'  */
  YYSYMBOL_36_ = 36,                       /* ','  */
  YYSYMBOL_37_ = 37,                       /* '['  */
  YYSYMBOL_38_ = 38,                       /* ']'  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* '&'  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_program = 43,                   /* program  */
  YYSYMBOL_Slist = 44,                     /* Slist  */
  YYSYMBOL_Stmt = 45,                      /* Stmt  */
  YYSYMBOL_Declarations = 46,              /* Declarations  */
  YYSYMBOL_DeclList = 47,                  /* DeclList  */
  YYSYMBOL_Decl = 48,                      /* Decl  */
  YYSYMBOL_Type = 49,                      /* Type  */
  YYSYMBOL_VarList = 50,                   /* VarList  */
  YYSYMBOL_IfStmt = 51,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 52,                 /* WhileStmt  */
  YYSYMBOL_BrkStmt = 53,                   /* BrkStmt  */
  YYSYMBOL_ContStmt = 54,                  /* ContStmt  */
  YYSYMBOL_InputStmt = 55,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 56,                /* OutputStmt  */
  YYSYMBOL_AsgStmt = 57,                   /* AsgStmt  */
  YYSYMBOL_expr = 58,                      /* expr  */
  YYSYMBOL_id = 59                         /* id  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_uint8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   270

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  131

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,     2,
      39,    40,     2,     2,    36,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    38,    38,    46,    49,    50,    53,    54,    55,    56,
      57,    58,    59,    62,    63,    66,    67,    70,    73,    74,
      77,    78,    79,    80,    81,    82,    83,    86,    90,    96,
     101,   104,   107,   110,   113,   120,   124,   128,   132,   136,
     140,   144,   148,   152,   156,   160,   164,   165,   166,   167,
     171,   180,   192,   201,   221,   235,   247
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "START", "END", "READ",
  "WRITE", "PLUS", "MINUS", "MUL", "DIV", "MOD", "ASSGN", "ID", "NUM",
  "STRVAL", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "EQ",
  "NEQ", "LE", "GE", "LT", "GT", "BREAK", "CONT", "DECL", "ENDDECL", "INT",
  "STR", "';'", "','", "'['", "']'", "'('", "')'", "'&'", "$accept",
  "program", "Slist", "Stmt", "Declarations", "DeclList", "Decl", "Type",
  "VarList", "IfStmt", "WhileStmt", "BrkStmt", "ContStmt", "InputStmt",
  "OutputStmt", "AsgStmt", "expr", "id", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-103)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -20,    11,    26,     9,   -17,  -103,  -103,    28,  -103,    19,
    -103,     0,  -103,     2,  -103,    22,    14,   -34,    23,    10,
      24,    44,    27,    37,    40,    48,    49,    73,    18,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,    75,  -103,  -103,
      79,  -103,    76,  -103,    12,    41,  -103,     1,    41,    41,
    -103,  -103,  -103,    60,  -103,    41,    58,    66,    69,  -103,
    -103,    41,   163,  -103,    68,    74,   174,   185,  -103,   219,
      80,   105,    81,   208,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    88,    87,    90,   111,   109,
    -103,   121,    96,  -103,  -103,   147,   147,  -103,  -103,  -103,
     155,   155,   242,   242,   242,   242,  -103,   123,    12,   139,
     139,   100,   104,   108,   113,   102,    72,  -103,   128,  -103,
    -103,   139,   112,   118,   116,   120,  -103,  -103,  -103,   125,
    -103
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,    18,    19,     0,    16,     0,
       1,     0,    14,     0,    15,     0,    25,     0,     0,     0,
       0,     0,    50,     0,     0,     0,     0,     0,     0,     5,
       9,    10,    11,    12,     6,     7,     8,     0,    13,    26,
       0,    17,     0,     3,     0,     0,    55,     0,     0,     0,
      30,    31,    56,     0,     4,     0,     0,    20,     0,    47,
      48,     0,     0,    49,     0,     0,     0,     0,     2,     0,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,    52,     0,     0,
      34,     0,     0,    32,    46,    35,    36,    37,    38,    39,
      45,    44,    42,    43,    40,    41,    33,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,    23,     0,    53,
      54,     0,     0,     0,     0,     0,    28,    29,    22,     0,
      27
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -103,  -103,  -102,   -25,  -103,  -103,   160,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,    -9,   -11
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    28,    29,     3,     7,     8,     9,    17,    30,
      31,    32,    33,    34,    35,    36,    62,    63
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    41,    42,    54,    18,    19,    20,   115,   116,    21,
      21,     1,    11,    22,    22,    64,    23,    37,    12,   125,
      24,    21,    53,    19,    20,    22,    10,    21,    15,    25,
      26,    22,    16,    58,    23,    39,    65,    38,    24,    66,
      67,    27,    27,     4,     5,     6,    69,    25,    26,    44,
      21,    40,    73,    27,    22,    59,    60,    46,    43,    27,
      13,     5,     6,    45,    47,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    48,    19,    20,    49,
      61,    21,    27,    50,    51,    22,    52,    55,    23,    57,
      54,    54,    24,    56,   123,    68,    70,   114,    37,    37,
      54,    25,    26,    71,    37,    37,    86,    19,    20,    72,
      37,    21,    87,    27,    37,    22,    93,    91,    23,    92,
     121,   122,    24,   106,   107,    19,    20,   108,   109,    21,
     110,    25,    26,    22,   112,   111,    23,   113,   117,   129,
      24,   118,   124,    27,    19,    20,   119,   126,    21,    25,
      26,   120,    22,   127,   128,    23,    76,    77,    78,    24,
     130,    27,    74,    75,    76,    77,    78,    14,    25,    26,
      74,    75,    76,    77,    78,     0,     0,     0,    79,    80,
      27,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     0,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    88,    74,    75,    76,    77,    78,
       0,     0,     0,     0,     0,    89,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,     0,     0,
       0,     0,    79,    80,    81,    82,    83,    84,    94,    74,
      75,    76,    77,    78,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,    80,    -1,    -1,    -1,
      -1
};

static const yytype_int8 yycheck[] =
{
      11,    35,    36,    28,     4,     5,     6,   109,   110,     9,
       9,    31,     3,    13,    13,    14,    16,    28,    35,   121,
      20,     9,     4,     5,     6,    13,     0,     9,     9,    29,
      30,    13,    13,    44,    16,    13,    47,    35,    20,    48,
      49,    41,    41,    32,    33,    34,    55,    29,    30,    39,
       9,    37,    61,    41,    13,    14,    15,    13,    35,    41,
      32,    33,    34,    39,    37,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    39,     5,     6,    39,
      39,     9,    41,    35,    35,    13,    13,    12,    16,    13,
     115,   116,    20,    14,    22,    35,    38,   108,   109,   110,
     125,    29,    30,    37,   115,   116,    38,     5,     6,    40,
     121,     9,    38,    41,   125,    13,    35,    37,    16,    14,
      18,    19,    20,    35,    37,     5,     6,    37,    17,     9,
      21,    29,    30,    13,    38,    14,    16,    14,    38,    19,
      20,    37,    14,    41,     5,     6,    38,    35,     9,    29,
      30,    38,    13,    35,    38,    16,     9,    10,    11,    20,
      35,    41,     7,     8,     9,    10,    11,     7,    29,    30,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    23,    24,
      41,     7,     8,     9,    10,    11,    23,    24,    25,    26,
      27,    28,     7,     8,     9,    10,    11,    23,    24,    25,
      26,    27,    28,    40,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    40,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    40,     7,     8,     9,    10,
      11,    23,    24,    25,    26,    27,    28,    -1,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    27,    28,    40,     7,
       8,     9,    10,    11,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    31,    43,    46,    32,    33,    34,    47,    48,    49,
       0,     3,    35,    32,    48,     9,    13,    50,     4,     5,
       6,     9,    13,    16,    20,    29,    30,    41,    44,    45,
      51,    52,    53,    54,    55,    56,    57,    59,    35,    13,
      37,    35,    36,    35,    39,    39,    13,    37,    39,    39,
      35,    35,    13,     4,    45,    12,    14,    13,    59,    14,
      15,    39,    58,    59,    14,    59,    58,    58,    35,    58,
      38,    37,    40,    58,     7,     8,     9,    10,    11,    23,
      24,    25,    26,    27,    28,    40,    38,    38,    40,    40,
      35,    37,    14,    35,    40,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    35,    37,    37,    17,
      21,    14,    38,    14,    59,    44,    44,    38,    37,    38,
      38,    18,    19,    22,    14,    44,    35,    35,    38,    19,
      35
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    45,    45,    45,    45,
      45,    45,    45,    46,    46,    47,    47,    48,    49,    49,
      50,    50,    50,    50,    50,    50,    50,    51,    51,    52,
      53,    54,    55,    56,    57,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      59,    59,    59,    59,    59,    59,    59
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     3,     2,     1,     3,     1,     1,
       3,     6,     9,     7,     4,     1,     2,    10,     8,     8,
       2,     2,     5,     5,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     4,     4,     7,     7,     2,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* program: Declarations START Slist END ';'  */
#line 38 "ex2.y"
                                            {
                                                (yyval.nptr) = (yyvsp[-2].nptr);
                                                //print_tree($$);
                                                printSymbolTable();
                                                print_header();
                                                codegen((yyval.nptr));
                                                print_footer();
                                            }
#line 1360 "y.tab.c"
    break;

  case 3: /* program: Declarations START END ';'  */
#line 46 "ex2.y"
                                            {(yyval.nptr) = (yyvsp[-3].nptr);}
#line 1366 "y.tab.c"
    break;

  case 4: /* Slist: Slist Stmt  */
#line 49 "ex2.y"
                        {(yyval.nptr) = createTree(TYPE_VOID, 0, NODE_CONNECTOR, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL,NULL);}
#line 1372 "y.tab.c"
    break;

  case 5: /* Slist: Stmt  */
#line 50 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1378 "y.tab.c"
    break;

  case 6: /* Stmt: InputStmt  */
#line 53 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1384 "y.tab.c"
    break;

  case 7: /* Stmt: OutputStmt  */
#line 54 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1390 "y.tab.c"
    break;

  case 8: /* Stmt: AsgStmt  */
#line 55 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1396 "y.tab.c"
    break;

  case 9: /* Stmt: IfStmt  */
#line 56 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1402 "y.tab.c"
    break;

  case 10: /* Stmt: WhileStmt  */
#line 57 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1408 "y.tab.c"
    break;

  case 11: /* Stmt: BrkStmt  */
#line 58 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1414 "y.tab.c"
    break;

  case 12: /* Stmt: ContStmt  */
#line 59 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1420 "y.tab.c"
    break;

  case 13: /* Declarations: DECL DeclList ENDDECL ';'  */
#line 62 "ex2.y"
                                        {(yyval.nptr)= (yyvsp[-2].nptr);}
#line 1426 "y.tab.c"
    break;

  case 14: /* Declarations: DECL ENDDECL ';'  */
#line 63 "ex2.y"
                               {(yyval.nptr) = NULL;}
#line 1432 "y.tab.c"
    break;

  case 18: /* Type: INT  */
#line 73 "ex2.y"
            {declaration_type = TYPE_INT;}
#line 1438 "y.tab.c"
    break;

  case 19: /* Type: STR  */
#line 74 "ex2.y"
            {declaration_type = TYPE_STR;}
#line 1444 "y.tab.c"
    break;

  case 20: /* VarList: VarList ',' ID  */
#line 77 "ex2.y"
                                        {GInstall((yyvsp[0].nptr)->varname, declaration_type, 1,0,0,0);}
#line 1450 "y.tab.c"
    break;

  case 21: /* VarList: VarList ',' ID '[' NUM ']'  */
#line 78 "ex2.y"
                                        {GInstall((yyvsp[-3].nptr)->varname, declaration_type, (yyvsp[-1].nptr)->val,0,0,0);}
#line 1456 "y.tab.c"
    break;

  case 22: /* VarList: VarList ',' ID '[' NUM ']' '[' NUM ']'  */
#line 79 "ex2.y"
                                               {GInstall((yyvsp[-6].nptr)->varname, declaration_type, ((yyvsp[-4].nptr)->val)*((yyvsp[-1].nptr)->val),1,(yyvsp[-4].nptr)->val,(yyvsp[-1].nptr)->val);}
#line 1462 "y.tab.c"
    break;

  case 23: /* VarList: ID '[' NUM ']' '[' NUM ']'  */
#line 80 "ex2.y"
                                   {GInstall((yyvsp[-6].nptr)->varname, declaration_type, ((yyvsp[-4].nptr)->val)*((yyvsp[-1].nptr)->val),1,(yyvsp[-4].nptr)->val,(yyvsp[-1].nptr)->val);}
#line 1468 "y.tab.c"
    break;

  case 24: /* VarList: ID '[' NUM ']'  */
#line 81 "ex2.y"
                                        {GInstall((yyvsp[-3].nptr)->varname, declaration_type, (yyvsp[-1].nptr)->val,0,0,0);}
#line 1474 "y.tab.c"
    break;

  case 25: /* VarList: ID  */
#line 82 "ex2.y"
                                        {GInstall((yyvsp[0].nptr)->varname, declaration_type, 1,0,0,0);}
#line 1480 "y.tab.c"
    break;

  case 26: /* VarList: MUL ID  */
#line 83 "ex2.y"
                                      {GInstall((yyvsp[0].nptr)->varname,TYPE_INT_POINTER, 1,0,0,0);}
#line 1486 "y.tab.c"
    break;

  case 27: /* IfStmt: IF '(' expr ')' THEN Slist ELSE Slist ENDIF ';'  */
#line 86 "ex2.y"
                                                            {
                                                                typecheck((yyvsp[-7].nptr)->type, TYPE_BOOL, 'e');
                                                                (yyval.nptr) = createTree(TYPE_VOID, 0, NODE_IF_ELSE, NULL, (yyvsp[-7].nptr), (yyvsp[-2].nptr), (yyvsp[-4].nptr),NULL);
                                                            }
#line 1495 "y.tab.c"
    break;

  case 28: /* IfStmt: IF '(' expr ')' THEN Slist ENDIF ';'  */
#line 90 "ex2.y"
                                                            {
                                                                typecheck((yyvsp[-5].nptr)->type, TYPE_BOOL, 'i');
                                                                (yyval.nptr) = createTree(TYPE_VOID, 0, NODE_IF, NULL, (yyvsp[-5].nptr), (yyvsp[-2].nptr), NULL,NULL);
                                                            }
#line 1504 "y.tab.c"
    break;

  case 29: /* WhileStmt: WHILE '(' expr ')' DO Slist ENDWHILE ';'  */
#line 96 "ex2.y"
                                                            {
                                                                typecheck((yyvsp[-5].nptr)->type, TYPE_BOOL, 'w');
                                                                (yyval.nptr) = createTree(TYPE_VOID, 0, NODE_WHILE, NULL, (yyvsp[-5].nptr), (yyvsp[-2].nptr), NULL,NULL);
                                                            }
#line 1513 "y.tab.c"
    break;

  case 30: /* BrkStmt: BREAK ';'  */
#line 101 "ex2.y"
                                    {(yyval.nptr) = createTree(TYPE_VOID, 0, NODE_BREAK, NULL, NULL, NULL, NULL,NULL);}
#line 1519 "y.tab.c"
    break;

  case 31: /* ContStmt: CONT ';'  */
#line 104 "ex2.y"
                                    {(yyval.nptr) = createTree(TYPE_VOID, 0, NODE_CONT, NULL, NULL, NULL, NULL,NULL);}
#line 1525 "y.tab.c"
    break;

  case 32: /* InputStmt: READ '(' id ')' ';'  */
#line 107 "ex2.y"
                                    {(yyval.nptr) = createTree(TYPE_VOID, 0, NODE_READ, NULL, (yyvsp[-2].nptr), NULL, NULL,NULL);}
#line 1531 "y.tab.c"
    break;

  case 33: /* OutputStmt: WRITE '(' expr ')' ';'  */
#line 110 "ex2.y"
                                    {(yyval.nptr) = createTree(TYPE_VOID, 0, NODE_WRITE, NULL, (yyvsp[-2].nptr), NULL, NULL,NULL);}
#line 1537 "y.tab.c"
    break;

  case 34: /* AsgStmt: id ASSGN expr ';'  */
#line 113 "ex2.y"
                                    {
                                        typecheck((yyvsp[-3].nptr)->type, (yyvsp[-1].nptr)->type, '=');
                                        (yyval.nptr) = createTree(TYPE_VOID, 0, NODE_ASSGN, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL,NULL);
                                    }
#line 1546 "y.tab.c"
    break;

  case 35: /* expr: expr PLUS expr  */
#line 120 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = createTree(TYPE_INT, 0, NODE_PLUS, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL,NULL);
                        }
#line 1555 "y.tab.c"
    break;

  case 36: /* expr: expr MINUS expr  */
#line 124 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = createTree(TYPE_INT, 0, NODE_MINUS, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL,NULL);
                        }
#line 1564 "y.tab.c"
    break;

  case 37: /* expr: expr MUL expr  */
#line 128 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = createTree(TYPE_INT, 0, NODE_MUL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL,NULL);
                        }
#line 1573 "y.tab.c"
    break;

  case 38: /* expr: expr DIV expr  */
#line 132 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = createTree(TYPE_INT, 0, NODE_DIV, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL,NULL);
                        }
#line 1582 "y.tab.c"
    break;

  case 39: /* expr: expr MOD expr  */
#line 136 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = createTree(TYPE_INT, 0, NODE_MOD, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL,NULL);
                        }
#line 1591 "y.tab.c"
    break;

  case 40: /* expr: expr LT expr  */
#line 140 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = createTree(TYPE_BOOL, 0, NODE_LT, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL,NULL);
                        }
#line 1600 "y.tab.c"
    break;

  case 41: /* expr: expr GT expr  */
#line 144 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = createTree(TYPE_BOOL, 0, NODE_GT, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL,NULL);
                        }
#line 1609 "y.tab.c"
    break;

  case 42: /* expr: expr LE expr  */
#line 148 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = createTree(TYPE_BOOL, 0, NODE_LE, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL,NULL);
                        }
#line 1618 "y.tab.c"
    break;

  case 43: /* expr: expr GE expr  */
#line 152 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = createTree(TYPE_BOOL, 0, NODE_GE, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL,NULL);
                        }
#line 1627 "y.tab.c"
    break;

  case 44: /* expr: expr NEQ expr  */
#line 156 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = createTree(TYPE_BOOL, 0, NODE_NEQ, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL,NULL);
                        }
#line 1636 "y.tab.c"
    break;

  case 45: /* expr: expr EQ expr  */
#line 160 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = createTree(TYPE_BOOL, 0, NODE_EQ, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL,NULL);
                        }
#line 1645 "y.tab.c"
    break;

  case 46: /* expr: '(' expr ')'  */
#line 164 "ex2.y"
                        {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 1651 "y.tab.c"
    break;

  case 47: /* expr: NUM  */
#line 165 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1657 "y.tab.c"
    break;

  case 48: /* expr: STRVAL  */
#line 166 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1663 "y.tab.c"
    break;

  case 49: /* expr: id  */
#line 167 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1669 "y.tab.c"
    break;

  case 50: /* id: ID  */
#line 171 "ex2.y"
                        {
                            (yyvsp[0].nptr)->Gentry = GLookup((yyvsp[0].nptr)->varname);
                            if((yyvsp[0].nptr)->Gentry == NULL) {
                                printf("Variable '%s' not declared!", (yyvsp[0].nptr)->varname);
                                exit(1);
                            }
                            (yyvsp[0].nptr)->type = (yyvsp[0].nptr)->Gentry->type;
                            (yyval.nptr) = (yyvsp[0].nptr);
                        }
#line 1683 "y.tab.c"
    break;

  case 51: /* id: ID '[' NUM ']'  */
#line 180 "ex2.y"
                        {
                            (yyvsp[-3].nptr)->Gentry = GLookup((yyvsp[-3].nptr)->varname);
                            if((yyvsp[-3].nptr)->Gentry == NULL) {
                                printf("Variable '%s' not declared!", (yyvsp[-3].nptr)->varname);
                                exit(1);
                            } else if((yyvsp[-3].nptr)->Gentry->size <= (yyvsp[-1].nptr)->val || (yyvsp[-1].nptr)->val < 0) {
                                printf("Array '%s' out of bounds!", (yyvsp[-3].nptr)->varname);
                                exit(1);
                            }
                            (yyvsp[-3].nptr)->type = (yyvsp[-3].nptr)->Gentry->type;
                            (yyval.nptr) = createTree((yyvsp[-3].nptr)->type, 0, NODE_ARRAY, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL,(yyvsp[-3].nptr)->Gentry);
                        }
#line 1700 "y.tab.c"
    break;

  case 52: /* id: ID '[' id ']'  */
#line 192 "ex2.y"
                        {
                            (yyvsp[-3].nptr)->Gentry = GLookup((yyvsp[-3].nptr)->varname);
                            if((yyvsp[-3].nptr)->Gentry == NULL) {
                                printf("Variable '%s' not declared!", (yyvsp[-3].nptr)->varname);
                                exit(1);
                            }
                            (yyvsp[-3].nptr)->type = (yyvsp[-3].nptr)->Gentry->type;
                            (yyval.nptr) = createTree((yyvsp[-3].nptr)->type, 0, NODE_ARRAY, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL,(yyvsp[-3].nptr)->Gentry);
                        }
#line 1714 "y.tab.c"
    break;

  case 53: /* id: ID '[' NUM ']' '[' NUM ']'  */
#line 202 "ex2.y"
                            {
                            (yyvsp[-6].nptr)->Gentry = GLookup((yyvsp[-6].nptr)->varname);
                            if((yyvsp[-6].nptr)->Gentry == NULL) {
                                printf("Variable '%s' not declared!", (yyvsp[-6].nptr)->varname);
                                exit(1);
                            }
                            else if ((yyvsp[-6].nptr)->Gentry->is2D == 0) {
                                printf("Variable '%s' is not a 2D array!", (yyvsp[-6].nptr)->varname);
                                exit(1);
                            } 
                            else if((yyvsp[-6].nptr)->Gentry->arrleft_index <= ((yyvsp[-4].nptr)->val) || (yyvsp[-6].nptr)->Gentry->arrright_index <= ((yyvsp[-1].nptr)->val) || (yyvsp[-4].nptr)->val < 0 || (yyvsp[-1].nptr)->val < 0) {
                                printf("Array '%s' out of bounds!", (yyvsp[-6].nptr)->varname);
                                exit(1);
                            }
                           
                            
                            (yyvsp[-6].nptr)->type = (yyvsp[-6].nptr)->Gentry->type;
                            (yyval.nptr) = createTree((yyvsp[-6].nptr)->type, 0, NODE_2D_ARRAY, NULL, (yyvsp[-6].nptr), (yyvsp[-1].nptr), (yyvsp[-4].nptr),(yyvsp[-6].nptr)->Gentry);
                        }
#line 1738 "y.tab.c"
    break;

  case 54: /* id: ID '[' id ']' '[' id ']'  */
#line 221 "ex2.y"
                               {
                            (yyvsp[-6].nptr)->Gentry = GLookup((yyvsp[-6].nptr)->varname);
                            if((yyvsp[-6].nptr)->Gentry == NULL) {
                                printf("Variable '%s' not declared!", (yyvsp[-6].nptr)->varname);
                                exit(1);
                            }
                            else if ((yyvsp[-6].nptr)->Gentry->is2D == 0) {
                                printf("Variable '%s' is not a 2D array!", (yyvsp[-6].nptr)->varname);
                                exit(1);
                            }
                            // We cannot do bounds checking here as indices are variables
                            (yyvsp[-6].nptr)->type = (yyvsp[-6].nptr)->Gentry->type;
                            (yyval.nptr) = createTree((yyvsp[-6].nptr)->type, 0, NODE_2D_ARRAY, NULL, (yyvsp[-6].nptr), (yyvsp[-1].nptr), (yyvsp[-4].nptr),(yyvsp[-6].nptr)->Gentry);
                        }
#line 1757 "y.tab.c"
    break;

  case 55: /* id: MUL ID  */
#line 235 "ex2.y"
                           {
                            (yyvsp[0].nptr)->Gentry = GLookup((yyvsp[0].nptr)->varname);
                            if((yyvsp[0].nptr)->Gentry == NULL) {
                                printf("Variable '%s' not declared!", (yyvsp[0].nptr)->varname);
                                exit(1);
                            } else if((yyvsp[0].nptr)->Gentry->type != TYPE_INT_POINTER) {
                                printf("Variable '%s' is not a pointer!", (yyvsp[0].nptr)->varname);
                                exit(1);
                            }
                            (yyvsp[0].nptr)->type = TYPE_INT_POINTER;
                            (yyval.nptr) = createTree(TYPE_INT, 0, NODE_INT_PTR, NULL, (yyvsp[0].nptr), NULL, NULL,(yyvsp[0].nptr)->Gentry);
                        }
#line 1774 "y.tab.c"
    break;

  case 56: /* id: '&' ID  */
#line 247 "ex2.y"
                           {
                            (yyvsp[0].nptr)->Gentry = GLookup((yyvsp[0].nptr)->varname);
                            if((yyvsp[0].nptr)->Gentry == NULL) {
                                printf("Variable '%s' not declared!", (yyvsp[0].nptr)->varname);
                                exit(1);
                            } 
                            (yyvsp[0].nptr)->type = (yyvsp[0].nptr)->Gentry->type;
                            (yyval.nptr) = createTree(TYPE_INT_POINTER, 0, NODE_ADDRESS, NULL, (yyvsp[0].nptr), NULL, NULL,(yyvsp[0].nptr)->Gentry);
                        }
#line 1788 "y.tab.c"
    break;


#line 1792 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 258 "ex2.y"


int yyerror(char const *s) 
{
    printf("perror %s",s);
    return 1;
}

int main(int argc, char *argv[]) 
{
    intermediate=fopen("temp.txt", "w");
    if (argc < 2) 
    {
        printf("Please provide an input filename\n");
        exit(1);
    } 
    else 
    {
        fp = fopen(argv[1], "r");
        if (!fp) 
        {
            printf("Invalid input file specified\n");
            exit(1);
        }
        else 
        {
            yyin = fp;
        }
    }
    yyparse();
    return 0;
}
