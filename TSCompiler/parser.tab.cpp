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

extern void rescanTokenString(const char *s);
extern void doWhileASI();
extern int yylex();

void yyerror(const char *s);
int yyfilter(int yychar, int yyn, int yystate, short *yyssp);

int isInFunctionBody = 0; // need for return stmt
int isInIterationBody = 0; // need for continue & break stmt
int isInForHeader = 0;

int syntaxErrorCounter = 0;

#line 96 "parser.tab.cpp"

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
  YYSYMBOL_statementSep = 130,             /* statementSep  */
  YYSYMBOL_initializer = 131,              /* initializer  */
  YYSYMBOL_type = 132,                     /* type  */
  YYSYMBOL_unionOrIntersectionOrPrimaryType = 133, /* unionOrIntersectionOrPrimaryType  */
  YYSYMBOL_primaryType = 134,              /* primaryType  */
  YYSYMBOL_tupleTypeElements = 135,        /* tupleTypeElements  */
  YYSYMBOL_predefinedType = 136,           /* predefinedType  */
  YYSYMBOL_typeAnnotation = 137,           /* typeAnnotation  */
  YYSYMBOL_arrayLiteral = 138,             /* arrayLiteral  */
  YYSYMBOL_elementList = 139,              /* elementList  */
  YYSYMBOL_arrayElement = 140,             /* arrayElement  */
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
  YYSYMBOL_153_4 = 153,                    /* $@4  */
  YYSYMBOL_154_5 = 154,                    /* $@5  */
  YYSYMBOL_155_6 = 155,                    /* $@6  */
  YYSYMBOL_156_7 = 156,                    /* $@7  */
  YYSYMBOL_157_8 = 157,                    /* $@8  */
  YYSYMBOL_158_9 = 158,                    /* $@9  */
  YYSYMBOL_159_10 = 159,                   /* $@10  */
  YYSYMBOL_160_11 = 160,                   /* $@11  */
  YYSYMBOL_161_12 = 161,                   /* $@12  */
  YYSYMBOL_162_13 = 162,                   /* $@13  */
  YYSYMBOL_163_14 = 163,                   /* $@14  */
  YYSYMBOL_continueStatement = 164,        /* continueStatement  */
  YYSYMBOL_breakStatement = 165,           /* breakStatement  */
  YYSYMBOL_returnStatement = 166,          /* returnStatement  */
  YYSYMBOL_labelledStatement = 167,        /* labelledStatement  */
  YYSYMBOL_blockStatement = 168,           /* blockStatement  */
  YYSYMBOL_switchStatement = 169,          /* switchStatement  */
  YYSYMBOL_caseClauseList = 170,           /* caseClauseList  */
  YYSYMBOL_caseClause = 171,               /* caseClause  */
  YYSYMBOL_defaultClause = 172,            /* defaultClause  */
  YYSYMBOL_functionDeclaration = 173,      /* functionDeclaration  */
  YYSYMBOL_functionBody = 174,             /* functionBody  */
  YYSYMBOL_175_15 = 175,                   /* $@15  */
  YYSYMBOL_callSignature = 176,            /* callSignature  */
  YYSYMBOL_parameterList = 177,            /* parameterList  */
  YYSYMBOL_parameter = 178,                /* parameter  */
  YYSYMBOL_requiredParameter = 179,        /* requiredParameter  */
  YYSYMBOL_optionalParameter = 180,        /* optionalParameter  */
  YYSYMBOL_restParameter = 181,            /* restParameter  */
  YYSYMBOL_classDeclaration = 182,         /* classDeclaration  */
  YYSYMBOL_classHeritage = 183,            /* classHeritage  */
  YYSYMBOL_classTail = 184,                /* classTail  */
  YYSYMBOL_classElementList = 185,         /* classElementList  */
  YYSYMBOL_classElement = 186,             /* classElement  */
  YYSYMBOL_propertyName = 187,             /* propertyName  */
  YYSYMBOL_identifier = 188                /* identifier  */
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
#define YYFINAL  103
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2350

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  123
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  254
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  438

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
       0,    87,    87,    97,    98,   102,   103,   104,   105,   106,
     107,   108,   109,   109,   114,   114,   119,   119,   124,   125,
     126,   127,   131,   135,   141,   142,   143,   147,   148,   149,
     153,   154,   155,   156,   157,   161,   162,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   183,   188,   189,   193,   194,   195,   199,   200,   206,
     207,   211,   212,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   276,   277,   279,   280,   282,   284,   286,   287,
     289,   290,   291,   293,   297,   298,   299,   303,   304,   308,
     309,   315,   319,   320,   324,   325,   326,   327,   331,   332,
     333,   339,   340,   344,   344,   344,   345,   345,   346,   346,
     346,   347,   347,   347,   348,   348,   348,   349,   349,   349,
     353,   354,   358,   359,   363,   364,   368,   372,   373,   377,
     378,   379,   380,   384,   385,   389,   390,   394,   395,   401,
     405,   406,   406,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   423,   424,   428,   429,   433,   434,   438,
     439,   440,   441,   445,   446,   452,   453,   457,   461,   462,
     466,   467,   471,   474,   475,   476,   477,   480,   483,   484,
     485,   489,   490,   491,   492,   493,   494,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515
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
  "statementListItem", "$@1", "$@2", "$@3", "statementSep", "initializer",
  "type", "unionOrIntersectionOrPrimaryType", "primaryType",
  "tupleTypeElements", "predefinedType", "typeAnnotation", "arrayLiteral",
  "elementList", "arrayElement", "expressionListOpt", "expressionList",
  "singleExpression", "arguments", "argumentList", "argument",
  "varStatement", "varDeclarationList", "varDeclaration", "varModifier",
  "ifStatement", "iterationStatement", "$@4", "$@5", "$@6", "$@7", "$@8",
  "$@9", "$@10", "$@11", "$@12", "$@13", "$@14", "continueStatement",
  "breakStatement", "returnStatement", "labelledStatement",
  "blockStatement", "switchStatement", "caseClauseList", "caseClause",
  "defaultClause", "functionDeclaration", "functionBody", "$@15",
  "callSignature", "parameterList", "parameter", "requiredParameter",
  "optionalParameter", "restParameter", "classDeclaration",
  "classHeritage", "classTail", "classElementList", "classElement",
  "propertyName", "identifier", YY_NULLPTR
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

