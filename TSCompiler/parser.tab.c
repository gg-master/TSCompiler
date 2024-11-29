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

#line 98 "parser.tab.c"

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
    CONTINUE = 271,                /* CONTINUE  */
    BREAK = 272,                   /* BREAK  */
    SWITCH = 273,                  /* SWITCH  */
    CASE = 274,                    /* CASE  */
    DEFAULT = 275,                 /* DEFAULT  */
    RETURN = 276,                  /* RETURN  */
    SUPER = 277,                   /* SUPER  */
    THIS = 278,                    /* THIS  */
    NEW = 279,                     /* NEW  */
    ELLIPSIS = 280,                /* ELLIPSIS  */
    OF = 281,                      /* OF  */
    ASYNC = 282,                   /* ASYNC  */
    AS = 283,                      /* AS  */
    FROM = 284,                    /* FROM  */
    YIELD = 285,                   /* YIELD  */
    KEYOF = 286,                   /* KEYOF  */
    CONSTRUCTOR = 287,             /* CONSTRUCTOR  */
    NAMESPACE = 288,               /* NAMESPACE  */
    ABSTRACT = 289,                /* ABSTRACT  */
    REQUIRE = 290,                 /* REQUIRE  */
    ANY = 291,                     /* ANY  */
    NUMBER = 292,                  /* NUMBER  */
    BOOLEAN = 293,                 /* BOOLEAN  */
    STRING = 294,                  /* STRING  */
    NEVER = 295,                   /* NEVER  */
    UNDEFINED = 296,               /* UNDEFINED  */
    UNIQUE = 297,                  /* UNIQUE  */
    SYMBOL = 298,                  /* SYMBOL  */
    OBJECT = 299,                  /* OBJECT  */
    VOID = 300,                    /* VOID  */
    UNKNOWN = 301,                 /* UNKNOWN  */
    STRING_LIT = 302,              /* STRING_LIT  */
    INT_LIT = 303,                 /* INT_LIT  */
    FLOAT_LIT = 304,               /* FLOAT_LIT  */
    NULL_KW = 305,                 /* NULL_KW  */
    TRUE_KW = 306,                 /* TRUE_KW  */
    FALSE_KW = 307,                /* FALSE_KW  */
    ID = 308,                      /* ID  */
    ENDL = 309,                    /* ENDL  */
    TEMPLATE_LITERAL = 310,        /* TEMPLATE_LITERAL  */
    OPERATOR_INCREMENT = 311,      /* OPERATOR_INCREMENT  */
    OPERATOR_DECREMENT = 312,      /* OPERATOR_DECREMENT  */
    ENDL_OPERATOR_INCREMENT = 313, /* ENDL_OPERATOR_INCREMENT  */
    ENDL_OPERATOR_DECREMENT = 314, /* ENDL_OPERATOR_DECREMENT  */
    IF_ONLY_PREC = 315,            /* IF_ONLY_PREC  */
    OPERATOR_ASSIGN_PLUS = 316,    /* OPERATOR_ASSIGN_PLUS  */
    OPERATOR_ASSIGN_MINUS = 317,   /* OPERATOR_ASSIGN_MINUS  */
    OPERATOR_ASSIGN_POWER = 318,   /* OPERATOR_ASSIGN_POWER  */
    OPERATOR_ASSIGN_MULTIPLY = 319, /* OPERATOR_ASSIGN_MULTIPLY  */
    OPERATOR_ASSIGN_DIVIDE = 320,  /* OPERATOR_ASSIGN_DIVIDE  */
    OPERATOR_ASSIGN_MOD = 321,     /* OPERATOR_ASSIGN_MOD  */
    OPERATOR_ASSIGN_SHIFT_LEFT = 322, /* OPERATOR_ASSIGN_SHIFT_LEFT  */
    OPERATOR_ASSIGN_SHIFT_RIGHT = 323, /* OPERATOR_ASSIGN_SHIFT_RIGHT  */
    OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT = 324, /* OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT  */
    OPERATOR_ASSIGN_BITWISE_AND = 325, /* OPERATOR_ASSIGN_BITWISE_AND  */
    OPERATOR_ASSIGN_BITWISE_XOR = 326, /* OPERATOR_ASSIGN_BITWISE_XOR  */
    OPERATOR_ASSIGN_BITWISE_OR = 327, /* OPERATOR_ASSIGN_BITWISE_OR  */
    OPERATOR_ASSIGN_LOGICAL_AND = 328, /* OPERATOR_ASSIGN_LOGICAL_AND  */
    OPERATOR_ASSIGN_LOGICAL_OR = 329, /* OPERATOR_ASSIGN_LOGICAL_OR  */
    OPERATOR_ASSIGN_NULLISH_COALESCING = 330, /* OPERATOR_ASSIGN_NULLISH_COALESCING  */
    OPERATOR_NULLISH_COALESCING = 331, /* OPERATOR_NULLISH_COALESCING  */
    OPERATOR_LOGICAL_OR = 332,     /* OPERATOR_LOGICAL_OR  */
    OPERATOR_LOGICAL_AND = 333,    /* OPERATOR_LOGICAL_AND  */
    OPERATOR_EQUAL = 334,          /* OPERATOR_EQUAL  */
    OPERATOR_NOT_EQUAL = 335,      /* OPERATOR_NOT_EQUAL  */
    OPERATOR_STRICT_EQUAL = 336,   /* OPERATOR_STRICT_EQUAL  */
    OPERATOR_STRICT_NOT_EQUAL = 337, /* OPERATOR_STRICT_NOT_EQUAL  */
    OPERATOR_GREATER_THAN_EQUAL = 338, /* OPERATOR_GREATER_THAN_EQUAL  */
    OPERATOR_LESS_THAN_EQUAL = 339, /* OPERATOR_LESS_THAN_EQUAL  */
    INSTANCEOF = 340,              /* INSTANCEOF  */
    IN = 341,                      /* IN  */
    OPERATOR_SHIFT_LEFT = 342,     /* OPERATOR_SHIFT_LEFT  */
    OPERATOR_SHIFT_RIGHT = 343,    /* OPERATOR_SHIFT_RIGHT  */
    OPERATOR_UNSIGNED_SHIFT_RIGHT = 344, /* OPERATOR_UNSIGNED_SHIFT_RIGHT  */
    OPERATOR_POWER = 345,          /* OPERATOR_POWER  */
    UMINUS = 346,                  /* UMINUS  */
    UPLUS = 347,                   /* UPLUS  */
    PREF_INCREMENT = 348,          /* PREF_INCREMENT  */
    PREF_DECREMENT = 349,          /* PREF_DECREMENT  */
    POST_INCREMENT = 350,          /* POST_INCREMENT  */
    POST_DECREMENT = 351,          /* POST_DECREMENT  */
    ENDL_BRACKET_OPEN = 352,       /* ENDL_BRACKET_OPEN  */
    OPTIONAL_CHAINING_OPERATOR = 353 /* OPTIONAL_CHAINING_OPERATOR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 ".\\parser.y"

    int _integer;
    char* _string;
    char* _id;
    double _floatingPoint;

#line 250 "parser.tab.c"

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
  YYSYMBOL_blockStatement = 129,           /* blockStatement  */
  YYSYMBOL_initializer = 130,              /* initializer  */
  YYSYMBOL_type = 131,                     /* type  */
  YYSYMBOL_unionOrIntersectionOrPrimaryType = 132, /* unionOrIntersectionOrPrimaryType  */
  YYSYMBOL_primaryType = 133,              /* primaryType  */
  YYSYMBOL_tupleTypeElements = 134,        /* tupleTypeElements  */
  YYSYMBOL_predefinedType = 135,           /* predefinedType  */
  YYSYMBOL_typeAnnotation = 136,           /* typeAnnotation  */
  YYSYMBOL_simpleLiteral = 137,            /* simpleLiteral  */
  YYSYMBOL_arrayLiteral = 138,             /* arrayLiteral  */
  YYSYMBOL_elementList = 139,              /* elementList  */
  YYSYMBOL_arrayElement = 140,             /* arrayElement  */
  YYSYMBOL_expressionStatement = 141,      /* expressionStatement  */
  YYSYMBOL_expressionListOpt = 142,        /* expressionListOpt  */
  YYSYMBOL_expressionList = 143,           /* expressionList  */
  YYSYMBOL_singleExpression = 144,         /* singleExpression  */
  YYSYMBOL_arguments = 145,                /* arguments  */
  YYSYMBOL_argumentList = 146,             /* argumentList  */
  YYSYMBOL_argument = 147,                 /* argument  */
  YYSYMBOL_varStatement = 148,             /* varStatement  */
  YYSYMBOL_varDeclarationList = 149,       /* varDeclarationList  */
  YYSYMBOL_varDeclaration = 150,           /* varDeclaration  */
  YYSYMBOL_varModifier = 151,              /* varModifier  */
  YYSYMBOL_ifStatement = 152,              /* ifStatement  */
  YYSYMBOL_switchStatement = 153,          /* switchStatement  */
  YYSYMBOL_caseClauseList = 154,           /* caseClauseList  */
  YYSYMBOL_caseClause = 155,               /* caseClause  */
  YYSYMBOL_defaultClause = 156,            /* defaultClause  */
  YYSYMBOL_iterationStatement = 157,       /* iterationStatement  */
  YYSYMBOL_158_1 = 158,                    /* $@1  */
  YYSYMBOL_159_2 = 159,                    /* $@2  */
  YYSYMBOL_160_3 = 160,                    /* $@3  */
  YYSYMBOL_161_4 = 161,                    /* $@4  */
  YYSYMBOL_162_5 = 162,                    /* $@5  */
  YYSYMBOL_163_6 = 163,                    /* $@6  */
  YYSYMBOL_164_7 = 164,                    /* $@7  */
  YYSYMBOL_forHeader = 165,                /* forHeader  */
  YYSYMBOL_continueStatement = 166,        /* continueStatement  */
  YYSYMBOL_breakStatement = 167,           /* breakStatement  */
  YYSYMBOL_labelledStatement = 168,        /* labelledStatement  */
  YYSYMBOL_returnStatement = 169,          /* returnStatement  */
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
#define YYFINAL  110
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2733

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  123
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  270
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  458

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
     110,   111,   118,   125,   132,   133,   134,   135,   137,   141,
     142,   143,   144,   145,   146,   153,   160,   167,   168,   169,
     170,   172,   176,   187,   188,   192,   198,   199,   200,   204,
     205,   206,   210,   211,   212,   213,   214,   215,   219,   220,
     221,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   240,   244,   245,   246,   247,   252,   253,
     257,   258,   259,   263,   264,   270,   274,   275,   279,   280,
     284,   285,   286,   287,   288,   289,   290,   292,   293,   295,
     296,   298,   299,   301,   302,   303,   304,   306,   307,   308,
     309,   310,   311,   312,   314,   317,   320,   323,   326,   329,
     332,   335,   338,   341,   344,   347,   350,   353,   356,   359,
     362,   365,   368,   371,   374,   377,   380,   383,   386,   389,
     392,   395,   398,   401,   404,   407,   410,   411,   413,   416,
     419,   421,   423,   426,   428,   429,   430,   432,   436,   437,
     438,   442,   443,   447,   448,   454,   455,   459,   460,   464,
     465,   466,   467,   471,   472,   473,   479,   482,   487,   490,
     493,   496,   501,   502,   506,   507,   511,   512,   518,   518,
     518,   521,   521,   524,   524,   527,   527,   530,   530,   533,
     533,   538,   542,   543,   547,   548,   552,   558,   559,   564,
     568,   569,   569,   573,   574,   578,   579,   580,   581,   583,
     584,   585,   587,   589,   590,   591,   593,   594,   595,   597,
     601,   602,   606,   607,   611,   612,   616,   617,   618,   619,
     623,   624,   630,   631,   635,   639,   640,   644,   645,   649,
     652,   653,   654,   655,   658,   661,   662,   663,   667,   671,
     672,   673,   674,   678,   679,   680,   681,   682,   683,   684,
     685,   686,   687,   688,   689,   690,   691,   692,   693,   694,
     695
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
  "emptyStatement", "blockStatement", "initializer", "type",
  "unionOrIntersectionOrPrimaryType", "primaryType", "tupleTypeElements",
  "predefinedType", "typeAnnotation", "simpleLiteral", "arrayLiteral",
  "elementList", "arrayElement", "expressionStatement",
  "expressionListOpt", "expressionList", "singleExpression", "arguments",
  "argumentList", "argument", "varStatement", "varDeclarationList",
  "varDeclaration", "varModifier", "ifStatement", "switchStatement",
  "caseClauseList", "caseClause", "defaultClause", "iterationStatement",
  "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "forHeader",
  "continueStatement", "breakStatement", "labelledStatement",
  "returnStatement", "functionDeclaration", "functionBody", "$@8",
  "callSignature", "parameterList", "requiredParameterList",
  "optionalParameterList", "requiredParameter", "optionalParameter",
  "restParameter", "classDeclaration", "classHeritage", "classTail",
  "classElementList", "classElement", "constructorCallSignature",
  "propertyName", "identifier", YY_NULLPTR
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

