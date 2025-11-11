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
        int size=0;
       

#line 97 "y.tab.c"

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
    ADDR = 294,                    /* ADDR  */
    TUPLE = 295                    /* TUPLE  */
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
#define TUPLE 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "ex2.y"

    struct ASTNode *nptr;
    struct Paramstruct *pptr;

#line 235 "y.tab.c"

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
  YYSYMBOL_TUPLE = 40,                     /* TUPLE  */
  YYSYMBOL_41_ = 41,                       /* ';'  */
  YYSYMBOL_42_ = 42,                       /* ','  */
  YYSYMBOL_43_ = 43,                       /* '('  */
  YYSYMBOL_44_ = 44,                       /* ')'  */
  YYSYMBOL_45_ = 45,                       /* '['  */
  YYSYMBOL_46_ = 46,                       /* ']'  */
  YYSYMBOL_47_ = 47,                       /* '{'  */
  YYSYMBOL_48_ = 48,                       /* '}'  */
  YYSYMBOL_49_ = 49,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_program = 51,                   /* program  */
  YYSYMBOL_GDeclBlock = 52,                /* GDeclBlock  */
  YYSYMBOL_GDeclList = 53,                 /* GDeclList  */
  YYSYMBOL_GDecl = 54,                     /* GDecl  */
  YYSYMBOL_TD = 55,                        /* TD  */
  YYSYMBOL_Type = 56,                      /* Type  */
  YYSYMBOL_FType = 57,                     /* FType  */
  YYSYMBOL_GIdList = 58,                   /* GIdList  */
  YYSYMBOL_GId = 59,                       /* GId  */
  YYSYMBOL_FDefBlock = 60,                 /* FDefBlock  */
  YYSYMBOL_FDef = 61,                      /* FDef  */
  YYSYMBOL_ParamList = 62,                 /* ParamList  */
  YYSYMBOL_Param = 63,                     /* Param  */
  YYSYMBOL_MainBlock = 64,                 /* MainBlock  */
  YYSYMBOL_LDeclBlock = 65,                /* LDeclBlock  */
  YYSYMBOL_LDecList = 66,                  /* LDecList  */
  YYSYMBOL_LDecl = 67,                     /* LDecl  */
  YYSYMBOL_IdList = 68,                    /* IdList  */
  YYSYMBOL_Body = 69,                      /* Body  */
  YYSYMBOL_RetStmt = 70,                   /* RetStmt  */
  YYSYMBOL_Slist = 71,                     /* Slist  */
  YYSYMBOL_Stmt = 72,                      /* Stmt  */
  YYSYMBOL_IfStmt = 73,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 74,                 /* WhileStmt  */
  YYSYMBOL_BrkStmt = 75,                   /* BrkStmt  */
  YYSYMBOL_ContStmt = 76,                  /* ContStmt  */
  YYSYMBOL_InputStmt = 77,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 78,                /* OutputStmt  */
  YYSYMBOL_AsgStmt = 79,                   /* AsgStmt  */
  YYSYMBOL_ExprList = 80,                  /* ExprList  */
  YYSYMBOL_expr = 81,                      /* expr  */
  YYSYMBOL_func = 82,                      /* func  */
  YYSYMBOL_id = 83                         /* id  */
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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   367

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  187

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


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
      43,    44,     2,     2,    42,     2,    49,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    54,    54,    55,    56,    59,    60,    63,    64,    67,
      84,   111,   132,   147,   148,   151,   152,   156,   157,   161,
     168,   172,   181,   212,   213,   216,   283,   284,   285,   289,
     293,   300,   339,   340,   341,   344,   345,   348,   351,   355,
     361,   362,   365,   379,   380,   383,   384,   385,   386,   387,
     388,   389,   390,   393,   397,   403,   408,   411,   414,   417,
     420,   426,   430,   431,   434,   438,   442,   446,   450,   454,
     458,   462,   466,   470,   474,   478,   482,   486,   487,   488,
     492,   493,   494,   495,   506,   556,   560,   566,   572
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
  "ENDDECL", "INT", "STR", "MAIN", "RETURN", "ADDR", "TUPLE", "';'", "','",
  "'('", "')'", "'['", "']'", "'{'", "'}'", "'.'", "$accept", "program",
  "GDeclBlock", "GDeclList", "GDecl", "TD", "Type", "FType", "GIdList",
  "GId", "FDefBlock", "FDef", "ParamList", "Param", "MainBlock",
  "LDeclBlock", "LDecList", "LDecl", "IdList", "Body", "RetStmt", "Slist",
  "Stmt", "IfStmt", "WhileStmt", "BrkStmt", "ContStmt", "InputStmt",
  "OutputStmt", "AsgStmt", "ExprList", "expr", "func", "id", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-158)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      39,    -2,  -158,  -158,    44,   -15,    36,  -158,   105,  -158,
       2,  -158,    56,  -158,     3,   -15,  -158,  -158,   109,  -158,
      82,  -158,  -158,    55,   112,   156,  -158,   115,  -158,  -158,
      51,  -158,   169,   165,   176,  -158,  -158,    56,   165,   147,
    -158,  -158,  -158,    73,    17,  -158,   153,  -158,   117,   180,
    -158,   199,   165,  -158,  -158,   172,   103,   210,  -158,  -158,
     180,  -158,   213,   121,  -158,   206,   173,   210,  -158,   170,
    -158,  -158,    91,   177,   182,   218,   183,   184,   188,   189,
       0,   224,   206,  -158,  -158,  -158,  -158,  -158,  -158,  -158,
    -158,   212,   253,  -158,   217,  -158,   265,     0,     0,   267,
      80,     0,  -158,     0,     0,  -158,  -158,  -158,  -158,   269,
      80,     0,   229,  -158,  -158,  -158,   266,  -158,  -158,     0,
    -158,  -158,   138,    77,    53,  -158,    86,   230,   116,   137,
     158,  -158,  -158,   179,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -158,  -158,   250,
       0,  -158,  -158,   241,   242,   268,   261,  -158,   164,   164,
    -158,  -158,  -158,   222,   222,    16,    16,   337,   337,   337,
     337,  -158,    77,  -158,  -158,   324,   324,   277,   292,   324,
     247,   249,   309,  -158,  -158,   251,  -158
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    13,    14,     0,     0,     0,     4,     0,     6,
       0,     8,     0,     1,     0,     0,    24,     3,     0,    12,
       0,     5,     7,    20,     0,     0,    18,     0,    23,     2,
       0,    10,     0,    28,     0,    22,     9,     0,    28,     0,
      11,    15,    16,     0,     0,    27,     0,    17,     0,    34,
      29,     0,     0,    19,    21,     0,     0,     0,    30,    26,
      34,    33,     0,     0,    36,     0,     0,     0,    39,     0,
      32,    35,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,    48,    49,    50,    51,    45,    46,
      47,     0,     0,    31,     0,    37,     0,    63,     0,     0,
       0,     0,    87,     0,     0,    56,    57,    78,    80,     0,
       0,     0,     0,    82,    81,    41,     0,    43,    52,     0,
      25,    38,     0,    62,     0,    88,    85,     0,     0,     0,
       0,    79,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    42,    40,     0,
       0,    84,    86,     0,     0,     0,     0,    77,    64,    65,
      66,    67,    68,    75,    76,    74,    73,    71,    72,    69,
      70,    60,    61,    58,    59,     0,     0,     0,     0,     0,
       0,     0,     0,    54,    55,     0,    53
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -158,  -158,  -158,  -158,   283,  -158,    71,    52,  -158,   257,
    -158,   287,   273,   254,     9,   243,  -158,   244,  -158,   238,
     233,  -157,   -81,  -158,  -158,  -158,  -158,  -158,  -158,  -158,
    -158,   -88,   -57,   -65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,    10,    11,    20,    12,    43,    25,    26,
      15,    16,    44,    45,     7,    57,    63,    64,    69,    66,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
     122,   112,   113,   114
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      92,   117,     8,   107,    72,   108,     8,    27,    91,   123,
     124,   109,    75,   128,    17,   129,   130,    92,   177,   178,
       2,     3,   182,   133,    29,    91,   134,   135,   136,   137,
     138,   149,     9,     2,     3,   127,    21,     2,     3,   110,
      18,   141,   142,   111,    13,   132,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,    52,
      23,    53,   172,   134,   135,   136,   137,   138,    24,   139,
     140,     6,     1,    18,     2,     3,    14,    50,   141,   142,
     143,   144,   145,   146,   126,    51,    14,   134,   135,   136,
     137,   138,    75,   139,   140,    39,   117,   117,    33,   152,
      34,   117,   141,   142,   143,   144,   145,   146,    62,    19,
      92,    92,    92,    92,    92,    62,    35,    92,    91,    91,
      91,    91,    91,    31,    32,    91,   134,   135,   136,   137,
     138,    98,   139,   140,    97,    99,    98,    61,    41,    42,
      99,   141,   142,   143,   144,   145,   146,   134,   135,   136,
     137,   138,    30,   139,   140,    70,    41,    42,    38,    52,
     154,    55,   141,   142,   143,   144,   145,   146,   134,   135,
     136,   137,   138,    40,   139,   140,   136,   137,   138,    46,
     150,   155,   151,   141,   142,   143,   144,   145,   146,   134,
     135,   136,   137,   138,    49,   139,   140,    36,    37,    54,
      41,    42,   156,    58,   141,   142,   143,   144,   145,   146,
      72,    95,    96,    56,    73,    74,    65,    68,    75,    60,
     100,    93,   102,   157,    76,   101,   103,   104,    77,   105,
     106,   115,   134,   135,   136,   137,   138,    78,    79,   134,
     135,   136,   137,   138,    80,   139,   140,   141,   142,   143,
     144,   145,   146,   118,   141,   142,   143,   144,   145,   146,
     134,   135,   136,   137,   138,   120,   139,   140,   119,   121,
     147,   125,   131,   148,   153,   141,   142,   143,   144,   145,
     146,    72,   173,   174,   176,    73,    74,   175,   183,    75,
     184,   171,   186,    22,    47,    76,    72,   179,   180,    77,
      73,    74,    28,    67,    75,    94,    59,    71,    78,    79,
      76,    48,     0,    72,    77,   116,   181,    73,    74,     0,
       0,    75,     0,    78,    79,     0,     0,    76,    72,     0,
     185,    77,    73,    74,     0,     0,    75,     0,     0,     0,
      78,    79,    76,     0,     0,     0,    77,   134,   135,   136,
     137,   138,     0,     0,     0,    78,    79,     0,     0,     0,
       0,     0,   141,   142,    -1,    -1,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
      65,    82,     4,     3,     4,     5,     4,     4,    65,    97,
      98,    11,    12,   101,     5,   103,   104,    82,   175,   176,
      35,    36,   179,   111,    15,    82,    10,    11,    12,    13,
      14,   119,    34,    35,    36,   100,    34,    35,    36,    39,
      37,    25,    26,    43,     0,   110,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    42,
       4,    44,   150,    10,    11,    12,    13,    14,    12,    16,
      17,     0,    33,    37,    35,    36,     5,     4,    25,    26,
      27,    28,    29,    30,     4,    12,    15,    10,    11,    12,
      13,    14,    12,    16,    17,    44,   177,   178,    43,    46,
      45,   182,    25,    26,    27,    28,    29,    30,    56,     4,
     175,   176,   177,   178,   179,    63,     4,   182,   175,   176,
     177,   178,   179,    41,    42,   182,    10,    11,    12,    13,
      14,    45,    16,    17,    43,    49,    45,    34,    35,    36,
      49,    25,    26,    27,    28,    29,    30,    10,    11,    12,
      13,    14,    43,    16,    17,    34,    35,    36,    43,    42,
      44,    44,    25,    26,    27,    28,    29,    30,    10,    11,
      12,    13,    14,     4,    16,    17,    12,    13,    14,     3,
      42,    44,    44,    25,    26,    27,    28,    29,    30,    10,
      11,    12,    13,    14,    47,    16,    17,    41,    42,    46,
      35,    36,    44,     4,    25,    26,    27,    28,    29,    30,
       4,    41,    42,    33,     8,     9,     6,     4,    12,    47,
      43,    48,     4,    44,    18,    43,    43,    43,    22,    41,
      41,     7,    10,    11,    12,    13,    14,    31,    32,    10,
      11,    12,    13,    14,    38,    16,    17,    25,    26,    27,
      28,    29,    30,    41,    25,    26,    27,    28,    29,    30,
      10,    11,    12,    13,    14,    48,    16,    17,    15,     4,
      41,     4,     3,     7,    44,    25,    26,    27,    28,    29,
      30,     4,    41,    41,    23,     8,     9,    19,    41,    12,
      41,    41,    41,    10,    37,    18,     4,    20,    21,    22,
       8,     9,    15,    60,    12,    67,    52,    63,    31,    32,
      18,    38,    -1,     4,    22,    82,    24,     8,     9,    -1,
      -1,    12,    -1,    31,    32,    -1,    -1,    18,     4,    -1,
      21,    22,     8,     9,    -1,    -1,    12,    -1,    -1,    -1,
      31,    32,    18,    -1,    -1,    -1,    22,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    33,    35,    36,    51,    52,    56,    64,     4,    34,
      53,    54,    56,     0,    56,    60,    61,    64,    37,     4,
      55,    34,    54,     4,    12,    58,    59,     4,    61,    64,
      43,    41,    42,    43,    45,     4,    41,    42,    43,    44,
       4,    35,    36,    57,    62,    63,     3,    59,    62,    47,
       4,    12,    42,    44,    46,    44,    33,    65,     4,    63,
      47,    34,    57,    66,    67,     6,    69,    65,     4,    68,
      34,    67,     4,     8,     9,    12,    18,    22,    31,    32,
      38,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    82,    83,    48,    69,    41,    42,    43,    45,    49,
      43,    43,     4,    43,    43,    41,    41,     3,     5,    11,
      39,    43,    81,    82,    83,     7,    70,    72,    41,    15,
      48,     4,    80,    81,    81,     4,     4,    83,    81,    81,
      81,     3,    83,    81,    10,    11,    12,    13,    14,    16,
      17,    25,    26,    27,    28,    29,    30,    41,     7,    81,
      42,    44,    46,    44,    44,    44,    44,    44,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    41,    81,    41,    41,    19,    23,    71,    71,    20,
      21,    24,    71,    41,    41,    21,    41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    51,    51,    52,    52,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    59,    59,    60,    60,    61,    62,    62,    62,    63,
      63,    64,    65,    65,    65,    66,    66,    67,    68,    68,
      69,    69,    70,    71,    71,    72,    72,    72,    72,    72,
      72,    72,    72,    73,    73,    74,    75,    76,    77,    78,
      79,    80,    80,    80,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    82,    83,    83,    83,    83
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       3,     3,     1,     1,     1,     1,     1,     3,     1,     4,
       1,     4,     2,     2,     1,     9,     3,     1,     0,     2,
       3,     8,     3,     2,     0,     2,     1,     3,     3,     1,
       4,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     2,    10,     8,     8,     2,     2,     5,     5,
       4,     3,     1,     0,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     2,
       1,     1,     1,     2,     4,     1,     4,     2,     3
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
#line 54 "ex2.y"
                                        {}
