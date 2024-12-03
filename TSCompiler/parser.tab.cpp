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
  YYSYMBOL_SWITCH = 16,                    /* SWITCH  */
  YYSYMBOL_CASE = 17,                      /* CASE  */
  YYSYMBOL_DEFAULT = 18,                   /* DEFAULT  */
  YYSYMBOL_RETURN = 19,                    /* RETURN  */
  YYSYMBOL_SUPER = 20,                     /* SUPER  */
  YYSYMBOL_THIS = 21,                      /* THIS  */
  YYSYMBOL_NEW = 22,                       /* NEW  */
  YYSYMBOL_ASYNC = 23,                     /* ASYNC  */
  YYSYMBOL_AS = 24,                        /* AS  */
  YYSYMBOL_FROM = 25,                      /* FROM  */
  YYSYMBOL_YIELD = 26,                     /* YIELD  */
  YYSYMBOL_KEYOF = 27,                     /* KEYOF  */
  YYSYMBOL_CONSTRUCTOR = 28,               /* CONSTRUCTOR  */
  YYSYMBOL_NAMESPACE = 29,                 /* NAMESPACE  */
  YYSYMBOL_ABSTRACT = 30,                  /* ABSTRACT  */
  YYSYMBOL_REQUIRE = 31,                   /* REQUIRE  */
  YYSYMBOL_ANY = 32,                       /* ANY  */
  YYSYMBOL_NUMBER = 33,                    /* NUMBER  */
  YYSYMBOL_BOOLEAN = 34,                   /* BOOLEAN  */
  YYSYMBOL_STRING = 35,                    /* STRING  */
  YYSYMBOL_NEVER = 36,                     /* NEVER  */
  YYSYMBOL_UNDEFINED = 37,                 /* UNDEFINED  */
  YYSYMBOL_UNIQUE = 38,                    /* UNIQUE  */
  YYSYMBOL_SYMBOL = 39,                    /* SYMBOL  */
  YYSYMBOL_OBJECT = 40,                    /* OBJECT  */
  YYSYMBOL_VOID = 41,                      /* VOID  */
  YYSYMBOL_UNKNOWN = 42,                   /* UNKNOWN  */
  YYSYMBOL_STRING_LIT = 43,                /* STRING_LIT  */
  YYSYMBOL_INT_LIT = 44,                   /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 45,                 /* FLOAT_LIT  */
  YYSYMBOL_NULL_KW = 46,                   /* NULL_KW  */
  YYSYMBOL_TRUE_KW = 47,                   /* TRUE_KW  */
  YYSYMBOL_FALSE_KW = 48,                  /* FALSE_KW  */
  YYSYMBOL_ID = 49,                        /* ID  */
  YYSYMBOL_ENDL = 50,                      /* ENDL  */
  YYSYMBOL_TEMPLATE_LITERAL = 51,          /* TEMPLATE_LITERAL  */
  YYSYMBOL_OPERATOR_INCREMENT = 52,        /* OPERATOR_INCREMENT  */
  YYSYMBOL_OPERATOR_DECREMENT = 53,        /* OPERATOR_DECREMENT  */
  YYSYMBOL_ENDL_OPERATOR_INCREMENT = 54,   /* ENDL_OPERATOR_INCREMENT  */
  YYSYMBOL_ENDL_OPERATOR_DECREMENT = 55,   /* ENDL_OPERATOR_DECREMENT  */
  YYSYMBOL_IF_ONLY_PREC = 56,              /* IF_ONLY_PREC  */
  YYSYMBOL_57_ = 57,                       /* ','  */
  YYSYMBOL_COMMA_OPERATOR = 58,            /* COMMA_OPERATOR  */
  YYSYMBOL_COMMA_SEPARATOR = 59,           /* COMMA_SEPARATOR  */
  YYSYMBOL_60_ = 60,                       /* '='  */
  YYSYMBOL_OPERATOR_ASSIGN_PLUS = 61,      /* OPERATOR_ASSIGN_PLUS  */
  YYSYMBOL_OPERATOR_ASSIGN_MINUS = 62,     /* OPERATOR_ASSIGN_MINUS  */
  YYSYMBOL_OPERATOR_ASSIGN_MULTIPLY = 63,  /* OPERATOR_ASSIGN_MULTIPLY  */
  YYSYMBOL_OPERATOR_ASSIGN_DIVIDE = 64,    /* OPERATOR_ASSIGN_DIVIDE  */
  YYSYMBOL_OPERATOR_ASSIGN_LOGICAL_AND = 65, /* OPERATOR_ASSIGN_LOGICAL_AND  */
  YYSYMBOL_OPERATOR_ASSIGN_LOGICAL_OR = 66, /* OPERATOR_ASSIGN_LOGICAL_OR  */
  YYSYMBOL_67_ = 67,                       /* '?'  */
  YYSYMBOL_68_ = 68,                       /* ':'  */
  YYSYMBOL_OPERATOR_LOGICAL_OR = 69,       /* OPERATOR_LOGICAL_OR  */
  YYSYMBOL_OPERATOR_LOGICAL_AND = 70,      /* OPERATOR_LOGICAL_AND  */
  YYSYMBOL_71_ = 71,                       /* '|'  */
  YYSYMBOL_72_ = 72,                       /* '^'  */
  YYSYMBOL_73_ = 73,                       /* '&'  */
  YYSYMBOL_OPERATOR_EQUAL = 74,            /* OPERATOR_EQUAL  */
  YYSYMBOL_OPERATOR_NOT_EQUAL = 75,        /* OPERATOR_NOT_EQUAL  */
  YYSYMBOL_OPERATOR_STRICT_EQUAL = 76,     /* OPERATOR_STRICT_EQUAL  */
  YYSYMBOL_OPERATOR_STRICT_NOT_EQUAL = 77, /* OPERATOR_STRICT_NOT_EQUAL  */
  YYSYMBOL_78_ = 78,                       /* '>'  */
  YYSYMBOL_79_ = 79,                       /* '<'  */
  YYSYMBOL_OPERATOR_GREATER_THAN_EQUAL = 80, /* OPERATOR_GREATER_THAN_EQUAL  */
  YYSYMBOL_OPERATOR_LESS_THAN_EQUAL = 81,  /* OPERATOR_LESS_THAN_EQUAL  */
  YYSYMBOL_INSTANCEOF = 82,                /* INSTANCEOF  */
  YYSYMBOL_IN = 83,                        /* IN  */
  YYSYMBOL_84_ = 84,                       /* '+'  */
  YYSYMBOL_85_ = 85,                       /* '-'  */
  YYSYMBOL_86_ = 86,                       /* '*'  */
  YYSYMBOL_87_ = 87,                       /* '/'  */
  YYSYMBOL_88_ = 88,                       /* '%'  */
  YYSYMBOL_89_ = 89,                       /* '!'  */
  YYSYMBOL_90_ = 90,                       /* '~'  */
  YYSYMBOL_UMINUS = 91,                    /* UMINUS  */
  YYSYMBOL_UPLUS = 92,                     /* UPLUS  */
  YYSYMBOL_PREF_INCREMENT = 93,            /* PREF_INCREMENT  */
  YYSYMBOL_PREF_DECREMENT = 94,            /* PREF_DECREMENT  */
  YYSYMBOL_POST_INCREMENT = 95,            /* POST_INCREMENT  */
  YYSYMBOL_POST_DECREMENT = 96,            /* POST_DECREMENT  */
  YYSYMBOL_97_ = 97,                       /* '.'  */
  YYSYMBOL_98_ = 98,                       /* '['  */
  YYSYMBOL_99_ = 99,                       /* ']'  */
  YYSYMBOL_ENDL_BRACKET_OPEN = 100,        /* ENDL_BRACKET_OPEN  */
  YYSYMBOL_OPTIONAL_CHAINING_OPERATOR = 101, /* OPTIONAL_CHAINING_OPERATOR  */
  YYSYMBOL_102_ = 102,                     /* '('  */
  YYSYMBOL_103_ = 103,                     /* ')'  */
  YYSYMBOL_104_ = 104,                     /* ';'  */
  YYSYMBOL_105_ = 105,                     /* '{'  */
  YYSYMBOL_106_ = 106,                     /* '}'  */
  YYSYMBOL_YYACCEPT = 107,                 /* $accept  */
  YYSYMBOL_script = 108,                   /* script  */
  YYSYMBOL_globalStatementList = 109,      /* globalStatementList  */
  YYSYMBOL_statementList = 110,            /* statementList  */
  YYSYMBOL_statementListItem = 111,        /* statementListItem  */
  YYSYMBOL_statementListItemWithoutEmptyStatement = 112, /* statementListItemWithoutEmptyStatement  */
  YYSYMBOL_emptyStatement = 113,           /* emptyStatement  */
  YYSYMBOL_blockStatement = 114,           /* blockStatement  */
  YYSYMBOL_initializer = 115,              /* initializer  */
  YYSYMBOL_type = 116,                     /* type  */
  YYSYMBOL_primaryType = 117,              /* primaryType  */
  YYSYMBOL_tupleTypeElements = 118,        /* tupleTypeElements  */
  YYSYMBOL_predefinedType = 119,           /* predefinedType  */
  YYSYMBOL_typeAnnotationOpt = 120,        /* typeAnnotationOpt  */
  YYSYMBOL_typeAnnotation = 121,           /* typeAnnotation  */
  YYSYMBOL_simpleLiteral = 122,            /* simpleLiteral  */
  YYSYMBOL_arrayLiteral = 123,             /* arrayLiteral  */
  YYSYMBOL_elementList = 124,              /* elementList  */
  YYSYMBOL_elementListItem = 125,          /* elementListItem  */
  YYSYMBOL_expressionStatement = 126,      /* expressionStatement  */
  YYSYMBOL_singleExpressionOpt = 127,      /* singleExpressionOpt  */
  YYSYMBOL_singleExpression = 128,         /* singleExpression  */
  YYSYMBOL_varStatement = 129,             /* varStatement  */
  YYSYMBOL_varDeclarationList = 130,       /* varDeclarationList  */
  YYSYMBOL_varDeclaration = 131,           /* varDeclaration  */
  YYSYMBOL_varModifier = 132,              /* varModifier  */
  YYSYMBOL_ifStatement = 133,              /* ifStatement  */
  YYSYMBOL_switchStatement = 134,          /* switchStatement  */
  YYSYMBOL_caseClauseList = 135,           /* caseClauseList  */
  YYSYMBOL_caseClause = 136,               /* caseClause  */
  YYSYMBOL_defaultClause = 137,            /* defaultClause  */
  YYSYMBOL_iterationStatement = 138,       /* iterationStatement  */
  YYSYMBOL_139_1 = 139,                    /* $@1  */
  YYSYMBOL_140_2 = 140,                    /* $@2  */
  YYSYMBOL_141_3 = 141,                    /* $@3  */
  YYSYMBOL_142_4 = 142,                    /* $@4  */
  YYSYMBOL_143_5 = 143,                    /* $@5  */
  YYSYMBOL_forHeader = 144,                /* forHeader  */
  YYSYMBOL_returnStatement = 145,          /* returnStatement  */
  YYSYMBOL_functionDeclaration = 146,      /* functionDeclaration  */
  YYSYMBOL_functionBody = 147,             /* functionBody  */
  YYSYMBOL_148_6 = 148,                    /* $@6  */
  YYSYMBOL_callSignature = 149,            /* callSignature  */
  YYSYMBOL_parameterList = 150,            /* parameterList  */
  YYSYMBOL_requiredParameterList = 151,    /* requiredParameterList  */
  YYSYMBOL_requiredParameter = 152,        /* requiredParameter  */
  YYSYMBOL_classDeclaration = 153,         /* classDeclaration  */
  YYSYMBOL_classHeritage = 154,            /* classHeritage  */
  YYSYMBOL_classTail = 155,                /* classTail  */
  YYSYMBOL_classElementList = 156,         /* classElementList  */
  YYSYMBOL_classElement = 157,             /* classElement  */
  YYSYMBOL_constructorCallSignature = 158, /* constructorCallSignature  */
  YYSYMBOL_propertyName = 159,             /* propertyName  */
  YYSYMBOL_identifier = 160                /* identifier  */
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
#define YYFINAL  97
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2330

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  107
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  201
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  352

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   337


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
       2,     2,     2,    89,     2,     2,     2,    88,    73,     2,
     102,   103,    86,    84,    57,    85,    97,    87,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    68,   104,
      79,    60,    78,    67,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    98,     2,    99,    72,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   105,    71,   106,    90,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    58,    59,    61,    62,    63,    64,    65,    66,
      69,    70,    74,    75,    76,    77,    80,    81,    82,    83,
      91,    92,    93,    94,    95,    96,   100,   101
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    85,    85,    96,    98,    99,   100,   101,   103,   104,
     108,   109,   113,   114,   115,   116,   117,   118,   119,   126,
     130,   131,   132,   133,   134,   135,   142,   144,   148,   159,
     160,   164,   170,   174,   175,   176,   177,   178,   182,   183,
     184,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   203,   204,   208,   212,   213,   214,   215,
     220,   221,   225,   226,   230,   231,   232,   238,   242,   243,
     247,   248,   249,   250,   251,   252,   253,   255,   256,   258,
     260,   261,   263,   264,   265,   266,   268,   269,   270,   271,
     272,   273,   275,   278,   281,   284,   287,   290,   293,   296,
     299,   302,   305,   308,   311,   314,   317,   320,   321,   323,
     326,   329,   332,   334,   335,   336,   338,   341,   343,   344,
     345,   347,   353,   354,   358,   359,   363,   364,   368,   369,
     370,   376,   379,   384,   387,   390,   393,   396,   401,   402,
     406,   407,   411,   412,   418,   418,   421,   424,   424,   427,
     427,   430,   430,   433,   433,   438,   444,   445,   449,   453,
     454,   454,   458,   462,   463,   464,   468,   469,   473,   479,
     480,   484,   488,   489,   493,   494,   498,   501,   502,   505,
     508,   509,   513,   517,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538
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
  "WHILE", "FOR", "SWITCH", "CASE", "DEFAULT", "RETURN", "SUPER", "THIS",
  "NEW", "ASYNC", "AS", "FROM", "YIELD", "KEYOF", "CONSTRUCTOR",
  "NAMESPACE", "ABSTRACT", "REQUIRE", "ANY", "NUMBER", "BOOLEAN", "STRING",
  "NEVER", "UNDEFINED", "UNIQUE", "SYMBOL", "OBJECT", "VOID", "UNKNOWN",
  "STRING_LIT", "INT_LIT", "FLOAT_LIT", "NULL_KW", "TRUE_KW", "FALSE_KW",
  "ID", "ENDL", "TEMPLATE_LITERAL", "OPERATOR_INCREMENT",
  "OPERATOR_DECREMENT", "ENDL_OPERATOR_INCREMENT",
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
  "']'", "ENDL_BRACKET_OPEN", "OPTIONAL_CHAINING_OPERATOR", "'('", "')'",
  "';'", "'{'", "'}'", "$accept", "script", "globalStatementList",
  "statementList", "statementListItem",
  "statementListItemWithoutEmptyStatement", "emptyStatement",
  "blockStatement", "initializer", "type", "primaryType",
  "tupleTypeElements", "predefinedType", "typeAnnotationOpt",
  "typeAnnotation", "simpleLiteral", "arrayLiteral", "elementList",
  "elementListItem", "expressionStatement", "singleExpressionOpt",
  "singleExpression", "varStatement", "varDeclarationList",
  "varDeclaration", "varModifier", "ifStatement", "switchStatement",
  "caseClauseList", "caseClause", "defaultClause", "iterationStatement",
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

