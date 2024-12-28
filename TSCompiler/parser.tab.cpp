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
#define YYSKELETON_NAME "./bison.m4"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <cstdio>
#include <iostream>

#include "Utils/utils.h"
#include "Tree/ts_script.h"

int debug = 1;
extern FILE* yyin;
extern TSScriptNode* root;

extern char* yytext_ptr;
extern int yyleng;

extern void rescanTokenString(const char *s);
extern void doWhileASI();
extern int yylex();

void yyerror(const char *s);
int yyfilter(int yychar, int yyn, int yystate, short *yyssp);

int isASIActivated = 0;
int isInFunctionBody = 0; // need for return stmt
int isInForHeader = 0;

int syntaxErrorCounter = 0;

#line 99 "parser.tab.cpp"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ENDL = 3,                       /* ENDL  */
  YYSYMBOL_VAR = 4,                        /* VAR  */
  YYSYMBOL_LET = 5,                        /* LET  */
  YYSYMBOL_CONST = 6,                      /* CONST  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_FUNCTION = 9,                   /* FUNCTION  */
  YYSYMBOL_CLASS = 10,                     /* CLASS  */
  YYSYMBOL_EXTENDS = 11,                   /* EXTENDS  */
  YYSYMBOL_GET = 12,                       /* GET  */
  YYSYMBOL_SET = 13,                       /* SET  */
  YYSYMBOL_DO = 14,                        /* DO  */
  YYSYMBOL_WHILE = 15,                     /* WHILE  */
  YYSYMBOL_FOR = 16,                       /* FOR  */
  YYSYMBOL_RETURN = 17,                    /* RETURN  */
  YYSYMBOL_SUPER = 18,                     /* SUPER  */
  YYSYMBOL_THIS = 19,                      /* THIS  */
  YYSYMBOL_NEW = 20,                       /* NEW  */
  YYSYMBOL_ASYNC = 21,                     /* ASYNC  */
  YYSYMBOL_AS = 22,                        /* AS  */
  YYSYMBOL_FROM = 23,                      /* FROM  */
  YYSYMBOL_YIELD = 24,                     /* YIELD  */
  YYSYMBOL_KEYOF = 25,                     /* KEYOF  */
  YYSYMBOL_CONSTRUCTOR = 26,               /* CONSTRUCTOR  */
  YYSYMBOL_NAMESPACE = 27,                 /* NAMESPACE  */
  YYSYMBOL_ABSTRACT = 28,                  /* ABSTRACT  */
  YYSYMBOL_REQUIRE = 29,                   /* REQUIRE  */
  YYSYMBOL_ANY = 30,                       /* ANY  */
  YYSYMBOL_NUMBER = 31,                    /* NUMBER  */
  YYSYMBOL_BOOLEAN = 32,                   /* BOOLEAN  */
  YYSYMBOL_STRING = 33,                    /* STRING  */
  YYSYMBOL_NEVER = 34,                     /* NEVER  */
  YYSYMBOL_UNDEFINED = 35,                 /* UNDEFINED  */
  YYSYMBOL_UNIQUE = 36,                    /* UNIQUE  */
  YYSYMBOL_SYMBOL = 37,                    /* SYMBOL  */
  YYSYMBOL_OBJECT = 38,                    /* OBJECT  */
  YYSYMBOL_VOID = 39,                      /* VOID  */
  YYSYMBOL_NULL_KW = 40,                   /* NULL_KW  */
  YYSYMBOL_TRUE_KW = 41,                   /* TRUE_KW  */
  YYSYMBOL_FALSE_KW = 42,                  /* FALSE_KW  */
  YYSYMBOL_TEMPLATE_LIT = 43,              /* TEMPLATE_LIT  */
  YYSYMBOL_STRING_LIT = 44,                /* STRING_LIT  */
  YYSYMBOL_INT_LIT = 45,                   /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 46,                 /* FLOAT_LIT  */
  YYSYMBOL_ID = 47,                        /* ID  */
  YYSYMBOL_OPERATOR_INCREMENT = 48,        /* OPERATOR_INCREMENT  */
  YYSYMBOL_OPERATOR_DECREMENT = 49,        /* OPERATOR_DECREMENT  */
  YYSYMBOL_ENDL_OPERATOR_INCREMENT = 50,   /* ENDL_OPERATOR_INCREMENT  */
  YYSYMBOL_ENDL_OPERATOR_DECREMENT = 51,   /* ENDL_OPERATOR_DECREMENT  */
  YYSYMBOL_IF_ONLY_PREC = 52,              /* IF_ONLY_PREC  */
  YYSYMBOL_53_ = 53,                       /* ','  */
  YYSYMBOL_COMMA_OPERATOR = 54,            /* COMMA_OPERATOR  */
  YYSYMBOL_COMMA_SEPARATOR = 55,           /* COMMA_SEPARATOR  */
  YYSYMBOL_56_ = 56,                       /* '='  */
  YYSYMBOL_OPERATOR_ASSIGN_PLUS = 57,      /* OPERATOR_ASSIGN_PLUS  */
  YYSYMBOL_OPERATOR_ASSIGN_MINUS = 58,     /* OPERATOR_ASSIGN_MINUS  */
  YYSYMBOL_OPERATOR_ASSIGN_MULTIPLY = 59,  /* OPERATOR_ASSIGN_MULTIPLY  */
  YYSYMBOL_OPERATOR_ASSIGN_DIVIDE = 60,    /* OPERATOR_ASSIGN_DIVIDE  */
  YYSYMBOL_OPERATOR_ASSIGN_LOGICAL_AND = 61, /* OPERATOR_ASSIGN_LOGICAL_AND  */
  YYSYMBOL_OPERATOR_ASSIGN_LOGICAL_OR = 62, /* OPERATOR_ASSIGN_LOGICAL_OR  */
  YYSYMBOL_63_ = 63,                       /* '?'  */
  YYSYMBOL_64_ = 64,                       /* ':'  */
  YYSYMBOL_OPERATOR_LOGICAL_OR = 65,       /* OPERATOR_LOGICAL_OR  */
  YYSYMBOL_OPERATOR_LOGICAL_AND = 66,      /* OPERATOR_LOGICAL_AND  */
  YYSYMBOL_67_ = 67,                       /* '|'  */
  YYSYMBOL_68_ = 68,                       /* '^'  */
  YYSYMBOL_69_ = 69,                       /* '&'  */
  YYSYMBOL_OPERATOR_EQUAL = 70,            /* OPERATOR_EQUAL  */
  YYSYMBOL_OPERATOR_NOT_EQUAL = 71,        /* OPERATOR_NOT_EQUAL  */
  YYSYMBOL_OPERATOR_STRICT_EQUAL = 72,     /* OPERATOR_STRICT_EQUAL  */
  YYSYMBOL_OPERATOR_STRICT_NOT_EQUAL = 73, /* OPERATOR_STRICT_NOT_EQUAL  */
  YYSYMBOL_74_ = 74,                       /* '>'  */
  YYSYMBOL_75_ = 75,                       /* '<'  */
  YYSYMBOL_OPERATOR_GREATER_THAN_EQUAL = 76, /* OPERATOR_GREATER_THAN_EQUAL  */
  YYSYMBOL_OPERATOR_LESS_THAN_EQUAL = 77,  /* OPERATOR_LESS_THAN_EQUAL  */
  YYSYMBOL_INSTANCEOF = 78,                /* INSTANCEOF  */
  YYSYMBOL_IN = 79,                        /* IN  */
  YYSYMBOL_80_ = 80,                       /* '+'  */
  YYSYMBOL_81_ = 81,                       /* '-'  */
  YYSYMBOL_82_ = 82,                       /* '*'  */
  YYSYMBOL_83_ = 83,                       /* '/'  */
  YYSYMBOL_84_ = 84,                       /* '%'  */
  YYSYMBOL_85_ = 85,                       /* '!'  */
  YYSYMBOL_86_ = 86,                       /* '~'  */
  YYSYMBOL_UMINUS = 87,                    /* UMINUS  */
  YYSYMBOL_UPLUS = 88,                     /* UPLUS  */
  YYSYMBOL_PREF_INCREMENT = 89,            /* PREF_INCREMENT  */
  YYSYMBOL_PREF_DECREMENT = 90,            /* PREF_DECREMENT  */
  YYSYMBOL_POST_INCREMENT = 91,            /* POST_INCREMENT  */
  YYSYMBOL_POST_DECREMENT = 92,            /* POST_DECREMENT  */
  YYSYMBOL_93_ = 93,                       /* '.'  */
  YYSYMBOL_94_ = 94,                       /* '['  */
  YYSYMBOL_95_ = 95,                       /* ']'  */
  YYSYMBOL_ENDL_BRACKET_OPEN = 96,         /* ENDL_BRACKET_OPEN  */
  YYSYMBOL_97_ = 97,                       /* '('  */
  YYSYMBOL_98_ = 98,                       /* ')'  */
  YYSYMBOL_99_ = 99,                       /* ';'  */
  YYSYMBOL_100_ = 100,                     /* '{'  */
  YYSYMBOL_101_ = 101,                     /* '}'  */
  YYSYMBOL_YYACCEPT = 102,                 /* $accept  */
  YYSYMBOL_script = 103,                   /* script  */
  YYSYMBOL_scriptElementList = 104,        /* scriptElementList  */
  YYSYMBOL_scriptElement = 105,            /* scriptElement  */
  YYSYMBOL_statementList = 106,            /* statementList  */
  YYSYMBOL_statementListItem = 107,        /* statementListItem  */
  YYSYMBOL_statementListItemWithoutEmptyStatement = 108, /* statementListItemWithoutEmptyStatement  */
  YYSYMBOL_emptyStatement = 109,           /* emptyStatement  */
  YYSYMBOL_blockStatement = 110,           /* blockStatement  */
  YYSYMBOL_type = 111,                     /* type  */
  YYSYMBOL_predefinedType = 112,           /* predefinedType  */
  YYSYMBOL_typeAnnotationOpt = 113,        /* typeAnnotationOpt  */
  YYSYMBOL_typeAnnotation = 114,           /* typeAnnotation  */
  YYSYMBOL_arrayLiteral = 115,             /* arrayLiteral  */
  YYSYMBOL_elementList = 116,              /* elementList  */
  YYSYMBOL_elementListItem = 117,          /* elementListItem  */
  YYSYMBOL_expressionStatement = 118,      /* expressionStatement  */
  YYSYMBOL_singleExpressionOpt = 119,      /* singleExpressionOpt  */
  YYSYMBOL_singleExpression = 120,         /* singleExpression  */
  YYSYMBOL_varStatement = 121,             /* varStatement  */
  YYSYMBOL_varDeclarationList = 122,       /* varDeclarationList  */
  YYSYMBOL_varDeclaration = 123,           /* varDeclaration  */
  YYSYMBOL_varModifier = 124,              /* varModifier  */
  YYSYMBOL_ifStatement = 125,              /* ifStatement  */
  YYSYMBOL_iterationStatement = 126,       /* iterationStatement  */
  YYSYMBOL_127_1 = 127,                    /* $@1  */
  YYSYMBOL_128_2 = 128,                    /* $@2  */
  YYSYMBOL_129_3 = 129,                    /* $@3  */
  YYSYMBOL_130_4 = 130,                    /* $@4  */
  YYSYMBOL_131_5 = 131,                    /* $@5  */
  YYSYMBOL_forHeader = 132,                /* forHeader  */
  YYSYMBOL_returnStatement = 133,          /* returnStatement  */
  YYSYMBOL_functionDeclaration = 134,      /* functionDeclaration  */
  YYSYMBOL_functionBody = 135,             /* functionBody  */
  YYSYMBOL_136_6 = 136,                    /* $@6  */
  YYSYMBOL_parameterList = 137,            /* parameterList  */
  YYSYMBOL_requiredParameterList = 138,    /* requiredParameterList  */
  YYSYMBOL_requiredParameter = 139,        /* requiredParameter  */
  YYSYMBOL_classDeclaration = 140,         /* classDeclaration  */
  YYSYMBOL_classHeritage = 141,            /* classHeritage  */
  YYSYMBOL_classTail = 142,                /* classTail  */
  YYSYMBOL_classElementList = 143,         /* classElementList  */
  YYSYMBOL_classElement = 144,             /* classElement  */
  YYSYMBOL_propertyName = 145,             /* propertyName  */
  YYSYMBOL_identifier = 146                /* identifier  */
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
typedef yytype_int16 yy_state_t;

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  95
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2748

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  102
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  176
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  321

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   332


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
       2,     2,     2,    85,     2,     2,     2,    84,    69,     2,
      97,    98,    82,    80,    53,    81,    93,    83,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    64,    99,
      75,    56,    74,    63,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    94,     2,    95,    68,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   100,    67,   101,    86,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    54,    55,
      57,    58,    59,    60,    61,    62,    65,    66,    70,    71,
      72,    73,    76,    77,    78,    79,    87,    88,    89,    90,
      91,    92,    96
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   162,   162,   173,   175,   180,   181,   182,   183,   187,
     188,   192,   193,   194,   195,   196,   197,   204,   208,   209,
     210,   211,   212,   219,   221,   225,   237,   238,   244,   245,
     249,   250,   251,   252,   253,   254,   255,   259,   260,   264,
     269,   271,   276,   278,   283,   284,   285,   296,   300,   301,
     305,   306,   307,   308,   309,   310,   312,   313,   314,   315,
     317,   319,   322,   325,   327,   330,   332,   334,   336,   339,
     341,   343,   345,   347,   349,   352,   354,   356,   358,   360,
     362,   365,   367,   369,   371,   373,   375,   377,   380,   382,
     385,   387,   390,   393,   396,   399,   401,   403,   407,   409,
     412,   416,   418,   420,   422,   425,   427,   429,   432,   434,
     436,   443,   444,   448,   450,   455,   457,   462,   463,   464,
     470,   476,   486,   486,   492,   498,   498,   504,   504,   510,
     510,   516,   516,   524,   530,   531,   535,   543,   544,   544,
     553,   554,   555,   559,   564,   572,   582,   587,   595,   599,
     600,   604,   605,   609,   616,   621,   628,   635,   640,   648,
     652,   653,   654,   655,   656,   657,   658,   659,   660,   661,
     662,   663,   664,   665,   666,   667,   668
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
  "\"end of file\"", "error", "\"invalid token\"", "ENDL", "VAR", "LET",
  "CONST", "IF", "ELSE", "FUNCTION", "CLASS", "EXTENDS", "GET", "SET",
  "DO", "WHILE", "FOR", "RETURN", "SUPER", "THIS", "NEW", "ASYNC", "AS",
  "FROM", "YIELD", "KEYOF", "CONSTRUCTOR", "NAMESPACE", "ABSTRACT",
  "REQUIRE", "ANY", "NUMBER", "BOOLEAN", "STRING", "NEVER", "UNDEFINED",
  "UNIQUE", "SYMBOL", "OBJECT", "VOID", "NULL_KW", "TRUE_KW", "FALSE_KW",
  "TEMPLATE_LIT", "STRING_LIT", "INT_LIT", "FLOAT_LIT", "ID",
  "OPERATOR_INCREMENT", "OPERATOR_DECREMENT", "ENDL_OPERATOR_INCREMENT",
  "ENDL_OPERATOR_DECREMENT", "IF_ONLY_PREC", "','", "COMMA_OPERATOR",
  "COMMA_SEPARATOR", "'='", "OPERATOR_ASSIGN_PLUS",
  "OPERATOR_ASSIGN_MINUS", "OPERATOR_ASSIGN_MULTIPLY",
  "OPERATOR_ASSIGN_DIVIDE", "OPERATOR_ASSIGN_LOGICAL_AND",
  "OPERATOR_ASSIGN_LOGICAL_OR", "'?'", "':'", "OPERATOR_LOGICAL_OR",
  "OPERATOR_LOGICAL_AND", "'|'", "'^'", "'&'", "OPERATOR_EQUAL",
  "OPERATOR_NOT_EQUAL", "OPERATOR_STRICT_EQUAL",
  "OPERATOR_STRICT_NOT_EQUAL", "'>'", "'<'", "OPERATOR_GREATER_THAN_EQUAL",
  "OPERATOR_LESS_THAN_EQUAL", "INSTANCEOF", "IN", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'!'", "'~'", "UMINUS", "UPLUS", "PREF_INCREMENT",
  "PREF_DECREMENT", "POST_INCREMENT", "POST_DECREMENT", "'.'", "'['",
  "']'", "ENDL_BRACKET_OPEN", "'('", "')'", "';'", "'{'", "'}'", "$accept",
  "script", "scriptElementList", "scriptElement", "statementList",
  "statementListItem", "statementListItemWithoutEmptyStatement",
  "emptyStatement", "blockStatement", "type", "predefinedType",
  "typeAnnotationOpt", "typeAnnotation", "arrayLiteral", "elementList",
  "elementListItem", "expressionStatement", "singleExpressionOpt",
  "singleExpression", "varStatement", "varDeclarationList",
  "varDeclaration", "varModifier", "ifStatement", "iterationStatement",
  "$@1", "$@2", "$@3", "$@4", "$@5", "forHeader", "returnStatement",
  "functionDeclaration", "functionBody", "$@6", "parameterList",
  "requiredParameterList", "requiredParameter", "classDeclaration",
  "classHeritage", "classTail", "classElementList", "classElement",
  "propertyName", "identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-286)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     404,  -286,  -286,  -286,  -286,   -91,   532,   532,   892,   -87,
     -85,  1090,   -80,  -286,   532,  -286,  -286,  -286,  -286,  -286,
    -286,  -286,  -286,  -286,  -286,  -286,  -286,  -286,  -286,  -286,
    -286,  -286,  -286,  -286,  -286,  -286,  -286,  -286,  -286,  -286,
    1739,  1739,  1739,  1739,  1739,  1739,  1739,  1739,  1739,  1739,
    -286,   598,    26,   307,  -286,  -286,  -286,  -286,  -286,  -286,
    1781,  -286,   208,  -286,  -286,   975,  -286,  -286,  -286,   -68,
    1739,   -43,    17,    31,  1739,  -286,  -286,  1830,  1172,   -36,
     -31,   -31,   -31,   -31,   -31,   -31,   -31,   -44,  -286,  2527,
     -42,  1928,  -286,   696,  -286,  -286,  -286,  -286,  -286,  1739,
    1739,  1739,  1739,  1739,  1739,  1739,  1739,  1739,  1739,  1739,
    1739,  1739,  1739,  1739,  1739,  1739,  1739,  1739,  1739,  1739,
    1739,  1739,  1739,  1739,   532,  1739,  1739,  -286,   -52,   -50,
    -286,     3,   -26,  2569,   532,  1253,  1979,   532,   532,  1015,
     -25,  -286,   -21,  2030,  -286,  -286,  2081,  1334,  1739,  -286,
    1739,  -286,  -286,  -286,  -286,    94,    94,    94,    94,    94,
      94,    94,    94,  2387,   394,   580,   674,   674,   674,   674,
     -24,   -24,   -24,   -24,   -24,   -24,   -69,   -69,   -31,   -31,
     -20,  2429,  2478,  -286,   532,  -286,    89,    22,  -286,  1739,
    1739,   -49,     0,  -286,  2132,   501,   -18,    28,  -286,     3,
    -286,   532,   532,   -15,  -286,  1052,  -286,   -57,  -286,  -286,
    1739,   892,  1415,  -286,  -286,  2183,  -286,  1739,  1496,  -286,
    -286,  -286,  -286,  -286,  -286,  -286,  -286,  -286,  -286,   -11,
    -286,  1739,   -13,  2611,   101,  1739,  1739,  1577,  -286,  -286,
      76,  -286,  -286,  -286,  -286,  -286,  -286,     3,   532,  -286,
      21,    29,   532,  -286,  -286,   532,   -51,  2234,  -286,  -286,
    -286,   297,  -286,  2285,    32,  2652,  1739,  -286,   -12,  2336,
    -286,   892,    23,  -286,    33,   532,    34,    36,  1739,  -286,
    -286,  1658,  -286,  -286,    37,   892,  1739,  -286,  -286,    40,
    -286,     3,    44,    23,     3,  1879,    45,  -286,  -286,  -286,
      47,   892,  -286,   892,    23,    23,  -286,    23,  -286,  -286,
     892,  -286,  -286,   794,  -286,  -286,  -286,  -286,   892,  -286,
    -286
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     8,   117,   118,   119,     0,     0,     0,     0,     0,
       0,     0,     0,    51,     0,   161,   162,   163,   164,   173,
     174,   175,   176,   165,   166,   167,   168,   171,    55,   169,
     170,   172,    54,    52,    53,    57,    56,    58,    59,   160,
       0,     0,     0,     0,     0,     0,     0,    44,    44,     0,
      25,     0,     0,     0,     3,     5,    11,    17,   105,    12,
       0,    13,     0,    14,    15,    48,    16,     6,     7,    50,
       0,     0,     0,     0,     0,   133,   134,     0,     0,   108,
      67,    68,    65,    66,    61,    60,    62,     0,    42,    45,
       0,     0,    26,     0,     9,     1,     4,    63,    64,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     0,     0,
     113,    37,     0,    49,     0,     0,     0,   140,     0,     0,
       0,   146,     0,     0,   135,    95,     0,     0,    44,    40,
      46,    41,    94,    27,    10,    93,    81,    84,    85,    82,
      83,    86,    87,     0,    88,    89,    75,    76,    77,    78,
      74,    73,    80,    79,    90,    91,    69,    70,    71,    72,
     101,     0,     0,   112,     0,   111,     0,   115,    38,    48,
       0,     0,   113,    98,     0,     0,     0,   141,   143,    37,
     148,     0,     0,     0,   149,     0,   151,    37,   159,   147,
       0,     0,     0,    96,   109,     0,    43,     0,     0,   106,
     107,   114,    30,    32,    31,    33,    34,    35,    36,    39,
      28,     0,     0,    49,    91,    48,     0,     0,    99,    24,
     120,    23,    18,    19,    20,    21,    22,    37,   142,   145,
       0,     0,   140,   150,   152,   140,     0,     0,   124,    97,
     110,    92,   102,     0,     0,   116,    48,   129,     0,     0,
     100,     0,     0,   144,     0,   140,     0,     0,     0,   154,
     122,     0,   103,    29,     0,     0,    48,   131,   121,   138,
     136,    37,     0,     0,    37,     0,     0,   104,   125,   130,
       0,     0,   137,     0,     0,     0,   153,     0,   155,   123,
       0,   127,   132,     0,   157,   158,   156,   126,     0,   139,
     128
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -286,  -286,  -286,    77,  -154,    -8,  -286,  -286,   -33,  -286,
    -286,  -133,  -286,  -286,   115,    30,    -9,  -147,   -10,    -6,
      51,  -132,   126,    -3,     1,  -286,  -286,  -286,  -286,  -286,
    -286,     6,  -286,  -285,  -286,  -234,  -286,   -35,  -286,  -286,
      58,  -286,    -1,  -157,     9
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    52,    53,    54,    93,    55,   240,    56,    57,   229,
     230,   187,   188,    58,    87,    88,    59,   132,    60,    61,
     129,   130,    62,    63,    64,   296,   310,   318,   285,   301,
      65,    66,    67,   290,   303,   196,   197,   198,    68,   140,
     141,   205,   206,   207,    69
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      73,    77,   192,   184,   184,   278,    70,   186,   306,   148,
      74,   148,    75,   122,   123,    71,    72,    78,   276,   314,
     315,   277,   316,    79,   124,   125,    95,   126,   138,   135,
      80,    81,    82,    83,    84,    85,    86,    89,    89,    91,
     255,   292,   232,    94,   250,   251,   142,   183,   279,   185,
     235,   149,   221,   151,   137,   133,   120,   121,   122,   123,
     136,   147,   124,   125,   143,   126,   249,   186,   146,   124,
     125,   131,   126,   189,   256,   139,   210,   218,   231,   236,
     247,   248,   252,   264,   271,   154,   266,   286,   268,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   272,   181,   182,   139,   274,   284,
     222,   223,   224,   289,   225,   194,   275,   283,   226,   227,
      96,   291,   293,   180,   294,   298,   228,   215,    89,   300,
     155,   302,   305,   131,   309,   311,   199,   200,   208,   313,
     100,   101,   102,   103,   104,   105,   106,   107,   304,   108,
     109,   307,   241,    90,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   216,   233,
     234,   120,   121,   122,   123,   191,   242,   124,   125,   243,
     126,   134,   244,   131,   124,   125,   245,   126,   209,   267,
     257,   246,   155,   258,   254,     0,     0,   261,   263,   128,
     208,   208,     0,   273,   208,     0,     0,     0,     0,     0,
       0,   265,     0,     0,     0,   233,   269,   155,     0,    15,
      16,    17,    18,    19,     0,    20,    21,    22,    23,    24,
      25,    26,    27,     0,    29,    30,    31,     0,     0,     0,
       0,     0,     0,     0,     0,    39,   233,   199,     0,     0,
       0,   199,     0,   288,   199,     0,     0,     0,   295,     0,
       0,   155,     0,     0,     0,     0,   233,   299,     0,     0,
       0,     0,     0,     0,   199,     0,     0,     0,     0,     0,
       0,     0,     0,   312,     0,    94,     0,     0,     0,     0,
       0,     0,   317,     0,     0,   154,     0,    -2,     1,     0,
     320,     2,     3,     4,     5,     0,     6,     7,     0,     0,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     0,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
       0,     0,   108,   109,     0,     0,     0,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,     0,     0,     0,     0,     0,     0,    44,    45,     0,
     124,   125,    46,   126,     0,     0,     0,     0,     0,     0,
       0,    47,     0,    48,    49,     1,    50,    51,     2,     3,
       4,     5,     0,     6,     7,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       0,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,     0,     0,     0,
     109,     0,     0,     0,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,     0,     0,
       0,     0,     0,     0,    44,    45,     0,   124,   125,    46,
     126,     0,     0,     0,     0,     0,     0,     0,    47,     0,
      48,    49,   239,    50,    51,     2,     3,     4,     5,     0,
       0,     0,     0,     0,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,     0,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    15,    16,    17,    18,    19,     0,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    29,    30,
      31,     0,     0,     0,     0,     0,     0,     0,     0,    39,
       0,    44,    45,     0,     0,     0,    46,     0,     0,     0,
       0,     0,     0,     0,     0,    47,     0,    48,    49,     0,
       0,    51,     2,     3,     4,     5,     0,     0,     0,     0,
       0,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,     0,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,   125,     0,   126,     0,    44,    45,
       0,     0,     0,    46,     0,     0,     0,     0,     0,     0,
       0,     0,    47,     0,    48,    49,     0,    50,    51,    92,
       2,     3,     4,     5,     0,     0,     0,     0,     0,     0,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     0,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   124,   125,     0,
     126,     0,     0,     0,     0,     0,    44,    45,     0,     0,
       0,    46,     0,     0,     0,     0,     0,     0,     0,     0,
      47,     0,    48,    49,     0,    50,    51,   153,     2,     3,
       4,     5,     0,     0,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       0,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,    45,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     0,
      48,    49,     0,    50,    51,   319,     2,     3,     4,     5,
       0,     0,     0,     0,     0,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     0,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,    45,     0,     0,     0,    46,     0,     2,
       3,     4,     0,     0,     0,     0,    47,     0,    48,    49,
       0,    50,    51,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,   201,   202,     0,
       0,     0,     0,     0,     0,     0,    15,    16,    17,    18,
      19,   203,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    29,    30,    31,     0,    44,    45,     0,     0,     0,
      46,     0,    39,     0,   201,   202,     0,     0,     0,    47,
       0,    48,    49,    15,    16,    17,    18,    19,   203,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    29,    30,
      31,     0,     0,     0,     0,     0,     0,     0,     0,    39,
       0,     0,     0,     0,     0,     0,     0,     0,    12,    13,
      14,    15,    16,    17,    18,    19,   204,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   253,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,    45,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     0,    48,    49,     0,    76,
      12,    13,    14,    15,    16,    17,    18,    19,     0,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,    45,     0,     0,     0,    46,     0,     0,
       0,     0,     0,     0,     0,     0,    47,     0,    48,    49,
     145,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,    45,     0,     0,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     0,    48,
      49,   193,    12,    13,    14,    15,    16,    17,    18,    19,
       0,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,    45,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     0,
      48,    49,   214,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    44,    45,     0,     0,     0,
      46,     0,     0,     0,     0,     0,     0,     0,     0,    47,
       0,    48,    49,   259,    12,    13,    14,    15,    16,    17,
      18,    19,     0,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    44,    45,     0,     0,
       0,    46,     0,     0,     0,     0,     0,     0,     0,     0,
      47,     0,    48,    49,   262,    12,    13,    14,    15,    16,
      17,    18,    19,     0,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,    45,     0,
       0,     0,    46,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,    48,    49,   270,    12,    13,    14,    15,
      16,    17,    18,    19,     0,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    44,    45,
       0,     0,     0,    46,     0,     0,     0,     0,     0,     0,
       0,     0,    47,     0,    48,    49,   297,    12,    13,    14,
      15,    16,    17,    18,    19,     0,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
      45,     0,     0,     0,    46,     0,     0,     0,     0,    97,
      98,     0,     0,    47,    99,    48,    49,   100,   101,   102,
     103,   104,   105,   106,   107,     0,   108,   109,     0,     0,
       0,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   124,   125,     0,   126,    97,    98,
     127,     0,     0,    99,     0,     0,   100,   101,   102,   103,
     104,   105,   106,   107,     0,   108,   109,     0,     0,     0,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,   125,     0,   126,    97,    98,   144,
       0,     0,    99,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   107,     0,   108,   109,     0,     0,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   124,   125,     0,   126,    97,    98,   308,     0,
       0,    99,     0,     0,   100,   101,   102,   103,   104,   105,
     106,   107,     0,   108,   109,     0,     0,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   124,   125,     0,   126,     0,   152,    97,    98,     0,
       0,     0,    99,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   107,     0,   108,   109,     0,     0,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   124,   125,     0,   126,     0,   195,    97,    98,
       0,     0,     0,    99,     0,     0,   100,   101,   102,   103,
     104,   105,   106,   107,     0,   108,   109,     0,     0,     0,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,   125,     0,   126,     0,   211,    97,
      98,     0,     0,     0,   212,     0,     0,   100,   101,   102,
     103,   104,   105,   106,   107,     0,   108,   109,     0,     0,
       0,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   124,   125,     0,   126,     0,   213,
      97,    98,     0,     0,     0,   237,     0,     0,   100,   101,
     102,   103,   104,   105,   106,   107,     0,   108,   109,     0,
       0,     0,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   124,   125,     0,   126,     0,
     238,    97,    98,     0,     0,     0,    99,     0,     0,   100,
     101,   102,   103,   104,   105,   106,   107,     0,   108,   109,
       0,     0,     0,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   124,   125,     0,   126,
       0,   260,    97,    98,     0,     0,     0,    99,     0,     0,
     100,   101,   102,   103,   104,   105,   106,   107,     0,   108,
     109,     0,     0,     0,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   124,   125,     0,
     126,     0,   280,    97,    98,     0,     0,     0,   281,     0,
       0,   100,   101,   102,   103,   104,   105,   106,   107,     0,
     108,   109,     0,     0,     0,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   124,   125,
       0,   126,     0,   282,    97,    98,     0,     0,     0,    99,
       0,     0,   100,   101,   102,   103,   104,   105,   106,   107,
       0,   108,   109,     0,     0,     0,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   124,
     125,     0,   126,     0,   287,    97,    98,     0,     0,     0,
      99,     0,     0,   100,   101,   102,   103,   104,   105,   106,
     107,   217,   108,   109,     0,     0,     0,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,     0,     0,     0,     0,     0,     0,    97,    98,     0,
     124,   125,    99,   126,     0,   100,   101,   102,   103,   104,
     105,   106,   107,     0,   108,   109,     0,     0,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   124,   125,   219,   126,    97,    98,     0,     0,
       0,    99,     0,     0,   100,   101,   102,   103,   104,   105,
     106,   107,     0,   108,   109,     0,     0,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   124,   125,   220,   126,    97,    98,     0,     0,     0,
     150,     0,     0,   100,   101,   102,   103,   104,   105,   106,
     107,     0,   108,   109,     0,     0,     0,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,     0,     0,     0,     0,     0,     0,    97,    98,     0,
     124,   125,    99,   126,     0,   100,   101,   102,   103,   104,
     105,   106,   107,     0,   108,   109,     0,     0,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   190,   120,
     121,   122,   123,     0,     0,     0,     0,     0,     0,    97,
      98,     0,   124,   125,    99,   126,     0,   100,   101,   102,
     103,   104,   105,   106,   107,     0,   108,   109,     0,     0,
       0,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,     0,     0,     0,     0,     0,
      97,    98,     0,     0,   124,   125,     0,   126,   100,   101,
     102,   103,   104,   105,   106,   107,     0,   108,   109,     0,
       0,     0,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   124,   125,     0,   126
};