#line 1452 "y.tab.c"
    break;

  case 3: /* program: GDeclBlock MainBlock  */
#line 55 "ex2.y"
                                        {}
#line 1458 "y.tab.c"
    break;

  case 4: /* program: MainBlock  */
#line 56 "ex2.y"
                                        {}
#line 1464 "y.tab.c"
    break;

  case 5: /* GDeclBlock: DECL GDeclList ENDDECL  */
#line 59 "ex2.y"
                                        { printGSymbolTable() ;print_header();}
#line 1470 "y.tab.c"
    break;

  case 6: /* GDeclBlock: DECL ENDDECL  */
#line 60 "ex2.y"
                                        { printGSymbolTable() ;print_header();}
#line 1476 "y.tab.c"
    break;

  case 10: /* GDecl: ID TD ';'  */
#line 84 "ex2.y"
                            {
                                struct Gsymbol* temp=GLookup((yyvsp[-2].nptr)->name);
                                if(temp==NULL)
                                {
                                    printf("Tuple %s not defined\n", (yyvsp[-2].nptr)->name);
                                    exit(1);
                                }
                                size=temp->size;
                                struct Paramstruct* t=(yyvsp[-1].pptr);
                                struct Paramstruct* tempParamList = (struct Paramstruct*)malloc(sizeof(struct Paramstruct));
                                tempParamList = GLookup((yyvsp[-2].nptr)->name)->paramlist;
                                while(t)
                                {
                                    struct Gsymbol* temp2=GLookup(t->name);
                                    if(temp2!=NULL)
                                    {
                                        printf("Tuple element %s already defined\n", t->name);
                                        exit(1);
                                    }
                                    
                                    GInstall(t->name, TYPE_TUPLE_VAR, size, tempParamList);
                                    t = t->next;
                                }

                            }
