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
#line 4 "compiler.y"

    #include "compiler_common.h"
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    int yylex_destroy ();
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    /* Symbol table function - you can add new functions if needed. */
    /* parameters and return type can be changed */
    static void create_symbol();
    static void insert_symbol();
    static int lookup_symbol();
    static void dump_symbol();

    /* Global variables */
    bool HAS_ERROR = false;
    int scope = 0;
    int scope_count = 0;
    int addr = -1;
    typedef struct {
        char* name;
        char* type;
        int mut;
        int scope;
        int addr;
        int line_no;
    } Symbol;

    Symbol symbol_table[100];
    int symbol_count = 0;

#line 115 "y.tab.c"

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
    LET = 258,                     /* LET  */
    MUT = 259,                     /* MUT  */
    NEWLINE = 260,                 /* NEWLINE  */
    INT = 261,                     /* INT  */
    FLOAT = 262,                   /* FLOAT  */
    BOOL = 263,                    /* BOOL  */
    STR = 264,                     /* STR  */
    TRUE = 265,                    /* TRUE  */
    FALSE = 266,                   /* FALSE  */
    GEQ = 267,                     /* GEQ  */
    LEQ = 268,                     /* LEQ  */
    EQL = 269,                     /* EQL  */
    NEQ = 270,                     /* NEQ  */
    LOR = 271,                     /* LOR  */
    LAND = 272,                    /* LAND  */
    ADD_ASSIGN = 273,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 274,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 275,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 276,              /* DIV_ASSIGN  */
    REM_ASSIGN = 277,              /* REM_ASSIGN  */
    IF = 278,                      /* IF  */
    ELSE = 279,                    /* ELSE  */
    FOR = 280,                     /* FOR  */
    WHILE = 281,                   /* WHILE  */
    LOOP = 282,                    /* LOOP  */
    PRINT = 283,                   /* PRINT  */
    PRINTLN = 284,                 /* PRINTLN  */
    FUNC = 285,                    /* FUNC  */
    RETURN = 286,                  /* RETURN  */
    BREAK = 287,                   /* BREAK  */
    ARROW = 288,                   /* ARROW  */
    AS = 289,                      /* AS  */
    IN = 290,                      /* IN  */
    DOTDOT = 291,                  /* DOTDOT  */
    RSHIFT = 292,                  /* RSHIFT  */
    LSHIFT = 293,                  /* LSHIFT  */
    INT_LIT = 294,                 /* INT_LIT  */
    FLOAT_LIT = 295,               /* FLOAT_LIT  */
    STRING_LIT = 296,              /* STRING_LIT  */
    ID = 297,                      /* ID  */
    UMINUS = 298                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define LET 258
#define MUT 259
#define NEWLINE 260
#define INT 261
#define FLOAT 262
#define BOOL 263
#define STR 264
#define TRUE 265
#define FALSE 266
#define GEQ 267
#define LEQ 268
#define EQL 269
#define NEQ 270
#define LOR 271
#define LAND 272
#define ADD_ASSIGN 273
#define SUB_ASSIGN 274
#define MUL_ASSIGN 275
#define DIV_ASSIGN 276
#define REM_ASSIGN 277
#define IF 278
#define ELSE 279
#define FOR 280
#define WHILE 281
#define LOOP 282
#define PRINT 283
#define PRINTLN 284
#define FUNC 285
#define RETURN 286
#define BREAK 287
#define ARROW 288
#define AS 289
#define IN 290
#define DOTDOT 291
#define RSHIFT 292
#define LSHIFT 293
#define INT_LIT 294
#define FLOAT_LIT 295
#define STRING_LIT 296
#define ID 297
#define UMINUS 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 54 "compiler.y"

    int i_val;
    float f_val;
    char *s_val;
    /* ... */

