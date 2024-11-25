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


#line 91 "parser.tab.cpp"

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
  YYSYMBOL_statementSep = 127,             /* statementSep  */
  YYSYMBOL_initializer = 128,              /* initializer  */
  YYSYMBOL_type = 129,                     /* type  */
  YYSYMBOL_unionOrIntersectionOrPrimaryType = 130, /* unionOrIntersectionOrPrimaryType  */
  YYSYMBOL_primaryType = 131,              /* primaryType  */
  YYSYMBOL_tupleTypeElements = 132,        /* tupleTypeElements  */
  YYSYMBOL_typeReference = 133,            /* typeReference  */
  YYSYMBOL_predefinedType = 134,           /* predefinedType  */
  YYSYMBOL_typeAnnotation = 135,           /* typeAnnotation  */
  YYSYMBOL_arrayLiteral = 136,             /* arrayLiteral  */
  YYSYMBOL_elementList = 137,              /* elementList  */
  YYSYMBOL_arrayElement = 138,             /* arrayElement  */
  YYSYMBOL_expressionListOpt = 139,        /* expressionListOpt  */
  YYSYMBOL_expressionList = 140,           /* expressionList  */
  YYSYMBOL_singleExpression = 141,         /* singleExpression  */
  YYSYMBOL_arguments = 142,                /* arguments  */
  YYSYMBOL_argumentList = 143,             /* argumentList  */
  YYSYMBOL_argument = 144,                 /* argument  */
  YYSYMBOL_varStatement = 145,             /* varStatement  */
  YYSYMBOL_varDeclarationList = 146,       /* varDeclarationList  */
  YYSYMBOL_varDeclaration = 147,           /* varDeclaration  */
  YYSYMBOL_varModifier = 148,              /* varModifier  */
  YYSYMBOL_ifStatement = 149,              /* ifStatement  */
  YYSYMBOL_iterationStatement = 150,       /* iterationStatement  */
  YYSYMBOL_151_1 = 151,                    /* $@1  */
  YYSYMBOL_continueStatement = 152,        /* continueStatement  */
  YYSYMBOL_breakStatement = 153,           /* breakStatement  */
  YYSYMBOL_returnStatement = 154,          /* returnStatement  */
  YYSYMBOL_labelledStatement = 155,        /* labelledStatement  */
  YYSYMBOL_blockStatement = 156,           /* blockStatement  */
  YYSYMBOL_switchStatement = 157,          /* switchStatement  */
  YYSYMBOL_caseClauseList = 158,           /* caseClauseList  */
  YYSYMBOL_caseClause = 159,               /* caseClause  */
  YYSYMBOL_defaultClause = 160,            /* defaultClause  */
  YYSYMBOL_functionDeclaration = 161,      /* functionDeclaration  */
  YYSYMBOL_functionBody = 162,             /* functionBody  */
  YYSYMBOL_callSignature = 163,            /* callSignature  */
  YYSYMBOL_parameterList = 164,            /* parameterList  */
  YYSYMBOL_parameter = 165,                /* parameter  */
  YYSYMBOL_requiredParameter = 166,        /* requiredParameter  */
  YYSYMBOL_optionalParameter = 167,        /* optionalParameter  */
  YYSYMBOL_restParameter = 168,            /* restParameter  */
  YYSYMBOL_classDeclaration = 169,         /* classDeclaration  */
  YYSYMBOL_classHeritage = 170,            /* classHeritage  */
  YYSYMBOL_classTail = 171,                /* classTail  */
  YYSYMBOL_classElementList = 172,         /* classElementList  */
  YYSYMBOL_classElement = 173,             /* classElement  */
  YYSYMBOL_propertyName = 174,             /* propertyName  */
  YYSYMBOL_identifier = 175                /* identifier  */
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
#define YYLAST   2053

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  123
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  237
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  430

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
       0,    82,    82,    86,    87,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   107,   111,
     117,   118,   119,   123,   124,   125,   129,   130,   131,   132,
     133,   134,   138,   139,   143,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   167,   172,   173,   177,   178,   179,
     183,   184,   190,   191,   195,   196,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   260,   261,   263,   264,   266,
     268,   270,   271,   273,   274,   275,   277,   281,   282,   283,
     287,   288,   292,   293,   299,   303,   304,   308,   309,   310,
     311,   315,   316,   317,   323,   324,   328,   328,   329,   330,
     331,   332,   333,   337,   338,   342,   343,   347,   348,   352,
     356,   357,   361,   362,   363,   364,   368,   369,   373,   374,
     378,   379,   385,   389,   390,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   407,   408,   412,   413,   417,
     418,   422,   423,   424,   425,   429,   430,   436,   437,   441,
     445,   446,   450,   451,   455,   458,   459,   460,   461,   464,
     467,   468,   469,   473,   474,   475,   476,   477,   478,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500
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
  "statementListItem", "statementSep", "initializer", "type",
  "unionOrIntersectionOrPrimaryType", "primaryType", "tupleTypeElements",
  "typeReference", "predefinedType", "typeAnnotation", "arrayLiteral",
  "elementList", "arrayElement", "expressionListOpt", "expressionList",
  "singleExpression", "arguments", "argumentList", "argument",
  "varStatement", "varDeclarationList", "varDeclaration", "varModifier",
  "ifStatement", "iterationStatement", "$@1", "continueStatement",
  "breakStatement", "returnStatement", "labelledStatement",
  "blockStatement", "switchStatement", "caseClauseList", "caseClause",
  "defaultClause", "functionDeclaration", "functionBody", "callSignature",
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

