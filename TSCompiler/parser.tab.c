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

#line 100 "parser.tab.c"

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
    ENDL = 258,                    /* ENDL  */
    VAR = 259,                     /* VAR  */
    LET = 260,                     /* LET  */
    CONST = 261,                   /* CONST  */
    IF = 262,                      /* IF  */
    ELSE = 263,                    /* ELSE  */
    FUNCTION = 264,                /* FUNCTION  */
    CLASS = 265,                   /* CLASS  */
    EXTENDS = 266,                 /* EXTENDS  */
    GET = 267,                     /* GET  */
    SET = 268,                     /* SET  */
    DO = 269,                      /* DO  */
    WHILE = 270,                   /* WHILE  */
    FOR = 271,                     /* FOR  */
    RETURN = 272,                  /* RETURN  */
    SUPER = 273,                   /* SUPER  */
    THIS = 274,                    /* THIS  */
    NEW = 275,                     /* NEW  */
    ASYNC = 276,                   /* ASYNC  */
    AS = 277,                      /* AS  */
    FROM = 278,                    /* FROM  */
    YIELD = 279,                   /* YIELD  */
    KEYOF = 280,                   /* KEYOF  */
    CONSTRUCTOR = 281,             /* CONSTRUCTOR  */
    NAMESPACE = 282,               /* NAMESPACE  */
    ABSTRACT = 283,                /* ABSTRACT  */
    REQUIRE = 284,                 /* REQUIRE  */
    ANY = 285,                     /* ANY  */
    NUMBER = 286,                  /* NUMBER  */
    BOOLEAN = 287,                 /* BOOLEAN  */
    STRING = 288,                  /* STRING  */
    NEVER = 289,                   /* NEVER  */
    UNDEFINED = 290,               /* UNDEFINED  */
    UNIQUE = 291,                  /* UNIQUE  */
    SYMBOL = 292,                  /* SYMBOL  */
    OBJECT = 293,                  /* OBJECT  */
    VOID = 294,                    /* VOID  */
    NULL_KW = 295,                 /* NULL_KW  */
    TRUE_KW = 296,                 /* TRUE_KW  */
    FALSE_KW = 297,                /* FALSE_KW  */
    TEMPLATE_LIT = 298,            /* TEMPLATE_LIT  */
    STRING_LIT = 299,              /* STRING_LIT  */
    INT_LIT = 300,                 /* INT_LIT  */
    FLOAT_LIT = 301,               /* FLOAT_LIT  */
    ID = 302,                      /* ID  */
    OPERATOR_INCREMENT = 303,      /* OPERATOR_INCREMENT  */
    OPERATOR_DECREMENT = 304,      /* OPERATOR_DECREMENT  */
    ENDL_OPERATOR_INCREMENT = 305, /* ENDL_OPERATOR_INCREMENT  */
    ENDL_OPERATOR_DECREMENT = 306, /* ENDL_OPERATOR_DECREMENT  */
    IF_ONLY_PREC = 307,            /* IF_ONLY_PREC  */
    COMMA_OPERATOR = 308,          /* COMMA_OPERATOR  */
    COMMA_SEPARATOR = 309,         /* COMMA_SEPARATOR  */
    OPERATOR_ASSIGN_PLUS = 310,    /* OPERATOR_ASSIGN_PLUS  */
    OPERATOR_ASSIGN_MINUS = 311,   /* OPERATOR_ASSIGN_MINUS  */
    OPERATOR_ASSIGN_MULTIPLY = 312, /* OPERATOR_ASSIGN_MULTIPLY  */
    OPERATOR_ASSIGN_DIVIDE = 313,  /* OPERATOR_ASSIGN_DIVIDE  */
    OPERATOR_ASSIGN_LOGICAL_AND = 314, /* OPERATOR_ASSIGN_LOGICAL_AND  */
    OPERATOR_ASSIGN_LOGICAL_OR = 315, /* OPERATOR_ASSIGN_LOGICAL_OR  */
    OPERATOR_LOGICAL_OR = 316,     /* OPERATOR_LOGICAL_OR  */
    OPERATOR_LOGICAL_AND = 317,    /* OPERATOR_LOGICAL_AND  */
    OPERATOR_EQUAL = 318,          /* OPERATOR_EQUAL  */
    OPERATOR_NOT_EQUAL = 319,      /* OPERATOR_NOT_EQUAL  */
    OPERATOR_STRICT_EQUAL = 320,   /* OPERATOR_STRICT_EQUAL  */
    OPERATOR_STRICT_NOT_EQUAL = 321, /* OPERATOR_STRICT_NOT_EQUAL  */
    OPERATOR_GREATER_THAN_EQUAL = 322, /* OPERATOR_GREATER_THAN_EQUAL  */
    OPERATOR_LESS_THAN_EQUAL = 323, /* OPERATOR_LESS_THAN_EQUAL  */
    INSTANCEOF = 324,              /* INSTANCEOF  */
    IN = 325,                      /* IN  */
    UMINUS = 326,                  /* UMINUS  */
    UPLUS = 327,                   /* UPLUS  */
    PREF_INCREMENT = 328,          /* PREF_INCREMENT  */
    PREF_DECREMENT = 329,          /* PREF_DECREMENT  */
    POST_INCREMENT = 330,          /* POST_INCREMENT  */
    POST_DECREMENT = 331,          /* POST_DECREMENT  */
    ENDL_BRACKET_OPEN = 332        /* ENDL_BRACKET_OPEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 36 ".\\parser.y"

    int integerValue;
    char* stringValue;
    char* identName;
    double floatingPointValue;

    struct TSScriptNode* tsscriptNode;
    struct TSElementListNode* tsscriptElementListNode;
    struct TSElementNode* tsscriptElementNode;

    struct ClassDeclarationNode* classDeclNode;
    struct ClassElementListNode* classElementListNode;
    struct ClassElementNode* classElementNode;

    struct RequiredParameterListNode* requiredParameterListNode;
    struct RequiredParameterNode* requiredParameterNode;
    struct CallSignatureNode* callSignatureNode;
    struct FunctionDeclarationNode* funcDeclarationNode;

    struct StatementListNode* stmtListNode;
    struct StatementNode* stmtNode;

    struct ExpressionListNode* exprListNode;
    struct ExpressionNode* exprNode;

    struct TypeNode* typeNode;
    struct TupleTypeNode* tupleTypeNode;

    enum class VarModifierType varModifierType;

    struct VarDeclarationNode* varDeclNode;
    struct VarDeclarationListNode* varDeclListNode;

#line 258 "parser.tab.c"

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
  YYSYMBOL_97_ = 97,                       /* '('  */
  YYSYMBOL_98_ = 98,                       /* ')'  */
  YYSYMBOL_99_ = 99,                       /* ';'  */
  YYSYMBOL_100_ = 100,                     /* '{'  */
  YYSYMBOL_101_ = 101,                     /* '}'  */
  YYSYMBOL_YYACCEPT = 102,                 /* $accept  */
  YYSYMBOL_script = 103,                   /* script  */
  YYSYMBOL_scriptElementList = 104,        /* scriptElementList  */
  YYSYMBOL_scriptElement = 105,            /* scriptElement  */
  YYSYMBOL_statementList = 106,            /* statementList  */
  YYSYMBOL_statementListItem = 107,        /* statementListItem  */
  YYSYMBOL_statementListItemWithoutEmptyStatement = 108, /* statementListItemWithoutEmptyStatement  */
  YYSYMBOL_emptyStatement = 109,           /* emptyStatement  */
  YYSYMBOL_blockStatement = 110,           /* blockStatement  */
  YYSYMBOL_type = 111,                     /* type  */
  YYSYMBOL_tupleTypeElements = 112,        /* tupleTypeElements  */
  YYSYMBOL_predefinedType = 113,           /* predefinedType  */
  YYSYMBOL_typeAnnotationOpt = 114,        /* typeAnnotationOpt  */
  YYSYMBOL_typeAnnotation = 115,           /* typeAnnotation  */
  YYSYMBOL_arrayLiteral = 116,             /* arrayLiteral  */
  YYSYMBOL_elementList = 117,              /* elementList  */
  YYSYMBOL_elementListItem = 118,          /* elementListItem  */
  YYSYMBOL_expressionStatement = 119,      /* expressionStatement  */
  YYSYMBOL_singleExpressionOpt = 120,      /* singleExpressionOpt  */
  YYSYMBOL_singleExpression = 121,         /* singleExpression  */
  YYSYMBOL_varStatement = 122,             /* varStatement  */
  YYSYMBOL_varDeclarationList = 123,       /* varDeclarationList  */
  YYSYMBOL_varDeclaration = 124,           /* varDeclaration  */
  YYSYMBOL_varModifier = 125,              /* varModifier  */
  YYSYMBOL_ifStatement = 126,              /* ifStatement  */
  YYSYMBOL_iterationStatement = 127,       /* iterationStatement  */
  YYSYMBOL_128_1 = 128,                    /* $@1  */
  YYSYMBOL_129_2 = 129,                    /* $@2  */
  YYSYMBOL_130_3 = 130,                    /* $@3  */
  YYSYMBOL_131_4 = 131,                    /* $@4  */
  YYSYMBOL_132_5 = 132,                    /* $@5  */
  YYSYMBOL_forHeader = 133,                /* forHeader  */
  YYSYMBOL_returnStatement = 134,          /* returnStatement  */
  YYSYMBOL_functionDeclaration = 135,      /* functionDeclaration  */
  YYSYMBOL_functionBody = 136,             /* functionBody  */
  YYSYMBOL_137_6 = 137,                    /* $@6  */
  YYSYMBOL_parameterList = 138,            /* parameterList  */
  YYSYMBOL_requiredParameterList = 139,    /* requiredParameterList  */
  YYSYMBOL_requiredParameter = 140,        /* requiredParameter  */
  YYSYMBOL_classDeclaration = 141,         /* classDeclaration  */
  YYSYMBOL_classHeritage = 142,            /* classHeritage  */
  YYSYMBOL_classTail = 143,                /* classTail  */
  YYSYMBOL_classElementList = 144,         /* classElementList  */
  YYSYMBOL_classElement = 145,             /* classElement  */
  YYSYMBOL_propertyName = 146,             /* propertyName  */
  YYSYMBOL_identifier = 147                /* identifier  */
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
#define YYFINAL  92
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2358

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  102
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  175
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  319

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   332


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
      97,    98,    82,    80,    53,    81,    93,    83,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    64,    99,
      75,    56,    74,    63,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    94,     2,    95,    68,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   100,    67,   101,    86,     2,     2,     2,
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
      91,    92,    96
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   169,   169,   182,   183,   187,   188,   189,   190,   194,
     195,   199,   200,   201,   202,   203,   204,   211,   215,   216,
     217,   218,   219,   226,   228,   232,   244,   245,   251,   252,
     253,   254,   255,   259,   260,   261,   265,   266,   267,   268,
     269,   270,   274,   275,   279,   284,   285,   289,   291,   296,
     297,   305,   309,   310,   314,   315,   316,   317,   318,   319,
     321,   322,   323,   324,   326,   327,   329,   331,   333,   336,
     338,   340,   342,   345,   346,   347,   348,   349,   350,   352,
     354,   356,   358,   360,   362,   365,   367,   369,   371,   373,
     375,   377,   380,   382,   385,   386,   388,   391,   394,   398,
     400,   403,   407,   409,   411,   413,   416,   417,   418,   428,
     429,   433,   435,   440,   442,   447,   448,   449,   455,   461,
     471,   471,   477,   483,   483,   489,   489,   495,   495,   501,
     501,   509,   515,   516,   520,   528,   529,   529,   538,   539,
     540,   544,   549,   557,   567,   572,   580,   584,   585,   589,
     590,   594,   601,   606,   613,   620,   625,   633,   637,   638,
     639,   640,   641,   642,   643,   644,   645,   646,   647,   648,
     649,   650,   651,   652,   653,   654
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
  "']'", "ENDL_BRACKET_OPEN", "'('", "')'", "';'", "'{'", "'}'", "$accept",
  "script", "scriptElementList", "scriptElement", "statementList",
  "statementListItem", "statementListItemWithoutEmptyStatement",
  "emptyStatement", "blockStatement", "type", "tupleTypeElements",
  "predefinedType", "typeAnnotationOpt", "typeAnnotation", "arrayLiteral",
  "elementList", "elementListItem", "expressionStatement",
  "singleExpressionOpt", "singleExpression", "varStatement",
  "varDeclarationList", "varDeclaration", "varModifier", "ifStatement",
  "iterationStatement", "$@1", "$@2", "$@3", "$@4", "$@5", "forHeader",
  "returnStatement", "functionDeclaration", "functionBody", "$@6",
  "parameterList", "requiredParameterList", "requiredParameter",
  "classDeclaration", "classHeritage", "classTail", "classElementList",
  "classElement", "propertyName", "identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-230)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     402,  -230,  -230,  -230,  -230,   -90,   627,   627,   890,   -72,
     -64,  1053,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,
    -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,
    -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  1459,
    1459,  1459,  1459,  1459,  1459,  1459,  1459,  1459,  1459,  -230,
     596,    34,   305,  -230,  -230,  -230,  -230,  -230,  -230,  1501,
    -230,  2311,  -230,  -230,   973,  -230,  -230,  -230,   -62,  1459,
     -60,    -9,    23,  1459,  -230,  -230,  1550,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -35,  -230,  2145,   -34,  1648,  -230,
     694,  -230,  -230,  -230,  -230,  -230,  1459,  1459,  1459,  1459,
    1459,  1459,  1459,  1459,  1459,  1459,  1459,  1459,  1459,  1459,
    1459,  1459,  1459,  1459,  1459,  1459,  1459,  1459,  1459,  1459,
    1459,   627,  1459,  1459,  -230,   -45,   -44,  -230,    -6,   -37,
    2187,   627,  1135,  1699,   627,   627,   143,   -28,  -230,   -23,
    1750,  -230,  1459,  -230,  -230,  -230,  -230,  -230,   301,   301,
     301,   301,   301,   301,   301,   301,  2005,   489,   676,   123,
     123,   123,   123,   165,   165,   165,   165,   165,   165,   131,
     131,   -67,   -67,   -21,  2047,  2096,  -230,   627,  -230,   -27,
       7,  -230,  1459,  1459,   -43,   -13,  -230,  1801,   499,   -19,
      27,  -230,    -6,  -230,   627,   627,   -16,  -230,  1013,  -230,
     -61,  -230,  -230,  1459,   890,  -230,  1459,  1216,  -230,  -230,
    -230,  -230,  -230,  -230,  -230,  -230,  -230,   -27,   -27,   -27,
      -7,  -230,  1459,   -14,  2145,   140,  1459,  1459,  1297,  -230,
    -230,    80,  -230,  -230,  -230,  -230,  -230,  -230,    -6,   627,
    -230,    -5,    -4,   627,  -230,  -230,   627,   -40,  1852,  -230,
     392,  -230,  1903,    -7,   -31,   -30,   -70,    -1,  2228,  1459,
    -230,   -10,  1954,  -230,   890,    25,  -230,    -3,   627,    -2,
       1,  1459,  -230,  -230,  1378,  -230,   -27,  -230,  -230,  -230,
    -230,    31,   890,  1459,  -230,  -230,   -11,  -230,    -6,    35,
      25,    -6,  1599,    33,  -230,    -7,  -230,  -230,    36,   890,
    -230,   890,    25,    25,  -230,    25,  -230,  -230,   890,  -230,
    -230,   792,  -230,  -230,  -230,  -230,   890,  -230,  -230
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     8,   115,   116,   117,     0,     0,     0,     0,     0,
       0,     0,    56,    55,   159,   160,   161,   162,   172,   173,
     174,   175,   163,   164,   165,   166,   169,   170,   167,   168,
     171,    59,    57,    58,    61,    60,    62,    63,   158,     0,
       0,     0,     0,     0,     0,     0,    49,    49,     0,    25,
       0,     0,     0,     3,     5,    11,    17,   106,    12,     0,
      13,     0,    14,    15,    52,    16,     6,     7,    54,     0,
       0,     0,     0,     0,   131,   132,     0,    71,    72,    69,
      70,    65,    64,    66,     0,    47,    50,     0,     0,    26,
       0,     9,     1,     4,    67,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,     0,     0,   111,    42,     0,
      53,     0,     0,     0,   138,     0,     0,     0,   144,     0,
       0,   133,    49,    45,    46,    98,    27,    10,    97,    85,
      88,    89,    86,    87,    90,    91,     0,    92,    93,    79,
      80,    81,    82,    78,    77,    84,    83,    94,    95,    73,
      74,    75,    76,   102,     0,     0,   110,     0,   109,     0,
     113,    43,    52,     0,     0,   111,    99,     0,     0,     0,
     139,   141,    42,   146,     0,     0,     0,   147,     0,   149,
      42,   157,   145,     0,     0,    48,     0,     0,   107,   108,
     112,    36,    38,    37,    39,    40,    41,    33,    33,     0,
      44,    29,     0,     0,    53,    95,    52,     0,     0,   100,
      24,   118,    23,    18,    19,    20,    21,    22,    42,   140,
     143,     0,     0,   138,   148,   150,   138,     0,     0,   122,
      96,   103,     0,    34,     0,     0,     0,     0,   114,    52,
     127,     0,     0,   101,     0,     0,   142,     0,   138,     0,
       0,     0,   152,   120,     0,   104,     0,    31,    32,    28,
      30,     0,     0,    52,   129,   119,   136,   134,    42,     0,
       0,    42,     0,     0,   105,    35,   123,   128,     0,     0,
     135,     0,     0,     0,   151,     0,   153,   121,     0,   125,
     130,     0,   155,   156,   154,   124,     0,   137,   126
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -230,  -230,  -230,    85,  -163,    -8,  -230,  -230,   -49,  -178,
     -78,  -230,  -160,  -230,  -230,    94,     0,   -41,  -129,     4,
     -36,    12,  -120,    87,   -29,   -26,  -230,  -230,  -230,  -230,
    -230,  -230,   -25,  -230,  -219,  -230,  -229,  -230,   -95,  -230,
    -230,    16,  -230,   -38,  -164,    14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    51,    52,    53,    90,    54,   231,    55,    56,   253,
     254,   221,   180,   181,    57,    84,    85,    58,   129,    59,
      60,   126,   127,    61,    62,    63,   293,   308,   316,   282,
     299,    64,    65,    66,   287,   301,   189,   190,   191,    67,
     137,   138,   198,   199,   200,    68
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      72,   220,   135,   179,   211,   212,   213,    69,   214,   177,
     177,   185,   215,   216,   269,    76,   271,   270,   142,   142,
      70,    71,   276,   276,   257,    73,   121,   122,   279,   123,
     241,   242,   240,    74,    92,   132,   246,   134,   139,   289,
     247,   256,    91,    77,    78,    79,    80,    81,    82,    83,
      86,    86,    88,   223,   176,   178,   226,   210,   179,   272,
     143,   144,   182,   222,   277,   278,   227,   217,   130,   218,
     219,   304,   136,   133,   203,   128,   207,   140,   265,   238,
     239,   243,   147,   312,   313,   259,   314,   257,   264,   283,
     300,   136,   267,   268,   280,   288,   290,   261,   295,   291,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   286,   174,   175,   302,   296,
     281,   305,   307,   303,   309,   173,   187,    93,   311,   232,
     255,    87,   205,   184,   266,   128,    86,   233,   192,   193,
     201,   131,   234,   202,   298,   194,   195,     0,     0,   235,
     245,     0,   236,   237,    14,    15,    16,    17,    18,   196,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     0,     0,     0,     0,   224,   225,     0,     0,
      38,   128,     0,     0,     0,     0,   249,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   248,   201,   201,
     250,   252,   201,   119,   120,     0,   121,   122,     0,   123,
     117,   118,   119,   120,   121,   122,   258,   123,     0,     0,
     224,   262,   148,   121,   122,     0,   123,     0,   260,     0,
       0,     0,     0,     0,   197,   117,   118,   119,   120,     0,
       0,     0,     0,   192,     0,     0,   285,   192,   121,   122,
     192,   123,     0,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   297,   292,     0,     0,   148,     0,
       0,     0,   192,     0,     0,     0,     0,   224,     0,     0,
       0,   310,     0,    91,     0,     0,     0,     0,     0,     0,
     315,     0,     0,   147,     0,    -2,     1,     0,   318,     2,
       3,     4,     5,     0,     6,     7,     0,     0,     0,     8,
       9,    10,    11,    12,    13,     0,    14,    15,    16,    17,
      18,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    97,    98,    99,
     100,   101,   102,   103,   104,     0,   105,   106,     0,     0,
       0,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    43,    44,     0,     0,     0,
      45,     0,     0,     0,   121,   122,     0,   123,     0,    46,
       0,    47,    48,     1,    49,    50,     2,     3,     4,     5,
       0,     6,     7,     0,     0,     0,     8,     9,    10,    11,
      12,    13,     0,    14,    15,    16,    17,    18,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,     0,     0,     0,   105,   106,     0,
       0,     0,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,     0,     0,     0,     0,
       0,     0,    43,    44,     0,   121,   122,    45,   123,     0,
       0,     0,     0,     0,     0,     0,    46,     0,    47,    48,
     230,    49,    50,     2,     3,     4,     5,     0,     0,     0,
       0,     0,     0,     8,     9,    10,    11,    12,    13,     0,
      14,    15,    16,    17,    18,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,     0,     0,     0,     0,   106,     0,     0,     0,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,     0,     0,     0,     0,     0,     0,    43,
      44,     0,   121,   122,    45,   123,     0,     0,     0,     0,
       0,     0,     0,    46,     0,    47,    48,     0,     0,    50,
       2,     3,     4,     5,     0,     0,     0,     0,     0,     0,
       8,     9,    10,    11,    12,    13,     0,    14,    15,    16,
      17,    18,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    14,    15,
      16,    17,    18,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,    43,    44,     0,     0,
       0,    45,     0,     0,     0,     0,     0,     0,     0,     0,
      46,     0,    47,    48,     0,    49,    50,    89,     2,     3,
       4,     5,     0,     0,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    13,     0,    14,    15,    16,    17,    18,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
     122,     0,   123,     0,    43,    44,     0,     0,     0,    45,
       0,     0,     0,     0,     0,     0,     0,     0,    46,     0,
      47,    48,     0,    49,    50,   146,     2,     3,     4,     5,
       0,     0,     0,     0,     0,     0,     8,     9,    10,    11,
      12,    13,     0,    14,    15,    16,    17,    18,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    43,    44,     0,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     0,    46,     0,    47,    48,
       0,    49,    50,   317,     2,     3,     4,     5,     0,     0,
       0,     0,     0,     0,     8,     9,    10,    11,    12,    13,
       0,    14,    15,    16,    17,    18,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      43,    44,     0,     0,     0,    45,     0,     2,     3,     4,
       0,     0,     0,     0,    46,     0,    47,    48,     0,    49,
      50,    12,    13,     0,    14,    15,    16,    17,    18,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   194,   195,     0,     0,     0,
       0,     0,     0,     0,    14,    15,    16,    17,    18,   196,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     0,    43,    44,     0,     0,     0,    45,     0,
      38,     0,     0,     0,     0,     0,     0,    46,     0,    47,
      48,    12,    13,     0,    14,    15,    16,    17,    18,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   244,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    43,    44,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,     0,    46,     0,    47,
      48,     0,    75,    12,    13,     0,    14,    15,    16,    17,
      18,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    43,    44,     0,     0,     0,
      45,     0,     0,     0,     0,     0,     0,     0,     0,    46,
       0,    47,    48,   186,    12,    13,     0,    14,    15,    16,
      17,    18,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43,    44,     0,     0,
       0,    45,     0,     0,     0,     0,     0,     0,     0,     0,
      46,     0,    47,    48,   251,    12,    13,     0,    14,    15,
      16,    17,    18,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    43,    44,     0,
       0,     0,    45,     0,     0,     0,     0,     0,     0,     0,
       0,    46,     0,    47,    48,   263,    12,    13,     0,    14,
      15,    16,    17,    18,     0,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    43,    44,
       0,     0,     0,    45,     0,     0,     0,     0,     0,     0,
       0,     0,    46,     0,    47,    48,   294,    12,    13,     0,
      14,    15,    16,    17,    18,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    43,
      44,     0,     0,     0,    45,     0,     0,     0,     0,    94,
      95,     0,     0,    46,    96,    47,    48,    97,    98,    99,
     100,   101,   102,   103,   104,     0,   105,   106,     0,     0,
       0,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,   122,     0,   123,    94,    95,
     124,     0,     0,    96,     0,     0,    97,    98,    99,   100,
     101,   102,   103,   104,     0,   105,   106,     0,     0,     0,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,   122,     0,   123,    94,    95,   141,
       0,     0,    96,     0,     0,    97,    98,    99,   100,   101,
     102,   103,   104,     0,   105,   106,     0,     0,     0,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,   122,     0,   123,    94,    95,   306,     0,
       0,    96,     0,     0,    97,    98,    99,   100,   101,   102,
     103,   104,     0,   105,   106,     0,     0,     0,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,   122,     0,   123,     0,   145,    94,    95,     0,
       0,     0,    96,     0,     0,    97,    98,    99,   100,   101,
     102,   103,   104,     0,   105,   106,     0,     0,     0,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,   122,     0,   123,     0,   188,    94,    95,
       0,     0,     0,    96,     0,     0,    97,    98,    99,   100,
     101,   102,   103,   104,     0,   105,   106,     0,     0,     0,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,   122,     0,   123,     0,   204,    94,
      95,     0,     0,     0,   228,     0,     0,    97,    98,    99,
     100,   101,   102,   103,   104,     0,   105,   106,     0,     0,
       0,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,   122,     0,   123,     0,   229,
      94,    95,     0,     0,     0,    96,     0,     0,    97,    98,
      99,   100,   101,   102,   103,   104,     0,   105,   106,     0,
       0,     0,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,   122,     0,   123,     0,
     273,    94,    95,     0,     0,     0,   274,     0,     0,    97,
      98,    99,   100,   101,   102,   103,   104,     0,   105,   106,
       0,     0,     0,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,   122,     0,   123,
       0,   275,    94,    95,     0,     0,     0,    96,     0,     0,
      97,    98,    99,   100,   101,   102,   103,   104,     0,   105,
     106,     0,     0,     0,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,   122,     0,
     123,     0,   284,    94,    95,     0,     0,     0,    96,     0,
       0,    97,    98,    99,   100,   101,   102,   103,   104,   206,
     105,   106,     0,     0,     0,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,     0,
       0,     0,     0,     0,     0,    94,    95,     0,   121,   122,
      96,   123,     0,    97,    98,    99,   100,   101,   102,   103,
     104,     0,   105,   106,     0,     0,     0,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,   122,   208,   123,    94,    95,     0,     0,     0,    96,
       0,     0,    97,    98,    99,   100,   101,   102,   103,   104,
       0,   105,   106,     0,     0,     0,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
     122,   209,   123,    94,    95,     0,     0,     0,    96,     0,
       0,    97,    98,    99,   100,   101,   102,   103,   104,     0,
     105,   106,     0,     0,     0,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,     0,
       0,     0,     0,     0,     0,    94,    95,     0,   121,   122,
      96,   123,     0,    97,    98,    99,   100,   101,   102,   103,
     104,     0,   105,   106,     0,     0,     0,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   183,   117,   118,   119,
     120,     0,     0,     0,     0,     0,    94,    95,     0,     0,
     121,   122,     0,   123,    97,    98,    99,   100,   101,   102,
     103,   104,     0,   105,   106,     0,     0,     0,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   125,     0,     0,     0,     0,     0,     0,     0,
       0,   121,   122,     0,   123,     0,     0,     0,     0,     0,
       0,     0,    14,    15,    16,    17,    18,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
       0,     0,     0,     0,     0,     0,     0,     0,    38
};