#line 261 "y.tab.c"

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
  YYSYMBOL_LET = 3,                        /* LET  */
  YYSYMBOL_MUT = 4,                        /* MUT  */
  YYSYMBOL_NEWLINE = 5,                    /* NEWLINE  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_FLOAT = 7,                      /* FLOAT  */
  YYSYMBOL_BOOL = 8,                       /* BOOL  */
  YYSYMBOL_STR = 9,                        /* STR  */
  YYSYMBOL_TRUE = 10,                      /* TRUE  */
  YYSYMBOL_FALSE = 11,                     /* FALSE  */
  YYSYMBOL_GEQ = 12,                       /* GEQ  */
  YYSYMBOL_LEQ = 13,                       /* LEQ  */
  YYSYMBOL_EQL = 14,                       /* EQL  */
  YYSYMBOL_NEQ = 15,                       /* NEQ  */
  YYSYMBOL_LOR = 16,                       /* LOR  */
  YYSYMBOL_LAND = 17,                      /* LAND  */
  YYSYMBOL_ADD_ASSIGN = 18,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 19,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 20,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 21,                /* DIV_ASSIGN  */
  YYSYMBOL_REM_ASSIGN = 22,                /* REM_ASSIGN  */
  YYSYMBOL_IF = 23,                        /* IF  */
  YYSYMBOL_ELSE = 24,                      /* ELSE  */
  YYSYMBOL_FOR = 25,                       /* FOR  */
  YYSYMBOL_WHILE = 26,                     /* WHILE  */
  YYSYMBOL_LOOP = 27,                      /* LOOP  */
  YYSYMBOL_PRINT = 28,                     /* PRINT  */
  YYSYMBOL_PRINTLN = 29,                   /* PRINTLN  */
  YYSYMBOL_FUNC = 30,                      /* FUNC  */
  YYSYMBOL_RETURN = 31,                    /* RETURN  */
  YYSYMBOL_BREAK = 32,                     /* BREAK  */
  YYSYMBOL_ARROW = 33,                     /* ARROW  */
  YYSYMBOL_AS = 34,                        /* AS  */
  YYSYMBOL_IN = 35,                        /* IN  */
  YYSYMBOL_DOTDOT = 36,                    /* DOTDOT  */
  YYSYMBOL_RSHIFT = 37,                    /* RSHIFT  */
  YYSYMBOL_LSHIFT = 38,                    /* LSHIFT  */
  YYSYMBOL_INT_LIT = 39,                   /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 40,                 /* FLOAT_LIT  */
  YYSYMBOL_STRING_LIT = 41,                /* STRING_LIT  */
  YYSYMBOL_ID = 42,                        /* ID  */
  YYSYMBOL_43_ = 43,                       /* '!'  */
  YYSYMBOL_44_ = 44,                       /* '>'  */
  YYSYMBOL_45_ = 45,                       /* '<'  */
  YYSYMBOL_46_ = 46,                       /* '+'  */
  YYSYMBOL_47_ = 47,                       /* '-'  */
  YYSYMBOL_48_ = 48,                       /* '*'  */
  YYSYMBOL_49_ = 49,                       /* '/'  */
  YYSYMBOL_50_ = 50,                       /* '%'  */
  YYSYMBOL_UMINUS = 51,                    /* UMINUS  */
  YYSYMBOL_52_ = 52,                       /* '('  */
  YYSYMBOL_53_ = 53,                       /* ')'  */
  YYSYMBOL_54_ = 54,                       /* '{'  */
  YYSYMBOL_55_ = 55,                       /* '}'  */
  YYSYMBOL_56_ = 56,                       /* '='  */
  YYSYMBOL_57_ = 57,                       /* ';'  */
  YYSYMBOL_58_ = 58,                       /* ':'  */
  YYSYMBOL_59_ = 59,                       /* '"'  */
  YYSYMBOL_60_ = 60,                       /* '['  */
  YYSYMBOL_61_ = 61,                       /* ']'  */
  YYSYMBOL_62_ = 62,                       /* ','  */
  YYSYMBOL_63_ = 63,                       /* '&'  */
  YYSYMBOL_YYACCEPT = 64,                  /* $accept  */
  YYSYMBOL_Program = 65,                   /* Program  */
  YYSYMBOL_GlobalStatementList = 66,       /* GlobalStatementList  */
  YYSYMBOL_GlobalStatement = 67,           /* GlobalStatement  */
  YYSYMBOL_FunctionDeclStmt = 68,          /* FunctionDeclStmt  */
  YYSYMBOL_69_1 = 69,                      /* $@1  */
  YYSYMBOL_BlockStmt = 70,                 /* BlockStmt  */
  YYSYMBOL_71_2 = 71,                      /* $@2  */
  YYSYMBOL_StatementList = 72,             /* StatementList  */
  YYSYMBOL_Statement = 73,                 /* Statement  */
  YYSYMBOL_VarDeclStmt = 74,               /* VarDeclStmt  */
  YYSYMBOL_IfStmt = 75,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 76,                 /* WhileStmt  */
  YYSYMBOL_AssignmentStmt = 77,            /* AssignmentStmt  */
  YYSYMBOL_PrintStmt = 78,                 /* PrintStmt  */
  YYSYMBOL_ExpressionList = 79,            /* ExpressionList  */
  YYSYMBOL_Expression = 80,                /* Expression  */
  YYSYMBOL_Type = 81                       /* Type  */
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   703

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  160

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


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
       2,     2,     2,    43,    59,     2,     2,    50,    63,     2,
      52,    53,    48,    46,    62,    47,     2,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,    57,
      45,    56,    44,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    60,     2,    61,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,    55,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    51
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    97,    97,   101,   102,   106,   107,   111,   111,   118,
     118,   133,   134,   138,   139,   140,   141,   142,   143,   144,
     148,   159,   170,   181,   192,   203,   214,   228,   229,   233,
     237,   248,   251,   254,   257,   260,   263,   269,   281,   293,
     300,   301,   305,   309,   313,   317,   321,   331,   337,   341,
     345,   349,   353,   357,   361,   365,   369,   377,   381,   388,
     392,   396,   400,   404,   407,   411,   415,   430,   431,   432,
     433,   434,   435
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "LET", "MUT",
  "NEWLINE", "INT", "FLOAT", "BOOL", "STR", "TRUE", "FALSE", "GEQ", "LEQ",
  "EQL", "NEQ", "LOR", "LAND", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "REM_ASSIGN", "IF", "ELSE", "FOR", "WHILE", "LOOP",
  "PRINT", "PRINTLN", "FUNC", "RETURN", "BREAK", "ARROW", "AS", "IN",
  "DOTDOT", "RSHIFT", "LSHIFT", "INT_LIT", "FLOAT_LIT", "STRING_LIT", "ID",
  "'!'", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS", "'('",
  "')'", "'{'", "'}'", "'='", "';'", "':'", "'\"'", "'['", "']'", "','",
  "'&'", "$accept", "Program", "GlobalStatementList", "GlobalStatement",
  "FunctionDeclStmt", "$@1", "BlockStmt", "$@2", "StatementList",
  "Statement", "VarDeclStmt", "IfStmt", "WhileStmt", "AssignmentStmt",
  "PrintStmt", "ExpressionList", "Expression", "Type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-66)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      12,   -66,   -40,    10,    12,   -66,   -66,   -33,   -66,   -66,
       6,   -66,     9,   -66,   -66,   101,    14,   -66,   128,   128,
      13,    15,    76,   -66,    57,   -66,   -66,   -66,   -66,   -66,
     -66,    22,    18,   -66,   -66,   -66,   -66,   -66,    19,   128,
     128,   128,    25,   514,   514,   128,   143,   128,   128,   128,
     128,   128,   166,   -66,   -66,   -47,    -2,    35,   653,   -26,
     539,   -66,   128,   128,   128,   128,    30,   128,   128,   128,
     128,   128,   128,   128,   128,    54,   -66,   564,    16,   589,
     289,   314,   339,   364,   389,   181,   414,   128,    -2,   -66,
     -66,   -66,   -66,    75,    78,   -43,    27,   -66,   607,   607,
     632,   653,   614,   -66,   614,   607,   607,    85,    85,   -26,
     -26,   -26,     9,    34,    33,    43,   -66,   -66,   -66,   -66,
     -66,    25,   237,   -66,   439,   -41,    44,   -66,   105,   -66,
     -66,   -66,   -66,    49,   -66,    48,   -66,   128,   -66,   128,
     181,   128,   464,    50,   -66,   489,   200,   263,   -37,   614,
     -66,   -66,   -66,   -66,    51,    53,   128,   -66,   -66,   614
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     6,     0,     0,     2,     4,     5,     0,     1,     3,
       0,     7,     0,     9,     8,     0,     0,    19,     0,     0,
       0,     0,     0,    18,     0,    12,    13,    16,    17,    14,
      15,     0,     0,    44,    45,    42,    43,    64,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,    49,    48,
       0,    65,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,    29,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      68,    69,    70,     0,     0,     0,     0,    63,    59,    60,
      62,    61,    50,    66,    58,    56,    57,    51,    52,    53,
      54,    55,     0,     0,     0,     0,    32,    33,    34,    35,
      36,    65,     0,    30,     0,     0,     0,    71,     0,    24,
      47,    28,    38,     0,    37,     0,    20,     0,    21,     0,
       0,     0,     0,     0,    31,     0,     0,     0,     0,    40,
      23,    39,    22,    72,     0,     0,     0,    25,    26,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -66,   -66,   -66,   109,   -66,   -66,    -9,   -66,   -66,    90,
     -66,   -66,   -66,   -66,   -66,   -66,   -19,   -65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     5,     6,    12,    23,    15,    24,    25,
      26,    27,    28,    29,    30,   148,    43,    95
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      44,   103,     7,    14,    89,    90,    91,    92,    66,    87,
       8,    88,    67,   128,   129,   137,   138,     1,    31,    10,
      58,    59,    60,   125,   155,   156,    77,    79,    80,    81,
      82,    83,    84,    86,    75,    76,    89,    90,    91,    92,
      33,    34,     2,    98,    99,   100,   101,   102,   104,   105,
     106,   107,   108,   109,   110,   111,    32,   114,    93,    11,
      16,    94,    17,    13,    55,    45,   122,    46,   124,    35,
      36,    37,    38,    39,    96,    61,    56,    40,   112,    57,
      18,   126,    41,    19,    61,    20,    21,   127,   130,    42,
      93,   132,   133,    94,    47,    48,    49,    50,    51,    22,
     134,   139,   143,   131,    16,   144,    17,   151,   157,   142,
     158,    13,    53,     9,    54,    33,    34,     0,   145,    66,
     146,   147,   149,    67,    18,     0,     0,    19,     0,    20,
      21,     0,    52,    72,    73,    74,     0,   159,    33,    34,
       0,     0,     0,    22,    35,    36,    37,    38,    39,     0,
       0,     0,    40,    33,    34,    13,     0,    41,     0,     0,
       0,     0,     0,     0,   140,   141,     0,    35,    36,    37,
      38,    39,     0,     0,     0,    40,    33,    34,     0,     0,
      41,     0,    35,    36,    37,    38,    39,    42,     0,     0,
      40,    33,    34,     0,     0,    41,     0,     0,     0,     0,
       0,     0,    78,     0,     0,    35,    36,    37,    38,    39,
       0,     0,     0,    40,    62,    63,    64,    65,    41,     0,
      35,    36,    37,    38,    39,    85,     0,     0,    40,     0,
       0,     0,     0,    41,    66,     0,     0,     0,    67,     0,
     121,     0,     0,     0,    68,    69,    70,    71,    72,    73,
      74,    62,    63,    64,    65,     0,     0,     0,     0,     0,
       0,   153,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    66,     0,     0,     0,    67,     0,    62,    63,    64,
      65,    68,    69,    70,    71,    72,    73,    74,     0,     0,
       0,     0,     0,     0,     0,     0,   135,    66,     0,     0,
       0,    67,     0,    62,    63,    64,    65,    68,    69,    70,
      71,    72,    73,    74,     0,     0,     0,     0,     0,     0,
       0,     0,   154,    66,     0,     0,     0,    67,    62,    63,
      64,    65,     0,    68,    69,    70,    71,    72,    73,    74,
       0,     0,     0,     0,     0,     0,   116,     0,    66,     0,
       0,     0,    67,    62,    63,    64,    65,     0,    68,    69,
      70,    71,    72,    73,    74,     0,     0,     0,     0,     0,
       0,   117,     0,    66,     0,     0,     0,    67,    62,    63,
      64,    65,     0,    68,    69,    70,    71,    72,    73,    74,
       0,     0,     0,     0,     0,     0,   118,     0,    66,     0,
       0,     0,    67,    62,    63,    64,    65,     0,    68,    69,
      70,    71,    72,    73,    74,     0,     0,     0,     0,     0,
       0,   119,     0,    66,     0,     0,     0,    67,    62,    63,
      64,    65,     0,    68,    69,    70,    71,    72,    73,    74,
       0,     0,     0,     0,     0,     0,   120,     0,    66,     0,
       0,     0,    67,    62,    63,    64,    65,     0,    68,    69,
      70,    71,    72,    73,    74,     0,     0,     0,     0,     0,
       0,   123,     0,    66,     0,     0,     0,    67,    62,    63,
      64,    65,     0,    68,    69,    70,    71,    72,    73,    74,
       0,     0,     0,     0,     0,     0,   136,     0,    66,     0,
       0,     0,    67,    62,    63,    64,    65,     0,    68,    69,
      70,    71,    72,    73,    74,     0,     0,     0,     0,     0,
       0,   150,     0,    66,     0,     0,     0,    67,    62,    63,
      64,    65,     0,    68,    69,    70,    71,    72,    73,    74,
       0,     0,     0,     0,     0,     0,   152,     0,    66,     0,
       0,     0,    67,    62,    63,    64,    65,     0,    68,    69,
      70,    71,    72,    73,    74,     0,     0,     0,    13,     0,
       0,     0,     0,    66,     0,     0,     0,    67,    62,    63,
      64,    65,     0,    68,    69,    70,    71,    72,    73,    74,
       0,     0,    97,     0,     0,     0,     0,     0,    66,     0,
       0,     0,    67,    62,    63,    64,    65,     0,    68,    69,
      70,    71,    72,    73,    74,     0,     0,   113,     0,     0,
       0,     0,     0,    66,     0,     0,     0,    67,    62,    63,
      64,    65,     0,    68,    69,    70,    71,    72,    73,    74,
       0,    66,   115,     0,     0,    67,    62,    63,    66,    65,
       0,     0,    67,    70,    71,    72,    73,    74,    68,    69,
      70,    71,    72,    73,    74,     0,    66,    62,    63,     0,
      67,     0,     0,     0,     0,     0,    68,    69,    70,    71,
      72,    73,    74,     0,     0,     0,     0,    66,     0,     0,
       0,    67,     0,     0,     0,     0,     0,    68,    69,    70,
      71,    72,    73,    74
};

