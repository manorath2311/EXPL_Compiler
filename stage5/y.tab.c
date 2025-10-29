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
        extern int lineno;
        FILE *fp;
        FILE *intermediate;
        void print(int);
        struct Paramstruct *argList1, *argList2;
        int declCount = 0, defCount = 0; // Definition and Declaration count of functions
        int testing = 0; // can use to test ASTree
        
        // Internal yyerror implementation for two arguments
        int yyerror_impl(const char *s, const char *var);
        
        // Wrapper for Bison's single-argument calls
        #define yyerror(msg) yyerror_impl(msg, NULL)
       

#line 96 "y.tab.c"

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
    START = 261,                   /* START  */
    END = 262,                     /* END  */
    READ = 263,                    /* READ  */
    WRITE = 264,                   /* WRITE  */
    PLUS = 265,                    /* PLUS  */
    MINUS = 266,                   /* MINUS  */
    MUL = 267,                     /* MUL  */
    DIV = 268,                     /* DIV  */
    MOD = 269,                     /* MOD  */
    ASSGN = 270,                   /* ASSGN  */
    AND = 271,                     /* AND  */
    OR = 272,                      /* OR  */
    IF = 273,                      /* IF  */
    THEN = 274,                    /* THEN  */
    ELSE = 275,                    /* ELSE  */
    ENDIF = 276,                   /* ENDIF  */
    WHILE = 277,                   /* WHILE  */
    DO = 278,                      /* DO  */
    ENDWHILE = 279,                /* ENDWHILE  */
    EQ = 280,                      /* EQ  */
    NEQ = 281,                     /* NEQ  */
    LE = 282,                      /* LE  */
    GE = 283,                      /* GE  */
    LT = 284,                      /* LT  */
    GT = 285,                      /* GT  */
    BREAK = 286,                   /* BREAK  */
    CONT = 287,                    /* CONT  */
    DECL = 288,                    /* DECL  */
    ENDDECL = 289,                 /* ENDDECL  */
    INT = 290,                     /* INT  */
    STR = 291,                     /* STR  */
    MAIN = 292,                    /* MAIN  */
    RETURN = 293,                  /* RETURN  */
    ADDR = 294                     /* ADDR  */
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
#define START 261
#define END 262
#define READ 263
#define WRITE 264
#define PLUS 265
#define MINUS 266
#define MUL 267
#define DIV 268
#define MOD 269
#define ASSGN 270
#define AND 271
#define OR 272
#define IF 273
#define THEN 274
#define ELSE 275
#define ENDIF 276
#define WHILE 277
#define DO 278
#define ENDWHILE 279
#define EQ 280
#define NEQ 281
#define LE 282
#define GE 283
#define LT 284
#define GT 285
#define BREAK 286
#define CONT 287
#define DECL 288
#define ENDDECL 289
#define INT 290
#define STR 291
#define MAIN 292
#define RETURN 293
#define ADDR 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "ex2.y"

    struct ASTNode *nptr;

