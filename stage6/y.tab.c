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
    //void error(char const *s, char const *var);
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
    TYPE = 294,                    /* TYPE  */
    ENDTYPE = 295,                 /* ENDTYPE  */
    NILL = 296,                    /* NILL  */
    DEQNILL = 297,                 /* DEQNILL  */
    NEQNILL = 298,                 /* NEQNILL  */
    FREE = 299,                    /* FREE  */
    ALLOC = 300,                   /* ALLOC  */
    INIT = 301                     /* INIT  */
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
#define TYPE 294
#define ENDTYPE 295
#define NILL 296
#define DEQNILL 297
#define NEQNILL 298
#define FREE 299
#define ALLOC 300
#define INIT 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "ex2.y"

    struct ASTNode *nptr;

#line 239 "y.tab.c"

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
  YYSYMBOL_TYPE = 39,                      /* TYPE  */
  YYSYMBOL_ENDTYPE = 40,                   /* ENDTYPE  */
  YYSYMBOL_NILL = 41,                      /* NILL  */
  YYSYMBOL_DEQNILL = 42,                   /* DEQNILL  */
  YYSYMBOL_NEQNILL = 43,                   /* NEQNILL  */
  YYSYMBOL_FREE = 44,                      /* FREE  */
  YYSYMBOL_ALLOC = 45,                     /* ALLOC  */
  YYSYMBOL_INIT = 46,                      /* INIT  */
  YYSYMBOL_47_ = 47,                       /* '{'  */
  YYSYMBOL_48_ = 48,                       /* '}'  */
  YYSYMBOL_49_ = 49,                       /* ';'  */
  YYSYMBOL_50_ = 50,                       /* ','  */
  YYSYMBOL_51_ = 51,                       /* '('  */
  YYSYMBOL_52_ = 52,                       /* ')'  */
  YYSYMBOL_53_ = 53,                       /* '['  */
  YYSYMBOL_54_ = 54,                       /* ']'  */
  YYSYMBOL_55_ = 55,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 56,                  /* $accept  */
  YYSYMBOL_program = 57,                   /* program  */
  YYSYMBOL_TypeDefBlock = 58,              /* TypeDefBlock  */
  YYSYMBOL_TypeDefList = 59,               /* TypeDefList  */
  YYSYMBOL_TypeDef = 60,                   /* TypeDef  */
  YYSYMBOL_UserDefinedType = 61,           /* UserDefinedType  */
  YYSYMBOL_FieldDeclList = 62,             /* FieldDeclList  */
  YYSYMBOL_FieldDecl = 63,                 /* FieldDecl  */
  YYSYMBOL_GDeclBlock = 64,                /* GDeclBlock  */
  YYSYMBOL_GDeclList = 65,                 /* GDeclList  */
  YYSYMBOL_GDecl = 66,                     /* GDecl  */
  YYSYMBOL_FieldType = 67,                 /* FieldType  */
  YYSYMBOL_Type = 68,                      /* Type  */
  YYSYMBOL_FType = 69,                     /* FType  */
  YYSYMBOL_GIdList = 70,                   /* GIdList  */
  YYSYMBOL_GId = 71,                       /* GId  */
  YYSYMBOL_FDefBlock = 72,                 /* FDefBlock  */
  YYSYMBOL_FDef = 73,                      /* FDef  */
  YYSYMBOL_ParamList = 74,                 /* ParamList  */
  YYSYMBOL_Param = 75,                     /* Param  */
  YYSYMBOL_MainBlock = 76,                 /* MainBlock  */
  YYSYMBOL_LDeclBlock = 77,                /* LDeclBlock  */
  YYSYMBOL_LDecList = 78,                  /* LDecList  */
  YYSYMBOL_LDecl = 79,                     /* LDecl  */
  YYSYMBOL_IdList = 80,                    /* IdList  */
  YYSYMBOL_LId = 81,                       /* LId  */
  YYSYMBOL_Body = 82,                      /* Body  */
  YYSYMBOL_RetStmt = 83,                   /* RetStmt  */
  YYSYMBOL_Field = 84,                     /* Field  */
  YYSYMBOL_Slist = 85,                     /* Slist  */
  YYSYMBOL_Stmt = 86,                      /* Stmt  */
  YYSYMBOL_IfStmt = 87,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 88,                 /* WhileStmt  */
  YYSYMBOL_BrkStmt = 89,                   /* BrkStmt  */
  YYSYMBOL_ContStmt = 90,                  /* ContStmt  */
  YYSYMBOL_InputStmt = 91,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 92,                /* OutputStmt  */
  YYSYMBOL_AsgStmt = 93,                   /* AsgStmt  */
  YYSYMBOL_ExprList = 94,                  /* ExprList  */
  YYSYMBOL_expr = 95,                      /* expr  */
  YYSYMBOL_func = 96,                      /* func  */
  YYSYMBOL_id = 97                         /* id  */
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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   378

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  231

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


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
      51,    52,     2,     2,    50,     2,    55,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    49,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    54,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    52,    52,    53,    56,    57,    60,    61,    64,    67,
      73,    74,    77,    87,    95,   102,   111,   112,   115,   118,
     119,   120,   137,   138,   139,   149,   150,   151,   162,   163,
     166,   173,   177,   188,   189,   192,   262,   263,   264,   267,
     273,   308,   309,   310,   313,   314,   317,   320,   321,   324,
     330,   331,   334,   347,   352,   357,   358,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   378,   386,   389,   393,
     399,   404,   407,   410,   418,   428,   431,   448,   456,   465,
     470,   479,   489,   493,   494,   497,   501,   505,   509,   513,
     517,   521,   525,   529,   533,   537,   541,   545,   549,   553,
     557,   558,   562,   567,   571,   572,   573,   576,   583,   587,
     592
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
  "ENDDECL", "INT", "STR", "MAIN", "RETURN", "TYPE", "ENDTYPE", "NILL",
  "DEQNILL", "NEQNILL", "FREE", "ALLOC", "INIT", "'{'", "'}'", "';'",
  "','", "'('", "')'", "'['", "']'", "'.'", "$accept", "program",
  "TypeDefBlock", "TypeDefList", "TypeDef", "UserDefinedType",
  "FieldDeclList", "FieldDecl", "GDeclBlock", "GDeclList", "GDecl",
  "FieldType", "Type", "FType", "GIdList", "GId", "FDefBlock", "FDef",
  "ParamList", "Param", "MainBlock", "LDeclBlock", "LDecList", "LDecl",
  "IdList", "LId", "Body", "RetStmt", "Field", "Slist", "Stmt", "IfStmt",
  "WhileStmt", "BrkStmt", "ContStmt", "InputStmt", "OutputStmt", "AsgStmt",
  "ExprList", "expr", "func", "id", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-112)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,     6,    44,    43,  -112,  -112,     7,  -112,    23,  -112,
      49,   156,  -112,  -112,   185,  -112,  -112,  -112,  -112,    65,
    -112,    94,    11,   156,  -112,  -112,  -112,  -112,  -112,    38,
    -112,   111,  -112,  -112,    29,   -43,  -112,    79,   101,  -112,
    -112,  -112,  -112,    85,   210,   192,  -112,    94,   210,   150,
    -112,  -112,  -112,  -112,   200,    64,  -112,   157,  -112,   116,
     166,  -112,   210,  -112,  -112,   171,   190,  -112,   190,    88,
     219,   219,  -112,   223,   149,  -112,   197,   183,   186,  -112,
     144,  -112,  -112,  -112,   -12,   191,   202,   205,   206,   187,
     220,    14,   217,   225,   248,   -10,   197,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,   221,  -112,  -112,  -112,   223,
      27,    14,   255,   270,    14,    14,    14,  -112,  -112,  -112,
     298,  -112,   274,    14,    24,   253,  -112,  -112,   281,   235,
    -112,    30,   289,   292,  -112,  -112,  -112,   251,   250,   278,
     117,   309,  -112,   135,   -29,   263,    77,    83,   145,  -112,
    -112,   204,  -112,   151,  -112,  -112,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,  -112,    87,    91,
     267,   268,   273,   284,  -112,  -112,  -112,   266,  -112,    14,
    -112,   276,   277,   293,   331,   329,   300,   302,   303,  -112,
      37,    37,  -112,  -112,  -112,   107,   107,   318,   318,   318,
     318,   307,   310,  -112,  -112,   306,  -112,   311,   309,  -112,
    -112,  -112,   240,   240,  -112,  -112,  -112,  -112,   312,  -112,
     178,   208,  -112,   240,   313,   314,   229,  -112,  -112,   315,
    -112
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    15,     9,     5,     0,     7,     0,     1,
       0,     0,     4,     6,     0,    24,    14,    22,    23,     0,
      17,     0,     0,     0,    34,     3,    21,    19,    20,     0,
      11,     0,    13,    16,    31,     0,    29,     0,     0,    33,
       2,     8,    10,     0,    38,     0,    18,     0,    38,     0,
      12,    27,    25,    26,     0,     0,    37,     0,    28,     0,
       0,    39,     0,    30,    32,     0,    43,    36,    43,     0,
       0,     0,    42,     0,     0,    45,     0,     0,     0,    49,
       0,    48,    41,    44,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    56,    60,    61,
      62,    63,    57,    58,    59,     0,    40,    35,    46,     0,
       0,    84,     0,     0,     0,     0,     0,    71,    72,   101,
     108,   103,     0,     0,   106,     0,   105,   104,     0,     0,
      51,     0,     0,     0,    55,    64,    47,     0,     0,     0,
       0,    83,    53,   108,     0,     0,     0,     0,     0,    98,
      99,     0,   102,     0,    96,    97,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,     0,     0,
       0,     0,     0,     0,    54,    50,    80,     0,    76,     0,
     107,     0,     0,     0,     0,     0,     0,   108,     0,   100,
      85,    86,    87,    88,    89,    95,    94,    92,    93,    90,
      91,     0,     0,    67,    81,     0,    79,     0,    82,    74,
      73,    75,     0,     0,   109,   110,    65,    66,     0,    78,
       0,     0,    77,     0,     0,     0,     0,    69,    70,     0,
      68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -112,  -112,  -112,  -112,   359,  -112,  -112,   337,  -112,  -112,
     348,  -112,     5,   -47,  -112,   321,  -112,   346,   322,   316,
     349,   305,  -112,   297,  -112,   265,   304,   280,   -76,   -85,
     -95,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -102,
     -72,  -111
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     6,     7,     8,    29,    30,    11,    19,
      20,    31,    21,    54,    35,    36,    23,    24,    55,    56,
      25,    70,    74,    75,    80,    81,    77,    94,   124,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   140,   125,
     126,   127
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      95,   134,   145,   110,   105,   131,    46,    47,   139,   141,
       4,     4,   146,   147,   148,    37,    22,   119,   120,   121,
      95,   153,    73,   181,   105,   122,   132,    73,    22,   173,
     119,   120,   121,   119,   120,   121,     1,   144,   122,   111,
     188,   122,    26,   112,     9,   132,     5,    12,    38,   158,
     159,   160,   169,    15,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   123,   154,   155,   137,    15,
      14,   171,   138,    27,    28,   172,    10,   208,   123,   132,
      44,   123,    45,    16,    17,    18,    41,   156,   157,   158,
     159,   160,    51,   156,   157,   158,   159,   160,    34,    32,
      17,    18,   161,   162,   163,   164,   165,   166,   161,   162,
     163,   164,   165,   166,    62,    43,    63,   156,   157,   158,
     159,   160,    72,    52,    53,   134,   134,   220,   221,   183,
      48,   134,   161,   162,    50,   184,    95,    95,   226,   201,
     105,   105,   112,   202,    95,    95,   132,    95,   105,   105,
      95,   105,    49,    51,   105,   156,   157,   158,   159,   160,
      15,   156,   157,   158,   159,   160,    62,   179,    65,   180,
     161,   162,   163,   164,   165,   166,   161,   162,   163,   164,
     165,   166,    84,    82,    52,    53,    85,    86,   151,    26,
     112,    17,    18,   108,   109,    57,    87,   185,   223,   224,
      88,    84,    60,   189,    61,    85,    86,   186,   187,    89,
      90,    64,    84,    66,    51,    87,    85,    86,    68,    88,
      27,    28,    92,    69,    93,    76,    87,    79,    89,    90,
      88,   106,   225,    84,   107,    91,   117,    85,    86,    89,
      90,    92,   113,    93,    84,    52,    53,    87,    85,    86,
     229,    88,    92,   114,    93,   130,   115,   116,    87,   142,
      89,    90,    88,   156,   157,   158,   159,   160,   128,   118,
     135,    89,    90,    92,   143,    93,   129,   152,   161,   162,
     163,   164,   165,   166,    92,   168,    93,   170,   156,   157,
     158,   159,   160,   174,   156,   157,   158,   159,   160,   175,
     176,   177,   167,   161,   162,   163,   164,   165,   166,   161,
     162,   163,   164,   165,   166,   182,   203,   204,   207,   156,
     157,   158,   159,   160,   205,   209,   210,   178,   156,   157,
     158,   159,   160,   206,   161,   162,   163,   164,   165,   166,
     149,   150,   211,   161,   162,    -1,    -1,    -1,    -1,   111,
     212,   151,   213,   112,   214,   151,   216,   215,   218,   217,
     219,   222,   227,   228,   230,    13,    42,    33,    58,    39,
      59,    83,    40,    71,   136,    78,   133,     0,    67
};