#define YYTABLE_NINF (-178)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1524,  -369,  -369,  -369,  -369,   -76,  2680,  2680,  -369,   -74,
     -71,   704,   826,   -67,  1775,  -369,  -369,  2009,  -369,  -369,
    -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,
    -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,
    -369,  -369,  -369,  2009,  2009,  2009,  2009,  2009,  2009,  2009,
    2009,  1912,  1912,  2009,  -369,  1036,    54,  1159,  -369,  -369,
    -369,  -369,  -369,  -369,   -33,  2400,  -369,   958,  -369,  -369,
    -369,   183,  -369,  -369,  -369,  -369,  -369,  -369,   -17,  2009,
     -47,     3,  1524,  2009,  -369,  -369,    29,  -369,    30,  2009,
    -369,  2206,  -369,   134,   134,   134,   134,   134,   134,   134,
     134,   134,  2009,   -34,  -369,  2400,   -24,   -11,  -369,  1280,
    -369,  -369,  2009,  -369,  -369,  -369,  -369,  2009,  2009,  2009,
    2009,  2009,  2009,  2009,  2009,  2009,  2009,  2009,  2009,  2009,
    2009,  2009,  2009,  2009,  2009,  2009,  2009,  2009,  2009,  2009,
    2009,  2009,  2009,  2009,  2009,  2009,  2009,  2009,  2009,  2009,
    2009,  2009,  2009,  2009,  2009,  2009,  2009,  2009,  2009,  2680,
    2009,  2009,  2009,  1874,  -369,    33,   -30,  -369,   -10,    38,
      42,  2464,  2680,  1524,    -5,  2211,    21,  2680,  1679,    27,
    -369,   146,    -3,  -369,  -369,     7,  -369,  2400,  1912,  -369,
    -369,  -369,  -369,  2400,  2521,  2521,  2521,  2521,  2521,  2521,
    2521,  2521,  2521,  2521,  2521,  2521,  2521,  2521,  2521,  2521,
    2272,  1138,  1258,  1379,  1500,  2555,  2588,  1748,  1748,  1748,
    1748,   322,   322,   322,   322,   322,   322,    81,    81,    81,
      53,    53,   141,   141,   141,   141,  -369,   -18,    22,    43,
    2009,  -369,  2400,    13,  -369,  -369,  2680,  -369,  2009,  2092,
     100,  2009,  2009,   -26,    69,  -369,  1645,  2009,    46,   113,
     115,  -369,  -369,   118,    57,    67,  -369,  -369,  2042,  2042,
      78,    92,    92,  -369,  -369,  1741,  -369,   -16,  -369,  -369,
      82,  -369,    83,  -369,  2009,  -369,  -369,  2400,   -58,  -369,
    -369,  2400,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,
    -369,  -369,  -369,  2142,  2142,  2092,  2092,  2092,  -369,   -45,
      88,  -369,  -369,  2009,    89,   210,  2009,  2009,  -369,   196,
    -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,  -369,
    -369,  -369,  2336,   129,  2211,  2211,  -369,  2009,   129,  -369,
     153,  -369,  1524,   111,   -47,  2211,    21,   122,   128,  -369,
    -369,  -369,   124,     2,    21,  2009,  1524,    -2,  1016,  -369,
    -369,   -45,   -45,  -369,    23,    28,   130,  2142,  2142,  2114,
    2400,  2009,  -369,   133,    14,  1524,  -369,  -369,   199,  -369,
     200,  -369,   201,    57,  2400,  -369,  -369,  1402,   144,    21,
     145,  -369,  -369,  -369,  -369,  -369,   150,  -369,    15,  -369,
    2009,  -369,    -4,  -369,  2092,  -369,  -369,  -369,   180,  -369,
    -369,   -35,   152,  1524,  2009,  -369,  -369,  2211,  -369,  -369,
     153,  -369,   -43,  -369,  -369,  -369,  -369,   -20,   193,  -369,
    -369,    -1,  -369,  -369,  -369,  -369,   154,  1524,   213,    21,
    -369,   156,   535,   792,  -369,     1,  1524,  -369,  -369,  -369,
    -369,  -369,   670,   914,  -369,  -369,  1524,  -369
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,    18,   163,   164,   165,     0,     0,     0,   178,     0,
       0,     0,     0,     0,     0,    83,    82,     0,   254,   255,
     256,   257,   267,   268,   269,   270,   258,   259,   260,   261,
     264,   265,   262,   263,   266,    64,    65,    66,    86,    84,
      85,   253,    67,     0,     0,     0,     0,     0,     0,     0,
       0,    70,    70,     0,    32,     0,     0,     0,     3,     5,
      15,    81,   144,     6,     0,    78,     7,     0,     8,     9,
      10,    76,    11,    12,    14,    13,    16,    17,    80,     0,
       0,     0,     0,     0,   191,   192,     0,   194,     0,     0,
     197,     0,    80,   147,    95,    96,    93,    94,    88,    87,
      89,    90,     0,     0,    71,    73,     0,     0,    33,     0,
       1,     4,     0,    75,   138,    91,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,     0,     0,   157,   159,     0,
      77,    78,     0,     0,     0,   205,     0,     0,     0,     0,
     232,     0,     0,   193,   195,     0,   198,    74,    70,    68,
      69,   140,    34,    79,   111,   115,   116,   122,   112,   113,
     114,   117,   118,   126,   119,   120,   121,   123,   124,   125,
       0,   135,   127,   128,   129,   130,   131,   105,   106,   107,
     108,   103,   102,   110,   109,   136,   137,   132,   133,   134,
      97,    98,    99,   100,   101,   104,   143,     0,     0,   142,
       0,   148,   153,     0,   151,   156,     0,   155,     0,     0,
     160,    76,     0,     0,   157,   196,     0,     0,     0,   206,
     207,   220,   222,   208,   224,   201,   199,   234,     0,     0,
       0,     0,     0,   235,   250,     0,   237,     0,   249,   233,
       0,   181,     0,    72,     0,   145,   146,   154,     0,   149,
     158,   161,    51,    52,    54,    53,    55,    57,    58,    56,
      59,    60,    61,     0,     0,    48,    48,     0,    63,    36,
      41,    43,    62,     0,     0,   137,    76,     0,    31,   166,
      28,    19,    20,    21,    22,    23,    24,    25,    27,    26,
      29,    30,   230,   203,   213,   214,   215,     0,   226,   228,
     225,   200,     0,     0,     0,   205,     0,     0,     0,   236,
     238,   240,     0,     0,     0,     0,     0,     0,   139,   150,
     152,    37,    38,    49,     0,     0,     0,     0,     0,     0,
     162,    76,   187,     0,     0,     0,   231,   204,   209,   221,
     210,   223,   211,     0,    35,   227,   229,     0,     0,     0,
       0,   239,   251,   252,   242,   241,     0,   244,     0,   182,
       0,   168,     0,   172,     0,    46,    47,    42,    39,    40,
      44,     0,     0,     0,    76,   189,   167,   216,   217,   218,
       0,   202,     0,   247,   248,   243,   179,     0,     0,   169,
     173,     0,    50,    45,   183,   188,     0,     0,   212,     0,
     245,     0,     0,     0,   170,     0,     0,   185,   190,   219,
     246,   180,     0,     0,   171,   184,     0,   186
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -369,  -369,   -51,   -56,  -369,  -369,    24,  -268,  -241,  -255,
     -92,   -28,  -369,  -232,  -176,  -369,   -42,  -369,    25,  -246,
     -50,   359,    -9,  -369,  -369,    31,   112,  -158,   214,    34,
      36,  -145,  -368,  -369,    37,  -369,  -369,  -369,  -369,  -369,
    -369,  -369,  -369,    39,    40,    47,    48,    59,  -324,  -369,
    -258,   -29,  -369,   -40,   -36,  -312,  -310,    61,  -369,   123,
    -369,    45,  -369,  -124,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    56,    57,    58,   319,    59,    60,   339,   363,   309,
     310,   364,   311,   250,    61,    62,   103,   104,    63,   169,
      64,    65,   164,   243,   244,    66,   166,   167,    67,    68,
      69,   402,   403,   431,    70,    82,   441,   356,   446,   456,
     413,   437,    71,    72,    73,    74,    75,    76,   266,   342,
     176,   258,   259,   260,   261,   262,   263,    77,   179,   180,
     275,   276,   346,   277,    92
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      78,   111,   274,   107,   109,   314,    80,    81,   308,   352,
     106,    86,    88,   177,   254,   400,   428,   400,   400,   354,
     400,   170,   391,   381,   380,   382,   181,   188,   112,   174,
     397,   246,   340,   182,   430,   246,   249,   188,   367,   185,
     368,   112,    79,   112,    83,   353,   337,    84,   361,   362,
     112,    89,   248,   111,   110,    78,   112,    78,   112,   442,
     163,   359,   173,   249,   337,   423,   366,   168,   112,   249,
     373,   175,   386,   312,   288,   112,   112,   430,   265,   369,
     433,   189,    78,   112,   404,   396,   389,   113,   290,   404,
     247,   190,   274,   274,   316,   347,   348,   285,   440,   274,
     376,   377,   175,   112,   351,   381,   385,   438,   191,    78,
     237,   238,   408,   409,   256,   450,   281,   255,   429,   337,
     401,   444,   395,   454,   178,   412,   282,   312,   312,   312,
     312,   312,   289,   415,   426,   338,   249,   286,   405,    35,
      36,    37,   265,   406,   343,   344,   283,    42,   178,   183,
     184,   420,   386,   245,   155,   156,   157,   158,   251,   236,
     280,   163,   313,   432,   317,   333,   159,   160,   436,   161,
     162,   163,   168,    78,   334,   264,   335,   267,   278,   336,
     153,   154,   155,   156,   157,   158,     2,     3,     4,   341,
     439,   312,   312,   312,   159,   160,   345,   161,   162,   163,
     355,   170,   369,   375,   357,    15,    16,    17,   249,   371,
      18,    19,    20,    21,    22,   337,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,   312,   388,
      35,    36,    37,    38,    39,    40,    41,   392,    42,    43,
      44,    45,    46,   393,   394,   158,   168,   159,   160,   407,
     161,   162,   163,   414,   159,   160,    78,   161,   162,   163,
     417,   418,   419,   422,   424,   368,   170,   374,   278,   278,
     425,   434,   443,   447,   449,   278,   451,   411,   365,   360,
     320,   321,    47,    48,   253,   172,   445,   322,    49,    50,
     323,   387,   324,   325,   378,   326,   327,    51,   379,    52,
     399,    53,   279,   328,   329,   398,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   330,   390,   331,     0,   416,
     350,   170,     0,   159,   160,     0,   161,   162,   163,   372,
       0,   111,     0,     0,   264,   383,     0,     0,     0,     0,
       0,     0,    78,     0,     0,   264,     0,     0,     0,     0,
     427,     0,     0,     0,     0,     0,    78,   435,     0,     0,
       0,     0,     0,     0,   170,     0,     0,     0,     0,     0,
       0,     0,     0,    91,     0,    78,    93,     0,     0,     0,
       0,   448,     0,     0,     0,     0,     0,    78,     0,     0,
     455,   452,   453,     0,     0,     0,   111,   111,     0,     0,
     457,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     105,   105,     0,    78,     0,     0,     0,   383,   150,   151,
     152,   153,   154,   155,   156,   157,   158,     0,     0,     0,
     171,     0,     0,     0,     0,   159,   160,    78,   161,   162,
     163,     0,    78,    78,     0,     0,    78,     0,     0,     0,
       0,     0,    78,    78,     0,     0,    78,     0,     0,     0,
       0,   187,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   193,     0,     0,     0,     0,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,     0,     0,
       0,   239,   242,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     2,     3,
       4,     5,     0,     6,     7,     0,     0,   105,     8,     9,
      10,    11,    12,    13,  -174,  -174,    14,    15,    16,    17,
       0,     0,    18,    19,    20,    21,    22,     0,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       0,     0,    35,    36,    37,    38,    39,    40,    41,     0,
      42,    43,    44,    45,    46,     0,     0,     0,     0,   287,
       0,     0,     0,     0,     0,     0,     0,   291,     0,     0,
       0,   315,     0,     0,     0,     0,   332,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,    48,     0,     0,     0,     0,
      49,    50,     0,   358,     0,     0,     0,     0,     0,    51,
       0,    52,     0,    53,     0,    54,    55,  -174,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,   370,     2,     3,     4,     5,     0,     6,     7,
       0,     0,     0,     8,     9,    10,    11,    12,    13,  -175,
    -175,    14,    15,    16,    17,     0,   384,    18,    19,    20,
      21,    22,     0,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,     0,     0,    35,    36,    37,
      38,    39,    40,    41,     0,    42,    43,    44,    45,    46,
       0,    18,    19,    20,    21,    22,     0,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     0,
       0,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
      48,     0,     0,     0,     0,    49,    50,     0,     0,     0,
       0,     0,     0,     0,    51,     0,    52,     0,    53,     0,
      54,    55,  -175,     1,     0,     2,     3,     4,     5,     0,
       6,     7,     0,     0,     0,     8,     9,    10,    11,    12,
      13,  -176,     0,    14,    15,    16,    17,     0,     0,    18,
      19,    20,    21,    22,    85,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     0,     0,    35,
      36,    37,    38,    39,    40,    41,     0,    42,    43,    44,
      45,    46,     0,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,     0,     0,     0,     0,     0,     0,     0,     0,    41,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,    48,     0,     0,     0,     0,    49,    50,     0,
       0,     0,     0,     0,     0,     0,    51,     0,    52,     0,
      53,     0,    54,    55,  -176,     1,     0,     2,     3,     4,
       5,     0,     6,     7,     0,     0,     0,     8,     9,    10,
      11,    12,    13,  -177,     0,    14,    15,    16,    17,     0,
       0,    18,    19,    20,    21,    22,    87,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,   165,
       0,    35,    36,    37,    38,    39,    40,    41,     0,    42,
      43,    44,    45,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,    19,    20,    21,    22,
       0,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     0,     0,     0,     0,     0,     0,     0,
       0,    41,     0,    47,    48,     0,     0,     0,     0,    49,
      50,     0,     0,     0,     0,     0,     0,     0,    51,     0,
      52,     0,    53,     0,    54,    55,  -177,     1,     0,     2,
       3,     4,     5,     0,     6,     7,     0,     0,     0,     8,
       9,    10,    11,    12,    13,     0,     0,    14,    15,    16,
      17,     0,     0,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,     0,     0,    35,    36,    37,    38,    39,    40,    41,
       0,    42,    43,    44,    45,    46,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,     0,     0,     0,     0,     0,     0,     0,     0,   159,
     160,     0,   161,   162,   163,    47,    48,     0,     0,     0,
       0,    49,    50,     0,     0,     0,     0,     0,     0,     0,
      51,     0,    52,     0,    53,     0,    54,    55,   108,    -2,
       1,     0,     2,     3,     4,     5,     0,     6,     7,     0,
       0,     0,     8,     9,    10,    11,    12,    13,     0,     0,
      14,    15,    16,    17,     0,     0,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,     0,    35,    36,    37,    38,
      39,    40,    41,     0,    42,    43,    44,    45,    46,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,     0,     0,     0,     0,     0,     0,     0,
       0,   159,   160,     0,   161,   162,   163,     0,    47,    48,
       0,     0,     0,     0,    49,    50,     0,     0,     0,     0,
       0,     0,     0,    51,     0,    52,     0,    53,     0,    54,
      55,     1,     0,     2,     3,     4,     5,     0,     6,     7,
       0,     0,     0,     8,     9,    10,    11,    12,    13,     0,
       0,    14,    15,    16,    17,     0,     0,    18,    19,    20,
      21,    22,     0,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,     0,     0,    35,    36,    37,
      38,    39,    40,    41,     0,    42,    43,    44,    45,    46,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,     0,     0,     0,     0,     0,     0,     0,
       0,   159,   160,     0,   161,   162,   163,     0,     0,    47,
      48,     0,     0,     0,     0,    49,    50,     0,     0,     0,
       0,     0,     0,     0,    51,     0,    52,     0,    53,     0,
      54,    55,   192,     1,     0,     2,     3,     4,     5,     0,
       6,     7,     0,     0,     0,     8,     9,    10,    11,    12,
      13,     0,     0,    14,    15,    16,    17,     0,     0,    18,
      19,    20,    21,    22,     0,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     0,     0,    35,
      36,    37,    38,    39,    40,    41,     0,    42,    43,    44,
      45,    46,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,     0,     0,     0,     0,     0,     0,
       0,     0,   159,   160,     0,   161,   162,   163,     0,     0,
       0,    47,    48,     0,     0,     0,     0,    49,    50,     0,
       0,     0,     0,     0,     0,     0,    51,     0,    52,     0,
      53,     0,    54,    55,   421,     1,     0,     2,     3,     4,
       5,     0,     6,     7,     0,     0,     0,     8,     9,    10,
      11,    12,    13,     0,     0,    14,    15,    16,    17,     0,
       0,    18,    19,    20,    21,    22,     0,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     0,
       0,    35,    36,    37,    38,    39,    40,    41,     0,    42,
      43,    44,    45,    46,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,     0,     0,     0,     0,     0,
       0,     0,     0,   159,   160,     0,   161,   162,   163,     0,
       0,     0,     0,    47,    48,     0,     0,     0,     0,    49,
      50,     0,     0,     0,     0,     0,     0,     0,    51,     0,
      52,     0,    53,     0,    54,    55,   318,     0,     2,     3,
       4,     5,     0,     6,     7,     0,     0,     0,     8,     9,
      10,    11,    12,    13,     0,     0,    14,    15,    16,    17,
       0,     0,    18,    19,    20,    21,    22,     0,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
     268,   269,    35,    36,    37,    38,    39,    40,    41,     0,
      42,    43,    44,    45,    46,     0,    18,    19,    20,    21,
      22,   270,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,     0,    35,    36,    37,     0,
       0,     0,    41,     0,    42,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,    48,     0,     0,     0,     0,
      49,    50,   268,   269,     0,     0,     0,     0,     0,    51,
       0,    52,     0,    53,     0,     0,    55,     0,    18,    19,
      20,    21,    22,   270,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,     0,     0,    35,    36,
      37,     0,     0,   271,    41,   272,    42,    15,    16,    17,
       0,   273,    18,    19,    20,    21,    22,     0,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       0,     0,    35,    36,    37,    38,    39,    40,    41,     0,
      42,    43,    44,    45,    46,     0,     0,     0,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,     0,     0,   271,     0,   272,     0,     0,
       0,   159,   160,   349,   161,   162,   163,     0,     0,     0,
       0,     0,     0,     0,    47,    48,     0,     0,     0,     0,
      49,    50,     0,     0,     0,     0,     0,     0,     0,    51,
       0,    52,     0,    53,     0,    90,    15,    16,    17,   240,
       0,    18,    19,    20,    21,    22,     0,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     0,
       0,    35,    36,    37,    38,    39,    40,    41,     0,    42,
      43,    44,    45,    46,    15,    16,    17,   102,     0,    18,
      19,    20,    21,    22,     0,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     0,     0,    35,
      36,    37,    38,    39,    40,    41,     0,    42,    43,    44,
      45,    46,     0,    47,    48,     0,     0,     0,     0,    49,
      50,     0,     0,     0,     0,     0,     0,     0,    51,     0,
      52,     0,    53,   241,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,    48,     0,     0,     0,     0,    49,    50,     0,
       0,     0,     0,     0,     0,     0,    51,     0,    52,     0,
      53,    15,    16,    17,     0,     0,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,     0,    35,    36,    37,    38,
      39,    40,    41,     0,    42,    43,    44,    45,    46,    18,
      19,    20,    21,    22,     0,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     0,     0,    35,
      36,    37,     0,     0,     0,    41,     0,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,    48,
       0,     0,     0,     0,    49,    50,     0,     0,     0,     0,
       0,     0,     0,    51,     0,    52,     0,    53,   292,   293,
     294,   295,   296,   297,     0,     0,     0,   298,   299,    35,
      36,    37,   300,   301,   302,     0,     0,    42,     0,     0,
     292,   293,   294,   295,   296,   297,   271,     0,   272,   298,
     299,    35,    36,    37,   300,   301,   302,     0,     0,    42,
       0,     0,     0,     0,     0,   303,     0,   304,   292,   293,
     294,   295,   296,   297,     0,     0,     0,   298,   299,    35,
      36,    37,   300,   301,   302,     0,     0,    42,     0,     0,
       0,     0,     0,     0,     0,     0,   305,     0,   306,     0,
     307,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   305,   410,
     306,     0,   307,     0,     0,     0,   257,     0,    18,    19,
      20,    21,    22,     0,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,   305,     0,   306,     0,
     307,   114,   115,   116,    41,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,     0,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,     0,     0,     0,     0,     0,     0,     0,     0,   159,
     160,     0,   161,   162,   163,     0,   186,   114,   115,   116,
       0,     0,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   284,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,     0,     0,     0,
       0,     0,     0,     0,     0,   159,   160,     0,   161,   162,
     163,   114,   115,   116,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   249,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,     0,     0,     0,     0,     0,     0,     0,     0,   159,
     160,     0,   161,   162,   163,   114,   115,   116,     0,     0,
       0,     0,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,     0,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,     0,     0,     0,     0,     0,
       0,     0,     0,   159,   160,     0,   161,   162,   163,   114,
     115,   116,     0,     0,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,     0,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   252,
     150,   151,   152,   153,   154,   155,   156,   157,   158,     0,
       0,     0,     0,     0,     0,     0,     0,   159,   160,     0,
     161,   162,   163,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
       0,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,     0,     0,     0,     0,
       0,     0,     0,     0,   159,   160,     0,   161,   162,   163,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
       0,     0,     0,     0,     0,     0,     0,     0,   159,   160,
       0,   161,   162,   163,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,     0,     0,     0,     0,     0,     0,     0,
       0,   159,   160,     0,   161,   162,   163,    18,    19,    20,
      21,    22,     0,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,     0,     0,     0,     0,     0,
       0,     0,     0,    41
};

