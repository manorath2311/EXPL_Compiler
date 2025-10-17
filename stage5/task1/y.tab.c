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
#line 1 "task1.y"

	#include <stdlib.h>
	#include <stdio.h>
    #include <string.h>
	#include "task1.h"
    #include "task1.c"

	int yylex(void);
        extern FILE *yyin;
        extern int lineno;
        FILE *fp;
        FILE *intermediate;
        void print(int);
        struct Paramstruct *argList1, *argList2;
        int declCount = 0, defCount = 0; // Definition and Declaration count of functions

        int testing = 0; // can use to test ASTree

#line 90 "y.tab.c"

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
    NUM = 258,                     /* NUM  */
    ID = 259,                      /* ID  */
    STRVAL = 260,                  /* STRVAL  */
    VOID = 261,                    /* VOID  */
    START = 262,                   /* START  */
    END = 263,                     /* END  */
    READ = 264,                    /* READ  */
    WRITE = 265,                   /* WRITE  */
    PLUS = 266,                    /* PLUS  */
    MINUS = 267,                   /* MINUS  */
    MUL = 268,                     /* MUL  */
    DIV = 269,                     /* DIV  */
    MOD = 270,                     /* MOD  */
    ASSGN = 271,                   /* ASSGN  */
    IF = 272,                      /* IF  */
    THEN = 273,                    /* THEN  */
    ELSE = 274,                    /* ELSE  */
    ENDIF = 275,                   /* ENDIF  */
    WHILE = 276,                   /* WHILE  */
    DO = 277,                      /* DO  */
    ENDWHILE = 278,                /* ENDWHILE  */
    EQ = 279,                      /* EQ  */
    NEQ = 280,                     /* NEQ  */
    LE = 281,                      /* LE  */
    GE = 282,                      /* GE  */
    LT = 283,                      /* LT  */
    GT = 284,                      /* GT  */
    BREAK = 285,                   /* BREAK  */
    CONT = 286,                    /* CONT  */
    DECL = 287,                    /* DECL  */
    ENDDECL = 288,                 /* ENDDECL  */
    INT = 289,                     /* INT  */
    STR = 290,                     /* STR  */
    MAIN = 291,                    /* MAIN  */
    RETURN = 292                   /* RETURN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NUM 258
#define ID 259
#define STRVAL 260
#define VOID 261
#define START 262
#define END 263
#define READ 264
#define WRITE 265
#define PLUS 266
#define MINUS 267
#define MUL 268
#define DIV 269
#define MOD 270
#define ASSGN 271
#define IF 272
#define THEN 273
#define ELSE 274
#define ENDIF 275
#define WHILE 276
#define DO 277
#define ENDWHILE 278
#define EQ 279
#define NEQ 280
#define LE 281
#define GE 282
#define LT 283
#define GT 284
#define BREAK 285
#define CONT 286
#define DECL 287
#define ENDDECL 288
#define INT 289
#define STR 290
#define MAIN 291
#define RETURN 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "task1.y"

    struct ASTNode *nptr;

#line 221 "y.tab.c"

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
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_STRVAL = 5,                     /* STRVAL  */
  YYSYMBOL_VOID = 6,                       /* VOID  */
  YYSYMBOL_START = 7,                      /* START  */
  YYSYMBOL_END = 8,                        /* END  */
  YYSYMBOL_READ = 9,                       /* READ  */
  YYSYMBOL_WRITE = 10,                     /* WRITE  */
  YYSYMBOL_PLUS = 11,                      /* PLUS  */
  YYSYMBOL_MINUS = 12,                     /* MINUS  */
  YYSYMBOL_MUL = 13,                       /* MUL  */
  YYSYMBOL_DIV = 14,                       /* DIV  */
  YYSYMBOL_MOD = 15,                       /* MOD  */
  YYSYMBOL_ASSGN = 16,                     /* ASSGN  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_THEN = 18,                      /* THEN  */
  YYSYMBOL_ELSE = 19,                      /* ELSE  */
  YYSYMBOL_ENDIF = 20,                     /* ENDIF  */
  YYSYMBOL_WHILE = 21,                     /* WHILE  */
  YYSYMBOL_DO = 22,                        /* DO  */
  YYSYMBOL_ENDWHILE = 23,                  /* ENDWHILE  */
  YYSYMBOL_EQ = 24,                        /* EQ  */
  YYSYMBOL_NEQ = 25,                       /* NEQ  */
  YYSYMBOL_LE = 26,                        /* LE  */
  YYSYMBOL_GE = 27,                        /* GE  */
  YYSYMBOL_LT = 28,                        /* LT  */
  YYSYMBOL_GT = 29,                        /* GT  */
  YYSYMBOL_BREAK = 30,                     /* BREAK  */
  YYSYMBOL_CONT = 31,                      /* CONT  */
  YYSYMBOL_DECL = 32,                      /* DECL  */
  YYSYMBOL_ENDDECL = 33,                   /* ENDDECL  */
  YYSYMBOL_INT = 34,                       /* INT  */
  YYSYMBOL_STR = 35,                       /* STR  */
  YYSYMBOL_MAIN = 36,                      /* MAIN  */
  YYSYMBOL_RETURN = 37,                    /* RETURN  */
  YYSYMBOL_38_ = 38,                       /* ';'  */
  YYSYMBOL_39_ = 39,                       /* ','  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_42_ = 42,                       /* '['  */
  YYSYMBOL_43_ = 43,                       /* ']'  */
  YYSYMBOL_44_ = 44,                       /* '{'  */
  YYSYMBOL_45_ = 45,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_program = 47,                   /* program  */
  YYSYMBOL_GDeclBlock = 48,                /* GDeclBlock  */
  YYSYMBOL_GDeclList = 49,                 /* GDeclList  */
  YYSYMBOL_GDecl = 50,                     /* GDecl  */
  YYSYMBOL_Type = 51,                      /* Type  */
  YYSYMBOL_FType = 52,                     /* FType  */
  YYSYMBOL_GIdList = 53,                   /* GIdList  */
  YYSYMBOL_GId = 54,                       /* GId  */
  YYSYMBOL_FDefBlock = 55,                 /* FDefBlock  */
  YYSYMBOL_FDef = 56,                      /* FDef  */
  YYSYMBOL_ParamList = 57,                 /* ParamList  */
  YYSYMBOL_Param = 58,                     /* Param  */
  YYSYMBOL_MainBlock = 59,                 /* MainBlock  */
  YYSYMBOL_LDeclBlock = 60,                /* LDeclBlock  */
  YYSYMBOL_LDecList = 61,                  /* LDecList  */
  YYSYMBOL_LDecl = 62,                     /* LDecl  */
  YYSYMBOL_IdList = 63,                    /* IdList  */
  YYSYMBOL_Body = 64,                      /* Body  */
  YYSYMBOL_RetStmt = 65,                   /* RetStmt  */
  YYSYMBOL_Slist = 66,                     /* Slist  */
  YYSYMBOL_Stmt = 67,                      /* Stmt  */
  YYSYMBOL_IfStmt = 68,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 69,                 /* WhileStmt  */
  YYSYMBOL_BrkStmt = 70,                   /* BrkStmt  */
  YYSYMBOL_ContStmt = 71,                  /* ContStmt  */
  YYSYMBOL_InputStmt = 72,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 73,                /* OutputStmt  */
  YYSYMBOL_AsgStmt = 74,                   /* AsgStmt  */
  YYSYMBOL_ExprList = 75,                  /* ExprList  */
  YYSYMBOL_expr = 76,                      /* expr  */
  YYSYMBOL_func = 77,                      /* func  */
  YYSYMBOL_id = 78                         /* id  */
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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   286

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,    41,     2,     2,    39,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
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
       0,    44,    44,    45,    46,    49,    50,    53,    54,    57,
      60,    61,    64,    65,    69,    70,    73,    80,    84,    94,
      95,    98,   160,   161,   162,   165,   171,   206,   207,   208,
     211,   212,   215,   218,   219,   225,   226,   229,   239,   240,
     243,   244,   245,   246,   247,   248,   249,   250,   253,   257,
     263,   268,   271,   274,   277,   280,   286,   290,   291,   294,
     298,   302,   306,   310,   314,   318,   322,   326,   330,   334,
     338,   339,   340,   344,   345,   346,   349,   356,   360,   364
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
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "ID", "STRVAL",
  "VOID", "START", "END", "READ", "WRITE", "PLUS", "MINUS", "MUL", "DIV",
  "MOD", "ASSGN", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE",
  "EQ", "NEQ", "LE", "GE", "LT", "GT", "BREAK", "CONT", "DECL", "ENDDECL",
  "INT", "STR", "MAIN", "RETURN", "';'", "','", "'('", "')'", "'['", "']'",
  "'{'", "'}'", "$accept", "program", "GDeclBlock", "GDeclList", "GDecl",
  "Type", "FType", "GIdList", "GId", "FDefBlock", "FDef", "ParamList",
  "Param", "MainBlock", "LDeclBlock", "LDecList", "LDecl", "IdList",
  "Body", "RetStmt", "Slist", "Stmt", "IfStmt", "WhileStmt", "BrkStmt",
  "ContStmt", "InputStmt", "OutputStmt", "AsgStmt", "ExprList", "expr",
  "func", "id", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-128)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      27,    58,  -128,  -128,    20,   -31,   -21,  -128,  -128,    62,
    -128,    25,  -128,    15,   -31,  -128,  -128,     8,  -128,  -128,
     -15,    19,  -128,    14,  -128,  -128,    34,    44,   112,  -128,
      25,    44,    72,  -128,  -128,   119,   136,  -128,    86,  -128,
     175,    98,  -128,    44,  -128,  -128,   111,    66,   171,  -128,
      98,  -128,   195,   155,  -128,    43,   161,   171,  -128,    49,
    -128,  -128,   154,   181,   182,   183,   190,   172,   173,     6,
     223,    43,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,
     194,   219,  -128,   191,  -128,   195,     6,   104,   245,     6,
       6,     6,  -128,  -128,  -128,  -128,   234,     6,   138,  -128,
    -128,  -128,   247,  -128,  -128,     6,  -128,   217,   176,   214,
     222,   224,   225,   226,    57,   107,   113,  -128,   132,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
    -128,  -128,   157,     6,  -128,  -128,  -128,   231,   232,   253,
     250,  -128,   189,   189,  -128,  -128,  -128,   239,   239,   233,
     233,   233,   233,  -128,   214,  -128,  -128,   203,   203,    46,
     170,   203,   235,   236,   188,  -128,  -128,   237,  -128
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    10,    11,     0,     0,     0,     4,     6,     0,
       8,     0,     1,     0,     0,    20,     3,     0,     5,     7,
      17,     0,    15,     0,    19,     2,     0,    24,     0,     9,
       0,    24,     0,    12,    13,     0,     0,    23,     0,    14,
       0,    29,    25,     0,    16,    18,     0,     0,     0,    22,
      29,    28,     0,     0,    31,     0,     0,     0,    34,     0,
      27,    30,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    39,    43,    44,    45,    46,    40,    41,    42,
       0,     0,    26,     0,    32,     0,    58,     0,     0,     0,
       0,     0,    51,    52,    71,    73,     0,     0,     0,    75,
      74,    36,     0,    38,    47,     0,    21,    33,     0,    57,
       0,    77,     0,     0,     0,     0,     0,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,    35,     0,     0,    76,    78,    79,     0,     0,     0,
       0,    70,    59,    60,    61,    62,    63,    69,    68,    66,
      67,    64,    65,    55,    56,    53,    54,     0,     0,     0,
       0,     0,     0,     0,     0,    49,    50,     0,    48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -128,  -128,  -128,  -128,   267,    12,   -25,  -128,   248,  -128,
     263,   249,   238,     9,   229,  -128,   230,   197,   227,   215,
    -127,   -70,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,
     -84,   -47,   -55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     9,    10,    11,    35,    21,    22,    14,
      15,    36,    37,     7,    48,    53,    54,    59,    56,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,   108,
      98,    99,   100
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      81,   103,   109,     2,     3,   114,   115,   116,    80,    94,
      62,    95,     6,   118,    16,    17,    81,    13,    96,    23,
      12,   132,    52,    25,    80,    27,    13,    28,    52,    20,
     159,   160,   112,   113,   164,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    97,    62,    26,   154,
      62,    17,    63,    64,    31,    63,    64,    29,    30,     1,
      65,     2,     3,    65,    66,   161,   162,    66,   119,   120,
     121,   122,   123,    67,    68,    32,    67,    68,    33,    34,
      69,   124,   125,   126,   127,   128,   129,    84,    85,   103,
     103,     8,     2,     3,   103,    18,     2,     3,   138,    51,
      33,    34,    81,    81,    81,    81,    81,   110,   111,    81,
      80,    80,    80,    80,    80,    38,    41,    80,   119,   120,
     121,   122,   123,    42,   119,   120,   121,   122,   123,    45,
      47,   124,   125,   126,   127,   128,   129,   124,   125,   126,
     127,   128,   129,   119,   120,   121,   122,   123,   139,   119,
     120,   121,   122,   123,   140,    50,   124,   125,   126,   127,
     128,   129,   124,   125,   126,   127,   128,   129,   119,   120,
     121,   122,   123,   141,    62,    43,   130,    44,    55,    63,
      64,   124,   125,   126,   127,   128,   129,    65,    60,    33,
      34,    66,    62,   163,    86,   153,    87,    63,    64,    58,
      67,    68,   121,   122,   123,    65,    82,    62,   167,    66,
      92,    93,    63,    64,    43,   133,    46,   134,    67,    68,
      65,    88,    89,    90,    66,   119,   120,   121,   122,   123,
      91,   101,   104,    67,    68,   105,   106,   117,   124,   125,
     126,   127,   128,   129,   119,   120,   121,   122,   123,   111,
     119,   120,   121,   122,   123,   131,    85,   124,   125,    -1,
      -1,    -1,    -1,   124,   125,   135,    87,   137,   136,   155,
     156,   157,   158,   165,   166,   168,    19,    24,    39,    57,
      40,    49,   107,    61,    83,     0,   102
};