static const yytype_int16 yycheck[] =
{
       8,   179,    11,    64,    31,    32,    33,    97,    35,    53,
      53,   131,    39,    40,   243,    11,    56,   246,    53,    53,
       6,     7,    53,    53,    94,    97,    93,    94,    98,    96,
     194,   195,   192,    97,     0,    97,    97,    97,    15,   268,
     200,   219,    50,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,   182,    99,    99,    99,   177,    64,    99,
      95,    95,    99,    56,    95,    95,    79,    94,    64,    96,
      97,   290,   100,    69,    97,    61,    97,    73,   238,    98,
      53,    97,    90,   302,   303,    99,   305,    94,     8,    99,
     101,   100,    97,    97,    95,    98,    98,   226,   276,    98,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   100,   122,   123,   288,    98,
     259,   291,    99,    98,    98,   121,   132,    52,   301,   188,
     218,    47,   142,   131,   239,   131,   142,   188,   134,   135,
     136,    64,   188,   137,   283,    12,    13,    -1,    -1,   188,
     198,    -1,   188,   188,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,   182,   183,    -1,    -1,
      47,   177,    -1,    -1,    -1,    -1,   204,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,   203,   194,   195,
     206,   207,   198,    82,    83,    -1,    93,    94,    -1,    96,
      80,    81,    82,    83,    93,    94,   222,    96,    -1,    -1,
     226,   227,   228,    93,    94,    -1,    96,    -1,    98,    -1,
      -1,    -1,    -1,    -1,   101,    80,    81,    82,    83,    -1,
      -1,    -1,    -1,   239,    -1,    -1,   264,   243,    93,    94,
     246,    96,    -1,   259,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   282,   271,    -1,    -1,   274,    -1,
      -1,    -1,   268,    -1,    -1,    -1,    -1,   283,    -1,    -1,
      -1,   299,    -1,   301,    -1,    -1,    -1,    -1,    -1,    -1,
     308,    -1,    -1,   311,    -1,     0,     1,    -1,   316,     4,
       5,     6,     7,    -1,     9,    10,    -1,    -1,    -1,    14,
      15,    16,    17,    18,    19,    -1,    21,    22,    23,    24,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    80,    81,    -1,    -1,    -1,
      85,    -1,    -1,    -1,    93,    94,    -1,    96,    -1,    94,
      -1,    96,    97,     1,    99,   100,     4,     5,     6,     7,
      -1,     9,    10,    -1,    -1,    -1,    14,    15,    16,    17,
      18,    19,    -1,    21,    22,    23,    24,    25,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    -1,    -1,    65,    66,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    81,    -1,    93,    94,    85,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    96,    97,
       1,    99,   100,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    14,    15,    16,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      81,    -1,    93,    94,    85,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    -1,    96,    97,    -1,    -1,   100,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    15,    16,    17,    18,    19,    -1,    21,    22,    23,
      24,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    21,    22,
      23,    24,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    80,    81,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    -1,    96,    97,    -1,    99,   100,   101,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    19,    -1,    21,    22,    23,    24,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      94,    -1,    96,    -1,    80,    81,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,
      96,    97,    -1,    99,   100,   101,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,    17,
      18,    19,    -1,    21,    22,    23,    24,    25,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    81,    -1,    -1,    -1,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    96,    97,
      -1,    99,   100,   101,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,    19,
      -1,    21,    22,    23,    24,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    81,    -1,    -1,    -1,    85,    -1,     4,     5,     6,
      -1,    -1,    -1,    -1,    94,    -1,    96,    97,    -1,    99,
     100,    18,    19,    -1,    21,    22,    23,    24,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    80,    81,    -1,    -1,    -1,    85,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    96,
      97,    18,    19,    -1,    21,    22,    23,    24,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    96,
      97,    -1,    99,    18,    19,    -1,    21,    22,    23,    24,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      -1,    96,    97,    98,    18,    19,    -1,    21,    22,    23,
      24,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    -1,    96,    97,    98,    18,    19,    -1,    21,    22,
      23,    24,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,
      -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    -1,    96,    97,    98,    18,    19,    -1,    21,
      22,    23,    24,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,
      -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    -1,    96,    97,    98,    18,    19,    -1,
      21,    22,    23,    24,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      81,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    48,
      49,    -1,    -1,    94,    53,    96,    97,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    94,    -1,    96,    48,    49,
      99,    -1,    -1,    53,    -1,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    -1,    96,    48,    49,    99,
      -1,    -1,    53,    -1,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    -1,    96,    48,    49,    99,    -1,
      -1,    53,    -1,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    94,    -1,    96,    -1,    98,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    -1,    96,    -1,    98,    48,    49,
      -1,    -1,    -1,    53,    -1,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    -1,    96,    -1,    98,    48,
      49,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    65,    66,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    94,    -1,    96,    -1,    98,
      48,    49,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    94,    -1,    96,    -1,
      98,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    65,    66,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    -1,    96,
      -1,    98,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    -1,
      96,    -1,    98,    48,    49,    -1,    -1,    -1,    53,    -1,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    93,    94,
      53,    96,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    95,    96,    48,    49,    -1,    -1,    -1,    53,
      -1,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      94,    95,    96,    48,    49,    -1,    -1,    -1,    53,    -1,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    66,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    93,    94,
      53,    96,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    65,    66,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,
      93,    94,    -1,    96,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    94,    -1,    96,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     4,     5,     6,     7,     9,    10,    14,    15,
      16,    17,    18,    19,    21,    22,    23,    24,    25,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    80,    81,    85,    94,    96,    97,    99,
     100,   103,   104,   105,   107,   109,   110,   116,   119,   121,
     122,   125,   126,   127,   133,   134,   135,   141,   147,    97,
     147,   147,   107,    97,    97,    99,   121,   121,   121,   121,
     121,   121,   121,   121,   117,   118,   121,   117,   121,   101,
     106,   107,     0,   105,    48,    49,    53,    56,    57,    58,
      59,    60,    61,    62,    63,    65,    66,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    93,    94,    96,    99,     1,   123,   124,   147,   120,
     121,   125,    97,   121,    97,    11,   100,   142,   143,    15,
     121,    99,    53,    95,    95,    98,   101,   107,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   147,   121,   121,    99,    53,    99,    64,
     114,   115,    99,    79,   123,   124,    98,   121,    98,   138,
     139,   140,   147,   147,    12,    13,    26,   101,   144,   145,
     146,   147,   143,    97,    98,   118,    64,    97,    95,    95,
     124,    31,    32,    33,    35,    39,    40,    94,    96,    97,
     111,   113,    56,   120,   121,   121,    99,    79,    53,    98,
       1,   108,   110,   119,   122,   126,   127,   134,    98,    53,
     114,   146,   146,    97,   101,   145,    97,   114,   121,   107,
     121,    98,   121,   111,   112,   112,   111,    94,   121,    99,
      98,   120,   121,    98,     8,   114,   140,    97,    97,   138,
     138,    56,    99,    98,    53,    98,    53,    95,    95,    98,
      95,   120,   131,    99,    98,   107,   100,   136,    98,   138,
      98,    98,   121,   128,    98,   111,    98,   107,   120,   132,
     101,   137,   114,    98,   136,   114,    99,    99,   129,    98,
     107,   106,   136,   136,   136,   107,   130,   101,   107
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   102,   103,   104,   104,   105,   105,   105,   105,   106,
     106,   107,   107,   107,   107,   107,   107,   107,   108,   108,
     108,   108,   108,   108,   108,   109,   110,   110,   111,   111,
     111,   111,   111,   112,   112,   112,   113,   113,   113,   113,
     113,   113,   114,   114,   115,   116,   116,   117,   117,   118,
     118,   119,   120,   120,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   122,
     122,   123,   123,   124,   124,   125,   125,   125,   126,   126,
     128,   127,   127,   129,   127,   130,   127,   131,   127,   132,
     127,   133,   134,   134,   135,   136,   137,   136,   138,   138,
     138,   139,   139,   140,   141,   141,   142,   143,   143,   144,
     144,   145,   145,   145,   145,   145,   145,   146,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     3,     1,
       3,     3,     3,     0,     1,     3,     1,     1,     1,     1,
       1,     1,     0,     1,     2,     3,     3,     1,     3,     0,
       1,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     5,     3,     3,     3,
       4,     5,     3,     5,     6,     7,     1,     4,     4,     3,
       3,     1,     3,     2,     4,     1,     1,     1,     5,     7,
       0,     8,     5,     0,     9,     0,    10,     0,     7,     0,
       8,     2,     2,     3,     7,     2,     0,     4,     0,     1,
       2,     1,     3,     2,     3,     4,     2,     2,     3,     1,
       2,     5,     3,     5,     6,     6,     6,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
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
#line 170 ".\\parser.y"
        { 
            if ( syntaxErrorCounter > 0 ) {
                PrintError("Found " + std::to_string(syntaxErrorCounter) + " syntax errors. Fix them and rerun.");
                exit(1);
            }
            Print("- R: scriptElementList -> script"); 
        
            (yyval.tsscriptNode) = root = createTSScriptNode((yyvsp[0].tsscriptElementListNode));
        }
#line 2440 "parser.tab.c"
    break;

  case 3: /* scriptElementList: scriptElement  */
#line 182 ".\\parser.y"
                                        { Print("- R: scriptElement -> scriptElementList"); (yyval.tsscriptElementListNode) = createTSElementListNode((yyvsp[0].tsscriptElementNode)); }
#line 2446 "parser.tab.c"
    break;

  case 4: /* scriptElementList: scriptElementList scriptElement  */
#line 183 ".\\parser.y"
                                        { Print("- R: scriptElementList scriptElement -> scriptElementList"); (yyval.tsscriptElementListNode) = addTSElementNodeToList((yyvsp[-1].tsscriptElementListNode), (yyvsp[0].tsscriptElementNode)); }
#line 2452 "parser.tab.c"
    break;

  case 5: /* scriptElement: statementListItem  */
#line 187 ".\\parser.y"
                            { Print("- R: statementListItem -> scriptElement"); (yyval.tsscriptElementNode) = createElementFromStatement((yyvsp[0].stmtNode)); }
#line 2458 "parser.tab.c"
    break;

  case 6: /* scriptElement: functionDeclaration  */
#line 188 ".\\parser.y"
                            { Print("- R: functionDeclaration -> scriptElement"); (yyval.tsscriptElementNode) = createElementFromFuncDeclaration((yyvsp[0].funcDeclarationNode)); }
#line 2464 "parser.tab.c"
    break;

  case 7: /* scriptElement: classDeclaration  */
#line 189 ".\\parser.y"
                            { Print("- R: classDeclaration -> scriptElement"); (yyval.tsscriptElementNode) = createElementFromClassDeclaration((yyvsp[0].classDeclNode)); }
#line 2470 "parser.tab.c"
    break;

  case 9: /* statementList: statementListItem  */
#line 194 ".\\parser.y"
                                        { Print("- R: statementListItem -> statementList"); (yyval.stmtListNode) = createStatementListNode((yyvsp[0].stmtNode)); }
#line 2476 "parser.tab.c"
    break;

  case 10: /* statementList: statementList statementListItem  */
#line 195 ".\\parser.y"
                                        { Print("- R: statementList statementListItem -> statementList"); (yyval.stmtListNode) = addStatementToStatementList((yyvsp[-1].stmtListNode), (yyvsp[0].stmtNode)); }
#line 2482 "parser.tab.c"
    break;

  case 11: /* statementListItem: emptyStatement  */
#line 199 ".\\parser.y"
                            { Print("- R: emptyStatement -> statementListItem"); }
#line 2488 "parser.tab.c"
    break;

  case 12: /* statementListItem: expressionStatement  */
#line 200 ".\\parser.y"
                            { Print("- R: expressionStatement -> statementListItem"); }
#line 2494 "parser.tab.c"
    break;

  case 13: /* statementListItem: varStatement  */
#line 201 ".\\parser.y"
                            { Print("- R: varStatement -> statementListItem"); }
#line 2500 "parser.tab.c"
    break;

  case 14: /* statementListItem: ifStatement  */
#line 202 ".\\parser.y"
                            { Print("- R: ifStatement -> statementListItem"); }
#line 2506 "parser.tab.c"
    break;

  case 15: /* statementListItem: iterationStatement  */
#line 203 ".\\parser.y"
                            { Print("- R: iterationStatement -> statementListItem"); }
#line 2512 "parser.tab.c"
    break;

  case 16: /* statementListItem: returnStatement  */
#line 205 ".\\parser.y"
        { 
            if ( !isInFunctionBody ) { 
                yyerror("illegal return statement."); YYERROR;
            } 
            Print("- R: returnStatement -> statementListItem");
        }
#line 2523 "parser.tab.c"
    break;

  case 17: /* statementListItem: blockStatement  */
#line 211 ".\\parser.y"
                            { Print("- R: blockStatement -> statementListItem"); }
#line 2529 "parser.tab.c"
    break;

  case 18: /* statementListItemWithoutEmptyStatement: expressionStatement  */
#line 215 ".\\parser.y"
                            { Print("- R: expressionStatement -> statementListItemWithoutEmptyStatement"); }
#line 2535 "parser.tab.c"
    break;

  case 19: /* statementListItemWithoutEmptyStatement: varStatement  */
#line 216 ".\\parser.y"
                            { Print("- R: varStatement -> statementListItemWithoutEmptyStatement"); }
#line 2541 "parser.tab.c"
    break;

  case 20: /* statementListItemWithoutEmptyStatement: ifStatement  */
#line 217 ".\\parser.y"
                            { Print("- R: ifStatement -> statementListItemWithoutEmptyStatement"); }
#line 2547 "parser.tab.c"
    break;

  case 21: /* statementListItemWithoutEmptyStatement: iterationStatement  */
#line 218 ".\\parser.y"
                            { Print("- R: iterationStatement -> statementListItemWithoutEmptyStatement"); }
#line 2553 "parser.tab.c"
    break;

  case 22: /* statementListItemWithoutEmptyStatement: returnStatement  */
#line 220 ".\\parser.y"
        { 
            if ( !isInFunctionBody ) { 
                yyerror("illegal return statement."); YYERROR;
            } 
            Print("- R: returnStatement -> statementListItemWithoutEmptyStatement");
        }
#line 2564 "parser.tab.c"
    break;

  case 23: /* statementListItemWithoutEmptyStatement: blockStatement  */
#line 226 ".\\parser.y"
                            { Print("- R: blockStatement -> statementListItemWithoutEmptyStatement"); }
#line 2570 "parser.tab.c"
    break;

  case 25: /* emptyStatement: ';'  */
#line 233 ".\\parser.y"
        { 
            if ( isASIActivated ) {
                std::string text(yytext_ptr, yyleng);
                yyerror(("syntax error on token: " + text).c_str()); YYERROR;
            }
            Print("- R: ';' -> emptyStatement");
            (yyval.stmtNode) = createEmptyStatementNode();
        }
#line 2583 "parser.tab.c"
    break;

  case 26: /* blockStatement: '{' '}'  */
#line 244 ".\\parser.y"
                            { Print("- R: '{' '}' -> blockStatement"); (yyval.stmtNode) = createBlockStatementNode(nullptr); }
#line 2589 "parser.tab.c"
    break;

  case 27: /* blockStatement: '{' statementList '}'  */
#line 245 ".\\parser.y"
                            { Print("- R: '{' statementList '}' -> blockStatement"); (yyval.stmtNode) = createBlockStatementNode((yyvsp[-1].stmtListNode)); }
#line 2595 "parser.tab.c"
    break;

  case 28: /* type: '(' type ')'  */
#line 251 ".\\parser.y"
                                                { Print("- R: '(' type ')' -> type"); (yyval.typeNode) = (yyvsp[-1].typeNode); }
#line 2601 "parser.tab.c"
    break;

  case 29: /* type: predefinedType  */
#line 252 ".\\parser.y"
                                                { Print("- R: predefinedType -> type"); (yyval.typeNode) = (yyvsp[0].typeNode); }
#line 2607 "parser.tab.c"
    break;

  case 30: /* type: type '[' ']'  */
#line 253 ".\\parser.y"
                                                { Print("- R: type '[' ']' -> type"); (yyval.typeNode) = createArrayTypeNode((yyvsp[-2].typeNode)); }
#line 2613 "parser.tab.c"
    break;

  case 31: /* type: '[' tupleTypeElements ']'  */
#line 254 ".\\parser.y"
                                                { Print("- R: '[' tupleTypeElements ']' -> type"); (yyval.typeNode) = createTypeFromTupleType((yyvsp[-1].tupleTypeNode)); }
#line 2619 "parser.tab.c"
    break;

  case 32: /* type: ENDL_BRACKET_OPEN tupleTypeElements ']'  */
#line 255 ".\\parser.y"
                                                { Print("- R: '[' tupleTypeElements ']' -> type"); (yyval.typeNode) = createTypeFromTupleType((yyvsp[-1].tupleTypeNode)); }
#line 2625 "parser.tab.c"
    break;

  case 33: /* tupleTypeElements: %empty  */
#line 259 ".\\parser.y"
                                    { Print("- R: #empty# -> tupleTypeElements"); (yyval.tupleTypeNode) = createTupleTypeNode(nullptr); }
#line 2631 "parser.tab.c"
    break;

  case 34: /* tupleTypeElements: type  */
#line 260 ".\\parser.y"
                                    { Print("- R: type -> tupleTypeElements"); (yyval.tupleTypeNode) = createTupleTypeNode((yyvsp[0].typeNode)); }
#line 2637 "parser.tab.c"
    break;

  case 35: /* tupleTypeElements: tupleTypeElements ',' type  */
#line 261 ".\\parser.y"
                                    { Print("- R: tupleTypeElements ',' type -> tupleTypeElements"); (yyval.tupleTypeNode) = addTypeToTupleType((yyvsp[-2].tupleTypeNode), (yyvsp[0].typeNode)); }
#line 2643 "parser.tab.c"
    break;

  case 36: /* predefinedType: NUMBER  */
#line 265 ".\\parser.y"
                    { Print("- R: NUMBER -> predefinedType"); (yyval.typeNode) = createNumberTypeNode(); }
#line 2649 "parser.tab.c"
    break;

  case 37: /* predefinedType: STRING  */
#line 266 ".\\parser.y"
                    { Print("- R: STRING -> predefinedType"); (yyval.typeNode) = createStringTypeNode(); }
#line 2655 "parser.tab.c"
    break;

  case 38: /* predefinedType: BOOLEAN  */
#line 267 ".\\parser.y"
                    { Print("- R: BOOLEAN -> predefinedType"); (yyval.typeNode) = createBooleanTypeNode(); }
#line 2661 "parser.tab.c"
    break;

  case 39: /* predefinedType: UNDEFINED  */
#line 268 ".\\parser.y"
                    { Print("- R: UNDEFINED -> predefinedType"); (yyval.typeNode) = createUndefinedTypeNode(); }
#line 2667 "parser.tab.c"
    break;

  case 40: /* predefinedType: VOID  */
#line 269 ".\\parser.y"
                    { Print("- R: VOID -> predefinedType"); (yyval.typeNode) = createVoidTypeNode(); }
#line 2673 "parser.tab.c"
    break;

  case 41: /* predefinedType: NULL_KW  */
#line 270 ".\\parser.y"
                    { Print("- R: NULL_KW -> predefinedType"); (yyval.typeNode) = createNullTypeNode(); }
#line 2679 "parser.tab.c"
    break;

  case 42: /* typeAnnotationOpt: %empty  */
#line 274 ".\\parser.y"
                        { Print("- R: # empty # -> typeAnnotationOpt"); (yyval.typeNode) = nullptr; }
#line 2685 "parser.tab.c"
    break;

  case 43: /* typeAnnotationOpt: typeAnnotation  */
#line 275 ".\\parser.y"
                        { Print("- R: typeAnnotation -> typeAnnotationOpt"); (yyval.typeNode) = (yyvsp[0].typeNode); }
#line 2691 "parser.tab.c"
    break;

  case 44: /* typeAnnotation: ':' type  */
#line 279 ".\\parser.y"
               { Print("- R: ':' type -> typeAnnotation"); (yyval.typeNode) = (yyvsp[0].typeNode); }
#line 2697 "parser.tab.c"
    break;

  case 45: /* arrayLiteral: '[' elementList ']'  */
#line 284 ".\\parser.y"
                                        { Print("- R: '[' elementList ']' -> arrayLiteral"); (yyval.exprNode) = createArrayLiteralFromExpressionList((yyvsp[-1].exprListNode)); }
#line 2703 "parser.tab.c"
    break;

  case 46: /* arrayLiteral: ENDL_BRACKET_OPEN elementList ']'  */
#line 285 ".\\parser.y"
                                        { Print("- R: ENDL_BRACKET_OPEN elementList ']' -> arrayLiteral"); (yyval.exprNode) = createArrayLiteralFromExpressionList((yyvsp[-1].exprListNode)); }
#line 2709 "parser.tab.c"
    break;

  case 47: /* elementList: elementListItem  */
#line 290 ".\\parser.y"
        { Print("- R: elementListItem -> elementList"); (yyval.exprListNode) = createExpressionListFromExpression((yyvsp[0].exprNode)); }
#line 2715 "parser.tab.c"
    break;

  case 48: /* elementList: elementList ',' elementListItem  */
#line 292 ".\\parser.y"
        { Print("- R: elementList ',' elementListItem -> elementList"); (yyval.exprListNode) = addExpressionListToExpressionList((yyvsp[-2].exprListNode), createExpressionListFromExpression((yyvsp[0].exprNode))); }
#line 2721 "parser.tab.c"
    break;

  case 49: /* elementListItem: %empty  */
#line 296 ".\\parser.y"
                  { Print("- R: #empty# -> elementListItem"); (yyval.exprNode) = createEmptyArrayElementExpressionNode(); }
#line 2727 "parser.tab.c"
    break;

  case 50: /* elementListItem: singleExpression  */
#line 297 ".\\parser.y"
                       { Print("- R: singleExpression -> elementListItem"); (yyval.exprNode) = (yyvsp[0].exprNode); }
#line 2733 "parser.tab.c"
    break;

  case 51: /* expressionStatement: singleExpression ';'  */
#line 305 ".\\parser.y"
                           { Print("- R: expressionList ';' -> expressionStatement"); (yyval.stmtNode) = createExpressionStatementNode((yyvsp[-1].exprNode)); }
#line 2739 "parser.tab.c"
    break;

  case 52: /* singleExpressionOpt: %empty  */
#line 309 ".\\parser.y"
                        { Print("- R: #empty# -> singleExpressionOpt"); (yyval.exprNode) = nullptr; }
#line 2745 "parser.tab.c"
    break;

  case 53: /* singleExpressionOpt: singleExpression  */
#line 310 ".\\parser.y"
                          { Print("- R: singleExpression -> singleExpressionOpt"); (yyval.exprNode) = (yyvsp[0].exprNode); }
#line 2751 "parser.tab.c"
    break;

  case 54: /* singleExpression: identifier  */
#line 314 ".\\parser.y"
                    { Print("- R: identifier -> singleExpression"); (yyval.exprNode) = createIDExpressionNode((yyvsp[0].identName)); }
#line 2757 "parser.tab.c"
    break;

  case 55: /* singleExpression: THIS  */
#line 315 ".\\parser.y"
                    { Print("- R: THIS -> singleExpression"); (yyval.exprNode) = createThisExpressionNode(); }
#line 2763 "parser.tab.c"
    break;

  case 56: /* singleExpression: SUPER  */
#line 316 ".\\parser.y"
                    { Print("- R: SUPER -> singleExpression"); (yyval.exprNode) = createSuperExpressionNode(); }
#line 2769 "parser.tab.c"
    break;

  case 57: /* singleExpression: TRUE_KW  */
#line 317 ".\\parser.y"
                    { Print("- R: TRUE_LITERAL -> singleExpression"); (yyval.exprNode) = createTrueLiteralExpressionNode(); }
#line 2775 "parser.tab.c"
    break;

  case 58: /* singleExpression: FALSE_KW  */
#line 318 ".\\parser.y"
                    { Print("- R: FALSE_LITERAL -> singleExpression"); (yyval.exprNode) = createFalseLiteralExpressionNode(); }
#line 2781 "parser.tab.c"
    break;

  case 59: /* singleExpression: NULL_KW  */
#line 319 ".\\parser.y"
                    { Print("- R: NULL_LITERAL -> singleExpression"); (yyval.exprNode) = createNullLiteralExpressionNode(); }
#line 2787 "parser.tab.c"
    break;

  case 60: /* singleExpression: STRING_LIT  */
#line 321 ".\\parser.y"
                    { Print("- R: STRING_LIT -> singleExpression"); (yyval.exprNode) = createStringLiteralExpressionNode((yyvsp[0].stringValue)); }
#line 2793 "parser.tab.c"
    break;

  case 61: /* singleExpression: TEMPLATE_LIT  */
#line 322 ".\\parser.y"
                    { Print("- R: TEMPLATE_LIT -> singleExpression"); (yyval.exprNode) = createStringLiteralExpressionNode((yyvsp[0].stringValue)); }
#line 2799 "parser.tab.c"
    break;

  case 62: /* singleExpression: INT_LIT  */
#line 323 ".\\parser.y"
                    { Print("- R: INT_LIT -> singleExpression"); (yyval.exprNode) = createIntLiteralExpressionNode((yyvsp[0].integerValue)); }
#line 2805 "parser.tab.c"
    break;

  case 63: /* singleExpression: FLOAT_LIT  */
#line 324 ".\\parser.y"
                    { Print("- R: FLOAT_LIT -> singleExpression"); (yyval.exprNode) = createFloatLiteralExpressionNode((yyvsp[0].floatingPointValue)); }
#line 2811 "parser.tab.c"
    break;

  case 64: /* singleExpression: '-' singleExpression  */
#line 326 ".\\parser.y"
                                        { Print("- R: '-' singleExpression -> singleExpression"); (yyval.exprNode) = createUMinusExpressionNode((yyvsp[0].exprNode)); }
#line 2817 "parser.tab.c"
    break;

  case 65: /* singleExpression: '+' singleExpression  */
#line 327 ".\\parser.y"
                                        { Print("- R: '+' singleExpression -> singleExpression"); (yyval.exprNode) = createUPlusExpressionNode((yyvsp[0].exprNode)); }
#line 2823 "parser.tab.c"
    break;

  case 66: /* singleExpression: '!' singleExpression  */
#line 329 ".\\parser.y"
                           { Print("- R: '!' singleExpression -> singleExpression"); (yyval.exprNode) = createLogNotExpressionNode((yyvsp[0].exprNode)); }
#line 2829 "parser.tab.c"
    break;

  case 67: /* singleExpression: singleExpression OPERATOR_INCREMENT  */
#line 332 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_INCREMENT -> singleExpression"); (yyval.exprNode) = createPostIncrementExpressionNode((yyvsp[-1].exprNode)); }
#line 2835 "parser.tab.c"
    break;

  case 68: /* singleExpression: singleExpression OPERATOR_DECREMENT  */
#line 334 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_DECREMENT -> singleExpression"); (yyval.exprNode) = createPostDecrementExpressionNode((yyvsp[-1].exprNode)); }
#line 2841 "parser.tab.c"
    break;

  case 69: /* singleExpression: ENDL_OPERATOR_INCREMENT singleExpression  */
#line 337 ".\\parser.y"
        { Print("- R: ENDL_OPERATOR_INCREMENT singleExpression -> singleExpression"); (yyval.exprNode) = createPrefIncrementExpressionNode((yyvsp[0].exprNode)); }
#line 2847 "parser.tab.c"
    break;

  case 70: /* singleExpression: ENDL_OPERATOR_DECREMENT singleExpression  */
#line 339 ".\\parser.y"
        { Print("- R: ENDL_OPERATOR_DECREMENT singleExpression -> singleExpression"); (yyval.exprNode) = createPrefDecrementExpressionNode((yyvsp[0].exprNode)); }
#line 2853 "parser.tab.c"
    break;

  case 71: /* singleExpression: OPERATOR_INCREMENT singleExpression  */
#line 341 ".\\parser.y"
        { Print("- R: OPERATOR_INCREMENT singleExpression -> singleExpression"); (yyval.exprNode) = createPrefIncrementExpressionNode((yyvsp[0].exprNode)); }
#line 2859 "parser.tab.c"
    break;

  case 72: /* singleExpression: OPERATOR_DECREMENT singleExpression  */
#line 343 ".\\parser.y"
        { Print("- R: OPERATOR_DECREMENT singleExpression -> singleExpression"); (yyval.exprNode) = createPrefDecrementExpressionNode((yyvsp[0].exprNode)); }
#line 2865 "parser.tab.c"
    break;

  case 73: /* singleExpression: singleExpression '+' singleExpression  */
#line 345 ".\\parser.y"
                                            { Print("- R: singleExpression '+' singleExpression -> singleExpression"); (yyval.exprNode) = createPlusExpressionNode((yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2871 "parser.tab.c"
    break;

  case 74: /* singleExpression: singleExpression '-' singleExpression  */
#line 346 ".\\parser.y"
                                            { Print("- R: singleExpression '-' singleExpression -> singleExpression"); (yyval.exprNode) = createMinusExpressionNode((yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2877 "parser.tab.c"
    break;

  case 75: /* singleExpression: singleExpression '*' singleExpression  */
#line 347 ".\\parser.y"
                                            { Print("- R: singleExpression '*' singleExpression -> singleExpression"); (yyval.exprNode) = createMulExpressionNode((yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2883 "parser.tab.c"
    break;

  case 76: /* singleExpression: singleExpression '/' singleExpression  */
#line 348 ".\\parser.y"
                                            { Print("- R: singleExpression '/' singleExpression -> singleExpression"); (yyval.exprNode) = createDivExpressionNode((yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2889 "parser.tab.c"
    break;

  case 77: /* singleExpression: singleExpression '<' singleExpression  */
#line 349 ".\\parser.y"
                                            { Print("- R: singleExpression '<' singleExpression -> singleExpression"); (yyval.exprNode) = createLessExpressionNode((yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2895 "parser.tab.c"
    break;

  case 78: /* singleExpression: singleExpression '>' singleExpression  */
#line 350 ".\\parser.y"
                                            { Print("- R: singleExpression '>' singleExpression -> singleExpression"); (yyval.exprNode) = createGreatExpressionNode((yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2901 "parser.tab.c"
    break;

  case 79: /* singleExpression: singleExpression OPERATOR_EQUAL singleExpression  */
#line 353 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_EQUAL singleExpression -> singleExpression"); (yyval.exprNode) = createEqualExpressionNode((yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2907 "parser.tab.c"
    break;

  case 80: /* singleExpression: singleExpression OPERATOR_NOT_EQUAL singleExpression  */
#line 355 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_NOT_EQUAL singleExpression -> singleExpression"); (yyval.exprNode) = createNotEqualExpressionNode((yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2913 "parser.tab.c"
    break;

  case 81: /* singleExpression: singleExpression OPERATOR_STRICT_EQUAL singleExpression  */
#line 357 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_STRICT_EQUAL singleExpression -> singleExpression"); (yyval.exprNode) = createStrictEqualExpressionNode((yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2919 "parser.tab.c"
    break;

  case 82: /* singleExpression: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression  */
#line 359 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression -> singleExpression"); (yyval.exprNode) = createStrictNotEqualExpressionNode((yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2925 "parser.tab.c"
    break;

  case 83: /* singleExpression: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression  */
#line 361 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression -> singleExpression"); (yyval.exprNode) = createLessEqualExpressionNode((yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2931 "parser.tab.c"
    break;

  case 84: /* singleExpression: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression  */
#line 363 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression -> singleExpression"); (yyval.exprNode) = createGreaterEqualExpressionNode((yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2937 "parser.tab.c"
    break;

  case 85: /* singleExpression: singleExpression '=' singleExpression  */
#line 366 ".\\parser.y"
        { Print("- R: singleExpression '=' singleExpression -> singleExpression"); (yyval.exprNode) = createAssignExpressionNode((yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2943 "parser.tab.c"
    break;

  case 86: /* singleExpression: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression  */
#line 368 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression -> singleExpression"); (yyval.exprNode) = createAssignMulExpressionNode((yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2949 "parser.tab.c"
    break;

  case 87: /* singleExpression: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression  */
#line 370 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression -> singleExpression"); (yyval.exprNode) = createAssignDivExpressionNode((yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2955 "parser.tab.c"
    break;

  case 88: /* singleExpression: singleExpression OPERATOR_ASSIGN_PLUS singleExpression  */
#line 372 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_PLUS singleExpression -> singleExpression"); (yyval.exprNode) = createAssignPlusExpressionNode((yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2961 "parser.tab.c"
    break;

  case 89: /* singleExpression: singleExpression OPERATOR_ASSIGN_MINUS singleExpression  */
#line 374 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_MINUS singleExpression -> singleExpression"); (yyval.exprNode) = createAssignMinusExpressionNode((yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2967 "parser.tab.c"
    break;

  case 90: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression  */
#line 376 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression -> singleExpression"); (yyval.exprNode) = createAssignLogAndExpressionNode((yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2973 "parser.tab.c"
    break;

  case 91: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression  */
#line 378 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression -> singleExpression"); (yyval.exprNode) = createAssignLogOrExpressionNode((yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2979 "parser.tab.c"
    break;

  case 92: /* singleExpression: singleExpression OPERATOR_LOGICAL_OR singleExpression  */
#line 381 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_LOGICAL_OR singleExpression -> singleExpression"); (yyval.exprNode) = createLogOrExpressionNode((yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2985 "parser.tab.c"
    break;

  case 93: /* singleExpression: singleExpression OPERATOR_LOGICAL_AND singleExpression  */
#line 383 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_LOGICAL_AND singleExpression -> singleExpression"); (yyval.exprNode) = createLogAndExpressionNode((yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2991 "parser.tab.c"
    break;

  case 94: /* singleExpression: singleExpression INSTANCEOF singleExpression  */
#line 385 ".\\parser.y"
                                                    { Print("- R: singleExpression INSTANCEOF singleExpression -> singleExpression"); (yyval.exprNode) = createInstanceOfExpressionNode((yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 2997 "parser.tab.c"
    break;

  case 95: /* singleExpression: singleExpression IN singleExpression  */
#line 386 ".\\parser.y"
                                                    { Print("- R: singleExpression IN singleExpression -> singleExpression"); (yyval.exprNode) = createInExpressionNode((yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 3003 "parser.tab.c"
    break;

  case 96: /* singleExpression: singleExpression '?' singleExpression ':' singleExpression  */
#line 389 ".\\parser.y"
        { Print("- R: singleExpression '?' singleExpression ':' singleExpression -> singleExpression"); (yyval.exprNode) = createTernaryExpressionNode((yyvsp[-4].exprNode), (yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 3009 "parser.tab.c"
    break;

  case 97: /* singleExpression: singleExpression ',' singleExpression  */
#line 392 ".\\parser.y"
        { Print("- R: singleExpression ',' singleExpressionn -> singleExpression"); (yyval.exprNode) = createCommaExpressionNode((yyvsp[-2].exprNode), (yyvsp[0].exprNode)); }
#line 3015 "parser.tab.c"
    break;

  case 98: /* singleExpression: '(' singleExpression ')'  */
#line 395 ".\\parser.y"
        { Print("- R: '(' singleExpression ')' -> singleExpression"); (yyval.exprNode) = createBracketsExpressionNode((yyvsp[-1].exprNode)); }
#line 3021 "parser.tab.c"
    break;

  case 99: /* singleExpression: identifier '(' ')'  */
#line 399 ".\\parser.y"
        { Print("- R: identifier '(' ')' -> singleExpression"); (yyval.exprNode) = createFuncCallExpressionNode((yyvsp[-2].identName), createExpressionListNode(nullptr)); }
#line 3027 "parser.tab.c"
    break;

  case 100: /* singleExpression: identifier '(' singleExpression ')'  */
#line 401 ".\\parser.y"
        { Print("- R: identifier '(' singleExpression ')' -> singleExpression"); (yyval.exprNode) = createFuncCallExpressionNode((yyvsp[-3].identName), createExpressionListFromExpression((yyvsp[-1].exprNode))); }
#line 3033 "parser.tab.c"
    break;

  case 101: /* singleExpression: identifier '(' singleExpression ',' ')'  */
#line 404 ".\\parser.y"
        { Print("- R: identifier '(' singleExpression ',' ')' -> singleExpression"); (yyval.exprNode) = createFuncCallExpressionNode((yyvsp[-4].identName), createExpressionListFromExpression((yyvsp[-2].exprNode))); }
#line 3039 "parser.tab.c"
    break;

  case 102: /* singleExpression: singleExpression '.' identifier  */
#line 408 ".\\parser.y"
        { Print("- R: singleExpression '.' identifier -> singleExpression"); (yyval.exprNode) = createFieldAccessExpressionNode((yyvsp[-2].exprNode), (yyvsp[0].identName)); }
#line 3045 "parser.tab.c"
    break;

  case 103: /* singleExpression: singleExpression '.' identifier '(' ')'  */
#line 410 ".\\parser.y"
        { Print("- R: singleExpression '.' identifier '(' ')' -> singleExpression"); (yyval.exprNode) = createMethodAccessExpressionNode((yyvsp[-4].exprNode), (yyvsp[-2].identName), createExpressionListNode(nullptr)); }
#line 3051 "parser.tab.c"
    break;

  case 104: /* singleExpression: singleExpression '.' identifier '(' singleExpression ')'  */
#line 412 ".\\parser.y"
        { Print("- R: singleExpression '.' identifier '(' singleExpression ')' -> singleExpression"); (yyval.exprNode) = createMethodAccessExpressionNode((yyvsp[-5].exprNode), (yyvsp[-3].identName), createExpressionListFromExpression((yyvsp[-1].exprNode))); }
#line 3057 "parser.tab.c"
    break;

  case 105: /* singleExpression: singleExpression '.' identifier '(' singleExpression ',' ')'  */
#line 414 ".\\parser.y"
        { Print("- R: singleExpression '.' identifier '(' singleExpression ',' ')' -> singleExpression"); (yyval.exprNode) = createMethodAccessExpressionNode((yyvsp[-6].exprNode), (yyvsp[-4].identName), createExpressionListFromExpression((yyvsp[-2].exprNode))); }
#line 3063 "parser.tab.c"
    break;

  case 106: /* singleExpression: arrayLiteral  */
#line 416 ".\\parser.y"
                                                              { Print("- R: arrayLiteral -> singleExpression"); (yyval.exprNode) = (yyvsp[0].exprNode); }
#line 3069 "parser.tab.c"
    break;

  case 107: /* singleExpression: singleExpression '[' singleExpression ']'  */
#line 417 ".\\parser.y"
                                                              { Print("- R: singleExpression '[' singleExpression ']' -> singleExpression"); (yyval.exprNode) = createArrayAccessExpressionNode((yyvsp[-3].exprNode), (yyvsp[-1].exprNode)); }
#line 3075 "parser.tab.c"
    break;

  case 108: /* singleExpression: singleExpression ENDL_BRACKET_OPEN singleExpression ']'  */
#line 418 ".\\parser.y"
                                                              { Print("- R: singleExpression ENDL_BRACKET_OPEN singleExpression ']' -> singleExpression"); (yyval.exprNode) = createArrayAccessExpressionNode((yyvsp[-3].exprNode), (yyvsp[-1].exprNode)); }
#line 3081 "parser.tab.c"
    break;

  case 109: /* varStatement: varModifier varDeclarationList ';'  */
#line 428 ".\\parser.y"
                                         { Print("- R: varModifier varDeclarationList ';' -> varStatement"); (yyval.stmtNode) = createVarStatementNode((yyvsp[-2].varModifierType), (yyvsp[-1].varDeclListNode)); }
#line 3087 "parser.tab.c"
    break;

  case 111: /* varDeclarationList: varDeclaration  */
#line 434 ".\\parser.y"
        { Print("- R: varDeclaration -> varDeclarationList"); (yyval.varDeclListNode) = createVarDeclarationListNode((yyvsp[0].varDeclNode)); }
#line 3093 "parser.tab.c"
    break;

  case 112: /* varDeclarationList: varDeclarationList ',' varDeclaration  */
#line 436 ".\\parser.y"
        { Print("- R: varDeclarationList ',' varDeclaration -> varDeclarationList"); (yyval.varDeclListNode) = addVarDeclarationToVarDeclarationList((yyvsp[-2].varDeclListNode), (yyvsp[0].varDeclNode)); }
#line 3099 "parser.tab.c"
    break;

  case 113: /* varDeclaration: identifier typeAnnotationOpt  */
#line 441 ".\\parser.y"
        { Print("- R: identifier typeAnnotationOpt -> varDeclaration"); (yyval.varDeclNode) = createVarDeclarationNode((yyvsp[-1].identName), (yyvsp[0].typeNode), nullptr); }
#line 3105 "parser.tab.c"
    break;

  case 114: /* varDeclaration: identifier typeAnnotationOpt '=' singleExpression  */
#line 443 ".\\parser.y"
        { Print("- R: identifier typeAnnotationOpt '=' singleExpression -> varDeclaration"); (yyval.varDeclNode) = createVarDeclarationNode((yyvsp[-3].identName), (yyvsp[-2].typeNode), (yyvsp[0].exprNode)); }
#line 3111 "parser.tab.c"
    break;

  case 115: /* varModifier: VAR  */
#line 447 ".\\parser.y"
            { Print("- R: VAR -> varModifier"); (yyval.varModifierType) = VarModifierType::_VAR; }
#line 3117 "parser.tab.c"
    break;

  case 116: /* varModifier: LET  */
#line 448 ".\\parser.y"
            { Print("- R: LET -> varModifier"); (yyval.varModifierType) = VarModifierType::_LET; }
#line 3123 "parser.tab.c"
    break;

  case 117: /* varModifier: CONST  */
#line 449 ".\\parser.y"
            { Print("- R: CONST -> varModifier"); (yyval.varModifierType) = VarModifierType::_CONST; }
#line 3129 "parser.tab.c"
    break;

  case 118: /* ifStatement: IF '(' singleExpression ')' statementListItemWithoutEmptyStatement  */
#line 456 ".\\parser.y"
        { 
            Print("- R: IF '(' expressionList ')' statementListItem -> ifStatement");
            (yyval.stmtNode) = createIfElseStatementNode((yyvsp[-2].exprNode), (yyvsp[0].stmtNode), nullptr);
        }
#line 3138 "parser.tab.c"
    break;

  case 119: /* ifStatement: IF '(' singleExpression ')' statementListItemWithoutEmptyStatement ELSE statementListItem  */
#line 462 ".\\parser.y"
        { 
            Print("- R: IF '(' expressionList ')' statementListItem ELSE statementListItem -> ifStatement");
            (yyval.stmtNode) = createIfElseStatementNode((yyvsp[-4].exprNode), (yyvsp[-2].stmtNode), (yyvsp[0].stmtNode));
        }
#line 3147 "parser.tab.c"
    break;

  case 120: /* $@1: %empty  */
#line 471 ".\\parser.y"
                                                          { doWhileASI(); }
#line 3153 "parser.tab.c"
    break;

  case 121: /* iterationStatement: DO statementListItem WHILE '(' singleExpression ')' $@1 ';'  */
#line 472 ".\\parser.y"
        { 
            Print("- R: DO statementListItem WHILE '(' expressionList ')' ';' -> iterationStatement");
            (yyval.stmtNode) = createDoWhileStatementNode((yyvsp[-6].stmtNode), (yyvsp[-3].exprNode));
        }
#line 3162 "parser.tab.c"
    break;

  case 122: /* iterationStatement: WHILE '(' singleExpression ')' statementListItem  */
#line 478 ".\\parser.y"
        { 
            Print("- R: WHILE '(' expressionList ')' statementListItem -> iterationStatement");
            (yyval.stmtNode) = createWhileStatementNode((yyvsp[-2].exprNode), (yyvsp[0].stmtNode));
        }
#line 3171 "parser.tab.c"
    break;

  case 123: /* $@2: %empty  */
#line 483 ".\\parser.y"
                                                                                        { isInForHeader = 0; }
#line 3177 "parser.tab.c"
    break;

  case 124: /* iterationStatement: forHeader singleExpressionOpt ';' singleExpressionOpt ';' singleExpressionOpt ')' $@2 statementListItem  */
#line 484 ".\\parser.y"
        { 
            Print("- R: FOR '(' singleExpressionOpt ';' singleExpressionOpt ';' singleExpressionOpt ')' statementListItem -> iterationStatement");
            (yyval.stmtNode) = createClassicForStatementNode((yyvsp[-7].exprNode), (yyvsp[-5].exprNode), (yyvsp[-3].exprNode), (yyvsp[0].stmtNode));
        }
#line 3186 "parser.tab.c"
    break;

  case 125: /* $@3: %empty  */
#line 489 ".\\parser.y"
                                                                                                   { isInForHeader = 0; }
#line 3192 "parser.tab.c"
    break;

  case 126: /* iterationStatement: forHeader varModifier varDeclarationList ';' singleExpressionOpt ';' singleExpressionOpt ')' $@3 statementListItem  */
#line 490 ".\\parser.y"
        {
            Print("- R: FOR '(' varModifier varDeclarationList ';' singleExpressionOpt ';' singleExpressionOpt ')' statementListItem -> iterationStatement");
            (yyval.stmtNode) = createClassicForWithVarDeclStatementNode((yyvsp[-8].varModifierType), (yyvsp[-7].varDeclListNode), (yyvsp[-5].exprNode), (yyvsp[-3].exprNode), (yyvsp[0].stmtNode));
        }
#line 3201 "parser.tab.c"
    break;

  case 127: /* $@4: %empty  */
#line 495 ".\\parser.y"
                                                         { isInForHeader = 0; }
#line 3207 "parser.tab.c"
    break;

  case 128: /* iterationStatement: forHeader singleExpression IN singleExpression ')' $@4 statementListItem  */
#line 496 ".\\parser.y"
        {
            Print("- R: FOR '(' singleExpression IN singleExpression ')' statementListItem -> iterationStatement");
            (yyval.stmtNode) = createForExprInExprStatementNode((yyvsp[-5].exprNode), (yyvsp[-3].exprNode), (yyvsp[0].stmtNode));
        }
#line 3216 "parser.tab.c"
    break;

  case 129: /* $@5: %empty  */
#line 501 ".\\parser.y"
                                                                   { isInForHeader = 0; }
#line 3222 "parser.tab.c"
    break;

  case 130: /* iterationStatement: forHeader varModifier varDeclaration IN singleExpression ')' $@5 statementListItem  */
#line 502 ".\\parser.y"
        {
            Print("- R: FOR '(' varModifier varDeclaration IN expressionList ')' statementListItem -> iterationStatement");
            (yyval.stmtNode) = createForVarDeclInExprStatementNode((yyvsp[-6].varModifierType), (yyvsp[-5].varDeclNode), (yyvsp[-3].exprNode), (yyvsp[0].stmtNode));
        }
#line 3231 "parser.tab.c"
    break;

  case 131: /* forHeader: FOR '('  */
#line 509 ".\\parser.y"
               { isInForHeader = 1; }
#line 3237 "parser.tab.c"
    break;

  case 132: /* returnStatement: RETURN ';'  */
#line 515 ".\\parser.y"
                                    { Print("- R: RETURN ';' -> returnStatement"); (yyval.stmtNode) = createReturnStatementNode(nullptr); }
#line 3243 "parser.tab.c"
    break;

  case 133: /* returnStatement: RETURN singleExpression ';'  */
#line 516 ".\\parser.y"
                                    { Print("- R: RETURN singleExpression ';' -> returnStatement"); (yyval.stmtNode) = createReturnStatementNode((yyvsp[-1].exprNode)); }
#line 3249 "parser.tab.c"
    break;

  case 134: /* functionDeclaration: FUNCTION identifier '(' parameterList ')' typeAnnotationOpt functionBody  */
#line 521 ".\\parser.y"
        {
            Print("- R: FUNCTION ID '(' parameterList ')' typeAnnotation functionBody -> functionDeclaration");
            (yyval.funcDeclarationNode) = createFunctionDeclarationNode((yyvsp[-5].identName), (yyvsp[-3].requiredParameterListNode), (yyvsp[-1].typeNode), (yyvsp[0].stmtListNode));
        }
#line 3258 "parser.tab.c"
    break;

  case 135: /* functionBody: '{' '}'  */
#line 528 ".\\parser.y"
              { Print("- R: '{' '}' -> functionBody"); (yyval.stmtListNode) = createStatementListNode(nullptr); }
#line 3264 "parser.tab.c"
    break;

  case 136: /* $@6: %empty  */
#line 529 ".\\parser.y"
          { isInFunctionBody = 1; }
#line 3270 "parser.tab.c"
    break;

  case 137: /* functionBody: '{' $@6 statementList '}'  */
#line 530 ".\\parser.y"
        { 
            isInFunctionBody = 0; 
            Print("- R: '{' statementList '}' -> functionBody");
            (yyval.stmtListNode) = (yyvsp[-1].stmtListNode);
        }
#line 3280 "parser.tab.c"
    break;

  case 138: /* parameterList: %empty  */
#line 538 ".\\parser.y"
                                { Print("- R: #empty# -> parameterList"); (yyval.requiredParameterListNode) = createRequiredParameterListNode(nullptr); }
#line 3286 "parser.tab.c"
    break;

  case 139: /* parameterList: requiredParameterList  */
#line 539 ".\\parser.y"
                                { Print("- R: requiredParameterList -> parameterList"); (yyval.requiredParameterListNode) = (yyvsp[0].requiredParameterListNode); }
#line 3292 "parser.tab.c"
    break;

  case 140: /* parameterList: requiredParameterList ','  */
#line 540 ".\\parser.y"
                                { Print("- R: requiredParameterList ',' -> parameterList"); (yyval.requiredParameterListNode) = (yyvsp[-1].requiredParameterListNode); }
#line 3298 "parser.tab.c"
    break;

  case 141: /* requiredParameterList: requiredParameter  */
#line 545 ".\\parser.y"
        {
            Print("- R: requiredParameter -> requiredParameterList");
            (yyval.requiredParameterListNode) = createRequiredParameterListNode((yyvsp[0].requiredParameterNode));
        }
#line 3307 "parser.tab.c"
    break;

  case 142: /* requiredParameterList: requiredParameterList ',' requiredParameter  */
#line 550 ".\\parser.y"
        {
            Print("- R: requiredParameterList ',' requiredParameter -> requiredParameterList");
            (yyval.requiredParameterListNode) = addRequiredParameterToRequiredParameterList((yyvsp[-2].requiredParameterListNode), (yyvsp[0].requiredParameterNode));
        }
#line 3316 "parser.tab.c"
    break;

  case 143: /* requiredParameter: identifier typeAnnotationOpt  */
#line 558 ".\\parser.y"
        { 
            Print("- R: ID typeAnnotationOpt -> requiredParameter");
            (yyval.requiredParameterNode) = createRequiredParameterNode((yyvsp[-1].identName), (yyvsp[0].typeNode));
        }
#line 3325 "parser.tab.c"
    break;

  case 144: /* classDeclaration: CLASS identifier classTail  */
#line 568 ".\\parser.y"
        {
            Print("- R: CLASS identifier classTail -> classDeclaration");
            (yyval.classDeclNode) = createClassDeclarationNode((yyvsp[-1].identName), nullptr, (yyvsp[0].classElementListNode));
        }
#line 3334 "parser.tab.c"
    break;

  case 145: /* classDeclaration: CLASS identifier classHeritage classTail  */
#line 573 ".\\parser.y"
        {
            Print("- R: CLASS identifier classHeritage classTail -> classDeclaration");
            (yyval.classDeclNode) = createClassDeclarationNode((yyvsp[-2].identName), (yyvsp[-1].identName), (yyvsp[0].classElementListNode));
        }
#line 3343 "parser.tab.c"
    break;

  case 146: /* classHeritage: EXTENDS identifier  */
#line 580 ".\\parser.y"
                         { Print("- R: EXTENDS identifier -> classHeritage"); (yyval.identName) = (yyvsp[0].identName); }
#line 3349 "parser.tab.c"
    break;

  case 147: /* classTail: '{' '}'  */
#line 584 ".\\parser.y"
                                { Print("- R: '{' '}' -> classTail"); (yyval.classElementListNode) = createClassElementListNode(nullptr); }
#line 3355 "parser.tab.c"
    break;

  case 148: /* classTail: '{' classElementList '}'  */
#line 585 ".\\parser.y"
                                { Print("- R: '{' classElementList '}' -> classTail"); (yyval.classElementListNode) = (yyvsp[-1].classElementListNode); }
#line 3361 "parser.tab.c"
    break;

  case 149: /* classElementList: classElement  */
#line 589 ".\\parser.y"
                                    { Print("- R: classElement -> classElementList"); (yyval.classElementListNode) = createClassElementListNode((yyvsp[0].classElementNode)); }
#line 3367 "parser.tab.c"
    break;

  case 150: /* classElementList: classElementList classElement  */
#line 590 ".\\parser.y"
                                    { Print("- R: classElementList classElement -> classElementList"); (yyval.classElementListNode) = addClassElementToClassElementList((yyvsp[-1].classElementListNode), (yyvsp[0].classElementNode)); }
#line 3373 "parser.tab.c"
    break;

  case 151: /* classElement: CONSTRUCTOR '(' parameterList ')' functionBody  */
#line 595 ".\\parser.y"
        {
            Print("- R: CONSTRUCTOR '(' parameterList ')' functionBody -> classElement");
            (yyval.classElementNode) = createClassConstructor((yyvsp[-2].requiredParameterListNode), (yyvsp[0].stmtListNode));
        }
#line 3382 "parser.tab.c"
    break;

  case 152: /* classElement: propertyName typeAnnotationOpt ';'  */
#line 602 ".\\parser.y"
        {
            Print("- R: propertyName typeAnnotationOpt ';' -> classElement");
            (yyval.classElementNode) = createClassProperty((yyvsp[-2].identName), (yyvsp[-1].typeNode), nullptr);
        }
#line 3391 "parser.tab.c"
    break;

  case 153: /* classElement: propertyName typeAnnotationOpt '=' singleExpression ';'  */
#line 607 ".\\parser.y"
        {
            Print("- R: propertyName typeAnnotationOpt '=' singleExpression ';' -> classElement");
            (yyval.classElementNode) = createClassProperty((yyvsp[-4].identName), (yyvsp[-3].typeNode), (yyvsp[-1].exprNode));
        }
#line 3400 "parser.tab.c"
    break;

  case 154: /* classElement: propertyName '(' parameterList ')' typeAnnotationOpt functionBody  */
#line 614 ".\\parser.y"
        {
            Print("- R: propertyName '(' parameterList ')' typeAnnotationOpt functionBody -> classElement");
            (yyval.classElementNode) = createClassMethod((yyvsp[-5].identName), (yyvsp[-3].requiredParameterListNode), (yyvsp[-1].typeNode), (yyvsp[0].stmtListNode));
        }
#line 3409 "parser.tab.c"
    break;

  case 155: /* classElement: GET propertyName '(' ')' typeAnnotationOpt functionBody  */
#line 621 ".\\parser.y"
        {
            Print("- R: GET propertyName '(' ')' typeAnnotationOpt functionBody -> classElement");
            (yyval.classElementNode) = createClassGetter((yyvsp[-4].identName), (yyvsp[-1].typeNode), (yyvsp[0].stmtListNode));
        }
#line 3418 "parser.tab.c"
    break;

  case 156: /* classElement: SET propertyName '(' parameterList ')' functionBody  */
#line 626 ".\\parser.y"
        {
            Print("- R: SET propertyName callSignature functionBody -> classElement");
            (yyval.classElementNode) = createClassSetter((yyvsp[-4].identName), (yyvsp[-2].requiredParameterListNode), (yyvsp[0].stmtListNode));
        }
#line 3427 "parser.tab.c"
    break;

  case 157: /* propertyName: identifier  */
#line 633 ".\\parser.y"
                 { Print("- R: identifier -> propertyName"); }
#line 3433 "parser.tab.c"
    break;

  case 158: /* identifier: ID  */
#line 637 ".\\parser.y"
                { Print("- R: ID -> identifier"); (yyval.identName) = (yyvsp[0].identName); }
#line 3439 "parser.tab.c"
    break;

  case 159: /* identifier: ASYNC  */
#line 638 ".\\parser.y"
                { Print("- R: ASYNC -> identifier"); (yyval.identName) = strdup("async"); }
#line 3445 "parser.tab.c"
    break;

  case 160: /* identifier: AS  */
#line 639 ".\\parser.y"
                { Print("- R: AS -> identifier"); (yyval.identName) = strdup("as"); }
#line 3451 "parser.tab.c"
    break;

  case 161: /* identifier: FROM  */
#line 640 ".\\parser.y"
                { Print("- R: FROM -> identifier"); (yyval.identName) = strdup("from"); }
#line 3457 "parser.tab.c"
    break;

  case 162: /* identifier: YIELD  */
#line 641 ".\\parser.y"
                { Print("- R: YIELD -> identifier"); (yyval.identName) = strdup("yield"); }
#line 3463 "parser.tab.c"
    break;

  case 163: /* identifier: ANY  */
#line 642 ".\\parser.y"
                { Print("- R: ANY -> identifier"); (yyval.identName) = strdup("any"); }
#line 3469 "parser.tab.c"
    break;

  case 164: /* identifier: NUMBER  */
#line 643 ".\\parser.y"
                { Print("- R: NUMBER -> identifier"); (yyval.identName) = strdup("number"); }
#line 3475 "parser.tab.c"
    break;

  case 165: /* identifier: BOOLEAN  */
#line 644 ".\\parser.y"
                { Print("- R: BOOLEAN -> identifier"); (yyval.identName) = strdup("boolean"); }
#line 3481 "parser.tab.c"
    break;

  case 166: /* identifier: STRING  */
#line 645 ".\\parser.y"
                { Print("- R: STRING -> identifier"); (yyval.identName) = strdup("string"); }
#line 3487 "parser.tab.c"
    break;

  case 167: /* identifier: UNIQUE  */
#line 646 ".\\parser.y"
                { Print("- R: UNIQUE -> identifier"); (yyval.identName) = strdup("unique"); }
#line 3493 "parser.tab.c"
    break;

  case 168: /* identifier: SYMBOL  */
#line 647 ".\\parser.y"
                { Print("- R: SYMBOL -> identifier"); (yyval.identName) = strdup("symbol"); }
#line 3499 "parser.tab.c"
    break;

  case 169: /* identifier: NEVER  */
#line 648 ".\\parser.y"
                { Print("- R: NEVER -> identifier"); (yyval.identName) = strdup("never"); }
#line 3505 "parser.tab.c"
    break;

  case 170: /* identifier: UNDEFINED  */
#line 649 ".\\parser.y"
                { Print("- R: UNDEFINED -> identifier"); (yyval.identName) = strdup("undefined"); }
#line 3511 "parser.tab.c"
    break;

  case 171: /* identifier: OBJECT  */
#line 650 ".\\parser.y"
                { Print("- R: OBJECT -> identifier"); (yyval.identName) = strdup("object"); }
#line 3517 "parser.tab.c"
    break;

  case 172: /* identifier: KEYOF  */
#line 651 ".\\parser.y"
                { Print("- R: KEYOF -> identifier"); (yyval.identName) = strdup("keyof"); }
#line 3523 "parser.tab.c"
    break;

  case 173: /* identifier: NAMESPACE  */
#line 652 ".\\parser.y"
                { Print("- R: NAMESPACE -> identifier"); (yyval.identName) = strdup("namespace"); }
#line 3529 "parser.tab.c"
    break;

  case 174: /* identifier: ABSTRACT  */
#line 653 ".\\parser.y"
                { Print("- R: ABSTRACT -> identifier"); (yyval.identName) = strdup("abstract"); }
#line 3535 "parser.tab.c"
    break;

  case 175: /* identifier: REQUIRE  */
#line 654 ".\\parser.y"
                { Print("- R: REQUIRE -> identifier"); (yyval.identName) = strdup("require"); }
#line 3541 "parser.tab.c"
    break;


#line 3545 "parser.tab.c"

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

#line 657 ".\\parser.y"



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