#define YYTABLE_NINF (-189)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1521,  -330,  -330,  -330,  -330,   -74,  1841,  1841,  -330,   -66,
     -62,  1841,  1841,   -39,  1695,  -330,  -330,  1695,  -330,  -330,
    -330,  -330,  -330,  -330,  -330,  -330,  -330,  -330,  -330,  -330,
    -330,  -330,  -330,  -330,  -330,  -330,  -330,  -330,  -330,  -330,
    -330,  -330,  -330,  1695,  1695,  1695,  1695,  1695,  1695,  1695,
    1695,  1657,  1657,  1695,  -330,  1033,    65,  1156,  -330,  -330,
     -31,  2111,   -32,  1841,  -330,  -330,  -330,  -330,  -330,  -330,
    -330,  -330,  -330,  -330,    15,  1695,    36,    -6,  1521,  1695,
      56,  -330,  -330,  1695,  2111,  -330,   115,   115,   115,   115,
     115,   115,   115,   115,   115,  1695,   -33,  -330,  2111,    -7,
     -24,  -330,  1277,  -330,  -330,  1695,  -330,  -330,  -330,  -330,
    -330,  1695,  1695,  1695,  1695,  1695,  1695,  1695,  1695,  1695,
    1695,  1695,  1695,  1695,  1695,  1695,  1695,  1695,  1695,  1695,
    1695,  1695,  1695,  1695,  1695,  1695,  1695,  1695,  1695,  1695,
    1695,  1695,  1695,  1695,  1695,  1695,  1695,  1695,  1695,  1695,
    1695,  1695,  1695,  1841,  1695,  1695,  1695,  1559,  -330,  -330,
     104,  -330,    52,   -32,   -32,   -32,  1521,   -23,   555,    57,
    1841,   108,    58,  -330,   166,   -22,  1695,    69,  1695,    69,
     -21,  2111,  1657,  -330,  -330,  -330,  -330,  2111,  2232,  2232,
    2232,  2232,  2232,  2232,  2232,  2232,  2232,  2232,  2232,  2232,
    2232,  2232,  2232,  2232,  1855,   890,  1011,   309,  1132,  1252,
    1373,   543,   543,   543,   543,  1553,  1553,  1553,  1553,  1553,
    1553,   194,   194,   194,    71,    71,   187,   187,   187,   187,
    -330,     1,     3,    68,  1695,  -330,  2111,   -20,  -330,  1841,
    1695,   204,   121,  -330,  -330,  -330,  -330,  1521,  1695,   111,
     -19,  -330,  -330,  -330,    73,   -12,    72,  -330,  -330,  1749,
    1749,    36,  -330,  -330,  -330,  1695,  1695,  -330,   170,  -330,
     -28,  -330,  -330,    75,  -330,    76,   134,  1841,  2175,  1841,
      94,  -330,  1695,  -330,  -330,  2111,     6,  -330,  -330,  2111,
    -330,  -330,  -330,  -330,  -330,  -330,  -330,  -330,  -330,  -330,
    -330,  -330,  -330,  -330,  1795,  1795,   204,   204,  -330,    49,
     102,  -330,  1695,   213,  1919,  -330,   702,   111,   111,  1695,
     111,  -330,   159,  -330,  1521,   107,    36,    57,  1983,  2047,
    -330,  -330,  -330,   106,   -17,    57,  1695,  1521,  1695,   -29,
    1695,   132,    -5,   769,  -330,  -330,    49,    49,  -330,     7,
     116,  1795,  1795,  1778,  2111,  1521,  -330,   111,  -330,   117,
    -330,  -330,  2111,  -330,  -330,  1399,   118,    57,  -330,  -330,
    -330,  -330,  -330,   114,  -330,   -18,  -330,   126,  1695,   661,
    1695,  1695,  -330,    -1,  -330,   204,  -330,  -330,   153,  -330,
    -330,    44,  -330,  -330,   111,  -330,   -46,  -330,  -330,  -330,
    1695,   128,  -330,   -14,    -3,   178,  -330,  -330,     4,  -330,
    -330,  -330,    57,  -330,   -32,   139,  1695,  1521,  -330,   510,
     789,  -330,     5,  -330,  -330,  -330,   142,  -330,  1521,   667,
     911,  -330,  1521,  -330,  -330,  -330,  1521,  -330
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,   148,   149,   150,     0,     0,     0,   153,     0,
       0,   170,   172,     0,   174,    65,    64,     0,   238,   239,
     240,   241,   251,   252,   253,   254,   242,   243,   244,   245,
     248,   249,   246,   247,   250,    68,    66,    67,    72,    70,
      71,   237,    69,     0,     0,     0,     0,     0,     0,     0,
       0,    54,    54,     0,     6,     0,     0,     0,     3,   130,
       0,    61,     0,     0,     9,    11,    12,    14,    16,    18,
      19,    10,    20,    21,    63,     0,     0,     0,     0,     0,
     158,   171,   173,     0,   175,    63,   133,    81,    82,    79,
      80,    74,    73,    75,    76,     0,     0,    55,    57,     0,
       0,   177,     0,     1,     4,     0,    22,     7,   124,    77,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   127,     8,
     141,   142,   144,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   215,     0,     0,    59,     0,     0,     0,
       0,    58,    54,    52,    53,   126,   178,    62,    97,   101,
     102,   108,    98,    99,   100,   103,   104,   112,   105,   106,
     107,   109,   110,   111,     0,   121,   113,   114,   115,   116,
     117,    91,    92,    93,    94,    89,    88,    96,    95,   122,
     123,   118,   119,   120,    83,    84,    85,    86,    87,    90,
     129,     0,     0,   128,     0,   134,   139,     0,   137,     0,
       0,     0,   145,    13,    15,    17,   176,     0,     0,   193,
       0,   203,   205,   206,     0,   207,   191,   189,   217,     0,
       0,     0,   232,   233,   234,     0,     0,   218,     0,   220,
       0,   231,   216,     0,   156,     0,    60,     0,     0,     0,
       0,    56,     0,   131,   132,   140,     0,   135,   143,   146,
      37,    38,    40,    39,    41,    43,    44,    42,    50,    46,
      47,    45,    48,    49,     0,     0,     0,     0,    51,    24,
      29,    31,     0,   151,   213,   194,     0,   197,   195,     0,
     209,   211,   208,   190,     0,     0,     0,     0,     0,     0,
     219,   221,   223,     0,     0,     0,     0,     0,    59,     0,
       0,     0,     0,   125,   136,   138,    25,    26,    35,     0,
       0,     0,     0,     0,   147,     0,   214,   201,   204,     0,
     198,   196,    23,   210,   212,     0,     0,     0,   222,   235,
     236,   225,   224,     0,   227,     0,   157,     0,    59,   123,
       0,     0,   179,     0,   183,     0,    34,    30,    27,    28,
      32,     0,   152,   202,   199,   192,     0,   230,   226,   154,
      59,     0,   165,     0,     0,     0,   180,   184,     0,    36,
      33,   200,     0,   228,     0,     0,    59,     0,   168,     0,
       0,   181,     0,   229,   155,   159,     0,   166,     0,     0,
       0,   182,     0,   162,   169,   160,     0,   163
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -330,  -330,   -53,   -56,  -330,  -330,  -330,   -52,  -253,  -281,
    -175,   -91,  -330,  -330,  -234,  -330,   -49,  -330,  -329,   -48,
     339,   -16,  -330,  -330,  -330,   -13,  -226,   -10,  -330,  -330,
    -330,  -330,  -330,  -330,  -330,  -330,  -330,  -330,  -330,  -330,
    -330,  -330,  -330,  -330,  -330,  -330,  -330,  -145,  -313,  -330,
    -330,  -319,  -330,  -241,  -330,   -51,  -330,  -330,   -50,  -330,
    -330,    95,  -330,     8,   -96,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    56,    57,    58,   163,   164,   165,   107,   321,   308,
     309,   310,   349,   311,   242,    59,    96,    97,   275,    60,
      61,   158,   237,   238,    62,   160,   161,    63,    64,    65,
      78,   414,   337,   176,   432,   177,   436,   178,   417,   179,
     428,    66,    67,    68,    69,    70,    71,   383,   384,   408,
      72,   257,   324,   169,   250,   251,   252,   253,   254,    73,
     172,   173,   268,   269,   270,    85
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      74,   104,   102,    99,   170,   100,    76,    77,   368,   377,
     159,    81,    82,   288,   381,   315,   374,   333,   381,   405,
     327,   322,   174,   381,   381,   348,   350,   167,   182,   335,
     105,   175,   239,   241,   319,   180,   334,   105,   105,   105,
     105,   286,   316,   105,    75,   319,   104,   105,   397,   401,
     319,   241,    79,   341,   182,    74,    80,    74,   105,  -161,
    -161,  -161,   105,   162,   105,   103,   320,   241,   385,   364,
     407,   415,     2,     3,     4,   256,   419,   413,    74,    83,
     356,   373,   183,   360,   361,   367,   363,   426,   106,   106,
     168,   378,   332,   423,   166,   185,   247,   274,   280,   287,
     317,   399,    74,   372,   409,   418,   231,   232,   184,   407,
     246,   243,   244,   245,   240,   171,   283,   382,   284,   259,
     260,   406,   386,   393,   157,   344,   421,   431,   276,   346,
     347,   241,   351,   281,   352,    18,    19,    20,    21,    22,
     261,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,   230,   168,   262,   263,   264,   353,   410,
     411,    41,   412,   325,   326,   239,    74,   277,   255,   279,
     258,   271,   149,   150,   151,   152,   388,   389,   256,   171,
     273,   259,   260,   312,   153,   154,   157,   155,   156,   157,
     241,   313,   318,   336,   323,   105,   338,    18,    19,    20,
      21,    22,   261,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,   342,   353,   262,   263,   264,
     355,   319,   265,    41,   266,   366,   371,   380,   153,   154,
     267,   155,   156,   157,   398,   387,   394,   396,   352,   162,
     290,   291,   292,   293,   294,   295,   400,    74,   416,   296,
     297,   298,   299,   300,   301,   302,   303,   420,   425,   271,
     271,   433,   391,   422,   339,   358,   359,   272,   271,     0,
     345,   365,     0,     0,     0,     0,   331,   162,     0,   162,
       0,   376,     0,     0,   265,     0,   266,   304,   375,   305,
     276,   152,   330,   147,   148,   149,   150,   151,   152,   392,
     153,   154,     0,   155,   156,   157,     0,   153,   154,   104,
     155,   156,   157,     0,     0,     0,   255,     0,   306,     0,
       0,     0,   307,     0,    74,     0,     0,     0,     0,     0,
     276,     0,   403,   404,     0,     0,     0,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   276,    84,     0,    74,    86,     0,     0,     0,
       0,   427,   424,     0,     0,    74,   429,   430,   276,     0,
       0,     0,   434,   104,   104,     0,   435,     0,     0,     0,
     437,     0,    87,    88,    89,    90,    91,    92,    93,    94,
      98,    98,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,     0,     0,    74,     0,    74,
      74,     0,   153,   154,     0,   155,   156,   157,    74,    74,
      74,     0,    74,     0,   181,     0,    74,     0,     0,     0,
       0,     0,     0,     0,   187,     0,     0,     0,     0,     0,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,     0,     0,     0,   233,   236,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     2,     3,     4,     5,   278,     6,     7,
       0,    98,     0,     8,     9,    10,    11,    12,    13,  -185,
    -185,    14,    15,    16,    17,     0,     0,    18,    19,    20,
      21,    22,     0,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,     0,     0,    35,    36,    37,
      38,    39,    40,    41,     0,    42,    43,    44,    45,    46,
       0,     0,     0,   285,     0,     0,     0,     0,     0,   289,
     248,     0,    18,    19,    20,    21,    22,   314,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       0,     0,     0,     0,   328,   329,     0,     0,    41,    47,
      48,     0,     0,     0,     0,    49,    50,     0,     0,     0,
       0,   343,     0,     0,    51,     0,    52,     0,    53,     0,
      54,    55,  -185,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,     0,
       0,   354,     0,     0,     0,     0,   153,   154,   362,   155,
     156,   157,     0,     0,     0,     0,     0,     0,     1,     0,
       2,     3,     4,     5,   249,     6,     7,     0,     0,   379,
       8,     9,    10,    11,    12,    13,  -186,  -186,    14,    15,
      16,    17,     0,     0,    18,    19,    20,    21,    22,     0,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     0,     0,    35,    36,    37,    38,    39,    40,
      41,     0,    42,    43,    44,    45,    46,   248,     0,    18,
      19,    20,    21,    22,     0,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     0,     0,     0,
       0,     0,     0,     0,     0,    41,     0,   144,   145,   146,
     147,   148,   149,   150,   151,   152,    47,    48,     0,     0,
       0,     0,    49,    50,   153,   154,     0,   155,   156,   157,
     402,    51,     0,    52,     0,    53,     0,    54,    55,  -186,
       1,     0,     2,     3,     4,     5,     0,     6,     7,     0,
       0,     0,     8,     9,    10,    11,    12,    13,  -187,     0,
      14,    15,    16,    17,     0,     0,    18,    19,    20,    21,
      22,   357,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,     0,    35,    36,    37,    38,
      39,    40,    41,     0,    42,    43,    44,    45,    46,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,     0,     0,     0,     0,     0,
       0,     0,   153,   154,     0,   155,   156,   157,    47,    48,
       0,     0,     0,     0,    49,    50,     0,     0,     0,     0,
       0,     0,     0,    51,     0,    52,     0,    53,     0,    54,
      55,  -187,     1,     0,     2,     3,     4,     5,     0,     6,
       7,     0,     0,     0,     8,     9,    10,    11,    12,    13,
    -188,     0,    14,    15,    16,    17,     0,     0,    18,    19,
      20,    21,    22,     0,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,     0,     0,    35,    36,
      37,    38,    39,    40,    41,     0,    42,    43,    44,    45,
      46,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,     0,     0,     0,     0,     0,
       0,     0,     0,   153,   154,     0,   155,   156,   157,     0,
      47,    48,     0,     0,     0,     0,    49,    50,     0,     0,
       0,     0,     0,     0,     0,    51,     0,    52,     0,    53,
       0,    54,    55,  -188,     1,     0,     2,     3,     4,     5,
       0,     6,     7,     0,     0,     0,     8,     9,    10,    11,
      12,    13,     0,     0,    14,    15,    16,    17,     0,     0,
      18,    19,    20,    21,    22,     0,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,     0,     0,
      35,    36,    37,    38,    39,    40,    41,     0,    42,    43,
      44,    45,    46,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     0,     0,     0,     0,
       0,     0,     0,     0,   153,   154,     0,   155,   156,   157,
       0,     0,    47,    48,     0,     0,     0,     0,    49,    50,
       0,     0,     0,     0,     0,     0,     0,    51,     0,    52,
       0,    53,     0,    54,    55,   101,    -2,     1,     0,     2,
       3,     4,     5,     0,     6,     7,     0,     0,     0,     8,
       9,    10,    11,    12,    13,     0,     0,    14,    15,    16,
      17,     0,     0,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,     0,     0,    35,    36,    37,    38,    39,    40,    41,
       0,    42,    43,    44,    45,    46,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,     0,     0,     0,
       0,     0,     0,     0,     0,   153,   154,     0,   155,   156,
     157,     0,     0,     0,     0,    47,    48,     0,     0,     0,
       0,    49,    50,     0,     0,     0,     0,     0,     0,     0,
      51,     0,    52,     0,    53,     0,    54,    55,     1,     0,
       2,     3,     4,     5,     0,     6,     7,     0,     0,     0,
       8,     9,    10,    11,    12,    13,     0,     0,    14,    15,
      16,    17,     0,     0,    18,    19,    20,    21,    22,     0,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     0,     0,    35,    36,    37,    38,    39,    40,
      41,     0,    42,    43,    44,    45,    46,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,     0,     0,     0,
       0,     0,     0,     0,     0,   153,   154,     0,   155,   156,
     157,     0,     0,     0,     0,     0,    47,    48,     0,     0,
       0,     0,    49,    50,     0,     0,     0,     0,     0,     0,
       0,    51,     0,    52,     0,    53,     0,    54,    55,   186,
       1,     0,     2,     3,     4,     5,     0,     6,     7,     0,
       0,     0,     8,     9,    10,    11,    12,    13,     0,     0,
      14,    15,    16,    17,     0,     0,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,     0,    35,    36,    37,    38,
      39,    40,    41,     0,    42,    43,    44,    45,    46,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,     0,
       0,     0,     0,     0,     0,     0,   153,   154,     0,   155,
     156,   157,     0,     0,     0,     0,     0,     0,    47,    48,
       0,     0,     0,     0,    49,    50,     0,     0,     0,     0,
       0,     0,     0,    51,     0,    52,     0,    53,     0,    54,
      55,   395,     1,     0,     2,     3,     4,     5,     0,     6,
       7,     0,     0,     0,     8,     9,    10,    11,    12,    13,
       0,     0,    14,    15,    16,    17,     0,     0,    18,    19,
      20,    21,    22,     0,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,     0,     0,    35,    36,
      37,    38,    39,    40,    41,     0,    42,    43,    44,    45,
      46,    15,    16,    17,   234,     0,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,     0,    35,    36,    37,    38,
      39,    40,    41,     0,    42,    43,    44,    45,    46,     0,
      47,    48,     0,     0,     0,     0,    49,    50,     0,     0,
       0,     0,     0,     0,     0,    51,     0,    52,     0,    53,
       0,    54,    55,     0,     0,     0,     0,     0,     0,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    47,    48,
       0,     0,     0,     0,    49,    50,   153,   154,     0,   155,
     156,   157,     0,    51,     0,    52,     0,    53,   235,    15,
      16,    17,    95,     0,    18,    19,    20,    21,    22,     0,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     0,     0,    35,    36,    37,    38,    39,    40,
      41,     0,    42,    43,    44,    45,    46,    15,    16,    17,
       0,     0,    18,    19,    20,    21,    22,     0,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       0,     0,    35,    36,    37,    38,    39,    40,    41,     0,
      42,    43,    44,    45,    46,     0,    47,    48,     0,     0,
       0,     0,    49,    50,     0,     0,     0,     0,     0,     0,
       0,    51,     0,    52,     0,    53,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    47,    48,   262,   263,   264,     0,
      49,    50,    41,     0,     0,     0,     0,     0,     0,    51,
       0,    52,     0,    53,   290,   291,   292,   293,   294,   295,
       0,     0,     0,   296,   297,   298,   299,   300,   301,   302,
     303,   290,   291,   292,   293,   294,   295,     0,     0,     0,
     296,   297,   298,   299,   300,   301,   302,   303,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   265,     0,   266,     0,     0,    18,    19,
      20,    21,    22,     0,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,     0,     0,     0,     0,
       0,     0,   306,   390,    41,     0,   307,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   306,
     108,   109,   110,   307,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   282,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
       0,     0,     0,     0,     0,     0,     0,     0,   153,   154,
       0,   155,   156,   157,   108,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   241,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,     0,     0,     0,     0,     0,
       0,     0,   153,   154,     0,   155,   156,   157,   108,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,     0,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,     0,
       0,     0,     0,     0,     0,     0,   153,   154,   369,   155,
     156,   157,   108,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,     0,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,     0,     0,     0,     0,     0,     0,     0,
     153,   154,   370,   155,   156,   157,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
       0,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     0,     0,     0,     0,
       0,     0,     0,     0,   153,   154,     0,   155,   156,   157,
     108,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,     0,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     340,   144,   145,   146,   147,   148,   149,   150,   151,   152,
       0,     0,     0,     0,     0,     0,     0,     0,   153,   154,
       0,   155,   156,   157,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,     0,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,     0,     0,     0,
       0,     0,     0,     0,     0,   153,   154,     0,   155,   156,
     157
};

