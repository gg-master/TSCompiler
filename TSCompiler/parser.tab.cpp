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
#include "Tree/parsing_tree.h"
#include "Tree/nodes.h"

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

#line 100 "parser.tab.cpp"

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
  YYSYMBOL_OPTIONAL_CHAINING_OPERATOR = 97, /* OPTIONAL_CHAINING_OPERATOR  */
  YYSYMBOL_98_ = 98,                       /* '('  */
  YYSYMBOL_99_ = 99,                       /* ')'  */
  YYSYMBOL_100_ = 100,                     /* ';'  */
  YYSYMBOL_101_ = 101,                     /* '{'  */
  YYSYMBOL_102_ = 102,                     /* '}'  */
  YYSYMBOL_YYACCEPT = 103,                 /* $accept  */
  YYSYMBOL_script = 104,                   /* script  */
  YYSYMBOL_scriptElementList = 105,        /* scriptElementList  */
  YYSYMBOL_scriptElement = 106,            /* scriptElement  */
  YYSYMBOL_statementList = 107,            /* statementList  */
  YYSYMBOL_statementListItem = 108,        /* statementListItem  */
  YYSYMBOL_statementListItemWithoutEmptyStatement = 109, /* statementListItemWithoutEmptyStatement  */
  YYSYMBOL_emptyStatement = 110,           /* emptyStatement  */
  YYSYMBOL_blockStatement = 111,           /* blockStatement  */
  YYSYMBOL_type = 112,                     /* type  */
  YYSYMBOL_tupleTypeElements = 113,        /* tupleTypeElements  */
  YYSYMBOL_predefinedType = 114,           /* predefinedType  */
  YYSYMBOL_typeAnnotationOpt = 115,        /* typeAnnotationOpt  */
  YYSYMBOL_typeAnnotation = 116,           /* typeAnnotation  */
  YYSYMBOL_arrayLiteral = 117,             /* arrayLiteral  */
  YYSYMBOL_elementList = 118,              /* elementList  */
  YYSYMBOL_elementListItem = 119,          /* elementListItem  */
  YYSYMBOL_expressionStatement = 120,      /* expressionStatement  */
  YYSYMBOL_singleExpressionOpt = 121,      /* singleExpressionOpt  */
  YYSYMBOL_singleExpression = 122,         /* singleExpression  */
  YYSYMBOL_varStatement = 123,             /* varStatement  */
  YYSYMBOL_varDeclarationList = 124,       /* varDeclarationList  */
  YYSYMBOL_varDeclaration = 125,           /* varDeclaration  */
  YYSYMBOL_varModifier = 126,              /* varModifier  */
  YYSYMBOL_ifStatement = 127,              /* ifStatement  */
  YYSYMBOL_iterationStatement = 128,       /* iterationStatement  */
  YYSYMBOL_129_1 = 129,                    /* $@1  */
  YYSYMBOL_130_2 = 130,                    /* $@2  */
  YYSYMBOL_131_3 = 131,                    /* $@3  */
  YYSYMBOL_132_4 = 132,                    /* $@4  */
  YYSYMBOL_133_5 = 133,                    /* $@5  */
  YYSYMBOL_forHeader = 134,                /* forHeader  */
  YYSYMBOL_returnStatement = 135,          /* returnStatement  */
  YYSYMBOL_functionDeclaration = 136,      /* functionDeclaration  */
  YYSYMBOL_functionBody = 137,             /* functionBody  */
  YYSYMBOL_138_6 = 138,                    /* $@6  */
  YYSYMBOL_parameterList = 139,            /* parameterList  */
  YYSYMBOL_requiredParameterList = 140,    /* requiredParameterList  */
  YYSYMBOL_requiredParameter = 141,        /* requiredParameter  */
  YYSYMBOL_classDeclaration = 142,         /* classDeclaration  */
  YYSYMBOL_classHeritage = 143,            /* classHeritage  */
  YYSYMBOL_classTail = 144,                /* classTail  */
  YYSYMBOL_classElementList = 145,         /* classElementList  */
  YYSYMBOL_classElement = 146,             /* classElement  */
  YYSYMBOL_propertyName = 147,             /* propertyName  */
  YYSYMBOL_identifier = 148                /* identifier  */
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
#define YYLAST   2571

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  103
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  180
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  328

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   333


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
      98,    99,    82,    80,    53,    81,    93,    83,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    64,   100,
      75,    56,    74,    63,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    94,     2,    95,    68,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   101,    67,   102,    86,     2,     2,     2,
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
      91,    92,    96,    97
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   169,   169,   182,   183,   187,   188,   189,   190,   194,
     195,   199,   200,   201,   202,   203,   204,   211,   215,   216,
     217,   218,   219,   226,   228,   232,   244,   245,   251,   252,
     253,   254,   255,   259,   260,   261,   265,   266,   267,   268,
     269,   270,   274,   275,   279,   284,   285,   289,   294,   302,
     303,   304,   314,   318,   319,   323,   324,   325,   326,   327,
     328,   330,   331,   332,   333,   335,   336,   338,   340,   341,
     343,   344,   345,   346,   348,   349,   350,   351,   352,   353,
     355,   358,   361,   364,   367,   370,   373,   376,   379,   382,
     385,   388,   391,   394,   397,   400,   401,   403,   406,   412,
     415,   416,   422,   424,   428,   429,   430,   431,   433,   434,
     435,   437,   438,   439,   445,   446,   450,   455,   463,   468,
     476,   477,   478,   484,   490,   500,   500,   506,   512,   512,
     518,   518,   524,   524,   530,   530,   538,   544,   545,   549,
     557,   558,   558,   567,   568,   569,   573,   578,   586,   596,
     601,   609,   613,   614,   618,   619,   623,   630,   635,   642,
     649,   654,   662,   666,   667,   668,   669,   670,   671,   672,
     673,   674,   675,   676,   677,   678,   679,   680,   681,   682,
     683
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
  "']'", "ENDL_BRACKET_OPEN", "OPTIONAL_CHAINING_OPERATOR", "'('", "')'",
  "';'", "'{'", "'}'", "$accept", "script", "scriptElementList",
  "scriptElement", "statementList", "statementListItem",
  "statementListItemWithoutEmptyStatement", "emptyStatement",
  "blockStatement", "type", "tupleTypeElements", "predefinedType",
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