static const yytype_int16 yycheck[] =
{
       0,    57,   178,    53,    55,   251,     6,     7,   249,   277,
      52,    11,    12,    10,   172,    19,    20,    19,    19,   277,
      19,    71,   346,   335,   334,   335,    82,    61,    61,    79,
     354,    61,   264,    83,   402,    61,    79,    61,    83,    89,
      85,    61,   118,    61,   118,   277,    62,   118,   303,   304,
      61,   118,    62,   109,     0,    55,    61,    57,    61,    79,
     118,   119,    79,    79,    62,   389,   307,    67,    61,    79,
     316,   118,   340,   249,    61,    61,    61,   445,   121,   114,
     115,   115,    82,    61,    61,   353,   344,   120,   246,    61,
     120,   115,   268,   269,   120,   271,   272,   115,   422,   275,
     332,   333,   118,    61,   120,   417,   338,   417,   119,   109,
     160,   161,   367,   368,   119,   439,   119,   173,   122,    62,
     122,   122,   120,   122,   121,   371,   119,   303,   304,   305,
     306,   307,   119,   119,   119,    78,    79,   115,   115,    47,
      48,    49,   121,   115,   268,   269,   188,    55,   121,   120,
     120,   383,   420,   120,   101,   102,   103,   104,   120,   159,
      14,   118,    62,   404,    95,   119,   113,   114,   414,   116,
     117,   118,   172,   173,    61,   175,    61,   177,   178,    61,
      99,   100,   101,   102,   103,   104,     3,     4,     5,   122,
     422,   367,   368,   369,   113,   114,   118,   116,   117,   118,
     118,   251,   114,     7,   121,    22,    23,    24,    79,   120,
      27,    28,    29,    30,    31,    62,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,   404,   118,
      47,    48,    49,    50,    51,    52,    53,   115,    55,    56,
      57,    58,    59,   115,   120,   104,   246,   113,   114,   119,
     116,   117,   118,   120,   113,   114,   256,   116,   117,   118,
      61,    61,    61,   119,   119,    85,   316,   317,   268,   269,
     120,   119,    79,   119,    61,   275,   120,   369,   306,   288,
     256,   256,    99,   100,   172,    71,   431,   256,   105,   106,
     256,   342,   256,   256,   334,   256,   256,   114,   334,   116,
     356,   118,   179,   256,   256,   355,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   256,   345,   256,    -1,   375,
     275,   371,    -1,   113,   114,    -1,   116,   117,   118,   119,
      -1,   387,    -1,    -1,   334,   335,    -1,    -1,    -1,    -1,
      -1,    -1,   342,    -1,    -1,   345,    -1,    -1,    -1,    -1,
     400,    -1,    -1,    -1,    -1,    -1,   356,   413,    -1,    -1,
      -1,    -1,    -1,    -1,   414,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    14,    -1,   375,    17,    -1,    -1,    -1,
      -1,   437,    -1,    -1,    -1,    -1,    -1,   387,    -1,    -1,
     446,   442,   443,    -1,    -1,    -1,   452,   453,    -1,    -1,
     456,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,   413,    -1,    -1,    -1,   417,    96,    97,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,    -1,
      71,    -1,    -1,    -1,    -1,   113,   114,   437,   116,   117,
     118,    -1,   442,   443,    -1,    -1,   446,    -1,    -1,    -1,
      -1,    -1,   452,   453,    -1,    -1,   456,    -1,    -1,    -1,
      -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,    -1,    -1,
      -1,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,   188,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    27,    28,    29,    30,    31,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,   240,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,   252,    -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,
     105,   106,    -1,   284,    -1,    -1,    -1,    -1,    -1,   114,
      -1,   116,    -1,   118,    -1,   120,   121,   122,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     1,   313,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,   337,    27,    28,    29,
      30,    31,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      -1,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,    -1,   116,    -1,   118,    -1,
     120,   121,   122,     1,    -1,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    13,    14,    15,    16,    17,
      18,    19,    -1,    21,    22,    23,    24,    -1,    -1,    27,
      28,    29,    30,    31,   120,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    -1,    27,    28,    29,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,    -1,    -1,    -1,    -1,   105,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,   116,    -1,
     118,    -1,   120,   121,   122,     1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    13,    14,    15,
      16,    17,    18,    19,    -1,    21,    22,    23,    24,    -1,
      -1,    27,    28,    29,    30,    31,   120,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     1,
      -1,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    99,   100,    -1,    -1,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,
     116,    -1,   118,    -1,   120,   121,   122,     1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    13,
      14,    15,    16,    17,    18,    -1,    -1,    21,    22,    23,
      24,    -1,    -1,    27,    28,    29,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
     114,    -1,   116,   117,   118,    99,   100,    -1,    -1,    -1,
      -1,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,    -1,   116,    -1,   118,    -1,   120,   121,   122,     0,
       1,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
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
     121,     1,    -1,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    13,    14,    15,    16,    17,    18,    -1,
      -1,    21,    22,    23,    24,    -1,    -1,    27,    28,    29,
      30,    31,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,   114,    -1,   116,   117,   118,    -1,    -1,    99,
     100,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,    -1,   116,    -1,   118,    -1,
     120,   121,   122,     1,    -1,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    13,    14,    15,    16,    17,
      18,    -1,    -1,    21,    22,    23,    24,    -1,    -1,    27,
      28,    29,    30,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,   114,    -1,   116,   117,   118,    -1,    -1,
      -1,    99,   100,    -1,    -1,    -1,    -1,   105,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,   116,    -1,
     118,    -1,   120,   121,   122,     1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    13,    14,    15,
      16,    17,    18,    -1,    -1,    21,    22,    23,    24,    -1,
      -1,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,    -1,   116,   117,   118,    -1,
      -1,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,
     116,    -1,   118,    -1,   120,   121,     1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    13,    14,
      15,    16,    17,    18,    -1,    -1,    21,    22,    23,    24,
      -1,    -1,    27,    28,    29,    30,    31,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      11,    12,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,
     105,   106,    11,    12,    -1,    -1,    -1,    -1,    -1,   114,
      -1,   116,    -1,   118,    -1,    -1,   121,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    47,    48,
      49,    -1,    -1,   114,    53,   116,    55,    22,    23,    24,
      -1,   122,    27,    28,    29,    30,    31,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    -1,    -1,   114,    -1,   116,    -1,    -1,
      -1,   113,   114,   122,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,
     105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,   116,    -1,   118,    -1,   120,    22,    23,    24,    25,
      -1,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    22,    23,    24,    25,    -1,    27,
      28,    29,    30,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    -1,    99,   100,    -1,    -1,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,
     116,    -1,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,    -1,    -1,    -1,    -1,   105,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,   116,    -1,
     118,    22,    23,    24,    -1,    -1,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    27,
      28,    29,    30,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    47,
      48,    49,    -1,    -1,    -1,    53,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
      -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,   116,    -1,   118,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    55,    -1,    -1,
      36,    37,    38,    39,    40,    41,   114,    -1,   116,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    83,    -1,    85,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,   116,    -1,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,
     116,    -1,   118,    -1,    -1,    -1,    25,    -1,    27,    28,
      29,    30,    31,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,   114,    -1,   116,    -1,
     118,    55,    56,    57,    53,    -1,    -1,    -1,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    -1,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
     114,    -1,   116,   117,   118,    -1,   120,    55,    56,    57,
      -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,    67,
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
      -1,    -1,    -1,   113,   114,    -1,   116,   117,   118,    55,
      56,    57,    -1,    -1,    -1,    -1,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    -1,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,
     116,   117,   118,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,   114,    -1,   116,   117,   118,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
      -1,   116,   117,   118,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,   114,    -1,   116,   117,   118,    27,    28,    29,
      30,    31,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53
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
     106,   114,   116,   118,   120,   121,   124,   125,   126,   128,
     129,   137,   138,   141,   143,   144,   148,   151,   152,   153,
     157,   165,   166,   167,   168,   169,   170,   180,   187,   118,
     187,   187,   158,   118,   118,   120,   187,   120,   187,   118,
     120,   144,   187,   144,   144,   144,   144,   144,   144,   144,
     144,   144,    25,   139,   140,   144,   139,   143,   122,   125,
       0,   126,    61,   120,    55,    56,    57,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   113,
     114,   116,   117,   118,   145,     1,   149,   150,   187,   142,
     143,   144,   151,    79,   143,   118,   173,    10,   121,   181,
     182,   126,   143,   120,   120,   143,   120,   144,    61,   115,
     115,   119,   122,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   187,   143,   143,   144,
      25,   119,   144,   146,   147,   120,    61,   120,    62,    79,
     136,   120,    95,   149,   150,   126,   119,    25,   174,   175,
     176,   177,   178,   179,   187,   121,   171,   187,    11,    12,
      32,   114,   116,   122,   137,   183,   184,   186,   187,   182,
      14,   119,   119,   139,    79,   115,   115,   144,    61,   119,
     150,   144,    36,    37,    38,    39,    40,    41,    45,    46,
      50,    51,    52,    83,    85,   114,   116,   118,   131,   132,
     133,   135,   137,    62,   142,   144,   120,    95,     1,   127,
     129,   141,   148,   152,   153,   157,   166,   167,   168,   169,
     170,   180,   144,   119,    61,    61,    61,    62,    78,   130,
     136,   122,   172,   186,   186,   118,   185,   137,   137,   122,
     184,   120,   130,   136,   173,   118,   160,   121,   144,   119,
     145,   132,   132,   131,   134,   134,   131,    83,    85,   114,
     144,   120,   119,   142,   143,     7,   136,   136,   176,   177,
     179,   178,   179,   187,   144,   136,   130,   125,   118,   173,
     174,   171,   115,   115,   120,   120,   130,   171,   143,   126,
      19,   122,   154,   155,    61,   115,   115,   119,   132,   132,
     115,   133,   142,   163,   120,   119,   126,    61,    61,    61,
     136,   122,   119,   171,   119,   120,   119,   143,    20,   122,
     155,   156,   131,   115,   119,   126,   142,   164,   179,   136,
     171,   159,    79,    79,   122,   154,   161,   119,   126,    61,
     171,   120,   125,   125,   122,   126,   162,   126
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   123,   124,   125,   125,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   128,   129,   129,   130,   131,   131,   131,   132,
     132,   132,   133,   133,   133,   133,   133,   133,   134,   134,
     134,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   136,   137,   137,   137,   137,   138,   138,
     139,   139,   139,   140,   140,   141,   142,   142,   143,   143,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   145,   145,
     145,   146,   146,   147,   147,   148,   148,   149,   149,   150,
     150,   150,   150,   151,   151,   151,   152,   152,   153,   153,
     153,   153,   154,   154,   155,   155,   156,   156,   158,   159,
     157,   160,   157,   161,   157,   162,   157,   163,   157,   164,
     157,   165,   166,   166,   167,   167,   168,   169,   169,   170,
     171,   172,   171,   173,   173,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     175,   175,   176,   176,   177,   177,   178,   178,   178,   178,
     179,   179,   180,   180,   181,   182,   182,   183,   183,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   185,   186,
     186,   186,   186,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     2,     1,     2,     2,     3,
       3,     1,     3,     1,     3,     4,     3,     3,     0,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     3,     3,
       0,     1,     3,     1,     2,     2,     0,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     5,
       3,     2,     3,     3,     1,     4,     4,     2,     2,     3,
       4,     1,     3,     1,     2,     3,     3,     1,     3,     1,
       2,     3,     4,     1,     1,     1,     5,     7,     6,     7,
       8,     9,     1,     2,     3,     4,     2,     3,     0,     0,
       9,     0,     6,     0,     9,     0,    10,     0,     7,     0,
       8,     2,     2,     3,     2,     3,     3,     2,     3,     4,
       2,     0,     4,     3,     4,     0,     1,     1,     1,     3,
       3,     3,     5,     2,     2,     2,     4,     4,     4,     6,
       1,     3,     1,     3,     1,     2,     2,     3,     2,     3,
       2,     3,     3,     4,     2,     2,     3,     1,     2,     3,
       2,     3,     3,     4,     3,     5,     6,     4,     3,     1,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     1,
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
  case 2: /* script: statementList  */
#line 90 ".\\parser.y"
        { 
            if ( syntaxErrorCounter > 0 ) {
                PrintError("Found " + std::to_string(syntaxErrorCounter) + " syntax errors. Fix them and rerun.");
                exit(1);
            }
            Print("- R: statementList -> script"); 
        }
#line 2637 "parser.tab.c"
    break;

  case 3: /* statementList: statementListItem  */
#line 100 ".\\parser.y"
                                        { Print("- R: statementListItem -> statementList"); }
#line 2643 "parser.tab.c"
    break;

  case 4: /* statementList: statementList statementListItem  */
#line 101 ".\\parser.y"
                                        { Print("- R: statementList statementListItem -> statementList"); }
#line 2649 "parser.tab.c"
    break;

  case 5: /* statementListItem: emptyStatement  */
#line 105 ".\\parser.y"
                                    { Print("- R: emptyStatement -> statementListItem"); }
#line 2655 "parser.tab.c"
    break;

  case 6: /* statementListItem: expressionStatement  */
#line 106 ".\\parser.y"
                                    { Print("- R: expressionStatement -> statementListItem"); }
#line 2661 "parser.tab.c"
    break;

  case 7: /* statementListItem: varStatement  */
#line 107 ".\\parser.y"
                                    { Print("- R: varStatement -> statementListItem"); }
#line 2667 "parser.tab.c"
    break;

  case 8: /* statementListItem: ifStatement  */
#line 108 ".\\parser.y"
                                    { Print("- R: ifStatement -> statementListItem"); }
#line 2673 "parser.tab.c"
    break;

  case 9: /* statementListItem: switchStatement  */
#line 109 ".\\parser.y"
                                    { Print("- R: switchStatement -> statementListItem"); }
#line 2679 "parser.tab.c"
    break;

  case 10: /* statementListItem: iterationStatement  */
#line 110 ".\\parser.y"
                                    { Print("- R: iterationStatement -> statementListItem"); }
#line 2685 "parser.tab.c"
    break;

  case 11: /* statementListItem: continueStatement  */
#line 112 ".\\parser.y"
        {
            if ( !isInIterationBody ) { 
                yyerror("illegal continue statement."); YYERROR;
            } 
            Print("- R: continueStatement -> statementListItem");  
        }
#line 2696 "parser.tab.c"
    break;

  case 12: /* statementListItem: breakStatement  */
#line 119 ".\\parser.y"
        {
            if ( !isInIterationBody ) { 
                yyerror("illegal break statement."); YYERROR;
            } 
            Print("- R: breakStatement -> statementListItem");
        }
#line 2707 "parser.tab.c"
    break;

  case 13: /* statementListItem: returnStatement  */
#line 126 ".\\parser.y"
        { 
            if ( !isInFunctionBody ) { 
                yyerror("illegal return statement."); YYERROR;
            } 
            Print("- R: returnStatement -> statementListItem"); 
        }
#line 2718 "parser.tab.c"
    break;

  case 14: /* statementListItem: labelledStatement  */
#line 132 ".\\parser.y"
                                    { Print("- R: labelledStatement -> statementListItem"); }
#line 2724 "parser.tab.c"
    break;

  case 15: /* statementListItem: blockStatement  */
#line 133 ".\\parser.y"
                                    { Print("- R: blockStatement -> statementListItem"); }
#line 2730 "parser.tab.c"
    break;

  case 16: /* statementListItem: functionDeclaration  */
#line 134 ".\\parser.y"
                                    { Print("- R: functionDeclaration -> statementListItem"); }
#line 2736 "parser.tab.c"
    break;

  case 17: /* statementListItem: classDeclaration  */
#line 135 ".\\parser.y"
                                    { Print("- R: classDeclaration -> statementListItem"); }
#line 2742 "parser.tab.c"
    break;

  case 19: /* statementListItemWithoutEmptyStatement: expressionStatement  */
#line 141 ".\\parser.y"
                                    { Print("- R: expressionStatement -> statementListItemWithoutEmptyStatement"); }
#line 2748 "parser.tab.c"
    break;

  case 20: /* statementListItemWithoutEmptyStatement: varStatement  */
#line 142 ".\\parser.y"
                                    { Print("- R: varStatement -> statementListItemWithoutEmptyStatement"); }
#line 2754 "parser.tab.c"
    break;

  case 21: /* statementListItemWithoutEmptyStatement: ifStatement  */
#line 143 ".\\parser.y"
                                    { Print("- R: ifStatement -> statementListItemWithoutEmptyStatement"); }
#line 2760 "parser.tab.c"
    break;

  case 22: /* statementListItemWithoutEmptyStatement: switchStatement  */
#line 144 ".\\parser.y"
                                    { Print("- R: switchStatement -> statementListItemWithoutEmptyStatement"); }
#line 2766 "parser.tab.c"
    break;

  case 23: /* statementListItemWithoutEmptyStatement: iterationStatement  */
#line 145 ".\\parser.y"
                                    { Print("- R: iterationStatement -> statementListItemWithoutEmptyStatement"); }
#line 2772 "parser.tab.c"
    break;

  case 24: /* statementListItemWithoutEmptyStatement: continueStatement  */
#line 147 ".\\parser.y"
        {
            if ( !isInIterationBody ) { 
                yyerror("illegal continue statement."); YYERROR;
            } 
            Print("- R: continueStatement -> statementListItemWithoutEmptyStatement");
        }
#line 2783 "parser.tab.c"
    break;

  case 25: /* statementListItemWithoutEmptyStatement: breakStatement  */
#line 154 ".\\parser.y"
        {
            if ( !isInIterationBody ) { 
                yyerror("illegal break statement."); YYERROR;
            } 
            Print("- R: breakStatement -> statementListItemWithoutEmptyStatement");
        }
#line 2794 "parser.tab.c"
    break;

  case 26: /* statementListItemWithoutEmptyStatement: returnStatement  */
#line 161 ".\\parser.y"
        { 
            if ( !isInFunctionBody ) { 
                yyerror("illegal return statement."); YYERROR;
            } 
            Print("- R: returnStatement -> statementListItemWithoutEmptyStatement"); 
        }
#line 2805 "parser.tab.c"
    break;

  case 27: /* statementListItemWithoutEmptyStatement: labelledStatement  */
#line 167 ".\\parser.y"
                                    { Print("- R: labelledStatement -> statementListItemWithoutEmptyStatement"); }
#line 2811 "parser.tab.c"
    break;

  case 28: /* statementListItemWithoutEmptyStatement: blockStatement  */
#line 168 ".\\parser.y"
                                    { Print("- R: blockStatement -> statementListItemWithoutEmptyStatement"); }
#line 2817 "parser.tab.c"
    break;

  case 29: /* statementListItemWithoutEmptyStatement: functionDeclaration  */
#line 169 ".\\parser.y"
                                    { Print("- R: functionDeclaration -> statementListItemWithoutEmptyStatement"); }
#line 2823 "parser.tab.c"
    break;

  case 30: /* statementListItemWithoutEmptyStatement: classDeclaration  */
#line 170 ".\\parser.y"
                                    { Print("- R: classDeclaration -> statementListItemWithoutEmptyStatement"); }
#line 2829 "parser.tab.c"
    break;

  case 32: /* emptyStatement: ';'  */
#line 177 ".\\parser.y"
        { 
            if ( isASIActivated ) {
                std::string text(yytext_ptr, yyleng);
                yyerror(("syntax error on token: " + text).c_str()); YYERROR;
            }
            Print("- R: ';' -> emptyStatement"); 
        }
#line 2841 "parser.tab.c"
    break;

  case 33: /* blockStatement: '{' '}'  */
#line 187 ".\\parser.y"
              { Print("- R: '{' '}' -> blockStatement"); }
#line 2847 "parser.tab.c"
    break;

  case 34: /* blockStatement: '{' statementList '}'  */
#line 188 ".\\parser.y"
                            { Print("- R: '{' statementList '}' -> blockStatement"); }
#line 2853 "parser.tab.c"
    break;

  case 35: /* initializer: '=' singleExpression  */
#line 192 ".\\parser.y"
                           { Print("- R: '=' singleExpression -> initializer"); }
#line 2859 "parser.tab.c"
    break;

  case 36: /* type: unionOrIntersectionOrPrimaryType  */
#line 198 ".\\parser.y"
                                            { Print("- R: unionOrIntersectionOrPrimaryType -> type"); }
#line 2865 "parser.tab.c"
    break;

  case 37: /* type: '|' unionOrIntersectionOrPrimaryType  */
#line 199 ".\\parser.y"
                                            { Print("- R: '|' unionOrIntersectionOrPrimaryType -> type"); }
#line 2871 "parser.tab.c"
    break;

  case 38: /* type: '&' unionOrIntersectionOrPrimaryType  */
#line 200 ".\\parser.y"
                                            { Print("- R: '&' unionOrIntersectionOrPrimaryType -> type"); }
#line 2877 "parser.tab.c"
    break;

  case 39: /* unionOrIntersectionOrPrimaryType: unionOrIntersectionOrPrimaryType '|' unionOrIntersectionOrPrimaryType  */
#line 204 ".\\parser.y"
                                                                            { Print("- R: unionOrIntersectionOrPrimaryType '|' unionOrIntersectionOrPrimaryType -> unionOrIntersectionOrPrimaryType"); }
#line 2883 "parser.tab.c"
    break;

  case 40: /* unionOrIntersectionOrPrimaryType: unionOrIntersectionOrPrimaryType '&' unionOrIntersectionOrPrimaryType  */
#line 205 ".\\parser.y"
                                                                            { Print("- R: unionOrIntersectionOrPrimaryType '&' unionOrIntersectionOrPrimaryType -> unionOrIntersectionOrPrimaryType"); }
#line 2889 "parser.tab.c"
    break;

  case 41: /* unionOrIntersectionOrPrimaryType: primaryType  */
#line 206 ".\\parser.y"
                  { Print("- R: primaryType -> argument"); }
#line 2895 "parser.tab.c"
    break;

  case 42: /* primaryType: '(' type ')'  */
#line 210 ".\\parser.y"
                                                { Print("- R: '(' type ')' -> primaryType"); }
#line 2901 "parser.tab.c"
    break;

  case 43: /* primaryType: predefinedType  */
#line 211 ".\\parser.y"
                                                { Print("- R: predefinedType -> primaryType"); }
#line 2907 "parser.tab.c"
    break;

  case 44: /* primaryType: primaryType '[' ']'  */
#line 212 ".\\parser.y"
                                                { Print("- R: primaryType '[' ']' -> primaryType"); }
#line 2913 "parser.tab.c"
    break;

  case 45: /* primaryType: primaryType '[' primaryType ']'  */
#line 213 ".\\parser.y"
                                                { Print("- R: primaryType '[' primaryType ']' -> primaryType"); }
#line 2919 "parser.tab.c"
    break;

  case 46: /* primaryType: '[' tupleTypeElements ']'  */
#line 214 ".\\parser.y"
                                                { Print("- R: '[' tupleTypeElements ']' -> primaryType"); }
#line 2925 "parser.tab.c"
    break;

  case 47: /* primaryType: ENDL_BRACKET_OPEN tupleTypeElements ']'  */
#line 215 ".\\parser.y"
                                                { Print("- R: '[' tupleTypeElements ']' -> primaryType"); }
#line 2931 "parser.tab.c"
    break;

  case 48: /* tupleTypeElements: %empty  */
#line 219 ".\\parser.y"
                                    { Print("- R: #empty# -> tupleTypeElements"); }
#line 2937 "parser.tab.c"
    break;

  case 49: /* tupleTypeElements: type  */
#line 220 ".\\parser.y"
                                    { Print("- R: type -> tupleTypeElements"); }
#line 2943 "parser.tab.c"
    break;

  case 50: /* tupleTypeElements: tupleTypeElements ',' type  */
#line 221 ".\\parser.y"
                                    { Print("- R: tupleTypeElements ',' type -> tupleTypeElements"); }
#line 2949 "parser.tab.c"
    break;

  case 51: /* predefinedType: ANY  */
#line 225 ".\\parser.y"
                    { Print("- R: ANY -> predefinedType"); }
#line 2955 "parser.tab.c"
    break;

  case 52: /* predefinedType: NUMBER  */
#line 226 ".\\parser.y"
                    { Print("- R: NUMBER -> predefinedType"); }
#line 2961 "parser.tab.c"
    break;

  case 53: /* predefinedType: STRING  */
#line 227 ".\\parser.y"
                    { Print("- R: STRING -> predefinedType"); }
#line 2967 "parser.tab.c"
    break;

  case 54: /* predefinedType: BOOLEAN  */
#line 228 ".\\parser.y"
                    { Print("- R: BOOLEAN -> predefinedType"); }
#line 2973 "parser.tab.c"
    break;

  case 55: /* predefinedType: NEVER  */
#line 229 ".\\parser.y"
                    { Print("- R: NEVER -> predefinedType"); }
#line 2979 "parser.tab.c"
    break;

  case 56: /* predefinedType: UNKNOWN  */
#line 230 ".\\parser.y"
                    { Print("- R: UNKNOWN -> predefinedType"); }
#line 2985 "parser.tab.c"
    break;

  case 57: /* predefinedType: UNDEFINED  */
#line 231 ".\\parser.y"
                    { Print("- R: UNDEFINED -> predefinedType"); }
#line 2991 "parser.tab.c"
    break;

  case 58: /* predefinedType: VOID  */
#line 232 ".\\parser.y"
                    { Print("- R: VOID -> predefinedType"); }
#line 2997 "parser.tab.c"
    break;

  case 59: /* predefinedType: NULL_KW  */
#line 233 ".\\parser.y"
                    { Print("- R: NULL_KW -> predefinedType"); }
#line 3003 "parser.tab.c"
    break;

  case 60: /* predefinedType: TRUE_KW  */
#line 234 ".\\parser.y"
                    { Print("- R: TRUE_WD -> predefinedType"); }
#line 3009 "parser.tab.c"
    break;

  case 61: /* predefinedType: FALSE_KW  */
#line 235 ".\\parser.y"
                    { Print("- R: FALSE_KW -> predefinedType"); }
#line 3015 "parser.tab.c"
    break;

  case 62: /* predefinedType: simpleLiteral  */
#line 236 ".\\parser.y"
                    { Print("- R: simpleLiteral -> predefinedType"); }
#line 3021 "parser.tab.c"
    break;

  case 63: /* typeAnnotation: ':' type  */
#line 240 ".\\parser.y"
               { Print("- R: ':' type -> typeAnnotation"); }
#line 3027 "parser.tab.c"
    break;

  case 64: /* simpleLiteral: STRING_LIT  */
#line 244 ".\\parser.y"
                        { Print("- R: STRING_LIT -> simpleLiteral"); }
#line 3033 "parser.tab.c"
    break;

  case 65: /* simpleLiteral: INT_LIT  */
#line 245 ".\\parser.y"
                        { Print("- R: INT_LIT -> simpleLiteral"); }
#line 3039 "parser.tab.c"
    break;

  case 66: /* simpleLiteral: FLOAT_LIT  */
#line 246 ".\\parser.y"
                        { Print("- R: FLOAT_LIT -> simpleLiteral"); }
#line 3045 "parser.tab.c"
    break;

  case 67: /* simpleLiteral: TEMPLATE_LITERAL  */
#line 247 ".\\parser.y"
                        { Print("- R: TEMPLATE_LITERAL -> simpleLiteral"); }
#line 3051 "parser.tab.c"
    break;

  case 68: /* arrayLiteral: '[' elementList ']'  */
#line 252 ".\\parser.y"
                                        { Print("- R: [ elementList ']' -> arrayLiteral"); }
#line 3057 "parser.tab.c"
    break;

  case 69: /* arrayLiteral: ENDL_BRACKET_OPEN elementList ']'  */
#line 253 ".\\parser.y"
                                        { Print("- R: ENDL_BRACKET_OPEN elementList ']' -> arrayLiteral"); }
#line 3063 "parser.tab.c"
    break;

  case 70: /* elementList: %empty  */
#line 257 ".\\parser.y"
                                    { Print("- R: #empty# -> elementList"); }
#line 3069 "parser.tab.c"
    break;

  case 71: /* elementList: arrayElement  */
#line 258 ".\\parser.y"
                                    { Print("- R: arrayElement -> elementList"); }
#line 3075 "parser.tab.c"
    break;

  case 72: /* elementList: elementList ',' elementList  */
#line 259 ".\\parser.y"
                                    { Print("- R: elementList ',' elementList -> elementList"); }
#line 3081 "parser.tab.c"
    break;

  case 73: /* arrayElement: singleExpression  */
#line 263 ".\\parser.y"
                                { Print("- R: singleExpression -> arrayElement"); }
#line 3087 "parser.tab.c"
    break;

  case 74: /* arrayElement: ELLIPSIS singleExpression  */
#line 264 ".\\parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> arrayElement"); }
#line 3093 "parser.tab.c"
    break;

  case 75: /* expressionStatement: expressionList ';'  */
#line 270 ".\\parser.y"
                         { Print("- R: expressionList ';' -> expressionStatement"); }
#line 3099 "parser.tab.c"
    break;

  case 76: /* expressionListOpt: %empty  */
#line 274 ".\\parser.y"
                        { Print("- R: #empty# -> expressionListOpt"); }
#line 3105 "parser.tab.c"
    break;

  case 77: /* expressionListOpt: expressionList  */
#line 275 ".\\parser.y"
                        { Print("- R: expressionList -> expressionListOpt"); }
#line 3111 "parser.tab.c"
    break;

  case 78: /* expressionList: singleExpression  */
#line 279 ".\\parser.y"
                                            { Print("- R: singleExpression -> expressionList"); }
#line 3117 "parser.tab.c"
    break;

  case 79: /* expressionList: expressionList ',' singleExpression  */
#line 280 ".\\parser.y"
                                            { Print("- R: expressionList ',' singleExpression -> expressionList"); }
#line 3123 "parser.tab.c"
    break;

  case 80: /* singleExpression: identifier  */
#line 284 ".\\parser.y"
                    { Print("- R: identifier -> singleExpression"); }
#line 3129 "parser.tab.c"
    break;

  case 81: /* singleExpression: simpleLiteral  */
#line 285 ".\\parser.y"
                    { Print("- R: simpleLiteral -> singleExpression"); }
#line 3135 "parser.tab.c"
    break;

  case 82: /* singleExpression: THIS  */
#line 286 ".\\parser.y"
                    { Print("- R: THIS -> singleExpression"); }
#line 3141 "parser.tab.c"
    break;

  case 83: /* singleExpression: SUPER  */
#line 287 ".\\parser.y"
                    { Print("- R: SUPER -> singleExpression"); }
#line 3147 "parser.tab.c"
    break;

  case 84: /* singleExpression: TRUE_KW  */
#line 288 ".\\parser.y"
                    { Print("- R: TRUE_LITERAL -> singleExpression"); }
#line 3153 "parser.tab.c"
    break;

  case 85: /* singleExpression: FALSE_KW  */
#line 289 ".\\parser.y"
                    { Print("- R: FALSE_LITERAL -> singleExpression"); }
#line 3159 "parser.tab.c"
    break;

  case 86: /* singleExpression: NULL_KW  */
#line 290 ".\\parser.y"
                    { Print("- R: NULL_LITERAL -> singleExpression"); }
#line 3165 "parser.tab.c"
    break;

  case 87: /* singleExpression: '-' singleExpression  */
#line 292 ".\\parser.y"
                                        { Print("- R: '-' singleExpression -> singleExpression"); }
#line 3171 "parser.tab.c"
    break;

  case 88: /* singleExpression: '+' singleExpression  */
#line 293 ".\\parser.y"
                                        { Print("- R: '+' singleExpression -> singleExpression"); }
#line 3177 "parser.tab.c"
    break;

  case 89: /* singleExpression: '!' singleExpression  */
#line 295 ".\\parser.y"
                           { Print("- R: '!' singleExpression -> singleExpression"); }
#line 3183 "parser.tab.c"
    break;

  case 90: /* singleExpression: '~' singleExpression  */
#line 296 ".\\parser.y"
                           { Print("- R: '~' singleExpression -> singleExpression"); }
#line 3189 "parser.tab.c"
    break;

  case 91: /* singleExpression: singleExpression OPERATOR_INCREMENT  */
#line 298 ".\\parser.y"
                                                               { Print("- R: singleExpression OPERATOR_INCREMENT -> singleExpression"); }
#line 3195 "parser.tab.c"
    break;

  case 92: /* singleExpression: singleExpression OPERATOR_DECREMENT  */
#line 299 ".\\parser.y"
                                                               { Print("- R: singleExpression OPERATOR_DECREMENT -> singleExpression"); }
#line 3201 "parser.tab.c"
    break;

  case 93: /* singleExpression: ENDL_OPERATOR_INCREMENT singleExpression  */
#line 301 ".\\parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 3207 "parser.tab.c"
    break;

  case 94: /* singleExpression: ENDL_OPERATOR_DECREMENT singleExpression  */
#line 302 ".\\parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 3213 "parser.tab.c"
    break;

  case 95: /* singleExpression: OPERATOR_INCREMENT singleExpression  */
#line 303 ".\\parser.y"
                                                               { Print("- R: OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 3219 "parser.tab.c"
    break;

  case 96: /* singleExpression: OPERATOR_DECREMENT singleExpression  */
#line 304 ".\\parser.y"
                                                               { Print("- R: OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 3225 "parser.tab.c"
    break;

  case 97: /* singleExpression: singleExpression '+' singleExpression  */
#line 306 ".\\parser.y"
                                            { Print("- R: singleExpression '+' singleExpression -> singleExpression"); }
#line 3231 "parser.tab.c"
    break;

  case 98: /* singleExpression: singleExpression '-' singleExpression  */
#line 307 ".\\parser.y"
                                            { Print("- R: singleExpression '-' singleExpression -> singleExpression"); }
#line 3237 "parser.tab.c"
    break;

  case 99: /* singleExpression: singleExpression '*' singleExpression  */
#line 308 ".\\parser.y"
                                            { Print("- R: singleExpression '*' singleExpression -> singleExpression"); }
#line 3243 "parser.tab.c"
    break;

  case 100: /* singleExpression: singleExpression '/' singleExpression  */
#line 309 ".\\parser.y"
                                            { Print("- R: singleExpression '/' singleExpression -> singleExpression"); }
#line 3249 "parser.tab.c"
    break;

  case 101: /* singleExpression: singleExpression '%' singleExpression  */
#line 310 ".\\parser.y"
                                            { Print("- R: singleExpression '%' singleExpression -> singleExpression"); }
#line 3255 "parser.tab.c"
    break;

  case 102: /* singleExpression: singleExpression '<' singleExpression  */
#line 311 ".\\parser.y"
                                            { Print("- R: singleExpression '<' singleExpression -> singleExpression"); }
#line 3261 "parser.tab.c"
    break;

  case 103: /* singleExpression: singleExpression '>' singleExpression  */
#line 312 ".\\parser.y"
                                            { Print("- R: singleExpression '>' singleExpression -> singleExpression"); }
#line 3267 "parser.tab.c"
    break;

  case 104: /* singleExpression: singleExpression OPERATOR_POWER singleExpression  */
#line 315 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_POWER singleExpression -> singleExpression"); }
#line 3273 "parser.tab.c"
    break;

  case 105: /* singleExpression: singleExpression OPERATOR_EQUAL singleExpression  */
#line 318 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_EQUAL singleExpression -> singleExpression"); }
#line 3279 "parser.tab.c"
    break;

  case 106: /* singleExpression: singleExpression OPERATOR_NOT_EQUAL singleExpression  */
#line 321 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_NOT_EQUAL singleExpression -> singleExpression"); }
#line 3285 "parser.tab.c"
    break;

  case 107: /* singleExpression: singleExpression OPERATOR_STRICT_EQUAL singleExpression  */
#line 324 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_STRICT_EQUAL singleExpression -> singleExpression"); }
#line 3291 "parser.tab.c"
    break;

  case 108: /* singleExpression: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression  */
#line 327 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression -> singleExpression"); }
#line 3297 "parser.tab.c"
    break;

  case 109: /* singleExpression: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression  */
#line 330 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression -> singleExpression"); }
#line 3303 "parser.tab.c"
    break;

  case 110: /* singleExpression: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression  */
#line 333 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression -> singleExpression"); }
#line 3309 "parser.tab.c"
    break;

  case 111: /* singleExpression: singleExpression '=' singleExpression  */
#line 336 ".\\parser.y"
        { Print("- R: singleExpression '=' singleExpression -> singleExpression"); }
#line 3315 "parser.tab.c"
    break;

  case 112: /* singleExpression: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression  */
#line 339 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression -> singleExpression"); }
#line 3321 "parser.tab.c"
    break;

  case 113: /* singleExpression: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression  */
#line 342 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression -> singleExpression"); }
#line 3327 "parser.tab.c"
    break;

  case 114: /* singleExpression: singleExpression OPERATOR_ASSIGN_MOD singleExpression  */
#line 345 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_MOD singleExpression -> singleExpression"); }
#line 3333 "parser.tab.c"
    break;

  case 115: /* singleExpression: singleExpression OPERATOR_ASSIGN_PLUS singleExpression  */
#line 348 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_PLUS singleExpression -> singleExpression"); }
#line 3339 "parser.tab.c"
    break;

  case 116: /* singleExpression: singleExpression OPERATOR_ASSIGN_MINUS singleExpression  */
#line 351 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_MINUS singleExpression -> singleExpression"); }
#line 3345 "parser.tab.c"
    break;

  case 117: /* singleExpression: singleExpression OPERATOR_ASSIGN_SHIFT_LEFT singleExpression  */
#line 354 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_SHIFT_LEFT singleExpression -> singleExpression"); }
#line 3351 "parser.tab.c"
    break;

  case 118: /* singleExpression: singleExpression OPERATOR_ASSIGN_SHIFT_RIGHT singleExpression  */
#line 357 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3357 "parser.tab.c"
    break;

  case 119: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_AND singleExpression  */
#line 360 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_AND singleExpression -> singleExpression"); }
#line 3363 "parser.tab.c"
    break;

  case 120: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_XOR singleExpression  */
#line 363 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_XOR singleExpression -> singleExpression"); }
#line 3369 "parser.tab.c"
    break;

  case 121: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_OR singleExpression  */
#line 366 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_OR singleExpression -> singleExpression"); }
#line 3375 "parser.tab.c"
    break;

  case 122: /* singleExpression: singleExpression OPERATOR_ASSIGN_POWER singleExpression  */
#line 369 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_POWER singleExpression -> singleExpression"); }
#line 3381 "parser.tab.c"
    break;

  case 123: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression  */
#line 372 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression -> singleExpression"); }
#line 3387 "parser.tab.c"
    break;

  case 124: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression  */
#line 375 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression -> singleExpression"); }
#line 3393 "parser.tab.c"
    break;

  case 125: /* singleExpression: singleExpression OPERATOR_ASSIGN_NULLISH_COALESCING singleExpression  */
#line 378 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_NULLISH_COALESCING singleExpression -> singleExpression"); }
#line 3399 "parser.tab.c"
    break;

  case 126: /* singleExpression: singleExpression OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT singleExpression  */
#line 381 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3405 "parser.tab.c"
    break;

  case 127: /* singleExpression: singleExpression OPERATOR_LOGICAL_OR singleExpression  */
#line 384 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_LOGICAL_OR singleExpression -> singleExpression"); }
#line 3411 "parser.tab.c"
    break;

  case 128: /* singleExpression: singleExpression OPERATOR_LOGICAL_AND singleExpression  */
#line 387 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_LOGICAL_AND singleExpression -> singleExpression"); }
#line 3417 "parser.tab.c"
    break;

  case 129: /* singleExpression: singleExpression '|' singleExpression  */
#line 390 ".\\parser.y"
        { Print("- R: singleExpression '|' singleExpression -> singleExpression"); }
#line 3423 "parser.tab.c"
    break;

  case 130: /* singleExpression: singleExpression '^' singleExpression  */
#line 393 ".\\parser.y"
        { Print("- R: singleExpression '^' singleExpression -> singleExpression"); }
#line 3429 "parser.tab.c"
    break;

  case 131: /* singleExpression: singleExpression '&' singleExpression  */
#line 396 ".\\parser.y"
        { Print("- R: singleExpression '&' singleExpression -> singleExpression"); }
#line 3435 "parser.tab.c"
    break;

  case 132: /* singleExpression: singleExpression OPERATOR_SHIFT_LEFT singleExpression  */
#line 399 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_SHIFT_LEFT singleExpression -> singleExpression"); }
#line 3441 "parser.tab.c"
    break;

  case 133: /* singleExpression: singleExpression OPERATOR_SHIFT_RIGHT singleExpression  */
#line 402 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3447 "parser.tab.c"
    break;

  case 134: /* singleExpression: singleExpression OPERATOR_UNSIGNED_SHIFT_RIGHT singleExpression  */
#line 405 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_UNSIGNED_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3453 "parser.tab.c"
    break;

  case 135: /* singleExpression: singleExpression OPERATOR_NULLISH_COALESCING singleExpression  */
#line 408 ".\\parser.y"
        { Print("- R: singleExpression OPERATOR_NULLISH_COALESCING singleExpression -> singleExpression"); }
#line 3459 "parser.tab.c"
    break;

  case 136: /* singleExpression: singleExpression INSTANCEOF singleExpression  */
#line 410 ".\\parser.y"
                                                    { Print("- R: singleExpression INSTANCEOF singleExpression -> singleExpression"); }
#line 3465 "parser.tab.c"
    break;

  case 137: /* singleExpression: singleExpression IN singleExpression  */
#line 411 ".\\parser.y"
                                                    { Print("- R: singleExpression IN singleExpression -> singleExpression"); }
#line 3471 "parser.tab.c"
    break;

  case 138: /* singleExpression: singleExpression TEMPLATE_LITERAL  */
#line 414 ".\\parser.y"
        { Print("- R: singleExpression TEMPLATE_LITERAL -> singleExpression"); }
#line 3477 "parser.tab.c"
    break;

  case 139: /* singleExpression: singleExpression '?' singleExpression ':' singleExpression  */
#line 416 ".\\parser.y"
                                                                 {
         Print("- R: singleExpression '?' singleExpression ':' singleExpression -> singleExpression"); }
#line 3484 "parser.tab.c"
    break;

  case 140: /* singleExpression: '(' expressionList ')'  */
#line 419 ".\\parser.y"
                             { Print("- R: '(' expressionList ')' -> singleExpression"); }
#line 3490 "parser.tab.c"
    break;

  case 141: /* singleExpression: singleExpression arguments  */
#line 421 ".\\parser.y"
                                 { Print("- R: singleExpression arguments -> singleExpression"); }
#line 3496 "parser.tab.c"
    break;

  case 142: /* singleExpression: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression  */
#line 424 ".\\parser.y"
        { Print("- R: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression -> singleExpression"); }
#line 3502 "parser.tab.c"
    break;

  case 143: /* singleExpression: singleExpression '.' identifier  */
#line 426 ".\\parser.y"
                                      { Print("- R: singleExpression '.' identifier -> singleExpression"); }
#line 3508 "parser.tab.c"
    break;

  case 144: /* singleExpression: arrayLiteral  */
#line 428 ".\\parser.y"
                                                            { Print("- R: arrayLiteral -> singleExpression"); }
#line 3514 "parser.tab.c"
    break;

  case 145: /* singleExpression: singleExpression '[' expressionList ']'  */
#line 429 ".\\parser.y"
                                                            { Print("- R: singleExpression '[' expressionList ']' -> singleExpression"); }
#line 3520 "parser.tab.c"
    break;

  case 146: /* singleExpression: singleExpression ENDL_BRACKET_OPEN expressionList ']'  */
#line 430 ".\\parser.y"
                                                            { Print("- R: singleExpression ENDL_BRACKET_OPEN expressionList ']' -> singleExpression"); }
#line 3526 "parser.tab.c"
    break;

  case 147: /* singleExpression: NEW singleExpression  */
#line 432 ".\\parser.y"
                           { Print("- R: NEW singleExpression -> singleExpression"); }
#line 3532 "parser.tab.c"
    break;

  case 148: /* arguments: '(' ')'  */
#line 436 ".\\parser.y"
                                { Print("- R: '(' ')' -> arguments"); }
#line 3538 "parser.tab.c"
    break;

  case 149: /* arguments: '(' argumentList ')'  */
#line 437 ".\\parser.y"
                                { Print("- R: '(' argumentList ')' -> arguments"); }
#line 3544 "parser.tab.c"
    break;

  case 150: /* arguments: '(' argumentList ',' ')'  */
#line 438 ".\\parser.y"
                                { Print("- R: '(' argumentList ',' ') -> arguments"); }
#line 3550 "parser.tab.c"
    break;

  case 151: /* argumentList: argument  */
#line 442 ".\\parser.y"
                                    { Print("- R: argument -> argumentList"); }
#line 3556 "parser.tab.c"
    break;

  case 152: /* argumentList: argumentList ',' arguments  */
#line 443 ".\\parser.y"
                                    { Print("- R: argumentList ',' arguments -> argumentList"); }
#line 3562 "parser.tab.c"
    break;

  case 153: /* argument: singleExpression  */
#line 447 ".\\parser.y"
                                { Print("- R: singleExpression -> argument"); }
#line 3568 "parser.tab.c"
    break;

  case 154: /* argument: ELLIPSIS singleExpression  */
#line 448 ".\\parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> argument"); }
#line 3574 "parser.tab.c"
    break;

  case 155: /* varStatement: varModifier varDeclarationList ';'  */
#line 454 ".\\parser.y"
                                         { Print("- R: varModifier varDeclarationList ';' -> varStatement"); }
#line 3580 "parser.tab.c"
    break;

  case 157: /* varDeclarationList: varDeclaration  */
#line 459 ".\\parser.y"
                                            { Print("- R: varDeclaration -> varDeclarationList"); }
#line 3586 "parser.tab.c"
    break;

  case 158: /* varDeclarationList: varDeclarationList ',' varDeclaration  */
#line 460 ".\\parser.y"
                                            { Print("- R: varDeclarationList ',' varDeclaration -> varDeclarationList"); }
#line 3592 "parser.tab.c"
    break;

  case 159: /* varDeclaration: identifier  */
#line 464 ".\\parser.y"
                                                        { Print("- R: identifier -> varDeclaration"); }
#line 3598 "parser.tab.c"
    break;

  case 160: /* varDeclaration: identifier typeAnnotation  */
#line 465 ".\\parser.y"
                                                        { Print("- R: identifier typeAnnotation -> varDeclaration"); }
#line 3604 "parser.tab.c"
    break;

  case 161: /* varDeclaration: identifier '=' singleExpression  */
#line 466 ".\\parser.y"
                                                        { Print("- R: identifier '=' singleExpression -> varDeclaration"); }
#line 3610 "parser.tab.c"
    break;

  case 162: /* varDeclaration: identifier typeAnnotation '=' singleExpression  */
#line 467 ".\\parser.y"
                                                        { Print("- R: identifier typeAnnotation '=' singleExpression -> varDeclaration"); }
#line 3616 "parser.tab.c"
    break;

  case 163: /* varModifier: VAR  */
#line 471 ".\\parser.y"
            { Print("- R: VAR -> varModifier"); }
#line 3622 "parser.tab.c"
    break;

  case 164: /* varModifier: LET  */
#line 472 ".\\parser.y"
            { Print("- R: LET -> varModifier"); }
#line 3628 "parser.tab.c"
    break;

  case 165: /* varModifier: CONST  */
#line 473 ".\\parser.y"
            { Print("- R: CONST -> varModifier"); }
#line 3634 "parser.tab.c"
    break;

  case 166: /* ifStatement: IF '(' expressionList ')' statementListItemWithoutEmptyStatement  */
#line 480 ".\\parser.y"
        { Print("- R: IF '(' expressionList ')' statementListItem -> ifStatement"); }
#line 3640 "parser.tab.c"
    break;

  case 167: /* ifStatement: IF '(' expressionList ')' statementListItemWithoutEmptyStatement ELSE statementListItem  */
#line 483 ".\\parser.y"
        { Print("- R: IF '(' expressionList ')' statementListItem ELSE statementListItem -> ifStatement"); }
#line 3646 "parser.tab.c"
    break;

  case 168: /* switchStatement: SWITCH '(' expressionList ')' '{' '}'  */
#line 488 ".\\parser.y"
        { Print("- R: SWITCH '(' expressionList ')' '{' '}' -> switchStatement"); }
#line 3652 "parser.tab.c"
    break;

  case 169: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList '}'  */
#line 491 ".\\parser.y"
        { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList '}' -> switchStatement"); }
#line 3658 "parser.tab.c"
    break;

  case 170: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause '}'  */
#line 494 ".\\parser.y"
        { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause '}' -> switchStatement"); }
#line 3664 "parser.tab.c"
    break;

  case 171: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause caseClauseList '}'  */
#line 497 ".\\parser.y"
        { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause caseClauseList '}' -> switchStatement"); }
#line 3670 "parser.tab.c"
    break;

  case 172: /* caseClauseList: caseClause  */
#line 501 ".\\parser.y"
                                { Print("- R: caseClause -> caseClauseList"); }
#line 3676 "parser.tab.c"
    break;

  case 173: /* caseClauseList: caseClauseList caseClause  */
#line 502 ".\\parser.y"
                                { Print("- R: caseClauseList caseClause -> caseClauseList"); }
#line 3682 "parser.tab.c"
    break;

  case 174: /* caseClause: CASE expressionList ':'  */
#line 506 ".\\parser.y"
                                            { Print("- R: CASE expressionList ':' -> caseClause"); }
#line 3688 "parser.tab.c"
    break;

  case 175: /* caseClause: CASE expressionList ':' statementList  */
#line 507 ".\\parser.y"
                                            { Print("- R: CASE expressionList ':' statementList -> caseClause"); }
#line 3694 "parser.tab.c"
    break;

  case 176: /* defaultClause: DEFAULT ':'  */
#line 511 ".\\parser.y"
                                { Print("- R: DEFAULT ':' -> defaultClause"); }
#line 3700 "parser.tab.c"
    break;

  case 177: /* defaultClause: DEFAULT ':' statementList  */
#line 512 ".\\parser.y"
                                { Print("- R: DEFAULT ':' statementList -> defaultClause"); }
#line 3706 "parser.tab.c"
    break;

  case 178: /* $@1: %empty  */
#line 518 ".\\parser.y"
         { isInIterationBody = 1; }
#line 3712 "parser.tab.c"
    break;

  case 179: /* $@2: %empty  */
#line 518 ".\\parser.y"
                                                                                   { doWhileASI(); }
#line 3718 "parser.tab.c"
    break;

  case 180: /* iterationStatement: DO $@1 statementListItem WHILE '(' expressionList ')' $@2 ';'  */
#line 519 ".\\parser.y"
        { isInIterationBody = 0; Print("- R: DO statementListItem WHILE '(' expressionList ')' ';' -> iterationStatement"); }
#line 3724 "parser.tab.c"
    break;

  case 181: /* $@3: %empty  */
#line 521 ".\\parser.y"
                                   { isInIterationBody = 1; }
#line 3730 "parser.tab.c"
    break;

  case 182: /* iterationStatement: WHILE '(' expressionList ')' $@3 statementListItem  */
#line 522 ".\\parser.y"
        { isInIterationBody = 0; Print("- R: WHILE '(' expressionList ')' statementListItem -> iterationStatement"); }
#line 3736 "parser.tab.c"
    break;

  case 183: /* $@4: %empty  */
#line 524 ".\\parser.y"
                                                                                  { isInForHeader = 0; isInIterationBody = 1; }
#line 3742 "parser.tab.c"
    break;

  case 184: /* iterationStatement: forHeader expressionListOpt ';' expressionListOpt ';' expressionListOpt ')' $@4 statementListItem  */
#line 525 ".\\parser.y"
        { isInIterationBody = 0; Print("- R: FOR '(' expressionListOpt ';' expressionListOpt ';' expressionListOpt ')' statementListItem -> iterationStatement"); }
#line 3748 "parser.tab.c"
    break;

  case 185: /* $@5: %empty  */
#line 527 ".\\parser.y"
                                                                                               { isInForHeader = 0; isInIterationBody = 1; }
#line 3754 "parser.tab.c"
    break;

  case 186: /* iterationStatement: forHeader varModifier varDeclarationList ';' expressionListOpt ';' expressionListOpt ')' $@5 statementListItem  */
#line 528 ".\\parser.y"
        { isInIterationBody = 0; Print("- R: FOR '(' varModifier varDeclarationList ';' expressionListOpt ';' expressionListOpt ')' statementListItem -> iterationStatement"); }
#line 3760 "parser.tab.c"
    break;

  case 187: /* $@6: %empty  */
#line 530 ".\\parser.y"
                                                         { isInForHeader = 0; isInIterationBody = 1; }
#line 3766 "parser.tab.c"
    break;

  case 188: /* iterationStatement: forHeader singleExpression IN singleExpression ')' $@6 statementListItem  */
#line 531 ".\\parser.y"
        { isInIterationBody = 0; Print("- R: FOR '(' singleExpression IN singleExpression ')' statementListItem -> iterationStatement"); }
#line 3772 "parser.tab.c"
    break;

  case 189: /* $@7: %empty  */
#line 533 ".\\parser.y"
                                                                 { isInForHeader = 0; isInIterationBody = 1; }
#line 3778 "parser.tab.c"
    break;

  case 190: /* iterationStatement: forHeader varModifier varDeclaration IN expressionList ')' $@7 statementListItem  */
#line 534 ".\\parser.y"
        { isInIterationBody = 0; Print("- R: FOR '(' varModifier varDeclaration IN expressionList ')' statementListItem -> iterationStatement"); }
#line 3784 "parser.tab.c"
    break;

  case 191: /* forHeader: FOR '('  */
#line 538 ".\\parser.y"
               { isInForHeader = 1; }
#line 3790 "parser.tab.c"
    break;

  case 192: /* continueStatement: CONTINUE ';'  */
#line 542 ".\\parser.y"
                                { Print("- R: CONTINUE ';' -> returnStatement"); }
#line 3796 "parser.tab.c"
    break;

  case 193: /* continueStatement: CONTINUE identifier ';'  */
#line 543 ".\\parser.y"
                                { Print("- R: CONTINUE identifier ';' -> returnStatement"); }
#line 3802 "parser.tab.c"
    break;

  case 194: /* breakStatement: BREAK ';'  */
#line 547 ".\\parser.y"
                                { Print("- R: BREAK ';' -> returnStatement"); }
#line 3808 "parser.tab.c"
    break;

  case 195: /* breakStatement: BREAK identifier ';'  */
#line 548 ".\\parser.y"
                                { Print("- R: BREAK identifier ';' -> returnStatement"); }
#line 3814 "parser.tab.c"
    break;

  case 196: /* labelledStatement: identifier ':' statementListItem  */
#line 552 ".\\parser.y"
                                       { Print("- R: identifier ':' statementListItem -> labelledStatement"); }
#line 3820 "parser.tab.c"
    break;

  case 197: /* returnStatement: RETURN ';'  */
#line 558 ".\\parser.y"
                                    { Print("- R: RETURN ';' -> returnStatement"); }
#line 3826 "parser.tab.c"
    break;

  case 198: /* returnStatement: RETURN singleExpression ';'  */
#line 559 ".\\parser.y"
                                    { Print("- R: RETURN singleExpression ';' -> returnStatement"); }
#line 3832 "parser.tab.c"
    break;

  case 199: /* functionDeclaration: FUNCTION identifier callSignature functionBody  */
#line 564 ".\\parser.y"
                                                     { Print("- R: FUNCTION ID callSignature functionBody -> functionDeclaration"); }
#line 3838 "parser.tab.c"
    break;

  case 200: /* functionBody: '{' '}'  */
#line 568 ".\\parser.y"
                                                        { Print("- R: '{' '}' -> functionBody"); }
#line 3844 "parser.tab.c"
    break;

  case 201: /* $@8: %empty  */
#line 569 ".\\parser.y"
          { isInFunctionBody = 1; }
#line 3850 "parser.tab.c"
    break;

  case 202: /* functionBody: '{' $@8 statementList '}'  */
#line 569 ".\\parser.y"
                                                        { isInFunctionBody = 0; Print("- R: '{' statementList '}' -> functionBody"); }
#line 3856 "parser.tab.c"
    break;

  case 203: /* callSignature: '(' parameterList ')'  */
#line 573 ".\\parser.y"
                                            { Print("- R: '(' parameterList ')' -> callSignature"); }
#line 3862 "parser.tab.c"
    break;

  case 204: /* callSignature: '(' parameterList ')' typeAnnotation  */
#line 574 ".\\parser.y"
                                            { Print("- R: '(' parameterList ')' typeAnnotation -> callSignature"); }
#line 3868 "parser.tab.c"
    break;

  case 205: /* parameterList: %empty  */
#line 578 ".\\parser.y"
                            { Print("- R: #empty# -> parameterList"); }
#line 3874 "parser.tab.c"
    break;

  case 206: /* parameterList: requiredParameterList  */
#line 579 ".\\parser.y"
                            { Print("- R: requiredParameterList -> parameterList"); }
#line 3880 "parser.tab.c"
    break;

  case 207: /* parameterList: optionalParameterList  */
#line 580 ".\\parser.y"
                            { Print("- R: optionalParameterList -> parameterList"); }
#line 3886 "parser.tab.c"
    break;

  case 208: /* parameterList: restParameter  */
#line 581 ".\\parser.y"
                            { Print("- R: restParameter -> parameterList"); }
#line 3892 "parser.tab.c"
    break;

  case 209: /* parameterList: requiredParameterList ',' optionalParameterList  */
#line 583 ".\\parser.y"
                                                        { Print("- R: requiredParameterList ',' optionalParameterList -> parameterList"); }
#line 3898 "parser.tab.c"
    break;

  case 210: /* parameterList: requiredParameterList ',' restParameter  */
#line 584 ".\\parser.y"
                                                        { Print("- R: requiredParameterList ',' restParameter -> parameterList"); }
#line 3904 "parser.tab.c"
    break;

  case 211: /* parameterList: optionalParameterList ',' restParameter  */
#line 585 ".\\parser.y"
                                                        { Print("- R: optionalParameterList ',' restParameter -> parameterList"); }
#line 3910 "parser.tab.c"
    break;

  case 212: /* parameterList: requiredParameterList ',' optionalParameterList ',' restParameter  */
#line 587 ".\\parser.y"
                                                                        { Print("- R: requiredParameterList ',' optionalParameterList ',' restParameter -> parameterList"); }
#line 3916 "parser.tab.c"
    break;

  case 213: /* parameterList: requiredParameterList ','  */
#line 589 ".\\parser.y"
                                { Print("- R: requiredParameterList ',' -> parameterList"); }
#line 3922 "parser.tab.c"
    break;

  case 214: /* parameterList: optionalParameterList ','  */
#line 590 ".\\parser.y"
                                { Print("- R: optionalParameterList ',' -> parameterList"); }
#line 3928 "parser.tab.c"
    break;

  case 215: /* parameterList: restParameter ','  */
#line 591 ".\\parser.y"
                                { Print("- R: restParameter ',' -> parameterList"); }
#line 3934 "parser.tab.c"
    break;

  case 216: /* parameterList: requiredParameterList ',' optionalParameterList ','  */
#line 593 ".\\parser.y"
                                                            { Print("- R: requiredParameterList ',' optionalParameterList ',' -> parameterList"); }
#line 3940 "parser.tab.c"
    break;

  case 217: /* parameterList: requiredParameterList ',' restParameter ','  */
#line 594 ".\\parser.y"
                                                            { Print("- R: requiredParameterList ',' restParameter ',' -> parameterList"); }
#line 3946 "parser.tab.c"
    break;

  case 218: /* parameterList: optionalParameterList ',' restParameter ','  */
#line 595 ".\\parser.y"
                                                            { Print("- R: optionalParameterList ',' restParameter ',' -> parameterList"); }
#line 3952 "parser.tab.c"
    break;

  case 219: /* parameterList: requiredParameterList ',' optionalParameterList ',' restParameter ','  */
#line 597 ".\\parser.y"
                                                                            { Print("- R: requiredParameterList ',' optionalParameterList ',' restParameter ',' -> parameterList"); }
#line 3958 "parser.tab.c"
    break;

  case 220: /* requiredParameterList: requiredParameter  */
#line 601 ".\\parser.y"
                                                    { Print("- R: requiredParameter -> requiredParameterList"); }
#line 3964 "parser.tab.c"
    break;

  case 221: /* requiredParameterList: requiredParameterList ',' requiredParameter  */
#line 602 ".\\parser.y"
                                                    { Print("- R: requiredParameterList ',' requiredParameter -> requiredParameterList"); }
#line 3970 "parser.tab.c"
    break;

  case 222: /* optionalParameterList: optionalParameter  */
#line 606 ".\\parser.y"
                                                    { Print("- R: optionalParameter -> optionalParameterList"); }
#line 3976 "parser.tab.c"
    break;

  case 223: /* optionalParameterList: optionalParameterList ',' optionalParameter  */
#line 607 ".\\parser.y"
                                                    { Print("- R: optionalParameterList ',' optionalParameter -> optionalParameterList"); }
#line 3982 "parser.tab.c"
    break;

  case 224: /* requiredParameter: identifier  */
#line 611 ".\\parser.y"
                                { Print("- R: ID -> requiredParameter"); }
#line 3988 "parser.tab.c"
    break;

  case 225: /* requiredParameter: identifier typeAnnotation  */
#line 612 ".\\parser.y"
                                { Print("- R: ID typeAnnotation -> requiredParameter"); }
#line 3994 "parser.tab.c"
    break;

  case 226: /* optionalParameter: identifier '?'  */
#line 616 ".\\parser.y"
                                            { Print("- R: ID '?' -> optionalParameter"); }
#line 4000 "parser.tab.c"
    break;

  case 227: /* optionalParameter: identifier '?' typeAnnotation  */
#line 617 ".\\parser.y"
                                            { Print("- R: ID '?' typeAnnotation -> optionalParameter"); }
#line 4006 "parser.tab.c"
    break;

  case 228: /* optionalParameter: identifier initializer  */
#line 618 ".\\parser.y"
                                            { Print("- R: ID initializer -> optionalParameter"); }
#line 4012 "parser.tab.c"
    break;

  case 229: /* optionalParameter: identifier typeAnnotation initializer  */
#line 619 ".\\parser.y"
                                            { Print("- R: ID typeAnnotation initializer -> optionalParameter"); }
#line 4018 "parser.tab.c"
    break;

  case 230: /* restParameter: ELLIPSIS singleExpression  */
#line 623 ".\\parser.y"
                                                { Print("- R: ELLIPSIS singleExpression -> restParameter"); }
#line 4024 "parser.tab.c"
    break;

  case 231: /* restParameter: ELLIPSIS singleExpression typeAnnotation  */
#line 624 ".\\parser.y"
                                                { Print("- R: ELLIPSIS singleExpression typeAnnotation -> restParameter"); }
#line 4030 "parser.tab.c"
    break;

  case 232: /* classDeclaration: CLASS identifier classTail  */
#line 630 ".\\parser.y"
                                                { Print("- R: CLASS identifier classTail -> classDeclaration"); }
#line 4036 "parser.tab.c"
    break;

  case 233: /* classDeclaration: CLASS identifier classHeritage classTail  */
#line 631 ".\\parser.y"
                                                { Print("- R: CLASS identifier classHeritage classTail -> classDeclaration"); }
#line 4042 "parser.tab.c"
    break;

  case 234: /* classHeritage: EXTENDS identifier  */
#line 635 ".\\parser.y"
                         { Print("- R: EXTENDS identifier -> classHeritage"); }
#line 4048 "parser.tab.c"
    break;

  case 235: /* classTail: '{' '}'  */
#line 639 ".\\parser.y"
                                { Print("- R: '{' '}' -> classTail"); }
#line 4054 "parser.tab.c"
    break;

  case 236: /* classTail: '{' classElementList '}'  */
#line 640 ".\\parser.y"
                                { Print("- R: '{' classElementList '}' -> classTail"); }
#line 4060 "parser.tab.c"
    break;

  case 237: /* classElementList: classElement  */
#line 644 ".\\parser.y"
                   { Print("- R: classElement -> classElementList"); }
#line 4066 "parser.tab.c"
    break;

  case 238: /* classElementList: classElementList classElement  */
#line 645 ".\\parser.y"
                                    { Print("- R: classElementList classElement -> classElementList"); }
#line 4072 "parser.tab.c"
    break;

  case 239: /* classElement: CONSTRUCTOR constructorCallSignature functionBody  */
#line 649 ".\\parser.y"
                                                        { Print("- R: CONSTRUCTOR callSignature functionBody -> classElement"); }
#line 4078 "parser.tab.c"
    break;

  case 240: /* classElement: propertyName ';'  */
#line 652 ".\\parser.y"
                                                    { Print("- R: propertyName ';' -> classElement"); }
#line 4084 "parser.tab.c"
    break;

  case 241: /* classElement: propertyName typeAnnotation ';'  */
#line 653 ".\\parser.y"
                                                    { Print("- R: propertyName typeAnnotation ';' -> classElement"); }
#line 4090 "parser.tab.c"
    break;

  case 242: /* classElement: propertyName initializer ';'  */
#line 654 ".\\parser.y"
                                                    { Print("- R: propertyName initializer ';' -> classElement"); }
#line 4096 "parser.tab.c"
    break;

  case 243: /* classElement: propertyName typeAnnotation initializer ';'  */
#line 655 ".\\parser.y"
                                                    { Print("- R: propertyName typeAnnotation initializer ';' -> classElement"); }
#line 4102 "parser.tab.c"
    break;

  case 244: /* classElement: propertyName callSignature functionBody  */
#line 658 ".\\parser.y"
                                              { Print("- R: propertyName callSignature functionBody -> classElement"); }
#line 4108 "parser.tab.c"
    break;

  case 245: /* classElement: GET propertyName '(' ')' functionBody  */
#line 661 ".\\parser.y"
                                                            { Print("- R: GET propertyName '(' ')' functionBody -> classElement"); }
#line 4114 "parser.tab.c"
    break;

  case 246: /* classElement: GET propertyName '(' ')' typeAnnotation functionBody  */
#line 662 ".\\parser.y"
                                                            { Print("- R: GET propertyName '(' ')' typeAnnotation functionBody -> classElement"); }
#line 4120 "parser.tab.c"
    break;

  case 247: /* classElement: SET propertyName callSignature functionBody  */
#line 663 ".\\parser.y"
                                                            { Print("- R: SET propertyName callSignature functionBody -> classElement"); }
#line 4126 "parser.tab.c"
    break;

  case 248: /* constructorCallSignature: '(' parameterList ')'  */
#line 667 ".\\parser.y"
                            { Print("- R: '(' parameterList ')' -> constructorCallSignature"); }
#line 4132 "parser.tab.c"
    break;

  case 249: /* propertyName: identifier  */
#line 671 ".\\parser.y"
                                            { Print("- R: identifier -> propertyName"); }
#line 4138 "parser.tab.c"
    break;

  case 250: /* propertyName: simpleLiteral  */
#line 672 ".\\parser.y"
                                            { Print("- R: STRING_LIT -> propertyName"); }
#line 4144 "parser.tab.c"
    break;

  case 251: /* propertyName: '[' simpleLiteral ']'  */
#line 673 ".\\parser.y"
                                            { Print("- R: '[' simpleLiteral ']' -> propertyName"); }
#line 4150 "parser.tab.c"
    break;

  case 252: /* propertyName: ENDL_BRACKET_OPEN simpleLiteral ']'  */
#line 674 ".\\parser.y"
                                            { Print("- R: ENDL_BRACKET_OPEN simpleLiteral ']' -> propertyName"); }
#line 4156 "parser.tab.c"
    break;

  case 253: /* identifier: ID  */
#line 678 ".\\parser.y"
                { Print("- R: ID -> identifier"); }
#line 4162 "parser.tab.c"
    break;

  case 254: /* identifier: ASYNC  */
#line 679 ".\\parser.y"
                { Print("- R: ASYNC -> identifier"); }
#line 4168 "parser.tab.c"
    break;

  case 255: /* identifier: AS  */
#line 680 ".\\parser.y"
                { Print("- R: AS -> identifier"); }
#line 4174 "parser.tab.c"
    break;

  case 256: /* identifier: FROM  */
#line 681 ".\\parser.y"
                { Print("- R: FROM -> identifier"); }
#line 4180 "parser.tab.c"
    break;

  case 257: /* identifier: YIELD  */
#line 682 ".\\parser.y"
                { Print("- R: YIELD -> identifier"); }
#line 4186 "parser.tab.c"
    break;

  case 258: /* identifier: ANY  */
#line 683 ".\\parser.y"
                { Print("- R: ANY -> identifier"); }
#line 4192 "parser.tab.c"
    break;

  case 259: /* identifier: NUMBER  */
#line 684 ".\\parser.y"
                { Print("- R: NUMBER -> identifier"); }
#line 4198 "parser.tab.c"
    break;

  case 260: /* identifier: BOOLEAN  */
#line 685 ".\\parser.y"
                { Print("- R: BOOLEAN -> identifier"); }
#line 4204 "parser.tab.c"
    break;

  case 261: /* identifier: STRING  */
#line 686 ".\\parser.y"
                { Print("- R: STRING -> identifier"); }
#line 4210 "parser.tab.c"
    break;

  case 262: /* identifier: UNIQUE  */
#line 687 ".\\parser.y"
                { Print("- R: UNIQUE -> identifier"); }
#line 4216 "parser.tab.c"
    break;

  case 263: /* identifier: SYMBOL  */
#line 688 ".\\parser.y"
                { Print("- R: SYMBOL -> identifier"); }
#line 4222 "parser.tab.c"
    break;

  case 264: /* identifier: NEVER  */
#line 689 ".\\parser.y"
                { Print("- R: NEVER -> identifier"); }
#line 4228 "parser.tab.c"
    break;

  case 265: /* identifier: UNDEFINED  */
#line 690 ".\\parser.y"
                { Print("- R: UNDEFINED -> identifier"); }
#line 4234 "parser.tab.c"
    break;

  case 266: /* identifier: OBJECT  */
#line 691 ".\\parser.y"
                { Print("- R: OBJECT -> identifier"); }
#line 4240 "parser.tab.c"
    break;

  case 267: /* identifier: KEYOF  */
#line 692 ".\\parser.y"
                { Print("- R: KEYOF -> identifier"); }
#line 4246 "parser.tab.c"
    break;

  case 268: /* identifier: NAMESPACE  */
#line 693 ".\\parser.y"
                { Print("- R: NAMESPACE -> identifier"); }
#line 4252 "parser.tab.c"
    break;

  case 269: /* identifier: ABSTRACT  */
#line 694 ".\\parser.y"
                { Print("- R: ABSTRACT -> identifier"); }
#line 4258 "parser.tab.c"
    break;

  case 270: /* identifier: REQUIRE  */
#line 695 ".\\parser.y"
                { Print("- R: REQUIRE -> identifier"); }
#line 4264 "parser.tab.c"
    break;


#line 4268 "parser.tab.c"

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

#line 698 ".\\parser.y"



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


