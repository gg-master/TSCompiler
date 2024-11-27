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
int noEmptyStatement = 0;

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
#line 35 ".\\parser.y"

    int _integer;
    char* _string;
    char* _id;
    double _floatingPoint;

#line 251 "parser.tab.c"

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
#define YYFINAL  104
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2544

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  123
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  267
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  455

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
       0,    90,    90,   100,   101,   105,   106,   113,   114,   115,
     116,   117,   118,   118,   123,   123,   128,   128,   133,   134,
     135,   136,   140,   141,   142,   143,   144,   145,   146,   146,
     151,   151,   156,   156,   161,   162,   163,   164,   168,   172,
     178,   179,   180,   184,   185,   186,   190,   191,   192,   193,
     194,   198,   199,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   220,   225,   226,
     230,   231,   232,   236,   237,   243,   244,   248,   249,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   313,   314,
     316,   317,   319,   321,   323,   324,   326,   327,   328,   330,
     334,   335,   336,   340,   341,   345,   346,   352,   356,   357,
     361,   362,   363,   364,   368,   369,   370,   376,   377,   381,
     381,   381,   382,   382,   383,   383,   384,   384,   385,   385,
     386,   386,   390,   394,   395,   399,   400,   404,   405,   409,
     413,   414,   418,   419,   420,   421,   425,   426,   430,   431,
     435,   436,   442,   446,   447,   447,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   464,   465,   469,   470,
     474,   475,   479,   480,   481,   482,   486,   487,   493,   494,
     498,   502,   503,   507,   508,   512,   515,   516,   517,   518,
     521,   524,   525,   526,   530,   531,   532,   533,   534,   535,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556
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

