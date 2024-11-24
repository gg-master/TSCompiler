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
  YYSYMBOL_STATIC = 11,                    /* STATIC  */
  YYSYMBOL_GET = 12,                       /* GET  */
  YYSYMBOL_SET = 13,                       /* SET  */
  YYSYMBOL_DO = 14,                        /* DO  */
  YYSYMBOL_WHILE = 15,                     /* WHILE  */
  YYSYMBOL_FOR = 16,                       /* FOR  */
  YYSYMBOL_CONTINUE = 17,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 18,                     /* BREAK  */
  YYSYMBOL_SWITCH = 19,                    /* SWITCH  */
  YYSYMBOL_CASE = 20,                      /* CASE  */
  YYSYMBOL_DEFAULT = 21,                   /* DEFAULT  */
  YYSYMBOL_RETURN = 22,                    /* RETURN  */
  YYSYMBOL_SUPER = 23,                     /* SUPER  */
  YYSYMBOL_THIS = 24,                      /* THIS  */
  YYSYMBOL_NEW = 25,                       /* NEW  */
  YYSYMBOL_ELLIPSIS = 26,                  /* ELLIPSIS  */
  YYSYMBOL_OF = 27,                        /* OF  */
  YYSYMBOL_ARROW_FUNCTION = 28,            /* ARROW_FUNCTION  */
  YYSYMBOL_PUBLIC = 29,                    /* PUBLIC  */
  YYSYMBOL_PRIVATE = 30,                   /* PRIVATE  */
  YYSYMBOL_PROTECTED = 31,                 /* PROTECTED  */
  YYSYMBOL_ASYNC = 32,                     /* ASYNC  */
  YYSYMBOL_AS = 33,                        /* AS  */
  YYSYMBOL_FROM = 34,                      /* FROM  */
  YYSYMBOL_YIELD = 35,                     /* YIELD  */
  YYSYMBOL_KEYOF = 36,                     /* KEYOF  */
  YYSYMBOL_CONSTRUCTOR = 37,               /* CONSTRUCTOR  */
  YYSYMBOL_NAMESPACE = 38,                 /* NAMESPACE  */
  YYSYMBOL_ABSTRACT = 39,                  /* ABSTRACT  */
  YYSYMBOL_REQUIRE = 40,                   /* REQUIRE  */
  YYSYMBOL_ANY = 41,                       /* ANY  */
  YYSYMBOL_NUMBER = 42,                    /* NUMBER  */
  YYSYMBOL_BOOLEAN = 43,                   /* BOOLEAN  */
  YYSYMBOL_STRING = 44,                    /* STRING  */
  YYSYMBOL_NEVER = 45,                     /* NEVER  */
  YYSYMBOL_UNDEFINED = 46,                 /* UNDEFINED  */
  YYSYMBOL_UNIQUE = 47,                    /* UNIQUE  */
  YYSYMBOL_SYMBOL = 48,                    /* SYMBOL  */
  YYSYMBOL_OBJECT = 49,                    /* OBJECT  */
  YYSYMBOL_VOID = 50,                      /* VOID  */
  YYSYMBOL_UNKNOWN = 51,                   /* UNKNOWN  */
  YYSYMBOL_STRING_LIT = 52,                /* STRING_LIT  */
  YYSYMBOL_INT_LIT = 53,                   /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 54,                 /* FLOAT_LIT  */
  YYSYMBOL_NULL_KW = 55,                   /* NULL_KW  */
  YYSYMBOL_TRUE_KW = 56,                   /* TRUE_KW  */
  YYSYMBOL_FALSE_KW = 57,                  /* FALSE_KW  */
  YYSYMBOL_ID = 58,                        /* ID  */
  YYSYMBOL_ENDL = 59,                      /* ENDL  */
  YYSYMBOL_TEMPLATE_LITERAL = 60,          /* TEMPLATE_LITERAL  */
  YYSYMBOL_OPERATOR_INCREMENT = 61,        /* OPERATOR_INCREMENT  */
  YYSYMBOL_OPERATOR_DECREMENT = 62,        /* OPERATOR_DECREMENT  */
  YYSYMBOL_ENDL_OPERATOR_INCREMENT = 63,   /* ENDL_OPERATOR_INCREMENT  */
  YYSYMBOL_ENDL_OPERATOR_DECREMENT = 64,   /* ENDL_OPERATOR_DECREMENT  */
  YYSYMBOL_IF_ONLY_PREC = 65,              /* IF_ONLY_PREC  */
  YYSYMBOL_66_ = 66,                       /* ','  */
  YYSYMBOL_67_ = 67,                       /* '='  */
  YYSYMBOL_OPERATOR_ASSIGN_PLUS = 68,      /* OPERATOR_ASSIGN_PLUS  */
  YYSYMBOL_OPERATOR_ASSIGN_MINUS = 69,     /* OPERATOR_ASSIGN_MINUS  */
  YYSYMBOL_OPERATOR_ASSIGN_POWER = 70,     /* OPERATOR_ASSIGN_POWER  */
  YYSYMBOL_OPERATOR_ASSIGN_MULTIPLY = 71,  /* OPERATOR_ASSIGN_MULTIPLY  */
  YYSYMBOL_OPERATOR_ASSIGN_DIVIDE = 72,    /* OPERATOR_ASSIGN_DIVIDE  */
  YYSYMBOL_OPERATOR_ASSIGN_MOD = 73,       /* OPERATOR_ASSIGN_MOD  */
  YYSYMBOL_OPERATOR_ASSIGN_SHIFT_LEFT = 74, /* OPERATOR_ASSIGN_SHIFT_LEFT  */
  YYSYMBOL_OPERATOR_ASSIGN_SHIFT_RIGHT = 75, /* OPERATOR_ASSIGN_SHIFT_RIGHT  */
  YYSYMBOL_OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT = 76, /* OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT  */
  YYSYMBOL_OPERATOR_ASSIGN_BITWISE_AND = 77, /* OPERATOR_ASSIGN_BITWISE_AND  */
  YYSYMBOL_OPERATOR_ASSIGN_BITWISE_XOR = 78, /* OPERATOR_ASSIGN_BITWISE_XOR  */
  YYSYMBOL_OPERATOR_ASSIGN_BITWISE_OR = 79, /* OPERATOR_ASSIGN_BITWISE_OR  */
  YYSYMBOL_OPERATOR_ASSIGN_LOGICAL_AND = 80, /* OPERATOR_ASSIGN_LOGICAL_AND  */
  YYSYMBOL_OPERATOR_ASSIGN_LOGICAL_OR = 81, /* OPERATOR_ASSIGN_LOGICAL_OR  */
  YYSYMBOL_OPERATOR_ASSIGN_NULLISH_COALESCING = 82, /* OPERATOR_ASSIGN_NULLISH_COALESCING  */
  YYSYMBOL_83_ = 83,                       /* '?'  */
  YYSYMBOL_84_ = 84,                       /* ':'  */
  YYSYMBOL_COND = 85,                      /* COND  */
  YYSYMBOL_OPERATOR_NULLISH_COALESCING = 86, /* OPERATOR_NULLISH_COALESCING  */
  YYSYMBOL_OPERATOR_LOGICAL_OR = 87,       /* OPERATOR_LOGICAL_OR  */
  YYSYMBOL_OPERATOR_LOGICAL_AND = 88,      /* OPERATOR_LOGICAL_AND  */
  YYSYMBOL_89_ = 89,                       /* '|'  */
  YYSYMBOL_90_ = 90,                       /* '^'  */
  YYSYMBOL_91_ = 91,                       /* '&'  */
  YYSYMBOL_OPERATOR_EQUAL = 92,            /* OPERATOR_EQUAL  */
  YYSYMBOL_OPERATOR_NOT_EQUAL = 93,        /* OPERATOR_NOT_EQUAL  */
  YYSYMBOL_OPERATOR_STRICT_EQUAL = 94,     /* OPERATOR_STRICT_EQUAL  */
  YYSYMBOL_OPERATOR_STRICT_NOT_EQUAL = 95, /* OPERATOR_STRICT_NOT_EQUAL  */
  YYSYMBOL_96_ = 96,                       /* '>'  */
  YYSYMBOL_97_ = 97,                       /* '<'  */
  YYSYMBOL_OPERATOR_GREATER_THAN_EQUAL = 98, /* OPERATOR_GREATER_THAN_EQUAL  */
  YYSYMBOL_OPERATOR_LESS_THAN_EQUAL = 99,  /* OPERATOR_LESS_THAN_EQUAL  */
  YYSYMBOL_INSTANCEOF = 100,               /* INSTANCEOF  */
  YYSYMBOL_IN = 101,                       /* IN  */
  YYSYMBOL_OPERATOR_SHIFT_LEFT = 102,      /* OPERATOR_SHIFT_LEFT  */
  YYSYMBOL_OPERATOR_SHIFT_RIGHT = 103,     /* OPERATOR_SHIFT_RIGHT  */
  YYSYMBOL_OPERATOR_UNSIGNED_SHIFT_RIGHT = 104, /* OPERATOR_UNSIGNED_SHIFT_RIGHT  */
  YYSYMBOL_105_ = 105,                     /* '+'  */
  YYSYMBOL_106_ = 106,                     /* '-'  */
  YYSYMBOL_107_ = 107,                     /* '*'  */
  YYSYMBOL_108_ = 108,                     /* '/'  */
  YYSYMBOL_109_ = 109,                     /* '%'  */
  YYSYMBOL_OPERATOR_POWER = 110,           /* OPERATOR_POWER  */
  YYSYMBOL_111_ = 111,                     /* '!'  */
  YYSYMBOL_112_ = 112,                     /* '~'  */
  YYSYMBOL_UMINUS = 113,                   /* UMINUS  */
  YYSYMBOL_UPLUS = 114,                    /* UPLUS  */
  YYSYMBOL_PREF_INCREMENT = 115,           /* PREF_INCREMENT  */
  YYSYMBOL_PREF_DECREMENT = 116,           /* PREF_DECREMENT  */
  YYSYMBOL_DELETE = 117,                   /* DELETE  */
  YYSYMBOL_TYPEOF = 118,                   /* TYPEOF  */
  YYSYMBOL_POST_INCREMENT = 119,           /* POST_INCREMENT  */
  YYSYMBOL_POST_DECREMENT = 120,           /* POST_DECREMENT  */
  YYSYMBOL_121_ = 121,                     /* '.'  */
  YYSYMBOL_122_ = 122,                     /* '['  */
  YYSYMBOL_123_ = 123,                     /* ']'  */
  YYSYMBOL_ENDL_BRACKET_OPEN = 124,        /* ENDL_BRACKET_OPEN  */
  YYSYMBOL_FUNC_CALL = 125,                /* FUNC_CALL  */
  YYSYMBOL_OPTIONAL_CHAINING_OPERATOR = 126, /* OPTIONAL_CHAINING_OPERATOR  */
  YYSYMBOL_MEMBER_ACCESS = 127,            /* MEMBER_ACCESS  */
  YYSYMBOL_128_ = 128,                     /* '('  */
  YYSYMBOL_129_ = 129,                     /* ')'  */
  YYSYMBOL_130_ = 130,                     /* ';'  */
  YYSYMBOL_131_ = 131,                     /* '{'  */
  YYSYMBOL_132_ = 132,                     /* '}'  */
  YYSYMBOL_YYACCEPT = 133,                 /* $accept  */
  YYSYMBOL_script = 134,                   /* script  */
  YYSYMBOL_statementList = 135,            /* statementList  */
  YYSYMBOL_statementListItem = 136,        /* statementListItem  */
  YYSYMBOL_statementSep = 137,             /* statementSep  */
  YYSYMBOL_initializer = 138,              /* initializer  */
  YYSYMBOL_type = 139,                     /* type  */
  YYSYMBOL_unionOrIntersectionOrPrimaryType = 140, /* unionOrIntersectionOrPrimaryType  */
  YYSYMBOL_primaryType = 141,              /* primaryType  */
  YYSYMBOL_predefinedType = 142,           /* predefinedType  */
  YYSYMBOL_typeAnnotation = 143,           /* typeAnnotation  */
  YYSYMBOL_arrayLiteral = 144,             /* arrayLiteral  */
  YYSYMBOL_elementList = 145,              /* elementList  */
  YYSYMBOL_arrayElement = 146,             /* arrayElement  */
  YYSYMBOL_expressionListOpt = 147,        /* expressionListOpt  */
  YYSYMBOL_expressionList = 148,           /* expressionList  */
  YYSYMBOL_singleExpression = 149,         /* singleExpression  */
  YYSYMBOL_arguments = 150,                /* arguments  */
  YYSYMBOL_argumentList = 151,             /* argumentList  */
  YYSYMBOL_argument = 152,                 /* argument  */
  YYSYMBOL_varStatement = 153,             /* varStatement  */
  YYSYMBOL_varDeclarationList = 154,       /* varDeclarationList  */
  YYSYMBOL_varDeclaration = 155,           /* varDeclaration  */
  YYSYMBOL_varModifier = 156,              /* varModifier  */
  YYSYMBOL_ifStatement = 157,              /* ifStatement  */
  YYSYMBOL_iterationStatement = 158,       /* iterationStatement  */
  YYSYMBOL_159_1 = 159,                    /* $@1  */
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
  YYSYMBOL_callSignature = 171,            /* callSignature  */
  YYSYMBOL_parameterList = 172,            /* parameterList  */
  YYSYMBOL_parameter = 173,                /* parameter  */
  YYSYMBOL_requiredParameter = 174,        /* requiredParameter  */
  YYSYMBOL_optionalParameter = 175,        /* optionalParameter  */
  YYSYMBOL_restParameter = 176,            /* restParameter  */
  YYSYMBOL_identifier = 177                /* identifier  */
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
#define YYFINAL  101
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1624

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  133
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  216
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  369

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   363


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   111,     2,     2,     2,   109,    91,     2,
     128,   129,   107,   105,    66,   106,   121,   108,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    84,   130,
      97,    67,    96,    83,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   122,     2,   123,    90,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   131,    89,   132,   112,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    85,    86,    87,    88,
      92,    93,    94,    95,    98,    99,   100,   101,   102,   103,
     104,   110,   113,   114,   115,   116,   117,   118,   119,   120,
     124,   125,   126,   127
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    83,    83,    87,    88,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   108,   112,   118,
     119,   120,   124,   125,   126,   130,   131,   133,   134,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   158,   163,   164,   168,
     169,   170,   174,   175,   181,   182,   186,   187,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   250,   251,   253,   254,
     256,   258,   259,   261,   262,   263,   265,   269,   270,   271,
     275,   276,   280,   281,   287,   291,   292,   296,   297,   298,
     299,   303,   304,   305,   311,   312,   316,   316,   317,   318,
     319,   320,   321,   325,   326,   330,   331,   335,   336,   340,
     344,   345,   349,   350,   351,   352,   356,   357,   361,   362,
     366,   367,   373,   377,   378,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   395,   396,   400,   401,   405,
     406,   410,   411,   412,   413,   417,   418,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463
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
  "IF", "ELSE", "FUNCTION", "CLASS", "EXTENDS", "STATIC", "GET", "SET",
  "DO", "WHILE", "FOR", "CONTINUE", "BREAK", "SWITCH", "CASE", "DEFAULT",
  "RETURN", "SUPER", "THIS", "NEW", "ELLIPSIS", "OF", "ARROW_FUNCTION",
  "PUBLIC", "PRIVATE", "PROTECTED", "ASYNC", "AS", "FROM", "YIELD",
  "KEYOF", "CONSTRUCTOR", "NAMESPACE", "ABSTRACT", "REQUIRE", "ANY",
  "NUMBER", "BOOLEAN", "STRING", "NEVER", "UNDEFINED", "UNIQUE", "SYMBOL",
  "OBJECT", "VOID", "UNKNOWN", "STRING_LIT", "INT_LIT", "FLOAT_LIT",
  "NULL_KW", "TRUE_KW", "FALSE_KW", "ID", "ENDL", "TEMPLATE_LITERAL",
  "OPERATOR_INCREMENT", "OPERATOR_DECREMENT", "ENDL_OPERATOR_INCREMENT",
  "ENDL_OPERATOR_DECREMENT", "IF_ONLY_PREC", "','", "'='",
  "OPERATOR_ASSIGN_PLUS", "OPERATOR_ASSIGN_MINUS", "OPERATOR_ASSIGN_POWER",
  "OPERATOR_ASSIGN_MULTIPLY", "OPERATOR_ASSIGN_DIVIDE",
  "OPERATOR_ASSIGN_MOD", "OPERATOR_ASSIGN_SHIFT_LEFT",
  "OPERATOR_ASSIGN_SHIFT_RIGHT", "OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT",
  "OPERATOR_ASSIGN_BITWISE_AND", "OPERATOR_ASSIGN_BITWISE_XOR",
  "OPERATOR_ASSIGN_BITWISE_OR", "OPERATOR_ASSIGN_LOGICAL_AND",
  "OPERATOR_ASSIGN_LOGICAL_OR", "OPERATOR_ASSIGN_NULLISH_COALESCING",
  "'?'", "':'", "COND", "OPERATOR_NULLISH_COALESCING",
  "OPERATOR_LOGICAL_OR", "OPERATOR_LOGICAL_AND", "'|'", "'^'", "'&'",
  "OPERATOR_EQUAL", "OPERATOR_NOT_EQUAL", "OPERATOR_STRICT_EQUAL",
  "OPERATOR_STRICT_NOT_EQUAL", "'>'", "'<'", "OPERATOR_GREATER_THAN_EQUAL",
  "OPERATOR_LESS_THAN_EQUAL", "INSTANCEOF", "IN", "OPERATOR_SHIFT_LEFT",
  "OPERATOR_SHIFT_RIGHT", "OPERATOR_UNSIGNED_SHIFT_RIGHT", "'+'", "'-'",
  "'*'", "'/'", "'%'", "OPERATOR_POWER", "'!'", "'~'", "UMINUS", "UPLUS",
  "PREF_INCREMENT", "PREF_DECREMENT", "DELETE", "TYPEOF", "POST_INCREMENT",
  "POST_DECREMENT", "'.'", "'['", "']'", "ENDL_BRACKET_OPEN", "FUNC_CALL",
  "OPTIONAL_CHAINING_OPERATOR", "MEMBER_ACCESS", "'('", "')'", "';'",
  "'{'", "'}'", "$accept", "script", "statementList", "statementListItem",
  "statementSep", "initializer", "type",
  "unionOrIntersectionOrPrimaryType", "primaryType", "predefinedType",
  "typeAnnotation", "arrayLiteral", "elementList", "arrayElement",
  "expressionListOpt", "expressionList", "singleExpression", "arguments",
  "argumentList", "argument", "varStatement", "varDeclarationList",
  "varDeclaration", "varModifier", "ifStatement", "iterationStatement",
  "$@1", "continueStatement", "breakStatement", "returnStatement",
  "labelledStatement", "blockStatement", "switchStatement",
  "caseClauseList", "caseClause", "defaultClause", "functionDeclaration",
  "functionBody", "callSignature", "parameterList", "parameter",
  "requiredParameter", "optionalParameter", "restParameter", "identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-323)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     714,  -323,  -323,  -323,  -114,  1566,   714,  -106,   -94,  1566,
    1566,   -90,  1032,  -323,  -323,  1032,  -323,  -323,  -323,  -323,
    -323,  -323,  -323,  -323,  -323,  -323,  -323,  -323,  -323,  -323,
    -323,  -323,  -323,  -323,  -323,  -323,  -323,  -323,  -323,  -323,
    -323,  -323,  -323,  1032,  1032,  1032,  1032,  1032,  1032,  1032,
    1032,   930,   930,  1032,  -323,   454,    41,   714,  -323,  -323,
     -43,  1227,   -80,  1566,  -323,  -323,   -80,   -80,   -80,  -323,
    -323,  -323,  -323,   -32,  1032,   -77,    38,  1032,    81,  -323,
    -323,  1032,  1227,  -323,    80,    80,    80,    80,    80,    80,
      80,    80,    80,  1032,   -24,  -323,  1227,    29,   -40,  -323,
     584,  -323,  -323,  1032,  -323,  -323,  -323,  -323,  -323,  1032,
    1032,  1032,  1032,  1032,  1032,  1032,  1032,  1032,  1032,  1032,
    1032,  1032,  1032,  1032,  1032,  1032,  1032,  1032,  1032,  1032,
    1032,  1032,  1032,  1032,  1032,  1032,  1032,  1032,  1032,  1032,
    1032,  1032,  1032,  1032,  1032,  1032,  1032,  1032,  1032,  1032,
    1566,  1032,  1032,   823,  -323,  -323,   -10,  -323,    93,  -323,
    -323,  -323,   714,   -36,    32,   -48,   -46,   -35,   -42,    26,
    1292,  1566,   -33,  1227,   930,  -323,  -323,  -323,  -323,  1227,
    1354,  1354,  1354,  1354,  1354,  1354,  1354,  1354,  1354,  1354,
    1354,  1354,  1354,  1354,  1354,  1354,  1097,   909,  1008,  1393,
    1431,  1468,   446,   446,   446,   446,   570,   570,   570,   570,
     570,   570,   700,   700,   700,  1018,  1018,    46,    46,    46,
      46,  -323,   107,   109,  1032,  -323,  1227,   -20,  -323,  1566,
    1032,   612,    65,  -323,   714,  1032,    56,   -19,  -323,  -323,
    -323,    34,   -22,   714,  1032,   714,  1032,  1032,   -39,    57,
      45,  -323,  1032,  -323,  -323,  1227,  -121,  -323,  -323,  1227,
    -323,  -323,  -323,  -323,  -323,  -323,   121,  -323,  -323,  -323,
    -323,  -323,  -323,  -323,  -323,  -323,  -323,   745,   745,   612,
    -323,   -76,    50,  -323,  1032,   173,  1162,  -323,   222,    56,
      56,  1032,    56,  -323,   111,   714,    49,   -18,  -323,    53,
     266,  1032,  1032,    15,   802,  -323,  -323,  -323,   -76,   -76,
      55,   745,   745,   171,  1227,   714,  -323,    56,  -323,    59,
    -323,  -323,  1227,  -323,  -323,  -323,  -323,  1032,   714,    60,
     -17,  1032,  -323,    -1,  -323,  -323,    94,  -323,  -323,   -79,
    -323,  -323,    56,   -80,    62,  -323,  1032,   714,   -45,   110,
    -323,  -323,    16,  -323,  -323,  -323,   714,    67,  -323,   714,
     714,  -323,    17,  -323,   714,   714,   714,  -323,  -323
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   141,   142,   143,     0,     0,     0,     0,     0,   153,
     155,     0,   157,    60,    59,     0,   202,   198,   199,   200,
     201,   212,   213,   214,   215,   216,   203,   204,   205,   206,
     209,   210,   207,   208,   211,    63,    61,    62,    67,    65,
      66,   197,    64,     0,     0,     0,     0,     0,     0,     0,
       0,    49,    49,     0,     5,     0,     0,     2,     3,   123,
       0,    56,     0,     0,     8,    10,     0,     0,     0,    14,
      15,     9,    16,    58,     0,     0,     0,     0,    54,   154,
     156,     0,   158,    58,   126,    76,    77,    74,    75,    69,
      68,    70,    71,     0,     0,    50,    52,     0,     0,   160,
       0,     1,     4,     0,    17,     6,   118,    72,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     7,   134,   135,   137,    11,
      12,    13,     0,     0,     0,     0,     0,     0,     0,    55,
      56,     0,     0,    53,    49,    47,    48,   120,   161,    57,
      92,    96,    97,   103,    93,    94,    95,    98,    99,   107,
     100,   101,   102,   104,   105,   106,     0,   108,   109,   110,
     111,   112,    86,    87,    88,    89,    84,    83,    91,    90,
     116,   117,   113,   114,   115,    78,    79,    80,    81,    82,
      85,   122,     0,     0,     0,   127,   132,     0,   130,     0,
       0,     0,   138,   159,     0,     0,   175,     0,   185,   187,
     188,     0,   189,   173,     0,     0,    54,     0,     0,   135,
       0,    51,     0,   124,   125,   133,     0,   128,   136,   139,
      29,    31,    34,    37,    41,    42,     0,    39,    44,    45,
      43,    38,    32,    33,    30,    35,    36,     0,     0,     0,
      46,    19,    24,    26,     0,   144,   195,   176,     0,   179,
     177,     0,   191,   193,   190,   174,     0,     0,   148,     0,
     117,    54,     0,     0,   119,   129,   131,    40,    20,    21,
       0,     0,     0,     0,   140,     0,   196,   183,   186,     0,
     180,   178,    18,   192,   194,   172,   146,    54,     0,     0,
       0,     0,   162,     0,   166,    25,    22,    23,    27,     0,
     145,   184,   181,     0,     0,   151,    54,     0,     0,     0,
     163,   167,     0,    28,   182,   147,     0,     0,   152,   168,
     170,   164,     0,   149,     0,   169,   171,   165,   150
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -323,  -323,   -54,    -3,   -50,   -88,   -69,  -112,  -102,  -323,
    -135,  -323,   -28,  -323,  -148,   -49,   289,   -23,  -323,  -323,
    -323,    64,  -169,   158,  -323,  -323,  -323,  -323,  -323,  -323,
    -323,  -323,  -323,  -115,  -322,  -323,  -323,  -323,  -323,  -323,
     -47,  -323,  -323,   -44,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    56,    57,    58,   105,   293,   280,   281,   282,   283,
     232,    59,    94,    95,   168,    60,    61,   154,   227,   228,
      62,   156,   157,    63,    64,    65,   343,    66,    67,    68,
      69,    70,    71,   333,   334,   352,    72,   296,   165,   237,
     238,   239,   240,   241,    83
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      73,   100,   249,    76,    98,    75,    73,   153,   305,    79,
      80,   351,   155,   311,    74,   312,   159,   160,   161,   331,
     349,   103,    77,   103,    97,   163,   103,   229,   167,   169,
     103,   103,   172,   103,    78,   331,   331,   331,    81,   359,
     351,   101,   174,   313,   353,   291,   256,   288,   103,   103,
     104,   164,   162,   166,   102,    73,   229,    73,   235,    16,
     258,   292,   231,   158,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,   244,   243,     1,     2,     3,   104,   246,   177,
      41,   301,   103,   234,   245,   174,   250,   102,   299,   175,
      73,   287,   222,   223,    13,    14,    15,   294,    16,   257,
     289,   326,   347,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,   350,   284,    35,    36,    37,    38,    39,    40,    41,
     231,    42,    43,    44,    45,    46,   251,   332,   361,   367,
     221,   316,   176,   329,   320,   321,   149,   323,   302,   233,
     230,   236,    73,   290,   242,   308,   309,   150,   151,   307,
     152,   158,   313,   103,   153,   103,   303,   231,   291,   344,
     315,   325,   341,   327,   335,   312,    47,    48,   342,   295,
     346,   356,    49,    50,   360,   297,   364,   169,   357,   336,
     337,   150,   151,    51,   152,    52,   324,   354,   153,    53,
     310,   339,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   158,
     253,   285,   254,   306,    73,   248,   171,   362,     0,     0,
       0,   318,   298,    73,   319,    73,     0,     0,   235,    16,
       0,     0,   169,   330,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     0,     0,     0,     0,     0,     0,   169,     0,
      41,     0,   348,     0,     0,     0,     0,     0,   242,     0,
       0,     0,   102,   355,   338,    73,     0,   169,     0,   279,
       0,    82,     0,     0,    84,   365,   366,     0,     0,     0,
       0,     0,   340,     0,     0,    73,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   345,     0,     0,    73,     0,
       0,     0,    85,    86,    87,    88,    89,    90,    91,    92,
      96,    96,     0,     0,   358,     0,     0,    73,     0,     0,
       0,   317,     0,   363,     0,     0,    73,     0,     0,    73,
      73,   368,   102,   102,    73,    73,    73,   170,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,     0,
       0,     0,   173,     0,     0,     0,     0,   150,   151,     0,
     152,     0,   179,     0,   153,   328,     0,     0,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,     0,
       0,     0,   226,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       4,     0,     5,    96,     0,     0,     0,     0,     6,     7,
       8,     9,    10,    11,     0,     0,    12,    13,    14,    15,
       0,    16,     0,     0,     0,     0,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,     0,    35,    36,    37,    38,
      39,    40,    41,   255,    42,    43,    44,    45,    46,   259,
       0,     0,     0,     0,   286,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   300,     0,     0,     0,
       0,   304,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,    47,
      48,     0,     0,     0,     0,    49,    50,   150,   151,     0,
     152,     0,     0,   314,   153,     0,    51,     0,    52,     0,
     322,     0,    53,     0,    54,    55,    99,     1,     2,     3,
       4,     0,     5,     0,     0,     0,     0,     0,     6,     7,
       8,     9,    10,    11,     0,     0,    12,    13,    14,    15,
       0,    16,     0,     0,     0,     0,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,     0,    35,    36,    37,    38,
      39,    40,    41,     0,    42,    43,    44,    45,    46,     0,
       0,     0,     0,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
       0,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,     0,     0,     0,     0,     0,     0,     0,     0,    47,
      48,   150,   151,     0,   152,    49,    50,     0,   153,     0,
       0,   277,     0,   278,     0,     0,    51,     0,    52,     0,
       0,     0,    53,     0,    54,    55,   178,     1,     2,     3,
       4,     0,     5,     0,     0,     0,     0,     0,     6,     7,
       8,     9,    10,    11,     0,     0,    12,    13,    14,    15,
     279,    16,     0,     0,     0,     0,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,     0,    35,    36,    37,    38,
      39,    40,    41,     0,    42,    43,    44,    45,    46,     0,
       0,     0,     0,     0,     0,     0,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,     0,     0,   144,   145,   146,   147,   148,
     149,     0,     0,     0,     0,     0,     0,     0,     0,    47,
      48,   150,   151,     0,   152,    49,    50,     0,   153,     0,
       0,     0,     0,     0,     0,     0,    51,     0,    52,     0,
       0,     0,    53,     0,    54,    55,    13,    14,    15,   224,
      16,     0,     0,     0,     0,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,   279,     0,    35,    36,    37,    38,    39,
      40,    41,     0,    42,    43,    44,    45,    46,     0,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   150,   151,     0,   152,     0,    47,    48,
     153,     0,     0,     0,    49,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,     0,    52,     0,     0,
       0,    53,   225,    13,    14,    15,    93,    16,     0,     0,
       0,     0,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       0,     0,    35,    36,    37,    38,    39,    40,    41,     0,
      42,    43,    44,    45,    46,     0,     0,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     150,   151,     0,   152,     0,    47,    48,   153,     0,     0,
       0,    49,    50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,     0,    52,    13,    14,    15,    53,    16,
       0,     0,     0,     0,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     0,     0,    35,    36,    37,    38,    39,    40,
      41,     0,    42,    43,    44,    45,    46,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,     0,
       0,     0,     0,     0,     0,   146,   147,   148,   149,   150,
     151,     0,   152,     0,     0,     0,   153,    47,    48,   150,
     151,     0,   152,    49,    50,     0,   153,     0,     0,     0,
       0,     0,     0,     0,    51,     0,    52,   106,   107,   108,
      53,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   252,     0,     0,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   150,   151,
       0,   152,   106,   107,   108,   153,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   231,     0,     0,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   150,   151,     0,   152,   106,   107,   108,
     153,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,     0,     0,     0,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   150,   151,
       0,   152,   106,   107,   108,   153,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,     0,     0,     0,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   247,   141,   142,   143,   144,   145,   146,
     147,   148,   149,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   150,   151,     0,   152,     0,     0,     0,
     153,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,     0,     0,
       0,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   150,   151,     0,   152,     0,
       0,     0,   153,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   150,   151,     0,   152,     0,     0,
       0,   153,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   150,   151,     0,   152,     0,     0,     0,   153,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   150,
     151,     0,   152,    16,     0,     0,   153,     0,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,     0,     0,     0,     0,
       0,     0,     0,     0,    41
};

