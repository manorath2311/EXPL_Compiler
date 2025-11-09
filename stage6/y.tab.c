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
        int tbv=0;
        char nameType[20];
        char declaredType[20];
       

#line 100 "y.tab.c"

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
    TYPE = 295,                    /* TYPE  */
    ENDTYPE = 296                  /* ENDTYPE  */
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
#define TYPE 295
#define ENDTYPE 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 30 "ex2.y"

    struct ASTNode *nptr;
    struct Paramstruct *pptr;
    struct Fieldstruct *fptr;
    struct TypeDef *tptr;

#line 242 "y.tab.c"

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
  YYSYMBOL_TYPE = 40,                      /* TYPE  */
  YYSYMBOL_ENDTYPE = 41,                   /* ENDTYPE  */
  YYSYMBOL_42_ = 42,                       /* '{'  */
  YYSYMBOL_43_ = 43,                       /* '}'  */
  YYSYMBOL_44_ = 44,                       /* ';'  */
  YYSYMBOL_45_ = 45,                       /* '.'  */
  YYSYMBOL_46_ = 46,                       /* ','  */
  YYSYMBOL_47_ = 47,                       /* '('  */
  YYSYMBOL_48_ = 48,                       /* ')'  */
  YYSYMBOL_49_ = 49,                       /* '['  */
  YYSYMBOL_50_ = 50,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_program = 52,                   /* program  */
  YYSYMBOL_TDeclBlock = 53,                /* TDeclBlock  */
  YYSYMBOL_TypeList = 54,                  /* TypeList  */
  YYSYMBOL_TypeDef = 55,                   /* TypeDef  */
  YYSYMBOL_TypeFieldList = 56,             /* TypeFieldList  */
  YYSYMBOL_TypeField = 57,                 /* TypeField  */
  YYSYMBOL_FIType = 58,                    /* FIType  */
  YYSYMBOL_Field = 59,                     /* Field  */
  YYSYMBOL_GDeclBlock = 60,                /* GDeclBlock  */
  YYSYMBOL_GDeclList = 61,                 /* GDeclList  */
  YYSYMBOL_GDecl = 62,                     /* GDecl  */
  YYSYMBOL_Type = 63,                      /* Type  */
  YYSYMBOL_FType = 64,                     /* FType  */
  YYSYMBOL_GIdList = 65,                   /* GIdList  */
  YYSYMBOL_GId = 66,                       /* GId  */
  YYSYMBOL_FDefBlock = 67,                 /* FDefBlock  */
  YYSYMBOL_FDef = 68,                      /* FDef  */
  YYSYMBOL_ParamList = 69,                 /* ParamList  */
  YYSYMBOL_Param = 70,                     /* Param  */
  YYSYMBOL_MainBlock = 71,                 /* MainBlock  */
  YYSYMBOL_LDeclBlock = 72,                /* LDeclBlock  */
  YYSYMBOL_LDecList = 73,                  /* LDecList  */
  YYSYMBOL_LDecl = 74,                     /* LDecl  */
  YYSYMBOL_IdList = 75,                    /* IdList  */
  YYSYMBOL_Body = 76,                      /* Body  */
  YYSYMBOL_RetStmt = 77,                   /* RetStmt  */
  YYSYMBOL_Slist = 78,                     /* Slist  */
  YYSYMBOL_Stmt = 79,                      /* Stmt  */
  YYSYMBOL_IfStmt = 80,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 81,                 /* WhileStmt  */
  YYSYMBOL_BrkStmt = 82,                   /* BrkStmt  */
  YYSYMBOL_ContStmt = 83,                  /* ContStmt  */
  YYSYMBOL_InputStmt = 84,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 85,                /* OutputStmt  */
  YYSYMBOL_AsgStmt = 86,                   /* AsgStmt  */
  YYSYMBOL_ExprList = 87,                  /* ExprList  */
  YYSYMBOL_expr = 88,                      /* expr  */
  YYSYMBOL_func = 89,                      /* func  */
  YYSYMBOL_id = 90                         /* id  */
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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   407

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  206

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
      47,    48,     2,     2,    46,     2,    45,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    64,    64,    65,    66,    69,    73,    75,    76,    78,
     128,   164,   176,   188,   189,   190,   214,   253,   309,   310,
     313,   314,   317,   378,   379,   380,   394,   395,   399,   400,
     404,   426,   438,   479,   480,   483,   550,   551,   552,   556,
     560,   567,   606,   607,   608,   611,   612,   615,   618,   622,
     628,   629,   632,   646,   647,   650,   651,   652,   653,   654,
     655,   656,   657,   660,   664,   670,   675,   678,   681,   684,
     687,   693,   697,   698,   701,   705,   709,   713,   717,   721,
     725,   729,   733,   737,   741,   745,   749,   753,   754,   755,
     759,   760,   761,   762,   770,   774,   824,   828,   834
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
  "ENDDECL", "INT", "STR", "MAIN", "RETURN", "ADDR", "TYPE", "ENDTYPE",
  "'{'", "'}'", "';'", "'.'", "','", "'('", "')'", "'['", "']'", "$accept",
  "program", "TDeclBlock", "TypeList", "TypeDef", "TypeFieldList",
  "TypeField", "FIType", "Field", "GDeclBlock", "GDeclList", "GDecl",
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