static const yytype_int16 yycheck[] =
{
      19,    66,    42,    12,     6,     7,     8,     9,    34,    56,
       0,    58,    38,    56,    57,    56,    57,     5,     4,    52,
      39,    40,    41,    88,    61,    62,    45,    46,    47,    48,
      49,    50,    51,    52,    43,    44,     6,     7,     8,     9,
      10,    11,    30,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    42,    41,    60,    53,
       3,    63,     5,    54,    42,    52,    85,    52,    87,    39,
      40,    41,    42,    43,    39,    59,    58,    47,    24,    60,
      23,     6,    52,    26,    59,    28,    29,     9,    61,    59,
      60,    57,    59,    63,    18,    19,    20,    21,    22,    42,
      57,    57,    53,   112,     3,    57,     5,    57,    57,   128,
      57,    54,    55,     4,    24,    10,    11,    -1,   137,    34,
     139,   140,   141,    38,    23,    -1,    -1,    26,    -1,    28,
      29,    -1,    56,    48,    49,    50,    -1,   156,    10,    11,
      -1,    -1,    -1,    42,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    47,    10,    11,    54,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    -1,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    47,    10,    11,    -1,    -1,
      52,    -1,    39,    40,    41,    42,    43,    59,    -1,    -1,
      47,    10,    11,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    -1,    -1,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    47,    14,    15,    16,    17,    52,    -1,
      39,    40,    41,    42,    43,    59,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    52,    34,    -1,    -1,    -1,    38,    -1,
      59,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    38,    -1,    14,    15,    16,
      17,    44,    45,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    34,    -1,    -1,
      -1,    38,    -1,    14,    15,    16,    17,    44,    45,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    34,    -1,    -1,    -1,    38,    14,    15,
      16,    17,    -1,    44,    45,    46,    47,    48,    49,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    34,    -1,
      -1,    -1,    38,    14,    15,    16,    17,    -1,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    34,    -1,    -1,    -1,    38,    14,    15,
      16,    17,    -1,    44,    45,    46,    47,    48,    49,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    34,    -1,
      -1,    -1,    38,    14,    15,    16,    17,    -1,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    34,    -1,    -1,    -1,    38,    14,    15,
      16,    17,    -1,    44,    45,    46,    47,    48,    49,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    34,    -1,
      -1,    -1,    38,    14,    15,    16,    17,    -1,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    34,    -1,    -1,    -1,    38,    14,    15,
      16,    17,    -1,    44,    45,    46,    47,    48,    49,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    34,    -1,
      -1,    -1,    38,    14,    15,    16,    17,    -1,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    34,    -1,    -1,    -1,    38,    14,    15,
      16,    17,    -1,    44,    45,    46,    47,    48,    49,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    34,    -1,
      -1,    -1,    38,    14,    15,    16,    17,    -1,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    -1,    38,    14,    15,
      16,    17,    -1,    44,    45,    46,    47,    48,    49,    50,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    -1,    38,    14,    15,    16,    17,    -1,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    -1,    38,    14,    15,
      16,    17,    -1,    44,    45,    46,    47,    48,    49,    50,
      -1,    34,    53,    -1,    -1,    38,    14,    15,    34,    17,
      -1,    -1,    38,    46,    47,    48,    49,    50,    44,    45,
      46,    47,    48,    49,    50,    -1,    34,    14,    15,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    -1,    34,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    30,    65,    66,    67,    68,    42,     0,    67,
      52,    53,    69,    54,    70,    71,     3,     5,    23,    26,
      28,    29,    42,    70,    72,    73,    74,    75,    76,    77,
      78,     4,    42,    10,    11,    39,    40,    41,    42,    43,
      47,    52,    59,    80,    80,    52,    52,    18,    19,    20,
      21,    22,    56,    55,    73,    42,    58,    60,    80,    80,
      80,    59,    14,    15,    16,    17,    34,    38,    44,    45,
      46,    47,    48,    49,    50,    70,    70,    80,    59,    80,
      80,    80,    80,    80,    80,    59,    80,    56,    58,     6,
       7,     8,     9,    60,    63,    81,    39,    53,    80,    80,
      80,    80,    80,    81,    80,    80,    80,    80,    80,    80,
      80,    80,    24,    53,    41,    53,    57,    57,    57,    57,
      57,    59,    80,    57,    80,    81,     6,     9,    56,    57,
      61,    70,    57,    59,    57,    59,    57,    56,    57,    57,
      59,    60,    80,    53,    57,    80,    80,    80,    79,    80,
      57,    57,    57,    61,    59,    61,    62,    57,    57,    80
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    66,    66,    67,    67,    69,    68,    71,
      70,    72,    72,    73,    73,    73,    73,    73,    73,    73,
      74,    74,    74,    74,    74,    74,    74,    75,    75,    76,
      77,    77,    77,    77,    77,    77,    77,    78,    78,    78,
      79,    79,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    81,    81,    81,
      81,    81,    81
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     0,     6,     0,
       4,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       6,     6,     8,     7,     5,     9,     9,     3,     5,     3,
       4,     6,     4,     4,     4,     4,     4,     5,     5,     7,
       1,     3,     1,     1,     1,     1,     1,     4,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     2,     3,     1,     1,     1,
       1,     2,     5
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 7: /* $@1: %empty  */
#line 111 "compiler.y"
                      {
        printf("func: %s\n", (yyvsp[-2].s_val));
        insert_symbol((yyvsp[-2].s_val), addr, scope);
      }
#line 1802 "y.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 118 "compiler.y"
          {
        scope++;
        scope_count++;
        create_symbol();
      }
#line 1812 "y.tab.c"
    break;

  case 10: /* BlockStmt: '{' $@2 StatementList '}'  */
#line 122 "compiler.y"
                          {
        dump_symbol();
        scope--;
        for (int i = 0; i < symbol_count; i++){
            if(symbol_table[i].scope > scope)
                symbol_count = i;
        }
      }
#line 1825 "y.tab.c"
    break;

  case 20: /* VarDeclStmt: LET MUT ID '=' Expression ';'  */
#line 148 "compiler.y"
                                   {
        ++addr;
        symbol_table[symbol_count].name = (yyvsp[-3].s_val);
        symbol_table[symbol_count].type = (yyvsp[-1].s_val);
        symbol_table[symbol_count].mut = 1;
        symbol_table[symbol_count].scope = scope;
        symbol_table[symbol_count].addr = addr;
        symbol_table[symbol_count].line_no = yylineno + 1;
        insert_symbol((yyvsp[-3].s_val), addr, scope);
        ++symbol_count;
    }
#line 1841 "y.tab.c"
    break;

  case 21: /* VarDeclStmt: LET MUT ID ':' Type ';'  */
#line 159 "compiler.y"
                              {
        ++addr;
        symbol_table[symbol_count].name = (yyvsp[-3].s_val);
        symbol_table[symbol_count].type = (yyvsp[-1].s_val);
        symbol_table[symbol_count].mut = 1;
        symbol_table[symbol_count].scope = scope;
        symbol_table[symbol_count].addr = addr;
        symbol_table[symbol_count].line_no = yylineno + 1;
        insert_symbol((yyvsp[-3].s_val), addr, scope);
        ++symbol_count;
    }
#line 1857 "y.tab.c"
    break;

  case 22: /* VarDeclStmt: LET MUT ID ':' Type '=' Expression ';'  */
#line 170 "compiler.y"
                                             {
        ++addr;
        symbol_table[symbol_count].name = (yyvsp[-5].s_val);
        symbol_table[symbol_count].type = (yyvsp[-3].s_val);
        symbol_table[symbol_count].mut = 1;
        symbol_table[symbol_count].scope = scope;
        symbol_table[symbol_count].addr = addr;
        symbol_table[symbol_count].line_no = yylineno + 1;
        insert_symbol((yyvsp[-5].s_val), addr, scope);
        ++symbol_count;
    }
#line 1873 "y.tab.c"
    break;

  case 23: /* VarDeclStmt: LET ID ':' Type '=' Expression ';'  */
#line 181 "compiler.y"
                                         {
        ++addr;
        symbol_table[symbol_count].name = (yyvsp[-5].s_val);
        symbol_table[symbol_count].type = (yyvsp[-3].s_val);
        symbol_table[symbol_count].mut = 0;
        symbol_table[symbol_count].scope = scope;
        symbol_table[symbol_count].addr = addr;
        symbol_table[symbol_count].line_no = yylineno + 1;
        insert_symbol((yyvsp[-5].s_val), addr, scope);
        ++symbol_count;
    }
#line 1889 "y.tab.c"
    break;

  case 24: /* VarDeclStmt: LET ID ':' Type ';'  */
#line 192 "compiler.y"
                          {
        ++addr;
        symbol_table[symbol_count].name = (yyvsp[-3].s_val);
        symbol_table[symbol_count].type = (yyvsp[-1].s_val);
        symbol_table[symbol_count].mut = 0;
        symbol_table[symbol_count].scope = scope;
        symbol_table[symbol_count].addr = addr;
        symbol_table[symbol_count].line_no = yylineno + 1;
        insert_symbol((yyvsp[-3].s_val), addr, scope);
        ++symbol_count;
    }
#line 1905 "y.tab.c"
    break;

  case 25: /* VarDeclStmt: LET ID ':' Type '=' '"' Expression '"' ';'  */
#line 203 "compiler.y"
                                                 {
        ++addr;
        symbol_table[symbol_count].name = (yyvsp[-7].s_val);
        symbol_table[symbol_count].type = (yyvsp[-5].s_val);
        symbol_table[symbol_count].mut = 0;
        symbol_table[symbol_count].scope = scope;
        symbol_table[symbol_count].addr = addr;
        symbol_table[symbol_count].line_no = yylineno + 1;
        insert_symbol((yyvsp[-7].s_val), addr, scope);
        ++symbol_count;
    }
#line 1921 "y.tab.c"
    break;

  case 26: /* VarDeclStmt: LET ID ':' Type '=' '[' ExpressionList ']' ';'  */
#line 214 "compiler.y"
                                                    {
        ++addr;
        symbol_table[symbol_count].name = (yyvsp[-7].s_val);
        symbol_table[symbol_count].type = (yyvsp[-5].s_val);
        symbol_table[symbol_count].mut = 0;
        symbol_table[symbol_count].scope = scope;
        symbol_table[symbol_count].addr = addr;
        symbol_table[symbol_count].line_no = yylineno + 1;
        insert_symbol((yyvsp[-7].s_val), addr, scope);
        ++symbol_count;
    }
#line 1937 "y.tab.c"
    break;

  case 30: /* AssignmentStmt: ID '=' Expression ';'  */
#line 237 "compiler.y"
                            {
        int idx = lookup_symbol((yyvsp[-3].s_val));
        if (idx == -1) {
            printf("error:%d: undefined: %s\n", yylineno + 1, (yyvsp[-3].s_val));
        }else{
            printf("ASSIGN\n");

            if (symbol_table[idx].mut == 0) 
                printf("error:%d: cannot borrow immutable borrowed content `%s` as mutable\n", yylineno + 1, (yyvsp[-3].s_val));   
        } 
    }
#line 1953 "y.tab.c"
    break;

  case 31: /* AssignmentStmt: ID '=' '"' Expression '"' ';'  */
#line 248 "compiler.y"
                                    {
        printf("ASSIGN\n");
    }
#line 1961 "y.tab.c"
    break;

  case 32: /* AssignmentStmt: ID ADD_ASSIGN Expression ';'  */
#line 251 "compiler.y"
                                   {
        printf("ADD_ASSIGN\n");
    }
#line 1969 "y.tab.c"
    break;

  case 33: /* AssignmentStmt: ID SUB_ASSIGN Expression ';'  */
#line 254 "compiler.y"
                                   {
        printf("SUB_ASSIGN\n");
    }
#line 1977 "y.tab.c"
    break;

  case 34: /* AssignmentStmt: ID MUL_ASSIGN Expression ';'  */
#line 257 "compiler.y"
                                   {
        printf("MUL_ASSIGN\n");
    }
#line 1985 "y.tab.c"
    break;

  case 35: /* AssignmentStmt: ID DIV_ASSIGN Expression ';'  */
#line 260 "compiler.y"
                                   {
        printf("DIV_ASSIGN\n");
    }
#line 1993 "y.tab.c"
    break;

  case 36: /* AssignmentStmt: ID REM_ASSIGN Expression ';'  */
#line 263 "compiler.y"
                                   {
        printf("REM_ASSIGN\n");
    }
#line 2001 "y.tab.c"
    break;

  case 37: /* PrintStmt: PRINTLN '(' Expression ')' ';'  */
#line 269 "compiler.y"
                                     {
        if (strcmp((yyvsp[-2].s_val), "i32") == 0)
            printf("PRINTLN i32\n");
        else if (strcmp((yyvsp[-2].s_val), "f32") == 0)
            printf("PRINTLN f32\n");
        else if (strcmp((yyvsp[-2].s_val), "bool") == 0)
            printf("PRINTLN bool\n");
        else if(strcmp((yyvsp[-2].s_val), "str") == 0)
            printf("PRINTLN str\n");
        else if(strcmp((yyvsp[-2].s_val), "array") == 0)
            printf("PRINTLN array\n");
    }
#line 2018 "y.tab.c"
    break;

  case 38: /* PrintStmt: PRINT '(' Expression ')' ';'  */
#line 281 "compiler.y"
                                   {
        if (strcmp((yyvsp[-2].s_val), "i32") == 0)
            printf("PRINT i32\n");
        else if (strcmp((yyvsp[-2].s_val), "f32") == 0)
            printf("PRINT f32\n");
        else if (strcmp((yyvsp[-2].s_val), "bool") == 0)
            printf("PRINT bool\n");
        else if(strcmp((yyvsp[-2].s_val), "str"))
            printf("PRINT str\n");
        else if(strcmp((yyvsp[-2].s_val), "array") == 0)
            printf("PRINTLN array\n");
    }
#line 2035 "y.tab.c"
    break;

  case 39: /* PrintStmt: PRINTLN '(' '"' STRING_LIT '"' ')' ';'  */
#line 293 "compiler.y"
                                             {
        printf("STRING_LIT \"%s\"\n", (yyvsp[-3].s_val));
        printf("PRINTLN str\n");
    }
#line 2044 "y.tab.c"
    break;

  case 42: /* Expression: INT_LIT  */
#line 305 "compiler.y"
              {
        printf("INT_LIT %d\n", (yyvsp[0].i_val));
        (yyval.s_val) = "i32";
    }
#line 2053 "y.tab.c"
    break;

  case 43: /* Expression: FLOAT_LIT  */
#line 309 "compiler.y"
                {
        printf("FLOAT_LIT %f\n", (yyvsp[0].f_val));
        (yyval.s_val) = "f32";
    }
#line 2062 "y.tab.c"
    break;

  case 44: /* Expression: TRUE  */
#line 313 "compiler.y"
           {
        printf("bool TRUE\n");
        (yyval.s_val) = "bool";
    }
#line 2071 "y.tab.c"
    break;

  case 45: /* Expression: FALSE  */
#line 317 "compiler.y"
            {
        printf("bool FALSE\n");
        (yyval.s_val) = "bool";
    }
#line 2080 "y.tab.c"
    break;

  case 46: /* Expression: ID  */
#line 321 "compiler.y"
         {
        int idx = lookup_symbol((yyvsp[0].s_val));
        if (idx == -1) {
            printf("error:%d: undefined: %s\n", yylineno + 1, (yyvsp[0].s_val));
            (yyval.s_val) = "undefined";
        } else {
            printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].s_val), symbol_table[idx].addr);  
            (yyval.s_val) = symbol_table[idx].type;
        }
    }