#line 231 "y.tab.c"

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
  YYSYMBOL_START = 6,                      /* START  */
  YYSYMBOL_END = 7,                        /* END  */
  YYSYMBOL_READ = 8,                       /* READ  */
  YYSYMBOL_WRITE = 9,                      /* WRITE  */
  YYSYMBOL_PLUS = 10,                      /* PLUS  */
  YYSYMBOL_MINUS = 11,                     /* MINUS  */
  YYSYMBOL_MUL = 12,                       /* MUL  */
  YYSYMBOL_DIV = 13,                       /* DIV  */
  YYSYMBOL_MOD = 14,                       /* MOD  */
  YYSYMBOL_ASSGN = 15,                     /* ASSGN  */
  YYSYMBOL_AND = 16,                       /* AND  */
  YYSYMBOL_OR = 17,                        /* OR  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_THEN = 19,                      /* THEN  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_ENDIF = 21,                     /* ENDIF  */
  YYSYMBOL_WHILE = 22,                     /* WHILE  */
  YYSYMBOL_DO = 23,                        /* DO  */
  YYSYMBOL_ENDWHILE = 24,                  /* ENDWHILE  */
  YYSYMBOL_EQ = 25,                        /* EQ  */
  YYSYMBOL_NEQ = 26,                       /* NEQ  */
  YYSYMBOL_LE = 27,                        /* LE  */
  YYSYMBOL_GE = 28,                        /* GE  */
  YYSYMBOL_LT = 29,                        /* LT  */
  YYSYMBOL_GT = 30,                        /* GT  */
  YYSYMBOL_BREAK = 31,                     /* BREAK  */
  YYSYMBOL_CONT = 32,                      /* CONT  */
  YYSYMBOL_DECL = 33,                      /* DECL  */
  YYSYMBOL_ENDDECL = 34,                   /* ENDDECL  */
  YYSYMBOL_INT = 35,                       /* INT  */
  YYSYMBOL_STR = 36,                       /* STR  */
  YYSYMBOL_MAIN = 37,                      /* MAIN  */
  YYSYMBOL_RETURN = 38,                    /* RETURN  */
  YYSYMBOL_ADDR = 39,                      /* ADDR  */
  YYSYMBOL_40_ = 40,                       /* ';'  */
  YYSYMBOL_41_ = 41,                       /* ','  */
  YYSYMBOL_42_ = 42,                       /* '('  */
  YYSYMBOL_43_ = 43,                       /* ')'  */
  YYSYMBOL_44_ = 44,                       /* '['  */
  YYSYMBOL_45_ = 45,                       /* ']'  */
  YYSYMBOL_46_ = 46,                       /* '{'  */
  YYSYMBOL_47_ = 47,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_program = 49,                   /* program  */
  YYSYMBOL_GDeclBlock = 50,                /* GDeclBlock  */
  YYSYMBOL_GDeclList = 51,                 /* GDeclList  */
  YYSYMBOL_GDecl = 52,                     /* GDecl  */
  YYSYMBOL_Type = 53,                      /* Type  */
  YYSYMBOL_FType = 54,                     /* FType  */
  YYSYMBOL_GIdList = 55,                   /* GIdList  */
  YYSYMBOL_GId = 56,                       /* GId  */
  YYSYMBOL_FDefBlock = 57,                 /* FDefBlock  */
  YYSYMBOL_FDef = 58,                      /* FDef  */
  YYSYMBOL_ParamList = 59,                 /* ParamList  */
  YYSYMBOL_Param = 60,                     /* Param  */
  YYSYMBOL_MainBlock = 61,                 /* MainBlock  */
  YYSYMBOL_LDeclBlock = 62,                /* LDeclBlock  */
  YYSYMBOL_LDecList = 63,                  /* LDecList  */
  YYSYMBOL_LDecl = 64,                     /* LDecl  */
  YYSYMBOL_IdList = 65,                    /* IdList  */
  YYSYMBOL_Body = 66,                      /* Body  */
  YYSYMBOL_RetStmt = 67,                   /* RetStmt  */
  YYSYMBOL_Slist = 68,                     /* Slist  */
  YYSYMBOL_Stmt = 69,                      /* Stmt  */
  YYSYMBOL_IfStmt = 70,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 71,                 /* WhileStmt  */
  YYSYMBOL_BrkStmt = 72,                   /* BrkStmt  */
  YYSYMBOL_ContStmt = 73,                  /* ContStmt  */
  YYSYMBOL_InputStmt = 74,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 75,                /* OutputStmt  */
  YYSYMBOL_AsgStmt = 76,                   /* AsgStmt  */
  YYSYMBOL_ExprList = 77,                  /* ExprList  */
  YYSYMBOL_expr = 78,                      /* expr  */
  YYSYMBOL_func = 79,                      /* func  */
  YYSYMBOL_id = 80                         /* id  */
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
#define YYLAST   372

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


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
      42,    43,     2,     2,    41,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,    45,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    51,    51,    52,    53,    56,    57,    60,    61,    64,
      67,    68,    71,    72,    76,    77,    80,    87,    91,   100,
     106,   107,   110,   182,   183,   184,   188,   192,   199,   243,
     244,   245,   248,   249,   252,   255,   259,   265,   266,   269,
     279,   280,   283,   284,   285,   286,   287,   288,   289,   290,
     293,   297,   303,   308,   311,   314,   317,   320,   326,   330,
     331,   334,   338,   342,   346,   350,   354,   358,   362,   366,
     370,   374,   378,   382,   386,   387,   388,   392,   393,   394,
     395,   406,   456,   460,   466
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
  "START", "END", "READ", "WRITE", "PLUS", "MINUS", "MUL", "DIV", "MOD",
  "ASSGN", "AND", "OR", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO",
  "ENDWHILE", "EQ", "NEQ", "LE", "GE", "LT", "GT", "BREAK", "CONT", "DECL",
  "ENDDECL", "INT", "STR", "MAIN", "RETURN", "ADDR", "';'", "','", "'('",
  "')'", "'['", "']'", "'{'", "'}'", "$accept", "program", "GDeclBlock",
  "GDeclList", "GDecl", "Type", "FType", "GIdList", "GId", "FDefBlock",
  "FDef", "ParamList", "Param", "MainBlock", "LDeclBlock", "LDecList",
  "LDecl", "IdList", "Body", "RetStmt", "Slist", "Stmt", "IfStmt",
  "WhileStmt", "BrkStmt", "ContStmt", "InputStmt", "OutputStmt", "AsgStmt",
  "ExprList", "expr", "func", "id", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-130)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      29,    62,  -130,  -130,    33,    45,   -35,  -130,  -130,    69,
    -130,     2,  -130,     0,    45,  -130,  -130,   -22,  -130,  -130,
     -39,    36,    48,  -130,    30,  -130,  -130,    58,    71,    97,
    -130,  -130,     2,    71,    67,  -130,  -130,    18,    81,  -130,
      82,  -130,    99,    95,  -130,   110,    71,  -130,  -130,    87,
      96,   128,  -130,  -130,    95,  -130,   137,   102,  -130,   117,
     129,   128,  -130,    52,  -130,  -130,    -1,   122,   142,   176,
     143,   155,   160,   162,    24,   175,   117,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,   163,   186,  -130,   158,  -130,
     202,    24,    24,    20,    24,  -130,    24,    24,  -130,  -130,
    -130,  -130,   215,    20,    24,   224,  -130,  -130,  -130,   214,
    -130,  -130,    24,  -130,  -130,   138,   332,    57,   178,   180,
     140,   161,   182,  -130,  -130,   203,    24,    24,    24,    24,
      24,    24,    24,    24,    24,    24,    24,    24,    24,  -130,
    -130,   245,    24,  -130,  -130,   184,   187,   207,   216,  -130,
      46,    46,  -130,  -130,  -130,   133,   133,    65,    65,   342,
     342,   342,   342,  -130,   332,  -130,  -130,   319,   319,   272,
     287,   319,   204,   205,   304,  -130,  -130,   208,  -130
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    10,    11,     0,     0,     0,     4,     6,     0,
       8,     0,     1,     0,     0,    21,     3,     0,     5,     7,
      17,     0,     0,    15,     0,    20,     2,     0,    25,     0,
      19,     9,     0,    25,     0,    12,    13,     0,     0,    24,
       0,    14,     0,    31,    26,     0,     0,    16,    18,     0,
       0,     0,    27,    23,    31,    30,     0,     0,    33,     0,
       0,     0,    36,     0,    29,    32,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    41,    45,    46,
      47,    48,    42,    43,    44,     0,     0,    28,     0,    34,
       0,    60,     0,     0,     0,    84,     0,     0,    53,    54,
      75,    77,     0,     0,     0,     0,    79,    78,    38,     0,
      40,    49,     0,    22,    35,     0,    59,     0,    82,     0,
       0,     0,     0,    76,    80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    39,
      37,     0,     0,    81,    83,     0,     0,     0,     0,    74,
      61,    62,    63,    64,    65,    72,    73,    71,    70,    68,
      69,    66,    67,    57,    58,    55,    56,     0,     0,     0,
       0,     0,     0,     0,     0,    51,    52,     0,    50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -130,  -130,  -130,  -130,   233,     7,   -31,  -130,   211,  -130,
     246,   230,   201,     4,   212,  -130,   210,  -130,   217,   189,
    -129,   -75,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
     -81,   -51,   -59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     9,    10,    11,    37,    22,    23,    14,
      15,    38,    39,     7,    51,    57,    58,    63,    60,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,   115,
     105,   106,   107
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      86,   110,    17,    28,    24,    29,    20,     6,    85,    16,
     116,   117,    13,   120,    21,   121,   122,    86,    26,    56,
      27,    13,    44,   125,   118,    85,    56,   100,    66,   101,
      45,   141,    69,    12,   119,   102,    69,    17,   169,   170,
      30,    91,   174,    92,   124,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   128,   129,
     130,   164,     1,   103,     2,     3,   104,   126,   127,   128,
     129,   130,    33,   131,   132,   126,   127,   128,   129,   130,
       2,     3,   133,   134,   135,   136,   137,   138,    31,    32,
     133,   134,    89,    90,   110,   110,     8,     2,     3,   110,
      40,    34,   144,    18,     2,     3,    35,    36,    86,    86,
      86,    86,    86,    43,    52,    86,    85,    85,    85,    85,
      85,    66,    46,    85,    47,    67,    68,    48,    50,    69,
      55,    35,    36,    54,    59,    70,    64,    35,    36,    71,
      46,    62,    49,   126,   127,   128,   129,   130,    72,    73,
     126,   127,   128,   129,   130,    74,   131,   132,   133,   134,
     135,   136,   137,   138,    93,   133,   134,   135,   136,   137,
     138,   126,   127,   128,   129,   130,    87,   131,   132,   142,
      95,   143,   108,   146,    94,    96,   133,   134,   135,   136,
     137,   138,   126,   127,   128,   129,   130,    97,   131,   132,
      98,   112,    99,   111,   147,   113,   114,   133,   134,   135,
     136,   137,   138,   126,   127,   128,   129,   130,   123,   131,
     132,   140,    92,   145,   165,   148,   167,   166,   133,   134,
     135,   136,   137,   138,   126,   127,   128,   129,   130,   168,
     131,   132,    19,    41,   175,   176,   149,    53,   178,   133,
     134,   135,   136,   137,   138,   126,   127,   128,   129,   130,
      25,   131,   132,    42,   139,   109,    61,    65,     0,     0,
     133,   134,   135,   136,   137,   138,    66,     0,    88,     0,
      67,    68,     0,     0,    69,   163,     0,     0,     0,     0,
      70,    66,   171,   172,    71,    67,    68,     0,     0,    69,
       0,     0,     0,    72,    73,    70,     0,     0,    66,    71,
       0,   173,    67,    68,     0,     0,    69,     0,    72,    73,
       0,     0,    70,    66,     0,   177,    71,    67,    68,     0,
       0,    69,     0,     0,     0,    72,    73,    70,     0,     0,
       0,    71,   126,   127,   128,   129,   130,     0,   131,   132,
      72,    73,   126,   127,   128,   129,   130,   133,   134,   135,
     136,   137,   138,     0,     0,     0,     0,   133,   134,    -1,
      -1,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
      59,    76,    37,    42,     4,    44,     4,     0,    59,     5,
      91,    92,     5,    94,    12,    96,    97,    76,    14,    50,
      42,    14,     4,   104,     4,    76,    57,     3,     4,     5,
      12,   112,    12,     0,    93,    11,    12,    37,   167,   168,
       4,    42,   171,    44,   103,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,    12,    13,
      14,   142,    33,    39,    35,    36,    42,    10,    11,    12,
      13,    14,    42,    16,    17,    10,    11,    12,    13,    14,
      35,    36,    25,    26,    27,    28,    29,    30,    40,    41,
      25,    26,    40,    41,   169,   170,    34,    35,    36,   174,
       3,    43,    45,    34,    35,    36,    35,    36,   167,   168,
     169,   170,   171,    46,     4,   174,   167,   168,   169,   170,
     171,     4,    41,   174,    43,     8,     9,    45,    33,    12,
      34,    35,    36,    46,     6,    18,    34,    35,    36,    22,
      41,     4,    43,    10,    11,    12,    13,    14,    31,    32,
      10,    11,    12,    13,    14,    38,    16,    17,    25,    26,
      27,    28,    29,    30,    42,    25,    26,    27,    28,    29,
      30,    10,    11,    12,    13,    14,    47,    16,    17,    41,
       4,    43,     7,    43,    42,    42,    25,    26,    27,    28,
      29,    30,    10,    11,    12,    13,    14,    42,    16,    17,
      40,    15,    40,    40,    43,    47,     4,    25,    26,    27,
      28,    29,    30,    10,    11,    12,    13,    14,     3,    16,
      17,     7,    44,    43,    40,    43,    19,    40,    25,    26,
      27,    28,    29,    30,    10,    11,    12,    13,    14,    23,
      16,    17,     9,    32,    40,    40,    43,    46,    40,    25,
      26,    27,    28,    29,    30,    10,    11,    12,    13,    14,
      14,    16,    17,    33,    40,    76,    54,    57,    -1,    -1,
      25,    26,    27,    28,    29,    30,     4,    -1,    61,    -1,
       8,     9,    -1,    -1,    12,    40,    -1,    -1,    -1,    -1,
      18,     4,    20,    21,    22,     8,     9,    -1,    -1,    12,
      -1,    -1,    -1,    31,    32,    18,    -1,    -1,     4,    22,
      -1,    24,     8,     9,    -1,    -1,    12,    -1,    31,    32,
      -1,    -1,    18,     4,    -1,    21,    22,     8,     9,    -1,
      -1,    12,    -1,    -1,    -1,    31,    32,    18,    -1,    -1,
      -1,    22,    10,    11,    12,    13,    14,    -1,    16,    17,
      31,    32,    10,    11,    12,    13,    14,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    33,    35,    36,    49,    50,    53,    61,    34,    51,
      52,    53,     0,    53,    57,    58,    61,    37,    34,    52,
       4,    12,    55,    56,     4,    58,    61,    42,    42,    44,
       4,    40,    41,    42,    43,    35,    36,    54,    59,    60,
       3,    56,    59,    46,     4,    12,    41,    43,    45,    43,
      33,    62,     4,    60,    46,    34,    54,    63,    64,     6,
      66,    62,     4,    65,    34,    64,     4,     8,     9,    12,
      18,    22,    31,    32,    38,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    79,    80,    47,    66,    40,
      41,    42,    44,    42,    42,     4,    42,    42,    40,    40,
       3,     5,    11,    39,    42,    78,    79,    80,     7,    67,
      69,    40,    15,    47,     4,    77,    78,    78,     4,    80,
      78,    78,    78,     3,    80,    78,    10,    11,    12,    13,
      14,    16,    17,    25,    26,    27,    28,    29,    30,    40,
       7,    78,    41,    43,    45,    43,    43,    43,    43,    43,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    40,    78,    40,    40,    19,    23,    68,
      68,    20,    21,    24,    68,    40,    40,    21,    40
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    49,    49,    50,    50,    51,    51,    52,
      53,    53,    54,    54,    55,    55,    56,    56,    56,    56,
      57,    57,    58,    59,    59,    59,    60,    60,    61,    62,
      62,    62,    63,    63,    64,    65,    65,    66,    66,    67,
      68,    68,    69,    69,    69,    69,    69,    69,    69,    69,
      70,    70,    71,    72,    73,    74,    75,    76,    77,    77,
      77,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    79,    80,    80,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       1,     1,     1,     1,     3,     1,     4,     1,     4,     2,
       2,     1,     9,     3,     1,     0,     2,     3,     8,     3,
       2,     0,     2,     1,     3,     3,     1,     4,     3,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     2,
      10,     8,     8,     2,     2,     5,     5,     4,     3,     1,
       0,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     2,     1,     1,     1,
       2,     4,     1,     4,     2
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
#line 51 "ex2.y"
                                        {}
