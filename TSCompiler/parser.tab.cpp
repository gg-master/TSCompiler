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
  YYSYMBOL_127_1 = 127,                    /* $@1  */
  YYSYMBOL_128_2 = 128,                    /* $@2  */
  YYSYMBOL_129_3 = 129,                    /* $@3  */
  YYSYMBOL_statementListItemWithoutEmptyStatement = 130, /* statementListItemWithoutEmptyStatement  */
  YYSYMBOL_131_4 = 131,                    /* $@4  */
  YYSYMBOL_132_5 = 132,                    /* $@5  */
  YYSYMBOL_133_6 = 133,                    /* $@6  */
  YYSYMBOL_statementSep = 134,             /* statementSep  */
  YYSYMBOL_initializer = 135,              /* initializer  */
  YYSYMBOL_type = 136,                     /* type  */
  YYSYMBOL_unionOrIntersectionOrPrimaryType = 137, /* unionOrIntersectionOrPrimaryType  */
  YYSYMBOL_primaryType = 138,              /* primaryType  */
  YYSYMBOL_tupleTypeElements = 139,        /* tupleTypeElements  */
  YYSYMBOL_predefinedType = 140,           /* predefinedType  */
  YYSYMBOL_typeAnnotation = 141,           /* typeAnnotation  */
  YYSYMBOL_arrayLiteral = 142,             /* arrayLiteral  */
  YYSYMBOL_elementList = 143,              /* elementList  */
  YYSYMBOL_arrayElement = 144,             /* arrayElement  */
  YYSYMBOL_expressionListOpt = 145,        /* expressionListOpt  */
  YYSYMBOL_expressionList = 146,           /* expressionList  */
  YYSYMBOL_singleExpression = 147,         /* singleExpression  */
  YYSYMBOL_arguments = 148,                /* arguments  */
  YYSYMBOL_argumentList = 149,             /* argumentList  */
  YYSYMBOL_argument = 150,                 /* argument  */
  YYSYMBOL_varStatement = 151,             /* varStatement  */
  YYSYMBOL_varDeclarationList = 152,       /* varDeclarationList  */
  YYSYMBOL_varDeclaration = 153,           /* varDeclaration  */
  YYSYMBOL_varModifier = 154,              /* varModifier  */
  YYSYMBOL_ifStatement = 155,              /* ifStatement  */
  YYSYMBOL_iterationStatement = 156,       /* iterationStatement  */
  YYSYMBOL_157_7 = 157,                    /* $@7  */
  YYSYMBOL_158_8 = 158,                    /* $@8  */
  YYSYMBOL_159_9 = 159,                    /* $@9  */
  YYSYMBOL_160_10 = 160,                   /* $@10  */
  YYSYMBOL_161_11 = 161,                   /* $@11  */
  YYSYMBOL_162_12 = 162,                   /* $@12  */
  YYSYMBOL_163_13 = 163,                   /* $@13  */
  YYSYMBOL_forHeader = 164,                /* forHeader  */
  YYSYMBOL_continueStatement = 165,        /* continueStatement  */
  YYSYMBOL_breakStatement = 166,           /* breakStatement  */
  YYSYMBOL_returnStatement = 167,          /* returnStatement  */
  YYSYMBOL_labelledStatement = 168,        /* labelledStatement  */
  YYSYMBOL_blockStatement = 169,           /* blockStatement  */
  YYSYMBOL_switchStatement = 170,          /* switchStatement  */
  YYSYMBOL_caseClauseList = 171,           /* caseClauseList  */
  YYSYMBOL_caseClause = 172,               /* caseClause  */
  YYSYMBOL_defaultClause = 173,            /* defaultClause  */
  YYSYMBOL_functionDeclaration = 174,      /* functionDeclaration  */
  YYSYMBOL_functionBody = 175,             /* functionBody  */
  YYSYMBOL_176_14 = 176,                   /* $@14  */
  YYSYMBOL_callSignature = 177,            /* callSignature  */
  YYSYMBOL_parameterList = 178,            /* parameterList  */
  YYSYMBOL_parameter = 179,                /* parameter  */
  YYSYMBOL_requiredParameter = 180,        /* requiredParameter  */
  YYSYMBOL_optionalParameter = 181,        /* optionalParameter  */
  YYSYMBOL_restParameter = 182,            /* restParameter  */
  YYSYMBOL_classDeclaration = 183,         /* classDeclaration  */
  YYSYMBOL_classHeritage = 184,            /* classHeritage  */
  YYSYMBOL_classTail = 185,                /* classTail  */
  YYSYMBOL_classElementList = 186,         /* classElementList  */
  YYSYMBOL_classElement = 187,             /* classElement  */
  YYSYMBOL_propertyName = 188,             /* propertyName  */
  YYSYMBOL_identifier = 189                /* identifier  */
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
#define YYFINAL  105
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2561

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  123
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  269
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  457

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
       0,    89,    89,    99,   100,   104,   105,   106,   113,   114,
     115,   116,   117,   118,   118,   123,   123,   128,   128,   133,
     134,   135,   136,   140,   141,   142,   143,   144,   145,   146,
     147,   147,   152,   152,   157,   157,   162,   163,   164,   165,
     169,   173,   179,   180,   181,   185,   186,   187,   191,   192,
     193,   194,   195,   199,   200,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   221,
     226,   227,   231,   232,   233,   237,   238,   244,   245,   249,
     250,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     314,   315,   317,   318,   320,   322,   324,   325,   327,   328,
     329,   331,   335,   336,   337,   341,   342,   346,   347,   353,
     357,   358,   362,   363,   364,   365,   369,   370,   371,   377,
     378,   382,   382,   382,   383,   383,   384,   384,   385,   385,
     386,   386,   387,   387,   391,   395,   396,   400,   401,   405,
     406,   410,   414,   415,   419,   420,   421,   422,   426,   427,
     431,   432,   436,   437,   443,   447,   448,   448,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   465,   466,
     470,   471,   475,   476,   480,   481,   482,   483,   487,   488,
     494,   495,   499,   503,   504,   508,   509,   513,   516,   517,
     518,   519,   522,   525,   526,   527,   531,   532,   533,   534,
     535,   536,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   553,   554,   555,   556,   557
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
  "statementListItem", "$@1", "$@2", "$@3",
  "statementListItemWithoutEmptyStatement", "$@4", "$@5", "$@6",
  "statementSep", "initializer", "type",
  "unionOrIntersectionOrPrimaryType", "primaryType", "tupleTypeElements",
  "predefinedType", "typeAnnotation", "arrayLiteral", "elementList",
  "arrayElement", "expressionListOpt", "expressionList",
  "singleExpression", "arguments", "argumentList", "argument",
  "varStatement", "varDeclarationList", "varDeclaration", "varModifier",
  "ifStatement", "iterationStatement", "$@7", "$@8", "$@9", "$@10", "$@11",
  "$@12", "$@13", "forHeader", "continueStatement", "breakStatement",
  "returnStatement", "labelledStatement", "blockStatement",
  "switchStatement", "caseClauseList", "caseClause", "defaultClause",
  "functionDeclaration", "functionBody", "$@14", "callSignature",
  "parameterList", "parameter", "requiredParameter", "optionalParameter",
  "restParameter", "classDeclaration", "classHeritage", "classTail",
  "classElementList", "classElement", "propertyName", "identifier", YY_NULLPTR
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