#define YYPACT_NINF (-329)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     806,  -329,  -329,  -329,   -86,  2000,  2000,   806,   -74,   -57,
    2000,  2000,   -40,  1180,  -329,  -329,  1180,  -329,  -329,  -329,
    -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,
    -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,
    -329,  -329,  -329,  1180,  1180,  1180,  1180,  1180,  1180,  1180,
    1180,  1083,  1083,  1180,  -329,   564,    81,   806,  -329,  -329,
     -32,  1648,   -37,  2000,  -329,  -329,   -37,   -37,   -37,  -329,
    -329,  -329,  -329,  -329,    24,  1180,   -29,    -6,    78,  1180,
     910,  -329,  -329,  1180,  1648,  -329,    64,    64,    64,    64,
      64,    64,    64,    64,    64,  1180,   -20,  -329,  1648,    -2,
     -21,  -329,   686,  -329,  -329,  1180,  -329,  -329,  -329,  -329,
    -329,  1180,  1180,  1180,  1180,  1180,  1180,  1180,  1180,  1180,
    1180,  1180,  1180,  1180,  1180,  1180,  1180,  1180,  1180,  1180,
    1180,  1180,  1180,  1180,  1180,  1180,  1180,  1180,  1180,  1180,
    1180,  1180,  1180,  1180,  1180,  1180,  1180,  1180,  1180,  1180,
    1180,  1180,  1180,  2000,  1180,  1180,  1180,  1045,  -329,  -329,
      66,  -329,    -8,  -329,  -329,  -329,   806,   -19,   107,     9,
    2000,   161,    18,  -329,    37,   -18,    39,   100,  1712,  2000,
     -14,  1648,  1083,  -329,  -329,  -329,  -329,  1648,  1769,  1769,
    1769,  1769,  1769,  1769,  1769,  1769,  1769,  1769,  1769,  1769,
    1769,  1769,  1769,  1769,  1392,   785,  1313,  1805,  1840,  1874,
    1907,   939,   939,   939,   939,   203,   203,   203,   203,   203,
     203,   146,   146,   146,   239,   239,   176,   176,   176,   176,
    -329,     7,    13,    44,  1180,  -329,  1648,   -13,  -329,  2000,
    1180,  1214,   101,  -329,   806,  1180,    85,   -12,  -329,  -329,
    -329,    46,    96,   806,  -329,  -329,  1337,  1337,   -29,  -329,
    -329,  -329,  1180,  1180,  -329,   944,  -329,   -34,  -329,  -329,
    1180,   806,  1180,  1180,   -30,    72,    48,  -329,  1180,  -329,
    -329,  1648,   -22,  -329,  -329,  1648,   140,  -329,  -329,  -329,
    -329,  -329,  -329,  -329,  -329,  1307,  1307,  1214,  1214,  -329,
      69,    70,  -329,  -329,  1180,   178,  1456,  -329,   428,    85,
      85,  1180,    85,  -329,   124,   806,    84,    89,   -29,    90,
    1520,  1584,  -329,  -329,  -329,    92,    -9,   103,   -11,  -329,
      93,   119,  1180,  1180,     1,   666,  -329,  -329,  -329,    69,
      69,  -329,    14,   109,  1307,  1307,  1274,  1648,   806,  -329,
      85,  -329,   110,  -329,  -329,  1648,  -329,  -329,  -329,   111,
     113,   806,  -329,  -329,  -329,  -329,   120,   806,  -329,  1180,
     806,   122,    -5,  1180,  -329,    -1,  -329,  1214,  -329,  -329,
     158,  -329,  -329,   -49,  -329,  -329,    85,   -28,   806,   129,
    -329,   130,   -37,   112,  -329,  1180,   806,   -15,   179,  -329,
    -329,     2,  -329,  -329,  -329,   806,   134,   139,  -329,  -329,
    -329,   806,   147,  -329,   806,   806,  -329,     4,   145,   806,
    -329,  -329,   806,   806,   806,  -329,  -329,   148,  -329,  -329
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   141,   142,   143,     0,     0,     0,     0,     0,     0,
     153,   155,     0,   157,    58,    57,     0,   224,   220,   221,
     222,   223,   234,   235,   236,   237,   225,   226,   227,   228,
     231,   232,   229,   230,   233,    61,    59,    60,    65,    63,
      64,   219,    62,     0,     0,     0,     0,     0,     0,     0,
       0,    47,    47,     0,     5,     0,     0,     2,     3,   123,
       0,    54,     0,     0,     8,    10,     0,     0,     0,    14,
      15,     9,    16,    17,    56,     0,     0,     0,     0,     0,
      52,   154,   156,     0,   158,    56,   126,    74,    75,    72,
      73,    67,    66,    68,    69,     0,     0,    48,    50,     0,
       0,   160,     0,     1,     4,     0,    18,     6,   117,    70,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   120,     7,
     134,   135,   137,    11,    12,    13,     0,     0,     0,     0,
       0,     0,     0,   197,     0,     0,     0,    53,    54,     0,
       0,    51,    47,    45,    46,   119,   161,    55,    90,    94,
      95,   101,    91,    92,    93,    96,    97,   105,    98,    99,
     100,   102,   103,   104,     0,   114,   106,   107,   108,   109,
     110,    84,    85,    86,    87,    82,    81,    89,    88,   115,
     116,   111,   112,   113,    76,    77,    78,    79,    80,    83,
     122,     0,     0,   121,     0,   127,   132,     0,   130,     0,
       0,     0,   138,   159,     0,     0,   175,     0,   185,   187,
     188,     0,   189,   173,   199,    34,     0,     0,     0,   214,
     215,   216,     0,     0,   200,     0,   202,     0,   213,   198,
       0,     0,    52,     0,     0,   135,     0,    49,     0,   124,
     125,   133,     0,   128,   136,   139,   229,    43,    42,    40,
      36,    37,    35,    38,    39,     0,     0,     0,     0,    44,
      20,    25,    28,    27,     0,   144,   195,   176,     0,   179,
     177,     0,   191,   193,   190,   174,     0,     0,     0,     0,
       0,     0,   201,   203,   205,     0,     0,     0,     0,   148,
       0,   116,    52,     0,     0,   118,   129,   131,    41,    21,
      22,    32,     0,     0,     0,     0,     0,   140,     0,   196,
     183,   186,     0,   180,   178,    19,   192,   194,   172,     0,
       0,   173,   217,   218,   207,   206,     0,   173,   146,    52,
       0,     0,     0,     0,   162,     0,   166,     0,    31,    26,
      23,    24,    29,     0,   145,   184,   181,     0,   173,     0,
     208,     0,     0,     0,   151,    52,     0,     0,     0,   163,
     167,     0,    33,    30,   182,   173,     0,     0,   204,   209,
     147,     0,     0,   152,   168,   170,   164,     0,     0,   173,
     212,   149,     0,   169,   171,   165,   210,     0,   150,   211
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -329,  -329,     3,    10,   -53,  -241,  -273,  -226,   -78,  -329,
      99,  -329,  -230,  -329,   -51,  -329,  -270,   -45,   394,   -10,
    -329,  -329,  -329,    94,  -167,   194,  -329,  -329,  -329,  -329,
    -329,  -329,  -329,  -329,  -329,  -125,  -323,  -329,  -329,  -328,
    -231,  -329,   -26,  -329,  -329,   -24,  -329,  -329,   106,  -329,
      20,  -140,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    56,   315,    58,   107,   313,   299,   300,   301,   342,
     302,   303,   242,    59,    96,    97,   176,    60,    61,   158,
     237,   238,    62,   160,   161,    63,    64,    65,   392,    66,
      67,    68,    69,    70,    71,   375,   376,   401,    72,   316,
     169,   247,   248,   249,   250,   251,    73,   172,   173,   265,
     266,   267,    85
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      74,    99,   330,    57,   170,    76,    77,    74,   100,   159,
      81,    82,   275,   163,   164,   165,   307,    78,   373,   398,
     373,   373,   314,   373,   341,   343,   325,   319,   311,   105,
     167,   239,    75,   389,   175,   177,   327,   326,   180,   391,
     105,   182,   105,   105,    79,   241,   105,   105,   282,   308,
     105,   241,   400,   311,   240,    74,   105,    74,   102,   182,
     407,    80,   371,   162,   414,   346,   403,   104,   105,   339,
     340,   241,   284,   357,   105,   377,   349,   418,    83,   353,
     354,   103,   356,   106,   168,   366,   324,   360,   106,   168,
     332,   427,   174,   405,   400,   183,   157,   336,   185,   393,
     244,   271,    74,   166,   402,   276,   283,   309,   368,   231,
     232,   365,   104,   184,   396,   171,   317,   318,   380,   381,
     385,   399,   279,   374,   416,   412,   425,   239,   280,   378,
     253,   277,   245,    17,    18,    19,    20,    21,    22,   171,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,   344,   230,   345,   270,   404,   406,   311,   272,
      41,   105,   157,   304,   241,   310,    74,   333,   252,   334,
     255,   268,   256,   257,   312,   241,   243,   153,   154,   162,
     155,   156,   157,   338,   346,   348,   311,    17,    18,    19,
      20,    21,    22,   258,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,   358,   359,   259,   260,
     261,   361,   364,   369,    41,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   367,   328,   246,   177,   379,   386,
     387,   411,   153,   154,   388,   155,   156,   157,   370,   162,
     390,   255,   395,   345,    74,   147,   148,   149,   150,   151,
     152,   408,   409,    74,   305,   419,   268,   268,   415,   153,
     154,   420,   155,   156,   157,   268,   422,   426,   383,   254,
     429,    74,   337,   274,   179,   262,   417,   263,   269,     0,
     152,   329,   351,   264,   352,   323,     0,   177,   372,   153,
     154,     0,   155,   156,   157,   255,   255,   255,   255,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   252,     0,
       0,     0,     0,     0,     0,    74,   153,   154,     0,   155,
     156,   157,     0,     0,   177,   104,     0,     0,   397,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   410,
     149,   150,   151,   152,   255,   255,   255,     0,    74,     0,
     177,     0,   153,   154,     0,   155,   156,   157,   384,     0,
       0,    74,     0,     0,     0,     0,     0,    74,     0,     0,
      74,     0,     0,     0,     0,     0,     0,   255,     0,     0,
     394,     0,     0,     0,     0,     0,     0,     0,    74,     0,
       0,     0,     0,     0,     0,     0,    74,     0,     0,     0,
       0,     0,     0,     0,     0,    74,   413,    84,     0,     0,
      86,    74,     0,     0,    74,    74,     0,   423,   424,    74,
       0,   421,    74,    74,    74,     0,     0,     0,     0,     0,
       0,     0,   428,   104,   104,     0,     0,    87,    88,    89,
      90,    91,    92,    93,    94,    98,    98,     0,     0,     0,
       0,     0,     0,   245,    17,    18,    19,    20,    21,    22,
       0,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     0,   178,     0,     0,     0,     0,     0,
       0,    41,     0,     0,     0,     0,     0,     0,     0,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   187,
       0,     0,     0,     0,     0,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   350,     0,     0,
     233,   236,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       4,     0,     5,     6,     0,     0,    98,     7,     8,     9,
      10,    11,    12,     0,     0,    13,    14,    15,    16,     0,
      17,    18,    19,    20,    21,    22,     0,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     0,
       0,    35,    36,    37,    38,    39,    40,    41,     0,    42,
      43,    44,    45,    46,     0,     0,     0,     0,   281,     0,
       0,     0,     0,     0,   285,     0,     0,     0,     0,   306,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   320,   321,     0,     0,
       0,     0,     0,    47,    48,     0,     0,   331,     0,    49,
      50,     0,   335,     0,     0,     0,     0,     0,    51,     0,
      52,     0,    53,     0,    54,    55,   101,     0,     0,     1,
       2,     3,     4,     0,     5,     6,     0,     0,   347,     7,
       8,     9,    10,    11,    12,   355,     0,    13,    14,    15,
      16,     0,    17,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,     0,     0,    35,    36,    37,    38,    39,    40,    41,
       0,    42,    43,    44,    45,    46,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     0,     0,     0,     0,     0,     0,     0,     0,   153,
     154,     0,   155,   156,   157,    47,    48,     0,     0,     0,
       0,    49,    50,     0,     0,     0,     0,     0,     0,     0,
      51,     0,    52,     0,    53,     0,    54,    55,   186,     1,
       2,     3,     4,     0,     5,     6,     0,     0,     0,     7,
       8,     9,    10,    11,    12,     0,     0,    13,    14,    15,
      16,     0,    17,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,     0,     0,    35,    36,    37,    38,    39,    40,    41,
       0,    42,    43,    44,    45,    46,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
       0,     0,     0,     0,     0,     0,     0,     0,   153,   154,
       0,   155,   156,   157,     0,    47,    48,     0,     0,     0,
       0,    49,    50,     1,     2,     3,     0,     0,     0,     0,
      51,     0,    52,     0,    53,     0,    54,    55,     0,     0,
       0,     0,    14,    15,    16,     0,    17,    18,    19,    20,
      21,    22,     0,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,   256,   257,    35,    36,    37,
      38,    39,    40,    41,     0,    42,    43,    44,    45,    46,
      17,    18,    19,    20,    21,    22,   258,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     0,
       0,   259,   260,   261,     0,     0,     0,    41,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
      48,     0,     0,     0,     0,    49,    50,     0,     0,     0,
       0,     0,     0,     0,    51,     0,    52,     0,    53,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,     0,     0,     0,     0,     0,
       0,     0,   153,   154,     0,   155,   156,   157,   262,     0,
     263,     0,     0,     0,     0,     0,   322,    14,    15,    16,
     234,    17,    18,    19,    20,    21,    22,     0,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       0,     0,    35,    36,    37,    38,    39,    40,    41,     0,
      42,    43,    44,    45,    46,    14,    15,    16,    95,    17,
      18,    19,    20,    21,    22,     0,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,     0,     0,
      35,    36,    37,    38,    39,    40,    41,     0,    42,    43,
      44,    45,    46,     0,    47,    48,     0,     0,     0,     0,
      49,    50,     0,     0,     0,     0,     0,     0,     0,    51,
       0,    52,     0,    53,   235,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    47,    48,     0,     0,     0,     0,    49,    50,
       0,     0,     0,     0,     0,     0,     0,    51,     0,    52,
       0,    53,    14,    15,    16,     0,    17,    18,    19,    20,
      21,    22,     0,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,     0,     0,    35,    36,    37,
      38,    39,    40,    41,     0,    42,    43,    44,    45,    46,
      17,    18,    19,    20,    21,    22,     0,    23,    24,    25,
      26,    27,    28,    29,    30,    31,   286,    33,    34,   287,
     288,   289,   290,   291,   292,   293,   294,    41,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
      48,     0,     0,     0,     0,    49,    50,     0,     0,     0,
       0,     0,     0,     0,    51,     0,    52,   295,    53,   296,
      17,    18,    19,    20,    21,    22,     0,    23,    24,    25,
      26,    27,    28,    29,    30,    31,   286,    33,    34,   287,
     288,   289,   290,   291,   292,   293,   294,    41,   297,     0,
       0,     0,   298,    17,    18,    19,    20,    21,    22,     0,
      23,    24,    25,    26,    27,    28,    29,    30,    31,   286,
      33,    34,   287,   288,   289,   290,   291,   292,   293,   294,
      41,     0,     0,    17,    18,    19,    20,    21,    22,     0,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     0,     0,   259,   260,   261,     0,   297,   382,
      41,     0,   298,     0,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,     0,
       0,   297,     0,     0,     0,   298,   153,   154,     0,   155,
     156,   157,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,   109,   110,
       0,   262,     0,   263,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   278,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,     0,     0,     0,
       0,     0,     0,     0,     0,   153,   154,     0,   155,   156,
     157,   108,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   241,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     0,     0,     0,     0,     0,     0,     0,     0,   153,
     154,     0,   155,   156,   157,   108,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,     0,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,     0,     0,     0,     0,     0,
       0,     0,     0,   153,   154,   362,   155,   156,   157,   108,
     109,   110,     0,     0,     0,     0,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,     0,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,     0,
       0,     0,     0,     0,     0,     0,     0,   153,   154,   363,
     155,   156,   157,   108,   109,   110,     0,     0,     0,     0,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,     0,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,     0,     0,     0,     0,     0,     0,     0,
       0,   153,   154,     0,   155,   156,   157,   108,   109,   110,
       0,     0,     0,     0,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,     0,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   273,   144,   145,
     146,   147,   148,   149,   150,   151,   152,     0,     0,     0,
       0,     0,     0,     0,     0,   153,   154,     0,   155,   156,
     157,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,     0,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,     0,     0,     0,     0,     0,
       0,     0,   153,   154,     0,   155,   156,   157,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
       0,     0,     0,     0,     0,     0,     0,     0,   153,   154,
       0,   155,   156,   157,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,     0,     0,     0,     0,     0,
       0,     0,     0,   153,   154,     0,   155,   156,   157,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,     0,
       0,     0,     0,     0,     0,     0,     0,   153,   154,     0,
     155,   156,   157,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,     0,     0,     0,     0,     0,     0,     0,
     153,   154,     0,   155,   156,   157,    17,    18,    19,    20,
      21,    22,     0,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,     0,     0,     0,     0,     0,
       0,     0,     0,    41
};