#line 2095 "y.tab.c"
    break;

  case 47: /* Expression: ID '[' INT_LIT ']'  */
#line 331 "compiler.y"
                        {
        int idx = lookup_symbol((yyvsp[-3].s_val));
        printf("IDENT (name=%s, address=%d)\n", (yyvsp[-3].s_val), symbol_table[idx].addr);  
        printf("INT_LIT %d\n", (yyvsp[-1].i_val));
        (yyval.s_val) = "array";
    }
#line 2106 "y.tab.c"
    break;

  case 48: /* Expression: '-' Expression  */
#line 337 "compiler.y"
                                  {
        printf("NEG\n");
        (yyval.s_val) = (yyvsp[0].s_val);
    }
#line 2115 "y.tab.c"
    break;

  case 49: /* Expression: '!' Expression  */
#line 341 "compiler.y"
                     {
        printf("NOT\n");
        (yyval.s_val) = "bool";
    }
#line 2124 "y.tab.c"
    break;

  case 50: /* Expression: Expression AS Expression  */
#line 345 "compiler.y"
                               {
        printf("AS\n");
        (yyval.s_val) = "as";
    }
#line 2133 "y.tab.c"
    break;

  case 51: /* Expression: Expression '+' Expression  */
#line 349 "compiler.y"
                                {
        printf("ADD\n");
        (yyval.s_val) = (strcmp((yyvsp[-2].s_val), "f32") == 0 || strcmp((yyvsp[0].s_val), "f32") == 0) ? "f32" : "i32";
    }