#line 1506 "y.tab.c"
    break;

  case 11: /* TD: TD ',' ID  */
#line 111 "ex2.y"
                    {

                                struct Gsymbol* temp=GLookup((yyvsp[0].nptr)->name);
                                if(temp!=NULL)
                                {
                                    printf("Tuple element %s already defined\n", (yyvsp[0].nptr)->name);
                                    exit(1);
                                }
                                
                                struct Paramstruct* tempParamList = (struct Paramstruct*)malloc(sizeof(struct Paramstruct));
                                tempParamList->name = (yyvsp[0].nptr)->name;
                                tempParamList->type = TYPE_TUPLE_VAR;
                                tempParamList->next = NULL;
                                struct Paramstruct* temp2 = (yyvsp[-2].pptr);
                                while(temp2->next != NULL)
                                {
                                    temp2 = temp2->next;
                                }
                                temp2->next = tempParamList;
                                (yyval.pptr) = (yyvsp[-2].pptr);
                            }
#line 1532 "y.tab.c"
    break;

  case 12: /* TD: ID  */
#line 132 "ex2.y"
                             {
                                struct Gsymbol* temp=GLookup((yyvsp[0].nptr)->name);
                                if(temp!=NULL)
                                {
                                    printf("Tuple element %s already defined\n", (yyvsp[0].nptr)->name);
                                    exit(1);
                                }
                                
                                struct Paramstruct* tempParamList = (struct Paramstruct*)malloc(sizeof(struct Paramstruct));
                                tempParamList->name = (yyvsp[0].nptr)->name;
                                tempParamList->type = TYPE_TUPLE_VAR;
                                tempParamList->next = NULL;
                                (yyval.pptr) = tempParamList;
                            }