#define YYTABLE_NINF (-204)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1524,   -68,  -369,  -369,  -369,   -62,  1678,  1678,  -369,   -47,
     -46,  1678,  1678,   -40,  1923,  -369,  -369,  1923,  -369,  -369,
    -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,
    -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,
    -369,  -369,  -369,  1923,  1923,  1923,  1923,  1923,  1923,  1923,
    1923,  1885,  1885,  1923,  -369,  1036,    62,  1159,  -369,  -369,
     -44,  2322,   -38,  1678,  -369,  -369,  1749,  -369,  -369,  -369,
    -369,  -369,  -369,  -369,  -369,    48,  -369,  1923,   -34,    -2,
    1524,  1923,  -369,  -369,  -369,  1923,  2322,  -369,    36,    36,
      36,    36,    36,    36,    36,    36,    36,  1923,   -10,  -369,
    2322,    -7,   -24,  -369,  1280,  -369,  -369,  1923,  -369,  -369,
    -369,  -369,  -369,  1923,  1923,  1923,  1923,  1923,  1923,  1923,
    1923,  1923,  1923,  1923,  1923,  1923,  1923,  1923,  1923,  1923,
    1923,  1923,  1923,  1923,  1923,  1923,  1923,  1923,  1923,  1923,
    1923,  1923,  1923,  1923,  1923,  1923,  1923,  1923,  1923,  1923,
    1923,  1923,  1923,  1923,  1923,  1678,  1923,  1923,  1923,  1787,
    -369,  -369,     8,  -369,     2,    10,    72,  2386,  1678,   -38,
     -38,   -38,  1524,   -22,   310,    15,  1678,   189,    16,  -369,
     124,   -21,   -20,  2322,  1885,  -369,  -369,  -369,  -369,  2322,
    2443,  2443,  2443,  2443,  2443,  2443,  2443,  2443,  2443,  2443,
    2443,  2443,  2443,  2443,  2443,  2443,  2066,   893,  1014,  1136,
    1256,  1377,  1498,   490,   490,   490,   490,   184,   184,   184,
     184,   184,   184,   317,   317,   317,   346,   346,   252,   252,
     252,   252,  -369,     5,     9,    33,  1923,  -369,  2322,   -18,
    -369,  1678,  1923,   209,    94,  1923,  1923,   -35,    64,  -369,
    -369,  -369,  -369,  1645,  1923,    85,   -17,  -369,  -369,  -369,
      46,    53,    45,  -369,  -369,   155,   155,   -34,  -369,  -369,
    -369,  1923,  1923,  -369,   616,  -369,   -32,  -369,  -369,    51,
    -369,    49,  -369,  1923,  -369,  -369,  2322,   -60,  -369,  -369,
    2322,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,
    -369,  -369,  -369,  -369,  -369,  2006,  2006,   209,   209,  -369,
     -52,    52,  -369,  1923,    55,    44,  1923,  1923,    58,   166,
     -44,   -38,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,
    -369,  -369,  2130,  -369,   718,    85,    85,  1923,    85,  -369,
     118,  -369,  1524,    69,   -34,    15,  2194,  2258,  -369,  -369,
    -369,    87,   -33,    15,  1923,  1524,    -1,   772,  -369,  -369,
     -52,   -52,  -369,    14,    86,  2006,  2006,  1968,  2322,  1923,
    -369,    89,   -16,  -369,  1524,  -369,  -369,   -38,   -38,   -38,
    -369,    85,  -369,    91,  -369,  -369,  2322,  -369,  -369,  1402,
      92,    15,  -369,  -369,  -369,  -369,  -369,    93,  -369,    -8,
    -369,  1923,  -369,     1,  -369,   209,  -369,  -369,   127,  -369,
    -369,   -54,    96,  1524,  1923,  -369,  -369,  -369,  -369,  -369,
    -369,    85,  -369,    13,  -369,  -369,  -369,     4,   156,  -369,
    -369,     3,  -369,  -369,  -369,  -369,   115,  1524,  -369,    15,
    -369,   -38,   518,   792,  -369,     6,  1524,  -369,  -369,  -369,
    -369,   670,   914,  -369,  -369,  1524,  -369
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     5,   166,   167,   168,     0,     0,     0,   171,     0,
       0,   185,   187,     0,   189,    83,    82,     0,   253,   254,
     255,   256,   266,   267,   268,   269,   257,   258,   259,   260,
     263,   264,   261,   262,   265,    86,    84,    85,    90,    88,
      89,   252,    87,     0,     0,     0,     0,     0,     0,     0,
       0,    72,    72,     0,     7,     0,     0,     0,     3,   148,
       0,    79,     0,     0,    10,    12,    77,    13,    15,    17,
      19,    20,    11,    21,    22,    81,     6,     0,     0,     0,
       0,     0,   184,   186,   188,     0,   190,    81,   151,    99,
     100,    97,    98,    92,    91,    93,    94,     0,     0,    73,
      75,     0,     0,   192,     0,     1,     4,     0,    40,     8,
     142,    95,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     145,     9,   159,   160,   162,     0,    78,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   230,
       0,     0,     0,    76,    72,    70,    71,   144,   193,    80,
     115,   119,   120,   126,   116,   117,   118,   121,   122,   130,
     123,   124,   125,   127,   128,   129,     0,   139,   131,   132,
     133,   134,   135,   109,   110,   111,   112,   107,   106,   114,
     113,   140,   141,   136,   137,   138,   101,   102,   103,   104,
     105,   108,   147,     0,     0,   146,     0,   152,   157,     0,
     155,     0,     0,     0,   163,    77,     0,     0,   160,    14,
      16,    18,   191,     0,     0,   208,     0,   218,   220,   221,
       0,   222,   206,   204,   232,     0,     0,     0,   247,   248,
     249,     0,     0,   233,     0,   235,     0,   246,   231,     0,
     174,     0,    74,     0,   149,   150,   158,     0,   153,   161,
     164,    55,    56,    58,    57,    59,    61,    62,    60,    68,
      64,    65,    63,    66,    67,     0,     0,     0,     0,    69,
      42,    47,    49,     0,     0,   141,    77,     0,    23,   169,
       0,     0,    27,    29,    30,    32,    34,    36,    37,    28,
      38,    39,   228,   209,     0,   212,   210,     0,   224,   226,
     223,   205,     0,     0,     0,     0,     0,     0,   234,   236,
     238,     0,     0,     0,     0,     0,     0,   143,   154,   156,
      43,    44,    53,     0,     0,     0,     0,     0,   165,    77,
     180,     0,     0,    24,     0,    25,    26,     0,     0,     0,
     229,   216,   219,     0,   213,   211,    41,   225,   227,     0,
       0,     0,   237,   250,   251,   240,   239,     0,   242,     0,
     175,     0,   194,     0,   198,     0,    52,    48,    45,    46,
      50,     0,     0,     0,    77,   182,   170,    31,    33,    35,
     217,   214,   207,     0,   245,   241,   172,     0,     0,   195,
     199,     0,    54,    51,   176,   181,     0,     0,   215,     0,
     243,     0,     0,     0,   196,     0,     0,   178,   183,   244,
     173,     0,     0,   197,   177,     0,   179
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -369,  -369,   -51,   -56,  -369,  -369,  -369,  -369,  -369,  -369,
    -369,   -57,  -261,  -298,  -256,  -128,  -369,  -369,  -242,  -369,
     -49,  -369,  -243,   -39,   359,   -43,  -369,  -369,   -13,    75,
    -152,   185,    17,    19,  -369,  -369,  -369,  -369,  -369,  -369,
    -369,  -369,    20,    22,    23,    26,    37,    40,  -179,  -368,
    -369,    42,  -317,  -369,  -244,  -369,   -72,  -369,  -369,   -67,
      43,  -369,    90,  -369,    30,  -198,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    56,    57,    58,   169,   170,   171,   319,   377,   378,
     379,   109,   339,   309,   310,   311,   363,   312,   244,    59,
      98,    99,   165,    60,    61,   160,   239,   240,    62,   162,
     163,    63,    64,    65,    80,   441,   355,   446,   455,   413,
     437,    66,    67,    68,    69,    70,    71,    72,   403,   404,
     431,    73,   263,   342,   175,   256,   257,   258,   259,   260,
      74,   178,   179,   274,   275,   276,    87
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      75,   106,   314,   101,   104,   161,    78,    79,   176,   362,
     364,    83,    84,   333,   102,   351,   248,   107,   401,   340,
     401,   428,   401,   345,   180,   401,   241,   166,   392,   337,
     337,   365,   353,   366,   352,   430,   398,   107,   173,   107,
     107,   107,   181,   287,   334,   107,   182,   243,   106,   360,
     361,   184,    76,   107,   184,    75,    77,    75,   159,   358,
     367,   433,   105,   164,   242,   107,   107,   343,   344,   241,
     107,    81,    82,   371,   424,   405,   108,   430,    85,   388,
      75,   243,   108,   442,   174,   316,   174,   396,   350,   289,
     380,   397,   243,   384,   385,   187,   387,   253,   280,   281,
     391,   288,   335,   415,    75,   185,   440,   432,   186,   408,
     409,   426,   249,   250,   251,   337,   252,   233,   234,   177,
     284,   402,   449,   429,   285,   444,   412,   172,   453,   406,
     245,   338,   243,   107,   262,   282,   262,   177,   279,   420,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   159,   157,   158,   159,   232,   313,   155,   156,   317,
     157,   158,   159,   370,   243,   336,   367,   341,   164,   354,
     356,   436,    75,   374,   261,   369,   264,   277,   373,   438,
     337,   439,    18,    19,    20,    21,    22,   390,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
     265,   266,   268,   269,   270,   407,   166,   395,    41,   414,
     421,   423,   366,   425,   320,   434,    18,    19,    20,    21,
      22,   267,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,   447,   443,   268,   269,   270,   411,
     321,   164,    41,   247,   359,   291,   292,   293,   294,   295,
     296,   168,   445,    75,   297,   298,   299,   300,   301,   302,
     303,   304,   382,   375,   376,   277,   277,   383,   278,   271,
     322,   272,   323,   324,   277,   325,   326,   166,   372,   327,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
     328,   389,   305,   329,   306,   330,   331,   155,   156,   400,
     157,   158,   159,   271,   349,   272,     0,     0,     0,     0,
       0,   273,     0,     0,     0,   399,     0,     0,   416,     0,
     417,   418,   419,   307,     0,     0,     0,   308,     0,     0,
     166,     0,     0,   106,   261,   254,     0,    18,    19,    20,
      21,    22,    75,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    75,   154,   435,     0,     0,
       0,     0,   427,    41,     0,   155,   156,     0,   157,   158,
     159,     0,     0,    86,    75,   166,    88,     0,     0,     0,
       0,   448,     0,     0,   450,     0,     0,     0,     0,    75,
     454,   451,   452,     0,     0,   106,   106,     0,     0,   456,
       0,     0,    89,    90,    91,    92,    93,    94,    95,    96,
     100,   100,     0,    75,     0,     0,   149,   150,   151,   152,
     153,   154,     0,     0,     0,   167,     0,     0,     0,   255,
     155,   156,     0,   157,   158,   159,     0,    75,     0,     0,
       0,     0,    75,    75,     0,     0,    75,   151,   152,   153,
     154,    75,    75,     0,     0,    75,   183,     0,     0,   155,
     156,     0,   157,   158,   159,     0,   189,     0,     0,     0,
       0,     0,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,     0,     0,     0,   235,   238,     1,
       0,     2,     3,     4,     5,     0,     6,     7,     0,     0,
       0,     8,     9,    10,    11,    12,    13,  -200,  -200,    14,
      15,    16,    17,   100,     0,    18,    19,    20,    21,    22,
       0,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     0,     0,    35,    36,    37,    38,    39,
      40,    41,     0,    42,    43,    44,    45,    46,     0,     0,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   286,     0,     0,     0,     0,
       0,   290,     0,   155,   156,   315,   157,   158,   159,     0,
       0,     0,     0,   332,     0,     0,     0,    47,    48,     0,
       0,     0,     0,    49,    50,     0,     0,   265,   266,     0,
     346,   347,    51,     0,    52,     0,    53,     0,    54,    55,
    -200,     0,   357,    18,    19,    20,    21,    22,   267,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,     0,     0,   268,   269,   270,     0,     0,     0,    41,
       0,     1,   368,     2,     3,     4,     5,     0,     6,     7,
       0,     0,     0,     8,     9,    10,    11,    12,    13,  -201,
    -201,    14,    15,    16,    17,     0,   386,    18,    19,    20,
      21,    22,     0,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,     0,     0,    35,    36,    37,
      38,    39,    40,    41,     0,    42,    43,    44,    45,    46,
     271,     0,   272,     0,     0,     0,     0,     0,   348,     0,
       0,     0,     0,   254,     0,    18,    19,    20,    21,    22,
       0,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     0,     0,     0,     0,     0,     0,    47,
      48,    41,     0,     0,     0,    49,    50,     0,     0,     0,
       0,     0,     0,     0,    51,     0,    52,     0,    53,     0,
      54,    55,  -201,     1,     0,     2,     3,     4,     5,     0,
       6,     7,     0,     0,     0,     8,     9,    10,    11,    12,
      13,  -202,     0,    14,    15,    16,    17,     0,     0,    18,
      19,    20,    21,    22,     0,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,   381,     0,    35,
      36,    37,    38,    39,    40,    41,     0,    42,    43,    44,
      45,    46,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     0,     0,     0,
       0,     0,     0,     0,     0,   155,   156,     0,   157,   158,
     159,    47,    48,     0,     0,     0,     0,    49,    50,     0,
       0,     0,     0,     0,     0,     0,    51,     0,    52,     0,
      53,     0,    54,    55,  -202,     1,     0,     2,     3,     4,
       5,     0,     6,     7,     0,     0,     0,     8,     9,    10,
      11,    12,    13,  -203,     0,    14,    15,    16,    17,     0,
       0,    18,    19,    20,    21,    22,     0,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     0,
       0,    35,    36,    37,    38,    39,    40,    41,     0,    42,
      43,    44,    45,    46,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,     0,     0,
       0,     0,     0,     0,     0,     0,   155,   156,     0,   157,
     158,   159,     0,    47,    48,     0,     0,     0,     0,    49,
      50,     0,     0,     0,     0,     0,     0,     0,    51,     0,
      52,     0,    53,     0,    54,    55,  -203,     1,     0,     2,
       3,     4,     5,     0,     6,     7,     0,     0,     0,     8,
       9,    10,    11,    12,    13,     0,     0,    14,    15,    16,
      17,     0,     0,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,     0,     0,    35,    36,    37,    38,    39,    40,    41,
       0,    42,    43,    44,    45,    46,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
       0,     0,     0,     0,     0,     0,     0,   155,   156,     0,
     157,   158,   159,     0,     0,    47,    48,     0,     0,     0,
       0,    49,    50,     0,     0,     0,     0,     0,     0,     0,
      51,     0,    52,     0,    53,     0,    54,    55,   103,    -2,
       1,     0,     2,     3,     4,     5,     0,     6,     7,     0,
       0,     0,     8,     9,    10,    11,    12,    13,     0,     0,
      14,    15,    16,    17,     0,     0,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,     0,    35,    36,    37,    38,
      39,    40,    41,     0,    42,    43,    44,    45,    46,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,     0,     0,     0,     0,     0,     0,     0,   155,
     156,     0,   157,   158,   159,     0,     0,     0,    47,    48,
       0,     0,     0,     0,    49,    50,     0,     0,     0,     0,
       0,     0,     0,    51,     0,    52,     0,    53,     0,    54,
      55,     1,     0,     2,     3,     4,     5,     0,     6,     7,
       0,     0,     0,     8,     9,    10,    11,    12,    13,     0,
       0,    14,    15,    16,    17,     0,     0,    18,    19,    20,
      21,    22,     0,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,     0,     0,    35,    36,    37,
      38,    39,    40,    41,     0,    42,    43,    44,    45,    46,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,     0,     0,     0,     0,     0,     0,     0,   155,
     156,     0,   157,   158,   159,     0,     0,     0,     0,    47,
      48,     0,     0,     0,     0,    49,    50,     0,     0,     0,
       0,     0,     0,     0,    51,     0,    52,     0,    53,     0,
      54,    55,   188,     1,     0,     2,     3,     4,     5,     0,
       6,     7,     0,     0,     0,     8,     9,    10,    11,    12,
      13,     0,     0,    14,    15,    16,    17,     0,     0,    18,
      19,    20,    21,    22,     0,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     0,     0,    35,
      36,    37,    38,    39,    40,    41,     0,    42,    43,    44,
      45,    46,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,     0,     0,     0,     0,     0,     0,     0,     0,
     155,   156,     0,   157,   158,   159,     0,     0,     0,     0,
       0,    47,    48,     0,     0,     0,     0,    49,    50,     0,
       0,     0,     0,     0,     0,     0,    51,     0,    52,     0,
      53,     0,    54,    55,   422,     1,     0,     2,     3,     4,
       5,     0,     6,     7,     0,     0,     0,     8,     9,    10,
      11,    12,    13,     0,     0,    14,    15,    16,    17,     0,
       0,    18,    19,    20,    21,    22,     0,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     0,
       0,    35,    36,    37,    38,    39,    40,    41,     0,    42,
      43,    44,    45,    46,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,     0,     0,     0,     0,     0,     0,
       0,   155,   156,     0,   157,   158,   159,     0,     0,     0,
       0,     0,     0,    47,    48,     0,     0,     0,     0,    49,
      50,     0,     0,     0,     0,     0,     0,     0,    51,     0,
      52,     0,    53,     0,    54,    55,   318,     0,     2,     3,
       4,     5,     0,     6,     7,     0,     0,     0,     8,     9,
      10,    11,    12,    13,     0,     0,    14,    15,    16,    17,
       0,     0,    18,    19,    20,    21,    22,     0,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       0,     0,    35,    36,    37,    38,    39,    40,    41,     0,
      42,    43,    44,    45,    46,    18,    19,    20,    21,    22,
       0,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     0,     0,     0,     0,     0,     0,     0,
       0,    41,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,    48,     0,     0,     0,     0,
      49,    50,     2,     3,     4,     0,     0,     0,     0,    51,
       0,    52,     0,    53,     0,     0,    55,     0,     0,     0,
       0,    15,    16,    17,     0,     0,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,     0,    35,    36,    37,    38,
      39,    40,    41,     0,    42,    43,    44,    45,    46,    15,
      16,    17,   236,     0,    18,    19,    20,    21,    22,     0,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     0,     0,    35,    36,    37,    38,    39,    40,
      41,     0,    42,    43,    44,    45,    46,     0,    47,    48,
       0,     0,     0,     0,    49,    50,     0,     0,     0,     0,
       0,     0,     0,    51,     0,    52,     0,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    47,    48,     0,     0,
       0,     0,    49,    50,     0,     0,     0,     0,     0,     0,
       0,    51,     0,    52,     0,    53,   237,    15,    16,    17,
      97,     0,    18,    19,    20,    21,    22,     0,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       0,     0,    35,    36,    37,    38,    39,    40,    41,     0,
      42,    43,    44,    45,    46,    15,    16,    17,     0,     0,
      18,    19,    20,    21,    22,     0,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,     0,     0,
      35,    36,    37,    38,    39,    40,    41,     0,    42,    43,
      44,    45,    46,     0,    47,    48,     0,     0,     0,     0,
      49,    50,     0,     0,     0,     0,     0,     0,     0,    51,
       0,    52,     0,    53,   291,   292,   293,   294,   295,   296,
       0,     0,     0,   297,   298,   299,   300,   301,   302,   303,
     304,     0,    47,    48,     0,     0,     0,     0,    49,    50,
       0,     0,     0,     0,     0,     0,     0,    51,     0,    52,
       0,    53,   291,   292,   293,   294,   295,   296,     0,     0,
       0,   297,   298,   299,   300,   301,   302,   303,   304,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   307,   410,     0,     0,   308,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     307,   110,   111,   112,   308,     0,     0,     0,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   283,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,     0,     0,     0,     0,     0,     0,     0,   155,
     156,     0,   157,   158,   159,   110,   111,   112,     0,     0,
       0,     0,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   243,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,     0,     0,     0,     0,
       0,     0,     0,   155,   156,     0,   157,   158,   159,   110,
     111,   112,     0,     0,     0,     0,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
       0,     0,     0,     0,     0,     0,     0,   155,   156,   393,
     157,   158,   159,   110,   111,   112,     0,     0,     0,     0,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,     0,     0,     0,     0,     0,     0,
       0,   155,   156,   394,   157,   158,   159,   110,   111,   112,
       0,     0,     0,     0,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     0,     0,     0,
       0,     0,     0,     0,     0,   155,   156,     0,   157,   158,
     159,   110,   111,   112,     0,     0,     0,     0,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   246,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,     0,     0,     0,     0,     0,     0,     0,   155,
     156,     0,   157,   158,   159,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,     0,     0,
       0,     0,     0,     0,     0,     0,   155,   156,     0,   157,
     158,   159
};