static const yytype_int16 yycheck[] =
{
       8,    11,   134,    53,    53,    56,    97,    64,   293,    53,
      97,    53,    97,    82,    83,     6,     7,    97,   252,   304,
     305,   255,   307,    14,    93,    94,     0,    96,    11,    97,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      97,   275,   189,    51,   201,   202,    15,    99,    99,    99,
      99,    95,   184,    95,    97,    65,    80,    81,    82,    83,
      70,    97,    93,    94,    74,    96,   199,    64,    78,    93,
      94,    62,    96,    99,   207,   100,    97,    97,    56,    79,
      98,    53,    97,    94,     8,    93,    99,    99,   235,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   247,   125,   126,   100,    97,   266,
      31,    32,    33,   100,    35,   135,    97,    95,    39,    40,
      53,    98,    98,   124,    98,    98,    47,   147,   148,   286,
     150,   101,    98,   134,    99,    98,   137,   138,   139,   303,
      56,    57,    58,    59,    60,    61,    62,    63,   291,    65,
      66,   294,   195,    48,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,   148,   189,
     190,    80,    81,    82,    83,   134,   195,    93,    94,   195,
      96,    65,   195,   184,    93,    94,   195,    96,   140,    98,
     210,   195,   212,   211,   205,    -1,    -1,   217,   218,     1,
     201,   202,    -1,   248,   205,    -1,    -1,    -1,    -1,    -1,
      -1,   231,    -1,    -1,    -1,   235,   236,   237,    -1,    21,
      22,    23,    24,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,   266,   248,    -1,    -1,
      -1,   252,    -1,   271,   255,    -1,    -1,    -1,   278,    -1,
      -1,   281,    -1,    -1,    -1,    -1,   286,   285,    -1,    -1,
      -1,    -1,    -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   301,    -1,   303,    -1,    -1,    -1,    -1,
      -1,    -1,   310,    -1,    -1,   313,    -1,     0,     1,    -1,
     318,     4,     5,     6,     7,    -1,     9,    10,    -1,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      -1,    -1,    65,    66,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,
      93,    94,    85,    96,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    -1,    96,    97,     1,    99,   100,     4,     5,
       6,     7,    -1,     9,    10,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    81,    -1,    93,    94,    85,
      96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,
      96,    97,     1,    99,   100,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    21,    22,    23,    24,    25,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    80,    81,    -1,    -1,    -1,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    -1,    96,    97,    -1,
      -1,   100,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    -1,    96,    -1,    80,    81,
      -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    -1,    96,    97,    -1,    99,   100,   101,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    -1,
      96,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    -1,    96,    97,    -1,    99,   100,   101,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,
      96,    97,    -1,    99,   100,   101,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    81,    -1,    -1,    -1,    85,    -1,     4,
       5,     6,    -1,    -1,    -1,    -1,    94,    -1,    96,    97,
      -1,    99,   100,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    36,    37,    38,    -1,    80,    81,    -1,    -1,    -1,
      85,    -1,    47,    -1,    12,    13,    -1,    -1,    -1,    94,
      -1,    96,    97,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,   101,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    81,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    -1,    96,    97,    -1,    99,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    81,    -1,    -1,    -1,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    96,    97,
      98,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    96,
      97,    98,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,
      96,    97,    98,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      -1,    96,    97,    98,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    -1,    96,    97,    98,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,
      -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    -1,    96,    97,    98,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,
      -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    -1,    96,    97,    98,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      81,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    48,
      49,    -1,    -1,    94,    53,    96,    97,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    94,    -1,    96,    48,    49,
      99,    -1,    -1,    53,    -1,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    -1,    96,    48,    49,    99,
      -1,    -1,    53,    -1,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    -1,    96,    48,    49,    99,    -1,
      -1,    53,    -1,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    94,    -1,    96,    -1,    98,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    -1,    96,    -1,    98,    48,    49,
      -1,    -1,    -1,    53,    -1,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    -1,    96,    -1,    98,    48,
      49,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    94,    -1,    96,    -1,    98,
      48,    49,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    94,    -1,    96,    -1,
      98,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    65,    66,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    -1,    96,
      -1,    98,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    -1,
      96,    -1,    98,    48,    49,    -1,    -1,    -1,    53,    -1,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    66,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      -1,    96,    -1,    98,    48,    49,    -1,    -1,    -1,    53,
      -1,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      94,    -1,    96,    -1,    98,    48,    49,    -1,    -1,    -1,
      53,    -1,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,
      93,    94,    53,    96,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    95,    96,    48,    49,    -1,    -1,
      -1,    53,    -1,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    94,    95,    96,    48,    49,    -1,    -1,    -1,
      53,    -1,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,
      93,    94,    53,    96,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    -1,    93,    94,    53,    96,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      48,    49,    -1,    -1,    93,    94,    -1,    96,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    94,    -1,    96
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     4,     5,     6,     7,     9,    10,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    80,    81,    85,    94,    96,    97,
      99,   100,   103,   104,   105,   107,   109,   110,   115,   118,
     120,   121,   124,   125,   126,   132,   133,   134,   140,   146,
      97,   146,   146,   107,    97,    97,    99,   120,    97,   146,
     120,   120,   120,   120,   120,   120,   120,   116,   117,   120,
     116,   120,   101,   106,   107,     0,   105,    48,    49,    53,
      56,    57,    58,    59,    60,    61,    62,    63,    65,    66,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    93,    94,    96,    99,     1,   122,
     123,   146,   119,   120,   124,    97,   120,    97,    11,   100,
     141,   142,    15,   120,    99,    98,   120,    97,    53,    95,
      53,    95,    98,   101,   107,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     146,   120,   120,    99,    53,    99,    64,   113,   114,    99,
      79,   122,   123,    98,   120,    98,   137,   138,   139,   146,
     146,    12,    13,    26,   101,   143,   144,   145,   146,   142,
      97,    98,    53,    98,    98,   120,   117,    64,    97,    95,
      95,   123,    31,    32,    33,    35,    39,    40,    47,   111,
     112,    56,   119,   120,   120,    99,    79,    53,    98,     1,
     108,   110,   118,   121,   125,   126,   133,    98,    53,   113,
     145,   145,    97,   101,   144,    97,   113,   120,   107,    98,
      98,   120,    98,   120,    94,   120,    99,    98,   119,   120,
      98,     8,   113,   139,    97,    97,   137,   137,    56,    99,
      98,    53,    98,    95,   119,   130,    99,    98,   107,   100,
     135,    98,   137,    98,    98,   120,   127,    98,    98,   107,
     119,   131,   101,   136,   113,    98,   135,   113,    99,    99,
     128,    98,   107,   106,   135,   135,   135,   107,   129,   101,
     107
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   102,   103,   104,   104,   105,   105,   105,   105,   106,
     106,   107,   107,   107,   107,   107,   107,   107,   108,   108,
     108,   108,   108,   108,   108,   109,   110,   110,   111,   111,
     112,   112,   112,   112,   112,   112,   112,   113,   113,   114,
     115,   115,   116,   116,   117,   117,   117,   118,   119,   119,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   121,   121,   122,   122,   123,   123,   124,   124,   124,
     125,   125,   127,   126,   126,   128,   126,   129,   126,   130,
     126,   131,   126,   132,   133,   133,   134,   135,   136,   135,
     137,   137,   137,   138,   138,   139,   140,   140,   141,   142,
     142,   143,   143,   144,   144,   144,   144,   144,   144,   145,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     2,
       3,     3,     1,     3,     0,     1,     2,     2,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     5,     3,     3,     3,     4,     5,     3,     4,
       5,     3,     5,     6,     7,     1,     4,     4,     2,     4,
       5,     3,     3,     1,     3,     2,     4,     1,     1,     1,
       5,     7,     0,     8,     5,     0,     9,     0,    10,     0,
       7,     0,     8,     2,     2,     3,     7,     2,     0,     4,
       0,     1,     2,     1,     3,     2,     3,     4,     2,     2,
       3,     1,     2,     5,     3,     5,     6,     6,     6,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
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

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
  YYLTYPE *yylloc;
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yyfilter(yychar, yyn, yystate, yyssp);
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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* script: scriptElementList  */
#line 163 "parser.y"
        { 
            if ( syntaxErrorCounter > 0 ) {
                PrintError("Found " + std::to_string(syntaxErrorCounter) + " syntax errors. Fix them and rerun.");
                exit(1);
            }
            Print("- R: scriptElementList -> script"); 
        }
#line 2353 "parser.tab.cpp"
    break;

  case 3: /* scriptElementList: scriptElement  */
#line 174 "parser.y"
        { Print("- R: scriptElement -> scriptElementList"); }
#line 2359 "parser.tab.cpp"
    break;

  case 4: /* scriptElementList: scriptElementList scriptElement  */
#line 176 "parser.y"
        { Print("- R: scriptElementList scriptElement -> scriptElementList"); }
#line 2365 "parser.tab.cpp"
    break;

  case 5: /* scriptElement: statementListItem  */
#line 180 "parser.y"
                            { Print("- R: statementListItem -> scriptElement"); root -> add((yyvsp[0].stmtNode)); }
#line 2371 "parser.tab.cpp"
    break;

  case 6: /* scriptElement: functionDeclaration  */
#line 181 "parser.y"
                            { Print("- R: functionDeclaration -> scriptElement"); root -> add((yyvsp[0].funcDeclarationNode)); }
#line 2377 "parser.tab.cpp"
    break;

  case 7: /* scriptElement: classDeclaration  */
#line 182 "parser.y"
                            { Print("- R: classDeclaration -> scriptElement"); root -> add((yyvsp[0].classDeclNode)); }
#line 2383 "parser.tab.cpp"
    break;

  case 9: /* statementList: statementListItem  */
#line 187 "parser.y"
                                        { Print("- R: statementListItem -> statementList"); (yyval.stmtListNode) = new StatementListNode((yyvsp[0].stmtNode)); }
#line 2389 "parser.tab.cpp"
    break;

  case 10: /* statementList: statementList statementListItem  */
#line 188 "parser.y"
                                        { Print("- R: statementList statementListItem -> statementList"); (yyval.stmtListNode) -> add((yyvsp[0].stmtNode)); }
#line 2395 "parser.tab.cpp"
    break;

  case 11: /* statementListItem: emptyStatement  */
#line 192 "parser.y"
                            { Print("- R: emptyStatement -> statementListItem"); }
#line 2401 "parser.tab.cpp"
    break;

  case 12: /* statementListItem: expressionStatement  */
#line 193 "parser.y"
                            { Print("- R: expressionStatement -> statementListItem"); }
#line 2407 "parser.tab.cpp"
    break;

  case 13: /* statementListItem: varStatement  */
#line 194 "parser.y"
                            { Print("- R: varStatement -> statementListItem"); }
#line 2413 "parser.tab.cpp"
    break;

  case 14: /* statementListItem: ifStatement  */
#line 195 "parser.y"
                            { Print("- R: ifStatement -> statementListItem"); }
#line 2419 "parser.tab.cpp"
    break;

  case 15: /* statementListItem: iterationStatement  */
#line 196 "parser.y"
                            { Print("- R: iterationStatement -> statementListItem"); }
#line 2425 "parser.tab.cpp"
    break;

  case 16: /* statementListItem: returnStatement  */
#line 198 "parser.y"
        { 
            if ( !isInFunctionBody ) { 
                yyerror("illegal return statement."); YYERROR;
            } 
            Print("- R: returnStatement -> statementListItem");
        }
#line 2436 "parser.tab.cpp"
    break;

  case 17: /* statementListItem: blockStatement  */
#line 204 "parser.y"
                            { Print("- R: blockStatement -> statementListItem"); }
#line 2442 "parser.tab.cpp"
    break;

  case 18: /* statementListItemWithoutEmptyStatement: expressionStatement  */
#line 208 "parser.y"
                            { Print("- R: expressionStatement -> statementListItemWithoutEmptyStatement"); }
#line 2448 "parser.tab.cpp"
    break;

  case 19: /* statementListItemWithoutEmptyStatement: varStatement  */
#line 209 "parser.y"
                            { Print("- R: varStatement -> statementListItemWithoutEmptyStatement"); }
#line 2454 "parser.tab.cpp"
    break;

  case 20: /* statementListItemWithoutEmptyStatement: ifStatement  */
#line 210 "parser.y"
                            { Print("- R: ifStatement -> statementListItemWithoutEmptyStatement"); }
#line 2460 "parser.tab.cpp"
    break;

  case 21: /* statementListItemWithoutEmptyStatement: iterationStatement  */
#line 211 "parser.y"
                            { Print("- R: iterationStatement -> statementListItemWithoutEmptyStatement"); }
#line 2466 "parser.tab.cpp"
    break;

  case 22: /* statementListItemWithoutEmptyStatement: returnStatement  */
#line 213 "parser.y"
        { 
            if ( !isInFunctionBody ) { 
                yyerror("illegal return statement."); YYERROR;
            } 
            Print("- R: returnStatement -> statementListItemWithoutEmptyStatement");
        }
#line 2477 "parser.tab.cpp"
    break;

  case 23: /* statementListItemWithoutEmptyStatement: blockStatement  */
#line 219 "parser.y"
                            { Print("- R: blockStatement -> statementListItemWithoutEmptyStatement"); }
#line 2483 "parser.tab.cpp"
    break;

  case 25: /* emptyStatement: ';'  */
#line 226 "parser.y"
        { 
            if ( isASIActivated ) {
                std::string text(yytext_ptr, yyleng);
                yyerror(("syntax error on token: " + text).c_str()); YYERROR;
            }
            Print("- R: ';' -> emptyStatement");
            (yyval.stmtNode) = StatementNode::fromEmptyStmt();
        }
#line 2496 "parser.tab.cpp"
    break;

  case 26: /* blockStatement: '{' '}'  */
#line 237 "parser.y"
                            { Print("- R: '{' '}' -> blockStatement"); (yyval.stmtNode) = StatementNode::fromBlockStmt(nullptr); }
#line 2502 "parser.tab.cpp"
    break;

  case 27: /* blockStatement: '{' statementList '}'  */
#line 238 "parser.y"
                            { Print("- R: '{' statementList '}' -> blockStatement"); (yyval.stmtNode) = StatementNode::fromBlockStmt((yyvsp[-1].stmtListNode)); }
#line 2508 "parser.tab.cpp"
    break;

  case 28: /* type: predefinedType  */
#line 244 "parser.y"
                     { Print("- R: predefinedType -> type"); (yyval.typeNode) = (yyvsp[0].typeNode); }
#line 2514 "parser.tab.cpp"
    break;

  case 29: /* type: type '[' ']'  */
#line 245 "parser.y"
                     { Print("- R: type '[' ']' -> type"); (yyval.typeNode) -> arrayArity++; }
#line 2520 "parser.tab.cpp"
    break;

  case 30: /* predefinedType: NUMBER  */
#line 249 "parser.y"
                    { Print("- R: NUMBER -> predefinedType"); (yyval.typeNode) = new TypeNode(TypeNode::Type::_NUMBER); }
#line 2526 "parser.tab.cpp"
    break;

  case 31: /* predefinedType: STRING  */
#line 250 "parser.y"
                    { Print("- R: STRING -> predefinedType"); (yyval.typeNode) = new TypeNode(TypeNode::Type::_STRING); }
#line 2532 "parser.tab.cpp"
    break;

  case 32: /* predefinedType: BOOLEAN  */
#line 251 "parser.y"
                    { Print("- R: BOOLEAN -> predefinedType"); (yyval.typeNode) = new TypeNode(TypeNode::Type::_BOOLEAN); }
#line 2538 "parser.tab.cpp"
    break;

  case 33: /* predefinedType: UNDEFINED  */
#line 252 "parser.y"
                    { Print("- R: UNDEFINED -> predefinedType"); (yyval.typeNode) = new TypeNode(TypeNode::Type::_UNDEFINED); }
#line 2544 "parser.tab.cpp"
    break;

  case 34: /* predefinedType: VOID  */
#line 253 "parser.y"
                    { Print("- R: VOID -> predefinedType"); (yyval.typeNode) = new TypeNode(TypeNode::Type::_VOID); }
#line 2550 "parser.tab.cpp"
    break;

  case 35: /* predefinedType: NULL_KW  */
#line 254 "parser.y"
                    { Print("- R: NULL_KW -> predefinedType"); (yyval.typeNode) = new TypeNode(TypeNode::Type::_NULL); }
#line 2556 "parser.tab.cpp"
    break;

  case 36: /* predefinedType: ID  */
#line 255 "parser.y"
                    { Print("- R: ID -> predefinedType"); (yyval.typeNode) = new TypeNode((yyvsp[0].identName)); }
#line 2562 "parser.tab.cpp"
    break;

  case 37: /* typeAnnotationOpt: %empty  */
#line 259 "parser.y"
                        { Print("- R: # empty # -> typeAnnotationOpt"); (yyval.typeNode) = nullptr; }
#line 2568 "parser.tab.cpp"
    break;

  case 38: /* typeAnnotationOpt: typeAnnotation  */
#line 260 "parser.y"
                        { Print("- R: typeAnnotation -> typeAnnotationOpt"); (yyval.typeNode) = (yyvsp[0].typeNode); }
#line 2574 "parser.tab.cpp"
    break;

  case 39: /* typeAnnotation: ':' type  */
#line 264 "parser.y"
               { Print("- R: ':' type -> typeAnnotation"); (yyval.typeNode) = (yyvsp[0].typeNode); }
#line 2580 "parser.tab.cpp"
    break;

  case 40: /* arrayLiteral: '[' elementList ']'  */
#line 270 "parser.y"
        { Print("- R: '[' elementList ']' -> arrayLiteral"); (yyval.exprNode) = ExpressionNode::fromArrayLiteral((yyvsp[-1].exprListNode)); }
#line 2586 "parser.tab.cpp"
    break;

  case 41: /* arrayLiteral: ENDL_BRACKET_OPEN elementList ']'  */
#line 272 "parser.y"
        { Print("- R: ENDL_BRACKET_OPEN elementList ']' -> arrayLiteral"); (yyval.exprNode) = ExpressionNode::fromArrayLiteral((yyvsp[-1].exprListNode)); }
#line 2592 "parser.tab.cpp"
    break;

  case 42: /* elementList: elementListItem  */
#line 277 "parser.y"
        { Print("- R: elementListItem -> elementList"); (yyval.exprListNode) = ExpressionListNode::fromExpression((yyvsp[0].exprNode)); }
#line 2598 "parser.tab.cpp"
    break;

  case 43: /* elementList: elementList ',' elementListItem  */
#line 279 "parser.y"
        { Print("- R: elementList ',' elementListItem -> elementList"); (yyval.exprListNode) -> merge(ExpressionListNode::fromExpression((yyvsp[0].exprNode))); }
#line 2604 "parser.tab.cpp"
    break;

  case 44: /* elementListItem: %empty  */
#line 283 "parser.y"
                  { Print("- R: #empty# -> elementListItem"); (yyval.exprNode) = ExpressionNode::fromEmptyArrayElementExpr(); }
#line 2610 "parser.tab.cpp"
    break;

  case 45: /* elementListItem: singleExpression  */
#line 284 "parser.y"
                       { Print("- R: singleExpression -> elementListItem"); (yyval.exprNode) = (yyvsp[0].exprNode); }
#line 2616 "parser.tab.cpp"
    break;

  case 46: /* elementListItem: singleExpression ','  */
#line 286 "parser.y"
        { 
            Print("- R: singleExpression ',' -> elementListItem");
            ExpressionNode *node = ExpressionNode::fromEmptyArrayElementExpr();
            (yyval.exprNode) = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_COMMA, (yyvsp[-1].exprNode), node);
        }