static const yytype_int16 yycheck[] =
{
       0,    52,   272,     0,    10,     5,     6,     7,    53,    62,
      10,    11,   179,    66,    67,    68,   246,     7,    19,    20,
      19,    19,   252,    19,   297,   298,   267,   258,    62,    61,
      75,    61,   118,   361,    79,    80,   267,   267,    83,   367,
      61,    61,    61,    61,   118,    79,    61,    61,    61,    61,
      61,    79,   375,    62,    62,    55,    61,    57,    55,    61,
     388,   118,   332,    63,    79,   114,   115,    57,    61,   295,
     296,    79,   239,   314,    61,    61,   306,   405,   118,   309,
     310,     0,   312,   120,   118,   326,   120,   318,   120,   118,
     120,   419,    14,   121,   417,   115,   118,   119,   119,   369,
     119,   119,   102,    79,   377,   119,   119,   119,   119,   154,
     155,   120,   102,   115,   119,   121,   256,   257,   344,   345,
     350,   122,   115,   122,   122,   395,   122,    61,   115,   115,
     121,   182,    25,    26,    27,    28,    29,    30,    31,   121,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    83,   153,    85,   118,   386,   387,    62,   120,
      53,    61,   118,    62,    79,   119,   166,    95,   168,   121,
     170,   171,    11,    12,    78,    79,   166,   113,   114,   179,
     116,   117,   118,    43,   114,     7,    62,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,   122,   118,    47,    48,
      49,   121,   120,   120,    53,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   121,   270,   119,   272,   119,   119,
     119,   119,   113,   114,   121,   116,   117,   118,   119,   239,
     120,   241,   120,    85,   244,    99,   100,   101,   102,   103,
     104,   122,   122,   253,   244,   121,   256,   257,    79,   113,
     114,   122,   116,   117,   118,   265,   119,   122,   346,   170,
     122,   271,   282,   179,    80,   114,   401,   116,   172,    -1,
     104,   271,   308,   122,   308,   265,    -1,   332,   333,   113,
     114,    -1,   116,   117,   118,   295,   296,   297,   298,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   308,    -1,
      -1,    -1,    -1,    -1,    -1,   315,   113,   114,    -1,   116,
     117,   118,    -1,    -1,   369,   315,    -1,    -1,   373,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   392,
     101,   102,   103,   104,   344,   345,   346,    -1,   348,    -1,
     395,    -1,   113,   114,    -1,   116,   117,   118,   348,    -1,
      -1,   361,    -1,    -1,    -1,    -1,    -1,   367,    -1,    -1,
     370,    -1,    -1,    -1,    -1,    -1,    -1,   377,    -1,    -1,
     370,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   388,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   396,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   405,   396,    13,    -1,    -1,
      16,   411,    -1,    -1,   414,   415,    -1,   414,   415,   419,
      -1,   411,   422,   423,   424,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   422,   423,   424,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    29,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   119,    -1,    -1,
     156,   157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,   182,    13,    14,    15,
      16,    17,    18,    -1,    -1,    21,    22,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,   234,    -1,
      -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,   245,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   262,   263,    -1,    -1,
      -1,    -1,    -1,    99,   100,    -1,    -1,   273,    -1,   105,
     106,    -1,   278,    -1,    -1,    -1,    -1,    -1,   114,    -1,
     116,    -1,   118,    -1,   120,   121,   122,    -1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,   304,    13,
      14,    15,    16,    17,    18,   311,    -1,    21,    22,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
     114,    -1,   116,   117,   118,    99,   100,    -1,    -1,    -1,
      -1,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,    -1,   116,    -1,   118,    -1,   120,   121,   122,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    13,
      14,    15,    16,    17,    18,    -1,    -1,    21,    22,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
      -1,   116,   117,   118,    -1,    99,   100,    -1,    -1,    -1,
      -1,   105,   106,     3,     4,     5,    -1,    -1,    -1,    -1,
     114,    -1,   116,    -1,   118,    -1,   120,   121,    -1,    -1,
      -1,    -1,    22,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    11,    12,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    47,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,    -1,   116,    -1,   118,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,   114,    -1,   116,   117,   118,   114,    -1,
     116,    -1,    -1,    -1,    -1,    -1,   122,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    -1,    99,   100,    -1,    -1,    -1,    -1,
     105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,   116,    -1,   118,   119,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,   100,    -1,    -1,    -1,    -1,   105,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,   116,
      -1,   118,    22,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      26,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,    -1,   116,    83,   118,    85,
      26,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,   114,    -1,
      -1,    -1,   118,    26,    27,    28,    29,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    26,    27,    28,    29,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    47,    48,    49,    -1,   114,   115,
      53,    -1,   118,    -1,    -1,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
      -1,   114,    -1,    -1,    -1,   118,   113,   114,    -1,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      -1,   114,    -1,   116,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,   117,
     118,    55,    56,    57,    -1,    -1,    -1,    -1,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
     114,    -1,   116,   117,   118,    55,    56,    57,    -1,    -1,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    -1,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,   117,   118,    55,
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
      -1,   113,   114,    -1,   116,   117,   118,    55,    56,    57,
      -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    -1,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,   117,
     118,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    -1,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,   114,    -1,   116,   117,   118,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
      -1,   116,   117,   118,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,    -1,   116,   117,   118,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,
     116,   117,   118,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   114,    -1,   116,   117,   118,    26,    27,    28,    29,
      30,    31,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     8,     9,    13,    14,    15,
      16,    17,    18,    21,    22,    23,    24,    26,    27,    28,
      29,    30,    31,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    47,    48,    49,    50,    51,
      52,    53,    55,    56,    57,    58,    59,    99,   100,   105,
     106,   114,   116,   118,   120,   121,   124,   125,   126,   136,
     140,   141,   145,   148,   149,   150,   152,   153,   154,   155,
     156,   157,   161,   169,   175,   118,   175,   175,   126,   118,
     118,   175,   175,   118,   141,   175,   141,   141,   141,   141,
     141,   141,   141,   141,   141,    25,   137,   138,   141,   137,
     140,   122,   125,     0,   126,    61,   120,   127,    55,    56,
      57,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   113,   114,   116,   117,   118,   142,   127,
     146,   147,   175,   127,   127,   127,    79,   140,   118,   163,
      10,   121,   170,   171,    14,   140,   139,   140,   141,   148,
     140,   141,    61,   115,   115,   119,   122,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     175,   140,   140,   141,    25,   119,   141,   143,   144,    61,
      62,    79,   135,   126,   119,    25,   119,   164,   165,   166,
     167,   168,   175,   121,   133,   175,    11,    12,    32,    47,
      48,    49,   114,   116,   122,   172,   173,   174,   175,   171,
     118,   119,   120,    95,   146,   147,   119,   137,    79,   115,
     115,   141,    61,   119,   147,   141,    42,    45,    46,    47,
      48,    49,    50,    51,    52,    83,    85,   114,   118,   129,
     130,   131,   133,   134,    62,   126,   141,   135,    61,   119,
     119,    62,    78,   128,   135,   125,   162,   174,   174,   163,
     141,   141,   122,   173,   120,   128,   135,   163,   140,   126,
     139,   141,   120,    95,   121,   141,   119,   142,    43,   130,
     130,   129,   132,   129,    83,    85,   114,   141,     7,   135,
     119,   165,   168,   135,   135,   141,   135,   128,   122,   118,
     163,   121,   115,   115,   120,   120,   128,   121,   119,   120,
     119,   139,   140,    19,   122,   158,   159,    61,   115,   119,
     130,   130,   115,   131,   126,   135,   119,   119,   121,   162,
     120,   162,   151,   139,   126,   120,   119,   140,    20,   122,
     159,   160,   129,   115,   135,   121,   135,   162,   122,   122,
     127,   119,   139,   126,    79,    79,   122,   158,   162,   121,
     122,   126,   119,   125,   125,   122,   122,   162,   126,   122
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   123,   124,   125,   125,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   127,   128,
     129,   129,   129,   130,   130,   130,   131,   131,   131,   131,
     131,   131,   132,   132,   133,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   135,   136,   136,   137,   137,   137,
     138,   138,   139,   139,   140,   140,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   142,   142,   142,
     143,   143,   144,   144,   145,   146,   146,   147,   147,   147,
     147,   148,   148,   148,   149,   149,   151,   150,   150,   150,
     150,   150,   150,   152,   152,   153,   153,   154,   154,   155,
     156,   156,   157,   157,   157,   157,   158,   158,   159,   159,
     160,   160,   161,   162,   162,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   164,   164,   165,   165,   166,
     166,   167,   167,   167,   167,   168,   168,   169,   169,   170,
     171,   171,   172,   172,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   174,   174,   174,   174,   174,   174,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     2,     1,     1,
       1,     2,     2,     2,     1,     1,     1,     1,     1,     2,
       1,     2,     2,     3,     3,     1,     3,     1,     1,     3,
       4,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     2,     3,     3,     0,     1,     3,
       1,     2,     0,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     5,     3,
       2,     3,     3,     1,     4,     4,     2,     2,     3,     4,
       1,     3,     1,     2,     2,     1,     3,     1,     2,     3,
       4,     1,     1,     1,     5,     7,     0,     8,     5,     9,
      10,     7,     8,     1,     2,     1,     2,     1,     2,     3,
       2,     3,     6,     7,     8,     9,     1,     2,     3,     4,
       2,     3,     6,     0,     1,     2,     3,     3,     4,     3,
       4,     5,     6,     4,     5,     1,     3,     1,     1,     1,
       2,     2,     3,     2,     3,     2,     3,     3,     4,     2,
       2,     3,     1,     2,     5,     2,     3,     3,     4,     5,
       7,     8,     6,     1,     1,     1,     1,     3,     3,     1,
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
#line 82 "parser.y"
                    { Print("- R: statementList -> script"); }
#line 2291 "parser.tab.cpp"
    break;

  case 3: /* statementList: statementListItem  */
#line 86 "parser.y"
                        { Print("- R: statementListItem -> statementList"); }
#line 2297 "parser.tab.cpp"
    break;

  case 4: /* statementList: statementList statementListItem  */
#line 87 "parser.y"
                                      { Print("- R: statementList statementListItem -> statementList"); }
#line 2303 "parser.tab.cpp"
    break;

  case 5: /* statementListItem: ';'  */
#line 91 "parser.y"
          { Print("- R: ';' -> statementListItem"); }
#line 2309 "parser.tab.cpp"
    break;

  case 6: /* statementListItem: expressionList statementSep  */
#line 92 "parser.y"
                                  { Print("- R: expressionList statementSep -> statementListItem"); }
#line 2315 "parser.tab.cpp"
    break;

  case 11: /* statementListItem: continueStatement statementSep  */
#line 97 "parser.y"
                                     { Print("- R: continueStatement statementSep -> statementListItem");  }
#line 2321 "parser.tab.cpp"
    break;

  case 12: /* statementListItem: breakStatement statementSep  */
#line 98 "parser.y"
                                  { Print("- R: breakStatement statementSep -> statementListItem"); }
#line 2327 "parser.tab.cpp"
    break;

  case 13: /* statementListItem: returnStatement statementSep  */
#line 99 "parser.y"
                                   { Print("- R: returnStatement statementSep -> statementListItem"); }
#line 2333 "parser.tab.cpp"
    break;

  case 18: /* statementSep: ';'  */
#line 107 "parser.y"
          { Print("- R: ';' -> statementSep"); }
#line 2339 "parser.tab.cpp"
    break;

  case 19: /* initializer: '=' singleExpression  */
#line 111 "parser.y"
                           { Print("- R: '=' singleExpression -> initializer"); }
#line 2345 "parser.tab.cpp"
    break;

  case 20: /* type: unionOrIntersectionOrPrimaryType  */
#line 117 "parser.y"
                                       { Print("- R: unionOrIntersectionOrPrimaryType -> type"); }
#line 2351 "parser.tab.cpp"
    break;

  case 21: /* type: '|' unionOrIntersectionOrPrimaryType  */
#line 118 "parser.y"
                                           { Print("- R: '|' unionOrIntersectionOrPrimaryType -> type"); }
#line 2357 "parser.tab.cpp"
    break;

  case 22: /* type: '&' unionOrIntersectionOrPrimaryType  */
#line 119 "parser.y"
                                           { Print("- R: '&' unionOrIntersectionOrPrimaryType -> type"); }
#line 2363 "parser.tab.cpp"
    break;

  case 23: /* unionOrIntersectionOrPrimaryType: unionOrIntersectionOrPrimaryType '|' unionOrIntersectionOrPrimaryType  */
#line 123 "parser.y"
                                                                            { Print("- R: unionOrIntersectionOrPrimaryType '|' unionOrIntersectionOrPrimaryType -> unionOrIntersectionOrPrimaryType"); }
#line 2369 "parser.tab.cpp"
    break;

  case 24: /* unionOrIntersectionOrPrimaryType: unionOrIntersectionOrPrimaryType '&' unionOrIntersectionOrPrimaryType  */
#line 124 "parser.y"
                                                                            { Print("- R: unionOrIntersectionOrPrimaryType '&' unionOrIntersectionOrPrimaryType -> unionOrIntersectionOrPrimaryType"); }
#line 2375 "parser.tab.cpp"
    break;

  case 25: /* unionOrIntersectionOrPrimaryType: primaryType  */
#line 125 "parser.y"
                  { Print("- R: primaryType -> argument"); }
#line 2381 "parser.tab.cpp"
    break;

  case 26: /* primaryType: '(' type ')'  */
#line 129 "parser.y"
                   { Print("- R: '(' type ')' -> primaryType"); }
#line 2387 "parser.tab.cpp"
    break;

  case 27: /* primaryType: predefinedType  */
#line 130 "parser.y"
                     { Print("- R: predefinedType -> primaryType"); }
#line 2393 "parser.tab.cpp"
    break;

  case 28: /* primaryType: typeReference  */
#line 131 "parser.y"
                    { Print("- R: typeReference -> primaryType"); }
#line 2399 "parser.tab.cpp"
    break;

  case 29: /* primaryType: primaryType '[' ']'  */
#line 132 "parser.y"
                          { Print("- R: primaryType '[' ']' -> primaryType"); }
#line 2405 "parser.tab.cpp"
    break;

  case 30: /* primaryType: primaryType '[' primaryType ']'  */
#line 133 "parser.y"
                                      { Print("- R: primaryType '[' primaryType ']' -> primaryType"); }
#line 2411 "parser.tab.cpp"
    break;

  case 31: /* primaryType: '[' tupleTypeElements ']'  */
#line 134 "parser.y"
                                { Print("- R: '[' tupleTypeElements ']' -> primaryType"); }
#line 2417 "parser.tab.cpp"
    break;

  case 32: /* tupleTypeElements: type  */
#line 138 "parser.y"
           { Print("- R: type -> tupleTypeElements"); }
#line 2423 "parser.tab.cpp"
    break;

  case 33: /* tupleTypeElements: tupleTypeElements ',' type  */
#line 139 "parser.y"
                                 { Print("- R: tupleTypeElements ',' type -> tupleTypeElements"); }
#line 2429 "parser.tab.cpp"
    break;

  case 34: /* typeReference: identifier  */
#line 143 "parser.y"
                 { Print("- R: identifier -> typeReference"); }
#line 2435 "parser.tab.cpp"
    break;

  case 35: /* predefinedType: NULL_KW  */
#line 147 "parser.y"
              { Print("- R: NULL_LITERAL -> predefinedType"); }
#line 2441 "parser.tab.cpp"
    break;

  case 36: /* predefinedType: INT_LIT  */
#line 148 "parser.y"
              { Print("- R: INT_LIT -> predefinedType"); }
#line 2447 "parser.tab.cpp"
    break;

  case 37: /* predefinedType: FLOAT_LIT  */
#line 149 "parser.y"
                { Print("- R: FLOAT_LIT -> predefinedType"); }
#line 2453 "parser.tab.cpp"
    break;

  case 38: /* predefinedType: TRUE_KW  */
#line 150 "parser.y"
              { Print("- R: TRUE_LITERAL -> predefinedType"); }
#line 2459 "parser.tab.cpp"
    break;

  case 39: /* predefinedType: FALSE_KW  */
#line 151 "parser.y"
               { Print("- R: FALSE_LITERAL -> predefinedType"); }
#line 2465 "parser.tab.cpp"
    break;

  case 40: /* predefinedType: STRING_LIT  */
#line 152 "parser.y"
                 { Print("- R: STRING_LIT -> predefinedType"); }
#line 2471 "parser.tab.cpp"
    break;

  case 41: /* predefinedType: UNIQUE SYMBOL  */
#line 153 "parser.y"
                    { Print("- R: UNIQUE SYMBOL -> predefinedType"); }
#line 2477 "parser.tab.cpp"
    break;

  case 42: /* predefinedType: UNKNOWN  */
#line 154 "parser.y"
              { Print("- R: UNKNOWN -> predefinedType"); }
#line 2483 "parser.tab.cpp"
    break;

  case 43: /* predefinedType: VOID  */
#line 155 "parser.y"
           { Print("- R: VOID -> predefinedType"); }
#line 2489 "parser.tab.cpp"
    break;

  case 44: /* typeAnnotation: ':' type  */
#line 167 "parser.y"
               { Print("- R: ':' type -> typeAnnotation"); }
#line 2495 "parser.tab.cpp"
    break;

  case 45: /* arrayLiteral: '[' elementList ']'  */
#line 172 "parser.y"
                          { Print("- R: [ elementList ']' -> arrayLiteral"); }
#line 2501 "parser.tab.cpp"
    break;

  case 46: /* arrayLiteral: ENDL_BRACKET_OPEN elementList ']'  */
#line 173 "parser.y"
                                        { Print("- R: ENDL_BRACKET_OPEN elementList ']' -> arrayLiteral"); }
#line 2507 "parser.tab.cpp"
    break;

  case 47: /* elementList: %empty  */
#line 177 "parser.y"
                  { Print("- R: #empty# -> elementList"); }
#line 2513 "parser.tab.cpp"
    break;

  case 48: /* elementList: arrayElement  */
#line 178 "parser.y"
                   { Print("- R: arrayElement -> elementList"); }
#line 2519 "parser.tab.cpp"
    break;

  case 49: /* elementList: elementList ',' elementList  */
#line 179 "parser.y"
                                  { Print("- R: elementList ',' elementList -> elementList"); }
#line 2525 "parser.tab.cpp"
    break;

  case 50: /* arrayElement: singleExpression  */
#line 183 "parser.y"
                       { Print("- R: singleExpression -> arrayElement"); }
#line 2531 "parser.tab.cpp"
    break;

  case 51: /* arrayElement: ELLIPSIS singleExpression  */
#line 184 "parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> arrayElement"); }
#line 2537 "parser.tab.cpp"
    break;

  case 52: /* expressionListOpt: %empty  */
#line 190 "parser.y"
                  { Print("- R: #empty# -> expressionListOpt"); }
#line 2543 "parser.tab.cpp"
    break;

  case 53: /* expressionListOpt: expressionList  */
#line 191 "parser.y"
                     { Print("- R: expressionList -> expressionListOpt"); }
#line 2549 "parser.tab.cpp"
    break;

  case 54: /* expressionList: singleExpression  */
#line 195 "parser.y"
                       { Print("- R: singleExpression -> expressionList"); }
#line 2555 "parser.tab.cpp"
    break;

  case 55: /* expressionList: expressionList ',' singleExpression  */
#line 196 "parser.y"
                                          { Print("- R: expressionList ',' singleExpression -> expressionList"); }
#line 2561 "parser.tab.cpp"
    break;

  case 56: /* singleExpression: identifier  */
#line 200 "parser.y"
                 { Print("- R: identifier -> singleExpression"); }
#line 2567 "parser.tab.cpp"
    break;

  case 57: /* singleExpression: THIS  */
#line 201 "parser.y"
           { Print("- R: THIS -> singleExpression"); }
#line 2573 "parser.tab.cpp"
    break;

  case 58: /* singleExpression: SUPER  */
#line 202 "parser.y"
            { Print("- R: SUPER -> singleExpression"); }
#line 2579 "parser.tab.cpp"
    break;

  case 59: /* singleExpression: INT_LIT  */
#line 203 "parser.y"
              { Print("- R: INT_LIT -> singleExpression"); }
#line 2585 "parser.tab.cpp"
    break;

  case 60: /* singleExpression: FLOAT_LIT  */
#line 204 "parser.y"
                { Print("- R: FLOAT_LIT -> singleExpression"); }
#line 2591 "parser.tab.cpp"
    break;

  case 61: /* singleExpression: STRING_LIT  */
#line 205 "parser.y"
                 { Print("- R: STRING_LIT -> singleExpression"); }
#line 2597 "parser.tab.cpp"
    break;

  case 62: /* singleExpression: TEMPLATE_LITERAL  */
#line 206 "parser.y"
                       { Print("- R: TEMPLATE_LITERAL -> singleExpression"); }
#line 2603 "parser.tab.cpp"
    break;

  case 63: /* singleExpression: TRUE_KW  */
#line 207 "parser.y"
              { Print("- R: TRUE_LITERAL -> singleExpression"); }
#line 2609 "parser.tab.cpp"
    break;

  case 64: /* singleExpression: FALSE_KW  */
#line 208 "parser.y"
               { Print("- R: FALSE_LITERAL -> singleExpression"); }
#line 2615 "parser.tab.cpp"
    break;

  case 65: /* singleExpression: NULL_KW  */
#line 209 "parser.y"
              { Print("- R: NULL_LITERAL -> singleExpression"); }
#line 2621 "parser.tab.cpp"
    break;

  case 66: /* singleExpression: '-' singleExpression  */
#line 210 "parser.y"
                                        { Print("- R: '-' singleExpression -> singleExpression"); }
#line 2627 "parser.tab.cpp"
    break;

  case 67: /* singleExpression: '+' singleExpression  */
#line 211 "parser.y"
                                       { Print("- R: '+'s singleExpression -> singleExpression"); }
#line 2633 "parser.tab.cpp"
    break;

  case 68: /* singleExpression: '!' singleExpression  */
#line 212 "parser.y"
                           { Print("- R: '!' singleExpression -> singleExpression"); }
#line 2639 "parser.tab.cpp"
    break;

  case 69: /* singleExpression: '~' singleExpression  */
#line 213 "parser.y"
                           { Print("- R: '~' singleExpression -> singleExpression"); }
#line 2645 "parser.tab.cpp"
    break;

  case 70: /* singleExpression: singleExpression OPERATOR_INCREMENT  */
#line 214 "parser.y"
                                                               { Print("- R: singleExpression OPERATOR_INCREMENT -> singleExpression"); }
#line 2651 "parser.tab.cpp"
    break;

  case 71: /* singleExpression: singleExpression OPERATOR_DECREMENT  */
#line 215 "parser.y"
                                                               { Print("- R: singleExpression OPERATOR_DECREMENT -> singleExpression"); }
#line 2657 "parser.tab.cpp"
    break;

  case 72: /* singleExpression: ENDL_OPERATOR_INCREMENT singleExpression  */
#line 216 "parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 2663 "parser.tab.cpp"
    break;

  case 73: /* singleExpression: ENDL_OPERATOR_DECREMENT singleExpression  */
#line 217 "parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 2669 "parser.tab.cpp"
    break;

  case 74: /* singleExpression: OPERATOR_INCREMENT singleExpression  */
#line 218 "parser.y"
                                                               { Print("- R: OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 2675 "parser.tab.cpp"
    break;

  case 75: /* singleExpression: OPERATOR_DECREMENT singleExpression  */
#line 219 "parser.y"
                                                               { Print("- R: OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 2681 "parser.tab.cpp"
    break;

  case 76: /* singleExpression: singleExpression '+' singleExpression  */
#line 220 "parser.y"
                                            { Print("- R: singleExpression '+' singleExpression -> singleExpression"); }
#line 2687 "parser.tab.cpp"
    break;

  case 77: /* singleExpression: singleExpression '-' singleExpression  */
#line 221 "parser.y"
                                            { Print("- R: singleExpression '-' singleExpression -> singleExpression"); }
#line 2693 "parser.tab.cpp"
    break;

  case 78: /* singleExpression: singleExpression '*' singleExpression  */
#line 222 "parser.y"
                                            { Print("- R: singleExpression '*' singleExpression -> singleExpression"); }
#line 2699 "parser.tab.cpp"
    break;

  case 79: /* singleExpression: singleExpression '/' singleExpression  */
#line 223 "parser.y"
                                            { Print("- R: singleExpression '/' singleExpression -> singleExpression"); }
#line 2705 "parser.tab.cpp"
    break;

  case 80: /* singleExpression: singleExpression '%' singleExpression  */
#line 224 "parser.y"
                                            { Print("- R: singleExpression '%' singleExpression -> singleExpression"); }
#line 2711 "parser.tab.cpp"
    break;

  case 81: /* singleExpression: singleExpression '<' singleExpression  */
#line 225 "parser.y"
                                            { Print("- R: singleExpression '<' singleExpression -> singleExpression"); }
#line 2717 "parser.tab.cpp"
    break;

  case 82: /* singleExpression: singleExpression '>' singleExpression  */
#line 226 "parser.y"
                                            { Print("- R: singleExpression '>' singleExpression -> singleExpression"); }
#line 2723 "parser.tab.cpp"
    break;

  case 83: /* singleExpression: singleExpression OPERATOR_POWER singleExpression  */
#line 227 "parser.y"
                                                       { Print("- R: singleExpression OPERATOR_POWER singleExpression -> singleExpression"); }
#line 2729 "parser.tab.cpp"
    break;

  case 84: /* singleExpression: singleExpression OPERATOR_EQUAL singleExpression  */
#line 228 "parser.y"
                                                       { Print("- R: singleExpression OPERATOR_EQUAL singleExpression -> singleExpression"); }
#line 2735 "parser.tab.cpp"
    break;

  case 85: /* singleExpression: singleExpression OPERATOR_NOT_EQUAL singleExpression  */
#line 229 "parser.y"
                                                           { Print("- R: singleExpression OPERATOR_NOT_EQUAL singleExpression -> singleExpression"); }
#line 2741 "parser.tab.cpp"
    break;

  case 86: /* singleExpression: singleExpression OPERATOR_STRICT_EQUAL singleExpression  */
#line 230 "parser.y"
                                                              { Print("- R: singleExpression OPERATOR_STRICT_EQUAL singleExpression -> singleExpression"); }
#line 2747 "parser.tab.cpp"
    break;

  case 87: /* singleExpression: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression  */
#line 231 "parser.y"
                                                                  { Print("- R: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression -> singleExpression"); }
#line 2753 "parser.tab.cpp"
    break;

  case 88: /* singleExpression: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression  */
#line 232 "parser.y"
                                                                 { Print("- R: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression -> singleExpression"); }
#line 2759 "parser.tab.cpp"
    break;

  case 89: /* singleExpression: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression  */
#line 233 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression -> singleExpression"); }
#line 2765 "parser.tab.cpp"
    break;

  case 90: /* singleExpression: singleExpression '=' singleExpression  */
#line 234 "parser.y"
                                            { Print("- R: singleExpression '=' singleExpression -> singleExpression"); }
#line 2771 "parser.tab.cpp"
    break;

  case 91: /* singleExpression: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression  */
#line 235 "parser.y"
                                                                 { Print("- R: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression -> singleExpression"); }
#line 2777 "parser.tab.cpp"
    break;

  case 92: /* singleExpression: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression  */
#line 236 "parser.y"
                                                               { Print("- R: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression -> singleExpression"); }
#line 2783 "parser.tab.cpp"
    break;

  case 93: /* singleExpression: singleExpression OPERATOR_ASSIGN_MOD singleExpression  */
#line 237 "parser.y"
                                                            { Print("- R: singleExpression OPERATOR_ASSIGN_MOD singleExpression -> singleExpression"); }
#line 2789 "parser.tab.cpp"
    break;

  case 94: /* singleExpression: singleExpression OPERATOR_ASSIGN_PLUS singleExpression  */
#line 238 "parser.y"
                                                             { Print("- R: singleExpression OPERATOR_ASSIGN_PLUS singleExpression -> singleExpression"); }
#line 2795 "parser.tab.cpp"
    break;

  case 95: /* singleExpression: singleExpression OPERATOR_ASSIGN_MINUS singleExpression  */
#line 239 "parser.y"
                                                              { Print("- R: singleExpression OPERATOR_ASSIGN_MINUS singleExpression -> singleExpression"); }
#line 2801 "parser.tab.cpp"
    break;

  case 96: /* singleExpression: singleExpression OPERATOR_ASSIGN_SHIFT_LEFT singleExpression  */
#line 240 "parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_SHIFT_LEFT singleExpression -> singleExpression"); }
#line 2807 "parser.tab.cpp"
    break;

  case 97: /* singleExpression: singleExpression OPERATOR_ASSIGN_SHIFT_RIGHT singleExpression  */
#line 241 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 2813 "parser.tab.cpp"
    break;

  case 98: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_AND singleExpression  */
#line 242 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_AND singleExpression -> singleExpression"); }
#line 2819 "parser.tab.cpp"
    break;

  case 99: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_XOR singleExpression  */
#line 243 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_XOR singleExpression -> singleExpression"); }
#line 2825 "parser.tab.cpp"
    break;

  case 100: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_OR singleExpression  */
#line 244 "parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_OR singleExpression -> singleExpression"); }
#line 2831 "parser.tab.cpp"
    break;

  case 101: /* singleExpression: singleExpression OPERATOR_ASSIGN_POWER singleExpression  */
#line 245 "parser.y"
                                                              { Print("- R: singleExpression OPERATOR_ASSIGN_POWER singleExpression -> singleExpression"); }
#line 2837 "parser.tab.cpp"
    break;

  case 102: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression  */
#line 246 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression -> singleExpression"); }
#line 2843 "parser.tab.cpp"
    break;

  case 103: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression  */
#line 247 "parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression -> singleExpression"); }
#line 2849 "parser.tab.cpp"
    break;

  case 104: /* singleExpression: singleExpression OPERATOR_ASSIGN_NULLISH_COALESCING singleExpression  */
#line 248 "parser.y"
                                                                           { Print("- R: singleExpression OPERATOR_ASSIGN_NULLISH_COALESCING singleExpression -> singleExpression"); }
#line 2855 "parser.tab.cpp"
    break;

  case 105: /* singleExpression: singleExpression OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT singleExpression  */
#line 249 "parser.y"
                                                                             { Print("- R: singleExpression OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 2861 "parser.tab.cpp"
    break;

  case 106: /* singleExpression: singleExpression OPERATOR_LOGICAL_OR singleExpression  */
#line 250 "parser.y"
                                                            { Print("- R: singleExpression OPERATOR_LOGICAL_OR singleExpression -> singleExpression"); }
#line 2867 "parser.tab.cpp"
    break;

  case 107: /* singleExpression: singleExpression OPERATOR_LOGICAL_AND singleExpression  */
#line 251 "parser.y"
                                                             { Print("- R: singleExpression OPERATOR_LOGICAL_AND singleExpression -> singleExpression"); }
#line 2873 "parser.tab.cpp"
    break;

  case 108: /* singleExpression: singleExpression '|' singleExpression  */
#line 252 "parser.y"
                                            { Print("- R: singleExpression '|' singleExpression -> singleExpression"); }
#line 2879 "parser.tab.cpp"
    break;

  case 109: /* singleExpression: singleExpression '^' singleExpression  */
#line 253 "parser.y"
                                            { Print("- R: singleExpression '^' singleExpression -> singleExpression"); }
#line 2885 "parser.tab.cpp"
    break;

  case 110: /* singleExpression: singleExpression '&' singleExpression  */
#line 254 "parser.y"
                                            { Print("- R: singleExpression '&' singleExpression -> singleExpression"); }
#line 2891 "parser.tab.cpp"
    break;

  case 111: /* singleExpression: singleExpression OPERATOR_SHIFT_LEFT singleExpression  */
#line 255 "parser.y"
                                                            { Print("- R: singleExpression OPERATOR_SHIFT_LEFT singleExpression -> singleExpression"); }
#line 2897 "parser.tab.cpp"
    break;

  case 112: /* singleExpression: singleExpression OPERATOR_SHIFT_RIGHT singleExpression  */
#line 256 "parser.y"
                                                             { Print("- R: singleExpression OPERATOR_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 2903 "parser.tab.cpp"
    break;

  case 113: /* singleExpression: singleExpression OPERATOR_UNSIGNED_SHIFT_RIGHT singleExpression  */
#line 257 "parser.y"
                                                                      { Print("- R: singleExpression OPERATOR_UNSIGNED_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 2909 "parser.tab.cpp"
    break;

  case 114: /* singleExpression: singleExpression OPERATOR_NULLISH_COALESCING singleExpression  */
#line 258 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_NULLISH_COALESCING singleExpression -> singleExpression"); }
#line 2915 "parser.tab.cpp"
    break;

  case 115: /* singleExpression: singleExpression INSTANCEOF singleExpression  */
#line 260 "parser.y"
                                                   { Print("- R: singleExpression INSTANCEOF singleExpression -> singleExpression"); }
#line 2921 "parser.tab.cpp"
    break;

  case 116: /* singleExpression: singleExpression IN singleExpression  */
#line 261 "parser.y"
                                           { Print("- R: singleExpression IN singleExpression -> singleExpression"); }
#line 2927 "parser.tab.cpp"
    break;

  case 117: /* singleExpression: singleExpression TEMPLATE_LITERAL  */
#line 263 "parser.y"
                                        { Print("- R: singleExpression TEMPLATE_LITERAL -> singleExpression"); }
#line 2933 "parser.tab.cpp"
    break;

  case 118: /* singleExpression: singleExpression '?' singleExpression ':' singleExpression  */
#line 264 "parser.y"
                                                                 { Print("- R: singleExpression '?' singleExpression ':' singleExpression -> singleExpression"); }
#line 2939 "parser.tab.cpp"
    break;

  case 119: /* singleExpression: '(' expressionList ')'  */
#line 266 "parser.y"
                             { Print("- R: '(' expressionList ')' -> singleExpression"); }
#line 2945 "parser.tab.cpp"
    break;

  case 120: /* singleExpression: singleExpression arguments  */
#line 268 "parser.y"
                                 { Print("- R: singleExpression arguments -> singleExpression"); }
#line 2951 "parser.tab.cpp"
    break;

  case 121: /* singleExpression: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression  */
#line 270 "parser.y"
                                                                   { Print("- R: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression -> singleExpression"); }
#line 2957 "parser.tab.cpp"
    break;

  case 122: /* singleExpression: singleExpression '.' identifier  */
#line 271 "parser.y"
                                      { Print("- R: singleExpression '.' identifier -> singleExpression"); }
#line 2963 "parser.tab.cpp"
    break;

  case 123: /* singleExpression: arrayLiteral  */
#line 273 "parser.y"
                   { Print("- R: arrayLiteral -> singleExpression"); }
#line 2969 "parser.tab.cpp"
    break;

  case 124: /* singleExpression: singleExpression '[' expressionList ']'  */
#line 274 "parser.y"
                                              { Print("- R: singleExpression '[' singleExpression ']' -> singleExpression"); }
#line 2975 "parser.tab.cpp"
    break;

  case 125: /* singleExpression: singleExpression ENDL_BRACKET_OPEN expressionList ']'  */
#line 275 "parser.y"
                                                            { Print("- R: singleExpression ENDL_BRACKET_OPEN singleExpression ']' -> singleExpression"); }
#line 2981 "parser.tab.cpp"
    break;

  case 126: /* singleExpression: NEW singleExpression  */
#line 277 "parser.y"
                           { Print("- R: NEW singleExpression -> singleExpression"); }
#line 2987 "parser.tab.cpp"
    break;

  case 127: /* arguments: '(' ')'  */
#line 281 "parser.y"
              { Print("- R: '(' ')' -> arguments"); }
#line 2993 "parser.tab.cpp"
    break;

  case 128: /* arguments: '(' argumentList ')'  */
#line 282 "parser.y"
                           { Print("- R: '(' argumentList ')' -> arguments"); }
#line 2999 "parser.tab.cpp"
    break;

  case 129: /* arguments: '(' argumentList ',' ')'  */
#line 283 "parser.y"
                               { Print("- R: '(' argumentList ',' ') -> arguments"); }
#line 3005 "parser.tab.cpp"
    break;

  case 130: /* argumentList: argument  */
#line 287 "parser.y"
               { Print("- R: argument -> argumentList"); }
#line 3011 "parser.tab.cpp"
    break;

  case 131: /* argumentList: argumentList ',' arguments  */
#line 288 "parser.y"
                                 { Print("- R: argumentList ',' arguments -> argumentList"); }
#line 3017 "parser.tab.cpp"
    break;

  case 132: /* argument: singleExpression  */
#line 292 "parser.y"
                       { Print("- R: singleExpression -> argument"); }
#line 3023 "parser.tab.cpp"
    break;

  case 133: /* argument: ELLIPSIS singleExpression  */
#line 293 "parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> argument"); }
#line 3029 "parser.tab.cpp"
    break;

  case 134: /* varStatement: varModifier varDeclarationList  */
#line 299 "parser.y"
                                     { Print("- R: varModifier varDeclarationList -> varStatement"); }
#line 3035 "parser.tab.cpp"
    break;

  case 135: /* varDeclarationList: varDeclaration  */
#line 303 "parser.y"
                     { Print("- R: varDeclaration -> argument"); }
#line 3041 "parser.tab.cpp"
    break;

  case 136: /* varDeclarationList: varDeclarationList ',' varDeclaration  */
#line 304 "parser.y"
                                            { Print("- R: varDeclarationList ',' varDeclaration -> varDeclarationList"); }
#line 3047 "parser.tab.cpp"
    break;

  case 137: /* varDeclaration: identifier  */
#line 308 "parser.y"
                 { Print("- R: identifier -> varDeclaration"); }
#line 3053 "parser.tab.cpp"
    break;

  case 138: /* varDeclaration: identifier typeAnnotation  */
#line 309 "parser.y"
                                { Print("- R: identifier typeAnnotation -> varDeclaration"); }
#line 3059 "parser.tab.cpp"
    break;

  case 139: /* varDeclaration: identifier '=' singleExpression  */
#line 310 "parser.y"
                                      { Print("- R: identifier '=' singleExpression -> varDeclaration"); }
#line 3065 "parser.tab.cpp"
    break;

  case 140: /* varDeclaration: identifier typeAnnotation '=' singleExpression  */
#line 311 "parser.y"
                                                     { Print("- R: identifier typeAnnotation '=' singleExpression -> varDeclaration"); }
#line 3071 "parser.tab.cpp"
    break;

  case 141: /* varModifier: VAR  */
#line 315 "parser.y"
          { Print("- R: VAR -> varModifier"); }
#line 3077 "parser.tab.cpp"
    break;

  case 142: /* varModifier: LET  */
#line 316 "parser.y"
          { Print("- R: LET -> varModifier"); }
#line 3083 "parser.tab.cpp"
    break;

  case 143: /* varModifier: CONST  */
#line 317 "parser.y"
            { Print("- R: CONST -> varModifier"); }
#line 3089 "parser.tab.cpp"
    break;

  case 144: /* ifStatement: IF '(' expressionList ')' statementListItem  */
#line 323 "parser.y"
                                                                     { Print("- R:  IF '(' expressionList ')' statementListItem -> ifStatement"); }
#line 3095 "parser.tab.cpp"
    break;

  case 145: /* ifStatement: IF '(' expressionList ')' statementListItem ELSE statementListItem  */
#line 324 "parser.y"
                                                                         { Print("- R: IF '(' expressionList ')' statementListItem ELSE statementListItem -> ifStatement"); }
#line 3101 "parser.tab.cpp"
    break;

  case 146: /* $@1: %empty  */
#line 328 "parser.y"
                                                        { doWhileASI(); }
#line 3107 "parser.tab.cpp"
    break;

  case 147: /* iterationStatement: DO statementListItem WHILE '(' expressionList ')' $@1 statementSep  */
#line 328 "parser.y"
                                                                                       { Print("- R: DO statementListItem WHILE '(' expressionList ')' statementSep -> iterationStatement"); }
#line 3113 "parser.tab.cpp"
    break;

  case 148: /* iterationStatement: WHILE '(' expressionList ')' statementListItem  */
#line 329 "parser.y"
                                                     { Print("- R: WHILE '(' expressionList ')' statementListItem -> iterationStatement"); }
#line 3119 "parser.tab.cpp"
    break;

  case 149: /* iterationStatement: FOR '(' expressionListOpt ';' expressionListOpt ';' expressionListOpt ')' statementListItem  */
#line 330 "parser.y"
                                                                                                  { Print("- R: FOR '(' expressionListOpt ';' expressionListOpt ';' expressionListOpt ')' statementListItem -> iterationStatement"); }
#line 3125 "parser.tab.cpp"
    break;

  case 150: /* iterationStatement: FOR '(' varModifier varDeclarationList ';' expressionListOpt ';' expressionListOpt ')' statementListItem  */
#line 331 "parser.y"
                                                                                                               { Print("- R: FOR '(' varModifier varDeclarationList ';' expressionListOpt ';' expressionListOpt ')' statementListItem -> iterationStatement"); }
#line 3131 "parser.tab.cpp"
    break;

  case 151: /* iterationStatement: FOR '(' singleExpression IN singleExpression ')' statementListItem  */
#line 332 "parser.y"
                                                                         { Print("- R: FOR '(' singleExpression IN singleExpression ')' statementListItem -> iterationStatement"); }
#line 3137 "parser.tab.cpp"
    break;

  case 152: /* iterationStatement: FOR '(' varModifier varDeclaration IN expressionList ')' statementListItem  */
#line 333 "parser.y"
                                                                                 { Print("- R: FOR '(' varModifier varDeclaration IN expressionList ')' statementListItem -> iterationStatement"); }
#line 3143 "parser.tab.cpp"
    break;

  case 153: /* continueStatement: CONTINUE  */
#line 337 "parser.y"
               { Print("- R: CONTINUE -> returnStatement"); }
#line 3149 "parser.tab.cpp"
    break;

  case 154: /* continueStatement: CONTINUE identifier  */
#line 338 "parser.y"
                          { Print("- R: CONTINUE identifier -> returnStatement"); }
#line 3155 "parser.tab.cpp"
    break;

  case 155: /* breakStatement: BREAK  */
#line 342 "parser.y"
             { Print("- R: BREAK -> returnStatement"); }
#line 3161 "parser.tab.cpp"
    break;

  case 156: /* breakStatement: BREAK identifier  */
#line 343 "parser.y"
                       { Print("- R: BREAK identifier -> returnStatement"); }
#line 3167 "parser.tab.cpp"
    break;

  case 157: /* returnStatement: RETURN  */
#line 347 "parser.y"
             { Print("- R: RETURN -> returnStatement"); }
#line 3173 "parser.tab.cpp"
    break;

  case 158: /* returnStatement: RETURN singleExpression  */
#line 348 "parser.y"
                              { Print("- R: RETURN singleExpression -> returnStatement"); }
#line 3179 "parser.tab.cpp"
    break;

  case 159: /* labelledStatement: identifier ':' statementListItem  */
#line 352 "parser.y"
                                       { Print("- R: identifier ':' statementListItem -> labelledStatement"); }
#line 3185 "parser.tab.cpp"
    break;

  case 160: /* blockStatement: '{' '}'  */
#line 356 "parser.y"
              { Print("- R: '{' '}' -> blockStatement"); }
#line 3191 "parser.tab.cpp"
    break;

  case 161: /* blockStatement: '{' statementList '}'  */
#line 357 "parser.y"
                            { Print("- R: '{' statementList '}' -> blockStatement"); }
#line 3197 "parser.tab.cpp"
    break;

  case 162: /* switchStatement: SWITCH '(' expressionList ')' '{' '}'  */
#line 361 "parser.y"
                                            { Print("- R: SWITCH '(' expressionList ')' '{' '}' -> switchStatement"); }
#line 3203 "parser.tab.cpp"
    break;

  case 163: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList '}'  */
#line 362 "parser.y"
                                                           { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList '}' -> switchStatement"); }
#line 3209 "parser.tab.cpp"
    break;

  case 164: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause '}'  */
#line 363 "parser.y"
                                                                         { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause '}' -> switchStatement"); }
#line 3215 "parser.tab.cpp"
    break;

  case 165: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause caseClauseList '}'  */
#line 364 "parser.y"
                                                                                        { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause caseClauseList '}' -> switchStatement"); }
#line 3221 "parser.tab.cpp"
    break;

  case 166: /* caseClauseList: caseClause  */
#line 368 "parser.y"
                 { Print("- R: caseClause -> caseClauseList"); }
#line 3227 "parser.tab.cpp"
    break;

  case 167: /* caseClauseList: caseClauseList caseClause  */
#line 369 "parser.y"
                                { Print("- R: caseClauseList caseClause -> caseClauseList"); }
#line 3233 "parser.tab.cpp"
    break;

  case 168: /* caseClause: CASE expressionList ':'  */
#line 373 "parser.y"
                              { Print("- R: CASE expressionList ':' -> caseClause"); }
#line 3239 "parser.tab.cpp"
    break;

  case 169: /* caseClause: CASE expressionList ':' statementList  */
#line 374 "parser.y"
                                            { Print("- R: CASE expressionList ':' statementList -> caseClause"); }
#line 3245 "parser.tab.cpp"
    break;

  case 170: /* defaultClause: DEFAULT ':'  */
#line 378 "parser.y"
                  { Print("- R: DEFAULT ':' -> defaultClause"); }
#line 3251 "parser.tab.cpp"
    break;

  case 171: /* defaultClause: DEFAULT ':' statementList  */
#line 379 "parser.y"
                                { Print("- R: DEFAULT ':' statementList -> defaultClause"); }
#line 3257 "parser.tab.cpp"
    break;

  case 172: /* functionDeclaration: FUNCTION identifier callSignature '{' functionBody '}'  */
#line 385 "parser.y"
                                                             { Print("- R: FUNCTION ID callSignature '{' functionBody '}' -> functionDeclaration"); }
#line 3263 "parser.tab.cpp"
    break;

  case 173: /* functionBody: %empty  */
#line 389 "parser.y"
                  { Print("- R: #empty# -> functionBody"); }
#line 3269 "parser.tab.cpp"
    break;

  case 174: /* functionBody: statementList  */
#line 390 "parser.y"
                    { Print("- R: statementList -> returnStatement"); }
#line 3275 "parser.tab.cpp"
    break;

  case 175: /* callSignature: '(' ')'  */
#line 394 "parser.y"
              { Print("- R: '(' ')' -> callSignature"); }
#line 3281 "parser.tab.cpp"
    break;

  case 176: /* callSignature: '(' ')' typeAnnotation  */
#line 395 "parser.y"
                             { Print("- R: '(' ')' typeAnnotation -> callSignature"); }
#line 3287 "parser.tab.cpp"
    break;

  case 177: /* callSignature: '(' restParameter ')'  */
#line 396 "parser.y"
                            { Print("- R: '(' restParameter ')' -> callSignature"); }
#line 3293 "parser.tab.cpp"
    break;

  case 178: /* callSignature: '(' restParameter ')' typeAnnotation  */
#line 397 "parser.y"
                                           { Print("- R: '(' restParameter ')' typeAnnotation -> callSignature"); }
#line 3299 "parser.tab.cpp"
    break;

  case 179: /* callSignature: '(' parameterList ')'  */
#line 398 "parser.y"
                            { Print("- R: '(' parameterList ')' -> callSignature"); }
#line 3305 "parser.tab.cpp"
    break;

  case 180: /* callSignature: '(' parameterList ')' typeAnnotation  */
#line 399 "parser.y"
                                           { Print("- R: '(' parameterList ')' typeAnnotation -> callSignature"); }
#line 3311 "parser.tab.cpp"
    break;

  case 181: /* callSignature: '(' parameterList ',' restParameter ')'  */
#line 400 "parser.y"
                                              { Print("- R: '(' parameterList ',' restParameter ')' -> callSignature"); }
#line 3317 "parser.tab.cpp"
    break;

  case 182: /* callSignature: '(' parameterList ',' restParameter ')' typeAnnotation  */
#line 401 "parser.y"
                                                             { Print("- R: '(' parameterList ',' restParameter ')' typeAnnotation -> callSignature"); }
#line 3323 "parser.tab.cpp"
    break;

  case 183: /* callSignature: '(' parameterList ',' ')'  */
#line 402 "parser.y"
                                { Print("- R: '(' parameterList ',' ')' -> callSignature"); }
#line 3329 "parser.tab.cpp"
    break;

  case 184: /* callSignature: '(' parameterList ',' ')' typeAnnotation  */
#line 403 "parser.y"
                                               { Print("- R: '(' parameterList ',' ')' typeAnnotation -> callSignature"); }
#line 3335 "parser.tab.cpp"
    break;

  case 185: /* parameterList: parameter  */
#line 407 "parser.y"
                { Print("- R: parameter -> parameterList"); }
#line 3341 "parser.tab.cpp"
    break;

  case 186: /* parameterList: parameterList ',' parameter  */
#line 408 "parser.y"
                                  { Print("- R: parameterList ',' parameter -> parameterList"); }
#line 3347 "parser.tab.cpp"
    break;

  case 187: /* parameter: requiredParameter  */
#line 412 "parser.y"
                        { Print("- R: requiredParameter -> parameter"); }
#line 3353 "parser.tab.cpp"
    break;

  case 188: /* parameter: optionalParameter  */
#line 413 "parser.y"
                        { Print("- R: optionalParameter -> parameter"); }
#line 3359 "parser.tab.cpp"
    break;

  case 189: /* requiredParameter: identifier  */
#line 417 "parser.y"
                 { Print("- R: ID -> requiredParameter"); }
#line 3365 "parser.tab.cpp"
    break;

  case 190: /* requiredParameter: identifier typeAnnotation  */
#line 418 "parser.y"
                                { Print("- R: ID typeAnnotation -> requiredParameter"); }
#line 3371 "parser.tab.cpp"
    break;

  case 191: /* optionalParameter: identifier '?'  */
#line 422 "parser.y"
                     { Print("- R: ID '?' -> optionalParameter"); }
#line 3377 "parser.tab.cpp"
    break;

  case 192: /* optionalParameter: identifier '?' typeAnnotation  */
#line 423 "parser.y"
                                    { Print("- R: ID '?' typeAnnotation -> optionalParameter"); }
#line 3383 "parser.tab.cpp"
    break;

  case 193: /* optionalParameter: identifier initializer  */
#line 424 "parser.y"
                             { Print("- R: ID initializer -> optionalParameter"); }
#line 3389 "parser.tab.cpp"
    break;

  case 194: /* optionalParameter: identifier typeAnnotation initializer  */
#line 425 "parser.y"
                                            { Print("- R: ID typeAnnotation initializer -> optionalParameter"); }
#line 3395 "parser.tab.cpp"
    break;

  case 195: /* restParameter: ELLIPSIS singleExpression  */
#line 429 "parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> restParameter"); }
#line 3401 "parser.tab.cpp"
    break;

  case 196: /* restParameter: ELLIPSIS singleExpression typeAnnotation  */
#line 430 "parser.y"
                                               { Print("- R: ELLIPSIS singleExpression typeAnnotation -> restParameter"); }
#line 3407 "parser.tab.cpp"
    break;

  case 197: /* classDeclaration: CLASS identifier classTail  */
#line 436 "parser.y"
                                 { Print("- R: CLASS identifier classTail -> classDeclaration"); }
#line 3413 "parser.tab.cpp"
    break;

  case 198: /* classDeclaration: CLASS identifier classHeritage classTail  */
#line 437 "parser.y"
                                               { Print("- R: CLASS identifier classHeritage classTail -> classDeclaration"); }
#line 3419 "parser.tab.cpp"
    break;

  case 199: /* classHeritage: EXTENDS typeReference  */
#line 441 "parser.y"
                            { Print("- R: EXTENDS typeReference -> classHeritage"); }
#line 3425 "parser.tab.cpp"
    break;

  case 200: /* classTail: '{' '}'  */
#line 445 "parser.y"
              { Print("- R: '{' '}' -> classTail"); }
#line 3431 "parser.tab.cpp"
    break;

  case 201: /* classTail: '{' classElementList '}'  */
#line 446 "parser.y"
                               { Print("- R: '{' classElementList '}' -> classTail"); }
#line 3437 "parser.tab.cpp"
    break;

  case 202: /* classElementList: classElement  */
#line 450 "parser.y"
                   { Print("- R: classElement -> classElementList"); }
#line 3443 "parser.tab.cpp"
    break;

  case 203: /* classElementList: classElementList classElement  */
#line 451 "parser.y"
                                    { Print("- R: classElementList classElement -> classElementList"); }
#line 3449 "parser.tab.cpp"
    break;

  case 204: /* classElement: CONSTRUCTOR callSignature '{' functionBody '}'  */
#line 455 "parser.y"
                                                     { Print("- R: CONSTRUCTOR callSignature '{' functionBody '}' -> classElement"); }
#line 3455 "parser.tab.cpp"
    break;

  case 205: /* classElement: propertyName ';'  */
#line 458 "parser.y"
                       { Print("- R: propertyName ';' -> classElement"); }
#line 3461 "parser.tab.cpp"
    break;

  case 206: /* classElement: propertyName typeAnnotation ';'  */
#line 459 "parser.y"
                                      { Print("- R: propertyName typeAnnotation ';' -> classElement"); }
#line 3467 "parser.tab.cpp"
    break;

  case 207: /* classElement: propertyName initializer ';'  */
#line 460 "parser.y"
                                   { Print("- R: propertyName initializer ';' -> classElement"); }
#line 3473 "parser.tab.cpp"
    break;

  case 208: /* classElement: propertyName typeAnnotation initializer ';'  */
#line 461 "parser.y"
                                                  { Print("- R: propertyName typeAnnotation initializer ';' -> classElement"); }
#line 3479 "parser.tab.cpp"
    break;

  case 209: /* classElement: propertyName callSignature '{' functionBody '}'  */
#line 464 "parser.y"
                                                      { Print("- R: propertyName callSignature '{' functionBody '}' -> classElement"); }
#line 3485 "parser.tab.cpp"
    break;

  case 210: /* classElement: GET propertyName '(' ')' '{' functionBody '}'  */
#line 467 "parser.y"
                                                    { Print("- R: GET propertyName '(' ')' '{' functionBody '}' -> classElement"); }
#line 3491 "parser.tab.cpp"
    break;

  case 211: /* classElement: GET propertyName '(' ')' typeAnnotation '{' functionBody '}'  */
#line 468 "parser.y"
                                                                   { Print("- R: GET propertyName '(' ')' typeAnnotation '{' functionBody '}' -> classElement"); }
#line 3497 "parser.tab.cpp"
    break;

  case 212: /* classElement: SET propertyName callSignature '{' functionBody '}'  */
#line 469 "parser.y"
                                                          { Print("- R: SET propertyName callSignature '{' functionBody '}' -> classElement"); }
#line 3503 "parser.tab.cpp"
    break;

  case 213: /* propertyName: identifier  */
#line 473 "parser.y"
                 { Print("- R: identifier -> propertyName"); }
#line 3509 "parser.tab.cpp"
    break;

  case 214: /* propertyName: STRING_LIT  */
#line 474 "parser.y"
                 { Print("- R: STRING_LIT -> propertyName"); }
#line 3515 "parser.tab.cpp"
    break;

  case 215: /* propertyName: INT_LIT  */
#line 475 "parser.y"
              { Print("- R: INT_LIT -> propertyName"); }
#line 3521 "parser.tab.cpp"
    break;

  case 216: /* propertyName: FLOAT_LIT  */
#line 476 "parser.y"
                { Print("- R: FLOAT_LIT -> propertyName"); }
#line 3527 "parser.tab.cpp"
    break;

  case 217: /* propertyName: '[' singleExpression ']'  */
#line 477 "parser.y"
                               { Print("- R: '[' singleExpression ']' -> propertyName"); }
#line 3533 "parser.tab.cpp"
    break;

  case 218: /* propertyName: ENDL_BRACKET_OPEN singleExpression ']'  */
#line 478 "parser.y"
                                             { Print("- R: ENDL_BRACKET_OPEN singleExpression ']' -> propertyName"); }
#line 3539 "parser.tab.cpp"
    break;

  case 219: /* identifier: ID  */
#line 482 "parser.y"
         { Print("- R: ID -> identifier"); }
#line 3545 "parser.tab.cpp"
    break;

  case 220: /* identifier: ASYNC  */
#line 483 "parser.y"
            { Print("- R: ASYNC -> identifier"); }
#line 3551 "parser.tab.cpp"
    break;

  case 221: /* identifier: AS  */
#line 484 "parser.y"
         { Print("- R: AS -> identifier"); }
#line 3557 "parser.tab.cpp"
    break;

  case 222: /* identifier: FROM  */
#line 485 "parser.y"
           { Print("- R: FROM -> identifier"); }
#line 3563 "parser.tab.cpp"
    break;

  case 223: /* identifier: YIELD  */
#line 486 "parser.y"
            { Print("- R: YIELD -> identifier"); }
#line 3569 "parser.tab.cpp"
    break;

  case 224: /* identifier: OF  */
#line 487 "parser.y"
         { Print("- R: OF -> identifier"); }
#line 3575 "parser.tab.cpp"
    break;

  case 225: /* identifier: ANY  */
#line 488 "parser.y"
          { Print("- R: ANY -> identifier"); }
#line 3581 "parser.tab.cpp"
    break;

  case 226: /* identifier: NUMBER  */
#line 489 "parser.y"
             { Print("- R: NUMBER -> identifier"); }
#line 3587 "parser.tab.cpp"
    break;

  case 227: /* identifier: BOOLEAN  */
#line 490 "parser.y"
              { Print("- R: BOOLEAN -> identifier"); }
#line 3593 "parser.tab.cpp"
    break;

  case 228: /* identifier: STRING  */
#line 491 "parser.y"
             { Print("- R: STRING -> identifier"); }
#line 3599 "parser.tab.cpp"
    break;

  case 229: /* identifier: UNIQUE  */
#line 492 "parser.y"
             { Print("- R: UNIQUE -> identifier"); }
#line 3605 "parser.tab.cpp"
    break;

  case 230: /* identifier: SYMBOL  */
#line 493 "parser.y"
             { Print("- R: SYMBOL -> identifier"); }
#line 3611 "parser.tab.cpp"
    break;

  case 231: /* identifier: NEVER  */
#line 494 "parser.y"
            { Print("- R: NEVER -> identifier"); }
#line 3617 "parser.tab.cpp"
    break;

  case 232: /* identifier: UNDEFINED  */
#line 495 "parser.y"
                { Print("- R: UNDEFINED -> identifier"); }
#line 3623 "parser.tab.cpp"
    break;

  case 233: /* identifier: OBJECT  */
#line 496 "parser.y"
             { Print("- R: OBJECT -> identifier"); }
#line 3629 "parser.tab.cpp"
    break;

  case 234: /* identifier: KEYOF  */
#line 497 "parser.y"
            { Print("- R: KEYOF -> identifier"); }
#line 3635 "parser.tab.cpp"
    break;

  case 235: /* identifier: NAMESPACE  */
#line 498 "parser.y"
                { Print("- R: NAMESPACE -> identifier"); }
#line 3641 "parser.tab.cpp"
    break;

  case 236: /* identifier: ABSTRACT  */
#line 499 "parser.y"
               { Print("- R: ABSTRACT -> identifier"); }
#line 3647 "parser.tab.cpp"
    break;

  case 237: /* identifier: REQUIRE  */
#line 500 "parser.y"
              { Print("- R: REQUIRE -> identifier"); }
#line 3653 "parser.tab.cpp"
    break;


#line 3657 "parser.tab.cpp"

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

#line 503 "parser.y"



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