static const yytype_int16 yycheck[] =
{
       0,    57,   245,    52,    55,    62,     6,     7,    10,   307,
     308,    11,    12,   255,    53,   276,   168,    61,    19,   261,
      19,    20,    19,   267,    80,    19,    61,    66,   345,    62,
      62,    83,   276,    85,   276,   403,   353,    61,    77,    61,
      61,    61,    81,    61,    61,    61,    85,    79,   104,   305,
     306,    61,   120,    61,    61,    55,   118,    57,   118,   119,
     114,   115,     0,    63,    62,    61,    61,   265,   266,    61,
      61,   118,   118,   316,   391,    61,   120,   445,   118,   340,
      80,    79,   120,    79,   118,   120,   118,   120,   120,   241,
     332,   352,    79,   335,   336,   119,   338,   119,   119,   119,
     344,   119,   119,   119,   104,   115,   423,   405,   115,   365,
     366,   119,   169,   170,   171,    62,   172,   156,   157,   121,
     115,   122,   439,   122,   115,   122,   369,    79,   122,   115,
     120,    78,    79,    61,   121,   184,   121,   121,    14,   381,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   113,
     114,   118,   116,   117,   118,   155,    62,   113,   114,    95,
     116,   117,   118,   119,    79,   119,   114,   122,   168,   118,
     121,   414,   172,     7,   174,   120,   176,   177,   120,   421,
      62,   423,    27,    28,    29,    30,    31,   118,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      11,    12,    47,    48,    49,   119,   245,   120,    53,   120,
     119,   119,    85,   120,   253,   119,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,   119,    79,    47,    48,    49,   367,
     253,   241,    53,   168,   287,    36,    37,    38,    39,    40,
      41,    66,   431,   253,    45,    46,    47,    48,    49,    50,
      51,    52,   334,   320,   321,   265,   266,   334,   178,   114,
     253,   116,   253,   253,   274,   253,   253,   316,   317,   253,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
     253,   342,    83,   253,    85,   253,   253,   113,   114,   355,
     116,   117,   118,   114,   274,   116,    -1,    -1,    -1,    -1,
      -1,   122,    -1,    -1,    -1,   354,    -1,    -1,   374,    -1,
     377,   378,   379,   114,    -1,    -1,    -1,   118,    -1,    -1,
     369,    -1,    -1,   389,   334,    25,    -1,    27,    28,    29,
      30,    31,   342,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,   355,   104,   413,    -1,    -1,
      -1,    -1,   401,    53,    -1,   113,   114,    -1,   116,   117,
     118,    -1,    -1,    14,   374,   414,    17,    -1,    -1,    -1,
      -1,   437,    -1,    -1,   441,    -1,    -1,    -1,    -1,   389,
     446,   442,   443,    -1,    -1,   451,   452,    -1,    -1,   455,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,   413,    -1,    -1,    99,   100,   101,   102,
     103,   104,    -1,    -1,    -1,    66,    -1,    -1,    -1,   119,
     113,   114,    -1,   116,   117,   118,    -1,   437,    -1,    -1,
      -1,    -1,   442,   443,    -1,    -1,   446,   101,   102,   103,
     104,   451,   452,    -1,    -1,   455,    97,    -1,    -1,   113,
     114,    -1,   116,   117,   118,    -1,   107,    -1,    -1,    -1,
      -1,    -1,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,   158,   159,     1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,   184,    -1,    27,    28,    29,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    -1,    -1,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   236,    -1,    -1,    -1,    -1,
      -1,   242,    -1,   113,   114,   246,   116,   117,   118,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    99,   100,    -1,
      -1,    -1,    -1,   105,   106,    -1,    -1,    11,    12,    -1,
     271,   272,   114,    -1,   116,    -1,   118,    -1,   120,   121,
     122,    -1,   283,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    47,    48,    49,    -1,    -1,    -1,    53,
      -1,     1,   313,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,   337,    27,    28,    29,
      30,    31,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
     114,    -1,   116,    -1,    -1,    -1,    -1,    -1,   122,    -1,
      -1,    -1,    -1,    25,    -1,    27,    28,    29,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,    53,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,    -1,   116,    -1,   118,    -1,
     120,   121,   122,     1,    -1,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    13,    14,    15,    16,    17,
      18,    19,    -1,    21,    22,    23,    24,    -1,    -1,    27,
      28,    29,    30,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,   119,    -1,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,   117,
     118,    99,   100,    -1,    -1,    -1,    -1,   105,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,   116,    -1,
     118,    -1,   120,   121,   122,     1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    13,    14,    15,
      16,    17,    18,    19,    -1,    21,    22,    23,    24,    -1,
      -1,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,
     117,   118,    -1,    99,   100,    -1,    -1,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,
     116,    -1,   118,    -1,   120,   121,   122,     1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    13,
      14,    15,    16,    17,    18,    -1,    -1,    21,    22,    23,
      24,    -1,    -1,    27,    28,    29,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,
     116,   117,   118,    -1,    -1,    99,   100,    -1,    -1,    -1,
      -1,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,    -1,   116,    -1,   118,    -1,   120,   121,   122,     0,
       1,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    13,    14,    15,    16,    17,    18,    -1,    -1,
      21,    22,    23,    24,    -1,    -1,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
     114,    -1,   116,   117,   118,    -1,    -1,    -1,    99,   100,
      -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,   116,    -1,   118,    -1,   120,
     121,     1,    -1,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    13,    14,    15,    16,    17,    18,    -1,
      -1,    21,    22,    23,    24,    -1,    -1,    27,    28,    29,
      30,    31,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
     114,    -1,   116,   117,   118,    -1,    -1,    -1,    -1,    99,
     100,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,    -1,   116,    -1,   118,    -1,
     120,   121,   122,     1,    -1,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    13,    14,    15,    16,    17,
      18,    -1,    -1,    21,    22,    23,    24,    -1,    -1,    27,
      28,    29,    30,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   114,    -1,   116,   117,   118,    -1,    -1,    -1,    -1,
      -1,    99,   100,    -1,    -1,    -1,    -1,   105,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,   116,    -1,
     118,    -1,   120,   121,   122,     1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    13,    14,    15,
      16,    17,    18,    -1,    -1,    21,    22,    23,    24,    -1,
      -1,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,   114,    -1,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,
     116,    -1,   118,    -1,   120,   121,     1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    13,    14,
      15,    16,    17,    18,    -1,    -1,    21,    22,    23,    24,
      -1,    -1,    27,    28,    29,    30,    31,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    27,    28,    29,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,
     105,   106,     3,     4,     5,    -1,    -1,    -1,    -1,   114,
      -1,   116,    -1,   118,    -1,    -1,   121,    -1,    -1,    -1,
      -1,    22,    23,    24,    -1,    -1,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    22,
      23,    24,    25,    -1,    27,    28,    29,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    -1,    99,   100,
      -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,   116,    -1,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,
      -1,    -1,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,   116,    -1,   118,   119,    22,    23,    24,
      25,    -1,    27,    28,    29,    30,    31,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    22,    23,    24,    -1,    -1,
      27,    28,    29,    30,    31,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    -1,    99,   100,    -1,    -1,    -1,    -1,
     105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,   116,    -1,   118,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    99,   100,    -1,    -1,    -1,    -1,   105,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,   116,
      -1,   118,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,   115,    -1,    -1,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,    55,    56,    57,   118,    -1,    -1,    -1,    62,    63,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,
     116,   117,   118,    55,    56,    57,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,   114,   115,   116,   117,   118,    55,    56,    57,
      -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    -1,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,   117,
     118,    55,    56,    57,    -1,    -1,    -1,    -1,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    -1,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
     114,    -1,   116,   117,   118,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,
     117,   118
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     8,     9,    13,    14,
      15,    16,    17,    18,    21,    22,    23,    24,    27,    28,
      29,    30,    31,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    47,    48,    49,    50,    51,
      52,    53,    55,    56,    57,    58,    59,    99,   100,   105,
     106,   114,   116,   118,   120,   121,   124,   125,   126,   142,
     146,   147,   151,   154,   155,   156,   164,   165,   166,   167,
     168,   169,   170,   174,   183,   189,   120,   118,   189,   189,
     157,   118,   118,   189,   189,   118,   147,   189,   147,   147,
     147,   147,   147,   147,   147,   147,   147,    25,   143,   144,
     147,   143,   146,   122,   125,     0,   126,    61,   120,   134,
      55,    56,    57,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   113,   114,   116,   117,   118,
     148,   134,   152,   153,   189,   145,   146,   147,   154,   127,
     128,   129,    79,   146,   118,   177,    10,   121,   184,   185,
     126,   146,   146,   147,    61,   115,   115,   119,   122,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   189,   146,   146,   147,    25,   119,   147,   149,
     150,    61,    62,    79,   141,   120,    95,   152,   153,   134,
     134,   134,   126,   119,    25,   119,   178,   179,   180,   181,
     182,   189,   121,   175,   189,    11,    12,    32,    47,    48,
      49,   114,   116,   122,   186,   187,   188,   189,   185,    14,
     119,   119,   143,    79,   115,   115,   147,    61,   119,   153,
     147,    36,    37,    38,    39,    40,    41,    45,    46,    47,
      48,    49,    50,    51,    52,    83,    85,   114,   118,   136,
     137,   138,   140,    62,   145,   147,   120,    95,     1,   130,
     146,   151,   155,   156,   165,   166,   167,   168,   169,   170,
     174,   183,   147,   141,    61,   119,   119,    62,    78,   135,
     141,   122,   176,   188,   188,   177,   147,   147,   122,   187,
     120,   135,   141,   177,   118,   159,   121,   147,   119,   148,
     137,   137,   136,   139,   136,    83,    85,   114,   147,   120,
     119,   145,   146,   120,     7,   134,   134,   131,   132,   133,
     141,   119,   179,   182,   141,   141,   147,   141,   135,   125,
     118,   177,   175,   115,   115,   120,   120,   135,   175,   146,
     126,    19,   122,   171,   172,    61,   115,   119,   137,   137,
     115,   138,   145,   162,   120,   119,   126,   134,   134,   134,
     141,   119,   122,   119,   175,   120,   119,   146,    20,   122,
     172,   173,   136,   115,   119,   126,   145,   163,   141,   141,
     175,   158,    79,    79,   122,   171,   160,   119,   126,   175,
     134,   125,   125,   122,   126,   161,   126
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   123,   124,   125,   125,   126,   126,   126,   126,   126,
     126,   126,   126,   127,   126,   128,   126,   129,   126,   126,
     126,   126,   126,   130,   130,   130,   130,   130,   130,   130,
     131,   130,   132,   130,   133,   130,   130,   130,   130,   130,
     134,   135,   136,   136,   136,   137,   137,   137,   138,   138,
     138,   138,   138,   139,   139,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   141,
     142,   142,   143,   143,   143,   144,   144,   145,   145,   146,
     146,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   148,   148,   148,   149,   149,   150,   150,   151,
     152,   152,   153,   153,   153,   153,   154,   154,   154,   155,
     155,   157,   158,   156,   159,   156,   160,   156,   161,   156,
     162,   156,   163,   156,   164,   165,   165,   166,   166,   167,
     167,   168,   169,   169,   170,   170,   170,   170,   171,   171,
     172,   172,   173,   173,   174,   175,   176,   175,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   178,   178,
     179,   179,   180,   180,   181,   181,   181,   181,   182,   182,
     183,   183,   184,   185,   185,   186,   186,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   188,   188,   188,   188,
     188,   188,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     1,     2,     2,
       1,     1,     1,     0,     3,     0,     3,     0,     3,     1,
       1,     1,     1,     1,     2,     2,     2,     1,     1,     1,
       0,     3,     0,     3,     0,     3,     1,     1,     1,     1,
       1,     2,     1,     2,     2,     3,     3,     1,     3,     1,
       3,     4,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     3,     0,     1,     3,     1,     2,     0,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     5,     3,     2,     3,     3,     1,     4,
       4,     2,     2,     3,     4,     1,     3,     1,     2,     2,
       1,     3,     1,     2,     3,     4,     1,     1,     1,     5,
       7,     0,     0,     9,     0,     6,     0,     9,     0,    10,
       0,     7,     0,     8,     2,     1,     2,     1,     2,     1,
       2,     3,     2,     3,     6,     7,     8,     9,     1,     2,
       3,     4,     2,     3,     4,     2,     0,     4,     2,     3,
       3,     4,     3,     4,     5,     6,     4,     5,     1,     3,
       1,     1,     1,     2,     2,     3,     2,     3,     2,     3,
       3,     4,     2,     2,     3,     1,     2,     3,     2,     3,
       3,     4,     3,     5,     6,     4,     1,     1,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 89 "parser.y"
                    { 
        if ( syntaxErrorCounter > 0 ) {
            PrintError("Found " + std::to_string(syntaxErrorCounter) + " syntax errors. Fix them and rerun.");
            exit(1);
        }
        Print("- R: statementList -> script"); 
    }
#line 2443 "parser.tab.cpp"
    break;

  case 3: /* statementList: statementListItem  */
#line 99 "parser.y"
                        { Print("- R: statementListItem -> statementList"); }
#line 2449 "parser.tab.cpp"
    break;

  case 4: /* statementList: statementList statementListItem  */
#line 100 "parser.y"
                                      { Print("- R: statementList statementListItem -> statementList"); }
#line 2455 "parser.tab.cpp"
    break;

  case 7: /* statementListItem: ';'  */
#line 106 "parser.y"
                                    { 
        if ( isASIActivated ) {
            std::string text(yytext_ptr, yyleng);
            yyerror(("syntax error on token: " + text).c_str()); YYERROR;
        }
        Print("- R: ';' -> statementListItem"); 
    }
#line 2467 "parser.tab.cpp"
    break;

  case 8: /* statementListItem: expressionList statementSep  */
#line 113 "parser.y"
                                    { Print("- R: expressionList statementSep -> statementListItem"); }
#line 2473 "parser.tab.cpp"
    break;

  case 9: /* statementListItem: varStatement statementSep  */
#line 114 "parser.y"
                                    { Print("- R: varStatement statementSep -> statementListItem"); }
#line 2479 "parser.tab.cpp"
    break;

  case 10: /* statementListItem: ifStatement  */
#line 115 "parser.y"
                                    { Print("- R: ifStatement -> statementListItem"); }
#line 2485 "parser.tab.cpp"
    break;

  case 11: /* statementListItem: switchStatement  */
#line 116 "parser.y"
                                    { Print("- R: switchStatement -> statementListItem"); }
#line 2491 "parser.tab.cpp"
    break;

  case 12: /* statementListItem: iterationStatement  */
#line 117 "parser.y"
                                    { Print("- R: iterationStatement -> statementListItem"); }
#line 2497 "parser.tab.cpp"
    break;

  case 13: /* $@1: %empty  */
#line 118 "parser.y"
                        {
        if ( !isInIterationBody ) { 
            yyerror("illegal continue statement."); YYERROR;
        } 
    }
#line 2507 "parser.tab.cpp"
    break;

  case 14: /* statementListItem: continueStatement $@1 statementSep  */
#line 122 "parser.y"
                                    { Print("- R: continueStatement statementSep -> statementListItem");  }
#line 2513 "parser.tab.cpp"
    break;

  case 15: /* $@2: %empty  */
#line 123 "parser.y"
                     {
        if ( !isInIterationBody ) { 
            yyerror("illegal break statement."); YYERROR;
        } 
    }
#line 2523 "parser.tab.cpp"
    break;

  case 16: /* statementListItem: breakStatement $@2 statementSep  */
#line 127 "parser.y"
                                    { Print("- R: breakStatement statementSep -> statementListItem"); }
#line 2529 "parser.tab.cpp"
    break;

  case 17: /* $@3: %empty  */
#line 128 "parser.y"
                      { 
        if ( !isInFunctionBody ) { 
            yyerror("illegal return statement."); YYERROR;
        } 
    }
#line 2539 "parser.tab.cpp"
    break;

  case 18: /* statementListItem: returnStatement $@3 statementSep  */
#line 132 "parser.y"
                                    { Print("- R: returnStatement statementSep -> statementListItem"); }
#line 2545 "parser.tab.cpp"
    break;

  case 19: /* statementListItem: labelledStatement  */
#line 133 "parser.y"
                                    { Print("- R: labelledStatement -> statementListItem"); }
#line 2551 "parser.tab.cpp"
    break;

  case 20: /* statementListItem: blockStatement  */
#line 134 "parser.y"
                                    { Print("- R: blockStatement -> statementListItem"); }
#line 2557 "parser.tab.cpp"
    break;

  case 21: /* statementListItem: functionDeclaration  */
#line 135 "parser.y"
                                    { Print("- R: functionDeclaration -> statementListItem"); }
#line 2563 "parser.tab.cpp"
    break;

  case 22: /* statementListItem: classDeclaration  */
#line 136 "parser.y"
                                    { Print("- R: classDeclaration -> statementListItem"); }
#line 2569 "parser.tab.cpp"
    break;

  case 25: /* statementListItemWithoutEmptyStatement: expressionList statementSep  */
#line 142 "parser.y"
                                    { Print("- R: expressionList statementSep -> statementListItem"); }
#line 2575 "parser.tab.cpp"
    break;

  case 26: /* statementListItemWithoutEmptyStatement: varStatement statementSep  */
#line 143 "parser.y"
                                    { Print("- R: varStatement statementSep -> statementListItem"); }
#line 2581 "parser.tab.cpp"
    break;

  case 27: /* statementListItemWithoutEmptyStatement: ifStatement  */
#line 144 "parser.y"
                                    { Print("- R: ifStatement -> statementListItem"); }
#line 2587 "parser.tab.cpp"
    break;

  case 28: /* statementListItemWithoutEmptyStatement: switchStatement  */
#line 145 "parser.y"
                                    { Print("- R: switchStatement -> statementListItem"); }
#line 2593 "parser.tab.cpp"
    break;

  case 29: /* statementListItemWithoutEmptyStatement: iterationStatement  */
#line 146 "parser.y"
                                    { Print("- R: iterationStatement -> statementListItem"); }
#line 2599 "parser.tab.cpp"
    break;

  case 30: /* $@4: %empty  */
#line 147 "parser.y"
                        {
        if ( !isInIterationBody ) { 
            yyerror("illegal continue statement."); YYERROR;
        } 
    }
#line 2609 "parser.tab.cpp"
    break;

  case 31: /* statementListItemWithoutEmptyStatement: continueStatement $@4 statementSep  */
#line 151 "parser.y"
                                    { Print("- R: continueStatement statementSep -> statementListItem");  }
#line 2615 "parser.tab.cpp"
    break;

  case 32: /* $@5: %empty  */
#line 152 "parser.y"
                     {
        if ( !isInIterationBody ) { 
            yyerror("illegal break statement."); YYERROR;
        } 
    }
#line 2625 "parser.tab.cpp"
    break;

  case 33: /* statementListItemWithoutEmptyStatement: breakStatement $@5 statementSep  */
#line 156 "parser.y"
                                    { Print("- R: breakStatement statementSep -> statementListItem"); }
#line 2631 "parser.tab.cpp"
    break;

  case 34: /* $@6: %empty  */
#line 157 "parser.y"
                      { 
        if ( !isInFunctionBody ) { 
            yyerror("illegal return statement."); YYERROR;
        } 
    }
#line 2641 "parser.tab.cpp"
    break;

  case 35: /* statementListItemWithoutEmptyStatement: returnStatement $@6 statementSep  */
#line 161 "parser.y"
                                    { Print("- R: returnStatement statementSep -> statementListItem"); }
#line 2647 "parser.tab.cpp"
    break;

  case 36: /* statementListItemWithoutEmptyStatement: labelledStatement  */
#line 162 "parser.y"
                                    { Print("- R: labelledStatement -> statementListItem"); }
#line 2653 "parser.tab.cpp"
    break;

  case 37: /* statementListItemWithoutEmptyStatement: blockStatement  */
#line 163 "parser.y"
                                    { Print("- R: blockStatement -> statementListItem"); }
#line 2659 "parser.tab.cpp"
    break;

  case 38: /* statementListItemWithoutEmptyStatement: functionDeclaration  */
#line 164 "parser.y"
                                    { Print("- R: functionDeclaration -> statementListItem"); }
#line 2665 "parser.tab.cpp"
    break;

  case 39: /* statementListItemWithoutEmptyStatement: classDeclaration  */
#line 165 "parser.y"
                                    { Print("- R: classDeclaration -> statementListItem"); }
#line 2671 "parser.tab.cpp"
    break;

  case 40: /* statementSep: ';'  */
#line 169 "parser.y"
          { Print("- R: ';' -> statementSep"); }
#line 2677 "parser.tab.cpp"
    break;

  case 41: /* initializer: '=' singleExpression  */
#line 173 "parser.y"
                           { Print("- R: '=' singleExpression -> initializer"); }
#line 2683 "parser.tab.cpp"
    break;

  case 42: /* type: unionOrIntersectionOrPrimaryType  */
#line 179 "parser.y"
                                       { Print("- R: unionOrIntersectionOrPrimaryType -> type"); }
#line 2689 "parser.tab.cpp"
    break;

  case 43: /* type: '|' unionOrIntersectionOrPrimaryType  */
#line 180 "parser.y"
                                           { Print("- R: '|' unionOrIntersectionOrPrimaryType -> type"); }
#line 2695 "parser.tab.cpp"
    break;

  case 44: /* type: '&' unionOrIntersectionOrPrimaryType  */
#line 181 "parser.y"
                                           { Print("- R: '&' unionOrIntersectionOrPrimaryType -> type"); }
#line 2701 "parser.tab.cpp"
    break;

  case 45: /* unionOrIntersectionOrPrimaryType: unionOrIntersectionOrPrimaryType '|' unionOrIntersectionOrPrimaryType  */
#line 185 "parser.y"
                                                                            { Print("- R: unionOrIntersectionOrPrimaryType '|' unionOrIntersectionOrPrimaryType -> unionOrIntersectionOrPrimaryType"); }
#line 2707 "parser.tab.cpp"
    break;

  case 46: /* unionOrIntersectionOrPrimaryType: unionOrIntersectionOrPrimaryType '&' unionOrIntersectionOrPrimaryType  */
#line 186 "parser.y"
                                                                            { Print("- R: unionOrIntersectionOrPrimaryType '&' unionOrIntersectionOrPrimaryType -> unionOrIntersectionOrPrimaryType"); }
#line 2713 "parser.tab.cpp"
    break;

  case 47: /* unionOrIntersectionOrPrimaryType: primaryType  */
#line 187 "parser.y"
                  { Print("- R: primaryType -> argument"); }
#line 2719 "parser.tab.cpp"
    break;

  case 48: /* primaryType: '(' type ')'  */
#line 191 "parser.y"
                   { Print("- R: '(' type ')' -> primaryType"); }
#line 2725 "parser.tab.cpp"
    break;

  case 49: /* primaryType: predefinedType  */
#line 192 "parser.y"
                     { Print("- R: predefinedType -> primaryType"); }
#line 2731 "parser.tab.cpp"
    break;

  case 50: /* primaryType: primaryType '[' ']'  */
#line 193 "parser.y"
                          { Print("- R: primaryType '[' ']' -> primaryType"); }
#line 2737 "parser.tab.cpp"
    break;

  case 51: /* primaryType: primaryType '[' primaryType ']'  */
#line 194 "parser.y"
                                      { Print("- R: primaryType '[' primaryType ']' -> primaryType"); }
#line 2743 "parser.tab.cpp"
    break;

  case 52: /* primaryType: '[' tupleTypeElements ']'  */
#line 195 "parser.y"
                                { Print("- R: '[' tupleTypeElements ']' -> primaryType"); }
#line 2749 "parser.tab.cpp"
    break;

  case 53: /* tupleTypeElements: type  */
#line 199 "parser.y"
           { Print("- R: type -> tupleTypeElements"); }
#line 2755 "parser.tab.cpp"
    break;

  case 54: /* tupleTypeElements: tupleTypeElements ',' type  */
#line 200 "parser.y"
                                 { Print("- R: tupleTypeElements ',' type -> tupleTypeElements"); }
#line 2761 "parser.tab.cpp"
    break;

  case 55: /* predefinedType: ANY  */
#line 204 "parser.y"
          { Print("- R: ANY -> predefinedType"); }
#line 2767 "parser.tab.cpp"
    break;

  case 56: /* predefinedType: NUMBER  */
#line 205 "parser.y"
             { Print("- R: NUMBER -> predefinedType"); }
#line 2773 "parser.tab.cpp"
    break;

  case 57: /* predefinedType: STRING  */
#line 206 "parser.y"
             { Print("- R: STRING -> predefinedType"); }
#line 2779 "parser.tab.cpp"
    break;

  case 58: /* predefinedType: BOOLEAN  */
#line 207 "parser.y"
              { Print("- R: BOOLEAN -> predefinedType"); }
#line 2785 "parser.tab.cpp"
    break;

  case 59: /* predefinedType: NEVER  */
#line 208 "parser.y"
            { Print("- R: NEVER -> predefinedType"); }
#line 2791 "parser.tab.cpp"
    break;

  case 60: /* predefinedType: UNKNOWN  */
#line 209 "parser.y"
              { Print("- R: UNKNOWN -> predefinedType"); }
#line 2797 "parser.tab.cpp"
    break;

  case 61: /* predefinedType: UNDEFINED  */
#line 210 "parser.y"
                { Print("- R: UNDEFINED -> predefinedType"); }
#line 2803 "parser.tab.cpp"
    break;

  case 62: /* predefinedType: VOID  */
#line 211 "parser.y"
           { Print("- R: VOID -> predefinedType"); }
#line 2809 "parser.tab.cpp"
    break;

  case 63: /* predefinedType: NULL_KW  */
#line 212 "parser.y"
              { Print("- R: NULL_KW -> predefinedType"); }
#line 2815 "parser.tab.cpp"
    break;

  case 64: /* predefinedType: INT_LIT  */
#line 213 "parser.y"
              { Print("- R: INT_LIT -> predefinedType"); }
#line 2821 "parser.tab.cpp"
    break;

  case 65: /* predefinedType: FLOAT_LIT  */
#line 214 "parser.y"
                { Print("- R: FLOAT_LIT -> predefinedType"); }
#line 2827 "parser.tab.cpp"
    break;

  case 66: /* predefinedType: TRUE_KW  */
#line 215 "parser.y"
              { Print("- R: TRUE_WD -> predefinedType"); }
#line 2833 "parser.tab.cpp"
    break;

  case 67: /* predefinedType: FALSE_KW  */
#line 216 "parser.y"
               { Print("- R: FALSE_KW -> predefinedType"); }
#line 2839 "parser.tab.cpp"
    break;

  case 68: /* predefinedType: STRING_LIT  */
#line 217 "parser.y"
                 { Print("- R: STRING_LIT -> predefinedType"); }
#line 2845 "parser.tab.cpp"
    break;

  case 69: /* typeAnnotation: ':' type  */
#line 221 "parser.y"
               { Print("- R: ':' type -> typeAnnotation"); }
#line 2851 "parser.tab.cpp"
    break;

  case 70: /* arrayLiteral: '[' elementList ']'  */
#line 226 "parser.y"
                          { Print("- R: [ elementList ']' -> arrayLiteral"); }
#line 2857 "parser.tab.cpp"
    break;

  case 71: /* arrayLiteral: ENDL_BRACKET_OPEN elementList ']'  */
#line 227 "parser.y"
                                        { Print("- R: ENDL_BRACKET_OPEN elementList ']' -> arrayLiteral"); }
#line 2863 "parser.tab.cpp"
    break;

  case 72: /* elementList: %empty  */
#line 231 "parser.y"
                  { Print("- R: #empty# -> elementList"); }
#line 2869 "parser.tab.cpp"
    break;

  case 73: /* elementList: arrayElement  */
#line 232 "parser.y"
                   { Print("- R: arrayElement -> elementList"); }
#line 2875 "parser.tab.cpp"
    break;

  case 74: /* elementList: elementList ',' elementList  */
#line 233 "parser.y"
                                  { Print("- R: elementList ',' elementList -> elementList"); }
#line 2881 "parser.tab.cpp"
    break;

  case 75: /* arrayElement: singleExpression  */
#line 237 "parser.y"
                       { Print("- R: singleExpression -> arrayElement"); }
#line 2887 "parser.tab.cpp"
    break;

  case 76: /* arrayElement: ELLIPSIS singleExpression  */
#line 238 "parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> arrayElement"); }
#line 2893 "parser.tab.cpp"
    break;

  case 77: /* expressionListOpt: %empty  */
#line 244 "parser.y"
                  { Print("- R: #empty# -> expressionListOpt"); }
#line 2899 "parser.tab.cpp"
    break;

  case 78: /* expressionListOpt: expressionList  */
#line 245 "parser.y"
                     { Print("- R: expressionList -> expressionListOpt"); }
#line 2905 "parser.tab.cpp"
    break;

  case 79: /* expressionList: singleExpression  */
#line 249 "parser.y"
                       { Print("- R: singleExpression -> expressionList"); }
#line 2911 "parser.tab.cpp"
    break;

  case 80: /* expressionList: expressionList ',' singleExpression  */
#line 250 "parser.y"
                                          { Print("- R: expressionList ',' singleExpression -> expressionList"); }
#line 2917 "parser.tab.cpp"
    break;

  case 81: /* singleExpression: identifier  */
#line 254 "parser.y"
                 { Print("- R: identifier -> singleExpression"); }
#line 2923 "parser.tab.cpp"
    break;

  case 82: /* singleExpression: THIS  */
#line 255 "parser.y"
           { Print("- R: THIS -> singleExpression"); }
#line 2929 "parser.tab.cpp"
    break;

  case 83: /* singleExpression: SUPER  */
#line 256 "parser.y"
            { Print("- R: SUPER -> singleExpression"); }
#line 2935 "parser.tab.cpp"
    break;

  case 84: /* singleExpression: INT_LIT  */
#line 257 "parser.y"
              { Print("- R: INT_LIT -> singleExpression"); }
#line 2941 "parser.tab.cpp"
    break;

  case 85: /* singleExpression: FLOAT_LIT  */
#line 258 "parser.y"
                { Print("- R: FLOAT_LIT -> singleExpression"); }
#line 2947 "parser.tab.cpp"
    break;

  case 86: /* singleExpression: STRING_LIT  */
#line 259 "parser.y"
                 { Print("- R: STRING_LIT -> singleExpression"); }
#line 2953 "parser.tab.cpp"
    break;

  case 87: /* singleExpression: TEMPLATE_LITERAL  */
#line 260 "parser.y"
                       { Print("- R: TEMPLATE_LITERAL -> singleExpression"); }
#line 2959 "parser.tab.cpp"
    break;

  case 88: /* singleExpression: TRUE_KW  */
#line 261 "parser.y"
              { Print("- R: TRUE_LITERAL -> singleExpression"); }
#line 2965 "parser.tab.cpp"
    break;

  case 89: /* singleExpression: FALSE_KW  */
#line 262 "parser.y"
               { Print("- R: FALSE_LITERAL -> singleExpression"); }
#line 2971 "parser.tab.cpp"
    break;

  case 90: /* singleExpression: NULL_KW  */
#line 263 "parser.y"
              { Print("- R: NULL_LITERAL -> singleExpression"); }
#line 2977 "parser.tab.cpp"
    break;

  case 91: /* singleExpression: '-' singleExpression  */
#line 264 "parser.y"
                                        { Print("- R: '-' singleExpression -> singleExpression"); }
#line 2983 "parser.tab.cpp"
    break;

  case 92: /* singleExpression: '+' singleExpression  */
#line 265 "parser.y"
                                       { Print("- R: '+'s singleExpression -> singleExpression"); }
#line 2989 "parser.tab.cpp"
    break;

  case 93: /* singleExpression: '!' singleExpression  */
#line 266 "parser.y"
                           { Print("- R: '!' singleExpression -> singleExpression"); }
#line 2995 "parser.tab.cpp"
    break;

  case 94: /* singleExpression: '~' singleExpression  */
#line 267 "parser.y"
                           { Print("- R: '~' singleExpression -> singleExpression"); }
#line 3001 "parser.tab.cpp"
    break;

  case 95: /* singleExpression: singleExpression OPERATOR_INCREMENT  */
#line 268 "parser.y"
                                                               { Print("- R: singleExpression OPERATOR_INCREMENT -> singleExpression"); }
#line 3007 "parser.tab.cpp"
    break;

  case 96: /* singleExpression: singleExpression OPERATOR_DECREMENT  */
#line 269 "parser.y"
                                                               { Print("- R: singleExpression OPERATOR_DECREMENT -> singleExpression"); }
#line 3013 "parser.tab.cpp"
    break;

  case 97: /* singleExpression: ENDL_OPERATOR_INCREMENT singleExpression  */
#line 270 "parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 3019 "parser.tab.cpp"
    break;

  case 98: /* singleExpression: ENDL_OPERATOR_DECREMENT singleExpression  */
#line 271 "parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 3025 "parser.tab.cpp"
    break;

  case 99: /* singleExpression: OPERATOR_INCREMENT singleExpression  */
#line 272 "parser.y"
                                                               { Print("- R: OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 3031 "parser.tab.cpp"
    break;

  case 100: /* singleExpression: OPERATOR_DECREMENT singleExpression  */
#line 273 "parser.y"
                                                               { Print("- R: OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 3037 "parser.tab.cpp"
    break;

  case 101: /* singleExpression: singleExpression '+' singleExpression  */
#line 274 "parser.y"
                                            { Print("- R: singleExpression '+' singleExpression -> singleExpression"); }
#line 3043 "parser.tab.cpp"
    break;

  case 102: /* singleExpression: singleExpression '-' singleExpression  */
#line 275 "parser.y"
                                            { Print("- R: singleExpression '-' singleExpression -> singleExpression"); }
#line 3049 "parser.tab.cpp"
    break;

  case 103: /* singleExpression: singleExpression '*' singleExpression  */
#line 276 "parser.y"
                                            { Print("- R: singleExpression '*' singleExpression -> singleExpression"); }
#line 3055 "parser.tab.cpp"
    break;

  case 104: /* singleExpression: singleExpression '/' singleExpression  */
#line 277 "parser.y"
                                            { Print("- R: singleExpression '/' singleExpression -> singleExpression"); }
#line 3061 "parser.tab.cpp"
    break;

  case 105: /* singleExpression: singleExpression '%' singleExpression  */
#line 278 "parser.y"
                                            { Print("- R: singleExpression '%' singleExpression -> singleExpression"); }
#line 3067 "parser.tab.cpp"
    break;

  case 106: /* singleExpression: singleExpression '<' singleExpression  */
#line 279 "parser.y"
                                            { Print("- R: singleExpression '<' singleExpression -> singleExpression"); }
#line 3073 "parser.tab.cpp"
    break;

  case 107: /* singleExpression: singleExpression '>' singleExpression  */
#line 280 "parser.y"
                                            { Print("- R: singleExpression '>' singleExpression -> singleExpression"); }
#line 3079 "parser.tab.cpp"
    break;

  case 108: /* singleExpression: singleExpression OPERATOR_POWER singleExpression  */
#line 281 "parser.y"
                                                       { Print("- R: singleExpression OPERATOR_POWER singleExpression -> singleExpression"); }
#line 3085 "parser.tab.cpp"
    break;

  case 109: /* singleExpression: singleExpression OPERATOR_EQUAL singleExpression  */
#line 282 "parser.y"
                                                       { Print("- R: singleExpression OPERATOR_EQUAL singleExpression -> singleExpression"); }
#line 3091 "parser.tab.cpp"
    break;

  case 110: /* singleExpression: singleExpression OPERATOR_NOT_EQUAL singleExpression  */
#line 283 "parser.y"
                                                           { Print("- R: singleExpression OPERATOR_NOT_EQUAL singleExpression -> singleExpression"); }
#line 3097 "parser.tab.cpp"
    break;

  case 111: /* singleExpression: singleExpression OPERATOR_STRICT_EQUAL singleExpression  */
#line 284 "parser.y"
                                                              { Print("- R: singleExpression OPERATOR_STRICT_EQUAL singleExpression -> singleExpression"); }
#line 3103 "parser.tab.cpp"
    break;

  case 112: /* singleExpression: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression  */
#line 285 "parser.y"
                                                                  { Print("- R: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression -> singleExpression"); }
#line 3109 "parser.tab.cpp"
    break;

  case 113: /* singleExpression: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression  */
#line 286 "parser.y"
                                                                 { Print("- R: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression -> singleExpression"); }
#line 3115 "parser.tab.cpp"
    break;

  case 114: /* singleExpression: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression  */
#line 287 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression -> singleExpression"); }
#line 3121 "parser.tab.cpp"
    break;

  case 115: /* singleExpression: singleExpression '=' singleExpression  */
#line 288 "parser.y"
                                            { Print("- R: singleExpression '=' singleExpression -> singleExpression"); }
#line 3127 "parser.tab.cpp"
    break;

  case 116: /* singleExpression: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression  */
#line 289 "parser.y"
                                                                 { Print("- R: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression -> singleExpression"); }
#line 3133 "parser.tab.cpp"
    break;

  case 117: /* singleExpression: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression  */
#line 290 "parser.y"
                                                               { Print("- R: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression -> singleExpression"); }
#line 3139 "parser.tab.cpp"
    break;

  case 118: /* singleExpression: singleExpression OPERATOR_ASSIGN_MOD singleExpression  */
#line 291 "parser.y"
                                                            { Print("- R: singleExpression OPERATOR_ASSIGN_MOD singleExpression -> singleExpression"); }
#line 3145 "parser.tab.cpp"
    break;

  case 119: /* singleExpression: singleExpression OPERATOR_ASSIGN_PLUS singleExpression  */
#line 292 "parser.y"
                                                             { Print("- R: singleExpression OPERATOR_ASSIGN_PLUS singleExpression -> singleExpression"); }
#line 3151 "parser.tab.cpp"
    break;

  case 120: /* singleExpression: singleExpression OPERATOR_ASSIGN_MINUS singleExpression  */
#line 293 "parser.y"
                                                              { Print("- R: singleExpression OPERATOR_ASSIGN_MINUS singleExpression -> singleExpression"); }
#line 3157 "parser.tab.cpp"
    break;

  case 121: /* singleExpression: singleExpression OPERATOR_ASSIGN_SHIFT_LEFT singleExpression  */
#line 294 "parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_SHIFT_LEFT singleExpression -> singleExpression"); }
#line 3163 "parser.tab.cpp"
    break;

  case 122: /* singleExpression: singleExpression OPERATOR_ASSIGN_SHIFT_RIGHT singleExpression  */
#line 295 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3169 "parser.tab.cpp"
    break;

  case 123: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_AND singleExpression  */
#line 296 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_AND singleExpression -> singleExpression"); }
#line 3175 "parser.tab.cpp"
    break;

  case 124: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_XOR singleExpression  */
#line 297 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_XOR singleExpression -> singleExpression"); }
#line 3181 "parser.tab.cpp"
    break;

  case 125: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_OR singleExpression  */
#line 298 "parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_OR singleExpression -> singleExpression"); }
#line 3187 "parser.tab.cpp"
    break;

  case 126: /* singleExpression: singleExpression OPERATOR_ASSIGN_POWER singleExpression  */
#line 299 "parser.y"
                                                              { Print("- R: singleExpression OPERATOR_ASSIGN_POWER singleExpression -> singleExpression"); }
#line 3193 "parser.tab.cpp"
    break;

  case 127: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression  */
#line 300 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression -> singleExpression"); }
#line 3199 "parser.tab.cpp"
    break;

  case 128: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression  */
#line 301 "parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression -> singleExpression"); }
#line 3205 "parser.tab.cpp"
    break;

  case 129: /* singleExpression: singleExpression OPERATOR_ASSIGN_NULLISH_COALESCING singleExpression  */
#line 302 "parser.y"
                                                                           { Print("- R: singleExpression OPERATOR_ASSIGN_NULLISH_COALESCING singleExpression -> singleExpression"); }
#line 3211 "parser.tab.cpp"
    break;

  case 130: /* singleExpression: singleExpression OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT singleExpression  */
#line 303 "parser.y"
                                                                             { Print("- R: singleExpression OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3217 "parser.tab.cpp"
    break;

  case 131: /* singleExpression: singleExpression OPERATOR_LOGICAL_OR singleExpression  */
#line 304 "parser.y"
                                                            { Print("- R: singleExpression OPERATOR_LOGICAL_OR singleExpression -> singleExpression"); }
#line 3223 "parser.tab.cpp"
    break;

  case 132: /* singleExpression: singleExpression OPERATOR_LOGICAL_AND singleExpression  */
#line 305 "parser.y"
                                                             { Print("- R: singleExpression OPERATOR_LOGICAL_AND singleExpression -> singleExpression"); }
#line 3229 "parser.tab.cpp"
    break;

  case 133: /* singleExpression: singleExpression '|' singleExpression  */
#line 306 "parser.y"
                                            { Print("- R: singleExpression '|' singleExpression -> singleExpression"); }
#line 3235 "parser.tab.cpp"
    break;

  case 134: /* singleExpression: singleExpression '^' singleExpression  */
#line 307 "parser.y"
                                            { Print("- R: singleExpression '^' singleExpression -> singleExpression"); }
#line 3241 "parser.tab.cpp"
    break;

  case 135: /* singleExpression: singleExpression '&' singleExpression  */
#line 308 "parser.y"
                                            { Print("- R: singleExpression '&' singleExpression -> singleExpression"); }
#line 3247 "parser.tab.cpp"
    break;

  case 136: /* singleExpression: singleExpression OPERATOR_SHIFT_LEFT singleExpression  */
#line 309 "parser.y"
                                                            { Print("- R: singleExpression OPERATOR_SHIFT_LEFT singleExpression -> singleExpression"); }
#line 3253 "parser.tab.cpp"
    break;

  case 137: /* singleExpression: singleExpression OPERATOR_SHIFT_RIGHT singleExpression  */
#line 310 "parser.y"
                                                             { Print("- R: singleExpression OPERATOR_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3259 "parser.tab.cpp"
    break;

  case 138: /* singleExpression: singleExpression OPERATOR_UNSIGNED_SHIFT_RIGHT singleExpression  */
#line 311 "parser.y"
                                                                      { Print("- R: singleExpression OPERATOR_UNSIGNED_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3265 "parser.tab.cpp"
    break;

  case 139: /* singleExpression: singleExpression OPERATOR_NULLISH_COALESCING singleExpression  */
#line 312 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_NULLISH_COALESCING singleExpression -> singleExpression"); }
#line 3271 "parser.tab.cpp"
    break;

  case 140: /* singleExpression: singleExpression INSTANCEOF singleExpression  */
#line 314 "parser.y"
                                                   { Print("- R: singleExpression INSTANCEOF singleExpression -> singleExpression"); }
#line 3277 "parser.tab.cpp"
    break;

  case 141: /* singleExpression: singleExpression IN singleExpression  */
#line 315 "parser.y"
                                           { Print("- R: singleExpression IN singleExpression -> singleExpression"); }
#line 3283 "parser.tab.cpp"
    break;

  case 142: /* singleExpression: singleExpression TEMPLATE_LITERAL  */
#line 317 "parser.y"
                                        { Print("- R: singleExpression TEMPLATE_LITERAL -> singleExpression"); }
#line 3289 "parser.tab.cpp"
    break;

  case 143: /* singleExpression: singleExpression '?' singleExpression ':' singleExpression  */
#line 318 "parser.y"
                                                                 { Print("- R: singleExpression '?' singleExpression ':' singleExpression -> singleExpression"); }
#line 3295 "parser.tab.cpp"
    break;

  case 144: /* singleExpression: '(' expressionList ')'  */
#line 320 "parser.y"
                             { Print("- R: '(' expressionList ')' -> singleExpression"); }
#line 3301 "parser.tab.cpp"
    break;

  case 145: /* singleExpression: singleExpression arguments  */
#line 322 "parser.y"
                                 { Print("- R: singleExpression arguments -> singleExpression"); }
#line 3307 "parser.tab.cpp"
    break;

  case 146: /* singleExpression: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression  */
#line 324 "parser.y"
                                                                   { Print("- R: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression -> singleExpression"); }
#line 3313 "parser.tab.cpp"
    break;

  case 147: /* singleExpression: singleExpression '.' identifier  */
#line 325 "parser.y"
                                      { Print("- R: singleExpression '.' identifier -> singleExpression"); }
#line 3319 "parser.tab.cpp"
    break;

  case 148: /* singleExpression: arrayLiteral  */
#line 327 "parser.y"
                   { Print("- R: arrayLiteral -> singleExpression"); }
#line 3325 "parser.tab.cpp"
    break;

  case 149: /* singleExpression: singleExpression '[' expressionList ']'  */
#line 328 "parser.y"
                                              { Print("- R: singleExpression '[' singleExpression ']' -> singleExpression"); }
#line 3331 "parser.tab.cpp"
    break;

  case 150: /* singleExpression: singleExpression ENDL_BRACKET_OPEN expressionList ']'  */
#line 329 "parser.y"
                                                            { Print("- R: singleExpression ENDL_BRACKET_OPEN singleExpression ']' -> singleExpression"); }
#line 3337 "parser.tab.cpp"
    break;

  case 151: /* singleExpression: NEW singleExpression  */
#line 331 "parser.y"
                           { Print("- R: NEW singleExpression -> singleExpression"); }
#line 3343 "parser.tab.cpp"
    break;

  case 152: /* arguments: '(' ')'  */
#line 335 "parser.y"
              { Print("- R: '(' ')' -> arguments"); }
#line 3349 "parser.tab.cpp"
    break;

  case 153: /* arguments: '(' argumentList ')'  */
#line 336 "parser.y"
                           { Print("- R: '(' argumentList ')' -> arguments"); }
#line 3355 "parser.tab.cpp"
    break;

  case 154: /* arguments: '(' argumentList ',' ')'  */
#line 337 "parser.y"
                               { Print("- R: '(' argumentList ',' ') -> arguments"); }
#line 3361 "parser.tab.cpp"
    break;

  case 155: /* argumentList: argument  */
#line 341 "parser.y"
               { Print("- R: argument -> argumentList"); }
#line 3367 "parser.tab.cpp"
    break;

  case 156: /* argumentList: argumentList ',' arguments  */
#line 342 "parser.y"
                                 { Print("- R: argumentList ',' arguments -> argumentList"); }
#line 3373 "parser.tab.cpp"
    break;

  case 157: /* argument: singleExpression  */
#line 346 "parser.y"
                       { Print("- R: singleExpression -> argument"); }
#line 3379 "parser.tab.cpp"
    break;

  case 158: /* argument: ELLIPSIS singleExpression  */
#line 347 "parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> argument"); }
#line 3385 "parser.tab.cpp"
    break;

  case 159: /* varStatement: varModifier varDeclarationList  */
#line 353 "parser.y"
                                     { Print("- R: varModifier varDeclarationList -> varStatement"); }
#line 3391 "parser.tab.cpp"
    break;

  case 160: /* varDeclarationList: varDeclaration  */
#line 357 "parser.y"
                     { Print("- R: varDeclaration -> argument"); }
#line 3397 "parser.tab.cpp"
    break;

  case 161: /* varDeclarationList: varDeclarationList ',' varDeclaration  */
#line 358 "parser.y"
                                            { Print("- R: varDeclarationList ',' varDeclaration -> varDeclarationList"); }
#line 3403 "parser.tab.cpp"
    break;

  case 162: /* varDeclaration: identifier  */
#line 362 "parser.y"
                 { Print("- R: identifier -> varDeclaration"); }
#line 3409 "parser.tab.cpp"
    break;

  case 163: /* varDeclaration: identifier typeAnnotation  */
#line 363 "parser.y"
                                { Print("- R: identifier typeAnnotation -> varDeclaration"); }
#line 3415 "parser.tab.cpp"
    break;

  case 164: /* varDeclaration: identifier '=' singleExpression  */
#line 364 "parser.y"
                                      { Print("- R: identifier '=' singleExpression -> varDeclaration"); }
#line 3421 "parser.tab.cpp"
    break;

  case 165: /* varDeclaration: identifier typeAnnotation '=' singleExpression  */
#line 365 "parser.y"
                                                     { Print("- R: identifier typeAnnotation '=' singleExpression -> varDeclaration"); }
#line 3427 "parser.tab.cpp"
    break;

  case 166: /* varModifier: VAR  */
#line 369 "parser.y"
          { Print("- R: VAR -> varModifier"); }
#line 3433 "parser.tab.cpp"
    break;

  case 167: /* varModifier: LET  */
#line 370 "parser.y"
          { Print("- R: LET -> varModifier"); }
#line 3439 "parser.tab.cpp"
    break;

  case 168: /* varModifier: CONST  */
#line 371 "parser.y"
            { Print("- R: CONST -> varModifier"); }
#line 3445 "parser.tab.cpp"
    break;

  case 169: /* ifStatement: IF '(' expressionList ')' statementListItemWithoutEmptyStatement  */
#line 377 "parser.y"
                                                                                          { Print("- R: IF '(' expressionList ')' statementListItem -> ifStatement"); }
#line 3451 "parser.tab.cpp"
    break;

  case 170: /* ifStatement: IF '(' expressionList ')' statementListItemWithoutEmptyStatement ELSE statementListItem  */
#line 378 "parser.y"
                                                                                              { Print("- R: IF '(' expressionList ')' statementListItem ELSE statementListItem -> ifStatement"); }
#line 3457 "parser.tab.cpp"
    break;

  case 171: /* $@7: %empty  */
#line 382 "parser.y"
         { isInIterationBody = 1; }
#line 3463 "parser.tab.cpp"
    break;

  case 172: /* $@8: %empty  */
#line 382 "parser.y"
                                                                                   { doWhileASI(); }
#line 3469 "parser.tab.cpp"
    break;

  case 173: /* iterationStatement: DO $@7 statementListItem WHILE '(' expressionList ')' $@8 statementSep  */
#line 382 "parser.y"
                                                                                                                                            { isInIterationBody = 0; Print("- R: DO statementListItem WHILE '(' expressionList ')' statementSep -> iterationStatement"); }
#line 3475 "parser.tab.cpp"
    break;

  case 174: /* $@9: %empty  */
#line 383 "parser.y"
                                   { isInIterationBody = 1; }
#line 3481 "parser.tab.cpp"
    break;

  case 175: /* iterationStatement: WHILE '(' expressionList ')' $@9 statementListItem  */
#line 383 "parser.y"
                                                                                                                                            { isInIterationBody = 0; Print("- R: WHILE '(' expressionList ')' statementListItem -> iterationStatement"); }
#line 3487 "parser.tab.cpp"
    break;

  case 176: /* $@10: %empty  */
#line 384 "parser.y"
                                                                                  { isInForHeader = 0; isInIterationBody = 1; }
#line 3493 "parser.tab.cpp"
    break;

  case 177: /* iterationStatement: forHeader expressionListOpt ';' expressionListOpt ';' expressionListOpt ')' $@10 statementListItem  */
#line 384 "parser.y"
                                                                                                                                                                 { isInIterationBody = 0; Print("- R: FOR '(' expressionListOpt ';' expressionListOpt ';' expressionListOpt ')' statementListItem -> iterationStatement"); }
#line 3499 "parser.tab.cpp"
    break;

  case 178: /* $@11: %empty  */
#line 385 "parser.y"
                                                                                               { isInForHeader = 0; isInIterationBody = 1; }
#line 3505 "parser.tab.cpp"
    break;

  case 179: /* iterationStatement: forHeader varModifier varDeclarationList ';' expressionListOpt ';' expressionListOpt ')' $@11 statementListItem  */
#line 385 "parser.y"
                                                                                                                                                                 { isInIterationBody = 0; Print("- R: FOR '(' varModifier varDeclarationList ';' expressionListOpt ';' expressionListOpt ')' statementListItem -> iterationStatement"); }
#line 3511 "parser.tab.cpp"
    break;

  case 180: /* $@12: %empty  */
#line 386 "parser.y"
                                                         { isInForHeader = 0; isInIterationBody = 1; }
#line 3517 "parser.tab.cpp"
    break;

  case 181: /* iterationStatement: forHeader singleExpression IN singleExpression ')' $@12 statementListItem  */
#line 386 "parser.y"
                                                                                                                                                                 { isInIterationBody = 0; Print("- R: FOR '(' singleExpression IN singleExpression ')' statementListItem -> iterationStatement"); }
#line 3523 "parser.tab.cpp"
    break;

  case 182: /* $@13: %empty  */
#line 387 "parser.y"
                                                                 { isInForHeader = 0; isInIterationBody = 1; }
#line 3529 "parser.tab.cpp"
    break;

  case 183: /* iterationStatement: forHeader varModifier varDeclaration IN expressionList ')' $@13 statementListItem  */
#line 387 "parser.y"
                                                                                                                                                                 { isInIterationBody = 0; Print("- R: FOR '(' varModifier varDeclaration IN expressionList ')' statementListItem -> iterationStatement"); }
#line 3535 "parser.tab.cpp"
    break;

  case 184: /* forHeader: FOR '('  */
#line 391 "parser.y"
               { isInForHeader = 1; }
#line 3541 "parser.tab.cpp"
    break;

  case 185: /* continueStatement: CONTINUE  */
#line 395 "parser.y"
               { Print("- R: CONTINUE -> returnStatement"); }
#line 3547 "parser.tab.cpp"
    break;

  case 186: /* continueStatement: CONTINUE identifier  */
#line 396 "parser.y"
                          { Print("- R: CONTINUE identifier -> returnStatement"); }
#line 3553 "parser.tab.cpp"
    break;

  case 187: /* breakStatement: BREAK  */
#line 400 "parser.y"
             { Print("- R: BREAK -> returnStatement"); }
#line 3559 "parser.tab.cpp"
    break;

  case 188: /* breakStatement: BREAK identifier  */
#line 401 "parser.y"
                       { Print("- R: BREAK identifier -> returnStatement"); }
#line 3565 "parser.tab.cpp"
    break;

  case 189: /* returnStatement: RETURN  */
#line 405 "parser.y"
             { Print("- R: RETURN -> returnStatement"); }
#line 3571 "parser.tab.cpp"
    break;

  case 190: /* returnStatement: RETURN singleExpression  */
#line 406 "parser.y"
                              { Print("- R: RETURN singleExpression -> returnStatement"); }
#line 3577 "parser.tab.cpp"
    break;

  case 191: /* labelledStatement: identifier ':' statementListItem  */
#line 410 "parser.y"
                                       { Print("- R: identifier ':' statementListItem -> labelledStatement"); }
#line 3583 "parser.tab.cpp"
    break;

  case 192: /* blockStatement: '{' '}'  */
#line 414 "parser.y"
              { Print("- R: '{' '}' -> blockStatement"); }
#line 3589 "parser.tab.cpp"
    break;

  case 193: /* blockStatement: '{' statementList '}'  */
#line 415 "parser.y"
                            { Print("- R: '{' statementList '}' -> blockStatement"); }
#line 3595 "parser.tab.cpp"
    break;

  case 194: /* switchStatement: SWITCH '(' expressionList ')' '{' '}'  */
#line 419 "parser.y"
                                            { Print("- R: SWITCH '(' expressionList ')' '{' '}' -> switchStatement"); }
#line 3601 "parser.tab.cpp"
    break;

  case 195: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList '}'  */
#line 420 "parser.y"
                                                           { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList '}' -> switchStatement"); }
#line 3607 "parser.tab.cpp"
    break;

  case 196: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause '}'  */
#line 421 "parser.y"
                                                                         { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause '}' -> switchStatement"); }
#line 3613 "parser.tab.cpp"
    break;

  case 197: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause caseClauseList '}'  */
#line 422 "parser.y"
                                                                                        { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause caseClauseList '}' -> switchStatement"); }
#line 3619 "parser.tab.cpp"
    break;

  case 198: /* caseClauseList: caseClause  */
#line 426 "parser.y"
                 { Print("- R: caseClause -> caseClauseList"); }
#line 3625 "parser.tab.cpp"
    break;

  case 199: /* caseClauseList: caseClauseList caseClause  */
#line 427 "parser.y"
                                { Print("- R: caseClauseList caseClause -> caseClauseList"); }
#line 3631 "parser.tab.cpp"
    break;

  case 200: /* caseClause: CASE expressionList ':'  */
#line 431 "parser.y"
                              { Print("- R: CASE expressionList ':' -> caseClause"); }
#line 3637 "parser.tab.cpp"
    break;

  case 201: /* caseClause: CASE expressionList ':' statementList  */
#line 432 "parser.y"
                                            { Print("- R: CASE expressionList ':' statementList -> caseClause"); }
#line 3643 "parser.tab.cpp"
    break;

  case 202: /* defaultClause: DEFAULT ':'  */
#line 436 "parser.y"
                  { Print("- R: DEFAULT ':' -> defaultClause"); }
#line 3649 "parser.tab.cpp"
    break;

  case 203: /* defaultClause: DEFAULT ':' statementList  */
#line 437 "parser.y"
                                { Print("- R: DEFAULT ':' statementList -> defaultClause"); }
#line 3655 "parser.tab.cpp"
    break;

  case 204: /* functionDeclaration: FUNCTION identifier callSignature functionBody  */
#line 443 "parser.y"
                                                     { Print("- R: FUNCTION ID callSignature functionBody -> functionDeclaration"); }
#line 3661 "parser.tab.cpp"
    break;

  case 205: /* functionBody: '{' '}'  */
#line 447 "parser.y"
              { Print("- R: '{' '}' -> functionBody"); }
#line 3667 "parser.tab.cpp"
    break;

  case 206: /* $@14: %empty  */
#line 448 "parser.y"
          { isInFunctionBody = 1; }
#line 3673 "parser.tab.cpp"
    break;

  case 207: /* functionBody: '{' $@14 statementList '}'  */
#line 448 "parser.y"
                                                      { isInFunctionBody = 0; Print("- R: '{' statementList '}' -> functionBody"); }
#line 3679 "parser.tab.cpp"
    break;

  case 208: /* callSignature: '(' ')'  */
#line 452 "parser.y"
              { Print("- R: '(' ')' -> callSignature"); }
#line 3685 "parser.tab.cpp"
    break;

  case 209: /* callSignature: '(' ')' typeAnnotation  */
#line 453 "parser.y"
                             { Print("- R: '(' ')' typeAnnotation -> callSignature"); }
#line 3691 "parser.tab.cpp"
    break;

  case 210: /* callSignature: '(' restParameter ')'  */
#line 454 "parser.y"
                            { Print("- R: '(' restParameter ')' -> callSignature"); }
#line 3697 "parser.tab.cpp"
    break;

  case 211: /* callSignature: '(' restParameter ')' typeAnnotation  */
#line 455 "parser.y"
                                           { Print("- R: '(' restParameter ')' typeAnnotation -> callSignature"); }
#line 3703 "parser.tab.cpp"
    break;

  case 212: /* callSignature: '(' parameterList ')'  */
#line 456 "parser.y"
                            { Print("- R: '(' parameterList ')' -> callSignature"); }
#line 3709 "parser.tab.cpp"
    break;

  case 213: /* callSignature: '(' parameterList ')' typeAnnotation  */
#line 457 "parser.y"
                                           { Print("- R: '(' parameterList ')' typeAnnotation -> callSignature"); }
#line 3715 "parser.tab.cpp"
    break;

  case 214: /* callSignature: '(' parameterList ',' restParameter ')'  */
#line 458 "parser.y"
                                              { Print("- R: '(' parameterList ',' restParameter ')' -> callSignature"); }
#line 3721 "parser.tab.cpp"
    break;

  case 215: /* callSignature: '(' parameterList ',' restParameter ')' typeAnnotation  */
#line 459 "parser.y"
                                                             { Print("- R: '(' parameterList ',' restParameter ')' typeAnnotation -> callSignature"); }
#line 3727 "parser.tab.cpp"
    break;

  case 216: /* callSignature: '(' parameterList ',' ')'  */
#line 460 "parser.y"
                                { Print("- R: '(' parameterList ',' ')' -> callSignature"); }
#line 3733 "parser.tab.cpp"
    break;

  case 217: /* callSignature: '(' parameterList ',' ')' typeAnnotation  */
#line 461 "parser.y"
                                               { Print("- R: '(' parameterList ',' ')' typeAnnotation -> callSignature"); }
#line 3739 "parser.tab.cpp"
    break;

  case 218: /* parameterList: parameter  */
#line 465 "parser.y"
                { Print("- R: parameter -> parameterList"); }
#line 3745 "parser.tab.cpp"
    break;

  case 219: /* parameterList: parameterList ',' parameter  */
#line 466 "parser.y"
                                  { Print("- R: parameterList ',' parameter -> parameterList"); }
#line 3751 "parser.tab.cpp"
    break;

  case 220: /* parameter: requiredParameter  */
#line 470 "parser.y"
                        { Print("- R: requiredParameter -> parameter"); }
#line 3757 "parser.tab.cpp"
    break;

  case 221: /* parameter: optionalParameter  */
#line 471 "parser.y"
                        { Print("- R: optionalParameter -> parameter"); }
#line 3763 "parser.tab.cpp"
    break;

  case 222: /* requiredParameter: identifier  */
#line 475 "parser.y"
                 { Print("- R: ID -> requiredParameter"); }
#line 3769 "parser.tab.cpp"
    break;

  case 223: /* requiredParameter: identifier typeAnnotation  */
#line 476 "parser.y"
                                { Print("- R: ID typeAnnotation -> requiredParameter"); }
#line 3775 "parser.tab.cpp"
    break;

  case 224: /* optionalParameter: identifier '?'  */
#line 480 "parser.y"
                     { Print("- R: ID '?' -> optionalParameter"); }
#line 3781 "parser.tab.cpp"
    break;

  case 225: /* optionalParameter: identifier '?' typeAnnotation  */
#line 481 "parser.y"
                                    { Print("- R: ID '?' typeAnnotation -> optionalParameter"); }
#line 3787 "parser.tab.cpp"
    break;

  case 226: /* optionalParameter: identifier initializer  */
#line 482 "parser.y"
                             { Print("- R: ID initializer -> optionalParameter"); }
#line 3793 "parser.tab.cpp"
    break;

  case 227: /* optionalParameter: identifier typeAnnotation initializer  */
#line 483 "parser.y"
                                            { Print("- R: ID typeAnnotation initializer -> optionalParameter"); }
#line 3799 "parser.tab.cpp"
    break;

  case 228: /* restParameter: ELLIPSIS singleExpression  */
#line 487 "parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> restParameter"); }
#line 3805 "parser.tab.cpp"
    break;

  case 229: /* restParameter: ELLIPSIS singleExpression typeAnnotation  */
#line 488 "parser.y"
                                               { Print("- R: ELLIPSIS singleExpression typeAnnotation -> restParameter"); }
#line 3811 "parser.tab.cpp"
    break;

  case 230: /* classDeclaration: CLASS identifier classTail  */
#line 494 "parser.y"
                                 { Print("- R: CLASS identifier classTail -> classDeclaration"); }
#line 3817 "parser.tab.cpp"
    break;

  case 231: /* classDeclaration: CLASS identifier classHeritage classTail  */
#line 495 "parser.y"
                                               { Print("- R: CLASS identifier classHeritage classTail -> classDeclaration"); }
#line 3823 "parser.tab.cpp"
    break;

  case 232: /* classHeritage: EXTENDS identifier  */
#line 499 "parser.y"
                         { Print("- R: EXTENDS identifier -> classHeritage"); }
#line 3829 "parser.tab.cpp"
    break;

  case 233: /* classTail: '{' '}'  */
#line 503 "parser.y"
              { Print("- R: '{' '}' -> classTail"); }
#line 3835 "parser.tab.cpp"
    break;

  case 234: /* classTail: '{' classElementList '}'  */
#line 504 "parser.y"
                               { Print("- R: '{' classElementList '}' -> classTail"); }
#line 3841 "parser.tab.cpp"
    break;

  case 235: /* classElementList: classElement  */
#line 508 "parser.y"
                   { Print("- R: classElement -> classElementList"); }
#line 3847 "parser.tab.cpp"
    break;

  case 236: /* classElementList: classElementList classElement  */
#line 509 "parser.y"
                                    { Print("- R: classElementList classElement -> classElementList"); }
#line 3853 "parser.tab.cpp"
    break;

  case 237: /* classElement: CONSTRUCTOR callSignature functionBody  */
#line 513 "parser.y"
                                             { Print("- R: CONSTRUCTOR callSignature functionBody -> classElement"); }
#line 3859 "parser.tab.cpp"
    break;

  case 238: /* classElement: propertyName ';'  */
#line 516 "parser.y"
                       { Print("- R: propertyName ';' -> classElement"); }
#line 3865 "parser.tab.cpp"
    break;

  case 239: /* classElement: propertyName typeAnnotation ';'  */
#line 517 "parser.y"
                                      { Print("- R: propertyName typeAnnotation ';' -> classElement"); }
#line 3871 "parser.tab.cpp"
    break;

  case 240: /* classElement: propertyName initializer ';'  */
#line 518 "parser.y"
                                   { Print("- R: propertyName initializer ';' -> classElement"); }
#line 3877 "parser.tab.cpp"
    break;

  case 241: /* classElement: propertyName typeAnnotation initializer ';'  */
#line 519 "parser.y"
                                                  { Print("- R: propertyName typeAnnotation initializer ';' -> classElement"); }
#line 3883 "parser.tab.cpp"
    break;

  case 242: /* classElement: propertyName callSignature functionBody  */
#line 522 "parser.y"
                                              { Print("- R: propertyName callSignature functionBody -> classElement"); }
#line 3889 "parser.tab.cpp"
    break;

  case 243: /* classElement: GET propertyName '(' ')' functionBody  */
#line 525 "parser.y"
                                            { Print("- R: GET propertyName '(' ')' functionBody -> classElement"); }
#line 3895 "parser.tab.cpp"
    break;

  case 244: /* classElement: GET propertyName '(' ')' typeAnnotation functionBody  */
#line 526 "parser.y"
                                                           { Print("- R: GET propertyName '(' ')' typeAnnotation functionBody -> classElement"); }
#line 3901 "parser.tab.cpp"
    break;

  case 245: /* classElement: SET propertyName callSignature functionBody  */
#line 527 "parser.y"
                                                  { Print("- R: SET propertyName callSignature functionBody -> classElement"); }
#line 3907 "parser.tab.cpp"
    break;

  case 246: /* propertyName: identifier  */
#line 531 "parser.y"
                 { Print("- R: identifier -> propertyName"); }
#line 3913 "parser.tab.cpp"
    break;

  case 247: /* propertyName: STRING_LIT  */
#line 532 "parser.y"
                 { Print("- R: STRING_LIT -> propertyName"); }
#line 3919 "parser.tab.cpp"
    break;

  case 248: /* propertyName: INT_LIT  */
#line 533 "parser.y"
              { Print("- R: INT_LIT -> propertyName"); }
#line 3925 "parser.tab.cpp"
    break;

  case 249: /* propertyName: FLOAT_LIT  */
#line 534 "parser.y"
                { Print("- R: FLOAT_LIT -> propertyName"); }
#line 3931 "parser.tab.cpp"
    break;

  case 250: /* propertyName: '[' singleExpression ']'  */
#line 535 "parser.y"
                               { Print("- R: '[' singleExpression ']' -> propertyName"); }
#line 3937 "parser.tab.cpp"
    break;

  case 251: /* propertyName: ENDL_BRACKET_OPEN singleExpression ']'  */
#line 536 "parser.y"
                                             { Print("- R: ENDL_BRACKET_OPEN singleExpression ']' -> propertyName"); }
#line 3943 "parser.tab.cpp"
    break;

  case 252: /* identifier: ID  */
#line 540 "parser.y"
         { Print("- R: ID -> identifier"); }
#line 3949 "parser.tab.cpp"
    break;

  case 253: /* identifier: ASYNC  */
#line 541 "parser.y"
            { Print("- R: ASYNC -> identifier"); }
#line 3955 "parser.tab.cpp"
    break;

  case 254: /* identifier: AS  */
#line 542 "parser.y"
         { Print("- R: AS -> identifier"); }
#line 3961 "parser.tab.cpp"
    break;

  case 255: /* identifier: FROM  */
#line 543 "parser.y"
           { Print("- R: FROM -> identifier"); }
#line 3967 "parser.tab.cpp"
    break;

  case 256: /* identifier: YIELD  */
#line 544 "parser.y"
            { Print("- R: YIELD -> identifier"); }
#line 3973 "parser.tab.cpp"
    break;

  case 257: /* identifier: ANY  */
#line 545 "parser.y"
          { Print("- R: ANY -> identifier"); }
#line 3979 "parser.tab.cpp"
    break;

  case 258: /* identifier: NUMBER  */
#line 546 "parser.y"
             { Print("- R: NUMBER -> identifier"); }
#line 3985 "parser.tab.cpp"
    break;

  case 259: /* identifier: BOOLEAN  */
#line 547 "parser.y"
              { Print("- R: BOOLEAN -> identifier"); }
#line 3991 "parser.tab.cpp"
    break;

  case 260: /* identifier: STRING  */
#line 548 "parser.y"
             { Print("- R: STRING -> identifier"); }
#line 3997 "parser.tab.cpp"
    break;

  case 261: /* identifier: UNIQUE  */
#line 549 "parser.y"
             { Print("- R: UNIQUE -> identifier"); }
#line 4003 "parser.tab.cpp"
    break;

  case 262: /* identifier: SYMBOL  */
#line 550 "parser.y"
             { Print("- R: SYMBOL -> identifier"); }
#line 4009 "parser.tab.cpp"
    break;

  case 263: /* identifier: NEVER  */
#line 551 "parser.y"
            { Print("- R: NEVER -> identifier"); }
#line 4015 "parser.tab.cpp"
    break;

  case 264: /* identifier: UNDEFINED  */
#line 552 "parser.y"
                { Print("- R: UNDEFINED -> identifier"); }
#line 4021 "parser.tab.cpp"
    break;

  case 265: /* identifier: OBJECT  */
#line 553 "parser.y"
             { Print("- R: OBJECT -> identifier"); }
#line 4027 "parser.tab.cpp"
    break;

  case 266: /* identifier: KEYOF  */
#line 554 "parser.y"
            { Print("- R: KEYOF -> identifier"); }
#line 4033 "parser.tab.cpp"
    break;

  case 267: /* identifier: NAMESPACE  */
#line 555 "parser.y"
                { Print("- R: NAMESPACE -> identifier"); }
#line 4039 "parser.tab.cpp"
    break;

  case 268: /* identifier: ABSTRACT  */
#line 556 "parser.y"
               { Print("- R: ABSTRACT -> identifier"); }
#line 4045 "parser.tab.cpp"
    break;

  case 269: /* identifier: REQUIRE  */
#line 557 "parser.y"
              { Print("- R: REQUIRE -> identifier"); }
#line 4051 "parser.tab.cpp"
    break;


#line 4055 "parser.tab.cpp"

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

#line 560 "parser.y"



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