static const yytype_int16 yycheck[] =
{
      76,    96,   113,    15,    76,    15,    49,    50,   110,   111,
       4,     4,   114,   115,   116,     4,    11,     3,     4,     5,
      96,   123,    69,    52,    96,    11,    55,    74,    23,   131,
       3,     4,     5,     3,     4,     5,    39,   113,    11,    51,
     151,    11,     4,    55,     0,    55,    40,    40,    37,    12,
      13,    14,   128,     4,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,    51,    42,    43,    41,     4,
      47,    41,    45,    35,    36,    45,    33,   179,    51,    55,
      51,    51,    53,    34,    35,    36,    48,    10,    11,    12,
      13,    14,     4,    10,    11,    12,    13,    14,     4,    34,
      35,    36,    25,    26,    27,    28,    29,    30,    25,    26,
      27,    28,    29,    30,    50,     4,    52,    10,    11,    12,
      13,    14,    34,    35,    36,   220,   221,   212,   213,    52,
      51,   226,    25,    26,    49,    52,   212,   213,   223,    52,
     212,   213,    55,    52,   220,   221,    55,   223,   220,   221,
     226,   223,    51,     4,   226,    10,    11,    12,    13,    14,
       4,    10,    11,    12,    13,    14,    50,    50,    52,    52,
      25,    26,    27,    28,    29,    30,    25,    26,    27,    28,
      29,    30,     4,    34,    35,    36,     8,     9,    53,     4,
      55,    35,    36,    49,    50,     3,    18,    52,    20,    21,
      22,     4,    52,    52,     4,     8,     9,     3,     4,    31,
      32,    54,     4,    47,     4,    18,     8,     9,    47,    22,
      35,    36,    44,    33,    46,     6,    18,     4,    31,    32,
      22,    48,    24,     4,    48,    38,    49,     8,     9,    31,
      32,    44,    51,    46,     4,    35,    36,    18,     8,     9,
      21,    22,    44,    51,    46,     7,    51,    51,    18,     4,
      31,    32,    22,    10,    11,    12,    13,    14,    51,    49,
      49,    31,    32,    44,     4,    46,    51,     3,    25,    26,
      27,    28,    29,    30,    44,     4,    46,    52,    10,    11,
      12,    13,    14,     4,    10,    11,    12,    13,    14,     7,
      49,    51,    49,    25,    26,    27,    28,    29,    30,    25,
      26,    27,    28,    29,    30,    52,    49,    49,    52,    10,
      11,    12,    13,    14,    51,    49,    49,    49,    10,    11,
      12,    13,    14,    49,    25,    26,    27,    28,    29,    30,
      42,    43,    49,    25,    26,    27,    28,    29,    30,    51,
      19,    53,    23,    55,    54,    53,    49,    54,    52,    49,
      49,    49,    49,    49,    49,     6,    29,    19,    47,    23,
      48,    74,    23,    68,   109,    71,    96,    -1,    62
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    39,    57,    58,     4,    40,    59,    60,    61,     0,
      33,    64,    40,    60,    47,     4,    34,    35,    36,    65,
      66,    68,    68,    72,    73,    76,     4,    35,    36,    62,
      63,    67,    34,    66,     4,    70,    71,     4,    37,    73,
      76,    48,    63,     4,    51,    53,    49,    50,    51,    51,
      49,     4,    35,    36,    69,    74,    75,     3,    71,    74,
      52,     4,    50,    52,    54,    52,    47,    75,    47,    33,
      77,    77,    34,    69,    78,    79,     6,    82,    82,     4,
      80,    81,    34,    79,     4,     8,     9,    18,    22,    31,
      32,    38,    44,    46,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    96,    48,    48,    49,    50,
      15,    51,    55,    51,    51,    51,    51,    49,    49,     3,
       4,     5,    11,    51,    84,    95,    96,    97,    51,    51,
       7,    15,    55,    83,    86,    49,    81,    41,    45,    95,
      94,    95,     4,     4,    84,    97,    95,    95,    95,    42,
      43,    53,     3,    95,    42,    43,    10,    11,    12,    13,
      14,    25,    26,    27,    28,    29,    30,    49,     4,    84,
      52,    41,    45,    95,     4,     7,    49,    51,    49,    50,
      52,    52,    52,    52,    52,    52,     3,     4,    97,    52,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    52,    52,    49,    49,    51,    49,    52,    95,    49,
      49,    49,    19,    23,    54,    54,    49,    49,    52,    49,
      85,    85,    49,    20,    21,    24,    85,    49,    49,    21,
      49
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    57,    58,    58,    59,    59,    60,    61,
      62,    62,    63,    64,    64,    64,    65,    65,    66,    67,
      67,    67,    68,    68,    68,    69,    69,    69,    70,    70,
      71,    71,    71,    72,    72,    73,    74,    74,    74,    75,
      76,    77,    77,    77,    78,    78,    79,    80,    80,    81,
      82,    82,    83,    84,    84,    85,    85,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    87,    87,
      88,    89,    90,    91,    91,    92,    93,    93,    93,    93,
      93,    93,    94,    94,    94,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    96,    97,    97,
      97
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     3,     2,     2,     1,     4,     1,
       2,     1,     3,     3,     2,     0,     2,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       4,     1,     4,     2,     1,     9,     3,     1,     0,     2,
       8,     3,     2,     0,     2,     1,     3,     3,     1,     1,
       4,     3,     3,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     5,     5,     4,    10,     8,
       8,     2,     2,     5,     5,     5,     4,     6,     6,     4,
       4,     4,     3,     1,     0,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       3,     1,     2,     1,     1,     1,     1,     4,     1,     4,
       4
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
  case 2: /* program: TypeDefBlock GDeclBlock FDefBlock MainBlock  */
#line 52 "ex2.y"
                                                     {}
#line 1502 "y.tab.c"
    break;

  case 3: /* program: TypeDefBlock GDeclBlock MainBlock  */
#line 53 "ex2.y"
                                                     {}
#line 1508 "y.tab.c"
    break;

  case 4: /* TypeDefBlock: TYPE TypeDefList ENDTYPE  */
#line 56 "ex2.y"
                                       {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 1514 "y.tab.c"
    break;

  case 5: /* TypeDefBlock: TYPE ENDTYPE  */
#line 57 "ex2.y"
                           {(yyval.nptr) = NULL;}
#line 1520 "y.tab.c"
    break;

  case 6: /* TypeDefList: TypeDefList TypeDef  */
#line 60 "ex2.y"
                                 {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 1526 "y.tab.c"
    break;

  case 7: /* TypeDefList: TypeDef  */
#line 61 "ex2.y"
                     {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1532 "y.tab.c"
    break;

  case 8: /* TypeDef: UserDefinedType '{' FieldDeclList '}'  */
#line 64 "ex2.y"
                                                { TInstall((yyvsp[-3].nptr)->name, Fhead); }
#line 1538 "y.tab.c"
    break;

  case 9: /* UserDefinedType: ID  */
#line 67 "ex2.y"
                    {
                        tempASTNode = (yyvsp[0].nptr);
                        (yyval.nptr) = (yyvsp[0].nptr);
                    }
#line 1547 "y.tab.c"
    break;

  case 12: /* FieldDecl: FieldType ID ';'  */
#line 77 "ex2.y"
                            {
                                if(FLookup((yyvsp[-1].nptr)->name, Fhead) != NULL) 
                                {
                                    error("Re-declaration of Field element %s\n", (yyvsp[-1].nptr)->name);
                                    exit(1);
                                }
                                FInstall((yyvsp[-1].nptr)->name, declarationType);
                            }
#line 1560 "y.tab.c"
    break;

  case 13: /* GDeclBlock: DECL GDeclList ENDDECL  */
#line 87 "ex2.y"
                                        {
                                            
                                                initialize();
                                            
                                                printTypeTable();
                                                printGSymbolTable();
                                            
                                        }
#line 1573 "y.tab.c"
    break;

  case 14: /* GDeclBlock: DECL ENDDECL  */
#line 95 "ex2.y"
                                        {
                                            initialize();
                                           
                                                printTypeTable();
                                                printGSymbolTable();
                                            
                                        }
#line 1585 "y.tab.c"
    break;

  case 15: /* GDeclBlock: %empty  */
#line 102 "ex2.y"
                                        {
                                            initialize();

                                                printTypeTable();
                                                printGSymbolTable();
                                            
                                        }
#line 1597 "y.tab.c"
    break;

  case 19: /* FieldType: INT  */
#line 118 "ex2.y"
                {declarationType = TLookup("integer");}
#line 1603 "y.tab.c"
    break;

  case 20: /* FieldType: STR  */
#line 119 "ex2.y"
                {declarationType = TLookup("string");}
#line 1609 "y.tab.c"
    break;

  case 21: /* FieldType: ID  */
#line 120 "ex2.y"
                {
                    declarationType = TLookup((yyvsp[0].nptr)->name);
                    if(declarationType == NULL) 
                    {
                        if(strcmp(tempASTNode->name, (yyvsp[0].nptr)->name) != 0) 
                        {
                            error("Undefined User Defined Type %s\n", (yyvsp[0].nptr)->name);
                            exit(1);
                        }
                        else 
                        {
                            declarationType = TLookup("dummy");
                        }
                    }
                }
#line 1629 "y.tab.c"
    break;

  case 22: /* Type: INT  */
#line 137 "ex2.y"
            {declarationType = TLookup("integer");}
#line 1635 "y.tab.c"
    break;

  case 23: /* Type: STR  */
#line 138 "ex2.y"
            {declarationType = TLookup("string");}
#line 1641 "y.tab.c"
    break;

  case 24: /* Type: ID  */
#line 139 "ex2.y"
            {
                declarationType = TLookup((yyvsp[0].nptr)->name);
                if(declarationType == NULL) 
                {
                    error("Unknown user-defined type %s\n", (yyvsp[0].nptr)->name);
                    exit(1);
                }
            }
#line 1654 "y.tab.c"
    break;

  case 25: /* FType: INT  */
#line 149 "ex2.y"
            {FDeclarationType = TLookup("integer");}
#line 1660 "y.tab.c"
    break;

  case 26: /* FType: STR  */
#line 150 "ex2.y"
            {FDeclarationType = TLookup("string");}
#line 1666 "y.tab.c"
    break;

  case 27: /* FType: ID  */
#line 151 "ex2.y"
            {
                FDeclarationType = TLookup((yyvsp[0].nptr)->name);
                if(FDeclarationType == NULL) 
                {
                    error("Unknown user-defined type %s\n", (yyvsp[0].nptr)->name);
                    exit(1);
                }
            }
#line 1679 "y.tab.c"
    break;

  case 30: /* GId: ID '(' ParamList ')'  */
#line 166 "ex2.y"
                            {
                                declCount++;
                                checkAvailability((yyvsp[-3].nptr)->name, 1);
                                GInstall((yyvsp[-3].nptr)->name, declarationType, -1, Phead);
                                Phead = NULL;
                                Ptail = NULL;
                            }
#line 1691 "y.tab.c"
    break;

  case 31: /* GId: ID  */
#line 173 "ex2.y"
                            {
                                checkAvailability((yyvsp[0].nptr)->name, 1);
                                GInstall((yyvsp[0].nptr)->name, declarationType, 1, NULL);
                            }
#line 1700 "y.tab.c"
    break;

  case 32: /* GId: ID '[' NUM ']'  */
#line 177 "ex2.y"
                            {
                                checkAvailability((yyvsp[-3].nptr)->name, 1);
                                if((yyvsp[-1].nptr)->value.intval < 1) 
                                {
                                    error("Invalid array size", NULL);
                                    exit(1);
                                }
                                GInstall((yyvsp[-3].nptr)->name, declarationType, (yyvsp[-1].nptr)->value.intval, NULL);
                            }
#line 1714 "y.tab.c"
    break;

  case 35: /* FDef: Type ID '(' ParamList ')' '{' LDeclBlock Body '}'  */
#line 192 "ex2.y"
                                                        {
                                                            defCount++;
                                                            Gtemp = GLookup((yyvsp[-7].nptr)->name);

                                                            if(Gtemp == NULL) 
                                                            {
                                                                error("Function %s not declared", (yyvsp[-7].nptr)->name);
                                                                exit(1);
                                                            }

                                                            if(Gtemp->type != declarationType) 
                                                            {
                                                               error("%s : Function type does not match declaration", (yyvsp[-7].nptr)->name);
                                                               exit(1);
                                                            }

                                                            argList1 = Phead;
                                                            argList2 = Gtemp->paramlist;

                                                            while(argList1 != NULL && argList2 != NULL) 
                                                            {
                                                                if(argList1->type != argList2->type) {
                                                                    error("%s : Conflict in argument types", (yyvsp[-7].nptr)->name);
                                                                    exit(1);
                                                                }

                                                                if(strcmp(argList1->name, argList2->name)) {
                                                                    error("%s : Conflict in argument names", (yyvsp[-7].nptr)->name);
                                                                    exit(1);
                                                                }

                                                                argList1 = argList1->next;
                                                                argList2 = argList2->next;
                                                            }

                                                            if ((argList1 != NULL) || (argList2 != NULL)) 
                                                            {
                                                                error("Not enough arguments", NULL);
                                                                exit(1);
                                                            }

                                                            if(testing) 
                                                            {
                                                                printLSymbolTable((yyvsp[-7].nptr)->name);
                                                                print_dot((yyvsp[-1].nptr), (yyvsp[-7].nptr)->name);
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
#line 1787 "y.tab.c"
    break;

  case 38: /* ParamList: %empty  */
#line 264 "ex2.y"
                {(yyval.nptr) = NULL;}
#line 1793 "y.tab.c"
    break;

  case 39: /* Param: FType ID  */
#line 267 "ex2.y"
                 {
                    checkAvailability((yyvsp[0].nptr)->name, 0);
                    PInstall((yyvsp[0].nptr)->name, FDeclarationType);
                }
#line 1802 "y.tab.c"
    break;

  case 40: /* MainBlock: Type MAIN '(' ')' '{' LDeclBlock Body '}'  */
#line 273 "ex2.y"
                                                       {
                                                            if(defCount != declCount) 
                                                            {
                                                                error("All functions declared need to be defined\n", NULL);
                                                                exit(1);
                                                            }

                                                            if(declarationType != TLookup("integer")) 
                                                            {
                                                                error("Main return type should be of integer type\n",NULL);
                                                                exit(1);
                                                            }

                                                            
                                                                printLSymbolTable("main");
                                                                print_dot((yyvsp[-1].nptr), "main");
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
#line 1840 "y.tab.c"
    break;

  case 41: /* LDeclBlock: DECL LDecList ENDDECL  */
#line 308 "ex2.y"
                                    {InstallParamsInLocal();}
#line 1846 "y.tab.c"
    break;

  case 42: /* LDeclBlock: DECL ENDDECL  */
#line 309 "ex2.y"
                                    {InstallParamsInLocal();}
#line 1852 "y.tab.c"
    break;

  case 43: /* LDeclBlock: %empty  */
#line 310 "ex2.y"
                                    {InstallParamsInLocal();}
#line 1858 "y.tab.c"
    break;

  case 49: /* LId: ID  */
#line 324 "ex2.y"
        {
            checkAvailability((yyvsp[0].nptr)->name, 0);
            LInstall((yyvsp[0].nptr)->name, FDeclarationType);
        }
#line 1867 "y.tab.c"
    break;

  case 50: /* Body: START Slist RetStmt END  */
#line 330 "ex2.y"
                                {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_CONNECTOR, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[-1].nptr), NULL);}
#line 1873 "y.tab.c"
    break;

  case 51: /* Body: START RetStmt END  */
#line 331 "ex2.y"
                                {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 1879 "y.tab.c"
    break;

  case 52: /* RetStmt: RETURN expr ';'  */
#line 334 "ex2.y"
                            {
                                if(declarationType == (yyvsp[-1].nptr)->type) 
                                {
                                    (yyval.nptr) = TreeCreate(TLookup("void"), NODE_RET, NULL, NULL, NULL, (yyvsp[-1].nptr), NULL, NULL);
                                }
                                else 
                                {
                                    error("Return type mismatch", NULL);
                                    exit(1);
                                }
                            }
#line 1895 "y.tab.c"
    break;

  case 53: /* Field: ID '.' ID  */
#line 347 "ex2.y"
                        {
                            assignType((yyvsp[-2].nptr), 0);
                            assignTypeField((yyvsp[0].nptr), (yyvsp[-2].nptr)->type->fields);
                            (yyval.nptr) = TreeCreate((yyvsp[0].nptr)->type, NODE_FIELD, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1905 "y.tab.c"
    break;

  case 54: /* Field: Field '.' ID  */
#line 352 "ex2.y"
                        {
                            (yyval.nptr) = insertFieldId((yyvsp[-2].nptr), (yyvsp[0].nptr));
                        }
#line 1913 "y.tab.c"
    break;

  case 55: /* Slist: Slist Stmt  */
#line 357 "ex2.y"
                        {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_CONNECTOR, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);}
#line 1919 "y.tab.c"
    break;

  case 56: /* Slist: Stmt  */
#line 358 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1925 "y.tab.c"
    break;

  case 57: /* Stmt: InputStmt  */
#line 361 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1931 "y.tab.c"
    break;

  case 58: /* Stmt: OutputStmt  */
#line 362 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1937 "y.tab.c"
    break;

  case 59: /* Stmt: AsgStmt  */
#line 363 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1943 "y.tab.c"
    break;

  case 60: /* Stmt: IfStmt  */
#line 364 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1949 "y.tab.c"
    break;

  case 61: /* Stmt: WhileStmt  */
#line 365 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1955 "y.tab.c"
    break;

  case 62: /* Stmt: BrkStmt  */
#line 366 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1961 "y.tab.c"
    break;

  case 63: /* Stmt: ContStmt  */
#line 367 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1967 "y.tab.c"
    break;

  case 64: /* Stmt: func ';'  */
#line 368 "ex2.y"
                        {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 1973 "y.tab.c"
    break;

  case 65: /* Stmt: FREE '(' ID ')' ';'  */
#line 369 "ex2.y"
                                {
                                    assignType((yyvsp[-2].nptr), 0);
                                    if((yyvsp[-2].nptr)->type == TLookup("integer") || (yyvsp[-2].nptr)->type == TLookup("string")) 
                                    {
                                        error("Cannot FREE a string or integer variable\n", NULL);
                                        exit(1);
                                    }
                                    (yyval.nptr) = TreeCreate(TLookup("void"), NODE_FREE, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);
                                }
#line 1987 "y.tab.c"
    break;

  case 66: /* Stmt: FREE '(' Field ')' ';'  */
#line 378 "ex2.y"
                                {
                                    if((yyvsp[-2].nptr)->type == TLookup("integer") || (yyvsp[-2].nptr)->type == TLookup("string")) 
                                    {
                                        error("Cannot FREE a string or integer variable\n", NULL);
                                        exit(1);
                                    }
                                    (yyval.nptr) = TreeCreate(TLookup("void"), NODE_FREE, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);
                                }
#line 2000 "y.tab.c"
    break;

  case 67: /* Stmt: INIT '(' ')' ';'  */
#line 386 "ex2.y"
                                {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_INIT, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 2006 "y.tab.c"
    break;

  case 68: /* IfStmt: IF '(' expr ')' THEN Slist ELSE Slist ENDIF ';'  */
#line 389 "ex2.y"
                                                            {
                                                                typecheck((yyvsp[-7].nptr)->type, TLookup("boolean"), 'e');
                                                                (yyval.nptr) = TreeCreate(TLookup("void"), NODE_IF_ELSE, NULL, NULL, NULL, (yyvsp[-7].nptr), (yyvsp[-2].nptr), (yyvsp[-4].nptr));
                                                            }
#line 2015 "y.tab.c"
    break;

  case 69: /* IfStmt: IF '(' expr ')' THEN Slist ENDIF ';'  */
#line 393 "ex2.y"
                                                            {
                                                                typecheck((yyvsp[-5].nptr)->type, TLookup("boolean"), 'i');
                                                                (yyval.nptr) = TreeCreate(TLookup("void"), NODE_IF, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-2].nptr), NULL);
                                                            }
#line 2024 "y.tab.c"
    break;

  case 70: /* WhileStmt: WHILE '(' expr ')' DO Slist ENDWHILE ';'  */
#line 399 "ex2.y"
                                                            {
                                                                typecheck((yyvsp[-5].nptr)->type, TLookup("boolean"), 'w');
                                                                (yyval.nptr) = TreeCreate(TLookup("void"), NODE_WHILE, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-2].nptr), NULL);
                                                            }
#line 2033 "y.tab.c"
    break;

  case 71: /* BrkStmt: BREAK ';'  */
#line 404 "ex2.y"
                                    {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_BREAK, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 2039 "y.tab.c"
    break;

  case 72: /* ContStmt: CONT ';'  */
#line 407 "ex2.y"
                                    {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_CONT, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 2045 "y.tab.c"
    break;

  case 73: /* InputStmt: READ '(' id ')' ';'  */
#line 410 "ex2.y"
                                    {
                                        if((yyvsp[-2].nptr)->type != TLookup("integer") && (yyvsp[-2].nptr)->type != TLookup("string")) 
                                        {
                                            error("Cannot READ a udt type\n", NULL);
                                            exit(1);
                                        }
                                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_READ, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);
                                    }
#line 2058 "y.tab.c"
    break;

  case 74: /* InputStmt: READ '(' Field ')' ';'  */
#line 418 "ex2.y"
                                    {
                                        if((yyvsp[-2].nptr)->type != TLookup("integer") && (yyvsp[-2].nptr)->type != TLookup("string")) 
                                        {
                                            error("Cannot READ a udt type\n", NULL);
                                            exit(1);
                                        }
                                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_READ, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);
                                    }
#line 2071 "y.tab.c"
    break;

  case 75: /* OutputStmt: WRITE '(' expr ')' ';'  */
#line 428 "ex2.y"
                                    {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_WRITE, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);}
#line 2077 "y.tab.c"
    break;

  case 76: /* AsgStmt: ID ASSGN expr ';'  */
#line 431 "ex2.y"
                                    {
                                        assignType((yyvsp[-3].nptr), 0);
                                        typecheck((yyvsp[-3].nptr)->type, (yyvsp[-1].nptr)->type, '=');
                                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                                    }
#line 2087 "y.tab.c"
    break;

  case 77: /* AsgStmt: Field ASSGN ALLOC '(' ')' ';'  */
#line 448 "ex2.y"
                                        {
                                            if((yyvsp[-5].nptr)->type == TLookup("integer") || (yyvsp[-5].nptr)->type == TLookup("string")) 
                                            {
                                                error("Cannot ALLOC to string or integer variable\n", NULL);
                                                exit(1);
                                            }
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-3].nptr), NULL);
                                        }
#line 2100 "y.tab.c"
    break;

  case 78: /* AsgStmt: ID ASSGN ALLOC '(' ')' ';'  */
#line 456 "ex2.y"
                                        {
                                            assignType((yyvsp[-5].nptr), 0);
                                            if((yyvsp[-5].nptr)->type == TLookup("integer") || (yyvsp[-5].nptr)->type == TLookup("string")) 
                                            {
                                                error("Cannot ALLOC to string or integer variable\n", NULL);
                                                exit(1);
                                            }
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-3].nptr), NULL);
                                        }