#define YYPACT_NINF (-115)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      60,  -115,     7,  -115,  -115,    -1,     6,    11,    26,    10,
    -115,  -115,    63,  -115,    82,    40,  -115,    25,    90,  -115,
      26,  -115,    74,  -115,  -115,   -28,   -13,  -115,    73,  -115,
    -115,   103,    26,  -115,    81,    78,   133,  -115,    82,  -115,
    -115,  -115,     3,  -115,   135,    97,     0,  -115,  -115,   125,
    -115,  -115,     1,    37,  -115,    95,  -115,   116,  -115,   124,
      78,   144,  -115,   180,    78,  -115,  -115,  -115,  -115,    57,
     107,   181,  -115,  -115,   146,  -115,   185,   118,  -115,   265,
     147,   144,  -115,   119,  -115,  -115,   117,   153,   154,   187,
     155,   161,   148,   167,    24,   205,   265,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,   170,   198,  -115,   181,  -115,
     211,    24,    24,    12,    24,  -115,    24,    24,  -115,  -115,
    -115,   -27,  -115,   213,    12,    24,   179,   217,  -115,  -115,
    -115,   218,  -115,  -115,    24,   183,  -115,   130,   346,    62,
     186,   184,   121,   145,   169,   232,  -115,  -115,   193,   233,
      24,    24,    24,    24,    24,    24,    24,    24,    24,    24,
      24,    24,    24,  -115,  -115,   238,  -115,    24,  -115,  -115,
     194,   195,   221,   230,  -115,  -115,  -115,    56,    56,  -115,
    -115,  -115,   356,   356,   246,   246,   377,   377,   377,   377,
    -115,   346,  -115,  -115,   333,   333,   280,   301,   333,   226,
     231,   318,  -115,  -115,   234,  -115
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    25,     0,    23,    24,     0,     0,     0,     0,     0,
       4,    19,     0,    21,     0,     0,     6,     0,     8,     1,
       0,     3,     0,    18,    20,    31,     0,    29,     0,     5,
       7,     0,     0,    34,     0,    38,     0,    22,     0,    15,
      13,    14,     0,    11,     0,     0,     0,    33,     2,     0,
      26,    27,     0,     0,    37,     0,    28,     0,    10,     0,
      38,    44,    39,     0,     0,    30,    32,     9,    12,     0,
       0,     0,    40,    36,     0,    43,     0,     0,    46,     0,
       0,    44,    49,     0,    42,    45,    96,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,    58,    59,
      60,    61,    55,    56,    57,     0,     0,    41,     0,    47,
       0,    73,     0,     0,     0,    98,     0,     0,    66,    67,
      88,    96,    90,     0,     0,     0,    94,     0,    92,    91,
      51,     0,    53,    62,     0,     0,    48,     0,    72,     0,
      96,     0,     0,     0,     0,     0,    89,    93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,    50,     0,    35,     0,    95,    97,
       0,     0,     0,     0,    17,    87,    16,    74,    75,    76,
      77,    78,    85,    86,    84,    83,    81,    82,    79,    80,
      70,    71,    68,    69,     0,     0,     0,     0,     0,     0,
       0,     0,    64,    65,     0,    63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -115,  -115,  -115,   244,  -115,  -115,   237,  -115,  -115,   269,
    -115,   268,   108,    34,  -115,   243,  -115,   253,   235,   222,
      -6,   209,  -115,   214,  -115,   191,   197,  -114,   -95,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -102,   -71,   -79
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,    17,    18,    42,    43,    44,   126,     8,
      12,    13,     9,    52,    26,    27,    32,    33,    53,    54,
      10,    71,    77,    78,    83,    80,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   137,   127,   128,   129
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     106,   132,    21,    15,    45,    62,    19,    39,   105,   138,
     139,     1,   142,    63,   143,   144,   140,   106,   145,    35,
     111,    36,   112,   148,    89,   105,    48,   120,   121,   122,
       1,    37,   165,    38,   141,   123,    89,    22,    40,    41,
      16,    11,     3,     4,     2,   147,    57,    22,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     3,     4,   124,     1,   191,    29,     1,   152,   153,
     154,   125,   150,   151,   152,   153,   154,    39,   155,   156,
     196,   197,    28,    64,   201,    65,    25,   157,   158,   159,
     160,   161,   162,     2,    15,     3,     4,    23,     3,     4,
       5,   132,   132,    64,    76,    74,   132,    45,    40,    41,
      14,    76,   169,    50,    51,   106,   106,   106,   106,   106,
      14,    34,   106,   105,   105,   105,   105,   105,    31,    49,
     105,   150,   151,   152,   153,   154,    55,   155,   156,    59,
      46,    75,    50,    51,    60,    66,   157,   158,   159,   160,
     161,   162,    84,    50,    51,   150,   151,   152,   153,   154,
      67,   155,   156,   109,   111,   110,   112,    61,    68,   171,
     157,   158,   159,   160,   161,   162,   167,    70,   168,   150,
     151,   152,   153,   154,    72,   155,   156,    79,    81,    82,
     107,   115,   118,   172,   157,   158,   159,   160,   161,   162,
     113,   114,   116,   150,   151,   152,   153,   154,   117,   155,
     156,   119,   130,   134,   133,   136,   146,   173,   157,   158,
     159,   160,   161,   162,   149,   164,   166,   150,   151,   152,
     153,   154,   170,   155,   156,   112,   174,   176,   192,   193,
     194,   175,   157,   158,   159,   160,   161,   162,   150,   151,
     152,   153,   154,   195,   155,   156,   150,   151,   152,   153,
     154,   163,    30,   157,   158,   159,   160,   161,   162,    86,
     202,   157,   158,    87,    88,   203,    20,    89,   205,    58,
      24,    56,   190,    90,    86,    47,    73,    91,    87,    88,
     108,    85,    89,   131,     0,    69,    92,    93,    90,   135,
     198,   199,    91,    94,     0,    86,     0,     0,     0,    87,
      88,    92,    93,    89,     0,     0,     0,     0,     0,    90,
       0,     0,    86,    91,     0,   200,    87,    88,     0,     0,
      89,     0,    92,    93,     0,     0,    90,    86,     0,   204,
      91,    87,    88,     0,     0,    89,     0,     0,     0,    92,
      93,    90,     0,     0,     0,    91,   150,   151,   152,   153,
     154,     0,   155,   156,    92,    93,   150,   151,   152,   153,
     154,   157,   158,   159,   160,   161,   162,     0,     0,     0,
       0,   157,   158,   159,   160,   161,   162,   150,   151,   152,
     153,   154,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   157,   158,    -1,    -1,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
      79,    96,     8,     4,     4,     4,     0,     4,    79,   111,
     112,     4,   114,    12,   116,   117,     4,    96,    45,    47,
      47,    49,    49,   125,    12,    96,    32,     3,     4,     5,
       4,    44,   134,    46,   113,    11,    12,    37,    35,    36,
      41,    34,    35,    36,    33,   124,    43,    37,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,    35,    36,    39,     4,   167,    41,     4,    12,    13,
      14,    47,    10,    11,    12,    13,    14,     4,    16,    17,
     194,   195,    42,    46,   198,    48,     4,    25,    26,    27,
      28,    29,    30,    33,     4,    35,    36,    34,    35,    36,
      40,   196,   197,    46,    70,    48,   201,     4,    35,    36,
       2,    77,    50,    35,    36,   194,   195,   196,   197,   198,
      12,    47,   201,   194,   195,   196,   197,   198,    20,    48,
     201,    10,    11,    12,    13,    14,     3,    16,    17,     4,
      32,    34,    35,    36,    47,    50,    25,    26,    27,    28,
      29,    30,    34,    35,    36,    10,    11,    12,    13,    14,
      44,    16,    17,    44,    47,    46,    49,    42,    44,    48,
      25,    26,    27,    28,    29,    30,    46,    33,    48,    10,
      11,    12,    13,    14,     4,    16,    17,     6,    42,     4,
      43,     4,    44,    48,    25,    26,    27,    28,    29,    30,
      47,    47,    47,    10,    11,    12,    13,    14,    47,    16,
      17,    44,     7,    15,    44,     4,     3,    48,    25,    26,
      27,    28,    29,    30,    45,     7,    43,    10,    11,    12,
      13,    14,    48,    16,    17,    49,     4,     4,    44,    44,
      19,    48,    25,    26,    27,    28,    29,    30,    10,    11,
      12,    13,    14,    23,    16,    17,    10,    11,    12,    13,
      14,    44,    18,    25,    26,    27,    28,    29,    30,     4,
      44,    25,    26,     8,     9,    44,     7,    12,    44,    42,
      12,    38,    44,    18,     4,    32,    64,    22,     8,     9,
      81,    77,    12,    96,    -1,    60,    31,    32,    18,   108,
      20,    21,    22,    38,    -1,     4,    -1,    -1,    -1,     8,
       9,    31,    32,    12,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    -1,     4,    22,    -1,    24,     8,     9,    -1,    -1,
      12,    -1,    31,    32,    -1,    -1,    18,     4,    -1,    21,
      22,     8,     9,    -1,    -1,    12,    -1,    -1,    -1,    31,
      32,    18,    -1,    -1,    -1,    22,    10,    11,    12,    13,
      14,    -1,    16,    17,    31,    32,    10,    11,    12,    13,
      14,    25,    26,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    29,    30,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    33,    35,    36,    40,    52,    53,    60,    63,
      71,    34,    61,    62,    63,     4,    41,    54,    55,     0,
      60,    71,    37,    34,    62,     4,    65,    66,    42,    41,
      54,    63,    67,    68,    47,    47,    49,    44,    46,     4,
      35,    36,    56,    57,    58,     4,    63,    68,    71,    48,
      35,    36,    64,    69,    70,     3,    66,    43,    57,     4,
      47,    42,     4,    12,    46,    48,    50,    44,    44,    69,
      33,    72,     4,    70,    48,    34,    64,    73,    74,     6,
      76,    42,     4,    75,    34,    74,     4,     8,     9,    12,
      18,    22,    31,    32,    38,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    89,    90,    43,    72,    44,
      46,    47,    49,    47,    47,     4,    47,    47,    44,    44,
       3,     4,     5,    11,    39,    47,    59,    88,    89,    90,
       7,    77,    79,    44,    15,    76,     4,    87,    88,    88,
       4,    90,    88,    88,    88,    45,     3,    90,    88,    45,
      10,    11,    12,    13,    14,    16,    17,    25,    26,    27,
      28,    29,    30,    44,     7,    88,    43,    46,    48,    50,
      48,    48,    48,    48,     4,    48,     4,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      44,    88,    44,    44,    19,    23,    78,    78,    20,    21,
      24,    78,    44,    44,    21,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    52,    52,    53,    53,    54,    54,    55,
      56,    56,    57,    58,    58,    58,    59,    59,    60,    60,
      61,    61,    62,    63,    63,    63,    64,    64,    65,    65,
      66,    66,    66,    67,    67,    68,    69,    69,    69,    70,
      70,    71,    72,    72,    72,    73,    73,    74,    75,    75,
      76,    76,    77,    78,    78,    79,    79,    79,    79,    79,
      79,    79,    79,    80,    80,    81,    82,    83,    84,    85,
      86,    87,    87,    87,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    89,    90,    90,    90
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     2,     1,     3,     2,     2,     1,     5,
       2,     1,     3,     1,     1,     1,     3,     3,     3,     2,
       2,     1,     3,     1,     1,     1,     1,     1,     3,     1,
       4,     1,     4,     2,     1,     9,     3,     1,     0,     2,
       3,     8,     3,     2,     0,     2,     1,     3,     3,     1,
       4,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     2,    10,     8,     8,     2,     2,     5,     5,
       4,     3,     1,     0,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     2,
       1,     1,     1,     2,     1,     4,     1,     4,     2
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
  case 2: /* program: TDeclBlock GDeclBlock FDefBlock MainBlock  */