#line 1551 "y.tab.c"
    break;

  case 13: /* Type: INT  */
#line 147 "ex2.y"
            {declarationType = TYPE_INT;}
#line 1557 "y.tab.c"
    break;

  case 14: /* Type: STR  */
#line 148 "ex2.y"
            {declarationType = TYPE_STR;}
#line 1563 "y.tab.c"
    break;

  case 15: /* FType: INT  */
#line 151 "ex2.y"
             {FDeclarationType = TYPE_INT;}
#line 1569 "y.tab.c"
    break;

  case 16: /* FType: STR  */
#line 152 "ex2.y"
             {FDeclarationType = TYPE_STR;}
#line 1575 "y.tab.c"
    break;

  case 19: /* GId: ID '(' ParamList ')'  */
#line 161 "ex2.y"
                            {
                                declCount++;
                                checkAvailability((yyvsp[-3].nptr)->name, 1);
                                GInstall((yyvsp[-3].nptr)->name, declarationType, -1, Phead);
                                Phead = NULL;
                                Ptail = NULL;
                            }
#line 1587 "y.tab.c"
    break;

  case 20: /* GId: ID  */
#line 168 "ex2.y"
                            {
                                checkAvailability((yyvsp[0].nptr)->name, 1);
                                GInstall((yyvsp[0].nptr)->name, declarationType, 1, NULL);
                            }