#line 2114 "y.tab.c"
    break;

  case 79: /* AsgStmt: Field ASSGN expr ';'  */
#line 465 "ex2.y"
                                        {
                                            typecheck((yyvsp[-3].nptr)->type, (yyvsp[-1].nptr)->type, '=');
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                    
                                        }
#line 2124 "y.tab.c"
    break;

  case 80: /* AsgStmt: ID ASSGN NILL ';'  */
#line 470 "ex2.y"
                                        {
                                            assignType((yyvsp[-3].nptr), 0);
                                            if((yyvsp[-3].nptr)->type == TLookup("integer") || (yyvsp[-3].nptr)->type == TLookup("string")) 
                                            {
                                                error("Cannot assign NULL to string or integer variable\n", NULL);
                                                exit(1);
                                            }
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                                        }
#line 2138 "y.tab.c"
    break;

  case 81: /* AsgStmt: Field ASSGN NILL ';'  */
#line 479 "ex2.y"
                                        {
                                            if((yyvsp[-3].nptr)->type == TLookup("integer") || (yyvsp[-3].nptr)->type == TLookup("string"))    
                                            {
                                                error("Cannot assign NULL to string or integer variable\n", NULL);
                                                exit(1);
                                            }
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                                        }
#line 2151 "y.tab.c"
    break;

  case 82: /* ExprList: ExprList ',' expr  */