#line 1444 "y.tab.c"
    break;

  case 3: /* program: GDeclBlock MainBlock  */
#line 52 "ex2.y"
                                        {}
#line 1450 "y.tab.c"
    break;

  case 4: /* program: MainBlock  */
#line 53 "ex2.y"
                                        {}
#line 1456 "y.tab.c"
    break;

  case 5: /* GDeclBlock: DECL GDeclList ENDDECL  */
#line 56 "ex2.y"
                                        { printGSymbolTable() ;print_header();}
#line 1462 "y.tab.c"
    break;

  case 6: /* GDeclBlock: DECL ENDDECL  */
#line 57 "ex2.y"
                                        { printGSymbolTable() ;print_header();}
#line 1468 "y.tab.c"
    break;

  case 10: /* Type: INT  */
#line 67 "ex2.y"
            {declarationType = TYPE_INT;}
#line 1474 "y.tab.c"
    break;

  case 11: /* Type: STR  */
#line 68 "ex2.y"
            {declarationType = TYPE_STR;}
#line 1480 "y.tab.c"
    break;

  case 12: /* FType: INT  */
#line 71 "ex2.y"
             {FDeclarationType = TYPE_INT;}
#line 1486 "y.tab.c"
    break;

  case 13: /* FType: STR  */
#line 72 "ex2.y"
             {FDeclarationType = TYPE_STR;}