#define YYPACT_NINF (-349)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-202)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1545,  -349,  -349,  -349,  -349,   -83,  1699,  1699,  -349,   -60,
     -46,  1699,  1699,   -36,  1944,  -349,  -349,  1944,  -349,  -349,
    -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,
    -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,
    -349,  -349,  -349,  1944,  1944,  1944,  1944,  1944,  1944,  1944,
    1944,  1906,  1906,  1944,  -349,  1057,    62,  1180,  -349,  -349,
     -44,  2305,   -37,  1699,  -349,  -349,  1770,  -349,  -349,  -349,
    -349,  -349,  -349,  -349,  -349,    50,  1944,     4,    -2,  1545,
    1944,  -349,  -349,  -349,  1944,  2305,  -349,    19,    19,    19,
      19,    19,    19,    19,    19,    19,  1944,   -31,  -349,  2305,
     -23,   -33,  -349,  1301,  -349,  -349,  1944,  -349,  -349,  -349,
    -349,  -349,  1944,  1944,  1944,  1944,  1944,  1944,  1944,  1944,
    1944,  1944,  1944,  1944,  1944,  1944,  1944,  1944,  1944,  1944,
    1944,  1944,  1944,  1944,  1944,  1944,  1944,  1944,  1944,  1944,
    1944,  1944,  1944,  1944,  1944,  1944,  1944,  1944,  1944,  1944,
    1944,  1944,  1944,  1944,  1699,  1944,  1944,  1944,  1808,  -349,
    -349,     8,  -349,    69,    10,    88,  2369,  1699,   -37,   -37,
     -37,  1545,   -32,   427,    29,  1699,   188,    30,  -349,   138,
     -22,   -18,  2305,  1906,  -349,  -349,  -349,  -349,  2305,  2426,
    2426,  2426,  2426,  2426,  2426,  2426,  2426,  2426,  2426,  2426,
    2426,  2426,  2426,  2426,  2426,  2049,   914,  1035,  1157,  1277,
    1398,  1519,   511,   511,   511,   511,   183,   183,   183,   183,
     183,   183,   267,   267,   267,   301,   301,   368,   368,   368,
     368,  -349,   -10,    -7,    35,  1944,  -349,  2305,   -17,  -349,
    1699,  1944,   208,    93,  1944,  1944,   -35,    63,  -349,  -349,
    -349,  -349,  1666,  1944,    84,   -15,  -349,  -349,  -349,    45,
     -14,    44,  -349,  -349,   154,   154,     4,  -349,  -349,  -349,
    1944,  1944,  -349,   637,  -349,   -29,  -349,  -349,    47,  -349,
      48,  -349,  1944,  -349,  -349,  2305,   -48,  -349,  -349,  2305,
    -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,
    -349,  -349,  -349,  -349,  1989,  1989,   208,   208,  -349,   -24,
      54,  -349,  1944,    52,    43,  1944,  1944,  -349,   167,   -44,
     -37,  -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,
    -349,  2113,  -349,   739,    84,    84,  1944,    84,  -349,   115,
    -349,  1545,    61,     4,    29,  2177,  2241,  -349,  -349,  -349,
      66,   -13,    29,  1944,  1545,    -1,   793,  -349,  -349,   -24,
     -24,  -349,     5,    85,  1989,  1989,   298,  2305,  1944,  -349,
      86,    -9,  1545,  -349,  -349,   -37,   -37,   -37,  -349,    84,
    -349,    89,  -349,  -349,  2305,  -349,  -349,  1423,    90,    29,
    -349,  -349,  -349,  -349,  -349,    91,  -349,    -5,  -349,  1944,
    -349,    -4,  -349,   208,  -349,  -349,   125,  -349,  -349,   -40,
      95,  1545,  1944,  -349,  -349,  -349,  -349,  -349,  -349,    84,
    -349,   -43,  -349,  -349,  -349,   -19,   133,  -349,  -349,     1,
    -349,  -349,  -349,  -349,   114,  1545,  -349,    29,  -349,   -37,
     539,   813,  -349,     2,  1545,  -349,  -349,  -349,  -349,   691,
     935,  -349,  -349,  1545,  -349
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     5,   164,   165,   166,     0,     0,     0,   169,     0,
       0,   183,   185,     0,   187,    81,    80,     0,   251,   252,
     253,   254,   264,   265,   266,   267,   255,   256,   257,   258,
     261,   262,   259,   260,   263,    84,    82,    83,    88,    86,
      87,   250,    85,     0,     0,     0,     0,     0,     0,     0,
       0,    70,    70,     0,     6,     0,     0,     0,     3,   146,
       0,    77,     0,     0,     9,    11,    75,    12,    14,    16,
      18,    19,    10,    20,    21,    79,     0,     0,     0,     0,
       0,   182,   184,   186,     0,   188,    79,   149,    97,    98,
      95,    96,    90,    89,    91,    92,     0,     0,    71,    73,
       0,     0,   190,     0,     1,     4,     0,    38,     7,   140,
      93,    94,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   143,
       8,   157,   158,   160,     0,    76,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   228,     0,
       0,     0,    74,    70,    68,    69,   142,   191,    78,   113,
     117,   118,   124,   114,   115,   116,   119,   120,   128,   121,
     122,   123,   125,   126,   127,     0,   137,   129,   130,   131,
     132,   133,   107,   108,   109,   110,   105,   104,   112,   111,
     138,   139,   134,   135,   136,    99,   100,   101,   102,   103,
     106,   145,     0,     0,   144,     0,   150,   155,     0,   153,
       0,     0,     0,   161,    75,     0,     0,   158,    13,    15,
      17,   189,     0,     0,   206,     0,   216,   218,   219,     0,
     220,   204,   202,   230,     0,     0,     0,   245,   246,   247,
       0,     0,   231,     0,   233,     0,   244,   229,     0,   172,
       0,    72,     0,   147,   148,   156,     0,   151,   159,   162,
      53,    54,    56,    55,    57,    59,    60,    58,    66,    62,
      63,    61,    64,    65,     0,     0,     0,     0,    67,    40,
      45,    47,     0,     0,   139,    75,     0,    22,   167,     0,
       0,    25,    27,    28,    30,    32,    34,    35,    26,    36,
      37,   226,   207,     0,   210,   208,     0,   222,   224,   221,
     203,     0,     0,     0,     0,     0,     0,   232,   234,   236,
       0,     0,     0,     0,     0,     0,   141,   152,   154,    41,
      42,    51,     0,     0,     0,     0,     0,   163,    75,   178,
       0,     0,     0,    23,    24,     0,     0,     0,   227,   214,
     217,     0,   211,   209,    39,   223,   225,     0,     0,     0,
     235,   248,   249,   238,   237,     0,   240,     0,   173,     0,
     192,     0,   196,     0,    50,    46,    43,    44,    48,     0,
       0,     0,    75,   180,   168,    29,    31,    33,   215,   212,
     205,     0,   243,   239,   170,     0,     0,   193,   197,     0,
      52,    49,   174,   179,     0,     0,   213,     0,   241,     0,
       0,     0,   194,     0,     0,   176,   181,   242,   171,     0,
       0,   195,   175,     0,   177
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -349,  -349,   -51,   -56,  -349,  -349,  -349,  -349,  -349,  -349,
    -349,   -57,  -251,  -297,  -237,  -132,  -349,  -349,  -241,  -349,
     -49,  -349,  -242,   -39,   381,   -47,  -349,  -349,     9,    71,
    -142,   176,    14,    15,  -349,  -349,  -349,  -349,  -349,  -349,
    -349,  -349,    17,    20,    22,    23,    26,    36,  -186,  -348,
    -349,    37,  -312,  -349,  -244,  -349,   -82,  -349,  -349,   -62,
      40,  -349,    73,  -349,    21,  -184,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    56,    57,    58,   168,   169,   170,   318,   375,   376,
     377,   108,   338,   308,   309,   310,   362,   311,   243,    59,
      97,    98,   164,    60,    61,   159,   238,   239,    62,   161,
     162,    63,    64,    65,    79,   439,   354,   444,   453,   411,
     435,    66,    67,    68,    69,    70,    71,    72,   401,   402,
     429,    73,   262,   341,   174,   255,   256,   257,   258,   259,
      74,   177,   178,   273,   274,   275,    86
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      75,   105,   313,   100,   103,   160,    77,    78,   175,   361,
     363,    82,    83,   332,   101,   399,   426,   106,   399,   339,
     399,   399,   344,   179,   350,   247,   240,   165,   106,   106,
     183,   352,   390,   336,   351,    76,   242,   172,   183,   106,
     396,   180,   106,   106,   286,   181,   333,   105,   336,   336,
     242,   106,   106,   428,   106,    75,   106,    75,    80,   364,
     440,   365,   104,   163,   337,   242,   403,   359,   360,   240,
     158,   357,    81,   370,   366,   431,   107,   422,   261,    75,
     342,   343,    84,   107,   184,   315,   186,   252,   386,   173,
     378,   349,   185,   382,   383,   428,   385,   279,   288,   389,
     395,   280,   287,    75,   334,   283,   430,   394,   284,   438,
     413,   248,   249,   250,   424,   251,   232,   233,   427,   176,
     404,   400,   173,   442,   451,   447,   410,   406,   407,   171,
     244,   241,   154,   155,   281,   156,   157,   158,   418,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   242,   106,
     261,   176,   278,   158,   231,   312,   154,   155,   316,   156,
     157,   158,   369,   242,   335,   353,   340,   163,   366,   355,
     434,    75,   368,   260,   372,   263,   276,   336,   436,   388,
     437,    18,    19,    20,    21,    22,   393,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,   264,
     265,   267,   268,   269,   405,   165,   412,    41,   419,   421,
     365,   423,   441,   319,   432,    18,    19,    20,    21,    22,
     266,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,   445,   409,   267,   268,   269,   246,   358,
     163,    41,   167,   443,   290,   291,   292,   293,   294,   295,
     277,   380,    75,   296,   297,   298,   299,   300,   301,   302,
     303,   320,   373,   374,   276,   276,   321,   322,   270,   323,
     271,   381,   324,   276,   325,   326,   165,   371,   327,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   328,   329,
     387,   304,   330,   305,   348,     0,   154,   155,   398,   156,
     157,   158,   270,     0,   271,     0,     0,     0,     0,     0,
     272,     0,     0,     0,   397,     0,   414,     0,   415,   416,
     417,     0,   306,     0,     0,     0,   307,     0,     0,   165,
       0,   105,     0,   260,   290,   291,   292,   293,   294,   295,
       0,    75,     0,   296,   297,   298,   299,   300,   301,   302,
     303,     0,     0,     0,    75,   433,     0,     0,     0,     0,
     425,     0,     0,     0,     0,     0,   148,   149,   150,   151,
     152,   153,    75,   165,     0,     0,     0,     0,     0,   446,
     154,   155,   448,   156,   157,   158,     0,    75,   452,   449,
     450,     0,     0,   105,   105,    85,     0,   454,    87,     0,
       0,     0,   150,   151,   152,   153,     0,     0,     0,     0,
       0,    75,   306,   408,   154,   155,   307,   156,   157,   158,
       0,     0,     0,     0,    88,    89,    90,    91,    92,    93,
      94,    95,    99,    99,     0,    75,     0,     0,     0,     0,
      75,    75,     0,     0,    75,     0,     0,   166,     0,    75,
      75,     0,   253,    75,    18,    19,    20,    21,    22,     0,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,   153,     0,     0,     0,     0,   182,     0,     0,
      41,   154,   155,     0,   156,   157,   158,   188,     0,     0,
       0,     0,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,     0,     0,     0,   234,   237,
       1,     0,     2,     3,     4,     5,   254,     6,     7,     0,
       0,     0,     8,     9,    10,    11,    12,    13,  -198,  -198,
      14,    15,    16,    17,    99,     0,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,     0,    35,    36,    37,    38,
      39,    40,    41,     0,    42,    43,    44,    45,    46,     0,
       0,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   285,     0,     0,     0,
       0,     0,   289,     0,   154,   155,   314,   156,   157,   158,
       0,     0,     0,     0,   331,     0,     0,     0,    47,    48,
       0,     0,     0,     0,    49,    50,     0,     0,   264,   265,
       0,   345,   346,    51,     0,    52,     0,    53,     0,    54,
      55,  -198,     0,   356,    18,    19,    20,    21,    22,   266,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     0,     0,   267,   268,   269,     0,     0,     0,
      41,     0,     1,   367,     2,     3,     4,     5,     0,     6,
       7,     0,     0,     0,     8,     9,    10,    11,    12,    13,
    -199,  -199,    14,    15,    16,    17,     0,   384,    18,    19,
      20,    21,    22,     0,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,     0,     0,    35,    36,
      37,    38,    39,    40,    41,     0,    42,    43,    44,    45,
      46,   270,     0,   271,     0,     0,     0,     0,     0,   347,
       0,     0,     0,     0,   253,     0,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,     0,     0,     0,     0,     0,
      47,    48,    41,     0,     0,     0,    49,    50,     0,     0,
       0,     0,     0,     0,     0,    51,     0,    52,     0,    53,
       0,    54,    55,  -199,     1,     0,     2,     3,     4,     5,
       0,     6,     7,     0,     0,     0,     8,     9,    10,    11,
      12,    13,  -200,     0,    14,    15,    16,    17,     0,     0,
      18,    19,    20,    21,    22,     0,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,   379,     0,
      35,    36,    37,    38,    39,    40,    41,     0,    42,    43,
      44,    45,    46,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,     0,     0,
       0,     0,     0,     0,     0,     0,   154,   155,     0,   156,
     157,   158,    47,    48,     0,     0,     0,     0,    49,    50,
       0,     0,     0,     0,     0,     0,     0,    51,     0,    52,
       0,    53,     0,    54,    55,  -200,     1,     0,     2,     3,
       4,     5,     0,     6,     7,     0,     0,     0,     8,     9,
      10,    11,    12,    13,  -201,     0,    14,    15,    16,    17,
       0,     0,    18,    19,    20,    21,    22,     0,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       0,     0,    35,    36,    37,    38,    39,    40,    41,     0,
      42,    43,    44,    45,    46,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,     0,
       0,     0,     0,     0,     0,     0,     0,   154,   155,     0,
     156,   157,   158,     0,    47,    48,     0,     0,     0,     0,
      49,    50,     0,     0,     0,     0,     0,     0,     0,    51,
       0,    52,     0,    53,     0,    54,    55,  -201,     1,     0,
       2,     3,     4,     5,     0,     6,     7,     0,     0,     0,
       8,     9,    10,    11,    12,    13,     0,     0,    14,    15,
      16,    17,     0,     0,    18,    19,    20,    21,    22,     0,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     0,     0,    35,    36,    37,    38,    39,    40,
      41,     0,    42,    43,    44,    45,    46,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
       0,     0,     0,     0,     0,     0,     0,     0,   154,   155,
       0,   156,   157,   158,     0,     0,    47,    48,     0,     0,
       0,     0,    49,    50,     0,     0,     0,     0,     0,     0,
       0,    51,     0,    52,     0,    53,     0,    54,    55,   102,
      -2,     1,     0,     2,     3,     4,     5,     0,     6,     7,
       0,     0,     0,     8,     9,    10,    11,    12,    13,     0,
       0,    14,    15,    16,    17,     0,     0,    18,    19,    20,
      21,    22,     0,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,     0,     0,    35,    36,    37,
      38,    39,    40,    41,     0,    42,    43,    44,    45,    46,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,     0,     0,     0,     0,     0,     0,     0,     0,
     154,   155,     0,   156,   157,   158,     0,     0,     0,    47,
      48,     0,     0,     0,     0,    49,    50,     0,     0,     0,
       0,     0,     0,     0,    51,     0,    52,     0,    53,     0,
      54,    55,     1,     0,     2,     3,     4,     5,     0,     6,
       7,     0,     0,     0,     8,     9,    10,    11,    12,    13,
       0,     0,    14,    15,    16,    17,     0,     0,    18,    19,
      20,    21,    22,     0,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,     0,     0,    35,    36,
      37,    38,    39,    40,    41,     0,    42,    43,    44,    45,
      46,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,     0,     0,     0,     0,     0,     0,     0,     0,
     154,   155,     0,   156,   157,   158,     0,     0,     0,     0,
      47,    48,     0,     0,     0,     0,    49,    50,     0,     0,
       0,     0,     0,     0,     0,    51,     0,    52,     0,    53,
       0,    54,    55,   187,     1,     0,     2,     3,     4,     5,
       0,     6,     7,     0,     0,     0,     8,     9,    10,    11,
      12,    13,     0,     0,    14,    15,    16,    17,     0,     0,
      18,    19,    20,    21,    22,     0,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,     0,     0,
      35,    36,    37,    38,    39,    40,    41,     0,    42,    43,
      44,    45,    46,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,     0,     0,     0,     0,     0,     0,     0,
       0,   154,   155,     0,   156,   157,   158,     0,     0,     0,
       0,     0,    47,    48,     0,     0,     0,     0,    49,    50,
       0,     0,     0,     0,     0,     0,     0,    51,     0,    52,
       0,    53,     0,    54,    55,   420,     1,     0,     2,     3,
       4,     5,     0,     6,     7,     0,     0,     0,     8,     9,
      10,    11,    12,    13,     0,     0,    14,    15,    16,    17,
       0,     0,    18,    19,    20,    21,    22,     0,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       0,     0,    35,    36,    37,    38,    39,    40,    41,     0,
      42,    43,    44,    45,    46,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,     0,     0,     0,     0,     0,     0,
       0,     0,   154,   155,     0,   156,   157,   158,     0,     0,
       0,     0,     0,     0,    47,    48,     0,     0,     0,     0,
      49,    50,     0,     0,     0,     0,     0,     0,     0,    51,
       0,    52,     0,    53,     0,    54,    55,   317,     0,     2,
       3,     4,     5,     0,     6,     7,     0,     0,     0,     8,
       9,    10,    11,    12,    13,     0,     0,    14,    15,    16,
      17,     0,     0,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,     0,     0,    35,    36,    37,    38,    39,    40,    41,
       0,    42,    43,    44,    45,    46,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,     0,     0,     0,     0,     0,
       0,     0,    41,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    47,    48,     0,     0,     0,
       0,    49,    50,     2,     3,     4,     0,     0,     0,     0,
      51,     0,    52,     0,    53,     0,     0,    55,     0,     0,
       0,     0,    15,    16,    17,     0,     0,    18,    19,    20,
      21,    22,     0,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,     0,     0,    35,    36,    37,
      38,    39,    40,    41,     0,    42,    43,    44,    45,    46,
      15,    16,    17,   235,     0,    18,    19,    20,    21,    22,
       0,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     0,     0,    35,    36,    37,    38,    39,
      40,    41,     0,    42,    43,    44,    45,    46,     0,    47,
      48,     0,     0,     0,     0,    49,    50,     0,     0,     0,
       0,     0,     0,     0,    51,     0,    52,     0,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,    48,     0,
       0,     0,     0,    49,    50,     0,     0,     0,     0,     0,
       0,     0,    51,     0,    52,     0,    53,   236,    15,    16,
      17,    96,     0,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,     0,     0,    35,    36,    37,    38,    39,    40,    41,
       0,    42,    43,    44,    45,    46,    15,    16,    17,     0,
       0,    18,    19,    20,    21,    22,     0,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     0,
       0,    35,    36,    37,    38,    39,    40,    41,     0,    42,
      43,    44,    45,    46,     0,    47,    48,     0,     0,     0,
       0,    49,    50,     0,     0,     0,     0,     0,     0,     0,
      51,     0,    52,     0,    53,   290,   291,   292,   293,   294,
     295,     0,     0,     0,   296,   297,   298,   299,   300,   301,
     302,   303,     0,    47,    48,     0,     0,     0,     0,    49,
      50,     0,     0,     0,     0,     0,     0,     0,    51,     0,
      52,     0,    53,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   306,   109,   110,   111,   307,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   282,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,     0,     0,     0,     0,     0,     0,
       0,     0,   154,   155,     0,   156,   157,   158,   109,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   242,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,     0,     0,
       0,     0,     0,     0,     0,     0,   154,   155,     0,   156,
     157,   158,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,     0,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,     0,     0,     0,     0,     0,     0,     0,     0,
     154,   155,   391,   156,   157,   158,   109,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
       0,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,     0,     0,     0,     0,
       0,     0,     0,     0,   154,   155,   392,   156,   157,   158,
     109,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,     0,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
       0,     0,     0,     0,     0,     0,     0,     0,   154,   155,
       0,   156,   157,   158,   109,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,     0,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   245,   145,   146,   147,   148,   149,
     150,   151,   152,   153,     0,     0,     0,     0,     0,     0,
       0,     0,   154,   155,     0,   156,   157,   158,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,     0,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,     0,     0,     0,     0,     0,     0,     0,     0,   154,
     155,     0,   156,   157,   158
};