#line 489 "ex2.y"
                            {
                                (yyvsp[0].nptr)->arglist = (yyvsp[-2].nptr);
                                (yyval.nptr) = (yyvsp[0].nptr);
                            }
#line 2160 "y.tab.c"
    break;

  case 83: /* ExprList: expr  */
#line 493 "ex2.y"
                            {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2166 "y.tab.c"
    break;

  case 84: /* ExprList: %empty  */
#line 494 "ex2.y"
                            {(yyval.nptr) = NULL;}
#line 2172 "y.tab.c"
    break;

  case 85: /* expr: expr PLUS expr  */
#line 497 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_PLUS, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2181 "y.tab.c"
    break;

  case 86: /* expr: expr MINUS expr  */
#line 501 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_MINUS, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2190 "y.tab.c"
    break;

  case 87: /* expr: expr MUL expr  */
#line 505 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_MUL, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2199 "y.tab.c"
    break;

  case 88: /* expr: expr DIV expr  */
#line 509 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_DIV, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2208 "y.tab.c"
    break;

  case 89: /* expr: expr MOD expr  */
#line 513 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_MOD, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2217 "y.tab.c"
    break;

  case 90: /* expr: expr LT expr  */
#line 517 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_LT, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2226 "y.tab.c"
    break;

  case 91: /* expr: expr GT expr  */
#line 521 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_GT, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2235 "y.tab.c"
    break;

  case 92: /* expr: expr LE expr  */
#line 525 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_LE, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2244 "y.tab.c"
    break;

  case 93: /* expr: expr GE expr  */
#line 529 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_GE, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2253 "y.tab.c"
    break;

  case 94: /* expr: expr NEQ expr  */
#line 533 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_NEQ, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2262 "y.tab.c"
    break;

  case 95: /* expr: expr EQ expr  */
#line 537 "ex2.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_EQ, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2271 "y.tab.c"
    break;

  case 96: /* expr: Field DEQNILL  */
#line 541 "ex2.y"
                        {
                            typecheck((yyvsp[-1].nptr)->type, NULL, '!');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_EQ, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2280 "y.tab.c"
    break;

  case 97: /* expr: Field NEQNILL  */
#line 545 "ex2.y"
                        {
                            typecheck((yyvsp[-1].nptr)->type, NULL, '!');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_NEQ, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2289 "y.tab.c"
    break;

  case 98: /* expr: ID DEQNILL  */
#line 549 "ex2.y"
                        {
                            assignType((yyvsp[-1].nptr), 0);
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_EQ, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2298 "y.tab.c"
    break;

  case 99: /* expr: ID NEQNILL  */
#line 553 "ex2.y"
                        {
                            assignType((yyvsp[-1].nptr), 0);
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_NEQ, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2307 "y.tab.c"
    break;

  case 100: /* expr: '(' expr ')'  */
#line 557 "ex2.y"
                        {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 2313 "y.tab.c"
    break;

  case 101: /* expr: NUM  */
#line 558 "ex2.y"
                        {
                            (yyval.nptr) = (yyvsp[0].nptr);
                            (yyval.nptr)->type = TLookup("integer");
                        }
#line 2322 "y.tab.c"
    break;

  case 102: /* expr: MINUS NUM  */
#line 562 "ex2.y"
                        {
                            (yyvsp[0].nptr)->value.intval = -1*((yyvsp[0].nptr)->value.intval);
                            (yyval.nptr) = (yyvsp[0].nptr);
                            (yyval.nptr)->type = TLookup("integer");
                        }
#line 2332 "y.tab.c"
    break;

  case 103: /* expr: STRVAL  */
#line 567 "ex2.y"
                        {
                            (yyval.nptr) = (yyvsp[0].nptr);
                            (yyval.nptr)->type = TLookup("string");
                        }
#line 2341 "y.tab.c"
    break;

  case 104: /* expr: id  */
#line 571 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2347 "y.tab.c"
    break;

  case 105: /* expr: func  */
#line 572 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2353 "y.tab.c"
    break;

  case 106: /* expr: Field  */
#line 573 "ex2.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2359 "y.tab.c"
    break;

  case 107: /* func: ID '(' ExprList ')'  */
#line 576 "ex2.y"
                            {
                                assignType((yyvsp[-3].nptr), 1);
                                (yyvsp[-3].nptr)->nodetype = NODE_FUNC;
                                (yyvsp[-3].nptr)->ptr1 = reverseList((yyvsp[-1].nptr));
                                (yyval.nptr) = (yyvsp[-3].nptr);
                            }
#line 2370 "y.tab.c"
    break;

  case 108: /* id: ID  */
#line 583 "ex2.y"
                        {
                            assignType((yyvsp[0].nptr), 0);
                            (yyval.nptr) = (yyvsp[0].nptr);
                        }
#line 2379 "y.tab.c"
    break;

  case 109: /* id: ID '[' NUM ']'  */
#line 587 "ex2.y"
                        {
                            (yyvsp[-1].nptr)->type = TLookup("integer");
                            assignType((yyvsp[-3].nptr), 2);
                            (yyval.nptr) = TreeCreate((yyvsp[-3].nptr)->type, NODE_ARRAY, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                        }
#line 2389 "y.tab.c"
    break;

  case 110: /* id: ID '[' id ']'  */
#line 592 "ex2.y"
                        {
                            assignType((yyvsp[-3].nptr), 2);
                            (yyval.nptr) = TreeCreate((yyvsp[-3].nptr)->type, NODE_ARRAY, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                        }
#line 2398 "y.tab.c"
    break;


#line 2402 "y.tab.c"

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

#line 598 "ex2.y"


void error(char const *s, char const *var) 
{
    if(var==NULL)
    {
        printf("Error : %s at line %d\n",s, lineno);
        return;
    }
    printf("Error : %s %s at line %d\n", s, var, lineno);
}
void yyerror(char const *s) 
{
    fprintf(stderr, "Error at line %d: %s\n", lineno, s);
}

int main(int argc, char *argv[]) {
    TInstall("integer", NULL);
    TInstall("string", NULL);
    TInstall("boolean", NULL);
    TInstall("void", NULL);
    TInstall("dummy", NULL); // This is for creating the fieldlist in case of udt

    if (argc < 2) {
        error("Please provide an input filename\n", NULL);
        exit(1);
    } else {
        fp = fopen(argv[1], "r");
        if (!fp) {
            error("Invalid input file specified\n", NULL);
            exit(1);
        } else {
            yyin = fp;
        }
    }
    yyparse();
    return 0;
}
