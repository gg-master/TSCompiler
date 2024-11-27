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

#line 93 "parser.tab.cpp"

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
  YYSYMBOL_continueStatement = 160,        /* continueStatement  */
  YYSYMBOL_breakStatement = 161,           /* breakStatement  */
  YYSYMBOL_returnStatement = 162,          /* returnStatement  */
  YYSYMBOL_labelledStatement = 163,        /* labelledStatement  */
  YYSYMBOL_blockStatement = 164,           /* blockStatement  */
  YYSYMBOL_switchStatement = 165,          /* switchStatement  */
  YYSYMBOL_caseClauseList = 166,           /* caseClauseList  */
  YYSYMBOL_caseClause = 167,               /* caseClause  */
  YYSYMBOL_defaultClause = 168,            /* defaultClause  */
  YYSYMBOL_functionDeclaration = 169,      /* functionDeclaration  */
  YYSYMBOL_functionBody = 170,             /* functionBody  */
  YYSYMBOL_171_11 = 171,                   /* $@11  */
  YYSYMBOL_callSignature = 172,            /* callSignature  */
  YYSYMBOL_parameterList = 173,            /* parameterList  */
  YYSYMBOL_parameter = 174,                /* parameter  */
  YYSYMBOL_requiredParameter = 175,        /* requiredParameter  */
  YYSYMBOL_optionalParameter = 176,        /* optionalParameter  */
  YYSYMBOL_restParameter = 177,            /* restParameter  */
  YYSYMBOL_classDeclaration = 178,         /* classDeclaration  */
  YYSYMBOL_classHeritage = 179,            /* classHeritage  */
  YYSYMBOL_classTail = 180,                /* classTail  */
  YYSYMBOL_classElementList = 181,         /* classElementList  */
  YYSYMBOL_classElement = 182,             /* classElement  */
  YYSYMBOL_propertyName = 183,             /* propertyName  */
  YYSYMBOL_identifier = 184                /* identifier  */
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
#define YYFINAL  102
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1950

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  123
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  249
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  432

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
       0,    84,    84,    88,    89,    93,    94,    95,    96,    97,
      98,    99,    99,   104,   104,   109,   109,   114,   115,   116,
     117,   121,   125,   131,   132,   133,   137,   138,   139,   143,
     144,   145,   146,   147,   151,   152,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     173,   178,   179,   183,   184,   185,   189,   190,   196,   197,
     201,   202,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   266,   267,   269,   270,   272,   274,   276,   277,   279,
     280,   281,   283,   287,   288,   289,   293,   294,   298,   299,
     305,   309,   310,   314,   315,   316,   317,   321,   322,   323,
     329,   330,   334,   334,   334,   335,   335,   336,   336,   337,
     337,   338,   338,   339,   339,   343,   344,   348,   349,   353,
     354,   358,   362,   363,   367,   368,   369,   370,   374,   375,
     379,   380,   384,   385,   391,   395,   396,   396,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   413,   414,
     418,   419,   423,   424,   428,   429,   430,   431,   435,   436,
     442,   443,   447,   451,   452,   456,   457,   461,   464,   465,
     466,   467,   470,   473,   474,   475,   479,   480,   481,   482,
     483,   484,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505
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
  "$@9", "$@10", "continueStatement", "breakStatement", "returnStatement",
  "labelledStatement", "blockStatement", "switchStatement",
  "caseClauseList", "caseClause", "defaultClause", "functionDeclaration",
  "functionBody", "$@11", "callSignature", "parameterList", "parameter",
  "requiredParameter", "optionalParameter", "restParameter",
  "classDeclaration", "classHeritage", "classTail", "classElementList",
  "classElement", "propertyName", "identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-288)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     859,  -288,  -288,  -288,   -99,  1055,  1055,  -288,   -94,   -91,
    1055,  1055,   -23,  1228,  -288,  -288,  1228,  -288,  -288,  -288,
    -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,
    -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,
    -288,  -288,  1228,  1228,  1228,  1228,  1228,  1228,  1228,  1228,
    1131,  1131,  1228,  -288,   490,   122,   859,  -288,  -288,   -31,
    1573,     8,  1055,  -288,  -288,  -288,  -288,  -288,  -288,  -288,
    -288,  -288,  -288,    58,  1228,    35,    -2,   859,  1228,   963,
    -288,  -288,  1228,  1573,  -288,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,  1228,    42,  -288,  1573,    56,   -25,
    -288,   619,  -288,  -288,  1228,  -288,  -288,  -288,  -288,  -288,
    1228,  1228,  1228,  1228,  1228,  1228,  1228,  1228,  1228,  1228,
    1228,  1228,  1228,  1228,  1228,  1228,  1228,  1228,  1228,  1228,
    1228,  1228,  1228,  1228,  1228,  1228,  1228,  1228,  1228,  1228,
    1228,  1228,  1228,  1228,  1228,  1228,  1228,  1228,  1228,  1228,
    1228,  1228,  1055,  1228,  1228,  1228,  1093,  -288,  -288,    84,
    -288,    53,     8,     8,     8,   859,   -22,    30,    33,  1055,
     165,    34,  -288,   142,   -21,    39,   100,  1637,  1055,   -20,
    1573,  1131,  -288,  -288,  -288,  -288,  1573,  1694,  1694,  1694,
    1694,  1694,  1694,  1694,  1694,  1694,  1694,  1694,  1694,  1694,
    1694,  1694,  1694,  1317,   718,   837,  1730,  1765,  1799,  1832,
     461,   461,   461,   461,  1125,  1125,  1125,  1125,  1125,  1125,
     224,   224,   224,   159,   159,    71,    71,    71,    71,  -288,
      59,    64,    45,  1228,  -288,  1573,   -19,  -288,  1055,  1228,
     203,   102,  -288,  -288,  -288,  -288,   859,  1228,    83,   -17,
    -288,  -288,  -288,    47,    61,    46,  -288,  -288,  1261,  1261,
      35,  -288,  -288,  -288,  1228,  1228,  -288,   997,  -288,    13,
    -288,  -288,    54,  -288,  1228,  1228,   -30,    78,    60,  -288,
    1228,  -288,  -288,  1573,    23,  -288,  -288,  1573,  -288,  -288,
    -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,
    -288,  -288,  1311,  1311,   203,   203,  -288,    44,    72,  -288,
    1228,   183,  1381,  -288,   367,    83,    83,  1228,    83,  -288,
     148,  -288,   859,    93,    35,    33,  1445,  1509,  -288,  -288,
    -288,    95,   -13,    33,  1228,   859,    96,   957,  1228,  1228,
     -10,   599,  -288,  -288,    44,    44,  -288,    65,    98,  1311,
    1311,   185,  1573,   859,  -288,    83,  -288,   101,  -288,  -288,
    1573,  -288,  -288,   739,   108,    33,  -288,  -288,  -288,  -288,
    -288,    99,  -288,    27,  -288,  1228,  -288,   125,    32,  1228,
    -288,    -4,  -288,   203,  -288,  -288,   143,  -288,  -288,    29,
    -288,  -288,    83,  -288,   -41,  -288,  -288,  -288,   128,   859,
    1228,  -288,   -36,   177,  -288,  -288,    -6,  -288,  -288,  -288,
      33,  -288,     8,  -288,  -288,   138,   859,   859,   859,  -288,
       2,  -288,  -288,   859,  -288,  -288,   859,   859,  -288,  -288,
     859,  -288
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   147,   148,   149,     0,     0,     0,   152,     0,     0,
     165,   167,     0,   169,    64,    63,     0,   233,   234,   235,
     236,   246,   247,   248,   249,   237,   238,   239,   240,   243,
     244,   241,   242,   245,    67,    65,    66,    71,    69,    70,
     232,    68,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    53,     0,     5,     0,     0,     2,     3,   129,     0,
      60,     0,     0,     8,    10,    11,    13,    15,    17,    18,
       9,    19,    20,    62,     0,     0,     0,     0,     0,    58,
     166,   168,     0,   170,    62,   132,    80,    81,    78,    79,
      73,    72,    74,    75,     0,     0,    54,    56,     0,     0,
     172,     0,     1,     4,     0,    21,     6,   123,    76,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   126,     7,   140,
     141,   143,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   210,     0,     0,     0,    59,    60,     0,     0,
      57,    53,    51,    52,   125,   173,    61,    96,   100,   101,
     107,    97,    98,    99,   102,   103,   111,   104,   105,   106,
     108,   109,   110,     0,   120,   112,   113,   114,   115,   116,
      90,    91,    92,    93,    88,    87,    95,    94,   121,   122,
     117,   118,   119,    82,    83,    84,    85,    86,    89,   128,
       0,     0,   127,     0,   133,   138,     0,   136,     0,     0,
       0,   144,    12,    14,    16,   171,     0,     0,   188,     0,
     198,   200,   201,     0,   202,   186,   184,   212,     0,     0,
       0,   227,   228,   229,     0,     0,   213,     0,   215,     0,
     226,   211,     0,   155,    58,     0,     0,   141,     0,    55,
       0,   130,   131,   139,     0,   134,   142,   145,    36,    37,
      39,    38,    40,    42,    43,    41,    49,    45,    46,    44,
      47,    48,     0,     0,     0,     0,    50,    23,    28,    30,
       0,   150,   208,   189,     0,   192,   190,     0,   204,   206,
     203,   185,     0,     0,     0,     0,     0,     0,   214,   216,
     218,     0,     0,     0,     0,     0,     0,   122,    58,     0,
       0,   124,   135,   137,    24,    25,    34,     0,     0,     0,
       0,     0,   146,     0,   209,   196,   199,     0,   193,   191,
      22,   205,   207,     0,     0,     0,   217,   230,   231,   220,
     219,     0,   222,     0,   156,    58,   161,     0,     0,     0,
     174,     0,   178,     0,    33,    29,    26,    27,    31,     0,
     151,   197,   194,   187,     0,   225,   221,   153,     0,     0,
      58,   163,     0,     0,   175,   179,     0,    35,    32,   195,
       0,   223,     0,   157,   162,     0,     0,   180,   182,   176,
       0,   224,   154,     0,   159,   164,   181,   183,   177,   158,
       0,   160
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -288,  -288,   -52,   -55,  -288,  -288,  -288,   -58,  -241,  -287,
    -167,   -87,  -288,  -288,  -234,  -288,   -47,  -288,  -262,   -45,
     334,   -18,  -288,  -288,  -288,    87,  -152,   189,  -288,  -288,
    -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,
    -288,  -288,  -288,  -137,  -270,  -288,  -288,  -280,  -288,  -237,
    -288,   -43,  -288,  -288,   -40,  -288,  -288,   107,  -288,    15,
    -111,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    55,    56,    57,   162,   163,   164,   106,   319,   306,
     307,   308,   347,   309,   241,    58,    95,    96,   175,    59,
      60,   157,   236,   237,    61,   159,   160,    62,    63,    64,
      77,   412,   335,   423,   430,   399,   416,    65,    66,    67,
      68,    69,    70,   381,   382,   406,    71,   256,   322,   168,
     249,   250,   251,   252,   253,    72,   171,   172,   267,   268,
     269,    84
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      73,   103,   101,   158,    98,    75,    76,    99,   169,   379,
      80,    81,   336,   379,   313,   379,   403,   346,   348,    74,
     320,   379,   173,   325,    78,   104,   277,    79,   331,   166,
     104,   238,   333,   174,   176,   332,   104,   179,   240,   104,
     104,   104,   284,   417,   314,   366,   103,   152,   153,   317,
     154,   155,   156,   372,    73,   247,    73,    17,    18,    19,
      20,    21,   161,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,   317,   377,    73,   354,   362,
     255,   358,   359,    40,   361,   395,   286,   365,   104,   105,
     338,   371,   240,   104,   184,    82,   407,   246,   273,   278,
     285,    73,   315,   181,   242,   243,   244,   370,   230,   231,
     245,   405,   380,   398,   411,   239,   419,   181,   404,   170,
     104,   391,   102,   317,   428,   104,   383,   349,   105,   350,
     421,   167,   240,   330,   279,   344,   345,   165,   415,   318,
     240,   156,   342,   351,   408,   238,   397,   323,   324,   248,
     405,   401,   229,   167,   255,   170,   272,   182,   409,   274,
     410,   104,   240,   156,   310,    73,   316,   254,   321,   257,
     270,   183,   334,   339,   281,   151,   258,   259,   161,   282,
     384,   340,   386,   387,   152,   153,   351,   154,   155,   156,
     353,   311,    17,    18,    19,    20,    21,   260,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
     317,   364,   261,   262,   263,   369,   375,   385,    40,   396,
     392,   288,   289,   290,   291,   292,   293,   394,   350,   176,
     294,   295,   296,   297,   298,   299,   300,   301,   161,   288,
     289,   290,   291,   292,   293,   400,    73,   413,   294,   295,
     296,   297,   298,   299,   300,   301,   418,   424,   270,   270,
     148,   149,   150,   151,   389,   276,   343,   270,   178,   420,
     363,   356,   152,   153,   357,   154,   155,   156,   271,   264,
     374,   265,   329,     0,     0,     0,   302,   266,   303,   373,
       0,     0,     0,   176,   378,     0,     0,     0,   390,   304,
     388,     0,     0,   305,     0,     0,     0,     0,   103,     0,
       0,     0,     0,     0,   254,     0,     0,   304,     0,     0,
       0,   305,    73,   146,   147,   148,   149,   150,   151,     0,
     176,     0,     0,     0,   402,    73,     0,   152,   153,     0,
     154,   155,   156,     0,   414,     0,     0,    83,     0,     0,
      85,     0,     0,    73,   422,   176,     0,     0,     0,     0,
       0,   425,     0,    73,     0,   426,   427,     0,   429,     0,
       0,   103,   103,     0,     0,   431,    86,    87,    88,    89,
      90,    91,    92,    93,    97,    97,     0,     0,     0,     0,
       0,     0,   247,     0,    17,    18,    19,    20,    21,    73,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,     0,   177,     0,     0,    73,    73,    73,     0,
      40,     0,     0,    73,     0,     0,    73,    73,   180,     0,
      73,     0,     0,     0,     0,     0,     0,     0,   186,     0,
       0,     0,     0,     0,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   355,     0,     0,   232,
     235,     0,     0,     1,     2,     3,     4,     0,     5,     6,
       0,     0,     0,     7,     8,     9,    10,    11,    12,     0,
       0,    13,    14,    15,    16,    97,     0,    17,    18,    19,
      20,    21,     0,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,     0,     0,    34,    35,    36,
      37,    38,    39,    40,     0,    41,    42,    43,    44,    45,
       0,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,     0,   283,     0,     0,
       0,     0,     0,   287,   152,   153,     0,   154,   155,   156,
       0,   312,     0,     0,     0,     0,     0,     0,     0,    46,
      47,     0,     0,     0,     0,    48,    49,     0,   326,   327,
       0,     0,     0,     0,    50,     0,    51,     0,    52,   337,
      53,    54,   100,     0,   341,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     4,     0,     5,     6,     0,
       0,     0,     7,     8,     9,    10,    11,    12,     0,     0,
      13,    14,    15,    16,   352,     0,    17,    18,    19,    20,
      21,   360,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,     0,     0,    34,    35,    36,    37,
      38,    39,    40,     0,    41,    42,    43,    44,    45,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,     0,     0,     0,     0,     0,     0,
       0,     0,   152,   153,     0,   154,   155,   156,    46,    47,
       0,     0,     0,     0,    48,    49,     0,     0,     0,     0,
       0,     0,     0,    50,     0,    51,     0,    52,     0,    53,
      54,   185,     1,     2,     3,     4,     0,     5,     6,     0,
       0,     0,     7,     8,     9,    10,    11,    12,     0,     0,
      13,    14,    15,    16,     0,     0,    17,    18,    19,    20,
      21,     0,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,     0,     0,    34,    35,    36,    37,
      38,    39,    40,     0,    41,    42,    43,    44,    45,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,     0,     0,     0,     0,     0,     0,     0,
       0,   152,   153,     0,   154,   155,   156,     0,    46,    47,
       0,     0,     0,     0,    48,    49,     0,     0,     0,     0,
       0,     0,     0,    50,     0,    51,     0,    52,     0,    53,
      54,   393,     1,     2,     3,     4,     0,     5,     6,     0,
       0,     0,     7,     8,     9,    10,    11,    12,     0,     0,
      13,    14,    15,    16,     0,     0,    17,    18,    19,    20,
      21,     0,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,     0,     0,    34,    35,    36,    37,
      38,    39,    40,     0,    41,    42,    43,    44,    45,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,     0,     0,     0,     0,     0,     0,     0,     0,
     152,   153,     0,   154,   155,   156,     0,     0,    46,    47,
       0,     0,     0,     0,    48,    49,     1,     2,     3,     0,
       0,     0,     0,    50,     0,    51,     0,    52,     0,    53,
      54,     0,     0,     0,     0,    14,    15,    16,     0,     0,
      17,    18,    19,    20,    21,     0,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,   258,   259,
      34,    35,    36,    37,    38,    39,    40,     0,    41,    42,
      43,    44,    45,     0,    17,    18,    19,    20,    21,   260,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,     0,     0,   261,   262,   263,     0,     0,     0,
      40,     0,     0,   143,   144,   145,   146,   147,   148,   149,
     150,   151,    46,    47,     0,     0,     0,     0,    48,    49,
     152,   153,     0,   154,   155,   156,   376,    50,     0,    51,
       0,    52,    17,    18,    19,    20,    21,     0,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       0,     0,     0,     0,     0,     0,     0,     0,    40,     0,
       0,   264,     0,   265,     0,    14,    15,    16,   233,   328,
      17,    18,    19,    20,    21,     0,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,     0,     0,
      34,    35,    36,    37,    38,    39,    40,     0,    41,    42,
      43,    44,    45,    14,    15,    16,    94,     0,    17,    18,
      19,    20,    21,     0,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     0,     0,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,    43,    44,
      45,     0,    46,    47,     0,     0,     0,     0,    48,    49,
       0,     0,     0,     0,     0,     0,     0,    50,     0,    51,
       0,    52,   234,     0,     0,     0,     0,     0,     0,     0,
       0,   143,   144,   145,   146,   147,   148,   149,   150,   151,
      46,    47,     0,     0,     0,     0,    48,    49,   152,   153,
       0,   154,   155,   156,     0,    50,     0,    51,     0,    52,
      14,    15,    16,     0,     0,    17,    18,    19,    20,    21,
       0,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,     0,     0,    34,    35,    36,    37,    38,
      39,    40,     0,    41,    42,    43,    44,    45,    17,    18,
      19,    20,    21,     0,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     0,     0,   261,   262,
     263,     0,     0,     0,    40,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    46,    47,     0,
       0,     0,     0,    48,    49,     0,     0,     0,     0,     0,
       0,     0,    50,     0,    51,     0,    52,   288,   289,   290,
     291,   292,   293,     0,     0,     0,   294,   295,   296,   297,
     298,   299,   300,   301,     0,     0,     0,     0,     0,     0,
       0,     0,   107,   108,   109,   264,     0,   265,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   280,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,     0,     0,     0,   304,     0,     0,     0,   305,
     152,   153,     0,   154,   155,   156,   107,   108,   109,     0,
       0,     0,     0,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     240,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,     0,     0,     0,     0,
       0,     0,     0,     0,   152,   153,     0,   154,   155,   156,
     107,   108,   109,     0,     0,     0,     0,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,     0,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
       0,     0,     0,     0,     0,     0,     0,     0,   152,   153,
     367,   154,   155,   156,   107,   108,   109,     0,     0,     0,
       0,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,     0,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,     0,     0,     0,     0,     0,     0,
       0,     0,   152,   153,   368,   154,   155,   156,   107,   108,
     109,     0,     0,     0,     0,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,     0,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,     0,     0,
       0,     0,     0,     0,     0,     0,   152,   153,     0,   154,
     155,   156,   107,   108,   109,     0,     0,     0,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,     0,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   275,   143,   144,   145,   146,   147,   148,   149,
     150,   151,     0,     0,     0,     0,     0,     0,     0,     0,
     152,   153,     0,   154,   155,   156,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,     0,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,     0,
       0,     0,     0,     0,     0,     0,     0,   152,   153,     0,
     154,   155,   156,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,     0,     0,     0,     0,     0,
       0,     0,     0,   152,   153,     0,   154,   155,   156,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
       0,     0,     0,     0,     0,     0,     0,     0,   152,   153,
       0,   154,   155,   156,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,     0,     0,     0,     0,     0,     0,
       0,     0,   152,   153,     0,   154,   155,   156,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,     0,     0,     0,
       0,     0,     0,     0,     0,   152,   153,     0,   154,   155,
     156
};