static const yytype_int16 yycheck[] =
{
       0,    57,   244,    52,    55,    62,     6,     7,    10,   306,
     307,    11,    12,   254,    53,    19,    20,    61,    19,   260,
      19,    19,   266,    79,   275,   167,    61,    66,    61,    61,
      61,   275,   344,    62,   275,   118,    79,    76,    61,    61,
     352,    80,    61,    61,    61,    84,    61,   103,    62,    62,
      79,    61,    61,   401,    61,    55,    61,    57,   118,    83,
      79,    85,     0,    63,    78,    79,    61,   304,   305,    61,
     118,   119,   118,   315,   114,   115,   120,   389,   121,    79,
     264,   265,   118,   120,   115,   120,   119,   119,   339,   118,
     331,   120,   115,   334,   335,   443,   337,   119,   240,   343,
     351,   119,   119,   103,   119,   115,   403,   120,   115,   421,
     119,   168,   169,   170,   119,   171,   155,   156,   122,   121,
     115,   122,   118,   122,   122,   437,   368,   364,   365,    79,
     120,    62,   113,   114,   183,   116,   117,   118,   379,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    79,    61,
     121,   121,    14,   118,   154,    62,   113,   114,    95,   116,
     117,   118,   119,    79,   119,   118,   122,   167,   114,   121,
     412,   171,   120,   173,     7,   175,   176,    62,   419,   118,
     421,    27,    28,    29,    30,    31,   120,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    11,
      12,    47,    48,    49,   119,   244,   120,    53,   119,   119,
      85,   120,    79,   252,   119,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,   119,   366,    47,    48,    49,   167,   286,
     240,    53,    66,   429,    36,    37,    38,    39,    40,    41,
     177,   333,   252,    45,    46,    47,    48,    49,    50,    51,
      52,   252,   319,   320,   264,   265,   252,   252,   114,   252,
     116,   333,   252,   273,   252,   252,   315,   316,   252,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   252,   252,
     341,    83,   252,    85,   273,    -1,   113,   114,   354,   116,
     117,   118,   114,    -1,   116,    -1,    -1,    -1,    -1,    -1,
     122,    -1,    -1,    -1,   353,    -1,   372,    -1,   375,   376,
     377,    -1,   114,    -1,    -1,    -1,   118,    -1,    -1,   368,
      -1,   387,    -1,   333,    36,    37,    38,    39,    40,    41,
      -1,   341,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    -1,   354,   411,    -1,    -1,    -1,    -1,
     399,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,
     103,   104,   372,   412,    -1,    -1,    -1,    -1,    -1,   435,
     113,   114,   439,   116,   117,   118,    -1,   387,   444,   440,
     441,    -1,    -1,   449,   450,    14,    -1,   453,    17,    -1,
      -1,    -1,   101,   102,   103,   104,    -1,    -1,    -1,    -1,
      -1,   411,   114,   115,   113,   114,   118,   116,   117,   118,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,   435,    -1,    -1,    -1,    -1,
     440,   441,    -1,    -1,   444,    -1,    -1,    66,    -1,   449,
     450,    -1,    25,   453,    27,    28,    29,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,   104,    -1,    -1,    -1,    -1,    96,    -1,    -1,
      53,   113,   114,    -1,   116,   117,   118,   106,    -1,    -1,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,   157,   158,
       1,    -1,     3,     4,     5,     6,   119,     8,     9,    -1,
      -1,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   183,    -1,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    -1,
      -1,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   235,    -1,    -1,    -1,
      -1,    -1,   241,    -1,   113,   114,   245,   116,   117,   118,
      -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,    99,   100,
      -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    11,    12,
      -1,   270,   271,   114,    -1,   116,    -1,   118,    -1,   120,
     121,   122,    -1,   282,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    47,    48,    49,    -1,    -1,    -1,
      53,    -1,     1,   312,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,   336,    27,    28,
      29,    30,    31,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,   114,    -1,   116,    -1,    -1,    -1,    -1,    -1,   122,
      -1,    -1,    -1,    -1,    25,    -1,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   100,    53,    -1,    -1,    -1,   105,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    -1,   116,    -1,   118,
      -1,   120,   121,   122,     1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    13,    14,    15,    16,
      17,    18,    19,    -1,    21,    22,    23,    24,    -1,    -1,
      27,    28,    29,    30,    31,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,   119,    -1,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,
     117,   118,    99,   100,    -1,    -1,    -1,    -1,   105,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,   116,
      -1,   118,    -1,   120,   121,   122,     1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    13,    14,
      15,    16,    17,    18,    19,    -1,    21,    22,    23,    24,
      -1,    -1,    27,    28,    29,    30,    31,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,
     116,   117,   118,    -1,    99,   100,    -1,    -1,    -1,    -1,
     105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,   116,    -1,   118,    -1,   120,   121,   122,     1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    -1,    -1,    21,    22,
      23,    24,    -1,    -1,    27,    28,    29,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
      -1,   116,   117,   118,    -1,    -1,    99,   100,    -1,    -1,
      -1,    -1,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,   116,    -1,   118,    -1,   120,   121,   122,
       0,     1,    -1,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    13,    14,    15,    16,    17,    18,    -1,
      -1,    21,    22,    23,    24,    -1,    -1,    27,    28,    29,
      30,    31,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   114,    -1,   116,   117,   118,    -1,    -1,    -1,    99,
     100,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,    -1,   116,    -1,   118,    -1,
     120,   121,     1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    13,    14,    15,    16,    17,    18,
      -1,    -1,    21,    22,    23,    24,    -1,    -1,    27,    28,
      29,    30,    31,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   114,    -1,   116,   117,   118,    -1,    -1,    -1,    -1,
      99,   100,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    -1,   116,    -1,   118,
      -1,   120,   121,   122,     1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    13,    14,    15,    16,
      17,    18,    -1,    -1,    21,    22,    23,    24,    -1,    -1,
      27,    28,    29,    30,    31,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,   114,    -1,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    99,   100,    -1,    -1,    -1,    -1,   105,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,   116,
      -1,   118,    -1,   120,   121,   122,     1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    13,    14,
      15,    16,    17,    18,    -1,    -1,    21,    22,    23,    24,
      -1,    -1,    27,    28,    29,    30,    31,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,   114,    -1,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,
     105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,   116,    -1,   118,    -1,   120,   121,     1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    13,
      14,    15,    16,    17,    18,    -1,    -1,    21,    22,    23,
      24,    -1,    -1,    27,    28,    29,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,
      -1,   105,   106,     3,     4,     5,    -1,    -1,    -1,    -1,
     114,    -1,   116,    -1,   118,    -1,    -1,   121,    -1,    -1,
      -1,    -1,    22,    23,    24,    -1,    -1,    27,    28,    29,
      30,    31,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      22,    23,    24,    25,    -1,    27,    28,    29,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    -1,    99,
     100,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,    -1,   116,    -1,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,
      -1,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,    -1,   116,    -1,   118,   119,    22,    23,
      24,    25,    -1,    27,    28,    29,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    22,    23,    24,    -1,
      -1,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    -1,    99,   100,    -1,    -1,    -1,
      -1,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,    -1,   116,    -1,   118,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    99,   100,    -1,    -1,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,
     116,    -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    55,    56,    57,   118,    -1,    -1,
      -1,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,   114,    -1,   116,   117,   118,    55,    56,
      57,    -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,
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
      -1,    -1,    -1,    -1,   113,   114,   115,   116,   117,   118,
      55,    56,    57,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
      -1,   116,   117,   118,    55,    56,    57,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    -1,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,   114,    -1,   116,   117,   118,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    -1,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
     114,    -1,   116,   117,   118
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
     168,   169,   170,   174,   183,   189,   118,   189,   189,   157,
     118,   118,   189,   189,   118,   147,   189,   147,   147,   147,
     147,   147,   147,   147,   147,   147,    25,   143,   144,   147,
     143,   146,   122,   125,     0,   126,    61,   120,   134,    55,
      56,    57,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   113,   114,   116,   117,   118,   148,
     134,   152,   153,   189,   145,   146,   147,   154,   127,   128,
     129,    79,   146,   118,   177,    10,   121,   184,   185,   126,
     146,   146,   147,    61,   115,   115,   119,   122,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   189,   146,   146,   147,    25,   119,   147,   149,   150,
      61,    62,    79,   141,   120,    95,   152,   153,   134,   134,
     134,   126,   119,    25,   119,   178,   179,   180,   181,   182,
     189,   121,   175,   189,    11,    12,    32,    47,    48,    49,
     114,   116,   122,   186,   187,   188,   189,   185,    14,   119,
     119,   143,    79,   115,   115,   147,    61,   119,   153,   147,
      36,    37,    38,    39,    40,    41,    45,    46,    47,    48,
      49,    50,    51,    52,    83,    85,   114,   118,   136,   137,
     138,   140,    62,   145,   147,   120,    95,     1,   130,   146,
     151,   155,   156,   165,   166,   167,   168,   169,   170,   174,
     183,   147,   141,    61,   119,   119,    62,    78,   135,   141,
     122,   176,   188,   188,   177,   147,   147,   122,   187,   120,
     135,   141,   177,   118,   159,   121,   147,   119,   148,   137,
     137,   136,   139,   136,    83,    85,   114,   147,   120,   119,
     145,   146,     7,   134,   134,   131,   132,   133,   141,   119,
     179,   182,   141,   141,   147,   141,   135,   125,   118,   177,
     175,   115,   115,   120,   120,   135,   175,   146,   126,    19,
     122,   171,   172,    61,   115,   119,   137,   137,   115,   138,
     145,   162,   120,   119,   126,   134,   134,   134,   141,   119,
     122,   119,   175,   120,   119,   146,    20,   122,   172,   173,
     136,   115,   119,   126,   145,   163,   141,   141,   175,   158,
      79,    79,   122,   171,   160,   119,   126,   175,   134,   125,
     125,   122,   126,   161,   126
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   123,   124,   125,   125,   126,   126,   126,   126,   126,
     126,   126,   127,   126,   128,   126,   129,   126,   126,   126,
     126,   126,   130,   130,   130,   130,   130,   130,   131,   130,
     132,   130,   133,   130,   130,   130,   130,   130,   134,   135,
     136,   136,   136,   137,   137,   137,   138,   138,   138,   138,
     138,   139,   139,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   141,   142,   142,
     143,   143,   143,   144,   144,   145,   145,   146,   146,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     148,   148,   148,   149,   149,   150,   150,   151,   152,   152,
     153,   153,   153,   153,   154,   154,   154,   155,   155,   157,
     158,   156,   159,   156,   160,   156,   161,   156,   162,   156,
     163,   156,   164,   165,   165,   166,   166,   167,   167,   168,
     169,   169,   170,   170,   170,   170,   171,   171,   172,   172,
     173,   173,   174,   175,   176,   175,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   178,   178,   179,   179,
     180,   180,   181,   181,   181,   181,   182,   182,   183,   183,
     184,   185,   185,   186,   186,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   188,   188,   188,   188,   188,   188,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     2,     2,     1,
       1,     1,     0,     3,     0,     3,     0,     3,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     1,     0,     3,
       0,     3,     0,     3,     1,     1,     1,     1,     1,     2,
       1,     2,     2,     3,     3,     1,     3,     1,     3,     4,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     3,
       0,     1,     3,     1,     2,     0,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     5,     3,     2,     3,     3,     1,     4,     4,     2,
       2,     3,     4,     1,     3,     1,     2,     2,     1,     3,
       1,     2,     3,     4,     1,     1,     1,     5,     7,     0,
       0,     9,     0,     6,     0,     9,     0,    10,     0,     7,
       0,     8,     2,     1,     2,     1,     2,     1,     2,     3,
       2,     3,     6,     7,     8,     9,     1,     2,     3,     4,
       2,     3,     4,     2,     0,     4,     2,     3,     3,     4,
       3,     4,     5,     6,     4,     5,     1,     3,     1,     1,
       1,     2,     2,     3,     2,     3,     2,     3,     3,     4,
       2,     2,     3,     1,     2,     3,     2,     3,     3,     4,
       3,     5,     6,     4,     1,     1,     1,     1,     3,     3,
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
#line 90 ".\\parser.y"
                    { 
        if ( syntaxErrorCounter > 0 ) {
            PrintError("Found " + std::to_string(syntaxErrorCounter) + " syntax errors. Fix them and rerun.");
            exit(1);
        }
        Print("- R: statementList -> script"); 
    }
#line 2598 "parser.tab.c"
    break;

  case 3: /* statementList: statementListItem  */
#line 100 ".\\parser.y"
                        { Print("- R: statementListItem -> statementList"); }
#line 2604 "parser.tab.c"
    break;

  case 4: /* statementList: statementList statementListItem  */
#line 101 ".\\parser.y"
                                      { Print("- R: statementList statementListItem -> statementList"); }
#line 2610 "parser.tab.c"
    break;

  case 6: /* statementListItem: ';'  */
#line 106 ".\\parser.y"
                                    { 
        if ( isASIActivated ) {
            std::string text(yytext_ptr, yyleng);
            yyerror(("syntax error on token: " + text).c_str()); YYERROR;
        }
        Print("- R: ';' -> statementListItem"); 
    }
#line 2622 "parser.tab.c"
    break;

  case 7: /* statementListItem: expressionList statementSep  */
#line 113 ".\\parser.y"
                                    { Print("- R: expressionList statementSep -> statementListItem"); }
#line 2628 "parser.tab.c"
    break;

  case 8: /* statementListItem: varStatement statementSep  */
#line 114 ".\\parser.y"
                                    { Print("- R: varStatement statementSep -> statementListItem"); }
#line 2634 "parser.tab.c"
    break;

  case 9: /* statementListItem: ifStatement  */
#line 115 ".\\parser.y"
                                    { Print("- R: ifStatement -> statementListItem"); }
#line 2640 "parser.tab.c"
    break;

  case 10: /* statementListItem: switchStatement  */
#line 116 ".\\parser.y"
                                    { Print("- R: switchStatement -> statementListItem"); }
#line 2646 "parser.tab.c"
    break;

  case 11: /* statementListItem: iterationStatement  */
#line 117 ".\\parser.y"
                                    { Print("- R: iterationStatement -> statementListItem"); }
#line 2652 "parser.tab.c"
    break;

  case 12: /* $@1: %empty  */
#line 118 ".\\parser.y"
                        {
        if ( !isInIterationBody ) { 
            yyerror("illegal continue statement."); YYERROR;
        } 
    }
#line 2662 "parser.tab.c"
    break;

  case 13: /* statementListItem: continueStatement $@1 statementSep  */
#line 122 ".\\parser.y"
                                    { Print("- R: continueStatement statementSep -> statementListItem");  }
#line 2668 "parser.tab.c"
    break;

  case 14: /* $@2: %empty  */
#line 123 ".\\parser.y"
                     {
        if ( !isInIterationBody ) { 
            yyerror("illegal break statement."); YYERROR;
        } 
    }
#line 2678 "parser.tab.c"
    break;

  case 15: /* statementListItem: breakStatement $@2 statementSep  */
#line 127 ".\\parser.y"
                                    { Print("- R: breakStatement statementSep -> statementListItem"); }
#line 2684 "parser.tab.c"
    break;

  case 16: /* $@3: %empty  */
#line 128 ".\\parser.y"
                      { 
        if ( !isInFunctionBody ) { 
            yyerror("illegal return statement."); YYERROR;
        } 
    }
#line 2694 "parser.tab.c"
    break;

  case 17: /* statementListItem: returnStatement $@3 statementSep  */
#line 132 ".\\parser.y"
                                    { Print("- R: returnStatement statementSep -> statementListItem"); }
#line 2700 "parser.tab.c"
    break;

  case 18: /* statementListItem: labelledStatement  */
#line 133 ".\\parser.y"
                                    { Print("- R: labelledStatement -> statementListItem"); }
#line 2706 "parser.tab.c"
    break;

  case 19: /* statementListItem: blockStatement  */
#line 134 ".\\parser.y"
                                    { Print("- R: blockStatement -> statementListItem"); }
#line 2712 "parser.tab.c"
    break;

  case 20: /* statementListItem: functionDeclaration  */
#line 135 ".\\parser.y"
                                    { Print("- R: functionDeclaration -> statementListItem"); }
#line 2718 "parser.tab.c"
    break;

  case 21: /* statementListItem: classDeclaration  */
#line 136 ".\\parser.y"
                                    { Print("- R: classDeclaration -> statementListItem"); }
#line 2724 "parser.tab.c"
    break;

  case 23: /* statementListItemWithoutEmptyStatement: expressionList statementSep  */
#line 141 ".\\parser.y"
                                    { Print("- R: expressionList statementSep -> statementListItem"); }
#line 2730 "parser.tab.c"
    break;

  case 24: /* statementListItemWithoutEmptyStatement: varStatement statementSep  */
#line 142 ".\\parser.y"
                                    { Print("- R: varStatement statementSep -> statementListItem"); }
#line 2736 "parser.tab.c"
    break;

  case 25: /* statementListItemWithoutEmptyStatement: ifStatement  */
#line 143 ".\\parser.y"
                                    { Print("- R: ifStatement -> statementListItem"); }
#line 2742 "parser.tab.c"
    break;

  case 26: /* statementListItemWithoutEmptyStatement: switchStatement  */
#line 144 ".\\parser.y"
                                    { Print("- R: switchStatement -> statementListItem"); }
#line 2748 "parser.tab.c"
    break;

  case 27: /* statementListItemWithoutEmptyStatement: iterationStatement  */
#line 145 ".\\parser.y"
                                    { Print("- R: iterationStatement -> statementListItem"); }
#line 2754 "parser.tab.c"
    break;

  case 28: /* $@4: %empty  */
#line 146 ".\\parser.y"
                        {
        if ( !isInIterationBody ) { 
            yyerror("illegal continue statement."); YYERROR;
        } 
    }
#line 2764 "parser.tab.c"
    break;

  case 29: /* statementListItemWithoutEmptyStatement: continueStatement $@4 statementSep  */
#line 150 ".\\parser.y"
                                    { Print("- R: continueStatement statementSep -> statementListItem");  }
#line 2770 "parser.tab.c"
    break;

  case 30: /* $@5: %empty  */
#line 151 ".\\parser.y"
                     {
        if ( !isInIterationBody ) { 
            yyerror("illegal break statement."); YYERROR;
        } 
    }
#line 2780 "parser.tab.c"
    break;

  case 31: /* statementListItemWithoutEmptyStatement: breakStatement $@5 statementSep  */
#line 155 ".\\parser.y"
                                    { Print("- R: breakStatement statementSep -> statementListItem"); }
#line 2786 "parser.tab.c"
    break;

  case 32: /* $@6: %empty  */
#line 156 ".\\parser.y"
                      { 
        if ( !isInFunctionBody ) { 
            yyerror("illegal return statement."); YYERROR;
        } 
    }
#line 2796 "parser.tab.c"
    break;

  case 33: /* statementListItemWithoutEmptyStatement: returnStatement $@6 statementSep  */
#line 160 ".\\parser.y"
                                    { Print("- R: returnStatement statementSep -> statementListItem"); }
#line 2802 "parser.tab.c"
    break;

  case 34: /* statementListItemWithoutEmptyStatement: labelledStatement  */
#line 161 ".\\parser.y"
                                    { Print("- R: labelledStatement -> statementListItem"); }
#line 2808 "parser.tab.c"
    break;

  case 35: /* statementListItemWithoutEmptyStatement: blockStatement  */
#line 162 ".\\parser.y"
                                    { Print("- R: blockStatement -> statementListItem"); }
#line 2814 "parser.tab.c"
    break;

  case 36: /* statementListItemWithoutEmptyStatement: functionDeclaration  */
#line 163 ".\\parser.y"
                                    { Print("- R: functionDeclaration -> statementListItem"); }
#line 2820 "parser.tab.c"
    break;

  case 37: /* statementListItemWithoutEmptyStatement: classDeclaration  */
#line 164 ".\\parser.y"
                                    { Print("- R: classDeclaration -> statementListItem"); }
#line 2826 "parser.tab.c"
    break;

  case 38: /* statementSep: ';'  */
#line 168 ".\\parser.y"
          { Print("- R: ';' -> statementSep"); }
#line 2832 "parser.tab.c"
    break;

  case 39: /* initializer: '=' singleExpression  */
#line 172 ".\\parser.y"
                           { Print("- R: '=' singleExpression -> initializer"); }
#line 2838 "parser.tab.c"
    break;

  case 40: /* type: unionOrIntersectionOrPrimaryType  */
#line 178 ".\\parser.y"
                                       { Print("- R: unionOrIntersectionOrPrimaryType -> type"); }
#line 2844 "parser.tab.c"
    break;

  case 41: /* type: '|' unionOrIntersectionOrPrimaryType  */
#line 179 ".\\parser.y"
                                           { Print("- R: '|' unionOrIntersectionOrPrimaryType -> type"); }
#line 2850 "parser.tab.c"
    break;

  case 42: /* type: '&' unionOrIntersectionOrPrimaryType  */
#line 180 ".\\parser.y"
                                           { Print("- R: '&' unionOrIntersectionOrPrimaryType -> type"); }
#line 2856 "parser.tab.c"
    break;

  case 43: /* unionOrIntersectionOrPrimaryType: unionOrIntersectionOrPrimaryType '|' unionOrIntersectionOrPrimaryType  */
#line 184 ".\\parser.y"
                                                                            { Print("- R: unionOrIntersectionOrPrimaryType '|' unionOrIntersectionOrPrimaryType -> unionOrIntersectionOrPrimaryType"); }
#line 2862 "parser.tab.c"
    break;

  case 44: /* unionOrIntersectionOrPrimaryType: unionOrIntersectionOrPrimaryType '&' unionOrIntersectionOrPrimaryType  */
#line 185 ".\\parser.y"
                                                                            { Print("- R: unionOrIntersectionOrPrimaryType '&' unionOrIntersectionOrPrimaryType -> unionOrIntersectionOrPrimaryType"); }
#line 2868 "parser.tab.c"
    break;

  case 45: /* unionOrIntersectionOrPrimaryType: primaryType  */
#line 186 ".\\parser.y"
                  { Print("- R: primaryType -> argument"); }
#line 2874 "parser.tab.c"
    break;

  case 46: /* primaryType: '(' type ')'  */
#line 190 ".\\parser.y"
                   { Print("- R: '(' type ')' -> primaryType"); }
#line 2880 "parser.tab.c"
    break;

  case 47: /* primaryType: predefinedType  */
#line 191 ".\\parser.y"
                     { Print("- R: predefinedType -> primaryType"); }
#line 2886 "parser.tab.c"
    break;

  case 48: /* primaryType: primaryType '[' ']'  */
#line 192 ".\\parser.y"
                          { Print("- R: primaryType '[' ']' -> primaryType"); }
#line 2892 "parser.tab.c"
    break;

  case 49: /* primaryType: primaryType '[' primaryType ']'  */
#line 193 ".\\parser.y"
                                      { Print("- R: primaryType '[' primaryType ']' -> primaryType"); }
#line 2898 "parser.tab.c"
    break;

  case 50: /* primaryType: '[' tupleTypeElements ']'  */
#line 194 ".\\parser.y"
                                { Print("- R: '[' tupleTypeElements ']' -> primaryType"); }
#line 2904 "parser.tab.c"
    break;

  case 51: /* tupleTypeElements: type  */
#line 198 ".\\parser.y"
           { Print("- R: type -> tupleTypeElements"); }
#line 2910 "parser.tab.c"
    break;

  case 52: /* tupleTypeElements: tupleTypeElements ',' type  */
#line 199 ".\\parser.y"
                                 { Print("- R: tupleTypeElements ',' type -> tupleTypeElements"); }
#line 2916 "parser.tab.c"
    break;

  case 53: /* predefinedType: ANY  */
#line 203 ".\\parser.y"
          { Print("- R: ANY -> predefinedType"); }
#line 2922 "parser.tab.c"
    break;

  case 54: /* predefinedType: NUMBER  */
#line 204 ".\\parser.y"
             { Print("- R: NUMBER -> predefinedType"); }
#line 2928 "parser.tab.c"
    break;

  case 55: /* predefinedType: STRING  */
#line 205 ".\\parser.y"
             { Print("- R: STRING -> predefinedType"); }
#line 2934 "parser.tab.c"
    break;

  case 56: /* predefinedType: BOOLEAN  */
#line 206 ".\\parser.y"
              { Print("- R: BOOLEAN -> predefinedType"); }
#line 2940 "parser.tab.c"
    break;

  case 57: /* predefinedType: NEVER  */
#line 207 ".\\parser.y"
            { Print("- R: NEVER -> predefinedType"); }
#line 2946 "parser.tab.c"
    break;

  case 58: /* predefinedType: UNKNOWN  */
#line 208 ".\\parser.y"
              { Print("- R: UNKNOWN -> predefinedType"); }
#line 2952 "parser.tab.c"
    break;

  case 59: /* predefinedType: UNDEFINED  */
#line 209 ".\\parser.y"
                { Print("- R: UNDEFINED -> predefinedType"); }
#line 2958 "parser.tab.c"
    break;

  case 60: /* predefinedType: VOID  */
#line 210 ".\\parser.y"
           { Print("- R: VOID -> predefinedType"); }
#line 2964 "parser.tab.c"
    break;

  case 61: /* predefinedType: NULL_KW  */
#line 211 ".\\parser.y"
              { Print("- R: NULL_KW -> predefinedType"); }
#line 2970 "parser.tab.c"
    break;

  case 62: /* predefinedType: INT_LIT  */
#line 212 ".\\parser.y"
              { Print("- R: INT_LIT -> predefinedType"); }
#line 2976 "parser.tab.c"
    break;

  case 63: /* predefinedType: FLOAT_LIT  */
#line 213 ".\\parser.y"
                { Print("- R: FLOAT_LIT -> predefinedType"); }
#line 2982 "parser.tab.c"
    break;

  case 64: /* predefinedType: TRUE_KW  */
#line 214 ".\\parser.y"
              { Print("- R: TRUE_WD -> predefinedType"); }
#line 2988 "parser.tab.c"
    break;

  case 65: /* predefinedType: FALSE_KW  */
#line 215 ".\\parser.y"
               { Print("- R: FALSE_KW -> predefinedType"); }
#line 2994 "parser.tab.c"
    break;

  case 66: /* predefinedType: STRING_LIT  */
#line 216 ".\\parser.y"
                 { Print("- R: STRING_LIT -> predefinedType"); }
#line 3000 "parser.tab.c"
    break;

  case 67: /* typeAnnotation: ':' type  */
#line 220 ".\\parser.y"
               { Print("- R: ':' type -> typeAnnotation"); }
#line 3006 "parser.tab.c"
    break;

  case 68: /* arrayLiteral: '[' elementList ']'  */
#line 225 ".\\parser.y"
                          { Print("- R: [ elementList ']' -> arrayLiteral"); }
#line 3012 "parser.tab.c"
    break;

  case 69: /* arrayLiteral: ENDL_BRACKET_OPEN elementList ']'  */
#line 226 ".\\parser.y"
                                        { Print("- R: ENDL_BRACKET_OPEN elementList ']' -> arrayLiteral"); }
#line 3018 "parser.tab.c"
    break;

  case 70: /* elementList: %empty  */
#line 230 ".\\parser.y"
                  { Print("- R: #empty# -> elementList"); }
#line 3024 "parser.tab.c"
    break;

  case 71: /* elementList: arrayElement  */
#line 231 ".\\parser.y"
                   { Print("- R: arrayElement -> elementList"); }
#line 3030 "parser.tab.c"
    break;

  case 72: /* elementList: elementList ',' elementList  */
#line 232 ".\\parser.y"
                                  { Print("- R: elementList ',' elementList -> elementList"); }
#line 3036 "parser.tab.c"
    break;

  case 73: /* arrayElement: singleExpression  */
#line 236 ".\\parser.y"
                       { Print("- R: singleExpression -> arrayElement"); }
#line 3042 "parser.tab.c"
    break;

  case 74: /* arrayElement: ELLIPSIS singleExpression  */
#line 237 ".\\parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> arrayElement"); }
#line 3048 "parser.tab.c"
    break;

  case 75: /* expressionListOpt: %empty  */
#line 243 ".\\parser.y"
                  { Print("- R: #empty# -> expressionListOpt"); }
#line 3054 "parser.tab.c"
    break;

  case 76: /* expressionListOpt: expressionList  */
#line 244 ".\\parser.y"
                     { Print("- R: expressionList -> expressionListOpt"); }
#line 3060 "parser.tab.c"
    break;

  case 77: /* expressionList: singleExpression  */
#line 248 ".\\parser.y"
                       { Print("- R: singleExpression -> expressionList"); }
#line 3066 "parser.tab.c"
    break;

  case 78: /* expressionList: expressionList ',' singleExpression  */
#line 249 ".\\parser.y"
                                          { Print("- R: expressionList ',' singleExpression -> expressionList"); }
#line 3072 "parser.tab.c"
    break;

  case 79: /* singleExpression: identifier  */
#line 253 ".\\parser.y"
                 { Print("- R: identifier -> singleExpression"); }
#line 3078 "parser.tab.c"
    break;

  case 80: /* singleExpression: THIS  */
#line 254 ".\\parser.y"
           { Print("- R: THIS -> singleExpression"); }
#line 3084 "parser.tab.c"
    break;

  case 81: /* singleExpression: SUPER  */
#line 255 ".\\parser.y"
            { Print("- R: SUPER -> singleExpression"); }
#line 3090 "parser.tab.c"
    break;

  case 82: /* singleExpression: INT_LIT  */
#line 256 ".\\parser.y"
              { Print("- R: INT_LIT -> singleExpression"); }
#line 3096 "parser.tab.c"
    break;

  case 83: /* singleExpression: FLOAT_LIT  */
#line 257 ".\\parser.y"
                { Print("- R: FLOAT_LIT -> singleExpression"); }
#line 3102 "parser.tab.c"
    break;

  case 84: /* singleExpression: STRING_LIT  */
#line 258 ".\\parser.y"
                 { Print("- R: STRING_LIT -> singleExpression"); }
#line 3108 "parser.tab.c"
    break;

  case 85: /* singleExpression: TEMPLATE_LITERAL  */
#line 259 ".\\parser.y"
                       { Print("- R: TEMPLATE_LITERAL -> singleExpression"); }
#line 3114 "parser.tab.c"
    break;

  case 86: /* singleExpression: TRUE_KW  */
#line 260 ".\\parser.y"
              { Print("- R: TRUE_LITERAL -> singleExpression"); }
#line 3120 "parser.tab.c"
    break;

  case 87: /* singleExpression: FALSE_KW  */
#line 261 ".\\parser.y"
               { Print("- R: FALSE_LITERAL -> singleExpression"); }
#line 3126 "parser.tab.c"
    break;

  case 88: /* singleExpression: NULL_KW  */
#line 262 ".\\parser.y"
              { Print("- R: NULL_LITERAL -> singleExpression"); }
#line 3132 "parser.tab.c"
    break;

  case 89: /* singleExpression: '-' singleExpression  */
#line 263 ".\\parser.y"
                                        { Print("- R: '-' singleExpression -> singleExpression"); }
#line 3138 "parser.tab.c"
    break;

  case 90: /* singleExpression: '+' singleExpression  */
#line 264 ".\\parser.y"
                                       { Print("- R: '+'s singleExpression -> singleExpression"); }
#line 3144 "parser.tab.c"
    break;

  case 91: /* singleExpression: '!' singleExpression  */
#line 265 ".\\parser.y"
                           { Print("- R: '!' singleExpression -> singleExpression"); }
#line 3150 "parser.tab.c"
    break;

  case 92: /* singleExpression: '~' singleExpression  */
#line 266 ".\\parser.y"
                           { Print("- R: '~' singleExpression -> singleExpression"); }
#line 3156 "parser.tab.c"
    break;

  case 93: /* singleExpression: singleExpression OPERATOR_INCREMENT  */
#line 267 ".\\parser.y"
                                                               { Print("- R: singleExpression OPERATOR_INCREMENT -> singleExpression"); }
#line 3162 "parser.tab.c"
    break;

  case 94: /* singleExpression: singleExpression OPERATOR_DECREMENT  */
#line 268 ".\\parser.y"
                                                               { Print("- R: singleExpression OPERATOR_DECREMENT -> singleExpression"); }
#line 3168 "parser.tab.c"
    break;

  case 95: /* singleExpression: ENDL_OPERATOR_INCREMENT singleExpression  */
#line 269 ".\\parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 3174 "parser.tab.c"
    break;

  case 96: /* singleExpression: ENDL_OPERATOR_DECREMENT singleExpression  */
#line 270 ".\\parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 3180 "parser.tab.c"
    break;

  case 97: /* singleExpression: OPERATOR_INCREMENT singleExpression  */
#line 271 ".\\parser.y"
                                                               { Print("- R: OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 3186 "parser.tab.c"
    break;

  case 98: /* singleExpression: OPERATOR_DECREMENT singleExpression  */
#line 272 ".\\parser.y"
                                                               { Print("- R: OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 3192 "parser.tab.c"
    break;

  case 99: /* singleExpression: singleExpression '+' singleExpression  */
#line 273 ".\\parser.y"
                                            { Print("- R: singleExpression '+' singleExpression -> singleExpression"); }
#line 3198 "parser.tab.c"
    break;

  case 100: /* singleExpression: singleExpression '-' singleExpression  */
#line 274 ".\\parser.y"
                                            { Print("- R: singleExpression '-' singleExpression -> singleExpression"); }
#line 3204 "parser.tab.c"
    break;

  case 101: /* singleExpression: singleExpression '*' singleExpression  */
#line 275 ".\\parser.y"
                                            { Print("- R: singleExpression '*' singleExpression -> singleExpression"); }
#line 3210 "parser.tab.c"
    break;

  case 102: /* singleExpression: singleExpression '/' singleExpression  */
#line 276 ".\\parser.y"
                                            { Print("- R: singleExpression '/' singleExpression -> singleExpression"); }
#line 3216 "parser.tab.c"
    break;

  case 103: /* singleExpression: singleExpression '%' singleExpression  */
#line 277 ".\\parser.y"
                                            { Print("- R: singleExpression '%' singleExpression -> singleExpression"); }
#line 3222 "parser.tab.c"
    break;

  case 104: /* singleExpression: singleExpression '<' singleExpression  */
#line 278 ".\\parser.y"
                                            { Print("- R: singleExpression '<' singleExpression -> singleExpression"); }
#line 3228 "parser.tab.c"
    break;

  case 105: /* singleExpression: singleExpression '>' singleExpression  */
#line 279 ".\\parser.y"
                                            { Print("- R: singleExpression '>' singleExpression -> singleExpression"); }
#line 3234 "parser.tab.c"
    break;

  case 106: /* singleExpression: singleExpression OPERATOR_POWER singleExpression  */
#line 280 ".\\parser.y"
                                                       { Print("- R: singleExpression OPERATOR_POWER singleExpression -> singleExpression"); }
#line 3240 "parser.tab.c"
    break;

  case 107: /* singleExpression: singleExpression OPERATOR_EQUAL singleExpression  */
#line 281 ".\\parser.y"
                                                       { Print("- R: singleExpression OPERATOR_EQUAL singleExpression -> singleExpression"); }
#line 3246 "parser.tab.c"
    break;

  case 108: /* singleExpression: singleExpression OPERATOR_NOT_EQUAL singleExpression  */
#line 282 ".\\parser.y"
                                                           { Print("- R: singleExpression OPERATOR_NOT_EQUAL singleExpression -> singleExpression"); }
#line 3252 "parser.tab.c"
    break;

  case 109: /* singleExpression: singleExpression OPERATOR_STRICT_EQUAL singleExpression  */
#line 283 ".\\parser.y"
                                                              { Print("- R: singleExpression OPERATOR_STRICT_EQUAL singleExpression -> singleExpression"); }
#line 3258 "parser.tab.c"
    break;

  case 110: /* singleExpression: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression  */
#line 284 ".\\parser.y"
                                                                  { Print("- R: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression -> singleExpression"); }
#line 3264 "parser.tab.c"
    break;

  case 111: /* singleExpression: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression  */
#line 285 ".\\parser.y"
                                                                 { Print("- R: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression -> singleExpression"); }
#line 3270 "parser.tab.c"
    break;

  case 112: /* singleExpression: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression  */
#line 286 ".\\parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression -> singleExpression"); }
#line 3276 "parser.tab.c"
    break;

  case 113: /* singleExpression: singleExpression '=' singleExpression  */
#line 287 ".\\parser.y"
                                            { Print("- R: singleExpression '=' singleExpression -> singleExpression"); }
#line 3282 "parser.tab.c"
    break;

  case 114: /* singleExpression: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression  */
#line 288 ".\\parser.y"
                                                                 { Print("- R: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression -> singleExpression"); }
#line 3288 "parser.tab.c"
    break;

  case 115: /* singleExpression: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression  */
#line 289 ".\\parser.y"
                                                               { Print("- R: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression -> singleExpression"); }
#line 3294 "parser.tab.c"
    break;

  case 116: /* singleExpression: singleExpression OPERATOR_ASSIGN_MOD singleExpression  */
#line 290 ".\\parser.y"
                                                            { Print("- R: singleExpression OPERATOR_ASSIGN_MOD singleExpression -> singleExpression"); }
#line 3300 "parser.tab.c"
    break;

  case 117: /* singleExpression: singleExpression OPERATOR_ASSIGN_PLUS singleExpression  */
#line 291 ".\\parser.y"
                                                             { Print("- R: singleExpression OPERATOR_ASSIGN_PLUS singleExpression -> singleExpression"); }
#line 3306 "parser.tab.c"
    break;

  case 118: /* singleExpression: singleExpression OPERATOR_ASSIGN_MINUS singleExpression  */
#line 292 ".\\parser.y"
                                                              { Print("- R: singleExpression OPERATOR_ASSIGN_MINUS singleExpression -> singleExpression"); }
#line 3312 "parser.tab.c"
    break;

  case 119: /* singleExpression: singleExpression OPERATOR_ASSIGN_SHIFT_LEFT singleExpression  */
#line 293 ".\\parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_SHIFT_LEFT singleExpression -> singleExpression"); }
#line 3318 "parser.tab.c"
    break;

  case 120: /* singleExpression: singleExpression OPERATOR_ASSIGN_SHIFT_RIGHT singleExpression  */
#line 294 ".\\parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3324 "parser.tab.c"
    break;

  case 121: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_AND singleExpression  */
#line 295 ".\\parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_AND singleExpression -> singleExpression"); }
#line 3330 "parser.tab.c"
    break;

  case 122: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_XOR singleExpression  */
#line 296 ".\\parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_XOR singleExpression -> singleExpression"); }
#line 3336 "parser.tab.c"
    break;

  case 123: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_OR singleExpression  */
#line 297 ".\\parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_OR singleExpression -> singleExpression"); }
#line 3342 "parser.tab.c"
    break;

  case 124: /* singleExpression: singleExpression OPERATOR_ASSIGN_POWER singleExpression  */
#line 298 ".\\parser.y"
                                                              { Print("- R: singleExpression OPERATOR_ASSIGN_POWER singleExpression -> singleExpression"); }
#line 3348 "parser.tab.c"
    break;

  case 125: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression  */
#line 299 ".\\parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression -> singleExpression"); }
#line 3354 "parser.tab.c"
    break;

  case 126: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression  */
#line 300 ".\\parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression -> singleExpression"); }
#line 3360 "parser.tab.c"
    break;

  case 127: /* singleExpression: singleExpression OPERATOR_ASSIGN_NULLISH_COALESCING singleExpression  */
#line 301 ".\\parser.y"
                                                                           { Print("- R: singleExpression OPERATOR_ASSIGN_NULLISH_COALESCING singleExpression -> singleExpression"); }
#line 3366 "parser.tab.c"
    break;

  case 128: /* singleExpression: singleExpression OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT singleExpression  */
#line 302 ".\\parser.y"
                                                                             { Print("- R: singleExpression OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3372 "parser.tab.c"
    break;

  case 129: /* singleExpression: singleExpression OPERATOR_LOGICAL_OR singleExpression  */
#line 303 ".\\parser.y"
                                                            { Print("- R: singleExpression OPERATOR_LOGICAL_OR singleExpression -> singleExpression"); }
#line 3378 "parser.tab.c"
    break;

  case 130: /* singleExpression: singleExpression OPERATOR_LOGICAL_AND singleExpression  */
#line 304 ".\\parser.y"
                                                             { Print("- R: singleExpression OPERATOR_LOGICAL_AND singleExpression -> singleExpression"); }
#line 3384 "parser.tab.c"
    break;

  case 131: /* singleExpression: singleExpression '|' singleExpression  */
#line 305 ".\\parser.y"
                                            { Print("- R: singleExpression '|' singleExpression -> singleExpression"); }
#line 3390 "parser.tab.c"
    break;

  case 132: /* singleExpression: singleExpression '^' singleExpression  */
#line 306 ".\\parser.y"
                                            { Print("- R: singleExpression '^' singleExpression -> singleExpression"); }
#line 3396 "parser.tab.c"
    break;

  case 133: /* singleExpression: singleExpression '&' singleExpression  */
#line 307 ".\\parser.y"
                                            { Print("- R: singleExpression '&' singleExpression -> singleExpression"); }
#line 3402 "parser.tab.c"
    break;

  case 134: /* singleExpression: singleExpression OPERATOR_SHIFT_LEFT singleExpression  */
#line 308 ".\\parser.y"
                                                            { Print("- R: singleExpression OPERATOR_SHIFT_LEFT singleExpression -> singleExpression"); }
#line 3408 "parser.tab.c"
    break;

  case 135: /* singleExpression: singleExpression OPERATOR_SHIFT_RIGHT singleExpression  */
#line 309 ".\\parser.y"
                                                             { Print("- R: singleExpression OPERATOR_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3414 "parser.tab.c"
    break;

  case 136: /* singleExpression: singleExpression OPERATOR_UNSIGNED_SHIFT_RIGHT singleExpression  */
#line 310 ".\\parser.y"
                                                                      { Print("- R: singleExpression OPERATOR_UNSIGNED_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3420 "parser.tab.c"
    break;

  case 137: /* singleExpression: singleExpression OPERATOR_NULLISH_COALESCING singleExpression  */
#line 311 ".\\parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_NULLISH_COALESCING singleExpression -> singleExpression"); }
#line 3426 "parser.tab.c"
    break;

  case 138: /* singleExpression: singleExpression INSTANCEOF singleExpression  */
#line 313 ".\\parser.y"
                                                   { Print("- R: singleExpression INSTANCEOF singleExpression -> singleExpression"); }
#line 3432 "parser.tab.c"
    break;

  case 139: /* singleExpression: singleExpression IN singleExpression  */
#line 314 ".\\parser.y"
                                           { Print("- R: singleExpression IN singleExpression -> singleExpression"); }
#line 3438 "parser.tab.c"
    break;

  case 140: /* singleExpression: singleExpression TEMPLATE_LITERAL  */
#line 316 ".\\parser.y"
                                        { Print("- R: singleExpression TEMPLATE_LITERAL -> singleExpression"); }
#line 3444 "parser.tab.c"
    break;

  case 141: /* singleExpression: singleExpression '?' singleExpression ':' singleExpression  */
#line 317 ".\\parser.y"
                                                                 { Print("- R: singleExpression '?' singleExpression ':' singleExpression -> singleExpression"); }
#line 3450 "parser.tab.c"
    break;

  case 142: /* singleExpression: '(' expressionList ')'  */
#line 319 ".\\parser.y"
                             { Print("- R: '(' expressionList ')' -> singleExpression"); }
#line 3456 "parser.tab.c"
    break;

  case 143: /* singleExpression: singleExpression arguments  */
#line 321 ".\\parser.y"
                                 { Print("- R: singleExpression arguments -> singleExpression"); }
#line 3462 "parser.tab.c"
    break;

  case 144: /* singleExpression: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression  */
#line 323 ".\\parser.y"
                                                                   { Print("- R: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression -> singleExpression"); }
#line 3468 "parser.tab.c"
    break;

  case 145: /* singleExpression: singleExpression '.' identifier  */
#line 324 ".\\parser.y"
                                      { Print("- R: singleExpression '.' identifier -> singleExpression"); }
#line 3474 "parser.tab.c"
    break;

  case 146: /* singleExpression: arrayLiteral  */
#line 326 ".\\parser.y"
                   { Print("- R: arrayLiteral -> singleExpression"); }
#line 3480 "parser.tab.c"
    break;

  case 147: /* singleExpression: singleExpression '[' expressionList ']'  */
#line 327 ".\\parser.y"
                                              { Print("- R: singleExpression '[' singleExpression ']' -> singleExpression"); }
#line 3486 "parser.tab.c"
    break;

  case 148: /* singleExpression: singleExpression ENDL_BRACKET_OPEN expressionList ']'  */
#line 328 ".\\parser.y"
                                                            { Print("- R: singleExpression ENDL_BRACKET_OPEN singleExpression ']' -> singleExpression"); }
#line 3492 "parser.tab.c"
    break;

  case 149: /* singleExpression: NEW singleExpression  */
#line 330 ".\\parser.y"
                           { Print("- R: NEW singleExpression -> singleExpression"); }
#line 3498 "parser.tab.c"
    break;

  case 150: /* arguments: '(' ')'  */
#line 334 ".\\parser.y"
              { Print("- R: '(' ')' -> arguments"); }
#line 3504 "parser.tab.c"
    break;

  case 151: /* arguments: '(' argumentList ')'  */
#line 335 ".\\parser.y"
                           { Print("- R: '(' argumentList ')' -> arguments"); }
#line 3510 "parser.tab.c"
    break;

  case 152: /* arguments: '(' argumentList ',' ')'  */
#line 336 ".\\parser.y"
                               { Print("- R: '(' argumentList ',' ') -> arguments"); }
#line 3516 "parser.tab.c"
    break;

  case 153: /* argumentList: argument  */
#line 340 ".\\parser.y"
               { Print("- R: argument -> argumentList"); }
#line 3522 "parser.tab.c"
    break;

  case 154: /* argumentList: argumentList ',' arguments  */
#line 341 ".\\parser.y"
                                 { Print("- R: argumentList ',' arguments -> argumentList"); }
#line 3528 "parser.tab.c"
    break;

  case 155: /* argument: singleExpression  */
#line 345 ".\\parser.y"
                       { Print("- R: singleExpression -> argument"); }
#line 3534 "parser.tab.c"
    break;

  case 156: /* argument: ELLIPSIS singleExpression  */
#line 346 ".\\parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> argument"); }
#line 3540 "parser.tab.c"
    break;

  case 157: /* varStatement: varModifier varDeclarationList  */
#line 352 ".\\parser.y"
                                     { Print("- R: varModifier varDeclarationList -> varStatement"); }
#line 3546 "parser.tab.c"
    break;

  case 158: /* varDeclarationList: varDeclaration  */
#line 356 ".\\parser.y"
                     { Print("- R: varDeclaration -> argument"); }
#line 3552 "parser.tab.c"
    break;

  case 159: /* varDeclarationList: varDeclarationList ',' varDeclaration  */
#line 357 ".\\parser.y"
                                            { Print("- R: varDeclarationList ',' varDeclaration -> varDeclarationList"); }
#line 3558 "parser.tab.c"
    break;

  case 160: /* varDeclaration: identifier  */
#line 361 ".\\parser.y"
                 { Print("- R: identifier -> varDeclaration"); }
#line 3564 "parser.tab.c"
    break;

  case 161: /* varDeclaration: identifier typeAnnotation  */
#line 362 ".\\parser.y"
                                { Print("- R: identifier typeAnnotation -> varDeclaration"); }
#line 3570 "parser.tab.c"
    break;

  case 162: /* varDeclaration: identifier '=' singleExpression  */
#line 363 ".\\parser.y"
                                      { Print("- R: identifier '=' singleExpression -> varDeclaration"); }
#line 3576 "parser.tab.c"
    break;

  case 163: /* varDeclaration: identifier typeAnnotation '=' singleExpression  */
#line 364 ".\\parser.y"
                                                     { Print("- R: identifier typeAnnotation '=' singleExpression -> varDeclaration"); }
#line 3582 "parser.tab.c"
    break;

  case 164: /* varModifier: VAR  */
#line 368 ".\\parser.y"
          { Print("- R: VAR -> varModifier"); }
#line 3588 "parser.tab.c"
    break;

  case 165: /* varModifier: LET  */
#line 369 ".\\parser.y"
          { Print("- R: LET -> varModifier"); }
#line 3594 "parser.tab.c"
    break;

  case 166: /* varModifier: CONST  */
#line 370 ".\\parser.y"
            { Print("- R: CONST -> varModifier"); }
#line 3600 "parser.tab.c"
    break;

  case 167: /* ifStatement: IF '(' expressionList ')' statementListItemWithoutEmptyStatement  */
#line 376 ".\\parser.y"
                                                                                          { Print("- R: IF '(' expressionList ')' statementListItem -> ifStatement"); }
#line 3606 "parser.tab.c"
    break;

  case 168: /* ifStatement: IF '(' expressionList ')' statementListItemWithoutEmptyStatement ELSE statementListItem  */
#line 377 ".\\parser.y"
                                                                                              { Print("- R: IF '(' expressionList ')' statementListItem ELSE statementListItem -> ifStatement"); }
#line 3612 "parser.tab.c"
    break;

  case 169: /* $@7: %empty  */
#line 381 ".\\parser.y"
         { isInIterationBody = 1; }
#line 3618 "parser.tab.c"
    break;

  case 170: /* $@8: %empty  */
#line 381 ".\\parser.y"
                                                                                   { doWhileASI(); }
#line 3624 "parser.tab.c"
    break;

  case 171: /* iterationStatement: DO $@7 statementListItem WHILE '(' expressionList ')' $@8 statementSep  */
#line 381 ".\\parser.y"
                                                                                                                                            { isInIterationBody = 0; Print("- R: DO statementListItem WHILE '(' expressionList ')' statementSep -> iterationStatement"); }
#line 3630 "parser.tab.c"
    break;

  case 172: /* $@9: %empty  */
#line 382 ".\\parser.y"
                                   { isInIterationBody = 1; }
#line 3636 "parser.tab.c"
    break;

  case 173: /* iterationStatement: WHILE '(' expressionList ')' $@9 statementListItem  */
#line 382 ".\\parser.y"
                                                                                                                                            { isInIterationBody = 0; Print("- R: WHILE '(' expressionList ')' statementListItem -> iterationStatement"); }
#line 3642 "parser.tab.c"
    break;

  case 174: /* $@10: %empty  */
#line 383 ".\\parser.y"
                                                                                  { isInForHeader = 0; isInIterationBody = 1; }
#line 3648 "parser.tab.c"
    break;

  case 175: /* iterationStatement: forHeader expressionListOpt ';' expressionListOpt ';' expressionListOpt ')' $@10 statementListItem  */
#line 383 ".\\parser.y"
                                                                                                                                                                 { isInIterationBody = 0; Print("- R: FOR '(' expressionListOpt ';' expressionListOpt ';' expressionListOpt ')' statementListItem -> iterationStatement"); }
#line 3654 "parser.tab.c"
    break;

  case 176: /* $@11: %empty  */
#line 384 ".\\parser.y"
                                                                                               { isInForHeader = 0; isInIterationBody = 1; }
#line 3660 "parser.tab.c"
    break;

  case 177: /* iterationStatement: forHeader varModifier varDeclarationList ';' expressionListOpt ';' expressionListOpt ')' $@11 statementListItem  */
#line 384 ".\\parser.y"
                                                                                                                                                                 { isInIterationBody = 0; Print("- R: FOR '(' varModifier varDeclarationList ';' expressionListOpt ';' expressionListOpt ')' statementListItem -> iterationStatement"); }
#line 3666 "parser.tab.c"
    break;

  case 178: /* $@12: %empty  */
#line 385 ".\\parser.y"
                                                         { isInForHeader = 0; isInIterationBody = 1; }
#line 3672 "parser.tab.c"
    break;

  case 179: /* iterationStatement: forHeader singleExpression IN singleExpression ')' $@12 statementListItem  */
#line 385 ".\\parser.y"
                                                                                                                                                                 { isInIterationBody = 0; Print("- R: FOR '(' singleExpression IN singleExpression ')' statementListItem -> iterationStatement"); }
#line 3678 "parser.tab.c"
    break;

  case 180: /* $@13: %empty  */
#line 386 ".\\parser.y"
                                                                 { isInForHeader = 0; isInIterationBody = 1; }
#line 3684 "parser.tab.c"
    break;

  case 181: /* iterationStatement: forHeader varModifier varDeclaration IN expressionList ')' $@13 statementListItem  */
#line 386 ".\\parser.y"
                                                                                                                                                                 { isInIterationBody = 0; Print("- R: FOR '(' varModifier varDeclaration IN expressionList ')' statementListItem -> iterationStatement"); }
#line 3690 "parser.tab.c"
    break;

  case 182: /* forHeader: FOR '('  */
#line 390 ".\\parser.y"
               { isInForHeader = 1; }
#line 3696 "parser.tab.c"
    break;

  case 183: /* continueStatement: CONTINUE  */
#line 394 ".\\parser.y"
               { Print("- R: CONTINUE -> returnStatement"); }
#line 3702 "parser.tab.c"
    break;

  case 184: /* continueStatement: CONTINUE identifier  */
#line 395 ".\\parser.y"
                          { Print("- R: CONTINUE identifier -> returnStatement"); }
#line 3708 "parser.tab.c"
    break;

  case 185: /* breakStatement: BREAK  */
#line 399 ".\\parser.y"
             { Print("- R: BREAK -> returnStatement"); }
#line 3714 "parser.tab.c"
    break;

  case 186: /* breakStatement: BREAK identifier  */
#line 400 ".\\parser.y"
                       { Print("- R: BREAK identifier -> returnStatement"); }
#line 3720 "parser.tab.c"
    break;

  case 187: /* returnStatement: RETURN  */
#line 404 ".\\parser.y"
             { Print("- R: RETURN -> returnStatement"); }
#line 3726 "parser.tab.c"
    break;

  case 188: /* returnStatement: RETURN singleExpression  */
#line 405 ".\\parser.y"
                              { Print("- R: RETURN singleExpression -> returnStatement"); }
#line 3732 "parser.tab.c"
    break;

  case 189: /* labelledStatement: identifier ':' statementListItem  */
#line 409 ".\\parser.y"
                                       { Print("- R: identifier ':' statementListItem -> labelledStatement"); }
#line 3738 "parser.tab.c"
    break;

  case 190: /* blockStatement: '{' '}'  */
#line 413 ".\\parser.y"
              { Print("- R: '{' '}' -> blockStatement"); }
#line 3744 "parser.tab.c"
    break;

  case 191: /* blockStatement: '{' statementList '}'  */
#line 414 ".\\parser.y"
                            { Print("- R: '{' statementList '}' -> blockStatement"); }
#line 3750 "parser.tab.c"
    break;

  case 192: /* switchStatement: SWITCH '(' expressionList ')' '{' '}'  */
#line 418 ".\\parser.y"
                                            { Print("- R: SWITCH '(' expressionList ')' '{' '}' -> switchStatement"); }
#line 3756 "parser.tab.c"
    break;

  case 193: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList '}'  */
#line 419 ".\\parser.y"
                                                           { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList '}' -> switchStatement"); }
#line 3762 "parser.tab.c"
    break;

  case 194: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause '}'  */
#line 420 ".\\parser.y"
                                                                         { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause '}' -> switchStatement"); }
#line 3768 "parser.tab.c"
    break;

  case 195: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause caseClauseList '}'  */
#line 421 ".\\parser.y"
                                                                                        { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause caseClauseList '}' -> switchStatement"); }
#line 3774 "parser.tab.c"
    break;

  case 196: /* caseClauseList: caseClause  */
#line 425 ".\\parser.y"
                 { Print("- R: caseClause -> caseClauseList"); }
#line 3780 "parser.tab.c"
    break;

  case 197: /* caseClauseList: caseClauseList caseClause  */
#line 426 ".\\parser.y"
                                { Print("- R: caseClauseList caseClause -> caseClauseList"); }
#line 3786 "parser.tab.c"
    break;

  case 198: /* caseClause: CASE expressionList ':'  */
#line 430 ".\\parser.y"
                              { Print("- R: CASE expressionList ':' -> caseClause"); }
#line 3792 "parser.tab.c"
    break;

  case 199: /* caseClause: CASE expressionList ':' statementList  */
#line 431 ".\\parser.y"
                                            { Print("- R: CASE expressionList ':' statementList -> caseClause"); }
#line 3798 "parser.tab.c"
    break;

  case 200: /* defaultClause: DEFAULT ':'  */
#line 435 ".\\parser.y"
                  { Print("- R: DEFAULT ':' -> defaultClause"); }
#line 3804 "parser.tab.c"
    break;

  case 201: /* defaultClause: DEFAULT ':' statementList  */
#line 436 ".\\parser.y"
                                { Print("- R: DEFAULT ':' statementList -> defaultClause"); }
#line 3810 "parser.tab.c"
    break;

  case 202: /* functionDeclaration: FUNCTION identifier callSignature functionBody  */
#line 442 ".\\parser.y"
                                                     { Print("- R: FUNCTION ID callSignature functionBody -> functionDeclaration"); }
#line 3816 "parser.tab.c"
    break;

  case 203: /* functionBody: '{' '}'  */
#line 446 ".\\parser.y"
              { Print("- R: '{' '}' -> functionBody"); }
#line 3822 "parser.tab.c"
    break;

  case 204: /* $@14: %empty  */
#line 447 ".\\parser.y"
          { isInFunctionBody = 1; }
#line 3828 "parser.tab.c"
    break;

  case 205: /* functionBody: '{' $@14 statementList '}'  */
#line 447 ".\\parser.y"
                                                      { isInFunctionBody = 0; Print("- R: '{' statementList '}' -> functionBody"); }
#line 3834 "parser.tab.c"
    break;

  case 206: /* callSignature: '(' ')'  */
#line 451 ".\\parser.y"
              { Print("- R: '(' ')' -> callSignature"); }
#line 3840 "parser.tab.c"
    break;

  case 207: /* callSignature: '(' ')' typeAnnotation  */
#line 452 ".\\parser.y"
                             { Print("- R: '(' ')' typeAnnotation -> callSignature"); }
#line 3846 "parser.tab.c"
    break;

  case 208: /* callSignature: '(' restParameter ')'  */
#line 453 ".\\parser.y"
                            { Print("- R: '(' restParameter ')' -> callSignature"); }
#line 3852 "parser.tab.c"
    break;

  case 209: /* callSignature: '(' restParameter ')' typeAnnotation  */
#line 454 ".\\parser.y"
                                           { Print("- R: '(' restParameter ')' typeAnnotation -> callSignature"); }
#line 3858 "parser.tab.c"
    break;

  case 210: /* callSignature: '(' parameterList ')'  */
#line 455 ".\\parser.y"
                            { Print("- R: '(' parameterList ')' -> callSignature"); }
#line 3864 "parser.tab.c"
    break;

  case 211: /* callSignature: '(' parameterList ')' typeAnnotation  */
#line 456 ".\\parser.y"
                                           { Print("- R: '(' parameterList ')' typeAnnotation -> callSignature"); }
#line 3870 "parser.tab.c"
    break;

  case 212: /* callSignature: '(' parameterList ',' restParameter ')'  */
#line 457 ".\\parser.y"
                                              { Print("- R: '(' parameterList ',' restParameter ')' -> callSignature"); }
#line 3876 "parser.tab.c"
    break;

  case 213: /* callSignature: '(' parameterList ',' restParameter ')' typeAnnotation  */
#line 458 ".\\parser.y"
                                                             { Print("- R: '(' parameterList ',' restParameter ')' typeAnnotation -> callSignature"); }
#line 3882 "parser.tab.c"
    break;

  case 214: /* callSignature: '(' parameterList ',' ')'  */
#line 459 ".\\parser.y"
                                { Print("- R: '(' parameterList ',' ')' -> callSignature"); }
#line 3888 "parser.tab.c"
    break;

  case 215: /* callSignature: '(' parameterList ',' ')' typeAnnotation  */
#line 460 ".\\parser.y"
                                               { Print("- R: '(' parameterList ',' ')' typeAnnotation -> callSignature"); }
#line 3894 "parser.tab.c"
    break;

  case 216: /* parameterList: parameter  */
#line 464 ".\\parser.y"
                { Print("- R: parameter -> parameterList"); }
#line 3900 "parser.tab.c"
    break;

  case 217: /* parameterList: parameterList ',' parameter  */
#line 465 ".\\parser.y"
                                  { Print("- R: parameterList ',' parameter -> parameterList"); }
#line 3906 "parser.tab.c"
    break;

  case 218: /* parameter: requiredParameter  */
#line 469 ".\\parser.y"
                        { Print("- R: requiredParameter -> parameter"); }
#line 3912 "parser.tab.c"
    break;

  case 219: /* parameter: optionalParameter  */
#line 470 ".\\parser.y"
                        { Print("- R: optionalParameter -> parameter"); }
#line 3918 "parser.tab.c"
    break;

  case 220: /* requiredParameter: identifier  */
#line 474 ".\\parser.y"
                 { Print("- R: ID -> requiredParameter"); }
#line 3924 "parser.tab.c"
    break;

  case 221: /* requiredParameter: identifier typeAnnotation  */
#line 475 ".\\parser.y"
                                { Print("- R: ID typeAnnotation -> requiredParameter"); }
#line 3930 "parser.tab.c"
    break;

  case 222: /* optionalParameter: identifier '?'  */
#line 479 ".\\parser.y"
                     { Print("- R: ID '?' -> optionalParameter"); }
#line 3936 "parser.tab.c"
    break;

  case 223: /* optionalParameter: identifier '?' typeAnnotation  */
#line 480 ".\\parser.y"
                                    { Print("- R: ID '?' typeAnnotation -> optionalParameter"); }
#line 3942 "parser.tab.c"
    break;

  case 224: /* optionalParameter: identifier initializer  */
#line 481 ".\\parser.y"
                             { Print("- R: ID initializer -> optionalParameter"); }
#line 3948 "parser.tab.c"
    break;

  case 225: /* optionalParameter: identifier typeAnnotation initializer  */
#line 482 ".\\parser.y"
                                            { Print("- R: ID typeAnnotation initializer -> optionalParameter"); }
#line 3954 "parser.tab.c"
    break;

  case 226: /* restParameter: ELLIPSIS singleExpression  */
#line 486 ".\\parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> restParameter"); }
#line 3960 "parser.tab.c"
    break;

  case 227: /* restParameter: ELLIPSIS singleExpression typeAnnotation  */
#line 487 ".\\parser.y"
                                               { Print("- R: ELLIPSIS singleExpression typeAnnotation -> restParameter"); }
#line 3966 "parser.tab.c"
    break;

  case 228: /* classDeclaration: CLASS identifier classTail  */
#line 493 ".\\parser.y"
                                 { Print("- R: CLASS identifier classTail -> classDeclaration"); }
#line 3972 "parser.tab.c"
    break;

  case 229: /* classDeclaration: CLASS identifier classHeritage classTail  */
#line 494 ".\\parser.y"
                                               { Print("- R: CLASS identifier classHeritage classTail -> classDeclaration"); }
#line 3978 "parser.tab.c"
    break;

  case 230: /* classHeritage: EXTENDS identifier  */
#line 498 ".\\parser.y"
                         { Print("- R: EXTENDS identifier -> classHeritage"); }
#line 3984 "parser.tab.c"
    break;

  case 231: /* classTail: '{' '}'  */
#line 502 ".\\parser.y"
              { Print("- R: '{' '}' -> classTail"); }
#line 3990 "parser.tab.c"
    break;

  case 232: /* classTail: '{' classElementList '}'  */
#line 503 ".\\parser.y"
                               { Print("- R: '{' classElementList '}' -> classTail"); }
#line 3996 "parser.tab.c"
    break;

  case 233: /* classElementList: classElement  */
#line 507 ".\\parser.y"
                   { Print("- R: classElement -> classElementList"); }
#line 4002 "parser.tab.c"
    break;

  case 234: /* classElementList: classElementList classElement  */
#line 508 ".\\parser.y"
                                    { Print("- R: classElementList classElement -> classElementList"); }
#line 4008 "parser.tab.c"
    break;

  case 235: /* classElement: CONSTRUCTOR callSignature functionBody  */
#line 512 ".\\parser.y"
                                             { Print("- R: CONSTRUCTOR callSignature functionBody -> classElement"); }
#line 4014 "parser.tab.c"
    break;

  case 236: /* classElement: propertyName ';'  */
#line 515 ".\\parser.y"
                       { Print("- R: propertyName ';' -> classElement"); }
#line 4020 "parser.tab.c"
    break;

  case 237: /* classElement: propertyName typeAnnotation ';'  */
#line 516 ".\\parser.y"
                                      { Print("- R: propertyName typeAnnotation ';' -> classElement"); }
#line 4026 "parser.tab.c"
    break;

  case 238: /* classElement: propertyName initializer ';'  */
#line 517 ".\\parser.y"
                                   { Print("- R: propertyName initializer ';' -> classElement"); }
#line 4032 "parser.tab.c"
    break;

  case 239: /* classElement: propertyName typeAnnotation initializer ';'  */
#line 518 ".\\parser.y"
                                                  { Print("- R: propertyName typeAnnotation initializer ';' -> classElement"); }
#line 4038 "parser.tab.c"
    break;

  case 240: /* classElement: propertyName callSignature functionBody  */
#line 521 ".\\parser.y"
                                              { Print("- R: propertyName callSignature functionBody -> classElement"); }
#line 4044 "parser.tab.c"
    break;

  case 241: /* classElement: GET propertyName '(' ')' functionBody  */
#line 524 ".\\parser.y"
                                            { Print("- R: GET propertyName '(' ')' functionBody -> classElement"); }
#line 4050 "parser.tab.c"
    break;

  case 242: /* classElement: GET propertyName '(' ')' typeAnnotation functionBody  */
#line 525 ".\\parser.y"
                                                           { Print("- R: GET propertyName '(' ')' typeAnnotation functionBody -> classElement"); }
#line 4056 "parser.tab.c"
    break;

  case 243: /* classElement: SET propertyName callSignature functionBody  */
#line 526 ".\\parser.y"
                                                  { Print("- R: SET propertyName callSignature functionBody -> classElement"); }
#line 4062 "parser.tab.c"
    break;

  case 244: /* propertyName: identifier  */
#line 530 ".\\parser.y"
                 { Print("- R: identifier -> propertyName"); }
#line 4068 "parser.tab.c"
    break;

  case 245: /* propertyName: STRING_LIT  */
#line 531 ".\\parser.y"
                 { Print("- R: STRING_LIT -> propertyName"); }
#line 4074 "parser.tab.c"
    break;

  case 246: /* propertyName: INT_LIT  */
#line 532 ".\\parser.y"
              { Print("- R: INT_LIT -> propertyName"); }
#line 4080 "parser.tab.c"
    break;

  case 247: /* propertyName: FLOAT_LIT  */
#line 533 ".\\parser.y"
                { Print("- R: FLOAT_LIT -> propertyName"); }
#line 4086 "parser.tab.c"
    break;

  case 248: /* propertyName: '[' singleExpression ']'  */
#line 534 ".\\parser.y"
                               { Print("- R: '[' singleExpression ']' -> propertyName"); }
#line 4092 "parser.tab.c"
    break;

  case 249: /* propertyName: ENDL_BRACKET_OPEN singleExpression ']'  */
#line 535 ".\\parser.y"
                                             { Print("- R: ENDL_BRACKET_OPEN singleExpression ']' -> propertyName"); }
#line 4098 "parser.tab.c"
    break;

  case 250: /* identifier: ID  */
#line 539 ".\\parser.y"
         { Print("- R: ID -> identifier"); }
#line 4104 "parser.tab.c"
    break;

  case 251: /* identifier: ASYNC  */
#line 540 ".\\parser.y"
            { Print("- R: ASYNC -> identifier"); }
#line 4110 "parser.tab.c"
    break;

  case 252: /* identifier: AS  */
#line 541 ".\\parser.y"
         { Print("- R: AS -> identifier"); }
#line 4116 "parser.tab.c"
    break;

  case 253: /* identifier: FROM  */
#line 542 ".\\parser.y"
           { Print("- R: FROM -> identifier"); }
#line 4122 "parser.tab.c"
    break;

  case 254: /* identifier: YIELD  */
#line 543 ".\\parser.y"
            { Print("- R: YIELD -> identifier"); }
#line 4128 "parser.tab.c"
    break;

  case 255: /* identifier: ANY  */
#line 544 ".\\parser.y"
          { Print("- R: ANY -> identifier"); }
#line 4134 "parser.tab.c"
    break;

  case 256: /* identifier: NUMBER  */
#line 545 ".\\parser.y"
             { Print("- R: NUMBER -> identifier"); }
#line 4140 "parser.tab.c"
    break;

  case 257: /* identifier: BOOLEAN  */
#line 546 ".\\parser.y"
              { Print("- R: BOOLEAN -> identifier"); }
#line 4146 "parser.tab.c"
    break;

  case 258: /* identifier: STRING  */
#line 547 ".\\parser.y"
             { Print("- R: STRING -> identifier"); }
#line 4152 "parser.tab.c"
    break;

  case 259: /* identifier: UNIQUE  */
#line 548 ".\\parser.y"
             { Print("- R: UNIQUE -> identifier"); }
#line 4158 "parser.tab.c"
    break;

  case 260: /* identifier: SYMBOL  */
#line 549 ".\\parser.y"
             { Print("- R: SYMBOL -> identifier"); }
#line 4164 "parser.tab.c"
    break;

  case 261: /* identifier: NEVER  */
#line 550 ".\\parser.y"
            { Print("- R: NEVER -> identifier"); }
#line 4170 "parser.tab.c"
    break;

  case 262: /* identifier: UNDEFINED  */
#line 551 ".\\parser.y"
                { Print("- R: UNDEFINED -> identifier"); }
#line 4176 "parser.tab.c"
    break;

  case 263: /* identifier: OBJECT  */
#line 552 ".\\parser.y"
             { Print("- R: OBJECT -> identifier"); }
#line 4182 "parser.tab.c"
    break;

  case 264: /* identifier: KEYOF  */
#line 553 ".\\parser.y"
            { Print("- R: KEYOF -> identifier"); }
#line 4188 "parser.tab.c"
    break;

  case 265: /* identifier: NAMESPACE  */
#line 554 ".\\parser.y"
                { Print("- R: NAMESPACE -> identifier"); }
#line 4194 "parser.tab.c"
    break;

  case 266: /* identifier: ABSTRACT  */
#line 555 ".\\parser.y"
               { Print("- R: ABSTRACT -> identifier"); }
#line 4200 "parser.tab.c"
    break;

  case 267: /* identifier: REQUIRE  */
#line 556 ".\\parser.y"
              { Print("- R: REQUIRE -> identifier"); }
#line 4206 "parser.tab.c"
    break;


#line 4210 "parser.tab.c"

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

#line 559 ".\\parser.y"



void yyerror(const char* s) {
    syntaxErrorCounter++;
    std::string text(yytext_ptr, yyleng);

    fprintf(stderr, ">> SyntaxError: Line:%d. Text: %s. Error: %s <<\n", yylloc.first_line, text.c_str(), s);
}

/* Implementing part of automatic semicolon insertion of TypeScript / ECMAscript. 
 * This part is impelemnted first rule of semicolon insertion. 
 * See: https://262.ecma-international.org/14.0/#sec-unicode-format-control-characters:~:text=The%20offending%20token%20is%20separated%20from%20the%20previous%20token%20by%20at%20least%20one
 */
int yyfilter(int yychar, int yyn, int yystate, short *yyssp) {
    isASIActivated = 0;

    if (yychar != ENDL) {
        return yychar;
    }
    // Skiping multiple ENDL symbols
    do { yychar = yylex(); } while (yychar == ENDL); 

    if ( yychar == ';' || isInForHeader ) {
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
            
            isASIActivated = 1;
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
