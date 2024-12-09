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
#line 1 ".\\parser.y"

#include <cstdio>
#include <iostream>

#include "utils.h"
#include "parsing_tree.h"

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

#line 99 "parser.tab.c"

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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    VAR = 258,                     /* VAR  */
    LET = 259,                     /* LET  */
    CONST = 260,                   /* CONST  */
    IF = 261,                      /* IF  */
    ELSE = 262,                    /* ELSE  */
    FUNCTION = 263,                /* FUNCTION  */
    CLASS = 264,                   /* CLASS  */
    EXTENDS = 265,                 /* EXTENDS  */
    GET = 266,                     /* GET  */
    SET = 267,                     /* SET  */
    DO = 268,                      /* DO  */
    WHILE = 269,                   /* WHILE  */
    FOR = 270,                     /* FOR  */
    RETURN = 271,                  /* RETURN  */
    SUPER = 272,                   /* SUPER  */
    THIS = 273,                    /* THIS  */
    NEW = 274,                     /* NEW  */
    ASYNC = 275,                   /* ASYNC  */
    AS = 276,                      /* AS  */
    FROM = 277,                    /* FROM  */
    YIELD = 278,                   /* YIELD  */
    KEYOF = 279,                   /* KEYOF  */
    CONSTRUCTOR = 280,             /* CONSTRUCTOR  */
    NAMESPACE = 281,               /* NAMESPACE  */
    ABSTRACT = 282,                /* ABSTRACT  */
    REQUIRE = 283,                 /* REQUIRE  */
    ANY = 284,                     /* ANY  */
    NUMBER = 285,                  /* NUMBER  */
    BOOLEAN = 286,                 /* BOOLEAN  */
    STRING = 287,                  /* STRING  */
    NEVER = 288,                   /* NEVER  */
    UNDEFINED = 289,               /* UNDEFINED  */
    UNIQUE = 290,                  /* UNIQUE  */
    SYMBOL = 291,                  /* SYMBOL  */
    OBJECT = 292,                  /* OBJECT  */
    VOID = 293,                    /* VOID  */
    UNKNOWN = 294,                 /* UNKNOWN  */
    STRING_LIT = 295,              /* STRING_LIT  */
    INT_LIT = 296,                 /* INT_LIT  */
    FLOAT_LIT = 297,               /* FLOAT_LIT  */
    NULL_KW = 298,                 /* NULL_KW  */
    TRUE_KW = 299,                 /* TRUE_KW  */
    FALSE_KW = 300,                /* FALSE_KW  */
    ID = 301,                      /* ID  */
    ENDL = 302,                    /* ENDL  */
    TEMPLATE_LITERAL = 303,        /* TEMPLATE_LITERAL  */
    OPERATOR_INCREMENT = 304,      /* OPERATOR_INCREMENT  */
    OPERATOR_DECREMENT = 305,      /* OPERATOR_DECREMENT  */
    ENDL_OPERATOR_INCREMENT = 306, /* ENDL_OPERATOR_INCREMENT  */
    ENDL_OPERATOR_DECREMENT = 307, /* ENDL_OPERATOR_DECREMENT  */
    IF_ONLY_PREC = 308,            /* IF_ONLY_PREC  */
    COMMA_OPERATOR = 309,          /* COMMA_OPERATOR  */
    COMMA_SEPARATOR = 310,         /* COMMA_SEPARATOR  */
    OPERATOR_ASSIGN_PLUS = 311,    /* OPERATOR_ASSIGN_PLUS  */
    OPERATOR_ASSIGN_MINUS = 312,   /* OPERATOR_ASSIGN_MINUS  */
    OPERATOR_ASSIGN_MULTIPLY = 313, /* OPERATOR_ASSIGN_MULTIPLY  */
    OPERATOR_ASSIGN_DIVIDE = 314,  /* OPERATOR_ASSIGN_DIVIDE  */
    OPERATOR_ASSIGN_LOGICAL_AND = 315, /* OPERATOR_ASSIGN_LOGICAL_AND  */
    OPERATOR_ASSIGN_LOGICAL_OR = 316, /* OPERATOR_ASSIGN_LOGICAL_OR  */
    OPERATOR_LOGICAL_OR = 317,     /* OPERATOR_LOGICAL_OR  */
    OPERATOR_LOGICAL_AND = 318,    /* OPERATOR_LOGICAL_AND  */
    OPERATOR_EQUAL = 319,          /* OPERATOR_EQUAL  */
    OPERATOR_NOT_EQUAL = 320,      /* OPERATOR_NOT_EQUAL  */
    OPERATOR_STRICT_EQUAL = 321,   /* OPERATOR_STRICT_EQUAL  */
    OPERATOR_STRICT_NOT_EQUAL = 322, /* OPERATOR_STRICT_NOT_EQUAL  */
    OPERATOR_GREATER_THAN_EQUAL = 323, /* OPERATOR_GREATER_THAN_EQUAL  */
    OPERATOR_LESS_THAN_EQUAL = 324, /* OPERATOR_LESS_THAN_EQUAL  */
    INSTANCEOF = 325,              /* INSTANCEOF  */
    IN = 326,                      /* IN  */
    UMINUS = 327,                  /* UMINUS  */
    UPLUS = 328,                   /* UPLUS  */
    PREF_INCREMENT = 329,          /* PREF_INCREMENT  */
    PREF_DECREMENT = 330,          /* PREF_DECREMENT  */
    POST_INCREMENT = 331,          /* POST_INCREMENT  */
    POST_DECREMENT = 332,          /* POST_DECREMENT  */
    ENDL_BRACKET_OPEN = 333,       /* ENDL_BRACKET_OPEN  */
    OPTIONAL_CHAINING_OPERATOR = 334 /* OPTIONAL_CHAINING_OPERATOR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 35 ".\\parser.y"

    int _integer;
    char* _string;
    char* ident;
    double _floatingPoint;

    struct TSScriptNode* tsscript;
    struct TSElementListNode* tsscriptElementList;
    struct TSElementNode* tsscriptElement;

    struct StatementListNode* stmtList;
    struct StatementNode* stmt;

    struct ExpressionNode* exprStmt;


#line 242 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);



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
  YYSYMBOL_scriptElementList = 106,        /* scriptElementList  */
  YYSYMBOL_scriptElement = 107,            /* scriptElement  */
  YYSYMBOL_statementList = 108,            /* statementList  */
  YYSYMBOL_statementListItem = 109,        /* statementListItem  */
  YYSYMBOL_statementListItemWithoutEmptyStatement = 110, /* statementListItemWithoutEmptyStatement  */
  YYSYMBOL_emptyStatement = 111,           /* emptyStatement  */
  YYSYMBOL_blockStatement = 112,           /* blockStatement  */
  YYSYMBOL_initializer = 113,              /* initializer  */
  YYSYMBOL_type = 114,                     /* type  */
  YYSYMBOL_primaryType = 115,              /* primaryType  */
  YYSYMBOL_tupleTypeElements = 116,        /* tupleTypeElements  */
  YYSYMBOL_predefinedType = 117,           /* predefinedType  */
  YYSYMBOL_typeAnnotationOpt = 118,        /* typeAnnotationOpt  */
  YYSYMBOL_typeAnnotation = 119,           /* typeAnnotation  */
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
#define YYLAST   2278

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  104
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  189
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  327

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
       0,   112,   112,   125,   126,   130,   131,   132,   133,   137,
     138,   142,   143,   144,   145,   146,   147,   154,   158,   159,
     160,   161,   162,   169,   171,   175,   186,   187,   191,   197,
     201,   202,   203,   204,   205,   209,   210,   211,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   233,   234,   238,   243,   244,   248,   249,
     253,   254,   255,   261,   265,   266,   270,   271,   272,   273,
     274,   275,   277,   278,   279,   280,   282,   283,   285,   287,
     288,   290,   291,   292,   293,   295,   296,   297,   298,   299,
     300,   302,   305,   308,   311,   314,   317,   320,   323,   326,
     329,   332,   335,   338,   341,   344,   347,   348,   350,   353,
     356,   359,   361,   362,   363,   365,   368,   370,   371,   372,
     374,   380,   381,   385,   386,   390,   391,   395,   396,   397,
     403,   406,   413,   413,   416,   419,   419,   422,   422,   425,
     425,   428,   428,   433,   439,   440,   444,   448,   449,   449,
     453,   457,   458,   459,   463,   464,   468,   474,   475,   479,
     483,   484,   488,   489,   493,   496,   497,   500,   503,   504,
     508,   512,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533
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
  "';'", "'{'", "'}'", "$accept", "script", "scriptElementList",
  "scriptElement", "statementList", "statementListItem",
  "statementListItemWithoutEmptyStatement", "emptyStatement",
  "blockStatement", "initializer", "type", "primaryType",
  "tupleTypeElements", "predefinedType", "typeAnnotationOpt",
  "typeAnnotation", "arrayLiteral", "elementList", "elementListItem",
  "expressionStatement", "singleExpressionOpt", "singleExpression",
  "varStatement", "varDeclarationList", "varDeclaration", "varModifier",
  "ifStatement", "iterationStatement", "$@1", "$@2", "$@3", "$@4", "$@5",
  "forHeader", "returnStatement", "functionDeclaration", "functionBody",
  "$@6", "callSignature", "parameterList", "requiredParameterList",
  "requiredParameter", "classDeclaration", "classHeritage", "classTail",
  "classElementList", "classElement", "constructorCallSignature",
  "propertyName", "identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-263)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     412,  -263,  -263,  -263,  -263,   -91,   233,   233,   917,   -75,
     -69,  1086,  -263,  -263,  1339,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
    1339,  1339,  1339,  1339,  1339,  1339,  1339,  1339,  1339,  1339,
    -263,   614,    31,   310,  -263,  -263,  -263,  -263,  -263,  -263,
    1407,  -263,   347,  -263,  -263,  1003,  -263,  -263,  -263,  -263,
    1339,   -67,    -9,    19,  1339,  -263,  -263,  1461,   -85,   -85,
     -85,   -85,   -85,   -85,   -85,   -85,   -37,  -263,  1989,   -35,
    1515,  -263,   715,  -263,  -263,  -263,  -263,  -263,  -263,  1339,
    1339,  1339,  1339,  1339,  1339,  1339,  1339,  1339,  1339,  1339,
    1339,  1339,  1339,  1339,  1339,  1339,  1339,  1339,  1339,  1339,
    1339,  1339,  1339,  1339,   233,  1339,  1339,  1339,  1171,  -263,
     -65,   -47,  -263,   -27,   -61,  2041,   233,  1568,   233,   -68,
     233,   145,   -63,  -263,   -58,  1621,  -263,  1339,  -263,  1339,
    -263,  -263,  -263,  -263,  2179,  2179,  2179,  2179,  2179,  2179,
    2179,  2179,  1833,   504,   604,    65,    65,    65,    65,   304,
     304,   304,   304,   304,   304,    -3,    -3,   -85,   -85,  -263,
    1885,  1937,   -57,  -263,  1674,  -263,   233,  -263,  1363,     5,
    -263,  1339,  1339,   -43,   -17,   514,   -34,    13,  -263,   -27,
     -33,  -263,  -263,   233,   233,   -28,  -263,   203,  -263,   -62,
    -263,  -263,  1339,   917,  -263,  1339,  -263,  -263,  1255,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,  1363,  1363,  1363,  -263,
     -23,  -263,  1339,   -26,  2093,   204,  1339,  1339,  -263,    61,
    -263,  -263,  -263,  -263,  -263,  -263,   -27,   233,  -263,  -263,
     917,   -20,   -67,   233,   -68,  -263,  -263,   -41,   -68,  1727,
    -263,   402,  -263,  -263,   -32,   -31,   -15,   -13,  2136,  1339,
    -263,   -14,  1780,   917,  -263,  -263,   816,   -12,   -68,   -11,
    -263,  1339,  -263,    -4,  -263,  -263,  1363,  -263,  -263,  -263,
    -263,   -10,   917,  1339,  -263,  -263,  -263,   -27,  -263,  -263,
    2093,  -263,    -2,  -263,  -263,  -263,     0,   917,   -68,  -263,
     917,  -263,  -263,  -263,  -263,   917,  -263
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     8,   127,   128,   129,     0,     0,     0,     0,     0,
       0,     0,    68,    67,     0,   173,   174,   175,   176,   186,
     187,   188,   189,   177,   178,   179,   180,   183,   184,   181,
     182,   185,    72,    73,    74,    71,    69,    70,   172,    75,
       0,     0,     0,     0,     0,     0,     0,    60,    60,     0,
      25,     0,     0,     0,     3,     5,    11,    17,   117,    12,
       0,    13,     0,    14,    15,    64,    16,     6,     7,    66,
       0,     0,     0,     0,     0,   143,   144,     0,   120,    83,
      84,    81,    82,    77,    76,    78,     0,    58,    61,     0,
       0,    26,     0,     9,     1,     4,   108,    79,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
       0,     0,   123,    53,     0,    65,     0,     0,   151,     0,
       0,     0,     0,   157,     0,     0,   145,    60,    56,    62,
      57,   111,    27,    10,   110,    97,   100,   101,    98,    99,
     102,   103,     0,   104,   105,    91,    92,    93,    94,    90,
      89,    96,    95,   106,   107,    85,    86,    87,    88,   116,
       0,     0,   115,   112,     0,   122,     0,   121,     0,   125,
      54,    64,     0,     0,   123,     0,     0,   152,   154,    53,
     148,   146,   159,     0,     0,     0,   160,     0,   162,    53,
     171,   158,     0,     0,    59,     0,   118,   119,     0,   113,
     124,    38,    39,    41,    40,    42,    44,    45,    43,    49,
      50,    51,    46,    47,    48,    52,    35,    35,     0,    55,
      29,    31,     0,     0,    65,   107,    64,     0,    24,   130,
      23,    18,    19,    20,    21,    22,    53,   153,   156,   147,
       0,     0,     0,   151,     0,   161,   163,     0,     0,     0,
     134,   109,   114,    36,     0,     0,     0,     0,   126,    64,
     139,     0,     0,     0,   150,   155,     0,     0,     0,     0,
     164,     0,   165,     0,   167,   132,     0,    33,    34,    30,
      32,     0,     0,    64,   141,   131,   149,    53,   169,   170,
      28,   166,     0,    37,   135,   140,     0,     0,     0,   133,
       0,   137,   142,   168,   136,     0,   138
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -263,  -263,  -263,    33,  -162,    -8,  -263,  -263,   -94,  -263,
    -161,  -263,  -135,  -263,  -174,  -263,  -263,    86,    11,   -59,
    -118,     4,   -56,     1,  -131,   118,    -7,    -6,  -263,  -263,
    -263,  -263,  -263,  -263,    -5,  -263,  -262,  -263,  -205,   -79,
    -263,   -71,  -263,  -263,    45,  -263,    -1,  -263,  -175,    14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    52,    53,    54,    92,    55,   249,    56,    57,   293,
     273,   240,   274,   241,   189,   190,    58,    86,    87,    59,
     134,    60,    61,   131,   132,    62,    63,    64,   312,   320,
     325,   302,   317,    65,    66,    67,   201,   260,   139,   196,
     197,   198,    68,   142,   143,   207,   208,   264,   209,    69
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      73,   140,   290,   188,   268,   194,   294,   186,    70,   124,
     125,   186,   126,   127,   128,    77,   291,   147,    78,   147,
      71,    72,   296,   296,    74,   258,   308,   239,   261,   262,
      75,    94,   138,   144,   200,   267,   185,   138,   188,   141,
     191,   212,   128,    93,    79,    80,    81,    82,    83,    84,
      85,    88,    88,    90,   187,   220,   323,   288,   246,   148,
     292,   150,   242,   247,   297,   298,   256,   257,   283,   135,
     259,   263,   277,   243,   137,   279,   133,   276,   145,   287,
     122,   123,   284,   300,   153,   299,    95,   303,   307,   309,
     314,   124,   125,   141,   126,   127,   128,   311,   286,   319,
     321,   250,   275,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   281,   180,
     181,   182,   184,   318,    89,   313,   251,   193,   179,   252,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     133,    88,   199,   154,   202,   210,   203,   204,   214,   124,
     125,   301,   126,   127,   128,    15,    16,    17,    18,    19,
     205,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,   136,   289,   316,   285,   211,   253,   254,
     255,    38,     0,     0,     0,   244,   245,     0,     0,     0,
     133,     0,     0,     0,     0,   270,   266,     0,     0,     0,
       0,     0,     0,     0,   203,   204,   269,   210,   210,   271,
       0,   210,   154,    15,    16,    17,    18,    19,   205,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     0,     0,     0,     0,     0,   278,     0,   206,    38,
     244,   282,    93,    15,    16,    17,    18,    19,     0,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,   199,     0,     0,     0,   305,     0,   199,   153,    38,
       0,     0,     0,   244,     0,   120,   121,   122,   123,     0,
       0,     0,     0,     0,   315,   310,     0,     0,   124,   125,
       0,   126,   127,   128,   280,     0,   265,   244,     0,   322,
      -2,     1,   324,     2,     3,     4,     5,   326,     6,     7,
       0,     0,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,     0,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,   130,     0,
      32,    33,    34,    35,    36,    37,    38,     0,    39,    40,
      41,    42,    43,     0,     0,     0,     0,    15,    16,    17,
      18,    19,     0,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,   120,   121,   122,   123,     0,
       0,    44,    45,    38,     0,     0,    46,     0,   124,   125,
       0,   126,   127,   128,     0,    47,     0,    48,     0,    49,
       0,    50,    51,     1,     0,     2,     3,     4,     5,     0,
       6,     7,     0,     0,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,     0,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       0,     0,    32,    33,    34,    35,    36,    37,    38,     0,
      39,    40,    41,    42,    43,     0,     0,     0,   108,   109,
       0,     0,     0,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,     0,     0,     0,
       0,     0,     0,    44,    45,     0,   124,   125,    46,   126,
     127,   128,     0,     0,     0,     0,     0,    47,     0,    48,
       0,    49,     0,    50,    51,   248,     0,     2,     3,     4,
       5,     0,     0,     0,     0,     0,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,     0,    32,    33,    34,    35,    36,    37,
      38,     0,    39,    40,    41,    42,    43,     0,     0,     0,
       0,   109,     0,     0,     0,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,     0,
       0,     0,     0,     0,     0,    44,    45,     0,   124,   125,
      46,   126,   127,   128,     0,     0,     0,     0,     0,    47,
       0,    48,     0,    49,     0,     0,    51,     2,     3,     4,
       5,     0,     0,     0,     0,     0,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,     0,    32,    33,    34,    35,    36,    37,
      38,     0,    39,    40,    41,    42,    43,     0,     0,     0,
       0,     0,     0,     0,     0,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,     0,
       0,     0,     0,     0,     0,    44,    45,     0,   124,   125,
      46,   126,   127,   128,     0,     0,     0,     0,     0,    47,
       0,    48,     0,    49,     0,    50,    51,    91,     2,     3,
       4,     5,     0,     0,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       0,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     0,     0,    32,    33,    34,    35,    36,
      37,    38,     0,    39,    40,    41,    42,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    44,    45,     0,     0,
       0,    46,     0,     0,     0,     0,     0,     0,     0,     0,
      47,     0,    48,     0,    49,     0,    50,    51,   152,     2,
       3,     4,     5,     0,     0,     0,     0,     0,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,     0,    32,    33,    34,    35,
      36,    37,    38,     0,    39,    40,    41,    42,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,    45,     0,
       0,     0,    46,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,    48,     0,    49,     0,    50,    51,   306,
       2,     3,     4,     5,     0,     0,     0,     0,     0,     0,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     0,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,     0,     0,    32,    33,    34,
      35,    36,    37,    38,     0,    39,    40,    41,    42,    43,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    44,    45,
       0,     0,     0,    46,     0,     0,     2,     3,     4,     0,
       0,     0,    47,     0,    48,     0,    49,     0,    50,    51,
      12,    13,    14,    15,    16,    17,    18,    19,     0,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     0,     0,    32,    33,    34,    35,    36,    37,    38,
       0,    39,    40,    41,    42,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,    45,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     0,
      48,     0,    49,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,     0,    32,    33,    34,    35,
      36,    37,    38,     0,    39,    40,    41,    42,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,    45,     0,
       0,     0,    46,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,    48,     0,    49,     0,    76,    12,    13,
      14,    15,    16,    17,    18,    19,     0,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     0,
       0,    32,    33,    34,    35,    36,    37,    38,     0,    39,
      40,    41,    42,    43,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,    45,     0,     0,     0,    46,     0,     0,
       0,     0,     0,     0,     0,     0,    47,     0,    48,     0,
      49,   183,    12,    13,    14,    15,    16,    17,    18,    19,
       0,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     0,     0,    32,    33,    34,    35,    36,
      37,    38,     0,    39,    40,    41,    42,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    44,    45,     0,     0,
       0,    46,     0,     0,     0,     0,     0,     0,     0,     0,
      47,     0,    48,     0,    49,   272,    12,    13,    14,    15,
      16,    17,    18,    19,     0,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     0,     0,    32,
      33,    34,    35,    36,    37,    38,     0,    39,    40,    41,
      42,    43,   221,   222,   223,   224,   225,   226,     0,     0,
       0,   227,   228,   229,   230,   231,   232,   233,   234,     0,
       0,   235,     0,     0,     0,     0,     0,     0,     0,     0,
      44,    45,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     0,    48,     0,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,   236,     0,
     237,    99,   238,     0,   100,   101,   102,   103,   104,   105,
     106,   107,     0,   108,   109,     0,     0,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   124,   125,     0,   126,   127,   128,     0,   129,    96,
      97,    98,     0,     0,     0,    99,     0,     0,   100,   101,
     102,   103,   104,   105,   106,   107,     0,   108,   109,     0,
       0,     0,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   124,   125,     0,   126,   127,
     128,     0,   146,    96,    97,    98,     0,     0,     0,    99,
       0,     0,   100,   101,   102,   103,   104,   105,   106,   107,
       0,   108,   109,     0,     0,     0,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   124,
     125,     0,   126,   127,   128,   151,    96,    97,    98,     0,
       0,     0,    99,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   107,     0,   108,   109,     0,     0,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   124,   125,     0,   126,   127,   128,   195,    96,
      97,    98,     0,     0,     0,    99,     0,     0,   100,   101,
     102,   103,   104,   105,   106,   107,     0,   108,   109,     0,
       0,     0,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   124,   125,     0,   126,   127,
     128,   213,    96,    97,    98,     0,     0,     0,   218,     0,
       0,   100,   101,   102,   103,   104,   105,   106,   107,     0,
     108,   109,     0,     0,     0,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   124,   125,
       0,   126,   127,   128,   219,    96,    97,    98,     0,     0,
       0,    99,     0,     0,   100,   101,   102,   103,   104,   105,
     106,   107,     0,   108,   109,     0,     0,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   124,   125,     0,   126,   127,   128,   295,    96,    97,
      98,     0,     0,     0,    99,     0,     0,   100,   101,   102,
     103,   104,   105,   106,   107,     0,   108,   109,     0,     0,
       0,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   124,   125,     0,   126,   127,   128,
     304,    96,    97,    98,     0,     0,     0,    99,     0,     0,
     100,   101,   102,   103,   104,   105,   106,   107,   215,   108,
     109,     0,     0,     0,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   124,   125,     0,
     126,   127,   128,    96,    97,    98,     0,     0,     0,    99,
       0,     0,   100,   101,   102,   103,   104,   105,   106,   107,
       0,   108,   109,     0,     0,     0,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   124,
     125,   216,   126,   127,   128,    96,    97,    98,     0,     0,
       0,    99,     0,     0,   100,   101,   102,   103,   104,   105,
     106,   107,     0,   108,   109,     0,     0,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   124,   125,   217,   126,   127,   128,    96,    97,    98,
       0,     0,     0,   149,     0,     0,   100,   101,   102,   103,
     104,   105,   106,   107,     0,   108,   109,     0,     0,     0,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,   125,     0,   126,   127,   128,    96,
      97,    98,     0,     0,     0,    99,     0,     0,   100,   101,
     102,   103,   104,   105,   106,   107,     0,   108,   109,     0,
       0,     0,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   192,   120,   121,   122,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   124,   125,     0,   126,   127,
     128,    96,    97,    98,     0,     0,     0,    99,     0,     0,
     100,   101,   102,   103,   104,   105,   106,   107,     0,   108,
     109,     0,     0,     0,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,     0,     0,
       0,     0,     0,     0,    96,    97,    98,   124,   125,     0,
     126,   127,   128,   100,   101,   102,   103,   104,   105,   106,
     107,     0,   108,   109,     0,     0,     0,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     124,   125,     0,   126,   127,   128,   100,   101,   102,   103,
     104,   105,   106,   107,     0,   108,   109,     0,     0,     0,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,   125,     0,   126,   127,   128
};

