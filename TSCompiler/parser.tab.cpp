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

#include "utils.h"

int debug = 1;
extern FILE* yyin;

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

#line 97 "parser.tab.cpp"

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
  YYSYMBOL_VAR = 3,                        /* VAR  */
  YYSYMBOL_LET = 4,                        /* LET  */
  YYSYMBOL_CONST = 5,                      /* CONST  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_ELSE = 7,                       /* ELSE  */
  YYSYMBOL_FUNCTION = 8,                   /* FUNCTION  */
  YYSYMBOL_CLASS = 9,                      /* CLASS  */
  YYSYMBOL_EXTENDS = 10,                   /* EXTENDS  */
  YYSYMBOL_GET = 11,                       /* GET  */
  YYSYMBOL_SET = 12,                       /* SET  */
  YYSYMBOL_DO = 13,                        /* DO  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_FOR = 15,                       /* FOR  */
  YYSYMBOL_RETURN = 16,                    /* RETURN  */
  YYSYMBOL_SUPER = 17,                     /* SUPER  */
  YYSYMBOL_THIS = 18,                      /* THIS  */
  YYSYMBOL_NEW = 19,                       /* NEW  */
  YYSYMBOL_ASYNC = 20,                     /* ASYNC  */
  YYSYMBOL_AS = 21,                        /* AS  */
  YYSYMBOL_FROM = 22,                      /* FROM  */
  YYSYMBOL_YIELD = 23,                     /* YIELD  */
  YYSYMBOL_KEYOF = 24,                     /* KEYOF  */
  YYSYMBOL_CONSTRUCTOR = 25,               /* CONSTRUCTOR  */
  YYSYMBOL_NAMESPACE = 26,                 /* NAMESPACE  */
  YYSYMBOL_ABSTRACT = 27,                  /* ABSTRACT  */
  YYSYMBOL_REQUIRE = 28,                   /* REQUIRE  */
  YYSYMBOL_ANY = 29,                       /* ANY  */
  YYSYMBOL_NUMBER = 30,                    /* NUMBER  */
  YYSYMBOL_BOOLEAN = 31,                   /* BOOLEAN  */
  YYSYMBOL_STRING = 32,                    /* STRING  */
  YYSYMBOL_NEVER = 33,                     /* NEVER  */
  YYSYMBOL_UNDEFINED = 34,                 /* UNDEFINED  */
  YYSYMBOL_UNIQUE = 35,                    /* UNIQUE  */
  YYSYMBOL_SYMBOL = 36,                    /* SYMBOL  */
  YYSYMBOL_OBJECT = 37,                    /* OBJECT  */
  YYSYMBOL_VOID = 38,                      /* VOID  */
  YYSYMBOL_UNKNOWN = 39,                   /* UNKNOWN  */
  YYSYMBOL_STRING_LIT = 40,                /* STRING_LIT  */
  YYSYMBOL_INT_LIT = 41,                   /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 42,                 /* FLOAT_LIT  */
  YYSYMBOL_NULL_KW = 43,                   /* NULL_KW  */
  YYSYMBOL_TRUE_KW = 44,                   /* TRUE_KW  */
  YYSYMBOL_FALSE_KW = 45,                  /* FALSE_KW  */
  YYSYMBOL_ID = 46,                        /* ID  */
  YYSYMBOL_ENDL = 47,                      /* ENDL  */
  YYSYMBOL_TEMPLATE_LITERAL = 48,          /* TEMPLATE_LITERAL  */
  YYSYMBOL_OPERATOR_INCREMENT = 49,        /* OPERATOR_INCREMENT  */
  YYSYMBOL_OPERATOR_DECREMENT = 50,        /* OPERATOR_DECREMENT  */
  YYSYMBOL_ENDL_OPERATOR_INCREMENT = 51,   /* ENDL_OPERATOR_INCREMENT  */
  YYSYMBOL_ENDL_OPERATOR_DECREMENT = 52,   /* ENDL_OPERATOR_DECREMENT  */
  YYSYMBOL_IF_ONLY_PREC = 53,              /* IF_ONLY_PREC  */
  YYSYMBOL_54_ = 54,                       /* ','  */
  YYSYMBOL_COMMA_OPERATOR = 55,            /* COMMA_OPERATOR  */
  YYSYMBOL_COMMA_SEPARATOR = 56,           /* COMMA_SEPARATOR  */
  YYSYMBOL_57_ = 57,                       /* '='  */
  YYSYMBOL_OPERATOR_ASSIGN_PLUS = 58,      /* OPERATOR_ASSIGN_PLUS  */
  YYSYMBOL_OPERATOR_ASSIGN_MINUS = 59,     /* OPERATOR_ASSIGN_MINUS  */
  YYSYMBOL_OPERATOR_ASSIGN_MULTIPLY = 60,  /* OPERATOR_ASSIGN_MULTIPLY  */
  YYSYMBOL_OPERATOR_ASSIGN_DIVIDE = 61,    /* OPERATOR_ASSIGN_DIVIDE  */
  YYSYMBOL_OPERATOR_ASSIGN_LOGICAL_AND = 62, /* OPERATOR_ASSIGN_LOGICAL_AND  */
  YYSYMBOL_OPERATOR_ASSIGN_LOGICAL_OR = 63, /* OPERATOR_ASSIGN_LOGICAL_OR  */
  YYSYMBOL_64_ = 64,                       /* '?'  */
  YYSYMBOL_65_ = 65,                       /* ':'  */
  YYSYMBOL_OPERATOR_LOGICAL_OR = 66,       /* OPERATOR_LOGICAL_OR  */
  YYSYMBOL_OPERATOR_LOGICAL_AND = 67,      /* OPERATOR_LOGICAL_AND  */
  YYSYMBOL_68_ = 68,                       /* '|'  */
  YYSYMBOL_69_ = 69,                       /* '^'  */
  YYSYMBOL_70_ = 70,                       /* '&'  */
  YYSYMBOL_OPERATOR_EQUAL = 71,            /* OPERATOR_EQUAL  */
  YYSYMBOL_OPERATOR_NOT_EQUAL = 72,        /* OPERATOR_NOT_EQUAL  */
  YYSYMBOL_OPERATOR_STRICT_EQUAL = 73,     /* OPERATOR_STRICT_EQUAL  */
  YYSYMBOL_OPERATOR_STRICT_NOT_EQUAL = 74, /* OPERATOR_STRICT_NOT_EQUAL  */
  YYSYMBOL_75_ = 75,                       /* '>'  */
  YYSYMBOL_76_ = 76,                       /* '<'  */
  YYSYMBOL_OPERATOR_GREATER_THAN_EQUAL = 77, /* OPERATOR_GREATER_THAN_EQUAL  */
  YYSYMBOL_OPERATOR_LESS_THAN_EQUAL = 78,  /* OPERATOR_LESS_THAN_EQUAL  */
  YYSYMBOL_INSTANCEOF = 79,                /* INSTANCEOF  */
  YYSYMBOL_IN = 80,                        /* IN  */
  YYSYMBOL_81_ = 81,                       /* '+'  */
  YYSYMBOL_82_ = 82,                       /* '-'  */
  YYSYMBOL_83_ = 83,                       /* '*'  */
  YYSYMBOL_84_ = 84,                       /* '/'  */
  YYSYMBOL_85_ = 85,                       /* '%'  */
  YYSYMBOL_86_ = 86,                       /* '!'  */
  YYSYMBOL_87_ = 87,                       /* '~'  */
  YYSYMBOL_UMINUS = 88,                    /* UMINUS  */
  YYSYMBOL_UPLUS = 89,                     /* UPLUS  */
  YYSYMBOL_PREF_INCREMENT = 90,            /* PREF_INCREMENT  */
  YYSYMBOL_PREF_DECREMENT = 91,            /* PREF_DECREMENT  */
  YYSYMBOL_POST_INCREMENT = 92,            /* POST_INCREMENT  */
  YYSYMBOL_POST_DECREMENT = 93,            /* POST_DECREMENT  */
  YYSYMBOL_94_ = 94,                       /* '.'  */
  YYSYMBOL_95_ = 95,                       /* '['  */
  YYSYMBOL_96_ = 96,                       /* ']'  */
  YYSYMBOL_ENDL_BRACKET_OPEN = 97,         /* ENDL_BRACKET_OPEN  */
  YYSYMBOL_OPTIONAL_CHAINING_OPERATOR = 98, /* OPTIONAL_CHAINING_OPERATOR  */
  YYSYMBOL_99_ = 99,                       /* '('  */
  YYSYMBOL_100_ = 100,                     /* ')'  */
  YYSYMBOL_101_ = 101,                     /* ';'  */
  YYSYMBOL_102_ = 102,                     /* '{'  */
  YYSYMBOL_103_ = 103,                     /* '}'  */
  YYSYMBOL_YYACCEPT = 104,                 /* $accept  */
  YYSYMBOL_script = 105,                   /* script  */
  YYSYMBOL_globalStatementList = 106,      /* globalStatementList  */
  YYSYMBOL_statementList = 107,            /* statementList  */
  YYSYMBOL_statementListItem = 108,        /* statementListItem  */
  YYSYMBOL_statementListItemWithoutEmptyStatement = 109, /* statementListItemWithoutEmptyStatement  */
  YYSYMBOL_emptyStatement = 110,           /* emptyStatement  */
  YYSYMBOL_blockStatement = 111,           /* blockStatement  */
  YYSYMBOL_initializer = 112,              /* initializer  */
  YYSYMBOL_type = 113,                     /* type  */
  YYSYMBOL_primaryType = 114,              /* primaryType  */
  YYSYMBOL_tupleTypeElements = 115,        /* tupleTypeElements  */
  YYSYMBOL_predefinedType = 116,           /* predefinedType  */
  YYSYMBOL_typeAnnotationOpt = 117,        /* typeAnnotationOpt  */
  YYSYMBOL_typeAnnotation = 118,           /* typeAnnotation  */
  YYSYMBOL_simpleLiteral = 119,            /* simpleLiteral  */
  YYSYMBOL_arrayLiteral = 120,             /* arrayLiteral  */
  YYSYMBOL_elementList = 121,              /* elementList  */
  YYSYMBOL_elementListItem = 122,          /* elementListItem  */
  YYSYMBOL_expressionStatement = 123,      /* expressionStatement  */
  YYSYMBOL_singleExpressionOpt = 124,      /* singleExpressionOpt  */
  YYSYMBOL_singleExpression = 125,         /* singleExpression  */
  YYSYMBOL_varStatement = 126,             /* varStatement  */
  YYSYMBOL_varDeclarationList = 127,       /* varDeclarationList  */
  YYSYMBOL_varDeclaration = 128,           /* varDeclaration  */
  YYSYMBOL_varModifier = 129,              /* varModifier  */
  YYSYMBOL_ifStatement = 130,              /* ifStatement  */
  YYSYMBOL_iterationStatement = 131,       /* iterationStatement  */
  YYSYMBOL_132_1 = 132,                    /* $@1  */
  YYSYMBOL_133_2 = 133,                    /* $@2  */
  YYSYMBOL_134_3 = 134,                    /* $@3  */
  YYSYMBOL_135_4 = 135,                    /* $@4  */
  YYSYMBOL_136_5 = 136,                    /* $@5  */
  YYSYMBOL_forHeader = 137,                /* forHeader  */
  YYSYMBOL_returnStatement = 138,          /* returnStatement  */
  YYSYMBOL_functionDeclaration = 139,      /* functionDeclaration  */
  YYSYMBOL_functionBody = 140,             /* functionBody  */
  YYSYMBOL_141_6 = 141,                    /* $@6  */
  YYSYMBOL_callSignature = 142,            /* callSignature  */
  YYSYMBOL_parameterList = 143,            /* parameterList  */
  YYSYMBOL_requiredParameterList = 144,    /* requiredParameterList  */
  YYSYMBOL_requiredParameter = 145,        /* requiredParameter  */
  YYSYMBOL_classDeclaration = 146,         /* classDeclaration  */
  YYSYMBOL_classHeritage = 147,            /* classHeritage  */
  YYSYMBOL_classTail = 148,                /* classTail  */
  YYSYMBOL_classElementList = 149,         /* classElementList  */
  YYSYMBOL_classElement = 150,             /* classElement  */
  YYSYMBOL_constructorCallSignature = 151, /* constructorCallSignature  */
  YYSYMBOL_propertyName = 152,             /* propertyName  */
  YYSYMBOL_identifier = 153                /* identifier  */
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
#define YYFINAL  94
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2151

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  104
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  188
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  326

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   334


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
       2,     2,     2,    86,     2,     2,     2,    85,    70,     2,
      99,   100,    83,    81,    54,    82,    94,    84,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    65,   101,
      76,    57,    75,    64,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    95,     2,    96,    69,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   102,    68,   103,    87,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    55,
      56,    58,    59,    60,    61,    62,    63,    66,    67,    71,
      72,    73,    74,    77,    78,    79,    80,    88,    89,    90,
      91,    92,    93,    97,    98
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    85,    85,    96,    98,    99,   100,   101,   103,   104,
     108,   109,   113,   114,   115,   116,   117,   118,   125,   129,
     130,   131,   132,   133,   140,   142,   146,   157,   158,   162,
     168,   172,   173,   174,   175,   176,   180,   181,   182,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   201,   202,   206,   210,   211,   212,   213,   218,   219,
     223,   224,   228,   229,   230,   236,   240,   241,   245,   246,
     247,   248,   249,   250,   251,   253,   254,   256,   258,   259,
     261,   262,   263,   264,   266,   267,   268,   269,   270,   271,
     273,   276,   279,   282,   285,   288,   291,   294,   297,   300,
     303,   306,   309,   312,   315,   318,   319,   321,   324,   327,
     330,   332,   333,   334,   336,   339,   341,   342,   343,   345,
     351,   352,   356,   357,   361,   362,   366,   367,   368,   374,
     377,   384,   384,   387,   390,   390,   393,   393,   396,   396,
     399,   399,   404,   410,   411,   415,   419,   420,   420,   424,
     428,   429,   430,   434,   435,   439,   445,   446,   450,   454,
     455,   459,   460,   464,   467,   468,   471,   474,   475,   479,
     483,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504
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
  "\"end of file\"", "error", "\"invalid token\"", "VAR", "LET", "CONST",
  "IF", "ELSE", "FUNCTION", "CLASS", "EXTENDS", "GET", "SET", "DO",
  "WHILE", "FOR", "RETURN", "SUPER", "THIS", "NEW", "ASYNC", "AS", "FROM",
  "YIELD", "KEYOF", "CONSTRUCTOR", "NAMESPACE", "ABSTRACT", "REQUIRE",
  "ANY", "NUMBER", "BOOLEAN", "STRING", "NEVER", "UNDEFINED", "UNIQUE",
  "SYMBOL", "OBJECT", "VOID", "UNKNOWN", "STRING_LIT", "INT_LIT",
  "FLOAT_LIT", "NULL_KW", "TRUE_KW", "FALSE_KW", "ID", "ENDL",
  "TEMPLATE_LITERAL", "OPERATOR_INCREMENT", "OPERATOR_DECREMENT",
  "ENDL_OPERATOR_INCREMENT", "ENDL_OPERATOR_DECREMENT", "IF_ONLY_PREC",
  "','", "COMMA_OPERATOR", "COMMA_SEPARATOR", "'='",
  "OPERATOR_ASSIGN_PLUS", "OPERATOR_ASSIGN_MINUS",
  "OPERATOR_ASSIGN_MULTIPLY", "OPERATOR_ASSIGN_DIVIDE",
  "OPERATOR_ASSIGN_LOGICAL_AND", "OPERATOR_ASSIGN_LOGICAL_OR", "'?'",
  "':'", "OPERATOR_LOGICAL_OR", "OPERATOR_LOGICAL_AND", "'|'", "'^'",
  "'&'", "OPERATOR_EQUAL", "OPERATOR_NOT_EQUAL", "OPERATOR_STRICT_EQUAL",
  "OPERATOR_STRICT_NOT_EQUAL", "'>'", "'<'", "OPERATOR_GREATER_THAN_EQUAL",
  "OPERATOR_LESS_THAN_EQUAL", "INSTANCEOF", "IN", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'!'", "'~'", "UMINUS", "UPLUS", "PREF_INCREMENT",
  "PREF_DECREMENT", "POST_INCREMENT", "POST_DECREMENT", "'.'", "'['",
  "']'", "ENDL_BRACKET_OPEN", "OPTIONAL_CHAINING_OPERATOR", "'('", "')'",
  "';'", "'{'", "'}'", "$accept", "script", "globalStatementList",
  "statementList", "statementListItem",
  "statementListItemWithoutEmptyStatement", "emptyStatement",
  "blockStatement", "initializer", "type", "primaryType",
  "tupleTypeElements", "predefinedType", "typeAnnotationOpt",
  "typeAnnotation", "simpleLiteral", "arrayLiteral", "elementList",
  "elementListItem", "expressionStatement", "singleExpressionOpt",
  "singleExpression", "varStatement", "varDeclarationList",
  "varDeclaration", "varModifier", "ifStatement", "iterationStatement",
  "$@1", "$@2", "$@3", "$@4", "$@5", "forHeader", "returnStatement",
  "functionDeclaration", "functionBody", "$@6", "callSignature",
  "parameterList", "requiredParameterList", "requiredParameter",
  "classDeclaration", "classHeritage", "classTail", "classElementList",
  "classElement", "constructorCallSignature", "propertyName", "identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-255)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     309,  -255,  -255,  -255,  -255,   -78,   746,   746,   814,   -76,
     -74,   983,  -255,  -255,  1236,  -255,  -255,  -255,  -255,  -255,
    -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,
    -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,
    1236,  1236,  1236,  1236,  1236,  1236,  1236,  1236,  1236,  1236,
    -255,   511,    28,   128,   814,  -255,  -255,  -255,  -255,  -255,
    -255,  1280,  -255,   346,  -255,  -255,   900,  -255,  -255,  -255,
    -255,  1236,   -70,    -9,    16,  1236,  -255,  -255,  1334,   -16,
     -16,   -16,   -16,   -16,   -16,   -16,   -16,   -40,  -255,  1862,
     -39,  1388,  -255,   612,  -255,  -255,  -255,  -255,  -255,  -255,
    -255,  -255,  1236,  1236,  1236,  1236,  1236,  1236,  1236,  1236,
    1236,  1236,  1236,  1236,  1236,  1236,  1236,  1236,  1236,  1236,
    1236,  1236,  1236,  1236,  1236,  1236,  1236,   746,  1236,  1236,
    1236,  1068,  -255,   -69,   -51,  -255,   -21,   -56,  1914,   746,
    1441,   746,   -71,   746,   140,   -55,  -255,   -46,  1494,  -255,
    1236,  -255,  1236,  -255,  -255,  -255,  2052,  2052,  2052,  2052,
    2052,  2052,  2052,  2052,  1706,   501,   602,   170,   170,   170,
     170,   303,   303,   303,   303,   303,   303,    -7,    -7,   -16,
     -16,  -255,  1758,  1810,   -45,  -255,  1547,  -255,   746,  -255,
     186,     7,  -255,  1236,  1236,   -42,   -32,   411,   -25,    -5,
    -255,   -21,   -37,  -255,  -255,   746,   746,   -19,  -255,   856,
    -255,   -41,  -255,  -255,  1236,   814,  -255,  1236,  -255,  -255,
    1152,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,
    -255,  -255,  -255,  -255,   186,   186,   186,  -255,   -11,  -255,
    -255,  1236,   -15,  1966,   205,  1236,  1236,  -255,    82,  -255,
    -255,  -255,  -255,  -255,  -255,   -21,   746,  -255,  -255,   814,
      -4,   -70,   746,   -71,  -255,  -255,   -50,   -71,  1600,  -255,
     401,  -255,  -255,   -35,   -34,    30,    -2,  2009,  1236,  -255,
      32,  1653,   814,  -255,  -255,   713,    34,   -71,    35,  -255,
    1236,  -255,    37,  -255,  -255,   186,  -255,  -255,  -255,  -255,
      39,   814,  1236,  -255,  -255,  -255,   -21,  -255,  -255,  1966,
    -255,    40,  -255,  -255,  -255,    42,   814,   -71,  -255,   814,
    -255,  -255,  -255,  -255,   814,  -255
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     8,   126,   127,   128,     0,     0,     0,     0,     0,
       0,     0,    71,    70,     0,   172,   173,   174,   175,   185,
     186,   187,   188,   176,   177,   178,   179,   182,   183,   180,
     181,   184,    54,    55,    56,    74,    72,    73,   171,    57,
       0,     0,     0,     0,     0,     0,     0,    62,    62,     0,
      26,     0,     0,     0,     3,    10,    12,    18,    69,   116,
      13,     0,    14,     0,    15,    16,    66,    17,     4,     5,
      68,     0,     0,     0,     0,     0,   142,   143,     0,   119,
      82,    83,    80,    81,    76,    75,    77,     0,    60,    63,
       0,     0,    27,     0,     1,     9,     6,     7,    11,   107,
      78,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    65,     0,     0,   122,    51,     0,    67,     0,
       0,   150,     0,     0,     0,     0,   156,     0,     0,   144,
      62,    58,    64,    59,   110,    28,   109,    96,    99,   100,
      97,    98,   101,   102,     0,   103,   104,    90,    91,    92,
      93,    89,    88,    95,    94,   105,   106,    84,    85,    86,
      87,   115,     0,     0,   114,   111,     0,   121,     0,   120,
       0,   124,    52,    66,     0,     0,   122,     0,     0,   151,
     153,    51,   147,   145,   158,     0,     0,     0,   159,     0,
     161,    51,   170,   157,     0,     0,    61,     0,   117,   118,
       0,   112,   123,    39,    40,    42,    41,    43,    45,    46,
      44,    47,    48,    49,    36,    36,     0,    53,    30,    32,
      50,     0,     0,    67,   106,    66,     0,    25,   129,    24,
      19,    20,    21,    22,    23,    51,   152,   155,   146,     0,
       0,     0,   150,     0,   160,   162,     0,     0,     0,   133,
     108,   113,    37,     0,     0,     0,     0,   125,    66,   138,
       0,     0,     0,   149,   154,     0,     0,     0,     0,   163,
       0,   164,     0,   166,   131,     0,    34,    35,    31,    33,
       0,     0,    66,   140,   130,   148,    51,   168,   169,    29,
     165,     0,    38,   134,   139,     0,     0,     0,   132,     0,
     136,   141,   167,   135,     0,   137
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -255,  -255,  -255,   -47,    -8,  -255,  -255,   -57,  -255,  -168,
    -255,   -86,  -255,  -185,  -255,  -163,  -255,   102,     3,   -43,
    -119,    -6,   -18,    17,  -133,    89,   -17,   -13,  -255,  -255,
    -255,  -255,  -255,  -255,   -12,   104,  -254,  -255,  -209,  -104,
    -255,   -75,   125,  -255,    44,  -255,   -27,  -255,  -188,     4
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    52,    53,    54,    55,   248,    56,    57,   292,   272,
     238,   273,   239,   191,   192,    58,    59,    87,    88,    60,
     137,    61,    62,   134,   135,    63,    64,    65,   311,   319,
     324,   301,   316,    66,    67,    68,   203,   259,   142,   198,
     199,   200,    69,   145,   146,   209,   210,   263,   211,    70
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      74,   143,   267,   188,    93,    78,   196,   290,    79,   289,
      72,    73,   188,   293,   150,   150,   257,   260,   261,   295,
     295,    71,   237,    75,   190,    76,   266,   240,    94,   141,
     147,   202,   187,   307,    80,    81,    82,    83,    84,    85,
      86,    89,    89,    91,   190,   193,    98,   144,   246,   256,
     189,   291,   287,   214,   131,   222,   151,   153,   141,   245,
     138,   296,   297,   322,   241,   140,   258,   136,   275,   148,
     283,   240,   240,   240,   242,   255,   125,   126,   127,   128,
     262,   129,   130,   131,   276,    98,   278,   127,   128,   282,
     129,   130,   131,   144,   299,   286,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   317,   182,   183,   184,   186,   280,   312,    -2,    95,
     298,   181,   240,   302,   306,   308,     6,     7,   310,   313,
     249,   318,   320,   136,    89,   201,   156,   204,   212,   274,
      90,   205,   206,   216,   250,   139,   195,    96,   288,   300,
      15,    16,    17,    18,    19,   207,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    97,   251,
     252,   284,   265,   315,   253,   254,    38,   243,   244,   213,
       0,     0,   136,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   269,   268,   212,
     212,   270,   285,   212,   156,   223,   224,   225,   226,   227,
     228,     0,     0,     0,   229,   230,    32,    33,    34,   231,
     232,   233,     0,     0,    39,   277,     0,     0,     0,   243,
     281,     0,     0,   208,     0,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,     0,     0,     0,     0,     0,
     201,     0,     0,     0,   127,   128,   201,   129,   130,   131,
       0,     0,   243,     0,   304,     0,     0,    98,     0,     0,
       0,   234,     0,   235,   309,   236,   123,   124,   125,   126,
       0,     0,     0,   314,     0,     0,   243,     0,     0,   127,
     128,     0,   129,   130,   131,   279,     0,     0,   321,     0,
       1,   323,     2,     3,     4,     5,   325,     6,     7,     0,
       0,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,     0,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,   133,     0,    32,
      33,    34,    35,    36,    37,    38,     0,    39,    40,    41,
      42,    43,     0,     0,     0,     0,    15,    16,    17,    18,
      19,     0,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,   123,   124,   125,   126,     0,     0,
      44,    45,    38,     0,     0,    46,     0,   127,   128,     0,
     129,   130,   131,     0,    47,     0,    48,     0,    49,     0,
      50,    51,   247,     0,     2,     3,     4,     5,     0,     0,
       0,     0,     0,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,     0,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     0,
       0,    32,    33,    34,    35,    36,    37,    38,     0,    39,
      40,    41,    42,    43,     0,     0,     0,   111,   112,     0,
       0,     0,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,     0,     0,     0,     0,
       0,     0,    44,    45,     0,   127,   128,    46,   129,   130,
     131,     0,     0,     0,     0,     0,    47,     0,    48,     0,
      49,     0,     0,    51,     2,     3,     4,     5,     0,     0,
       0,     0,     0,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,     0,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     0,
       0,    32,    33,    34,    35,    36,    37,    38,     0,    39,
      40,    41,    42,    43,     0,     0,     0,     0,   112,     0,
       0,     0,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,     0,     0,     0,     0,
       0,     0,    44,    45,     0,   127,   128,    46,   129,   130,
     131,     0,     0,     0,     0,     0,    47,     0,    48,     0,
      49,     0,    50,    51,    92,     2,     3,     4,     5,     0,
       0,     0,     0,     0,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,     0,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       0,     0,    32,    33,    34,    35,    36,    37,    38,     0,
      39,    40,    41,    42,    43,     0,     0,     0,     0,     0,
       0,     0,     0,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     0,     0,     0,
       0,     0,     0,    44,    45,     0,   127,   128,    46,   129,
     130,   131,     0,     0,     0,     0,     0,    47,     0,    48,
       0,    49,     0,    50,    51,   155,     2,     3,     4,     5,
       0,     0,     0,     0,     0,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     0,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     0,     0,    32,    33,    34,    35,    36,    37,    38,
       0,    39,    40,    41,    42,    43,    15,    16,    17,    18,
      19,     0,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,    44,    45,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     0,
      48,     0,    49,     0,    50,    51,   305,     2,     3,     4,
       5,     0,     0,     0,     0,     0,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,     0,    32,    33,    34,    35,    36,    37,
      38,     0,    39,    40,    41,    42,    43,   205,   206,     0,
       0,     0,     0,     0,     0,     0,    15,    16,    17,    18,
      19,   207,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,    44,    45,     0,     0,     0,
      46,     0,    38,     2,     3,     4,     0,     0,     0,    47,
       0,    48,     0,    49,     0,    50,    51,    12,    13,    14,
      15,    16,    17,    18,    19,     0,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     0,     0,
      32,    33,    34,    35,    36,    37,    38,     0,    39,    40,
      41,    42,    43,     0,     0,     0,     0,     0,     0,   264,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    44,    45,     0,     0,     0,    46,     0,     0,     0,
       0,     0,     0,     0,     0,    47,     0,    48,     0,    49,
      12,    13,    14,    15,    16,    17,    18,    19,     0,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     0,     0,    32,    33,    34,    35,    36,    37,    38,
       0,    39,    40,    41,    42,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,    45,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     0,
      48,     0,    49,     0,    77,    12,    13,    14,    15,    16,
      17,    18,    19,     0,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,     0,     0,    32,    33,
      34,    35,    36,    37,    38,     0,    39,    40,    41,    42,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
      45,     0,     0,     0,    46,     0,     0,     0,     0,     0,
       0,     0,     0,    47,     0,    48,     0,    49,   185,    12,
      13,    14,    15,    16,    17,    18,    19,     0,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       0,     0,    32,    33,    34,    35,    36,    37,    38,     0,
      39,    40,    41,    42,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,    45,     0,     0,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     0,    48,
       0,    49,   271,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,     0,    32,    33,    34,    35,
      36,    37,    38,     0,    39,    40,    41,    42,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,    45,     0,
       0,     0,    46,     0,     0,     0,     0,     0,    99,   100,
     101,    47,     0,    48,   102,    49,     0,   103,   104,   105,
     106,   107,   108,   109,   110,     0,   111,   112,     0,     0,
       0,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   127,   128,     0,   129,   130,   131,
       0,   132,    99,   100,   101,     0,     0,     0,   102,     0,
       0,   103,   104,   105,   106,   107,   108,   109,   110,     0,
     111,   112,     0,     0,     0,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   127,   128,
       0,   129,   130,   131,     0,   149,    99,   100,   101,     0,
       0,     0,   102,     0,     0,   103,   104,   105,   106,   107,
     108,   109,   110,     0,   111,   112,     0,     0,     0,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   127,   128,     0,   129,   130,   131,   154,    99,
     100,   101,     0,     0,     0,   102,     0,     0,   103,   104,
     105,   106,   107,   108,   109,   110,     0,   111,   112,     0,
       0,     0,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,   128,     0,   129,   130,
     131,   197,    99,   100,   101,     0,     0,     0,   102,     0,
       0,   103,   104,   105,   106,   107,   108,   109,   110,     0,
     111,   112,     0,     0,     0,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   127,   128,
       0,   129,   130,   131,   215,    99,   100,   101,     0,     0,
       0,   220,     0,     0,   103,   104,   105,   106,   107,   108,
     109,   110,     0,   111,   112,     0,     0,     0,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,   128,     0,   129,   130,   131,   221,    99,   100,
     101,     0,     0,     0,   102,     0,     0,   103,   104,   105,
     106,   107,   108,   109,   110,     0,   111,   112,     0,     0,
       0,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   127,   128,     0,   129,   130,   131,
     294,    99,   100,   101,     0,     0,     0,   102,     0,     0,
     103,   104,   105,   106,   107,   108,   109,   110,     0,   111,
     112,     0,     0,     0,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,   128,     0,
     129,   130,   131,   303,    99,   100,   101,     0,     0,     0,
     102,     0,     0,   103,   104,   105,   106,   107,   108,   109,
     110,   217,   111,   112,     0,     0,     0,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     127,   128,     0,   129,   130,   131,    99,   100,   101,     0,
       0,     0,   102,     0,     0,   103,   104,   105,   106,   107,
     108,   109,   110,     0,   111,   112,     0,     0,     0,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   127,   128,   218,   129,   130,   131,    99,   100,
     101,     0,     0,     0,   102,     0,     0,   103,   104,   105,
     106,   107,   108,   109,   110,     0,   111,   112,     0,     0,
       0,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   127,   128,   219,   129,   130,   131,
      99,   100,   101,     0,     0,     0,   152,     0,     0,   103,
     104,   105,   106,   107,   108,   109,   110,     0,   111,   112,
       0,     0,     0,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   127,   128,     0,   129,
     130,   131,    99,   100,   101,     0,     0,     0,   102,     0,
       0,   103,   104,   105,   106,   107,   108,   109,   110,     0,
     111,   112,     0,     0,     0,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   194,   123,   124,   125,   126,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   127,   128,
       0,   129,   130,   131,    99,   100,   101,     0,     0,     0,
     102,     0,     0,   103,   104,   105,   106,   107,   108,   109,
     110,     0,   111,   112,     0,     0,     0,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,     0,     0,     0,     0,     0,     0,    99,   100,   101,
     127,   128,     0,   129,   130,   131,   103,   104,   105,   106,
     107,   108,   109,   110,     0,   111,   112,     0,     0,     0,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   127,   128,     0,   129,   130,   131,   103,
     104,   105,   106,   107,   108,   109,   110,     0,   111,   112,
       0,     0,     0,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   127,   128,     0,   129,
     130,   131
};