#line 64 "ex2.y"
                                                   {}
#line 1485 "y.tab.c"
    break;

  case 3: /* program: GDeclBlock MainBlock  */
#line 65 "ex2.y"
                                        {}
#line 1491 "y.tab.c"
    break;

  case 4: /* program: MainBlock  */
#line 66 "ex2.y"
                                        {}
#line 1497 "y.tab.c"
    break;

  case 5: /* TDeclBlock: TYPE TypeList ENDTYPE  */
#line 69 "ex2.y"
                                        {
                                            
                                            printTypeTable();
                                        }
#line 1506 "y.tab.c"
    break;

  case 6: /* TDeclBlock: TYPE ENDTYPE  */
#line 73 "ex2.y"
                                       {}
#line 1512 "y.tab.c"
    break;

  case 9: /* TypeDef: ID '{' TypeFieldList '}' ';'  */
#line 78 "ex2.y"
                                         {
                                            checkAvailability((yyvsp[-4].nptr)->name, 2);
                                            int count=0;
                                            struct Fieldstruct* temp=(yyvsp[-2].fptr);
                                            while(temp!=NULL)
                                            {
                                                count++;
                                                temp = temp->next;
                                            }
                                            printf("Type %s with %d fields\n", (yyvsp[-4].nptr)->name, count);
                                            //TInstall($1->name,$3, count);
                                            
                                            struct TypeDef* tempTypeDef = (struct TypeDef*)malloc(sizeof(struct TypeDef));
                                            tempTypeDef->name = (yyvsp[-4].nptr)->name;
                                            tempTypeDef->fields = (yyvsp[-2].fptr);
                                            tempTypeDef->size = count;
                                            tempTypeDef->next = NULL;
                                            struct Fieldstruct* temp1=Fhead;
                                            while(temp1!=NULL)
                                            {
                                                if(temp1->tbv)
                                                {
                                                    printf("verification in progress for %s %s\n",(yyvsp[-4].nptr)->name,temp1->typeName);
                                                    if(strcmp(temp1->typeName,(yyvsp[-4].nptr)->name)==0)
                                                    {
                                                        temp1->tbv=0;
                                                    }
                                                    else
                                                    {
                                                        printf("Error in type fields of user defined %s in field %s\n", (yyvsp[-4].nptr)->name, temp1->typeName);
                                                        exit(1);
                                                    }
                                                }
                                                temp1=temp1->next;
                                            }
                                            if(Thead == NULL) 
                                            {
                                                Thead = tempTypeDef;
                                                Ttail = tempTypeDef;
                                            } 
                                            else 
                                            {
                                                Ttail->next = tempTypeDef;
                                                Ttail = tempTypeDef;
                                            }
                                            Fhead = NULL;
                                            Ftail = NULL;

                                        }