static const yytype_int16 yycheck[] =
{
      55,    71,    86,    34,    35,    89,    90,    91,    55,     3,
       4,     5,     0,    97,     5,    36,    71,     5,    12,     4,
       0,   105,    47,    14,    71,    40,    14,    42,    53,     4,
     157,   158,    87,    88,   161,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,    40,     4,    40,   133,
       4,    36,     9,    10,    40,     9,    10,    38,    39,    32,
      17,    34,    35,    17,    21,    19,    20,    21,    11,    12,
      13,    14,    15,    30,    31,    41,    30,    31,    34,    35,
      37,    24,    25,    26,    27,    28,    29,    38,    39,   159,
     160,    33,    34,    35,   164,    33,    34,    35,    41,    33,
      34,    35,   157,   158,   159,   160,   161,     3,     4,   164,
     157,   158,   159,   160,   161,     3,    44,   164,    11,    12,
      13,    14,    15,     4,    11,    12,    13,    14,    15,    43,
      32,    24,    25,    26,    27,    28,    29,    24,    25,    26,
      27,    28,    29,    11,    12,    13,    14,    15,    41,    11,
      12,    13,    14,    15,    41,    44,    24,    25,    26,    27,
      28,    29,    24,    25,    26,    27,    28,    29,    11,    12,
      13,    14,    15,    41,     4,    39,    38,    41,     7,     9,
      10,    24,    25,    26,    27,    28,    29,    17,    33,    34,
      35,    21,     4,    23,    40,    38,    42,     9,    10,     4,
      30,    31,    13,    14,    15,    17,    45,     4,    20,    21,
      38,    38,     9,    10,    39,    39,    41,    41,    30,    31,
      17,    40,    40,    40,    21,    11,    12,    13,    14,    15,
      40,     8,    38,    30,    31,    16,    45,     3,    24,    25,
      26,    27,    28,    29,    11,    12,    13,    14,    15,     4,
      11,    12,    13,    14,    15,     8,    39,    24,    25,    26,
      27,    28,    29,    24,    25,    43,    42,    41,    43,    38,
      38,    18,    22,    38,    38,    38,     9,    14,    30,    50,
      31,    43,    85,    53,    57,    -1,    71
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    32,    34,    35,    47,    48,    51,    59,    33,    49,
      50,    51,     0,    51,    55,    56,    59,    36,    33,    50,
       4,    53,    54,     4,    56,    59,    40,    40,    42,    38,
      39,    40,    41,    34,    35,    52,    57,    58,     3,    54,
      57,    44,     4,    39,    41,    43,    41,    32,    60,    58,
      44,    33,    52,    61,    62,     7,    64,    60,     4,    63,
      33,    62,     4,     9,    10,    17,    21,    30,    31,    37,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      77,    78,    45,    64,    38,    39,    40,    42,    40,    40,
      40,    40,    38,    38,     3,     5,    12,    40,    76,    77,
      78,     8,    65,    67,    38,    16,    45,    63,    75,    76,
       3,     4,    78,    78,    76,    76,    76,     3,    76,    11,
      12,    13,    14,    15,    24,    25,    26,    27,    28,    29,
      38,     8,    76,    39,    41,    43,    43,    41,    41,    41,
      41,    41,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    38,    76,    38,    38,    18,    22,    66,
      66,    19,    20,    23,    66,    38,    38,    20,    38
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    47,    47,    48,    48,    49,    49,    50,
      51,    51,    52,    52,    53,    53,    54,    54,    54,    55,
      55,    56,    57,    57,    57,    58,    59,    60,    60,    60,
      61,    61,    62,    63,    63,    64,    64,    65,    66,    66,
      67,    67,    67,    67,    67,    67,    67,    67,    68,    68,
      69,    70,    71,    72,    73,    74,    75,    75,    75,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    77,    78,    78,    78
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       1,     1,     1,     1,     3,     1,     4,     1,     4,     2,
       1,     9,     3,     1,     0,     2,     8,     3,     2,     0,
       2,     1,     3,     3,     1,     4,     3,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,    10,     8,
       8,     2,     2,     5,     5,     4,     3,     1,     0,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     2,     1,     1,     1,     4,     1,     4,     4
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
  case 2: /* program: GDeclBlock FDefBlock MainBlock  */
#line 44 "task1.y"
                                        {fclose(intermediate);}
#line 1408 "y.tab.c"
    break;

  case 3: /* program: GDeclBlock MainBlock  */
#line 45 "task1.y"
                                        {fclose(intermediate);}
#line 1414 "y.tab.c"
    break;

  case 4: /* program: MainBlock  */
#line 46 "task1.y"
                                        {fclose(intermediate);}
#line 1420 "y.tab.c"
    break;

  case 5: /* GDeclBlock: DECL GDeclList ENDDECL  */
#line 49 "task1.y"
                                        {initialize();}
#line 1426 "y.tab.c"
    break;

  case 6: /* GDeclBlock: DECL ENDDECL  */
#line 50 "task1.y"
                                        {initialize();}
#line 1432 "y.tab.c"
    break;

  case 10: /* Type: INT  */
#line 60 "task1.y"
            {declarationType = TYPE_INT;}
#line 1438 "y.tab.c"
    break;

  case 11: /* Type: STR  */
#line 61 "task1.y"
            {declarationType = TYPE_STR;}
#line 1444 "y.tab.c"
    break;

  case 12: /* FType: INT  */
#line 64 "task1.y"
             {FDeclarationType = TYPE_INT;}
#line 1450 "y.tab.c"
    break;

  case 13: /* FType: STR  */
#line 65 "task1.y"
             {FDeclarationType = TYPE_STR;}
#line 1456 "y.tab.c"
    break;

  case 16: /* GId: ID '(' ParamList ')'  */
#line 73 "task1.y"
                            {
                                declCount++;
                                checkAvailability((yyvsp[-3].nptr)->name, 1);
                                GInstall((yyvsp[-3].nptr)->name, declarationType, -1, Phead);
                                Phead = NULL;
                                Ptail = NULL;
                            }
#line 1468 "y.tab.c"
    break;

  case 17: /* GId: ID  */
#line 80 "task1.y"
                            {
                                checkAvailability((yyvsp[0].nptr)->name, 1);
                                GInstall((yyvsp[0].nptr)->name, declarationType, 1, NULL);
                            }
#line 1477 "y.tab.c"
    break;

  case 18: /* GId: ID '[' NUM ']'  */
#line 84 "task1.y"
                            {
                                checkAvailability((yyvsp[-3].nptr)->name, 1);
                                if((yyvsp[-1].nptr)->value.intval < 1) {
                                    yyerror("Invalid array size");
                                    exit(1);
                                }
                                GInstall((yyvsp[-3].nptr)->name, declarationType, (yyvsp[-1].nptr)->value.intval, NULL);
                            }
#line 1490 "y.tab.c"
    break;

  case 21: /* FDef: Type ID '(' ParamList ')' '{' LDeclBlock Body '}'  */
#line 98 "task1.y"
                                                        {
                                                            defCount++;
                                                            Gtemp = GLookup((yyvsp[-7].nptr)->name);

                                                            if(Gtemp == NULL) {
                                                                yyerror("Function not declared");
                                                                exit(1);
                                                            }

                                                            if(Gtemp->type != declarationType) {
                                                               yyerror("Function type does not match declaration");
                                                               exit(1);
                                                            }

                                                            argList1 = Phead;
                                                            argList2 = Gtemp->paramlist;

                                                            while(argList1 != NULL && argList2 != NULL) {
                                                                if(argList1->type != argList2->type) {
                                                                    yyerror("Conflict in argument types");
                                                                    exit(1);
                                                                }

                                                                if(strcmp(argList1->name, argList2->name)) {
                                                                    yyerror("Conflict in argument names");
                                                                    exit(1);
                                                                }

                                                                argList1 = argList1->next;
                                                                argList2 = argList2->next;
                                                            }

                                                            if ((argList1 != NULL) || (argList2 != NULL)) {
                                                                yyerror("Not enough arguments");
                                                                exit(1);
                                                            }

                                                            if(testing) {
                                                                printLSymbolTable();
                                                            
                                                            } else {
                                                                fprintf(intermediate, "F%d:\n",Gtemp->flabel);
                                                                fprintf(intermediate, "PUSH BP\n");
                                                                fprintf(intermediate, "MOV BP,SP\n");

                                                                Ltemp = Lhead;
                                                                while(Ltemp != NULL) {
                                                                    if(Ltemp->binding > 0)
                                                                        fprintf(intermediate, "PUSH R0\n");
                                                                    Ltemp = Ltemp->next;
                                                                }

                                                                codegen((yyvsp[-1].nptr));
                                                            }

                                                            Phead = NULL;
                                                            Ptail = NULL;
                                                            Lhead = NULL;
                                                            Ltail = NULL;
                                                        }
#line 1555 "y.tab.c"
    break;

  case 24: /* ParamList: %empty  */
#line 162 "task1.y"
                        {(yyval.nptr) = NULL;}
#line 1561 "y.tab.c"
    break;

  case 25: /* Param: FType ID  */
#line 165 "task1.y"
                 {
                    checkAvailability((yyvsp[0].nptr)->name, 0);
                    PInstall((yyvsp[0].nptr)->name, FDeclarationType);
                }
#line 1570 "y.tab.c"
    break;

  case 26: /* MainBlock: Type MAIN '(' ')' '{' LDeclBlock Body '}'  */
#line 171 "task1.y"
                                                       {
                                                            if(defCount != declCount) {
                                                                yyerror("All functions declared need to be defined\n");
                                                                exit(1);
                                                            }

                                                            if(declarationType != TYPE_INT) {
                                                                yyerror("Main return type should be of integer type\n");
                                                                exit(1);
                                                            }

                                                            if(testing) {
                                                                printGSymbolTable();
                                                                printLSymbolTable();
                                                        
                                                            } else {
                                                                fprintf(intermediate, "MAIN:\n");
                                                                fprintf(intermediate, "PUSH BP\n");
                                                                fprintf(intermediate, "MOV BP,SP\n");

                                                                Ltemp = Lhead;
                                                                while (Ltemp != NULL)
                                                                {
                                                                    fprintf(intermediate, "PUSH R0\n");
                                                                    Ltemp = Ltemp->next;
                                                                }

                                                                codegen((yyvsp[-1].nptr));
                                                            }

                                                            Lhead = NULL;
                                                            Ltail = NULL;
                                                        }
#line 1608 "y.tab.c"
    break;

  case 27: /* LDeclBlock: DECL LDecList ENDDECL  */
#line 206 "task1.y"
                                    {InstallParamsInLocal();}
#line 1614 "y.tab.c"
    break;

  case 28: /* LDeclBlock: DECL ENDDECL  */
#line 207 "task1.y"
                                    {InstallParamsInLocal();}
#line 1620 "y.tab.c"
    break;

  case 29: /* LDeclBlock: %empty  */
#line 208 "task1.y"
                                    {InstallParamsInLocal();}
#line 1626 "y.tab.c"
    break;

  case 34: /* IdList: ID  */
#line 219 "task1.y"
                {
                    checkAvailability((yyvsp[0].nptr)->name, 0);
                    LInstall((yyvsp[0].nptr)->name, FDeclarationType);
                }
#line 1635 "y.tab.c"
    break;

  case 35: /* Body: START Slist RetStmt END  */
#line 225 "task1.y"
                                {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_CONNECTOR, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[-1].nptr), NULL);}