#define YYPACT_NINF (-235)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     412,  -235,  -235,  -235,  -235,   -85,   738,   738,   905,   -80,
     -73,  1070,  -235,  -235,  1563,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
    1563,  1563,  1563,  1563,  1563,  1563,  1563,  1563,  1563,  1563,
    -235,   608,    10,   314,  -235,  -235,  -235,  -235,  -235,  -235,
    1607,  -235,  2524,  -235,  -235,   989,  -235,  -235,  -235,   -57,
    1563,   -54,    12,    41,  1563,  -235,  -235,  1657,    30,    36,
      36,    36,    36,    36,    36,    36,   -46,  -235,  2315,   -41,
    1757,  -235,   707,  -235,  -235,  -235,  -235,  -235,  1563,  1563,
    1563,  1563,  1563,  1563,  1563,  1563,  1563,  1563,  1563,  1563,
    1563,  1563,  1563,  1563,  1563,  1563,  1563,  1563,  1563,  1563,
    1563,  1563,  1563,   738,  1563,  1563,  1563,  -235,   -43,   -50,
    -235,    -1,   -34,  2357,   738,  1153,  1809,   738,   738,   127,
     -32,  -235,   -24,  1861,  -235,  1235,  1563,  -235,  1563,  -235,
    -235,  -235,  -235,   310,   310,   310,   310,   310,   310,   310,
     310,  2173,   500,   590,   784,   784,   784,   784,   170,   170,
     170,   170,   170,   170,   -21,   -21,    36,    36,   -19,  2215,
    2265,  -235,  -235,   738,  -235,   -11,    25,  -235,  1563,  1563,
     -48,     3,  -235,  1913,   510,    20,    69,  -235,    -1,  -235,
     738,   738,    39,  -235,   209,  -235,   -56,  -235,  -235,  1563,
     905,  -235,  1965,  -235,  1563,  1317,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,   -11,   -11,   -11,    40,  -235,
    1563,    43,  2399,    87,  1563,  1563,  1399,  -235,  -235,   133,
    -235,  -235,  -235,  -235,  -235,  -235,    -1,   738,  -235,    68,
      73,   738,  -235,  -235,   738,   -47,  2017,  -235,  -235,   402,
    -235,  2069,    40,   -37,   -27,   -88,    77,  2441,  1563,  -235,
      75,  2121,  -235,   905,    72,  -235,    78,   738,    83,    86,
    1563,  -235,  -235,  1481,  -235,   -11,  -235,  -235,  -235,  -235,
      88,   905,  1563,  -235,  -235,    74,  -235,    -1,    89,    72,
      -1,  1707,    90,  -235,    40,  -235,  -235,    93,   905,  -235,
     905,    72,    72,  -235,    72,  -235,  -235,   905,  -235,  -235,
     806,  -235,  -235,  -235,  -235,   905,  -235,  -235
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     8,   120,   121,   122,     0,     0,     0,     0,     0,
       0,     0,    57,    56,     0,   164,   165,   166,   167,   177,
     178,   179,   180,   168,   169,   170,   171,   174,   175,   172,
     173,   176,    60,    58,    59,    62,    61,    63,    64,   163,
       0,     0,     0,     0,     0,     0,     0,    49,    49,     0,
      25,     0,     0,     0,     3,     5,    11,    17,   108,    12,
       0,    13,     0,    14,    15,    53,    16,     6,     7,    55,
       0,     0,     0,     0,     0,   136,   137,     0,   111,    72,
      73,    70,    71,    66,    65,    67,     0,    47,    50,     0,
       0,    26,     0,     9,     1,     4,    68,    69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,     0,     0,
     116,    42,     0,    54,     0,     0,     0,   143,     0,     0,
       0,   149,     0,     0,   138,     0,    49,    45,    51,    46,
      99,    27,    10,    98,    86,    89,    90,    87,    88,    91,
      92,     0,    93,    94,    80,    81,    82,    83,    79,    78,
      85,    84,    95,    96,    74,    75,    76,    77,   104,     0,
       0,   103,   115,     0,   114,     0,   118,    43,    53,     0,
       0,   116,   100,     0,     0,     0,   144,   146,    42,   151,
       0,     0,     0,   152,     0,   154,    42,   162,   150,     0,
       0,   112,     0,    48,     0,     0,   109,   110,   117,    36,
      38,    37,    39,    40,    41,    33,    33,     0,    44,    29,
       0,     0,    54,    96,    53,     0,     0,   101,    24,   123,
      23,    18,    19,    20,    21,    22,    42,   145,   148,     0,
       0,   143,   153,   155,   143,     0,     0,   127,   113,    97,
     105,     0,    34,     0,     0,     0,     0,   119,    53,   132,
       0,     0,   102,     0,     0,   147,     0,   143,     0,     0,
       0,   157,   125,     0,   106,     0,    31,    32,    28,    30,
       0,     0,    53,   134,   124,   141,   139,    42,     0,     0,
      42,     0,     0,   107,    35,   128,   133,     0,     0,   140,
       0,     0,     0,   156,     0,   158,   126,     0,   130,   135,
       0,   160,   161,   159,   129,     0,   142,   131
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -235,  -235,  -235,   136,  -117,    -8,  -235,  -235,     0,  -168,
     -31,  -235,  -179,  -235,  -235,   148,    51,     4,  -148,   -10,
       6,    67,  -132,   138,    13,    16,  -235,  -235,  -235,  -235,
    -235,  -235,    17,  -235,  -234,  -235,  -206,  -235,   -33,  -235,
    -235,    66,  -235,     9,  -154,     8
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    52,    53,    54,    92,    55,   239,    56,    57,   262,
     263,   229,   186,   187,    58,    86,    87,    59,   132,    60,
      61,   129,   130,    62,    63,    64,   302,   317,   325,   291,
     308,    65,    66,    67,   296,   310,   195,   196,   197,    68,
     140,   141,   204,   205,   206,    69
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      73,    77,   191,   183,    78,   183,   266,   146,   185,   280,
      94,   288,   146,    70,    71,    72,   285,   228,    74,   248,
     219,   220,   221,   138,   222,    75,   285,   255,   223,   224,
      79,    80,    81,    82,    83,    84,    85,    88,    88,    90,
     231,   135,   254,    93,   137,   278,   249,   250,   279,   147,
     184,   218,   234,   281,   149,   133,   142,   182,   286,   265,
     136,   121,   122,   185,   143,   313,   188,   274,   287,   139,
     131,   298,   123,   124,   209,   125,   126,   321,   322,   215,
     323,   230,   235,   225,   152,   226,   270,   227,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   139,   179,   180,   181,   304,   311,   246,
     290,   314,   247,   123,   124,   193,   125,   126,   145,   123,
     124,   178,   125,   126,   266,   212,    88,   251,   153,   200,
     201,   273,   131,   268,   307,   198,   199,   207,    15,    16,
      17,    18,    19,   202,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,   276,   119,   120,   121,
     122,   277,   289,   295,    39,   292,   309,   297,   232,   233,
     123,   124,   299,   125,   126,   300,   269,   305,   312,    95,
     316,   131,   318,   320,   240,   264,    89,   213,   241,   256,
     242,   190,   257,   134,   259,   261,   208,   243,   207,   207,
     244,   245,   207,   253,   275,     0,     0,     0,     0,     0,
     267,   200,   201,     0,   232,   271,   153,     0,     0,   203,
      15,    16,    17,    18,    19,   202,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     0,     0,
     119,   120,   121,   122,     0,   198,    39,     0,   232,   198,
       0,     0,   198,   123,   124,   294,   125,   126,     0,     0,
     301,     0,     0,   153,     0,     0,     0,     0,     0,     0,
       0,     0,   232,   306,     0,   198,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     319,     0,    93,     0,     0,     0,     0,     0,     0,   324,
       0,   252,   152,     0,    -2,     1,     0,   327,     2,     3,
       4,     5,     0,     6,     7,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       0,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    99,   100,   101,   102,
     103,   104,   105,   106,     0,   107,   108,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,    44,    45,     0,     0,     0,    46,
       0,     0,     0,   123,   124,     0,   125,   126,    47,     0,
      48,     0,    49,     1,    50,    51,     2,     3,     4,     5,
       0,     6,     7,     0,     0,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     0,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,     0,     0,   107,   108,     0,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,     0,     0,     0,     0,
       0,     0,    44,    45,     0,   123,   124,    46,   125,   126,
       0,     0,     0,     0,     0,     0,    47,     0,    48,     0,
      49,   238,    50,    51,     2,     3,     4,     5,     0,     0,
       0,     0,     0,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,     0,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,     0,     0,     0,   108,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,     0,     0,     0,     0,     0,     0,
      44,    45,     0,   123,   124,    46,   125,   126,     0,     0,
       0,     0,     0,     0,    47,     0,    48,     0,    49,     0,
       0,    51,     2,     3,     4,     5,     0,     0,     0,     0,
       0,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,     0,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   123,   124,     0,   125,   126,    44,    45,
       0,     0,     0,    46,     0,     0,     0,     0,     0,     0,
       0,     0,    47,     0,    48,     0,    49,     0,    50,    51,
      91,     2,     3,     4,     5,     0,     0,     0,     0,     0,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     0,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    15,
      16,    17,    18,    19,     0,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     0,     0,     0,
       0,     0,     0,     0,     0,    39,     0,    44,    45,     0,
       0,     0,    46,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,    48,     0,    49,     0,    50,    51,   151,
       2,     3,     4,     5,     0,     0,     0,     0,     0,     0,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     0,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   123,   124,     0,
     125,   126,     0,     0,     0,     0,    44,    45,     0,     0,
       0,    46,     0,     0,     0,     0,     0,     0,     0,     0,
      47,     0,    48,     0,    49,     0,    50,    51,   326,     2,
       3,     4,     5,     0,     0,     0,     0,     0,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    44,    45,     0,     0,     0,
      46,     0,     0,     2,     3,     4,     0,     0,     0,    47,
       0,    48,     0,    49,     0,    50,    51,    12,    13,    14,
      15,    16,    17,    18,    19,     0,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
      45,     0,     0,     0,    46,     0,     0,     0,     0,     0,
       0,     0,     0,    47,     0,    48,     0,    49,    12,    13,
      14,    15,    16,    17,    18,    19,     0,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,    45,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     0,    48,     0,    49,     0,
      76,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,    45,     0,     0,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     0,    48,
       0,    49,   192,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    44,    45,     0,     0,     0,
      46,     0,     0,     0,     0,     0,     0,     0,     0,    47,
       0,    48,     0,    49,   211,    12,    13,    14,    15,    16,
      17,    18,    19,     0,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,    45,     0,
       0,     0,    46,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,    48,     0,    49,   260,    12,    13,    14,
      15,    16,    17,    18,    19,     0,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
      45,     0,     0,     0,    46,     0,     0,     0,     0,     0,
       0,     0,     0,    47,     0,    48,     0,    49,   272,    12,
      13,    14,    15,    16,    17,    18,    19,     0,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    44,    45,     0,     0,     0,    46,     0,     0,     0,
       0,     0,     0,     0,     0,    47,     0,    48,     0,    49,
     303,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,    45,     0,     0,     0,    46,     0,
       0,     0,     0,     0,     0,    96,    97,    47,     0,    48,
      98,    49,     0,    99,   100,   101,   102,   103,   104,   105,
     106,     0,   107,   108,     0,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     123,   124,     0,   125,   126,    96,    97,   127,     0,     0,
      98,     0,     0,    99,   100,   101,   102,   103,   104,   105,
     106,     0,   107,   108,     0,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     123,   124,     0,   125,   126,    96,    97,   144,     0,     0,
      98,     0,     0,    99,   100,   101,   102,   103,   104,   105,
     106,     0,   107,   108,     0,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     123,   124,     0,   125,   126,    96,    97,   315,     0,     0,
      98,     0,     0,    99,   100,   101,   102,   103,   104,   105,
     106,     0,   107,   108,     0,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     123,   124,     0,   125,   126,     0,   150,    96,    97,     0,
       0,     0,    98,     0,     0,    99,   100,   101,   102,   103,
     104,   105,   106,     0,   107,   108,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   123,   124,     0,   125,   126,     0,   194,    96,
      97,     0,     0,     0,    98,     0,     0,    99,   100,   101,
     102,   103,   104,   105,   106,     0,   107,   108,     0,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   123,   124,     0,   125,   126,     0,
     210,    96,    97,     0,     0,     0,   236,     0,     0,    99,
     100,   101,   102,   103,   104,   105,   106,     0,   107,   108,
       0,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   123,   124,     0,   125,
     126,     0,   237,    96,    97,     0,     0,     0,    98,     0,
       0,    99,   100,   101,   102,   103,   104,   105,   106,     0,
     107,   108,     0,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   123,   124,
       0,   125,   126,     0,   258,    96,    97,     0,     0,     0,
      98,     0,     0,    99,   100,   101,   102,   103,   104,   105,
     106,     0,   107,   108,     0,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     123,   124,     0,   125,   126,     0,   282,    96,    97,     0,
       0,     0,   283,     0,     0,    99,   100,   101,   102,   103,
     104,   105,   106,     0,   107,   108,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   123,   124,     0,   125,   126,     0,   284,    96,
      97,     0,     0,     0,    98,     0,     0,    99,   100,   101,
     102,   103,   104,   105,   106,     0,   107,   108,     0,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   123,   124,     0,   125,   126,     0,
     293,    96,    97,     0,     0,     0,    98,     0,     0,    99,
     100,   101,   102,   103,   104,   105,   106,   214,   107,   108,
       0,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,     0,     0,     0,
       0,     0,     0,    96,    97,     0,   123,   124,    98,   125,
     126,    99,   100,   101,   102,   103,   104,   105,   106,     0,
     107,   108,     0,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   123,   124,
     216,   125,   126,    96,    97,     0,     0,     0,    98,     0,
       0,    99,   100,   101,   102,   103,   104,   105,   106,     0,
     107,   108,     0,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   123,   124,
     217,   125,   126,    96,    97,     0,     0,     0,   148,     0,
       0,    99,   100,   101,   102,   103,   104,   105,   106,     0,
     107,   108,     0,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,     0,
       0,     0,     0,     0,     0,    96,    97,     0,   123,   124,
      98,   125,   126,    99,   100,   101,   102,   103,   104,   105,
     106,     0,   107,   108,     0,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   189,   119,   120,   121,
     122,     0,     0,     0,     0,     0,     0,    96,    97,     0,
     123,   124,    98,   125,   126,    99,   100,   101,   102,   103,
     104,   105,   106,     0,   107,   108,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,     0,     0,     0,     0,     0,     0,    96,
      97,     0,   123,   124,     0,   125,   126,    99,   100,   101,
     102,   103,   104,   105,   106,     0,   107,   108,     0,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   128,     0,     0,     0,     0,
       0,     0,     0,     0,   123,   124,     0,   125,   126,     0,
       0,     0,     0,     0,     0,    15,    16,    17,    18,    19,
       0,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     0,     0,     0,     0,     0,     0,     0,
       0,    39
};