#line 1596 "y.tab.c"
    break;

  case 21: /* GId: ID '[' NUM ']'  */
#line 172 "ex2.y"
                            {
                                checkAvailability((yyvsp[-3].nptr)->name, 1);
                                if((yyvsp[-1].nptr)->value.intval < 1) 
                                {
                                    yyerror_impl("Invalid array size for", (yyvsp[-3].nptr)->name);
                                    exit(1);
                                }
                                GInstall((yyvsp[-3].nptr)->name, declarationType, (yyvsp[-1].nptr)->value.intval, NULL);
                            }
#line 1610 "y.tab.c"
    break;

  case 22: /* GId: MUL ID  */
#line 181 "ex2.y"
                            {
                                checkAvailability((yyvsp[0].nptr)->name, 1);
                                GInstall((yyvsp[0].nptr)->name, TYPE_INT_PTR, 1, NULL); 
                            }
#line 1619 "y.tab.c"
    break;

  case 25: /* FDef: Type ID '(' ParamList ')' '{' LDeclBlock Body '}'  */
#line 217 "ex2.y"
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
                                                            

                                                            Phead = NULL;
                                                            Ptail = NULL;
                                                            Lhead = NULL;
                                                            Ltail = NULL;
                                                        }
#line 1688 "y.tab.c"
    break;

  case 28: /* ParamList: %empty  */