#line 1641 "y.tab.c"
    break;

  case 36: /* Body: START RetStmt END  */
#line 226 "task1.y"
                                {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 1647 "y.tab.c"
    break;

  case 37: /* RetStmt: RETURN expr ';'  */
#line 229 "task1.y"
                            {
                                if(declarationType == (yyvsp[-1].nptr)->type) {
                                    (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_RET, NULL, NULL, NULL, (yyvsp[-1].nptr), NULL, NULL);
                                } else {
                                    yyerror("Return type mismatch");
                                    exit(1);
                                }
                            }
#line 1660 "y.tab.c"
    break;

  case 38: /* Slist: Slist Stmt  */
#line 239 "task1.y"
                        {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_CONNECTOR, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);}
#line 1666 "y.tab.c"
    break;

  case 39: /* Slist: Stmt  */
#line 240 "task1.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1672 "y.tab.c"
    break;

  case 40: /* Stmt: InputStmt  */
#line 243 "task1.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1678 "y.tab.c"
    break;

  case 41: /* Stmt: OutputStmt  */
#line 244 "task1.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1684 "y.tab.c"
    break;

  case 42: /* Stmt: AsgStmt  */
#line 245 "task1.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1690 "y.tab.c"
    break;

  case 43: /* Stmt: IfStmt  */