#line 2142 "y.tab.c"
    break;

  case 52: /* Expression: Expression '-' Expression  */
#line 353 "compiler.y"
                                {
        printf("SUB\n");
        (yyval.s_val) = (strcmp((yyvsp[-2].s_val), "f32") == 0 || strcmp((yyvsp[0].s_val), "f32") == 0) ? "f32" : "i32";
    }
#line 2151 "y.tab.c"
    break;

  case 53: /* Expression: Expression '*' Expression  */
#line 357 "compiler.y"
                                {
        printf("MUL\n");
        (yyval.s_val) = (strcmp((yyvsp[-2].s_val), "f32") == 0 || strcmp((yyvsp[0].s_val), "f32") == 0) ? "f32" : "i32";
    }
#line 2160 "y.tab.c"
    break;

  case 54: /* Expression: Expression '/' Expression  */
#line 361 "compiler.y"
                                {
        printf("DIV\n");
        (yyval.s_val) = (strcmp((yyvsp[-2].s_val), "f32") == 0 || strcmp((yyvsp[0].s_val), "f32") == 0) ? "f32" : "i32";
    }
#line 2169 "y.tab.c"
    break;

  case 55: /* Expression: Expression '%' Expression  */
#line 365 "compiler.y"
                                {
        printf("REM\n");
        (yyval.s_val) = "i32";
    }
