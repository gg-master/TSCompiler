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
  YYSYMBOL_parameter = 175,                /* parameter  */
  YYSYMBOL_requiredParameter = 176,        /* requiredParameter  */
  YYSYMBOL_optionalParameter = 177,        /* optionalParameter  */
  YYSYMBOL_restParameter = 178,            /* restParameter  */
  YYSYMBOL_classDeclaration = 179,         /* classDeclaration  */
  YYSYMBOL_classHeritage = 180,            /* classHeritage  */
  YYSYMBOL_classTail = 181,                /* classTail  */
  YYSYMBOL_classElementList = 182,         /* classElementList  */
  YYSYMBOL_classElement = 183,             /* classElement  */
  YYSYMBOL_constructorCallSignature = 184, /* constructorCallSignature  */
  YYSYMBOL_propertyName = 185,             /* propertyName  */
  YYSYMBOL_identifier = 186                /* identifier  */
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
#define YYFINAL  112
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2901

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  123
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  269
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  463

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
     170,   172,   176,   187,   193,   194,   195,   199,   200,   201,
     205,   206,   207,   208,   209,   210,   214,   215,   216,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   235,   239,   240,   241,   242,   247,   248,   252,   253,
     254,   258,   259,   265,   271,   272,   276,   277,   279,   280,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   341,   342,   344,   345,
     347,   349,   351,   352,   354,   355,   356,   358,   362,   363,
     364,   368,   369,   373,   374,   380,   387,   388,   392,   393,
     394,   395,   399,   400,   401,   407,   408,   412,   412,   412,
     413,   413,   414,   414,   415,   415,   416,   416,   417,   417,
     421,   425,   426,   430,   431,   435,   436,   440,   444,   445,
     449,   450,   451,   452,   456,   457,   461,   462,   466,   467,
     473,   477,   478,   478,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   495,   496,   500,   501,   505,   506,
     510,   511,   512,   513,   517,   518,   524,   525,   529,   533,
     534,   536,   540,   541,   545,   548,   549,   550,   551,   554,
     557,   558,   559,   563,   564,   565,   566,   567,   571,   572,
     573,   574,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595
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
  "functionBody", "$@8", "callSignature", "parameterList", "parameter",
  "requiredParameter", "optionalParameter", "restParameter",
  "classDeclaration", "classHeritage", "classTail", "classElementList",
  "classElement", "constructorCallSignature", "propertyName", "identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-379)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-200)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1462,   -22,  -379,  -379,  -379,   -82,  1124,  1124,  -379,   -77,
     -66,   982,  1103,   -45,  2124,  -379,  -379,  2358,  -379,  -379,
    -379,  -379,  -379,  -379,  -379,  -379,  -379,  -379,  -379,  -379,
    -379,  -379,  -379,  -379,  -379,  -379,  -379,  -379,  -379,  -379,
    -379,  -379,  -379,  2358,  2358,  2358,  2358,  2358,  2358,  2358,
    2358,  2261,  2261,  1989,  -379,   947,    74,  1070,  -379,  -379,
    -379,  -379,  -379,   -51,  2662,  -379,  1124,  -379,  -379,  1689,
    -379,  -379,  -379,  -379,  -379,  -379,  -379,  -379,    62,  -379,
    1989,    26,    -1,  1462,  1989,  -379,  -379,    27,  -379,    28,
    1989,  -379,  2468,  -379,   175,   175,   175,   175,   175,   175,
     175,   175,   175,  2358,   -44,  -379,  2662,   -14,   -22,   -10,
    -379,  1191,  -379,  -379,  2086,  -379,  -379,  -379,  -379,  2358,
    2358,  2358,  2358,  2358,  2358,  2358,  2358,  2358,  2358,  2358,
    2358,  2358,  2358,  2358,  2358,  2358,  2358,  2358,  2358,  2358,
    2358,  2358,  2358,  2358,  2358,  2358,  2358,  2358,  2358,  2358,
    2358,  2358,  2358,  2358,  2358,  2358,  2358,  2358,  2358,  2358,
    2358,  1124,  1989,  1989,  2358,  2223,  -379,   -38,  -379,   -25,
      30,    91,  2726,  1124,  1462,     3,   494,    35,  1124,  1409,
      37,  -379,   150,    53,  -379,  -379,    64,  -379,  2662,  2261,
    -379,  -379,  -379,  -379,  -379,  2662,  2783,  2783,  2783,  2783,
    2783,  2783,  2783,  2783,  2783,  2783,  2783,  2783,  2783,  2783,
    2783,  2783,  2534,  1456,  1291,  1560,  1883,  1964,  2391,  2118,
    2118,  2118,  2118,   575,   575,   575,   575,   575,   575,   181,
     181,   181,   212,   212,   149,   149,   149,   149,  -379,    60,
      77,    49,  2358,  -379,  2662,    66,  -379,  1124,  -379,  2358,
    2382,   106,  1789,  2358,   -28,    75,  -379,  1583,  2358,    92,
      82,  -379,  -379,  -379,    58,   -18,    59,  -379,  -379,    69,
    1838,  1838,    68,   254,   254,  -379,  -379,  1738,  -379,    31,
    -379,  -379,   136,  -379,    63,  -379,  2358,  -379,  -379,  2662,
     -69,  -379,  -379,  2662,  -379,  -379,  -379,  -379,  -379,  -379,
    -379,  -379,  -379,  -379,  -379,    39,    39,  2382,  2382,  2382,
    -379,   -37,   141,  -379,  -379,  2358,   144,   453,  1789,  1989,
     -22,   173,  -379,  -379,  -379,  -379,  -379,  -379,  -379,  -379,
    -379,  -379,  -379,  -379,  2598,  -379,   616,    92,    92,  2358,
      92,  -379,   194,  -379,  1462,  -379,   154,    26,   738,    35,
     158,   160,  -379,  -379,  -379,   156,    83,    35,  1989,  1462,
      -4,  1171,  -379,  -379,   -37,   -37,  -379,   185,   191,   159,
      39,    39,  2404,  2662,  1889,  -379,   166,   129,  1462,  -379,
      92,  -379,   168,  -379,  -379,  2662,  -379,  -379,  1313,   186,
      35,  -379,   132,   188,  -379,  -379,  -379,  -379,  -379,   190,
    -379,   139,  -379,  1989,  -379,    -6,  -379,  2382,  -379,  -379,
    -379,   226,  -379,  -379,   -56,   193,  1462,  1889,  -379,  -379,
    -379,    92,  -379,    61,  -379,   860,  -379,  -379,  -379,  -379,
     -26,   200,  -379,  -379,     1,  -379,  -379,  -379,  -379,   198,
    1462,  -379,    35,  -379,  -379,   199,   201,   459,   703,  -379,
       2,  1462,  -379,  -379,  -379,  -379,  -379,   581,   825,  -379,
    -379,  1462,  -379
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,    18,   162,   163,   164,     0,     0,     0,   167,     0,
       0,     0,     0,     0,     0,    83,    82,     0,   253,   254,
     255,   256,   266,   267,   268,   269,   257,   258,   259,   260,
     263,   264,   261,   262,   265,    62,    63,    64,    86,    84,
      85,   252,    65,     0,     0,     0,     0,     0,     0,     0,
       0,    68,    68,     0,    32,     0,     0,     0,     3,     5,
      81,   144,     6,     0,    76,     7,     0,     8,    10,     0,
      11,    12,    13,    14,    15,     9,    16,    17,    80,    78,
       0,     0,     0,     0,     0,   180,   181,     0,   183,     0,
       0,   185,     0,    80,   147,    95,    96,    93,    94,    88,
      87,    89,    90,     0,     0,    69,    71,     0,     0,     0,
     188,     0,     1,     4,     0,    73,   138,    91,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,     0,   156,   158,
       0,    75,    76,     0,     0,     0,     0,     0,     0,     0,
       0,   226,     0,     0,   182,   184,     0,   186,    72,    68,
      66,    67,   140,   189,    79,    77,   111,   115,   116,   122,
     112,   113,   114,   117,   118,   126,   119,   120,   121,   123,
     124,   125,     0,   135,   127,   128,   129,   130,   131,   105,
     106,   107,   108,   103,   102,   110,   109,   136,   137,   132,
     133,   134,    97,    98,    99,   100,   101,   104,   143,     0,
       0,   142,     0,   148,   153,     0,   151,     0,   155,     0,
       0,   159,     0,     0,     0,   156,   187,     0,     0,   204,
       0,   214,   216,   217,     0,   218,   202,   200,   228,     0,
       0,     0,     0,     0,     0,   229,   249,     0,   232,     0,
     248,   227,     0,   170,     0,    70,     0,   145,   146,   154,
       0,   149,   157,   160,    49,    50,    52,    51,    53,    55,
      56,    54,    57,    58,    59,     0,     0,    46,    46,     0,
      61,    34,    39,    41,    60,     0,     0,   137,     0,     0,
      31,   165,    19,    20,    21,    23,    24,    25,    26,    27,
      28,    22,    29,    30,   224,   205,     0,   208,   206,     0,
     220,   222,   219,   201,     0,   231,     0,     0,     0,     0,
       0,     0,   230,   233,   235,     0,     0,     0,     0,     0,
       0,   139,   150,   152,    35,    36,    47,     0,     0,     0,
       0,     0,     0,   161,     0,   176,     0,     0,     0,   225,
     212,   215,     0,   209,   207,    33,   221,   223,     0,     0,
       0,   243,     0,     0,   234,   250,   251,   237,   236,     0,
     239,     0,   171,     0,   190,     0,   194,     0,    44,    45,
      40,    37,    38,    42,     0,     0,     0,     0,   178,   166,
     213,   210,   203,     0,   242,     0,   245,   244,   238,   168,
       0,     0,   191,   195,     0,    48,    43,   172,   177,     0,
       0,   211,     0,   240,   247,     0,     0,     0,     0,   192,
       0,     0,   174,   179,   241,   246,   169,     0,     0,   193,
     173,     0,   175
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -379,  -379,   -54,   -55,  -379,  -379,  -261,  -242,  -263,   -53,
      12,  -379,  -234,  -111,  -379,   -47,  -379,    65,  -248,   -50,
      85,    41,  -379,  -379,    78,   164,  -151,   263,    84,    88,
    -379,  -379,  -379,  -379,  -379,  -379,  -379,  -379,    89,    90,
      93,    94,    95,    97,   -95,  -378,  -379,    98,  -325,  -379,
    -250,    -8,  -320,  -379,  -379,  -310,    99,  -379,   162,  -379,
      72,  -379,  -208,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    56,    57,    58,   321,    59,   341,   366,   311,   312,
     367,   313,   251,    60,    61,   104,   105,    62,   170,    63,
      64,   166,   245,   246,    65,   167,   168,    66,    67,    68,
      83,   446,   359,   451,   461,   416,   440,    69,    70,    71,
      72,    73,    74,    75,   405,   406,   434,    76,   267,   344,
     177,   260,   261,   262,   263,   264,    77,   180,   181,   277,
     278,   349,   279,    93
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      78,   111,   113,   109,   316,   107,    81,    82,   310,   178,
     114,    87,    89,   403,   431,   403,   381,   189,   355,   171,
     403,   403,   255,   247,   394,   335,   382,   433,   182,   357,
     175,   342,   400,   247,   183,   114,    80,   249,   393,    79,
     186,    84,   364,   365,   339,   356,   370,   189,   371,   165,
     362,   114,    85,   447,   250,    78,   113,    78,   372,   436,
     340,   250,   346,   347,   114,   424,   169,   369,   276,   115,
     376,   190,   433,    90,   112,   294,   295,   296,   297,   298,
     299,   387,   248,    78,   300,   301,    35,    36,    37,   302,
     303,   304,   318,   339,    42,   399,   292,   390,   443,    92,
     379,   191,    94,   383,   384,   381,   386,   411,   412,   192,
     250,    78,   239,   240,   114,   445,   432,   454,   404,   256,
     179,   114,   257,   449,   459,   114,   415,   290,    95,    96,
      97,    98,    99,   100,   101,   102,   106,   106,   114,   314,
     250,   174,   285,   336,   176,   339,   420,   184,   185,   176,
     252,   354,   114,   307,   172,   308,   266,   309,   179,   276,
     276,   238,   350,   351,   282,   435,   276,   165,   315,   439,
     319,   250,   283,   169,    78,   287,   265,   338,   268,   280,
     378,   343,   266,   284,   360,   291,   348,   441,   188,   442,
     114,   345,   288,   425,   314,   314,   314,   314,   314,   195,
     114,   337,   171,   398,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   407,   169,   418,   241,
     244,   426,   407,   160,   358,   372,   339,    78,   429,   314,
     314,   314,   161,   162,   374,   163,   164,   165,   171,   377,
     280,   280,   389,   395,   106,   396,   397,   280,   410,   448,
     155,   156,   157,   158,   159,   160,   417,   421,   161,   162,
     388,   163,   164,   165,   161,   162,   314,   163,   164,   165,
     408,    35,    36,    37,   402,   423,   409,   427,   401,    42,
     428,   371,   437,   157,   158,   159,   160,   452,   455,   414,
     368,   456,   322,   419,   171,   161,   162,   289,   163,   164,
     165,   363,   173,   113,   293,   323,   265,   254,   317,   450,
     392,   324,   281,   334,    78,   325,   326,   327,   265,   353,
     328,   329,   330,   430,   331,   332,   333,     0,     0,    78,
       0,   438,     0,     0,     0,     0,     0,   171,     0,     0,
       0,   361,     0,     0,     0,     0,     0,     0,    78,     0,
       0,     0,     0,     0,     0,   453,     0,     0,    78,     0,
       0,     0,     0,   457,   458,     0,   460,     0,     0,     0,
     373,     0,   113,   113,     0,     0,   462,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,     0,
       0,     0,     0,     0,   385,   265,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,     0,     0,     0,     0,     0,     0,    78,    78,     0,
       0,    78,     0,     0,     0,     0,     0,    78,    78,     0,
       1,    78,     2,     3,     4,     5,     0,     6,     7,     0,
       0,     0,     8,     9,    10,    11,    12,    13,  -196,  -196,
      14,    15,    16,    17,     0,     0,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,     0,    35,    36,    37,    38,
      39,    40,    41,     0,    42,    43,    44,    45,    46,   258,
       0,    18,    19,    20,    21,    22,     0,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     0,
       0,     0,     0,     0,     0,     0,     0,    41,     0,   152,
     153,   154,   155,   156,   157,   158,   159,   160,    47,    48,
       0,     0,     0,     0,    49,    50,   161,   162,     0,   163,
     164,   165,   375,    51,     0,    52,     0,    53,     0,    54,
      55,  -196,     1,     0,     2,     3,     4,     5,     0,     6,
       7,     0,     0,     0,     8,     9,    10,    11,    12,    13,
    -197,  -197,    14,    15,    16,    17,     0,     0,    18,    19,
      20,    21,    22,   259,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,     0,     0,    35,    36,
      37,    38,    39,    40,    41,     0,    42,    43,    44,    45,
      46,   258,     0,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,     0,     0,     0,     0,     0,     0,     0,     0,    41,
       0,   152,   153,   154,   155,   156,   157,   158,   159,   160,
      47,    48,     0,     0,     0,     0,    49,    50,   161,   162,
       0,   163,   164,   165,     0,    51,     0,    52,     0,    53,
       0,    54,    55,  -197,     1,     0,     2,     3,     4,     5,
       0,     6,     7,     0,     0,     0,     8,     9,    10,    11,
      12,    13,  -198,     0,    14,    15,    16,    17,     0,     0,
      18,    19,    20,    21,    22,   380,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,     0,     0,
      35,    36,    37,    38,    39,    40,    41,     0,    42,    43,
      44,    45,    46,   258,     0,    18,    19,    20,    21,    22,
       0,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     0,     0,     0,     0,     0,     0,     0,
       0,    41,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    47,    48,     0,     0,     0,     0,    49,    50,
       0,     0,     0,     0,     0,     0,     0,    51,     0,    52,
       0,    53,     0,    54,    55,  -198,     1,     0,     2,     3,
       4,     5,     0,     6,     7,     0,     0,     0,     8,     9,
      10,    11,    12,    13,  -199,     0,    14,    15,    16,    17,
       0,     0,    18,    19,    20,    21,    22,   391,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       0,     0,    35,    36,    37,    38,    39,    40,    41,     0,
      42,    43,    44,    45,    46,   258,     0,    18,    19,    20,
      21,    22,     0,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,     0,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,    48,     0,     0,     0,     0,
      49,    50,     0,     0,     0,     0,     0,     0,     0,    51,
       0,    52,     0,    53,     0,    54,    55,  -199,     1,     0,
       2,     3,     4,     5,     0,     6,     7,     0,     0,     0,
       8,     9,    10,    11,    12,    13,     0,     0,    14,    15,
      16,    17,     0,     0,    18,    19,    20,    21,    22,   444,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     0,     0,    35,    36,    37,    38,    39,    40,
      41,     0,    42,    43,    44,    45,    46,     0,     0,    18,
      19,    20,    21,    22,     0,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     0,     0,     0,
       0,     0,     0,     0,     0,    41,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    47,    48,     0,     0,
       0,     0,    49,    50,     0,     0,     0,     0,     0,     0,
       0,    51,     0,    52,     0,    53,     0,    54,    55,   110,
      -2,     1,     0,     2,     3,     4,     5,     0,     6,     7,
       0,     0,     0,     8,     9,    10,    11,    12,    13,     0,
       0,    14,    15,    16,    17,     0,     0,    18,    19,    20,
      21,    22,    86,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,     0,     0,    35,    36,    37,
      38,    39,    40,    41,     0,    42,    43,    44,    45,    46,
      18,    19,    20,    21,    22,     0,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,     0,     0,
       0,    18,    19,    20,    21,    22,    41,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    47,
      48,     0,     0,     0,     0,    49,    50,    41,     0,     0,
       0,     0,     0,     0,    51,     0,    52,     0,    53,     0,
      54,    55,     1,     0,     2,     3,     4,     5,     0,     6,
       7,     0,     0,     0,     8,     9,    10,    11,    12,    13,
       0,     0,    14,    15,    16,    17,     0,     0,    18,    19,
      20,    21,    22,    88,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,     0,     0,    35,    36,
      37,    38,    39,    40,    41,     0,    42,    43,    44,    45,
      46,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,     0,     0,     0,     0,
       0,     0,     0,     0,   161,   162,     0,   163,   164,   165,
      47,    48,     0,     0,     0,     0,    49,    50,     0,     0,
       0,     0,     0,     0,     0,    51,     0,    52,     0,    53,
       0,    54,    55,   193,     1,     0,     2,     3,     4,     5,
       0,     6,     7,     0,     0,     0,     8,     9,    10,    11,
      12,    13,     0,     0,    14,    15,    16,    17,     0,     0,
      18,    19,    20,    21,    22,     0,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,     0,     0,
      35,    36,    37,    38,    39,    40,    41,     0,    42,    43,
      44,    45,    46,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,     0,     0,     0,     0,
       0,     0,     0,     0,   161,   162,     0,   163,   164,   165,
     269,     0,    47,    48,     0,     0,     0,     0,    49,    50,
     270,   271,     0,     0,     0,     0,     0,    51,     0,    52,
       0,    53,     0,    54,    55,   422,    18,    19,    20,    21,
      22,   272,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,     0,    35,    36,    37,     0,
       0,     0,    41,     1,    42,     2,     3,     4,     5,     0,
       6,     7,     0,     0,     0,     8,     9,    10,    11,    12,
      13,     0,     0,    14,    15,    16,    17,     0,     0,    18,
      19,    20,    21,    22,     0,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     0,     0,    35,
      36,    37,    38,    39,    40,    41,     0,    42,    43,    44,
      45,    46,     0,   273,     0,   274,     0,     0,     0,     0,
       0,   275,     0,     0,     0,     0,     0,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,    47,    48,     0,     0,     0,     0,    49,    50,   161,
     162,     0,   163,   164,   165,     0,    51,     0,    52,     0,
      53,     0,    54,    55,   320,     0,     2,     3,     4,     5,
       0,     6,     7,     0,     0,     0,     8,     9,    10,    11,
      12,    13,     0,     0,    14,    15,    16,    17,     0,     0,
      18,    19,    20,    21,    22,     0,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,     0,     0,
      35,    36,    37,    38,    39,    40,    41,     0,    42,    43,
      44,    45,    46,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,     0,     0,     0,     0,     0,
       0,     0,     0,   161,   162,     0,   163,   164,   165,     0,
       0,     0,    47,    48,     0,     0,     0,     0,    49,    50,
     108,     0,     2,     3,     4,     0,     0,    51,     0,    52,
       0,    53,     0,     0,    55,     0,     0,     0,     0,     0,
       0,    15,    16,    17,     0,     0,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,     0,    35,    36,    37,    38,
      39,    40,    41,     0,    42,    43,    44,    45,    46,   270,
     271,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,    19,    20,    21,    22,
     272,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     0,     0,    35,    36,    37,    47,    48,
     108,    41,     0,    42,    49,    50,     0,     0,     0,     0,
       0,     0,     0,    51,     0,    52,     0,    53,     0,   -74,
       0,    15,    16,    17,     0,     0,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,     0,    35,    36,    37,    38,
      39,    40,    41,     0,    42,    43,    44,    45,    46,     0,
       0,     0,   273,     0,   274,     0,     0,     0,     0,     0,
     352,     0,     0,     0,     0,    18,    19,    20,    21,    22,
       0,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     0,     0,    35,    36,    37,    47,    48,
     108,    41,     0,    42,    49,    50,     0,     0,     0,     0,
       0,     0,     0,    51,     0,    52,     0,    53,     0,   -74,
       0,    15,    16,    17,     0,     0,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,     0,    35,    36,    37,    38,
      39,    40,    41,     0,    42,    43,    44,    45,    46,     0,
       0,     0,   273,     0,   274,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,    47,    48,
     108,     0,     0,     0,    49,    50,   161,   162,     0,   163,
     164,   165,     0,    51,     0,    52,     0,    53,   -74,     0,
       0,    15,    16,    17,     0,     0,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,     0,    35,    36,    37,    38,
      39,    40,    41,     0,    42,    43,    44,    45,    46,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,     0,
       0,     0,     0,     0,     0,     0,     0,   161,   162,     0,
     163,   164,   165,     0,     0,     0,     0,   194,    47,    48,
       0,     0,     0,     0,    49,    50,     0,     0,     0,     0,
       0,     0,     0,    51,     0,    52,     0,    53,    15,    16,
      17,     0,     0,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,     0,     0,    35,    36,    37,    38,    39,    40,    41,
       0,    42,    43,    44,    45,    46,    15,    16,    17,     0,
       0,    18,    19,    20,    21,    22,     0,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     0,
       0,    35,    36,    37,    38,    39,    40,    41,     0,    42,
      43,    44,    45,    46,     0,    47,    48,     0,     0,     0,
       0,    49,    50,     0,     0,     0,     0,     0,     0,     0,
      51,     0,    52,     0,    53,     0,     0,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,    47,    48,     0,     0,     0,     0,    49,
      50,   161,   162,     0,   163,   164,   165,     0,    51,     0,
      52,     0,    53,     0,    91,    15,    16,    17,   242,     0,
      18,    19,    20,    21,    22,     0,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,     0,     0,
      35,    36,    37,    38,    39,    40,    41,     0,    42,    43,
      44,    45,    46,    15,    16,    17,   103,     0,    18,    19,
      20,    21,    22,     0,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,     0,     0,    35,    36,
      37,    38,    39,    40,    41,     0,    42,    43,    44,    45,
      46,     0,    47,    48,     0,     0,     0,     0,    49,    50,
       0,     0,     0,     0,     0,     0,     0,    51,     0,    52,
       0,    53,   243,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,    48,     0,     0,     0,     0,    49,    50,     0,     0,
       0,     0,     0,     0,     0,    51,     0,    52,     0,    53,
      15,    16,    17,     0,     0,    18,    19,    20,    21,    22,
       0,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     0,     0,    35,    36,    37,    38,    39,
      40,    41,     0,    42,    43,    44,    45,    46,   294,   295,
     296,   297,   298,   299,     0,     0,     0,   300,   301,    35,
      36,    37,   302,   303,   304,     0,     0,    42,     0,     0,
     294,   295,   296,   297,   298,   299,     0,     0,     0,   300,
     301,    35,    36,    37,   302,   303,   304,    47,    48,    42,
       0,     0,     0,    49,    50,   305,     0,   306,     0,     0,
       0,     0,    51,     0,    52,     0,    53,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   307,     0,   308,     0,
     309,     0,     0,     0,   161,   162,     0,   163,   164,   165,
       0,     0,     0,     0,     0,     0,     0,     0,   307,   413,
     308,     0,   309,   116,   117,   118,     0,     0,     0,     0,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,     0,     0,     0,     0,     0,     0,     0,
       0,   161,   162,     0,   163,   164,   165,     0,   187,   116,
     117,   118,     0,     0,     0,     0,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   286,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,     0,
       0,     0,     0,     0,     0,     0,     0,   161,   162,     0,
     163,   164,   165,   116,   117,   118,     0,     0,     0,     0,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   250,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,     0,     0,     0,     0,     0,     0,     0,
       0,   161,   162,     0,   163,   164,   165,   116,   117,   118,
       0,     0,     0,     0,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,     0,     0,     0,
       0,     0,     0,     0,     0,   161,   162,     0,   163,   164,
     165,   116,   117,   118,     0,     0,     0,     0,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   253,   152,   153,   154,   155,   156,   157,   158,   159,
     160,     0,     0,     0,     0,     0,     0,     0,     0,   161,
     162,     0,   163,   164,   165,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,     0,     0,
       0,     0,     0,     0,     0,     0,   161,   162,     0,   163,
     164,   165
};