#line 1492 "y.tab.c"
    break;

  case 16: /* GId: ID '(' ParamList ')'  */
#line 80 "ex2.y"
                            {
                                declCount++;
                                checkAvailability((yyvsp[-3].nptr)->name, 1);
                                GInstall((yyvsp[-3].nptr)->name, declarationType, -1, Phead);
                                Phead = NULL;
                                Ptail = NULL;
                            }
#line 1504 "y.tab.c"
    break;

  case 17: /* GId: ID  */
#line 87 "ex2.y"
                            {
                                checkAvailability((yyvsp[0].nptr)->name, 1);
                                GInstall((yyvsp[0].nptr)->name, declarationType, 1, NULL);
                            }
#line 1513 "y.tab.c"
    break;

  case 18: /* GId: ID '[' NUM ']'  */
#line 91 "ex2.y"
                            {
                                checkAvailability((yyvsp[-3].nptr)->name, 1);
                                if((yyvsp[-1].nptr)->value.intval < 1) 
                                {
                                    yyerror_impl("Invalid array size for", (yyvsp[-3].nptr)->name);
                                    exit(1);
                                }
                                GInstall((yyvsp[-3].nptr)->name, declarationType, (yyvsp[-1].nptr)->value.intval, NULL);
                            }
#line 1527 "y.tab.c"
    break;

  case 19: /* GId: MUL ID  */