#line 1566 "y.tab.c"
    break;

  case 10: /* TypeFieldList: TypeFieldList TypeField  */
#line 128 "ex2.y"
                                        {
                                            struct Fieldstruct* tempFieldList = (struct Fieldstruct*)malloc(sizeof(struct Fieldstruct));
                                            tempFieldList = (yyvsp[0].fptr);
                                            struct Fieldstruct* temp = (yyvsp[-1].fptr);
                                            Fhead = (yyvsp[-1].fptr);
                                            tempFieldList->next = NULL;
                                            int cnt=1;
                                            while(temp->next != NULL) 
                                            {
                                                temp = temp->next;
                                                if(temp->type==TYPE_USER_DEC)
                                                {
                                                    struct TypeDef* tempTypeDef = TLookup(temp->typeName);
                                                    if(tempTypeDef==NULL)
                                                    {
                                                        printf("Error in type fields of user defined %s in field %s\n", nameType, temp->typeName);
                                                        exit(1);
                                                    }
                                                    else
                                                    {
                                                        cnt=cnt+tempTypeDef->size;
                                                    }
                                                }
                                                else
                                                {
                                                    cnt++;
                                                }
                                                
                                            }
                                            tempFieldList->fieldIndex=cnt;
                                            tempFieldList->tbv=tbv;
                                            tempFieldList->typeName=nameType;
                                            temp->next = tempFieldList;
                                            Ftail = tempFieldList;
                                            (yyval.fptr) = (yyvsp[-1].fptr);
                        }
