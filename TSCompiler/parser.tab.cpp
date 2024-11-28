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
int isInIterationBody = 0; // need for continue & break stmt
int isInForHeader = 0;

int syntaxErrorCounter = 0;

#line 98 "parser.tab.cpp"

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
  YYSYMBOL_CONTINUE = 16,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 17,                     /* BREAK  */
  YYSYMBOL_SWITCH = 18,                    /* SWITCH  */
  YYSYMBOL_CASE = 19,                      /* CASE  */
  YYSYMBOL_DEFAULT = 20,                   /* DEFAULT  */
  YYSYMBOL_RETURN = 21,                    /* RETURN  */
  YYSYMBOL_SUPER = 22,                     /* SUPER  */
  YYSYMBOL_THIS = 23,                      /* THIS  */
  YYSYMBOL_NEW = 24,                       /* NEW  */
  YYSYMBOL_ELLIPSIS = 25,                  /* ELLIPSIS  */
  YYSYMBOL_OF = 26,                        /* OF  */
  YYSYMBOL_ASYNC = 27,                     /* ASYNC  */
  YYSYMBOL_AS = 28,                        /* AS  */
  YYSYMBOL_FROM = 29,                      /* FROM  */
  YYSYMBOL_YIELD = 30,                     /* YIELD  */
  YYSYMBOL_KEYOF = 31,                     /* KEYOF  */
  YYSYMBOL_CONSTRUCTOR = 32,               /* CONSTRUCTOR  */
  YYSYMBOL_NAMESPACE = 33,                 /* NAMESPACE  */
  YYSYMBOL_ABSTRACT = 34,                  /* ABSTRACT  */
  YYSYMBOL_REQUIRE = 35,                   /* REQUIRE  */
  YYSYMBOL_ANY = 36,                       /* ANY  */
  YYSYMBOL_NUMBER = 37,                    /* NUMBER  */
  YYSYMBOL_BOOLEAN = 38,                   /* BOOLEAN  */
  YYSYMBOL_STRING = 39,                    /* STRING  */
  YYSYMBOL_NEVER = 40,                     /* NEVER  */
  YYSYMBOL_UNDEFINED = 41,                 /* UNDEFINED  */
  YYSYMBOL_UNIQUE = 42,                    /* UNIQUE  */
  YYSYMBOL_SYMBOL = 43,                    /* SYMBOL  */
  YYSYMBOL_OBJECT = 44,                    /* OBJECT  */
  YYSYMBOL_VOID = 45,                      /* VOID  */
  YYSYMBOL_UNKNOWN = 46,                   /* UNKNOWN  */
  YYSYMBOL_STRING_LIT = 47,                /* STRING_LIT  */
  YYSYMBOL_INT_LIT = 48,                   /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 49,                 /* FLOAT_LIT  */
  YYSYMBOL_NULL_KW = 50,                   /* NULL_KW  */
  YYSYMBOL_TRUE_KW = 51,                   /* TRUE_KW  */
  YYSYMBOL_FALSE_KW = 52,                  /* FALSE_KW  */
  YYSYMBOL_ID = 53,                        /* ID  */
  YYSYMBOL_ENDL = 54,                      /* ENDL  */
  YYSYMBOL_TEMPLATE_LITERAL = 55,          /* TEMPLATE_LITERAL  */
  YYSYMBOL_OPERATOR_INCREMENT = 56,        /* OPERATOR_INCREMENT  */
  YYSYMBOL_OPERATOR_DECREMENT = 57,        /* OPERATOR_DECREMENT  */
  YYSYMBOL_ENDL_OPERATOR_INCREMENT = 58,   /* ENDL_OPERATOR_INCREMENT  */
  YYSYMBOL_ENDL_OPERATOR_DECREMENT = 59,   /* ENDL_OPERATOR_DECREMENT  */
  YYSYMBOL_IF_ONLY_PREC = 60,              /* IF_ONLY_PREC  */
  YYSYMBOL_61_ = 61,                       /* ','  */
  YYSYMBOL_62_ = 62,                       /* '='  */
  YYSYMBOL_OPERATOR_ASSIGN_PLUS = 63,      /* OPERATOR_ASSIGN_PLUS  */
  YYSYMBOL_OPERATOR_ASSIGN_MINUS = 64,     /* OPERATOR_ASSIGN_MINUS  */
  YYSYMBOL_OPERATOR_ASSIGN_POWER = 65,     /* OPERATOR_ASSIGN_POWER  */
  YYSYMBOL_OPERATOR_ASSIGN_MULTIPLY = 66,  /* OPERATOR_ASSIGN_MULTIPLY  */
  YYSYMBOL_OPERATOR_ASSIGN_DIVIDE = 67,    /* OPERATOR_ASSIGN_DIVIDE  */
  YYSYMBOL_OPERATOR_ASSIGN_MOD = 68,       /* OPERATOR_ASSIGN_MOD  */
  YYSYMBOL_OPERATOR_ASSIGN_SHIFT_LEFT = 69, /* OPERATOR_ASSIGN_SHIFT_LEFT  */
  YYSYMBOL_OPERATOR_ASSIGN_SHIFT_RIGHT = 70, /* OPERATOR_ASSIGN_SHIFT_RIGHT  */
  YYSYMBOL_OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT = 71, /* OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT  */
  YYSYMBOL_OPERATOR_ASSIGN_BITWISE_AND = 72, /* OPERATOR_ASSIGN_BITWISE_AND  */
  YYSYMBOL_OPERATOR_ASSIGN_BITWISE_XOR = 73, /* OPERATOR_ASSIGN_BITWISE_XOR  */
  YYSYMBOL_OPERATOR_ASSIGN_BITWISE_OR = 74, /* OPERATOR_ASSIGN_BITWISE_OR  */
  YYSYMBOL_OPERATOR_ASSIGN_LOGICAL_AND = 75, /* OPERATOR_ASSIGN_LOGICAL_AND  */
  YYSYMBOL_OPERATOR_ASSIGN_LOGICAL_OR = 76, /* OPERATOR_ASSIGN_LOGICAL_OR  */
  YYSYMBOL_OPERATOR_ASSIGN_NULLISH_COALESCING = 77, /* OPERATOR_ASSIGN_NULLISH_COALESCING  */
  YYSYMBOL_78_ = 78,                       /* '?'  */
  YYSYMBOL_79_ = 79,                       /* ':'  */
  YYSYMBOL_OPERATOR_NULLISH_COALESCING = 80, /* OPERATOR_NULLISH_COALESCING  */
  YYSYMBOL_OPERATOR_LOGICAL_OR = 81,       /* OPERATOR_LOGICAL_OR  */
  YYSYMBOL_OPERATOR_LOGICAL_AND = 82,      /* OPERATOR_LOGICAL_AND  */
  YYSYMBOL_83_ = 83,                       /* '|'  */
  YYSYMBOL_84_ = 84,                       /* '^'  */
  YYSYMBOL_85_ = 85,                       /* '&'  */
  YYSYMBOL_OPERATOR_EQUAL = 86,            /* OPERATOR_EQUAL  */
  YYSYMBOL_OPERATOR_NOT_EQUAL = 87,        /* OPERATOR_NOT_EQUAL  */
  YYSYMBOL_OPERATOR_STRICT_EQUAL = 88,     /* OPERATOR_STRICT_EQUAL  */
  YYSYMBOL_OPERATOR_STRICT_NOT_EQUAL = 89, /* OPERATOR_STRICT_NOT_EQUAL  */
  YYSYMBOL_90_ = 90,                       /* '>'  */
  YYSYMBOL_91_ = 91,                       /* '<'  */
  YYSYMBOL_OPERATOR_GREATER_THAN_EQUAL = 92, /* OPERATOR_GREATER_THAN_EQUAL  */
  YYSYMBOL_OPERATOR_LESS_THAN_EQUAL = 93,  /* OPERATOR_LESS_THAN_EQUAL  */
  YYSYMBOL_INSTANCEOF = 94,                /* INSTANCEOF  */
  YYSYMBOL_IN = 95,                        /* IN  */
  YYSYMBOL_OPERATOR_SHIFT_LEFT = 96,       /* OPERATOR_SHIFT_LEFT  */
  YYSYMBOL_OPERATOR_SHIFT_RIGHT = 97,      /* OPERATOR_SHIFT_RIGHT  */
  YYSYMBOL_OPERATOR_UNSIGNED_SHIFT_RIGHT = 98, /* OPERATOR_UNSIGNED_SHIFT_RIGHT  */
  YYSYMBOL_99_ = 99,                       /* '+'  */
  YYSYMBOL_100_ = 100,                     /* '-'  */
  YYSYMBOL_101_ = 101,                     /* '*'  */
  YYSYMBOL_102_ = 102,                     /* '/'  */
  YYSYMBOL_103_ = 103,                     /* '%'  */
  YYSYMBOL_OPERATOR_POWER = 104,           /* OPERATOR_POWER  */
  YYSYMBOL_105_ = 105,                     /* '!'  */
  YYSYMBOL_106_ = 106,                     /* '~'  */
  YYSYMBOL_UMINUS = 107,                   /* UMINUS  */
  YYSYMBOL_UPLUS = 108,                    /* UPLUS  */
  YYSYMBOL_PREF_INCREMENT = 109,           /* PREF_INCREMENT  */
  YYSYMBOL_PREF_DECREMENT = 110,           /* PREF_DECREMENT  */
  YYSYMBOL_POST_INCREMENT = 111,           /* POST_INCREMENT  */
  YYSYMBOL_POST_DECREMENT = 112,           /* POST_DECREMENT  */
  YYSYMBOL_113_ = 113,                     /* '.'  */
  YYSYMBOL_114_ = 114,                     /* '['  */
  YYSYMBOL_115_ = 115,                     /* ']'  */
  YYSYMBOL_ENDL_BRACKET_OPEN = 116,        /* ENDL_BRACKET_OPEN  */
  YYSYMBOL_OPTIONAL_CHAINING_OPERATOR = 117, /* OPTIONAL_CHAINING_OPERATOR  */
  YYSYMBOL_118_ = 118,                     /* '('  */
  YYSYMBOL_119_ = 119,                     /* ')'  */
  YYSYMBOL_120_ = 120,                     /* ';'  */
  YYSYMBOL_121_ = 121,                     /* '{'  */
  YYSYMBOL_122_ = 122,                     /* '}'  */
  YYSYMBOL_YYACCEPT = 123,                 /* $accept  */
  YYSYMBOL_script = 124,                   /* script  */
  YYSYMBOL_statementList = 125,            /* statementList  */
  YYSYMBOL_statementListItem = 126,        /* statementListItem  */
  YYSYMBOL_statementListItemWithoutEmptyStatement = 127, /* statementListItemWithoutEmptyStatement  */
  YYSYMBOL_emptyStatement = 128,           /* emptyStatement  */
  YYSYMBOL_initializer = 129,              /* initializer  */
  YYSYMBOL_type = 130,                     /* type  */
  YYSYMBOL_unionOrIntersectionOrPrimaryType = 131, /* unionOrIntersectionOrPrimaryType  */
  YYSYMBOL_primaryType = 132,              /* primaryType  */
  YYSYMBOL_tupleTypeElements = 133,        /* tupleTypeElements  */
  YYSYMBOL_predefinedType = 134,           /* predefinedType  */
  YYSYMBOL_typeAnnotation = 135,           /* typeAnnotation  */
  YYSYMBOL_simpleLiteral = 136,            /* simpleLiteral  */
  YYSYMBOL_arrayLiteral = 137,             /* arrayLiteral  */
  YYSYMBOL_elementList = 138,              /* elementList  */
  YYSYMBOL_arrayElement = 139,             /* arrayElement  */
  YYSYMBOL_expressionStatement = 140,      /* expressionStatement  */
  YYSYMBOL_expressionListOpt = 141,        /* expressionListOpt  */
  YYSYMBOL_expressionList = 142,           /* expressionList  */
  YYSYMBOL_singleExpression = 143,         /* singleExpression  */
  YYSYMBOL_arguments = 144,                /* arguments  */
  YYSYMBOL_argumentList = 145,             /* argumentList  */
  YYSYMBOL_argument = 146,                 /* argument  */
  YYSYMBOL_varStatement = 147,             /* varStatement  */
  YYSYMBOL_varDeclarationList = 148,       /* varDeclarationList  */
  YYSYMBOL_varDeclaration = 149,           /* varDeclaration  */
  YYSYMBOL_varModifier = 150,              /* varModifier  */
  YYSYMBOL_ifStatement = 151,              /* ifStatement  */
  YYSYMBOL_iterationStatement = 152,       /* iterationStatement  */
  YYSYMBOL_153_1 = 153,                    /* $@1  */
  YYSYMBOL_154_2 = 154,                    /* $@2  */
  YYSYMBOL_155_3 = 155,                    /* $@3  */
  YYSYMBOL_156_4 = 156,                    /* $@4  */
  YYSYMBOL_157_5 = 157,                    /* $@5  */
  YYSYMBOL_158_6 = 158,                    /* $@6  */
  YYSYMBOL_159_7 = 159,                    /* $@7  */
  YYSYMBOL_forHeader = 160,                /* forHeader  */
  YYSYMBOL_continueStatement = 161,        /* continueStatement  */
  YYSYMBOL_breakStatement = 162,           /* breakStatement  */
  YYSYMBOL_returnStatement = 163,          /* returnStatement  */
  YYSYMBOL_labelledStatement = 164,        /* labelledStatement  */
  YYSYMBOL_blockStatement = 165,           /* blockStatement  */
  YYSYMBOL_switchStatement = 166,          /* switchStatement  */
  YYSYMBOL_caseClauseList = 167,           /* caseClauseList  */
  YYSYMBOL_caseClause = 168,               /* caseClause  */
  YYSYMBOL_defaultClause = 169,            /* defaultClause  */
  YYSYMBOL_functionDeclaration = 170,      /* functionDeclaration  */
  YYSYMBOL_functionBody = 171,             /* functionBody  */
  YYSYMBOL_172_8 = 172,                    /* $@8  */
  YYSYMBOL_callSignature = 173,            /* callSignature  */
  YYSYMBOL_parameterList = 174,            /* parameterList  */
  YYSYMBOL_parameter = 175,                /* parameter  */
  YYSYMBOL_requiredParameter = 176,        /* requiredParameter  */
  YYSYMBOL_optionalParameter = 177,        /* optionalParameter  */
  YYSYMBOL_restParameter = 178,            /* restParameter  */
  YYSYMBOL_classDeclaration = 179,         /* classDeclaration  */
  YYSYMBOL_classHeritage = 180,            /* classHeritage  */
  YYSYMBOL_classTail = 181,                /* classTail  */
  YYSYMBOL_classElementList = 182,         /* classElementList  */
  YYSYMBOL_classElement = 183,             /* classElement  */
  YYSYMBOL_constructorCallSignature = 184, /* constructorCallSignature  */
  YYSYMBOL_propertyName = 185,             /* propertyName  */
  YYSYMBOL_identifier = 186                /* identifier  */
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
#define YYFINAL  109
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2320

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  123
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  264
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  456

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   353


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
       2,     2,     2,   105,     2,     2,     2,   103,    85,     2,
     118,   119,   101,    99,    61,   100,   113,   102,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    79,   120,
      91,    62,    90,    78,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   114,     2,   115,    84,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   121,    83,   122,   106,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    80,    81,    82,    86,    87,    88,    89,    92,    93,
      94,    95,    96,    97,    98,   104,   107,   108,   109,   110,
     111,   112,   116,   117
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    89,    89,   100,   101,   105,   106,   107,   108,   109,
     110,   111,   118,   125,   132,   133,   134,   135,   139,   140,
     141,   142,   143,   144,   151,   158,   165,   166,   167,   168,
     172,   183,   189,   190,   191,   195,   196,   197,   201,   202,
     203,   204,   205,   206,   210,   211,   212,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   231,
     235,   236,   237,   238,   243,   244,   248,   249,   250,   254,
     255,   261,   265,   266,   270,   271,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   332,   333,   335,   336,   338,   340,   342,   343,
     345,   346,   347,   349,   353,   354,   355,   359,   360,   364,
     365,   371,   375,   376,   380,   381,   382,   383,   387,   388,
     389,   395,   396,   400,   400,   400,   401,   401,   402,   402,
     403,   403,   404,   404,   405,   405,   409,   413,   414,   418,
     419,   423,   424,   428,   432,   433,   437,   438,   439,   440,
     444,   445,   449,   450,   454,   455,   461,   465,   466,   466,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     483,   484,   488,   489,   493,   494,   498,   499,   500,   501,
     505,   506,   512,   513,   517,   521,   522,   526,   527,   531,
     534,   535,   536,   537,   540,   543,   544,   545,   549,   550,
     551,   552,   553,   557,   558,   559,   560,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581
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
  "WHILE", "FOR", "CONTINUE", "BREAK", "SWITCH", "CASE", "DEFAULT",
  "RETURN", "SUPER", "THIS", "NEW", "ELLIPSIS", "OF", "ASYNC", "AS",
  "FROM", "YIELD", "KEYOF", "CONSTRUCTOR", "NAMESPACE", "ABSTRACT",
  "REQUIRE", "ANY", "NUMBER", "BOOLEAN", "STRING", "NEVER", "UNDEFINED",
  "UNIQUE", "SYMBOL", "OBJECT", "VOID", "UNKNOWN", "STRING_LIT", "INT_LIT",
  "FLOAT_LIT", "NULL_KW", "TRUE_KW", "FALSE_KW", "ID", "ENDL",
  "TEMPLATE_LITERAL", "OPERATOR_INCREMENT", "OPERATOR_DECREMENT",
  "ENDL_OPERATOR_INCREMENT", "ENDL_OPERATOR_DECREMENT", "IF_ONLY_PREC",
  "','", "'='", "OPERATOR_ASSIGN_PLUS", "OPERATOR_ASSIGN_MINUS",
  "OPERATOR_ASSIGN_POWER", "OPERATOR_ASSIGN_MULTIPLY",
  "OPERATOR_ASSIGN_DIVIDE", "OPERATOR_ASSIGN_MOD",
  "OPERATOR_ASSIGN_SHIFT_LEFT", "OPERATOR_ASSIGN_SHIFT_RIGHT",
  "OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT", "OPERATOR_ASSIGN_BITWISE_AND",
  "OPERATOR_ASSIGN_BITWISE_XOR", "OPERATOR_ASSIGN_BITWISE_OR",
  "OPERATOR_ASSIGN_LOGICAL_AND", "OPERATOR_ASSIGN_LOGICAL_OR",
  "OPERATOR_ASSIGN_NULLISH_COALESCING", "'?'", "':'",
  "OPERATOR_NULLISH_COALESCING", "OPERATOR_LOGICAL_OR",
  "OPERATOR_LOGICAL_AND", "'|'", "'^'", "'&'", "OPERATOR_EQUAL",
  "OPERATOR_NOT_EQUAL", "OPERATOR_STRICT_EQUAL",
  "OPERATOR_STRICT_NOT_EQUAL", "'>'", "'<'", "OPERATOR_GREATER_THAN_EQUAL",
  "OPERATOR_LESS_THAN_EQUAL", "INSTANCEOF", "IN", "OPERATOR_SHIFT_LEFT",
  "OPERATOR_SHIFT_RIGHT", "OPERATOR_UNSIGNED_SHIFT_RIGHT", "'+'", "'-'",
  "'*'", "'/'", "'%'", "OPERATOR_POWER", "'!'", "'~'", "UMINUS", "UPLUS",
  "PREF_INCREMENT", "PREF_DECREMENT", "POST_INCREMENT", "POST_DECREMENT",
  "'.'", "'['", "']'", "ENDL_BRACKET_OPEN", "OPTIONAL_CHAINING_OPERATOR",
  "'('", "')'", "';'", "'{'", "'}'", "$accept", "script", "statementList",
  "statementListItem", "statementListItemWithoutEmptyStatement",
  "emptyStatement", "initializer", "type",
  "unionOrIntersectionOrPrimaryType", "primaryType", "tupleTypeElements",
  "predefinedType", "typeAnnotation", "simpleLiteral", "arrayLiteral",
  "elementList", "arrayElement", "expressionStatement",
  "expressionListOpt", "expressionList", "singleExpression", "arguments",
  "argumentList", "argument", "varStatement", "varDeclarationList",
  "varDeclaration", "varModifier", "ifStatement", "iterationStatement",
  "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "forHeader",
  "continueStatement", "breakStatement", "returnStatement",
  "labelledStatement", "blockStatement", "switchStatement",
  "caseClauseList", "caseClause", "defaultClause", "functionDeclaration",
  "functionBody", "$@8", "callSignature", "parameterList", "parameter",
  "requiredParameter", "optionalParameter", "restParameter",
  "classDeclaration", "classHeritage", "classTail", "classElementList",
  "classElement", "constructorCallSignature", "propertyName", "identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-369)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     929,  -369,  -369,  -369,   -80,  2267,  2267,  -369,   -56,   -49,
     743,   854,   -47,  1282,  -369,  -369,  1516,  -369,  -369,  -369,
    -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,
    -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,
    -369,  -369,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,
    1419,  1419,  1516,  -369,   547,    63,   929,  -369,  -369,  -369,
    -369,  -369,   -36,  1879,  -369,  2267,  -369,  -369,  1152,  -369,
    -369,  -369,  -369,  -369,  -369,  -369,  -369,     6,  1516,   -40,
       2,   929,  1516,  -369,  -369,   -38,  -369,    21,  1516,  -369,
    1685,  -369,   114,   114,   114,   114,   114,   114,   114,   114,
     114,  1516,   -25,  -369,  1879,    -4,   -30,  -369,   689,  -369,
    -369,  1516,  -369,  -369,  -369,  -369,  1516,  1516,  1516,  1516,
    1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,
    1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,
    1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,
    1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  2267,  1516,
    1516,  1516,  1381,  -369,   -34,  -369,    69,    22,    88,  1943,
    2267,   929,   -22,   171,    29,  2267,  1186,    31,  -369,   140,
     -16,  -369,  -369,   -10,  -369,  1879,  1419,  -369,  -369,  -369,
    -369,  1879,  2000,  2000,  2000,  2000,  2000,  2000,  2000,  2000,
    2000,  2000,  2000,  2000,  2000,  2000,  2000,  2000,  1751,  1605,
    2037,  2073,  2108,  2142,  2175,  1413,  1413,  1413,  1413,   246,
     246,   246,   246,   246,   246,   303,   303,   303,    43,    43,
      70,    70,    70,    70,  -369,     3,     9,    37,  1516,  -369,
    1879,    -9,  -369,  2267,  -369,  1516,   199,   100,  1516,  1516,
     -33,    74,  -369,  1048,  1516,    85,    -6,  -369,  -369,  -369,
      53,    89,    55,  -369,  -369,  1549,  1549,    62,   238,   238,
    -369,  -369,  1244,  -369,   -18,  -369,  -369,    67,  -369,    58,
    -369,  1516,  -369,  -369,  1879,   -84,  -369,  -369,  1879,  -369,
    -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,
    1621,  1621,   199,   199,   199,  -369,   -37,    78,  -369,  -369,
    1516,    73,   160,  1516,  1516,   174,  -369,  -369,  -369,  -369,
    -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  1815,  -369,
     428,    85,    85,  1516,    85,  -369,   132,  -369,   929,    77,
     -40,   646,    29,    82,   101,  -369,  -369,  -369,    97,    12,
      29,  1516,   929,    -3,  1028,  -369,  -369,   -37,   -37,  -369,
      38,    51,    99,  1621,  1621,  1599,  1879,  1516,  -369,   102,
      15,   929,  -369,    85,  -369,   104,  -369,  -369,  1879,  -369,
    -369,   809,   106,    29,  -369,    16,   110,  -369,  -369,  -369,
    -369,  -369,   113,  -369,    19,  -369,  1516,  -369,    -5,  -369,
     199,  -369,  -369,  -369,   135,  -369,  -369,   -65,   115,   929,
    1516,  -369,  -369,  -369,    85,  -369,    61,  -369,   974,  -369,
    -369,  -369,  -369,   -32,   162,  -369,  -369,    -2,  -369,  -369,
    -369,  -369,   123,   929,  -369,    29,  -369,  -369,   133,   147,
     929,   929,  -369,    -1,   929,  -369,  -369,  -369,  -369,  -369,
     929,   929,  -369,  -369,   929,  -369
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   158,   159,   160,     0,     0,     0,   163,     0,     0,
       0,     0,     0,     0,    79,    78,     0,   248,   249,   250,
     251,   261,   262,   263,   264,   252,   253,   254,   255,   258,
     259,   256,   257,   260,    60,    61,    62,    82,    80,    81,
     247,    63,     0,     0,     0,     0,     0,     0,     0,     0,
      66,    66,     0,    30,     0,     0,     2,     3,     5,    77,
     140,     6,     0,    74,     7,     0,     8,    10,    72,    11,
      12,    13,    14,    15,     9,    16,    17,    76,     0,     0,
       0,     0,     0,   176,   177,     0,   179,     0,     0,   181,
       0,    76,   143,    91,    92,    89,    90,    84,    83,    85,
      86,     0,     0,    67,    69,     0,     0,   184,     0,     1,
       4,     0,    71,   134,    87,    88,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   137,     0,   152,   154,     0,    73,    74,
       0,     0,     0,     0,     0,     0,     0,     0,   222,     0,
       0,   178,   180,     0,   182,    70,    66,    64,    65,   136,
     185,    75,   107,   111,   112,   118,   108,   109,   110,   113,
     114,   122,   115,   116,   117,   119,   120,   121,     0,   131,
     123,   124,   125,   126,   127,   101,   102,   103,   104,    99,
      98,   106,   105,   132,   133,   128,   129,   130,    93,    94,
      95,    96,    97,   100,   139,     0,     0,   138,     0,   144,
     149,     0,   147,     0,   151,     0,     0,   155,    72,     0,
       0,   152,   183,     0,     0,   200,     0,   210,   212,   213,
       0,   214,   198,   196,   224,     0,     0,     0,     0,     0,
     225,   244,     0,   227,     0,   243,   223,     0,   166,     0,
      68,     0,   141,   142,   150,     0,   145,   153,   156,    47,
      48,    50,    49,    51,    53,    54,    52,    55,    56,    57,
       0,     0,    44,    44,     0,    59,    32,    37,    39,    58,
       0,     0,   133,    72,     0,   161,    18,    19,    20,    22,
      23,    24,    25,    26,    27,    21,    28,    29,   220,   201,
       0,   204,   202,     0,   216,   218,   215,   197,     0,     0,
       0,     0,     0,     0,     0,   226,   228,   230,     0,     0,
       0,     0,     0,     0,   135,   146,   148,    33,    34,    45,
       0,     0,     0,     0,     0,     0,   157,    72,   172,     0,
       0,     0,   221,   208,   211,     0,   205,   203,    31,   217,
     219,     0,     0,     0,   238,     0,     0,   229,   245,   246,
     232,   231,     0,   234,     0,   167,     0,   186,     0,   190,
       0,    42,    43,    38,    35,    36,    40,     0,     0,     0,
      72,   174,   162,   209,   206,   199,     0,   237,     0,   240,
     239,   233,   164,     0,     0,   187,   191,     0,    46,    41,
     168,   173,     0,     0,   207,     0,   235,   242,     0,     0,
     192,   194,   188,     0,     0,   170,   175,   236,   241,   165,
     193,   195,   189,   169,     0,   171
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -369,  -369,   -50,   -55,  -369,  -369,  -253,  -237,  -259,  -110,
     -28,  -369,  -195,  -174,  -369,   -43,  -369,    17,  -245,   -45,
     381,   -14,  -369,  -369,    27,   111,  -150,   215,    36,    39,
    -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,    41,    42,
      45,    46,    47,    48,  -136,  -368,  -369,    49,  -310,  -369,
    -252,   -31,  -311,  -369,  -369,  -317,    50,  -369,   119,  -369,
      32,  -369,  -207,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    55,    56,    57,   315,    58,   335,   359,   306,   307,
     360,   308,   247,    59,    60,   102,   103,    61,   167,    62,
      63,   163,   241,   242,    64,   164,   165,    65,    66,    67,
      81,   439,   352,   444,   454,   409,   433,    68,    69,    70,
      71,    72,    73,    74,   398,   399,   427,    75,   263,   338,
     174,   256,   257,   258,   259,   260,    76,   177,   178,   272,
     273,   342,   274,    91
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      77,   110,   271,   311,   108,    79,    80,   106,   105,   305,
      85,    87,   175,   375,   396,   424,   396,   396,   396,   374,
     251,   348,   350,   168,   386,   111,   179,   243,   243,   111,
     426,   111,   387,   172,   162,   355,   186,   180,    78,   111,
     393,   357,   358,   183,   333,   111,   363,   440,   364,   365,
     429,   111,   285,   110,    77,   330,    77,   186,   339,   340,
     329,   246,    82,   109,   111,   166,   336,   362,   369,    83,
     111,    88,   309,   417,   333,   426,   111,   418,   173,   349,
     111,    77,   181,   380,   112,   171,   244,   313,   383,   189,
     187,   271,   271,   287,   343,   344,   392,   253,   271,   400,
     173,   438,   347,   278,   404,   405,   436,   374,    77,   279,
     286,   188,   400,   331,   235,   236,   252,   425,   282,   397,
     442,   452,   408,   176,   283,   447,   309,   309,   309,   309,
     309,   245,   391,   372,   411,   419,   376,   377,   422,   379,
     246,   182,   248,   280,   154,   155,   156,   157,   246,   111,
     262,   333,   176,   401,   277,   162,   158,   159,   234,   160,
     161,   162,   310,   428,   246,   432,   402,   334,   246,   314,
     166,    77,   332,   261,   157,   264,   275,   337,   413,   353,
     341,   371,   262,   158,   159,   351,   160,   161,   162,   309,
     309,   309,   365,   367,   333,   382,   254,   388,    17,    18,
      19,    20,    21,   168,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,   389,   390,   403,   434,
     364,   435,   410,   414,    40,   416,   309,   158,   159,   420,
     160,   161,   162,   421,   430,   289,   290,   291,   292,   293,
     294,   441,   445,   166,   295,   296,    34,    35,    36,   297,
     298,   299,   448,    77,    41,   407,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   275,   275,   449,   168,   370,
     316,   356,   275,   158,   159,   361,   160,   161,   162,   368,
     317,   250,   300,   170,   301,    34,    35,    36,   381,   318,
     255,   443,   319,    41,   320,   321,   276,   395,   322,   323,
     324,   325,   326,   327,   346,     0,   394,     0,     0,     0,
     385,     0,     0,   302,     0,   303,   412,   304,     0,     0,
       0,     0,   168,     0,     0,     0,   110,     0,     0,     0,
     261,     0,     0,     0,     0,     0,     0,     0,    77,     0,
       0,   261,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   423,    77,     0,   431,     0,     0,     0,     0,   158,
     159,     0,   160,   161,   162,   168,     0,     0,     0,     0,
       0,    77,     0,     0,     0,     0,     0,     0,   446,     0,
       0,    77,     0,     0,     0,     0,     0,     0,     0,   453,
     450,   451,     0,     0,    90,   110,   110,    92,     0,   455,
       0,     0,   152,   153,   154,   155,   156,   157,     0,    77,
       0,     0,     0,     0,     0,     0,   158,   159,   261,   160,
     161,   162,     0,    93,    94,    95,    96,    97,    98,    99,
     100,   104,   104,    77,     0,     0,     0,     0,     0,     0,
      77,    77,     0,     0,    77,     0,     0,     0,     0,   169,
      77,    77,     0,   254,    77,    17,    18,    19,    20,    21,
       0,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,     0,     0,     0,     0,     0,     0,     0,
       0,    40,   185,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   191,     0,     0,     0,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,     0,
       0,     0,   237,   240,     0,     0,     0,   373,     0,     0,
       1,     2,     3,     4,     0,     5,     6,     0,     0,     0,
       7,     8,     9,    10,    11,    12,     0,   104,    13,    14,
      15,    16,     0,     0,    17,    18,    19,    20,    21,     0,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,     0,     0,    34,    35,    36,    37,    38,    39,
      40,     0,    41,    42,    43,    44,    45,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   284,
       0,     0,     0,     0,     0,     0,   288,     0,     0,     0,
     312,     0,     0,     0,     0,   328,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    46,    47,     0,     0,
       0,     0,    48,    49,     0,     0,     0,     0,     0,     0,
       0,    50,   354,    51,     0,    52,     0,    53,    54,   107,
       0,   254,     0,    17,    18,    19,    20,    21,     0,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,   366,     1,     2,     3,     4,     0,     5,     6,    40,
       0,     0,     7,     8,     9,    10,    11,    12,     0,     0,
      13,    14,    15,    16,   378,     0,    17,    18,    19,    20,
      21,     0,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,     0,     0,    34,    35,    36,    37,
      38,    39,    40,     0,    41,    42,    43,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   384,     0,     0,     0,     0,
      17,    18,    19,    20,    21,     0,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    46,    47,
       0,     0,     0,     0,    48,    49,    40,     0,     0,     0,
       0,     0,     0,    50,     0,    51,     0,    52,     0,    53,
      54,   190,     1,     2,     3,     4,     0,     5,     6,     0,
       0,     0,     7,     8,     9,    10,    11,    12,     0,     0,
      13,    14,    15,    16,     0,     0,    17,    18,    19,    20,
      21,     0,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,     0,     0,    34,    35,    36,    37,
      38,    39,    40,    84,    41,    42,    43,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,    18,    19,    20,    21,     0,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,     0,
       0,     0,     0,     0,     0,     0,     0,    40,    46,    47,
       0,     0,     0,     0,    48,    49,     0,     0,     0,     0,
       0,     0,     0,    50,     0,    51,     0,    52,     0,    53,
      54,   415,     1,     2,     3,     4,     0,     5,     6,     0,
       0,     0,     7,     8,     9,    10,    11,    12,     0,     0,
      13,    14,    15,    16,     0,     0,    17,    18,    19,    20,
      21,     0,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    86,     0,    34,    35,    36,    37,
      38,    39,    40,     0,    41,    42,    43,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
       0,    17,    18,    19,    20,    21,     0,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,     0,
       0,     0,     0,     0,     0,     0,     0,    40,    46,    47,
       0,     0,     0,     0,    48,    49,     0,     0,     0,     0,
       0,     0,     0,    50,     0,    51,     0,    52,     0,    53,
      54,     1,     2,     3,     4,     0,     5,     6,     0,     0,
       0,     7,     8,     9,    10,    11,    12,     0,     0,    13,
      14,    15,    16,     0,     0,    17,    18,    19,    20,    21,
       0,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,   437,     0,    34,    35,    36,    37,    38,
      39,    40,     0,    41,    42,    43,    44,    45,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,     0,     0,     0,     0,     0,     0,     0,
       0,   158,   159,     0,   160,   161,   162,    46,    47,     0,
       0,     0,     0,    48,    49,     1,     2,     3,     0,     0,
       0,     0,    50,     0,    51,     0,    52,     0,     0,    54,
       0,     0,     0,     0,    14,    15,    16,     0,     0,    17,
      18,    19,    20,    21,     0,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,   265,   266,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,    43,
      44,    45,     0,    17,    18,    19,    20,    21,   267,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,     0,     0,    34,    35,    36,     0,     0,     0,    40,
       0,    41,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,    47,     0,     0,   265,   266,    48,    49,     0,
       0,     0,     0,     0,     0,     0,    50,     0,    51,     0,
      52,    17,    18,    19,    20,    21,   267,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,     0,
       0,    34,    35,    36,     0,     0,     0,    40,     0,    41,
     268,     0,   269,     0,    14,    15,    16,     0,   270,    17,
      18,    19,    20,    21,     0,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,     0,     0,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,    43,
      44,    45,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   268,     0,
     269,     0,     0,     0,     0,     0,   345,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,    47,     0,     0,     0,     0,    48,    49,     0,
       0,     0,     0,     0,     0,     0,    50,     0,    51,     0,
      52,     0,    89,    14,    15,    16,   238,     0,    17,    18,
      19,    20,    21,     0,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     0,     0,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
      45,    14,    15,    16,   101,     0,    17,    18,    19,    20,
      21,     0,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,     0,     0,    34,    35,    36,    37,
      38,    39,    40,     0,    41,    42,    43,    44,    45,     0,
      46,    47,     0,     0,     0,     0,    48,    49,     0,     0,
       0,     0,     0,     0,     0,    50,     0,    51,     0,    52,
     239,     0,     0,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,    46,    47,
       0,     0,     0,     0,    48,    49,   158,   159,     0,   160,
     161,   162,     0,    50,     0,    51,     0,    52,    14,    15,
      16,     0,     0,    17,    18,    19,    20,    21,     0,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,     0,     0,    34,    35,    36,    37,    38,    39,    40,
       0,    41,    42,    43,    44,    45,    17,    18,    19,    20,
      21,     0,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,     0,     0,    34,    35,    36,     0,
       0,     0,    40,     0,    41,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    46,    47,     0,     0,     0,
       0,    48,    49,     0,     0,     0,     0,     0,     0,     0,
      50,     0,    51,     0,    52,   289,   290,   291,   292,   293,
     294,     0,     0,     0,   295,   296,    34,    35,    36,   297,
     298,   299,     0,     0,    41,     0,     0,   289,   290,   291,
     292,   293,   294,   268,     0,   269,   295,   296,    34,    35,
      36,   297,   298,   299,     0,     0,    41,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
       0,     0,     0,   302,   406,   303,     0,   304,   158,   159,
       0,   160,   161,   162,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   302,     0,   303,     0,   304,
     113,   114,   115,     0,     0,     0,     0,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,     0,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
       0,     0,     0,     0,     0,     0,     0,     0,   158,   159,
       0,   160,   161,   162,     0,   184,   113,   114,   115,     0,
       0,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     281,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,     0,     0,     0,     0,
       0,     0,     0,     0,   158,   159,     0,   160,   161,   162,
     113,   114,   115,     0,     0,     0,     0,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   246,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
       0,     0,     0,     0,     0,     0,     0,     0,   158,   159,
       0,   160,   161,   162,   113,   114,   115,     0,     0,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,     0,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,     0,     0,     0,     0,     0,     0,
       0,     0,   158,   159,     0,   160,   161,   162,   113,   114,
     115,     0,     0,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,     0,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   249,   149,
     150,   151,   152,   153,   154,   155,   156,   157,     0,     0,
       0,     0,     0,     0,     0,     0,   158,   159,     0,   160,
     161,   162,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,     0,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,     0,     0,     0,     0,     0,
       0,     0,     0,   158,   159,     0,   160,   161,   162,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,     0,     0,     0,     0,     0,     0,     0,     0,
     158,   159,     0,   160,   161,   162,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,     0,     0,
       0,     0,     0,     0,     0,     0,   158,   159,     0,   160,
     161,   162,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,     0,     0,     0,     0,     0,     0,     0,
       0,   158,   159,     0,   160,   161,   162,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,     0,     0,     0,
       0,     0,     0,     0,     0,   158,   159,     0,   160,   161,
     162,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
       0,     0,     0,     0,     0,     0,     0,     0,   158,   159,
       0,   160,   161,   162,    17,    18,    19,    20,    21,     0,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,     0,     0,     0,     0,     0,     0,     0,     0,
      40
};