static const yytype_int16 yycheck[] =
{
       8,    10,   264,    65,   209,   136,   268,    54,    99,    94,
      95,    54,    97,    98,    99,    11,    57,    54,    14,    54,
       6,     7,    54,    54,    99,   199,   288,   188,   203,   204,
      99,     0,    99,    14,   102,   209,   101,    99,    65,   102,
     101,    99,    99,    51,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,   101,   186,   318,   262,   101,    96,
     101,    96,    57,    80,    96,    96,   100,    54,     7,    65,
     103,    99,    95,   191,    70,   101,    62,   238,    74,    99,
      83,    84,   256,    96,    92,   100,    53,   101,   100,   100,
     100,    94,    95,   102,    97,    98,    99,   101,   260,   101,
     100,   195,   237,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   246,   125,
     126,   127,   128,   307,    48,   296,   195,   136,   124,   195,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
     136,   147,   138,   149,   140,   141,    11,    12,   147,    94,
      95,   279,    97,    98,    99,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    65,   263,   303,   257,   142,   195,   195,
     195,    46,    -1,    -1,    -1,   191,   192,    -1,    -1,    -1,
     186,    -1,    -1,    -1,    -1,   213,   207,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    12,   212,   203,   204,   215,
      -1,   207,   218,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,   242,    -1,   103,    46,
     246,   247,   260,    20,    21,    22,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,   257,    -1,    -1,    -1,   283,    -1,   263,   286,    46,
      -1,    -1,    -1,   279,    -1,    81,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,   302,   291,    -1,    -1,    94,    95,
      -1,    97,    98,    99,   100,    -1,   103,   303,    -1,   317,
       0,     1,   320,     3,     4,     5,     6,   325,     8,     9,
      -1,    -1,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,     1,    -1,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    49,
      50,    51,    52,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    81,    82,    83,    84,    -1,
      -1,    81,    82,    46,    -1,    -1,    86,    -1,    94,    95,
      -1,    97,    98,    99,    -1,    95,    -1,    97,    -1,    99,
      -1,   101,   102,     1,    -1,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    66,    67,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    82,    -1,    94,    95,    86,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,    95,    -1,    97,
      -1,    99,    -1,   101,   102,     1,    -1,     3,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    94,    95,
      86,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,    95,
      -1,    97,    -1,    99,    -1,    -1,   102,     3,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    94,    95,
      86,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,    95,
      -1,    97,    -1,    99,    -1,   101,   102,   103,     3,     4,
       5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    -1,    97,    -1,    99,    -1,   101,   102,   103,     3,
       4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,
      -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    -1,    97,    -1,    99,    -1,   101,   102,   103,
       3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      -1,    -1,    -1,    86,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,    95,    -1,    97,    -1,    99,    -1,   101,   102,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      97,    -1,    99,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,
      -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    -1,    97,    -1,    99,    -1,   101,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    -1,    -1,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    97,    -1,
      99,   100,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    -1,    97,    -1,    99,   100,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    82,    -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    97,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    95,    -1,
      97,    54,    99,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    66,    67,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    97,    98,    99,    -1,   101,    48,
      49,    50,    -1,    -1,    -1,    54,    -1,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    97,    98,
      99,    -1,   101,    48,    49,    50,    -1,    -1,    -1,    54,
      -1,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      -1,    66,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    -1,    97,    98,    99,   100,    48,    49,    50,    -1,
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
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,
      97,    98,    99,    48,    49,    50,    -1,    -1,    -1,    54,
      -1,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      -1,    66,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,    48,    49,    50,    -1,    -1,
      -1,    54,    -1,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    66,    67,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,    48,    49,    50,
      -1,    -1,    -1,    54,    -1,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    97,    98,    99,    48,
      49,    50,    -1,    -1,    -1,    54,    -1,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    97,    98,
      99,    48,    49,    50,    -1,    -1,    -1,    54,    -1,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    94,    95,    -1,
      97,    98,    99,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    66,    67,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    -1,    97,    98,    99,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    97,    98,    99
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
     101,   102,   105,   106,   107,   109,   111,   112,   120,   123,
     125,   126,   129,   130,   131,   137,   138,   139,   146,   153,
      99,   153,   153,   109,    99,    99,   101,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   121,   122,   125,   121,
     125,   103,   108,   109,     0,   107,    48,    49,    50,    54,
      57,    58,    59,    60,    61,    62,    63,    64,    66,    67,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    94,    95,    97,    98,    99,   101,
       1,   127,   128,   153,   124,   125,   129,   125,    99,   142,
      10,   102,   147,   148,    14,   125,   101,    54,    96,    54,
      96,   100,   103,   109,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   153,
     125,   125,   125,   100,   125,   101,    54,   101,    65,   118,
     119,   101,    80,   127,   128,   100,   143,   144,   145,   153,
     102,   140,   153,    11,    12,    25,   103,   149,   150,   152,
     153,   148,    99,   100,   122,    65,    96,    96,    54,   100,
     128,    29,    30,    31,    32,    33,    34,    38,    39,    40,
      41,    42,    43,    44,    45,    48,    95,    97,    99,   114,
     115,   117,    57,   124,   125,   125,   101,    80,     1,   110,
     112,   123,   126,   130,   131,   138,   100,    54,   118,   103,
     141,   152,   152,    99,   151,   103,   150,   118,   142,   125,
     109,   125,   100,   114,   116,   116,   114,    95,   125,   101,
     100,   124,   125,     7,   118,   145,   108,    99,   142,   143,
     140,    57,   101,   113,   140,   100,    54,    96,    96,   100,
      96,   124,   135,   101,   100,   109,   103,   100,   140,   100,
     125,   101,   132,   114,   100,   109,   124,   136,   118,   101,
     133,   100,   109,   140,   109,   134,   109
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   104,   105,   106,   106,   107,   107,   107,   107,   108,
     108,   109,   109,   109,   109,   109,   109,   109,   110,   110,
     110,   110,   110,   110,   110,   111,   112,   112,   113,   114,
     115,   115,   115,   115,   115,   116,   116,   116,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   118,   118,   119,   120,   120,   121,   121,
     122,   122,   122,   123,   124,   124,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   126,   126,   127,   127,   128,   128,   129,   129,   129,
     130,   130,   132,   131,   131,   133,   131,   134,   131,   135,
     131,   136,   131,   137,   138,   138,   139,   140,   141,   140,
     142,   143,   143,   143,   144,   144,   145,   146,   146,   147,
     148,   148,   149,   149,   150,   150,   150,   150,   150,   150,
     151,   152,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     2,     1,
       3,     1,     3,     3,     3,     0,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     2,     3,     3,     1,     3,
       0,     1,     2,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     5,
       3,     3,     3,     4,     5,     3,     3,     1,     4,     4,
       2,     3,     3,     1,     3,     2,     4,     1,     1,     1,
       5,     7,     0,     8,     5,     0,     9,     0,    10,     0,
       7,     0,     8,     2,     2,     3,     4,     2,     0,     4,
       4,     0,     1,     2,     1,     3,     2,     3,     4,     2,
       2,     3,     1,     2,     3,     3,     4,     3,     6,     4,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
  case 2: /* script: scriptElementList  */
#line 113 ".\\parser.y"
        { 
            if ( syntaxErrorCounter > 0 ) {
                PrintError("Found " + std::to_string(syntaxErrorCounter) + " syntax errors. Fix them and rerun.");
                exit(1);
            }
            Print("- R: scriptElementList -> script"); 
        
            (yyval.tsscript) = root = createTSScriptNode((yyvsp[0].tsscriptElementList));
        }
#line 2422 "parser.tab.c"
    break;

  case 3: /* scriptElementList: scriptElement  */
#line 125 ".\\parser.y"
                                        { Print("- R: scriptElement -> scriptElementList"); (yyval.tsscriptElementList) = createTSElementListNode((yyvsp[0].tsscriptElement)); }
#line 2428 "parser.tab.c"
    break;

  case 4: /* scriptElementList: scriptElementList scriptElement  */
#line 126 ".\\parser.y"
                                        { Print("- R: scriptElementList scriptElement -> scriptElementList"); (yyval.tsscriptElementList) = addTSElementNodeToList((yyvsp[-1].tsscriptElementList), (yyvsp[0].tsscriptElement)); }
#line 2434 "parser.tab.c"
    break;

  case 5: /* scriptElement: statementListItem  */
#line 130 ".\\parser.y"
                            { Print("- R: statementListItem -> scriptElement"); (yyval.tsscriptElement) = createElementFromStatement((yyvsp[0].stmt)); }
#line 2440 "parser.tab.c"
    break;

  case 6: /* scriptElement: functionDeclaration  */
#line 131 ".\\parser.y"
                            { Print("- R: functionDeclaration -> scriptElement"); }
#line 2446 "parser.tab.c"
    break;

  case 7: /* scriptElement: classDeclaration  */
#line 132 ".\\parser.y"
                            { Print("- R: classDeclaration -> scriptElement"); }
#line 2452 "parser.tab.c"
    break;

  case 9: /* statementList: statementListItem  */
#line 137 ".\\parser.y"
                                        { Print("- R: statementListItem -> statementList"); (yyval.stmtList) = createStatementListNode((yyvsp[0].stmt)); }
#line 2458 "parser.tab.c"
    break;

  case 10: /* statementList: statementList statementListItem  */
#line 138 ".\\parser.y"
                                        { Print("- R: statementList statementListItem -> statementList"); (yyval.stmtList) = addStatementToStatementList((yyvsp[-1].stmtList), (yyvsp[0].stmt)); }
#line 2464 "parser.tab.c"
    break;

  case 11: /* statementListItem: emptyStatement  */
#line 142 ".\\parser.y"
                                    { Print("- R: emptyStatement -> statementListItem"); }
#line 2470 "parser.tab.c"
    break;

  case 12: /* statementListItem: expressionStatement  */
#line 143 ".\\parser.y"
                                    { Print("- R: expressionStatement -> statementListItem"); (yyval.stmt) = createStatementFromExpression((yyvsp[0].exprStmt)); }
#line 2476 "parser.tab.c"
    break;

  case 13: /* statementListItem: varStatement  */
#line 144 ".\\parser.y"
                                    { Print("- R: varStatement -> statementListItem"); }
#line 2482 "parser.tab.c"
    break;

  case 14: /* statementListItem: ifStatement  */
#line 145 ".\\parser.y"
                                    { Print("- R: ifStatement -> statementListItem"); }
#line 2488 "parser.tab.c"
    break;

  case 15: /* statementListItem: iterationStatement  */
#line 146 ".\\parser.y"
                                    { Print("- R: iterationStatement -> statementListItem"); }
#line 2494 "parser.tab.c"
    break;

  case 16: /* statementListItem: returnStatement  */
#line 148 ".\\parser.y"
        { 
            if ( !isInFunctionBody ) { 
                yyerror("illegal return statement."); YYERROR;
            } 
            Print("- R: returnStatement -> statementListItem"); 
        }
#line 2505 "parser.tab.c"
    break;

  case 17: /* statementListItem: blockStatement  */
#line 154 ".\\parser.y"
                                    { Print("- R: blockStatement -> statementListItem"); }
#line 2511 "parser.tab.c"
    break;

  case 18: /* statementListItemWithoutEmptyStatement: expressionStatement  */
#line 158 ".\\parser.y"
                                    { Print("- R: expressionStatement -> statementListItemWithoutEmptyStatement"); }
#line 2517 "parser.tab.c"
    break;

  case 19: /* statementListItemWithoutEmptyStatement: varStatement  */
#line 159 ".\\parser.y"
                                    { Print("- R: varStatement -> statementListItemWithoutEmptyStatement"); }
#line 2523 "parser.tab.c"
    break;

  case 20: /* statementListItemWithoutEmptyStatement: ifStatement  */
#line 160 ".\\parser.y"
                                    { Print("- R: ifStatement -> statementListItemWithoutEmptyStatement"); }
#line 2529 "parser.tab.c"
    break;

  case 21: /* statementListItemWithoutEmptyStatement: iterationStatement  */
#line 161 ".\\parser.y"
                                    { Print("- R: iterationStatement -> statementListItemWithoutEmptyStatement"); }
#line 2535 "parser.tab.c"
    break;

  case 22: /* statementListItemWithoutEmptyStatement: returnStatement  */
#line 163 ".\\parser.y"
        { 
            if ( !isInFunctionBody ) { 
                yyerror("illegal return statement."); YYERROR;
            } 
            Print("- R: returnStatement -> statementListItemWithoutEmptyStatement"); 
        }
#line 2546 "parser.tab.c"
    break;

  case 23: /* statementListItemWithoutEmptyStatement: blockStatement  */
#line 169 ".\\parser.y"
                                    { Print("- R: blockStatement -> statementListItemWithoutEmptyStatement"); }
#line 2552 "parser.tab.c"
    break;

  case 25: /* emptyStatement: ';'  */
#line 176 ".\\parser.y"
        { 
            if ( isASIActivated ) {
                std::string text(yytext_ptr, yyleng);
                yyerror(("syntax error on token: " + text).c_str()); YYERROR;
            }
            Print("- R: ';' -> emptyStatement"); 
        }
#line 2564 "parser.tab.c"
    break;

  case 26: /* blockStatement: '{' '}'  */
#line 186 ".\\parser.y"
              { Print("- R: '{' '}' -> blockStatement"); }
#line 2570 "parser.tab.c"
    break;

  case 27: /* blockStatement: '{' statementList '}'  */
#line 187 ".\\parser.y"
                            { Print("- R: '{' statementList '}' -> blockStatement"); }
#line 2576 "parser.tab.c"
    break;

  case 28: /* initializer: '=' singleExpression  */
#line 191 ".\\parser.y"
                           { Print("- R: '=' singleExpression -> initializer"); }
#line 2582 "parser.tab.c"
    break;

  case 29: /* type: primaryType  */
#line 197 ".\\parser.y"
                  { Print("- R: primaryType -> type"); }
#line 2588 "parser.tab.c"
    break;

  case 30: /* primaryType: '(' type ')'  */
#line 201 ".\\parser.y"
                                                { Print("- R: '(' type ')' -> primaryType"); }
#line 2594 "parser.tab.c"
    break;

  case 31: /* primaryType: predefinedType  */
#line 202 ".\\parser.y"
                                                { Print("- R: predefinedType -> primaryType"); }
#line 2600 "parser.tab.c"
    break;

  case 32: /* primaryType: primaryType '[' ']'  */
#line 203 ".\\parser.y"
                                                { Print("- R: primaryType '[' ']' -> primaryType"); }
#line 2606 "parser.tab.c"
    break;

  case 33: /* primaryType: '[' tupleTypeElements ']'  */
#line 204 ".\\parser.y"
                                                { Print("- R: '[' tupleTypeElements ']' -> primaryType"); }
#line 2612 "parser.tab.c"
    break;

  case 34: /* primaryType: ENDL_BRACKET_OPEN tupleTypeElements ']'  */
#line 205 ".\\parser.y"
                                                { Print("- R: '[' tupleTypeElements ']' -> primaryType"); }
#line 2618 "parser.tab.c"
    break;

  case 35: /* tupleTypeElements: %empty  */
#line 209 ".\\parser.y"
                                    { Print("- R: #empty# -> tupleTypeElements"); }
#line 2624 "parser.tab.c"
    break;

  case 36: /* tupleTypeElements: type  */
#line 210 ".\\parser.y"
                                    { Print("- R: type -> tupleTypeElements"); }
#line 2630 "parser.tab.c"
    break;

  case 37: /* tupleTypeElements: tupleTypeElements ',' type  */
#line 211 ".\\parser.y"
                                    { Print("- R: tupleTypeElements ',' type -> tupleTypeElements"); }
#line 2636 "parser.tab.c"
    break;

  case 38: /* predefinedType: ANY  */
#line 215 ".\\parser.y"
                        { Print("- R: ANY -> predefinedType"); }
#line 2642 "parser.tab.c"
    break;

  case 39: /* predefinedType: NUMBER  */
#line 216 ".\\parser.y"
                        { Print("- R: NUMBER -> predefinedType"); }
#line 2648 "parser.tab.c"
    break;

  case 40: /* predefinedType: STRING  */
#line 217 ".\\parser.y"
                        { Print("- R: STRING -> predefinedType"); }
#line 2654 "parser.tab.c"
    break;

  case 41: /* predefinedType: BOOLEAN  */
#line 218 ".\\parser.y"
                        { Print("- R: BOOLEAN -> predefinedType"); }
#line 2660 "parser.tab.c"
    break;

  case 42: /* predefinedType: NEVER  */
#line 219 ".\\parser.y"
                        { Print("- R: NEVER -> predefinedType"); }
#line 2666 "parser.tab.c"
    break;

  case 43: /* predefinedType: UNKNOWN  */
#line 220 ".\\parser.y"
                        { Print("- R: UNKNOWN -> predefinedType"); }
#line 2672 "parser.tab.c"
    break;

  case 44: /* predefinedType: UNDEFINED  */
#line 221 ".\\parser.y"
                        { Print("- R: UNDEFINED -> predefinedType"); }
#line 2678 "parser.tab.c"
    break;

  case 45: /* predefinedType: VOID  */
#line 222 ".\\parser.y"
                        { Print("- R: VOID -> predefinedType"); }
#line 2684 "parser.tab.c"
    break;

  case 46: /* predefinedType: NULL_KW  */
#line 223 ".\\parser.y"
                        { Print("- R: NULL_KW -> predefinedType"); }
#line 2690 "parser.tab.c"
    break;

  case 47: /* predefinedType: TRUE_KW  */
#line 224 ".\\parser.y"
                        { Print("- R: TRUE_WD -> predefinedType"); }
#line 2696 "parser.tab.c"
    break;

  case 48: /* predefinedType: FALSE_KW  */
#line 225 ".\\parser.y"
                        { Print("- R: FALSE_KW -> predefinedType"); }
#line 2702 "parser.tab.c"
    break;

  case 49: /* predefinedType: STRING_LIT  */
#line 226 ".\\parser.y"
                        { Print("- R: STRING_LIT -> predefinedType"); }
#line 2708 "parser.tab.c"
    break;

  case 50: /* predefinedType: INT_LIT  */
#line 227 ".\\parser.y"
                        { Print("- R: INT_LIT -> predefinedType"); }
#line 2714 "parser.tab.c"
    break;

  case 51: /* predefinedType: FLOAT_LIT  */
#line 228 ".\\parser.y"
                        { Print("- R: FLOAT_LIT -> predefinedType"); }
#line 2720 "parser.tab.c"
    break;

  case 52: /* predefinedType: TEMPLATE_LITERAL  */
#line 229 ".\\parser.y"
                        { Print("- R: TEMPLATE_LITERAL -> predefinedType"); }
#line 2726 "parser.tab.c"
    break;

  case 53: /* typeAnnotationOpt: %empty  */
#line 233 ".\\parser.y"
                        { Print("- R: # empty # -> typeAnnotationOpt"); }
#line 2732 "parser.tab.c"
    break;

  case 54: /* typeAnnotationOpt: typeAnnotation  */
#line 234 ".\\parser.y"
                        { Print("- R: typeAnnotation -> typeAnnotationOpt"); }
#line 2738 "parser.tab.c"
    break;

  case 55: /* typeAnnotation: ':' type  */
#line 238 ".\\parser.y"
               { Print("- R: ':' type -> typeAnnotation"); }
#line 2744 "parser.tab.c"
    break;

  case 56: /* arrayLiteral: '[' elementList ']'  */
#line 243 ".\\parser.y"
                                        { Print("- R: [ elementList ']' -> arrayLiteral"); }
#line 2750 "parser.tab.c"
    break;

  case 57: /* arrayLiteral: ENDL_BRACKET_OPEN elementList ']'  */
#line 244 ".\\parser.y"
                                        { Print("- R: ENDL_BRACKET_OPEN elementList ']' -> arrayLiteral"); }
#line 2756 "parser.tab.c"
    break;

  case 58: /* elementList: elementListItem  */
#line 248 ".\\parser.y"
                      { Print("- R: elementListItem -> elementList"); }
#line 2762 "parser.tab.c"
    break;

  case 59: /* elementList: elementList ',' elementListItem  */
#line 249 ".\\parser.y"
                                                            { Print("- R: elementList ',' elementListItem -> elementList"); }
#line 2768 "parser.tab.c"
    break;

  case 60: /* elementListItem: %empty  */
#line 253 ".\\parser.y"
                  { Print("- R: #empty# -> elementListItem"); }
#line 2774 "parser.tab.c"
    break;

  case 61: /* elementListItem: singleExpression  */
#line 254 ".\\parser.y"
                       { Print("- R: singleExpression -> elementListItem"); }
#line 2780 "parser.tab.c"
    break;

  case 62: /* elementListItem: singleExpression ','  */
#line 255 ".\\parser.y"
                           { Print("- R: singleExpression ',' -> elementListItem"); }
#line 2786 "parser.tab.c"
    break;

  case 63: /* expressionStatement: singleExpression ';'  */
#line 261 ".\\parser.y"
                           { Print("- R: expressionList ';' -> expressionStatement"); (yyval.exprStmt) = (yyvsp[-1].exprStmt); }
#line 2792 "parser.tab.c"
    break;

  case 64: /* singleExpressionOpt: %empty  */
#line 265 ".\\parser.y"
                        { Print("- R: #empty# -> singleExpressionOpt"); }
#line 2798 "parser.tab.c"
    break;

  case 65: /* singleExpressionOpt: singleExpression  */
#line 266 ".\\parser.y"
                          { Print("- R: singleExpression -> singleExpressionOpt"); }
#line 2804 "parser.tab.c"
    break;

  case 66: /* singleExpression: identifier  */
#line 270 ".\\parser.y"
                    { Print("- R: identifier -> singleExpression"); (yyval.exprStmt) = createIDExpressionNode((yyvsp[0].ident)); }
#line 2810 "parser.tab.c"
    break;

  case 67: /* singleExpression: THIS  */
#line 271 ".\\parser.y"
                    { Print("- R: THIS -> singleExpression"); }
#line 2816 "parser.tab.c"
    break;

  case 68: /* singleExpression: SUPER  */
#line 272 ".\\parser.y"
                    { Print("- R: SUPER -> singleExpression"); }
#line 2822 "parser.tab.c"
    break;

  case 69: /* singleExpression: TRUE_KW  */
#line 273 ".\\parser.y"
                    { Print("- R: TRUE_LITERAL -> singleExpression"); }
#line 2828 "parser.tab.c"
    break;

  case 70: /* singleExpression: FALSE_KW  */
#line 274 ".\\parser.y"
                    { Print("- R: FALSE_LITERAL -> singleExpression"); }
#line 2834 "parser.tab.c"
    break;

  case 71: /* singleExpression: NULL_KW  */
#line 275 ".\\parser.y"
                    { Print("- R: NULL_LITERAL -> singleExpression"); }
#line 2840 "parser.tab.c"
    break;

  case 72: /* singleExpression: STRING_LIT  */
#line 277 ".\\parser.y"
                        { Print("- R: STRING_LIT -> singleExpression"); }
#line 2846 "parser.tab.c"
    break;

  case 73: /* singleExpression: INT_LIT  */
#line 278 ".\\parser.y"
                        { Print("- R: INT_LIT -> singleExpression"); }
#line 2852 "parser.tab.c"
    break;

  case 74: /* singleExpression: FLOAT_LIT  */
#line 279 ".\\parser.y"
                        { Print("- R: FLOAT_LIT -> singleExpression"); }
#line 2858 "parser.tab.c"
    break;

  case 75: /* singleExpression: TEMPLATE_LITERAL  */
#line 280 ".\\parser.y"
                        { Print("- R: TEMPLATE_LITERAL -> singleExpression"); }
#line 2864 "parser.tab.c"
    break;

  case 76: /* singleExpression: '-' singleExpression  */
#line 282 ".\\parser.y"
                                        { Print("- R: '-' singleExpression -> singleExpression"); }
#line 2870 "parser.tab.c"
    break;

  case 77: /* singleExpression: '+' singleExpression  */
#line 283 ".\\parser.y"
                                        { Print("- R: '+' singleExpression -> singleExpression"); }
#line 2876 "parser.tab.c"
    break;

  case 78: /* singleExpression: '!' singleExpression  */
#line 285 ".\\parser.y"
                           { Print("- R: '!' singleExpression -> singleExpression"); }
#line 2882 "parser.tab.c"
    break;

  case 79: /* singleExpression: singleExpression OPERATOR_INCREMENT  */
#line 287 ".\\parser.y"
                                                               { Print("- R: singleExpression OPERATOR_INCREMENT -> singleExpression"); }
#line 2888 "parser.tab.c"
    break;

  case 80: /* singleExpression: singleExpression OPERATOR_DECREMENT  */
#line 288 ".\\parser.y"
                                                               { Print("- R: singleExpression OPERATOR_DECREMENT -> singleExpression"); }
#line 2894 "parser.tab.c"
    break;

  case 81: /* singleExpression: ENDL_OPERATOR_INCREMENT singleExpression  */
#line 290 ".\\parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 2900 "parser.tab.c"
    break;

  case 82: /* singleExpression: ENDL_OPERATOR_DECREMENT singleExpression  */
#line 291 ".\\parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 2906 "parser.tab.c"
    break;

  case 83: /* singleExpression: OPERATOR_INCREMENT singleExpression  */
#line 292 ".\\parser.y"
                                                               { Print("- R: OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 2912 "parser.tab.c"
    break;

  case 84: /* singleExpression: OPERATOR_DECREMENT singleExpression  */
#line 293 ".\\parser.y"
                                                               { Print("- R: OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 2918 "parser.tab.c"
    break;

  case 85: /* singleExpression: singleExpression '+' singleExpression  */
#line 295 ".\\parser.y"
                                            { Print("- R: singleExpression '+' singleExpression -> singleExpression"); }
#line 2924 "parser.tab.c"
    break;

  case 86: /* singleExpression: singleExpression '-' singleExpression  */
#line 296 ".\\parser.y"
                                            { Print("- R: singleExpression '-' singleExpression -> singleExpression"); }
#line 2930 "parser.tab.c"
    break;

  case 87: /* singleExpression: singleExpression '*' singleExpression  */
#line 297 ".\\parser.y"
                                            { Print("- R: singleExpression '*' singleExpression -> singleExpression"); }
#line 2936 "parser.tab.c"
    break;

  case 88: /* singleExpression: singleExpression '/' singleExpression  */
#line 298 ".\\parser.y"
                                            { Print("- R: singleExpression '/' singleExpression -> singleExpression"); }
#line 2942 "parser.tab.c"
    break;

  case 89: /* singleExpression: singleExpression '<' singleExpression  */
#line 299 ".\\parser.y"
                                            { Print("- R: singleExpression '<' singleExpression -> singleExpression"); }
#line 2948 "parser.tab.c"
    break;

  case 90: /* singleExpression: singleExpression '>' singleExpression  */
#line 300 ".\\parser.y"
                                            { Print("- R: singleExpression '>' singleExpression -> singleExpression"); }
#line 2954 "parser.tab.c"
    break;

  case 91: /* singleExpression: singleExpression OPERATOR_EQUAL singleExpression  */
#line 303 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_EQUAL singleExpression -> singleExpression"); }
#line 2960 "parser.tab.c"
    break;

  case 92: /* singleExpression: singleExpression OPERATOR_NOT_EQUAL singleExpression  */
#line 306 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_NOT_EQUAL singleExpression -> singleExpression"); }
#line 2966 "parser.tab.c"
    break;

  case 93: /* singleExpression: singleExpression OPERATOR_STRICT_EQUAL singleExpression  */
#line 309 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_STRICT_EQUAL singleExpression -> singleExpression"); }
#line 2972 "parser.tab.c"
    break;

  case 94: /* singleExpression: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression  */
#line 312 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression -> singleExpression"); }
#line 2978 "parser.tab.c"
    break;

  case 95: /* singleExpression: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression  */
#line 315 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression -> singleExpression"); }
#line 2984 "parser.tab.c"
    break;

  case 96: /* singleExpression: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression  */
#line 318 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression -> singleExpression"); }
#line 2990 "parser.tab.c"
    break;

  case 97: /* singleExpression: singleExpression '=' singleExpression  */
#line 321 ".\\parser.y"
        { Print("- R: singleExpression '=' singleExpression -> singleExpression"); }
#line 2996 "parser.tab.c"
    break;

  case 98: /* singleExpression: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression  */
#line 324 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression -> singleExpression"); }
#line 3002 "parser.tab.c"
    break;

  case 99: /* singleExpression: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression  */
#line 327 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression -> singleExpression"); }
#line 3008 "parser.tab.c"
    break;

  case 100: /* singleExpression: singleExpression OPERATOR_ASSIGN_PLUS singleExpression  */
#line 330 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_PLUS singleExpression -> singleExpression"); }
#line 3014 "parser.tab.c"
    break;

  case 101: /* singleExpression: singleExpression OPERATOR_ASSIGN_MINUS singleExpression  */
#line 333 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_MINUS singleExpression -> singleExpression"); }
#line 3020 "parser.tab.c"
    break;

  case 102: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression  */
#line 336 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression -> singleExpression"); }
#line 3026 "parser.tab.c"
    break;

  case 103: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression  */
#line 339 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression -> singleExpression"); }
#line 3032 "parser.tab.c"
    break;

  case 104: /* singleExpression: singleExpression OPERATOR_LOGICAL_OR singleExpression  */
#line 342 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_LOGICAL_OR singleExpression -> singleExpression"); }
#line 3038 "parser.tab.c"
    break;

  case 105: /* singleExpression: singleExpression OPERATOR_LOGICAL_AND singleExpression  */
#line 345 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_LOGICAL_AND singleExpression -> singleExpression"); }
#line 3044 "parser.tab.c"
    break;

  case 106: /* singleExpression: singleExpression INSTANCEOF singleExpression  */
#line 347 ".\\parser.y"
                                                    { Print("- R: singleExpression INSTANCEOF singleExpression -> singleExpression"); }
#line 3050 "parser.tab.c"
    break;

  case 107: /* singleExpression: singleExpression IN singleExpression  */
#line 348 ".\\parser.y"
                                                    { Print("- R: singleExpression IN singleExpression -> singleExpression"); }
#line 3056 "parser.tab.c"
    break;

  case 108: /* singleExpression: singleExpression TEMPLATE_LITERAL  */
#line 351 ".\\parser.y"
        { Print("- R: singleExpression TEMPLATE_LITERAL -> singleExpression"); }
#line 3062 "parser.tab.c"
    break;

  case 109: /* singleExpression: singleExpression '?' singleExpression ':' singleExpression  */
#line 354 ".\\parser.y"
        { Print("- R: singleExpression '?' singleExpression ':' singleExpression -> singleExpression"); }
#line 3068 "parser.tab.c"
    break;

  case 110: /* singleExpression: singleExpression ',' singleExpression  */
#line 357 ".\\parser.y"
        { Print("- R: singleExpression ',' singleExpressionn -> singleExpression"); }
#line 3074 "parser.tab.c"
    break;

  case 111: /* singleExpression: '(' singleExpression ')'  */
#line 359 ".\\parser.y"
                               { Print("- R: '(' expressionList ')' -> singleExpression"); }
#line 3080 "parser.tab.c"
    break;

  case 112: /* singleExpression: singleExpression '(' ')'  */
#line 361 ".\\parser.y"
                               { Print("- R: singleExpression '(' ')' -> singleExpression"); }
#line 3086 "parser.tab.c"
    break;

  case 113: /* singleExpression: singleExpression '(' singleExpression ')'  */
#line 362 ".\\parser.y"
                                                { Print("- R: singleExpression '(' singleExpression ')' -> singleExpression"); }
#line 3092 "parser.tab.c"
    break;

  case 114: /* singleExpression: singleExpression '(' singleExpression ',' ')'  */
#line 363 ".\\parser.y"
                                                    { Print("- R: singleExpression '(' singleExpression ',' ')' -> singleExpression"); }
#line 3098 "parser.tab.c"
    break;

  case 115: /* singleExpression: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression  */
#line 366 ".\\parser.y"
        { Print("- R: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression -> singleExpression"); }
#line 3104 "parser.tab.c"
    break;

  case 116: /* singleExpression: singleExpression '.' identifier  */
#line 368 ".\\parser.y"
                                      { Print("- R: singleExpression '.' identifier -> singleExpression"); }
#line 3110 "parser.tab.c"
    break;

  case 117: /* singleExpression: arrayLiteral  */
#line 370 ".\\parser.y"
                                                              { Print("- R: arrayLiteral -> singleExpression"); }
#line 3116 "parser.tab.c"
    break;

  case 118: /* singleExpression: singleExpression '[' singleExpression ']'  */
#line 371 ".\\parser.y"
                                                              { Print("- R: singleExpression '[' expressionList ']' -> singleExpression"); }
#line 3122 "parser.tab.c"
    break;

  case 119: /* singleExpression: singleExpression ENDL_BRACKET_OPEN singleExpression ']'  */
#line 372 ".\\parser.y"
                                                              { Print("- R: singleExpression ENDL_BRACKET_OPEN expressionList ']' -> singleExpression"); }
#line 3128 "parser.tab.c"
    break;

  case 120: /* singleExpression: NEW singleExpression  */
#line 374 ".\\parser.y"
                           { Print("- R: NEW singleExpression -> singleExpression"); }
#line 3134 "parser.tab.c"
    break;

  case 121: /* varStatement: varModifier varDeclarationList ';'  */
#line 380 ".\\parser.y"
                                         { Print("- R: varModifier varDeclarationList ';' -> varStatement"); }
#line 3140 "parser.tab.c"
    break;

  case 123: /* varDeclarationList: varDeclaration  */
#line 385 ".\\parser.y"
                                            { Print("- R: varDeclaration -> varDeclarationList"); }
#line 3146 "parser.tab.c"
    break;

  case 124: /* varDeclarationList: varDeclarationList ',' varDeclaration  */
#line 386 ".\\parser.y"
                                            { Print("- R: varDeclarationList ',' varDeclaration -> varDeclarationList"); }
#line 3152 "parser.tab.c"
    break;

  case 125: /* varDeclaration: identifier typeAnnotationOpt  */
#line 390 ".\\parser.y"
                                                           { Print("- R: identifier typeAnnotationOpt -> varDeclaration"); }
#line 3158 "parser.tab.c"
    break;

  case 126: /* varDeclaration: identifier typeAnnotationOpt '=' singleExpression  */
#line 391 ".\\parser.y"
                                                           { Print("- R: identifier typeAnnotationOpt '=' singleExpression -> varDeclaration"); }
#line 3164 "parser.tab.c"
    break;

  case 127: /* varModifier: VAR  */
#line 395 ".\\parser.y"
            { Print("- R: VAR -> varModifier"); }
#line 3170 "parser.tab.c"
    break;

  case 128: /* varModifier: LET  */
#line 396 ".\\parser.y"
            { Print("- R: LET -> varModifier"); }
#line 3176 "parser.tab.c"
    break;

  case 129: /* varModifier: CONST  */
#line 397 ".\\parser.y"
            { Print("- R: CONST -> varModifier"); }
#line 3182 "parser.tab.c"
    break;

  case 130: /* ifStatement: IF '(' singleExpression ')' statementListItemWithoutEmptyStatement  */
#line 404 ".\\parser.y"
        { Print("- R: IF '(' expressionList ')' statementListItem -> ifStatement"); }
#line 3188 "parser.tab.c"
    break;

  case 131: /* ifStatement: IF '(' singleExpression ')' statementListItemWithoutEmptyStatement ELSE statementListItem  */
#line 407 ".\\parser.y"
        { Print("- R: IF '(' expressionList ')' statementListItem ELSE statementListItem -> ifStatement"); }
#line 3194 "parser.tab.c"
    break;

  case 132: /* $@1: %empty  */
#line 413 ".\\parser.y"
                                                          { doWhileASI(); }
#line 3200 "parser.tab.c"
    break;

  case 133: /* iterationStatement: DO statementListItem WHILE '(' singleExpression ')' $@1 ';'  */
#line 414 ".\\parser.y"
        { Print("- R: DO statementListItem WHILE '(' expressionList ')' ';' -> iterationStatement"); }
#line 3206 "parser.tab.c"
    break;

  case 134: /* iterationStatement: WHILE '(' singleExpression ')' statementListItem  */
#line 417 ".\\parser.y"
        { Print("- R: WHILE '(' expressionList ')' statementListItem -> iterationStatement"); }
#line 3212 "parser.tab.c"
    break;

  case 135: /* $@2: %empty  */
#line 419 ".\\parser.y"
                                                                                        { isInForHeader = 0; }
#line 3218 "parser.tab.c"
    break;

  case 136: /* iterationStatement: forHeader singleExpressionOpt ';' singleExpressionOpt ';' singleExpressionOpt ')' $@2 statementListItem  */
#line 420 ".\\parser.y"
        { Print("- R: FOR '(' singleExpressionOpt ';' singleExpressionOpt ';' singleExpressionOpt ')' statementListItem -> iterationStatement"); }
#line 3224 "parser.tab.c"
    break;

  case 137: /* $@3: %empty  */
#line 422 ".\\parser.y"
                                                                                                   { isInForHeader = 0; }
#line 3230 "parser.tab.c"
    break;

  case 138: /* iterationStatement: forHeader varModifier varDeclarationList ';' singleExpressionOpt ';' singleExpressionOpt ')' $@3 statementListItem  */
#line 423 ".\\parser.y"
        { Print("- R: FOR '(' varModifier varDeclarationList ';' singleExpressionOpt ';' singleExpressionOpt ')' statementListItem -> iterationStatement"); }
#line 3236 "parser.tab.c"
    break;

  case 139: /* $@4: %empty  */
#line 425 ".\\parser.y"
                                                         { isInForHeader = 0; }
#line 3242 "parser.tab.c"
    break;

  case 140: /* iterationStatement: forHeader singleExpression IN singleExpression ')' $@4 statementListItem  */
#line 426 ".\\parser.y"
        { Print("- R: FOR '(' singleExpression IN singleExpression ')' statementListItem -> iterationStatement"); }
#line 3248 "parser.tab.c"
    break;

  case 141: /* $@5: %empty  */
#line 428 ".\\parser.y"
                                                                   { isInForHeader = 0; }
#line 3254 "parser.tab.c"
    break;

  case 142: /* iterationStatement: forHeader varModifier varDeclaration IN singleExpression ')' $@5 statementListItem  */
#line 429 ".\\parser.y"
        { Print("- R: FOR '(' varModifier varDeclaration IN expressionList ')' statementListItem -> iterationStatement"); }
#line 3260 "parser.tab.c"
    break;

  case 143: /* forHeader: FOR '('  */
#line 433 ".\\parser.y"
               { isInForHeader = 1; }
#line 3266 "parser.tab.c"
    break;

  case 144: /* returnStatement: RETURN ';'  */
#line 439 ".\\parser.y"
                                    { Print("- R: RETURN ';' -> returnStatement"); }
#line 3272 "parser.tab.c"
    break;

  case 145: /* returnStatement: RETURN singleExpression ';'  */
#line 440 ".\\parser.y"
                                    { Print("- R: RETURN singleExpression ';' -> returnStatement"); }
#line 3278 "parser.tab.c"
    break;

  case 146: /* functionDeclaration: FUNCTION identifier callSignature functionBody  */
#line 444 ".\\parser.y"
                                                     { Print("- R: FUNCTION ID callSignature functionBody -> functionDeclaration"); }
#line 3284 "parser.tab.c"
    break;

  case 147: /* functionBody: '{' '}'  */
#line 448 ".\\parser.y"
                                                        { Print("- R: '{' '}' -> functionBody"); }
#line 3290 "parser.tab.c"
    break;

  case 148: /* $@6: %empty  */
#line 449 ".\\parser.y"
          { isInFunctionBody = 1; }
#line 3296 "parser.tab.c"
    break;

  case 149: /* functionBody: '{' $@6 statementList '}'  */
#line 449 ".\\parser.y"
                                                        { isInFunctionBody = 0; Print("- R: '{' statementList '}' -> functionBody"); }
#line 3302 "parser.tab.c"
    break;

  case 150: /* callSignature: '(' parameterList ')' typeAnnotationOpt  */
#line 453 ".\\parser.y"
                                               { Print("- R : '(' parameterList ')' typeAnnotation -> callSignature"); }
#line 3308 "parser.tab.c"
    break;

  case 151: /* parameterList: %empty  */
#line 457 ".\\parser.y"
                         { Print("- R: #empty# -> parameterList"); }
#line 3314 "parser.tab.c"
    break;

  case 152: /* parameterList: requiredParameterList  */
#line 458 ".\\parser.y"
                            { Print("- R: requiredParameterList -> parameterList"); }
#line 3320 "parser.tab.c"
    break;

  case 153: /* parameterList: requiredParameterList ','  */
#line 459 ".\\parser.y"
                                { Print("- R: requiredParameterList ',' -> parameterList"); }
#line 3326 "parser.tab.c"
    break;

  case 154: /* requiredParameterList: requiredParameter  */
#line 463 ".\\parser.y"
                                                    { Print("- R: requiredParameter -> requiredParameterList"); }
#line 3332 "parser.tab.c"
    break;

  case 155: /* requiredParameterList: requiredParameterList ',' requiredParameter  */
#line 464 ".\\parser.y"
                                                    { Print("- R: requiredParameterList ',' requiredParameter -> requiredParameterList"); }
#line 3338 "parser.tab.c"
    break;

  case 156: /* requiredParameter: identifier typeAnnotationOpt  */
#line 468 ".\\parser.y"
                                   { Print("- R: ID typeAnnotationOpt -> requiredParameter"); }
#line 3344 "parser.tab.c"
    break;

  case 157: /* classDeclaration: CLASS identifier classTail  */
#line 474 ".\\parser.y"
                                                { Print("- R: CLASS identifier classTail -> classDeclaration"); }
#line 3350 "parser.tab.c"
    break;

  case 158: /* classDeclaration: CLASS identifier classHeritage classTail  */
#line 475 ".\\parser.y"
                                                { Print("- R: CLASS identifier classHeritage classTail -> classDeclaration"); }
#line 3356 "parser.tab.c"
    break;

  case 159: /* classHeritage: EXTENDS identifier  */
#line 479 ".\\parser.y"
                         { Print("- R: EXTENDS identifier -> classHeritage"); }
#line 3362 "parser.tab.c"
    break;

  case 160: /* classTail: '{' '}'  */
#line 483 ".\\parser.y"
                                { Print("- R: '{' '}' -> classTail"); }
#line 3368 "parser.tab.c"
    break;

  case 161: /* classTail: '{' classElementList '}'  */
#line 484 ".\\parser.y"
                                { Print("- R: '{' classElementList '}' -> classTail"); }
#line 3374 "parser.tab.c"
    break;

  case 162: /* classElementList: classElement  */
#line 488 ".\\parser.y"
                   { Print("- R: classElement -> classElementList"); }
#line 3380 "parser.tab.c"
    break;

  case 163: /* classElementList: classElementList classElement  */
#line 489 ".\\parser.y"
                                    { Print("- R: classElementList classElement -> classElementList"); }
#line 3386 "parser.tab.c"
    break;

  case 164: /* classElement: CONSTRUCTOR constructorCallSignature functionBody  */
#line 493 ".\\parser.y"
                                                        { Print("- R: CONSTRUCTOR callSignature functionBody -> classElement"); }
#line 3392 "parser.tab.c"
    break;

  case 165: /* classElement: propertyName typeAnnotationOpt ';'  */
#line 496 ".\\parser.y"
                                                       { Print("- R: propertyName typeAnnotationOpt ';' -> classElement"); }
#line 3398 "parser.tab.c"
    break;

  case 166: /* classElement: propertyName typeAnnotationOpt initializer ';'  */
#line 497 ".\\parser.y"
                                                       { Print("- R: propertyName typeAnnotationOpt initializer ';' -> classElement"); }
#line 3404 "parser.tab.c"
    break;

  case 167: /* classElement: propertyName callSignature functionBody  */
#line 500 ".\\parser.y"
                                              { Print("- R: propertyName callSignature functionBody -> classElement"); }
#line 3410 "parser.tab.c"
    break;

  case 168: /* classElement: GET propertyName '(' ')' typeAnnotationOpt functionBody  */
#line 503 ".\\parser.y"
                                                               { Print("- R: GET propertyName '(' ')' typeAnnotationOpt functionBody -> classElement"); }
#line 3416 "parser.tab.c"
    break;

  case 169: /* classElement: SET propertyName callSignature functionBody  */
#line 504 ".\\parser.y"
                                                            { Print("- R: SET propertyName callSignature functionBody -> classElement"); }
#line 3422 "parser.tab.c"
    break;

  case 170: /* constructorCallSignature: '(' parameterList ')'  */
#line 508 ".\\parser.y"
                            { Print("- R: '(' parameterList ')' -> constructorCallSignature"); }
#line 3428 "parser.tab.c"
    break;

  case 171: /* propertyName: identifier  */
#line 512 ".\\parser.y"
                 { Print("- R: identifier -> propertyName"); }
#line 3434 "parser.tab.c"
    break;

  case 172: /* identifier: ID  */
#line 516 ".\\parser.y"
                { Print("- R: ID -> identifier"); (yyval.ident) = (yyvsp[0].ident); }
#line 3440 "parser.tab.c"
    break;

  case 173: /* identifier: ASYNC  */
#line 517 ".\\parser.y"
                { Print("- R: ASYNC -> identifier"); (yyval.ident) = "async"; }
#line 3446 "parser.tab.c"
    break;

  case 174: /* identifier: AS  */
#line 518 ".\\parser.y"
                { Print("- R: AS -> identifier"); (yyval.ident) = "as";}
#line 3452 "parser.tab.c"
    break;

  case 175: /* identifier: FROM  */
#line 519 ".\\parser.y"
                { Print("- R: FROM -> identifier"); (yyval.ident) = "from";}
#line 3458 "parser.tab.c"
    break;

  case 176: /* identifier: YIELD  */
#line 520 ".\\parser.y"
                { Print("- R: YIELD -> identifier"); (yyval.ident) = "yield";}
#line 3464 "parser.tab.c"
    break;

  case 177: /* identifier: ANY  */
#line 521 ".\\parser.y"
                { Print("- R: ANY -> identifier"); (yyval.ident) = "any";}
#line 3470 "parser.tab.c"
    break;

  case 178: /* identifier: NUMBER  */
#line 522 ".\\parser.y"
                { Print("- R: NUMBER -> identifier"); (yyval.ident) = "number"; }
#line 3476 "parser.tab.c"
    break;

  case 179: /* identifier: BOOLEAN  */
#line 523 ".\\parser.y"
                { Print("- R: BOOLEAN -> identifier"); (yyval.ident) = "boolean"; }
#line 3482 "parser.tab.c"
    break;

  case 180: /* identifier: STRING  */
#line 524 ".\\parser.y"
                { Print("- R: STRING -> identifier"); (yyval.ident) = "string"; }
#line 3488 "parser.tab.c"
    break;

  case 181: /* identifier: UNIQUE  */
#line 525 ".\\parser.y"
                { Print("- R: UNIQUE -> identifier"); (yyval.ident) = "unique"; }
#line 3494 "parser.tab.c"
    break;

  case 182: /* identifier: SYMBOL  */
#line 526 ".\\parser.y"
                { Print("- R: SYMBOL -> identifier"); (yyval.ident) = "symbol"; }
#line 3500 "parser.tab.c"
    break;

  case 183: /* identifier: NEVER  */
#line 527 ".\\parser.y"
                { Print("- R: NEVER -> identifier"); (yyval.ident) = "never"; }
#line 3506 "parser.tab.c"
    break;

  case 184: /* identifier: UNDEFINED  */
#line 528 ".\\parser.y"
                { Print("- R: UNDEFINED -> identifier"); (yyval.ident) = "undefined"; }
#line 3512 "parser.tab.c"
    break;

  case 185: /* identifier: OBJECT  */
#line 529 ".\\parser.y"
                { Print("- R: OBJECT -> identifier"); (yyval.ident) = "object"; }
#line 3518 "parser.tab.c"
    break;

  case 186: /* identifier: KEYOF  */
#line 530 ".\\parser.y"
                { Print("- R: KEYOF -> identifier"); (yyval.ident) = "keyof"; }
#line 3524 "parser.tab.c"
    break;

  case 187: /* identifier: NAMESPACE  */
#line 531 ".\\parser.y"
                { Print("- R: NAMESPACE -> identifier"); (yyval.ident) = "namespace"; }
#line 3530 "parser.tab.c"
    break;

  case 188: /* identifier: ABSTRACT  */
#line 532 ".\\parser.y"
                { Print("- R: ABSTRACT -> identifier"); (yyval.ident) = "abstract"; }
#line 3536 "parser.tab.c"
    break;

  case 189: /* identifier: REQUIRE  */
#line 533 ".\\parser.y"
                { Print("- R: REQUIRE -> identifier"); (yyval.ident) = "require"; }
#line 3542 "parser.tab.c"
    break;


#line 3546 "parser.tab.c"

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

#line 536 ".\\parser.y"



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