#define YYPACT_NINF (-258)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     340,  -258,  -258,  -258,  -258,   -94,   685,   685,   860,   -75,
     -38,   -36,  1030,  -258,  -258,  1283,  -258,  -258,  -258,  -258,
    -258,  -258,  -258,  -258,  -258,  -258,  -258,  -258,  -258,  -258,
    -258,  -258,  -258,  -258,  -258,  -258,  -258,  -258,  -258,  -258,
    -258,  1283,  1283,  1283,  1283,  1283,  1283,  1283,  1283,  1283,
    1283,  -258,   548,    55,    74,   860,  -258,  -258,  -258,  -258,
    -258,  -258,  1351,  -258,   284,  -258,  -258,  -258,   947,  -258,
    -258,  -258,  -258,  1283,   -32,    20,    63,  1283,  -258,  1283,
    -258,  1405,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -34,  -258,  2038,   -28,  1459,  -258,   652,  -258,  -258,  -258,
    -258,  -258,  -258,  -258,  -258,  1283,  1283,  1283,  1283,  1283,
    1283,  1283,  1283,  1283,  1283,  1283,  1283,  1283,  1283,  1283,
    1283,  1283,  1283,  1283,  1283,  1283,  1283,  1283,  1283,  1283,
     685,  1283,  1283,  1283,  1115,  -258,   -26,   -48,  -258,    11,
     -24,  2090,   685,  1512,   685,   -20,   685,   137,   -19,  -258,
     -21,  1565,  1618,  -258,  1283,  -258,  1283,  -258,  -258,  -258,
    2228,  2228,  2228,  2228,  2228,  2228,  2228,  2228,  1830,   435,
     538,   734,   734,   734,   734,   105,   105,   105,   105,   105,
     105,   127,   127,   -81,   -81,  -258,  1882,  1934,   -15,  -258,
    1671,  -258,   685,  -258,  1307,    68,  -258,  1283,  1283,   -47,
       6,   445,    31,    73,  -258,    11,    26,  -258,  -258,   685,
     685,    35,  -258,   222,  -258,    77,  -258,  -258,  1283,   860,
      34,  -258,  1283,  -258,  -258,  1199,  -258,  -258,  -258,  -258,
    -258,  -258,  -258,  -258,  -258,  -258,  -258,  -258,  -258,  1307,
    1307,  1307,  -258,    42,  -258,  -258,  1283,    37,  2142,    96,
    1283,  1283,  -258,   135,  -258,  -258,  -258,  -258,  -258,  -258,
    -258,    11,   685,  -258,  -258,   860,    41,   -32,   685,   -20,
    -258,  -258,   -42,   -20,  1724,  -258,    25,   330,  -258,  -258,
      -7,    79,    44,    52,  2185,  1283,  -258,    49,  1777,   860,
    -258,  -258,   756,    53,   -20,    54,  -258,  1283,  -258,    80,
    -258,  -258,  1283,    90,  -258,    27,  -258,   168,  1307,  -258,
    -258,  -258,  -258,    92,   860,  1283,  -258,  -258,  -258,    11,
    -258,  -258,  2142,  -258,    97,  1986,   860,  -258,  -258,   -16,
     -13,  -258,  -258,  -258,   101,   860,   -20,  -258,   860,   860,
    -258,    29,  -258,   860,  -258,  -258,  -258,   860,  -258,  -258,
     860,  -258
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     8,   128,   129,   130,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    72,     0,   185,   186,   187,   188,
     198,   199,   200,   201,   189,   190,   191,   192,   195,   196,
     193,   194,   197,    56,    57,    58,    76,    74,    75,   184,
      59,     0,     0,     0,     0,     0,     0,     0,    64,    64,
       0,    28,     0,     0,     0,     3,    10,    12,    19,    71,
     118,    13,     0,    14,     0,    15,    16,    17,    68,    18,
       4,     5,    70,     0,     0,     0,     0,     0,   155,     0,
     156,     0,   121,    84,    85,    82,    83,    78,    77,    79,
       0,    62,    65,     0,     0,    29,     0,     1,     9,     6,
       7,    11,   109,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    67,     0,     0,   124,    53,
       0,    69,     0,     0,   163,     0,     0,     0,     0,   169,
       0,     0,     0,   157,    64,    60,    66,    61,   112,    30,
     111,    98,   101,   102,    99,   100,   103,   104,     0,   105,
     106,    92,    93,    94,    95,    91,    90,    97,    96,   107,
     108,    86,    87,    88,    89,   117,     0,     0,   116,   113,
       0,   123,     0,   122,     0,   126,    54,    68,     0,     0,
     124,     0,     0,   164,   166,    53,   160,   158,   171,     0,
       0,     0,   172,     0,   174,    53,   183,   170,     0,     0,
       0,    63,     0,   119,   120,     0,   114,   125,    41,    42,
      44,    43,    45,    47,    48,    46,    49,    50,    51,    38,
      38,     0,    55,    32,    34,    52,     0,     0,    69,   108,
      68,     0,    27,   131,    26,    20,    21,    22,    23,    24,
      25,    53,   165,   168,   159,     0,     0,     0,   163,     0,
     173,   175,     0,     0,     0,   146,     0,   110,   115,    39,
       0,     0,     0,     0,   127,    68,   151,     0,     0,     0,
     162,   167,     0,     0,     0,     0,   176,     0,   177,     0,
     179,   144,     0,     0,   133,     0,   138,     0,     0,    36,
      37,    33,    35,     0,     0,    68,   153,   132,   161,    53,
     181,   182,    31,   178,     0,     0,   142,   134,   139,     0,
       0,    40,   147,   152,     0,     0,     0,   145,   140,   143,
     135,     0,   136,     0,   149,   154,   180,   141,   137,   148,
       0,   150
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -258,  -258,  -258,   -49,    -8,  -258,  -258,     9,  -258,  -181,
    -258,   -31,  -258,  -193,  -258,  -188,  -258,   170,    66,    21,
    -156,   -10,    22,    84,  -131,   162,    30,    36,  -253,  -257,
     -73,    38,  -258,  -258,  -258,  -258,  -258,  -258,    43,   181,
    -245,  -258,  -208,   -30,  -258,     1,   188,  -258,   116,  -258,
      56,  -258,  -184,     8
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    53,    54,    55,    56,   253,    57,    58,   299,   279,
     243,   280,   244,   195,   196,    59,    60,    90,    91,    61,
     140,    62,    63,   137,   138,    64,    65,    66,   305,   306,
     307,    67,   324,   343,   350,   314,   335,    68,    69,    70,
     207,   265,   145,   202,   203,   204,    71,   148,   149,   213,
     214,   269,   215,    72
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      76,   302,    81,    96,   302,    82,   245,   273,    73,   192,
     192,   200,   263,   242,    74,    75,   130,   131,   297,   132,
     133,   134,   272,   154,   296,   266,   267,    77,   300,   154,
     146,    83,    84,    85,    86,    87,    88,    89,    92,    92,
      94,   247,   302,   303,   302,   303,   302,   101,   328,   320,
     308,   245,   245,   245,   330,    97,   193,   250,   141,   294,
     282,   227,   298,   143,    78,   155,    79,   151,   290,   152,
     144,   157,   139,   328,    -2,    98,   341,   150,   191,   194,
     197,   218,     6,     7,   328,   206,   147,   134,   101,   251,
     340,   346,   309,   342,   287,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     245,   186,   187,   188,   190,   147,   336,   331,   246,   313,
     262,   304,   264,   327,   261,   348,   308,   268,   185,   276,
     283,   285,   289,   293,    92,   194,   160,   311,   209,   210,
     139,   312,   205,   315,   208,   216,   319,   321,   326,   334,
      16,    17,    18,    19,    20,   211,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,   310,   144,
     126,   127,   128,   129,   323,   302,    39,   248,   249,   126,
     127,   128,   129,   130,   131,   332,   132,   133,   134,   286,
     139,   337,   130,   131,   344,   132,   133,   134,   274,   281,
     254,   275,   277,   128,   129,   160,   292,   216,   216,    93,
     221,   216,   255,   256,   130,   131,   199,   132,   133,   134,
     142,   257,   329,   209,   210,    99,   284,   258,   295,   259,
     248,   288,   100,   212,   260,    16,    17,    18,    19,    20,
     211,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,   291,   217,     0,     0,     0,     0,   271,
     205,    39,     0,     0,     0,   248,   205,   339,     0,     0,
       0,   317,     0,     0,   101,   136,     0,   322,     0,   347,
       0,     0,   325,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   333,    16,    17,    18,
      19,    20,     0,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,     0,     0,   345,   270,     0,
       0,   101,     0,    39,     0,   349,     0,     0,     0,   101,
       0,     1,   351,     2,     3,     4,     5,     0,     6,     7,
       0,     0,     0,     8,     9,    10,    11,     0,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,     0,     0,    33,    34,    35,    36,    37,    38,    39,
       0,    40,    41,    42,    43,    44,     0,     0,     0,   114,
     115,     0,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,     0,     0,
       0,     0,     0,     0,    45,    46,     0,   130,   131,    47,
     132,   133,   134,     0,     0,     0,     0,     0,    48,     0,
      49,     0,    50,     0,    51,    52,   252,     0,     2,     3,
       4,     5,     0,     0,     0,     0,     0,     0,     8,     9,
      10,    11,     0,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,     0,     0,    33,    34,
      35,    36,    37,    38,    39,     0,    40,    41,    42,    43,
      44,     0,     0,     0,     0,   115,     0,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,     0,     0,     0,     0,     0,     0,    45,
      46,     0,   130,   131,    47,   132,   133,   134,     0,     0,
       0,     0,     0,    48,     0,    49,     0,    50,     0,     0,
      52,     2,     3,     4,     5,     0,     0,     0,     0,     0,
       0,     8,     9,    10,    11,     0,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,     0,
       0,    33,    34,    35,    36,    37,    38,    39,     0,    40,
      41,    42,    43,    44,     0,     0,     0,     0,     0,     0,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,     0,     0,     0,     0,
       0,     0,    45,    46,     0,   130,   131,    47,   132,   133,
     134,     0,     0,     0,     0,     0,    48,     0,    49,     0,
      50,     0,    51,    52,    95,     2,     3,     4,     5,     0,
       0,     0,     0,     0,     0,     8,     9,    10,    11,     0,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,     0,     0,    33,    34,    35,    36,    37,
      38,    39,     0,    40,    41,    42,    43,    44,    16,    17,
      18,    19,    20,     0,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,     0,     0,     0,     0,
       0,     0,     0,     0,    39,     0,    45,    46,     0,     0,
       0,    47,     0,     0,     0,     0,     0,     0,     0,     0,
      48,     0,    49,     0,    50,     0,    51,    52,   159,     2,
       3,     4,     5,     0,     0,     0,     0,     0,     0,     8,
       9,    10,    11,     0,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,     0,     0,    33,
      34,    35,    36,    37,    38,    39,     0,    40,    41,    42,
      43,    44,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   130,   131,     0,   132,   133,   134,     0,     0,     0,
      45,    46,     0,     0,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,    49,     0,    50,     0,
      51,    52,   318,     2,     3,     4,     5,     0,     0,     0,
       0,     0,     0,     8,     9,    10,    11,     0,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,     0,     0,    33,    34,    35,    36,    37,    38,    39,
       0,    40,    41,    42,    43,    44,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    45,    46,     0,     0,     0,    47,
       2,     3,     4,     0,     0,     0,     0,     0,    48,     0,
      49,     0,    50,     0,    51,    52,     0,    13,    14,    15,
      16,    17,    18,    19,    20,     0,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     0,     0,
      33,    34,    35,    36,    37,    38,    39,     0,    40,    41,
      42,    43,    44,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    45,    46,     0,     0,     0,    47,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,    49,     0,    50,
      13,    14,    15,    16,    17,    18,    19,    20,     0,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,     0,     0,    33,    34,    35,    36,    37,    38,    39,
       0,    40,    41,    42,    43,    44,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    45,    46,     0,     0,     0,    47,
       0,     0,     0,     0,     0,     0,     0,     0,    48,     0,
      49,     0,    50,     0,    80,    13,    14,    15,    16,    17,
      18,    19,    20,     0,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,     0,     0,    33,    34,
      35,    36,    37,    38,    39,     0,    40,    41,    42,    43,
      44,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    45,
      46,     0,     0,     0,    47,     0,     0,     0,     0,     0,
       0,     0,     0,    48,     0,    49,     0,    50,   189,    13,
      14,    15,    16,    17,    18,    19,    20,     0,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
       0,     0,    33,    34,    35,    36,    37,    38,    39,     0,
      40,    41,    42,    43,    44,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    45,    46,     0,     0,     0,    47,     0,
       0,     0,     0,     0,     0,     0,     0,    48,     0,    49,
       0,    50,   278,    13,    14,    15,    16,    17,    18,    19,
      20,     0,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,     0,     0,    33,    34,    35,    36,
      37,    38,    39,     0,    40,    41,    42,    43,    44,   228,
     229,   230,   231,   232,   233,     0,     0,     0,   234,   235,
      33,    34,    35,   236,   237,   238,     0,     0,    40,     0,
       0,     0,     0,     0,     0,     0,     0,    45,    46,     0,
       0,     0,    47,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,    49,     0,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   102,   103,   104,   239,     0,   240,   105,   241,
       0,   106,   107,   108,   109,   110,   111,   112,   113,     0,
     114,   115,     0,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   130,   131,
       0,   132,   133,   134,     0,   135,   102,   103,   104,     0,
       0,     0,   105,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,     0,   114,   115,     0,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   130,   131,     0,   132,   133,   134,     0,   153,
     102,   103,   104,     0,     0,     0,   105,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,     0,   114,   115,
       0,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   130,   131,     0,   132,
     133,   134,   158,   102,   103,   104,     0,     0,     0,   105,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
       0,   114,   115,     0,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
     131,     0,   132,   133,   134,   201,   102,   103,   104,     0,
       0,     0,   105,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,     0,   114,   115,     0,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   130,   131,     0,   132,   133,   134,   219,   102,
     103,   104,     0,     0,     0,   105,     0,     0,   106,   107,
     108,   109,   110,   111,   112,   113,     0,   114,   115,     0,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,     0,   132,   133,
     134,   220,   102,   103,   104,     0,     0,     0,   225,     0,
       0,   106,   107,   108,   109,   110,   111,   112,   113,     0,
     114,   115,     0,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   130,   131,
       0,   132,   133,   134,   226,   102,   103,   104,     0,     0,
       0,   105,     0,     0,   106,   107,   108,   109,   110,   111,
     112,   113,     0,   114,   115,     0,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   130,   131,     0,   132,   133,   134,   301,   102,   103,
     104,     0,     0,     0,   105,     0,     0,   106,   107,   108,
     109,   110,   111,   112,   113,     0,   114,   115,     0,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   130,   131,     0,   132,   133,   134,
     316,   102,   103,   104,     0,     0,     0,   105,     0,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   222,   114,
     115,     0,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,   131,     0,
     132,   133,   134,   102,   103,   104,     0,     0,     0,   105,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
       0,   114,   115,     0,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
     131,   223,   132,   133,   134,   102,   103,   104,     0,     0,
       0,   105,     0,     0,   106,   107,   108,   109,   110,   111,
     112,   113,     0,   114,   115,     0,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   130,   131,   224,   132,   133,   134,   102,   103,   104,
       0,     0,     0,   105,     0,     0,   106,   107,   108,   109,
     110,   111,   112,   113,   338,   114,   115,     0,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   130,   131,     0,   132,   133,   134,   102,
     103,   104,     0,     0,     0,   156,     0,     0,   106,   107,
     108,   109,   110,   111,   112,   113,     0,   114,   115,     0,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,     0,   132,   133,
     134,   102,   103,   104,     0,     0,     0,   105,     0,     0,
     106,   107,   108,   109,   110,   111,   112,   113,     0,   114,
     115,     0,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   198,   126,   127,   128,   129,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,   131,     0,
     132,   133,   134,   102,   103,   104,     0,     0,     0,   105,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
       0,   114,   115,     0,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
       0,     0,     0,     0,     0,     0,   102,   103,   104,   130,
     131,     0,   132,   133,   134,   106,   107,   108,   109,   110,
     111,   112,   113,     0,   114,   115,     0,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   130,   131,     0,   132,   133,   134,   106,   107,
     108,   109,   110,   111,   112,   113,     0,   114,   115,     0,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,     0,   132,   133,
     134
};