#line 1607 "y.tab.c"
    break;

  case 11: /* TypeFieldList: TypeField  */
#line 164 "ex2.y"
                          {
                                        struct Fieldstruct* tempFieldList = (struct Fieldstruct*)malloc(sizeof(struct Fieldstruct));
                                        tempFieldList = (yyvsp[0].fptr);
                                        tempFieldList->next = NULL;
                                        tempFieldList->fieldIndex=0;
                                        tempFieldList->tbv=tbv;
                                        tempFieldList->typeName=nameType;
                                        (yyval.fptr) = tempFieldList;
                                        Fhead = tempFieldList;
                                        Ftail = tempFieldList;
                        }
#line 1623 "y.tab.c"
    break;

  case 12: /* TypeField: FIType ID ';'  */
#line 176 "ex2.y"
                            {
                                    struct Fieldstruct* tempFieldList = (struct Fieldstruct*)malloc(sizeof(struct Fieldstruct));
                                    tempFieldList->name = (yyvsp[-1].nptr)->name;
                                    tempFieldList->type = declarationType;
                                    tempFieldList->tbv=tbv;
                                    tempFieldList->typeName=nameType;
                                    tempFieldList->next = NULL;

                                    (yyval.fptr) = tempFieldList;
                        }
#line 1638 "y.tab.c"
    break;

  case 13: /* FIType: INT  */
#line 188 "ex2.y"
                { declarationType = TYPE_INT; tbv=0;strcpy(nameType,"Integer");}
#line 1644 "y.tab.c"
    break;

  case 14: /* FIType: STR  */
#line 189 "ex2.y"
                { declarationType = TYPE_STR; tbv=0;strcpy(nameType,"String");}
#line 1650 "y.tab.c"
    break;

  case 15: /* FIType: ID  */
#line 190 "ex2.y"
                { 
                    declarationType = TYPE_USER_DEC;
                    struct TypeDef* temp=Thead;

                    while(temp!=NULL)
                    {
                        if(strcmp(temp->name,(yyvsp[0].nptr)->name)==0)
                        {
                            printf("User-defined type %s found\n", (yyvsp[0].nptr)->name);
                            tbv=0;
                            strcpy(nameType,(yyvsp[0].nptr)->name);
                            break;
                        }
                        temp = temp->next;
                    }
                    if(temp==NULL)
                    { 
                        tbv=1;
                        strcpy(nameType,(yyvsp[0].nptr)->name);
                    }
                }
#line 1676 "y.tab.c"
    break;

  case 16: /* Field: Field '.' ID  */
#line 215 "ex2.y"
                    {
                        // Field is already validated, now validate next level==-
                        struct TypeDef* parentType = (yyvsp[-2].nptr)->userType;
                        if(parentType == NULL) 
                        {
                            printf("Error: Previous field is not a user-defined type\n");
                            exit(1);
                        }
                        
                        // Search for $3 (ID) in parentType's fields
                        struct Fieldstruct* field = parentType->fields;
                        int found = 0;
                        struct TypeDef* currentType = NULL;
                        
                        while(field != NULL) 
                        {
                            if(strcmp(field->name, (yyvsp[0].nptr)->name) == 0) 
                            {
                                found = 1;
                                // If this field is also user-defined, get its type
                                if(field->type == TYPE_USER_DEC) 
                                {
                                    currentType = TLookup(field->typeName);
                                }
                                break;
                            }
                            field = field->next;
                        }
                        
                        if(!found) {
                            printf("Error: Field %s not found in type %s\n", (yyvsp[0].nptr)->name, parentType->name);
                            exit(1);
                        }
                        
                        (yyval.nptr) = TreeCreate(field->type, NODE_FIELD, (yyvsp[0].nptr)->name, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);
                        (yyval.nptr)->userType = currentType;
                    }
#line 1718 "y.tab.c"
    break;

  case 17: /* Field: ID '.' ID  */
#line 253 "ex2.y"
                    {
                        // Look up ID in global symbol table
                        struct Gsymbol* var = GLookup((yyvsp[-2].nptr)->name);
                        if(var == NULL) 
                        {
                            printf("Error: Variable %s not declared\n", (yyvsp[-2].nptr)->name);
                            exit(1);
                        }
                        
                        // Check if it's a user-defined type
                        if(var->type != TYPE_USER_DEC) 
                        {
                            printf("Error: Variable %s is not of user-defined type\n", (yyvsp[-2].nptr)->name);
                            exit(1);
                        }
                        
                        // Get the type definition from type table
                        struct TypeDef* userType = var->userType;
                        if(userType == NULL) 
                        {
                            printf("Error: Type definition not found for %s\n", var->userType->name);
                            exit(1);
                        }
                        
                        // Search for field ID in the type's field list
                        struct Fieldstruct* field = userType->fields;
                        int found = 0;
                        struct TypeDef* fieldType = NULL;
                        
                        while(field != NULL) 
                        {
                            if(strcmp(field->name, (yyvsp[0].nptr)->name) == 0) 
                            {
                                found = 1;
                                // If field is also user-defined, get its type for further chaining
                                if(field->type == TYPE_USER_DEC) 
                                {
                                    fieldType = TLookup(field->typeName);
                                }
                                break;
                            }
                            field = field->next;
                        }
                        
                        if(!found) 
                        {
                            printf("Error: Field %s not found in type %s\n", (yyvsp[0].nptr)->name, userType->name);
                            exit(1);
                        }
                        
                        (yyval.nptr) = TreeCreate(field->type, NODE_FIELD, (yyvsp[0].nptr)->name, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);
                        (yyval.nptr)->Gentry = var;
                        (yyval.nptr)->userType = fieldType;  // Store for further chaining
                    }