#line 2178 "y.tab.c"
    break;

  case 56: /* Expression: Expression '>' Expression  */
#line 369 "compiler.y"
                                {
        if (strcmp((yyvsp[-2].s_val), "undefined") == 0) {
            printf("error:%d: invalid operation: GTR (mismatched types %s and %s)\n", yylineno + 1, (yyvsp[-2].s_val), (yyvsp[0].s_val));
        }

        printf("GTR\n");
        (yyval.s_val) = "bool";
    }
#line 2191 "y.tab.c"
    break;

  case 57: /* Expression: Expression '<' Expression  */
#line 377 "compiler.y"
                                {
        printf("LSS\n");
        (yyval.s_val) = "bool";
    }
#line 2200 "y.tab.c"
    break;

  case 58: /* Expression: Expression LSHIFT Expression  */
#line 381 "compiler.y"
                                   {
        if (strcmp((yyvsp[-2].s_val), (yyvsp[0].s_val)) != 0) {
            printf("error:%d: invalid operation: LSHIFT (mismatched types %s and %s)\n", yylineno + 1, (yyvsp[-2].s_val), (yyvsp[0].s_val));
        }
        printf("LSHIFT\n");
        (yyval.s_val) = "lshift";
    }
#line 2212 "y.tab.c"
    break;

  case 59: /* Expression: Expression EQL Expression  */