static const yytype_int16 yycheck[] =
{
       8,    17,    12,    52,    17,    15,   194,   215,   102,    57,
      57,   142,   205,   194,     6,     7,    97,    98,    60,   100,
     101,   102,   215,    57,   269,   209,   210,   102,   273,    57,
      10,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,   197,    17,    18,    17,    18,    17,    55,   305,   294,
      57,   239,   240,   241,   307,     0,   104,   104,    68,   267,
     241,   192,   104,    73,   102,    99,   102,    77,   261,    79,
     102,    99,    64,   330,     0,     1,   329,    14,   104,    68,
     104,   102,     8,     9,   341,   105,   105,   102,    96,    83,
     106,   336,    99,   106,   250,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     308,   131,   132,   133,   134,   105,   319,   308,    60,   285,
      57,   106,   106,   106,   103,   106,    57,   102,   130,   105,
      98,   104,     7,   102,   154,    68,   156,   103,    11,    12,
     142,    99,   144,   104,   146,   147,   103,   103,    68,   315,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    99,   102,
      84,    85,    86,    87,   104,    17,    49,   197,   198,    84,
      85,    86,    87,    97,    98,   103,   100,   101,   102,   103,
     192,   104,    97,    98,   103,   100,   101,   102,   218,   240,
     201,   219,   222,    86,    87,   225,   265,   209,   210,    49,
     154,   213,   201,   201,    97,    98,   142,   100,   101,   102,
      68,   201,   305,    11,    12,    54,   246,   201,   268,   201,
     250,   251,    54,   106,   201,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,   262,   148,    -1,    -1,    -1,    -1,   213,
     262,    49,    -1,    -1,    -1,   285,   268,   326,    -1,    -1,
      -1,   289,    -1,    -1,   292,     1,    -1,   297,    -1,   338,
      -1,    -1,   302,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   315,   314,    23,    24,    25,
      26,    27,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,   335,   106,    -1,
      -1,   339,    -1,    49,    -1,   343,    -1,    -1,    -1,   347,
      -1,     1,   350,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    13,    14,    15,    16,    -1,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    -1,    -1,    -1,    69,
      70,    -1,    -1,    -1,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    -1,    97,    98,    89,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,    98,    -1,
     100,    -1,   102,    -1,   104,   105,     1,    -1,     3,     4,
       5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      15,    16,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,    -1,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      85,    -1,    97,    98,    89,   100,   101,   102,    -1,    -1,
      -1,    -1,    -1,    98,    -1,   100,    -1,   102,    -1,    -1,
     105,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,    15,    16,    -1,    -1,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    -1,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    85,    -1,    97,    98,    89,   100,   101,
     102,    -1,    -1,    -1,    -1,    -1,    98,    -1,   100,    -1,
     102,    -1,   104,   105,   106,     3,     4,     5,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    15,    16,    -1,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    43,    44,    45,    46,    47,
      48,    49,    -1,    51,    52,    53,    54,    55,    23,    24,
      25,    26,    27,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    84,    85,    -1,    -1,
      -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    -1,   100,    -1,   102,    -1,   104,   105,   106,     3,
       4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    15,    16,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    -1,    51,    52,    53,
      54,    55,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    -1,   100,   101,   102,    -1,    -1,    -1,
      84,    85,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    -1,   100,    -1,   102,    -1,
     104,   105,   106,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,    15,    16,    -1,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    -1,    -1,    -1,    89,
       3,     4,     5,    -1,    -1,    -1,    -1,    -1,    98,    -1,
     100,    -1,   102,    -1,   104,   105,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    -1,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    -1,    -1,    -1,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    -1,   100,    -1,   102,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    -1,    -1,    -1,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,
     100,    -1,   102,    -1,   104,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,    -1,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      85,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    -1,   100,    -1,   102,   103,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    -1,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    -1,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,   100,
      -1,   102,   103,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    -1,    51,    52,    53,    54,    55,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    -1,
      -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    -1,   100,    -1,   102,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    98,    -1,   100,    57,   102,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      -1,   100,   101,   102,    -1,   104,    51,    52,    53,    -1,
      -1,    -1,    57,    -1,    -1,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    -1,    -1,    -1,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    97,    98,    -1,   100,   101,   102,    -1,   104,
      51,    52,    53,    -1,    -1,    -1,    57,    -1,    -1,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      -1,    -1,    -1,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    -1,   100,
     101,   102,   103,    51,    52,    53,    -1,    -1,    -1,    57,
      -1,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    -1,    -1,    -1,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      98,    -1,   100,   101,   102,   103,    51,    52,    53,    -1,
      -1,    -1,    57,    -1,    -1,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    -1,    -1,    -1,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    97,    98,    -1,   100,   101,   102,   103,    51,
      52,    53,    -1,    -1,    -1,    57,    -1,    -1,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    -1,
      -1,    -1,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    97,    98,    -1,   100,   101,
     102,   103,    51,    52,    53,    -1,    -1,    -1,    57,    -1,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      -1,   100,   101,   102,   103,    51,    52,    53,    -1,    -1,
      -1,    57,    -1,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    -1,    -1,    -1,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    -1,   100,   101,   102,   103,    51,    52,
      53,    -1,    -1,    -1,    57,    -1,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    -1,    -1,
      -1,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    98,    -1,   100,   101,   102,
     103,    51,    52,    53,    -1,    -1,    -1,    57,    -1,    -1,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    -1,
     100,   101,   102,    51,    52,    53,    -1,    -1,    -1,    57,
      -1,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    -1,    -1,    -1,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      98,    99,   100,   101,   102,    51,    52,    53,    -1,    -1,
      -1,    57,    -1,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    -1,    -1,    -1,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    99,   100,   101,   102,    51,    52,    53,
      -1,    -1,    -1,    57,    -1,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    -1,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    98,    -1,   100,   101,   102,    51,
      52,    53,    -1,    -1,    -1,    57,    -1,    -1,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    -1,
      -1,    -1,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    97,    98,    -1,   100,   101,
     102,    51,    52,    53,    -1,    -1,    -1,    57,    -1,    -1,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    -1,    -1,    -1,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    -1,
     100,   101,   102,    51,    52,    53,    -1,    -1,    -1,    57,
      -1,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    -1,    -1,    -1,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    97,
      98,    -1,   100,   101,   102,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    -1,    -1,    -1,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    97,    98,    -1,   100,   101,   102,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    -1,
      -1,    -1,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    97,    98,    -1,   100,   101,
     102
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     8,     9,    13,    14,
      15,    16,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    43,    44,    45,    46,    47,    48,    49,
      51,    52,    53,    54,    55,    84,    85,    89,    98,   100,
     102,   104,   105,   108,   109,   110,   111,   113,   114,   122,
     123,   126,   128,   129,   132,   133,   134,   138,   144,   145,
     146,   153,   160,   102,   160,   160,   111,   102,   102,   102,
     104,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     124,   125,   128,   124,   128,   106,   110,     0,     1,   146,
     153,   111,    51,    52,    53,    57,    60,    61,    62,    63,
      64,    65,    66,    67,    69,    70,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      97,    98,   100,   101,   102,   104,     1,   130,   131,   160,
     127,   128,   132,   128,   102,   149,    10,   105,   154,   155,
      14,   128,   128,   104,    57,    99,    57,    99,   103,   106,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   160,   128,   128,   128,   103,
     128,   104,    57,   104,    68,   120,   121,   104,    83,   130,
     131,   103,   150,   151,   152,   160,   105,   147,   160,    11,
      12,    28,   106,   156,   157,   159,   160,   155,   102,   103,
     103,   125,    68,    99,    99,    57,   103,   131,    32,    33,
      34,    35,    36,    37,    41,    42,    46,    47,    48,    98,
     100,   102,   116,   117,   119,   122,    60,   127,   128,   128,
     104,    83,     1,   112,   114,   126,   129,   133,   134,   138,
     145,   103,    57,   120,   106,   148,   159,   159,   102,   158,
     106,   157,   120,   149,   128,   111,   105,   128,   103,   116,
     118,   118,   116,    98,   128,   104,   103,   127,   128,     7,
     120,   152,   110,   102,   149,   150,   147,    60,   104,   115,
     147,   103,    17,    18,   106,   135,   136,   137,    57,    99,
      99,   103,    99,   127,   142,   104,   103,   111,   106,   103,
     147,   103,   128,   104,   139,   128,    68,   106,   136,   137,
     135,   116,   103,   111,   127,   143,   120,   104,    68,   110,
     106,   135,   106,   140,   103,   111,   147,   110,   106,   111,
     141,   111
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   107,   108,   109,   109,   109,   109,   109,   109,   109,
     110,   110,   111,   111,   111,   111,   111,   111,   111,   111,
     112,   112,   112,   112,   112,   112,   112,   112,   113,   114,
     114,   115,   116,   117,   117,   117,   117,   117,   118,   118,
     118,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   120,   120,   121,   122,   122,   122,   122,
     123,   123,   124,   124,   125,   125,   125,   126,   127,   127,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   129,   129,   130,   130,   131,   131,   132,   132,
     132,   133,   133,   134,   134,   134,   134,   134,   135,   135,
     136,   136,   137,   137,   139,   138,   138,   140,   138,   141,
     138,   142,   138,   143,   138,   144,   145,   145,   146,   147,
     148,   147,   149,   150,   150,   150,   151,   151,   152,   153,
     153,   154,   155,   155,   156,   156,   157,   157,   157,   157,
     157,   157,   158,   159,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     1,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     2,     1,     3,     1,     3,     3,     3,     0,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     2,     1,     1,     1,     1,
       3,     3,     1,     3,     0,     1,     2,     2,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       5,     3,     3,     3,     4,     5,     3,     3,     1,     4,
       4,     2,     3,     3,     1,     3,     2,     4,     1,     1,
       1,     5,     7,     6,     7,     8,     8,     9,     1,     2,
       3,     4,     2,     3,     0,     8,     5,     0,     9,     0,
      10,     0,     7,     0,     8,     2,     2,     3,     4,     2,
       0,     4,     4,     0,     1,     2,     1,     3,     2,     3,
       4,     2,     2,     3,     1,     2,     3,     3,     4,     3,
       6,     4,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
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
#line 2307 "parser.tab.cpp"
    break;

  case 3: /* globalStatementList: statementList  */
#line 96 "parser.y"
                                                { Print("- R: statementList -> globalStatementList"); }
#line 2313 "parser.tab.cpp"
    break;

  case 4: /* globalStatementList: functionDeclaration  */
#line 98 "parser.y"
                                                { Print("- R: functionDeclaration -> globalStatementList"); }
#line 2319 "parser.tab.cpp"
    break;

  case 5: /* globalStatementList: classDeclaration  */
#line 99 "parser.y"
                                                { Print("- R: classDeclaration -> globalStatementList"); }
#line 2325 "parser.tab.cpp"
    break;

  case 6: /* globalStatementList: globalStatementList functionDeclaration  */
#line 100 "parser.y"
                                                { Print("- R: globalStatementList functionDeclaration -> globalStatementList"); }
#line 2331 "parser.tab.cpp"
    break;

  case 7: /* globalStatementList: globalStatementList classDeclaration  */
#line 101 "parser.y"
                                                { Print("- R: globalStatementList classDeclaration -> globalStatementList"); }
#line 2337 "parser.tab.cpp"
    break;

  case 10: /* statementList: statementListItem  */
#line 108 "parser.y"
                                        { Print("- R: statementListItem -> statementList"); }
#line 2343 "parser.tab.cpp"
    break;

  case 11: /* statementList: statementList statementListItem  */
#line 109 "parser.y"
                                        { Print("- R: statementList statementListItem -> statementList"); }
#line 2349 "parser.tab.cpp"
    break;

  case 12: /* statementListItem: emptyStatement  */
#line 113 "parser.y"
                                    { Print("- R: emptyStatement -> statementListItem"); }
#line 2355 "parser.tab.cpp"
    break;

  case 13: /* statementListItem: expressionStatement  */
#line 114 "parser.y"
                                    { Print("- R: expressionStatement -> statementListItem"); }
#line 2361 "parser.tab.cpp"
    break;

  case 14: /* statementListItem: varStatement  */
#line 115 "parser.y"
                                    { Print("- R: varStatement -> statementListItem"); }
#line 2367 "parser.tab.cpp"
    break;

  case 15: /* statementListItem: ifStatement  */
#line 116 "parser.y"
                                    { Print("- R: ifStatement -> statementListItem"); }
#line 2373 "parser.tab.cpp"
    break;

  case 16: /* statementListItem: switchStatement  */
#line 117 "parser.y"
                                    { Print("- R: switchStatement -> statementListItem"); }
#line 2379 "parser.tab.cpp"
    break;

  case 17: /* statementListItem: iterationStatement  */
#line 118 "parser.y"
                                    { Print("- R: iterationStatement -> statementListItem"); }
#line 2385 "parser.tab.cpp"
    break;

  case 18: /* statementListItem: returnStatement  */
#line 120 "parser.y"
        { 
            if ( !isInFunctionBody ) { 
                yyerror("illegal return statement."); YYERROR;
            } 
            Print("- R: returnStatement -> statementListItem"); 
        }
#line 2396 "parser.tab.cpp"
    break;

  case 19: /* statementListItem: blockStatement  */
#line 126 "parser.y"
                                    { Print("- R: blockStatement -> statementListItem"); }
#line 2402 "parser.tab.cpp"
    break;

  case 20: /* statementListItemWithoutEmptyStatement: expressionStatement  */
#line 130 "parser.y"
                                    { Print("- R: expressionStatement -> statementListItemWithoutEmptyStatement"); }
#line 2408 "parser.tab.cpp"
    break;

  case 21: /* statementListItemWithoutEmptyStatement: varStatement  */
#line 131 "parser.y"
                                    { Print("- R: varStatement -> statementListItemWithoutEmptyStatement"); }
#line 2414 "parser.tab.cpp"
    break;

  case 22: /* statementListItemWithoutEmptyStatement: ifStatement  */
#line 132 "parser.y"
                                    { Print("- R: ifStatement -> statementListItemWithoutEmptyStatement"); }
#line 2420 "parser.tab.cpp"
    break;

  case 23: /* statementListItemWithoutEmptyStatement: switchStatement  */
#line 133 "parser.y"
                                    { Print("- R: switchStatement -> statementListItemWithoutEmptyStatement"); }
#line 2426 "parser.tab.cpp"
    break;

  case 24: /* statementListItemWithoutEmptyStatement: iterationStatement  */
#line 134 "parser.y"
                                    { Print("- R: iterationStatement -> statementListItemWithoutEmptyStatement"); }
#line 2432 "parser.tab.cpp"
    break;

  case 25: /* statementListItemWithoutEmptyStatement: returnStatement  */
#line 136 "parser.y"
        { 
            if ( !isInFunctionBody ) { 
                yyerror("illegal return statement."); YYERROR;
            } 
            Print("- R: returnStatement -> statementListItemWithoutEmptyStatement"); 
        }
#line 2443 "parser.tab.cpp"
    break;

  case 26: /* statementListItemWithoutEmptyStatement: blockStatement  */
#line 142 "parser.y"
                                    { Print("- R: blockStatement -> statementListItemWithoutEmptyStatement"); }
#line 2449 "parser.tab.cpp"
    break;

  case 28: /* emptyStatement: ';'  */
#line 149 "parser.y"
        { 
            if ( isASIActivated ) {
                std::string text(yytext_ptr, yyleng);
                yyerror(("syntax error on token: " + text).c_str()); YYERROR;
            }
            Print("- R: ';' -> emptyStatement"); 
        }
#line 2461 "parser.tab.cpp"
    break;

  case 29: /* blockStatement: '{' '}'  */
#line 159 "parser.y"
              { Print("- R: '{' '}' -> blockStatement"); }
#line 2467 "parser.tab.cpp"
    break;

  case 30: /* blockStatement: '{' statementList '}'  */
#line 160 "parser.y"
                            { Print("- R: '{' statementList '}' -> blockStatement"); }
#line 2473 "parser.tab.cpp"
    break;

  case 31: /* initializer: '=' singleExpression  */
#line 164 "parser.y"
                           { Print("- R: '=' singleExpression -> initializer"); }
#line 2479 "parser.tab.cpp"
    break;

  case 32: /* type: primaryType  */
#line 170 "parser.y"
                  { Print("- R: primaryType -> type"); }
#line 2485 "parser.tab.cpp"
    break;

  case 33: /* primaryType: '(' type ')'  */
#line 174 "parser.y"
                                                { Print("- R: '(' type ')' -> primaryType"); }
#line 2491 "parser.tab.cpp"
    break;

  case 34: /* primaryType: predefinedType  */
#line 175 "parser.y"
                                                { Print("- R: predefinedType -> primaryType"); }
#line 2497 "parser.tab.cpp"
    break;

  case 35: /* primaryType: primaryType '[' ']'  */
#line 176 "parser.y"
                                                { Print("- R: primaryType '[' ']' -> primaryType"); }
#line 2503 "parser.tab.cpp"
    break;

  case 36: /* primaryType: '[' tupleTypeElements ']'  */
#line 177 "parser.y"
                                                { Print("- R: '[' tupleTypeElements ']' -> primaryType"); }
#line 2509 "parser.tab.cpp"
    break;

  case 37: /* primaryType: ENDL_BRACKET_OPEN tupleTypeElements ']'  */
#line 178 "parser.y"
                                                { Print("- R: '[' tupleTypeElements ']' -> primaryType"); }
#line 2515 "parser.tab.cpp"
    break;

  case 38: /* tupleTypeElements: %empty  */
#line 182 "parser.y"
                                    { Print("- R: #empty# -> tupleTypeElements"); }
#line 2521 "parser.tab.cpp"
    break;

  case 39: /* tupleTypeElements: type  */
#line 183 "parser.y"
                                    { Print("- R: type -> tupleTypeElements"); }
#line 2527 "parser.tab.cpp"
    break;

  case 40: /* tupleTypeElements: tupleTypeElements ',' type  */
#line 184 "parser.y"
                                    { Print("- R: tupleTypeElements ',' type -> tupleTypeElements"); }
#line 2533 "parser.tab.cpp"
    break;

  case 41: /* predefinedType: ANY  */
#line 188 "parser.y"
                    { Print("- R: ANY -> predefinedType"); }
#line 2539 "parser.tab.cpp"
    break;

  case 42: /* predefinedType: NUMBER  */
#line 189 "parser.y"
                    { Print("- R: NUMBER -> predefinedType"); }
#line 2545 "parser.tab.cpp"
    break;

  case 43: /* predefinedType: STRING  */
#line 190 "parser.y"
                    { Print("- R: STRING -> predefinedType"); }
#line 2551 "parser.tab.cpp"
    break;

  case 44: /* predefinedType: BOOLEAN  */
#line 191 "parser.y"
                    { Print("- R: BOOLEAN -> predefinedType"); }
#line 2557 "parser.tab.cpp"
    break;

  case 45: /* predefinedType: NEVER  */
#line 192 "parser.y"
                    { Print("- R: NEVER -> predefinedType"); }
#line 2563 "parser.tab.cpp"
    break;

  case 46: /* predefinedType: UNKNOWN  */
#line 193 "parser.y"
                    { Print("- R: UNKNOWN -> predefinedType"); }
#line 2569 "parser.tab.cpp"
    break;

  case 47: /* predefinedType: UNDEFINED  */
#line 194 "parser.y"
                    { Print("- R: UNDEFINED -> predefinedType"); }
#line 2575 "parser.tab.cpp"
    break;

  case 48: /* predefinedType: VOID  */
#line 195 "parser.y"
                    { Print("- R: VOID -> predefinedType"); }
#line 2581 "parser.tab.cpp"
    break;

  case 49: /* predefinedType: NULL_KW  */
#line 196 "parser.y"
                    { Print("- R: NULL_KW -> predefinedType"); }
#line 2587 "parser.tab.cpp"
    break;

  case 50: /* predefinedType: TRUE_KW  */
#line 197 "parser.y"
                    { Print("- R: TRUE_WD -> predefinedType"); }
#line 2593 "parser.tab.cpp"
    break;

  case 51: /* predefinedType: FALSE_KW  */
#line 198 "parser.y"
                    { Print("- R: FALSE_KW -> predefinedType"); }
#line 2599 "parser.tab.cpp"
    break;

  case 52: /* predefinedType: simpleLiteral  */
#line 199 "parser.y"
                    { Print("- R: simpleLiteral -> predefinedType"); }
#line 2605 "parser.tab.cpp"
    break;

  case 53: /* typeAnnotationOpt: %empty  */
#line 203 "parser.y"
                        { Print("- R: # empty # -> typeAnnotationOpt"); }
#line 2611 "parser.tab.cpp"
    break;

  case 54: /* typeAnnotationOpt: typeAnnotation  */
#line 204 "parser.y"
                        { Print("- R: typeAnnotation -> typeAnnotationOpt"); }
#line 2617 "parser.tab.cpp"
    break;

  case 55: /* typeAnnotation: ':' type  */
#line 208 "parser.y"
               { Print("- R: ':' type -> typeAnnotation"); }
#line 2623 "parser.tab.cpp"
    break;

  case 56: /* simpleLiteral: STRING_LIT  */
#line 212 "parser.y"
                        { Print("- R: STRING_LIT -> simpleLiteral"); }
#line 2629 "parser.tab.cpp"
    break;

  case 57: /* simpleLiteral: INT_LIT  */
#line 213 "parser.y"
                        { Print("- R: INT_LIT -> simpleLiteral"); }
#line 2635 "parser.tab.cpp"
    break;

  case 58: /* simpleLiteral: FLOAT_LIT  */
#line 214 "parser.y"
                        { Print("- R: FLOAT_LIT -> simpleLiteral"); }
#line 2641 "parser.tab.cpp"
    break;

  case 59: /* simpleLiteral: TEMPLATE_LITERAL  */
#line 215 "parser.y"
                        { Print("- R: TEMPLATE_LITERAL -> simpleLiteral"); }
#line 2647 "parser.tab.cpp"
    break;

  case 60: /* arrayLiteral: '[' elementList ']'  */
#line 220 "parser.y"
                                        { Print("- R: [ elementList ']' -> arrayLiteral"); }
#line 2653 "parser.tab.cpp"
    break;

  case 61: /* arrayLiteral: ENDL_BRACKET_OPEN elementList ']'  */
#line 221 "parser.y"
                                        { Print("- R: ENDL_BRACKET_OPEN elementList ']' -> arrayLiteral"); }
#line 2659 "parser.tab.cpp"
    break;

  case 62: /* elementList: elementListItem  */
#line 225 "parser.y"
                      { Print("- R: elementListItem -> elementList"); }
#line 2665 "parser.tab.cpp"
    break;

  case 63: /* elementList: elementList ',' elementListItem  */
#line 226 "parser.y"
                                                            { Print("- R: elementList ',' elementListItem -> elementList"); }
#line 2671 "parser.tab.cpp"
    break;

  case 64: /* elementListItem: %empty  */
#line 230 "parser.y"
                  { Print("- R: #empty# -> elementListItem"); }
#line 2677 "parser.tab.cpp"
    break;

  case 65: /* elementListItem: singleExpression  */
#line 231 "parser.y"
                       { Print("- R: singleExpression -> elementListItem"); }
#line 2683 "parser.tab.cpp"
    break;

  case 66: /* elementListItem: singleExpression ','  */
#line 232 "parser.y"
                           { Print("- R: singleExpression ',' -> elementListItem"); }
#line 2689 "parser.tab.cpp"
    break;

  case 67: /* expressionStatement: singleExpression ';'  */
#line 238 "parser.y"
                           { Print("- R: expressionList ';' -> expressionStatement"); }
#line 2695 "parser.tab.cpp"
    break;

  case 68: /* singleExpressionOpt: %empty  */
#line 242 "parser.y"
                        { Print("- R: #empty# -> singleExpressionOpt"); }
#line 2701 "parser.tab.cpp"
    break;

  case 69: /* singleExpressionOpt: singleExpression  */
#line 243 "parser.y"
                          { Print("- R: singleExpression -> singleExpressionOpt"); }
#line 2707 "parser.tab.cpp"
    break;

  case 70: /* singleExpression: identifier  */
#line 247 "parser.y"
                    { Print("- R: identifier -> singleExpression"); }
#line 2713 "parser.tab.cpp"
    break;

  case 71: /* singleExpression: simpleLiteral  */
#line 248 "parser.y"
                    { Print("- R: simpleLiteral -> singleExpression"); }
#line 2719 "parser.tab.cpp"
    break;

  case 72: /* singleExpression: THIS  */
#line 249 "parser.y"
                    { Print("- R: THIS -> singleExpression"); }
#line 2725 "parser.tab.cpp"
    break;

  case 73: /* singleExpression: SUPER  */
#line 250 "parser.y"
                    { Print("- R: SUPER -> singleExpression"); }
#line 2731 "parser.tab.cpp"
    break;

  case 74: /* singleExpression: TRUE_KW  */
#line 251 "parser.y"
                    { Print("- R: TRUE_LITERAL -> singleExpression"); }
#line 2737 "parser.tab.cpp"
    break;

  case 75: /* singleExpression: FALSE_KW  */
#line 252 "parser.y"
                    { Print("- R: FALSE_LITERAL -> singleExpression"); }
#line 2743 "parser.tab.cpp"
    break;

  case 76: /* singleExpression: NULL_KW  */
#line 253 "parser.y"
                    { Print("- R: NULL_LITERAL -> singleExpression"); }
#line 2749 "parser.tab.cpp"
    break;

  case 77: /* singleExpression: '-' singleExpression  */
#line 255 "parser.y"
                                        { Print("- R: '-' singleExpression -> singleExpression"); }
#line 2755 "parser.tab.cpp"
    break;

  case 78: /* singleExpression: '+' singleExpression  */
#line 256 "parser.y"
                                        { Print("- R: '+' singleExpression -> singleExpression"); }
#line 2761 "parser.tab.cpp"
    break;

  case 79: /* singleExpression: '!' singleExpression  */
#line 258 "parser.y"
                           { Print("- R: '!' singleExpression -> singleExpression"); }
#line 2767 "parser.tab.cpp"
    break;

  case 80: /* singleExpression: singleExpression OPERATOR_INCREMENT  */
#line 260 "parser.y"
                                                               { Print("- R: singleExpression OPERATOR_INCREMENT -> singleExpression"); }
#line 2773 "parser.tab.cpp"
    break;

  case 81: /* singleExpression: singleExpression OPERATOR_DECREMENT  */
#line 261 "parser.y"
                                                               { Print("- R: singleExpression OPERATOR_DECREMENT -> singleExpression"); }
#line 2779 "parser.tab.cpp"
    break;

  case 82: /* singleExpression: ENDL_OPERATOR_INCREMENT singleExpression  */
#line 263 "parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 2785 "parser.tab.cpp"
    break;

  case 83: /* singleExpression: ENDL_OPERATOR_DECREMENT singleExpression  */
#line 264 "parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 2791 "parser.tab.cpp"
    break;

  case 84: /* singleExpression: OPERATOR_INCREMENT singleExpression  */
#line 265 "parser.y"
                                                               { Print("- R: OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 2797 "parser.tab.cpp"
    break;

  case 85: /* singleExpression: OPERATOR_DECREMENT singleExpression  */
#line 266 "parser.y"
                                                               { Print("- R: OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 2803 "parser.tab.cpp"
    break;

  case 86: /* singleExpression: singleExpression '+' singleExpression  */
#line 268 "parser.y"
                                            { Print("- R: singleExpression '+' singleExpression -> singleExpression"); }
#line 2809 "parser.tab.cpp"
    break;

  case 87: /* singleExpression: singleExpression '-' singleExpression  */
#line 269 "parser.y"
                                            { Print("- R: singleExpression '-' singleExpression -> singleExpression"); }
#line 2815 "parser.tab.cpp"
    break;

  case 88: /* singleExpression: singleExpression '*' singleExpression  */
#line 270 "parser.y"
                                            { Print("- R: singleExpression '*' singleExpression -> singleExpression"); }
#line 2821 "parser.tab.cpp"
    break;

  case 89: /* singleExpression: singleExpression '/' singleExpression  */
#line 271 "parser.y"
                                            { Print("- R: singleExpression '/' singleExpression -> singleExpression"); }
#line 2827 "parser.tab.cpp"
    break;

  case 90: /* singleExpression: singleExpression '<' singleExpression  */
#line 272 "parser.y"
                                            { Print("- R: singleExpression '<' singleExpression -> singleExpression"); }
#line 2833 "parser.tab.cpp"
    break;

  case 91: /* singleExpression: singleExpression '>' singleExpression  */
#line 273 "parser.y"
                                            { Print("- R: singleExpression '>' singleExpression -> singleExpression"); }
#line 2839 "parser.tab.cpp"
    break;

  case 92: /* singleExpression: singleExpression OPERATOR_EQUAL singleExpression  */
#line 276 "parser.y"
        { Print("- R: singleExpression OPERATOR_EQUAL singleExpression -> singleExpression"); }
#line 2845 "parser.tab.cpp"
    break;

  case 93: /* singleExpression: singleExpression OPERATOR_NOT_EQUAL singleExpression  */
#line 279 "parser.y"
        { Print("- R: singleExpression OPERATOR_NOT_EQUAL singleExpression -> singleExpression"); }
#line 2851 "parser.tab.cpp"
    break;

  case 94: /* singleExpression: singleExpression OPERATOR_STRICT_EQUAL singleExpression  */
#line 282 "parser.y"
        { Print("- R: singleExpression OPERATOR_STRICT_EQUAL singleExpression -> singleExpression"); }
#line 2857 "parser.tab.cpp"
    break;

  case 95: /* singleExpression: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression  */
#line 285 "parser.y"
        { Print("- R: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression -> singleExpression"); }
#line 2863 "parser.tab.cpp"
    break;

  case 96: /* singleExpression: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression  */
#line 288 "parser.y"
        { Print("- R: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression -> singleExpression"); }
#line 2869 "parser.tab.cpp"
    break;

  case 97: /* singleExpression: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression  */
#line 291 "parser.y"
        { Print("- R: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression -> singleExpression"); }
#line 2875 "parser.tab.cpp"
    break;

  case 98: /* singleExpression: singleExpression '=' singleExpression  */
#line 294 "parser.y"
        { Print("- R: singleExpression '=' singleExpression -> singleExpression"); }
#line 2881 "parser.tab.cpp"
    break;

  case 99: /* singleExpression: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression  */
#line 297 "parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression -> singleExpression"); }
#line 2887 "parser.tab.cpp"
    break;

  case 100: /* singleExpression: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression  */
#line 300 "parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression -> singleExpression"); }
#line 2893 "parser.tab.cpp"
    break;

  case 101: /* singleExpression: singleExpression OPERATOR_ASSIGN_PLUS singleExpression  */
#line 303 "parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_PLUS singleExpression -> singleExpression"); }
#line 2899 "parser.tab.cpp"
    break;

  case 102: /* singleExpression: singleExpression OPERATOR_ASSIGN_MINUS singleExpression  */
#line 306 "parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_MINUS singleExpression -> singleExpression"); }
#line 2905 "parser.tab.cpp"
    break;

  case 103: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression  */
#line 309 "parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression -> singleExpression"); }
#line 2911 "parser.tab.cpp"
    break;

  case 104: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression  */
#line 312 "parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression -> singleExpression"); }
#line 2917 "parser.tab.cpp"
    break;

  case 105: /* singleExpression: singleExpression OPERATOR_LOGICAL_OR singleExpression  */
#line 315 "parser.y"
        { Print("- R: singleExpression OPERATOR_LOGICAL_OR singleExpression -> singleExpression"); }
#line 2923 "parser.tab.cpp"
    break;

  case 106: /* singleExpression: singleExpression OPERATOR_LOGICAL_AND singleExpression  */
#line 318 "parser.y"
        { Print("- R: singleExpression OPERATOR_LOGICAL_AND singleExpression -> singleExpression"); }
#line 2929 "parser.tab.cpp"
    break;

  case 107: /* singleExpression: singleExpression INSTANCEOF singleExpression  */
#line 320 "parser.y"
                                                    { Print("- R: singleExpression INSTANCEOF singleExpression -> singleExpression"); }
#line 2935 "parser.tab.cpp"
    break;

  case 108: /* singleExpression: singleExpression IN singleExpression  */
#line 321 "parser.y"
                                                    { Print("- R: singleExpression IN singleExpression -> singleExpression"); }
#line 2941 "parser.tab.cpp"
    break;

  case 109: /* singleExpression: singleExpression TEMPLATE_LITERAL  */
#line 324 "parser.y"
        { Print("- R: singleExpression TEMPLATE_LITERAL -> singleExpression"); }
#line 2947 "parser.tab.cpp"
    break;

  case 110: /* singleExpression: singleExpression '?' singleExpression ':' singleExpression  */
#line 327 "parser.y"
        { Print("- R: singleExpression '?' singleExpression ':' singleExpression -> singleExpression"); }
#line 2953 "parser.tab.cpp"
    break;

  case 111: /* singleExpression: singleExpression ',' singleExpression  */
#line 330 "parser.y"
        { Print("- R: singleExpression ',' singleExpressionn -> singleExpression"); }
#line 2959 "parser.tab.cpp"
    break;

  case 112: /* singleExpression: '(' singleExpression ')'  */
#line 332 "parser.y"
                               { Print("- R: '(' expressionList ')' -> singleExpression"); }
#line 2965 "parser.tab.cpp"
    break;

  case 113: /* singleExpression: singleExpression '(' ')'  */
#line 334 "parser.y"
                               { Print("- R: singleExpression '(' ')' -> singleExpression"); }
#line 2971 "parser.tab.cpp"
    break;

  case 114: /* singleExpression: singleExpression '(' singleExpression ')'  */
#line 335 "parser.y"
                                                { Print("- R: singleExpression '(' singleExpression ')' -> singleExpression"); }
#line 2977 "parser.tab.cpp"
    break;

  case 115: /* singleExpression: singleExpression '(' singleExpression ',' ')'  */
#line 336 "parser.y"
                                                    { Print("- R: singleExpression '(' singleExpression ',' ')' -> singleExpression"); }
#line 2983 "parser.tab.cpp"
    break;

  case 116: /* singleExpression: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression  */
#line 339 "parser.y"
        { Print("- R: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression -> singleExpression"); }
#line 2989 "parser.tab.cpp"
    break;

  case 117: /* singleExpression: singleExpression '.' identifier  */
#line 341 "parser.y"
                                      { Print("- R: singleExpression '.' identifier -> singleExpression"); }
#line 2995 "parser.tab.cpp"
    break;

  case 118: /* singleExpression: arrayLiteral  */
#line 343 "parser.y"
                                                              { Print("- R: arrayLiteral -> singleExpression"); }
#line 3001 "parser.tab.cpp"
    break;

  case 119: /* singleExpression: singleExpression '[' singleExpression ']'  */
#line 344 "parser.y"
                                                              { Print("- R: singleExpression '[' expressionList ']' -> singleExpression"); }
#line 3007 "parser.tab.cpp"
    break;

  case 120: /* singleExpression: singleExpression ENDL_BRACKET_OPEN singleExpression ']'  */
#line 345 "parser.y"
                                                              { Print("- R: singleExpression ENDL_BRACKET_OPEN expressionList ']' -> singleExpression"); }
#line 3013 "parser.tab.cpp"
    break;

  case 121: /* singleExpression: NEW singleExpression  */
#line 347 "parser.y"
                           { Print("- R: NEW singleExpression -> singleExpression"); }
#line 3019 "parser.tab.cpp"
    break;

  case 122: /* varStatement: varModifier varDeclarationList ';'  */
#line 353 "parser.y"
                                         { Print("- R: varModifier varDeclarationList ';' -> varStatement"); }
#line 3025 "parser.tab.cpp"
    break;

  case 124: /* varDeclarationList: varDeclaration  */
#line 358 "parser.y"
                                            { Print("- R: varDeclaration -> varDeclarationList"); }
#line 3031 "parser.tab.cpp"
    break;

  case 125: /* varDeclarationList: varDeclarationList ',' varDeclaration  */
#line 359 "parser.y"
                                            { Print("- R: varDeclarationList ',' varDeclaration -> varDeclarationList"); }
#line 3037 "parser.tab.cpp"
    break;

  case 126: /* varDeclaration: identifier typeAnnotationOpt  */
#line 363 "parser.y"
                                                           { Print("- R: identifier typeAnnotationOpt -> varDeclaration"); }
#line 3043 "parser.tab.cpp"
    break;

  case 127: /* varDeclaration: identifier typeAnnotationOpt '=' singleExpression  */
#line 364 "parser.y"
                                                           { Print("- R: identifier typeAnnotationOpt '=' singleExpression -> varDeclaration"); }
#line 3049 "parser.tab.cpp"
    break;

  case 128: /* varModifier: VAR  */
#line 368 "parser.y"
            { Print("- R: VAR -> varModifier"); }
#line 3055 "parser.tab.cpp"
    break;

  case 129: /* varModifier: LET  */
#line 369 "parser.y"
            { Print("- R: LET -> varModifier"); }
#line 3061 "parser.tab.cpp"
    break;

  case 130: /* varModifier: CONST  */
#line 370 "parser.y"
            { Print("- R: CONST -> varModifier"); }
#line 3067 "parser.tab.cpp"
    break;

  case 131: /* ifStatement: IF '(' singleExpression ')' statementListItemWithoutEmptyStatement  */
#line 377 "parser.y"
        { Print("- R: IF '(' expressionList ')' statementListItem -> ifStatement"); }
#line 3073 "parser.tab.cpp"
    break;

  case 132: /* ifStatement: IF '(' singleExpression ')' statementListItemWithoutEmptyStatement ELSE statementListItem  */
#line 380 "parser.y"
        { Print("- R: IF '(' expressionList ')' statementListItem ELSE statementListItem -> ifStatement"); }
#line 3079 "parser.tab.cpp"
    break;

  case 133: /* switchStatement: SWITCH '(' singleExpression ')' '{' '}'  */
#line 385 "parser.y"
        { Print("- R: SWITCH '(' expressionList ')' '{' '}' -> switchStatement"); }
#line 3085 "parser.tab.cpp"
    break;

  case 134: /* switchStatement: SWITCH '(' singleExpression ')' '{' caseClauseList '}'  */
#line 388 "parser.y"
        { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList '}' -> switchStatement"); }
#line 3091 "parser.tab.cpp"
    break;

  case 135: /* switchStatement: SWITCH '(' singleExpression ')' '{' caseClauseList defaultClause '}'  */
#line 391 "parser.y"
        { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause '}' -> switchStatement"); }
#line 3097 "parser.tab.cpp"
    break;

  case 136: /* switchStatement: SWITCH '(' singleExpression ')' '{' defaultClause caseClauseList '}'  */
#line 394 "parser.y"
        { Print("- R: SWITCH '(' expressionList ')' '{' defaultClause caseClauseList '}' -> switchStatement"); }
#line 3103 "parser.tab.cpp"
    break;

  case 137: /* switchStatement: SWITCH '(' singleExpression ')' '{' caseClauseList defaultClause caseClauseList '}'  */
#line 397 "parser.y"
        { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause caseClauseList '}' -> switchStatement"); }
#line 3109 "parser.tab.cpp"
    break;

  case 138: /* caseClauseList: caseClause  */
#line 401 "parser.y"
                                { Print("- R: caseClause -> caseClauseList"); }
#line 3115 "parser.tab.cpp"
    break;

  case 139: /* caseClauseList: caseClauseList caseClause  */
#line 402 "parser.y"
                                { Print("- R: caseClauseList caseClause -> caseClauseList"); }
#line 3121 "parser.tab.cpp"
    break;

  case 140: /* caseClause: CASE singleExpression ':'  */
#line 406 "parser.y"
                                              { Print("- R: CASE expressionList ':' -> caseClause"); }
#line 3127 "parser.tab.cpp"
    break;

  case 141: /* caseClause: CASE singleExpression ':' statementList  */
#line 407 "parser.y"
                                              { Print("- R: CASE expressionList ':' statementList -> caseClause"); }
#line 3133 "parser.tab.cpp"
    break;

  case 142: /* defaultClause: DEFAULT ':'  */
#line 411 "parser.y"
                                { Print("- R: DEFAULT ':' -> defaultClause"); }
#line 3139 "parser.tab.cpp"
    break;

  case 143: /* defaultClause: DEFAULT ':' statementList  */
#line 412 "parser.y"
                                { Print("- R: DEFAULT ':' statementList -> defaultClause"); }
#line 3145 "parser.tab.cpp"
    break;

  case 144: /* $@1: %empty  */
#line 418 "parser.y"
                                                          { doWhileASI(); }
#line 3151 "parser.tab.cpp"
    break;

  case 145: /* iterationStatement: DO statementListItem WHILE '(' singleExpression ')' $@1 ';'  */
#line 419 "parser.y"
        { Print("- R: DO statementListItem WHILE '(' expressionList ')' ';' -> iterationStatement"); }
#line 3157 "parser.tab.cpp"
    break;

  case 146: /* iterationStatement: WHILE '(' singleExpression ')' statementListItem  */
#line 422 "parser.y"
        { Print("- R: WHILE '(' expressionList ')' statementListItem -> iterationStatement"); }
#line 3163 "parser.tab.cpp"
    break;

  case 147: /* $@2: %empty  */
#line 424 "parser.y"
                                                                                        { isInForHeader = 0; }
#line 3169 "parser.tab.cpp"
    break;

  case 148: /* iterationStatement: forHeader singleExpressionOpt ';' singleExpressionOpt ';' singleExpressionOpt ')' $@2 statementListItem  */
#line 425 "parser.y"
        { Print("- R: FOR '(' singleExpressionOpt ';' singleExpressionOpt ';' singleExpressionOpt ')' statementListItem -> iterationStatement"); }
#line 3175 "parser.tab.cpp"
    break;

  case 149: /* $@3: %empty  */
#line 427 "parser.y"
                                                                                                   { isInForHeader = 0; }
#line 3181 "parser.tab.cpp"
    break;

  case 150: /* iterationStatement: forHeader varModifier varDeclarationList ';' singleExpressionOpt ';' singleExpressionOpt ')' $@3 statementListItem  */
#line 428 "parser.y"
        { Print("- R: FOR '(' varModifier varDeclarationList ';' singleExpressionOpt ';' singleExpressionOpt ')' statementListItem -> iterationStatement"); }
#line 3187 "parser.tab.cpp"
    break;

  case 151: /* $@4: %empty  */
#line 430 "parser.y"
                                                         { isInForHeader = 0; }
#line 3193 "parser.tab.cpp"
    break;

  case 152: /* iterationStatement: forHeader singleExpression IN singleExpression ')' $@4 statementListItem  */
#line 431 "parser.y"
        { Print("- R: FOR '(' singleExpression IN singleExpression ')' statementListItem -> iterationStatement"); }
#line 3199 "parser.tab.cpp"
    break;

  case 153: /* $@5: %empty  */
#line 433 "parser.y"
                                                                   { isInForHeader = 0; }
#line 3205 "parser.tab.cpp"
    break;

  case 154: /* iterationStatement: forHeader varModifier varDeclaration IN singleExpression ')' $@5 statementListItem  */
#line 434 "parser.y"
        { Print("- R: FOR '(' varModifier varDeclaration IN expressionList ')' statementListItem -> iterationStatement"); }
#line 3211 "parser.tab.cpp"
    break;

  case 155: /* forHeader: FOR '('  */
#line 438 "parser.y"
               { isInForHeader = 1; }
#line 3217 "parser.tab.cpp"
    break;

  case 156: /* returnStatement: RETURN ';'  */
#line 444 "parser.y"
                                    { Print("- R: RETURN ';' -> returnStatement"); }
#line 3223 "parser.tab.cpp"
    break;

  case 157: /* returnStatement: RETURN singleExpression ';'  */
#line 445 "parser.y"
                                    { Print("- R: RETURN singleExpression ';' -> returnStatement"); }
#line 3229 "parser.tab.cpp"
    break;

  case 158: /* functionDeclaration: FUNCTION identifier callSignature functionBody  */
#line 449 "parser.y"
                                                     { Print("- R: FUNCTION ID callSignature functionBody -> functionDeclaration"); }
#line 3235 "parser.tab.cpp"
    break;

  case 159: /* functionBody: '{' '}'  */
#line 453 "parser.y"
                                                        { Print("- R: '{' '}' -> functionBody"); }
#line 3241 "parser.tab.cpp"
    break;

  case 160: /* $@6: %empty  */
#line 454 "parser.y"
          { isInFunctionBody = 1; }
#line 3247 "parser.tab.cpp"
    break;

  case 161: /* functionBody: '{' $@6 statementList '}'  */
#line 454 "parser.y"
                                                        { isInFunctionBody = 0; Print("- R: '{' statementList '}' -> functionBody"); }
#line 3253 "parser.tab.cpp"
    break;

  case 162: /* callSignature: '(' parameterList ')' typeAnnotationOpt  */
#line 458 "parser.y"
                                               { Print("- R : '(' parameterList ')' typeAnnotation -> callSignature"); }
#line 3259 "parser.tab.cpp"
    break;

  case 163: /* parameterList: %empty  */
#line 462 "parser.y"
                         { Print("- R: #empty# -> parameterList"); }
#line 3265 "parser.tab.cpp"
    break;

  case 164: /* parameterList: requiredParameterList  */
#line 463 "parser.y"
                            { Print("- R: requiredParameterList -> parameterList"); }
#line 3271 "parser.tab.cpp"
    break;

  case 165: /* parameterList: requiredParameterList ','  */
#line 464 "parser.y"
                                { Print("- R: requiredParameterList ',' -> parameterList"); }
#line 3277 "parser.tab.cpp"
    break;

  case 166: /* requiredParameterList: requiredParameter  */
#line 468 "parser.y"
                                                    { Print("- R: requiredParameter -> requiredParameterList"); }
#line 3283 "parser.tab.cpp"
    break;

  case 167: /* requiredParameterList: requiredParameterList ',' requiredParameter  */
#line 469 "parser.y"
                                                    { Print("- R: requiredParameterList ',' requiredParameter -> requiredParameterList"); }
#line 3289 "parser.tab.cpp"
    break;

  case 168: /* requiredParameter: identifier typeAnnotationOpt  */
#line 473 "parser.y"
                                   { Print("- R: ID typeAnnotationOpt -> requiredParameter"); }
#line 3295 "parser.tab.cpp"
    break;

  case 169: /* classDeclaration: CLASS identifier classTail  */
#line 479 "parser.y"
                                                { Print("- R: CLASS identifier classTail -> classDeclaration"); }
#line 3301 "parser.tab.cpp"
    break;

  case 170: /* classDeclaration: CLASS identifier classHeritage classTail  */
#line 480 "parser.y"
                                                { Print("- R: CLASS identifier classHeritage classTail -> classDeclaration"); }
#line 3307 "parser.tab.cpp"
    break;

  case 171: /* classHeritage: EXTENDS identifier  */
#line 484 "parser.y"
                         { Print("- R: EXTENDS identifier -> classHeritage"); }
#line 3313 "parser.tab.cpp"
    break;

  case 172: /* classTail: '{' '}'  */
#line 488 "parser.y"
                                { Print("- R: '{' '}' -> classTail"); }
#line 3319 "parser.tab.cpp"
    break;

  case 173: /* classTail: '{' classElementList '}'  */
#line 489 "parser.y"
                                { Print("- R: '{' classElementList '}' -> classTail"); }
#line 3325 "parser.tab.cpp"
    break;

  case 174: /* classElementList: classElement  */
#line 493 "parser.y"
                   { Print("- R: classElement -> classElementList"); }
#line 3331 "parser.tab.cpp"
    break;

  case 175: /* classElementList: classElementList classElement  */
#line 494 "parser.y"
                                    { Print("- R: classElementList classElement -> classElementList"); }
#line 3337 "parser.tab.cpp"
    break;

  case 176: /* classElement: CONSTRUCTOR constructorCallSignature functionBody  */
#line 498 "parser.y"
                                                        { Print("- R: CONSTRUCTOR callSignature functionBody -> classElement"); }
#line 3343 "parser.tab.cpp"
    break;

  case 177: /* classElement: propertyName typeAnnotationOpt ';'  */
#line 501 "parser.y"
                                                       { Print("- R: propertyName typeAnnotationOpt ';' -> classElement"); }
#line 3349 "parser.tab.cpp"
    break;

  case 178: /* classElement: propertyName typeAnnotationOpt initializer ';'  */
#line 502 "parser.y"
                                                       { Print("- R: propertyName typeAnnotationOpt initializer ';' -> classElement"); }
#line 3355 "parser.tab.cpp"
    break;

  case 179: /* classElement: propertyName callSignature functionBody  */
#line 505 "parser.y"
                                              { Print("- R: propertyName callSignature functionBody -> classElement"); }
#line 3361 "parser.tab.cpp"
    break;

  case 180: /* classElement: GET propertyName '(' ')' typeAnnotationOpt functionBody  */
#line 508 "parser.y"
                                                               { Print("- R: GET propertyName '(' ')' typeAnnotationOpt functionBody -> classElement"); }
#line 3367 "parser.tab.cpp"
    break;

  case 181: /* classElement: SET propertyName callSignature functionBody  */
#line 509 "parser.y"
                                                            { Print("- R: SET propertyName callSignature functionBody -> classElement"); }
#line 3373 "parser.tab.cpp"
    break;

  case 182: /* constructorCallSignature: '(' parameterList ')'  */
#line 513 "parser.y"
                            { Print("- R: '(' parameterList ')' -> constructorCallSignature"); }
#line 3379 "parser.tab.cpp"
    break;

  case 183: /* propertyName: identifier  */
#line 517 "parser.y"
                                            { Print("- R: identifier -> propertyName"); }
#line 3385 "parser.tab.cpp"
    break;

  case 184: /* identifier: ID  */
#line 521 "parser.y"
                { Print("- R: ID -> identifier"); }
#line 3391 "parser.tab.cpp"
    break;

  case 185: /* identifier: ASYNC  */
#line 522 "parser.y"
                { Print("- R: ASYNC -> identifier"); }
#line 3397 "parser.tab.cpp"
    break;

  case 186: /* identifier: AS  */
#line 523 "parser.y"
                { Print("- R: AS -> identifier"); }
#line 3403 "parser.tab.cpp"
    break;

  case 187: /* identifier: FROM  */
#line 524 "parser.y"
                { Print("- R: FROM -> identifier"); }
#line 3409 "parser.tab.cpp"
    break;

  case 188: /* identifier: YIELD  */
#line 525 "parser.y"
                { Print("- R: YIELD -> identifier"); }
#line 3415 "parser.tab.cpp"
    break;

  case 189: /* identifier: ANY  */
#line 526 "parser.y"
                { Print("- R: ANY -> identifier"); }
#line 3421 "parser.tab.cpp"
    break;

  case 190: /* identifier: NUMBER  */
#line 527 "parser.y"
                { Print("- R: NUMBER -> identifier"); }
#line 3427 "parser.tab.cpp"
    break;

  case 191: /* identifier: BOOLEAN  */
#line 528 "parser.y"
                { Print("- R: BOOLEAN -> identifier"); }
#line 3433 "parser.tab.cpp"
    break;

  case 192: /* identifier: STRING  */
#line 529 "parser.y"
                { Print("- R: STRING -> identifier"); }
#line 3439 "parser.tab.cpp"
    break;

  case 193: /* identifier: UNIQUE  */
#line 530 "parser.y"
                { Print("- R: UNIQUE -> identifier"); }
#line 3445 "parser.tab.cpp"
    break;

  case 194: /* identifier: SYMBOL  */
#line 531 "parser.y"
                { Print("- R: SYMBOL -> identifier"); }
#line 3451 "parser.tab.cpp"
    break;

  case 195: /* identifier: NEVER  */
#line 532 "parser.y"
                { Print("- R: NEVER -> identifier"); }
#line 3457 "parser.tab.cpp"
    break;

  case 196: /* identifier: UNDEFINED  */
#line 533 "parser.y"
                { Print("- R: UNDEFINED -> identifier"); }
#line 3463 "parser.tab.cpp"
    break;

  case 197: /* identifier: OBJECT  */
#line 534 "parser.y"
                { Print("- R: OBJECT -> identifier"); }
#line 3469 "parser.tab.cpp"
    break;

  case 198: /* identifier: KEYOF  */
#line 535 "parser.y"
                { Print("- R: KEYOF -> identifier"); }
#line 3475 "parser.tab.cpp"
    break;

  case 199: /* identifier: NAMESPACE  */
#line 536 "parser.y"
                { Print("- R: NAMESPACE -> identifier"); }
#line 3481 "parser.tab.cpp"
    break;

  case 200: /* identifier: ABSTRACT  */
#line 537 "parser.y"
                { Print("- R: ABSTRACT -> identifier"); }
#line 3487 "parser.tab.cpp"
    break;

  case 201: /* identifier: REQUIRE  */
#line 538 "parser.y"
                { Print("- R: REQUIRE -> identifier"); }
#line 3493 "parser.tab.cpp"
    break;


#line 3497 "parser.tab.cpp"

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

#line 541 "parser.y"



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