#line 2626 "parser.tab.cpp"
    break;

  case 47: /* expressionStatement: singleExpression ';'  */
#line 296 "parser.y"
                           { Print("- R: expressionList ';' -> expressionStatement"); (yyval.stmtNode) = StatementNode::fromExprStmt((yyvsp[-1].exprNode)); }
#line 2632 "parser.tab.cpp"
    break;

  case 48: /* singleExpressionOpt: %empty  */
#line 300 "parser.y"
                        { Print("- R: #empty# -> singleExpressionOpt"); (yyval.exprNode) = nullptr; }
#line 2638 "parser.tab.cpp"
    break;

  case 49: /* singleExpressionOpt: singleExpression  */
#line 301 "parser.y"
                        { Print("- R: singleExpression -> singleExpressionOpt"); (yyval.exprNode) = (yyvsp[0].exprNode); }
#line 2644 "parser.tab.cpp"
    break;

  case 50: /* singleExpression: identifier  */
#line 305 "parser.y"
                    { Print("- R: identifier -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromId((yyvsp[0].identName)); }
#line 2650 "parser.tab.cpp"
    break;

  case 51: /* singleExpression: THIS  */
#line 306 "parser.y"
                    { Print("- R: THIS -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromThis(); }
#line 2656 "parser.tab.cpp"
    break;

  case 52: /* singleExpression: TRUE_KW  */
#line 307 "parser.y"
                    { Print("- R: TRUE_LITERAL -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromTrueLit(); }
#line 2662 "parser.tab.cpp"
    break;

  case 53: /* singleExpression: FALSE_KW  */
#line 308 "parser.y"
                    { Print("- R: FALSE_LITERAL -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromFalseLit(); }
#line 2668 "parser.tab.cpp"
    break;

  case 54: /* singleExpression: NULL_KW  */
#line 309 "parser.y"
                    { Print("- R: NULL_LITERAL -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromNullLit(); }
#line 2674 "parser.tab.cpp"
    break;

  case 55: /* singleExpression: UNDEFINED  */
#line 310 "parser.y"
                    { Print("- R: NULL_LITERAL -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromUndefinedLit(); }
#line 2680 "parser.tab.cpp"
    break;

  case 56: /* singleExpression: STRING_LIT  */
#line 312 "parser.y"
                    { Print("- R: STRING_LIT -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromStringLit((yyvsp[0].stringValue)); }
#line 2686 "parser.tab.cpp"
    break;

  case 57: /* singleExpression: TEMPLATE_LIT  */
#line 313 "parser.y"
                    { Print("- R: TEMPLATE_LIT -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromStringLit((yyvsp[0].stringValue)); }
#line 2692 "parser.tab.cpp"
    break;

  case 58: /* singleExpression: INT_LIT  */
#line 314 "parser.y"
                    { Print("- R: INT_LIT -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromIntLit((yyvsp[0].integerValue)); }
#line 2698 "parser.tab.cpp"
    break;

  case 59: /* singleExpression: FLOAT_LIT  */
#line 315 "parser.y"
                    { Print("- R: FLOAT_LIT -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromFloatLit((yyvsp[0].floatingPointValue)); }
#line 2704 "parser.tab.cpp"
    break;

  case 60: /* singleExpression: '-' singleExpression  */
#line 318 "parser.y"
        { Print("- R: '-' singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromUnaryExpr(ExpressionNode::Type::_UMINUS, (yyvsp[0].exprNode)); }
#line 2710 "parser.tab.cpp"
    break;

  case 61: /* singleExpression: '+' singleExpression  */
#line 320 "parser.y"
        { Print("- R: '+' singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromUnaryExpr(ExpressionNode::Type::_UPLUS, (yyvsp[0].exprNode)); }
#line 2716 "parser.tab.cpp"
    break;

  case 62: /* singleExpression: '!' singleExpression  */
#line 323 "parser.y"
        { Print("- R: '!' singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromUnaryExpr(ExpressionNode::Type::_NOT, (yyvsp[0].exprNode)); }
#line 2722 "parser.tab.cpp"
    break;

  case 63: /* singleExpression: singleExpression OPERATOR_INCREMENT  */
#line 326 "parser.y"
        { Print("- R: singleExpression OPERATOR_INCREMENT -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromUnaryExpr(ExpressionNode::Type::_POST_INCREMENT, (yyvsp[-1].exprNode)); }
#line 2728 "parser.tab.cpp"
    break;

  case 64: /* singleExpression: singleExpression OPERATOR_DECREMENT  */
#line 328 "parser.y"
        { Print("- R: singleExpression OPERATOR_DECREMENT -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromUnaryExpr(ExpressionNode::Type::_POST_DECREMENT, (yyvsp[-1].exprNode)); }
#line 2734 "parser.tab.cpp"
    break;

  case 65: /* singleExpression: ENDL_OPERATOR_INCREMENT singleExpression  */
#line 331 "parser.y"
        { Print("- R: ENDL_OPERATOR_INCREMENT singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromUnaryExpr(ExpressionNode::Type::_PREF_INCREMENT, (yyvsp[0].exprNode)); }
#line 2740 "parser.tab.cpp"
    break;

  case 66: /* singleExpression: ENDL_OPERATOR_DECREMENT singleExpression  */
#line 333 "parser.y"
        { Print("- R: ENDL_OPERATOR_DECREMENT singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromUnaryExpr(ExpressionNode::Type::_PREF_DECREMENT, (yyvsp[0].exprNode)); }
#line 2746 "parser.tab.cpp"
    break;

  case 67: /* singleExpression: OPERATOR_INCREMENT singleExpression  */
#line 335 "parser.y"
        { Print("- R: OPERATOR_INCREMENT singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromUnaryExpr(ExpressionNode::Type::_PREF_INCREMENT, (yyvsp[0].exprNode)); }
#line 2752 "parser.tab.cpp"
    break;

  case 68: /* singleExpression: OPERATOR_DECREMENT singleExpression  */
#line 337 "parser.y"
        { Print("- R: OPERATOR_DECREMENT singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromUnaryExpr(ExpressionNode::Type::_PREF_DECREMENT, (yyvsp[0].exprNode)); }
#line 2758 "parser.tab.cpp"
    break;

  case 69: /* singleExpression: singleExpression '+' singleExpression  */
#line 340 "parser.y"
        { Print("- R: singleExpression '+' singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_PLUS, (yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2764 "parser.tab.cpp"
    break;

  case 70: /* singleExpression: singleExpression '-' singleExpression  */
#line 342 "parser.y"
        { Print("- R: singleExpression '-' singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_MINUS, (yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2770 "parser.tab.cpp"
    break;

  case 71: /* singleExpression: singleExpression '*' singleExpression  */
#line 344 "parser.y"
        { Print("- R: singleExpression '*' singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_MUL, (yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2776 "parser.tab.cpp"
    break;

  case 72: /* singleExpression: singleExpression '/' singleExpression  */
#line 346 "parser.y"
        { Print("- R: singleExpression '/' singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_DIV, (yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2782 "parser.tab.cpp"
    break;

  case 73: /* singleExpression: singleExpression '<' singleExpression  */
#line 348 "parser.y"
        { Print("- R: singleExpression '<' singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_LESS, (yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2788 "parser.tab.cpp"
    break;

  case 74: /* singleExpression: singleExpression '>' singleExpression  */
#line 350 "parser.y"
        { Print("- R: singleExpression '>' singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_GREAT, (yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2794 "parser.tab.cpp"
    break;

  case 75: /* singleExpression: singleExpression OPERATOR_EQUAL singleExpression  */
#line 353 "parser.y"
        { Print("- R: singleExpression OPERATOR_EQUAL singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_EQUAL, (yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2800 "parser.tab.cpp"
    break;

  case 76: /* singleExpression: singleExpression OPERATOR_NOT_EQUAL singleExpression  */
#line 355 "parser.y"
        { Print("- R: singleExpression OPERATOR_NOT_EQUAL singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_NOT_EQUAL, (yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2806 "parser.tab.cpp"
    break;

  case 77: /* singleExpression: singleExpression OPERATOR_STRICT_EQUAL singleExpression  */
#line 357 "parser.y"
        { Print("- R: singleExpression OPERATOR_STRICT_EQUAL singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_STRICT_EQUAL, (yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2812 "parser.tab.cpp"
    break;

  case 78: /* singleExpression: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression  */
#line 359 "parser.y"
        { Print("- R: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_STRICT_NOT_EQUAL, (yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2818 "parser.tab.cpp"
    break;

  case 79: /* singleExpression: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression  */
#line 361 "parser.y"
        { Print("- R: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_LESS_EQUAL, (yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2824 "parser.tab.cpp"
    break;

  case 80: /* singleExpression: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression  */
#line 363 "parser.y"
        { Print("- R: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_GREAT_EQUAL, (yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2830 "parser.tab.cpp"
    break;

  case 81: /* singleExpression: singleExpression '=' singleExpression  */
#line 366 "parser.y"
        { Print("- R: singleExpression '=' singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_ASSIGN, (yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2836 "parser.tab.cpp"
    break;

  case 82: /* singleExpression: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression  */
#line 368 "parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_ASSIGN_MUL, (yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2842 "parser.tab.cpp"
    break;

  case 83: /* singleExpression: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression  */
#line 370 "parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_ASSIGN_DIV, (yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2848 "parser.tab.cpp"
    break;

  case 84: /* singleExpression: singleExpression OPERATOR_ASSIGN_PLUS singleExpression  */
#line 372 "parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_PLUS singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_ASSIGN_PLUS, (yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2854 "parser.tab.cpp"
    break;

  case 85: /* singleExpression: singleExpression OPERATOR_ASSIGN_MINUS singleExpression  */
#line 374 "parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_MINUS singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_ASSIGN_MINUS, (yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2860 "parser.tab.cpp"
    break;

  case 86: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression  */
#line 376 "parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_ASSIGN_LOGICAL_AND, (yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2866 "parser.tab.cpp"
    break;

  case 87: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression  */
#line 378 "parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_ASSIGN_LOGICAL_OR, (yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2872 "parser.tab.cpp"
    break;

  case 88: /* singleExpression: singleExpression OPERATOR_LOGICAL_OR singleExpression  */
#line 381 "parser.y"
        { Print("- R: singleExpression OPERATOR_LOGICAL_OR singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_LOGICAL_OR, (yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2878 "parser.tab.cpp"
    break;

  case 89: /* singleExpression: singleExpression OPERATOR_LOGICAL_AND singleExpression  */
#line 383 "parser.y"
        { Print("- R: singleExpression OPERATOR_LOGICAL_AND singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_LOGICAL_AND, (yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2884 "parser.tab.cpp"
    break;

  case 90: /* singleExpression: singleExpression INSTANCEOF singleExpression  */
#line 386 "parser.y"
        { Print("- R: singleExpression INSTANCEOF singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_INSTANCEOF, (yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2890 "parser.tab.cpp"
    break;

  case 91: /* singleExpression: singleExpression IN singleExpression  */
#line 388 "parser.y"
        { Print("- R: singleExpression IN singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_IN, (yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2896 "parser.tab.cpp"
    break;

  case 92: /* singleExpression: singleExpression '?' singleExpression ':' singleExpression  */
#line 391 "parser.y"
        { Print("- R: singleExpression '?' singleExpression ':' singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromTernaryExpr((yyvsp[-4].exprNode), (yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2902 "parser.tab.cpp"
    break;

  case 93: /* singleExpression: singleExpression ',' singleExpression  */
#line 394 "parser.y"
        { Print("- R: singleExpression ',' singleExpressionn -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_COMMA, (yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2908 "parser.tab.cpp"
    break;

  case 94: /* singleExpression: '(' singleExpression ')'  */
#line 397 "parser.y"
        { Print("- R: '(' singleExpression ')' -> singleExpression"); (yyval.exprNode) = (yyvsp[-1].exprNode); }
#line 2914 "parser.tab.cpp"
    break;

  case 95: /* singleExpression: SUPER '(' ')'  */
#line 400 "parser.y"
        { Print("- R: SUPER '(' ')' -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromSuperCall(nullptr); }
#line 2920 "parser.tab.cpp"
    break;

  case 96: /* singleExpression: SUPER '(' singleExpression ')'  */
#line 402 "parser.y"
        { Print("- R: SUPER '(' singleExpression ')' -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromSuperCall(ExpressionListNode::fromExpression((yyvsp[-1].exprNode))); }
#line 2926 "parser.tab.cpp"
    break;

  case 97: /* singleExpression: SUPER '(' singleExpression ',' ')'  */
#line 404 "parser.y"
        { Print("- R: SUPER '(' singleExpression ',' ')' -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromSuperCall(ExpressionListNode::fromExpression((yyvsp[-2].exprNode))); }
#line 2932 "parser.tab.cpp"
    break;

  case 98: /* singleExpression: identifier '(' ')'  */
#line 408 "parser.y"
        { Print("- R: identifier '(' ')' -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromFuncCall((yyvsp[-2].identName), nullptr); }
#line 2938 "parser.tab.cpp"
    break;

  case 99: /* singleExpression: identifier '(' singleExpression ')'  */
#line 410 "parser.y"
        { Print("- R: identifier '(' singleExpression ')' -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromFuncCall((yyvsp[-3].identName), ExpressionListNode::fromExpression((yyvsp[-1].exprNode))); }
#line 2944 "parser.tab.cpp"
    break;

  case 100: /* singleExpression: identifier '(' singleExpression ',' ')'  */
#line 413 "parser.y"
        { Print("- R: identifier '(' singleExpression ',' ')' -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromFuncCall((yyvsp[-4].identName), ExpressionListNode::fromExpression((yyvsp[-2].exprNode))); }
#line 2950 "parser.tab.cpp"
    break;

  case 101: /* singleExpression: singleExpression '.' identifier  */
#line 417 "parser.y"
        { Print("- R: singleExpression '.' identifier -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromFieldAccess((yyvsp[-2].exprNode), (yyvsp[0].identName)); }
#line 2956 "parser.tab.cpp"
    break;

  case 102: /* singleExpression: singleExpression '.' identifier '(' ')'  */
#line 419 "parser.y"
        { Print("- R: singleExpression '.' identifier '(' ')' -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromMethodCall((yyvsp[-4].exprNode), (yyvsp[-2].identName), nullptr); }
#line 2962 "parser.tab.cpp"
    break;

  case 103: /* singleExpression: singleExpression '.' identifier '(' singleExpression ')'  */
#line 421 "parser.y"
        { Print("- R: singleExpression '.' identifier '(' singleExpression ')' -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromMethodCall((yyvsp[-5].exprNode), (yyvsp[-3].identName), ExpressionListNode::fromExpression((yyvsp[-1].exprNode))); }
#line 2968 "parser.tab.cpp"
    break;

  case 104: /* singleExpression: singleExpression '.' identifier '(' singleExpression ',' ')'  */
#line 423 "parser.y"
        { Print("- R: singleExpression '.' identifier '(' singleExpression ',' ')' -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromMethodCall((yyvsp[-6].exprNode), (yyvsp[-4].identName), ExpressionListNode::fromExpression((yyvsp[-2].exprNode))); }
#line 2974 "parser.tab.cpp"
    break;

  case 105: /* singleExpression: arrayLiteral  */
#line 425 "parser.y"
                   { Print("- R: arrayLiteral -> singleExpression"); (yyval.exprNode) = (yyvsp[0].exprNode); }
#line 2980 "parser.tab.cpp"
    break;

  case 106: /* singleExpression: singleExpression '[' singleExpression ']'  */
#line 428 "parser.y"
        { Print("- R: singleExpression '[' singleExpression ']' -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromArrayAccessExpr((yyvsp[-3].exprNode), (yyvsp[-1].exprNode)); }
#line 2986 "parser.tab.cpp"
    break;

  case 107: /* singleExpression: singleExpression ENDL_BRACKET_OPEN singleExpression ']'  */
#line 430 "parser.y"
        { Print("- R: singleExpression ENDL_BRACKET_OPEN singleExpression ']' -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromArrayAccessExpr((yyvsp[-3].exprNode), (yyvsp[-1].exprNode)); }
#line 2992 "parser.tab.cpp"
    break;

  case 108: /* singleExpression: NEW identifier  */
#line 433 "parser.y"
        { Print("- R: NEW singleExpression -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromNew((yyvsp[0].identName), nullptr); }
#line 2998 "parser.tab.cpp"
    break;

  case 109: /* singleExpression: NEW identifier '(' ')'  */
#line 435 "parser.y"
        { Print("- R: NEW singleExpression '(' ')' -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromNew((yyvsp[-2].identName), nullptr); }
#line 3004 "parser.tab.cpp"
    break;

  case 110: /* singleExpression: NEW identifier '(' singleExpression ')'  */
#line 437 "parser.y"
        { Print("- R: NEW singleExpression '(' singleExpression ')' -> singleExpression"); (yyval.exprNode) = ExpressionNode::fromNew((yyvsp[-3].identName), ExpressionListNode::fromExpression((yyvsp[-1].exprNode))); }
#line 3010 "parser.tab.cpp"
    break;

  case 111: /* varStatement: varModifier varDeclarationList ';'  */
#line 443 "parser.y"
                                         { Print("- R: varModifier varDeclarationList ';' -> varStatement"); (yyval.stmtNode) = StatementNode::fromVarStmt((yyvsp[-2].varModifierType), (yyvsp[-1].varDeclListNode)); }
#line 3016 "parser.tab.cpp"
    break;

  case 113: /* varDeclarationList: varDeclaration  */
#line 449 "parser.y"
        { Print("- R: varDeclaration -> varDeclarationList"); (yyval.varDeclListNode) = new VarDeclarationListNode((yyvsp[0].varDeclNode)); }
#line 3022 "parser.tab.cpp"
    break;

  case 114: /* varDeclarationList: varDeclarationList ',' varDeclaration  */
#line 451 "parser.y"
        { Print("- R: varDeclarationList ',' varDeclaration -> varDeclarationList"); (yyval.varDeclListNode) -> add((yyvsp[0].varDeclNode)); }
#line 3028 "parser.tab.cpp"
    break;

  case 115: /* varDeclaration: identifier typeAnnotationOpt  */
#line 456 "parser.y"
        { Print("- R: identifier typeAnnotationOpt -> varDeclaration"); (yyval.varDeclNode) = new VarDeclarationNode((yyvsp[-1].identName), (yyvsp[0].typeNode), nullptr); }
#line 3034 "parser.tab.cpp"
    break;

  case 116: /* varDeclaration: identifier typeAnnotationOpt '=' singleExpression  */
#line 458 "parser.y"
        { Print("- R: identifier typeAnnotationOpt '=' singleExpression -> varDeclaration"); (yyval.varDeclNode) = new VarDeclarationNode((yyvsp[-3].identName), (yyvsp[-2].typeNode), (yyvsp[0].exprNode)); }
#line 3040 "parser.tab.cpp"
    break;

  case 117: /* varModifier: VAR  */
#line 462 "parser.y"
            { Print("- R: VAR -> varModifier"); (yyval.varModifierType) = VarModifierType::_VAR; }
#line 3046 "parser.tab.cpp"
    break;

  case 118: /* varModifier: LET  */
#line 463 "parser.y"
            { Print("- R: LET -> varModifier"); (yyval.varModifierType) = VarModifierType::_LET; }
#line 3052 "parser.tab.cpp"
    break;

  case 119: /* varModifier: CONST  */
#line 464 "parser.y"
            { Print("- R: CONST -> varModifier"); (yyval.varModifierType) = VarModifierType::_CONST; }
#line 3058 "parser.tab.cpp"
    break;

  case 120: /* ifStatement: IF '(' singleExpression ')' statementListItemWithoutEmptyStatement  */
#line 471 "parser.y"
        { 
            Print("- R: IF '(' expressionList ')' statementListItem -> ifStatement");
            (yyval.stmtNode) = StatementNode::fromIfElseStmt((yyvsp[-2].exprNode), (yyvsp[0].stmtNode), nullptr);
        }
#line 3067 "parser.tab.cpp"
    break;

  case 121: /* ifStatement: IF '(' singleExpression ')' statementListItemWithoutEmptyStatement ELSE statementListItem  */
#line 477 "parser.y"
        { 
            Print("- R: IF '(' expressionList ')' statementListItem ELSE statementListItem -> ifStatement");
            (yyval.stmtNode) = StatementNode::fromIfElseStmt((yyvsp[-4].exprNode), (yyvsp[-2].stmtNode), (yyvsp[0].stmtNode));
        }
#line 3076 "parser.tab.cpp"
    break;

  case 122: /* $@1: %empty  */
#line 486 "parser.y"
                                                          { doWhileASI(); }
#line 3082 "parser.tab.cpp"
    break;

  case 123: /* iterationStatement: DO statementListItem WHILE '(' singleExpression ')' $@1 ';'  */
#line 487 "parser.y"
        { 
            Print("- R: DO statementListItem WHILE '(' expressionList ')' ';' -> iterationStatement");
            (yyval.stmtNode) = StatementNode::fromDoWhileStmt((yyvsp[-6].stmtNode), (yyvsp[-3].exprNode));
        }
#line 3091 "parser.tab.cpp"
    break;

  case 124: /* iterationStatement: WHILE '(' singleExpression ')' statementListItem  */
#line 493 "parser.y"
        { 
            Print("- R: WHILE '(' expressionList ')' statementListItem -> iterationStatement");
            (yyval.stmtNode) = StatementNode::fromWhileStmt((yyvsp[-2].exprNode), (yyvsp[0].stmtNode));
        }
#line 3100 "parser.tab.cpp"
    break;

  case 125: /* $@2: %empty  */
#line 498 "parser.y"
                                                                                        { isInForHeader = 0; }
#line 3106 "parser.tab.cpp"
    break;

  case 126: /* iterationStatement: forHeader singleExpressionOpt ';' singleExpressionOpt ';' singleExpressionOpt ')' $@2 statementListItem  */
#line 499 "parser.y"
        { 
            Print("- R: FOR '(' singleExpressionOpt ';' singleExpressionOpt ';' singleExpressionOpt ')' statementListItem -> iterationStatement");
            (yyval.stmtNode) = StatementNode::fromClassicForStmt((yyvsp[-7].exprNode), (yyvsp[-5].exprNode), (yyvsp[-3].exprNode), (yyvsp[0].stmtNode));
        }
#line 3115 "parser.tab.cpp"
    break;

  case 127: /* $@3: %empty  */
#line 504 "parser.y"
                                                                                                   { isInForHeader = 0; }
#line 3121 "parser.tab.cpp"
    break;

  case 128: /* iterationStatement: forHeader varModifier varDeclarationList ';' singleExpressionOpt ';' singleExpressionOpt ')' $@3 statementListItem  */
#line 505 "parser.y"
        {
            Print("- R: FOR '(' varModifier varDeclarationList ';' singleExpressionOpt ';' singleExpressionOpt ')' statementListItem -> iterationStatement");
            (yyval.stmtNode) = StatementNode::fromClassicForWithVarDeclStmt((yyvsp[-8].varModifierType), (yyvsp[-7].varDeclListNode), (yyvsp[-5].exprNode), (yyvsp[-3].exprNode), (yyvsp[0].stmtNode));
        }
#line 3130 "parser.tab.cpp"
    break;

  case 129: /* $@4: %empty  */
#line 510 "parser.y"
                                                         { isInForHeader = 0; }
#line 3136 "parser.tab.cpp"
    break;

  case 130: /* iterationStatement: forHeader singleExpression IN singleExpression ')' $@4 statementListItem  */
#line 511 "parser.y"
        {
            Print("- R: FOR '(' singleExpression IN singleExpression ')' statementListItem -> iterationStatement");
            (yyval.stmtNode) = StatementNode::fromForExprInExprStmt((yyvsp[-5].exprNode), (yyvsp[-3].exprNode), (yyvsp[0].stmtNode));
        }
#line 3145 "parser.tab.cpp"
    break;

  case 131: /* $@5: %empty  */
#line 516 "parser.y"
                                                                   { isInForHeader = 0; }
#line 3151 "parser.tab.cpp"
    break;

  case 132: /* iterationStatement: forHeader varModifier varDeclaration IN singleExpression ')' $@5 statementListItem  */
#line 517 "parser.y"
        {
            Print("- R: FOR '(' varModifier varDeclaration IN expressionList ')' statementListItem -> iterationStatement");
            (yyval.stmtNode) = StatementNode::fromForVarDeclInExprStmt((yyvsp[-6].varModifierType), (yyvsp[-5].varDeclNode), (yyvsp[-3].exprNode), (yyvsp[0].stmtNode));
        }
#line 3160 "parser.tab.cpp"
    break;

  case 133: /* forHeader: FOR '('  */
#line 524 "parser.y"
               { isInForHeader = 1; }
#line 3166 "parser.tab.cpp"
    break;

  case 134: /* returnStatement: RETURN ';'  */
#line 530 "parser.y"
                                    { Print("- R: RETURN ';' -> returnStatement"); (yyval.stmtNode) = StatementNode::fromReturnStmt(nullptr); }
#line 3172 "parser.tab.cpp"
    break;

  case 135: /* returnStatement: RETURN singleExpression ';'  */
#line 531 "parser.y"
                                    { Print("- R: RETURN singleExpression ';' -> returnStatement"); (yyval.stmtNode) = StatementNode::fromReturnStmt((yyvsp[-1].exprNode)); }
#line 3178 "parser.tab.cpp"
    break;

  case 136: /* functionDeclaration: FUNCTION identifier '(' parameterList ')' typeAnnotationOpt functionBody  */
#line 536 "parser.y"
        {
            Print("- R: FUNCTION ID '(' parameterList ')' typeAnnotation functionBody -> functionDeclaration");
            (yyval.funcDeclarationNode) = new FunctionDeclarationNode((yyvsp[-5].identName), (yyvsp[-3].requiredParameterListNode), (yyvsp[-1].typeNode), (yyvsp[0].stmtListNode));
        }
#line 3187 "parser.tab.cpp"
    break;

  case 137: /* functionBody: '{' '}'  */
#line 543 "parser.y"
              { Print("- R: '{' '}' -> functionBody"); (yyval.stmtListNode) = StatementListNode::makeEmpty(); }
#line 3193 "parser.tab.cpp"
    break;

  case 138: /* $@6: %empty  */
#line 544 "parser.y"
          { isInFunctionBody = 1; }
#line 3199 "parser.tab.cpp"
    break;

  case 139: /* functionBody: '{' $@6 statementList '}'  */
#line 545 "parser.y"
        { 
            isInFunctionBody = 0; 
            Print("- R: '{' statementList '}' -> functionBody");
            (yyval.stmtListNode) = (yyvsp[-1].stmtListNode);
        }
#line 3209 "parser.tab.cpp"
    break;

  case 140: /* parameterList: %empty  */
#line 553 "parser.y"
                                { Print("- R: #empty# -> parameterList"); (yyval.requiredParameterListNode) = RequiredParameterListNode::makeEmpty(); }
#line 3215 "parser.tab.cpp"
    break;

  case 141: /* parameterList: requiredParameterList  */
#line 554 "parser.y"
                                { Print("- R: requiredParameterList -> parameterList"); (yyval.requiredParameterListNode) = (yyvsp[0].requiredParameterListNode); }
#line 3221 "parser.tab.cpp"
    break;

  case 142: /* parameterList: requiredParameterList ','  */
#line 555 "parser.y"
                                { Print("- R: requiredParameterList ',' -> parameterList"); (yyval.requiredParameterListNode) = (yyvsp[-1].requiredParameterListNode); }
#line 3227 "parser.tab.cpp"
    break;

  case 143: /* requiredParameterList: requiredParameter  */
#line 560 "parser.y"
        {
            Print("- R: requiredParameter -> requiredParameterList");
            (yyval.requiredParameterListNode) = new RequiredParameterListNode((yyvsp[0].requiredParameterNode));
        }
#line 3236 "parser.tab.cpp"
    break;

  case 144: /* requiredParameterList: requiredParameterList ',' requiredParameter  */
#line 565 "parser.y"
        {
            Print("- R: requiredParameterList ',' requiredParameter -> requiredParameterList");
            (yyval.requiredParameterListNode) -> add((yyvsp[0].requiredParameterNode));
        }
#line 3245 "parser.tab.cpp"
    break;

  case 145: /* requiredParameter: identifier typeAnnotationOpt  */
#line 573 "parser.y"
        { 
            Print("- R: ID typeAnnotationOpt -> requiredParameter");
            (yyval.requiredParameterNode) = new RequiredParameterNode((yyvsp[-1].identName), (yyvsp[0].typeNode));
        }
#line 3254 "parser.tab.cpp"
    break;

  case 146: /* classDeclaration: CLASS identifier classTail  */
#line 583 "parser.y"
        {
            Print("- R: CLASS identifier classTail -> classDeclaration");
            (yyval.classDeclNode) = new ClassDeclarationNode((yyvsp[-1].identName), (yyvsp[0].classElementListNode));
        }
#line 3263 "parser.tab.cpp"
    break;

  case 147: /* classDeclaration: CLASS identifier classHeritage classTail  */
#line 588 "parser.y"
        {
            Print("- R: CLASS identifier classHeritage classTail -> classDeclaration");
            (yyval.classDeclNode) = new ClassDeclarationNode((yyvsp[-2].identName), (yyvsp[-1].identName), (yyvsp[0].classElementListNode));
        }
#line 3272 "parser.tab.cpp"
    break;

  case 148: /* classHeritage: EXTENDS identifier  */
#line 595 "parser.y"
                         { Print("- R: EXTENDS identifier -> classHeritage"); (yyval.identName) = (yyvsp[0].identName); }
#line 3278 "parser.tab.cpp"
    break;

  case 149: /* classTail: '{' '}'  */
#line 599 "parser.y"
                                { Print("- R: '{' '}' -> classTail"); (yyval.classElementListNode) = ClassElementListNode::makeEmpty(); }
#line 3284 "parser.tab.cpp"
    break;

  case 150: /* classTail: '{' classElementList '}'  */
#line 600 "parser.y"
                                { Print("- R: '{' classElementList '}' -> classTail"); (yyval.classElementListNode) = (yyvsp[-1].classElementListNode); }
#line 3290 "parser.tab.cpp"
    break;

  case 151: /* classElementList: classElement  */
#line 604 "parser.y"
                                    { Print("- R: classElement -> classElementList"); (yyval.classElementListNode) = new ClassElementListNode((yyvsp[0].classElementNode)); }
#line 3296 "parser.tab.cpp"
    break;

  case 152: /* classElementList: classElementList classElement  */
#line 605 "parser.y"
                                    { Print("- R: classElementList classElement -> classElementList"); (yyval.classElementListNode) ->add((yyvsp[0].classElementNode)); }
#line 3302 "parser.tab.cpp"
    break;

  case 153: /* classElement: CONSTRUCTOR '(' parameterList ')' functionBody  */
#line 610 "parser.y"
        {
            Print("- R: CONSTRUCTOR '(' parameterList ')' functionBody -> classElement");
            (yyval.classElementNode) = new ClassElementNode((yyvsp[-2].requiredParameterListNode), (yyvsp[0].stmtListNode));
        }
#line 3311 "parser.tab.cpp"
    break;

  case 154: /* classElement: propertyName typeAnnotationOpt ';'  */
#line 617 "parser.y"
        {
            Print("- R: propertyName typeAnnotationOpt ';' -> classElement");
            (yyval.classElementNode) = new ClassElementNode((yyvsp[-2].identName), (yyvsp[-1].typeNode), nullptr);
        }
#line 3320 "parser.tab.cpp"
    break;

  case 155: /* classElement: propertyName typeAnnotationOpt '=' singleExpression ';'  */
#line 622 "parser.y"
        {
            Print("- R: propertyName typeAnnotationOpt '=' singleExpression ';' -> classElement");
            (yyval.classElementNode) = new ClassElementNode((yyvsp[-4].identName), (yyvsp[-3].typeNode), (yyvsp[-1].exprNode));
        }
#line 3329 "parser.tab.cpp"
    break;

  case 156: /* classElement: propertyName '(' parameterList ')' typeAnnotationOpt functionBody  */
#line 629 "parser.y"
        {
            Print("- R: propertyName '(' parameterList ')' typeAnnotationOpt functionBody -> classElement");
            (yyval.classElementNode) = new ClassElementNode((yyvsp[-5].identName), (yyvsp[-3].requiredParameterListNode), (yyvsp[-1].typeNode), (yyvsp[0].stmtListNode));
        }
#line 3338 "parser.tab.cpp"
    break;

  case 157: /* classElement: GET propertyName '(' ')' typeAnnotationOpt functionBody  */
#line 636 "parser.y"
        {
            Print("- R: GET propertyName '(' ')' typeAnnotationOpt functionBody -> classElement");
            (yyval.classElementNode) = new ClassElementNode((yyvsp[-4].identName), nullptr, (yyvsp[-1].typeNode), (yyvsp[0].stmtListNode));
        }
#line 3347 "parser.tab.cpp"
    break;

  case 158: /* classElement: SET propertyName '(' parameterList ')' functionBody  */
#line 641 "parser.y"
        {
            Print("- R: SET propertyName callSignature functionBody -> classElement");
            (yyval.classElementNode) = new ClassElementNode((yyvsp[-4].identName), (yyvsp[-2].requiredParameterListNode), nullptr, (yyvsp[0].stmtListNode));
        }
#line 3356 "parser.tab.cpp"
    break;

  case 159: /* propertyName: identifier  */
#line 648 "parser.y"
                 { Print("- R: identifier -> propertyName"); }
#line 3362 "parser.tab.cpp"
    break;

  case 160: /* identifier: ID  */
#line 652 "parser.y"
                { Print("- R: ID -> identifier"); (yyval.identName) = (yyvsp[0].identName); }
#line 3368 "parser.tab.cpp"
    break;

  case 161: /* identifier: ASYNC  */
#line 653 "parser.y"
                { Print("- R: ASYNC -> identifier"); (yyval.identName) = strdup("async"); }
#line 3374 "parser.tab.cpp"
    break;

  case 162: /* identifier: AS  */
#line 654 "parser.y"
                { Print("- R: AS -> identifier"); (yyval.identName) = strdup("as"); }
#line 3380 "parser.tab.cpp"
    break;

  case 163: /* identifier: FROM  */
#line 655 "parser.y"
                { Print("- R: FROM -> identifier"); (yyval.identName) = strdup("from"); }
#line 3386 "parser.tab.cpp"
    break;

  case 164: /* identifier: YIELD  */
#line 656 "parser.y"
                { Print("- R: YIELD -> identifier"); (yyval.identName) = strdup("yield"); }
#line 3392 "parser.tab.cpp"
    break;

  case 165: /* identifier: ANY  */
#line 657 "parser.y"
                { Print("- R: ANY -> identifier"); (yyval.identName) = strdup("any"); }
#line 3398 "parser.tab.cpp"
    break;

  case 166: /* identifier: NUMBER  */
#line 658 "parser.y"
                { Print("- R: NUMBER -> identifier"); (yyval.identName) = strdup("number"); }
#line 3404 "parser.tab.cpp"
    break;

  case 167: /* identifier: BOOLEAN  */
#line 659 "parser.y"
                { Print("- R: BOOLEAN -> identifier"); (yyval.identName) = strdup("boolean"); }
#line 3410 "parser.tab.cpp"
    break;

  case 168: /* identifier: STRING  */
#line 660 "parser.y"
                { Print("- R: STRING -> identifier"); (yyval.identName) = strdup("string"); }
#line 3416 "parser.tab.cpp"
    break;

  case 169: /* identifier: UNIQUE  */
#line 661 "parser.y"
                { Print("- R: UNIQUE -> identifier"); (yyval.identName) = strdup("unique"); }
#line 3422 "parser.tab.cpp"
    break;

  case 170: /* identifier: SYMBOL  */
#line 662 "parser.y"
                { Print("- R: SYMBOL -> identifier"); (yyval.identName) = strdup("symbol"); }
#line 3428 "parser.tab.cpp"
    break;

  case 171: /* identifier: NEVER  */
#line 663 "parser.y"
                { Print("- R: NEVER -> identifier"); (yyval.identName) = strdup("never"); }
#line 3434 "parser.tab.cpp"
    break;

  case 172: /* identifier: OBJECT  */
#line 664 "parser.y"
                { Print("- R: OBJECT -> identifier"); (yyval.identName) = strdup("object"); }
#line 3440 "parser.tab.cpp"
    break;

  case 173: /* identifier: KEYOF  */
#line 665 "parser.y"
                { Print("- R: KEYOF -> identifier"); (yyval.identName) = strdup("keyof"); }
#line 3446 "parser.tab.cpp"
    break;

  case 174: /* identifier: NAMESPACE  */
#line 666 "parser.y"
                { Print("- R: NAMESPACE -> identifier"); (yyval.identName) = strdup("namespace"); }
#line 3452 "parser.tab.cpp"
    break;

  case 175: /* identifier: ABSTRACT  */
#line 667 "parser.y"
                { Print("- R: ABSTRACT -> identifier"); (yyval.identName) = strdup("abstract"); }
#line 3458 "parser.tab.cpp"
    break;

  case 176: /* identifier: REQUIRE  */
#line 668 "parser.y"
                { Print("- R: REQUIRE -> identifier"); (yyval.identName) = strdup("require"); }
#line 3464 "parser.tab.cpp"
    break;


#line 3468 "parser.tab.cpp"

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
  *++yylsp = yyloc;

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
          = {yyssp, yytoken, &yylloc};
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

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
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

#line 671 "parser.y"



void yyerror(const char* s) {
    syntaxErrorCounter++;
    std::string text(yytext_ptr, yyleng);

    fprintf(stderr, ">> SyntaxError: Line:%d. Text: %s. Error: %s <<\n", yylloc.first_line, text.c_str(), s);
}

bool checkOnSyntaxError(int yychar, int yyn, int yystate, short *yyssp) {
    yysymbol_kind_t yytoken = YYTRANSLATE(yychar); // getting char class

start: 
    yyn = yypact[yystate]; // first action index
    if (yypact_value_is_default(yyn)) {
        goto defact;
    }

    yyn += yytoken; // calc index inside yytable

    if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken) {
        /* default action */
defact: 
        yyn = yydefact[yystate];

        if (yyn == 0) { // syntax error
            return true;
        }
        goto reduce;
    }
    // table contains action 
    yyn = yytable[yyn];

    if (yyn <= 0) { // reduce case
        yyn = -yyn;
reduce:     
        yyssp -= yyr2[yyn];
        const int yylhs = yyr1[yyn] - YYNTOKENS;
        const int yyi = yypgoto[yylhs] + *yyssp;
        yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
                ? yytable[yyi]
                : yydefgoto[yylhs]);
        yyssp++;
        goto start;

    } else { // shift case
        return false;
    }
}

int simpleASI(int yychar, int yyn, int yystate, short *yyssp) {
    if (checkOnSyntaxError(yychar, yyn, yystate, yyssp)) {
        
        if (checkOnSyntaxError(';', yyn, yystate, yyssp)) {
            return yychar;
        }

        std::string yytext_str = std::string{yytext_ptr};
        if (yytext_str == "") {
            yytext_str = "<EOF>";
        }

        if (yytext_str != "<EOF>") { 
            rescanTokenString(yytext_ptr);
        }

        if ( debug ) {
            Print("found syntax error on token: " + yytext_str + ". inserted ';' as token", yylloc.first_line);
        }
        isASIActivated = 1;
        return ';';
    }
    return yychar;
}


/* Implementing part of automatic semicolon insertion of TypeScript / ECMAscript. 
 * This part is impelemnted first rule of semicolon insertion. 
 * See: https://262.ecma-international.org/14.0/#sec-unicode-format-control-characters:~:text=The%20offending%20token%20is%20separated%20from%20the%20previous%20token%20by%20at%20least%20one
 */
int yyfilter(int yychar, int yyn, int yystate, short *yyssp) {
    if (yychar == '}' && !isASIActivated) {
        return simpleASI(yychar, yyn, yystate, yyssp);
    }
    if (yychar == YYEOF && !isASIActivated) {
        return simpleASI(yychar, yyn, yystate, yyssp);
    }
    isASIActivated = 0;

    if (yychar != ENDL) {
        return yychar;
    }
    // Skiping multiple ENDL symbols
    do { yychar = yylex(); } while (yychar == ENDL); 

    if ( isInForHeader ) {
        return yychar;
    }

    std::string yytext_str = std::string{yytext_ptr};
    if (yytext_str == "") { 
        yytext_str = "<EOF>";
    }

    if ( debug ) {
        Print("skiped ENDL`s. jumped to: " + yytext_str);
    }

    return simpleASI(yychar, yyn, yystate, yyssp);
}