#line 246 "task1.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1696 "y.tab.c"
    break;

  case 44: /* Stmt: WhileStmt  */
#line 247 "task1.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1702 "y.tab.c"
    break;

  case 45: /* Stmt: BrkStmt  */
#line 248 "task1.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1708 "y.tab.c"
    break;

  case 46: /* Stmt: ContStmt  */
#line 249 "task1.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1714 "y.tab.c"
    break;

  case 47: /* Stmt: func ';'  */
#line 250 "task1.y"
                        {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 1720 "y.tab.c"
    break;

  case 48: /* IfStmt: IF '(' expr ')' THEN Slist ELSE Slist ENDIF ';'  */
#line 253 "task1.y"
                                                            {
                                                                typecheck((yyvsp[-7].nptr)->type, TYPE_BOOL, 'e');
                                                                (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_IF_ELSE, NULL, NULL, NULL, (yyvsp[-7].nptr), (yyvsp[-2].nptr), (yyvsp[-4].nptr));
                                                            }
#line 1729 "y.tab.c"
    break;

  case 49: /* IfStmt: IF '(' expr ')' THEN Slist ENDIF ';'  */
#line 257 "task1.y"
                                                            {
                                                                typecheck((yyvsp[-5].nptr)->type, TYPE_BOOL, 'i');
                                                                (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_IF, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-2].nptr), NULL);
                                                            }