#line 285 "ex2.y"
                            {(yyval.nptr) = NULL;}
#line 1694 "y.tab.c"
    break;

  case 29: /* Param: FType ID  */
#line 289 "ex2.y"
                {
                    checkAvailability((yyvsp[0].nptr)->name, 0);
                    PInstall((yyvsp[0].nptr)->name, FDeclarationType);
                }
#line 1703 "y.tab.c"
    break;

  case 30: /* Param: FType MUL ID  */
#line 294 "ex2.y"
                {
                    checkAvailability((yyvsp[0].nptr)->name, 0);
                    PInstall((yyvsp[0].nptr)->name, TYPE_INT_PTR);
                }
#line 1712 "y.tab.c"
    break;

  case 31: /* MainBlock: Type MAIN '(' ')' '{' LDeclBlock Body '}'  */
#line 300 "ex2.y"
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
                                                            

                                                            Lhead = NULL;
                                                            Ltail = NULL;
                                                        }
#line 1754 "y.tab.c"
    break;

  case 32: /* LDeclBlock: DECL LDecList ENDDECL  */
#line 339 "ex2.y"
                                    {InstallParamsInLocal();}
#line 1760 "y.tab.c"
    break;

  case 33: /* LDeclBlock: DECL ENDDECL  */
#line 340 "ex2.y"
                                    {InstallParamsInLocal();}
#line 1766 "y.tab.c"
    break;

  case 34: /* LDeclBlock: %empty  */
#line 341 "ex2.y"
                                    {InstallParamsInLocal();}
#line 1772 "y.tab.c"
    break;

  case 38: /* IdList: IdList ',' ID  */
#line 351 "ex2.y"
                        {
                            checkAvailability((yyvsp[0].nptr)->name, 0);
                            LInstall((yyvsp[0].nptr)->name, FDeclarationType);
                        }
#line 1781 "y.tab.c"
    break;

  case 39: /* IdList: ID  */
#line 355 "ex2.y"
                        {
                            checkAvailability((yyvsp[0].nptr)->name, 0);
                            LInstall((yyvsp[0].nptr)->name, FDeclarationType);
                        }
#line 1790 "y.tab.c"
    break;

  case 40: /* Body: START Slist RetStmt END  */
#line 361 "ex2.y"
                                {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_CONNECTOR, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[-1].nptr), NULL);}
#line 1796 "y.tab.c"
    break;

  case 41: /* Body: START RetStmt END  */
#line 362 "ex2.y"
                                {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 1802 "y.tab.c"
    break;

  case 42: /* RetStmt: RETURN expr ';'  */
#line 365 "ex2.y"
                            {
                                if(declarationType == (yyvsp[-1].nptr)->type) 
                                {
                                    (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_RET, NULL, NULL, NULL, (yyvsp[-1].nptr), NULL, NULL);
                                
                                } 
                                else 
                                {
                                    yyerror_impl("Return type mismatch", NULL);
                                    exit(1);
                                }
                            }
#line 1819 "y.tab.c"
    break;

  case 43: /* Slist: Slist Stmt  */
#line 379 "ex2.y"
                        {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_CONNECTOR, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);}
#line 1825 "y.tab.c"
    break;

  case 44: /* Slist: Stmt  */
#line 380 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1831 "y.tab.c"
    break;

  case 45: /* Stmt: InputStmt  */
#line 383 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1837 "y.tab.c"
    break;

  case 46: /* Stmt: OutputStmt  */
#line 384 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1843 "y.tab.c"
    break;

  case 47: /* Stmt: AsgStmt  */
#line 385 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1849 "y.tab.c"
    break;

  case 48: /* Stmt: IfStmt  */
#line 386 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1855 "y.tab.c"
    break;

  case 49: /* Stmt: WhileStmt  */
#line 387 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1861 "y.tab.c"
    break;

  case 50: /* Stmt: BrkStmt  */
#line 388 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1867 "y.tab.c"
    break;

  case 51: /* Stmt: ContStmt  */
#line 389 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1873 "y.tab.c"
    break;

  case 52: /* Stmt: func ';'  */