static const yytype_int16 yycheck[] =
{
       0,    56,   176,   248,    54,     5,     6,    52,    51,   246,
      10,    11,    10,   330,    19,    20,    19,    19,    19,   330,
     170,   274,   274,    68,   341,    61,    81,    61,    61,    61,
     398,    61,   342,    78,   118,   119,    61,    82,   118,    61,
     350,   300,   301,    88,    62,    61,    83,    79,    85,   114,
     115,    61,    61,   108,    54,    61,    56,    61,   265,   266,
     255,    79,   118,     0,    61,    65,   261,   304,   313,   118,
      61,   118,   246,   383,    62,   443,    61,    61,   118,   274,
      61,    81,   120,   336,   120,    79,   120,   120,   340,   119,
     115,   265,   266,   243,   268,   269,   349,   119,   272,    61,
     118,   418,   120,   119,   363,   364,   416,   418,   108,   119,
     119,   115,    61,   119,   159,   160,   171,   122,   115,   122,
     122,   122,   367,   121,   115,   435,   300,   301,   302,   303,
     304,    62,   120,   328,   119,   119,   331,   332,   119,   334,
      79,   120,   120,   186,   101,   102,   103,   104,    79,    61,
     121,    62,   121,   115,    14,   118,   113,   114,   158,   116,
     117,   118,    62,   400,    79,   410,   115,    78,    79,    95,
     170,   171,   119,   173,   104,   175,   176,   122,   373,   121,
     118,     7,   121,   113,   114,   118,   116,   117,   118,   363,
     364,   365,   114,   120,    62,   118,    25,   115,    27,    28,
      29,    30,    31,   248,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,   115,   120,   119,   414,
      85,   416,   120,   119,    53,   119,   400,   113,   114,   119,
     116,   117,   118,   120,   119,    36,    37,    38,    39,    40,
      41,    79,   119,   243,    45,    46,    47,    48,    49,    50,
      51,    52,   119,   253,    55,   365,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   265,   266,   120,   313,   314,
     253,   285,   272,   113,   114,   303,   116,   117,   118,   119,
     253,   170,    83,    68,    85,    47,    48,    49,   338,   253,
     119,   427,   253,    55,   253,   253,   177,   352,   253,   253,
     253,   253,   253,   253,   272,    -1,   351,    -1,    -1,    -1,
     341,    -1,    -1,   114,    -1,   116,   371,   118,    -1,    -1,
      -1,    -1,   367,    -1,    -1,    -1,   381,    -1,    -1,    -1,
     330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   338,    -1,
      -1,   341,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   396,   352,    -1,   409,    -1,    -1,    -1,    -1,   113,
     114,    -1,   116,   117,   118,   410,    -1,    -1,    -1,    -1,
      -1,   371,    -1,    -1,    -1,    -1,    -1,    -1,   433,    -1,
      -1,   381,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,
     440,   441,    -1,    -1,    13,   450,   451,    16,    -1,   454,
      -1,    -1,    99,   100,   101,   102,   103,   104,    -1,   409,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,   418,   116,
     117,   118,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,   433,    -1,    -1,    -1,    -1,    -1,    -1,
     440,   441,    -1,    -1,   444,    -1,    -1,    -1,    -1,    68,
     450,   451,    -1,    25,   454,    27,    28,    29,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,    -1,
      -1,    -1,   161,   162,    -1,    -1,    -1,   119,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    -1,   186,    21,    22,
      23,    24,    -1,    -1,    27,    28,    29,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,
      -1,    -1,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,   281,   116,    -1,   118,    -1,   120,   121,   122,
      -1,    25,    -1,    27,    28,    29,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,   310,     3,     4,     5,     6,    -1,     8,     9,    53,
      -1,    -1,    13,    14,    15,    16,    17,    18,    -1,    -1,
      21,    22,    23,    24,   333,    -1,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    99,   100,
      -1,    -1,    -1,    -1,   105,   106,    53,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,   116,    -1,   118,    -1,   120,
     121,   122,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    13,    14,    15,    16,    17,    18,    -1,    -1,
      21,    22,    23,    24,    -1,    -1,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,   120,    55,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    99,   100,
      -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,   116,    -1,   118,    -1,   120,
     121,   122,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    13,    14,    15,    16,    17,    18,    -1,    -1,
      21,    22,    23,    24,    -1,    -1,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,   120,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    99,   100,
      -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,   116,    -1,   118,    -1,   120,
     121,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    13,    14,    15,    16,    17,    18,    -1,    -1,    21,
      22,    23,    24,    -1,    -1,    27,    28,    29,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,   119,    -1,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,   114,    -1,   116,   117,   118,    99,   100,    -1,
      -1,    -1,    -1,   105,   106,     3,     4,     5,    -1,    -1,
      -1,    -1,   114,    -1,   116,    -1,   118,    -1,    -1,   121,
      -1,    -1,    -1,    -1,    22,    23,    24,    -1,    -1,    27,
      28,    29,    30,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    11,    12,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    47,    48,    49,    -1,    -1,    -1,    53,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,    -1,    -1,    11,    12,   105,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,   116,    -1,
     118,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    47,    48,    49,    -1,    -1,    -1,    53,    -1,    55,
     114,    -1,   116,    -1,    22,    23,    24,    -1,   122,    27,
      28,    29,    30,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,
     116,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,    -1,    -1,    -1,    -1,   105,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,   116,    -1,
     118,    -1,   120,    22,    23,    24,    25,    -1,    27,    28,
      29,    30,    31,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    22,    23,    24,    25,    -1,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    -1,
      99,   100,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    -1,   116,    -1,   118,
     119,    -1,    -1,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    99,   100,
      -1,    -1,    -1,    -1,   105,   106,   113,   114,    -1,   116,
     117,   118,    -1,   114,    -1,   116,    -1,   118,    22,    23,
      24,    -1,    -1,    27,    28,    29,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,
      -1,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,    -1,   116,    -1,   118,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    -1,    55,    -1,    -1,    36,    37,    38,
      39,    40,    41,   114,    -1,   116,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,   114,   115,   116,    -1,   118,   113,   114,
      -1,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    -1,   116,    -1,   118,
      55,    56,    57,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
      -1,   116,   117,   118,    -1,   120,    55,    56,    57,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,   114,    -1,   116,   117,   118,
      55,    56,    57,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
      -1,   116,   117,   118,    55,    56,    57,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    -1,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,   114,    -1,   116,   117,   118,    55,    56,
      57,    -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,
     117,   118,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    -1,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,    -1,   116,   117,   118,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   114,    -1,   116,   117,   118,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,
     117,   118,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,   114,    -1,   116,   117,   118,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,   117,
     118,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
      -1,   116,   117,   118,    27,    28,    29,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     8,     9,    13,    14,    15,
      16,    17,    18,    21,    22,    23,    24,    27,    28,    29,
      30,    31,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    47,    48,    49,    50,    51,    52,
      53,    55,    56,    57,    58,    59,    99,   100,   105,   106,
     114,   116,   118,   120,   121,   124,   125,   126,   128,   136,
     137,   140,   142,   143,   147,   150,   151,   152,   160,   161,
     162,   163,   164,   165,   166,   170,   179,   186,   118,   186,
     186,   153,   118,   118,   120,   186,   120,   186,   118,   120,
     143,   186,   143,   143,   143,   143,   143,   143,   143,   143,
     143,    25,   138,   139,   143,   138,   142,   122,   125,     0,
     126,    61,   120,    55,    56,    57,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   113,   114,
     116,   117,   118,   144,   148,   149,   186,   141,   142,   143,
     150,    79,   142,   118,   173,    10,   121,   180,   181,   126,
     142,   120,   120,   142,   120,   143,    61,   115,   115,   119,
     122,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   186,   142,   142,   143,    25,   119,
     143,   145,   146,    61,   120,    62,    79,   135,   120,    95,
     148,   149,   126,   119,    25,   119,   174,   175,   176,   177,
     178,   186,   121,   171,   186,    11,    12,    32,   114,   116,
     122,   136,   182,   183,   185,   186,   181,    14,   119,   119,
     138,    79,   115,   115,   143,    61,   119,   149,   143,    36,
      37,    38,    39,    40,    41,    45,    46,    50,    51,    52,
      83,    85,   114,   116,   118,   130,   131,   132,   134,   136,
      62,   141,   143,   120,    95,   127,   140,   147,   151,   152,
     161,   162,   163,   164,   165,   166,   170,   179,   143,   135,
      61,   119,   119,    62,    78,   129,   135,   122,   172,   185,
     185,   118,   184,   136,   136,   122,   183,   120,   129,   135,
     173,   118,   155,   121,   143,   119,   144,   131,   131,   130,
     133,   133,   130,    83,    85,   114,   143,   120,   119,   141,
     142,     7,   135,   119,   175,   178,   135,   135,   143,   135,
     129,   125,   118,   173,   119,   174,   178,   171,   115,   115,
     120,   120,   129,   171,   142,   126,    19,   122,   167,   168,
      61,   115,   115,   119,   131,   131,   115,   132,   141,   158,
     120,   119,   126,   135,   119,   122,   119,   171,    61,   119,
     119,   120,   119,   142,    20,   122,   168,   169,   130,   115,
     119,   126,   141,   159,   135,   135,   171,   119,   178,   154,
      79,    79,   122,   167,   156,   119,   126,   171,   119,   120,
     125,   125,   122,   126,   157,   126
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   123,   124,   125,   125,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     128,   129,   130,   130,   130,   131,   131,   131,   132,   132,
     132,   132,   132,   132,   133,   133,   133,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   135,
     136,   136,   136,   136,   137,   137,   138,   138,   138,   139,
     139,   140,   141,   141,   142,   142,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   144,   144,   144,   145,   145,   146,
     146,   147,   148,   148,   149,   149,   149,   149,   150,   150,
     150,   151,   151,   153,   154,   152,   155,   152,   156,   152,
     157,   152,   158,   152,   159,   152,   160,   161,   161,   162,
     162,   163,   163,   164,   165,   165,   166,   166,   166,   166,
     167,   167,   168,   168,   169,   169,   170,   171,   172,   171,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     174,   174,   175,   175,   176,   176,   177,   177,   177,   177,
     178,   178,   179,   179,   180,   181,   181,   182,   182,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   184,   184,
     184,   184,   184,   185,   185,   185,   185,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     2,     2,     3,     3,     1,     3,     1,
       3,     4,     3,     3,     0,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     3,     3,     0,     1,     3,     1,
       2,     2,     0,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     5,     3,     2,     3,     3,
       1,     4,     4,     2,     2,     3,     4,     1,     3,     1,
       2,     3,     1,     3,     1,     2,     3,     4,     1,     1,
       1,     5,     7,     0,     0,     9,     0,     6,     0,     9,
       0,    10,     0,     7,     0,     8,     2,     2,     3,     2,
       3,     2,     3,     3,     2,     3,     6,     7,     8,     9,
       1,     2,     3,     4,     2,     3,     4,     2,     0,     4,
       2,     3,     3,     4,     3,     4,     5,     6,     4,     5,
       1,     3,     1,     1,     1,     2,     2,     3,     2,     3,
       2,     3,     3,     4,     2,     2,     3,     1,     2,     3,
       2,     3,     3,     4,     3,     5,     6,     4,     2,     3,
       3,     5,     4,     1,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
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
  case 2: /* script: statementList  */
#line 90 "parser.y"
        { 
            if ( syntaxErrorCounter > 0 ) {
                PrintError("Found " + std::to_string(syntaxErrorCounter) + " syntax errors. Fix them and rerun.");
                exit(1);
            }
            Print("- R: statementList -> script"); 
        }
#line 2392 "parser.tab.cpp"
    break;

  case 3: /* statementList: statementListItem  */
#line 100 "parser.y"
                        { Print("- R: statementListItem -> statementList"); }
#line 2398 "parser.tab.cpp"
    break;

  case 4: /* statementList: statementList statementListItem  */
#line 101 "parser.y"
                                      { Print("- R: statementList statementListItem -> statementList"); }
#line 2404 "parser.tab.cpp"
    break;

  case 5: /* statementListItem: emptyStatement  */
#line 105 "parser.y"
                                    { Print("- R: emptyStatement -> statementListItem"); }
#line 2410 "parser.tab.cpp"
    break;

  case 6: /* statementListItem: expressionStatement  */
#line 106 "parser.y"
                                    { Print("- R: expressionStatement -> statementListItem"); }
#line 2416 "parser.tab.cpp"
    break;

  case 7: /* statementListItem: varStatement  */
#line 107 "parser.y"
                                    { Print("- R: varStatement -> statementListItem"); }
#line 2422 "parser.tab.cpp"
    break;

  case 8: /* statementListItem: ifStatement  */
#line 108 "parser.y"
                                    { Print("- R: ifStatement -> statementListItem"); }
#line 2428 "parser.tab.cpp"
    break;

  case 9: /* statementListItem: switchStatement  */
#line 109 "parser.y"
                                    { Print("- R: switchStatement -> statementListItem"); }
#line 2434 "parser.tab.cpp"
    break;

  case 10: /* statementListItem: iterationStatement  */
#line 110 "parser.y"
                                    { Print("- R: iterationStatement -> statementListItem"); }
#line 2440 "parser.tab.cpp"
    break;

  case 11: /* statementListItem: continueStatement  */
#line 112 "parser.y"
        {
            if ( !isInIterationBody ) { 
                yyerror("illegal continue statement."); YYERROR;
            } 
            Print("- R: continueStatement -> statementListItem");  
        }
#line 2451 "parser.tab.cpp"
    break;

  case 12: /* statementListItem: breakStatement  */
#line 119 "parser.y"
        {
            if ( !isInIterationBody ) { 
                yyerror("illegal break statement."); YYERROR;
            } 
            Print("- R: breakStatement -> statementListItem");
        }
#line 2462 "parser.tab.cpp"
    break;

  case 13: /* statementListItem: returnStatement  */
#line 126 "parser.y"
        { 
            if ( !isInFunctionBody ) { 
                yyerror("illegal return statement."); YYERROR;
            } 
            Print("- R: returnStatement -> statementListItem"); 
        }
#line 2473 "parser.tab.cpp"
    break;

  case 14: /* statementListItem: labelledStatement  */
#line 132 "parser.y"
                                    { Print("- R: labelledStatement -> statementListItem"); }
#line 2479 "parser.tab.cpp"
    break;

  case 15: /* statementListItem: blockStatement  */
#line 133 "parser.y"
                                    { Print("- R: blockStatement -> statementListItem"); }
#line 2485 "parser.tab.cpp"
    break;

  case 16: /* statementListItem: functionDeclaration  */
#line 134 "parser.y"
                                    { Print("- R: functionDeclaration -> statementListItem"); }
#line 2491 "parser.tab.cpp"
    break;

  case 17: /* statementListItem: classDeclaration  */
#line 135 "parser.y"
                                    { Print("- R: classDeclaration -> statementListItem"); }
#line 2497 "parser.tab.cpp"
    break;

  case 18: /* statementListItemWithoutEmptyStatement: expressionStatement  */
#line 139 "parser.y"
                                    { Print("- R: expressionStatement -> statementListItem"); }
#line 2503 "parser.tab.cpp"
    break;

  case 19: /* statementListItemWithoutEmptyStatement: varStatement  */
#line 140 "parser.y"
                                    { Print("- R: varStatement -> statementListItem"); }
#line 2509 "parser.tab.cpp"
    break;

  case 20: /* statementListItemWithoutEmptyStatement: ifStatement  */
#line 141 "parser.y"
                                    { Print("- R: ifStatement -> statementListItem"); }
#line 2515 "parser.tab.cpp"
    break;

  case 21: /* statementListItemWithoutEmptyStatement: switchStatement  */
#line 142 "parser.y"
                                    { Print("- R: switchStatement -> statementListItem"); }
#line 2521 "parser.tab.cpp"
    break;

  case 22: /* statementListItemWithoutEmptyStatement: iterationStatement  */
#line 143 "parser.y"
                                    { Print("- R: iterationStatement -> statementListItem"); }
#line 2527 "parser.tab.cpp"
    break;

  case 23: /* statementListItemWithoutEmptyStatement: continueStatement  */
#line 145 "parser.y"
        {
            if ( !isInIterationBody ) { 
                yyerror("illegal continue statement."); YYERROR;
            } 
            Print("- R: continueStatement -> statementListItem");
        }
#line 2538 "parser.tab.cpp"
    break;

  case 24: /* statementListItemWithoutEmptyStatement: breakStatement  */
#line 152 "parser.y"
        {
            if ( !isInIterationBody ) { 
                yyerror("illegal break statement."); YYERROR;
            } 
            Print("- R: breakStatement -> statementListItem");
        }
#line 2549 "parser.tab.cpp"
    break;

  case 25: /* statementListItemWithoutEmptyStatement: returnStatement  */
#line 159 "parser.y"
        { 
            if ( !isInFunctionBody ) { 
                yyerror("illegal return statement."); YYERROR;
            } 
            Print("- R: returnStatement -> statementListItem"); 
        }
#line 2560 "parser.tab.cpp"
    break;

  case 26: /* statementListItemWithoutEmptyStatement: labelledStatement  */
#line 165 "parser.y"
                                    { Print("- R: labelledStatement -> statementListItem"); }
#line 2566 "parser.tab.cpp"
    break;

  case 27: /* statementListItemWithoutEmptyStatement: blockStatement  */
#line 166 "parser.y"
                                    { Print("- R: blockStatement -> statementListItem"); }
#line 2572 "parser.tab.cpp"
    break;

  case 28: /* statementListItemWithoutEmptyStatement: functionDeclaration  */
#line 167 "parser.y"
                                    { Print("- R: functionDeclaration -> statementListItem"); }
#line 2578 "parser.tab.cpp"
    break;

  case 29: /* statementListItemWithoutEmptyStatement: classDeclaration  */
#line 168 "parser.y"
                                    { Print("- R: classDeclaration -> statementListItem"); }
#line 2584 "parser.tab.cpp"
    break;

  case 30: /* emptyStatement: ';'  */
#line 173 "parser.y"
        { 
            if ( isASIActivated ) {
                std::string text(yytext_ptr, yyleng);
                yyerror(("syntax error on token: " + text).c_str()); YYERROR;
            }
            Print("- R: ';' -> emptyStatement"); 
        }
#line 2596 "parser.tab.cpp"
    break;

  case 31: /* initializer: '=' singleExpression  */
#line 183 "parser.y"
                           { Print("- R: '=' singleExpression -> initializer"); }
#line 2602 "parser.tab.cpp"
    break;

  case 32: /* type: unionOrIntersectionOrPrimaryType  */
#line 189 "parser.y"
                                       { Print("- R: unionOrIntersectionOrPrimaryType -> type"); }
#line 2608 "parser.tab.cpp"
    break;

  case 33: /* type: '|' unionOrIntersectionOrPrimaryType  */
#line 190 "parser.y"
                                           { Print("- R: '|' unionOrIntersectionOrPrimaryType -> type"); }
#line 2614 "parser.tab.cpp"
    break;

  case 34: /* type: '&' unionOrIntersectionOrPrimaryType  */
#line 191 "parser.y"
                                           { Print("- R: '&' unionOrIntersectionOrPrimaryType -> type"); }
#line 2620 "parser.tab.cpp"
    break;

  case 35: /* unionOrIntersectionOrPrimaryType: unionOrIntersectionOrPrimaryType '|' unionOrIntersectionOrPrimaryType  */
#line 195 "parser.y"
                                                                            { Print("- R: unionOrIntersectionOrPrimaryType '|' unionOrIntersectionOrPrimaryType -> unionOrIntersectionOrPrimaryType"); }
#line 2626 "parser.tab.cpp"
    break;

  case 36: /* unionOrIntersectionOrPrimaryType: unionOrIntersectionOrPrimaryType '&' unionOrIntersectionOrPrimaryType  */
#line 196 "parser.y"
                                                                            { Print("- R: unionOrIntersectionOrPrimaryType '&' unionOrIntersectionOrPrimaryType -> unionOrIntersectionOrPrimaryType"); }
#line 2632 "parser.tab.cpp"
    break;

  case 37: /* unionOrIntersectionOrPrimaryType: primaryType  */
#line 197 "parser.y"
                  { Print("- R: primaryType -> argument"); }
#line 2638 "parser.tab.cpp"
    break;

  case 38: /* primaryType: '(' type ')'  */
#line 201 "parser.y"
                   { Print("- R: '(' type ')' -> primaryType"); }
#line 2644 "parser.tab.cpp"
    break;

  case 39: /* primaryType: predefinedType  */
#line 202 "parser.y"
                     { Print("- R: predefinedType -> primaryType"); }
#line 2650 "parser.tab.cpp"
    break;

  case 40: /* primaryType: primaryType '[' ']'  */
#line 203 "parser.y"
                          { Print("- R: primaryType '[' ']' -> primaryType"); }
#line 2656 "parser.tab.cpp"
    break;

  case 41: /* primaryType: primaryType '[' primaryType ']'  */
#line 204 "parser.y"
                                      { Print("- R: primaryType '[' primaryType ']' -> primaryType"); }
#line 2662 "parser.tab.cpp"
    break;

  case 42: /* primaryType: '[' tupleTypeElements ']'  */
#line 205 "parser.y"
                                { Print("- R: '[' tupleTypeElements ']' -> primaryType"); }
#line 2668 "parser.tab.cpp"
    break;

  case 43: /* primaryType: ENDL_BRACKET_OPEN tupleTypeElements ']'  */
#line 206 "parser.y"
                                              { Print("- R: '[' tupleTypeElements ']' -> primaryType"); }
#line 2674 "parser.tab.cpp"
    break;

  case 44: /* tupleTypeElements: %empty  */
#line 210 "parser.y"
                  { Print("- R: #empty# -> tupleTypeElements"); }
#line 2680 "parser.tab.cpp"
    break;

  case 45: /* tupleTypeElements: type  */
#line 211 "parser.y"
           { Print("- R: type -> tupleTypeElements"); }
#line 2686 "parser.tab.cpp"
    break;

  case 46: /* tupleTypeElements: tupleTypeElements ',' type  */
#line 212 "parser.y"
                                 { Print("- R: tupleTypeElements ',' type -> tupleTypeElements"); }
#line 2692 "parser.tab.cpp"
    break;

  case 47: /* predefinedType: ANY  */
#line 216 "parser.y"
          { Print("- R: ANY -> predefinedType"); }
#line 2698 "parser.tab.cpp"
    break;

  case 48: /* predefinedType: NUMBER  */
#line 217 "parser.y"
             { Print("- R: NUMBER -> predefinedType"); }
#line 2704 "parser.tab.cpp"
    break;

  case 49: /* predefinedType: STRING  */
#line 218 "parser.y"
             { Print("- R: STRING -> predefinedType"); }
#line 2710 "parser.tab.cpp"
    break;

  case 50: /* predefinedType: BOOLEAN  */
#line 219 "parser.y"
              { Print("- R: BOOLEAN -> predefinedType"); }
#line 2716 "parser.tab.cpp"
    break;

  case 51: /* predefinedType: NEVER  */
#line 220 "parser.y"
            { Print("- R: NEVER -> predefinedType"); }
#line 2722 "parser.tab.cpp"
    break;

  case 52: /* predefinedType: UNKNOWN  */
#line 221 "parser.y"
              { Print("- R: UNKNOWN -> predefinedType"); }
#line 2728 "parser.tab.cpp"
    break;

  case 53: /* predefinedType: UNDEFINED  */
#line 222 "parser.y"
                { Print("- R: UNDEFINED -> predefinedType"); }
#line 2734 "parser.tab.cpp"
    break;

  case 54: /* predefinedType: VOID  */
#line 223 "parser.y"
           { Print("- R: VOID -> predefinedType"); }
#line 2740 "parser.tab.cpp"
    break;

  case 55: /* predefinedType: NULL_KW  */
#line 224 "parser.y"
              { Print("- R: NULL_KW -> predefinedType"); }
#line 2746 "parser.tab.cpp"
    break;

  case 56: /* predefinedType: TRUE_KW  */
#line 225 "parser.y"
              { Print("- R: TRUE_WD -> predefinedType"); }
#line 2752 "parser.tab.cpp"
    break;

  case 57: /* predefinedType: FALSE_KW  */
#line 226 "parser.y"
               { Print("- R: FALSE_KW -> predefinedType"); }
#line 2758 "parser.tab.cpp"
    break;

  case 58: /* predefinedType: simpleLiteral  */
#line 227 "parser.y"
                    { Print("- R: simpleLiteral -> predefinedType"); }
#line 2764 "parser.tab.cpp"
    break;

  case 59: /* typeAnnotation: ':' type  */
#line 231 "parser.y"
               { Print("- R: ':' type -> typeAnnotation"); }
#line 2770 "parser.tab.cpp"
    break;

  case 60: /* simpleLiteral: STRING_LIT  */
#line 235 "parser.y"
                 { Print("- R: STRING_LIT -> simpleLiteral"); }
#line 2776 "parser.tab.cpp"
    break;

  case 61: /* simpleLiteral: INT_LIT  */
#line 236 "parser.y"
              { Print("- R: INT_LIT -> simpleLiteral"); }
#line 2782 "parser.tab.cpp"
    break;

  case 62: /* simpleLiteral: FLOAT_LIT  */
#line 237 "parser.y"
                { Print("- R: FLOAT_LIT -> simpleLiteral"); }
#line 2788 "parser.tab.cpp"
    break;

  case 63: /* simpleLiteral: TEMPLATE_LITERAL  */
#line 238 "parser.y"
                       { Print("- R: TEMPLATE_LITERAL -> simpleLiteral"); }
#line 2794 "parser.tab.cpp"
    break;

  case 64: /* arrayLiteral: '[' elementList ']'  */
#line 243 "parser.y"
                          { Print("- R: [ elementList ']' -> arrayLiteral"); }
#line 2800 "parser.tab.cpp"
    break;

  case 65: /* arrayLiteral: ENDL_BRACKET_OPEN elementList ']'  */
#line 244 "parser.y"
                                        { Print("- R: ENDL_BRACKET_OPEN elementList ']' -> arrayLiteral"); }
#line 2806 "parser.tab.cpp"
    break;

  case 66: /* elementList: %empty  */
#line 248 "parser.y"
                  { Print("- R: #empty# -> elementList"); }
#line 2812 "parser.tab.cpp"
    break;

  case 67: /* elementList: arrayElement  */
#line 249 "parser.y"
                   { Print("- R: arrayElement -> elementList"); }
#line 2818 "parser.tab.cpp"
    break;

  case 68: /* elementList: elementList ',' elementList  */
#line 250 "parser.y"
                                  { Print("- R: elementList ',' elementList -> elementList"); }
#line 2824 "parser.tab.cpp"
    break;

  case 69: /* arrayElement: singleExpression  */
#line 254 "parser.y"
                       { Print("- R: singleExpression -> arrayElement"); }
#line 2830 "parser.tab.cpp"
    break;

  case 70: /* arrayElement: ELLIPSIS singleExpression  */
#line 255 "parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> arrayElement"); }
#line 2836 "parser.tab.cpp"
    break;

  case 71: /* expressionStatement: expressionList ';'  */
#line 261 "parser.y"
                         { Print("- R: expressionList ';' -> expressionStatement"); }
#line 2842 "parser.tab.cpp"
    break;

  case 72: /* expressionListOpt: %empty  */
#line 265 "parser.y"
                  { Print("- R: #empty# -> expressionListOpt"); }
#line 2848 "parser.tab.cpp"
    break;

  case 73: /* expressionListOpt: expressionList  */
#line 266 "parser.y"
                     { Print("- R: expressionList -> expressionListOpt"); }
#line 2854 "parser.tab.cpp"
    break;

  case 74: /* expressionList: singleExpression  */
#line 270 "parser.y"
                       { Print("- R: singleExpression -> expressionList"); }
#line 2860 "parser.tab.cpp"
    break;

  case 75: /* expressionList: expressionList ',' singleExpression  */
#line 271 "parser.y"
                                          { Print("- R: expressionList ',' singleExpression -> expressionList"); }
#line 2866 "parser.tab.cpp"
    break;

  case 76: /* singleExpression: identifier  */
#line 275 "parser.y"
                 { Print("- R: identifier -> singleExpression"); }
#line 2872 "parser.tab.cpp"
    break;

  case 77: /* singleExpression: simpleLiteral  */
#line 276 "parser.y"
                    { Print("- R: simpleLiteral -> singleExpression"); }
#line 2878 "parser.tab.cpp"
    break;

  case 78: /* singleExpression: THIS  */
#line 277 "parser.y"
           { Print("- R: THIS -> singleExpression"); }
#line 2884 "parser.tab.cpp"
    break;

  case 79: /* singleExpression: SUPER  */
#line 278 "parser.y"
            { Print("- R: SUPER -> singleExpression"); }
#line 2890 "parser.tab.cpp"
    break;

  case 80: /* singleExpression: TRUE_KW  */
#line 279 "parser.y"
              { Print("- R: TRUE_LITERAL -> singleExpression"); }
#line 2896 "parser.tab.cpp"
    break;

  case 81: /* singleExpression: FALSE_KW  */
#line 280 "parser.y"
               { Print("- R: FALSE_LITERAL -> singleExpression"); }
#line 2902 "parser.tab.cpp"
    break;

  case 82: /* singleExpression: NULL_KW  */
#line 281 "parser.y"
              { Print("- R: NULL_LITERAL -> singleExpression"); }
#line 2908 "parser.tab.cpp"
    break;

  case 83: /* singleExpression: '-' singleExpression  */
#line 282 "parser.y"
                                        { Print("- R: '-' singleExpression -> singleExpression"); }
#line 2914 "parser.tab.cpp"
    break;

  case 84: /* singleExpression: '+' singleExpression  */
#line 283 "parser.y"
                                       { Print("- R: '+' singleExpression -> singleExpression"); }
#line 2920 "parser.tab.cpp"
    break;

  case 85: /* singleExpression: '!' singleExpression  */
#line 284 "parser.y"
                           { Print("- R: '!' singleExpression -> singleExpression"); }
#line 2926 "parser.tab.cpp"
    break;

  case 86: /* singleExpression: '~' singleExpression  */
#line 285 "parser.y"
                           { Print("- R: '~' singleExpression -> singleExpression"); }
#line 2932 "parser.tab.cpp"
    break;

  case 87: /* singleExpression: singleExpression OPERATOR_INCREMENT  */
#line 286 "parser.y"
                                                               { Print("- R: singleExpression OPERATOR_INCREMENT -> singleExpression"); }
#line 2938 "parser.tab.cpp"
    break;

  case 88: /* singleExpression: singleExpression OPERATOR_DECREMENT  */
#line 287 "parser.y"
                                                               { Print("- R: singleExpression OPERATOR_DECREMENT -> singleExpression"); }
#line 2944 "parser.tab.cpp"
    break;

  case 89: /* singleExpression: ENDL_OPERATOR_INCREMENT singleExpression  */
#line 288 "parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 2950 "parser.tab.cpp"
    break;

  case 90: /* singleExpression: ENDL_OPERATOR_DECREMENT singleExpression  */
#line 289 "parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 2956 "parser.tab.cpp"
    break;

  case 91: /* singleExpression: OPERATOR_INCREMENT singleExpression  */
#line 290 "parser.y"
                                                               { Print("- R: OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 2962 "parser.tab.cpp"
    break;

  case 92: /* singleExpression: OPERATOR_DECREMENT singleExpression  */
#line 291 "parser.y"
                                                               { Print("- R: OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 2968 "parser.tab.cpp"
    break;

  case 93: /* singleExpression: singleExpression '+' singleExpression  */
#line 292 "parser.y"
                                            { Print("- R: singleExpression '+' singleExpression -> singleExpression"); }
#line 2974 "parser.tab.cpp"
    break;

  case 94: /* singleExpression: singleExpression '-' singleExpression  */
#line 293 "parser.y"
                                            { Print("- R: singleExpression '-' singleExpression -> singleExpression"); }
#line 2980 "parser.tab.cpp"
    break;

  case 95: /* singleExpression: singleExpression '*' singleExpression  */
#line 294 "parser.y"
                                            { Print("- R: singleExpression '*' singleExpression -> singleExpression"); }
#line 2986 "parser.tab.cpp"
    break;

  case 96: /* singleExpression: singleExpression '/' singleExpression  */
#line 295 "parser.y"
                                            { Print("- R: singleExpression '/' singleExpression -> singleExpression"); }
#line 2992 "parser.tab.cpp"
    break;

  case 97: /* singleExpression: singleExpression '%' singleExpression  */
#line 296 "parser.y"
                                            { Print("- R: singleExpression '%' singleExpression -> singleExpression"); }
#line 2998 "parser.tab.cpp"
    break;

  case 98: /* singleExpression: singleExpression '<' singleExpression  */
#line 297 "parser.y"
                                            { Print("- R: singleExpression '<' singleExpression -> singleExpression"); }
#line 3004 "parser.tab.cpp"
    break;

  case 99: /* singleExpression: singleExpression '>' singleExpression  */
#line 298 "parser.y"
                                            { Print("- R: singleExpression '>' singleExpression -> singleExpression"); }
#line 3010 "parser.tab.cpp"
    break;

  case 100: /* singleExpression: singleExpression OPERATOR_POWER singleExpression  */
#line 299 "parser.y"
                                                       { Print("- R: singleExpression OPERATOR_POWER singleExpression -> singleExpression"); }
#line 3016 "parser.tab.cpp"
    break;

  case 101: /* singleExpression: singleExpression OPERATOR_EQUAL singleExpression  */
#line 300 "parser.y"
                                                       { Print("- R: singleExpression OPERATOR_EQUAL singleExpression -> singleExpression"); }
#line 3022 "parser.tab.cpp"
    break;

  case 102: /* singleExpression: singleExpression OPERATOR_NOT_EQUAL singleExpression  */
#line 301 "parser.y"
                                                           { Print("- R: singleExpression OPERATOR_NOT_EQUAL singleExpression -> singleExpression"); }
#line 3028 "parser.tab.cpp"
    break;

  case 103: /* singleExpression: singleExpression OPERATOR_STRICT_EQUAL singleExpression  */
#line 302 "parser.y"
                                                              { Print("- R: singleExpression OPERATOR_STRICT_EQUAL singleExpression -> singleExpression"); }
#line 3034 "parser.tab.cpp"
    break;

  case 104: /* singleExpression: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression  */
#line 303 "parser.y"
                                                                  { Print("- R: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression -> singleExpression"); }
#line 3040 "parser.tab.cpp"
    break;

  case 105: /* singleExpression: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression  */
#line 304 "parser.y"
                                                                 { Print("- R: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression -> singleExpression"); }
#line 3046 "parser.tab.cpp"
    break;

  case 106: /* singleExpression: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression  */
#line 305 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression -> singleExpression"); }
#line 3052 "parser.tab.cpp"
    break;

  case 107: /* singleExpression: singleExpression '=' singleExpression  */
#line 306 "parser.y"
                                            { Print("- R: singleExpression '=' singleExpression -> singleExpression"); }
#line 3058 "parser.tab.cpp"
    break;

  case 108: /* singleExpression: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression  */
#line 307 "parser.y"
                                                                 { Print("- R: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression -> singleExpression"); }
#line 3064 "parser.tab.cpp"
    break;

  case 109: /* singleExpression: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression  */
#line 308 "parser.y"
                                                               { Print("- R: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression -> singleExpression"); }
#line 3070 "parser.tab.cpp"
    break;

  case 110: /* singleExpression: singleExpression OPERATOR_ASSIGN_MOD singleExpression  */
#line 309 "parser.y"
                                                            { Print("- R: singleExpression OPERATOR_ASSIGN_MOD singleExpression -> singleExpression"); }
#line 3076 "parser.tab.cpp"
    break;

  case 111: /* singleExpression: singleExpression OPERATOR_ASSIGN_PLUS singleExpression  */
#line 310 "parser.y"
                                                             { Print("- R: singleExpression OPERATOR_ASSIGN_PLUS singleExpression -> singleExpression"); }
#line 3082 "parser.tab.cpp"
    break;

  case 112: /* singleExpression: singleExpression OPERATOR_ASSIGN_MINUS singleExpression  */
#line 311 "parser.y"
                                                              { Print("- R: singleExpression OPERATOR_ASSIGN_MINUS singleExpression -> singleExpression"); }
#line 3088 "parser.tab.cpp"
    break;

  case 113: /* singleExpression: singleExpression OPERATOR_ASSIGN_SHIFT_LEFT singleExpression  */
#line 312 "parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_SHIFT_LEFT singleExpression -> singleExpression"); }
#line 3094 "parser.tab.cpp"
    break;

  case 114: /* singleExpression: singleExpression OPERATOR_ASSIGN_SHIFT_RIGHT singleExpression  */
#line 313 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3100 "parser.tab.cpp"
    break;

  case 115: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_AND singleExpression  */
#line 314 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_AND singleExpression -> singleExpression"); }
#line 3106 "parser.tab.cpp"
    break;

  case 116: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_XOR singleExpression  */
#line 315 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_XOR singleExpression -> singleExpression"); }
#line 3112 "parser.tab.cpp"
    break;

  case 117: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_OR singleExpression  */
#line 316 "parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_OR singleExpression -> singleExpression"); }
#line 3118 "parser.tab.cpp"
    break;

  case 118: /* singleExpression: singleExpression OPERATOR_ASSIGN_POWER singleExpression  */
#line 317 "parser.y"
                                                              { Print("- R: singleExpression OPERATOR_ASSIGN_POWER singleExpression -> singleExpression"); }
#line 3124 "parser.tab.cpp"
    break;

  case 119: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression  */
#line 318 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression -> singleExpression"); }
#line 3130 "parser.tab.cpp"
    break;

  case 120: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression  */
#line 319 "parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression -> singleExpression"); }
#line 3136 "parser.tab.cpp"
    break;

  case 121: /* singleExpression: singleExpression OPERATOR_ASSIGN_NULLISH_COALESCING singleExpression  */
#line 320 "parser.y"
                                                                           { Print("- R: singleExpression OPERATOR_ASSIGN_NULLISH_COALESCING singleExpression -> singleExpression"); }
#line 3142 "parser.tab.cpp"
    break;

  case 122: /* singleExpression: singleExpression OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT singleExpression  */
#line 321 "parser.y"
                                                                             { Print("- R: singleExpression OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3148 "parser.tab.cpp"
    break;

  case 123: /* singleExpression: singleExpression OPERATOR_LOGICAL_OR singleExpression  */
#line 322 "parser.y"
                                                            { Print("- R: singleExpression OPERATOR_LOGICAL_OR singleExpression -> singleExpression"); }
#line 3154 "parser.tab.cpp"
    break;

  case 124: /* singleExpression: singleExpression OPERATOR_LOGICAL_AND singleExpression  */
#line 323 "parser.y"
                                                             { Print("- R: singleExpression OPERATOR_LOGICAL_AND singleExpression -> singleExpression"); }
#line 3160 "parser.tab.cpp"
    break;

  case 125: /* singleExpression: singleExpression '|' singleExpression  */
#line 324 "parser.y"
                                            { Print("- R: singleExpression '|' singleExpression -> singleExpression"); }
#line 3166 "parser.tab.cpp"
    break;

  case 126: /* singleExpression: singleExpression '^' singleExpression  */
#line 325 "parser.y"
                                            { Print("- R: singleExpression '^' singleExpression -> singleExpression"); }
#line 3172 "parser.tab.cpp"
    break;

  case 127: /* singleExpression: singleExpression '&' singleExpression  */
#line 326 "parser.y"
                                            { Print("- R: singleExpression '&' singleExpression -> singleExpression"); }
#line 3178 "parser.tab.cpp"
    break;

  case 128: /* singleExpression: singleExpression OPERATOR_SHIFT_LEFT singleExpression  */
#line 327 "parser.y"
                                                            { Print("- R: singleExpression OPERATOR_SHIFT_LEFT singleExpression -> singleExpression"); }
#line 3184 "parser.tab.cpp"
    break;

  case 129: /* singleExpression: singleExpression OPERATOR_SHIFT_RIGHT singleExpression  */
#line 328 "parser.y"
                                                             { Print("- R: singleExpression OPERATOR_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3190 "parser.tab.cpp"
    break;

  case 130: /* singleExpression: singleExpression OPERATOR_UNSIGNED_SHIFT_RIGHT singleExpression  */
#line 329 "parser.y"
                                                                      { Print("- R: singleExpression OPERATOR_UNSIGNED_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3196 "parser.tab.cpp"
    break;

  case 131: /* singleExpression: singleExpression OPERATOR_NULLISH_COALESCING singleExpression  */
#line 330 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_NULLISH_COALESCING singleExpression -> singleExpression"); }
#line 3202 "parser.tab.cpp"
    break;

  case 132: /* singleExpression: singleExpression INSTANCEOF singleExpression  */
#line 332 "parser.y"
                                                   { Print("- R: singleExpression INSTANCEOF singleExpression -> singleExpression"); }
#line 3208 "parser.tab.cpp"
    break;

  case 133: /* singleExpression: singleExpression IN singleExpression  */
#line 333 "parser.y"
                                           { Print("- R: singleExpression IN singleExpression -> singleExpression"); }
#line 3214 "parser.tab.cpp"
    break;

  case 134: /* singleExpression: singleExpression TEMPLATE_LITERAL  */
#line 335 "parser.y"
                                        { Print("- R: singleExpression TEMPLATE_LITERAL -> singleExpression"); }
#line 3220 "parser.tab.cpp"
    break;

  case 135: /* singleExpression: singleExpression '?' singleExpression ':' singleExpression  */
#line 336 "parser.y"
                                                                 { Print("- R: singleExpression '?' singleExpression ':' singleExpression -> singleExpression"); }
#line 3226 "parser.tab.cpp"
    break;

  case 136: /* singleExpression: '(' expressionList ')'  */
#line 338 "parser.y"
                             { Print("- R: '(' expressionList ')' -> singleExpression"); }
#line 3232 "parser.tab.cpp"
    break;

  case 137: /* singleExpression: singleExpression arguments  */
#line 340 "parser.y"
                                 { Print("- R: singleExpression arguments -> singleExpression"); }
#line 3238 "parser.tab.cpp"
    break;

  case 138: /* singleExpression: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression  */
#line 342 "parser.y"
                                                                   { Print("- R: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression -> singleExpression"); }
#line 3244 "parser.tab.cpp"
    break;

  case 139: /* singleExpression: singleExpression '.' identifier  */
#line 343 "parser.y"
                                      { Print("- R: singleExpression '.' identifier -> singleExpression"); }
#line 3250 "parser.tab.cpp"
    break;

  case 140: /* singleExpression: arrayLiteral  */
#line 345 "parser.y"
                   { Print("- R: arrayLiteral -> singleExpression"); }
#line 3256 "parser.tab.cpp"
    break;

  case 141: /* singleExpression: singleExpression '[' expressionList ']'  */
#line 346 "parser.y"
                                              { Print("- R: singleExpression '[' expressionList ']' -> singleExpression"); }
#line 3262 "parser.tab.cpp"
    break;

  case 142: /* singleExpression: singleExpression ENDL_BRACKET_OPEN expressionList ']'  */
#line 347 "parser.y"
                                                            { Print("- R: singleExpression ENDL_BRACKET_OPEN expressionList ']' -> singleExpression"); }
#line 3268 "parser.tab.cpp"
    break;

  case 143: /* singleExpression: NEW singleExpression  */
#line 349 "parser.y"
                           { Print("- R: NEW singleExpression -> singleExpression"); }
#line 3274 "parser.tab.cpp"
    break;

  case 144: /* arguments: '(' ')'  */
#line 353 "parser.y"
              { Print("- R: '(' ')' -> arguments"); }
#line 3280 "parser.tab.cpp"
    break;

  case 145: /* arguments: '(' argumentList ')'  */
#line 354 "parser.y"
                           { Print("- R: '(' argumentList ')' -> arguments"); }
#line 3286 "parser.tab.cpp"
    break;

  case 146: /* arguments: '(' argumentList ',' ')'  */
#line 355 "parser.y"
                               { Print("- R: '(' argumentList ',' ') -> arguments"); }
#line 3292 "parser.tab.cpp"
    break;

  case 147: /* argumentList: argument  */
#line 359 "parser.y"
               { Print("- R: argument -> argumentList"); }
#line 3298 "parser.tab.cpp"
    break;

  case 148: /* argumentList: argumentList ',' arguments  */
#line 360 "parser.y"
                                 { Print("- R: argumentList ',' arguments -> argumentList"); }
#line 3304 "parser.tab.cpp"
    break;

  case 149: /* argument: singleExpression  */
#line 364 "parser.y"
                       { Print("- R: singleExpression -> argument"); }
#line 3310 "parser.tab.cpp"
    break;

  case 150: /* argument: ELLIPSIS singleExpression  */
#line 365 "parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> argument"); }
#line 3316 "parser.tab.cpp"
    break;

  case 151: /* varStatement: varModifier varDeclarationList ';'  */
#line 371 "parser.y"
                                         { Print("- R: varModifier varDeclarationList ';' -> varStatement"); }
#line 3322 "parser.tab.cpp"
    break;

  case 152: /* varDeclarationList: varDeclaration  */
#line 375 "parser.y"
                     { Print("- R: varDeclaration -> argument"); }
#line 3328 "parser.tab.cpp"
    break;

  case 153: /* varDeclarationList: varDeclarationList ',' varDeclaration  */
#line 376 "parser.y"
                                            { Print("- R: varDeclarationList ',' varDeclaration -> varDeclarationList"); }
#line 3334 "parser.tab.cpp"
    break;

  case 154: /* varDeclaration: identifier  */
#line 380 "parser.y"
                 { Print("- R: identifier -> varDeclaration"); }
#line 3340 "parser.tab.cpp"
    break;

  case 155: /* varDeclaration: identifier typeAnnotation  */
#line 381 "parser.y"
                                { Print("- R: identifier typeAnnotation -> varDeclaration"); }
#line 3346 "parser.tab.cpp"
    break;

  case 156: /* varDeclaration: identifier '=' singleExpression  */
#line 382 "parser.y"
                                      { Print("- R: identifier '=' singleExpression -> varDeclaration"); }
#line 3352 "parser.tab.cpp"
    break;

  case 157: /* varDeclaration: identifier typeAnnotation '=' singleExpression  */
#line 383 "parser.y"
                                                     { Print("- R: identifier typeAnnotation '=' singleExpression -> varDeclaration"); }
#line 3358 "parser.tab.cpp"
    break;

  case 158: /* varModifier: VAR  */
#line 387 "parser.y"
          { Print("- R: VAR -> varModifier"); }
#line 3364 "parser.tab.cpp"
    break;

  case 159: /* varModifier: LET  */
#line 388 "parser.y"
          { Print("- R: LET -> varModifier"); }
#line 3370 "parser.tab.cpp"
    break;

  case 160: /* varModifier: CONST  */
#line 389 "parser.y"
            { Print("- R: CONST -> varModifier"); }
#line 3376 "parser.tab.cpp"
    break;

  case 161: /* ifStatement: IF '(' expressionList ')' statementListItemWithoutEmptyStatement  */
#line 395 "parser.y"
                                                                                          { Print("- R: IF '(' expressionList ')' statementListItem -> ifStatement"); }
#line 3382 "parser.tab.cpp"
    break;

  case 162: /* ifStatement: IF '(' expressionList ')' statementListItemWithoutEmptyStatement ELSE statementListItem  */
#line 396 "parser.y"
                                                                                              { Print("- R: IF '(' expressionList ')' statementListItem ELSE statementListItem -> ifStatement"); }
#line 3388 "parser.tab.cpp"
    break;

  case 163: /* $@1: %empty  */
#line 400 "parser.y"
         { isInIterationBody = 1; }
#line 3394 "parser.tab.cpp"
    break;

  case 164: /* $@2: %empty  */
#line 400 "parser.y"
                                                                                   { doWhileASI(); }
#line 3400 "parser.tab.cpp"
    break;

  case 165: /* iterationStatement: DO $@1 statementListItem WHILE '(' expressionList ')' $@2 ';'  */
#line 400 "parser.y"
                                                                                                                                   { isInIterationBody = 0; Print("- R: DO statementListItem WHILE '(' expressionList ')' ';' -> iterationStatement"); }
#line 3406 "parser.tab.cpp"
    break;

  case 166: /* $@3: %empty  */
#line 401 "parser.y"
                                   { isInIterationBody = 1; }
#line 3412 "parser.tab.cpp"
    break;

  case 167: /* iterationStatement: WHILE '(' expressionList ')' $@3 statementListItem  */
#line 401 "parser.y"
                                                                                                                                            { isInIterationBody = 0; Print("- R: WHILE '(' expressionList ')' statementListItem -> iterationStatement"); }
#line 3418 "parser.tab.cpp"
    break;

  case 168: /* $@4: %empty  */
#line 402 "parser.y"
                                                                                  { isInForHeader = 0; isInIterationBody = 1; }
#line 3424 "parser.tab.cpp"
    break;

  case 169: /* iterationStatement: forHeader expressionListOpt ';' expressionListOpt ';' expressionListOpt ')' $@4 statementListItem  */
#line 402 "parser.y"
                                                                                                                                                                 { isInIterationBody = 0; Print("- R: FOR '(' expressionListOpt ';' expressionListOpt ';' expressionListOpt ')' statementListItem -> iterationStatement"); }
#line 3430 "parser.tab.cpp"
    break;

  case 170: /* $@5: %empty  */
#line 403 "parser.y"
                                                                                               { isInForHeader = 0; isInIterationBody = 1; }
#line 3436 "parser.tab.cpp"
    break;

  case 171: /* iterationStatement: forHeader varModifier varDeclarationList ';' expressionListOpt ';' expressionListOpt ')' $@5 statementListItem  */
#line 403 "parser.y"
                                                                                                                                                                 { isInIterationBody = 0; Print("- R: FOR '(' varModifier varDeclarationList ';' expressionListOpt ';' expressionListOpt ')' statementListItem -> iterationStatement"); }
#line 3442 "parser.tab.cpp"
    break;

  case 172: /* $@6: %empty  */
#line 404 "parser.y"
                                                         { isInForHeader = 0; isInIterationBody = 1; }
#line 3448 "parser.tab.cpp"
    break;

  case 173: /* iterationStatement: forHeader singleExpression IN singleExpression ')' $@6 statementListItem  */
#line 404 "parser.y"
                                                                                                                                                                 { isInIterationBody = 0; Print("- R: FOR '(' singleExpression IN singleExpression ')' statementListItem -> iterationStatement"); }
#line 3454 "parser.tab.cpp"
    break;

  case 174: /* $@7: %empty  */
#line 405 "parser.y"
                                                                 { isInForHeader = 0; isInIterationBody = 1; }
#line 3460 "parser.tab.cpp"
    break;

  case 175: /* iterationStatement: forHeader varModifier varDeclaration IN expressionList ')' $@7 statementListItem  */
#line 405 "parser.y"
                                                                                                                                                                 { isInIterationBody = 0; Print("- R: FOR '(' varModifier varDeclaration IN expressionList ')' statementListItem -> iterationStatement"); }
#line 3466 "parser.tab.cpp"
    break;

  case 176: /* forHeader: FOR '('  */
#line 409 "parser.y"
               { isInForHeader = 1; }
#line 3472 "parser.tab.cpp"
    break;

  case 177: /* continueStatement: CONTINUE ';'  */
#line 413 "parser.y"
                   { Print("- R: CONTINUE ';' -> returnStatement"); }
#line 3478 "parser.tab.cpp"
    break;

  case 178: /* continueStatement: CONTINUE identifier ';'  */
#line 414 "parser.y"
                              { Print("- R: CONTINUE identifier ';' -> returnStatement"); }
#line 3484 "parser.tab.cpp"
    break;

  case 179: /* breakStatement: BREAK ';'  */
#line 418 "parser.y"
                 { Print("- R: BREAK ';' -> returnStatement"); }
#line 3490 "parser.tab.cpp"
    break;

  case 180: /* breakStatement: BREAK identifier ';'  */
#line 419 "parser.y"
                           { Print("- R: BREAK identifier ';' -> returnStatement"); }
#line 3496 "parser.tab.cpp"
    break;

  case 181: /* returnStatement: RETURN ';'  */
#line 423 "parser.y"
                 { Print("- R: RETURN ';' -> returnStatement"); }
#line 3502 "parser.tab.cpp"
    break;

  case 182: /* returnStatement: RETURN singleExpression ';'  */
#line 424 "parser.y"
                                  { Print("- R: RETURN singleExpression ';' -> returnStatement"); }
#line 3508 "parser.tab.cpp"
    break;

  case 183: /* labelledStatement: identifier ':' statementListItem  */
#line 428 "parser.y"
                                       { Print("- R: identifier ':' statementListItem -> labelledStatement"); }
#line 3514 "parser.tab.cpp"
    break;

  case 184: /* blockStatement: '{' '}'  */
#line 432 "parser.y"
              { Print("- R: '{' '}' -> blockStatement"); }
#line 3520 "parser.tab.cpp"
    break;

  case 185: /* blockStatement: '{' statementList '}'  */
#line 433 "parser.y"
                            { Print("- R: '{' statementList '}' -> blockStatement"); }
#line 3526 "parser.tab.cpp"
    break;

  case 186: /* switchStatement: SWITCH '(' expressionList ')' '{' '}'  */
#line 437 "parser.y"
                                            { Print("- R: SWITCH '(' expressionList ')' '{' '}' -> switchStatement"); }
#line 3532 "parser.tab.cpp"
    break;

  case 187: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList '}'  */
#line 438 "parser.y"
                                                           { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList '}' -> switchStatement"); }
#line 3538 "parser.tab.cpp"
    break;

  case 188: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause '}'  */
#line 439 "parser.y"
                                                                         { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause '}' -> switchStatement"); }
#line 3544 "parser.tab.cpp"
    break;

  case 189: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause caseClauseList '}'  */
#line 440 "parser.y"
                                                                                        { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause caseClauseList '}' -> switchStatement"); }
#line 3550 "parser.tab.cpp"
    break;

  case 190: /* caseClauseList: caseClause  */
#line 444 "parser.y"
                 { Print("- R: caseClause -> caseClauseList"); }
#line 3556 "parser.tab.cpp"
    break;

  case 191: /* caseClauseList: caseClauseList caseClause  */
#line 445 "parser.y"
                                { Print("- R: caseClauseList caseClause -> caseClauseList"); }
#line 3562 "parser.tab.cpp"
    break;

  case 192: /* caseClause: CASE expressionList ':'  */
#line 449 "parser.y"
                              { Print("- R: CASE expressionList ':' -> caseClause"); }
#line 3568 "parser.tab.cpp"
    break;

  case 193: /* caseClause: CASE expressionList ':' statementList  */
#line 450 "parser.y"
                                            { Print("- R: CASE expressionList ':' statementList -> caseClause"); }
#line 3574 "parser.tab.cpp"
    break;

  case 194: /* defaultClause: DEFAULT ':'  */
#line 454 "parser.y"
                  { Print("- R: DEFAULT ':' -> defaultClause"); }
#line 3580 "parser.tab.cpp"
    break;

  case 195: /* defaultClause: DEFAULT ':' statementList  */
#line 455 "parser.y"
                                { Print("- R: DEFAULT ':' statementList -> defaultClause"); }
#line 3586 "parser.tab.cpp"
    break;

  case 196: /* functionDeclaration: FUNCTION identifier callSignature functionBody  */
#line 461 "parser.y"
                                                     { Print("- R: FUNCTION ID callSignature functionBody -> functionDeclaration"); }
#line 3592 "parser.tab.cpp"
    break;

  case 197: /* functionBody: '{' '}'  */
#line 465 "parser.y"
              { Print("- R: '{' '}' -> functionBody"); }
#line 3598 "parser.tab.cpp"
    break;

  case 198: /* $@8: %empty  */
#line 466 "parser.y"
          { isInFunctionBody = 1; }
#line 3604 "parser.tab.cpp"
    break;

  case 199: /* functionBody: '{' $@8 statementList '}'  */
#line 466 "parser.y"
                                                      { isInFunctionBody = 0; Print("- R: '{' statementList '}' -> functionBody"); }
#line 3610 "parser.tab.cpp"
    break;

  case 200: /* callSignature: '(' ')'  */
#line 470 "parser.y"
              { Print("- R: '(' ')' -> callSignature"); }
#line 3616 "parser.tab.cpp"
    break;

  case 201: /* callSignature: '(' ')' typeAnnotation  */
#line 471 "parser.y"
                             { Print("- R: '(' ')' typeAnnotation -> callSignature"); }
#line 3622 "parser.tab.cpp"
    break;

  case 202: /* callSignature: '(' restParameter ')'  */
#line 472 "parser.y"
                            { Print("- R: '(' restParameter ')' -> callSignature"); }
#line 3628 "parser.tab.cpp"
    break;

  case 203: /* callSignature: '(' restParameter ')' typeAnnotation  */
#line 473 "parser.y"
                                           { Print("- R: '(' restParameter ')' typeAnnotation -> callSignature"); }
#line 3634 "parser.tab.cpp"
    break;

  case 204: /* callSignature: '(' parameterList ')'  */
#line 474 "parser.y"
                            { Print("- R: '(' parameterList ')' -> callSignature"); }
#line 3640 "parser.tab.cpp"
    break;

  case 205: /* callSignature: '(' parameterList ')' typeAnnotation  */
#line 475 "parser.y"
                                           { Print("- R: '(' parameterList ')' typeAnnotation -> callSignature"); }
#line 3646 "parser.tab.cpp"
    break;

  case 206: /* callSignature: '(' parameterList ',' restParameter ')'  */
#line 476 "parser.y"
                                              { Print("- R: '(' parameterList ',' restParameter ')' -> callSignature"); }
#line 3652 "parser.tab.cpp"
    break;

  case 207: /* callSignature: '(' parameterList ',' restParameter ')' typeAnnotation  */
#line 477 "parser.y"
                                                             { Print("- R: '(' parameterList ',' restParameter ')' typeAnnotation -> callSignature"); }
#line 3658 "parser.tab.cpp"
    break;

  case 208: /* callSignature: '(' parameterList ',' ')'  */
#line 478 "parser.y"
                                { Print("- R: '(' parameterList ',' ')' -> callSignature"); }
#line 3664 "parser.tab.cpp"
    break;

  case 209: /* callSignature: '(' parameterList ',' ')' typeAnnotation  */
#line 479 "parser.y"
                                               { Print("- R: '(' parameterList ',' ')' typeAnnotation -> callSignature"); }
#line 3670 "parser.tab.cpp"
    break;

  case 210: /* parameterList: parameter  */
#line 483 "parser.y"
                { Print("- R: parameter -> parameterList"); }
#line 3676 "parser.tab.cpp"
    break;

  case 211: /* parameterList: parameterList ',' parameter  */
#line 484 "parser.y"
                                  { Print("- R: parameterList ',' parameter -> parameterList"); }
#line 3682 "parser.tab.cpp"
    break;

  case 212: /* parameter: requiredParameter  */
#line 488 "parser.y"
                        { Print("- R: requiredParameter -> parameter"); }
#line 3688 "parser.tab.cpp"
    break;

  case 213: /* parameter: optionalParameter  */
#line 489 "parser.y"
                        { Print("- R: optionalParameter -> parameter"); }
#line 3694 "parser.tab.cpp"
    break;

  case 214: /* requiredParameter: identifier  */
#line 493 "parser.y"
                 { Print("- R: ID -> requiredParameter"); }
#line 3700 "parser.tab.cpp"
    break;

  case 215: /* requiredParameter: identifier typeAnnotation  */
#line 494 "parser.y"
                                { Print("- R: ID typeAnnotation -> requiredParameter"); }
#line 3706 "parser.tab.cpp"
    break;

  case 216: /* optionalParameter: identifier '?'  */
#line 498 "parser.y"
                     { Print("- R: ID '?' -> optionalParameter"); }
#line 3712 "parser.tab.cpp"
    break;

  case 217: /* optionalParameter: identifier '?' typeAnnotation  */
#line 499 "parser.y"
                                    { Print("- R: ID '?' typeAnnotation -> optionalParameter"); }
#line 3718 "parser.tab.cpp"
    break;

  case 218: /* optionalParameter: identifier initializer  */
#line 500 "parser.y"
                             { Print("- R: ID initializer -> optionalParameter"); }
#line 3724 "parser.tab.cpp"
    break;

  case 219: /* optionalParameter: identifier typeAnnotation initializer  */
#line 501 "parser.y"
                                            { Print("- R: ID typeAnnotation initializer -> optionalParameter"); }
#line 3730 "parser.tab.cpp"
    break;

  case 220: /* restParameter: ELLIPSIS singleExpression  */
#line 505 "parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> restParameter"); }
#line 3736 "parser.tab.cpp"
    break;

  case 221: /* restParameter: ELLIPSIS singleExpression typeAnnotation  */
#line 506 "parser.y"
                                               { Print("- R: ELLIPSIS singleExpression typeAnnotation -> restParameter"); }
#line 3742 "parser.tab.cpp"
    break;

  case 222: /* classDeclaration: CLASS identifier classTail  */
#line 512 "parser.y"
                                 { Print("- R: CLASS identifier classTail -> classDeclaration"); }
#line 3748 "parser.tab.cpp"
    break;

  case 223: /* classDeclaration: CLASS identifier classHeritage classTail  */
#line 513 "parser.y"
                                               { Print("- R: CLASS identifier classHeritage classTail -> classDeclaration"); }
#line 3754 "parser.tab.cpp"
    break;

  case 224: /* classHeritage: EXTENDS identifier  */
#line 517 "parser.y"
                         { Print("- R: EXTENDS identifier -> classHeritage"); }
#line 3760 "parser.tab.cpp"
    break;

  case 225: /* classTail: '{' '}'  */
#line 521 "parser.y"
              { Print("- R: '{' '}' -> classTail"); }
#line 3766 "parser.tab.cpp"
    break;

  case 226: /* classTail: '{' classElementList '}'  */
#line 522 "parser.y"
                               { Print("- R: '{' classElementList '}' -> classTail"); }
#line 3772 "parser.tab.cpp"
    break;

  case 227: /* classElementList: classElement  */
#line 526 "parser.y"
                   { Print("- R: classElement -> classElementList"); }
#line 3778 "parser.tab.cpp"
    break;

  case 228: /* classElementList: classElementList classElement  */
#line 527 "parser.y"
                                    { Print("- R: classElementList classElement -> classElementList"); }
#line 3784 "parser.tab.cpp"
    break;

  case 229: /* classElement: CONSTRUCTOR constructorCallSignature functionBody  */
#line 531 "parser.y"
                                                        { Print("- R: CONSTRUCTOR callSignature functionBody -> classElement"); }
#line 3790 "parser.tab.cpp"
    break;

  case 230: /* classElement: propertyName ';'  */
#line 534 "parser.y"
                       { Print("- R: propertyName ';' -> classElement"); }
#line 3796 "parser.tab.cpp"
    break;

  case 231: /* classElement: propertyName typeAnnotation ';'  */
#line 535 "parser.y"
                                      { Print("- R: propertyName typeAnnotation ';' -> classElement"); }
#line 3802 "parser.tab.cpp"
    break;

  case 232: /* classElement: propertyName initializer ';'  */
#line 536 "parser.y"
                                   { Print("- R: propertyName initializer ';' -> classElement"); }
#line 3808 "parser.tab.cpp"
    break;

  case 233: /* classElement: propertyName typeAnnotation initializer ';'  */
#line 537 "parser.y"
                                                  { Print("- R: propertyName typeAnnotation initializer ';' -> classElement"); }
#line 3814 "parser.tab.cpp"
    break;

  case 234: /* classElement: propertyName callSignature functionBody  */
#line 540 "parser.y"
                                              { Print("- R: propertyName callSignature functionBody -> classElement"); }
#line 3820 "parser.tab.cpp"
    break;

  case 235: /* classElement: GET propertyName '(' ')' functionBody  */
#line 543 "parser.y"
                                            { Print("- R: GET propertyName '(' ')' functionBody -> classElement"); }
#line 3826 "parser.tab.cpp"
    break;

  case 236: /* classElement: GET propertyName '(' ')' typeAnnotation functionBody  */
#line 544 "parser.y"
                                                           { Print("- R: GET propertyName '(' ')' typeAnnotation functionBody -> classElement"); }
#line 3832 "parser.tab.cpp"
    break;

  case 237: /* classElement: SET propertyName callSignature functionBody  */
#line 545 "parser.y"
                                                  { Print("- R: SET propertyName callSignature functionBody -> classElement"); }
#line 3838 "parser.tab.cpp"
    break;

  case 238: /* constructorCallSignature: '(' ')'  */
#line 549 "parser.y"
              { Print("- R: '(' ')' -> constructorCallSignature"); }
#line 3844 "parser.tab.cpp"
    break;

  case 239: /* constructorCallSignature: '(' restParameter ')'  */
#line 550 "parser.y"
                            { Print("- R: '(' restParameter ')' -> constructorCallSignature"); }
#line 3850 "parser.tab.cpp"
    break;

  case 240: /* constructorCallSignature: '(' parameterList ')'  */
#line 551 "parser.y"
                            { Print("- R: '(' parameterList ')' -> constructorCallSignature"); }
#line 3856 "parser.tab.cpp"
    break;

  case 241: /* constructorCallSignature: '(' parameterList ',' restParameter ')'  */
#line 552 "parser.y"
                                              { Print("- R: '(' parameterList ',' restParameter ')' -> constructorCallSignature"); }
#line 3862 "parser.tab.cpp"
    break;

  case 242: /* constructorCallSignature: '(' parameterList ',' ')'  */
#line 553 "parser.y"
                                { Print("- R: '(' parameterList ',' ')' -> constructorCallSignature"); }
#line 3868 "parser.tab.cpp"
    break;

  case 243: /* propertyName: identifier  */
#line 557 "parser.y"
                 { Print("- R: identifier -> propertyName"); }
#line 3874 "parser.tab.cpp"
    break;

  case 244: /* propertyName: simpleLiteral  */
#line 558 "parser.y"
                    { Print("- R: STRING_LIT -> propertyName"); }
#line 3880 "parser.tab.cpp"
    break;

  case 245: /* propertyName: '[' simpleLiteral ']'  */
#line 559 "parser.y"
                            { Print("- R: '[' simpleLiteral ']' -> propertyName"); }
#line 3886 "parser.tab.cpp"
    break;

  case 246: /* propertyName: ENDL_BRACKET_OPEN simpleLiteral ']'  */
#line 560 "parser.y"
                                          { Print("- R: ENDL_BRACKET_OPEN simpleLiteral ']' -> propertyName"); }
#line 3892 "parser.tab.cpp"
    break;

  case 247: /* identifier: ID  */
#line 564 "parser.y"
         { Print("- R: ID -> identifier"); }
#line 3898 "parser.tab.cpp"
    break;

  case 248: /* identifier: ASYNC  */
#line 565 "parser.y"
            { Print("- R: ASYNC -> identifier"); }
#line 3904 "parser.tab.cpp"
    break;

  case 249: /* identifier: AS  */
#line 566 "parser.y"
         { Print("- R: AS -> identifier"); }
#line 3910 "parser.tab.cpp"
    break;

  case 250: /* identifier: FROM  */
#line 567 "parser.y"
           { Print("- R: FROM -> identifier"); }
#line 3916 "parser.tab.cpp"
    break;

  case 251: /* identifier: YIELD  */
#line 568 "parser.y"
            { Print("- R: YIELD -> identifier"); }
#line 3922 "parser.tab.cpp"
    break;

  case 252: /* identifier: ANY  */
#line 569 "parser.y"
          { Print("- R: ANY -> identifier"); }
#line 3928 "parser.tab.cpp"
    break;

  case 253: /* identifier: NUMBER  */
#line 570 "parser.y"
             { Print("- R: NUMBER -> identifier"); }
#line 3934 "parser.tab.cpp"
    break;

  case 254: /* identifier: BOOLEAN  */
#line 571 "parser.y"
              { Print("- R: BOOLEAN -> identifier"); }
#line 3940 "parser.tab.cpp"
    break;

  case 255: /* identifier: STRING  */
#line 572 "parser.y"
             { Print("- R: STRING -> identifier"); }
#line 3946 "parser.tab.cpp"
    break;

  case 256: /* identifier: UNIQUE  */
#line 573 "parser.y"
             { Print("- R: UNIQUE -> identifier"); }
#line 3952 "parser.tab.cpp"
    break;

  case 257: /* identifier: SYMBOL  */
#line 574 "parser.y"
             { Print("- R: SYMBOL -> identifier"); }
#line 3958 "parser.tab.cpp"
    break;

  case 258: /* identifier: NEVER  */
#line 575 "parser.y"
            { Print("- R: NEVER -> identifier"); }
#line 3964 "parser.tab.cpp"
    break;

  case 259: /* identifier: UNDEFINED  */
#line 576 "parser.y"
                { Print("- R: UNDEFINED -> identifier"); }
#line 3970 "parser.tab.cpp"
    break;

  case 260: /* identifier: OBJECT  */
#line 577 "parser.y"
             { Print("- R: OBJECT -> identifier"); }
#line 3976 "parser.tab.cpp"
    break;

  case 261: /* identifier: KEYOF  */
#line 578 "parser.y"
            { Print("- R: KEYOF -> identifier"); }
#line 3982 "parser.tab.cpp"
    break;

  case 262: /* identifier: NAMESPACE  */
#line 579 "parser.y"
                { Print("- R: NAMESPACE -> identifier"); }
#line 3988 "parser.tab.cpp"
    break;

  case 263: /* identifier: ABSTRACT  */
#line 580 "parser.y"
               { Print("- R: ABSTRACT -> identifier"); }
#line 3994 "parser.tab.cpp"
    break;

  case 264: /* identifier: REQUIRE  */
#line 581 "parser.y"
              { Print("- R: REQUIRE -> identifier"); }
#line 4000 "parser.tab.cpp"
    break;


#line 4004 "parser.tab.cpp"

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

#line 584 "parser.y"



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
    isASIActivated = 0;

    if (yychar == '}') {
        return simpleASI(yychar, yyn, yystate, yyssp);
    }

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