#line 388 "compiler.y"
                                {
        printf("EQL\n");
        (yyval.s_val) = "eql";
    }
#line 2221 "y.tab.c"
    break;

  case 60: /* Expression: Expression NEQ Expression  */
#line 392 "compiler.y"
                                {
        printf("NEQ\n");
        (yyval.s_val) = "neq";
    }
#line 2230 "y.tab.c"
    break;

  case 61: /* Expression: Expression LAND Expression  */
#line 396 "compiler.y"
                                 {
        printf("LAND\n");
        (yyval.s_val) = "bool";
    }
#line 2239 "y.tab.c"
    break;

  case 62: /* Expression: Expression LOR Expression  */
#line 400 "compiler.y"
                                {
        printf("LOR\n");
        (yyval.s_val) = "bool";
    }
#line 2248 "y.tab.c"
    break;

  case 63: /* Expression: '(' Expression ')'  */
#line 404 "compiler.y"
                         {
        (yyval.s_val) = (yyvsp[-1].s_val);
    }
#line 2256 "y.tab.c"
    break;

  case 64: /* Expression: STRING_LIT  */
#line 407 "compiler.y"
                 {
        printf("STRING_LIT \"%s\"\n", (yyvsp[0].s_val));
        (yyval.s_val) = "str";
    }