static const yytype_int16 yycheck[] =
{
       0,    55,   171,     6,    53,     5,     6,   128,   129,     9,
      10,   333,    62,    89,   128,    91,    66,    67,    68,    20,
      21,    66,   128,    66,    52,    74,    66,    66,    77,    78,
      66,    66,    81,    66,   128,    20,    20,    20,   128,    84,
     362,     0,    66,   122,   123,    67,    66,    66,    66,    66,
     130,   128,    84,    15,    57,    55,    66,    57,    26,    27,
     229,    83,    84,    63,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,   128,   131,     3,     4,     5,   130,   130,   129,
      58,   130,    66,   129,   129,    66,   129,   100,   246,   123,
     100,   236,   151,   152,    23,    24,    25,   242,    27,   129,
     129,   129,   129,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,   132,    67,    52,    53,    54,    55,    56,    57,    58,
      84,    60,    61,    62,    63,    64,   174,   132,   132,   132,
     150,   286,   123,   301,   289,   290,   110,   292,   101,   162,
      67,   129,   162,   129,   164,   277,   278,   121,   122,    48,
     124,   171,   122,    66,   128,    66,   131,    84,    67,   327,
       7,   132,   317,   130,   129,    91,   105,   106,   129,   243,
     130,   129,   111,   112,    84,   244,   129,   246,   346,   311,
     312,   121,   122,   122,   124,   124,   294,   342,   128,   128,
     279,   313,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,   229,
     123,   234,   123,   256,   234,   171,    78,   352,    -1,    -1,
      -1,   288,   245,   243,   288,   245,    -1,    -1,    26,    27,
      -1,    -1,   301,   302,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,   327,    -1,
      58,    -1,   331,    -1,    -1,    -1,    -1,    -1,   288,    -1,
      -1,    -1,   295,   343,   123,   295,    -1,   346,    -1,   128,
      -1,    12,    -1,    -1,    15,   359,   360,    -1,    -1,    -1,
      -1,    -1,   315,    -1,    -1,   315,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   328,    -1,    -1,   328,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    -1,   347,    -1,    -1,   347,    -1,    -1,
      -1,   129,    -1,   356,    -1,    -1,   356,    -1,    -1,   359,
     360,   364,   365,   366,   364,   365,   366,    78,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    -1,    -1,    -1,
      -1,    -1,    93,    -1,    -1,    -1,    -1,   121,   122,    -1,
     124,    -1,   103,    -1,   128,   129,    -1,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,   174,    -1,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    19,    -1,    -1,    22,    23,    24,    25,
      -1,    27,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    52,    53,    54,    55,
      56,    57,    58,   224,    60,    61,    62,    63,    64,   230,
      -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,   252,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,   111,   112,   121,   122,    -1,
     124,    -1,    -1,   284,   128,    -1,   122,    -1,   124,    -1,
     291,    -1,   128,    -1,   130,   131,   132,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    19,    -1,    -1,    22,    23,    24,    25,
      -1,    27,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,   121,   122,    -1,   124,   111,   112,    -1,   128,    -1,
      -1,    89,    -1,    91,    -1,    -1,   122,    -1,   124,    -1,
      -1,    -1,   128,    -1,   130,   131,   132,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    19,    -1,    -1,    22,    23,    24,    25,
     128,    27,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    -1,   105,   106,   107,   108,   109,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,   121,   122,    -1,   124,   111,   112,    -1,   128,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,   124,    -1,
      -1,    -1,   128,    -1,   130,   131,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,   128,    -1,    52,    53,    54,    55,    56,
      57,    58,    -1,    60,    61,    62,    63,    64,    -1,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,    -1,   124,    -1,   105,   106,
     128,    -1,    -1,    -1,   111,   112,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   122,    -1,   124,    -1,    -1,
      -1,   128,   129,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    61,    62,    63,    64,    -1,    -1,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,   122,    -1,   124,    -1,   105,   106,   128,    -1,    -1,
      -1,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   122,    -1,   124,    23,    24,    25,   128,    27,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    52,    53,    54,    55,    56,    57,
      58,    -1,    60,    61,    62,    63,    64,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,   110,   121,
     122,    -1,   124,    -1,    -1,    -1,   128,   105,   106,   121,
     122,    -1,   124,   111,   112,    -1,   128,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   122,    -1,   124,    60,    61,    62,
     128,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    -1,    -1,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
      -1,   124,    60,    61,    62,   128,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    -1,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,    -1,   124,    60,    61,    62,
     128,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
      -1,   124,    60,    61,    62,   128,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,    -1,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,    -1,   124,    -1,    -1,    -1,
     128,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,    -1,   124,    -1,
      -1,    -1,   128,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,   122,    -1,   124,    -1,    -1,
      -1,   128,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,   122,    -1,   124,    -1,    -1,    -1,   128,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,    -1,   124,    27,    -1,    -1,   128,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     8,    14,    15,    16,    17,
      18,    19,    22,    23,    24,    25,    27,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    52,    53,    54,    55,    56,
      57,    58,    60,    61,    62,    63,    64,   105,   106,   111,
     112,   122,   124,   128,   130,   131,   134,   135,   136,   144,
     148,   149,   153,   156,   157,   158,   160,   161,   162,   163,
     164,   165,   169,   177,   128,   177,   136,   128,   128,   177,
     177,   128,   149,   177,   149,   149,   149,   149,   149,   149,
     149,   149,   149,    26,   145,   146,   149,   145,   148,   132,
     135,     0,   136,    66,   130,   137,    60,    61,    62,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     121,   122,   124,   128,   150,   137,   154,   155,   177,   137,
     137,   137,    84,   148,   128,   171,    15,   148,   147,   148,
     149,   156,   148,   149,    66,   123,   123,   129,   132,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   177,   148,   148,    26,   129,   149,   151,   152,    66,
      67,    84,   143,   136,   129,    26,   129,   172,   173,   174,
     175,   176,   177,   131,   128,   129,   130,   101,   154,   155,
     129,   145,    84,   123,   123,   149,    66,   129,   155,   149,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    89,    91,   128,
     139,   140,   141,   142,    67,   136,   149,   143,    66,   129,
     129,    67,    83,   138,   143,   135,   170,   148,   136,   147,
     149,   130,   101,   131,   149,   129,   150,    48,   140,   140,
     139,    89,    91,   122,   149,     7,   143,   129,   173,   176,
     143,   143,   149,   143,   138,   132,   129,   130,   129,   147,
     148,    20,   132,   166,   167,   129,   140,   140,   123,   141,
     136,   143,   129,   159,   147,   136,   130,   129,   148,    21,
     132,   167,   168,   123,   143,   137,   129,   147,   136,    84,
      84,   132,   166,   136,   129,   135,   135,   132,   136
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   133,   134,   135,   135,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   137,   138,   139,
     139,   139,   140,   140,   140,   141,   141,   141,   141,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   143,   144,   144,   145,
     145,   145,   146,   146,   147,   147,   148,   148,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   150,   150,   150,
     151,   151,   152,   152,   153,   154,   154,   155,   155,   155,
     155,   156,   156,   156,   157,   157,   159,   158,   158,   158,
     158,   158,   158,   160,   160,   161,   161,   162,   162,   163,
     164,   164,   165,   165,   165,   165,   166,   166,   167,   167,
     168,   168,   169,   170,   170,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   172,   172,   173,   173,   174,
     174,   175,   175,   175,   175,   176,   176,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     2,     1,     1,
       1,     2,     2,     2,     1,     1,     1,     1,     2,     1,
       2,     2,     3,     3,     1,     3,     1,     3,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     2,     3,     3,     0,
       1,     3,     1,     2,     0,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     5,
       3,     2,     3,     1,     4,     4,     2,     2,     3,     4,
       1,     3,     1,     2,     2,     1,     3,     1,     2,     3,
       4,     1,     1,     1,     5,     7,     0,     8,     5,     9,
      10,     7,     8,     1,     2,     1,     2,     1,     2,     3,
       2,     3,     6,     7,     8,     9,     1,     2,     3,     4,
       2,     3,     6,     0,     1,     2,     3,     3,     4,     3,
       4,     5,     6,     4,     5,     1,     3,     1,     1,     1,
       2,     2,     3,     2,     3,     2,     3,     1,     1,     1,
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
  case 2: /* script: statementList  */
#line 83 "parser.y"
                    { Print("- R: statementList -> script"); }
#line 2181 "parser.tab.cpp"
    break;

  case 3: /* statementList: statementListItem  */
#line 87 "parser.y"
                        { Print("- R: statementListItem -> statementList"); }
#line 2187 "parser.tab.cpp"
    break;

  case 4: /* statementList: statementList statementListItem  */
#line 88 "parser.y"
                                      { Print("- R: statementList statementListItem -> statementList"); }
#line 2193 "parser.tab.cpp"
    break;

  case 5: /* statementListItem: ';'  */
#line 92 "parser.y"
          { Print("- R: ';' -> statementListItem"); }
#line 2199 "parser.tab.cpp"
    break;

  case 6: /* statementListItem: expressionList statementSep  */
#line 93 "parser.y"
                                  { Print("- R: expressionList statementSep -> statementListItem"); }
#line 2205 "parser.tab.cpp"
    break;

  case 11: /* statementListItem: continueStatement statementSep  */
#line 98 "parser.y"
                                     { Print("- R: continueStatement statementSep -> statementListItem");  }
#line 2211 "parser.tab.cpp"
    break;

  case 12: /* statementListItem: breakStatement statementSep  */
#line 99 "parser.y"
                                  { Print("- R: breakStatement statementSep -> statementListItem"); }
#line 2217 "parser.tab.cpp"
    break;

  case 13: /* statementListItem: returnStatement statementSep  */
#line 100 "parser.y"
                                   { Print("- R: returnStatement statementSep -> statementListItem"); }
#line 2223 "parser.tab.cpp"
    break;

  case 17: /* statementSep: ';'  */
#line 108 "parser.y"
          { Print("- R: ';' -> statementSep"); }
#line 2229 "parser.tab.cpp"
    break;

  case 18: /* initializer: '=' singleExpression  */
#line 112 "parser.y"
                           { Print("- R: '=' singleExpression -> initializer"); }
#line 2235 "parser.tab.cpp"
    break;

  case 19: /* type: unionOrIntersectionOrPrimaryType  */
#line 118 "parser.y"
                                       { Print("- R: unionOrIntersectionOrPrimaryType -> type"); }
#line 2241 "parser.tab.cpp"
    break;

  case 20: /* type: '|' unionOrIntersectionOrPrimaryType  */
#line 119 "parser.y"
                                           { Print("- R: '|' unionOrIntersectionOrPrimaryType -> type"); }
#line 2247 "parser.tab.cpp"
    break;

  case 21: /* type: '&' unionOrIntersectionOrPrimaryType  */
#line 120 "parser.y"
                                           { Print("- R: '&' unionOrIntersectionOrPrimaryType -> type"); }
#line 2253 "parser.tab.cpp"
    break;

  case 22: /* unionOrIntersectionOrPrimaryType: unionOrIntersectionOrPrimaryType '|' unionOrIntersectionOrPrimaryType  */
#line 124 "parser.y"
                                                                            { Print("- R: unionOrIntersectionOrPrimaryType '|' unionOrIntersectionOrPrimaryType -> unionOrIntersectionOrPrimaryType"); }
#line 2259 "parser.tab.cpp"
    break;

  case 23: /* unionOrIntersectionOrPrimaryType: unionOrIntersectionOrPrimaryType '&' unionOrIntersectionOrPrimaryType  */
#line 125 "parser.y"
                                                                            { Print("- R: unionOrIntersectionOrPrimaryType '&' unionOrIntersectionOrPrimaryType -> unionOrIntersectionOrPrimaryType"); }
#line 2265 "parser.tab.cpp"
    break;

  case 24: /* unionOrIntersectionOrPrimaryType: primaryType  */
#line 126 "parser.y"
                  { Print("- R: primaryType -> argument"); }
#line 2271 "parser.tab.cpp"
    break;

  case 25: /* primaryType: '(' type ')'  */
#line 130 "parser.y"
                   { Print("- R: '(' type ')' -> primaryType"); }
#line 2277 "parser.tab.cpp"
    break;

  case 26: /* primaryType: predefinedType  */
#line 131 "parser.y"
                     { Print("- R: predefinedType -> primaryType"); }
#line 2283 "parser.tab.cpp"
    break;

  case 27: /* primaryType: primaryType '[' ']'  */
#line 133 "parser.y"
                          { Print("- R: primaryType ENDL_BRACKET_OPEN ']' -> primaryType"); }
#line 2289 "parser.tab.cpp"
    break;

  case 28: /* primaryType: primaryType '[' primaryType ']'  */
#line 134 "parser.y"
                                      { Print("- R: primaryType ENDL_BRACKET_OPEN primaryType ']' -> primaryType"); }
#line 2295 "parser.tab.cpp"
    break;

  case 29: /* predefinedType: ANY  */
#line 138 "parser.y"
          { Print("- R: ANY -> predefinedType"); }
#line 2301 "parser.tab.cpp"
    break;

  case 30: /* predefinedType: NULL_KW  */
#line 139 "parser.y"
              { Print("- R: NULL_LITERAL -> predefinedType"); }
#line 2307 "parser.tab.cpp"
    break;

  case 31: /* predefinedType: NUMBER  */
#line 140 "parser.y"
             { Print("- R: NUMBER -> predefinedType"); }
#line 2313 "parser.tab.cpp"
    break;

  case 32: /* predefinedType: INT_LIT  */
#line 141 "parser.y"
              { Print("- R: INT_LIT -> predefinedType"); }
#line 2319 "parser.tab.cpp"
    break;

  case 33: /* predefinedType: FLOAT_LIT  */
#line 142 "parser.y"
                { Print("- R: FLOAT_LIT -> predefinedType"); }
#line 2325 "parser.tab.cpp"
    break;

  case 34: /* predefinedType: BOOLEAN  */
#line 143 "parser.y"
              { Print("- R: BOOLEAN -> predefinedType"); }
#line 2331 "parser.tab.cpp"
    break;

  case 35: /* predefinedType: TRUE_KW  */
#line 144 "parser.y"
              { Print("- R: TRUE_LITERAL -> predefinedType"); }
#line 2337 "parser.tab.cpp"
    break;

  case 36: /* predefinedType: FALSE_KW  */
#line 145 "parser.y"
               { Print("- R: FALSE_LITERAL -> predefinedType"); }
#line 2343 "parser.tab.cpp"
    break;

  case 37: /* predefinedType: STRING  */
#line 146 "parser.y"
             { Print("- R: STRING -> predefinedType"); }
#line 2349 "parser.tab.cpp"
    break;

  case 38: /* predefinedType: STRING_LIT  */
#line 147 "parser.y"
                 { Print("- R: STRING_LIT -> predefinedType"); }
#line 2355 "parser.tab.cpp"
    break;

  case 39: /* predefinedType: SYMBOL  */
#line 148 "parser.y"
             { Print("- R: SYMBOL -> predefinedType"); }
#line 2361 "parser.tab.cpp"
    break;

  case 40: /* predefinedType: UNIQUE SYMBOL  */
#line 149 "parser.y"
                    { Print("- R: UNIQUE SYMBOL -> predefinedType"); }
#line 2367 "parser.tab.cpp"
    break;

  case 41: /* predefinedType: NEVER  */
#line 150 "parser.y"
            { Print("- R: NEVER -> predefinedType"); }
#line 2373 "parser.tab.cpp"
    break;

  case 42: /* predefinedType: UNDEFINED  */
#line 151 "parser.y"
                { Print("- R: UNDEFINED -> predefinedType"); }
#line 2379 "parser.tab.cpp"
    break;

  case 43: /* predefinedType: UNKNOWN  */
#line 152 "parser.y"
              { Print("- R: UNKNOWN -> predefinedType"); }
#line 2385 "parser.tab.cpp"
    break;

  case 44: /* predefinedType: OBJECT  */
#line 153 "parser.y"
             { Print("- R: OBJECT -> predefinedType"); }
#line 2391 "parser.tab.cpp"
    break;

  case 45: /* predefinedType: VOID  */
#line 154 "parser.y"
           { Print("- R: VOID -> predefinedType"); }
#line 2397 "parser.tab.cpp"
    break;

  case 46: /* typeAnnotation: ':' type  */
#line 158 "parser.y"
               { Print("- R: ':' type -> typeAnnotation"); }
#line 2403 "parser.tab.cpp"
    break;

  case 47: /* arrayLiteral: '[' elementList ']'  */
#line 163 "parser.y"
                          { Print("- R: [ elementList ']' -> arrayLiteral"); }
#line 2409 "parser.tab.cpp"
    break;

  case 48: /* arrayLiteral: ENDL_BRACKET_OPEN elementList ']'  */
#line 164 "parser.y"
                                        { Print("- R: ENDL_BRACKET_OPEN elementList ']' -> arrayLiteral"); }
#line 2415 "parser.tab.cpp"
    break;

  case 49: /* elementList: %empty  */
#line 168 "parser.y"
                  { Print("- R: #empty# -> elementList"); }
#line 2421 "parser.tab.cpp"
    break;

  case 50: /* elementList: arrayElement  */
#line 169 "parser.y"
                   { Print("- R: arrayElement -> elementList"); }
#line 2427 "parser.tab.cpp"
    break;

  case 51: /* elementList: elementList ',' elementList  */
#line 170 "parser.y"
                                  { Print("- R: elementList ',' elementList -> elementList"); }
#line 2433 "parser.tab.cpp"
    break;

  case 52: /* arrayElement: singleExpression  */
#line 174 "parser.y"
                       { Print("- R: singleExpression -> arrayElement"); }
#line 2439 "parser.tab.cpp"
    break;

  case 53: /* arrayElement: ELLIPSIS singleExpression  */
#line 175 "parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> arrayElement"); }
#line 2445 "parser.tab.cpp"
    break;

  case 54: /* expressionListOpt: %empty  */
#line 181 "parser.y"
                  { Print("- R: #empty# -> expressionListOpt"); }
#line 2451 "parser.tab.cpp"
    break;

  case 55: /* expressionListOpt: expressionList  */
#line 182 "parser.y"
                     { Print("- R: expressionList -> expressionListOpt"); }
#line 2457 "parser.tab.cpp"
    break;

  case 56: /* expressionList: singleExpression  */
#line 186 "parser.y"
                       { Print("- R: singleExpression -> expressionList"); }
#line 2463 "parser.tab.cpp"
    break;

  case 57: /* expressionList: expressionList ',' singleExpression  */
#line 187 "parser.y"
                                          { Print("- R: expressionList ',' singleExpression -> expressionList"); }
#line 2469 "parser.tab.cpp"
    break;

  case 58: /* singleExpression: identifier  */
#line 191 "parser.y"
                 { Print("- R: identifier -> singleExpression"); }
#line 2475 "parser.tab.cpp"
    break;

  case 59: /* singleExpression: THIS  */
#line 192 "parser.y"
           { Print("- R: THIS -> singleExpression"); }
#line 2481 "parser.tab.cpp"
    break;

  case 60: /* singleExpression: SUPER  */
#line 193 "parser.y"
            { Print("- R: SUPER -> singleExpression"); }
#line 2487 "parser.tab.cpp"
    break;

  case 61: /* singleExpression: INT_LIT  */
#line 194 "parser.y"
              { Print("- R: INT_LIT -> singleExpression"); }
#line 2493 "parser.tab.cpp"
    break;

  case 62: /* singleExpression: FLOAT_LIT  */
#line 195 "parser.y"
                { Print("- R: FLOAT_LIT -> singleExpression"); }
#line 2499 "parser.tab.cpp"
    break;

  case 63: /* singleExpression: STRING_LIT  */
#line 196 "parser.y"
                 { Print("- R: STRING_LIT -> singleExpression"); }
#line 2505 "parser.tab.cpp"
    break;

  case 64: /* singleExpression: TEMPLATE_LITERAL  */
#line 197 "parser.y"
                       { Print("- R: TEMPLATE_LITERAL -> singleExpression"); }
#line 2511 "parser.tab.cpp"
    break;

  case 65: /* singleExpression: TRUE_KW  */
#line 198 "parser.y"
              { Print("- R: TRUE_LITERAL -> singleExpression"); }
#line 2517 "parser.tab.cpp"
    break;

  case 66: /* singleExpression: FALSE_KW  */
#line 199 "parser.y"
               { Print("- R: FALSE_LITERAL -> singleExpression"); }
#line 2523 "parser.tab.cpp"
    break;

  case 67: /* singleExpression: NULL_KW  */
#line 200 "parser.y"
              { Print("- R: NULL_LITERAL -> singleExpression"); }
#line 2529 "parser.tab.cpp"
    break;

  case 68: /* singleExpression: '-' singleExpression  */
#line 201 "parser.y"
                                        { Print("- R: '-' singleExpression -> singleExpression"); }
#line 2535 "parser.tab.cpp"
    break;

  case 69: /* singleExpression: '+' singleExpression  */
#line 202 "parser.y"
                                       { Print("- R: '+'s singleExpression -> singleExpression"); }
#line 2541 "parser.tab.cpp"
    break;

  case 70: /* singleExpression: '!' singleExpression  */
#line 203 "parser.y"
                           { Print("- R: '!' singleExpression -> singleExpression"); }
#line 2547 "parser.tab.cpp"
    break;

  case 71: /* singleExpression: '~' singleExpression  */
#line 204 "parser.y"
                           { Print("- R: '~' singleExpression -> singleExpression"); }
#line 2553 "parser.tab.cpp"
    break;

  case 72: /* singleExpression: singleExpression OPERATOR_INCREMENT  */
#line 205 "parser.y"
                                                               { Print("- R: singleExpression OPERATOR_INCREMENT -> singleExpression"); }
#line 2559 "parser.tab.cpp"
    break;

  case 73: /* singleExpression: singleExpression OPERATOR_DECREMENT  */
#line 206 "parser.y"
                                                               { Print("- R: singleExpression OPERATOR_DECREMENT -> singleExpression"); }
#line 2565 "parser.tab.cpp"
    break;

  case 74: /* singleExpression: ENDL_OPERATOR_INCREMENT singleExpression  */
#line 207 "parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 2571 "parser.tab.cpp"
    break;

  case 75: /* singleExpression: ENDL_OPERATOR_DECREMENT singleExpression  */
#line 208 "parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 2577 "parser.tab.cpp"
    break;

  case 76: /* singleExpression: OPERATOR_INCREMENT singleExpression  */
#line 209 "parser.y"
                                                               { Print("- R: OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 2583 "parser.tab.cpp"
    break;

  case 77: /* singleExpression: OPERATOR_DECREMENT singleExpression  */
#line 210 "parser.y"
                                                               { Print("- R: OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 2589 "parser.tab.cpp"
    break;

  case 78: /* singleExpression: singleExpression '+' singleExpression  */
#line 211 "parser.y"
                                            { Print("- R: singleExpression '+' singleExpression -> singleExpression"); }
#line 2595 "parser.tab.cpp"
    break;

  case 79: /* singleExpression: singleExpression '-' singleExpression  */
#line 212 "parser.y"
                                            { Print("- R: singleExpression '-' singleExpression -> singleExpression"); }
#line 2601 "parser.tab.cpp"
    break;

  case 80: /* singleExpression: singleExpression '*' singleExpression  */
#line 213 "parser.y"
                                            { Print("- R: singleExpression '*' singleExpression -> singleExpression"); }
#line 2607 "parser.tab.cpp"
    break;

  case 81: /* singleExpression: singleExpression '/' singleExpression  */
#line 214 "parser.y"
                                            { Print("- R: singleExpression '/' singleExpression -> singleExpression"); }
#line 2613 "parser.tab.cpp"
    break;

  case 82: /* singleExpression: singleExpression '%' singleExpression  */
#line 215 "parser.y"
                                            { Print("- R: singleExpression '%' singleExpression -> singleExpression"); }
#line 2619 "parser.tab.cpp"
    break;

  case 83: /* singleExpression: singleExpression '<' singleExpression  */
#line 216 "parser.y"
                                            { Print("- R: singleExpression '<' singleExpression -> singleExpression"); }
#line 2625 "parser.tab.cpp"
    break;

  case 84: /* singleExpression: singleExpression '>' singleExpression  */
#line 217 "parser.y"
                                            { Print("- R: singleExpression '>' singleExpression -> singleExpression"); }
#line 2631 "parser.tab.cpp"
    break;

  case 85: /* singleExpression: singleExpression OPERATOR_POWER singleExpression  */
#line 218 "parser.y"
                                                       { Print("- R: singleExpression OPERATOR_POWER singleExpression -> singleExpression"); }
#line 2637 "parser.tab.cpp"
    break;

  case 86: /* singleExpression: singleExpression OPERATOR_EQUAL singleExpression  */
#line 219 "parser.y"
                                                       { Print("- R: singleExpression OPERATOR_EQUAL singleExpression -> singleExpression"); }
#line 2643 "parser.tab.cpp"
    break;

  case 87: /* singleExpression: singleExpression OPERATOR_NOT_EQUAL singleExpression  */
#line 220 "parser.y"
                                                           { Print("- R: singleExpression OPERATOR_NOT_EQUAL singleExpression -> singleExpression"); }
#line 2649 "parser.tab.cpp"
    break;

  case 88: /* singleExpression: singleExpression OPERATOR_STRICT_EQUAL singleExpression  */
#line 221 "parser.y"
                                                              { Print("- R: singleExpression OPERATOR_STRICT_EQUAL singleExpression -> singleExpression"); }
#line 2655 "parser.tab.cpp"
    break;

  case 89: /* singleExpression: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression  */
#line 222 "parser.y"
                                                                  { Print("- R: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression -> singleExpression"); }
#line 2661 "parser.tab.cpp"
    break;

  case 90: /* singleExpression: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression  */
#line 223 "parser.y"
                                                                 { Print("- R: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression -> singleExpression"); }
#line 2667 "parser.tab.cpp"
    break;

  case 91: /* singleExpression: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression  */
#line 224 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression -> singleExpression"); }
#line 2673 "parser.tab.cpp"
    break;

  case 92: /* singleExpression: singleExpression '=' singleExpression  */
#line 225 "parser.y"
                                            { Print("- R: singleExpression '=' singleExpression -> singleExpression"); }
#line 2679 "parser.tab.cpp"
    break;

  case 93: /* singleExpression: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression  */
#line 226 "parser.y"
                                                                 { Print("- R: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression -> singleExpression"); }
#line 2685 "parser.tab.cpp"
    break;

  case 94: /* singleExpression: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression  */
#line 227 "parser.y"
                                                               { Print("- R: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression -> singleExpression"); }
#line 2691 "parser.tab.cpp"
    break;

  case 95: /* singleExpression: singleExpression OPERATOR_ASSIGN_MOD singleExpression  */
#line 228 "parser.y"
                                                            { Print("- R: singleExpression OPERATOR_ASSIGN_MOD singleExpression -> singleExpression"); }
#line 2697 "parser.tab.cpp"
    break;

  case 96: /* singleExpression: singleExpression OPERATOR_ASSIGN_PLUS singleExpression  */
#line 229 "parser.y"
                                                             { Print("- R: singleExpression OPERATOR_ASSIGN_PLUS singleExpression -> singleExpression"); }
#line 2703 "parser.tab.cpp"
    break;

  case 97: /* singleExpression: singleExpression OPERATOR_ASSIGN_MINUS singleExpression  */
#line 230 "parser.y"
                                                              { Print("- R: singleExpression OPERATOR_ASSIGN_MINUS singleExpression -> singleExpression"); }
#line 2709 "parser.tab.cpp"
    break;

  case 98: /* singleExpression: singleExpression OPERATOR_ASSIGN_SHIFT_LEFT singleExpression  */
#line 231 "parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_SHIFT_LEFT singleExpression -> singleExpression"); }
#line 2715 "parser.tab.cpp"
    break;

  case 99: /* singleExpression: singleExpression OPERATOR_ASSIGN_SHIFT_RIGHT singleExpression  */
#line 232 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 2721 "parser.tab.cpp"
    break;

  case 100: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_AND singleExpression  */
#line 233 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_AND singleExpression -> singleExpression"); }
#line 2727 "parser.tab.cpp"
    break;

  case 101: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_XOR singleExpression  */
#line 234 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_XOR singleExpression -> singleExpression"); }
#line 2733 "parser.tab.cpp"
    break;

  case 102: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_OR singleExpression  */
#line 235 "parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_OR singleExpression -> singleExpression"); }
#line 2739 "parser.tab.cpp"
    break;

  case 103: /* singleExpression: singleExpression OPERATOR_ASSIGN_POWER singleExpression  */
#line 236 "parser.y"
                                                              { Print("- R: singleExpression OPERATOR_ASSIGN_POWER singleExpression -> singleExpression"); }
#line 2745 "parser.tab.cpp"
    break;

  case 104: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression  */
#line 237 "parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression -> singleExpression"); }
#line 2751 "parser.tab.cpp"
    break;

  case 105: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression  */
#line 238 "parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression -> singleExpression"); }
#line 2757 "parser.tab.cpp"
    break;

  case 106: /* singleExpression: singleExpression OPERATOR_ASSIGN_NULLISH_COALESCING singleExpression  */
#line 239 "parser.y"
                                                                           { Print("- R: singleExpression OPERATOR_ASSIGN_NULLISH_COALESCING singleExpression -> singleExpression"); }
#line 2763 "parser.tab.cpp"
    break;

  case 107: /* singleExpression: singleExpression OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT singleExpression  */
#line 240 "parser.y"
                                                                             { Print("- R: singleExpression OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 2769 "parser.tab.cpp"
    break;

  case 108: /* singleExpression: singleExpression OPERATOR_LOGICAL_OR singleExpression  */
#line 241 "parser.y"
                                                            { Print("- R: singleExpression OPERATOR_LOGICAL_OR singleExpression -> singleExpression"); }
#line 2775 "parser.tab.cpp"
    break;

  case 109: /* singleExpression: singleExpression OPERATOR_LOGICAL_AND singleExpression  */
#line 242 "parser.y"
                                                             { Print("- R: singleExpression OPERATOR_LOGICAL_AND singleExpression -> singleExpression"); }
#line 2781 "parser.tab.cpp"
    break;

  case 110: /* singleExpression: singleExpression '|' singleExpression  */
#line 243 "parser.y"
                                            { Print("- R: singleExpression '|' singleExpression -> singleExpression"); }
#line 2787 "parser.tab.cpp"
    break;

  case 111: /* singleExpression: singleExpression '^' singleExpression  */
#line 244 "parser.y"
                                            { Print("- R: singleExpression '^' singleExpression -> singleExpression"); }
#line 2793 "parser.tab.cpp"
    break;

  case 112: /* singleExpression: singleExpression '&' singleExpression  */
#line 245 "parser.y"
                                            { Print("- R: singleExpression '&' singleExpression -> singleExpression"); }
#line 2799 "parser.tab.cpp"
    break;

  case 113: /* singleExpression: singleExpression OPERATOR_SHIFT_LEFT singleExpression  */
#line 246 "parser.y"
                                                            { Print("- R: singleExpression OPERATOR_SHIFT_LEFT singleExpression -> singleExpression"); }
#line 2805 "parser.tab.cpp"
    break;

  case 114: /* singleExpression: singleExpression OPERATOR_SHIFT_RIGHT singleExpression  */
#line 247 "parser.y"
                                                             { Print("- R: singleExpression OPERATOR_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 2811 "parser.tab.cpp"
    break;

  case 115: /* singleExpression: singleExpression OPERATOR_UNSIGNED_SHIFT_RIGHT singleExpression  */
#line 248 "parser.y"
                                                                      { Print("- R: singleExpression OPERATOR_UNSIGNED_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 2817 "parser.tab.cpp"
    break;

  case 116: /* singleExpression: singleExpression INSTANCEOF singleExpression  */
#line 250 "parser.y"
                                                   { Print("- R: singleExpression INSTANCEOF singleExpression -> singleExpression"); }
#line 2823 "parser.tab.cpp"
    break;

  case 117: /* singleExpression: singleExpression IN singleExpression  */
#line 251 "parser.y"
                                           { Print("- R: singleExpression IN singleExpression -> singleExpression"); }
#line 2829 "parser.tab.cpp"
    break;

  case 118: /* singleExpression: singleExpression TEMPLATE_LITERAL  */
#line 253 "parser.y"
                                        { Print("- R: singleExpression TEMPLATE_LITERAL -> singleExpression"); }
#line 2835 "parser.tab.cpp"
    break;

  case 119: /* singleExpression: singleExpression '?' singleExpression ':' singleExpression  */
#line 254 "parser.y"
                                                                 { Print("- R: singleExpression '?' singleExpression ':' singleExpression -> singleExpression"); }
#line 2841 "parser.tab.cpp"
    break;

  case 120: /* singleExpression: '(' expressionList ')'  */
#line 256 "parser.y"
                             { Print("- R: '(' expressionList ')' -> singleExpression"); }
#line 2847 "parser.tab.cpp"
    break;

  case 121: /* singleExpression: singleExpression arguments  */
#line 258 "parser.y"
                                 { Print("- R: singleExpression arguments -> singleExpression"); }
#line 2853 "parser.tab.cpp"
    break;

  case 122: /* singleExpression: singleExpression '.' identifier  */
#line 259 "parser.y"
                                      { Print("- R: singleExpression '.' ID -> singleExpression"); }
#line 2859 "parser.tab.cpp"
    break;

  case 123: /* singleExpression: arrayLiteral  */
#line 261 "parser.y"
                   { Print("- R: arrayLiteral -> singleExpression"); }
#line 2865 "parser.tab.cpp"
    break;

  case 124: /* singleExpression: singleExpression '[' expressionList ']'  */
#line 262 "parser.y"
                                              { Print("- R: singleExpression '[' singleExpression ']' -> singleExpression"); }
#line 2871 "parser.tab.cpp"
    break;

  case 125: /* singleExpression: singleExpression ENDL_BRACKET_OPEN expressionList ']'  */
#line 263 "parser.y"
                                                            { Print("- R: singleExpression ENDL_BRACKET_OPEN singleExpression ']' -> singleExpression"); }
#line 2877 "parser.tab.cpp"
    break;

  case 126: /* singleExpression: NEW singleExpression  */
#line 265 "parser.y"
                           { Print("- R: NEW singleExpression -> singleExpression"); }
#line 2883 "parser.tab.cpp"
    break;

  case 127: /* arguments: '(' ')'  */
#line 269 "parser.y"
              { Print("- R: '(' ')' -> arguments"); }
#line 2889 "parser.tab.cpp"
    break;

  case 128: /* arguments: '(' argumentList ')'  */
#line 270 "parser.y"
                           { Print("- R: '(' argumentList ')' -> arguments"); }
#line 2895 "parser.tab.cpp"
    break;

  case 129: /* arguments: '(' argumentList ',' ')'  */
#line 271 "parser.y"
                               { Print("- R: '(' argumentList ',' ') -> arguments"); }
#line 2901 "parser.tab.cpp"
    break;

  case 130: /* argumentList: argument  */
#line 275 "parser.y"
               { Print("- R: argument -> argumentList"); }
#line 2907 "parser.tab.cpp"
    break;

  case 131: /* argumentList: argumentList ',' arguments  */
#line 276 "parser.y"
                                 { Print("- R: argumentList ',' arguments -> argumentList"); }
#line 2913 "parser.tab.cpp"
    break;

  case 132: /* argument: singleExpression  */
#line 280 "parser.y"
                       { Print("- R: singleExpression -> argument"); }
#line 2919 "parser.tab.cpp"
    break;

  case 133: /* argument: ELLIPSIS singleExpression  */
#line 281 "parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> argument"); }
#line 2925 "parser.tab.cpp"
    break;

  case 134: /* varStatement: varModifier varDeclarationList  */
#line 287 "parser.y"
                                     { Print("- R: varModifier varDeclarationList -> varStatement"); }
#line 2931 "parser.tab.cpp"
    break;

  case 135: /* varDeclarationList: varDeclaration  */
#line 291 "parser.y"
                     { Print("- R: varDeclaration -> argument"); }
#line 2937 "parser.tab.cpp"
    break;

  case 136: /* varDeclarationList: varDeclarationList ',' varDeclaration  */
#line 292 "parser.y"
                                            { Print("- R: varDeclarationList ',' varDeclaration -> varDeclarationList"); }
#line 2943 "parser.tab.cpp"
    break;

  case 137: /* varDeclaration: identifier  */
#line 296 "parser.y"
                 { Print("- R: identifier -> varDeclaration"); }
#line 2949 "parser.tab.cpp"
    break;

  case 138: /* varDeclaration: identifier typeAnnotation  */
#line 297 "parser.y"
                                { Print("- R: identifier typeAnnotation -> varDeclaration"); }
#line 2955 "parser.tab.cpp"
    break;

  case 139: /* varDeclaration: identifier '=' singleExpression  */
#line 298 "parser.y"
                                      { Print("- R: identifier '=' singleExpression -> varDeclaration"); }
#line 2961 "parser.tab.cpp"
    break;

  case 140: /* varDeclaration: identifier typeAnnotation '=' singleExpression  */
#line 299 "parser.y"
                                                     { Print("- R: identifier typeAnnotation '=' singleExpression -> varDeclaration"); }
#line 2967 "parser.tab.cpp"
    break;

  case 141: /* varModifier: VAR  */
#line 303 "parser.y"
          { Print("- R: VAR -> varModifier"); }
#line 2973 "parser.tab.cpp"
    break;

  case 142: /* varModifier: LET  */
#line 304 "parser.y"
          { Print("- R: LET -> varModifier"); }
#line 2979 "parser.tab.cpp"
    break;

  case 143: /* varModifier: CONST  */
#line 305 "parser.y"
            { Print("- R: CONST -> varModifier"); }
#line 2985 "parser.tab.cpp"
    break;

  case 144: /* ifStatement: IF '(' expressionList ')' statementListItem  */
#line 311 "parser.y"
                                                                     { Print("- R:  IF '(' expressionList ')' statementListItem -> ifStatement"); }
#line 2991 "parser.tab.cpp"
    break;

  case 145: /* ifStatement: IF '(' expressionList ')' statementListItem ELSE statementListItem  */
#line 312 "parser.y"
                                                                         { Print("- R: IF '(' expressionList ')' statementListItem ELSE statementListItem -> ifStatement"); }
#line 2997 "parser.tab.cpp"
    break;

  case 146: /* $@1: %empty  */
#line 316 "parser.y"
                                                        { doWhileASI(); }
#line 3003 "parser.tab.cpp"
    break;

  case 147: /* iterationStatement: DO statementListItem WHILE '(' expressionList ')' $@1 statementSep  */
#line 316 "parser.y"
                                                                                       { Print("- R: DO statementListItem WHILE '(' expressionList ')' statementSep -> iterationStatement"); }
#line 3009 "parser.tab.cpp"
    break;

  case 148: /* iterationStatement: WHILE '(' expressionList ')' statementListItem  */
#line 317 "parser.y"
                                                     { Print("- R: WHILE '(' expressionList ')' statementListItem -> iterationStatement"); }
#line 3015 "parser.tab.cpp"
    break;

  case 149: /* iterationStatement: FOR '(' expressionListOpt ';' expressionListOpt ';' expressionListOpt ')' statementListItem  */
#line 318 "parser.y"
                                                                                                  { Print("- R: FOR '(' expressionListOpt ';' expressionListOpt ';' expressionListOpt ')' statementListItem -> iterationStatement"); }
#line 3021 "parser.tab.cpp"
    break;

  case 150: /* iterationStatement: FOR '(' varModifier varDeclarationList ';' expressionListOpt ';' expressionListOpt ')' statementListItem  */
#line 319 "parser.y"
                                                                                                               { Print("- R: FOR '(' varModifier varDeclarationList ';' expressionListOpt ';' expressionListOpt ')' statementListItem -> iterationStatement"); }
#line 3027 "parser.tab.cpp"
    break;

  case 151: /* iterationStatement: FOR '(' singleExpression IN singleExpression ')' statementListItem  */
#line 320 "parser.y"
                                                                         { Print("- R: FOR '(' singleExpression IN singleExpression ')' statementListItem -> iterationStatement"); }
#line 3033 "parser.tab.cpp"
    break;

  case 152: /* iterationStatement: FOR '(' varModifier varDeclaration IN expressionList ')' statementListItem  */
#line 321 "parser.y"
                                                                                 { Print("- R: FOR '(' varModifier varDeclaration IN expressionList ')' statementListItem -> iterationStatement"); }
#line 3039 "parser.tab.cpp"
    break;

  case 153: /* continueStatement: CONTINUE  */
#line 325 "parser.y"
               { Print("- R: CONTINUE -> returnStatement"); }
#line 3045 "parser.tab.cpp"
    break;

  case 154: /* continueStatement: CONTINUE identifier  */
#line 326 "parser.y"
                          { Print("- R: CONTINUE identifier -> returnStatement"); }
#line 3051 "parser.tab.cpp"
    break;

  case 155: /* breakStatement: BREAK  */
#line 330 "parser.y"
             { Print("- R: BREAK -> returnStatement"); }
#line 3057 "parser.tab.cpp"
    break;

  case 156: /* breakStatement: BREAK identifier  */
#line 331 "parser.y"
                       { Print("- R: BREAK identifier -> returnStatement"); }
#line 3063 "parser.tab.cpp"
    break;

  case 157: /* returnStatement: RETURN  */
#line 335 "parser.y"
             { Print("- R: RETURN -> returnStatement"); }
#line 3069 "parser.tab.cpp"
    break;

  case 158: /* returnStatement: RETURN singleExpression  */
#line 336 "parser.y"
                              { Print("- R: RETURN singleExpression -> returnStatement"); }
#line 3075 "parser.tab.cpp"
    break;

  case 159: /* labelledStatement: identifier ':' statementListItem  */
#line 340 "parser.y"
                                       { Print("- R: identifier ':' statementListItem -> labelledStatement"); }
#line 3081 "parser.tab.cpp"
    break;

  case 160: /* blockStatement: '{' '}'  */
#line 344 "parser.y"
              { Print("- R: '{' '}' -> blockStatement"); }
#line 3087 "parser.tab.cpp"
    break;

  case 161: /* blockStatement: '{' statementList '}'  */
#line 345 "parser.y"
                            { Print("- R: '{' statementList '}' -> blockStatement"); }
#line 3093 "parser.tab.cpp"
    break;

  case 162: /* switchStatement: SWITCH '(' expressionList ')' '{' '}'  */
#line 349 "parser.y"
                                            { Print("- R: SWITCH '(' expressionList ')' '{' '}' -> switchStatement"); }
#line 3099 "parser.tab.cpp"
    break;

  case 163: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList '}'  */
#line 350 "parser.y"
                                                           { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList '}' -> switchStatement"); }
#line 3105 "parser.tab.cpp"
    break;

  case 164: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause '}'  */
#line 351 "parser.y"
                                                                         { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause '}' -> switchStatement"); }
#line 3111 "parser.tab.cpp"
    break;

  case 165: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause caseClauseList '}'  */
#line 352 "parser.y"
                                                                                        { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause caseClauseList '}' -> switchStatement"); }
#line 3117 "parser.tab.cpp"
    break;

  case 166: /* caseClauseList: caseClause  */
#line 356 "parser.y"
                 { Print("- R: caseClause -> caseClauseList"); }
#line 3123 "parser.tab.cpp"
    break;

  case 167: /* caseClauseList: caseClauseList caseClause  */
#line 357 "parser.y"
                                { Print("- R: caseClauseList caseClause -> caseClauseList"); }
#line 3129 "parser.tab.cpp"
    break;

  case 168: /* caseClause: CASE expressionList ':'  */
#line 361 "parser.y"
                              { Print("- R: CASE expressionList ':' -> caseClause"); }
#line 3135 "parser.tab.cpp"
    break;

  case 169: /* caseClause: CASE expressionList ':' statementList  */
#line 362 "parser.y"
                                            { Print("- R: CASE expressionList ':' statementList -> caseClause"); }
#line 3141 "parser.tab.cpp"
    break;

  case 170: /* defaultClause: DEFAULT ':'  */
#line 366 "parser.y"
                  { Print("- R: DEFAULT ':' -> defaultClause"); }
#line 3147 "parser.tab.cpp"
    break;

  case 171: /* defaultClause: DEFAULT ':' statementList  */
#line 367 "parser.y"
                                { Print("- R: DEFAULT ':' statementList -> defaultClause"); }
#line 3153 "parser.tab.cpp"
    break;

  case 172: /* functionDeclaration: FUNCTION identifier callSignature '{' functionBody '}'  */
#line 373 "parser.y"
                                                             { Print("- R: FUNCTION ID callSignature '{' functionBody '}' -> functionDeclaration"); }
#line 3159 "parser.tab.cpp"
    break;

  case 173: /* functionBody: %empty  */
#line 377 "parser.y"
                  { Print("- R: #empty# -> functionBody"); }
#line 3165 "parser.tab.cpp"
    break;

  case 174: /* functionBody: statementList  */
#line 378 "parser.y"
                    { Print("- R: statementList -> returnStatement"); }
#line 3171 "parser.tab.cpp"
    break;

  case 175: /* callSignature: '(' ')'  */
#line 382 "parser.y"
              { Print("- R: '(' ')' -> callSignature"); }
#line 3177 "parser.tab.cpp"
    break;

  case 176: /* callSignature: '(' ')' typeAnnotation  */
#line 383 "parser.y"
                             { Print("- R: '(' ')' typeAnnotation -> callSignature"); }
#line 3183 "parser.tab.cpp"
    break;

  case 177: /* callSignature: '(' restParameter ')'  */
#line 384 "parser.y"
                            { Print("- R: '(' restParameter ')' -> callSignature"); }
#line 3189 "parser.tab.cpp"
    break;

  case 178: /* callSignature: '(' restParameter ')' typeAnnotation  */
#line 385 "parser.y"
                                           { Print("- R: '(' restParameter ')' typeAnnotation -> callSignature"); }
#line 3195 "parser.tab.cpp"
    break;

  case 179: /* callSignature: '(' parameterList ')'  */
#line 386 "parser.y"
                            { Print("- R: '(' parameterList ')' -> callSignature"); }
#line 3201 "parser.tab.cpp"
    break;

  case 180: /* callSignature: '(' parameterList ')' typeAnnotation  */
#line 387 "parser.y"
                                           { Print("- R: '(' parameterList ')' typeAnnotation -> callSignature"); }
#line 3207 "parser.tab.cpp"
    break;

  case 181: /* callSignature: '(' parameterList ',' restParameter ')'  */
#line 388 "parser.y"
                                              { Print("- R: '(' parameterList ',' restParameter ')' -> callSignature"); }
#line 3213 "parser.tab.cpp"
    break;

  case 182: /* callSignature: '(' parameterList ',' restParameter ')' typeAnnotation  */
#line 389 "parser.y"
                                                             { Print("- R: '(' parameterList ',' restParameter ')' typeAnnotation -> callSignature"); }
#line 3219 "parser.tab.cpp"
    break;

  case 183: /* callSignature: '(' parameterList ',' ')'  */
#line 390 "parser.y"
                                { Print("- R: '(' parameterList ',' ')' -> callSignature"); }
#line 3225 "parser.tab.cpp"
    break;

  case 184: /* callSignature: '(' parameterList ',' ')' typeAnnotation  */
#line 391 "parser.y"
                                               { Print("- R: '(' parameterList ',' ')' typeAnnotation -> callSignature"); }
#line 3231 "parser.tab.cpp"
    break;

  case 185: /* parameterList: parameter  */
#line 395 "parser.y"
                { Print("- R: parameter -> parameterList"); }
#line 3237 "parser.tab.cpp"
    break;

  case 186: /* parameterList: parameterList ',' parameter  */
#line 396 "parser.y"
                                  { Print("- R: parameterList ',' parameter -> parameterList"); }
#line 3243 "parser.tab.cpp"
    break;

  case 187: /* parameter: requiredParameter  */
#line 400 "parser.y"
                        { Print("- R: requiredParameter -> parameter"); }
#line 3249 "parser.tab.cpp"
    break;

  case 188: /* parameter: optionalParameter  */
#line 401 "parser.y"
                        { Print("- R: optionalParameter -> parameter"); }
#line 3255 "parser.tab.cpp"
    break;

  case 189: /* requiredParameter: identifier  */
#line 405 "parser.y"
                 { Print("- R: ID -> requiredParameter"); }
#line 3261 "parser.tab.cpp"
    break;

  case 190: /* requiredParameter: identifier typeAnnotation  */
#line 406 "parser.y"
                                { Print("- R: ID typeAnnotation -> requiredParameter"); }
#line 3267 "parser.tab.cpp"
    break;

  case 191: /* optionalParameter: identifier '?'  */
#line 410 "parser.y"
                     { Print("- R: ID '?' -> optionalParameter"); }
#line 3273 "parser.tab.cpp"
    break;

  case 192: /* optionalParameter: identifier '?' typeAnnotation  */
#line 411 "parser.y"
                                    { Print("- R: ID '?' typeAnnotation -> optionalParameter"); }
#line 3279 "parser.tab.cpp"
    break;

  case 193: /* optionalParameter: identifier initializer  */
#line 412 "parser.y"
                             { Print("- R: ID initializer -> optionalParameter"); }
#line 3285 "parser.tab.cpp"
    break;

  case 194: /* optionalParameter: identifier typeAnnotation initializer  */
#line 413 "parser.y"
                                            { Print("- R: ID typeAnnotation initializer -> optionalParameter"); }
#line 3291 "parser.tab.cpp"
    break;

  case 195: /* restParameter: ELLIPSIS singleExpression  */
#line 417 "parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> restParameter"); }
#line 3297 "parser.tab.cpp"
    break;

  case 196: /* restParameter: ELLIPSIS singleExpression typeAnnotation  */
#line 418 "parser.y"
                                               { Print("- R: ELLIPSIS singleExpression typeAnnotation -> restParameter"); }
#line 3303 "parser.tab.cpp"
    break;


#line 3307 "parser.tab.cpp"

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

#line 466 "parser.y"



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
