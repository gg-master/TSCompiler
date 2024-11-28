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
  YYSYMBOL_requiredParameterList = 175,    /* requiredParameterList  */
  YYSYMBOL_optionalParameterList = 176,    /* optionalParameterList  */
  YYSYMBOL_requiredParameter = 177,        /* requiredParameter  */
  YYSYMBOL_optionalParameter = 178,        /* optionalParameter  */
  YYSYMBOL_restParameter = 179,            /* restParameter  */
  YYSYMBOL_classDeclaration = 180,         /* classDeclaration  */
  YYSYMBOL_classHeritage = 181,            /* classHeritage  */
  YYSYMBOL_classTail = 182,                /* classTail  */
  YYSYMBOL_classElementList = 183,         /* classElementList  */
  YYSYMBOL_classElement = 184,             /* classElement  */
  YYSYMBOL_constructorCallSignature = 185, /* constructorCallSignature  */
  YYSYMBOL_propertyName = 186,             /* propertyName  */
  YYSYMBOL_identifier = 187                /* identifier  */
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
#define YYLAST   2210

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  123
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  267
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  454

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
     470,   471,   475,   476,   477,   478,   480,   481,   482,   484,
     486,   487,   488,   490,   491,   492,   494,   498,   499,   503,
     504,   508,   509,   513,   514,   515,   516,   520,   521,   527,
     528,   532,   536,   537,   541,   542,   546,   549,   550,   551,
     552,   555,   558,   559,   560,   564,   568,   569,   570,   571,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592
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
  "functionBody", "$@8", "callSignature", "parameterList",
  "requiredParameterList", "optionalParameterList", "requiredParameter",
  "optionalParameter", "restParameter", "classDeclaration",
  "classHeritage", "classTail", "classElementList", "classElement",
  "constructorCallSignature", "propertyName", "identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-330)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     904,  -330,  -330,  -330,   -76,  2157,  2157,  -330,   -60,   -41,
     171,   618,    17,  1257,  -330,  -330,  1491,  -330,  -330,  -330,
    -330,  -330,  -330,  -330,  -330,  -330,  -330,  -330,  -330,  -330,
    -330,  -330,  -330,  -330,  -330,  -330,  -330,  -330,  -330,  -330,
    -330,  -330,  1491,  1491,  1491,  1491,  1491,  1491,  1491,  1491,
    1394,  1394,  1491,  -330,   522,    89,   904,  -330,  -330,  -330,
    -330,  -330,   -30,  1854,  -330,  2157,  -330,  -330,  1127,  -330,
    -330,  -330,  -330,  -330,  -330,  -330,  -330,    58,  1491,    20,
       3,   904,  1491,  -330,  -330,    34,  -330,    43,  1491,  -330,
    1660,  -330,   103,   103,   103,   103,   103,   103,   103,   103,
     103,  1491,   -36,  -330,  1854,   -29,   -32,  -330,   664,  -330,
    -330,  1491,  -330,  -330,  -330,  -330,  1491,  1491,  1491,  1491,
    1491,  1491,  1491,  1491,  1491,  1491,  1491,  1491,  1491,  1491,
    1491,  1491,  1491,  1491,  1491,  1491,  1491,  1491,  1491,  1491,
    1491,  1491,  1491,  1491,  1491,  1491,  1491,  1491,  1491,  1491,
    1491,  1491,  1491,  1491,  1491,  1491,  1491,  1491,  2157,  1491,
    1491,  1491,  1356,  -330,   -27,  -330,   -17,    44,    98,  1918,
    2157,   904,   -13,  2136,    48,  2157,  1161,    56,  -330,   170,
     -12,  -330,  -330,    -6,  -330,  1854,  1394,  -330,  -330,  -330,
    -330,  1854,  1975,  1975,  1975,  1975,  1975,  1975,  1975,  1975,
    1975,  1975,  1975,  1975,  1975,  1975,  1975,  1975,  1726,   658,
     882,  1000,  1568,  2009,  2042,  1388,  1388,  1388,  1388,   246,
     246,   246,   246,   246,   246,    79,    79,    79,    39,    39,
      32,    32,    32,    32,  -330,   -10,    -4,    67,  1491,  -330,
    1854,     6,  -330,  2157,  -330,  1491,   199,   124,  1491,  1491,
     -21,    92,  -330,  1023,  1491,    69,   133,   157,  -330,  -330,
     161,    82,   101,  -330,  -330,  1524,  1524,   107,   119,   119,
    -330,  -330,  1219,  -330,   -18,  -330,  -330,   109,  -330,   108,
    -330,  1491,  -330,  -330,  1854,   -80,  -330,  -330,  1854,  -330,
    -330,  -330,  -330,  -330,  -330,  -330,  -330,  -330,  -330,  -330,
    1596,  1596,   199,   199,   199,  -330,   -33,   114,  -330,  -330,
    1491,   110,   160,  1491,  1491,   224,  -330,  -330,  -330,  -330,
    -330,  -330,  -330,  -330,  -330,  -330,  -330,  -330,  1790,   153,
    2136,  2136,  -330,  1491,   153,  -330,   172,  -330,   904,   115,
      20,  2136,    48,   126,   127,  -330,  -330,  -330,   132,    -2,
      48,  1491,   904,    -5,   764,  -330,  -330,   -33,   -33,  -330,
      19,    24,   136,  1596,  1596,  1574,  1854,  1491,  -330,   147,
      12,   904,  -330,  -330,   209,  -330,   210,  -330,   214,    82,
    1854,  -330,  -330,   784,   162,    48,   164,  -330,  -330,  -330,
    -330,  -330,   165,  -330,    13,  -330,  1491,  -330,    -3,  -330,
     199,  -330,  -330,  -330,   195,  -330,  -330,   -51,   167,   904,
    1491,  -330,  -330,  2136,  -330,  -330,   172,  -330,   -43,  -330,
    -330,  -330,  -330,   -20,   208,  -330,  -330,    -1,  -330,  -330,
    -330,  -330,   173,   904,   228,    48,  -330,   174,   904,   904,
    -330,     1,   904,  -330,  -330,  -330,  -330,  -330,   904,   904,
    -330,  -330,   904,  -330
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   158,   159,   160,     0,     0,     0,   163,     0,     0,
       0,     0,     0,     0,    79,    78,     0,   251,   252,   253,
     254,   264,   265,   266,   267,   255,   256,   257,   258,   261,
     262,   259,   260,   263,    60,    61,    62,    82,    80,    81,
     250,    63,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,   202,     0,     0,     0,     0,   229,     0,
       0,   178,   180,     0,   182,    70,    66,    64,    65,   136,
     185,    75,   107,   111,   112,   118,   108,   109,   110,   113,
     114,   122,   115,   116,   117,   119,   120,   121,     0,   131,
     123,   124,   125,   126,   127,   101,   102,   103,   104,    99,
      98,   106,   105,   132,   133,   128,   129,   130,    93,    94,
      95,    96,    97,   100,   139,     0,     0,   138,     0,   144,
     149,     0,   147,     0,   151,     0,     0,   155,    72,     0,
       0,   152,   183,     0,     0,     0,   203,   204,   217,   219,
     205,   221,   198,   196,   231,     0,     0,     0,     0,     0,
     232,   247,     0,   234,     0,   246,   230,     0,   166,     0,
      68,     0,   141,   142,   150,     0,   145,   153,   156,    47,
      48,    50,    49,    51,    53,    54,    52,    55,    56,    57,
       0,     0,    44,    44,     0,    59,    32,    37,    39,    58,
       0,     0,   133,    72,     0,   161,    18,    19,    20,    22,
      23,    24,    25,    26,    27,    21,    28,    29,   227,   200,
     210,   211,   212,     0,   223,   225,   222,   197,     0,     0,
       0,   202,     0,     0,     0,   233,   235,   237,     0,     0,
       0,     0,     0,     0,   135,   146,   148,    33,    34,    45,
       0,     0,     0,     0,     0,     0,   157,    72,   172,     0,
       0,     0,   228,   201,   206,   218,   207,   220,   208,     0,
      31,   224,   226,     0,     0,     0,     0,   236,   248,   249,
     239,   238,     0,   241,     0,   167,     0,   186,     0,   190,
       0,    42,    43,    38,    35,    36,    40,     0,     0,     0,
      72,   174,   162,   213,   214,   215,     0,   199,     0,   244,
     245,   240,   164,     0,     0,   187,   191,     0,    46,    41,
     168,   173,     0,     0,   209,     0,   242,     0,   192,   194,
     188,     0,     0,   170,   175,   216,   243,   165,   193,   195,
     189,   169,     0,   171
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -330,  -330,   -50,   -55,  -330,  -330,  -265,  -238,  -254,   -75,
      -8,  -330,  -246,  -174,  -330,   -39,  -330,    40,  -245,   -45,
     356,    11,  -330,  -330,    45,   129,  -146,   232,    49,    50,
    -330,  -330,  -330,  -330,  -330,  -330,  -330,  -330,    51,    52,
      54,    55,    57,    59,  -126,  -329,  -330,    61,  -315,  -330,
    -244,   -23,  -330,   -19,   -11,  -312,  -309,    68,  -330,   143,
    -330,    37,  -330,  -190,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    55,    56,    57,   315,    58,   335,   359,   306,   307,
     360,   308,   247,    59,    60,   102,   103,    61,   167,    62,
      63,   163,   241,   242,    64,   164,   165,    65,    66,    67,
      81,   437,   352,   442,   452,   409,   433,    68,    69,    70,
      71,    72,    73,    74,   398,   399,   427,    75,   263,   338,
     174,   255,   256,   257,   258,   259,   260,    76,   177,   178,
     272,   273,   342,   274,    91
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      77,   110,   271,   311,   108,    79,    80,   106,   305,   348,
      85,    87,   105,   175,   396,   336,   396,   424,   396,   377,
     396,   376,   378,   168,   251,   186,   179,   387,   349,   111,
     350,   111,   186,   172,   243,   393,   246,   180,   162,   355,
     243,   111,    78,   183,   333,   245,   357,   358,   111,   111,
     363,   111,   364,   110,    77,   111,    77,   111,    82,   438,
     333,   246,   246,   365,   429,   166,   362,   285,   369,   426,
     419,   382,   309,   111,   111,   339,   340,    83,   262,   187,
     400,    77,   372,   373,   392,   400,   188,   189,   381,   109,
     112,   271,   271,   244,   343,   344,   385,   287,   271,   313,
     173,   377,   347,   436,   434,   282,   253,   278,    77,   404,
     405,   283,   426,   279,   235,   236,   252,   397,   391,   425,
     446,   440,   408,   450,   176,   286,   309,   309,   309,   309,
     309,   411,   422,   416,   401,    88,   157,   171,   173,   402,
     154,   155,   156,   157,   333,   158,   159,   280,   160,   161,
     162,   382,   158,   159,   181,   160,   161,   162,   234,   111,
     334,   246,   428,   182,   248,   432,    34,    35,    36,   262,
     166,    77,   435,   261,    41,   264,   275,   176,   152,   153,
     154,   155,   156,   157,   277,   162,   310,   314,   329,   309,
     309,   309,   158,   159,   330,   160,   161,   162,    17,    18,
      19,    20,    21,   168,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,   158,   159,   331,   160,
     161,   162,   332,   337,    40,   341,   309,   351,   365,   353,
     367,   371,   246,   384,   333,   289,   290,   291,   292,   293,
     294,   388,   389,   166,   295,   296,    34,    35,    36,   297,
     298,   299,   390,    77,    41,   403,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   275,   275,   410,   168,   370,
     413,   414,   275,   158,   159,   415,   160,   161,   162,   368,
     364,   418,   300,   420,   301,   421,   430,   439,   383,   445,
     407,    84,   443,   316,   447,   361,   356,   395,   317,   250,
     170,   441,   318,   319,   320,   321,   394,   322,   323,   346,
     324,   374,   325,   302,   326,   303,   412,   304,   386,   375,
     276,   327,   168,     0,     0,     0,     0,     0,   110,     0,
     261,   379,     0,     0,     0,     0,     0,     0,    77,     0,
       0,   261,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   423,    77,     0,   431,     0,     0,     0,     0,   158,
     159,     0,   160,   161,   162,   168,     0,     0,     0,    90,
       0,    77,    92,     0,     0,     0,     0,     0,   444,     0,
       0,     0,     0,    77,     0,     0,     0,   451,   448,   449,
       0,     0,     0,   110,   110,     0,     0,   453,    93,    94,
      95,    96,    97,    98,    99,   100,   104,   104,     0,    77,
       0,     0,     0,   379,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   169,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,     0,     0,     0,    77,    77,
       0,     0,    77,     0,     0,     0,     0,     0,    77,    77,
       0,     0,    77,     0,     0,     0,     0,   185,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   191,     0,     0,
       0,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,     0,     0,     0,   237,   240,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     4,     0,
       5,     6,     0,     0,     0,     7,     8,     9,    10,    11,
      12,     0,   104,    13,    14,    15,    16,     0,     0,    17,
      18,    19,    20,    21,     0,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,     0,     0,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,    43,
      44,    45,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   284,     0,     0,     0,     0,     0,
       0,   288,     0,     0,     0,   312,     0,     0,     0,     0,
     328,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,    47,     0,     0,     0,     0,    48,    49,     0,
       0,     0,     0,     0,     0,     0,    50,   354,    51,     0,
      52,     0,    53,    54,   107,    17,    18,    19,    20,    21,
       0,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,     0,     0,     0,   366,     1,     2,     3,
       4,    40,     5,     6,     0,     0,     0,     7,     8,     9,
      10,    11,    12,     0,     0,    13,    14,    15,    16,   380,
       0,    17,    18,    19,    20,    21,     0,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,     0,
       0,    34,    35,    36,    37,    38,    39,    40,     0,    41,
      42,    43,    44,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    86,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,    46,    47,     0,     0,     0,     0,    48,
      49,   158,   159,     0,   160,   161,   162,     0,    50,     0,
      51,     0,    52,     0,    53,    54,   190,     1,     2,     3,
       4,     0,     5,     6,     0,     0,     0,     7,     8,     9,
      10,    11,    12,     0,     0,    13,    14,    15,    16,     0,
       0,    17,    18,    19,    20,    21,     0,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,     0,
       0,    34,    35,    36,    37,    38,    39,    40,     0,    41,
      42,    43,    44,    45,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,     0,
       0,     0,     0,     0,     0,     0,     0,   158,   159,     0,
     160,   161,   162,    46,    47,     0,     0,     0,     0,    48,
      49,     0,     0,     0,     0,     0,     0,     0,    50,     0,
      51,     0,    52,     0,    53,    54,   417,     1,     2,     3,
       4,     0,     5,     6,     0,     0,     0,     7,     8,     9,
      10,    11,    12,     0,     0,    13,    14,    15,    16,     0,
       0,    17,    18,    19,    20,    21,     0,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,     0,
       0,    34,    35,    36,    37,    38,    39,    40,     0,    41,
      42,    43,    44,    45,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,     0,     0,     0,
       0,     0,     0,     0,     0,   158,   159,     0,   160,   161,
     162,     0,     0,    46,    47,     0,     0,     0,     0,    48,
      49,     0,     0,     0,     0,     0,     0,     0,    50,     0,
      51,     0,    52,     0,    53,    54,     1,     2,     3,     4,
       0,     5,     6,     0,     0,     0,     7,     8,     9,    10,
      11,    12,     0,     0,    13,    14,    15,    16,     0,     0,
      17,    18,    19,    20,    21,     0,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,     0,     0,
      34,    35,    36,    37,    38,    39,    40,     0,    41,    42,
      43,    44,    45,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,     0,     0,     0,     0,     0,
       0,     0,     0,   158,   159,     0,   160,   161,   162,     0,
       0,     0,    46,    47,     0,     0,     0,     0,    48,    49,
       1,     2,     3,     0,     0,     0,     0,    50,     0,    51,
       0,    52,     0,     0,    54,     0,     0,     0,     0,    14,
      15,    16,     0,     0,    17,    18,    19,    20,    21,     0,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,   265,   266,    34,    35,    36,    37,    38,    39,
      40,     0,    41,    42,    43,    44,    45,     0,    17,    18,
      19,    20,    21,   267,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     0,     0,    34,    35,
      36,     0,     0,     0,    40,     0,    41,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    46,    47,     0,     0,
     265,   266,    48,    49,     0,     0,     0,     0,     0,     0,
       0,    50,     0,    51,     0,    52,    17,    18,    19,    20,
      21,   267,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,     0,     0,    34,    35,    36,     0,
       0,     0,    40,     0,    41,   268,     0,   269,     0,    14,
      15,    16,     0,   270,    17,    18,    19,    20,    21,     0,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,     0,     0,    34,    35,    36,    37,    38,    39,
      40,     0,    41,    42,    43,    44,    45,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   268,     0,   269,     0,     0,     0,     0,
       0,   345,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    46,    47,     0,     0,
       0,     0,    48,    49,     0,     0,     0,     0,     0,     0,
       0,    50,     0,    51,     0,    52,     0,    89,    14,    15,
      16,   238,     0,    17,    18,    19,    20,    21,     0,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,     0,     0,    34,    35,    36,    37,    38,    39,    40,
       0,    41,    42,    43,    44,    45,    14,    15,    16,   101,
       0,    17,    18,    19,    20,    21,     0,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,     0,
       0,    34,    35,    36,    37,    38,    39,    40,     0,    41,
      42,    43,    44,    45,     0,    46,    47,     0,     0,     0,
       0,    48,    49,     0,     0,     0,     0,     0,     0,     0,
      50,     0,    51,     0,    52,   239,     0,     0,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,    46,    47,     0,     0,     0,     0,    48,
      49,   158,   159,     0,   160,   161,   162,     0,    50,     0,
      51,     0,    52,    14,    15,    16,     0,     0,    17,    18,
      19,    20,    21,     0,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     0,     0,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
      45,    17,    18,    19,    20,    21,     0,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,     0,
       0,    34,    35,    36,     0,     0,     0,    40,     0,    41,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46,    47,     0,     0,     0,     0,    48,    49,     0,     0,
       0,     0,     0,     0,     0,    50,     0,    51,     0,    52,
     289,   290,   291,   292,   293,   294,     0,     0,     0,   295,
     296,    34,    35,    36,   297,   298,   299,     0,     0,    41,
       0,     0,   289,   290,   291,   292,   293,   294,   268,     0,
     269,   295,   296,    34,    35,    36,   297,   298,   299,     0,
       0,    41,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,     0,     0,     0,     0,     0,     0,     0,
       0,   158,   159,     0,   160,   161,   162,     0,   302,   406,
     303,     0,   304,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     302,     0,   303,     0,   304,   113,   114,   115,     0,     0,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,     0,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,     0,     0,     0,     0,     0,
       0,     0,     0,   158,   159,     0,   160,   161,   162,     0,
     184,   113,   114,   115,     0,     0,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   281,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,     0,     0,   158,
     159,     0,   160,   161,   162,   113,   114,   115,     0,     0,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   246,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,     0,     0,     0,     0,     0,
       0,     0,     0,   158,   159,     0,   160,   161,   162,   113,
     114,   115,     0,     0,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,     0,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,     0,
       0,     0,     0,     0,     0,     0,     0,   158,   159,     0,
     160,   161,   162,   113,   114,   115,     0,     0,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,     0,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   249,   149,   150,   151,   152,   153,   154,
     155,   156,   157,     0,     0,     0,     0,     0,     0,     0,
       0,   158,   159,     0,   160,   161,   162,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,     0,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
       0,     0,     0,     0,     0,     0,     0,     0,   158,   159,
       0,   160,   161,   162,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,     0,     0,     0,     0,     0,     0,
       0,     0,   158,   159,     0,   160,   161,   162,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,     0,     0,     0,
       0,     0,     0,     0,     0,   158,   159,     0,   160,   161,
     162,   254,     0,    17,    18,    19,    20,    21,     0,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,     0,     0,     0,    17,    18,    19,    20,    21,    40,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,     0,     0,     0,     0,     0,     0,     0,     0,
      40
};