static const yytype_int16 yycheck[] =
{
       0,    56,    54,    61,    51,     5,     6,    52,    10,    19,
      10,    11,   274,    19,   248,    19,    20,   304,   305,   118,
     254,    19,    77,   260,   118,    61,   178,   118,   269,    74,
      61,    61,   269,    78,    79,   269,    61,    82,    79,    61,
      61,    61,    61,    79,    61,   325,   101,   113,   114,    62,
     116,   117,   118,   333,    54,    25,    56,    27,    28,    29,
      30,    31,    62,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    62,   338,    77,   312,   320,
     121,   315,   316,    53,   318,   365,   238,   324,    61,   120,
     120,   332,    79,    61,   119,   118,   383,   119,   119,   119,
     119,   101,   119,    61,   162,   163,   164,   120,   153,   154,
     165,   381,   122,   375,   394,    62,   122,    61,   122,   121,
      61,   355,     0,    62,   122,    61,    61,    83,   120,    85,
     410,   118,    79,   120,   181,   302,   303,    79,   400,    78,
      79,   118,   119,   114,   115,    61,   119,   258,   259,   119,
     420,   119,   152,   118,   121,   121,    14,   115,   392,   120,
     394,    61,    79,   118,    62,   165,   119,   167,   122,   169,
     170,   115,   118,    95,   115,   104,    11,    12,   178,   115,
     115,   121,   349,   350,   113,   114,   114,   116,   117,   118,
       7,   246,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      62,   118,    47,    48,    49,   120,   120,   119,    53,   120,
     119,    36,    37,    38,    39,    40,    41,   119,    85,   274,
      45,    46,    47,    48,    49,    50,    51,    52,   238,    36,
      37,    38,    39,    40,    41,   120,   246,   119,    45,    46,
      47,    48,    49,    50,    51,    52,    79,   119,   258,   259,
     101,   102,   103,   104,   351,   178,   284,   267,    79,   406,
     322,   314,   113,   114,   314,   116,   117,   118,   171,   114,
     335,   116,   267,    -1,    -1,    -1,    83,   122,    85,   334,
      -1,    -1,    -1,   338,   339,    -1,    -1,    -1,   353,   114,
     115,    -1,    -1,   118,    -1,    -1,    -1,    -1,   363,    -1,
      -1,    -1,    -1,    -1,   314,    -1,    -1,   114,    -1,    -1,
      -1,   118,   322,    99,   100,   101,   102,   103,   104,    -1,
     375,    -1,    -1,    -1,   379,   335,    -1,   113,   114,    -1,
     116,   117,   118,    -1,   399,    -1,    -1,    13,    -1,    -1,
      16,    -1,    -1,   353,   412,   400,    -1,    -1,    -1,    -1,
      -1,   416,    -1,   363,    -1,   417,   418,    -1,   423,    -1,
      -1,   426,   427,    -1,    -1,   430,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    -1,    27,    28,    29,    30,    31,   399,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    79,    -1,    -1,   416,   417,   418,    -1,
      53,    -1,    -1,   423,    -1,    -1,   426,   427,    94,    -1,
     430,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   119,    -1,    -1,   155,
     156,    -1,    -1,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    13,    14,    15,    16,    17,    18,    -1,
      -1,    21,    22,    23,    24,   181,    -1,    27,    28,    29,
      30,    31,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      -1,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    -1,   233,    -1,    -1,
      -1,    -1,    -1,   239,   113,   114,    -1,   116,   117,   118,
      -1,   247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,    -1,    -1,    -1,    -1,   105,   106,    -1,   264,   265,
      -1,    -1,    -1,    -1,   114,    -1,   116,    -1,   118,   275,
     120,   121,   122,    -1,   280,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    13,    14,    15,    16,    17,    18,    -1,    -1,
      21,    22,    23,    24,   310,    -1,    27,    28,    29,    30,
      31,   317,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,   114,    -1,   116,   117,   118,    99,   100,
      -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,   116,    -1,   118,    -1,   120,
     121,   122,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    13,    14,    15,    16,    17,    18,    -1,    -1,
      21,    22,    23,    24,    -1,    -1,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,   114,    -1,   116,   117,   118,    -1,    99,   100,
      -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,   116,    -1,   118,    -1,   120,
     121,   122,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    13,    14,    15,    16,    17,    18,    -1,    -1,
      21,    22,    23,    24,    -1,    -1,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   114,    -1,   116,   117,   118,    -1,    -1,    99,   100,
      -1,    -1,    -1,    -1,   105,   106,     3,     4,     5,    -1,
      -1,    -1,    -1,   114,    -1,   116,    -1,   118,    -1,   120,
     121,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,    -1,
      27,    28,    29,    30,    31,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    11,    12,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    47,    48,    49,    -1,    -1,    -1,
      53,    -1,    -1,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    99,   100,    -1,    -1,    -1,    -1,   105,   106,
     113,   114,    -1,   116,   117,   118,   119,   114,    -1,   116,
      -1,   118,    27,    28,    29,    30,    31,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      -1,   114,    -1,   116,    -1,    22,    23,    24,    25,   122,
      27,    28,    29,    30,    31,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    22,    23,    24,    25,    -1,    27,    28,
      29,    30,    31,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    -1,    99,   100,    -1,    -1,    -1,    -1,   105,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,   116,
      -1,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      99,   100,    -1,    -1,    -1,    -1,   105,   106,   113,   114,
      -1,   116,   117,   118,    -1,   114,    -1,   116,    -1,   118,
      22,    23,    24,    -1,    -1,    27,    28,    29,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    27,    28,
      29,    30,    31,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    47,    48,
      49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,
      -1,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,    -1,   116,    -1,   118,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,   114,    -1,   116,    -1,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    -1,    -1,    -1,   114,    -1,    -1,    -1,   118,
     113,   114,    -1,   116,   117,   118,    55,    56,    57,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,   114,    -1,   116,   117,   118,
      55,    56,    57,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
     115,   116,   117,   118,    55,    56,    57,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    -1,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,   114,   115,   116,   117,   118,    55,    56,
      57,    -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,
     117,   118,    55,    56,    57,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    -1,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   114,    -1,   116,   117,   118,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    -1,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,
     116,   117,   118,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,    -1,   116,   117,   118,    84,
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
     118
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
     114,   116,   118,   120,   121,   124,   125,   126,   138,   142,
     143,   147,   150,   151,   152,   160,   161,   162,   163,   164,
     165,   169,   178,   184,   118,   184,   184,   153,   118,   118,
     184,   184,   118,   143,   184,   143,   143,   143,   143,   143,
     143,   143,   143,   143,    25,   139,   140,   143,   139,   142,
     122,   125,     0,   126,    61,   120,   130,    55,    56,    57,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   113,   114,   116,   117,   118,   144,   130,   148,
     149,   184,   127,   128,   129,    79,   142,   118,   172,    10,
     121,   179,   180,   126,   142,   141,   142,   143,   150,   142,
     143,    61,   115,   115,   119,   122,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   184,
     142,   142,   143,    25,   119,   143,   145,   146,    61,    62,
      79,   137,   130,   130,   130,   126,   119,    25,   119,   173,
     174,   175,   176,   177,   184,   121,   170,   184,    11,    12,
      32,    47,    48,    49,   114,   116,   122,   181,   182,   183,
     184,   180,    14,   119,   120,    95,   148,   149,   119,   139,
      79,   115,   115,   143,    61,   119,   149,   143,    36,    37,
      38,    39,    40,    41,    45,    46,    47,    48,    49,    50,
      51,    52,    83,    85,   114,   118,   132,   133,   134,   136,
      62,   126,   143,   137,    61,   119,   119,    62,    78,   131,
     137,   122,   171,   183,   183,   172,   143,   143,   122,   182,
     120,   131,   137,   172,   118,   155,   141,   143,   120,    95,
     121,   143,   119,   144,   133,   133,   132,   135,   132,    83,
      85,   114,   143,     7,   137,   119,   174,   177,   137,   137,
     143,   137,   131,   125,   118,   172,   170,   115,   115,   120,
     120,   131,   170,   142,   126,   120,   119,   141,   142,    19,
     122,   166,   167,    61,   115,   119,   133,   133,   115,   134,
     126,   137,   119,   122,   119,   170,   120,   119,   141,   158,
     120,   119,   142,    20,   122,   167,   168,   132,   115,   137,
     137,   170,   154,   119,   126,   141,   159,    79,    79,   122,
     166,   170,   130,   156,   119,   126,   125,   125,   122,   126,
     157,   126
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   123,   124,   125,   125,   126,   126,   126,   126,   126,
     126,   127,   126,   128,   126,   129,   126,   126,   126,   126,
     126,   130,   131,   132,   132,   132,   133,   133,   133,   134,
     134,   134,   134,   134,   135,   135,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     137,   138,   138,   139,   139,   139,   140,   140,   141,   141,
     142,   142,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   144,   144,   144,   145,   145,   146,   146,
     147,   148,   148,   149,   149,   149,   149,   150,   150,   150,
     151,   151,   153,   154,   152,   155,   152,   156,   152,   157,
     152,   158,   152,   159,   152,   160,   160,   161,   161,   162,
     162,   163,   164,   164,   165,   165,   165,   165,   166,   166,
     167,   167,   168,   168,   169,   170,   171,   170,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   173,   173,
     174,   174,   175,   175,   176,   176,   176,   176,   177,   177,
     178,   178,   179,   180,   180,   181,   181,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   183,   183,   183,   183,
     183,   183,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     2,     1,     1,
       1,     0,     3,     0,     3,     0,     3,     1,     1,     1,
       1,     1,     2,     1,     2,     2,     3,     3,     1,     3,
       1,     3,     4,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     3,     0,     1,     3,     1,     2,     0,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     5,     3,     2,     3,     3,     1,
       4,     4,     2,     2,     3,     4,     1,     3,     1,     2,
       2,     1,     3,     1,     2,     3,     4,     1,     1,     1,
       5,     7,     0,     0,     9,     0,     6,     0,    10,     0,
      11,     0,     8,     0,     9,     1,     2,     1,     2,     1,
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
#line 84 "parser.y"
                    { Print("- R: statementList -> script"); }
#line 2291 "parser.tab.cpp"
    break;

  case 3: /* statementList: statementListItem  */
#line 88 "parser.y"
                        { Print("- R: statementListItem -> statementList"); }
#line 2297 "parser.tab.cpp"
    break;

  case 4: /* statementList: statementList statementListItem  */
#line 89 "parser.y"
                                      { Print("- R: statementList statementListItem -> statementList"); }
#line 2303 "parser.tab.cpp"
    break;

  case 5: /* statementListItem: ';'  */
#line 93 "parser.y"
                                    { Print("- R: ';' -> statementListItem"); }
#line 2309 "parser.tab.cpp"
    break;

  case 6: /* statementListItem: expressionList statementSep  */
#line 94 "parser.y"
                                    { Print("- R: expressionList statementSep -> statementListItem"); }
#line 2315 "parser.tab.cpp"
    break;

  case 7: /* statementListItem: varStatement statementSep  */
#line 95 "parser.y"
                                    { Print("- R: varStatement statementSep -> statementListItem"); }
#line 2321 "parser.tab.cpp"
    break;

  case 8: /* statementListItem: ifStatement  */
#line 96 "parser.y"
                                    { Print("- R: ifStatement -> statementListItem"); }
#line 2327 "parser.tab.cpp"
    break;

  case 9: /* statementListItem: switchStatement  */
#line 97 "parser.y"
                                    { Print("- R: switchStatement -> statementListItem"); }
#line 2333 "parser.tab.cpp"
    break;

  case 10: /* statementListItem: iterationStatement  */
#line 98 "parser.y"
                                    { Print("- R: iterationStatement -> statementListItem"); }
#line 2339 "parser.tab.cpp"
    break;

  case 11: /* $@1: %empty  */
#line 99 "parser.y"
                        {
        if ( !isInIterationBody ) { 
            yyerror("illegal continue statement"); 
        } 
    }
#line 2349 "parser.tab.cpp"
    break;

  case 12: /* statementListItem: continueStatement $@1 statementSep  */
#line 103 "parser.y"
                                    { Print("- R: continueStatement statementSep -> statementListItem");  }
#line 2355 "parser.tab.cpp"
    break;

  case 13: /* $@2: %empty  */
#line 104 "parser.y"
                     {
        if ( !isInIterationBody ) { 
            yyerror("illegal break statement"); 
        } 
    }
#line 2365 "parser.tab.cpp"
    break;

  case 14: /* statementListItem: breakStatement $@2 statementSep  */
#line 108 "parser.y"
                                    { Print("- R: breakStatement statementSep -> statementListItem"); }
#line 2371 "parser.tab.cpp"
    break;

  case 15: /* $@3: %empty  */
#line 109 "parser.y"
                      { 
        if ( !isInFunctionBody ) { 
            yyerror("illegal return statement"); 
        } 
    }
#line 2381 "parser.tab.cpp"
    break;

  case 16: /* statementListItem: returnStatement $@3 statementSep  */
#line 113 "parser.y"
                                    { Print("- R: returnStatement statementSep -> statementListItem"); }
#line 2387 "parser.tab.cpp"
    break;

  case 17: /* statementListItem: labelledStatement  */
#line 114 "parser.y"
                                    { Print("- R: labelledStatement -> statementListItem"); }
#line 2393 "parser.tab.cpp"
    break;

  case 18: /* statementListItem: blockStatement  */
#line 115 "parser.y"
                                    { Print("- R: blockStatement -> statementListItem"); }
#line 2399 "parser.tab.cpp"
    break;

  case 19: /* statementListItem: functionDeclaration  */
#line 116 "parser.y"
                                    { Print("- R: functionDeclaration -> statementListItem"); }
#line 2405 "parser.tab.cpp"
    break;

  case 20: /* statementListItem: classDeclaration  */
#line 117 "parser.y"
                                    { Print("- R: classDeclaration -> statementListItem"); }
#line 2411 "parser.tab.cpp"
    break;

  case 21: /* statementSep: ';'  */
#line 121 "parser.y"
          { Print("- R: ';' -> statementSep"); }
#line 2417 "parser.tab.cpp"
    break;

  case 22: /* initializer: '=' singleExpression  */
#line 125 "parser.y"
                           { Print("- R: '=' singleExpression -> initializer"); }
#line 2423 "parser.tab.cpp"
    break;

  case 23: /* type: unionOrIntersectionOrPrimaryType  */
#line 131 "parser.y"
                                       { Print("- R: unionOrIntersectionOrPrimaryType -> type"); }
#line 2429 "parser.tab.cpp"
    break;

  case 24: /* type: '|' unionOrIntersectionOrPrimaryType  */
#line 132 "parser.y"
                                           { Print("- R: '|' unionOrIntersectionOrPrimaryType -> type"); }
#line 2435 "parser.tab.cpp"
    break;

  case 25: /* type: '&' unionOrIntersectionOrPrimaryType  */
#line 133 "parser.y"
                                           { Print("- R: '&' unionOrIntersectionOrPrimaryType -> type"); }
#line 2441 "parser.tab.cpp"
    break;

  case 26: /* unionOrIntersectionOrPrimaryType: unionOrIntersectionOrPrimaryType '|' unionOrIntersectionOrPrimaryType  */
#line 137 "parser.y"
                                                                            { Print("- R: unionOrIntersectionOrPrimaryType '|' unionOrIntersectionOrPrimaryType -> unionOrIntersectionOrPrimaryType"); }
#line 2447 "parser.tab.cpp"
    break;

  case 27: /* unionOrIntersectionOrPrimaryType: unionOrIntersectionOrPrimaryType '&' unionOrIntersectionOrPrimaryType  */
#line 138 "parser.y"
                                                                            { Print("- R: unionOrIntersectionOrPrimaryType '&' unionOrIntersectionOrPrimaryType -> unionOrIntersectionOrPrimaryType"); }
#line 2453 "parser.tab.cpp"
    break;

  case 28: /* unionOrIntersectionOrPrimaryType: primaryType  */
#line 139 "parser.y"
                  { Print("- R: primaryType -> argument"); }
#line 2459 "parser.tab.cpp"
    break;

  case 29: /* primaryType: '(' type ')'  */
#line 143 "parser.y"
                   { Print("- R: '(' type ')' -> primaryType"); }
#line 2465 "parser.tab.cpp"
    break;

  case 30: /* primaryType: predefinedType  */
#line 144 "parser.y"
                     { Print("- R: predefinedType -> primaryType"); }
#line 2471 "parser.tab.cpp"
    break;

  case 31: /* primaryType: primaryType '[' ']'  */
#line 145 "parser.y"
                          { Print("- R: primaryType '[' ']' -> primaryType"); }
#line 2477 "parser.tab.cpp"
    break;

  case 32: /* primaryType: primaryType '[' primaryType ']'  */
#line 146 "parser.y"
                                      { Print("- R: primaryType '[' primaryType ']' -> primaryType"); }
#line 2483 "parser.tab.cpp"
    break;

  case 33: /* primaryType: '[' tupleTypeElements ']'  */
#line 147 "parser.y"
                                { Print("- R: '[' tupleTypeElements ']' -> primaryType"); }
#line 2489 "parser.tab.cpp"
    break;

  case 34: /* tupleTypeElements: type  */
#line 151 "parser.y"
           { Print("- R: type -> tupleTypeElements"); }
#line 2495 "parser.tab.cpp"
    break;

  case 35: /* tupleTypeElements: tupleTypeElements ',' type  */
#line 152 "parser.y"
                                 { Print("- R: tupleTypeElements ',' type -> tupleTypeElements"); }
#line 2501 "parser.tab.cpp"
    break;

  case 36: /* predefinedType: ANY  */
#line 156 "parser.y"
          { Print("- R: ANY -> predefinedType"); }
#line 2507 "parser.tab.cpp"
    break;

  case 37: /* predefinedType: NUMBER  */
#line 157 "parser.y"
             { Print("- R: NUMBER -> predefinedType"); }
#line 2513 "parser.tab.cpp"
    break;

  case 38: /* predefinedType: STRING  */
#line 158 "parser.y"
             { Print("- R: STRING -> predefinedType"); }
#line 2519 "parser.tab.cpp"
    break;

  case 39: /* predefinedType: BOOLEAN  */
#line 159 "parser.y"
              { Print("- R: BOOLEAN -> predefinedType"); }
#line 2525 "parser.tab.cpp"
    break;

  case 40: /* predefinedType: NEVER  */
#line 160 "parser.y"
            { Print("- R: NEVER -> predefinedType"); }
#line 2531 "parser.tab.cpp"
    break;

  case 41: /* predefinedType: UNKNOWN  */
#line 161 "parser.y"
              { Print("- R: UNKNOWN -> predefinedType"); }
#line 2537 "parser.tab.cpp"
    break;

  case 42: /* predefinedType: UNDEFINED  */
#line 162 "parser.y"
                { Print("- R: UNDEFINED -> predefinedType"); }
#line 2543 "parser.tab.cpp"
    break;

  case 43: /* predefinedType: VOID  */
#line 163 "parser.y"
           { Print("- R: VOID -> predefinedType"); }
#line 2549 "parser.tab.cpp"
    break;

  case 44: /* predefinedType: NULL_KW  */
#line 164 "parser.y"
              { Print("- R: NULL_KW -> predefinedType"); }
#line 2555 "parser.tab.cpp"
    break;

  case 45: /* predefinedType: INT_LIT  */
#line 165 "parser.y"
              { Print("- R: INT_LIT -> predefinedType"); }
#line 2561 "parser.tab.cpp"
    break;

  case 46: /* predefinedType: FLOAT_LIT  */
#line 166 "parser.y"
                { Print("- R: FLOAT_LIT -> predefinedType"); }
#line 2567 "parser.tab.cpp"
    break;

  case 47: /* predefinedType: TRUE_KW  */
#line 167 "parser.y"
              { Print("- R: TRUE_WD -> predefinedType"); }
#line 2573 "parser.tab.cpp"
    break;

  case 48: /* predefinedType: FALSE_KW  */
#line 168 "parser.y"
               { Print("- R: FALSE_KW -> predefinedType"); }
#line 2579 "parser.tab.cpp"
    break;

  case 49: /* predefinedType: STRING_LIT  */
#line 169 "parser.y"
                 { Print("- R: STRING_LIT -> predefinedType"); }
#line 2585 "parser.tab.cpp"
    break;

  case 50: /* typeAnnotation: ':' type  */
#line 173 "parser.y"
               { Print("- R: ':' type -> typeAnnotation"); }
#line 2591 "parser.tab.cpp"
    break;

  case 51: /* arrayLiteral: '[' elementList ']'  */
#line 178 "parser.y"
                          { Print("- R: [ elementList ']' -> arrayLiteral"); }
#line 2597 "parser.tab.cpp"
    break;

  case 52: /* arrayLiteral: ENDL_BRACKET_OPEN elementList ']'  */
#line 179 "parser.y"
                                        { Print("- R: ENDL_BRACKET_OPEN elementList ']' -> arrayLiteral"); }
#line 2603 "parser.tab.cpp"
    break;

  case 53: /* elementList: %empty  */
#line 183 "parser.y"
                  { Print("- R: #empty# -> elementList"); }
#line 2609 "parser.tab.cpp"
    break;

  case 54: /* elementList: arrayElement  */
#line 184 "parser.y"
                   { Print("- R: arrayElement -> elementList"); }
#line 2615 "parser.tab.cpp"
    break;

  case 55: /* elementList: elementList ',' elementList  */
#line 185 "parser.y"
                                  { Print("- R: elementList ',' elementList -> elementList"); }
#line 2621 "parser.tab.cpp"
    break;

  case 56: /* arrayElement: singleExpression  */
#line 189 "parser.y"
                       { Print("- R: singleExpression -> arrayElement"); }
#line 2627 "parser.tab.cpp"
    break;

  case 57: /* arrayElement: ELLIPSIS singleExpression  */
#line 190 "parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> arrayElement"); }
#line 2633 "parser.tab.cpp"
    break;

  case 58: /* expressionListOpt: %empty  */
#line 196 "parser.y"
                  { Print("- R: #empty# -> expressionListOpt"); }
#line 2639 "parser.tab.cpp"
    break;

  case 59: /* expressionListOpt: expressionList  */
#line 197 "parser.y"
                     { Print("- R: expressionList -> expressionListOpt"); }
#line 2645 "parser.tab.cpp"
    break;

  case 60: /* expressionList: singleExpression  */
#line 201 "parser.y"
                       { Print("- R: singleExpression -> expressionList"); }
#line 2651 "parser.tab.cpp"
    break;

  case 61: /* expressionList: expressionList ',' singleExpression  */
#line 202 "parser.y"
                                          { Print("- R: expressionList ',' singleExpression -> expressionList"); }
#line 2657 "parser.tab.cpp"
    break;

  case 62: /* singleExpression: identifier  */
#line 206 "parser.y"
                 { Print("- R: identifier -> singleExpression"); }
#line 2663 "parser.tab.cpp"
    break;

  case 63: /* singleExpression: THIS  */
#line 207 "parser.y"
           { Print("- R: THIS -> singleExpression"); }
#line 2669 "parser.tab.cpp"
    break;

  case 64: /* singleExpression: SUPER  */
#line 208 "parser.y"
            { Print("- R: SUPER -> singleExpression"); }
#line 2675 "parser.tab.cpp"
    break;

  case 65: /* singleExpression: INT_LIT  */
#line 209 "parser.y"
              { Print("- R: INT_LIT -> singleExpression"); }
#line 2681 "parser.tab.cpp"
    break;

  case 66: /* singleExpression: FLOAT_LIT  */
#line 210 "parser.y"
                { Print("- R: FLOAT_LIT -> singleExpression"); }
#line 2687 "parser.tab.cpp"
    break;

  case 67: /* singleExpression: STRING_LIT  */
#line 211 "parser.y"
                 { Print("- R: STRING_LIT -> singleExpression"); }
#line 2693 "parser.tab.cpp"
    break;

  case 68: /* singleExpression: TEMPLATE_LITERAL  */
#line 212 "parser.y"
                       { Print("- R: TEMPLATE_LITERAL -> singleExpression"); }
#line 2699 "parser.tab.cpp"
    break;

  case 69: /* singleExpression: TRUE_KW  */
#line 213 "parser.y"
              { Print("- R: TRUE_LITERAL -> singleExpression"); }
#line 2705 "parser.tab.cpp"
    break;

  case 70: /* singleExpression: FALSE_KW  */
#line 214 "parser.y"
               { Print("- R: FALSE_LITERAL -> singleExpression"); }
#line 2711 "parser.tab.cpp"
    break;

  case 71: /* singleExpression: NULL_KW  */
#line 215 "parser.y"
              { Print("- R: NULL_LITERAL -> singleExpression"); }
#line 2717 "parser.tab.cpp"
    break;

  case 72: /* singleExpression: '-' singleExpression  */
#line 216 "parser.y"
                                        { Print("- R: '-' singleExpression -> singleExpression"); }
#line 2723 "parser.tab.cpp"
    break;

  case 73: /* singleExpression: '+' singleExpression  */
#line 217 "parser.y"
                                       { Print("- R: '+'s singleExpression -> singleExpression"); }
#line 2729 "parser.tab.cpp"
    break;

  case 74: /* singleExpression: '!' singleExpression  */
#line 218 "parser.y"
                           { Print("- R: '!' singleExpression -> singleExpression"); }
#line 2735 "parser.tab.cpp"
    break;

  case 75: /* singleExpression: '~' singleExpression  */
#line 219 "parser.y"
                           { Print("- R: '~' singleExpression -> singleExpression"); }
#line 2741 "parser.tab.cpp"
    break;

  case 76: /* singleExpression: singleExpression OPERATOR_INCREMENT  */
#line 220 "parser.y"
                                                               { Print("- R: singleExpression OPERATOR_INCREMENT -> singleExpression"); }
#line 2747 "parser.tab.cpp"
    break;

  case 77: /* singleExpression: singleExpression OPERATOR_DECREMENT  */
#line 221 "parser.y"
                                                               { Print("- R: singleExpression OPERATOR_DECREMENT -> singleExpression"); }
#line 2753 "parser.tab.cpp"
    break;

  case 78: /* singleExpression: ENDL_OPERATOR_INCREMENT singleExpression  */
#line 222 "parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 2759 "parser.tab.cpp"
    break;

  case 79: /* singleExpression: ENDL_OPERATOR_DECREMENT singleExpression  */
#line 223 "parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 2765 "parser.tab.cpp"
    break;

  case 80: /* singleExpression: OPERATOR_INCREMENT singleExpression  */
#line 224 "parser.y"
                                                               { Print("- R: OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 2771 "parser.tab.cpp"
    break;

  case 81: /* singleExpression: OPERATOR_DECREMENT singleExpression  */
#line 225 "parser.y"
                                                               { Print("- R: OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 2777 "parser.tab.cpp"
    break;

  case 82: /* singleExpression: singleExpression '+' singleExpression  */
#line 226 "parser.y"
                                            { Print("- R: singleExpression '+' singleExpression -> singleExpression"); }
#line 2783 "parser.tab.cpp"
    break;

  case 83: /* singleExpression: singleExpression '-' singleExpression  */
#line 227 "parser.y"
                                            { Print("- R: singleExpression '-' singleExpression -> singleExpression"); }
#line 2789 "parser.tab.cpp"
    break;

  case 84: /* singleExpression: singleExpression '*' singleExpression  */
#line 228 "parser.y"
                                            { Print("- R: singleExpression '*' singleExpression -> singleExpression"); }
#line 2795 "parser.tab.cpp"
    break;

  case 85: /* singleExpression: singleExpression '/' singleExpression  */
#line 229 "parser.y"
                                            { Print("- R: singleExpression '/' singleExpression -> singleExpression"); }
#line 2801 "parser.tab.cpp"
    break;

  case 86: /* singleExpression: singleExpression '%' singleExpression  */
#line 230 "parser.y"
                                            { Print("- R: singleExpression '%' singleExpression -> singleExpression"); }
#line 2807 "parser.tab.cpp"
    break;

  case 87: /* singleExpression: singleExpression '<' singleExpression  */
#line 231 "parser.y"
                                            { Print("- R: singleExpression '<' singleExpression -> singleExpression"); }
#line 2813 "parser.tab.cpp"
    break;

  case 88: /* singleExpression: singleExpression '>' singleExpression  */
#line 232 "parser.y"
                                            { Print("- R: singleExpression '>' singleExpression -> singleExpression"); }
#line 2819 "parser.tab.cpp"
    break;

  case 89: /* singleExpression: singleExpression OPERATOR_POWER singleExpression  */
#line 233 "parser.y"
                                                       { Print("- R: singleExpression OPERATOR_POWER singleExpression -> singleExpression"); }
#line 2825 "parser.tab.cpp"
    break;

  case 90: /* singleExpression: singleExpression OPERATOR_EQUAL singleExpression  */
#line 234 "parser.y"
                                                       { Print("- R: singleExpression OPERATOR_EQUAL singleExpression -> singleExpression"); }
#line 2831 "parser.tab.cpp"
    break;

  case 91: /* singleExpression: singleExpression OPERATOR_NOT_EQUAL singleExpression  */
#line 235 "parser.y"
                                                           { Print("- R: singleExpression OPERATOR_NOT_EQUAL singleExpression -> singleExpression"); }
#line 2837 "parser.tab.cpp"
    break;

  case 92: /* singleExpression: singleExpression OPERATOR_STRICT_EQUAL singleExpression  */
#line 236 "parser.y"
                                                              { Print("- R: singleExpression OPERATOR_STRICT_EQUAL singleExpression -> singleExpression"); }
#line 2843 "parser.tab.cpp"
    break;

  case 93: /* singleExpression: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression  */
#line 237 "parser.y"
                                                                  { Print("- R: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression -> singleExpression"); }
#line 2849 "parser.tab.cpp"
    break;

  case 94: /* singleExpression: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression  */
#line 238 "parser.y"
                                                                 { Print("- R: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression -> singleExpression"); }
#line 2855 "parser.tab.cpp"
    break;

  case 95: /* singleExpression: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression  */
#line 239 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression -> singleExpression"); }
#line 2861 "parser.tab.cpp"
    break;

  case 96: /* singleExpression: singleExpression '=' singleExpression  */
#line 240 "parser.y"
                                            { Print("- R: singleExpression '=' singleExpression -> singleExpression"); }
#line 2867 "parser.tab.cpp"
    break;

  case 97: /* singleExpression: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression  */
#line 241 "parser.y"
                                                                 { Print("- R: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression -> singleExpression"); }
#line 2873 "parser.tab.cpp"
    break;

  case 98: /* singleExpression: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression  */
#line 242 "parser.y"
                                                               { Print("- R: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression -> singleExpression"); }
#line 2879 "parser.tab.cpp"
    break;

  case 99: /* singleExpression: singleExpression OPERATOR_ASSIGN_MOD singleExpression  */
#line 243 "parser.y"
                                                            { Print("- R: singleExpression OPERATOR_ASSIGN_MOD singleExpression -> singleExpression"); }
#line 2885 "parser.tab.cpp"
    break;

  case 100: /* singleExpression: singleExpression OPERATOR_ASSIGN_PLUS singleExpression  */
#line 244 "parser.y"
                                                             { Print("- R: singleExpression OPERATOR_ASSIGN_PLUS singleExpression -> singleExpression"); }
#line 2891 "parser.tab.cpp"
    break;

  case 101: /* singleExpression: singleExpression OPERATOR_ASSIGN_MINUS singleExpression  */
#line 245 "parser.y"
                                                              { Print("- R: singleExpression OPERATOR_ASSIGN_MINUS singleExpression -> singleExpression"); }
#line 2897 "parser.tab.cpp"
    break;

  case 102: /* singleExpression: singleExpression OPERATOR_ASSIGN_SHIFT_LEFT singleExpression  */
#line 246 "parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_SHIFT_LEFT singleExpression -> singleExpression"); }
#line 2903 "parser.tab.cpp"
    break;

  case 103: /* singleExpression: singleExpression OPERATOR_ASSIGN_SHIFT_RIGHT singleExpression  */
#line 247 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 2909 "parser.tab.cpp"
    break;

  case 104: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_AND singleExpression  */
#line 248 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_AND singleExpression -> singleExpression"); }
#line 2915 "parser.tab.cpp"
    break;

  case 105: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_XOR singleExpression  */
#line 249 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_XOR singleExpression -> singleExpression"); }
#line 2921 "parser.tab.cpp"
    break;

  case 106: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_OR singleExpression  */
#line 250 "parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_OR singleExpression -> singleExpression"); }
#line 2927 "parser.tab.cpp"
    break;

  case 107: /* singleExpression: singleExpression OPERATOR_ASSIGN_POWER singleExpression  */
#line 251 "parser.y"
                                                              { Print("- R: singleExpression OPERATOR_ASSIGN_POWER singleExpression -> singleExpression"); }
#line 2933 "parser.tab.cpp"
    break;

  case 108: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression  */
#line 252 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression -> singleExpression"); }
#line 2939 "parser.tab.cpp"
    break;

  case 109: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression  */
#line 253 "parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression -> singleExpression"); }
#line 2945 "parser.tab.cpp"
    break;

  case 110: /* singleExpression: singleExpression OPERATOR_ASSIGN_NULLISH_COALESCING singleExpression  */
#line 254 "parser.y"
                                                                           { Print("- R: singleExpression OPERATOR_ASSIGN_NULLISH_COALESCING singleExpression -> singleExpression"); }
#line 2951 "parser.tab.cpp"
    break;

  case 111: /* singleExpression: singleExpression OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT singleExpression  */
#line 255 "parser.y"
                                                                             { Print("- R: singleExpression OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 2957 "parser.tab.cpp"
    break;

  case 112: /* singleExpression: singleExpression OPERATOR_LOGICAL_OR singleExpression  */
#line 256 "parser.y"
                                                            { Print("- R: singleExpression OPERATOR_LOGICAL_OR singleExpression -> singleExpression"); }
#line 2963 "parser.tab.cpp"
    break;

  case 113: /* singleExpression: singleExpression OPERATOR_LOGICAL_AND singleExpression  */
#line 257 "parser.y"
                                                             { Print("- R: singleExpression OPERATOR_LOGICAL_AND singleExpression -> singleExpression"); }
#line 2969 "parser.tab.cpp"
    break;

  case 114: /* singleExpression: singleExpression '|' singleExpression  */
#line 258 "parser.y"
                                            { Print("- R: singleExpression '|' singleExpression -> singleExpression"); }
#line 2975 "parser.tab.cpp"
    break;

  case 115: /* singleExpression: singleExpression '^' singleExpression  */
#line 259 "parser.y"
                                            { Print("- R: singleExpression '^' singleExpression -> singleExpression"); }
#line 2981 "parser.tab.cpp"
    break;

  case 116: /* singleExpression: singleExpression '&' singleExpression  */
#line 260 "parser.y"
                                            { Print("- R: singleExpression '&' singleExpression -> singleExpression"); }
#line 2987 "parser.tab.cpp"
    break;

  case 117: /* singleExpression: singleExpression OPERATOR_SHIFT_LEFT singleExpression  */
#line 261 "parser.y"
                                                            { Print("- R: singleExpression OPERATOR_SHIFT_LEFT singleExpression -> singleExpression"); }
#line 2993 "parser.tab.cpp"
    break;

  case 118: /* singleExpression: singleExpression OPERATOR_SHIFT_RIGHT singleExpression  */
#line 262 "parser.y"
                                                             { Print("- R: singleExpression OPERATOR_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 2999 "parser.tab.cpp"
    break;

  case 119: /* singleExpression: singleExpression OPERATOR_UNSIGNED_SHIFT_RIGHT singleExpression  */
#line 263 "parser.y"
                                                                      { Print("- R: singleExpression OPERATOR_UNSIGNED_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3005 "parser.tab.cpp"
    break;

  case 120: /* singleExpression: singleExpression OPERATOR_NULLISH_COALESCING singleExpression  */
#line 264 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_NULLISH_COALESCING singleExpression -> singleExpression"); }
#line 3011 "parser.tab.cpp"
    break;

  case 121: /* singleExpression: singleExpression INSTANCEOF singleExpression  */
#line 266 "parser.y"
                                                   { Print("- R: singleExpression INSTANCEOF singleExpression -> singleExpression"); }
#line 3017 "parser.tab.cpp"
    break;

  case 122: /* singleExpression: singleExpression IN singleExpression  */
#line 267 "parser.y"
                                           { Print("- R: singleExpression IN singleExpression -> singleExpression"); }
#line 3023 "parser.tab.cpp"
    break;

  case 123: /* singleExpression: singleExpression TEMPLATE_LITERAL  */
#line 269 "parser.y"
                                        { Print("- R: singleExpression TEMPLATE_LITERAL -> singleExpression"); }
#line 3029 "parser.tab.cpp"
    break;

  case 124: /* singleExpression: singleExpression '?' singleExpression ':' singleExpression  */
#line 270 "parser.y"
                                                                 { Print("- R: singleExpression '?' singleExpression ':' singleExpression -> singleExpression"); }
#line 3035 "parser.tab.cpp"
    break;

  case 125: /* singleExpression: '(' expressionList ')'  */
#line 272 "parser.y"
                             { Print("- R: '(' expressionList ')' -> singleExpression"); }
#line 3041 "parser.tab.cpp"
    break;

  case 126: /* singleExpression: singleExpression arguments  */
#line 274 "parser.y"
                                 { Print("- R: singleExpression arguments -> singleExpression"); }
#line 3047 "parser.tab.cpp"
    break;

  case 127: /* singleExpression: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression  */
#line 276 "parser.y"
                                                                   { Print("- R: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression -> singleExpression"); }
#line 3053 "parser.tab.cpp"
    break;

  case 128: /* singleExpression: singleExpression '.' identifier  */
#line 277 "parser.y"
                                      { Print("- R: singleExpression '.' identifier -> singleExpression"); }
#line 3059 "parser.tab.cpp"
    break;

  case 129: /* singleExpression: arrayLiteral  */
#line 279 "parser.y"
                   { Print("- R: arrayLiteral -> singleExpression"); }
#line 3065 "parser.tab.cpp"
    break;

  case 130: /* singleExpression: singleExpression '[' expressionList ']'  */
#line 280 "parser.y"
                                              { Print("- R: singleExpression '[' singleExpression ']' -> singleExpression"); }
#line 3071 "parser.tab.cpp"
    break;

  case 131: /* singleExpression: singleExpression ENDL_BRACKET_OPEN expressionList ']'  */
#line 281 "parser.y"
                                                            { Print("- R: singleExpression ENDL_BRACKET_OPEN singleExpression ']' -> singleExpression"); }
#line 3077 "parser.tab.cpp"
    break;

  case 132: /* singleExpression: NEW singleExpression  */
#line 283 "parser.y"
                           { Print("- R: NEW singleExpression -> singleExpression"); }
#line 3083 "parser.tab.cpp"
    break;

  case 133: /* arguments: '(' ')'  */
#line 287 "parser.y"
              { Print("- R: '(' ')' -> arguments"); }
#line 3089 "parser.tab.cpp"
    break;

  case 134: /* arguments: '(' argumentList ')'  */
#line 288 "parser.y"
                           { Print("- R: '(' argumentList ')' -> arguments"); }
#line 3095 "parser.tab.cpp"
    break;

  case 135: /* arguments: '(' argumentList ',' ')'  */
#line 289 "parser.y"
                               { Print("- R: '(' argumentList ',' ') -> arguments"); }
#line 3101 "parser.tab.cpp"
    break;

  case 136: /* argumentList: argument  */
#line 293 "parser.y"
               { Print("- R: argument -> argumentList"); }
#line 3107 "parser.tab.cpp"
    break;

  case 137: /* argumentList: argumentList ',' arguments  */
#line 294 "parser.y"
                                 { Print("- R: argumentList ',' arguments -> argumentList"); }
#line 3113 "parser.tab.cpp"
    break;

  case 138: /* argument: singleExpression  */
#line 298 "parser.y"
                       { Print("- R: singleExpression -> argument"); }
#line 3119 "parser.tab.cpp"
    break;

  case 139: /* argument: ELLIPSIS singleExpression  */
#line 299 "parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> argument"); }
#line 3125 "parser.tab.cpp"
    break;

  case 140: /* varStatement: varModifier varDeclarationList  */
#line 305 "parser.y"
                                     { Print("- R: varModifier varDeclarationList -> varStatement"); }
#line 3131 "parser.tab.cpp"
    break;

  case 141: /* varDeclarationList: varDeclaration  */
#line 309 "parser.y"
                     { Print("- R: varDeclaration -> argument"); }
#line 3137 "parser.tab.cpp"
    break;

  case 142: /* varDeclarationList: varDeclarationList ',' varDeclaration  */
#line 310 "parser.y"
                                            { Print("- R: varDeclarationList ',' varDeclaration -> varDeclarationList"); }
#line 3143 "parser.tab.cpp"
    break;

  case 143: /* varDeclaration: identifier  */
#line 314 "parser.y"
                 { Print("- R: identifier -> varDeclaration"); }
#line 3149 "parser.tab.cpp"
    break;

  case 144: /* varDeclaration: identifier typeAnnotation  */
#line 315 "parser.y"
                                { Print("- R: identifier typeAnnotation -> varDeclaration"); }
#line 3155 "parser.tab.cpp"
    break;

  case 145: /* varDeclaration: identifier '=' singleExpression  */
#line 316 "parser.y"
                                      { Print("- R: identifier '=' singleExpression -> varDeclaration"); }
#line 3161 "parser.tab.cpp"
    break;

  case 146: /* varDeclaration: identifier typeAnnotation '=' singleExpression  */
#line 317 "parser.y"
                                                     { Print("- R: identifier typeAnnotation '=' singleExpression -> varDeclaration"); }
#line 3167 "parser.tab.cpp"
    break;

  case 147: /* varModifier: VAR  */
#line 321 "parser.y"
          { Print("- R: VAR -> varModifier"); }
#line 3173 "parser.tab.cpp"
    break;

  case 148: /* varModifier: LET  */
#line 322 "parser.y"
          { Print("- R: LET -> varModifier"); }
#line 3179 "parser.tab.cpp"
    break;

  case 149: /* varModifier: CONST  */
#line 323 "parser.y"
            { Print("- R: CONST -> varModifier"); }
#line 3185 "parser.tab.cpp"
    break;

  case 150: /* ifStatement: IF '(' expressionList ')' statementListItem  */
#line 329 "parser.y"
                                                                     { Print("- R:  IF '(' expressionList ')' statementListItem -> ifStatement"); }
#line 3191 "parser.tab.cpp"
    break;

  case 151: /* ifStatement: IF '(' expressionList ')' statementListItem ELSE statementListItem  */
#line 330 "parser.y"
                                                                         { Print("- R: IF '(' expressionList ')' statementListItem ELSE statementListItem -> ifStatement"); }
#line 3197 "parser.tab.cpp"
    break;

  case 152: /* $@4: %empty  */
#line 334 "parser.y"
         { isInIterationBody = 1; }
#line 3203 "parser.tab.cpp"
    break;

  case 153: /* $@5: %empty  */
#line 334 "parser.y"
                                                                                   { doWhileASI(); }
#line 3209 "parser.tab.cpp"
    break;

  case 154: /* iterationStatement: DO $@4 statementListItem WHILE '(' expressionList ')' $@5 statementSep  */
#line 334 "parser.y"
                                                                                                                                            { isInIterationBody = 0; Print("- R: DO statementListItem WHILE '(' expressionList ')' statementSep -> iterationStatement"); }
#line 3215 "parser.tab.cpp"
    break;

  case 155: /* $@6: %empty  */
#line 335 "parser.y"
                                   { isInIterationBody = 1; }
#line 3221 "parser.tab.cpp"
    break;

  case 156: /* iterationStatement: WHILE '(' expressionList ')' $@6 statementListItem  */
#line 335 "parser.y"
                                                                                                                                            { isInIterationBody = 0; Print("- R: WHILE '(' expressionList ')' statementListItem -> iterationStatement"); }
#line 3227 "parser.tab.cpp"
    break;

  case 157: /* $@7: %empty  */
#line 336 "parser.y"
                                                                                { isInIterationBody = 1; }
#line 3233 "parser.tab.cpp"
    break;

  case 158: /* iterationStatement: FOR '(' expressionListOpt ';' expressionListOpt ';' expressionListOpt ')' $@7 statementListItem  */
#line 336 "parser.y"
                                                                                                                                            { isInIterationBody = 0; Print("- R: FOR '(' expressionListOpt ';' expressionListOpt ';' expressionListOpt ')' statementListItem -> iterationStatement"); }
#line 3239 "parser.tab.cpp"
    break;

  case 159: /* $@8: %empty  */
#line 337 "parser.y"
                                                                                             { isInIterationBody = 1; }
#line 3245 "parser.tab.cpp"
    break;

  case 160: /* iterationStatement: FOR '(' varModifier varDeclarationList ';' expressionListOpt ';' expressionListOpt ')' $@8 statementListItem  */
#line 337 "parser.y"
                                                                                                                                            { isInIterationBody = 0; Print("- R: FOR '(' varModifier varDeclarationList ';' expressionListOpt ';' expressionListOpt ')' statementListItem -> iterationStatement"); }
#line 3251 "parser.tab.cpp"
    break;

  case 161: /* $@9: %empty  */
#line 338 "parser.y"
                                                       { isInIterationBody = 1; }
#line 3257 "parser.tab.cpp"
    break;

  case 162: /* iterationStatement: FOR '(' singleExpression IN singleExpression ')' $@9 statementListItem  */
#line 338 "parser.y"
                                                                                                                                            { isInIterationBody = 0; Print("- R: FOR '(' singleExpression IN singleExpression ')' statementListItem -> iterationStatement"); }
#line 3263 "parser.tab.cpp"
    break;

  case 163: /* $@10: %empty  */
#line 339 "parser.y"
                                                               { isInIterationBody = 1; }
#line 3269 "parser.tab.cpp"
    break;

  case 164: /* iterationStatement: FOR '(' varModifier varDeclaration IN expressionList ')' $@10 statementListItem  */
#line 339 "parser.y"
                                                                                                                                            { isInIterationBody = 0; Print("- R: FOR '(' varModifier varDeclaration IN expressionList ')' statementListItem -> iterationStatement"); }
#line 3275 "parser.tab.cpp"
    break;

  case 165: /* continueStatement: CONTINUE  */
#line 343 "parser.y"
               { Print("- R: CONTINUE -> returnStatement"); }
#line 3281 "parser.tab.cpp"
    break;

  case 166: /* continueStatement: CONTINUE identifier  */
#line 344 "parser.y"
                          { Print("- R: CONTINUE identifier -> returnStatement"); }
#line 3287 "parser.tab.cpp"
    break;

  case 167: /* breakStatement: BREAK  */
#line 348 "parser.y"
             { Print("- R: BREAK -> returnStatement"); }
#line 3293 "parser.tab.cpp"
    break;

  case 168: /* breakStatement: BREAK identifier  */
#line 349 "parser.y"
                       { Print("- R: BREAK identifier -> returnStatement"); }
#line 3299 "parser.tab.cpp"
    break;

  case 169: /* returnStatement: RETURN  */
#line 353 "parser.y"
             { Print("- R: RETURN -> returnStatement"); }
#line 3305 "parser.tab.cpp"
    break;

  case 170: /* returnStatement: RETURN singleExpression  */
#line 354 "parser.y"
                              { Print("- R: RETURN singleExpression -> returnStatement"); }
#line 3311 "parser.tab.cpp"
    break;

  case 171: /* labelledStatement: identifier ':' statementListItem  */
#line 358 "parser.y"
                                       { Print("- R: identifier ':' statementListItem -> labelledStatement"); }
#line 3317 "parser.tab.cpp"
    break;

  case 172: /* blockStatement: '{' '}'  */
#line 362 "parser.y"
              { Print("- R: '{' '}' -> blockStatement"); }
#line 3323 "parser.tab.cpp"
    break;

  case 173: /* blockStatement: '{' statementList '}'  */
#line 363 "parser.y"
                            { Print("- R: '{' statementList '}' -> blockStatement"); }
#line 3329 "parser.tab.cpp"
    break;

  case 174: /* switchStatement: SWITCH '(' expressionList ')' '{' '}'  */
#line 367 "parser.y"
                                            { Print("- R: SWITCH '(' expressionList ')' '{' '}' -> switchStatement"); }
#line 3335 "parser.tab.cpp"
    break;

  case 175: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList '}'  */
#line 368 "parser.y"
                                                           { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList '}' -> switchStatement"); }
#line 3341 "parser.tab.cpp"
    break;

  case 176: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause '}'  */
#line 369 "parser.y"
                                                                         { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause '}' -> switchStatement"); }
#line 3347 "parser.tab.cpp"
    break;

  case 177: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause caseClauseList '}'  */
#line 370 "parser.y"
                                                                                        { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause caseClauseList '}' -> switchStatement"); }
#line 3353 "parser.tab.cpp"
    break;

  case 178: /* caseClauseList: caseClause  */
#line 374 "parser.y"
                 { Print("- R: caseClause -> caseClauseList"); }
#line 3359 "parser.tab.cpp"
    break;

  case 179: /* caseClauseList: caseClauseList caseClause  */
#line 375 "parser.y"
                                { Print("- R: caseClauseList caseClause -> caseClauseList"); }
#line 3365 "parser.tab.cpp"
    break;

  case 180: /* caseClause: CASE expressionList ':'  */
#line 379 "parser.y"
                              { Print("- R: CASE expressionList ':' -> caseClause"); }
#line 3371 "parser.tab.cpp"
    break;

  case 181: /* caseClause: CASE expressionList ':' statementList  */
#line 380 "parser.y"
                                            { Print("- R: CASE expressionList ':' statementList -> caseClause"); }
#line 3377 "parser.tab.cpp"
    break;

  case 182: /* defaultClause: DEFAULT ':'  */
#line 384 "parser.y"
                  { Print("- R: DEFAULT ':' -> defaultClause"); }
#line 3383 "parser.tab.cpp"
    break;

  case 183: /* defaultClause: DEFAULT ':' statementList  */
#line 385 "parser.y"
                                { Print("- R: DEFAULT ':' statementList -> defaultClause"); }
#line 3389 "parser.tab.cpp"
    break;

  case 184: /* functionDeclaration: FUNCTION identifier callSignature functionBody  */
#line 391 "parser.y"
                                                     { Print("- R: FUNCTION ID callSignature functionBody -> functionDeclaration"); }
#line 3395 "parser.tab.cpp"
    break;

  case 185: /* functionBody: '{' '}'  */
#line 395 "parser.y"
              { Print("- R: '{' '}' -> functionBody"); }
#line 3401 "parser.tab.cpp"
    break;

  case 186: /* $@11: %empty  */
#line 396 "parser.y"
          { isInFunctionBody = 1; }
#line 3407 "parser.tab.cpp"
    break;

  case 187: /* functionBody: '{' $@11 statementList '}'  */
#line 396 "parser.y"
                                                      { isInFunctionBody = 0; Print("- R: '{' statementList '}' -> functionBody"); }
#line 3413 "parser.tab.cpp"
    break;

  case 188: /* callSignature: '(' ')'  */
#line 400 "parser.y"
              { Print("- R: '(' ')' -> callSignature"); }
#line 3419 "parser.tab.cpp"
    break;

  case 189: /* callSignature: '(' ')' typeAnnotation  */
#line 401 "parser.y"
                             { Print("- R: '(' ')' typeAnnotation -> callSignature"); }
#line 3425 "parser.tab.cpp"
    break;

  case 190: /* callSignature: '(' restParameter ')'  */
#line 402 "parser.y"
                            { Print("- R: '(' restParameter ')' -> callSignature"); }
#line 3431 "parser.tab.cpp"
    break;

  case 191: /* callSignature: '(' restParameter ')' typeAnnotation  */
#line 403 "parser.y"
                                           { Print("- R: '(' restParameter ')' typeAnnotation -> callSignature"); }
#line 3437 "parser.tab.cpp"
    break;

  case 192: /* callSignature: '(' parameterList ')'  */
#line 404 "parser.y"
                            { Print("- R: '(' parameterList ')' -> callSignature"); }
#line 3443 "parser.tab.cpp"
    break;

  case 193: /* callSignature: '(' parameterList ')' typeAnnotation  */
#line 405 "parser.y"
                                           { Print("- R: '(' parameterList ')' typeAnnotation -> callSignature"); }
#line 3449 "parser.tab.cpp"
    break;

  case 194: /* callSignature: '(' parameterList ',' restParameter ')'  */
#line 406 "parser.y"
                                              { Print("- R: '(' parameterList ',' restParameter ')' -> callSignature"); }
#line 3455 "parser.tab.cpp"
    break;

  case 195: /* callSignature: '(' parameterList ',' restParameter ')' typeAnnotation  */
#line 407 "parser.y"
                                                             { Print("- R: '(' parameterList ',' restParameter ')' typeAnnotation -> callSignature"); }
#line 3461 "parser.tab.cpp"
    break;

  case 196: /* callSignature: '(' parameterList ',' ')'  */
#line 408 "parser.y"
                                { Print("- R: '(' parameterList ',' ')' -> callSignature"); }
#line 3467 "parser.tab.cpp"
    break;

  case 197: /* callSignature: '(' parameterList ',' ')' typeAnnotation  */
#line 409 "parser.y"
                                               { Print("- R: '(' parameterList ',' ')' typeAnnotation -> callSignature"); }
#line 3473 "parser.tab.cpp"
    break;

  case 198: /* parameterList: parameter  */
#line 413 "parser.y"
                { Print("- R: parameter -> parameterList"); }
#line 3479 "parser.tab.cpp"
    break;

  case 199: /* parameterList: parameterList ',' parameter  */
#line 414 "parser.y"
                                  { Print("- R: parameterList ',' parameter -> parameterList"); }
#line 3485 "parser.tab.cpp"
    break;

  case 200: /* parameter: requiredParameter  */
#line 418 "parser.y"
                        { Print("- R: requiredParameter -> parameter"); }
#line 3491 "parser.tab.cpp"
    break;

  case 201: /* parameter: optionalParameter  */
#line 419 "parser.y"
                        { Print("- R: optionalParameter -> parameter"); }
#line 3497 "parser.tab.cpp"
    break;

  case 202: /* requiredParameter: identifier  */
#line 423 "parser.y"
                 { Print("- R: ID -> requiredParameter"); }
#line 3503 "parser.tab.cpp"
    break;

  case 203: /* requiredParameter: identifier typeAnnotation  */
#line 424 "parser.y"
                                { Print("- R: ID typeAnnotation -> requiredParameter"); }
#line 3509 "parser.tab.cpp"
    break;

  case 204: /* optionalParameter: identifier '?'  */
#line 428 "parser.y"
                     { Print("- R: ID '?' -> optionalParameter"); }
#line 3515 "parser.tab.cpp"
    break;

  case 205: /* optionalParameter: identifier '?' typeAnnotation  */
#line 429 "parser.y"
                                    { Print("- R: ID '?' typeAnnotation -> optionalParameter"); }
#line 3521 "parser.tab.cpp"
    break;

  case 206: /* optionalParameter: identifier initializer  */
#line 430 "parser.y"
                             { Print("- R: ID initializer -> optionalParameter"); }
#line 3527 "parser.tab.cpp"
    break;

  case 207: /* optionalParameter: identifier typeAnnotation initializer  */
#line 431 "parser.y"
                                            { Print("- R: ID typeAnnotation initializer -> optionalParameter"); }
#line 3533 "parser.tab.cpp"
    break;

  case 208: /* restParameter: ELLIPSIS singleExpression  */
#line 435 "parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> restParameter"); }
#line 3539 "parser.tab.cpp"
    break;

  case 209: /* restParameter: ELLIPSIS singleExpression typeAnnotation  */
#line 436 "parser.y"
                                               { Print("- R: ELLIPSIS singleExpression typeAnnotation -> restParameter"); }
#line 3545 "parser.tab.cpp"
    break;

  case 210: /* classDeclaration: CLASS identifier classTail  */
#line 442 "parser.y"
                                 { Print("- R: CLASS identifier classTail -> classDeclaration"); }
#line 3551 "parser.tab.cpp"
    break;

  case 211: /* classDeclaration: CLASS identifier classHeritage classTail  */
#line 443 "parser.y"
                                               { Print("- R: CLASS identifier classHeritage classTail -> classDeclaration"); }
#line 3557 "parser.tab.cpp"
    break;

  case 212: /* classHeritage: EXTENDS identifier  */
#line 447 "parser.y"
                         { Print("- R: EXTENDS identifier -> classHeritage"); }
#line 3563 "parser.tab.cpp"
    break;

  case 213: /* classTail: '{' '}'  */
#line 451 "parser.y"
              { Print("- R: '{' '}' -> classTail"); }
#line 3569 "parser.tab.cpp"
    break;

  case 214: /* classTail: '{' classElementList '}'  */
#line 452 "parser.y"
                               { Print("- R: '{' classElementList '}' -> classTail"); }
#line 3575 "parser.tab.cpp"
    break;

  case 215: /* classElementList: classElement  */
#line 456 "parser.y"
                   { Print("- R: classElement -> classElementList"); }
#line 3581 "parser.tab.cpp"
    break;

  case 216: /* classElementList: classElementList classElement  */
#line 457 "parser.y"
                                    { Print("- R: classElementList classElement -> classElementList"); }
#line 3587 "parser.tab.cpp"
    break;

  case 217: /* classElement: CONSTRUCTOR callSignature functionBody  */
#line 461 "parser.y"
                                             { Print("- R: CONSTRUCTOR callSignature functionBody -> classElement"); }
#line 3593 "parser.tab.cpp"
    break;

  case 218: /* classElement: propertyName ';'  */
#line 464 "parser.y"
                       { Print("- R: propertyName ';' -> classElement"); }
#line 3599 "parser.tab.cpp"
    break;

  case 219: /* classElement: propertyName typeAnnotation ';'  */
#line 465 "parser.y"
                                      { Print("- R: propertyName typeAnnotation ';' -> classElement"); }
#line 3605 "parser.tab.cpp"
    break;

  case 220: /* classElement: propertyName initializer ';'  */
#line 466 "parser.y"
                                   { Print("- R: propertyName initializer ';' -> classElement"); }
#line 3611 "parser.tab.cpp"
    break;

  case 221: /* classElement: propertyName typeAnnotation initializer ';'  */
#line 467 "parser.y"
                                                  { Print("- R: propertyName typeAnnotation initializer ';' -> classElement"); }
#line 3617 "parser.tab.cpp"
    break;

  case 222: /* classElement: propertyName callSignature functionBody  */
#line 470 "parser.y"
                                              { Print("- R: propertyName callSignature functionBody -> classElement"); }
#line 3623 "parser.tab.cpp"
    break;

  case 223: /* classElement: GET propertyName '(' ')' functionBody  */
#line 473 "parser.y"
                                            { Print("- R: GET propertyName '(' ')' functionBody -> classElement"); }
#line 3629 "parser.tab.cpp"
    break;

  case 224: /* classElement: GET propertyName '(' ')' typeAnnotation functionBody  */
#line 474 "parser.y"
                                                           { Print("- R: GET propertyName '(' ')' typeAnnotation functionBody -> classElement"); }
#line 3635 "parser.tab.cpp"
    break;

  case 225: /* classElement: SET propertyName callSignature functionBody  */
#line 475 "parser.y"
                                                  { Print("- R: SET propertyName callSignature functionBody -> classElement"); }
#line 3641 "parser.tab.cpp"
    break;

  case 226: /* propertyName: identifier  */
#line 479 "parser.y"
                 { Print("- R: identifier -> propertyName"); }
#line 3647 "parser.tab.cpp"
    break;

  case 227: /* propertyName: STRING_LIT  */
#line 480 "parser.y"
                 { Print("- R: STRING_LIT -> propertyName"); }
#line 3653 "parser.tab.cpp"
    break;

  case 228: /* propertyName: INT_LIT  */
#line 481 "parser.y"
              { Print("- R: INT_LIT -> propertyName"); }
#line 3659 "parser.tab.cpp"
    break;

  case 229: /* propertyName: FLOAT_LIT  */
#line 482 "parser.y"
                { Print("- R: FLOAT_LIT -> propertyName"); }
#line 3665 "parser.tab.cpp"
    break;

  case 230: /* propertyName: '[' singleExpression ']'  */
#line 483 "parser.y"
                               { Print("- R: '[' singleExpression ']' -> propertyName"); }
#line 3671 "parser.tab.cpp"
    break;

  case 231: /* propertyName: ENDL_BRACKET_OPEN singleExpression ']'  */
#line 484 "parser.y"
                                             { Print("- R: ENDL_BRACKET_OPEN singleExpression ']' -> propertyName"); }
#line 3677 "parser.tab.cpp"
    break;

  case 232: /* identifier: ID  */
#line 488 "parser.y"
         { Print("- R: ID -> identifier"); }
#line 3683 "parser.tab.cpp"
    break;

  case 233: /* identifier: ASYNC  */
#line 489 "parser.y"
            { Print("- R: ASYNC -> identifier"); }
#line 3689 "parser.tab.cpp"
    break;

  case 234: /* identifier: AS  */
#line 490 "parser.y"
         { Print("- R: AS -> identifier"); }
#line 3695 "parser.tab.cpp"
    break;

  case 235: /* identifier: FROM  */
#line 491 "parser.y"
           { Print("- R: FROM -> identifier"); }
#line 3701 "parser.tab.cpp"
    break;

  case 236: /* identifier: YIELD  */
#line 492 "parser.y"
            { Print("- R: YIELD -> identifier"); }
#line 3707 "parser.tab.cpp"
    break;

  case 237: /* identifier: ANY  */
#line 493 "parser.y"
          { Print("- R: ANY -> identifier"); }
#line 3713 "parser.tab.cpp"
    break;

  case 238: /* identifier: NUMBER  */
#line 494 "parser.y"
             { Print("- R: NUMBER -> identifier"); }
#line 3719 "parser.tab.cpp"
    break;

  case 239: /* identifier: BOOLEAN  */
#line 495 "parser.y"
              { Print("- R: BOOLEAN -> identifier"); }
#line 3725 "parser.tab.cpp"
    break;

  case 240: /* identifier: STRING  */
#line 496 "parser.y"
             { Print("- R: STRING -> identifier"); }
#line 3731 "parser.tab.cpp"
    break;

  case 241: /* identifier: UNIQUE  */
#line 497 "parser.y"
             { Print("- R: UNIQUE -> identifier"); }
#line 3737 "parser.tab.cpp"
    break;

  case 242: /* identifier: SYMBOL  */
#line 498 "parser.y"
             { Print("- R: SYMBOL -> identifier"); }
#line 3743 "parser.tab.cpp"
    break;

  case 243: /* identifier: NEVER  */
#line 499 "parser.y"
            { Print("- R: NEVER -> identifier"); }
#line 3749 "parser.tab.cpp"
    break;

  case 244: /* identifier: UNDEFINED  */
#line 500 "parser.y"
                { Print("- R: UNDEFINED -> identifier"); }
#line 3755 "parser.tab.cpp"
    break;

  case 245: /* identifier: OBJECT  */
#line 501 "parser.y"
             { Print("- R: OBJECT -> identifier"); }
#line 3761 "parser.tab.cpp"
    break;

  case 246: /* identifier: KEYOF  */
#line 502 "parser.y"
            { Print("- R: KEYOF -> identifier"); }
#line 3767 "parser.tab.cpp"
    break;

  case 247: /* identifier: NAMESPACE  */
#line 503 "parser.y"
                { Print("- R: NAMESPACE -> identifier"); }
#line 3773 "parser.tab.cpp"
    break;

  case 248: /* identifier: ABSTRACT  */
#line 504 "parser.y"
               { Print("- R: ABSTRACT -> identifier"); }
#line 3779 "parser.tab.cpp"
    break;

  case 249: /* identifier: REQUIRE  */
#line 505 "parser.y"
              { Print("- R: REQUIRE -> identifier"); }
#line 3785 "parser.tab.cpp"
    break;


#line 3789 "parser.tab.cpp"

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

#line 508 "parser.y"



void yyerror(const char* s) {
    fprintf(stderr, "Line:%d. Text: %s. Error: %s\n", yylloc.first_line, yytext_ptr, s);
    exit(1);
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