#line 2265 "y.tab.c"
    break;

  case 65: /* Expression: '"' '"'  */
#line 411 "compiler.y"
             {
        printf("STRING_LIT \"\"\n");
        (yyval.s_val) = "str";
    }
#line 2274 "y.tab.c"
    break;

  case 66: /* Expression: Expression AS Type  */
#line 415 "compiler.y"
                         {
        if (strcmp((yyvsp[-2].s_val), "f32") == 0 && strcmp((yyvsp[0].s_val), "i32") == 0) {
            printf("f2i\n");
            (yyval.s_val) = "i32";
        } else if (strcmp((yyvsp[-2].s_val), "i32") == 0 && strcmp((yyvsp[0].s_val), "f32") == 0) {
            printf("i2f\n");
            (yyval.s_val) = "f32";
        } else {
            (yyval.s_val) = (yyvsp[0].s_val);
        }
    }
#line 2290 "y.tab.c"
    break;

  case 67: /* Type: INT  */
#line 430 "compiler.y"
            { (yyval.s_val) = "i32"; }
#line 2296 "y.tab.c"
    break;

  case 68: /* Type: FLOAT  */
#line 431 "compiler.y"
            { (yyval.s_val) = "f32"; }
#line 2302 "y.tab.c"
    break;

  case 69: /* Type: BOOL  */
#line 432 "compiler.y"
            { (yyval.s_val) = "bool"; }
#line 2308 "y.tab.c"
    break;

  case 70: /* Type: STR  */
#line 433 "compiler.y"
            { (yyval.s_val) = "string"; }
#line 2314 "y.tab.c"
    break;

  case 71: /* Type: '&' STR  */
#line 434 "compiler.y"
              { (yyval.s_val) = "str"; }
#line 2320 "y.tab.c"
    break;

  case 72: /* Type: '[' INT ';' Expression ']'  */
#line 435 "compiler.y"
                                 {(yyval.s_val) = "array"; }
#line 2326 "y.tab.c"
    break;


#line 2330 "y.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 437 "compiler.y"


/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    yylineno = 0;
    create_symbol();
    yyparse();
    dump_symbol();

	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    return 0;
}

static void create_symbol() {
    printf("> Create symbol table (scope level %d)\n", scope);
}

static void insert_symbol(const char* name, int addr, int _scope) {
    printf("> Insert `%s` (addr: %d) to scope level %d\n", name, addr, _scope);
}

static int lookup_symbol(const char* name) {
    for (int i = symbol_count - 1; i >= 0; i--) {
        if (symbol_table[i].scope <= scope && strcmp(symbol_table[i].name, name) == 0 ) {
            return i;
        }   
    }
    return -1;
}

static void dump_symbol() {
    printf("\n> Dump symbol table (scope level: %d)\n", scope);
    printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n",
           "Index", "Name", "Mut", "Type", "Addr", "Lineno", "Func_sig");

    int index = 0;
    for (int i = 0; i < symbol_count; i++) {
        if (symbol_table[i].scope == scope) {
            printf("%-10d%-10s%-10d%-10s%-10d%-10d%-10s\n",
                   index,
                   symbol_table[i].name,
                   symbol_table[i].mut,                      
                   symbol_table[i].type,
                   symbol_table[i].addr,                     
                   symbol_table[i].line_no,
                   "-");                     // 非函式填 "-"
            index++;
        }
        
    }

    if (scope == 0) {
        printf("%-10d%-10s%-10d%-10s%-10d%-10d%-10s\n",
               0, "main", -1, "func", -1, 1, "(V)V");
    }
}