#line 390 "ex2.y"
                        {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 1879 "y.tab.c"
    break;

  case 53: /* IfStmt: IF '(' expr ')' THEN Slist ELSE Slist ENDIF ';'  */
#line 393 "ex2.y"
                                                            {
                                                                typecheck((yyvsp[-7].nptr)->type, TYPE_BOOL, 'e');
                                                                (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_IF_ELSE, NULL, NULL, NULL, (yyvsp[-7].nptr), (yyvsp[-2].nptr), (yyvsp[-4].nptr));
                                                            }
#line 1888 "y.tab.c"
    break;

  case 54: /* IfStmt: IF '(' expr ')' THEN Slist ENDIF ';'  */
#line 397 "ex2.y"
                                                            {
                                                                typecheck((yyvsp[-5].nptr)->type, TYPE_BOOL, 'i');
                                                                (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_IF, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-2].nptr), NULL);
                                                            }
#line 1897 "y.tab.c"
    break;

  case 55: /* WhileStmt: WHILE '(' expr ')' DO Slist ENDWHILE ';'  */
#line 403 "ex2.y"
                                                            {
                                                                typecheck((yyvsp[-5].nptr)->type, TYPE_BOOL, 'w');
                                                                (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_WHILE, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-2].nptr), NULL);
                                                            }
#line 1906 "y.tab.c"
    break;

  case 56: /* BrkStmt: BREAK ';'  */
#line 408 "ex2.y"
                                    {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_BREAK, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1912 "y.tab.c"
    break;

  case 57: /* ContStmt: CONT ';'  */
#line 411 "ex2.y"
                                    {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_CONT, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1918 "y.tab.c"
    break;

  case 58: /* InputStmt: READ '(' id ')' ';'  */
#line 414 "ex2.y"
                                    {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_READ, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);}
#line 1924 "y.tab.c"
    break;

  case 59: /* OutputStmt: WRITE '(' expr ')' ';'  */
#line 417 "ex2.y"
                                    {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_WRITE, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);}
#line 1930 "y.tab.c"
    break;

  case 60: /* AsgStmt: id ASSGN expr ';'  */