static const yytype_int16 yycheck[] =
{
       8,    11,   134,    53,    14,    53,    94,    53,    64,    56,
       0,    99,    53,    98,     6,     7,    53,   185,    98,   198,
      31,    32,    33,    11,    35,    98,    53,   206,    39,    40,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
     188,    98,    98,    51,    98,   251,   200,   201,   254,    95,
     100,   183,   100,   100,    95,    65,    15,   100,    95,   227,
      70,    82,    83,    64,    74,   299,   100,   246,    95,   101,
      62,   277,    93,    94,    98,    96,    97,   311,   312,    98,
     314,    56,    79,    94,    92,    96,   234,    98,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   101,   124,   125,   126,   285,   297,    99,
     268,   300,    53,    93,    94,   135,    96,    97,    98,    93,
      94,   123,    96,    97,    94,   145,   146,    98,   148,    12,
      13,     8,   134,   100,   292,   137,   138,   139,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    98,    80,    81,    82,
      83,    98,    95,   101,    47,   100,   102,    99,   188,   189,
      93,    94,    99,    96,    97,    99,    99,    99,    99,    53,
     100,   183,    99,   310,   194,   226,    48,   146,   194,   209,
     194,   134,   210,    65,   214,   215,   140,   194,   200,   201,
     194,   194,   204,   204,   247,    -1,    -1,    -1,    -1,    -1,
     230,    12,    13,    -1,   234,   235,   236,    -1,    -1,   102,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      80,    81,    82,    83,    -1,   247,    47,    -1,   268,   251,
      -1,    -1,   254,    93,    94,   273,    96,    97,    -1,    -1,
     280,    -1,    -1,   283,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   292,   291,    -1,   277,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     308,    -1,   310,    -1,    -1,    -1,    -1,    -1,    -1,   317,
      -1,   102,   320,    -1,     0,     1,    -1,   325,     4,     5,
       6,     7,    -1,     9,    10,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    80,    81,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    93,    94,    -1,    96,    97,    94,    -1,
      96,    -1,    98,     1,   100,   101,     4,     5,     6,     7,
      -1,     9,    10,    -1,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    -1,    -1,    65,    66,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    81,    -1,    93,    94,    85,    96,    97,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    96,    -1,
      98,     1,   100,   101,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    81,    -1,    93,    94,    85,    96,    97,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    -1,    96,    -1,    98,    -1,
      -1,   101,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    -1,    96,    97,    80,    81,
      -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    -1,    96,    -1,    98,    -1,   100,   101,
     102,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    21,
      22,    23,    24,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    80,    81,    -1,
      -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    -1,    96,    -1,    98,    -1,   100,   101,   102,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    -1,
      96,    97,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    -1,    96,    -1,    98,    -1,   100,   101,   102,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,
      85,    -1,    -1,     4,     5,     6,    -1,    -1,    -1,    94,
      -1,    96,    -1,    98,    -1,   100,   101,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      81,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    -1,    96,    -1,    98,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    81,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    -1,    96,    -1,    98,    -1,
     100,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    96,
      -1,    98,    99,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      -1,    96,    -1,    98,    99,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,
      -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    -1,    96,    -1,    98,    99,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      81,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    -1,    96,    -1,    98,    99,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    81,    -1,    -1,    -1,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    -1,    96,    -1,    98,
      99,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    94,    -1,    96,
      53,    98,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    -1,    96,    97,    48,    49,   100,    -1,    -1,
      53,    -1,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    -1,    96,    97,    48,    49,   100,    -1,    -1,
      53,    -1,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    -1,    96,    97,    48,    49,   100,    -1,    -1,
      53,    -1,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    -1,    96,    97,    -1,    99,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    -1,    96,    97,    -1,    99,    48,
      49,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    94,    -1,    96,    97,    -1,
      99,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    65,    66,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    -1,    96,
      97,    -1,    99,    48,    49,    -1,    -1,    -1,    53,    -1,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    66,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      -1,    96,    97,    -1,    99,    48,    49,    -1,    -1,    -1,
      53,    -1,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    -1,    96,    97,    -1,    99,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    -1,    96,    97,    -1,    99,    48,
      49,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    94,    -1,    96,    97,    -1,
      99,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    -1,    93,    94,    53,    96,
      97,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    66,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    97,    48,    49,    -1,    -1,    -1,    53,    -1,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    66,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    97,    48,    49,    -1,    -1,    -1,    53,    -1,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    66,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    93,    94,
      53,    96,    97,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,
      93,    94,    53,    96,    97,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    -1,    93,    94,    -1,    96,    97,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    94,    -1,    96,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     4,     5,     6,     7,     9,    10,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    80,    81,    85,    94,    96,    98,
     100,   101,   104,   105,   106,   108,   110,   111,   117,   120,
     122,   123,   126,   127,   128,   134,   135,   136,   142,   148,
      98,   148,   148,   108,    98,    98,   100,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   118,   119,   122,   118,
     122,   102,   107,   108,     0,   106,    48,    49,    53,    56,
      57,    58,    59,    60,    61,    62,    63,    65,    66,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    93,    94,    96,    97,   100,     1,   124,
     125,   148,   121,   122,   126,    98,   122,    98,    11,   101,
     143,   144,    15,   122,   100,    98,    53,    95,    53,    95,
      99,   102,   108,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   148,   122,
     122,   122,   100,    53,   100,    64,   115,   116,   100,    79,
     124,   125,    99,   122,    99,   139,   140,   141,   148,   148,
      12,    13,    26,   102,   145,   146,   147,   148,   144,    98,
      99,    99,   122,   119,    64,    98,    95,    95,   125,    31,
      32,    33,    35,    39,    40,    94,    96,    98,   112,   114,
      56,   121,   122,   122,   100,    79,    53,    99,     1,   109,
     111,   120,   123,   127,   128,   135,    99,    53,   115,   147,
     147,    98,   102,   146,    98,   115,   122,   108,    99,   122,
      99,   122,   112,   113,   113,   112,    94,   122,   100,    99,
     121,   122,    99,     8,   115,   141,    98,    98,   139,   139,
      56,   100,    99,    53,    99,    53,    95,    95,    99,    95,
     121,   132,   100,    99,   108,   101,   137,    99,   139,    99,
      99,   122,   129,    99,   112,    99,   108,   121,   133,   102,
     138,   115,    99,   137,   115,   100,   100,   130,    99,   108,
     107,   137,   137,   137,   108,   131,   102,   108
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   103,   104,   105,   105,   106,   106,   106,   106,   107,
     107,   108,   108,   108,   108,   108,   108,   108,   109,   109,
     109,   109,   109,   109,   109,   110,   111,   111,   112,   112,
     112,   112,   112,   113,   113,   113,   114,   114,   114,   114,
     114,   114,   115,   115,   116,   117,   117,   118,   118,   119,
     119,   119,   120,   121,   121,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   123,   123,   124,   124,   125,   125,
     126,   126,   126,   127,   127,   129,   128,   128,   130,   128,
     131,   128,   132,   128,   133,   128,   134,   135,   135,   136,
     137,   138,   137,   139,   139,   139,   140,   140,   141,   142,
     142,   143,   144,   144,   145,   145,   146,   146,   146,   146,
     146,   146,   147,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     3,     1,
       3,     3,     3,     0,     1,     3,     1,     1,     1,     1,
       1,     1,     0,     1,     2,     3,     3,     1,     3,     0,
       1,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     5,     3,     3,
       3,     4,     5,     3,     3,     5,     6,     7,     1,     4,
       4,     2,     4,     5,     3,     3,     1,     3,     2,     4,
       1,     1,     1,     5,     7,     0,     8,     5,     0,     9,
       0,    10,     0,     7,     0,     8,     2,     2,     3,     7,
       2,     0,     4,     0,     1,     2,     1,     3,     2,     3,
       4,     2,     2,     3,     1,     2,     5,     3,     5,     6,
       6,     6,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
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
#line 170 "parser.y"
        { 
            if ( syntaxErrorCounter > 0 ) {
                PrintError("Found " + std::to_string(syntaxErrorCounter) + " syntax errors. Fix them and rerun.");
                exit(1);
            }
            Print("- R: scriptElementList -> script"); 
        
            (yyval.tsscriptNode) = root = createTSScriptNode((yyvsp[0].tsscriptElementListNode));
        }
#line 2328 "parser.tab.cpp"
    break;

  case 3: /* scriptElementList: scriptElement  */
#line 182 "parser.y"
                                        { Print("- R: scriptElement -> scriptElementList"); (yyval.tsscriptElementListNode) = createTSElementListNode((yyvsp[0].tsscriptElementNode)); }
#line 2334 "parser.tab.cpp"
    break;

  case 4: /* scriptElementList: scriptElementList scriptElement  */
#line 183 "parser.y"
                                        { Print("- R: scriptElementList scriptElement -> scriptElementList"); (yyval.tsscriptElementListNode) = addTSElementNodeToList((yyvsp[-1].tsscriptElementListNode), (yyvsp[0].tsscriptElementNode)); }
#line 2340 "parser.tab.cpp"
    break;

  case 5: /* scriptElement: statementListItem  */
#line 187 "parser.y"
                            { Print("- R: statementListItem -> scriptElement"); (yyval.tsscriptElementNode) = createElementFromStatement((yyvsp[0].stmtNode)); }
#line 2346 "parser.tab.cpp"
    break;

  case 6: /* scriptElement: functionDeclaration  */
#line 188 "parser.y"
                            { Print("- R: functionDeclaration -> scriptElement"); (yyval.tsscriptElementNode) = createElementFromFuncDeclaration((yyvsp[0].funcDeclarationNode)); }
#line 2352 "parser.tab.cpp"
    break;

  case 7: /* scriptElement: classDeclaration  */
#line 189 "parser.y"
                            { Print("- R: classDeclaration -> scriptElement"); (yyval.tsscriptElementNode) = createElementFromClassDeclaration((yyvsp[0].classDeclNode)); }
#line 2358 "parser.tab.cpp"
    break;

  case 9: /* statementList: statementListItem  */
#line 194 "parser.y"
                                        { Print("- R: statementListItem -> statementList"); (yyval.stmtListNode) = createStatementListNode((yyvsp[0].stmtNode)); }
#line 2364 "parser.tab.cpp"
    break;

  case 10: /* statementList: statementList statementListItem  */
#line 195 "parser.y"
                                        { Print("- R: statementList statementListItem -> statementList"); (yyval.stmtListNode) = addStatementToStatementList((yyvsp[-1].stmtListNode), (yyvsp[0].stmtNode)); }
#line 2370 "parser.tab.cpp"
    break;

  case 11: /* statementListItem: emptyStatement  */
#line 199 "parser.y"
                                    { Print("- R: emptyStatement -> statementListItem"); }
#line 2376 "parser.tab.cpp"
    break;

  case 12: /* statementListItem: expressionStatement  */
#line 200 "parser.y"
                                    { Print("- R: expressionStatement -> statementListItem"); }
#line 2382 "parser.tab.cpp"
    break;

  case 13: /* statementListItem: varStatement  */
#line 201 "parser.y"
                                    { Print("- R: varStatement -> statementListItem"); }
#line 2388 "parser.tab.cpp"
    break;

  case 14: /* statementListItem: ifStatement  */
#line 202 "parser.y"
                                    { Print("- R: ifStatement -> statementListItem"); }
#line 2394 "parser.tab.cpp"
    break;

  case 15: /* statementListItem: iterationStatement  */
#line 203 "parser.y"
                                    { Print("- R: iterationStatement -> statementListItem"); }
#line 2400 "parser.tab.cpp"
    break;

  case 16: /* statementListItem: returnStatement  */
#line 205 "parser.y"
        { 
            if ( !isInFunctionBody ) { 
                yyerror("illegal return statement."); YYERROR;
            } 
            Print("- R: returnStatement -> statementListItem");
        }
#line 2411 "parser.tab.cpp"
    break;

  case 17: /* statementListItem: blockStatement  */
#line 211 "parser.y"
                                    { Print("- R: blockStatement -> statementListItem"); }
#line 2417 "parser.tab.cpp"
    break;

  case 18: /* statementListItemWithoutEmptyStatement: expressionStatement  */
#line 215 "parser.y"
                                    { Print("- R: expressionStatement -> statementListItemWithoutEmptyStatement"); }
#line 2423 "parser.tab.cpp"
    break;

  case 19: /* statementListItemWithoutEmptyStatement: varStatement  */
#line 216 "parser.y"
                                    { Print("- R: varStatement -> statementListItemWithoutEmptyStatement"); }
#line 2429 "parser.tab.cpp"
    break;

  case 20: /* statementListItemWithoutEmptyStatement: ifStatement  */
#line 217 "parser.y"
                                    { Print("- R: ifStatement -> statementListItemWithoutEmptyStatement"); }
#line 2435 "parser.tab.cpp"
    break;

  case 21: /* statementListItemWithoutEmptyStatement: iterationStatement  */
#line 218 "parser.y"
                                    { Print("- R: iterationStatement -> statementListItemWithoutEmptyStatement"); }
#line 2441 "parser.tab.cpp"
    break;

  case 22: /* statementListItemWithoutEmptyStatement: returnStatement  */
#line 220 "parser.y"
        { 
            if ( !isInFunctionBody ) { 
                yyerror("illegal return statement."); YYERROR;
            } 
            Print("- R: returnStatement -> statementListItemWithoutEmptyStatement");
        }
#line 2452 "parser.tab.cpp"
    break;

  case 23: /* statementListItemWithoutEmptyStatement: blockStatement  */
#line 226 "parser.y"
                                    { Print("- R: blockStatement -> statementListItemWithoutEmptyStatement"); }
#line 2458 "parser.tab.cpp"
    break;

  case 25: /* emptyStatement: ';'  */
#line 233 "parser.y"
        { 
            if ( isASIActivated ) {
                std::string text(yytext_ptr, yyleng);
                yyerror(("syntax error on token: " + text).c_str()); YYERROR;
            }
            Print("- R: ';' -> emptyStatement");
            (yyval.stmtNode) = createEmptyStatementNode();
        }
#line 2471 "parser.tab.cpp"
    break;

  case 26: /* blockStatement: '{' '}'  */
#line 244 "parser.y"
              { Print("- R: '{' '}' -> blockStatement"); (yyval.stmtNode) = createBlockStatementNode(nullptr); }
#line 2477 "parser.tab.cpp"
    break;

  case 27: /* blockStatement: '{' statementList '}'  */
#line 245 "parser.y"
                            { Print("- R: '{' statementList '}' -> blockStatement"); (yyval.stmtNode) = createBlockStatementNode((yyvsp[-1].stmtListNode)); }
#line 2483 "parser.tab.cpp"
    break;

  case 28: /* type: '(' type ')'  */
#line 251 "parser.y"
                                                { Print("- R: '(' type ')' -> type"); (yyval.typeNode) = (yyvsp[-1].typeNode); }
#line 2489 "parser.tab.cpp"
    break;

  case 29: /* type: predefinedType  */
#line 252 "parser.y"
                                                { Print("- R: predefinedType -> type"); (yyval.typeNode) = (yyvsp[0].typeNode); }
#line 2495 "parser.tab.cpp"
    break;

  case 30: /* type: type '[' ']'  */
#line 253 "parser.y"
                                                { Print("- R: type '[' ']' -> type"); (yyval.typeNode) = createArrayTypeNode((yyvsp[-2].typeNode)); }
#line 2501 "parser.tab.cpp"
    break;

  case 31: /* type: '[' tupleTypeElements ']'  */
#line 254 "parser.y"
                                                { Print("- R: '[' tupleTypeElements ']' -> type"); (yyval.typeNode) = createTypeFromTupleType((yyvsp[-1].tupleTypeNode)); }
#line 2507 "parser.tab.cpp"
    break;

  case 32: /* type: ENDL_BRACKET_OPEN tupleTypeElements ']'  */
#line 255 "parser.y"
                                                { Print("- R: '[' tupleTypeElements ']' -> type"); (yyval.typeNode) = createTypeFromTupleType((yyvsp[-1].tupleTypeNode)); }
#line 2513 "parser.tab.cpp"
    break;

  case 33: /* tupleTypeElements: %empty  */
#line 259 "parser.y"
                                    { Print("- R: #empty# -> tupleTypeElements"); (yyval.tupleTypeNode) = createTupleTypeNode(nullptr); }
#line 2519 "parser.tab.cpp"
    break;

  case 34: /* tupleTypeElements: type  */
#line 260 "parser.y"
                                    { Print("- R: type -> tupleTypeElements"); (yyval.tupleTypeNode) = createTupleTypeNode((yyvsp[0].typeNode)); }
#line 2525 "parser.tab.cpp"
    break;

  case 35: /* tupleTypeElements: tupleTypeElements ',' type  */
#line 261 "parser.y"
                                    { Print("- R: tupleTypeElements ',' type -> tupleTypeElements"); (yyval.tupleTypeNode) = addTypeToTupleType((yyvsp[-2].tupleTypeNode), (yyvsp[0].typeNode)); }
#line 2531 "parser.tab.cpp"
    break;

  case 36: /* predefinedType: NUMBER  */
#line 265 "parser.y"
                    { Print("- R: NUMBER -> predefinedType"); (yyval.typeNode) = createNumberTypeNode(); }
#line 2537 "parser.tab.cpp"
    break;

  case 37: /* predefinedType: STRING  */
#line 266 "parser.y"
                    { Print("- R: STRING -> predefinedType"); (yyval.typeNode) = createStringTypeNode(); }
#line 2543 "parser.tab.cpp"
    break;

  case 38: /* predefinedType: BOOLEAN  */
#line 267 "parser.y"
                    { Print("- R: BOOLEAN -> predefinedType"); (yyval.typeNode) = createBooleanTypeNode(); }
#line 2549 "parser.tab.cpp"
    break;

  case 39: /* predefinedType: UNDEFINED  */
#line 268 "parser.y"
                    { Print("- R: UNDEFINED -> predefinedType"); (yyval.typeNode) = createUndefinedTypeNode(); }
#line 2555 "parser.tab.cpp"
    break;

  case 40: /* predefinedType: VOID  */
#line 269 "parser.y"
                    { Print("- R: VOID -> predefinedType"); (yyval.typeNode) = createVoidTypeNode(); }
#line 2561 "parser.tab.cpp"
    break;

  case 41: /* predefinedType: NULL_KW  */
#line 270 "parser.y"
                    { Print("- R: NULL_KW -> predefinedType"); (yyval.typeNode) = createNullTypeNode(); }
#line 2567 "parser.tab.cpp"
    break;

  case 42: /* typeAnnotationOpt: %empty  */
#line 274 "parser.y"
                        { Print("- R: # empty # -> typeAnnotationOpt"); (yyval.typeNode) = nullptr; }
#line 2573 "parser.tab.cpp"
    break;

  case 43: /* typeAnnotationOpt: typeAnnotation  */
#line 275 "parser.y"
                        { Print("- R: typeAnnotation -> typeAnnotationOpt"); (yyval.typeNode) = (yyvsp[0].typeNode); }
#line 2579 "parser.tab.cpp"
    break;

  case 44: /* typeAnnotation: ':' type  */
#line 279 "parser.y"
               { Print("- R: ':' type -> typeAnnotation"); (yyval.typeNode) = (yyvsp[0].typeNode); }
#line 2585 "parser.tab.cpp"
    break;

  case 45: /* arrayLiteral: '[' elementList ']'  */
#line 284 "parser.y"
                                        { Print("- R: [ elementList ']' -> arrayLiteral"); (yyval.exprNode) = createExpressionFromExpressionList((yyvsp[-1].exprListNode)); }
#line 2591 "parser.tab.cpp"
    break;

  case 46: /* arrayLiteral: ENDL_BRACKET_OPEN elementList ']'  */
#line 285 "parser.y"
                                        { Print("- R: ENDL_BRACKET_OPEN elementList ']' -> arrayLiteral"); (yyval.exprNode) = createExpressionFromExpressionList((yyvsp[-1].exprListNode)); }
#line 2597 "parser.tab.cpp"
    break;

  case 47: /* elementList: elementListItem  */
#line 290 "parser.y"
        { 
            Print("- R: elementListItem -> elementList");
            (yyval.exprListNode) = createExpressionListFromExpression((yyvsp[0].exprNode));
        }
#line 2606 "parser.tab.cpp"
    break;

  case 48: /* elementList: elementList ',' elementListItem  */
#line 295 "parser.y"
        { 
            Print("- R: elementList ',' elementListItem -> elementList"); 
            (yyval.exprListNode) = addExpressionListToExpressionList((yyvsp[-2].exprListNode), createExpressionListFromExpression((yyvsp[0].exprNode))); 
        }
#line 2615 "parser.tab.cpp"
    break;

  case 49: /* elementListItem: %empty  */
#line 302 "parser.y"
                  { Print("- R: #empty# -> elementListItem"); (yyval.exprNode) = createEmptyArrayElementExpressionNode(); }
#line 2621 "parser.tab.cpp"
    break;

  case 50: /* elementListItem: singleExpression  */
#line 303 "parser.y"
                       { Print("- R: singleExpression -> elementListItem"); (yyval.exprNode) = (yyvsp[0].exprNode); }
#line 2627 "parser.tab.cpp"
    break;

  case 51: /* elementListItem: singleExpression ','  */
#line 305 "parser.y"
        { 
            Print("- R: singleExpression ',' -> elementListItem"); 
            (yyval.exprNode) = createCommaExpressionNode((yyvsp[-1].exprNode), createEmptyArrayElementExpressionNode());
        }
#line 2636 "parser.tab.cpp"
    break;

  case 52: /* expressionStatement: singleExpression ';'  */
#line 314 "parser.y"
                           { Print("- R: expressionList ';' -> expressionStatement"); (yyval.stmtNode) = createExpressionStatementNode((yyvsp[-1].exprNode)); }
#line 2642 "parser.tab.cpp"
    break;

  case 53: /* singleExpressionOpt: %empty  */
#line 318 "parser.y"
                        { Print("- R: #empty# -> singleExpressionOpt"); (yyval.exprNode) = nullptr; }
#line 2648 "parser.tab.cpp"
    break;

  case 54: /* singleExpressionOpt: singleExpression  */
#line 319 "parser.y"
                          { Print("- R: singleExpression -> singleExpressionOpt"); (yyval.exprNode) = (yyvsp[0].exprNode); }
#line 2654 "parser.tab.cpp"
    break;

  case 55: /* singleExpression: identifier  */
#line 323 "parser.y"
                    { Print("- R: identifier -> singleExpression"); (yyval.exprNode) = createIDExpressionNode((yyvsp[0].identName)); }
#line 2660 "parser.tab.cpp"
    break;

  case 56: /* singleExpression: THIS  */
#line 324 "parser.y"
                    { Print("- R: THIS -> singleExpression"); (yyval.exprNode) = createThisExpressionNode(); }
#line 2666 "parser.tab.cpp"
    break;

  case 57: /* singleExpression: SUPER  */
#line 325 "parser.y"
                    { Print("- R: SUPER -> singleExpression"); }
#line 2672 "parser.tab.cpp"
    break;

  case 58: /* singleExpression: TRUE_KW  */
#line 326 "parser.y"
                    { Print("- R: TRUE_LITERAL -> singleExpression"); }
#line 2678 "parser.tab.cpp"
    break;

  case 59: /* singleExpression: FALSE_KW  */
#line 327 "parser.y"
                    { Print("- R: FALSE_LITERAL -> singleExpression"); }
#line 2684 "parser.tab.cpp"
    break;

  case 60: /* singleExpression: NULL_KW  */
#line 328 "parser.y"
                    { Print("- R: NULL_LITERAL -> singleExpression"); }
#line 2690 "parser.tab.cpp"
    break;

  case 61: /* singleExpression: STRING_LIT  */
#line 330 "parser.y"
                    { Print("- R: STRING_LIT -> singleExpression"); (yyval.exprNode) = createStringLiteralExpressionNode((yyvsp[0].stringValue)); }
#line 2696 "parser.tab.cpp"
    break;

  case 62: /* singleExpression: TEMPLATE_LIT  */
#line 331 "parser.y"
                    { Print("- R: TEMPLATE_LIT -> singleExpression"); (yyval.exprNode) = createStringLiteralExpressionNode((yyvsp[0].stringValue)); }
#line 2702 "parser.tab.cpp"
    break;

  case 63: /* singleExpression: INT_LIT  */
#line 332 "parser.y"
                    { Print("- R: INT_LIT -> singleExpression"); (yyval.exprNode) = createIntLiteralExpressionNode((yyvsp[0].integerValue)); }
#line 2708 "parser.tab.cpp"
    break;

  case 64: /* singleExpression: FLOAT_LIT  */
#line 333 "parser.y"
                    { Print("- R: FLOAT_LIT -> singleExpression"); (yyval.exprNode) = createFloatLiteralExpressionNode((yyvsp[0].floatingPointValue)); }
#line 2714 "parser.tab.cpp"
    break;

  case 65: /* singleExpression: '-' singleExpression  */
#line 335 "parser.y"
                                        { Print("- R: '-' singleExpression -> singleExpression"); }
#line 2720 "parser.tab.cpp"
    break;

  case 66: /* singleExpression: '+' singleExpression  */
#line 336 "parser.y"
                                        { Print("- R: '+' singleExpression -> singleExpression"); }
#line 2726 "parser.tab.cpp"
    break;

  case 67: /* singleExpression: '!' singleExpression  */
#line 338 "parser.y"
                           { Print("- R: '!' singleExpression -> singleExpression"); }
#line 2732 "parser.tab.cpp"
    break;

  case 68: /* singleExpression: singleExpression OPERATOR_INCREMENT  */
#line 340 "parser.y"
                                                               { Print("- R: singleExpression OPERATOR_INCREMENT -> singleExpression"); }
#line 2738 "parser.tab.cpp"
    break;

  case 69: /* singleExpression: singleExpression OPERATOR_DECREMENT  */
#line 341 "parser.y"
                                                               { Print("- R: singleExpression OPERATOR_DECREMENT -> singleExpression"); }
#line 2744 "parser.tab.cpp"
    break;

  case 70: /* singleExpression: ENDL_OPERATOR_INCREMENT singleExpression  */
#line 343 "parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 2750 "parser.tab.cpp"
    break;

  case 71: /* singleExpression: ENDL_OPERATOR_DECREMENT singleExpression  */
#line 344 "parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 2756 "parser.tab.cpp"
    break;

  case 72: /* singleExpression: OPERATOR_INCREMENT singleExpression  */
#line 345 "parser.y"
                                                               { Print("- R: OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 2762 "parser.tab.cpp"
    break;

  case 73: /* singleExpression: OPERATOR_DECREMENT singleExpression  */
#line 346 "parser.y"
                                                               { Print("- R: OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 2768 "parser.tab.cpp"
    break;

  case 74: /* singleExpression: singleExpression '+' singleExpression  */
#line 348 "parser.y"
                                            { Print("- R: singleExpression '+' singleExpression -> singleExpression"); (yyval.exprNode) = createPlusExpressionNode((yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2774 "parser.tab.cpp"
    break;

  case 75: /* singleExpression: singleExpression '-' singleExpression  */
#line 349 "parser.y"
                                            { Print("- R: singleExpression '-' singleExpression -> singleExpression"); }
#line 2780 "parser.tab.cpp"
    break;

  case 76: /* singleExpression: singleExpression '*' singleExpression  */
#line 350 "parser.y"
                                            { Print("- R: singleExpression '*' singleExpression -> singleExpression"); }
#line 2786 "parser.tab.cpp"
    break;

  case 77: /* singleExpression: singleExpression '/' singleExpression  */
#line 351 "parser.y"
                                            { Print("- R: singleExpression '/' singleExpression -> singleExpression"); }
#line 2792 "parser.tab.cpp"
    break;

  case 78: /* singleExpression: singleExpression '<' singleExpression  */
#line 352 "parser.y"
                                            { Print("- R: singleExpression '<' singleExpression -> singleExpression"); }
#line 2798 "parser.tab.cpp"
    break;

  case 79: /* singleExpression: singleExpression '>' singleExpression  */
#line 353 "parser.y"
                                            { Print("- R: singleExpression '>' singleExpression -> singleExpression"); }
#line 2804 "parser.tab.cpp"
    break;

  case 80: /* singleExpression: singleExpression OPERATOR_EQUAL singleExpression  */
#line 356 "parser.y"
        { Print("- R: singleExpression OPERATOR_EQUAL singleExpression -> singleExpression"); }
#line 2810 "parser.tab.cpp"
    break;

  case 81: /* singleExpression: singleExpression OPERATOR_NOT_EQUAL singleExpression  */
#line 359 "parser.y"
        { Print("- R: singleExpression OPERATOR_NOT_EQUAL singleExpression -> singleExpression"); }
#line 2816 "parser.tab.cpp"
    break;

  case 82: /* singleExpression: singleExpression OPERATOR_STRICT_EQUAL singleExpression  */
#line 362 "parser.y"
        { Print("- R: singleExpression OPERATOR_STRICT_EQUAL singleExpression -> singleExpression"); }
#line 2822 "parser.tab.cpp"
    break;

  case 83: /* singleExpression: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression  */
#line 365 "parser.y"
        { Print("- R: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression -> singleExpression"); }
#line 2828 "parser.tab.cpp"
    break;

  case 84: /* singleExpression: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression  */
#line 368 "parser.y"
        { Print("- R: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression -> singleExpression"); }
#line 2834 "parser.tab.cpp"
    break;

  case 85: /* singleExpression: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression  */
#line 371 "parser.y"
        { Print("- R: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression -> singleExpression"); }
#line 2840 "parser.tab.cpp"
    break;

  case 86: /* singleExpression: singleExpression '=' singleExpression  */
#line 374 "parser.y"
        { Print("- R: singleExpression '=' singleExpression -> singleExpression"); }
#line 2846 "parser.tab.cpp"
    break;

  case 87: /* singleExpression: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression  */
#line 377 "parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression -> singleExpression"); }
#line 2852 "parser.tab.cpp"
    break;

  case 88: /* singleExpression: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression  */
#line 380 "parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression -> singleExpression"); }
#line 2858 "parser.tab.cpp"
    break;

  case 89: /* singleExpression: singleExpression OPERATOR_ASSIGN_PLUS singleExpression  */
#line 383 "parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_PLUS singleExpression -> singleExpression"); }
#line 2864 "parser.tab.cpp"
    break;

  case 90: /* singleExpression: singleExpression OPERATOR_ASSIGN_MINUS singleExpression  */
#line 386 "parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_MINUS singleExpression -> singleExpression"); }
#line 2870 "parser.tab.cpp"
    break;

  case 91: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression  */
#line 389 "parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression -> singleExpression"); }
#line 2876 "parser.tab.cpp"
    break;

  case 92: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression  */
#line 392 "parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression -> singleExpression"); }
#line 2882 "parser.tab.cpp"
    break;

  case 93: /* singleExpression: singleExpression OPERATOR_LOGICAL_OR singleExpression  */
#line 395 "parser.y"
        { Print("- R: singleExpression OPERATOR_LOGICAL_OR singleExpression -> singleExpression"); }
#line 2888 "parser.tab.cpp"
    break;

  case 94: /* singleExpression: singleExpression OPERATOR_LOGICAL_AND singleExpression  */
#line 398 "parser.y"
        { Print("- R: singleExpression OPERATOR_LOGICAL_AND singleExpression -> singleExpression"); }
#line 2894 "parser.tab.cpp"
    break;

  case 95: /* singleExpression: singleExpression INSTANCEOF singleExpression  */
#line 400 "parser.y"
                                                    { Print("- R: singleExpression INSTANCEOF singleExpression -> singleExpression"); }
#line 2900 "parser.tab.cpp"
    break;

  case 96: /* singleExpression: singleExpression IN singleExpression  */
#line 401 "parser.y"
                                                    { Print("- R: singleExpression IN singleExpression -> singleExpression"); }
#line 2906 "parser.tab.cpp"
    break;

  case 97: /* singleExpression: singleExpression '?' singleExpression ':' singleExpression  */
#line 404 "parser.y"
        { Print("- R: singleExpression '?' singleExpression ':' singleExpression -> singleExpression"); }
#line 2912 "parser.tab.cpp"
    break;

  case 98: /* singleExpression: singleExpression ',' singleExpression  */
#line 407 "parser.y"
        { 
            Print("- R: singleExpression ',' singleExpressionn -> singleExpression"); 
            (yyval.exprNode) = createCommaExpressionNode((yyvsp[-2].exprNode), (yyvsp[0].exprNode));
        }
#line 2921 "parser.tab.cpp"
    break;

  case 99: /* singleExpression: '(' singleExpression ')'  */
#line 412 "parser.y"
                               { Print("- R: '(' expressionList ')' -> singleExpression"); }
#line 2927 "parser.tab.cpp"
    break;

  case 100: /* singleExpression: identifier '(' ')'  */
#line 415 "parser.y"
                         { Print("- R: identifier '(' ')' -> singleExpression"); }
#line 2933 "parser.tab.cpp"
    break;

  case 101: /* singleExpression: identifier '(' singleExpression ')'  */
#line 417 "parser.y"
        { 
            Print("- R: identifier '(' singleExpression ')' -> singleExpression");

            (yyval.exprNode) = createFuncCallExpressionNode((yyvsp[-3].identName), createExpressionListFromExpression((yyvsp[-1].exprNode)));
        }
#line 2943 "parser.tab.cpp"
    break;

  case 102: /* singleExpression: identifier '(' singleExpression ',' ')'  */
#line 422 "parser.y"
                                              { Print("- R: identifier '(' singleExpression ',' ')' -> singleExpression"); }
#line 2949 "parser.tab.cpp"
    break;

  case 103: /* singleExpression: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression  */
#line 425 "parser.y"
        { Print("- R: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression -> singleExpression"); }
#line 2955 "parser.tab.cpp"
    break;

  case 104: /* singleExpression: singleExpression '.' identifier  */
#line 428 "parser.y"
                                      { Print("- R: singleExpression '.' identifier -> singleExpression"); }
#line 2961 "parser.tab.cpp"
    break;

  case 105: /* singleExpression: singleExpression '.' identifier '(' ')'  */
#line 429 "parser.y"
                                              { Print("- R: singleExpression '.' identifier '(' ')' -> singleExpression"); }
#line 2967 "parser.tab.cpp"
    break;

  case 106: /* singleExpression: singleExpression '.' identifier '(' singleExpression ')'  */
#line 430 "parser.y"
                                                               { Print("- R: singleExpression '.' identifier '(' singleExpression ')' -> singleExpression"); }
#line 2973 "parser.tab.cpp"
    break;

  case 107: /* singleExpression: singleExpression '.' identifier '(' singleExpression ',' ')'  */
#line 431 "parser.y"
                                                                   { Print("- R: singleExpression '.' identifier '(' singleExpression ',' ')' -> singleExpression"); }
#line 2979 "parser.tab.cpp"
    break;

  case 108: /* singleExpression: arrayLiteral  */
#line 433 "parser.y"
                                                              { Print("- R: arrayLiteral -> singleExpression"); (yyval.exprNode) = (yyvsp[0].exprNode); }
#line 2985 "parser.tab.cpp"
    break;

  case 109: /* singleExpression: singleExpression '[' singleExpression ']'  */
#line 434 "parser.y"
                                                              { Print("- R: singleExpression '[' expressionList ']' -> singleExpression"); }
#line 2991 "parser.tab.cpp"
    break;

  case 110: /* singleExpression: singleExpression ENDL_BRACKET_OPEN singleExpression ']'  */
#line 435 "parser.y"
                                                              { Print("- R: singleExpression ENDL_BRACKET_OPEN expressionList ']' -> singleExpression"); }
#line 2997 "parser.tab.cpp"
    break;

  case 111: /* singleExpression: NEW singleExpression  */
#line 437 "parser.y"
                           { Print("- R: NEW singleExpression -> singleExpression"); }
#line 3003 "parser.tab.cpp"
    break;

  case 112: /* singleExpression: NEW singleExpression '(' ')'  */
#line 438 "parser.y"
                                   { Print("- R: NEW singleExpression '(' ')' -> singleExpression"); }
#line 3009 "parser.tab.cpp"
    break;

  case 113: /* singleExpression: NEW singleExpression '(' singleExpression ')'  */
#line 439 "parser.y"
                                                     { Print("- R: NEW singleExpression '(' singleExpression ')' -> singleExpression"); }
#line 3015 "parser.tab.cpp"
    break;

  case 114: /* varStatement: varModifier varDeclarationList ';'  */
#line 445 "parser.y"
                                         { Print("- R: varModifier varDeclarationList ';' -> varStatement"); (yyval.stmtNode) = createVarStatementNode((yyvsp[-2].varModifierType), (yyvsp[-1].varDeclListNode)); }
#line 3021 "parser.tab.cpp"
    break;

  case 116: /* varDeclarationList: varDeclaration  */
#line 451 "parser.y"
        {
             Print("- R: varDeclaration -> varDeclarationList");
             (yyval.varDeclListNode) = createVarDeclarationListNode((yyvsp[0].varDeclNode));
        }
#line 3030 "parser.tab.cpp"
    break;

  case 117: /* varDeclarationList: varDeclarationList ',' varDeclaration  */
#line 456 "parser.y"
        { 
            Print("- R: varDeclarationList ',' varDeclaration -> varDeclarationList");
            (yyval.varDeclListNode) = addVarDeclarationToVarDeclarationList((yyvsp[-2].varDeclListNode), (yyvsp[0].varDeclNode));
        }
#line 3039 "parser.tab.cpp"
    break;

  case 118: /* varDeclaration: identifier typeAnnotationOpt  */
#line 464 "parser.y"
        { 
            Print("- R: identifier typeAnnotationOpt -> varDeclaration"); 
            (yyval.varDeclNode) = createVarDeclarationNode((yyvsp[-1].identName), (yyvsp[0].typeNode), nullptr); 
        }
#line 3048 "parser.tab.cpp"
    break;

  case 119: /* varDeclaration: identifier typeAnnotationOpt '=' singleExpression  */
#line 469 "parser.y"
        { 
            Print("- R: identifier typeAnnotationOpt '=' singleExpression -> varDeclaration"); 
            (yyval.varDeclNode) = createVarDeclarationNode((yyvsp[-3].identName), (yyvsp[-2].typeNode), (yyvsp[0].exprNode)); 
        }
#line 3057 "parser.tab.cpp"
    break;

  case 120: /* varModifier: VAR  */
#line 476 "parser.y"
            { Print("- R: VAR -> varModifier"); (yyval.varModifierType) = VarModifierType::_VAR; }
#line 3063 "parser.tab.cpp"
    break;

  case 121: /* varModifier: LET  */
#line 477 "parser.y"
            { Print("- R: LET -> varModifier"); (yyval.varModifierType) = VarModifierType::_LET; }
#line 3069 "parser.tab.cpp"
    break;

  case 122: /* varModifier: CONST  */
#line 478 "parser.y"
            { Print("- R: CONST -> varModifier"); (yyval.varModifierType) = VarModifierType::_CONST; }
#line 3075 "parser.tab.cpp"
    break;

  case 123: /* ifStatement: IF '(' singleExpression ')' statementListItemWithoutEmptyStatement  */
#line 485 "parser.y"
        { 
            Print("- R: IF '(' expressionList ')' statementListItem -> ifStatement");
            (yyval.stmtNode) = createIfElseStatementNode((yyvsp[-2].exprNode), (yyvsp[0].stmtNode), nullptr);
        }
#line 3084 "parser.tab.cpp"
    break;

  case 124: /* ifStatement: IF '(' singleExpression ')' statementListItemWithoutEmptyStatement ELSE statementListItem  */
#line 491 "parser.y"
        { 
            Print("- R: IF '(' expressionList ')' statementListItem ELSE statementListItem -> ifStatement");
            (yyval.stmtNode) = createIfElseStatementNode((yyvsp[-4].exprNode), (yyvsp[-2].stmtNode), (yyvsp[0].stmtNode));
        }
#line 3093 "parser.tab.cpp"
    break;

  case 125: /* $@1: %empty  */
#line 500 "parser.y"
                                                          { doWhileASI(); }
#line 3099 "parser.tab.cpp"
    break;

  case 126: /* iterationStatement: DO statementListItem WHILE '(' singleExpression ')' $@1 ';'  */
#line 501 "parser.y"
        { 
            Print("- R: DO statementListItem WHILE '(' expressionList ')' ';' -> iterationStatement");
            (yyval.stmtNode) = createDoWhileStatementNode((yyvsp[-6].stmtNode), (yyvsp[-3].exprNode));
        }
#line 3108 "parser.tab.cpp"
    break;

  case 127: /* iterationStatement: WHILE '(' singleExpression ')' statementListItem  */
#line 507 "parser.y"
        { 
            Print("- R: WHILE '(' expressionList ')' statementListItem -> iterationStatement");
            (yyval.stmtNode) = createWhileStatementNode((yyvsp[-2].exprNode), (yyvsp[0].stmtNode));
        }
#line 3117 "parser.tab.cpp"
    break;

  case 128: /* $@2: %empty  */
#line 512 "parser.y"
                                                                                        { isInForHeader = 0; }
#line 3123 "parser.tab.cpp"
    break;

  case 129: /* iterationStatement: forHeader singleExpressionOpt ';' singleExpressionOpt ';' singleExpressionOpt ')' $@2 statementListItem  */
#line 513 "parser.y"
        { 
            Print("- R: FOR '(' singleExpressionOpt ';' singleExpressionOpt ';' singleExpressionOpt ')' statementListItem -> iterationStatement");
            (yyval.stmtNode) = createClassicForStatementNode((yyvsp[-7].exprNode), (yyvsp[-5].exprNode), (yyvsp[-3].exprNode), (yyvsp[0].stmtNode));
        }
#line 3132 "parser.tab.cpp"
    break;

  case 130: /* $@3: %empty  */
#line 518 "parser.y"
                                                                                                   { isInForHeader = 0; }
#line 3138 "parser.tab.cpp"
    break;

  case 131: /* iterationStatement: forHeader varModifier varDeclarationList ';' singleExpressionOpt ';' singleExpressionOpt ')' $@3 statementListItem  */
#line 519 "parser.y"
        {
            Print("- R: FOR '(' varModifier varDeclarationList ';' singleExpressionOpt ';' singleExpressionOpt ')' statementListItem -> iterationStatement");
            (yyval.stmtNode) = createClassicForWithVarDeclStatementNode((yyvsp[-8].varModifierType), (yyvsp[-7].varDeclListNode), (yyvsp[-5].exprNode), (yyvsp[-3].exprNode), (yyvsp[0].stmtNode));
        }
#line 3147 "parser.tab.cpp"
    break;

  case 132: /* $@4: %empty  */
#line 524 "parser.y"
                                                         { isInForHeader = 0; }
#line 3153 "parser.tab.cpp"
    break;

  case 133: /* iterationStatement: forHeader singleExpression IN singleExpression ')' $@4 statementListItem  */
#line 525 "parser.y"
        {
            Print("- R: FOR '(' singleExpression IN singleExpression ')' statementListItem -> iterationStatement");
            (yyval.stmtNode) = createForExprInExprStatementNode((yyvsp[-5].exprNode), (yyvsp[-3].exprNode), (yyvsp[0].stmtNode));
        }
#line 3162 "parser.tab.cpp"
    break;

  case 134: /* $@5: %empty  */
#line 530 "parser.y"
                                                                   { isInForHeader = 0; }
#line 3168 "parser.tab.cpp"
    break;

  case 135: /* iterationStatement: forHeader varModifier varDeclaration IN singleExpression ')' $@5 statementListItem  */
#line 531 "parser.y"
        {
            Print("- R: FOR '(' varModifier varDeclaration IN expressionList ')' statementListItem -> iterationStatement");
            (yyval.stmtNode) = createForVarDeclInExprStatementNode((yyvsp[-6].varModifierType), (yyvsp[-5].varDeclNode), (yyvsp[-3].exprNode), (yyvsp[0].stmtNode));
        }
#line 3177 "parser.tab.cpp"
    break;

  case 136: /* forHeader: FOR '('  */
#line 538 "parser.y"
               { isInForHeader = 1; }
#line 3183 "parser.tab.cpp"
    break;

  case 137: /* returnStatement: RETURN ';'  */
#line 544 "parser.y"
                                    { Print("- R: RETURN ';' -> returnStatement"); (yyval.stmtNode) = createReturnStatementNode(nullptr); }
#line 3189 "parser.tab.cpp"
    break;

  case 138: /* returnStatement: RETURN singleExpression ';'  */
#line 545 "parser.y"
                                    { Print("- R: RETURN singleExpression ';' -> returnStatement"); (yyval.stmtNode) = createReturnStatementNode((yyvsp[-1].exprNode)); }
#line 3195 "parser.tab.cpp"
    break;

  case 139: /* functionDeclaration: FUNCTION identifier '(' parameterList ')' typeAnnotationOpt functionBody  */
#line 550 "parser.y"
        {
            Print("- R: FUNCTION ID '(' parameterList ')' typeAnnotation functionBody -> functionDeclaration");
            (yyval.funcDeclarationNode) = createFunctionDeclarationNode((yyvsp[-5].identName), (yyvsp[-3].requiredParameterListNode), (yyvsp[-1].typeNode), (yyvsp[0].stmtListNode));
        }
#line 3204 "parser.tab.cpp"
    break;

  case 140: /* functionBody: '{' '}'  */
#line 557 "parser.y"
              { Print("- R: '{' '}' -> functionBody"); (yyval.stmtListNode) = createStatementListNode(nullptr); }
#line 3210 "parser.tab.cpp"
    break;

  case 141: /* $@6: %empty  */
#line 558 "parser.y"
          { isInFunctionBody = 1; }
#line 3216 "parser.tab.cpp"
    break;

  case 142: /* functionBody: '{' $@6 statementList '}'  */
#line 559 "parser.y"
        { 
            isInFunctionBody = 0; 
            Print("- R: '{' statementList '}' -> functionBody");
            (yyval.stmtListNode) = (yyvsp[-1].stmtListNode);
        }
#line 3226 "parser.tab.cpp"
    break;

  case 143: /* parameterList: %empty  */
#line 567 "parser.y"
                                { Print("- R: #empty# -> parameterList"); (yyval.requiredParameterListNode) = createRequiredParameterListNode(nullptr); }
#line 3232 "parser.tab.cpp"
    break;

  case 144: /* parameterList: requiredParameterList  */
#line 568 "parser.y"
                                { Print("- R: requiredParameterList -> parameterList"); (yyval.requiredParameterListNode) = (yyvsp[0].requiredParameterListNode); }
#line 3238 "parser.tab.cpp"
    break;

  case 145: /* parameterList: requiredParameterList ','  */
#line 569 "parser.y"
                                { Print("- R: requiredParameterList ',' -> parameterList"); (yyval.requiredParameterListNode) = (yyvsp[-1].requiredParameterListNode); }
#line 3244 "parser.tab.cpp"
    break;

  case 146: /* requiredParameterList: requiredParameter  */
#line 574 "parser.y"
        {
            Print("- R: requiredParameter -> requiredParameterList");
            (yyval.requiredParameterListNode) = createRequiredParameterListNode((yyvsp[0].requiredParameterNode));
        }
#line 3253 "parser.tab.cpp"
    break;

  case 147: /* requiredParameterList: requiredParameterList ',' requiredParameter  */
#line 579 "parser.y"
        {
            Print("- R: requiredParameterList ',' requiredParameter -> requiredParameterList");
            (yyval.requiredParameterListNode) = addRequiredParameterToRequiredParameterList((yyvsp[-2].requiredParameterListNode), (yyvsp[0].requiredParameterNode));
        }
#line 3262 "parser.tab.cpp"
    break;

  case 148: /* requiredParameter: identifier typeAnnotationOpt  */
#line 587 "parser.y"
        { 
            Print("- R: ID typeAnnotationOpt -> requiredParameter");
            (yyval.requiredParameterNode) = createRequiredParameterNode((yyvsp[-1].identName), (yyvsp[0].typeNode));
        }
#line 3271 "parser.tab.cpp"
    break;

  case 149: /* classDeclaration: CLASS identifier classTail  */
#line 597 "parser.y"
        {
            Print("- R: CLASS identifier classTail -> classDeclaration");
            (yyval.classDeclNode) = createClassDeclarationNode((yyvsp[-1].identName), nullptr, (yyvsp[0].classElementListNode));
        }
#line 3280 "parser.tab.cpp"
    break;

  case 150: /* classDeclaration: CLASS identifier classHeritage classTail  */
#line 602 "parser.y"
        {
            Print("- R: CLASS identifier classHeritage classTail -> classDeclaration");
            (yyval.classDeclNode) = createClassDeclarationNode((yyvsp[-2].identName), (yyvsp[-1].identName), (yyvsp[0].classElementListNode));
        }
#line 3289 "parser.tab.cpp"
    break;

  case 151: /* classHeritage: EXTENDS identifier  */
#line 609 "parser.y"
                         { Print("- R: EXTENDS identifier -> classHeritage"); (yyval.identName) = (yyvsp[0].identName); }
#line 3295 "parser.tab.cpp"
    break;

  case 152: /* classTail: '{' '}'  */
#line 613 "parser.y"
                                { Print("- R: '{' '}' -> classTail"); (yyval.classElementListNode) = createClassElementListNode(nullptr); }
#line 3301 "parser.tab.cpp"
    break;

  case 153: /* classTail: '{' classElementList '}'  */
#line 614 "parser.y"
                                { Print("- R: '{' classElementList '}' -> classTail"); (yyval.classElementListNode) = (yyvsp[-1].classElementListNode); }
#line 3307 "parser.tab.cpp"
    break;

  case 154: /* classElementList: classElement  */
#line 618 "parser.y"
                                    { Print("- R: classElement -> classElementList"); (yyval.classElementListNode) = createClassElementListNode((yyvsp[0].classElementNode)); }
#line 3313 "parser.tab.cpp"
    break;

  case 155: /* classElementList: classElementList classElement  */
#line 619 "parser.y"
                                    { Print("- R: classElementList classElement -> classElementList"); (yyval.classElementListNode) = addClassElementToClassElementList((yyvsp[-1].classElementListNode), (yyvsp[0].classElementNode)); }
#line 3319 "parser.tab.cpp"
    break;

  case 156: /* classElement: CONSTRUCTOR '(' parameterList ')' functionBody  */
#line 624 "parser.y"
        {
            Print("- R: CONSTRUCTOR '(' parameterList ')' functionBody -> classElement");
            (yyval.classElementNode) = createClassConstructor((yyvsp[-2].requiredParameterListNode), (yyvsp[0].stmtListNode));
        }
#line 3328 "parser.tab.cpp"
    break;

  case 157: /* classElement: propertyName typeAnnotationOpt ';'  */
#line 631 "parser.y"
        {
            Print("- R: propertyName typeAnnotationOpt ';' -> classElement");
            (yyval.classElementNode) = createClassProperty((yyvsp[-2].identName), (yyvsp[-1].typeNode), nullptr);
        }
#line 3337 "parser.tab.cpp"
    break;

  case 158: /* classElement: propertyName typeAnnotationOpt '=' singleExpression ';'  */
#line 636 "parser.y"
        {
            Print("- R: propertyName typeAnnotationOpt '=' singleExpression ';' -> classElement");
            (yyval.classElementNode) = createClassProperty((yyvsp[-4].identName), (yyvsp[-3].typeNode), (yyvsp[-1].exprNode));
        }
#line 3346 "parser.tab.cpp"
    break;

  case 159: /* classElement: propertyName '(' parameterList ')' typeAnnotationOpt functionBody  */
#line 643 "parser.y"
        {
            Print("- R: propertyName '(' parameterList ')' typeAnnotationOpt functionBody -> classElement");
            (yyval.classElementNode) = createClassMethod((yyvsp[-5].identName), (yyvsp[-3].requiredParameterListNode), (yyvsp[-1].typeNode), (yyvsp[0].stmtListNode));
        }
#line 3355 "parser.tab.cpp"
    break;

  case 160: /* classElement: GET propertyName '(' ')' typeAnnotationOpt functionBody  */
#line 650 "parser.y"
        {
            Print("- R: GET propertyName '(' ')' typeAnnotationOpt functionBody -> classElement");
            (yyval.classElementNode) = createClassGetter((yyvsp[-4].identName), (yyvsp[-1].typeNode), (yyvsp[0].stmtListNode));
        }
#line 3364 "parser.tab.cpp"
    break;

  case 161: /* classElement: SET propertyName '(' parameterList ')' functionBody  */
#line 655 "parser.y"
        {
            Print("- R: SET propertyName callSignature functionBody -> classElement");
            (yyval.classElementNode) = createClassSetter((yyvsp[-4].identName), (yyvsp[-2].requiredParameterListNode), (yyvsp[0].stmtListNode));
        }
#line 3373 "parser.tab.cpp"
    break;

  case 162: /* propertyName: identifier  */
#line 662 "parser.y"
                 { Print("- R: identifier -> propertyName"); }
#line 3379 "parser.tab.cpp"
    break;

  case 163: /* identifier: ID  */
#line 666 "parser.y"
                { Print("- R: ID -> identifier"); (yyval.identName) = (yyvsp[0].identName); }
#line 3385 "parser.tab.cpp"
    break;

  case 164: /* identifier: ASYNC  */
#line 667 "parser.y"
                { Print("- R: ASYNC -> identifier"); (yyval.identName) = strdup("async"); }
#line 3391 "parser.tab.cpp"
    break;

  case 165: /* identifier: AS  */
#line 668 "parser.y"
                { Print("- R: AS -> identifier"); (yyval.identName) = strdup("as"); }
#line 3397 "parser.tab.cpp"
    break;

  case 166: /* identifier: FROM  */
#line 669 "parser.y"
                { Print("- R: FROM -> identifier"); (yyval.identName) = strdup("from"); }
#line 3403 "parser.tab.cpp"
    break;

  case 167: /* identifier: YIELD  */
#line 670 "parser.y"
                { Print("- R: YIELD -> identifier"); (yyval.identName) = strdup("yield"); }
#line 3409 "parser.tab.cpp"
    break;

  case 168: /* identifier: ANY  */
#line 671 "parser.y"
                { Print("- R: ANY -> identifier"); (yyval.identName) = strdup("any"); }
#line 3415 "parser.tab.cpp"
    break;

  case 169: /* identifier: NUMBER  */
#line 672 "parser.y"
                { Print("- R: NUMBER -> identifier"); (yyval.identName) = strdup("number"); }
#line 3421 "parser.tab.cpp"
    break;

  case 170: /* identifier: BOOLEAN  */
#line 673 "parser.y"
                { Print("- R: BOOLEAN -> identifier"); (yyval.identName) = strdup("boolean"); }
#line 3427 "parser.tab.cpp"
    break;

  case 171: /* identifier: STRING  */
#line 674 "parser.y"
                { Print("- R: STRING -> identifier"); (yyval.identName) = strdup("string"); }
#line 3433 "parser.tab.cpp"
    break;

  case 172: /* identifier: UNIQUE  */
#line 675 "parser.y"
                { Print("- R: UNIQUE -> identifier"); (yyval.identName) = strdup("unique"); }
#line 3439 "parser.tab.cpp"
    break;

  case 173: /* identifier: SYMBOL  */
#line 676 "parser.y"
                { Print("- R: SYMBOL -> identifier"); (yyval.identName) = strdup("symbol"); }
#line 3445 "parser.tab.cpp"
    break;

  case 174: /* identifier: NEVER  */
#line 677 "parser.y"
                { Print("- R: NEVER -> identifier"); (yyval.identName) = strdup("never"); }
#line 3451 "parser.tab.cpp"
    break;

  case 175: /* identifier: UNDEFINED  */
#line 678 "parser.y"
                { Print("- R: UNDEFINED -> identifier"); (yyval.identName) = strdup("undefined"); }
#line 3457 "parser.tab.cpp"
    break;

  case 176: /* identifier: OBJECT  */
#line 679 "parser.y"
                { Print("- R: OBJECT -> identifier"); (yyval.identName) = strdup("object"); }
#line 3463 "parser.tab.cpp"
    break;

  case 177: /* identifier: KEYOF  */
#line 680 "parser.y"
                { Print("- R: KEYOF -> identifier"); (yyval.identName) = strdup("keyof"); }
#line 3469 "parser.tab.cpp"
    break;

  case 178: /* identifier: NAMESPACE  */
#line 681 "parser.y"
                { Print("- R: NAMESPACE -> identifier"); (yyval.identName) = strdup("namespace"); }
#line 3475 "parser.tab.cpp"
    break;

  case 179: /* identifier: ABSTRACT  */
#line 682 "parser.y"
                { Print("- R: ABSTRACT -> identifier"); (yyval.identName) = strdup("abstract"); }
#line 3481 "parser.tab.cpp"
    break;

  case 180: /* identifier: REQUIRE  */
#line 683 "parser.y"
                { Print("- R: REQUIRE -> identifier"); (yyval.identName) = strdup("require"); }
#line 3487 "parser.tab.cpp"
    break;


#line 3491 "parser.tab.cpp"

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

#line 686 "parser.y"



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