static const yytype_int16 yycheck[] =
{
       8,    10,   211,    54,    51,    11,   139,    57,    14,   263,
       6,     7,    54,   267,    54,    54,   201,   205,   206,    54,
      54,    99,   190,    99,    65,    99,   211,   190,     0,    99,
      14,   102,   101,   287,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    65,   101,    54,   102,    80,    54,
     101,   101,   261,    99,    99,   188,    96,    96,    99,   101,
      66,    96,    96,   317,    57,    71,   103,    63,   236,    75,
     255,   234,   235,   236,   193,   100,    83,    84,    94,    95,
      99,    97,    98,    99,    95,    93,   101,    94,    95,     7,
      97,    98,    99,   102,    96,    99,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   306,   128,   129,   130,   131,   245,   295,     0,     1,
     100,   127,   295,   101,   100,   100,     8,     9,   101,   100,
     197,   101,   100,   139,   150,   141,   152,   143,   144,   235,
      48,    11,    12,   150,   197,    66,   139,    53,   262,   278,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    53,   197,
     197,   256,   209,   302,   197,   197,    46,   193,   194,   145,
      -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,   214,   205,
     206,   217,   259,   209,   220,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    48,   241,    -1,    -1,    -1,   245,
     246,    -1,    -1,   103,    -1,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    94,    95,   262,    97,    98,    99,
      -1,    -1,   278,    -1,   282,    -1,    -1,   285,    -1,    -1,
      -1,    95,    -1,    97,   290,    99,    81,    82,    83,    84,
      -1,    -1,    -1,   301,    -1,    -1,   302,    -1,    -1,    94,
      95,    -1,    97,    98,    99,   100,    -1,    -1,   316,    -1,
       1,   319,     3,     4,     5,     6,   324,     8,     9,    -1,
      -1,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,     1,    -1,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    81,    82,    83,    84,    -1,    -1,
      81,    82,    46,    -1,    -1,    86,    -1,    94,    95,    -1,
      97,    98,    99,    -1,    95,    -1,    97,    -1,    99,    -1,
     101,   102,     1,    -1,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    -1,    94,    95,    86,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,    95,    -1,    97,    -1,
      99,    -1,    -1,   102,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    -1,    94,    95,    86,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,    95,    -1,    97,    -1,
      99,    -1,   101,   102,   103,     3,     4,     5,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    82,    -1,    94,    95,    86,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,    95,    -1,    97,
      -1,    99,    -1,   101,   102,   103,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    81,    82,    -1,    -1,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      97,    -1,    99,    -1,   101,   102,   103,     3,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    81,    82,    -1,    -1,    -1,
      86,    -1,    46,     3,     4,     5,    -1,    -1,    -1,    95,
      -1,    97,    -1,    99,    -1,   101,   102,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    49,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    82,    -1,    -1,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    -1,    97,    -1,    99,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      97,    -1,    99,    -1,   101,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      82,    -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    -1,    97,    -1,    99,   100,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    82,    -1,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    97,
      -1,    99,   100,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,
      -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    95,    -1,    97,    54,    99,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    67,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    -1,    97,    98,    99,
      -1,   101,    48,    49,    50,    -1,    -1,    -1,    54,    -1,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      -1,    97,    98,    99,    -1,   101,    48,    49,    50,    -1,
      -1,    -1,    54,    -1,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    97,    98,    99,   100,    48,
      49,    50,    -1,    -1,    -1,    54,    -1,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    97,    98,
      99,   100,    48,    49,    50,    -1,    -1,    -1,    54,    -1,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      -1,    97,    98,    99,   100,    48,    49,    50,    -1,    -1,
      -1,    54,    -1,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    66,    67,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    97,    98,    99,   100,    48,    49,
      50,    -1,    -1,    -1,    54,    -1,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    67,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    -1,    97,    98,    99,
     100,    48,    49,    50,    -1,    -1,    -1,    54,    -1,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,
      97,    98,    99,   100,    48,    49,    50,    -1,    -1,    -1,
      54,    -1,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    -1,    97,    98,    99,    48,    49,    50,    -1,
      -1,    -1,    54,    -1,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,    48,    49,
      50,    -1,    -1,    -1,    54,    -1,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    67,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,    99,
      48,    49,    50,    -1,    -1,    -1,    54,    -1,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    66,    67,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    97,
      98,    99,    48,    49,    50,    -1,    -1,    -1,    54,    -1,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      -1,    97,    98,    99,    48,    49,    50,    -1,    -1,    -1,
      54,    -1,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    66,    67,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      94,    95,    -1,    97,    98,    99,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    97,    98,    99,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    66,    67,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    97,
      98,    99
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     8,     9,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    40,    41,    42,    43,    44,    45,    46,    48,
      49,    50,    51,    52,    81,    82,    86,    95,    97,    99,
     101,   102,   105,   106,   107,   108,   110,   111,   119,   120,
     123,   125,   126,   129,   130,   131,   137,   138,   139,   146,
     153,    99,   153,   153,   108,    99,    99,   101,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   121,   122,   125,
     121,   125,   103,   107,     0,     1,   139,   146,   108,    48,
      49,    50,    54,    57,    58,    59,    60,    61,    62,    63,
      64,    66,    67,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    94,    95,    97,
      98,    99,   101,     1,   127,   128,   153,   124,   125,   129,
     125,    99,   142,    10,   102,   147,   148,    14,   125,   101,
      54,    96,    54,    96,   100,   103,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   153,   125,   125,   125,   100,   125,   101,    54,   101,
      65,   117,   118,   101,    80,   127,   128,   100,   143,   144,
     145,   153,   102,   140,   153,    11,    12,    25,   103,   149,
     150,   152,   153,   148,    99,   100,   122,    65,    96,    96,
      54,   100,   128,    29,    30,    31,    32,    33,    34,    38,
      39,    43,    44,    45,    95,    97,    99,   113,   114,   116,
     119,    57,   124,   125,   125,   101,    80,     1,   109,   111,
     123,   126,   130,   131,   138,   100,    54,   117,   103,   141,
     152,   152,    99,   151,   103,   150,   117,   142,   125,   108,
     125,   100,   113,   115,   115,   113,    95,   125,   101,   100,
     124,   125,     7,   117,   145,   107,    99,   142,   143,   140,
      57,   101,   112,   140,   100,    54,    96,    96,   100,    96,
     124,   135,   101,   100,   108,   103,   100,   140,   100,   125,
     101,   132,   113,   100,   108,   124,   136,   117,   101,   133,
     100,   108,   140,   108,   134,   108
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   104,   105,   106,   106,   106,   106,   106,   106,   106,
     107,   107,   108,   108,   108,   108,   108,   108,   108,   109,
     109,   109,   109,   109,   109,   109,   110,   111,   111,   112,
     113,   114,   114,   114,   114,   114,   115,   115,   115,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   117,   117,   118,   119,   119,   119,   119,   120,   120,
     121,   121,   122,   122,   122,   123,   124,   124,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     126,   126,   127,   127,   128,   128,   129,   129,   129,   130,
     130,   132,   131,   131,   133,   131,   134,   131,   135,   131,
     136,   131,   137,   138,   138,   139,   140,   141,   140,   142,
     143,   143,   143,   144,   144,   145,   146,   146,   147,   148,
     148,   149,   149,   150,   150,   150,   150,   150,   150,   151,
     152,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     1,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     2,
       1,     3,     1,     3,     3,     3,     0,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     2,     1,     1,     1,     1,     3,     3,
       1,     3,     0,     1,     2,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     5,     3,
       3,     3,     4,     5,     3,     3,     1,     4,     4,     2,
       3,     3,     1,     3,     2,     4,     1,     1,     1,     5,
       7,     0,     8,     5,     0,     9,     0,    10,     0,     7,
       0,     8,     2,     2,     3,     4,     2,     0,     4,     4,
       0,     1,     2,     1,     3,     2,     3,     4,     2,     2,
       3,     1,     2,     3,     3,     4,     3,     6,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
  case 2: /* script: globalStatementList  */
#line 86 "parser.y"
        { 
            if ( syntaxErrorCounter > 0 ) {
                PrintError("Found " + std::to_string(syntaxErrorCounter) + " syntax errors. Fix them and rerun.");
                exit(1);
            }
            Print("- R: globalStatementList -> script"); 
        }
#line 2245 "parser.tab.cpp"
    break;

  case 3: /* globalStatementList: statementList  */
#line 96 "parser.y"
                                                { Print("- R: statementList -> globalStatementList"); }
#line 2251 "parser.tab.cpp"
    break;

  case 4: /* globalStatementList: functionDeclaration  */
#line 98 "parser.y"
                                                { Print("- R: functionDeclaration -> globalStatementList"); }
#line 2257 "parser.tab.cpp"
    break;

  case 5: /* globalStatementList: classDeclaration  */
#line 99 "parser.y"
                                                { Print("- R: classDeclaration -> globalStatementList"); }
#line 2263 "parser.tab.cpp"
    break;

  case 6: /* globalStatementList: globalStatementList functionDeclaration  */
#line 100 "parser.y"
                                                { Print("- R: globalStatementList functionDeclaration -> globalStatementList"); }
#line 2269 "parser.tab.cpp"
    break;

  case 7: /* globalStatementList: globalStatementList classDeclaration  */
#line 101 "parser.y"
                                                { Print("- R: globalStatementList classDeclaration -> globalStatementList"); }
#line 2275 "parser.tab.cpp"
    break;

  case 10: /* statementList: statementListItem  */
#line 108 "parser.y"
                                        { Print("- R: statementListItem -> statementList"); }
#line 2281 "parser.tab.cpp"
    break;

  case 11: /* statementList: statementList statementListItem  */
#line 109 "parser.y"
                                        { Print("- R: statementList statementListItem -> statementList"); }
#line 2287 "parser.tab.cpp"
    break;

  case 12: /* statementListItem: emptyStatement  */
#line 113 "parser.y"
                                    { Print("- R: emptyStatement -> statementListItem"); }
#line 2293 "parser.tab.cpp"
    break;

  case 13: /* statementListItem: expressionStatement  */
#line 114 "parser.y"
                                    { Print("- R: expressionStatement -> statementListItem"); }
#line 2299 "parser.tab.cpp"
    break;

  case 14: /* statementListItem: varStatement  */
#line 115 "parser.y"
                                    { Print("- R: varStatement -> statementListItem"); }
#line 2305 "parser.tab.cpp"
    break;

  case 15: /* statementListItem: ifStatement  */
#line 116 "parser.y"
                                    { Print("- R: ifStatement -> statementListItem"); }
#line 2311 "parser.tab.cpp"
    break;

  case 16: /* statementListItem: iterationStatement  */
#line 117 "parser.y"
                                    { Print("- R: iterationStatement -> statementListItem"); }
#line 2317 "parser.tab.cpp"
    break;

  case 17: /* statementListItem: returnStatement  */
#line 119 "parser.y"
        { 
            if ( !isInFunctionBody ) { 
                yyerror("illegal return statement."); YYERROR;
            } 
            Print("- R: returnStatement -> statementListItem"); 
        }
#line 2328 "parser.tab.cpp"
    break;

  case 18: /* statementListItem: blockStatement  */
#line 125 "parser.y"
                                    { Print("- R: blockStatement -> statementListItem"); }
#line 2334 "parser.tab.cpp"
    break;

  case 19: /* statementListItemWithoutEmptyStatement: expressionStatement  */
#line 129 "parser.y"
                                    { Print("- R: expressionStatement -> statementListItemWithoutEmptyStatement"); }
#line 2340 "parser.tab.cpp"
    break;

  case 20: /* statementListItemWithoutEmptyStatement: varStatement  */
#line 130 "parser.y"
                                    { Print("- R: varStatement -> statementListItemWithoutEmptyStatement"); }
#line 2346 "parser.tab.cpp"
    break;

  case 21: /* statementListItemWithoutEmptyStatement: ifStatement  */
#line 131 "parser.y"
                                    { Print("- R: ifStatement -> statementListItemWithoutEmptyStatement"); }
#line 2352 "parser.tab.cpp"
    break;

  case 22: /* statementListItemWithoutEmptyStatement: iterationStatement  */
#line 132 "parser.y"
                                    { Print("- R: iterationStatement -> statementListItemWithoutEmptyStatement"); }
#line 2358 "parser.tab.cpp"
    break;

  case 23: /* statementListItemWithoutEmptyStatement: returnStatement  */
#line 134 "parser.y"
        { 
            if ( !isInFunctionBody ) { 
                yyerror("illegal return statement."); YYERROR;
            } 
            Print("- R: returnStatement -> statementListItemWithoutEmptyStatement"); 
        }
#line 2369 "parser.tab.cpp"
    break;

  case 24: /* statementListItemWithoutEmptyStatement: blockStatement  */
#line 140 "parser.y"
                                    { Print("- R: blockStatement -> statementListItemWithoutEmptyStatement"); }
#line 2375 "parser.tab.cpp"
    break;

  case 26: /* emptyStatement: ';'  */
#line 147 "parser.y"
        { 
            if ( isASIActivated ) {
                std::string text(yytext_ptr, yyleng);
                yyerror(("syntax error on token: " + text).c_str()); YYERROR;
            }
            Print("- R: ';' -> emptyStatement"); 
        }
#line 2387 "parser.tab.cpp"
    break;

  case 27: /* blockStatement: '{' '}'  */
#line 157 "parser.y"
              { Print("- R: '{' '}' -> blockStatement"); }
#line 2393 "parser.tab.cpp"
    break;

  case 28: /* blockStatement: '{' statementList '}'  */
#line 158 "parser.y"
                            { Print("- R: '{' statementList '}' -> blockStatement"); }
#line 2399 "parser.tab.cpp"
    break;

  case 29: /* initializer: '=' singleExpression  */
#line 162 "parser.y"
                           { Print("- R: '=' singleExpression -> initializer"); }
#line 2405 "parser.tab.cpp"
    break;

  case 30: /* type: primaryType  */
#line 168 "parser.y"
                  { Print("- R: primaryType -> type"); }
#line 2411 "parser.tab.cpp"
    break;

  case 31: /* primaryType: '(' type ')'  */
#line 172 "parser.y"
                                                { Print("- R: '(' type ')' -> primaryType"); }
#line 2417 "parser.tab.cpp"
    break;

  case 32: /* primaryType: predefinedType  */
#line 173 "parser.y"
                                                { Print("- R: predefinedType -> primaryType"); }
#line 2423 "parser.tab.cpp"
    break;

  case 33: /* primaryType: primaryType '[' ']'  */
#line 174 "parser.y"
                                                { Print("- R: primaryType '[' ']' -> primaryType"); }
#line 2429 "parser.tab.cpp"
    break;

  case 34: /* primaryType: '[' tupleTypeElements ']'  */
#line 175 "parser.y"
                                                { Print("- R: '[' tupleTypeElements ']' -> primaryType"); }
#line 2435 "parser.tab.cpp"
    break;

  case 35: /* primaryType: ENDL_BRACKET_OPEN tupleTypeElements ']'  */
#line 176 "parser.y"
                                                { Print("- R: '[' tupleTypeElements ']' -> primaryType"); }
#line 2441 "parser.tab.cpp"
    break;

  case 36: /* tupleTypeElements: %empty  */
#line 180 "parser.y"
                                    { Print("- R: #empty# -> tupleTypeElements"); }
#line 2447 "parser.tab.cpp"
    break;

  case 37: /* tupleTypeElements: type  */
#line 181 "parser.y"
                                    { Print("- R: type -> tupleTypeElements"); }
#line 2453 "parser.tab.cpp"
    break;

  case 38: /* tupleTypeElements: tupleTypeElements ',' type  */
#line 182 "parser.y"
                                    { Print("- R: tupleTypeElements ',' type -> tupleTypeElements"); }
#line 2459 "parser.tab.cpp"
    break;

  case 39: /* predefinedType: ANY  */
#line 186 "parser.y"
                    { Print("- R: ANY -> predefinedType"); }
#line 2465 "parser.tab.cpp"
    break;

  case 40: /* predefinedType: NUMBER  */
#line 187 "parser.y"
                    { Print("- R: NUMBER -> predefinedType"); }
#line 2471 "parser.tab.cpp"
    break;

  case 41: /* predefinedType: STRING  */
#line 188 "parser.y"
                    { Print("- R: STRING -> predefinedType"); }
#line 2477 "parser.tab.cpp"
    break;

  case 42: /* predefinedType: BOOLEAN  */
#line 189 "parser.y"
                    { Print("- R: BOOLEAN -> predefinedType"); }
#line 2483 "parser.tab.cpp"
    break;

  case 43: /* predefinedType: NEVER  */
#line 190 "parser.y"
                    { Print("- R: NEVER -> predefinedType"); }
#line 2489 "parser.tab.cpp"
    break;

  case 44: /* predefinedType: UNKNOWN  */
#line 191 "parser.y"
                    { Print("- R: UNKNOWN -> predefinedType"); }
#line 2495 "parser.tab.cpp"
    break;

  case 45: /* predefinedType: UNDEFINED  */
#line 192 "parser.y"
                    { Print("- R: UNDEFINED -> predefinedType"); }
#line 2501 "parser.tab.cpp"
    break;

  case 46: /* predefinedType: VOID  */
#line 193 "parser.y"
                    { Print("- R: VOID -> predefinedType"); }
#line 2507 "parser.tab.cpp"
    break;

  case 47: /* predefinedType: NULL_KW  */
#line 194 "parser.y"
                    { Print("- R: NULL_KW -> predefinedType"); }
#line 2513 "parser.tab.cpp"
    break;

  case 48: /* predefinedType: TRUE_KW  */
#line 195 "parser.y"
                    { Print("- R: TRUE_WD -> predefinedType"); }
#line 2519 "parser.tab.cpp"
    break;

  case 49: /* predefinedType: FALSE_KW  */
#line 196 "parser.y"
                    { Print("- R: FALSE_KW -> predefinedType"); }
#line 2525 "parser.tab.cpp"
    break;

  case 50: /* predefinedType: simpleLiteral  */
#line 197 "parser.y"
                    { Print("- R: simpleLiteral -> predefinedType"); }
#line 2531 "parser.tab.cpp"
    break;

  case 51: /* typeAnnotationOpt: %empty  */
#line 201 "parser.y"
                        { Print("- R: # empty # -> typeAnnotationOpt"); }
#line 2537 "parser.tab.cpp"
    break;

  case 52: /* typeAnnotationOpt: typeAnnotation  */
#line 202 "parser.y"
                        { Print("- R: typeAnnotation -> typeAnnotationOpt"); }
#line 2543 "parser.tab.cpp"
    break;

  case 53: /* typeAnnotation: ':' type  */
#line 206 "parser.y"
               { Print("- R: ':' type -> typeAnnotation"); }
#line 2549 "parser.tab.cpp"
    break;

  case 54: /* simpleLiteral: STRING_LIT  */
#line 210 "parser.y"
                        { Print("- R: STRING_LIT -> simpleLiteral"); }
#line 2555 "parser.tab.cpp"
    break;

  case 55: /* simpleLiteral: INT_LIT  */
#line 211 "parser.y"
                        { Print("- R: INT_LIT -> simpleLiteral"); }
#line 2561 "parser.tab.cpp"
    break;

  case 56: /* simpleLiteral: FLOAT_LIT  */
#line 212 "parser.y"
                        { Print("- R: FLOAT_LIT -> simpleLiteral"); }
#line 2567 "parser.tab.cpp"
    break;

  case 57: /* simpleLiteral: TEMPLATE_LITERAL  */
#line 213 "parser.y"
                        { Print("- R: TEMPLATE_LITERAL -> simpleLiteral"); }
#line 2573 "parser.tab.cpp"
    break;

  case 58: /* arrayLiteral: '[' elementList ']'  */
#line 218 "parser.y"
                                        { Print("- R: [ elementList ']' -> arrayLiteral"); }
#line 2579 "parser.tab.cpp"
    break;

  case 59: /* arrayLiteral: ENDL_BRACKET_OPEN elementList ']'  */
#line 219 "parser.y"
                                        { Print("- R: ENDL_BRACKET_OPEN elementList ']' -> arrayLiteral"); }
#line 2585 "parser.tab.cpp"
    break;

  case 60: /* elementList: elementListItem  */
#line 223 "parser.y"
                      { Print("- R: elementListItem -> elementList"); }
#line 2591 "parser.tab.cpp"
    break;

  case 61: /* elementList: elementList ',' elementListItem  */
#line 224 "parser.y"
                                                            { Print("- R: elementList ',' elementListItem -> elementList"); }
#line 2597 "parser.tab.cpp"
    break;

  case 62: /* elementListItem: %empty  */
#line 228 "parser.y"
                  { Print("- R: #empty# -> elementListItem"); }
#line 2603 "parser.tab.cpp"
    break;

  case 63: /* elementListItem: singleExpression  */
#line 229 "parser.y"
                       { Print("- R: singleExpression -> elementListItem"); }
#line 2609 "parser.tab.cpp"
    break;

  case 64: /* elementListItem: singleExpression ','  */
#line 230 "parser.y"
                           { Print("- R: singleExpression ',' -> elementListItem"); }
#line 2615 "parser.tab.cpp"
    break;

  case 65: /* expressionStatement: singleExpression ';'  */
#line 236 "parser.y"
                           { Print("- R: expressionList ';' -> expressionStatement"); }
#line 2621 "parser.tab.cpp"
    break;

  case 66: /* singleExpressionOpt: %empty  */
#line 240 "parser.y"
                        { Print("- R: #empty# -> singleExpressionOpt"); }
#line 2627 "parser.tab.cpp"
    break;

  case 67: /* singleExpressionOpt: singleExpression  */
#line 241 "parser.y"
                          { Print("- R: singleExpression -> singleExpressionOpt"); }
#line 2633 "parser.tab.cpp"
    break;

  case 68: /* singleExpression: identifier  */
#line 245 "parser.y"
                    { Print("- R: identifier -> singleExpression"); }
#line 2639 "parser.tab.cpp"
    break;

  case 69: /* singleExpression: simpleLiteral  */
#line 246 "parser.y"
                    { Print("- R: simpleLiteral -> singleExpression"); }
#line 2645 "parser.tab.cpp"
    break;

  case 70: /* singleExpression: THIS  */
#line 247 "parser.y"
                    { Print("- R: THIS -> singleExpression"); }
#line 2651 "parser.tab.cpp"
    break;

  case 71: /* singleExpression: SUPER  */
#line 248 "parser.y"
                    { Print("- R: SUPER -> singleExpression"); }
#line 2657 "parser.tab.cpp"
    break;

  case 72: /* singleExpression: TRUE_KW  */
#line 249 "parser.y"
                    { Print("- R: TRUE_LITERAL -> singleExpression"); }
#line 2663 "parser.tab.cpp"
    break;

  case 73: /* singleExpression: FALSE_KW  */
#line 250 "parser.y"
                    { Print("- R: FALSE_LITERAL -> singleExpression"); }
#line 2669 "parser.tab.cpp"
    break;

  case 74: /* singleExpression: NULL_KW  */
#line 251 "parser.y"
                    { Print("- R: NULL_LITERAL -> singleExpression"); }
#line 2675 "parser.tab.cpp"
    break;

  case 75: /* singleExpression: '-' singleExpression  */
#line 253 "parser.y"
                                        { Print("- R: '-' singleExpression -> singleExpression"); }
#line 2681 "parser.tab.cpp"
    break;

  case 76: /* singleExpression: '+' singleExpression  */
#line 254 "parser.y"
                                        { Print("- R: '+' singleExpression -> singleExpression"); }
#line 2687 "parser.tab.cpp"
    break;

  case 77: /* singleExpression: '!' singleExpression  */
#line 256 "parser.y"
                           { Print("- R: '!' singleExpression -> singleExpression"); }
#line 2693 "parser.tab.cpp"
    break;

  case 78: /* singleExpression: singleExpression OPERATOR_INCREMENT  */
#line 258 "parser.y"
                                                               { Print("- R: singleExpression OPERATOR_INCREMENT -> singleExpression"); }
#line 2699 "parser.tab.cpp"
    break;

  case 79: /* singleExpression: singleExpression OPERATOR_DECREMENT  */
#line 259 "parser.y"
                                                               { Print("- R: singleExpression OPERATOR_DECREMENT -> singleExpression"); }
#line 2705 "parser.tab.cpp"
    break;

  case 80: /* singleExpression: ENDL_OPERATOR_INCREMENT singleExpression  */
#line 261 "parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 2711 "parser.tab.cpp"
    break;

  case 81: /* singleExpression: ENDL_OPERATOR_DECREMENT singleExpression  */
#line 262 "parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 2717 "parser.tab.cpp"
    break;

  case 82: /* singleExpression: OPERATOR_INCREMENT singleExpression  */
#line 263 "parser.y"
                                                               { Print("- R: OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 2723 "parser.tab.cpp"
    break;

  case 83: /* singleExpression: OPERATOR_DECREMENT singleExpression  */
#line 264 "parser.y"
                                                               { Print("- R: OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 2729 "parser.tab.cpp"
    break;

  case 84: /* singleExpression: singleExpression '+' singleExpression  */
#line 266 "parser.y"
                                            { Print("- R: singleExpression '+' singleExpression -> singleExpression"); }
#line 2735 "parser.tab.cpp"
    break;

  case 85: /* singleExpression: singleExpression '-' singleExpression  */
#line 267 "parser.y"
                                            { Print("- R: singleExpression '-' singleExpression -> singleExpression"); }
#line 2741 "parser.tab.cpp"
    break;

  case 86: /* singleExpression: singleExpression '*' singleExpression  */
#line 268 "parser.y"
                                            { Print("- R: singleExpression '*' singleExpression -> singleExpression"); }
#line 2747 "parser.tab.cpp"
    break;

  case 87: /* singleExpression: singleExpression '/' singleExpression  */
#line 269 "parser.y"
                                            { Print("- R: singleExpression '/' singleExpression -> singleExpression"); }
#line 2753 "parser.tab.cpp"
    break;

  case 88: /* singleExpression: singleExpression '<' singleExpression  */
#line 270 "parser.y"
                                            { Print("- R: singleExpression '<' singleExpression -> singleExpression"); }
#line 2759 "parser.tab.cpp"
    break;

  case 89: /* singleExpression: singleExpression '>' singleExpression  */
#line 271 "parser.y"
                                            { Print("- R: singleExpression '>' singleExpression -> singleExpression"); }
#line 2765 "parser.tab.cpp"
    break;

  case 90: /* singleExpression: singleExpression OPERATOR_EQUAL singleExpression  */
#line 274 "parser.y"
        { Print("- R: singleExpression OPERATOR_EQUAL singleExpression -> singleExpression"); }
#line 2771 "parser.tab.cpp"
    break;

  case 91: /* singleExpression: singleExpression OPERATOR_NOT_EQUAL singleExpression  */
#line 277 "parser.y"
        { Print("- R: singleExpression OPERATOR_NOT_EQUAL singleExpression -> singleExpression"); }
#line 2777 "parser.tab.cpp"
    break;

  case 92: /* singleExpression: singleExpression OPERATOR_STRICT_EQUAL singleExpression  */
#line 280 "parser.y"
        { Print("- R: singleExpression OPERATOR_STRICT_EQUAL singleExpression -> singleExpression"); }
#line 2783 "parser.tab.cpp"
    break;

  case 93: /* singleExpression: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression  */
#line 283 "parser.y"
        { Print("- R: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression -> singleExpression"); }
#line 2789 "parser.tab.cpp"
    break;

  case 94: /* singleExpression: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression  */
#line 286 "parser.y"
        { Print("- R: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression -> singleExpression"); }
#line 2795 "parser.tab.cpp"
    break;

  case 95: /* singleExpression: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression  */
#line 289 "parser.y"
        { Print("- R: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression -> singleExpression"); }
#line 2801 "parser.tab.cpp"
    break;

  case 96: /* singleExpression: singleExpression '=' singleExpression  */
#line 292 "parser.y"
        { Print("- R: singleExpression '=' singleExpression -> singleExpression"); }
#line 2807 "parser.tab.cpp"
    break;

  case 97: /* singleExpression: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression  */
#line 295 "parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression -> singleExpression"); }
#line 2813 "parser.tab.cpp"
    break;

  case 98: /* singleExpression: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression  */
#line 298 "parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression -> singleExpression"); }
#line 2819 "parser.tab.cpp"
    break;

  case 99: /* singleExpression: singleExpression OPERATOR_ASSIGN_PLUS singleExpression  */
#line 301 "parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_PLUS singleExpression -> singleExpression"); }
#line 2825 "parser.tab.cpp"
    break;

  case 100: /* singleExpression: singleExpression OPERATOR_ASSIGN_MINUS singleExpression  */
#line 304 "parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_MINUS singleExpression -> singleExpression"); }
#line 2831 "parser.tab.cpp"
    break;

  case 101: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression  */
#line 307 "parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression -> singleExpression"); }
#line 2837 "parser.tab.cpp"
    break;

  case 102: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression  */
#line 310 "parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression -> singleExpression"); }
#line 2843 "parser.tab.cpp"
    break;

  case 103: /* singleExpression: singleExpression OPERATOR_LOGICAL_OR singleExpression  */
#line 313 "parser.y"
        { Print("- R: singleExpression OPERATOR_LOGICAL_OR singleExpression -> singleExpression"); }
#line 2849 "parser.tab.cpp"
    break;

  case 104: /* singleExpression: singleExpression OPERATOR_LOGICAL_AND singleExpression  */
#line 316 "parser.y"
        { Print("- R: singleExpression OPERATOR_LOGICAL_AND singleExpression -> singleExpression"); }
#line 2855 "parser.tab.cpp"
    break;

  case 105: /* singleExpression: singleExpression INSTANCEOF singleExpression  */
#line 318 "parser.y"
                                                    { Print("- R: singleExpression INSTANCEOF singleExpression -> singleExpression"); }
#line 2861 "parser.tab.cpp"
    break;

  case 106: /* singleExpression: singleExpression IN singleExpression  */
#line 319 "parser.y"
                                                    { Print("- R: singleExpression IN singleExpression -> singleExpression"); }
#line 2867 "parser.tab.cpp"
    break;

  case 107: /* singleExpression: singleExpression TEMPLATE_LITERAL  */
#line 322 "parser.y"
        { Print("- R: singleExpression TEMPLATE_LITERAL -> singleExpression"); }
#line 2873 "parser.tab.cpp"
    break;

  case 108: /* singleExpression: singleExpression '?' singleExpression ':' singleExpression  */
#line 325 "parser.y"
        { Print("- R: singleExpression '?' singleExpression ':' singleExpression -> singleExpression"); }
#line 2879 "parser.tab.cpp"
    break;

  case 109: /* singleExpression: singleExpression ',' singleExpression  */
#line 328 "parser.y"
        { Print("- R: singleExpression ',' singleExpressionn -> singleExpression"); }
#line 2885 "parser.tab.cpp"
    break;

  case 110: /* singleExpression: '(' singleExpression ')'  */
#line 330 "parser.y"
                               { Print("- R: '(' expressionList ')' -> singleExpression"); }
#line 2891 "parser.tab.cpp"
    break;

  case 111: /* singleExpression: singleExpression '(' ')'  */
#line 332 "parser.y"
                               { Print("- R: singleExpression '(' ')' -> singleExpression"); }
#line 2897 "parser.tab.cpp"
    break;

  case 112: /* singleExpression: singleExpression '(' singleExpression ')'  */
#line 333 "parser.y"
                                                { Print("- R: singleExpression '(' singleExpression ')' -> singleExpression"); }
#line 2903 "parser.tab.cpp"
    break;

  case 113: /* singleExpression: singleExpression '(' singleExpression ',' ')'  */
#line 334 "parser.y"
                                                    { Print("- R: singleExpression '(' singleExpression ',' ')' -> singleExpression"); }
#line 2909 "parser.tab.cpp"
    break;

  case 114: /* singleExpression: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression  */
#line 337 "parser.y"
        { Print("- R: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression -> singleExpression"); }
#line 2915 "parser.tab.cpp"
    break;

  case 115: /* singleExpression: singleExpression '.' identifier  */
#line 339 "parser.y"
                                      { Print("- R: singleExpression '.' identifier -> singleExpression"); }
#line 2921 "parser.tab.cpp"
    break;

  case 116: /* singleExpression: arrayLiteral  */
#line 341 "parser.y"
                                                              { Print("- R: arrayLiteral -> singleExpression"); }
#line 2927 "parser.tab.cpp"
    break;

  case 117: /* singleExpression: singleExpression '[' singleExpression ']'  */
#line 342 "parser.y"
                                                              { Print("- R: singleExpression '[' expressionList ']' -> singleExpression"); }
#line 2933 "parser.tab.cpp"
    break;

  case 118: /* singleExpression: singleExpression ENDL_BRACKET_OPEN singleExpression ']'  */
#line 343 "parser.y"
                                                              { Print("- R: singleExpression ENDL_BRACKET_OPEN expressionList ']' -> singleExpression"); }
#line 2939 "parser.tab.cpp"
    break;

  case 119: /* singleExpression: NEW singleExpression  */
#line 345 "parser.y"
                           { Print("- R: NEW singleExpression -> singleExpression"); }
#line 2945 "parser.tab.cpp"
    break;

  case 120: /* varStatement: varModifier varDeclarationList ';'  */
#line 351 "parser.y"
                                         { Print("- R: varModifier varDeclarationList ';' -> varStatement"); }
#line 2951 "parser.tab.cpp"
    break;

  case 122: /* varDeclarationList: varDeclaration  */
#line 356 "parser.y"
                                            { Print("- R: varDeclaration -> varDeclarationList"); }
#line 2957 "parser.tab.cpp"
    break;

  case 123: /* varDeclarationList: varDeclarationList ',' varDeclaration  */
#line 357 "parser.y"
                                            { Print("- R: varDeclarationList ',' varDeclaration -> varDeclarationList"); }
#line 2963 "parser.tab.cpp"
    break;

  case 124: /* varDeclaration: identifier typeAnnotationOpt  */
#line 361 "parser.y"
                                                           { Print("- R: identifier typeAnnotationOpt -> varDeclaration"); }
#line 2969 "parser.tab.cpp"
    break;

  case 125: /* varDeclaration: identifier typeAnnotationOpt '=' singleExpression  */
#line 362 "parser.y"
                                                           { Print("- R: identifier typeAnnotationOpt '=' singleExpression -> varDeclaration"); }
#line 2975 "parser.tab.cpp"
    break;

  case 126: /* varModifier: VAR  */
#line 366 "parser.y"
            { Print("- R: VAR -> varModifier"); }
#line 2981 "parser.tab.cpp"
    break;

  case 127: /* varModifier: LET  */
#line 367 "parser.y"
            { Print("- R: LET -> varModifier"); }
#line 2987 "parser.tab.cpp"
    break;

  case 128: /* varModifier: CONST  */
#line 368 "parser.y"
            { Print("- R: CONST -> varModifier"); }
#line 2993 "parser.tab.cpp"
    break;

  case 129: /* ifStatement: IF '(' singleExpression ')' statementListItemWithoutEmptyStatement  */
#line 375 "parser.y"
        { Print("- R: IF '(' expressionList ')' statementListItem -> ifStatement"); }
#line 2999 "parser.tab.cpp"
    break;

  case 130: /* ifStatement: IF '(' singleExpression ')' statementListItemWithoutEmptyStatement ELSE statementListItem  */
#line 378 "parser.y"
        { Print("- R: IF '(' expressionList ')' statementListItem ELSE statementListItem -> ifStatement"); }
#line 3005 "parser.tab.cpp"
    break;

  case 131: /* $@1: %empty  */
#line 384 "parser.y"
                                                          { doWhileASI(); }
#line 3011 "parser.tab.cpp"
    break;

  case 132: /* iterationStatement: DO statementListItem WHILE '(' singleExpression ')' $@1 ';'  */
#line 385 "parser.y"
        { Print("- R: DO statementListItem WHILE '(' expressionList ')' ';' -> iterationStatement"); }
#line 3017 "parser.tab.cpp"
    break;

  case 133: /* iterationStatement: WHILE '(' singleExpression ')' statementListItem  */
#line 388 "parser.y"
        { Print("- R: WHILE '(' expressionList ')' statementListItem -> iterationStatement"); }
#line 3023 "parser.tab.cpp"
    break;

  case 134: /* $@2: %empty  */
#line 390 "parser.y"
                                                                                        { isInForHeader = 0; }
#line 3029 "parser.tab.cpp"
    break;

  case 135: /* iterationStatement: forHeader singleExpressionOpt ';' singleExpressionOpt ';' singleExpressionOpt ')' $@2 statementListItem  */
#line 391 "parser.y"
        { Print("- R: FOR '(' singleExpressionOpt ';' singleExpressionOpt ';' singleExpressionOpt ')' statementListItem -> iterationStatement"); }
#line 3035 "parser.tab.cpp"
    break;

  case 136: /* $@3: %empty  */
#line 393 "parser.y"
                                                                                                   { isInForHeader = 0; }
#line 3041 "parser.tab.cpp"
    break;

  case 137: /* iterationStatement: forHeader varModifier varDeclarationList ';' singleExpressionOpt ';' singleExpressionOpt ')' $@3 statementListItem  */
#line 394 "parser.y"
        { Print("- R: FOR '(' varModifier varDeclarationList ';' singleExpressionOpt ';' singleExpressionOpt ')' statementListItem -> iterationStatement"); }
#line 3047 "parser.tab.cpp"
    break;

  case 138: /* $@4: %empty  */
#line 396 "parser.y"
                                                         { isInForHeader = 0; }
#line 3053 "parser.tab.cpp"
    break;

  case 139: /* iterationStatement: forHeader singleExpression IN singleExpression ')' $@4 statementListItem  */
#line 397 "parser.y"
        { Print("- R: FOR '(' singleExpression IN singleExpression ')' statementListItem -> iterationStatement"); }
#line 3059 "parser.tab.cpp"
    break;

  case 140: /* $@5: %empty  */
#line 399 "parser.y"
                                                                   { isInForHeader = 0; }
#line 3065 "parser.tab.cpp"
    break;

  case 141: /* iterationStatement: forHeader varModifier varDeclaration IN singleExpression ')' $@5 statementListItem  */
#line 400 "parser.y"
        { Print("- R: FOR '(' varModifier varDeclaration IN expressionList ')' statementListItem -> iterationStatement"); }
#line 3071 "parser.tab.cpp"
    break;

  case 142: /* forHeader: FOR '('  */
#line 404 "parser.y"
               { isInForHeader = 1; }
#line 3077 "parser.tab.cpp"
    break;

  case 143: /* returnStatement: RETURN ';'  */
#line 410 "parser.y"
                                    { Print("- R: RETURN ';' -> returnStatement"); }
#line 3083 "parser.tab.cpp"
    break;

  case 144: /* returnStatement: RETURN singleExpression ';'  */
#line 411 "parser.y"
                                    { Print("- R: RETURN singleExpression ';' -> returnStatement"); }
#line 3089 "parser.tab.cpp"
    break;

  case 145: /* functionDeclaration: FUNCTION identifier callSignature functionBody  */
#line 415 "parser.y"
                                                     { Print("- R: FUNCTION ID callSignature functionBody -> functionDeclaration"); }
#line 3095 "parser.tab.cpp"
    break;

  case 146: /* functionBody: '{' '}'  */
#line 419 "parser.y"
                                                        { Print("- R: '{' '}' -> functionBody"); }
#line 3101 "parser.tab.cpp"
    break;

  case 147: /* $@6: %empty  */
#line 420 "parser.y"
          { isInFunctionBody = 1; }
#line 3107 "parser.tab.cpp"
    break;

  case 148: /* functionBody: '{' $@6 statementList '}'  */
#line 420 "parser.y"
                                                        { isInFunctionBody = 0; Print("- R: '{' statementList '}' -> functionBody"); }
#line 3113 "parser.tab.cpp"
    break;

  case 149: /* callSignature: '(' parameterList ')' typeAnnotationOpt  */
#line 424 "parser.y"
                                               { Print("- R : '(' parameterList ')' typeAnnotation -> callSignature"); }
#line 3119 "parser.tab.cpp"
    break;

  case 150: /* parameterList: %empty  */
#line 428 "parser.y"
                         { Print("- R: #empty# -> parameterList"); }
#line 3125 "parser.tab.cpp"
    break;

  case 151: /* parameterList: requiredParameterList  */
#line 429 "parser.y"
                            { Print("- R: requiredParameterList -> parameterList"); }
#line 3131 "parser.tab.cpp"
    break;

  case 152: /* parameterList: requiredParameterList ','  */
#line 430 "parser.y"
                                { Print("- R: requiredParameterList ',' -> parameterList"); }
#line 3137 "parser.tab.cpp"
    break;

  case 153: /* requiredParameterList: requiredParameter  */
#line 434 "parser.y"
                                                    { Print("- R: requiredParameter -> requiredParameterList"); }
#line 3143 "parser.tab.cpp"
    break;

  case 154: /* requiredParameterList: requiredParameterList ',' requiredParameter  */
#line 435 "parser.y"
                                                    { Print("- R: requiredParameterList ',' requiredParameter -> requiredParameterList"); }
#line 3149 "parser.tab.cpp"
    break;

  case 155: /* requiredParameter: identifier typeAnnotationOpt  */
#line 439 "parser.y"
                                   { Print("- R: ID typeAnnotationOpt -> requiredParameter"); }
#line 3155 "parser.tab.cpp"
    break;

  case 156: /* classDeclaration: CLASS identifier classTail  */
#line 445 "parser.y"
                                                { Print("- R: CLASS identifier classTail -> classDeclaration"); }
#line 3161 "parser.tab.cpp"
    break;

  case 157: /* classDeclaration: CLASS identifier classHeritage classTail  */
#line 446 "parser.y"
                                                { Print("- R: CLASS identifier classHeritage classTail -> classDeclaration"); }
#line 3167 "parser.tab.cpp"
    break;

  case 158: /* classHeritage: EXTENDS identifier  */
#line 450 "parser.y"
                         { Print("- R: EXTENDS identifier -> classHeritage"); }
#line 3173 "parser.tab.cpp"
    break;

  case 159: /* classTail: '{' '}'  */
#line 454 "parser.y"
                                { Print("- R: '{' '}' -> classTail"); }
#line 3179 "parser.tab.cpp"
    break;

  case 160: /* classTail: '{' classElementList '}'  */
#line 455 "parser.y"
                                { Print("- R: '{' classElementList '}' -> classTail"); }
#line 3185 "parser.tab.cpp"
    break;

  case 161: /* classElementList: classElement  */
#line 459 "parser.y"
                   { Print("- R: classElement -> classElementList"); }
#line 3191 "parser.tab.cpp"
    break;

  case 162: /* classElementList: classElementList classElement  */
#line 460 "parser.y"
                                    { Print("- R: classElementList classElement -> classElementList"); }
#line 3197 "parser.tab.cpp"
    break;

  case 163: /* classElement: CONSTRUCTOR constructorCallSignature functionBody  */
#line 464 "parser.y"
                                                        { Print("- R: CONSTRUCTOR callSignature functionBody -> classElement"); }
#line 3203 "parser.tab.cpp"
    break;

  case 164: /* classElement: propertyName typeAnnotationOpt ';'  */
#line 467 "parser.y"
                                                       { Print("- R: propertyName typeAnnotationOpt ';' -> classElement"); }
#line 3209 "parser.tab.cpp"
    break;

  case 165: /* classElement: propertyName typeAnnotationOpt initializer ';'  */
#line 468 "parser.y"
                                                       { Print("- R: propertyName typeAnnotationOpt initializer ';' -> classElement"); }
#line 3215 "parser.tab.cpp"
    break;

  case 166: /* classElement: propertyName callSignature functionBody  */
#line 471 "parser.y"
                                              { Print("- R: propertyName callSignature functionBody -> classElement"); }
#line 3221 "parser.tab.cpp"
    break;

  case 167: /* classElement: GET propertyName '(' ')' typeAnnotationOpt functionBody  */
#line 474 "parser.y"
                                                               { Print("- R: GET propertyName '(' ')' typeAnnotationOpt functionBody -> classElement"); }
#line 3227 "parser.tab.cpp"
    break;

  case 168: /* classElement: SET propertyName callSignature functionBody  */
#line 475 "parser.y"
                                                            { Print("- R: SET propertyName callSignature functionBody -> classElement"); }
#line 3233 "parser.tab.cpp"
    break;

  case 169: /* constructorCallSignature: '(' parameterList ')'  */
#line 479 "parser.y"
                            { Print("- R: '(' parameterList ')' -> constructorCallSignature"); }
#line 3239 "parser.tab.cpp"
    break;

  case 170: /* propertyName: identifier  */
#line 483 "parser.y"
                                            { Print("- R: identifier -> propertyName"); }
#line 3245 "parser.tab.cpp"
    break;

  case 171: /* identifier: ID  */
#line 487 "parser.y"
                { Print("- R: ID -> identifier"); }
#line 3251 "parser.tab.cpp"
    break;

  case 172: /* identifier: ASYNC  */
#line 488 "parser.y"
                { Print("- R: ASYNC -> identifier"); }
#line 3257 "parser.tab.cpp"
    break;

  case 173: /* identifier: AS  */
#line 489 "parser.y"
                { Print("- R: AS -> identifier"); }
#line 3263 "parser.tab.cpp"
    break;

  case 174: /* identifier: FROM  */
#line 490 "parser.y"
                { Print("- R: FROM -> identifier"); }
#line 3269 "parser.tab.cpp"
    break;

  case 175: /* identifier: YIELD  */
#line 491 "parser.y"
                { Print("- R: YIELD -> identifier"); }
#line 3275 "parser.tab.cpp"
    break;

  case 176: /* identifier: ANY  */
#line 492 "parser.y"
                { Print("- R: ANY -> identifier"); }
#line 3281 "parser.tab.cpp"
    break;

  case 177: /* identifier: NUMBER  */
#line 493 "parser.y"
                { Print("- R: NUMBER -> identifier"); }
#line 3287 "parser.tab.cpp"
    break;

  case 178: /* identifier: BOOLEAN  */
#line 494 "parser.y"
                { Print("- R: BOOLEAN -> identifier"); }
#line 3293 "parser.tab.cpp"
    break;

  case 179: /* identifier: STRING  */
#line 495 "parser.y"
                { Print("- R: STRING -> identifier"); }
#line 3299 "parser.tab.cpp"
    break;

  case 180: /* identifier: UNIQUE  */
#line 496 "parser.y"
                { Print("- R: UNIQUE -> identifier"); }
#line 3305 "parser.tab.cpp"
    break;

  case 181: /* identifier: SYMBOL  */
#line 497 "parser.y"
                { Print("- R: SYMBOL -> identifier"); }
#line 3311 "parser.tab.cpp"
    break;

  case 182: /* identifier: NEVER  */
#line 498 "parser.y"
                { Print("- R: NEVER -> identifier"); }
#line 3317 "parser.tab.cpp"
    break;

  case 183: /* identifier: UNDEFINED  */
#line 499 "parser.y"
                { Print("- R: UNDEFINED -> identifier"); }
#line 3323 "parser.tab.cpp"
    break;

  case 184: /* identifier: OBJECT  */
#line 500 "parser.y"
                { Print("- R: OBJECT -> identifier"); }
#line 3329 "parser.tab.cpp"
    break;

  case 185: /* identifier: KEYOF  */
#line 501 "parser.y"
                { Print("- R: KEYOF -> identifier"); }
#line 3335 "parser.tab.cpp"
    break;

  case 186: /* identifier: NAMESPACE  */
#line 502 "parser.y"
                { Print("- R: NAMESPACE -> identifier"); }
#line 3341 "parser.tab.cpp"
    break;

  case 187: /* identifier: ABSTRACT  */
#line 503 "parser.y"
                { Print("- R: ABSTRACT -> identifier"); }
#line 3347 "parser.tab.cpp"
    break;

  case 188: /* identifier: REQUIRE  */
#line 504 "parser.y"
                { Print("- R: REQUIRE -> identifier"); }
#line 3353 "parser.tab.cpp"
    break;


#line 3357 "parser.tab.cpp"

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

#line 507 "parser.y"



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