#line 100 "ex2.y"
                            {
                                checkAvailability((yyvsp[0].nptr)->name, 1);
                                GInstall((yyvsp[0].nptr)->name, TYPE_INT_PTR, 1, NULL); 
                            }
#line 1536 "y.tab.c"
    break;

  case 22: /* FDef: Type ID '(' ParamList ')' '{' LDeclBlock Body '}'  */
#line 111 "ex2.y"
                                                        {
                                                            defCount++;
                                                            Gtemp = GLookup((yyvsp[-7].nptr)->name);

                                                            if(Gtemp == NULL) {
                                                                yyerror_impl("Function is not declared:", (yyvsp[-7].nptr)->name);
                                                                exit(1);
                                                            }

                                                            if(Gtemp->type != declarationType) {
                                                               yyerror_impl("Function type does not match declaration:", (yyvsp[-7].nptr)->name);
                                                               exit(1);
                                                            }

                                                            argList1 = Phead;
                                                            argList2 = Gtemp->paramlist;

                                                            while(argList1 != NULL && argList2 != NULL) {
                                                                if(argList1->type != argList2->type) {
                                                                    yyerror_impl("Conflict in argument types for function:", (yyvsp[-7].nptr)->name);
                                                                    exit(1);
                                                                }

                                                                if(strcmp(argList1->name, argList2->name)) {
                                                                    yyerror_impl("Conflict in argument names for function:", (yyvsp[-7].nptr)->name);
                                                                    exit(1);
                                                                }

                                                                argList1 = argList1->next;
                                                                argList2 = argList2->next;
                                                            }

                                                            if ((argList1 != NULL) || (argList2 != NULL)) {
                                                                yyerror_impl("Not enough arguments for function:", (yyvsp[-7].nptr)->name);
                                                                exit(1);
                                                            }

                                                             printLSymbolTable();
                                                             printf("print_tree for function %s:\n", (yyvsp[-7].nptr)->name);
                                                             print_tree((yyvsp[-1].nptr),0);
                                                             printf("Done\n");

                                                             
                                                            if(testing) 
                                                            {
                                                                // print_dot($8, $2->name);
                                                            }
                                                            else 
                                                            {
                                                                fprintf(intermediate, "F%d:\n",Gtemp->flabel);
                                                                fprintf(intermediate, "PUSH BP\n");
                                                                fprintf(intermediate, "MOV BP,SP\n");

                                                                Ltemp = Lhead;
                                                                while(Ltemp != NULL) 
                                                                {
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
#line 1610 "y.tab.c"
    break;

  case 25: /* ParamList: %empty  */
#line 184 "ex2.y"
                            {(yyval.nptr) = NULL;}
#line 1616 "y.tab.c"
    break;

  case 26: /* Param: FType ID  */
#line 188 "ex2.y"
                {
                    checkAvailability((yyvsp[0].nptr)->name, 0);
                    PInstall((yyvsp[0].nptr)->name, FDeclarationType);
                }
#line 1625 "y.tab.c"
    break;

  case 27: /* Param: FType MUL ID  */
#line 193 "ex2.y"
                {
                    checkAvailability((yyvsp[0].nptr)->name, 0);
                    PInstall((yyvsp[0].nptr)->name, TYPE_INT_PTR);
                }
#line 1634 "y.tab.c"
    break;

  case 28: /* MainBlock: Type MAIN '(' ')' '{' LDeclBlock Body '}'  */
#line 199 "ex2.y"
                                                       {
                                                            if(defCount != declCount) 
                                                            {
                                                                yyerror_impl("All functions declared need to be defined", NULL);
                                                                exit(1);
                                                            }

                                                            if(declarationType != TYPE_INT) 
                                                            {
                                                                yyerror_impl("Main return type should be of integer type", NULL);
                                                                exit(1);
                                                            }

                                                            //printGSymbolTable();
                                                            printLSymbolTable();
                                                            printf("print_tree for main:\n");
                                                            print_tree((yyvsp[-1].nptr),0);
                                                            printf("Done\n");
                                                            if(testing) 
                                                            {
                                                                
                                                                //print_dot($7, "main");
                                                            }
                                                            else 
                                                            {
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
#line 1681 "y.tab.c"
    break;

  case 29: /* LDeclBlock: DECL LDecList ENDDECL  */
#line 243 "ex2.y"
                                    {InstallParamsInLocal();}
#line 1687 "y.tab.c"
    break;

  case 30: /* LDeclBlock: DECL ENDDECL  */
#line 244 "ex2.y"
                                    {InstallParamsInLocal();}
#line 1693 "y.tab.c"
    break;

  case 31: /* LDeclBlock: %empty  */
#line 245 "ex2.y"
                                    {InstallParamsInLocal();}
#line 1699 "y.tab.c"
    break;

  case 35: /* IdList: IdList ',' ID  */
#line 255 "ex2.y"
                        {
                            checkAvailability((yyvsp[0].nptr)->name, 0);
                            LInstall((yyvsp[0].nptr)->name, FDeclarationType);
                        }
#line 1708 "y.tab.c"
    break;

  case 36: /* IdList: ID  */
#line 259 "ex2.y"
                        {
                            checkAvailability((yyvsp[0].nptr)->name, 0);
                            LInstall((yyvsp[0].nptr)->name, FDeclarationType);
                        }
#line 1717 "y.tab.c"
    break;

  case 37: /* Body: START Slist RetStmt END  */
#line 265 "ex2.y"
                                {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_CONNECTOR, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[-1].nptr), NULL);}
#line 1723 "y.tab.c"
    break;

  case 38: /* Body: START RetStmt END  */
#line 266 "ex2.y"
                                {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 1729 "y.tab.c"
    break;

  case 39: /* RetStmt: RETURN expr ';'  */
#line 269 "ex2.y"
                            {
                                if(declarationType == (yyvsp[-1].nptr)->type) {
                                    (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_RET, NULL, NULL, NULL, (yyvsp[-1].nptr), NULL, NULL);
                                } else {
                                    yyerror_impl("Return type mismatch", NULL);
                                    exit(1);
                                }
                            }
#line 1742 "y.tab.c"
    break;

  case 40: /* Slist: Slist Stmt  */
#line 279 "ex2.y"
                        {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_CONNECTOR, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);}
#line 1748 "y.tab.c"
    break;

  case 41: /* Slist: Stmt  */
#line 280 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1754 "y.tab.c"
    break;

  case 42: /* Stmt: InputStmt  */
#line 283 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1760 "y.tab.c"
    break;

  case 43: /* Stmt: OutputStmt  */
#line 284 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1766 "y.tab.c"
    break;

  case 44: /* Stmt: AsgStmt  */
#line 285 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1772 "y.tab.c"
    break;

  case 45: /* Stmt: IfStmt  */
#line 286 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1778 "y.tab.c"
    break;

  case 46: /* Stmt: WhileStmt  */
#line 287 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1784 "y.tab.c"
    break;

  case 47: /* Stmt: BrkStmt  */
#line 288 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1790 "y.tab.c"
    break;

  case 48: /* Stmt: ContStmt  */
#line 289 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1796 "y.tab.c"
    break;

  case 49: /* Stmt: func ';'  */
#line 290 "ex2.y"
                        {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 1802 "y.tab.c"
    break;

  case 50: /* IfStmt: IF '(' expr ')' THEN Slist ELSE Slist ENDIF ';'  */
#line 293 "ex2.y"
                                                            {
                                                                typecheck((yyvsp[-7].nptr)->type, TYPE_BOOL, 'e');
                                                                (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_IF_ELSE, NULL, NULL, NULL, (yyvsp[-7].nptr), (yyvsp[-2].nptr), (yyvsp[-4].nptr));
                                                            }
#line 1811 "y.tab.c"
    break;

  case 51: /* IfStmt: IF '(' expr ')' THEN Slist ENDIF ';'  */
#line 297 "ex2.y"
                                                            {
                                                                typecheck((yyvsp[-5].nptr)->type, TYPE_BOOL, 'i');
                                                                (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_IF, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-2].nptr), NULL);
                                                            }
#line 1820 "y.tab.c"
    break;

  case 52: /* WhileStmt: WHILE '(' expr ')' DO Slist ENDWHILE ';'  */
#line 303 "ex2.y"
                                                            {
                                                                typecheck((yyvsp[-5].nptr)->type, TYPE_BOOL, 'w');
                                                                (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_WHILE, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-2].nptr), NULL);
                                                            }