#line 1777 "y.tab.c"
    break;

  case 18: /* GDeclBlock: DECL GDeclList ENDDECL  */
#line 309 "ex2.y"
                                        { printGSymbolTable() ;print_header();}
#line 1783 "y.tab.c"
    break;

  case 19: /* GDeclBlock: DECL ENDDECL  */
#line 310 "ex2.y"
                                        { printGSymbolTable() ;print_header();}
#line 1789 "y.tab.c"
    break;

  case 23: /* Type: INT  */
#line 378 "ex2.y"
            {declarationType = TYPE_INT;}
#line 1795 "y.tab.c"
    break;

  case 24: /* Type: STR  */
#line 379 "ex2.y"
            {declarationType = TYPE_STR;}
#line 1801 "y.tab.c"
    break;

  case 25: /* Type: ID  */
#line 380 "ex2.y"
            {
                declarationType = TYPE_USER_DEC;
                struct TypeDef* tempTypeDef = TLookup((yyvsp[0].nptr)->name);
                if(tempTypeDef == NULL)
                {
                    printf("User-defined type %s not defined\n", (yyvsp[0].nptr)->name);
                    exit(1);
                }
                
                strcpy(declaredType, (yyvsp[0].nptr)->name);
            }
#line 1817 "y.tab.c"
    break;

  case 26: /* FType: INT  */
#line 394 "ex2.y"
             {FDeclarationType = TYPE_INT;}
#line 1823 "y.tab.c"
    break;

  case 27: /* FType: STR  */
#line 395 "ex2.y"
             {FDeclarationType = TYPE_STR;}
#line 1829 "y.tab.c"
    break;

  case 30: /* GId: ID '(' ParamList ')'  */
#line 404 "ex2.y"
                            {
                                if(declarationType==TYPE_USER_DEC)
                                {
                                    checkAvailability((yyvsp[-3].nptr)->name, 1);
                                    GInstallType((yyvsp[-3].nptr)->name, declarationType, -1, TLookup(declaredType));
                                    declCount++;
                                    Phead = NULL;
                                    Ptail = NULL;
                                    
                                }
                                else
                                {
                                    declCount++;
                                    checkAvailability((yyvsp[-3].nptr)->name, 1);
                                    GInstall((yyvsp[-3].nptr)->name, declarationType, -1, Phead);
                                    Phead = NULL;
                                    Ptail = NULL;
                                }
                                


                            }
#line 1856 "y.tab.c"
    break;

  case 31: /* GId: ID  */
#line 426 "ex2.y"
                            {
                                if(declarationType==TYPE_USER_DEC)
                                {
                                    checkAvailability((yyvsp[0].nptr)->name, 1);
                                    GInstallType((yyvsp[0].nptr)->name, declarationType, 1, TLookup(declaredType));
                                }
                                else
                                {   
                                checkAvailability((yyvsp[0].nptr)->name, 1);
                                GInstall((yyvsp[0].nptr)->name, declarationType, 1, NULL);
                                }
                            }
#line 1873 "y.tab.c"
    break;

  case 32: /* GId: ID '[' NUM ']'  */
#line 438 "ex2.y"
                            {
                                checkAvailability((yyvsp[-3].nptr)->name, 1);
                                if((yyvsp[-1].nptr)->value.intval < 1) 
                                {
                                    yyerror_impl("Invalid array size for", (yyvsp[-3].nptr)->name);
                                    exit(1);
                                }
                                GInstall((yyvsp[-3].nptr)->name, declarationType, (yyvsp[-1].nptr)->value.intval, NULL);
                            }
#line 1887 "y.tab.c"
    break;

  case 35: /* FDef: Type ID '(' ParamList ')' '{' LDeclBlock Body '}'  */
#line 484 "ex2.y"
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
#line 1956 "y.tab.c"
    break;

  case 38: /* ParamList: %empty  */
#line 552 "ex2.y"
                            {(yyval.nptr) = NULL;}
#line 1962 "y.tab.c"
    break;

  case 39: /* Param: FType ID  */
#line 556 "ex2.y"
                {
                    checkAvailability((yyvsp[0].nptr)->name, 0);
                    PInstall((yyvsp[0].nptr)->name, FDeclarationType);
                }
#line 1971 "y.tab.c"
    break;

  case 40: /* Param: FType MUL ID  */
#line 561 "ex2.y"
                {
                    checkAvailability((yyvsp[0].nptr)->name, 0);
                    PInstall((yyvsp[0].nptr)->name, TYPE_INT_PTR);
                }