static const yytype_int16 yycheck[] =
{
       0,    55,    57,    53,   252,    52,     6,     7,   250,    10,
      61,    11,    12,    19,    20,    19,   336,    61,   279,    69,
      19,    19,   173,    61,   349,   259,   336,   405,    83,   279,
      80,   265,   357,    61,    84,    61,   118,    62,   348,    61,
      90,   118,   305,   306,    62,   279,    83,    61,    85,   118,
     119,    61,   118,    79,    79,    55,   111,    57,   114,   115,
      78,    79,   270,   271,    61,   390,    66,   309,   179,   120,
     318,   115,   450,   118,     0,    36,    37,    38,    39,    40,
      41,   342,   120,    83,    45,    46,    47,    48,    49,    50,
      51,    52,   120,    62,    55,   356,   247,   347,   423,    14,
     334,   115,    17,   337,   338,   425,   340,   370,   371,   119,
      79,   111,   162,   163,    61,   425,   122,   442,   122,   174,
     121,    61,   119,   122,   122,    61,   374,    61,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    61,   250,
      79,    79,   189,    61,   118,    62,   380,   120,   120,   118,
     120,   120,    61,   114,    69,   116,   121,   118,   121,   270,
     271,   161,   273,   274,    14,   407,   277,   118,    62,   417,
      95,    79,   119,   173,   174,   115,   176,   119,   178,   179,
       7,   122,   121,   119,   121,   119,   118,   421,   103,   423,
      61,   122,   115,    61,   305,   306,   307,   308,   309,   114,
      61,   119,   252,   120,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,    61,   247,   119,   164,
     165,   119,    61,   104,   118,   114,    62,   257,   119,   370,
     371,   372,   113,   114,   120,   116,   117,   118,   318,   319,
     270,   271,   118,   115,   189,   115,   120,   277,   119,    79,
      99,   100,   101,   102,   103,   104,   120,   119,   113,   114,
     344,   116,   117,   118,   113,   114,   407,   116,   117,   118,
     115,    47,    48,    49,   359,   119,   115,   119,   358,    55,
     120,    85,   119,   101,   102,   103,   104,   119,   119,   372,
     308,   120,   257,   378,   374,   113,   114,   242,   116,   117,
     118,   290,    69,   388,   249,   257,   336,   173,   253,   434,
     348,   257,   180,   258,   344,   257,   257,   257,   348,   277,
     257,   257,   257,   403,   257,   257,   257,    -1,    -1,   359,
      -1,   416,    -1,    -1,    -1,    -1,    -1,   417,    -1,    -1,
      -1,   286,    -1,    -1,    -1,    -1,    -1,    -1,   378,    -1,
      -1,    -1,    -1,    -1,    -1,   440,    -1,    -1,   388,    -1,
      -1,    -1,    -1,   447,   448,    -1,   451,    -1,    -1,    -1,
     315,    -1,   457,   458,    -1,    -1,   461,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   339,   425,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     440,    -1,    -1,    -1,    -1,    -1,    -1,   447,   448,    -1,
      -1,   451,    -1,    -1,    -1,    -1,    -1,   457,   458,    -1,
       1,   461,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    25,
      -1,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    99,   100,
      -1,    -1,    -1,    -1,   105,   106,   113,   114,    -1,   116,
     117,   118,   119,   114,    -1,   116,    -1,   118,    -1,   120,
     121,   122,     1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    27,    28,
      29,    30,    31,   119,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    25,    -1,    27,    28,    29,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      99,   100,    -1,    -1,    -1,    -1,   105,   106,   113,   114,
      -1,   116,   117,   118,    -1,   114,    -1,   116,    -1,   118,
      -1,   120,   121,   122,     1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    13,    14,    15,    16,
      17,    18,    19,    -1,    21,    22,    23,    24,    -1,    -1,
      27,    28,    29,    30,    31,   119,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    25,    -1,    27,    28,    29,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,   100,    -1,    -1,    -1,    -1,   105,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,   116,
      -1,   118,    -1,   120,   121,   122,     1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    13,    14,
      15,    16,    17,    18,    19,    -1,    21,    22,    23,    24,
      -1,    -1,    27,    28,    29,    30,    31,   119,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    25,    -1,    27,    28,    29,
      30,    31,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,
     105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,   116,    -1,   118,    -1,   120,   121,   122,     1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    -1,    -1,    21,    22,
      23,    24,    -1,    -1,    27,    28,    29,    30,    31,   119,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    -1,    -1,    27,
      28,    29,    30,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,
      -1,    -1,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,   116,    -1,   118,    -1,   120,   121,   122,
       0,     1,    -1,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    13,    14,    15,    16,    17,    18,    -1,
      -1,    21,    22,    23,    24,    -1,    -1,    27,    28,    29,
      30,    31,   120,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      27,    28,    29,    30,    31,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    53,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    99,
     100,    -1,    -1,    -1,    -1,   105,   106,    53,    -1,    -1,
      -1,    -1,    -1,    -1,   114,    -1,   116,    -1,   118,    -1,
     120,   121,     1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    13,    14,    15,    16,    17,    18,
      -1,    -1,    21,    22,    23,    24,    -1,    -1,    27,    28,
      29,    30,    31,   120,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,   114,    -1,   116,   117,   118,
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
       1,    -1,    99,   100,    -1,    -1,    -1,    -1,   105,   106,
      11,    12,    -1,    -1,    -1,    -1,    -1,   114,    -1,   116,
      -1,   118,    -1,   120,   121,   122,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    49,    -1,
      -1,    -1,    53,     1,    55,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    13,    14,    15,    16,    17,
      18,    -1,    -1,    21,    22,    23,    24,    -1,    -1,    27,
      28,    29,    30,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    -1,   114,    -1,   116,    -1,    -1,    -1,    -1,
      -1,   122,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,    99,   100,    -1,    -1,    -1,    -1,   105,   106,   113,
     114,    -1,   116,   117,   118,    -1,   114,    -1,   116,    -1,
     118,    -1,   120,   121,     1,    -1,     3,     4,     5,     6,
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
       1,    -1,     3,     4,     5,    -1,    -1,   114,    -1,   116,
      -1,   118,    -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    -1,    -1,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    47,    48,    49,    99,   100,
       1,    53,    -1,    55,   105,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,   116,    -1,   118,    -1,   120,
      -1,    22,    23,    24,    -1,    -1,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    -1,
      -1,    -1,   114,    -1,   116,    -1,    -1,    -1,    -1,    -1,
     122,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    47,    48,    49,    99,   100,
       1,    53,    -1,    55,   105,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,   116,    -1,   118,    -1,   120,
      -1,    22,    23,    24,    -1,    -1,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    -1,
      -1,    -1,   114,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    99,   100,
       1,    -1,    -1,    -1,   105,   106,   113,   114,    -1,   116,
     117,   118,    -1,   114,    -1,   116,    -1,   118,   119,    -1,
      -1,    22,    23,    24,    -1,    -1,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,
     116,   117,   118,    -1,    -1,    -1,    -1,     1,    99,   100,
      -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,   116,    -1,   118,    22,    23,
      24,    -1,    -1,    27,    28,    29,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    22,    23,    24,    -1,
      -1,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    -1,    99,   100,    -1,    -1,    -1,
      -1,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,    -1,   116,    -1,   118,    -1,    -1,    -1,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    99,   100,    -1,    -1,    -1,    -1,   105,
     106,   113,   114,    -1,   116,   117,   118,    -1,   114,    -1,
     116,    -1,   118,    -1,   120,    22,    23,    24,    25,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   100,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    -1,   116,    -1,   118,
      22,    23,    24,    -1,    -1,    27,    28,    29,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    55,    -1,    -1,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    99,   100,    55,
      -1,    -1,    -1,   105,   106,    83,    -1,    85,    -1,    -1,
      -1,    -1,   114,    -1,   116,    -1,   118,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   114,    -1,   116,    -1,
     118,    -1,    -1,    -1,   113,   114,    -1,   116,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,
     116,    -1,   118,    55,    56,    57,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,   114,    -1,   116,   117,   118,    -1,   120,    55,
      56,    57,    -1,    -1,    -1,    -1,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,
     116,   117,   118,    55,    56,    57,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
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
     106,   114,   116,   118,   120,   121,   124,   125,   126,   128,
     136,   137,   140,   142,   143,   147,   150,   151,   152,   160,
     161,   162,   163,   164,   165,   166,   170,   179,   186,    61,
     118,   186,   186,   153,   118,   118,   120,   186,   120,   186,
     118,   120,   143,   186,   143,   143,   143,   143,   143,   143,
     143,   143,   143,    25,   138,   139,   143,   138,     1,   142,
     122,   125,     0,   126,    61,   120,    55,    56,    57,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   113,   114,   116,   117,   118,   144,   148,   149,   186,
     141,   142,   143,   150,    79,   142,   118,   173,    10,   121,
     180,   181,   126,   142,   120,   120,   142,   120,   143,    61,
     115,   115,   119,   122,     1,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   186,   142,
     142,   143,    25,   119,   143,   145,   146,    61,   120,    62,
      79,   135,   120,    95,   148,   149,   126,   119,    25,   119,
     174,   175,   176,   177,   178,   186,   121,   171,   186,     1,
      11,    12,    32,   114,   116,   122,   136,   182,   183,   185,
     186,   181,    14,   119,   119,   138,    79,   115,   115,   143,
      61,   119,   149,   143,    36,    37,    38,    39,    40,    41,
      45,    46,    50,    51,    52,    83,    85,   114,   116,   118,
     130,   131,   132,   134,   136,    62,   141,   143,   120,    95,
       1,   127,   140,   147,   151,   152,   161,   162,   163,   164,
     165,   166,   170,   179,   143,   135,    61,   119,   119,    62,
      78,   129,   135,   122,   172,   122,   185,   185,   118,   184,
     136,   136,   122,   183,   120,   129,   135,   173,   118,   155,
     121,   143,   119,   144,   131,   131,   130,   133,   133,   130,
      83,    85,   114,   143,   120,   119,   141,   142,     7,   135,
     119,   175,   178,   135,   135,   143,   135,   129,   125,   118,
     173,   119,   174,   178,   171,   115,   115,   120,   120,   129,
     171,   142,   126,    19,   122,   167,   168,    61,   115,   115,
     119,   131,   131,   115,   132,   141,   158,   120,   119,   126,
     135,   119,   122,   119,   171,    61,   119,   119,   120,   119,
     142,    20,   122,   168,   169,   130,   115,   119,   126,   141,
     159,   135,   135,   171,   119,   178,   154,    79,    79,   122,
     167,   156,   119,   126,   171,   119,   120,   125,   125,   122,
     126,   157,   126
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   123,   124,   125,   125,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   128,   129,   130,   130,   130,   131,   131,   131,
     132,   132,   132,   132,   132,   132,   133,   133,   133,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   135,   136,   136,   136,   136,   137,   137,   138,   138,
     138,   139,   139,   140,   141,   141,   142,   142,   142,   142,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   144,   144,
     144,   145,   145,   146,   146,   147,   148,   148,   149,   149,
     149,   149,   150,   150,   150,   151,   151,   153,   154,   152,
     155,   152,   156,   152,   157,   152,   158,   152,   159,   152,
     160,   161,   161,   162,   162,   163,   163,   164,   165,   165,
     166,   166,   166,   166,   167,   167,   168,   168,   169,   169,
     170,   171,   172,   171,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   174,   174,   175,   175,   176,   176,
     177,   177,   177,   177,   178,   178,   179,   179,   180,   181,
     181,   181,   182,   182,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   184,   184,   184,   184,   184,   185,   185,
     185,   185,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     2,     3,     3,     1,
       3,     1,     3,     4,     3,     3,     0,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     3,     3,     0,     1,
       3,     1,     2,     2,     0,     1,     1,     3,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     5,
       3,     2,     3,     3,     1,     4,     4,     2,     2,     3,
       4,     1,     3,     1,     2,     3,     1,     3,     1,     2,
       3,     4,     1,     1,     1,     5,     7,     0,     0,     9,
       0,     6,     0,     9,     0,    10,     0,     7,     0,     8,
       2,     2,     3,     2,     3,     2,     3,     3,     2,     3,
       6,     7,     8,     9,     1,     2,     3,     4,     2,     3,
       4,     2,     0,     4,     2,     3,     3,     4,     3,     4,
       5,     6,     4,     5,     1,     3,     1,     1,     1,     2,
       2,     3,     2,     3,     2,     3,     3,     4,     2,     2,
       3,     3,     1,     2,     3,     2,     3,     3,     4,     3,
       5,     6,     4,     2,     3,     3,     5,     4,     1,     1,
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
#line 90 ".\\parser.y"
        { 
            if ( syntaxErrorCounter > 0 ) {
                PrintError("Found " + std::to_string(syntaxErrorCounter) + " syntax errors. Fix them and rerun.");
                exit(1);
            }
            Print("- R: statementList -> script"); 
        }
#line 2669 "parser.tab.c"
    break;

  case 3: /* statementList: statementListItem  */
#line 100 ".\\parser.y"
                        { Print("- R: statementListItem -> statementList"); }
#line 2675 "parser.tab.c"
    break;

  case 4: /* statementList: statementList statementListItem  */
#line 101 ".\\parser.y"
                                      { Print("- R: statementList statementListItem -> statementList"); }
#line 2681 "parser.tab.c"
    break;

  case 5: /* statementListItem: emptyStatement  */
#line 105 ".\\parser.y"
                                    { Print("- R: emptyStatement -> statementListItem"); }
#line 2687 "parser.tab.c"
    break;

  case 6: /* statementListItem: expressionStatement  */
#line 106 ".\\parser.y"
                                    { Print("- R: expressionStatement -> statementListItem"); }
#line 2693 "parser.tab.c"
    break;

  case 7: /* statementListItem: varStatement  */
#line 107 ".\\parser.y"
                                    { Print("- R: varStatement -> statementListItem"); }
#line 2699 "parser.tab.c"
    break;

  case 8: /* statementListItem: ifStatement  */
#line 108 ".\\parser.y"
                                    { Print("- R: ifStatement -> statementListItem"); }
#line 2705 "parser.tab.c"
    break;

  case 9: /* statementListItem: switchStatement  */
#line 109 ".\\parser.y"
                                    { Print("- R: switchStatement -> statementListItem"); }
#line 2711 "parser.tab.c"
    break;

  case 10: /* statementListItem: iterationStatement  */
#line 110 ".\\parser.y"
                                    { Print("- R: iterationStatement -> statementListItem"); }
#line 2717 "parser.tab.c"
    break;

  case 11: /* statementListItem: continueStatement  */
#line 112 ".\\parser.y"
        {
            if ( !isInIterationBody ) { 
                yyerror("illegal continue statement."); YYERROR;
            } 
            Print("- R: continueStatement -> statementListItem");  
        }
#line 2728 "parser.tab.c"
    break;

  case 12: /* statementListItem: breakStatement  */
#line 119 ".\\parser.y"
        {
            if ( !isInIterationBody ) { 
                yyerror("illegal break statement."); YYERROR;
            } 
            Print("- R: breakStatement -> statementListItem");
        }
#line 2739 "parser.tab.c"
    break;

  case 13: /* statementListItem: returnStatement  */
#line 126 ".\\parser.y"
        { 
            if ( !isInFunctionBody ) { 
                yyerror("illegal return statement."); YYERROR;
            } 
            Print("- R: returnStatement -> statementListItem"); 
        }
#line 2750 "parser.tab.c"
    break;

  case 14: /* statementListItem: labelledStatement  */
#line 132 ".\\parser.y"
                                    { Print("- R: labelledStatement -> statementListItem"); }
#line 2756 "parser.tab.c"
    break;

  case 15: /* statementListItem: blockStatement  */
#line 133 ".\\parser.y"
                                    { Print("- R: blockStatement -> statementListItem"); }
#line 2762 "parser.tab.c"
    break;

  case 16: /* statementListItem: functionDeclaration  */
#line 134 ".\\parser.y"
                                    { Print("- R: functionDeclaration -> statementListItem"); }
#line 2768 "parser.tab.c"
    break;

  case 17: /* statementListItem: classDeclaration  */
#line 135 ".\\parser.y"
                                    { Print("- R: classDeclaration -> statementListItem"); }
#line 2774 "parser.tab.c"
    break;

  case 19: /* statementListItemWithoutEmptyStatement: expressionStatement  */
#line 141 ".\\parser.y"
                                    { Print("- R: expressionStatement -> statementListItem"); }
#line 2780 "parser.tab.c"
    break;

  case 20: /* statementListItemWithoutEmptyStatement: varStatement  */
#line 142 ".\\parser.y"
                                    { Print("- R: varStatement -> statementListItem"); }
#line 2786 "parser.tab.c"
    break;

  case 21: /* statementListItemWithoutEmptyStatement: ifStatement  */
#line 143 ".\\parser.y"
                                    { Print("- R: ifStatement -> statementListItem"); }
#line 2792 "parser.tab.c"
    break;

  case 22: /* statementListItemWithoutEmptyStatement: switchStatement  */
#line 144 ".\\parser.y"
                                    { Print("- R: switchStatement -> statementListItem"); }
#line 2798 "parser.tab.c"
    break;

  case 23: /* statementListItemWithoutEmptyStatement: iterationStatement  */
#line 145 ".\\parser.y"
                                    { Print("- R: iterationStatement -> statementListItem"); }
#line 2804 "parser.tab.c"
    break;

  case 24: /* statementListItemWithoutEmptyStatement: continueStatement  */
#line 147 ".\\parser.y"
        {
            if ( !isInIterationBody ) { 
                yyerror("illegal continue statement."); YYERROR;
            } 
            Print("- R: continueStatement -> statementListItem");
        }
#line 2815 "parser.tab.c"
    break;

  case 25: /* statementListItemWithoutEmptyStatement: breakStatement  */
#line 154 ".\\parser.y"
        {
            if ( !isInIterationBody ) { 
                yyerror("illegal break statement."); YYERROR;
            } 
            Print("- R: breakStatement -> statementListItem");
        }
#line 2826 "parser.tab.c"
    break;

  case 26: /* statementListItemWithoutEmptyStatement: returnStatement  */
#line 161 ".\\parser.y"
        { 
            if ( !isInFunctionBody ) { 
                yyerror("illegal return statement."); YYERROR;
            } 
            Print("- R: returnStatement -> statementListItem"); 
        }
#line 2837 "parser.tab.c"
    break;

  case 27: /* statementListItemWithoutEmptyStatement: labelledStatement  */
#line 167 ".\\parser.y"
                                    { Print("- R: labelledStatement -> statementListItem"); }
#line 2843 "parser.tab.c"
    break;

  case 28: /* statementListItemWithoutEmptyStatement: blockStatement  */
#line 168 ".\\parser.y"
                                    { Print("- R: blockStatement -> statementListItem"); }
#line 2849 "parser.tab.c"
    break;

  case 29: /* statementListItemWithoutEmptyStatement: functionDeclaration  */
#line 169 ".\\parser.y"
                                    { Print("- R: functionDeclaration -> statementListItem"); }
#line 2855 "parser.tab.c"
    break;

  case 30: /* statementListItemWithoutEmptyStatement: classDeclaration  */
#line 170 ".\\parser.y"
                                    { Print("- R: classDeclaration -> statementListItem"); }
#line 2861 "parser.tab.c"
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
#line 2873 "parser.tab.c"
    break;

  case 33: /* initializer: '=' singleExpression  */
#line 187 ".\\parser.y"
                           { Print("- R: '=' singleExpression -> initializer"); }
#line 2879 "parser.tab.c"
    break;

  case 34: /* type: unionOrIntersectionOrPrimaryType  */
#line 193 ".\\parser.y"
                                       { Print("- R: unionOrIntersectionOrPrimaryType -> type"); }
#line 2885 "parser.tab.c"
    break;

  case 35: /* type: '|' unionOrIntersectionOrPrimaryType  */
#line 194 ".\\parser.y"
                                           { Print("- R: '|' unionOrIntersectionOrPrimaryType -> type"); }
#line 2891 "parser.tab.c"
    break;

  case 36: /* type: '&' unionOrIntersectionOrPrimaryType  */
#line 195 ".\\parser.y"
                                           { Print("- R: '&' unionOrIntersectionOrPrimaryType -> type"); }
#line 2897 "parser.tab.c"
    break;

  case 37: /* unionOrIntersectionOrPrimaryType: unionOrIntersectionOrPrimaryType '|' unionOrIntersectionOrPrimaryType  */
#line 199 ".\\parser.y"
                                                                            { Print("- R: unionOrIntersectionOrPrimaryType '|' unionOrIntersectionOrPrimaryType -> unionOrIntersectionOrPrimaryType"); }
#line 2903 "parser.tab.c"
    break;

  case 38: /* unionOrIntersectionOrPrimaryType: unionOrIntersectionOrPrimaryType '&' unionOrIntersectionOrPrimaryType  */
#line 200 ".\\parser.y"
                                                                            { Print("- R: unionOrIntersectionOrPrimaryType '&' unionOrIntersectionOrPrimaryType -> unionOrIntersectionOrPrimaryType"); }
#line 2909 "parser.tab.c"
    break;

  case 39: /* unionOrIntersectionOrPrimaryType: primaryType  */
#line 201 ".\\parser.y"
                  { Print("- R: primaryType -> argument"); }
#line 2915 "parser.tab.c"
    break;

  case 40: /* primaryType: '(' type ')'  */
#line 205 ".\\parser.y"
                   { Print("- R: '(' type ')' -> primaryType"); }
#line 2921 "parser.tab.c"
    break;

  case 41: /* primaryType: predefinedType  */
#line 206 ".\\parser.y"
                     { Print("- R: predefinedType -> primaryType"); }
#line 2927 "parser.tab.c"
    break;

  case 42: /* primaryType: primaryType '[' ']'  */
#line 207 ".\\parser.y"
                          { Print("- R: primaryType '[' ']' -> primaryType"); }
#line 2933 "parser.tab.c"
    break;

  case 43: /* primaryType: primaryType '[' primaryType ']'  */
#line 208 ".\\parser.y"
                                      { Print("- R: primaryType '[' primaryType ']' -> primaryType"); }
#line 2939 "parser.tab.c"
    break;

  case 44: /* primaryType: '[' tupleTypeElements ']'  */
#line 209 ".\\parser.y"
                                { Print("- R: '[' tupleTypeElements ']' -> primaryType"); }
#line 2945 "parser.tab.c"
    break;

  case 45: /* primaryType: ENDL_BRACKET_OPEN tupleTypeElements ']'  */
#line 210 ".\\parser.y"
                                              { Print("- R: '[' tupleTypeElements ']' -> primaryType"); }
#line 2951 "parser.tab.c"
    break;

  case 46: /* tupleTypeElements: %empty  */
#line 214 ".\\parser.y"
                  { Print("- R: #empty# -> tupleTypeElements"); }
#line 2957 "parser.tab.c"
    break;

  case 47: /* tupleTypeElements: type  */
#line 215 ".\\parser.y"
           { Print("- R: type -> tupleTypeElements"); }
#line 2963 "parser.tab.c"
    break;

  case 48: /* tupleTypeElements: tupleTypeElements ',' type  */
#line 216 ".\\parser.y"
                                 { Print("- R: tupleTypeElements ',' type -> tupleTypeElements"); }
#line 2969 "parser.tab.c"
    break;

  case 49: /* predefinedType: ANY  */
#line 220 ".\\parser.y"
          { Print("- R: ANY -> predefinedType"); }
#line 2975 "parser.tab.c"
    break;

  case 50: /* predefinedType: NUMBER  */
#line 221 ".\\parser.y"
             { Print("- R: NUMBER -> predefinedType"); }
#line 2981 "parser.tab.c"
    break;

  case 51: /* predefinedType: STRING  */
#line 222 ".\\parser.y"
             { Print("- R: STRING -> predefinedType"); }
#line 2987 "parser.tab.c"
    break;

  case 52: /* predefinedType: BOOLEAN  */
#line 223 ".\\parser.y"
              { Print("- R: BOOLEAN -> predefinedType"); }
#line 2993 "parser.tab.c"
    break;

  case 53: /* predefinedType: NEVER  */
#line 224 ".\\parser.y"
            { Print("- R: NEVER -> predefinedType"); }
#line 2999 "parser.tab.c"
    break;

  case 54: /* predefinedType: UNKNOWN  */
#line 225 ".\\parser.y"
              { Print("- R: UNKNOWN -> predefinedType"); }
#line 3005 "parser.tab.c"
    break;

  case 55: /* predefinedType: UNDEFINED  */
#line 226 ".\\parser.y"
                { Print("- R: UNDEFINED -> predefinedType"); }
#line 3011 "parser.tab.c"
    break;

  case 56: /* predefinedType: VOID  */
#line 227 ".\\parser.y"
           { Print("- R: VOID -> predefinedType"); }
#line 3017 "parser.tab.c"
    break;

  case 57: /* predefinedType: NULL_KW  */
#line 228 ".\\parser.y"
              { Print("- R: NULL_KW -> predefinedType"); }
#line 3023 "parser.tab.c"
    break;

  case 58: /* predefinedType: TRUE_KW  */
#line 229 ".\\parser.y"
              { Print("- R: TRUE_WD -> predefinedType"); }
#line 3029 "parser.tab.c"
    break;

  case 59: /* predefinedType: FALSE_KW  */
#line 230 ".\\parser.y"
               { Print("- R: FALSE_KW -> predefinedType"); }
#line 3035 "parser.tab.c"
    break;

  case 60: /* predefinedType: simpleLiteral  */
#line 231 ".\\parser.y"
                    { Print("- R: simpleLiteral -> predefinedType"); }
#line 3041 "parser.tab.c"
    break;

  case 61: /* typeAnnotation: ':' type  */
#line 235 ".\\parser.y"
               { Print("- R: ':' type -> typeAnnotation"); }
#line 3047 "parser.tab.c"
    break;

  case 62: /* simpleLiteral: STRING_LIT  */
#line 239 ".\\parser.y"
                 { Print("- R: STRING_LIT -> simpleLiteral"); }
#line 3053 "parser.tab.c"
    break;

  case 63: /* simpleLiteral: INT_LIT  */
#line 240 ".\\parser.y"
              { Print("- R: INT_LIT -> simpleLiteral"); }
#line 3059 "parser.tab.c"
    break;

  case 64: /* simpleLiteral: FLOAT_LIT  */
#line 241 ".\\parser.y"
                { Print("- R: FLOAT_LIT -> simpleLiteral"); }
#line 3065 "parser.tab.c"
    break;

  case 65: /* simpleLiteral: TEMPLATE_LITERAL  */
#line 242 ".\\parser.y"
                       { Print("- R: TEMPLATE_LITERAL -> simpleLiteral"); }
#line 3071 "parser.tab.c"
    break;

  case 66: /* arrayLiteral: '[' elementList ']'  */
#line 247 ".\\parser.y"
                          { Print("- R: [ elementList ']' -> arrayLiteral"); }
#line 3077 "parser.tab.c"
    break;

  case 67: /* arrayLiteral: ENDL_BRACKET_OPEN elementList ']'  */
#line 248 ".\\parser.y"
                                        { Print("- R: ENDL_BRACKET_OPEN elementList ']' -> arrayLiteral"); }
#line 3083 "parser.tab.c"
    break;

  case 68: /* elementList: %empty  */
#line 252 ".\\parser.y"
                  { Print("- R: #empty# -> elementList"); }
#line 3089 "parser.tab.c"
    break;

  case 69: /* elementList: arrayElement  */
#line 253 ".\\parser.y"
                   { Print("- R: arrayElement -> elementList"); }
#line 3095 "parser.tab.c"
    break;

  case 70: /* elementList: elementList ',' elementList  */
#line 254 ".\\parser.y"
                                  { Print("- R: elementList ',' elementList -> elementList"); }
#line 3101 "parser.tab.c"
    break;

  case 71: /* arrayElement: singleExpression  */
#line 258 ".\\parser.y"
                       { Print("- R: singleExpression -> arrayElement"); }
#line 3107 "parser.tab.c"
    break;

  case 72: /* arrayElement: ELLIPSIS singleExpression  */
#line 259 ".\\parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> arrayElement"); }
#line 3113 "parser.tab.c"
    break;

  case 73: /* expressionStatement: expressionList ';'  */
#line 265 ".\\parser.y"
                         { Print("- R: expressionList ';' -> expressionStatement"); }
#line 3119 "parser.tab.c"
    break;

  case 74: /* expressionListOpt: %empty  */
#line 271 ".\\parser.y"
                  { Print("- R: #empty# -> expressionListOpt"); }
#line 3125 "parser.tab.c"
    break;

  case 75: /* expressionListOpt: expressionList  */
#line 272 ".\\parser.y"
                     { Print("- R: expressionList -> expressionListOpt"); }
#line 3131 "parser.tab.c"
    break;

  case 76: /* expressionList: singleExpression  */
#line 276 ".\\parser.y"
                       { Print("- R: singleExpression -> expressionList"); }
#line 3137 "parser.tab.c"
    break;

  case 77: /* expressionList: expressionList ',' singleExpression  */
#line 277 ".\\parser.y"
                                          { Print("- R: expressionList ',' singleExpression -> expressionList"); }
#line 3143 "parser.tab.c"
    break;

  case 80: /* singleExpression: identifier  */
#line 284 ".\\parser.y"
                 { Print("- R: identifier -> singleExpression"); }
#line 3149 "parser.tab.c"
    break;

  case 81: /* singleExpression: simpleLiteral  */
#line 285 ".\\parser.y"
                    { Print("- R: simpleLiteral -> singleExpression"); }
#line 3155 "parser.tab.c"
    break;

  case 82: /* singleExpression: THIS  */
#line 286 ".\\parser.y"
           { Print("- R: THIS -> singleExpression"); }
#line 3161 "parser.tab.c"
    break;

  case 83: /* singleExpression: SUPER  */
#line 287 ".\\parser.y"
            { Print("- R: SUPER -> singleExpression"); }
#line 3167 "parser.tab.c"
    break;

  case 84: /* singleExpression: TRUE_KW  */
#line 288 ".\\parser.y"
              { Print("- R: TRUE_LITERAL -> singleExpression"); }
#line 3173 "parser.tab.c"
    break;

  case 85: /* singleExpression: FALSE_KW  */
#line 289 ".\\parser.y"
               { Print("- R: FALSE_LITERAL -> singleExpression"); }
#line 3179 "parser.tab.c"
    break;

  case 86: /* singleExpression: NULL_KW  */
#line 290 ".\\parser.y"
              { Print("- R: NULL_LITERAL -> singleExpression"); }
#line 3185 "parser.tab.c"
    break;

  case 87: /* singleExpression: '-' singleExpression  */
#line 291 ".\\parser.y"
                                        { Print("- R: '-' singleExpression -> singleExpression"); }
#line 3191 "parser.tab.c"
    break;

  case 88: /* singleExpression: '+' singleExpression  */
#line 292 ".\\parser.y"
                                       { Print("- R: '+' singleExpression -> singleExpression"); }
#line 3197 "parser.tab.c"
    break;

  case 89: /* singleExpression: '!' singleExpression  */
#line 293 ".\\parser.y"
                           { Print("- R: '!' singleExpression -> singleExpression"); }
#line 3203 "parser.tab.c"
    break;

  case 90: /* singleExpression: '~' singleExpression  */
#line 294 ".\\parser.y"
                           { Print("- R: '~' singleExpression -> singleExpression"); }
#line 3209 "parser.tab.c"
    break;

  case 91: /* singleExpression: singleExpression OPERATOR_INCREMENT  */
#line 295 ".\\parser.y"
                                                               { Print("- R: singleExpression OPERATOR_INCREMENT -> singleExpression"); }
#line 3215 "parser.tab.c"
    break;

  case 92: /* singleExpression: singleExpression OPERATOR_DECREMENT  */
#line 296 ".\\parser.y"
                                                               { Print("- R: singleExpression OPERATOR_DECREMENT -> singleExpression"); }
#line 3221 "parser.tab.c"
    break;

  case 93: /* singleExpression: ENDL_OPERATOR_INCREMENT singleExpression  */
#line 297 ".\\parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 3227 "parser.tab.c"
    break;

  case 94: /* singleExpression: ENDL_OPERATOR_DECREMENT singleExpression  */
#line 298 ".\\parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 3233 "parser.tab.c"
    break;

  case 95: /* singleExpression: OPERATOR_INCREMENT singleExpression  */
#line 299 ".\\parser.y"
                                                               { Print("- R: OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 3239 "parser.tab.c"
    break;

  case 96: /* singleExpression: OPERATOR_DECREMENT singleExpression  */
#line 300 ".\\parser.y"
                                                               { Print("- R: OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 3245 "parser.tab.c"
    break;

  case 97: /* singleExpression: singleExpression '+' singleExpression  */
#line 301 ".\\parser.y"
                                            { Print("- R: singleExpression '+' singleExpression -> singleExpression"); }
#line 3251 "parser.tab.c"
    break;

  case 98: /* singleExpression: singleExpression '-' singleExpression  */
#line 302 ".\\parser.y"
                                            { Print("- R: singleExpression '-' singleExpression -> singleExpression"); }
#line 3257 "parser.tab.c"
    break;

  case 99: /* singleExpression: singleExpression '*' singleExpression  */
#line 303 ".\\parser.y"
                                            { Print("- R: singleExpression '*' singleExpression -> singleExpression"); }
#line 3263 "parser.tab.c"
    break;

  case 100: /* singleExpression: singleExpression '/' singleExpression  */
#line 304 ".\\parser.y"
                                            { Print("- R: singleExpression '/' singleExpression -> singleExpression"); }
#line 3269 "parser.tab.c"
    break;

  case 101: /* singleExpression: singleExpression '%' singleExpression  */
#line 305 ".\\parser.y"
                                            { Print("- R: singleExpression '%' singleExpression -> singleExpression"); }
#line 3275 "parser.tab.c"
    break;

  case 102: /* singleExpression: singleExpression '<' singleExpression  */
#line 306 ".\\parser.y"
                                            { Print("- R: singleExpression '<' singleExpression -> singleExpression"); }
#line 3281 "parser.tab.c"
    break;

  case 103: /* singleExpression: singleExpression '>' singleExpression  */
#line 307 ".\\parser.y"
                                            { Print("- R: singleExpression '>' singleExpression -> singleExpression"); }
#line 3287 "parser.tab.c"
    break;

  case 104: /* singleExpression: singleExpression OPERATOR_POWER singleExpression  */
#line 308 ".\\parser.y"
                                                       { Print("- R: singleExpression OPERATOR_POWER singleExpression -> singleExpression"); }
#line 3293 "parser.tab.c"
    break;

  case 105: /* singleExpression: singleExpression OPERATOR_EQUAL singleExpression  */
#line 309 ".\\parser.y"
                                                       { Print("- R: singleExpression OPERATOR_EQUAL singleExpression -> singleExpression"); }
#line 3299 "parser.tab.c"
    break;

  case 106: /* singleExpression: singleExpression OPERATOR_NOT_EQUAL singleExpression  */
#line 310 ".\\parser.y"
                                                           { Print("- R: singleExpression OPERATOR_NOT_EQUAL singleExpression -> singleExpression"); }
#line 3305 "parser.tab.c"
    break;

  case 107: /* singleExpression: singleExpression OPERATOR_STRICT_EQUAL singleExpression  */
#line 311 ".\\parser.y"
                                                              { Print("- R: singleExpression OPERATOR_STRICT_EQUAL singleExpression -> singleExpression"); }
#line 3311 "parser.tab.c"
    break;

  case 108: /* singleExpression: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression  */
#line 312 ".\\parser.y"
                                                                  { Print("- R: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression -> singleExpression"); }
#line 3317 "parser.tab.c"
    break;

  case 109: /* singleExpression: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression  */
#line 313 ".\\parser.y"
                                                                 { Print("- R: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression -> singleExpression"); }
#line 3323 "parser.tab.c"
    break;

  case 110: /* singleExpression: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression  */
#line 314 ".\\parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression -> singleExpression"); }
#line 3329 "parser.tab.c"
    break;

  case 111: /* singleExpression: singleExpression '=' singleExpression  */
#line 315 ".\\parser.y"
                                            { Print("- R: singleExpression '=' singleExpression -> singleExpression"); }
#line 3335 "parser.tab.c"
    break;

  case 112: /* singleExpression: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression  */
#line 316 ".\\parser.y"
                                                                 { Print("- R: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression -> singleExpression"); }
#line 3341 "parser.tab.c"
    break;

  case 113: /* singleExpression: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression  */
#line 317 ".\\parser.y"
                                                               { Print("- R: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression -> singleExpression"); }
#line 3347 "parser.tab.c"
    break;

  case 114: /* singleExpression: singleExpression OPERATOR_ASSIGN_MOD singleExpression  */
#line 318 ".\\parser.y"
                                                            { Print("- R: singleExpression OPERATOR_ASSIGN_MOD singleExpression -> singleExpression"); }
#line 3353 "parser.tab.c"
    break;

  case 115: /* singleExpression: singleExpression OPERATOR_ASSIGN_PLUS singleExpression  */
#line 319 ".\\parser.y"
                                                             { Print("- R: singleExpression OPERATOR_ASSIGN_PLUS singleExpression -> singleExpression"); }
#line 3359 "parser.tab.c"
    break;

  case 116: /* singleExpression: singleExpression OPERATOR_ASSIGN_MINUS singleExpression  */
#line 320 ".\\parser.y"
                                                              { Print("- R: singleExpression OPERATOR_ASSIGN_MINUS singleExpression -> singleExpression"); }
#line 3365 "parser.tab.c"
    break;

  case 117: /* singleExpression: singleExpression OPERATOR_ASSIGN_SHIFT_LEFT singleExpression  */
#line 321 ".\\parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_SHIFT_LEFT singleExpression -> singleExpression"); }
#line 3371 "parser.tab.c"
    break;

  case 118: /* singleExpression: singleExpression OPERATOR_ASSIGN_SHIFT_RIGHT singleExpression  */
#line 322 ".\\parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3377 "parser.tab.c"
    break;

  case 119: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_AND singleExpression  */
#line 323 ".\\parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_AND singleExpression -> singleExpression"); }
#line 3383 "parser.tab.c"
    break;

  case 120: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_XOR singleExpression  */
#line 324 ".\\parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_XOR singleExpression -> singleExpression"); }
#line 3389 "parser.tab.c"
    break;

  case 121: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_OR singleExpression  */
#line 325 ".\\parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_OR singleExpression -> singleExpression"); }
#line 3395 "parser.tab.c"
    break;

  case 122: /* singleExpression: singleExpression OPERATOR_ASSIGN_POWER singleExpression  */
#line 326 ".\\parser.y"
                                                              { Print("- R: singleExpression OPERATOR_ASSIGN_POWER singleExpression -> singleExpression"); }
#line 3401 "parser.tab.c"
    break;

  case 123: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression  */
#line 327 ".\\parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression -> singleExpression"); }
#line 3407 "parser.tab.c"
    break;

  case 124: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression  */
#line 328 ".\\parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression -> singleExpression"); }
#line 3413 "parser.tab.c"
    break;

  case 125: /* singleExpression: singleExpression OPERATOR_ASSIGN_NULLISH_COALESCING singleExpression  */
#line 329 ".\\parser.y"
                                                                           { Print("- R: singleExpression OPERATOR_ASSIGN_NULLISH_COALESCING singleExpression -> singleExpression"); }
#line 3419 "parser.tab.c"
    break;

  case 126: /* singleExpression: singleExpression OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT singleExpression  */
#line 330 ".\\parser.y"
                                                                             { Print("- R: singleExpression OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3425 "parser.tab.c"
    break;

  case 127: /* singleExpression: singleExpression OPERATOR_LOGICAL_OR singleExpression  */
#line 331 ".\\parser.y"
                                                            { Print("- R: singleExpression OPERATOR_LOGICAL_OR singleExpression -> singleExpression"); }
#line 3431 "parser.tab.c"
    break;

  case 128: /* singleExpression: singleExpression OPERATOR_LOGICAL_AND singleExpression  */
#line 332 ".\\parser.y"
                                                             { Print("- R: singleExpression OPERATOR_LOGICAL_AND singleExpression -> singleExpression"); }
#line 3437 "parser.tab.c"
    break;

  case 129: /* singleExpression: singleExpression '|' singleExpression  */
#line 333 ".\\parser.y"
                                            { Print("- R: singleExpression '|' singleExpression -> singleExpression"); }
#line 3443 "parser.tab.c"
    break;

  case 130: /* singleExpression: singleExpression '^' singleExpression  */
#line 334 ".\\parser.y"
                                            { Print("- R: singleExpression '^' singleExpression -> singleExpression"); }
#line 3449 "parser.tab.c"
    break;

  case 131: /* singleExpression: singleExpression '&' singleExpression  */
#line 335 ".\\parser.y"
                                            { Print("- R: singleExpression '&' singleExpression -> singleExpression"); }
#line 3455 "parser.tab.c"
    break;

  case 132: /* singleExpression: singleExpression OPERATOR_SHIFT_LEFT singleExpression  */
#line 336 ".\\parser.y"
                                                            { Print("- R: singleExpression OPERATOR_SHIFT_LEFT singleExpression -> singleExpression"); }
#line 3461 "parser.tab.c"
    break;

  case 133: /* singleExpression: singleExpression OPERATOR_SHIFT_RIGHT singleExpression  */
#line 337 ".\\parser.y"
                                                             { Print("- R: singleExpression OPERATOR_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3467 "parser.tab.c"
    break;

  case 134: /* singleExpression: singleExpression OPERATOR_UNSIGNED_SHIFT_RIGHT singleExpression  */
#line 338 ".\\parser.y"
                                                                      { Print("- R: singleExpression OPERATOR_UNSIGNED_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3473 "parser.tab.c"
    break;

  case 135: /* singleExpression: singleExpression OPERATOR_NULLISH_COALESCING singleExpression  */
#line 339 ".\\parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_NULLISH_COALESCING singleExpression -> singleExpression"); }
#line 3479 "parser.tab.c"
    break;

  case 136: /* singleExpression: singleExpression INSTANCEOF singleExpression  */
#line 341 ".\\parser.y"
                                                   { Print("- R: singleExpression INSTANCEOF singleExpression -> singleExpression"); }
#line 3485 "parser.tab.c"
    break;

  case 137: /* singleExpression: singleExpression IN singleExpression  */
#line 342 ".\\parser.y"
                                           { Print("- R: singleExpression IN singleExpression -> singleExpression"); }
#line 3491 "parser.tab.c"
    break;

  case 138: /* singleExpression: singleExpression TEMPLATE_LITERAL  */
#line 344 ".\\parser.y"
                                        { Print("- R: singleExpression TEMPLATE_LITERAL -> singleExpression"); }
#line 3497 "parser.tab.c"
    break;

  case 139: /* singleExpression: singleExpression '?' singleExpression ':' singleExpression  */
#line 345 ".\\parser.y"
                                                                 { Print("- R: singleExpression '?' singleExpression ':' singleExpression -> singleExpression"); }
#line 3503 "parser.tab.c"
    break;

  case 140: /* singleExpression: '(' expressionList ')'  */
#line 347 ".\\parser.y"
                             { Print("- R: '(' expressionList ')' -> singleExpression"); }
#line 3509 "parser.tab.c"
    break;

  case 141: /* singleExpression: singleExpression arguments  */
#line 349 ".\\parser.y"
                                 { Print("- R: singleExpression arguments -> singleExpression"); }
#line 3515 "parser.tab.c"
    break;

  case 142: /* singleExpression: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression  */
#line 351 ".\\parser.y"
                                                                   { Print("- R: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression -> singleExpression"); }
#line 3521 "parser.tab.c"
    break;

  case 143: /* singleExpression: singleExpression '.' identifier  */
#line 352 ".\\parser.y"
                                      { Print("- R: singleExpression '.' identifier -> singleExpression"); }
#line 3527 "parser.tab.c"
    break;

  case 144: /* singleExpression: arrayLiteral  */
#line 354 ".\\parser.y"
                   { Print("- R: arrayLiteral -> singleExpression"); }
#line 3533 "parser.tab.c"
    break;

  case 145: /* singleExpression: singleExpression '[' expressionList ']'  */
#line 355 ".\\parser.y"
                                              { Print("- R: singleExpression '[' expressionList ']' -> singleExpression"); }
#line 3539 "parser.tab.c"
    break;

  case 146: /* singleExpression: singleExpression ENDL_BRACKET_OPEN expressionList ']'  */
#line 356 ".\\parser.y"
                                                            { Print("- R: singleExpression ENDL_BRACKET_OPEN singleExpression ']' -> singleExpression"); }
#line 3545 "parser.tab.c"
    break;

  case 147: /* singleExpression: NEW singleExpression  */
#line 358 ".\\parser.y"
                           { Print("- R: NEW singleExpression -> singleExpression"); }
#line 3551 "parser.tab.c"
    break;

  case 148: /* arguments: '(' ')'  */
#line 362 ".\\parser.y"
              { Print("- R: '(' ')' -> arguments"); }
#line 3557 "parser.tab.c"
    break;

  case 149: /* arguments: '(' argumentList ')'  */
#line 363 ".\\parser.y"
                           { Print("- R: '(' argumentList ')' -> arguments"); }
#line 3563 "parser.tab.c"
    break;

  case 150: /* arguments: '(' argumentList ',' ')'  */
#line 364 ".\\parser.y"
                               { Print("- R: '(' argumentList ',' ') -> arguments"); }
#line 3569 "parser.tab.c"
    break;

  case 151: /* argumentList: argument  */
#line 368 ".\\parser.y"
               { Print("- R: argument -> argumentList"); }
#line 3575 "parser.tab.c"
    break;

  case 152: /* argumentList: argumentList ',' arguments  */
#line 369 ".\\parser.y"
                                 { Print("- R: argumentList ',' arguments -> argumentList"); }
#line 3581 "parser.tab.c"
    break;

  case 153: /* argument: singleExpression  */
#line 373 ".\\parser.y"
                       { Print("- R: singleExpression -> argument"); }
#line 3587 "parser.tab.c"
    break;

  case 154: /* argument: ELLIPSIS singleExpression  */
#line 374 ".\\parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> argument"); }
#line 3593 "parser.tab.c"
    break;

  case 155: /* varStatement: varModifier varDeclarationList ';'  */
#line 380 ".\\parser.y"
                                         { Print("- R: varModifier varDeclarationList ';' -> varStatement"); }
#line 3599 "parser.tab.c"
    break;

  case 156: /* varDeclarationList: varDeclaration  */
#line 387 ".\\parser.y"
                     { Print("- R: varDeclaration -> argument"); }
#line 3605 "parser.tab.c"
    break;

  case 157: /* varDeclarationList: varDeclarationList ',' varDeclaration  */
#line 388 ".\\parser.y"
                                            { Print("- R: varDeclarationList ',' varDeclaration -> varDeclarationList"); }
#line 3611 "parser.tab.c"
    break;

  case 158: /* varDeclaration: identifier  */
#line 392 ".\\parser.y"
                 { Print("- R: identifier -> varDeclaration"); }
#line 3617 "parser.tab.c"
    break;

  case 159: /* varDeclaration: identifier typeAnnotation  */
#line 393 ".\\parser.y"
                                { Print("- R: identifier typeAnnotation -> varDeclaration"); }
#line 3623 "parser.tab.c"
    break;

  case 160: /* varDeclaration: identifier '=' singleExpression  */
#line 394 ".\\parser.y"
                                      { Print("- R: identifier '=' singleExpression -> varDeclaration"); }
#line 3629 "parser.tab.c"
    break;

  case 161: /* varDeclaration: identifier typeAnnotation '=' singleExpression  */
#line 395 ".\\parser.y"
                                                     { Print("- R: identifier typeAnnotation '=' singleExpression -> varDeclaration"); }
#line 3635 "parser.tab.c"
    break;

  case 162: /* varModifier: VAR  */
#line 399 ".\\parser.y"
          { Print("- R: VAR -> varModifier"); }
#line 3641 "parser.tab.c"
    break;

  case 163: /* varModifier: LET  */
#line 400 ".\\parser.y"
          { Print("- R: LET -> varModifier"); }
#line 3647 "parser.tab.c"
    break;

  case 164: /* varModifier: CONST  */
#line 401 ".\\parser.y"
            { Print("- R: CONST -> varModifier"); }
#line 3653 "parser.tab.c"
    break;

  case 165: /* ifStatement: IF '(' expressionList ')' statementListItemWithoutEmptyStatement  */
#line 407 ".\\parser.y"
                                                                                          { Print("- R: IF '(' expressionList ')' statementListItem -> ifStatement"); }
#line 3659 "parser.tab.c"
    break;

  case 166: /* ifStatement: IF '(' expressionList ')' statementListItemWithoutEmptyStatement ELSE statementListItem  */
#line 408 ".\\parser.y"
                                                                                              { Print("- R: IF '(' expressionList ')' statementListItem ELSE statementListItem -> ifStatement"); }
#line 3665 "parser.tab.c"
    break;

  case 167: /* $@1: %empty  */
#line 412 ".\\parser.y"
         { isInIterationBody = 1; }
#line 3671 "parser.tab.c"
    break;

  case 168: /* $@2: %empty  */
#line 412 ".\\parser.y"
                                                                                   { doWhileASI(); }
#line 3677 "parser.tab.c"
    break;

  case 169: /* iterationStatement: DO $@1 statementListItem WHILE '(' expressionList ')' $@2 ';'  */
#line 412 ".\\parser.y"
                                                                                                                                   { isInIterationBody = 0; Print("- R: DO statementListItem WHILE '(' expressionList ')' ';' -> iterationStatement"); }
#line 3683 "parser.tab.c"
    break;

  case 170: /* $@3: %empty  */
#line 413 ".\\parser.y"
                                   { isInIterationBody = 1; }
#line 3689 "parser.tab.c"
    break;

  case 171: /* iterationStatement: WHILE '(' expressionList ')' $@3 statementListItem  */
#line 413 ".\\parser.y"
                                                                                                                                            { isInIterationBody = 0; Print("- R: WHILE '(' expressionList ')' statementListItem -> iterationStatement"); }
#line 3695 "parser.tab.c"
    break;

  case 172: /* $@4: %empty  */
#line 414 ".\\parser.y"
                                                                                  { isInForHeader = 0; isInIterationBody = 1; }
#line 3701 "parser.tab.c"
    break;

  case 173: /* iterationStatement: forHeader expressionListOpt ';' expressionListOpt ';' expressionListOpt ')' $@4 statementListItem  */
#line 414 ".\\parser.y"
                                                                                                                                                                 { isInIterationBody = 0; Print("- R: FOR '(' expressionListOpt ';' expressionListOpt ';' expressionListOpt ')' statementListItem -> iterationStatement"); }
#line 3707 "parser.tab.c"
    break;

  case 174: /* $@5: %empty  */
#line 415 ".\\parser.y"
                                                                                               { isInForHeader = 0; isInIterationBody = 1; }
#line 3713 "parser.tab.c"
    break;

  case 175: /* iterationStatement: forHeader varModifier varDeclarationList ';' expressionListOpt ';' expressionListOpt ')' $@5 statementListItem  */
#line 415 ".\\parser.y"
                                                                                                                                                                 { isInIterationBody = 0; Print("- R: FOR '(' varModifier varDeclarationList ';' expressionListOpt ';' expressionListOpt ')' statementListItem -> iterationStatement"); }
#line 3719 "parser.tab.c"
    break;

  case 176: /* $@6: %empty  */
#line 416 ".\\parser.y"
                                                         { isInForHeader = 0; isInIterationBody = 1; }
#line 3725 "parser.tab.c"
    break;

  case 177: /* iterationStatement: forHeader singleExpression IN singleExpression ')' $@6 statementListItem  */
#line 416 ".\\parser.y"
                                                                                                                                                                 { isInIterationBody = 0; Print("- R: FOR '(' singleExpression IN singleExpression ')' statementListItem -> iterationStatement"); }
#line 3731 "parser.tab.c"
    break;

  case 178: /* $@7: %empty  */
#line 417 ".\\parser.y"
                                                                 { isInForHeader = 0; isInIterationBody = 1; }
#line 3737 "parser.tab.c"
    break;

  case 179: /* iterationStatement: forHeader varModifier varDeclaration IN expressionList ')' $@7 statementListItem  */
#line 417 ".\\parser.y"
                                                                                                                                                                 { isInIterationBody = 0; Print("- R: FOR '(' varModifier varDeclaration IN expressionList ')' statementListItem -> iterationStatement"); }
#line 3743 "parser.tab.c"
    break;

  case 180: /* forHeader: FOR '('  */
#line 421 ".\\parser.y"
               { isInForHeader = 1; }
#line 3749 "parser.tab.c"
    break;

  case 181: /* continueStatement: CONTINUE ';'  */
#line 425 ".\\parser.y"
                   { Print("- R: CONTINUE ';' -> returnStatement"); }
#line 3755 "parser.tab.c"
    break;

  case 182: /* continueStatement: CONTINUE identifier ';'  */
#line 426 ".\\parser.y"
                              { Print("- R: CONTINUE identifier ';' -> returnStatement"); }
#line 3761 "parser.tab.c"
    break;

  case 183: /* breakStatement: BREAK ';'  */
#line 430 ".\\parser.y"
                 { Print("- R: BREAK ';' -> returnStatement"); }
#line 3767 "parser.tab.c"
    break;

  case 184: /* breakStatement: BREAK identifier ';'  */
#line 431 ".\\parser.y"
                           { Print("- R: BREAK identifier ';' -> returnStatement"); }
#line 3773 "parser.tab.c"
    break;

  case 185: /* returnStatement: RETURN ';'  */
#line 435 ".\\parser.y"
                 { Print("- R: RETURN ';' -> returnStatement"); }
#line 3779 "parser.tab.c"
    break;

  case 186: /* returnStatement: RETURN singleExpression ';'  */
#line 436 ".\\parser.y"
                                  { Print("- R: RETURN singleExpression ';' -> returnStatement"); }
#line 3785 "parser.tab.c"
    break;

  case 187: /* labelledStatement: identifier ':' statementListItem  */
#line 440 ".\\parser.y"
                                       { Print("- R: identifier ':' statementListItem -> labelledStatement"); }
#line 3791 "parser.tab.c"
    break;

  case 188: /* blockStatement: '{' '}'  */
#line 444 ".\\parser.y"
              { Print("- R: '{' '}' -> blockStatement"); }
#line 3797 "parser.tab.c"
    break;

  case 189: /* blockStatement: '{' statementList '}'  */
#line 445 ".\\parser.y"
                            { Print("- R: '{' statementList '}' -> blockStatement"); }
#line 3803 "parser.tab.c"
    break;

  case 190: /* switchStatement: SWITCH '(' expressionList ')' '{' '}'  */
#line 449 ".\\parser.y"
                                            { Print("- R: SWITCH '(' expressionList ')' '{' '}' -> switchStatement"); }
#line 3809 "parser.tab.c"
    break;

  case 191: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList '}'  */
#line 450 ".\\parser.y"
                                                           { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList '}' -> switchStatement"); }
#line 3815 "parser.tab.c"
    break;

  case 192: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause '}'  */
#line 451 ".\\parser.y"
                                                                         { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause '}' -> switchStatement"); }
#line 3821 "parser.tab.c"
    break;

  case 193: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause caseClauseList '}'  */
#line 452 ".\\parser.y"
                                                                                        { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause caseClauseList '}' -> switchStatement"); }
#line 3827 "parser.tab.c"
    break;

  case 194: /* caseClauseList: caseClause  */
#line 456 ".\\parser.y"
                 { Print("- R: caseClause -> caseClauseList"); }
#line 3833 "parser.tab.c"
    break;

  case 195: /* caseClauseList: caseClauseList caseClause  */
#line 457 ".\\parser.y"
                                { Print("- R: caseClauseList caseClause -> caseClauseList"); }
#line 3839 "parser.tab.c"
    break;

  case 196: /* caseClause: CASE expressionList ':'  */
#line 461 ".\\parser.y"
                              { Print("- R: CASE expressionList ':' -> caseClause"); }
#line 3845 "parser.tab.c"
    break;

  case 197: /* caseClause: CASE expressionList ':' statementList  */
#line 462 ".\\parser.y"
                                            { Print("- R: CASE expressionList ':' statementList -> caseClause"); }
#line 3851 "parser.tab.c"
    break;

  case 198: /* defaultClause: DEFAULT ':'  */
#line 466 ".\\parser.y"
                  { Print("- R: DEFAULT ':' -> defaultClause"); }
#line 3857 "parser.tab.c"
    break;

  case 199: /* defaultClause: DEFAULT ':' statementList  */
#line 467 ".\\parser.y"
                                { Print("- R: DEFAULT ':' statementList -> defaultClause"); }
#line 3863 "parser.tab.c"
    break;

  case 200: /* functionDeclaration: FUNCTION identifier callSignature functionBody  */
#line 473 ".\\parser.y"
                                                     { Print("- R: FUNCTION ID callSignature functionBody -> functionDeclaration"); }
#line 3869 "parser.tab.c"
    break;

  case 201: /* functionBody: '{' '}'  */
#line 477 ".\\parser.y"
              { Print("- R: '{' '}' -> functionBody"); }
#line 3875 "parser.tab.c"
    break;

  case 202: /* $@8: %empty  */
#line 478 ".\\parser.y"
          { isInFunctionBody = 1; }
#line 3881 "parser.tab.c"
    break;

  case 203: /* functionBody: '{' $@8 statementList '}'  */
#line 478 ".\\parser.y"
                                                      { isInFunctionBody = 0; Print("- R: '{' statementList '}' -> functionBody"); }
#line 3887 "parser.tab.c"
    break;

  case 204: /* callSignature: '(' ')'  */
#line 482 ".\\parser.y"
              { Print("- R: '(' ')' -> callSignature"); }
#line 3893 "parser.tab.c"
    break;

  case 205: /* callSignature: '(' ')' typeAnnotation  */
#line 483 ".\\parser.y"
                             { Print("- R: '(' ')' typeAnnotation -> callSignature"); }
#line 3899 "parser.tab.c"
    break;

  case 206: /* callSignature: '(' restParameter ')'  */
#line 484 ".\\parser.y"
                            { Print("- R: '(' restParameter ')' -> callSignature"); }
#line 3905 "parser.tab.c"
    break;

  case 207: /* callSignature: '(' restParameter ')' typeAnnotation  */
#line 485 ".\\parser.y"
                                           { Print("- R: '(' restParameter ')' typeAnnotation -> callSignature"); }
#line 3911 "parser.tab.c"
    break;

  case 208: /* callSignature: '(' parameterList ')'  */
#line 486 ".\\parser.y"
                            { Print("- R: '(' parameterList ')' -> callSignature"); }
#line 3917 "parser.tab.c"
    break;

  case 209: /* callSignature: '(' parameterList ')' typeAnnotation  */
#line 487 ".\\parser.y"
                                           { Print("- R: '(' parameterList ')' typeAnnotation -> callSignature"); }
#line 3923 "parser.tab.c"
    break;

  case 210: /* callSignature: '(' parameterList ',' restParameter ')'  */
#line 488 ".\\parser.y"
                                              { Print("- R: '(' parameterList ',' restParameter ')' -> callSignature"); }
#line 3929 "parser.tab.c"
    break;

  case 211: /* callSignature: '(' parameterList ',' restParameter ')' typeAnnotation  */
#line 489 ".\\parser.y"
                                                             { Print("- R: '(' parameterList ',' restParameter ')' typeAnnotation -> callSignature"); }
#line 3935 "parser.tab.c"
    break;

  case 212: /* callSignature: '(' parameterList ',' ')'  */
#line 490 ".\\parser.y"
                                { Print("- R: '(' parameterList ',' ')' -> callSignature"); }
#line 3941 "parser.tab.c"
    break;

  case 213: /* callSignature: '(' parameterList ',' ')' typeAnnotation  */
#line 491 ".\\parser.y"
                                               { Print("- R: '(' parameterList ',' ')' typeAnnotation -> callSignature"); }
#line 3947 "parser.tab.c"
    break;

  case 214: /* parameterList: parameter  */
#line 495 ".\\parser.y"
                { Print("- R: parameter -> parameterList"); }
#line 3953 "parser.tab.c"
    break;

  case 215: /* parameterList: parameterList ',' parameter  */
#line 496 ".\\parser.y"
                                  { Print("- R: parameterList ',' parameter -> parameterList"); }
#line 3959 "parser.tab.c"
    break;

  case 216: /* parameter: requiredParameter  */
#line 500 ".\\parser.y"
                        { Print("- R: requiredParameter -> parameter"); }
#line 3965 "parser.tab.c"
    break;

  case 217: /* parameter: optionalParameter  */
#line 501 ".\\parser.y"
                        { Print("- R: optionalParameter -> parameter"); }
#line 3971 "parser.tab.c"
    break;

  case 218: /* requiredParameter: identifier  */
#line 505 ".\\parser.y"
                 { Print("- R: ID -> requiredParameter"); }
#line 3977 "parser.tab.c"
    break;

  case 219: /* requiredParameter: identifier typeAnnotation  */
#line 506 ".\\parser.y"
                                { Print("- R: ID typeAnnotation -> requiredParameter"); }
#line 3983 "parser.tab.c"
    break;

  case 220: /* optionalParameter: identifier '?'  */
#line 510 ".\\parser.y"
                     { Print("- R: ID '?' -> optionalParameter"); }
#line 3989 "parser.tab.c"
    break;

  case 221: /* optionalParameter: identifier '?' typeAnnotation  */
#line 511 ".\\parser.y"
                                    { Print("- R: ID '?' typeAnnotation -> optionalParameter"); }
#line 3995 "parser.tab.c"
    break;

  case 222: /* optionalParameter: identifier initializer  */
#line 512 ".\\parser.y"
                             { Print("- R: ID initializer -> optionalParameter"); }
#line 4001 "parser.tab.c"
    break;

  case 223: /* optionalParameter: identifier typeAnnotation initializer  */
#line 513 ".\\parser.y"
                                            { Print("- R: ID typeAnnotation initializer -> optionalParameter"); }
#line 4007 "parser.tab.c"
    break;

  case 224: /* restParameter: ELLIPSIS singleExpression  */
#line 517 ".\\parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> restParameter"); }
#line 4013 "parser.tab.c"
    break;

  case 225: /* restParameter: ELLIPSIS singleExpression typeAnnotation  */
#line 518 ".\\parser.y"
                                               { Print("- R: ELLIPSIS singleExpression typeAnnotation -> restParameter"); }
#line 4019 "parser.tab.c"
    break;

  case 226: /* classDeclaration: CLASS identifier classTail  */
#line 524 ".\\parser.y"
                                 { Print("- R: CLASS identifier classTail -> classDeclaration"); }
#line 4025 "parser.tab.c"
    break;

  case 227: /* classDeclaration: CLASS identifier classHeritage classTail  */
#line 525 ".\\parser.y"
                                               { Print("- R: CLASS identifier classHeritage classTail -> classDeclaration"); }
#line 4031 "parser.tab.c"
    break;

  case 228: /* classHeritage: EXTENDS identifier  */
#line 529 ".\\parser.y"
                         { Print("- R: EXTENDS identifier -> classHeritage"); }
#line 4037 "parser.tab.c"
    break;

  case 229: /* classTail: '{' '}'  */
#line 533 ".\\parser.y"
              { Print("- R: '{' '}' -> classTail"); }
#line 4043 "parser.tab.c"
    break;

  case 230: /* classTail: '{' classElementList '}'  */
#line 534 ".\\parser.y"
                               { Print("- R: '{' classElementList '}' -> classTail"); }
#line 4049 "parser.tab.c"
    break;

  case 232: /* classElementList: classElement  */
#line 540 ".\\parser.y"
                   { Print("- R: classElement -> classElementList"); }
#line 4055 "parser.tab.c"
    break;

  case 233: /* classElementList: classElementList classElement  */
#line 541 ".\\parser.y"
                                    { Print("- R: classElementList classElement -> classElementList"); }
#line 4061 "parser.tab.c"
    break;

  case 234: /* classElement: CONSTRUCTOR constructorCallSignature functionBody  */
#line 545 ".\\parser.y"
                                                        { Print("- R: CONSTRUCTOR callSignature functionBody -> classElement"); }
#line 4067 "parser.tab.c"
    break;

  case 235: /* classElement: propertyName ';'  */
#line 548 ".\\parser.y"
                       { Print("- R: propertyName ';' -> classElement"); }
#line 4073 "parser.tab.c"
    break;

  case 236: /* classElement: propertyName typeAnnotation ';'  */
#line 549 ".\\parser.y"
                                      { Print("- R: propertyName typeAnnotation ';' -> classElement"); }
#line 4079 "parser.tab.c"
    break;

  case 237: /* classElement: propertyName initializer ';'  */
#line 550 ".\\parser.y"
                                   { Print("- R: propertyName initializer ';' -> classElement"); }
#line 4085 "parser.tab.c"
    break;

  case 238: /* classElement: propertyName typeAnnotation initializer ';'  */
#line 551 ".\\parser.y"
                                                  { Print("- R: propertyName typeAnnotation initializer ';' -> classElement"); }
#line 4091 "parser.tab.c"
    break;

  case 239: /* classElement: propertyName callSignature functionBody  */
#line 554 ".\\parser.y"
                                              { Print("- R: propertyName callSignature functionBody -> classElement"); }
#line 4097 "parser.tab.c"
    break;

  case 240: /* classElement: GET propertyName '(' ')' functionBody  */
#line 557 ".\\parser.y"
                                            { Print("- R: GET propertyName '(' ')' functionBody -> classElement"); }
#line 4103 "parser.tab.c"
    break;

  case 241: /* classElement: GET propertyName '(' ')' typeAnnotation functionBody  */
#line 558 ".\\parser.y"
                                                           { Print("- R: GET propertyName '(' ')' typeAnnotation functionBody -> classElement"); }
#line 4109 "parser.tab.c"
    break;

  case 242: /* classElement: SET propertyName callSignature functionBody  */
#line 559 ".\\parser.y"
                                                  { Print("- R: SET propertyName callSignature functionBody -> classElement"); }
#line 4115 "parser.tab.c"
    break;

  case 243: /* constructorCallSignature: '(' ')'  */
#line 563 ".\\parser.y"
              { Print("- R: '(' ')' -> constructorCallSignature"); }
#line 4121 "parser.tab.c"
    break;

  case 244: /* constructorCallSignature: '(' restParameter ')'  */
#line 564 ".\\parser.y"
                            { Print("- R: '(' restParameter ')' -> constructorCallSignature"); }
#line 4127 "parser.tab.c"
    break;

  case 245: /* constructorCallSignature: '(' parameterList ')'  */
#line 565 ".\\parser.y"
                            { Print("- R: '(' parameterList ')' -> constructorCallSignature"); }
#line 4133 "parser.tab.c"
    break;

  case 246: /* constructorCallSignature: '(' parameterList ',' restParameter ')'  */
#line 566 ".\\parser.y"
                                              { Print("- R: '(' parameterList ',' restParameter ')' -> constructorCallSignature"); }
#line 4139 "parser.tab.c"
    break;

  case 247: /* constructorCallSignature: '(' parameterList ',' ')'  */
#line 567 ".\\parser.y"
                                { Print("- R: '(' parameterList ',' ')' -> constructorCallSignature"); }
#line 4145 "parser.tab.c"
    break;

  case 248: /* propertyName: identifier  */
#line 571 ".\\parser.y"
                 { Print("- R: identifier -> propertyName"); }
#line 4151 "parser.tab.c"
    break;

  case 249: /* propertyName: simpleLiteral  */
#line 572 ".\\parser.y"
                    { Print("- R: STRING_LIT -> propertyName"); }
#line 4157 "parser.tab.c"
    break;

  case 250: /* propertyName: '[' simpleLiteral ']'  */
#line 573 ".\\parser.y"
                            { Print("- R: '[' simpleLiteral ']' -> propertyName"); }
#line 4163 "parser.tab.c"
    break;

  case 251: /* propertyName: ENDL_BRACKET_OPEN simpleLiteral ']'  */
#line 574 ".\\parser.y"
                                          { Print("- R: ENDL_BRACKET_OPEN simpleLiteral ']' -> propertyName"); }
#line 4169 "parser.tab.c"
    break;

  case 252: /* identifier: ID  */
#line 578 ".\\parser.y"
         { Print("- R: ID -> identifier"); }
#line 4175 "parser.tab.c"
    break;

  case 253: /* identifier: ASYNC  */
#line 579 ".\\parser.y"
            { Print("- R: ASYNC -> identifier"); }
#line 4181 "parser.tab.c"
    break;

  case 254: /* identifier: AS  */
#line 580 ".\\parser.y"
         { Print("- R: AS -> identifier"); }
#line 4187 "parser.tab.c"
    break;

  case 255: /* identifier: FROM  */
#line 581 ".\\parser.y"
           { Print("- R: FROM -> identifier"); }
#line 4193 "parser.tab.c"
    break;

  case 256: /* identifier: YIELD  */
#line 582 ".\\parser.y"
            { Print("- R: YIELD -> identifier"); }
#line 4199 "parser.tab.c"
    break;

  case 257: /* identifier: ANY  */
#line 583 ".\\parser.y"
          { Print("- R: ANY -> identifier"); }
#line 4205 "parser.tab.c"
    break;

  case 258: /* identifier: NUMBER  */
#line 584 ".\\parser.y"
             { Print("- R: NUMBER -> identifier"); }
#line 4211 "parser.tab.c"
    break;

  case 259: /* identifier: BOOLEAN  */
#line 585 ".\\parser.y"
              { Print("- R: BOOLEAN -> identifier"); }
#line 4217 "parser.tab.c"
    break;

  case 260: /* identifier: STRING  */
#line 586 ".\\parser.y"
             { Print("- R: STRING -> identifier"); }
#line 4223 "parser.tab.c"
    break;

  case 261: /* identifier: UNIQUE  */
#line 587 ".\\parser.y"
             { Print("- R: UNIQUE -> identifier"); }
#line 4229 "parser.tab.c"
    break;

  case 262: /* identifier: SYMBOL  */
#line 588 ".\\parser.y"
             { Print("- R: SYMBOL -> identifier"); }
#line 4235 "parser.tab.c"
    break;

  case 263: /* identifier: NEVER  */
#line 589 ".\\parser.y"
            { Print("- R: NEVER -> identifier"); }
#line 4241 "parser.tab.c"
    break;

  case 264: /* identifier: UNDEFINED  */
#line 590 ".\\parser.y"
                { Print("- R: UNDEFINED -> identifier"); }
#line 4247 "parser.tab.c"
    break;

  case 265: /* identifier: OBJECT  */
#line 591 ".\\parser.y"
             { Print("- R: OBJECT -> identifier"); }
#line 4253 "parser.tab.c"
    break;

  case 266: /* identifier: KEYOF  */
#line 592 ".\\parser.y"
            { Print("- R: KEYOF -> identifier"); }
#line 4259 "parser.tab.c"
    break;

  case 267: /* identifier: NAMESPACE  */
#line 593 ".\\parser.y"
                { Print("- R: NAMESPACE -> identifier"); }
#line 4265 "parser.tab.c"
    break;

  case 268: /* identifier: ABSTRACT  */
#line 594 ".\\parser.y"
               { Print("- R: ABSTRACT -> identifier"); }
#line 4271 "parser.tab.c"
    break;

  case 269: /* identifier: REQUIRE  */
#line 595 ".\\parser.y"
              { Print("- R: REQUIRE -> identifier"); }
#line 4277 "parser.tab.c"
    break;


#line 4281 "parser.tab.c"

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

#line 598 ".\\parser.y"



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