static const yytype_int16 yycheck[] =
{
       0,    57,    55,    52,    10,    53,     6,     7,   327,   338,
      62,    11,    12,   239,    19,   249,   335,   270,    19,    20,
     261,   255,    78,    19,    19,   306,   307,    75,    61,   270,
      61,    79,    61,    79,    62,    83,   270,    61,    61,    61,
      61,    61,    61,    61,   118,    62,   102,    61,   367,   378,
      62,    79,   118,   279,    61,    55,   118,    57,    61,     3,
       4,     5,    61,    63,    61,     0,    78,    79,    61,   322,
     383,   400,     3,     4,     5,   121,    79,   396,    78,   118,
     314,   334,   115,   317,   318,   326,   320,   416,   120,   120,
     118,   120,   120,   412,    79,   119,   119,   119,   119,   119,
     119,   119,   102,   120,   385,   119,   154,   155,   115,   422,
     166,   163,   164,   165,    62,   121,   115,   122,   115,    11,
      12,   122,   115,   357,   118,   119,   122,   122,   176,   304,
     305,    79,    83,   182,    85,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,   153,   118,    47,    48,    49,   114,   115,
     394,    53,   396,   259,   260,    61,   166,   177,   168,   179,
     170,   171,   101,   102,   103,   104,   351,   352,   121,   121,
      14,    11,    12,    62,   113,   114,   118,   116,   117,   118,
      79,   247,   119,   118,   122,    61,   120,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,   121,   114,    47,    48,    49,
       7,    62,   114,    53,   116,   118,   120,    95,   113,   114,
     122,   116,   117,   118,   120,   119,   119,   119,    85,   239,
      36,    37,    38,    39,    40,    41,   120,   247,   120,    45,
      46,    47,    48,    49,    50,    51,    52,    79,   119,   259,
     260,   119,   353,   408,   277,   316,   316,   172,   268,    -1,
     286,   324,    -1,    -1,    -1,    -1,   268,   277,    -1,   279,
      -1,   337,    -1,    -1,   114,    -1,   116,    83,   336,    85,
     338,   104,   122,    99,   100,   101,   102,   103,   104,   355,
     113,   114,    -1,   116,   117,   118,    -1,   113,   114,   365,
     116,   117,   118,    -1,    -1,    -1,   316,    -1,   114,    -1,
      -1,    -1,   118,    -1,   324,    -1,    -1,    -1,    -1,    -1,
     378,    -1,   380,   381,    -1,    -1,    -1,   337,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   400,    14,    -1,   355,    17,    -1,    -1,    -1,
      -1,   417,   414,    -1,    -1,   365,   419,   420,   416,    -1,
      -1,    -1,   428,   429,   430,    -1,   432,    -1,    -1,    -1,
     436,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,    -1,   417,    -1,   419,
     420,    -1,   113,   114,    -1,   116,   117,   118,   428,   429,
     430,    -1,   432,    -1,    95,    -1,   436,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,   178,     8,     9,
      -1,   182,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    27,    28,    29,
      30,    31,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,    -1,   240,
      25,    -1,    27,    28,    29,    30,    31,   248,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    -1,   265,   266,    -1,    -1,    53,    99,
     100,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,
      -1,   282,    -1,    -1,   114,    -1,   116,    -1,   118,    -1,
     120,   121,   122,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
      -1,   312,    -1,    -1,    -1,    -1,   113,   114,   319,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,   119,     8,     9,    -1,    -1,   340,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    28,    29,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    25,    -1,    27,
      28,    29,    30,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    99,   100,    -1,    -1,
      -1,    -1,   105,   106,   113,   114,    -1,   116,   117,   118,
     119,   114,    -1,   116,    -1,   118,    -1,   120,   121,   122,
       1,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    13,    14,    15,    16,    17,    18,    19,    -1,
      21,    22,    23,    24,    -1,    -1,    27,    28,    29,    30,
      31,   119,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,   114,    -1,   116,   117,   118,    99,   100,
      -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,   116,    -1,   118,    -1,   120,
     121,   122,     1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    13,    14,    15,    16,    17,    18,
      19,    -1,    21,    22,    23,    24,    -1,    -1,    27,    28,
      29,    30,    31,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,    -1,   116,   117,   118,    -1,
      99,   100,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    -1,   116,    -1,   118,
      -1,   120,   121,   122,     1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    13,    14,    15,    16,
      17,    18,    -1,    -1,    21,    22,    23,    24,    -1,    -1,
      27,    28,    29,    30,    31,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,   114,    -1,   116,   117,   118,
      -1,    -1,    99,   100,    -1,    -1,    -1,    -1,   105,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,   116,
      -1,   118,    -1,   120,   121,   122,     0,     1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    13,
      14,    15,    16,    17,    18,    -1,    -1,    21,    22,    23,
      24,    -1,    -1,    27,    28,    29,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,   117,
     118,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,
      -1,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,    -1,   116,    -1,   118,    -1,   120,   121,     1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    -1,    -1,    21,    22,
      23,    24,    -1,    -1,    27,    28,    29,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,   117,
     118,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,
      -1,    -1,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,   116,    -1,   118,    -1,   120,   121,   122,
       1,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    13,    14,    15,    16,    17,    18,    -1,    -1,
      21,    22,    23,    24,    -1,    -1,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
      -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,   116,    -1,   118,    -1,   120,
     121,   122,     1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    13,    14,    15,    16,    17,    18,
      -1,    -1,    21,    22,    23,    24,    -1,    -1,    27,    28,
      29,    30,    31,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    22,    23,    24,    25,    -1,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    -1,
      99,   100,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    -1,   116,    -1,   118,
      -1,   120,   121,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    99,   100,
      -1,    -1,    -1,    -1,   105,   106,   113,   114,    -1,   116,
     117,   118,    -1,   114,    -1,   116,    -1,   118,   119,    22,
      23,    24,    25,    -1,    27,    28,    29,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    22,    23,    24,
      -1,    -1,    27,    28,    29,    30,    31,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    -1,    99,   100,    -1,    -1,
      -1,    -1,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,   116,    -1,   118,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    99,   100,    47,    48,    49,    -1,
     105,   106,    53,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,   116,    -1,   118,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,   116,    -1,    -1,    27,    28,
      29,    30,    31,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,
      -1,    -1,   114,   115,    53,    -1,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      55,    56,    57,   118,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
      -1,   116,   117,   118,    55,    56,    57,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,   114,    -1,   116,   117,   118,    55,    56,
      57,    -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,   116,
     117,   118,    55,    56,    57,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    -1,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   114,   115,   116,   117,   118,    55,    56,    57,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,   114,    -1,   116,   117,   118,
      55,    56,    57,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
      -1,   116,   117,   118,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    -1,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,   117,
     118
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
     106,   114,   116,   118,   120,   121,   124,   125,   126,   138,
     142,   143,   147,   150,   151,   152,   164,   165,   166,   167,
     168,   169,   173,   182,   188,   118,   188,   188,   153,   118,
     118,   188,   188,   118,   143,   188,   143,   143,   143,   143,
     143,   143,   143,   143,   143,    25,   139,   140,   143,   139,
     142,   122,   125,     0,   126,    61,   120,   130,    55,    56,
      57,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   113,   114,   116,   117,   118,   144,   130,
     148,   149,   188,   127,   128,   129,    79,   142,   118,   176,
      10,   121,   183,   184,   126,   142,   156,   158,   160,   162,
     142,   143,    61,   115,   115,   119,   122,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     188,   142,   142,   143,    25,   119,   143,   145,   146,    61,
      62,    79,   137,   130,   130,   130,   126,   119,    25,   119,
     177,   178,   179,   180,   181,   188,   121,   174,   188,    11,
      12,    32,    47,    48,    49,   114,   116,   122,   185,   186,
     187,   188,   184,    14,   119,   141,   142,   150,   143,   150,
     119,   139,    79,   115,   115,   143,    61,   119,   149,   143,
      36,    37,    38,    39,    40,    41,    45,    46,    47,    48,
      49,    50,    51,    52,    83,    85,   114,   118,   132,   133,
     134,   136,    62,   126,   143,   137,    61,   119,   119,    62,
      78,   131,   137,   122,   175,   187,   187,   176,   143,   143,
     122,   186,   120,   131,   137,   176,   118,   155,   120,   148,
      95,   149,   121,   143,   119,   144,   133,   133,   132,   135,
     132,    83,    85,   114,   143,     7,   137,   119,   178,   181,
     137,   137,   143,   137,   131,   125,   118,   176,   174,   115,
     115,   120,   120,   131,   174,   142,   126,   141,   120,   143,
      95,    19,   122,   170,   171,    61,   115,   119,   133,   133,
     115,   134,   126,   137,   119,   122,   119,   174,   120,   119,
     120,   141,   119,   142,   142,    20,   122,   171,   172,   132,
     115,   137,   137,   174,   154,   141,   120,   161,   119,    79,
      79,   122,   170,   174,   130,   119,   141,   126,   163,   125,
     125,   122,   157,   119,   126,   126,   159,   126
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   123,   124,   125,   125,   126,   126,   126,   126,   126,
     126,   126,   127,   126,   128,   126,   129,   126,   126,   126,
     126,   126,   130,   131,   132,   132,   132,   133,   133,   133,
     134,   134,   134,   134,   134,   135,   135,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   137,   138,   138,   139,   139,   139,   140,   140,   141,
     141,   142,   142,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   144,   144,   144,   145,   145,   146,
     146,   147,   148,   148,   149,   149,   149,   149,   150,   150,
     150,   151,   151,   153,   154,   152,   155,   152,   156,   157,
     152,   158,   159,   152,   160,   161,   152,   162,   163,   152,
     164,   164,   165,   165,   166,   166,   167,   168,   168,   169,
     169,   169,   169,   170,   170,   171,   171,   172,   172,   173,
     174,   175,   174,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   177,   177,   178,   178,   179,   179,   180,
     180,   180,   180,   181,   181,   182,   182,   183,   184,   184,
     185,   185,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   187,   187,   187,   187,   187,   187,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     2,     2,     1,
       1,     1,     0,     3,     0,     3,     0,     3,     1,     1,
       1,     1,     1,     2,     1,     2,     2,     3,     3,     1,
       3,     1,     3,     4,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     3,     0,     1,     3,     1,     2,     0,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     5,     3,     2,     3,     3,
       1,     4,     4,     2,     2,     3,     4,     1,     3,     1,
       2,     2,     1,     3,     1,     2,     3,     4,     1,     1,
       1,     5,     7,     0,     0,     9,     0,     6,     0,     0,
      11,     0,     0,    12,     0,     0,     9,     0,     0,    10,
       1,     2,     1,     2,     1,     2,     3,     2,     3,     6,
       7,     8,     9,     1,     2,     3,     4,     2,     3,     4,
       2,     0,     4,     2,     3,     3,     4,     3,     4,     5,
       6,     4,     5,     1,     3,     1,     1,     1,     2,     2,
       3,     2,     3,     2,     3,     3,     4,     2,     2,     3,
       1,     2,     3,     2,     3,     3,     4,     3,     5,     6,
       4,     1,     1,     1,     1,     3,     3,     1,     1,     1,
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
#line 87 "parser.y"
                    { 
        if ( syntaxErrorCounter > 0 ) {
            PrintError("Found " + std::to_string(syntaxErrorCounter) + " syntax errors. Fix them and rerun.");
            exit(1);
        }
        Print("- R: statementList -> script"); 
    }
#line 2388 "parser.tab.cpp"
    break;

  case 3: /* statementList: statementListItem  */
#line 97 "parser.y"
                        { Print("- R: statementListItem -> statementList"); }
#line 2394 "parser.tab.cpp"
    break;

  case 4: /* statementList: statementList statementListItem  */
#line 98 "parser.y"
                                      { Print("- R: statementList statementListItem -> statementList"); }
#line 2400 "parser.tab.cpp"
    break;

  case 6: /* statementListItem: ';'  */
#line 103 "parser.y"
                                    { Print("- R: ';' -> statementListItem"); }
#line 2406 "parser.tab.cpp"
    break;

  case 7: /* statementListItem: expressionList statementSep  */
#line 104 "parser.y"
                                    { Print("- R: expressionList statementSep -> statementListItem"); }
#line 2412 "parser.tab.cpp"
    break;

  case 8: /* statementListItem: varStatement statementSep  */
#line 105 "parser.y"
                                    { Print("- R: varStatement statementSep -> statementListItem"); }
#line 2418 "parser.tab.cpp"
    break;

  case 9: /* statementListItem: ifStatement  */
#line 106 "parser.y"
                                    { Print("- R: ifStatement -> statementListItem"); }
#line 2424 "parser.tab.cpp"
    break;

  case 10: /* statementListItem: switchStatement  */
#line 107 "parser.y"
                                    { Print("- R: switchStatement -> statementListItem"); }
#line 2430 "parser.tab.cpp"
    break;

  case 11: /* statementListItem: iterationStatement  */
#line 108 "parser.y"
                                    { Print("- R: iterationStatement -> statementListItem"); }
#line 2436 "parser.tab.cpp"
    break;

  case 12: /* $@1: %empty  */
#line 109 "parser.y"
                        {
        if ( !isInIterationBody ) { 
            yyerror("illegal continue statement"); 
        } 
    }
#line 2446 "parser.tab.cpp"
    break;

  case 13: /* statementListItem: continueStatement $@1 statementSep  */
#line 113 "parser.y"
                                    { Print("- R: continueStatement statementSep -> statementListItem");  }
#line 2452 "parser.tab.cpp"
    break;

  case 14: /* $@2: %empty  */
#line 114 "parser.y"
                     {
        if ( !isInIterationBody ) { 
            yyerror("illegal break statement"); 
        } 
    }
#line 2462 "parser.tab.cpp"
    break;

  case 15: /* statementListItem: breakStatement $@2 statementSep  */
#line 118 "parser.y"
                                    { Print("- R: breakStatement statementSep -> statementListItem"); }
#line 2468 "parser.tab.cpp"
    break;

  case 16: /* $@3: %empty  */
#line 119 "parser.y"
                      { 
        if ( !isInFunctionBody ) { 
            yyerror("illegal return statement"); 
        } 
    }
#line 2478 "parser.tab.cpp"
    break;

  case 17: /* statementListItem: returnStatement $@3 statementSep  */
#line 123 "parser.y"
                                    { Print("- R: returnStatement statementSep -> statementListItem"); }
#line 2484 "parser.tab.cpp"
    break;

  case 18: /* statementListItem: labelledStatement  */
#line 124 "parser.y"
                                    { Print("- R: labelledStatement -> statementListItem"); }
#line 2490 "parser.tab.cpp"
    break;

  case 19: /* statementListItem: blockStatement  */
#line 125 "parser.y"
                                    { Print("- R: blockStatement -> statementListItem"); }
#line 2496 "parser.tab.cpp"
    break;

  case 20: /* statementListItem: functionDeclaration  */
#line 126 "parser.y"
                                    { Print("- R: functionDeclaration -> statementListItem"); }
#line 2502 "parser.tab.cpp"
    break;

  case 21: /* statementListItem: classDeclaration  */
#line 127 "parser.y"
                                    { Print("- R: classDeclaration -> statementListItem"); }
#line 2508 "parser.tab.cpp"
    break;

  case 22: /* statementSep: ';'  */
#line 131 "parser.y"
          { Print("- R: ';' -> statementSep"); }
#line 2514 "parser.tab.cpp"
    break;

  case 23: /* initializer: '=' singleExpression  */
#line 135 "parser.y"
                           { Print("- R: '=' singleExpression -> initializer"); }
#line 2520 "parser.tab.cpp"
    break;

  case 24: /* type: unionOrIntersectionOrPrimaryType  */
#line 141 "parser.y"
                                       { Print("- R: unionOrIntersectionOrPrimaryType -> type"); }
#line 2526 "parser.tab.cpp"
    break;

  case 25: /* type: '|' unionOrIntersectionOrPrimaryType  */
#line 142 "parser.y"
                                           { Print("- R: '|' unionOrIntersectionOrPrimaryType -> type"); }
#line 2532 "parser.tab.cpp"
    break;

  case 26: /* type: '&' unionOrIntersectionOrPrimaryType  */
#line 143 "parser.y"
                                           { Print("- R: '&' unionOrIntersectionOrPrimaryType -> type"); }
#line 2538 "parser.tab.cpp"
    break;

  case 27: /* unionOrIntersectionOrPrimaryType: unionOrIntersectionOrPrimaryType '|' unionOrIntersectionOrPrimaryType  */
#line 147 "parser.y"
                                                                            { Print("- R: unionOrIntersectionOrPrimaryType '|' unionOrIntersectionOrPrimaryType -> unionOrIntersectionOrPrimaryType"); }
#line 2544 "parser.tab.cpp"
    break;

  case 28: /* unionOrIntersectionOrPrimaryType: unionOrIntersectionOrPrimaryType '&' unionOrIntersectionOrPrimaryType  */
#line 148 "parser.y"
                                                                            { Print("- R: unionOrIntersectionOrPrimaryType '&' unionOrIntersectionOrPrimaryType -> unionOrIntersectionOrPrimaryType"); }
#line 2550 "parser.tab.cpp"
    break;

  case 29: /* unionOrIntersectionOrPrimaryType: primaryType  */
#line 149 "parser.y"
                  { Print("- R: primaryType -> argument"); }
#line 2556 "parser.tab.cpp"
    break;

  case 30: /* primaryType: '(' type ')'  */
#line 153 "parser.y"
                   { Print("- R: '(' type ')' -> primaryType"); }
#line 2562 "parser.tab.cpp"
    break;

  case 31: /* primaryType: predefinedType  */
#line 154 "parser.y"
                     { Print("- R: predefinedType -> primaryType"); }
#line 2568 "parser.tab.cpp"
    break;

  case 32: /* primaryType: primaryType '[' ']'  */
#line 155 "parser.y"
                          { Print("- R: primaryType '[' ']' -> primaryType"); }
#line 2574 "parser.tab.cpp"
    break;

  case 33: /* primaryType: primaryType '[' primaryType ']'  */
#line 156 "parser.y"
                                      { Print("- R: primaryType '[' primaryType ']' -> primaryType"); }
#line 2580 "parser.tab.cpp"
    break;

  case 34: /* primaryType: '[' tupleTypeElements ']'  */
#line 157 "parser.y"
                                { Print("- R: '[' tupleTypeElements ']' -> primaryType"); }
#line 2586 "parser.tab.cpp"
    break;

  case 35: /* tupleTypeElements: type  */
#line 161 "parser.y"
           { Print("- R: type -> tupleTypeElements"); }
#line 2592 "parser.tab.cpp"
    break;

  case 36: /* tupleTypeElements: tupleTypeElements ',' type  */
#line 162 "parser.y"
                                 { Print("- R: tupleTypeElements ',' type -> tupleTypeElements"); }
#line 2598 "parser.tab.cpp"
    break;

  case 37: /* predefinedType: ANY  */
#line 166 "parser.y"
          { Print("- R: ANY -> predefinedType"); }
#line 2604 "parser.tab.cpp"
    break;

  case 38: /* predefinedType: NUMBER  */
#line 167 "parser.y"
             { Print("- R: NUMBER -> predefinedType"); }
#line 2610 "parser.tab.cpp"
    break;

  case 39: /* predefinedType: STRING  */
#line 168 "parser.y"
             { Print("- R: STRING -> predefinedType"); }
#line 2616 "parser.tab.cpp"
    break;

  case 40: /* predefinedType: BOOLEAN  */
#line 169 "parser.y"
              { Print("- R: BOOLEAN -> predefinedType"); }
#line 2622 "parser.tab.cpp"
    break;

  case 41: /* predefinedType: NEVER  */
#line 170 "parser.y"
            { Print("- R: NEVER -> predefinedType"); }
#line 2628 "parser.tab.cpp"
    break;

  case 42: /* predefinedType: UNKNOWN  */
#line 171 "parser.y"
              { Print("- R: UNKNOWN -> predefinedType"); }
#line 2634 "parser.tab.cpp"
    break;

  case 43: /* predefinedType: UNDEFINED  */
#line 172 "parser.y"
                { Print("- R: UNDEFINED -> predefinedType"); }
#line 2640 "parser.tab.cpp"
    break;

  case 44: /* predefinedType: VOID  */
#line 173 "parser.y"
           { Print("- R: VOID -> predefinedType"); }
#line 2646 "parser.tab.cpp"
    break;

  case 45: /* predefinedType: NULL_KW  */
#line 174 "parser.y"
              { Print("- R: NULL_KW -> predefinedType"); }
#line 2652 "parser.tab.cpp"
    break;

  case 46: /* predefinedType: INT_LIT  */
#line 175 "parser.y"
              { Print("- R: INT_LIT -> predefinedType"); }
#line 2658 "parser.tab.cpp"
    break;

  case 47: /* predefinedType: FLOAT_LIT  */
#line 176 "parser.y"
                { Print("- R: FLOAT_LIT -> predefinedType"); }
#line 2664 "parser.tab.cpp"
    break;

  case 48: /* predefinedType: TRUE_KW  */
#line 177 "parser.y"
              { Print("- R: TRUE_WD -> predefinedType"); }
#line 2670 "parser.tab.cpp"
    break;

  case 49: /* predefinedType: FALSE_KW  */
#line 178 "parser.y"
               { Print("- R: FALSE_KW -> predefinedType"); }
#line 2676 "parser.tab.cpp"
    break;

  case 50: /* predefinedType: STRING_LIT  */
#line 179 "parser.y"
                 { Print("- R: STRING_LIT -> predefinedType"); }
#line 2682 "parser.tab.cpp"
    break;

  case 51: /* typeAnnotation: ':' type  */
#line 183 "parser.y"
               { Print("- R: ':' type -> typeAnnotation"); }
#line 2688 "parser.tab.cpp"
    break;

  case 52: /* arrayLiteral: '[' elementList ']'  */
#line 188 "parser.y"
                          { Print("- R: [ elementList ']' -> arrayLiteral"); }
#line 2694 "parser.tab.cpp"
    break;

  case 53: /* arrayLiteral: ENDL_BRACKET_OPEN elementList ']'  */
#line 189 "parser.y"
                                        { Print("- R: ENDL_BRACKET_OPEN elementList ']' -> arrayLiteral"); }
#line 2700 "parser.tab.cpp"
    break;

  case 54: /* elementList: %empty  */
#line 193 "parser.y"
                  { Print("- R: #empty# -> elementList"); }
#line 2706 "parser.tab.cpp"
    break;

  case 55: /* elementList: arrayElement  */
#line 194 "parser.y"
                   { Print("- R: arrayElement -> elementList"); }
#line 2712 "parser.tab.cpp"
    break;

  case 56: /* elementList: elementList ',' elementList  */
#line 195 "parser.y"
                                  { Print("- R: elementList ',' elementList -> elementList"); }
#line 2718 "parser.tab.cpp"
    break;

  case 57: /* arrayElement: singleExpression  */
#line 199 "parser.y"
                       { Print("- R: singleExpression -> arrayElement"); }
#line 2724 "parser.tab.cpp"
    break;

  case 58: /* arrayElement: ELLIPSIS singleExpression  */
#line 200 "parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> arrayElement"); }
#line 2730 "parser.tab.cpp"
    break;

  case 59: /* expressionListOpt: %empty  */
#line 206 "parser.y"
                  { Print("- R: #empty# -> expressionListOpt"); }
#line 2736 "parser.tab.cpp"
    break;

  case 60: /* expressionListOpt: expressionList  */
#line 207 "parser.y"
                     { Print("- R: expressionList -> expressionListOpt"); }
#line 2742 "parser.tab.cpp"
    break;

  case 61: /* expressionList: singleExpression  */
#line 211 "parser.y"
                       { Print("- R: singleExpression -> expressionList"); }
#line 2748 "parser.tab.cpp"
    break;

  case 62: /* expressionList: expressionList ',' singleExpression  */
#line 212 "parser.y"
                                          { Print("- R: expressionList ',' singleExpression -> expressionList"); }
#line 2754 "parser.tab.cpp"
    break;

  case 63: /* singleExpression: identifier  */
#line 216 "parser.y"
                 { Print("- R: identifier -> singleExpression"); }
#line 2760 "parser.tab.cpp"
    break;

  case 64: /* singleExpression: THIS  */
#line 217 "parser.y"
           { Print("- R: THIS -> singleExpression"); }
#line 2766 "parser.tab.cpp"
    break;

  case 65: /* singleExpression: SUPER  */
#line 218 "parser.y"
            { Print("- R: SUPER -> singleExpression"); }
#line 2772 "parser.tab.cpp"
    break;

  case 66: /* singleExpression: INT_LIT  */
#line 219 "parser.y"
              { Print("- R: INT_LIT -> singleExpression"); }
#line 2778 "parser.tab.cpp"
    break;

  case 67: /* singleExpression: FLOAT_LIT  */
#line 220 "parser.y"
                { Print("- R: FLOAT_LIT -> singleExpression"); }
#line 2784 "parser.tab.cpp"
    break;

  case 68: /* singleExpression: STRING_LIT  */
#line 221 "parser.y"
                 { Print("- R: STRING_LIT -> singleExpression"); }
#line 2790 "parser.tab.cpp"
    break;

  case 69: /* singleExpression: TEMPLATE_LITERAL  */
#line 222 "parser.y"
                       { Print("- R: TEMPLATE_LITERAL -> singleExpression"); }
#line 2796 "parser.tab.cpp"
    break;

  case 70: /* singleExpression: TRUE_KW  */
#line 223 "parser.y"
              { Print("- R: TRUE_LITERAL -> singleExpression"); }
#line 2802 "parser.tab.cpp"
    break;

  case 71: /* singleExpression: FALSE_KW  */
#line 224 "parser.y"
               { Print("- R: FALSE_LITERAL -> singleExpression"); }
#line 2808 "parser.tab.cpp"
    break;

  case 72: /* singleExpression: NULL_KW  */
#line 225 "parser.y"
              { Print("- R: NULL_LITERAL -> singleExpression"); }
#line 2814 "parser.tab.cpp"
    break;

  case 73: /* singleExpression: '-' singleExpression  */
#line 226 "parser.y"
                                        { Print("- R: '-' singleExpression -> singleExpression"); }
#line 2820 "parser.tab.cpp"
    break;

  case 74: /* singleExpression: '+' singleExpression  */
#line 227 "parser.y"
                                       { Print("- R: '+'s singleExpression -> singleExpression"); }
#line 2826 "parser.tab.cpp"
    break;

  case 75: /* singleExpression: '!' singleExpression  */
#line 228 "parser.y"
                           { Print("- R: '!' singleExpression -> singleExpression"); }
#line 2832 "parser.tab.cpp"
    break;

  case 76: /* singleExpression: '~' singleExpression  */
#line 229 "parser.y"
                           { Print("- R: '~' singleExpression -> singleExpression"); }
#line 2838 "parser.tab.cpp"
    break;

  case 77: /* singleExpression: singleExpression OPERATOR_INCREMENT  */
#line 230 "parser.y"
                                                               { Print("- R: singleExpression OPERATOR_INCREMENT -> singleExpression"); }
#line 2844 "parser.tab.cpp"
    break;

  case 78: /* singleExpression: singleExpression OPERATOR_DECREMENT  */
#line 231 "parser.y"
                                                               { Print("- R: singleExpression OPERATOR_DECREMENT -> singleExpression"); }
#line 2850 "parser.tab.cpp"
    break;

  case 79: /* singleExpression: ENDL_OPERATOR_INCREMENT singleExpression  */
#line 232 "parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 2856 "parser.tab.cpp"
    break;

  case 80: /* singleExpression: ENDL_OPERATOR_DECREMENT singleExpression  */
#line 233 "parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 2862 "parser.tab.cpp"
    break;

  case 81: /* singleExpression: OPERATOR_INCREMENT singleExpression  */
#line 234 "parser.y"
                                                               { Print("- R: OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 2868 "parser.tab.cpp"
    break;

  case 82: /* singleExpression: OPERATOR_DECREMENT singleExpression  */
#line 235 "parser.y"
                                                               { Print("- R: OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 2874 "parser.tab.cpp"
    break;

  case 83: /* singleExpression: singleExpression '+' singleExpression  */
#line 236 "parser.y"
                                            { Print("- R: singleExpression '+' singleExpression -> singleExpression"); }
#line 2880 "parser.tab.cpp"
    break;

  case 84: /* singleExpression: singleExpression '-' singleExpression  */
#line 237 "parser.y"
                                            { Print("- R: singleExpression '-' singleExpression -> singleExpression"); }
#line 2886 "parser.tab.cpp"
    break;

  case 85: /* singleExpression: singleExpression '*' singleExpression  */
#line 238 "parser.y"
                                            { Print("- R: singleExpression '*' singleExpression -> singleExpression"); }
#line 2892 "parser.tab.cpp"
    break;

  case 86: /* singleExpression: singleExpression '/' singleExpression  */
#line 239 "parser.y"
                                            { Print("- R: singleExpression '/' singleExpression -> singleExpression"); }
#line 2898 "parser.tab.cpp"
    break;

  case 87: /* singleExpression: singleExpression '%' singleExpression  */
#line 240 "parser.y"
                                            { Print("- R: singleExpression '%' singleExpression -> singleExpression"); }
#line 2904 "parser.tab.cpp"
    break;

  case 88: /* singleExpression: singleExpression '<' singleExpression  */
#line 241 "parser.y"
                                            { Print("- R: singleExpression '<' singleExpression -> singleExpression"); }
#line 2910 "parser.tab.cpp"
    break;

  case 89: /* singleExpression: singleExpression '>' singleExpression  */
#line 242 "parser.y"
                                            { Print("- R: singleExpression '>' singleExpression -> singleExpression"); }
#line 2916 "parser.tab.cpp"
    break;

  case 90: /* singleExpression: singleExpression OPERATOR_POWER singleExpression  */
#line 243 "parser.y"
                                                       { Print("- R: singleExpression OPERATOR_POWER singleExpression -> singleExpression"); }
#line 2922 "parser.tab.cpp"
    break;

  case 91: /* singleExpression: singleExpression OPERATOR_EQUAL singleExpression  */
#line 244 "parser.y"
                                                       { Print("- R: singleExpression OPERATOR_EQUAL singleExpression -> singleExpression"); }
#line 2928 "parser.tab.cpp"
    break;

  case 92: /* singleExpression: singleExpression OPERATOR_NOT_EQUAL singleExpression  */
#line 245 "parser.y"
                                                           { Print("- R: singleExpression OPERATOR_NOT_EQUAL singleExpression -> singleExpression"); }
#line 2934 "parser.tab.cpp"
    break;

  case 93: /* singleExpression: singleExpression OPERATOR_STRICT_EQUAL singleExpression  */
#line 246 "parser.y"
                                                              { Print("- R: singleExpression OPERATOR_STRICT_EQUAL singleExpression -> singleExpression"); }
#line 2940 "parser.tab.cpp"
    break;

  case 94: /* singleExpression: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression  */
#line 247 "parser.y"
                                                                  { Print("- R: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression -> singleExpression"); }
#line 2946 "parser.tab.cpp"
    break;

  case 95: /* singleExpression: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression  */
#line 248 "parser.y"
                                                                 { Print("- R: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression -> singleExpression"); }
#line 2952 "parser.tab.cpp"
    break;

  case 96: /* singleExpression: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression  */
#line 249 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression -> singleExpression"); }
#line 2958 "parser.tab.cpp"
    break;

  case 97: /* singleExpression: singleExpression '=' singleExpression  */
#line 250 "parser.y"
                                            { Print("- R: singleExpression '=' singleExpression -> singleExpression"); }
#line 2964 "parser.tab.cpp"
    break;

  case 98: /* singleExpression: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression  */
#line 251 "parser.y"
                                                                 { Print("- R: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression -> singleExpression"); }
#line 2970 "parser.tab.cpp"
    break;

  case 99: /* singleExpression: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression  */
#line 252 "parser.y"
                                                               { Print("- R: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression -> singleExpression"); }
#line 2976 "parser.tab.cpp"
    break;

  case 100: /* singleExpression: singleExpression OPERATOR_ASSIGN_MOD singleExpression  */
#line 253 "parser.y"
                                                            { Print("- R: singleExpression OPERATOR_ASSIGN_MOD singleExpression -> singleExpression"); }
#line 2982 "parser.tab.cpp"
    break;

  case 101: /* singleExpression: singleExpression OPERATOR_ASSIGN_PLUS singleExpression  */
#line 254 "parser.y"
                                                             { Print("- R: singleExpression OPERATOR_ASSIGN_PLUS singleExpression -> singleExpression"); }
#line 2988 "parser.tab.cpp"
    break;

  case 102: /* singleExpression: singleExpression OPERATOR_ASSIGN_MINUS singleExpression  */
#line 255 "parser.y"
                                                              { Print("- R: singleExpression OPERATOR_ASSIGN_MINUS singleExpression -> singleExpression"); }
#line 2994 "parser.tab.cpp"
    break;

  case 103: /* singleExpression: singleExpression OPERATOR_ASSIGN_SHIFT_LEFT singleExpression  */
#line 256 "parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_SHIFT_LEFT singleExpression -> singleExpression"); }
#line 3000 "parser.tab.cpp"
    break;

  case 104: /* singleExpression: singleExpression OPERATOR_ASSIGN_SHIFT_RIGHT singleExpression  */
#line 257 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3006 "parser.tab.cpp"
    break;

  case 105: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_AND singleExpression  */
#line 258 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_AND singleExpression -> singleExpression"); }
#line 3012 "parser.tab.cpp"
    break;

  case 106: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_XOR singleExpression  */
#line 259 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_XOR singleExpression -> singleExpression"); }
#line 3018 "parser.tab.cpp"
    break;

  case 107: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_OR singleExpression  */
#line 260 "parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_OR singleExpression -> singleExpression"); }
#line 3024 "parser.tab.cpp"
    break;

  case 108: /* singleExpression: singleExpression OPERATOR_ASSIGN_POWER singleExpression  */
#line 261 "parser.y"
                                                              { Print("- R: singleExpression OPERATOR_ASSIGN_POWER singleExpression -> singleExpression"); }
#line 3030 "parser.tab.cpp"
    break;

  case 109: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression  */
#line 262 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression -> singleExpression"); }
#line 3036 "parser.tab.cpp"
    break;

  case 110: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression  */
#line 263 "parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression -> singleExpression"); }
#line 3042 "parser.tab.cpp"
    break;

  case 111: /* singleExpression: singleExpression OPERATOR_ASSIGN_NULLISH_COALESCING singleExpression  */
#line 264 "parser.y"
                                                                           { Print("- R: singleExpression OPERATOR_ASSIGN_NULLISH_COALESCING singleExpression -> singleExpression"); }
#line 3048 "parser.tab.cpp"
    break;

  case 112: /* singleExpression: singleExpression OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT singleExpression  */
#line 265 "parser.y"
                                                                             { Print("- R: singleExpression OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3054 "parser.tab.cpp"
    break;

  case 113: /* singleExpression: singleExpression OPERATOR_LOGICAL_OR singleExpression  */
#line 266 "parser.y"
                                                            { Print("- R: singleExpression OPERATOR_LOGICAL_OR singleExpression -> singleExpression"); }
#line 3060 "parser.tab.cpp"
    break;

  case 114: /* singleExpression: singleExpression OPERATOR_LOGICAL_AND singleExpression  */
#line 267 "parser.y"
                                                             { Print("- R: singleExpression OPERATOR_LOGICAL_AND singleExpression -> singleExpression"); }
#line 3066 "parser.tab.cpp"
    break;

  case 115: /* singleExpression: singleExpression '|' singleExpression  */
#line 268 "parser.y"
                                            { Print("- R: singleExpression '|' singleExpression -> singleExpression"); }
#line 3072 "parser.tab.cpp"
    break;

  case 116: /* singleExpression: singleExpression '^' singleExpression  */
#line 269 "parser.y"
                                            { Print("- R: singleExpression '^' singleExpression -> singleExpression"); }
#line 3078 "parser.tab.cpp"
    break;

  case 117: /* singleExpression: singleExpression '&' singleExpression  */
#line 270 "parser.y"
                                            { Print("- R: singleExpression '&' singleExpression -> singleExpression"); }
#line 3084 "parser.tab.cpp"
    break;

  case 118: /* singleExpression: singleExpression OPERATOR_SHIFT_LEFT singleExpression  */
#line 271 "parser.y"
                                                            { Print("- R: singleExpression OPERATOR_SHIFT_LEFT singleExpression -> singleExpression"); }
#line 3090 "parser.tab.cpp"
    break;

  case 119: /* singleExpression: singleExpression OPERATOR_SHIFT_RIGHT singleExpression  */
#line 272 "parser.y"
                                                             { Print("- R: singleExpression OPERATOR_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3096 "parser.tab.cpp"
    break;

  case 120: /* singleExpression: singleExpression OPERATOR_UNSIGNED_SHIFT_RIGHT singleExpression  */
#line 273 "parser.y"
                                                                      { Print("- R: singleExpression OPERATOR_UNSIGNED_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3102 "parser.tab.cpp"
    break;

  case 121: /* singleExpression: singleExpression OPERATOR_NULLISH_COALESCING singleExpression  */
#line 274 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_NULLISH_COALESCING singleExpression -> singleExpression"); }
#line 3108 "parser.tab.cpp"
    break;

  case 122: /* singleExpression: singleExpression INSTANCEOF singleExpression  */
#line 276 "parser.y"
                                                   { Print("- R: singleExpression INSTANCEOF singleExpression -> singleExpression"); }
#line 3114 "parser.tab.cpp"
    break;

  case 123: /* singleExpression: singleExpression IN singleExpression  */
#line 277 "parser.y"
                                           { Print("- R: singleExpression IN singleExpression -> singleExpression"); }
#line 3120 "parser.tab.cpp"
    break;

  case 124: /* singleExpression: singleExpression TEMPLATE_LITERAL  */
#line 279 "parser.y"
                                        { Print("- R: singleExpression TEMPLATE_LITERAL -> singleExpression"); }
#line 3126 "parser.tab.cpp"
    break;

  case 125: /* singleExpression: singleExpression '?' singleExpression ':' singleExpression  */
#line 280 "parser.y"
                                                                 { Print("- R: singleExpression '?' singleExpression ':' singleExpression -> singleExpression"); }
#line 3132 "parser.tab.cpp"
    break;

  case 126: /* singleExpression: '(' expressionList ')'  */
#line 282 "parser.y"
                             { Print("- R: '(' expressionList ')' -> singleExpression"); }
#line 3138 "parser.tab.cpp"
    break;

  case 127: /* singleExpression: singleExpression arguments  */
#line 284 "parser.y"
                                 { Print("- R: singleExpression arguments -> singleExpression"); }
#line 3144 "parser.tab.cpp"
    break;

  case 128: /* singleExpression: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression  */
#line 286 "parser.y"
                                                                   { Print("- R: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression -> singleExpression"); }
#line 3150 "parser.tab.cpp"
    break;

  case 129: /* singleExpression: singleExpression '.' identifier  */
#line 287 "parser.y"
                                      { Print("- R: singleExpression '.' identifier -> singleExpression"); }
#line 3156 "parser.tab.cpp"
    break;

  case 130: /* singleExpression: arrayLiteral  */
#line 289 "parser.y"
                   { Print("- R: arrayLiteral -> singleExpression"); }
#line 3162 "parser.tab.cpp"
    break;

  case 131: /* singleExpression: singleExpression '[' expressionList ']'  */
#line 290 "parser.y"
                                              { Print("- R: singleExpression '[' singleExpression ']' -> singleExpression"); }
#line 3168 "parser.tab.cpp"
    break;

  case 132: /* singleExpression: singleExpression ENDL_BRACKET_OPEN expressionList ']'  */
#line 291 "parser.y"
                                                            { Print("- R: singleExpression ENDL_BRACKET_OPEN singleExpression ']' -> singleExpression"); }
#line 3174 "parser.tab.cpp"
    break;

  case 133: /* singleExpression: NEW singleExpression  */
#line 293 "parser.y"
                           { Print("- R: NEW singleExpression -> singleExpression"); }
#line 3180 "parser.tab.cpp"
    break;

  case 134: /* arguments: '(' ')'  */
#line 297 "parser.y"
              { Print("- R: '(' ')' -> arguments"); }
#line 3186 "parser.tab.cpp"
    break;

  case 135: /* arguments: '(' argumentList ')'  */
#line 298 "parser.y"
                           { Print("- R: '(' argumentList ')' -> arguments"); }
#line 3192 "parser.tab.cpp"
    break;

  case 136: /* arguments: '(' argumentList ',' ')'  */
#line 299 "parser.y"
                               { Print("- R: '(' argumentList ',' ') -> arguments"); }
#line 3198 "parser.tab.cpp"
    break;

  case 137: /* argumentList: argument  */
#line 303 "parser.y"
               { Print("- R: argument -> argumentList"); }
#line 3204 "parser.tab.cpp"
    break;

  case 138: /* argumentList: argumentList ',' arguments  */
#line 304 "parser.y"
                                 { Print("- R: argumentList ',' arguments -> argumentList"); }
#line 3210 "parser.tab.cpp"
    break;

  case 139: /* argument: singleExpression  */
#line 308 "parser.y"
                       { Print("- R: singleExpression -> argument"); }
#line 3216 "parser.tab.cpp"
    break;

  case 140: /* argument: ELLIPSIS singleExpression  */
#line 309 "parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> argument"); }
#line 3222 "parser.tab.cpp"
    break;

  case 141: /* varStatement: varModifier varDeclarationList  */
#line 315 "parser.y"
                                     { Print("- R: varModifier varDeclarationList -> varStatement"); }
#line 3228 "parser.tab.cpp"
    break;

  case 142: /* varDeclarationList: varDeclaration  */
#line 319 "parser.y"
                     { Print("- R: varDeclaration -> argument"); }
#line 3234 "parser.tab.cpp"
    break;

  case 143: /* varDeclarationList: varDeclarationList ',' varDeclaration  */
#line 320 "parser.y"
                                            { Print("- R: varDeclarationList ',' varDeclaration -> varDeclarationList"); }
#line 3240 "parser.tab.cpp"
    break;

  case 144: /* varDeclaration: identifier  */
#line 324 "parser.y"
                 { Print("- R: identifier -> varDeclaration"); }
#line 3246 "parser.tab.cpp"
    break;

  case 145: /* varDeclaration: identifier typeAnnotation  */
#line 325 "parser.y"
                                { Print("- R: identifier typeAnnotation -> varDeclaration"); }
#line 3252 "parser.tab.cpp"
    break;

  case 146: /* varDeclaration: identifier '=' singleExpression  */
#line 326 "parser.y"
                                      { Print("- R: identifier '=' singleExpression -> varDeclaration"); }
#line 3258 "parser.tab.cpp"
    break;

  case 147: /* varDeclaration: identifier typeAnnotation '=' singleExpression  */
#line 327 "parser.y"
                                                     { Print("- R: identifier typeAnnotation '=' singleExpression -> varDeclaration"); }
#line 3264 "parser.tab.cpp"
    break;

  case 148: /* varModifier: VAR  */
#line 331 "parser.y"
          { Print("- R: VAR -> varModifier"); }
#line 3270 "parser.tab.cpp"
    break;

  case 149: /* varModifier: LET  */
#line 332 "parser.y"
          { Print("- R: LET -> varModifier"); }
#line 3276 "parser.tab.cpp"
    break;

  case 150: /* varModifier: CONST  */
#line 333 "parser.y"
            { Print("- R: CONST -> varModifier"); }
#line 3282 "parser.tab.cpp"
    break;

  case 151: /* ifStatement: IF '(' expressionList ')' statementListItem  */
#line 339 "parser.y"
                                                                     { Print("- R:  IF '(' expressionList ')' statementListItem -> ifStatement"); }
#line 3288 "parser.tab.cpp"
    break;

  case 152: /* ifStatement: IF '(' expressionList ')' statementListItem ELSE statementListItem  */
#line 340 "parser.y"
                                                                         { Print("- R: IF '(' expressionList ')' statementListItem ELSE statementListItem -> ifStatement"); }
#line 3294 "parser.tab.cpp"
    break;

  case 153: /* $@4: %empty  */
#line 344 "parser.y"
         { isInIterationBody = 1; }
#line 3300 "parser.tab.cpp"
    break;

  case 154: /* $@5: %empty  */
#line 344 "parser.y"
                                                                                   { doWhileASI(); }
#line 3306 "parser.tab.cpp"
    break;

  case 155: /* iterationStatement: DO $@4 statementListItem WHILE '(' expressionList ')' $@5 statementSep  */
#line 344 "parser.y"
                                                                                                                                            { isInIterationBody = 0; Print("- R: DO statementListItem WHILE '(' expressionList ')' statementSep -> iterationStatement"); }
#line 3312 "parser.tab.cpp"
    break;

  case 156: /* $@6: %empty  */
#line 345 "parser.y"
                                   { isInIterationBody = 1; }
#line 3318 "parser.tab.cpp"
    break;

  case 157: /* iterationStatement: WHILE '(' expressionList ')' $@6 statementListItem  */
#line 345 "parser.y"
                                                                                                                                            { isInIterationBody = 0; Print("- R: WHILE '(' expressionList ')' statementListItem -> iterationStatement"); }
#line 3324 "parser.tab.cpp"
    break;

  case 158: /* $@7: %empty  */
#line 346 "parser.y"
              { isInForHeader = 1; }
#line 3330 "parser.tab.cpp"
    break;

  case 159: /* $@8: %empty  */
#line 346 "parser.y"
                                                                                                       { isInForHeader = 0; isInIterationBody = 1; }
#line 3336 "parser.tab.cpp"
    break;

  case 160: /* iterationStatement: FOR '(' $@7 expressionListOpt ';' expressionListOpt ';' expressionListOpt ')' $@8 statementListItem  */
#line 346 "parser.y"
                                                                                                                                                                                      { isInIterationBody = 0; Print("- R: FOR '(' expressionListOpt ';' expressionListOpt ';' expressionListOpt ')' statementListItem -> iterationStatement"); }
#line 3342 "parser.tab.cpp"
    break;

  case 161: /* $@9: %empty  */
#line 347 "parser.y"
              { isInForHeader = 1; }
#line 3348 "parser.tab.cpp"
    break;

  case 162: /* $@10: %empty  */
#line 347 "parser.y"
                                                                                                                    { isInForHeader = 0; isInIterationBody = 1; }
#line 3354 "parser.tab.cpp"
    break;

  case 163: /* iterationStatement: FOR '(' $@9 varModifier varDeclarationList ';' expressionListOpt ';' expressionListOpt ')' $@10 statementListItem  */
#line 347 "parser.y"
                                                                                                                                                                                      { isInIterationBody = 0; Print("- R: FOR '(' varModifier varDeclarationList ';' expressionListOpt ';' expressionListOpt ')' statementListItem -> iterationStatement"); }
#line 3360 "parser.tab.cpp"
    break;

  case 164: /* $@11: %empty  */
#line 348 "parser.y"
              { isInForHeader = 1; }
#line 3366 "parser.tab.cpp"
    break;

  case 165: /* $@12: %empty  */
#line 348 "parser.y"
                                                                              { isInForHeader = 0; isInIterationBody = 1; }
#line 3372 "parser.tab.cpp"
    break;

  case 166: /* iterationStatement: FOR '(' $@11 singleExpression IN singleExpression ')' $@12 statementListItem  */
#line 348 "parser.y"
                                                                                                                                                                                      { isInIterationBody = 0; Print("- R: FOR '(' singleExpression IN singleExpression ')' statementListItem -> iterationStatement"); }
#line 3378 "parser.tab.cpp"
    break;

  case 167: /* $@13: %empty  */
#line 349 "parser.y"
              { isInForHeader = 1; }
#line 3384 "parser.tab.cpp"
    break;

  case 168: /* $@14: %empty  */
#line 349 "parser.y"
                                                                                      { isInForHeader = 0; isInIterationBody = 1; }
#line 3390 "parser.tab.cpp"
    break;

  case 169: /* iterationStatement: FOR '(' $@13 varModifier varDeclaration IN expressionList ')' $@14 statementListItem  */
#line 349 "parser.y"
                                                                                                                                                                                      { isInIterationBody = 0; Print("- R: FOR '(' varModifier varDeclaration IN expressionList ')' statementListItem -> iterationStatement"); }
#line 3396 "parser.tab.cpp"
    break;

  case 170: /* continueStatement: CONTINUE  */
#line 353 "parser.y"
               { Print("- R: CONTINUE -> returnStatement"); }
#line 3402 "parser.tab.cpp"
    break;

  case 171: /* continueStatement: CONTINUE identifier  */
#line 354 "parser.y"
                          { Print("- R: CONTINUE identifier -> returnStatement"); }
#line 3408 "parser.tab.cpp"
    break;

  case 172: /* breakStatement: BREAK  */
#line 358 "parser.y"
             { Print("- R: BREAK -> returnStatement"); }
#line 3414 "parser.tab.cpp"
    break;

  case 173: /* breakStatement: BREAK identifier  */
#line 359 "parser.y"
                       { Print("- R: BREAK identifier -> returnStatement"); }
#line 3420 "parser.tab.cpp"
    break;

  case 174: /* returnStatement: RETURN  */
#line 363 "parser.y"
             { Print("- R: RETURN -> returnStatement"); }
#line 3426 "parser.tab.cpp"
    break;

  case 175: /* returnStatement: RETURN singleExpression  */
#line 364 "parser.y"
                              { Print("- R: RETURN singleExpression -> returnStatement"); }
#line 3432 "parser.tab.cpp"
    break;

  case 176: /* labelledStatement: identifier ':' statementListItem  */
#line 368 "parser.y"
                                       { Print("- R: identifier ':' statementListItem -> labelledStatement"); }
#line 3438 "parser.tab.cpp"
    break;

  case 177: /* blockStatement: '{' '}'  */
#line 372 "parser.y"
              { Print("- R: '{' '}' -> blockStatement"); }
#line 3444 "parser.tab.cpp"
    break;

  case 178: /* blockStatement: '{' statementList '}'  */
#line 373 "parser.y"
                            { Print("- R: '{' statementList '}' -> blockStatement"); }
#line 3450 "parser.tab.cpp"
    break;

  case 179: /* switchStatement: SWITCH '(' expressionList ')' '{' '}'  */
#line 377 "parser.y"
                                            { Print("- R: SWITCH '(' expressionList ')' '{' '}' -> switchStatement"); }
#line 3456 "parser.tab.cpp"
    break;

  case 180: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList '}'  */
#line 378 "parser.y"
                                                           { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList '}' -> switchStatement"); }
#line 3462 "parser.tab.cpp"
    break;

  case 181: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause '}'  */
#line 379 "parser.y"
                                                                         { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause '}' -> switchStatement"); }
#line 3468 "parser.tab.cpp"
    break;

  case 182: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause caseClauseList '}'  */
#line 380 "parser.y"
                                                                                        { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause caseClauseList '}' -> switchStatement"); }
#line 3474 "parser.tab.cpp"
    break;

  case 183: /* caseClauseList: caseClause  */
#line 384 "parser.y"
                 { Print("- R: caseClause -> caseClauseList"); }
#line 3480 "parser.tab.cpp"
    break;

  case 184: /* caseClauseList: caseClauseList caseClause  */
#line 385 "parser.y"
                                { Print("- R: caseClauseList caseClause -> caseClauseList"); }
#line 3486 "parser.tab.cpp"
    break;

  case 185: /* caseClause: CASE expressionList ':'  */
#line 389 "parser.y"
                              { Print("- R: CASE expressionList ':' -> caseClause"); }
#line 3492 "parser.tab.cpp"
    break;

  case 186: /* caseClause: CASE expressionList ':' statementList  */
#line 390 "parser.y"
                                            { Print("- R: CASE expressionList ':' statementList -> caseClause"); }
#line 3498 "parser.tab.cpp"
    break;

  case 187: /* defaultClause: DEFAULT ':'  */
#line 394 "parser.y"
                  { Print("- R: DEFAULT ':' -> defaultClause"); }
#line 3504 "parser.tab.cpp"
    break;

  case 188: /* defaultClause: DEFAULT ':' statementList  */
#line 395 "parser.y"
                                { Print("- R: DEFAULT ':' statementList -> defaultClause"); }
#line 3510 "parser.tab.cpp"
    break;

  case 189: /* functionDeclaration: FUNCTION identifier callSignature functionBody  */
#line 401 "parser.y"
                                                     { Print("- R: FUNCTION ID callSignature functionBody -> functionDeclaration"); }
#line 3516 "parser.tab.cpp"
    break;

  case 190: /* functionBody: '{' '}'  */
#line 405 "parser.y"
              { Print("- R: '{' '}' -> functionBody"); }
#line 3522 "parser.tab.cpp"
    break;

  case 191: /* $@15: %empty  */
#line 406 "parser.y"
          { isInFunctionBody = 1; }
#line 3528 "parser.tab.cpp"
    break;

  case 192: /* functionBody: '{' $@15 statementList '}'  */
#line 406 "parser.y"
                                                      { isInFunctionBody = 0; Print("- R: '{' statementList '}' -> functionBody"); }
#line 3534 "parser.tab.cpp"
    break;

  case 193: /* callSignature: '(' ')'  */
#line 410 "parser.y"
              { Print("- R: '(' ')' -> callSignature"); }
#line 3540 "parser.tab.cpp"
    break;

  case 194: /* callSignature: '(' ')' typeAnnotation  */
#line 411 "parser.y"
                             { Print("- R: '(' ')' typeAnnotation -> callSignature"); }
#line 3546 "parser.tab.cpp"
    break;

  case 195: /* callSignature: '(' restParameter ')'  */
#line 412 "parser.y"
                            { Print("- R: '(' restParameter ')' -> callSignature"); }
#line 3552 "parser.tab.cpp"
    break;

  case 196: /* callSignature: '(' restParameter ')' typeAnnotation  */
#line 413 "parser.y"
                                           { Print("- R: '(' restParameter ')' typeAnnotation -> callSignature"); }
#line 3558 "parser.tab.cpp"
    break;

  case 197: /* callSignature: '(' parameterList ')'  */
#line 414 "parser.y"
                            { Print("- R: '(' parameterList ')' -> callSignature"); }
#line 3564 "parser.tab.cpp"
    break;

  case 198: /* callSignature: '(' parameterList ')' typeAnnotation  */
#line 415 "parser.y"
                                           { Print("- R: '(' parameterList ')' typeAnnotation -> callSignature"); }
#line 3570 "parser.tab.cpp"
    break;

  case 199: /* callSignature: '(' parameterList ',' restParameter ')'  */
#line 416 "parser.y"
                                              { Print("- R: '(' parameterList ',' restParameter ')' -> callSignature"); }
#line 3576 "parser.tab.cpp"
    break;

  case 200: /* callSignature: '(' parameterList ',' restParameter ')' typeAnnotation  */
#line 417 "parser.y"
                                                             { Print("- R: '(' parameterList ',' restParameter ')' typeAnnotation -> callSignature"); }
#line 3582 "parser.tab.cpp"
    break;

  case 201: /* callSignature: '(' parameterList ',' ')'  */
#line 418 "parser.y"
                                { Print("- R: '(' parameterList ',' ')' -> callSignature"); }
#line 3588 "parser.tab.cpp"
    break;

  case 202: /* callSignature: '(' parameterList ',' ')' typeAnnotation  */
#line 419 "parser.y"
                                               { Print("- R: '(' parameterList ',' ')' typeAnnotation -> callSignature"); }
#line 3594 "parser.tab.cpp"
    break;

  case 203: /* parameterList: parameter  */
#line 423 "parser.y"
                { Print("- R: parameter -> parameterList"); }
#line 3600 "parser.tab.cpp"
    break;

  case 204: /* parameterList: parameterList ',' parameter  */
#line 424 "parser.y"
                                  { Print("- R: parameterList ',' parameter -> parameterList"); }
#line 3606 "parser.tab.cpp"
    break;

  case 205: /* parameter: requiredParameter  */
#line 428 "parser.y"
                        { Print("- R: requiredParameter -> parameter"); }
#line 3612 "parser.tab.cpp"
    break;

  case 206: /* parameter: optionalParameter  */
#line 429 "parser.y"
                        { Print("- R: optionalParameter -> parameter"); }
#line 3618 "parser.tab.cpp"
    break;

  case 207: /* requiredParameter: identifier  */
#line 433 "parser.y"
                 { Print("- R: ID -> requiredParameter"); }
#line 3624 "parser.tab.cpp"
    break;

  case 208: /* requiredParameter: identifier typeAnnotation  */
#line 434 "parser.y"
                                { Print("- R: ID typeAnnotation -> requiredParameter"); }
#line 3630 "parser.tab.cpp"
    break;

  case 209: /* optionalParameter: identifier '?'  */
#line 438 "parser.y"
                     { Print("- R: ID '?' -> optionalParameter"); }
#line 3636 "parser.tab.cpp"
    break;

  case 210: /* optionalParameter: identifier '?' typeAnnotation  */
#line 439 "parser.y"
                                    { Print("- R: ID '?' typeAnnotation -> optionalParameter"); }
#line 3642 "parser.tab.cpp"
    break;

  case 211: /* optionalParameter: identifier initializer  */
#line 440 "parser.y"
                             { Print("- R: ID initializer -> optionalParameter"); }
#line 3648 "parser.tab.cpp"
    break;

  case 212: /* optionalParameter: identifier typeAnnotation initializer  */
#line 441 "parser.y"
                                            { Print("- R: ID typeAnnotation initializer -> optionalParameter"); }
#line 3654 "parser.tab.cpp"
    break;

  case 213: /* restParameter: ELLIPSIS singleExpression  */
#line 445 "parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> restParameter"); }
#line 3660 "parser.tab.cpp"
    break;

  case 214: /* restParameter: ELLIPSIS singleExpression typeAnnotation  */
#line 446 "parser.y"
                                               { Print("- R: ELLIPSIS singleExpression typeAnnotation -> restParameter"); }
#line 3666 "parser.tab.cpp"
    break;

  case 215: /* classDeclaration: CLASS identifier classTail  */
#line 452 "parser.y"
                                 { Print("- R: CLASS identifier classTail -> classDeclaration"); }
#line 3672 "parser.tab.cpp"
    break;

  case 216: /* classDeclaration: CLASS identifier classHeritage classTail  */
#line 453 "parser.y"
                                               { Print("- R: CLASS identifier classHeritage classTail -> classDeclaration"); }
#line 3678 "parser.tab.cpp"
    break;

  case 217: /* classHeritage: EXTENDS identifier  */
#line 457 "parser.y"
                         { Print("- R: EXTENDS identifier -> classHeritage"); }
#line 3684 "parser.tab.cpp"
    break;

  case 218: /* classTail: '{' '}'  */
#line 461 "parser.y"
              { Print("- R: '{' '}' -> classTail"); }
#line 3690 "parser.tab.cpp"
    break;

  case 219: /* classTail: '{' classElementList '}'  */
#line 462 "parser.y"
                               { Print("- R: '{' classElementList '}' -> classTail"); }
#line 3696 "parser.tab.cpp"
    break;

  case 220: /* classElementList: classElement  */
#line 466 "parser.y"
                   { Print("- R: classElement -> classElementList"); }
#line 3702 "parser.tab.cpp"
    break;

  case 221: /* classElementList: classElementList classElement  */
#line 467 "parser.y"
                                    { Print("- R: classElementList classElement -> classElementList"); }
#line 3708 "parser.tab.cpp"
    break;

  case 222: /* classElement: CONSTRUCTOR callSignature functionBody  */
#line 471 "parser.y"
                                             { Print("- R: CONSTRUCTOR callSignature functionBody -> classElement"); }
#line 3714 "parser.tab.cpp"
    break;

  case 223: /* classElement: propertyName ';'  */
#line 474 "parser.y"
                       { Print("- R: propertyName ';' -> classElement"); }
#line 3720 "parser.tab.cpp"
    break;

  case 224: /* classElement: propertyName typeAnnotation ';'  */
#line 475 "parser.y"
                                      { Print("- R: propertyName typeAnnotation ';' -> classElement"); }
#line 3726 "parser.tab.cpp"
    break;

  case 225: /* classElement: propertyName initializer ';'  */
#line 476 "parser.y"
                                   { Print("- R: propertyName initializer ';' -> classElement"); }
#line 3732 "parser.tab.cpp"
    break;

  case 226: /* classElement: propertyName typeAnnotation initializer ';'  */
#line 477 "parser.y"
                                                  { Print("- R: propertyName typeAnnotation initializer ';' -> classElement"); }
#line 3738 "parser.tab.cpp"
    break;

  case 227: /* classElement: propertyName callSignature functionBody  */
#line 480 "parser.y"
                                              { Print("- R: propertyName callSignature functionBody -> classElement"); }
#line 3744 "parser.tab.cpp"
    break;

  case 228: /* classElement: GET propertyName '(' ')' functionBody  */
#line 483 "parser.y"
                                            { Print("- R: GET propertyName '(' ')' functionBody -> classElement"); }
#line 3750 "parser.tab.cpp"
    break;

  case 229: /* classElement: GET propertyName '(' ')' typeAnnotation functionBody  */
#line 484 "parser.y"
                                                           { Print("- R: GET propertyName '(' ')' typeAnnotation functionBody -> classElement"); }
#line 3756 "parser.tab.cpp"
    break;

  case 230: /* classElement: SET propertyName callSignature functionBody  */
#line 485 "parser.y"
                                                  { Print("- R: SET propertyName callSignature functionBody -> classElement"); }
#line 3762 "parser.tab.cpp"
    break;

  case 231: /* propertyName: identifier  */
#line 489 "parser.y"
                 { Print("- R: identifier -> propertyName"); }
#line 3768 "parser.tab.cpp"
    break;

  case 232: /* propertyName: STRING_LIT  */
#line 490 "parser.y"
                 { Print("- R: STRING_LIT -> propertyName"); }
#line 3774 "parser.tab.cpp"
    break;

  case 233: /* propertyName: INT_LIT  */
#line 491 "parser.y"
              { Print("- R: INT_LIT -> propertyName"); }
#line 3780 "parser.tab.cpp"
    break;

  case 234: /* propertyName: FLOAT_LIT  */
#line 492 "parser.y"
                { Print("- R: FLOAT_LIT -> propertyName"); }
#line 3786 "parser.tab.cpp"
    break;

  case 235: /* propertyName: '[' singleExpression ']'  */
#line 493 "parser.y"
                               { Print("- R: '[' singleExpression ']' -> propertyName"); }
#line 3792 "parser.tab.cpp"
    break;

  case 236: /* propertyName: ENDL_BRACKET_OPEN singleExpression ']'  */
#line 494 "parser.y"
                                             { Print("- R: ENDL_BRACKET_OPEN singleExpression ']' -> propertyName"); }
#line 3798 "parser.tab.cpp"
    break;

  case 237: /* identifier: ID  */
#line 498 "parser.y"
         { Print("- R: ID -> identifier"); }
#line 3804 "parser.tab.cpp"
    break;

  case 238: /* identifier: ASYNC  */
#line 499 "parser.y"
            { Print("- R: ASYNC -> identifier"); }
#line 3810 "parser.tab.cpp"
    break;

  case 239: /* identifier: AS  */
#line 500 "parser.y"
         { Print("- R: AS -> identifier"); }
#line 3816 "parser.tab.cpp"
    break;

  case 240: /* identifier: FROM  */
#line 501 "parser.y"
           { Print("- R: FROM -> identifier"); }
#line 3822 "parser.tab.cpp"
    break;

  case 241: /* identifier: YIELD  */
#line 502 "parser.y"
            { Print("- R: YIELD -> identifier"); }
#line 3828 "parser.tab.cpp"
    break;

  case 242: /* identifier: ANY  */
#line 503 "parser.y"
          { Print("- R: ANY -> identifier"); }
#line 3834 "parser.tab.cpp"
    break;

  case 243: /* identifier: NUMBER  */
#line 504 "parser.y"
             { Print("- R: NUMBER -> identifier"); }
#line 3840 "parser.tab.cpp"
    break;

  case 244: /* identifier: BOOLEAN  */
#line 505 "parser.y"
              { Print("- R: BOOLEAN -> identifier"); }
#line 3846 "parser.tab.cpp"
    break;

  case 245: /* identifier: STRING  */
#line 506 "parser.y"
             { Print("- R: STRING -> identifier"); }
#line 3852 "parser.tab.cpp"
    break;

  case 246: /* identifier: UNIQUE  */
#line 507 "parser.y"
             { Print("- R: UNIQUE -> identifier"); }
#line 3858 "parser.tab.cpp"
    break;

  case 247: /* identifier: SYMBOL  */
#line 508 "parser.y"
             { Print("- R: SYMBOL -> identifier"); }
#line 3864 "parser.tab.cpp"
    break;

  case 248: /* identifier: NEVER  */
#line 509 "parser.y"
            { Print("- R: NEVER -> identifier"); }
#line 3870 "parser.tab.cpp"
    break;

  case 249: /* identifier: UNDEFINED  */
#line 510 "parser.y"
                { Print("- R: UNDEFINED -> identifier"); }
#line 3876 "parser.tab.cpp"
    break;

  case 250: /* identifier: OBJECT  */
#line 511 "parser.y"
             { Print("- R: OBJECT -> identifier"); }
#line 3882 "parser.tab.cpp"
    break;

  case 251: /* identifier: KEYOF  */
#line 512 "parser.y"
            { Print("- R: KEYOF -> identifier"); }
#line 3888 "parser.tab.cpp"
    break;

  case 252: /* identifier: NAMESPACE  */
#line 513 "parser.y"
                { Print("- R: NAMESPACE -> identifier"); }
#line 3894 "parser.tab.cpp"
    break;

  case 253: /* identifier: ABSTRACT  */
#line 514 "parser.y"
               { Print("- R: ABSTRACT -> identifier"); }
#line 3900 "parser.tab.cpp"
    break;

  case 254: /* identifier: REQUIRE  */
#line 515 "parser.y"
              { Print("- R: REQUIRE -> identifier"); }
#line 3906 "parser.tab.cpp"
    break;


#line 3910 "parser.tab.cpp"

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

#line 518 "parser.y"



void yyerror(const char* s) {
    syntaxErrorCounter++;
    fprintf(stderr, "Line:%d. Text: %s. Error: %s\n", yylloc.first_line, yytext_ptr, s);
}

/* Implementing part of automatic semicolon insertion of TypeScript / ECMAscript. 
 * This part is impelemnted first rule of semicolon insertion. 
 * See: https://262.ecma-international.org/14.0/#sec-unicode-format-control-characters:~:text=The%20offending%20token%20is%20separated%20from%20the%20previous%20token%20by%20at%20least%20one
 */
int yyfilter(int yychar, int yyn, int yystate, short *yyssp) {
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

            if (yytext_str != "<EOF>") { 
                rescanTokenString(yytext_ptr);
            }

            if ( debug ) {
                Print("found syntax error on token: " + yytext_str + ". inserted ';' as token", yylloc.first_line);
            }
            return ';';
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
        return yychar;
    }
}