#line 1980 "y.tab.c"
    break;

  case 41: /* MainBlock: Type MAIN '(' ')' '{' LDeclBlock Body '}'  */
#line 567 "ex2.y"
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
#line 2022 "y.tab.c"
    break;

  case 42: /* LDeclBlock: DECL LDecList ENDDECL  */
#line 606 "ex2.y"
                                    {InstallParamsInLocal();}
#line 2028 "y.tab.c"
    break;

  case 43: /* LDeclBlock: DECL ENDDECL  */
#line 607 "ex2.y"
                                    {InstallParamsInLocal();}
#line 2034 "y.tab.c"
    break;

  case 44: /* LDeclBlock: %empty  */
#line 608 "ex2.y"
                                    {InstallParamsInLocal();}
#line 2040 "y.tab.c"
    break;

  case 48: /* IdList: IdList ',' ID  */
#line 618 "ex2.y"
                        {
                            checkAvailability((yyvsp[0].nptr)->name, 0);
                            LInstall((yyvsp[0].nptr)->name, FDeclarationType);
                        }
#line 2049 "y.tab.c"
    break;

  case 49: /* IdList: ID  */
#line 622 "ex2.y"
                        {
                            checkAvailability((yyvsp[0].nptr)->name, 0);
                            LInstall((yyvsp[0].nptr)->name, FDeclarationType);
                        }
#line 2058 "y.tab.c"
    break;

  case 50: /* Body: START Slist RetStmt END  */
#line 628 "ex2.y"
                                {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_CONNECTOR, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[-1].nptr), NULL);}
#line 2064 "y.tab.c"
    break;

  case 51: /* Body: START RetStmt END  */
#line 629 "ex2.y"
                                {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 2070 "y.tab.c"
    break;

  case 52: /* RetStmt: RETURN expr ';'  */
#line 632 "ex2.y"
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
#line 2087 "y.tab.c"
    break;

  case 53: /* Slist: Slist Stmt  */
#line 646 "ex2.y"
                        {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_CONNECTOR, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);}
#line 2093 "y.tab.c"
    break;

  case 54: /* Slist: Stmt  */
#line 647 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2099 "y.tab.c"
    break;

  case 55: /* Stmt: InputStmt  */
#line 650 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2105 "y.tab.c"
    break;

  case 56: /* Stmt: OutputStmt  */
#line 651 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2111 "y.tab.c"
    break;

  case 57: /* Stmt: AsgStmt  */
#line 652 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2117 "y.tab.c"
    break;

  case 58: /* Stmt: IfStmt  */
#line 653 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2123 "y.tab.c"
    break;

  case 59: /* Stmt: WhileStmt  */
#line 654 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2129 "y.tab.c"
    break;

  case 60: /* Stmt: BrkStmt  */
#line 655 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2135 "y.tab.c"
    break;

  case 61: /* Stmt: ContStmt  */
#line 656 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2141 "y.tab.c"
    break;

  case 62: /* Stmt: func ';'  */
#line 657 "ex2.y"
                        {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 2147 "y.tab.c"
    break;

  case 63: /* IfStmt: IF '(' expr ')' THEN Slist ELSE Slist ENDIF ';'  */
#line 660 "ex2.y"
                                                            {
                                                                typecheck((yyvsp[-7].nptr)->type, TYPE_BOOL, 'e');
                                                                (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_IF_ELSE, NULL, NULL, NULL, (yyvsp[-7].nptr), (yyvsp[-2].nptr), (yyvsp[-4].nptr));
                                                            }
#line 2156 "y.tab.c"
    break;

  case 64: /* IfStmt: IF '(' expr ')' THEN Slist ENDIF ';'  */
#line 664 "ex2.y"
                                                            {
                                                                typecheck((yyvsp[-5].nptr)->type, TYPE_BOOL, 'i');
                                                                (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_IF, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-2].nptr), NULL);
                                                            }
#line 2165 "y.tab.c"
    break;

  case 65: /* WhileStmt: WHILE '(' expr ')' DO Slist ENDWHILE ';'  */
#line 670 "ex2.y"
                                                            {
                                                                typecheck((yyvsp[-5].nptr)->type, TYPE_BOOL, 'w');
                                                                (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_WHILE, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-2].nptr), NULL);
                                                            }
#line 2174 "y.tab.c"
    break;

  case 66: /* BrkStmt: BREAK ';'  */
#line 675 "ex2.y"
                                    {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_BREAK, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 2180 "y.tab.c"
    break;

  case 67: /* ContStmt: CONT ';'  */
#line 678 "ex2.y"
                                    {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_CONT, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 2186 "y.tab.c"
    break;

  case 68: /* InputStmt: READ '(' id ')' ';'  */
#line 681 "ex2.y"
                                    {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_READ, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);}
#line 2192 "y.tab.c"
    break;

  case 69: /* OutputStmt: WRITE '(' expr ')' ';'  */
#line 684 "ex2.y"
                                    {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_WRITE, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);}
#line 2198 "y.tab.c"
    break;

  case 70: /* AsgStmt: id ASSGN expr ';'  */