static const yytype_int16 yycheck[] =
{
       0,    56,   176,   248,    54,     5,     6,    52,   246,   274,
      10,    11,    51,    10,    19,   261,    19,    20,    19,   331,
      19,   330,   331,    68,   170,    61,    81,   342,   274,    61,
     274,    61,    61,    78,    61,   350,    79,    82,   118,   119,
      61,    61,   118,    88,    62,    62,   300,   301,    61,    61,
      83,    61,    85,   108,    54,    61,    56,    61,   118,    79,
      62,    79,    79,   114,   115,    65,   304,    61,   313,   398,
     385,   336,   246,    61,    61,   265,   266,   118,   121,   115,
      61,    81,   328,   329,   349,    61,   115,   119,   334,     0,
     120,   265,   266,   120,   268,   269,   340,   243,   272,   120,
     118,   413,   120,   418,   413,   115,   119,   119,   108,   363,
     364,   115,   441,   119,   159,   160,   171,   122,   120,   122,
     435,   122,   367,   122,   121,   119,   300,   301,   302,   303,
     304,   119,   119,   379,   115,   118,   104,    79,   118,   115,
     101,   102,   103,   104,    62,   113,   114,   186,   116,   117,
     118,   416,   113,   114,   120,   116,   117,   118,   158,    61,
      78,    79,   400,   120,   120,   410,    47,    48,    49,   121,
     170,   171,   418,   173,    55,   175,   176,   121,    99,   100,
     101,   102,   103,   104,    14,   118,    62,    95,   119,   363,
     364,   365,   113,   114,    61,   116,   117,   118,    27,    28,
      29,    30,    31,   248,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,   113,   114,    61,   116,
     117,   118,    61,   122,    53,   118,   400,   118,   114,   121,
     120,     7,    79,   118,    62,    36,    37,    38,    39,    40,
      41,   115,   115,   243,    45,    46,    47,    48,    49,    50,
      51,    52,   120,   253,    55,   119,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   265,   266,   120,   313,   314,
      61,    61,   272,   113,   114,    61,   116,   117,   118,   119,
      85,   119,    83,   119,    85,   120,   119,    79,   338,    61,
     365,   120,   119,   253,   120,   303,   285,   352,   253,   170,
      68,   427,   253,   253,   253,   253,   351,   253,   253,   272,
     253,   330,   253,   114,   253,   116,   371,   118,   341,   330,
     177,   253,   367,    -1,    -1,    -1,    -1,    -1,   383,    -1,
     330,   331,    -1,    -1,    -1,    -1,    -1,    -1,   338,    -1,
      -1,   341,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   396,   352,    -1,   409,    -1,    -1,    -1,    -1,   113,
     114,    -1,   116,   117,   118,   410,    -1,    -1,    -1,    13,
      -1,   371,    16,    -1,    -1,    -1,    -1,    -1,   433,    -1,
      -1,    -1,    -1,   383,    -1,    -1,    -1,   442,   438,   439,
      -1,    -1,    -1,   448,   449,    -1,    -1,   452,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    -1,   409,
      -1,    -1,    -1,   413,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   433,    -1,    -1,    -1,    -1,   438,   439,
      -1,    -1,   442,    -1,    -1,    -1,    -1,    -1,   448,   449,
      -1,    -1,   452,    -1,    -1,    -1,    -1,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,
      -1,    -1,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,    -1,    -1,    -1,   161,   162,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    13,    14,    15,    16,    17,
      18,    -1,   186,    21,    22,    23,    24,    -1,    -1,    27,
      28,    29,    30,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
      -1,   245,    -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,    -1,    -1,    -1,    -1,   105,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,   281,   116,    -1,
     118,    -1,   120,   121,   122,    27,    28,    29,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,   310,     3,     4,     5,
       6,    53,     8,     9,    -1,    -1,    -1,    13,    14,    15,
      16,    17,    18,    -1,    -1,    21,    22,    23,    24,   333,
      -1,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    99,   100,    -1,    -1,    -1,    -1,   105,
     106,   113,   114,    -1,   116,   117,   118,    -1,   114,    -1,
     116,    -1,   118,    -1,   120,   121,   122,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    13,    14,    15,
      16,    17,    18,    -1,    -1,    21,    22,    23,    24,    -1,
      -1,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,
     116,   117,   118,    99,   100,    -1,    -1,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,
     116,    -1,   118,    -1,   120,   121,   122,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    13,    14,    15,
      16,    17,    18,    -1,    -1,    21,    22,    23,    24,    -1,
      -1,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,   117,
     118,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,
     116,    -1,   118,    -1,   120,   121,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    13,    14,    15,    16,
      17,    18,    -1,    -1,    21,    22,    23,    24,    -1,    -1,
      27,    28,    29,    30,    31,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,    -1,   116,   117,   118,    -1,
      -1,    -1,    99,   100,    -1,    -1,    -1,    -1,   105,   106,
       3,     4,     5,    -1,    -1,    -1,    -1,   114,    -1,   116,
      -1,   118,    -1,    -1,   121,    -1,    -1,    -1,    -1,    22,
      23,    24,    -1,    -1,    27,    28,    29,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    11,    12,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    47,    48,
      49,    -1,    -1,    -1,    53,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,
      11,    12,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,   116,    -1,   118,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    55,   114,    -1,   116,    -1,    22,
      23,    24,    -1,   122,    27,    28,    29,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,   116,    -1,    -1,    -1,    -1,
      -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,
      -1,    -1,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,   116,    -1,   118,    -1,   120,    22,    23,
      24,    25,    -1,    27,    28,    29,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    22,    23,    24,    25,
      -1,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    -1,    99,   100,    -1,    -1,    -1,
      -1,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,    -1,   116,    -1,   118,   119,    -1,    -1,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    99,   100,    -1,    -1,    -1,    -1,   105,
     106,   113,   114,    -1,   116,   117,   118,    -1,   114,    -1,
     116,    -1,   118,    22,    23,    24,    -1,    -1,    27,    28,
      29,    30,    31,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    47,    48,    49,    -1,    -1,    -1,    53,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   100,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    -1,   116,    -1,   118,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    55,
      -1,    -1,    36,    37,    38,    39,    40,    41,   114,    -1,
     116,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      -1,    55,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,   114,    -1,   116,   117,   118,    -1,   114,   115,
     116,    -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,    -1,   116,    -1,   118,    55,    56,    57,    -1,    -1,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    -1,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,    -1,   116,   117,   118,    -1,
     120,    55,    56,    57,    -1,    -1,    -1,    -1,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
     114,    -1,   116,   117,   118,    55,    56,    57,    -1,    -1,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,    -1,   116,   117,   118,    55,
      56,    57,    -1,    -1,    -1,    -1,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    -1,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,
     116,   117,   118,    55,    56,    57,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,   114,    -1,   116,   117,   118,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
      -1,   116,   117,   118,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,   114,    -1,   116,   117,   118,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,   117,
     118,    25,    -1,    27,    28,    29,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    27,    28,    29,    30,    31,    53,
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
     162,   163,   164,   165,   166,   170,   180,   187,   118,   187,
     187,   153,   118,   118,   120,   187,   120,   187,   118,   120,
     143,   187,   143,   143,   143,   143,   143,   143,   143,   143,
     143,    25,   138,   139,   143,   138,   142,   122,   125,     0,
     126,    61,   120,    55,    56,    57,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   113,   114,
     116,   117,   118,   144,   148,   149,   187,   141,   142,   143,
     150,    79,   142,   118,   173,    10,   121,   181,   182,   126,
     142,   120,   120,   142,   120,   143,    61,   115,   115,   119,
     122,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   187,   142,   142,   143,    25,   119,
     143,   145,   146,    61,   120,    62,    79,   135,   120,    95,
     148,   149,   126,   119,    25,   174,   175,   176,   177,   178,
     179,   187,   121,   171,   187,    11,    12,    32,   114,   116,
     122,   136,   183,   184,   186,   187,   182,    14,   119,   119,
     138,    79,   115,   115,   143,    61,   119,   149,   143,    36,
      37,    38,    39,    40,    41,    45,    46,    50,    51,    52,
      83,    85,   114,   116,   118,   130,   131,   132,   134,   136,
      62,   141,   143,   120,    95,   127,   140,   147,   151,   152,
     161,   162,   163,   164,   165,   166,   170,   180,   143,   119,
      61,    61,    61,    62,    78,   129,   135,   122,   172,   186,
     186,   118,   185,   136,   136,   122,   184,   120,   129,   135,
     173,   118,   155,   121,   143,   119,   144,   131,   131,   130,
     133,   133,   130,    83,    85,   114,   143,   120,   119,   141,
     142,     7,   135,   135,   176,   177,   179,   178,   179,   187,
     143,   135,   129,   125,   118,   173,   174,   171,   115,   115,
     120,   120,   129,   171,   142,   126,    19,   122,   167,   168,
      61,   115,   115,   119,   131,   131,   115,   132,   141,   158,
     120,   119,   126,    61,    61,    61,   135,   122,   119,   171,
     119,   120,   119,   142,    20,   122,   168,   169,   130,   115,
     119,   126,   141,   159,   179,   135,   171,   154,    79,    79,
     122,   167,   156,   119,   126,    61,   171,   120,   125,   125,
     122,   126,   157,   126
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
     173,   173,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   175,   175,   176,
     176,   177,   177,   178,   178,   178,   178,   179,   179,   180,
     180,   181,   182,   182,   183,   183,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   185,   186,   186,   186,   186,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187
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
       3,     4,     0,     1,     1,     1,     3,     3,     3,     5,
       2,     2,     2,     4,     4,     4,     6,     1,     3,     1,
       3,     1,     2,     2,     3,     2,     3,     2,     3,     3,
       4,     2,     2,     3,     1,     2,     3,     2,     3,     3,
       4,     3,     5,     6,     4,     3,     1,     1,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
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
#line 2372 "parser.tab.cpp"
    break;

  case 3: /* statementList: statementListItem  */
#line 100 "parser.y"
                        { Print("- R: statementListItem -> statementList"); }
#line 2378 "parser.tab.cpp"
    break;

  case 4: /* statementList: statementList statementListItem  */
#line 101 "parser.y"
                                      { Print("- R: statementList statementListItem -> statementList"); }
#line 2384 "parser.tab.cpp"
    break;

  case 5: /* statementListItem: emptyStatement  */
#line 105 "parser.y"
                                    { Print("- R: emptyStatement -> statementListItem"); }
#line 2390 "parser.tab.cpp"
    break;

  case 6: /* statementListItem: expressionStatement  */
#line 106 "parser.y"
                                    { Print("- R: expressionStatement -> statementListItem"); }
#line 2396 "parser.tab.cpp"
    break;

  case 7: /* statementListItem: varStatement  */
#line 107 "parser.y"
                                    { Print("- R: varStatement -> statementListItem"); }
#line 2402 "parser.tab.cpp"
    break;

  case 8: /* statementListItem: ifStatement  */
#line 108 "parser.y"
                                    { Print("- R: ifStatement -> statementListItem"); }
#line 2408 "parser.tab.cpp"
    break;

  case 9: /* statementListItem: switchStatement  */
#line 109 "parser.y"
                                    { Print("- R: switchStatement -> statementListItem"); }
#line 2414 "parser.tab.cpp"
    break;

  case 10: /* statementListItem: iterationStatement  */
#line 110 "parser.y"
                                    { Print("- R: iterationStatement -> statementListItem"); }
#line 2420 "parser.tab.cpp"
    break;

  case 11: /* statementListItem: continueStatement  */
#line 112 "parser.y"
        {
            if ( !isInIterationBody ) { 
                yyerror("illegal continue statement."); YYERROR;
            } 
            Print("- R: continueStatement -> statementListItem");  
        }
#line 2431 "parser.tab.cpp"
    break;

  case 12: /* statementListItem: breakStatement  */
#line 119 "parser.y"
        {
            if ( !isInIterationBody ) { 
                yyerror("illegal break statement."); YYERROR;
            } 
            Print("- R: breakStatement -> statementListItem");
        }
#line 2442 "parser.tab.cpp"
    break;

  case 13: /* statementListItem: returnStatement  */
#line 126 "parser.y"
        { 
            if ( !isInFunctionBody ) { 
                yyerror("illegal return statement."); YYERROR;
            } 
            Print("- R: returnStatement -> statementListItem"); 
        }
#line 2453 "parser.tab.cpp"
    break;

  case 14: /* statementListItem: labelledStatement  */
#line 132 "parser.y"
                                    { Print("- R: labelledStatement -> statementListItem"); }
#line 2459 "parser.tab.cpp"
    break;

  case 15: /* statementListItem: blockStatement  */
#line 133 "parser.y"
                                    { Print("- R: blockStatement -> statementListItem"); }
#line 2465 "parser.tab.cpp"
    break;

  case 16: /* statementListItem: functionDeclaration  */
#line 134 "parser.y"
                                    { Print("- R: functionDeclaration -> statementListItem"); }
#line 2471 "parser.tab.cpp"
    break;

  case 17: /* statementListItem: classDeclaration  */
#line 135 "parser.y"
                                    { Print("- R: classDeclaration -> statementListItem"); }
#line 2477 "parser.tab.cpp"
    break;

  case 18: /* statementListItemWithoutEmptyStatement: expressionStatement  */
#line 139 "parser.y"
                                    { Print("- R: expressionStatement -> statementListItem"); }
#line 2483 "parser.tab.cpp"
    break;

  case 19: /* statementListItemWithoutEmptyStatement: varStatement  */
#line 140 "parser.y"
                                    { Print("- R: varStatement -> statementListItem"); }
#line 2489 "parser.tab.cpp"
    break;

  case 20: /* statementListItemWithoutEmptyStatement: ifStatement  */
#line 141 "parser.y"
                                    { Print("- R: ifStatement -> statementListItem"); }
#line 2495 "parser.tab.cpp"
    break;

  case 21: /* statementListItemWithoutEmptyStatement: switchStatement  */
#line 142 "parser.y"
                                    { Print("- R: switchStatement -> statementListItem"); }
#line 2501 "parser.tab.cpp"
    break;

  case 22: /* statementListItemWithoutEmptyStatement: iterationStatement  */
#line 143 "parser.y"
                                    { Print("- R: iterationStatement -> statementListItem"); }
#line 2507 "parser.tab.cpp"
    break;

  case 23: /* statementListItemWithoutEmptyStatement: continueStatement  */
#line 145 "parser.y"
        {
            if ( !isInIterationBody ) { 
                yyerror("illegal continue statement."); YYERROR;
            } 
            Print("- R: continueStatement -> statementListItem");
        }
#line 2518 "parser.tab.cpp"
    break;

  case 24: /* statementListItemWithoutEmptyStatement: breakStatement  */
#line 152 "parser.y"
        {
            if ( !isInIterationBody ) { 
                yyerror("illegal break statement."); YYERROR;
            } 
            Print("- R: breakStatement -> statementListItem");
        }
#line 2529 "parser.tab.cpp"
    break;

  case 25: /* statementListItemWithoutEmptyStatement: returnStatement  */
#line 159 "parser.y"
        { 
            if ( !isInFunctionBody ) { 
                yyerror("illegal return statement."); YYERROR;
            } 
            Print("- R: returnStatement -> statementListItem"); 
        }
#line 2540 "parser.tab.cpp"
    break;

  case 26: /* statementListItemWithoutEmptyStatement: labelledStatement  */
#line 165 "parser.y"
                                    { Print("- R: labelledStatement -> statementListItem"); }
#line 2546 "parser.tab.cpp"
    break;

  case 27: /* statementListItemWithoutEmptyStatement: blockStatement  */
#line 166 "parser.y"
                                    { Print("- R: blockStatement -> statementListItem"); }
#line 2552 "parser.tab.cpp"
    break;

  case 28: /* statementListItemWithoutEmptyStatement: functionDeclaration  */
#line 167 "parser.y"
                                    { Print("- R: functionDeclaration -> statementListItem"); }
#line 2558 "parser.tab.cpp"
    break;

  case 29: /* statementListItemWithoutEmptyStatement: classDeclaration  */
#line 168 "parser.y"
                                    { Print("- R: classDeclaration -> statementListItem"); }
#line 2564 "parser.tab.cpp"
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
#line 2576 "parser.tab.cpp"
    break;

  case 31: /* initializer: '=' singleExpression  */
#line 183 "parser.y"
                           { Print("- R: '=' singleExpression -> initializer"); }
#line 2582 "parser.tab.cpp"
    break;

  case 32: /* type: unionOrIntersectionOrPrimaryType  */
#line 189 "parser.y"
                                       { Print("- R: unionOrIntersectionOrPrimaryType -> type"); }
#line 2588 "parser.tab.cpp"
    break;

  case 33: /* type: '|' unionOrIntersectionOrPrimaryType  */
#line 190 "parser.y"
                                           { Print("- R: '|' unionOrIntersectionOrPrimaryType -> type"); }
#line 2594 "parser.tab.cpp"
    break;

  case 34: /* type: '&' unionOrIntersectionOrPrimaryType  */
#line 191 "parser.y"
                                           { Print("- R: '&' unionOrIntersectionOrPrimaryType -> type"); }
#line 2600 "parser.tab.cpp"
    break;

  case 35: /* unionOrIntersectionOrPrimaryType: unionOrIntersectionOrPrimaryType '|' unionOrIntersectionOrPrimaryType  */
#line 195 "parser.y"
                                                                            { Print("- R: unionOrIntersectionOrPrimaryType '|' unionOrIntersectionOrPrimaryType -> unionOrIntersectionOrPrimaryType"); }
#line 2606 "parser.tab.cpp"
    break;

  case 36: /* unionOrIntersectionOrPrimaryType: unionOrIntersectionOrPrimaryType '&' unionOrIntersectionOrPrimaryType  */
#line 196 "parser.y"
                                                                            { Print("- R: unionOrIntersectionOrPrimaryType '&' unionOrIntersectionOrPrimaryType -> unionOrIntersectionOrPrimaryType"); }
#line 2612 "parser.tab.cpp"
    break;

  case 37: /* unionOrIntersectionOrPrimaryType: primaryType  */
#line 197 "parser.y"
                  { Print("- R: primaryType -> argument"); }
#line 2618 "parser.tab.cpp"
    break;

  case 38: /* primaryType: '(' type ')'  */
#line 201 "parser.y"
                   { Print("- R: '(' type ')' -> primaryType"); }
#line 2624 "parser.tab.cpp"
    break;

  case 39: /* primaryType: predefinedType  */
#line 202 "parser.y"
                     { Print("- R: predefinedType -> primaryType"); }
#line 2630 "parser.tab.cpp"
    break;

  case 40: /* primaryType: primaryType '[' ']'  */
#line 203 "parser.y"
                          { Print("- R: primaryType '[' ']' -> primaryType"); }
#line 2636 "parser.tab.cpp"
    break;

  case 41: /* primaryType: primaryType '[' primaryType ']'  */
#line 204 "parser.y"
                                      { Print("- R: primaryType '[' primaryType ']' -> primaryType"); }
#line 2642 "parser.tab.cpp"
    break;

  case 42: /* primaryType: '[' tupleTypeElements ']'  */
#line 205 "parser.y"
                                { Print("- R: '[' tupleTypeElements ']' -> primaryType"); }
#line 2648 "parser.tab.cpp"
    break;

  case 43: /* primaryType: ENDL_BRACKET_OPEN tupleTypeElements ']'  */
#line 206 "parser.y"
                                              { Print("- R: '[' tupleTypeElements ']' -> primaryType"); }
#line 2654 "parser.tab.cpp"
    break;

  case 44: /* tupleTypeElements: %empty  */
#line 210 "parser.y"
                  { Print("- R: #empty# -> tupleTypeElements"); }
#line 2660 "parser.tab.cpp"
    break;

  case 45: /* tupleTypeElements: type  */
#line 211 "parser.y"
           { Print("- R: type -> tupleTypeElements"); }
#line 2666 "parser.tab.cpp"
    break;

  case 46: /* tupleTypeElements: tupleTypeElements ',' type  */
#line 212 "parser.y"
                                 { Print("- R: tupleTypeElements ',' type -> tupleTypeElements"); }
#line 2672 "parser.tab.cpp"
    break;

  case 47: /* predefinedType: ANY  */
#line 216 "parser.y"
          { Print("- R: ANY -> predefinedType"); }
#line 2678 "parser.tab.cpp"
    break;

  case 48: /* predefinedType: NUMBER  */
#line 217 "parser.y"
             { Print("- R: NUMBER -> predefinedType"); }
#line 2684 "parser.tab.cpp"
    break;

  case 49: /* predefinedType: STRING  */
#line 218 "parser.y"
             { Print("- R: STRING -> predefinedType"); }
#line 2690 "parser.tab.cpp"
    break;

  case 50: /* predefinedType: BOOLEAN  */
#line 219 "parser.y"
              { Print("- R: BOOLEAN -> predefinedType"); }
#line 2696 "parser.tab.cpp"
    break;

  case 51: /* predefinedType: NEVER  */
#line 220 "parser.y"
            { Print("- R: NEVER -> predefinedType"); }
#line 2702 "parser.tab.cpp"
    break;

  case 52: /* predefinedType: UNKNOWN  */
#line 221 "parser.y"
              { Print("- R: UNKNOWN -> predefinedType"); }
#line 2708 "parser.tab.cpp"
    break;

  case 53: /* predefinedType: UNDEFINED  */
#line 222 "parser.y"
                { Print("- R: UNDEFINED -> predefinedType"); }
#line 2714 "parser.tab.cpp"
    break;

  case 54: /* predefinedType: VOID  */
#line 223 "parser.y"
           { Print("- R: VOID -> predefinedType"); }
#line 2720 "parser.tab.cpp"
    break;

  case 55: /* predefinedType: NULL_KW  */
#line 224 "parser.y"
              { Print("- R: NULL_KW -> predefinedType"); }
#line 2726 "parser.tab.cpp"
    break;

  case 56: /* predefinedType: TRUE_KW  */
#line 225 "parser.y"
              { Print("- R: TRUE_WD -> predefinedType"); }
#line 2732 "parser.tab.cpp"
    break;

  case 57: /* predefinedType: FALSE_KW  */
#line 226 "parser.y"
               { Print("- R: FALSE_KW -> predefinedType"); }
#line 2738 "parser.tab.cpp"
    break;

  case 58: /* predefinedType: simpleLiteral  */
#line 227 "parser.y"
                    { Print("- R: simpleLiteral -> predefinedType"); }
#line 2744 "parser.tab.cpp"
    break;

  case 59: /* typeAnnotation: ':' type  */
#line 231 "parser.y"
               { Print("- R: ':' type -> typeAnnotation"); }
#line 2750 "parser.tab.cpp"
    break;

  case 60: /* simpleLiteral: STRING_LIT  */
#line 235 "parser.y"
                 { Print("- R: STRING_LIT -> simpleLiteral"); }
#line 2756 "parser.tab.cpp"
    break;

  case 61: /* simpleLiteral: INT_LIT  */
#line 236 "parser.y"
              { Print("- R: INT_LIT -> simpleLiteral"); }
#line 2762 "parser.tab.cpp"
    break;

  case 62: /* simpleLiteral: FLOAT_LIT  */
#line 237 "parser.y"
                { Print("- R: FLOAT_LIT -> simpleLiteral"); }
#line 2768 "parser.tab.cpp"
    break;

  case 63: /* simpleLiteral: TEMPLATE_LITERAL  */
#line 238 "parser.y"
                       { Print("- R: TEMPLATE_LITERAL -> simpleLiteral"); }
#line 2774 "parser.tab.cpp"
    break;

  case 64: /* arrayLiteral: '[' elementList ']'  */
#line 243 "parser.y"
                          { Print("- R: [ elementList ']' -> arrayLiteral"); }
#line 2780 "parser.tab.cpp"
    break;

  case 65: /* arrayLiteral: ENDL_BRACKET_OPEN elementList ']'  */
#line 244 "parser.y"
                                        { Print("- R: ENDL_BRACKET_OPEN elementList ']' -> arrayLiteral"); }
#line 2786 "parser.tab.cpp"
    break;

  case 66: /* elementList: %empty  */
#line 248 "parser.y"
                  { Print("- R: #empty# -> elementList"); }
#line 2792 "parser.tab.cpp"
    break;

  case 67: /* elementList: arrayElement  */
#line 249 "parser.y"
                   { Print("- R: arrayElement -> elementList"); }
#line 2798 "parser.tab.cpp"
    break;

  case 68: /* elementList: elementList ',' elementList  */
#line 250 "parser.y"
                                  { Print("- R: elementList ',' elementList -> elementList"); }
#line 2804 "parser.tab.cpp"
    break;

  case 69: /* arrayElement: singleExpression  */
#line 254 "parser.y"
                       { Print("- R: singleExpression -> arrayElement"); }
#line 2810 "parser.tab.cpp"
    break;

  case 70: /* arrayElement: ELLIPSIS singleExpression  */
#line 255 "parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> arrayElement"); }
#line 2816 "parser.tab.cpp"
    break;

  case 71: /* expressionStatement: expressionList ';'  */
#line 261 "parser.y"
                         { Print("- R: expressionList ';' -> expressionStatement"); }
#line 2822 "parser.tab.cpp"
    break;

  case 72: /* expressionListOpt: %empty  */
#line 265 "parser.y"
                  { Print("- R: #empty# -> expressionListOpt"); }
#line 2828 "parser.tab.cpp"
    break;

  case 73: /* expressionListOpt: expressionList  */
#line 266 "parser.y"
                     { Print("- R: expressionList -> expressionListOpt"); }
#line 2834 "parser.tab.cpp"
    break;

  case 74: /* expressionList: singleExpression  */
#line 270 "parser.y"
                       { Print("- R: singleExpression -> expressionList"); }
#line 2840 "parser.tab.cpp"
    break;

  case 75: /* expressionList: expressionList ',' singleExpression  */
#line 271 "parser.y"
                                          { Print("- R: expressionList ',' singleExpression -> expressionList"); }
#line 2846 "parser.tab.cpp"
    break;

  case 76: /* singleExpression: identifier  */
#line 275 "parser.y"
                 { Print("- R: identifier -> singleExpression"); }
#line 2852 "parser.tab.cpp"
    break;

  case 77: /* singleExpression: simpleLiteral  */
#line 276 "parser.y"
                    { Print("- R: simpleLiteral -> singleExpression"); }
#line 2858 "parser.tab.cpp"
    break;

  case 78: /* singleExpression: THIS  */
#line 277 "parser.y"
           { Print("- R: THIS -> singleExpression"); }
#line 2864 "parser.tab.cpp"
    break;

  case 79: /* singleExpression: SUPER  */
#line 278 "parser.y"
            { Print("- R: SUPER -> singleExpression"); }
#line 2870 "parser.tab.cpp"
    break;

  case 80: /* singleExpression: TRUE_KW  */
#line 279 "parser.y"
              { Print("- R: TRUE_LITERAL -> singleExpression"); }
#line 2876 "parser.tab.cpp"
    break;

  case 81: /* singleExpression: FALSE_KW  */
#line 280 "parser.y"
               { Print("- R: FALSE_LITERAL -> singleExpression"); }
#line 2882 "parser.tab.cpp"
    break;

  case 82: /* singleExpression: NULL_KW  */
#line 281 "parser.y"
              { Print("- R: NULL_LITERAL -> singleExpression"); }
#line 2888 "parser.tab.cpp"
    break;

  case 83: /* singleExpression: '-' singleExpression  */
#line 282 "parser.y"
                                        { Print("- R: '-' singleExpression -> singleExpression"); }
#line 2894 "parser.tab.cpp"
    break;

  case 84: /* singleExpression: '+' singleExpression  */
#line 283 "parser.y"
                                       { Print("- R: '+' singleExpression -> singleExpression"); }
#line 2900 "parser.tab.cpp"
    break;

  case 85: /* singleExpression: '!' singleExpression  */
#line 284 "parser.y"
                           { Print("- R: '!' singleExpression -> singleExpression"); }
#line 2906 "parser.tab.cpp"
    break;

  case 86: /* singleExpression: '~' singleExpression  */
#line 285 "parser.y"
                           { Print("- R: '~' singleExpression -> singleExpression"); }
#line 2912 "parser.tab.cpp"
    break;

  case 87: /* singleExpression: singleExpression OPERATOR_INCREMENT  */
#line 286 "parser.y"
                                                               { Print("- R: singleExpression OPERATOR_INCREMENT -> singleExpression"); }
#line 2918 "parser.tab.cpp"
    break;

  case 88: /* singleExpression: singleExpression OPERATOR_DECREMENT  */
#line 287 "parser.y"
                                                               { Print("- R: singleExpression OPERATOR_DECREMENT -> singleExpression"); }
#line 2924 "parser.tab.cpp"
    break;

  case 89: /* singleExpression: ENDL_OPERATOR_INCREMENT singleExpression  */
#line 288 "parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 2930 "parser.tab.cpp"
    break;

  case 90: /* singleExpression: ENDL_OPERATOR_DECREMENT singleExpression  */
#line 289 "parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 2936 "parser.tab.cpp"
    break;

  case 91: /* singleExpression: OPERATOR_INCREMENT singleExpression  */
#line 290 "parser.y"
                                                               { Print("- R: OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 2942 "parser.tab.cpp"
    break;

  case 92: /* singleExpression: OPERATOR_DECREMENT singleExpression  */
#line 291 "parser.y"
                                                               { Print("- R: OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 2948 "parser.tab.cpp"
    break;

  case 93: /* singleExpression: singleExpression '+' singleExpression  */
#line 292 "parser.y"
                                            { Print("- R: singleExpression '+' singleExpression -> singleExpression"); }
#line 2954 "parser.tab.cpp"
    break;

  case 94: /* singleExpression: singleExpression '-' singleExpression  */
#line 293 "parser.y"
                                            { Print("- R: singleExpression '-' singleExpression -> singleExpression"); }
#line 2960 "parser.tab.cpp"
    break;

  case 95: /* singleExpression: singleExpression '*' singleExpression  */
#line 294 "parser.y"
                                            { Print("- R: singleExpression '*' singleExpression -> singleExpression"); }
#line 2966 "parser.tab.cpp"
    break;

  case 96: /* singleExpression: singleExpression '/' singleExpression  */
#line 295 "parser.y"
                                            { Print("- R: singleExpression '/' singleExpression -> singleExpression"); }
#line 2972 "parser.tab.cpp"
    break;

  case 97: /* singleExpression: singleExpression '%' singleExpression  */
#line 296 "parser.y"
                                            { Print("- R: singleExpression '%' singleExpression -> singleExpression"); }
#line 2978 "parser.tab.cpp"
    break;

  case 98: /* singleExpression: singleExpression '<' singleExpression  */
#line 297 "parser.y"
                                            { Print("- R: singleExpression '<' singleExpression -> singleExpression"); }
#line 2984 "parser.tab.cpp"
    break;

  case 99: /* singleExpression: singleExpression '>' singleExpression  */
#line 298 "parser.y"
                                            { Print("- R: singleExpression '>' singleExpression -> singleExpression"); }
#line 2990 "parser.tab.cpp"
    break;

  case 100: /* singleExpression: singleExpression OPERATOR_POWER singleExpression  */
#line 299 "parser.y"
                                                       { Print("- R: singleExpression OPERATOR_POWER singleExpression -> singleExpression"); }
#line 2996 "parser.tab.cpp"
    break;

  case 101: /* singleExpression: singleExpression OPERATOR_EQUAL singleExpression  */
#line 300 "parser.y"
                                                       { Print("- R: singleExpression OPERATOR_EQUAL singleExpression -> singleExpression"); }
#line 3002 "parser.tab.cpp"
    break;

  case 102: /* singleExpression: singleExpression OPERATOR_NOT_EQUAL singleExpression  */
#line 301 "parser.y"
                                                           { Print("- R: singleExpression OPERATOR_NOT_EQUAL singleExpression -> singleExpression"); }
#line 3008 "parser.tab.cpp"
    break;

  case 103: /* singleExpression: singleExpression OPERATOR_STRICT_EQUAL singleExpression  */
#line 302 "parser.y"
                                                              { Print("- R: singleExpression OPERATOR_STRICT_EQUAL singleExpression -> singleExpression"); }
#line 3014 "parser.tab.cpp"
    break;

  case 104: /* singleExpression: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression  */
#line 303 "parser.y"
                                                                  { Print("- R: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression -> singleExpression"); }
#line 3020 "parser.tab.cpp"
    break;

  case 105: /* singleExpression: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression  */
#line 304 "parser.y"
                                                                 { Print("- R: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression -> singleExpression"); }
#line 3026 "parser.tab.cpp"
    break;

  case 106: /* singleExpression: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression  */
#line 305 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression -> singleExpression"); }
#line 3032 "parser.tab.cpp"
    break;

  case 107: /* singleExpression: singleExpression '=' singleExpression  */
#line 306 "parser.y"
                                            { Print("- R: singleExpression '=' singleExpression -> singleExpression"); }
#line 3038 "parser.tab.cpp"
    break;

  case 108: /* singleExpression: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression  */
#line 307 "parser.y"
                                                                 { Print("- R: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression -> singleExpression"); }
#line 3044 "parser.tab.cpp"
    break;

  case 109: /* singleExpression: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression  */
#line 308 "parser.y"
                                                               { Print("- R: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression -> singleExpression"); }
#line 3050 "parser.tab.cpp"
    break;

  case 110: /* singleExpression: singleExpression OPERATOR_ASSIGN_MOD singleExpression  */
#line 309 "parser.y"
                                                            { Print("- R: singleExpression OPERATOR_ASSIGN_MOD singleExpression -> singleExpression"); }
#line 3056 "parser.tab.cpp"
    break;

  case 111: /* singleExpression: singleExpression OPERATOR_ASSIGN_PLUS singleExpression  */
#line 310 "parser.y"
                                                             { Print("- R: singleExpression OPERATOR_ASSIGN_PLUS singleExpression -> singleExpression"); }
#line 3062 "parser.tab.cpp"
    break;

  case 112: /* singleExpression: singleExpression OPERATOR_ASSIGN_MINUS singleExpression  */
#line 311 "parser.y"
                                                              { Print("- R: singleExpression OPERATOR_ASSIGN_MINUS singleExpression -> singleExpression"); }
#line 3068 "parser.tab.cpp"
    break;

  case 113: /* singleExpression: singleExpression OPERATOR_ASSIGN_SHIFT_LEFT singleExpression  */
#line 312 "parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_SHIFT_LEFT singleExpression -> singleExpression"); }
#line 3074 "parser.tab.cpp"
    break;

  case 114: /* singleExpression: singleExpression OPERATOR_ASSIGN_SHIFT_RIGHT singleExpression  */
#line 313 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3080 "parser.tab.cpp"
    break;

  case 115: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_AND singleExpression  */
#line 314 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_AND singleExpression -> singleExpression"); }
#line 3086 "parser.tab.cpp"
    break;

  case 116: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_XOR singleExpression  */
#line 315 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_XOR singleExpression -> singleExpression"); }
#line 3092 "parser.tab.cpp"
    break;

  case 117: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_OR singleExpression  */
#line 316 "parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_OR singleExpression -> singleExpression"); }
#line 3098 "parser.tab.cpp"
    break;

  case 118: /* singleExpression: singleExpression OPERATOR_ASSIGN_POWER singleExpression  */
#line 317 "parser.y"
                                                              { Print("- R: singleExpression OPERATOR_ASSIGN_POWER singleExpression -> singleExpression"); }
#line 3104 "parser.tab.cpp"
    break;

  case 119: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression  */
#line 318 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression -> singleExpression"); }
#line 3110 "parser.tab.cpp"
    break;

  case 120: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression  */
#line 319 "parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression -> singleExpression"); }
#line 3116 "parser.tab.cpp"
    break;

  case 121: /* singleExpression: singleExpression OPERATOR_ASSIGN_NULLISH_COALESCING singleExpression  */
#line 320 "parser.y"
                                                                           { Print("- R: singleExpression OPERATOR_ASSIGN_NULLISH_COALESCING singleExpression -> singleExpression"); }
#line 3122 "parser.tab.cpp"
    break;

  case 122: /* singleExpression: singleExpression OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT singleExpression  */
#line 321 "parser.y"
                                                                             { Print("- R: singleExpression OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3128 "parser.tab.cpp"
    break;

  case 123: /* singleExpression: singleExpression OPERATOR_LOGICAL_OR singleExpression  */
#line 322 "parser.y"
                                                            { Print("- R: singleExpression OPERATOR_LOGICAL_OR singleExpression -> singleExpression"); }
#line 3134 "parser.tab.cpp"
    break;

  case 124: /* singleExpression: singleExpression OPERATOR_LOGICAL_AND singleExpression  */
#line 323 "parser.y"
                                                             { Print("- R: singleExpression OPERATOR_LOGICAL_AND singleExpression -> singleExpression"); }
#line 3140 "parser.tab.cpp"
    break;

  case 125: /* singleExpression: singleExpression '|' singleExpression  */
#line 324 "parser.y"
                                            { Print("- R: singleExpression '|' singleExpression -> singleExpression"); }
#line 3146 "parser.tab.cpp"
    break;

  case 126: /* singleExpression: singleExpression '^' singleExpression  */
#line 325 "parser.y"
                                            { Print("- R: singleExpression '^' singleExpression -> singleExpression"); }
#line 3152 "parser.tab.cpp"
    break;

  case 127: /* singleExpression: singleExpression '&' singleExpression  */
#line 326 "parser.y"
                                            { Print("- R: singleExpression '&' singleExpression -> singleExpression"); }
#line 3158 "parser.tab.cpp"
    break;

  case 128: /* singleExpression: singleExpression OPERATOR_SHIFT_LEFT singleExpression  */
#line 327 "parser.y"
                                                            { Print("- R: singleExpression OPERATOR_SHIFT_LEFT singleExpression -> singleExpression"); }
#line 3164 "parser.tab.cpp"
    break;

  case 129: /* singleExpression: singleExpression OPERATOR_SHIFT_RIGHT singleExpression  */
#line 328 "parser.y"
                                                             { Print("- R: singleExpression OPERATOR_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3170 "parser.tab.cpp"
    break;

  case 130: /* singleExpression: singleExpression OPERATOR_UNSIGNED_SHIFT_RIGHT singleExpression  */
#line 329 "parser.y"
                                                                      { Print("- R: singleExpression OPERATOR_UNSIGNED_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3176 "parser.tab.cpp"
    break;

  case 131: /* singleExpression: singleExpression OPERATOR_NULLISH_COALESCING singleExpression  */
#line 330 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_NULLISH_COALESCING singleExpression -> singleExpression"); }
#line 3182 "parser.tab.cpp"
    break;

  case 132: /* singleExpression: singleExpression INSTANCEOF singleExpression  */
#line 332 "parser.y"
                                                   { Print("- R: singleExpression INSTANCEOF singleExpression -> singleExpression"); }
#line 3188 "parser.tab.cpp"
    break;

  case 133: /* singleExpression: singleExpression IN singleExpression  */
#line 333 "parser.y"
                                           { Print("- R: singleExpression IN singleExpression -> singleExpression"); }
#line 3194 "parser.tab.cpp"
    break;

  case 134: /* singleExpression: singleExpression TEMPLATE_LITERAL  */
#line 335 "parser.y"
                                        { Print("- R: singleExpression TEMPLATE_LITERAL -> singleExpression"); }
#line 3200 "parser.tab.cpp"
    break;

  case 135: /* singleExpression: singleExpression '?' singleExpression ':' singleExpression  */
#line 336 "parser.y"
                                                                 { Print("- R: singleExpression '?' singleExpression ':' singleExpression -> singleExpression"); }
#line 3206 "parser.tab.cpp"
    break;

  case 136: /* singleExpression: '(' expressionList ')'  */
#line 338 "parser.y"
                             { Print("- R: '(' expressionList ')' -> singleExpression"); }
#line 3212 "parser.tab.cpp"
    break;

  case 137: /* singleExpression: singleExpression arguments  */
#line 340 "parser.y"
                                 { Print("- R: singleExpression arguments -> singleExpression"); }
#line 3218 "parser.tab.cpp"
    break;

  case 138: /* singleExpression: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression  */
#line 342 "parser.y"
                                                                   { Print("- R: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression -> singleExpression"); }
#line 3224 "parser.tab.cpp"
    break;

  case 139: /* singleExpression: singleExpression '.' identifier  */
#line 343 "parser.y"
                                      { Print("- R: singleExpression '.' identifier -> singleExpression"); }
#line 3230 "parser.tab.cpp"
    break;

  case 140: /* singleExpression: arrayLiteral  */
#line 345 "parser.y"
                   { Print("- R: arrayLiteral -> singleExpression"); }
#line 3236 "parser.tab.cpp"
    break;

  case 141: /* singleExpression: singleExpression '[' expressionList ']'  */
#line 346 "parser.y"
                                              { Print("- R: singleExpression '[' expressionList ']' -> singleExpression"); }
#line 3242 "parser.tab.cpp"
    break;

  case 142: /* singleExpression: singleExpression ENDL_BRACKET_OPEN expressionList ']'  */
#line 347 "parser.y"
                                                            { Print("- R: singleExpression ENDL_BRACKET_OPEN expressionList ']' -> singleExpression"); }
#line 3248 "parser.tab.cpp"
    break;

  case 143: /* singleExpression: NEW singleExpression  */
#line 349 "parser.y"
                           { Print("- R: NEW singleExpression -> singleExpression"); }
#line 3254 "parser.tab.cpp"
    break;

  case 144: /* arguments: '(' ')'  */
#line 353 "parser.y"
              { Print("- R: '(' ')' -> arguments"); }
#line 3260 "parser.tab.cpp"
    break;

  case 145: /* arguments: '(' argumentList ')'  */
#line 354 "parser.y"
                           { Print("- R: '(' argumentList ')' -> arguments"); }
#line 3266 "parser.tab.cpp"
    break;

  case 146: /* arguments: '(' argumentList ',' ')'  */
#line 355 "parser.y"
                               { Print("- R: '(' argumentList ',' ') -> arguments"); }
#line 3272 "parser.tab.cpp"
    break;

  case 147: /* argumentList: argument  */
#line 359 "parser.y"
               { Print("- R: argument -> argumentList"); }
#line 3278 "parser.tab.cpp"
    break;

  case 148: /* argumentList: argumentList ',' arguments  */
#line 360 "parser.y"
                                 { Print("- R: argumentList ',' arguments -> argumentList"); }
#line 3284 "parser.tab.cpp"
    break;

  case 149: /* argument: singleExpression  */
#line 364 "parser.y"
                       { Print("- R: singleExpression -> argument"); }
#line 3290 "parser.tab.cpp"
    break;

  case 150: /* argument: ELLIPSIS singleExpression  */
#line 365 "parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> argument"); }
#line 3296 "parser.tab.cpp"
    break;

  case 151: /* varStatement: varModifier varDeclarationList ';'  */
#line 371 "parser.y"
                                         { Print("- R: varModifier varDeclarationList ';' -> varStatement"); }
#line 3302 "parser.tab.cpp"
    break;

  case 152: /* varDeclarationList: varDeclaration  */
#line 375 "parser.y"
                     { Print("- R: varDeclaration -> argument"); }
#line 3308 "parser.tab.cpp"
    break;

  case 153: /* varDeclarationList: varDeclarationList ',' varDeclaration  */
#line 376 "parser.y"
                                            { Print("- R: varDeclarationList ',' varDeclaration -> varDeclarationList"); }
#line 3314 "parser.tab.cpp"
    break;

  case 154: /* varDeclaration: identifier  */
#line 380 "parser.y"
                 { Print("- R: identifier -> varDeclaration"); }
#line 3320 "parser.tab.cpp"
    break;

  case 155: /* varDeclaration: identifier typeAnnotation  */
#line 381 "parser.y"
                                { Print("- R: identifier typeAnnotation -> varDeclaration"); }
#line 3326 "parser.tab.cpp"
    break;

  case 156: /* varDeclaration: identifier '=' singleExpression  */
#line 382 "parser.y"
                                      { Print("- R: identifier '=' singleExpression -> varDeclaration"); }
#line 3332 "parser.tab.cpp"
    break;

  case 157: /* varDeclaration: identifier typeAnnotation '=' singleExpression  */
#line 383 "parser.y"
                                                     { Print("- R: identifier typeAnnotation '=' singleExpression -> varDeclaration"); }
#line 3338 "parser.tab.cpp"
    break;

  case 158: /* varModifier: VAR  */
#line 387 "parser.y"
          { Print("- R: VAR -> varModifier"); }
#line 3344 "parser.tab.cpp"
    break;

  case 159: /* varModifier: LET  */
#line 388 "parser.y"
          { Print("- R: LET -> varModifier"); }
#line 3350 "parser.tab.cpp"
    break;

  case 160: /* varModifier: CONST  */
#line 389 "parser.y"
            { Print("- R: CONST -> varModifier"); }
#line 3356 "parser.tab.cpp"
    break;

  case 161: /* ifStatement: IF '(' expressionList ')' statementListItemWithoutEmptyStatement  */
#line 395 "parser.y"
                                                                                          { Print("- R: IF '(' expressionList ')' statementListItem -> ifStatement"); }
#line 3362 "parser.tab.cpp"
    break;

  case 162: /* ifStatement: IF '(' expressionList ')' statementListItemWithoutEmptyStatement ELSE statementListItem  */
#line 396 "parser.y"
                                                                                              { Print("- R: IF '(' expressionList ')' statementListItem ELSE statementListItem -> ifStatement"); }
#line 3368 "parser.tab.cpp"
    break;

  case 163: /* $@1: %empty  */
#line 400 "parser.y"
         { isInIterationBody = 1; }
#line 3374 "parser.tab.cpp"
    break;

  case 164: /* $@2: %empty  */
#line 400 "parser.y"
                                                                                   { doWhileASI(); }
#line 3380 "parser.tab.cpp"
    break;

  case 165: /* iterationStatement: DO $@1 statementListItem WHILE '(' expressionList ')' $@2 ';'  */
#line 400 "parser.y"
                                                                                                                                   { isInIterationBody = 0; Print("- R: DO statementListItem WHILE '(' expressionList ')' ';' -> iterationStatement"); }
#line 3386 "parser.tab.cpp"
    break;

  case 166: /* $@3: %empty  */
#line 401 "parser.y"
                                   { isInIterationBody = 1; }
#line 3392 "parser.tab.cpp"
    break;

  case 167: /* iterationStatement: WHILE '(' expressionList ')' $@3 statementListItem  */
#line 401 "parser.y"
                                                                                                                                            { isInIterationBody = 0; Print("- R: WHILE '(' expressionList ')' statementListItem -> iterationStatement"); }
#line 3398 "parser.tab.cpp"
    break;

  case 168: /* $@4: %empty  */
#line 402 "parser.y"
                                                                                  { isInForHeader = 0; isInIterationBody = 1; }
#line 3404 "parser.tab.cpp"
    break;

  case 169: /* iterationStatement: forHeader expressionListOpt ';' expressionListOpt ';' expressionListOpt ')' $@4 statementListItem  */
#line 402 "parser.y"
                                                                                                                                                                 { isInIterationBody = 0; Print("- R: FOR '(' expressionListOpt ';' expressionListOpt ';' expressionListOpt ')' statementListItem -> iterationStatement"); }
#line 3410 "parser.tab.cpp"
    break;

  case 170: /* $@5: %empty  */
#line 403 "parser.y"
                                                                                               { isInForHeader = 0; isInIterationBody = 1; }
#line 3416 "parser.tab.cpp"
    break;

  case 171: /* iterationStatement: forHeader varModifier varDeclarationList ';' expressionListOpt ';' expressionListOpt ')' $@5 statementListItem  */
#line 403 "parser.y"
                                                                                                                                                                 { isInIterationBody = 0; Print("- R: FOR '(' varModifier varDeclarationList ';' expressionListOpt ';' expressionListOpt ')' statementListItem -> iterationStatement"); }
#line 3422 "parser.tab.cpp"
    break;

  case 172: /* $@6: %empty  */
#line 404 "parser.y"
                                                         { isInForHeader = 0; isInIterationBody = 1; }
#line 3428 "parser.tab.cpp"
    break;

  case 173: /* iterationStatement: forHeader singleExpression IN singleExpression ')' $@6 statementListItem  */
#line 404 "parser.y"
                                                                                                                                                                 { isInIterationBody = 0; Print("- R: FOR '(' singleExpression IN singleExpression ')' statementListItem -> iterationStatement"); }
#line 3434 "parser.tab.cpp"
    break;

  case 174: /* $@7: %empty  */
#line 405 "parser.y"
                                                                 { isInForHeader = 0; isInIterationBody = 1; }
#line 3440 "parser.tab.cpp"
    break;

  case 175: /* iterationStatement: forHeader varModifier varDeclaration IN expressionList ')' $@7 statementListItem  */
#line 405 "parser.y"
                                                                                                                                                                 { isInIterationBody = 0; Print("- R: FOR '(' varModifier varDeclaration IN expressionList ')' statementListItem -> iterationStatement"); }
#line 3446 "parser.tab.cpp"
    break;

  case 176: /* forHeader: FOR '('  */
#line 409 "parser.y"
               { isInForHeader = 1; }
#line 3452 "parser.tab.cpp"
    break;

  case 177: /* continueStatement: CONTINUE ';'  */
#line 413 "parser.y"
                   { Print("- R: CONTINUE ';' -> returnStatement"); }
#line 3458 "parser.tab.cpp"
    break;

  case 178: /* continueStatement: CONTINUE identifier ';'  */
#line 414 "parser.y"
                              { Print("- R: CONTINUE identifier ';' -> returnStatement"); }
#line 3464 "parser.tab.cpp"
    break;

  case 179: /* breakStatement: BREAK ';'  */
#line 418 "parser.y"
                 { Print("- R: BREAK ';' -> returnStatement"); }
#line 3470 "parser.tab.cpp"
    break;

  case 180: /* breakStatement: BREAK identifier ';'  */
#line 419 "parser.y"
                           { Print("- R: BREAK identifier ';' -> returnStatement"); }
#line 3476 "parser.tab.cpp"
    break;

  case 181: /* returnStatement: RETURN ';'  */
#line 423 "parser.y"
                 { Print("- R: RETURN ';' -> returnStatement"); }
#line 3482 "parser.tab.cpp"
    break;

  case 182: /* returnStatement: RETURN singleExpression ';'  */
#line 424 "parser.y"
                                  { Print("- R: RETURN singleExpression ';' -> returnStatement"); }
#line 3488 "parser.tab.cpp"
    break;

  case 183: /* labelledStatement: identifier ':' statementListItem  */
#line 428 "parser.y"
                                       { Print("- R: identifier ':' statementListItem -> labelledStatement"); }
#line 3494 "parser.tab.cpp"
    break;

  case 184: /* blockStatement: '{' '}'  */
#line 432 "parser.y"
              { Print("- R: '{' '}' -> blockStatement"); }
#line 3500 "parser.tab.cpp"
    break;

  case 185: /* blockStatement: '{' statementList '}'  */
#line 433 "parser.y"
                            { Print("- R: '{' statementList '}' -> blockStatement"); }
#line 3506 "parser.tab.cpp"
    break;

  case 186: /* switchStatement: SWITCH '(' expressionList ')' '{' '}'  */
#line 437 "parser.y"
                                            { Print("- R: SWITCH '(' expressionList ')' '{' '}' -> switchStatement"); }
#line 3512 "parser.tab.cpp"
    break;

  case 187: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList '}'  */
#line 438 "parser.y"
                                                           { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList '}' -> switchStatement"); }
#line 3518 "parser.tab.cpp"
    break;

  case 188: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause '}'  */
#line 439 "parser.y"
                                                                         { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause '}' -> switchStatement"); }
#line 3524 "parser.tab.cpp"
    break;

  case 189: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause caseClauseList '}'  */
#line 440 "parser.y"
                                                                                        { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause caseClauseList '}' -> switchStatement"); }
#line 3530 "parser.tab.cpp"
    break;

  case 190: /* caseClauseList: caseClause  */
#line 444 "parser.y"
                 { Print("- R: caseClause -> caseClauseList"); }
#line 3536 "parser.tab.cpp"
    break;

  case 191: /* caseClauseList: caseClauseList caseClause  */
#line 445 "parser.y"
                                { Print("- R: caseClauseList caseClause -> caseClauseList"); }
#line 3542 "parser.tab.cpp"
    break;

  case 192: /* caseClause: CASE expressionList ':'  */
#line 449 "parser.y"
                              { Print("- R: CASE expressionList ':' -> caseClause"); }
#line 3548 "parser.tab.cpp"
    break;

  case 193: /* caseClause: CASE expressionList ':' statementList  */
#line 450 "parser.y"
                                            { Print("- R: CASE expressionList ':' statementList -> caseClause"); }
#line 3554 "parser.tab.cpp"
    break;

  case 194: /* defaultClause: DEFAULT ':'  */
#line 454 "parser.y"
                  { Print("- R: DEFAULT ':' -> defaultClause"); }
#line 3560 "parser.tab.cpp"
    break;

  case 195: /* defaultClause: DEFAULT ':' statementList  */
#line 455 "parser.y"
                                { Print("- R: DEFAULT ':' statementList -> defaultClause"); }
#line 3566 "parser.tab.cpp"
    break;

  case 196: /* functionDeclaration: FUNCTION identifier callSignature functionBody  */
#line 461 "parser.y"
                                                     { Print("- R: FUNCTION ID callSignature functionBody -> functionDeclaration"); }
#line 3572 "parser.tab.cpp"
    break;

  case 197: /* functionBody: '{' '}'  */
#line 465 "parser.y"
              { Print("- R: '{' '}' -> functionBody"); }
#line 3578 "parser.tab.cpp"
    break;

  case 198: /* $@8: %empty  */
#line 466 "parser.y"
          { isInFunctionBody = 1; }
#line 3584 "parser.tab.cpp"
    break;

  case 199: /* functionBody: '{' $@8 statementList '}'  */
#line 466 "parser.y"
                                                      { isInFunctionBody = 0; Print("- R: '{' statementList '}' -> functionBody"); }
#line 3590 "parser.tab.cpp"
    break;

  case 200: /* callSignature: '(' parameterList ')'  */
#line 470 "parser.y"
                            { Print("- R: '(' restParameter ')' -> callSignature"); }
#line 3596 "parser.tab.cpp"
    break;

  case 201: /* callSignature: '(' parameterList ')' typeAnnotation  */
#line 471 "parser.y"
                                           { Print("- R: '(' restParameter ')' typeAnnotation -> callSignature"); }
#line 3602 "parser.tab.cpp"
    break;

  case 202: /* parameterList: %empty  */
#line 475 "parser.y"
                  { Print("- R: #empty# -> parameterList"); }
#line 3608 "parser.tab.cpp"
    break;

  case 203: /* parameterList: requiredParameterList  */
#line 476 "parser.y"
                            { Print("- R: requiredParameterList -> parameterList"); }
#line 3614 "parser.tab.cpp"
    break;

  case 204: /* parameterList: optionalParameterList  */
#line 477 "parser.y"
                            { Print("- R: optionalParameterList -> parameterList"); }
#line 3620 "parser.tab.cpp"
    break;

  case 205: /* parameterList: restParameter  */
#line 478 "parser.y"
                    { Print("- R: restParameter -> parameterList"); }
#line 3626 "parser.tab.cpp"
    break;

  case 206: /* parameterList: requiredParameterList ',' optionalParameterList  */
#line 480 "parser.y"
                                                      { Print("- R: requiredParameterList ',' optionalParameterList -> parameterList"); }
#line 3632 "parser.tab.cpp"
    break;

  case 207: /* parameterList: requiredParameterList ',' restParameter  */
#line 481 "parser.y"
                                              { Print("- R: requiredParameterList ',' restParameter -> parameterList"); }
#line 3638 "parser.tab.cpp"
    break;

  case 208: /* parameterList: optionalParameterList ',' restParameter  */
#line 482 "parser.y"
                                              { Print("- R: optionalParameterList ',' restParameter -> parameterList"); }
#line 3644 "parser.tab.cpp"
    break;

  case 209: /* parameterList: requiredParameterList ',' optionalParameterList ',' restParameter  */
#line 484 "parser.y"
                                                                        { Print("- R: requiredParameterList ',' optionalParameterList ',' restParameter -> parameterList"); }
#line 3650 "parser.tab.cpp"
    break;

  case 210: /* parameterList: requiredParameterList ','  */
#line 486 "parser.y"
                                { Print("- R: requiredParameterList ',' -> parameterList"); }
#line 3656 "parser.tab.cpp"
    break;

  case 211: /* parameterList: optionalParameterList ','  */
#line 487 "parser.y"
                                { Print("- R: optionalParameterList ',' -> parameterList"); }
#line 3662 "parser.tab.cpp"
    break;

  case 212: /* parameterList: restParameter ','  */
#line 488 "parser.y"
                        { Print("- R: restParameter ',' -> parameterList"); }
#line 3668 "parser.tab.cpp"
    break;

  case 213: /* parameterList: requiredParameterList ',' optionalParameterList ','  */
#line 490 "parser.y"
                                                          { Print("- R: requiredParameterList ',' optionalParameterList ',' -> parameterList"); }
#line 3674 "parser.tab.cpp"
    break;

  case 214: /* parameterList: requiredParameterList ',' restParameter ','  */
#line 491 "parser.y"
                                                  { Print("- R: requiredParameterList ',' restParameter ',' -> parameterList"); }
#line 3680 "parser.tab.cpp"
    break;

  case 215: /* parameterList: optionalParameterList ',' restParameter ','  */
#line 492 "parser.y"
                                                  { Print("- R: optionalParameterList ',' restParameter ',' -> parameterList"); }
#line 3686 "parser.tab.cpp"
    break;

  case 216: /* parameterList: requiredParameterList ',' optionalParameterList ',' restParameter ','  */
#line 494 "parser.y"
                                                                            { Print("- R: requiredParameterList ',' optionalParameterList ',' restParameter ',' -> parameterList"); }
#line 3692 "parser.tab.cpp"
    break;

  case 217: /* requiredParameterList: requiredParameter  */
#line 498 "parser.y"
                        { Print("- R: requiredParameter -> requiredParameterList"); }
#line 3698 "parser.tab.cpp"
    break;

  case 218: /* requiredParameterList: requiredParameterList ',' requiredParameter  */
#line 499 "parser.y"
                                                  { Print("- R:  requiredParameterList ',' requiredParameter -> requiredParameterList"); }
#line 3704 "parser.tab.cpp"
    break;

  case 219: /* optionalParameterList: optionalParameter  */
#line 503 "parser.y"
                        { Print("- R: optionalParameter -> optionalParameterList"); }
#line 3710 "parser.tab.cpp"
    break;

  case 220: /* optionalParameterList: optionalParameterList ',' optionalParameter  */
#line 504 "parser.y"
                                                  { Print("- R: optionalParameterList ',' optionalParameter -> optionalParameterList"); }
#line 3716 "parser.tab.cpp"
    break;

  case 221: /* requiredParameter: identifier  */
#line 508 "parser.y"
                 { Print("- R: ID -> requiredParameter"); }
#line 3722 "parser.tab.cpp"
    break;

  case 222: /* requiredParameter: identifier typeAnnotation  */
#line 509 "parser.y"
                                { Print("- R: ID typeAnnotation -> requiredParameter"); }
#line 3728 "parser.tab.cpp"
    break;

  case 223: /* optionalParameter: identifier '?'  */
#line 513 "parser.y"
                     { Print("- R: ID '?' -> optionalParameter"); }
#line 3734 "parser.tab.cpp"
    break;

  case 224: /* optionalParameter: identifier '?' typeAnnotation  */
#line 514 "parser.y"
                                    { Print("- R: ID '?' typeAnnotation -> optionalParameter"); }
#line 3740 "parser.tab.cpp"
    break;

  case 225: /* optionalParameter: identifier initializer  */
#line 515 "parser.y"
                             { Print("- R: ID initializer -> optionalParameter"); }
#line 3746 "parser.tab.cpp"
    break;

  case 226: /* optionalParameter: identifier typeAnnotation initializer  */
#line 516 "parser.y"
                                            { Print("- R: ID typeAnnotation initializer -> optionalParameter"); }
#line 3752 "parser.tab.cpp"
    break;

  case 227: /* restParameter: ELLIPSIS singleExpression  */
#line 520 "parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> restParameter"); }
#line 3758 "parser.tab.cpp"
    break;

  case 228: /* restParameter: ELLIPSIS singleExpression typeAnnotation  */
#line 521 "parser.y"
                                               { Print("- R: ELLIPSIS singleExpression typeAnnotation -> restParameter"); }
#line 3764 "parser.tab.cpp"
    break;

  case 229: /* classDeclaration: CLASS identifier classTail  */
#line 527 "parser.y"
                                 { Print("- R: CLASS identifier classTail -> classDeclaration"); }
#line 3770 "parser.tab.cpp"
    break;

  case 230: /* classDeclaration: CLASS identifier classHeritage classTail  */
#line 528 "parser.y"
                                               { Print("- R: CLASS identifier classHeritage classTail -> classDeclaration"); }
#line 3776 "parser.tab.cpp"
    break;

  case 231: /* classHeritage: EXTENDS identifier  */
#line 532 "parser.y"
                         { Print("- R: EXTENDS identifier -> classHeritage"); }
#line 3782 "parser.tab.cpp"
    break;

  case 232: /* classTail: '{' '}'  */
#line 536 "parser.y"
              { Print("- R: '{' '}' -> classTail"); }
#line 3788 "parser.tab.cpp"
    break;

  case 233: /* classTail: '{' classElementList '}'  */
#line 537 "parser.y"
                               { Print("- R: '{' classElementList '}' -> classTail"); }
#line 3794 "parser.tab.cpp"
    break;

  case 234: /* classElementList: classElement  */
#line 541 "parser.y"
                   { Print("- R: classElement -> classElementList"); }
#line 3800 "parser.tab.cpp"
    break;

  case 235: /* classElementList: classElementList classElement  */
#line 542 "parser.y"
                                    { Print("- R: classElementList classElement -> classElementList"); }
#line 3806 "parser.tab.cpp"
    break;

  case 236: /* classElement: CONSTRUCTOR constructorCallSignature functionBody  */
#line 546 "parser.y"
                                                        { Print("- R: CONSTRUCTOR callSignature functionBody -> classElement"); }
#line 3812 "parser.tab.cpp"
    break;

  case 237: /* classElement: propertyName ';'  */
#line 549 "parser.y"
                       { Print("- R: propertyName ';' -> classElement"); }
#line 3818 "parser.tab.cpp"
    break;

  case 238: /* classElement: propertyName typeAnnotation ';'  */
#line 550 "parser.y"
                                      { Print("- R: propertyName typeAnnotation ';' -> classElement"); }
#line 3824 "parser.tab.cpp"
    break;

  case 239: /* classElement: propertyName initializer ';'  */
#line 551 "parser.y"
                                   { Print("- R: propertyName initializer ';' -> classElement"); }
#line 3830 "parser.tab.cpp"
    break;

  case 240: /* classElement: propertyName typeAnnotation initializer ';'  */
#line 552 "parser.y"
                                                  { Print("- R: propertyName typeAnnotation initializer ';' -> classElement"); }
#line 3836 "parser.tab.cpp"
    break;

  case 241: /* classElement: propertyName callSignature functionBody  */
#line 555 "parser.y"
                                              { Print("- R: propertyName callSignature functionBody -> classElement"); }
#line 3842 "parser.tab.cpp"
    break;

  case 242: /* classElement: GET propertyName '(' ')' functionBody  */
#line 558 "parser.y"
                                            { Print("- R: GET propertyName '(' ')' functionBody -> classElement"); }
#line 3848 "parser.tab.cpp"
    break;

  case 243: /* classElement: GET propertyName '(' ')' typeAnnotation functionBody  */
#line 559 "parser.y"
                                                           { Print("- R: GET propertyName '(' ')' typeAnnotation functionBody -> classElement"); }
#line 3854 "parser.tab.cpp"
    break;

  case 244: /* classElement: SET propertyName callSignature functionBody  */
#line 560 "parser.y"
                                                  { Print("- R: SET propertyName callSignature functionBody -> classElement"); }
#line 3860 "parser.tab.cpp"
    break;

  case 245: /* constructorCallSignature: '(' parameterList ')'  */
#line 564 "parser.y"
                            { Print("- R: '(' parameterList ')' -> constructorCallSignature"); }
#line 3866 "parser.tab.cpp"
    break;

  case 246: /* propertyName: identifier  */
#line 568 "parser.y"
                 { Print("- R: identifier -> propertyName"); }
#line 3872 "parser.tab.cpp"
    break;

  case 247: /* propertyName: simpleLiteral  */
#line 569 "parser.y"
                    { Print("- R: STRING_LIT -> propertyName"); }
#line 3878 "parser.tab.cpp"
    break;

  case 248: /* propertyName: '[' simpleLiteral ']'  */
#line 570 "parser.y"
                            { Print("- R: '[' simpleLiteral ']' -> propertyName"); }
#line 3884 "parser.tab.cpp"
    break;

  case 249: /* propertyName: ENDL_BRACKET_OPEN simpleLiteral ']'  */
#line 571 "parser.y"
                                          { Print("- R: ENDL_BRACKET_OPEN simpleLiteral ']' -> propertyName"); }
#line 3890 "parser.tab.cpp"
    break;

  case 250: /* identifier: ID  */
#line 575 "parser.y"
         { Print("- R: ID -> identifier"); }
#line 3896 "parser.tab.cpp"
    break;

  case 251: /* identifier: ASYNC  */
#line 576 "parser.y"
            { Print("- R: ASYNC -> identifier"); }
#line 3902 "parser.tab.cpp"
    break;

  case 252: /* identifier: AS  */
#line 577 "parser.y"
         { Print("- R: AS -> identifier"); }
#line 3908 "parser.tab.cpp"
    break;

  case 253: /* identifier: FROM  */
#line 578 "parser.y"
           { Print("- R: FROM -> identifier"); }
#line 3914 "parser.tab.cpp"
    break;

  case 254: /* identifier: YIELD  */
#line 579 "parser.y"
            { Print("- R: YIELD -> identifier"); }
#line 3920 "parser.tab.cpp"
    break;

  case 255: /* identifier: ANY  */
#line 580 "parser.y"
          { Print("- R: ANY -> identifier"); }
#line 3926 "parser.tab.cpp"
    break;

  case 256: /* identifier: NUMBER  */
#line 581 "parser.y"
             { Print("- R: NUMBER -> identifier"); }
#line 3932 "parser.tab.cpp"
    break;

  case 257: /* identifier: BOOLEAN  */
#line 582 "parser.y"
              { Print("- R: BOOLEAN -> identifier"); }
#line 3938 "parser.tab.cpp"
    break;

  case 258: /* identifier: STRING  */
#line 583 "parser.y"
             { Print("- R: STRING -> identifier"); }
#line 3944 "parser.tab.cpp"
    break;

  case 259: /* identifier: UNIQUE  */
#line 584 "parser.y"
             { Print("- R: UNIQUE -> identifier"); }
#line 3950 "parser.tab.cpp"
    break;

  case 260: /* identifier: SYMBOL  */
#line 585 "parser.y"
             { Print("- R: SYMBOL -> identifier"); }
#line 3956 "parser.tab.cpp"
    break;

  case 261: /* identifier: NEVER  */
#line 586 "parser.y"
            { Print("- R: NEVER -> identifier"); }
#line 3962 "parser.tab.cpp"
    break;

  case 262: /* identifier: UNDEFINED  */
#line 587 "parser.y"
                { Print("- R: UNDEFINED -> identifier"); }
#line 3968 "parser.tab.cpp"
    break;

  case 263: /* identifier: OBJECT  */
#line 588 "parser.y"
             { Print("- R: OBJECT -> identifier"); }
#line 3974 "parser.tab.cpp"
    break;

  case 264: /* identifier: KEYOF  */
#line 589 "parser.y"
            { Print("- R: KEYOF -> identifier"); }
#line 3980 "parser.tab.cpp"
    break;

  case 265: /* identifier: NAMESPACE  */
#line 590 "parser.y"
                { Print("- R: NAMESPACE -> identifier"); }
#line 3986 "parser.tab.cpp"
    break;

  case 266: /* identifier: ABSTRACT  */
#line 591 "parser.y"
               { Print("- R: ABSTRACT -> identifier"); }
#line 3992 "parser.tab.cpp"
    break;

  case 267: /* identifier: REQUIRE  */
#line 592 "parser.y"
              { Print("- R: REQUIRE -> identifier"); }
#line 3998 "parser.tab.cpp"
    break;


#line 4002 "parser.tab.cpp"

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

#line 595 "parser.y"



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