#line 420 "ex2.y"
                                    {
                                        typecheck((yyvsp[-3].nptr)->type, (yyvsp[-1].nptr)->type, '=');
                                        (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                                    }
#line 1939 "y.tab.c"
    break;

  case 61: /* ExprList: ExprList ',' expr  */
#line 426 "ex2.y"
                            {
                                (yyvsp[0].nptr)->arglist = (yyvsp[-2].nptr);
                                (yyval.nptr) = (yyvsp[0].nptr);
                            }
#line 1948 "y.tab.c"
    break;

  case 62: /* ExprList: expr  */
#line 430 "ex2.y"
                            {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1954 "y.tab.c"
    break;

  case 63: /* ExprList: %empty  */
#line 431 "ex2.y"
                            {(yyval.nptr) = NULL;}
#line 1960 "y.tab.c"
    break;

  case 64: /* expr: expr PLUS expr  */
#line 434 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TYPE_INT, NODE_PLUS, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1969 "y.tab.c"
    break;

  case 65: /* expr: expr MINUS expr  */
#line 438 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TYPE_INT, NODE_MINUS, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1978 "y.tab.c"
    break;

  case 66: /* expr: expr MUL expr  */
#line 442 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TYPE_INT, NODE_MUL, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1987 "y.tab.c"
    break;

  case 67: /* expr: expr DIV expr  */
#line 446 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TYPE_INT, NODE_DIV, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1996 "y.tab.c"
    break;

  case 68: /* expr: expr MOD expr  */
#line 450 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TYPE_INT, NODE_MOD, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2005 "y.tab.c"
    break;

  case 69: /* expr: expr LT expr  */
#line 454 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_LT, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2014 "y.tab.c"
    break;

  case 70: /* expr: expr GT expr  */
#line 458 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_GT, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2023 "y.tab.c"
    break;

  case 71: /* expr: expr LE expr  */
#line 462 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_LE, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2032 "y.tab.c"
    break;

  case 72: /* expr: expr GE expr  */
#line 466 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_GE, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2041 "y.tab.c"
    break;

  case 73: /* expr: expr NEQ expr  */
#line 470 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_NEQ, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2050 "y.tab.c"
    break;

  case 74: /* expr: expr EQ expr  */
#line 474 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_EQ, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2059 "y.tab.c"
    break;

  case 75: /* expr: expr AND expr  */
#line 478 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'l');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_AND, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2068 "y.tab.c"
    break;

  case 76: /* expr: expr OR expr  */
#line 482 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'l');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_OR, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2077 "y.tab.c"
    break;

  case 77: /* expr: '(' expr ')'  */
#line 486 "ex2.y"
                        {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 2083 "y.tab.c"
    break;

  case 78: /* expr: NUM  */
#line 487 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2089 "y.tab.c"
    break;

  case 79: /* expr: MINUS NUM  */
#line 488 "ex2.y"
                        {
                            (yyvsp[0].nptr)->value.intval = -1*((yyvsp[0].nptr)->value.intval);
                            (yyval.nptr) = (yyvsp[0].nptr);
                        }
#line 2098 "y.tab.c"
    break;

  case 80: /* expr: STRVAL  */
#line 492 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2104 "y.tab.c"
    break;

  case 81: /* expr: id  */
#line 493 "ex2.y"
                                {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2110 "y.tab.c"
    break;

  case 82: /* expr: func  */
#line 494 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2116 "y.tab.c"
    break;

  case 83: /* expr: ADDR id  */
#line 495 "ex2.y"
                       {
                            if((yyvsp[0].nptr)->type == TYPE_INT_PTR) 
                            {
                                yyerror_impl("Cannot take address of pointer variable", (yyvsp[0].nptr)->name);
                                exit(1);
                            }
                            (yyval.nptr) = TreeCreate(TYPE_INT_PTR, NODE_ADDR, NULL, NULL, NULL, (yyvsp[0].nptr), NULL, NULL);
                        }
#line 2129 "y.tab.c"
    break;

  case 84: /* func: ID '(' ExprList ')'  */
#line 506 "ex2.y"
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
#line 2183 "y.tab.c"
    break;

  case 85: /* id: ID  */
#line 556 "ex2.y"
                        {
                            assignType((yyvsp[0].nptr), 0);
                            (yyval.nptr) = (yyvsp[0].nptr);
                        }
#line 2192 "y.tab.c"
    break;

  case 86: /* id: ID '[' expr ']'  */
#line 560 "ex2.y"
                        {
                            assignType((yyvsp[-3].nptr), 2);
                            (yyval.nptr) = TreeCreate((yyvsp[-3].nptr)->type, NODE_ARRAY, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                            (yyval.nptr)->Gentry = (yyvsp[-3].nptr)->Gentry;
                            (yyval.nptr)->Lentry = (yyvsp[-3].nptr)->Lentry;
                        }
#line 2203 "y.tab.c"
    break;

  case 87: /* id: MUL ID  */
#line 566 "ex2.y"
                        {
                            assignType((yyvsp[0].nptr), 0);
                            (yyval.nptr) = TreeCreate((yyvsp[0].nptr)->type, NODE_INT_PTR, (yyvsp[0].nptr)->name, NULL, NULL, NULL, NULL, NULL);
                            (yyval.nptr)->Gentry = (yyvsp[0].nptr)->Gentry;
                            (yyval.nptr)->Lentry = (yyvsp[0].nptr)->Lentry;
                        }
#line 2214 "y.tab.c"
    break;

  case 88: /* id: ID '.' ID  */
#line 572 "ex2.y"
                        {
                            struct Gsymbol * temp=GLookup((yyvsp[-2].nptr)->name);
                            if(temp->type!=TYPE_TUPLE_VAR)
                            {
                                printf("Variable %s is not of tuple type\n", (yyvsp[-2].nptr)->name);
                                exit(1);
                            }
                            struct Paramstruct* tempParam=temp->paramlist;
                            int found=0;
                            while(tempParam!=NULL)
                            {
                                if(strcmp(tempParam->name,(yyvsp[0].nptr)->name)==0)
                                {
                                    found=1;
                                    break;

                                }
                                tempParam=tempParam->next;
                            }
                            if(found==0)
                            {
                                printf("Tuple %s does not have element %s\n", (yyvsp[-2].nptr)->name, (yyvsp[0].nptr)->name);
                                exit(1);
                            }
                            (yyval.nptr) = TreeCreate(tempParam->type, NODE_TUPLE, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                            (yyval.nptr)->Gentry=temp;

                        }
#line 2247 "y.tab.c"
    break;


#line 2251 "y.tab.c"

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

#line 604 "ex2.y"


int yyerror_impl(char const *s, const char *var) 
{
    printf("Error : %s",s);
    if(var != NULL) 
    {
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