#line 1738 "y.tab.c"
    break;

  case 50: /* WhileStmt: WHILE '(' expr ')' DO Slist ENDWHILE ';'  */
#line 263 "task1.y"
                                                            {
                                                                typecheck((yyvsp[-5].nptr)->type, TYPE_BOOL, 'w');
                                                                (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_WHILE, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-2].nptr), NULL);
                                                            }
#line 1747 "y.tab.c"
    break;

  case 51: /* BrkStmt: BREAK ';'  */
#line 268 "task1.y"
                                    {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_BREAK, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1753 "y.tab.c"
    break;

  case 52: /* ContStmt: CONT ';'  */
#line 271 "task1.y"
                                    {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_CONT, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1759 "y.tab.c"
    break;

  case 53: /* InputStmt: READ '(' id ')' ';'  */
#line 274 "task1.y"
                                    {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_READ, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);}
#line 1765 "y.tab.c"
    break;

  case 54: /* OutputStmt: WRITE '(' expr ')' ';'  */
#line 277 "task1.y"
                                    {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_WRITE, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);}
#line 1771 "y.tab.c"
    break;

  case 55: /* AsgStmt: id ASSGN expr ';'  */
#line 280 "task1.y"
                                    {
                                        typecheck((yyvsp[-3].nptr)->type, (yyvsp[-1].nptr)->type, '=');
                                        (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                                    }
#line 1780 "y.tab.c"
    break;

  case 56: /* ExprList: ExprList ',' expr  */
#line 286 "task1.y"
                            {
                                (yyvsp[0].nptr)->arglist = (yyvsp[-2].nptr);
                                (yyval.nptr) = (yyvsp[0].nptr);
                            }
#line 1789 "y.tab.c"
    break;

  case 57: /* ExprList: expr  */
#line 290 "task1.y"
                            {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1795 "y.tab.c"
    break;

  case 58: /* ExprList: %empty  */
#line 291 "task1.y"
                            {(yyval.nptr) = NULL;}
#line 1801 "y.tab.c"
    break;

  case 59: /* expr: expr PLUS expr  */
#line 294 "task1.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TYPE_INT, NODE_PLUS, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1810 "y.tab.c"
    break;

  case 60: /* expr: expr MINUS expr  */
#line 298 "task1.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TYPE_INT, NODE_MINUS, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1819 "y.tab.c"
    break;

  case 61: /* expr: expr MUL expr  */
#line 302 "task1.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TYPE_INT, NODE_MUL, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1828 "y.tab.c"
    break;

  case 62: /* expr: expr DIV expr  */
#line 306 "task1.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TYPE_INT, NODE_DIV, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1837 "y.tab.c"
    break;

  case 63: /* expr: expr MOD expr  */
#line 310 "task1.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TYPE_INT, NODE_MOD, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1846 "y.tab.c"
    break;

  case 64: /* expr: expr LT expr  */
#line 314 "task1.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_LT, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1855 "y.tab.c"
    break;

  case 65: /* expr: expr GT expr  */
#line 318 "task1.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_GT, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1864 "y.tab.c"
    break;

  case 66: /* expr: expr LE expr  */
#line 322 "task1.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_LE, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1873 "y.tab.c"
    break;

  case 67: /* expr: expr GE expr  */
#line 326 "task1.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_GE, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1882 "y.tab.c"
    break;

  case 68: /* expr: expr NEQ expr  */
#line 330 "task1.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_NEQ, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1891 "y.tab.c"
    break;

  case 69: /* expr: expr EQ expr  */
#line 334 "task1.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_EQ, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1900 "y.tab.c"
    break;

  case 70: /* expr: '(' expr ')'  */
#line 338 "task1.y"
                        {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 1906 "y.tab.c"
    break;

  case 71: /* expr: NUM  */
#line 339 "task1.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1912 "y.tab.c"
    break;

  case 72: /* expr: MINUS NUM  */
#line 340 "task1.y"
                        {
                            (yyvsp[0].nptr)->value.intval = -1*((yyvsp[0].nptr)->value.intval);
                            (yyval.nptr) = (yyvsp[0].nptr);
                        }
#line 1921 "y.tab.c"
    break;

  case 73: /* expr: STRVAL  */
#line 344 "task1.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1927 "y.tab.c"
    break;

  case 74: /* expr: id  */
#line 345 "task1.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1933 "y.tab.c"
    break;

  case 75: /* expr: func  */
#line 346 "task1.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1939 "y.tab.c"
    break;

  case 76: /* func: ID '(' ExprList ')'  */
#line 349 "task1.y"
                            {
                                assignType((yyvsp[-3].nptr), 1);
                                (yyvsp[-3].nptr)->nodetype = NODE_FUNC;
                                (yyvsp[-3].nptr)->ptr1 = reverseList((yyvsp[-1].nptr));
                                (yyval.nptr) = (yyvsp[-3].nptr);
                            }
#line 1950 "y.tab.c"
    break;

  case 77: /* id: ID  */
#line 356 "task1.y"
                        {
                            assignType((yyvsp[0].nptr), 0);
                            (yyval.nptr) = (yyvsp[0].nptr);
                        }
#line 1959 "y.tab.c"
    break;

  case 78: /* id: ID '[' NUM ']'  */
#line 360 "task1.y"
                        {
                            assignType((yyvsp[-3].nptr), 2);
                            (yyval.nptr) = TreeCreate((yyvsp[-3].nptr)->type, NODE_ARRAY, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                        }
#line 1968 "y.tab.c"
    break;

  case 79: /* id: ID '[' id ']'  */
#line 364 "task1.y"
                        {
                            assignType((yyvsp[-3].nptr), 2);
                            (yyval.nptr) = TreeCreate((yyvsp[-3].nptr)->type, NODE_ARRAY, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                        }
#line 1977 "y.tab.c"
    break;


#line 1981 "y.tab.c"

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

#line 370 "task1.y"


int yyerror(char const *s) {
    //printf("\033[0;31mERR:%d\033[0m : ", lineno);
    printf("%s", s);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        yyerror("Please provide an input filename\n");
        exit(1);
    } else {
        fp = fopen(argv[1], "r");
        if (!fp) {
            yyerror("Invalid input file specified\n");
            exit(1);
        } else {
            yyin = fp;
        }
    }
    yyparse();
    return 0;
}