#line 687 "ex2.y"
                                    {
                                        typecheck((yyvsp[-3].nptr)->type, (yyvsp[-1].nptr)->type, '=');
                                        (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                                    }
#line 2207 "y.tab.c"
    break;

  case 71: /* ExprList: ExprList ',' expr  */
#line 693 "ex2.y"
                            {
                                (yyvsp[0].nptr)->arglist = (yyvsp[-2].nptr);
                                (yyval.nptr) = (yyvsp[0].nptr);
                            }
#line 2216 "y.tab.c"
    break;

  case 72: /* ExprList: expr  */
#line 697 "ex2.y"
                            {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2222 "y.tab.c"
    break;

  case 73: /* ExprList: %empty  */
#line 698 "ex2.y"
                            {(yyval.nptr) = NULL;}
#line 2228 "y.tab.c"
    break;

  case 74: /* expr: expr PLUS expr  */
#line 701 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TYPE_INT, NODE_PLUS, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2237 "y.tab.c"
    break;

  case 75: /* expr: expr MINUS expr  */
#line 705 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TYPE_INT, NODE_MINUS, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2246 "y.tab.c"
    break;

  case 76: /* expr: expr MUL expr  */
#line 709 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TYPE_INT, NODE_MUL, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2255 "y.tab.c"
    break;

  case 77: /* expr: expr DIV expr  */
#line 713 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TYPE_INT, NODE_DIV, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2264 "y.tab.c"
    break;

  case 78: /* expr: expr MOD expr  */
#line 717 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TYPE_INT, NODE_MOD, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2273 "y.tab.c"
    break;

  case 79: /* expr: expr LT expr  */
#line 721 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_LT, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2282 "y.tab.c"
    break;

  case 80: /* expr: expr GT expr  */
#line 725 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_GT, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2291 "y.tab.c"
    break;

  case 81: /* expr: expr LE expr  */
#line 729 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_LE, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2300 "y.tab.c"
    break;

  case 82: /* expr: expr GE expr  */
#line 733 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_GE, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2309 "y.tab.c"
    break;

  case 83: /* expr: expr NEQ expr  */
#line 737 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_NEQ, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2318 "y.tab.c"
    break;

  case 84: /* expr: expr EQ expr  */
#line 741 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_EQ, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2327 "y.tab.c"
    break;

  case 85: /* expr: expr AND expr  */
#line 745 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'l');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_AND, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2336 "y.tab.c"
    break;

  case 86: /* expr: expr OR expr  */
#line 749 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'l');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_OR, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2345 "y.tab.c"
    break;

  case 87: /* expr: '(' expr ')'  */
#line 753 "ex2.y"
                        {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 2351 "y.tab.c"
    break;

  case 88: /* expr: NUM  */
#line 754 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2357 "y.tab.c"
    break;

  case 89: /* expr: MINUS NUM  */
#line 755 "ex2.y"
                        {
                            (yyvsp[0].nptr)->value.intval = -1*((yyvsp[0].nptr)->value.intval);
                            (yyval.nptr) = (yyvsp[0].nptr);
                        }
#line 2366 "y.tab.c"
    break;

  case 90: /* expr: STRVAL  */
#line 759 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2372 "y.tab.c"
    break;

  case 91: /* expr: id  */
#line 760 "ex2.y"
                                {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2378 "y.tab.c"
    break;

  case 92: /* expr: func  */
#line 761 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2384 "y.tab.c"
    break;

  case 93: /* expr: ADDR id  */
#line 762 "ex2.y"
                       {
                            if((yyvsp[0].nptr)->type == TYPE_INT_PTR) 
                            {
                                yyerror_impl("Cannot take address of pointer variable", (yyvsp[0].nptr)->name);
                                exit(1);
                            }
                            (yyval.nptr) = TreeCreate(TYPE_INT_PTR, NODE_ADDR, NULL, NULL, NULL, (yyvsp[0].nptr), NULL, NULL);
                        }
#line 2397 "y.tab.c"
    break;

  case 94: /* expr: Field  */
#line 770 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2403 "y.tab.c"
    break;

  case 95: /* func: ID '(' ExprList ')'  */
#line 774 "ex2.y"
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
#line 2457 "y.tab.c"
    break;

  case 96: /* id: ID  */
#line 824 "ex2.y"
                        {
                            assignType((yyvsp[0].nptr), 0);
                            (yyval.nptr) = (yyvsp[0].nptr);
                        }
#line 2466 "y.tab.c"
    break;

  case 97: /* id: ID '[' expr ']'  */
#line 828 "ex2.y"
                        {
                            assignType((yyvsp[-3].nptr), 2);
                            (yyval.nptr) = TreeCreate((yyvsp[-3].nptr)->type, NODE_ARRAY, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                            (yyval.nptr)->Gentry = (yyvsp[-3].nptr)->Gentry;
                            (yyval.nptr)->Lentry = (yyvsp[-3].nptr)->Lentry;
                        }
#line 2477 "y.tab.c"
    break;

  case 98: /* id: MUL ID  */
#line 834 "ex2.y"
                        {
                            assignType((yyvsp[0].nptr), 0);
                            (yyval.nptr) = TreeCreate((yyvsp[0].nptr)->type, NODE_INT_PTR, (yyvsp[0].nptr)->name, NULL, NULL, NULL, NULL, NULL);
                            (yyval.nptr)->Gentry = (yyvsp[0].nptr)->Gentry;
                            (yyval.nptr)->Lentry = (yyvsp[0].nptr)->Lentry;
                        }
#line 2488 "y.tab.c"
    break;


#line 2492 "y.tab.c"

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

#line 872 "ex2.y"


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