#line 1829 "y.tab.c"
    break;

  case 53: /* BrkStmt: BREAK ';'  */
#line 308 "ex2.y"
                                    {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_BREAK, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1835 "y.tab.c"
    break;

  case 54: /* ContStmt: CONT ';'  */
#line 311 "ex2.y"
                                    {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_CONT, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1841 "y.tab.c"
    break;

  case 55: /* InputStmt: READ '(' id ')' ';'  */
#line 314 "ex2.y"
                                    {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_READ, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);}
#line 1847 "y.tab.c"
    break;

  case 56: /* OutputStmt: WRITE '(' expr ')' ';'  */
#line 317 "ex2.y"
                                    {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_WRITE, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);}
#line 1853 "y.tab.c"
    break;

  case 57: /* AsgStmt: id ASSGN expr ';'  */
#line 320 "ex2.y"
                                    {
                                        typecheck((yyvsp[-3].nptr)->type, (yyvsp[-1].nptr)->type, '=');
                                        (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                                    }
#line 1862 "y.tab.c"
    break;

  case 58: /* ExprList: ExprList ',' expr  */
#line 326 "ex2.y"
                            {
                                (yyvsp[0].nptr)->arglist = (yyvsp[-2].nptr);
                                (yyval.nptr) = (yyvsp[0].nptr);
                            }
#line 1871 "y.tab.c"
    break;

  case 59: /* ExprList: expr  */
#line 330 "ex2.y"
                            {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1877 "y.tab.c"
    break;

  case 60: /* ExprList: %empty  */
#line 331 "ex2.y"
                            {(yyval.nptr) = NULL;}
#line 1883 "y.tab.c"
    break;

  case 61: /* expr: expr PLUS expr  */
#line 334 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TYPE_INT, NODE_PLUS, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1892 "y.tab.c"
    break;

  case 62: /* expr: expr MINUS expr  */
#line 338 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TYPE_INT, NODE_MINUS, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1901 "y.tab.c"
    break;

  case 63: /* expr: expr MUL expr  */
#line 342 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TYPE_INT, NODE_MUL, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1910 "y.tab.c"
    break;

  case 64: /* expr: expr DIV expr  */
#line 346 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TYPE_INT, NODE_DIV, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1919 "y.tab.c"
    break;

  case 65: /* expr: expr MOD expr  */
#line 350 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TYPE_INT, NODE_MOD, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1928 "y.tab.c"
    break;

  case 66: /* expr: expr LT expr  */
#line 354 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_LT, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1937 "y.tab.c"
    break;

  case 67: /* expr: expr GT expr  */
#line 358 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_GT, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1946 "y.tab.c"
    break;

  case 68: /* expr: expr LE expr  */
#line 362 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_LE, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1955 "y.tab.c"
    break;

  case 69: /* expr: expr GE expr  */
#line 366 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_GE, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1964 "y.tab.c"
    break;

  case 70: /* expr: expr NEQ expr  */
#line 370 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_NEQ, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1973 "y.tab.c"
    break;

  case 71: /* expr: expr EQ expr  */
#line 374 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_EQ, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1982 "y.tab.c"
    break;

  case 72: /* expr: expr AND expr  */
#line 378 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'l');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_AND, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1991 "y.tab.c"
    break;

  case 73: /* expr: expr OR expr  */
#line 382 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'l');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_OR, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2000 "y.tab.c"
    break;

  case 74: /* expr: '(' expr ')'  */
#line 386 "ex2.y"
                        {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 2006 "y.tab.c"
    break;

  case 75: /* expr: NUM  */
#line 387 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2012 "y.tab.c"
    break;

  case 76: /* expr: MINUS NUM  */
#line 388 "ex2.y"
                        {
                            (yyvsp[0].nptr)->value.intval = -1*((yyvsp[0].nptr)->value.intval);
                            (yyval.nptr) = (yyvsp[0].nptr);
                        }
#line 2021 "y.tab.c"
    break;

  case 77: /* expr: STRVAL  */
#line 392 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2027 "y.tab.c"
    break;

  case 78: /* expr: id  */
#line 393 "ex2.y"
                                {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2033 "y.tab.c"
    break;

  case 79: /* expr: func  */
#line 394 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2039 "y.tab.c"
    break;

  case 80: /* expr: ADDR id  */
#line 395 "ex2.y"
                       {
                            if((yyvsp[0].nptr)->type == TYPE_INT_PTR) 
                            {
                                yyerror_impl("Cannot take address of pointer variable", (yyvsp[0].nptr)->name);
                                exit(1);
                            }
                            (yyval.nptr) = TreeCreate(TYPE_INT_PTR, NODE_ADDR, NULL, NULL, NULL, (yyvsp[0].nptr), NULL, NULL);
                        }
#line 2052 "y.tab.c"
    break;

  case 81: /* func: ID '(' ExprList ')'  */
#line 406 "ex2.y"
                            {
                                 assignType((yyvsp[-3].nptr),1);
                                //checkParamType($1,$3);
                                (yyvsp[-3].nptr)->nodetype = NODE_FUNC;
                                (yyvsp[-3].nptr)->ptr1 = reverseList((yyvsp[-1].nptr));
                                    if((yyvsp[-3].nptr)==NULL || (yyvsp[-1].nptr)==NULL)
                                    {
                                        printf("Error at 394");
                                        exit(1);
                                    }
                                    struct Gsymbol* temp=GLookup((yyvsp[-3].nptr)->name);
                                    printf("func is :%s\n",temp->name);
                                    struct Paramstruct* temp2=temp->paramlist;
                                    struct ASTNode* right=(yyvsp[-3].nptr)->ptr1;

                                    while(right!=NULL && temp2!=NULL)
                                    {
                                        if(right->type==temp2->type)
                                        {
                                            // printf("hi bro %s %s\n",right->name,temp2->name);
                                            // printf("%d==%d\n",right->type,temp2->type);
                                            right=right->arglist;
                                            temp2=temp2->next;
                                        }
                                        else
                                        {
                                            // printf("hi bro %s %s\n",right->name,temp2->name);
                                            // printf("%d==%d\n",right->type,temp2->type);
                                            printf("mismatch bro in function arguments\n");
                                            exit(1);
                                        }
                                        
                                    }
                                    if(right!=NULL || temp2!=NULL)
                                    {
                                        printf("Error at 422");
                                        if(right==NULL)
                                        {
                                            printf("right is NULL\n");
                                        }
                                        if(temp2==NULL)
                                        {
                                            printf("temp2 is NULL\n");
                                        }
                                        exit(1);
                                    }
                                    (yyval.nptr) = (yyvsp[-3].nptr);
                                    codegen((yyval.nptr));
                            }
#line 2106 "y.tab.c"
    break;

  case 82: /* id: ID  */
#line 456 "ex2.y"
                        {
                            assignType((yyvsp[0].nptr), 0);
                            (yyval.nptr) = (yyvsp[0].nptr);
                        }
#line 2115 "y.tab.c"
    break;

  case 83: /* id: ID '[' expr ']'  */
#line 460 "ex2.y"
                        {
                            assignType((yyvsp[-3].nptr), 2);
                            (yyval.nptr) = TreeCreate((yyvsp[-3].nptr)->type, NODE_ARRAY, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                            (yyval.nptr)->Gentry = (yyvsp[-3].nptr)->Gentry;
                            (yyval.nptr)->Lentry = (yyvsp[-3].nptr)->Lentry;
                        }
#line 2126 "y.tab.c"
    break;

  case 84: /* id: MUL ID  */
#line 466 "ex2.y"
                        {
                            assignType((yyvsp[0].nptr), 0);
                            (yyval.nptr) = TreeCreate((yyvsp[0].nptr)->type, NODE_INT_PTR, (yyvsp[0].nptr)->name, NULL, NULL, NULL, NULL, NULL);
                            (yyval.nptr)->Gentry = (yyvsp[0].nptr)->Gentry;
                            (yyval.nptr)->Lentry = (yyvsp[0].nptr)->Lentry;
                        }
#line 2137 "y.tab.c"
    break;


#line 2141 "y.tab.c"

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

#line 475 "ex2.y"


int yyerror_impl(char const *s, const char *var) 
{
    printf("Error : %s",s);
    if(var != NULL) {
        printf(" '%s'", var);
    }
    printf("\n");
    return 0;
}

// Undefine the macro for the actual implementation
#undef yyerror

int main(int argc, char *argv[]) 
{
    if (argc < 2) 
    {
        yyerror_impl("Please provide an input filename", NULL);
        exit(1);
    }
    else 
    {
        fp = fopen(argv[1], "r");
        if (!fp) 
        {
            yyerror_impl("Invalid input file specified:", argv[1]);
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
