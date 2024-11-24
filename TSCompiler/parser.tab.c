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

extern void rescanTokenString(const char *s);
extern void doWhileASI();
extern int yylex();

void yyerror(const char *s);
int yyfilter(int yychar, int yyn, int yystate, short *yyssp);


#line 91 "parser.tab.c"

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
    STATIC = 266,                  /* STATIC  */
    GET = 267,                     /* GET  */
    SET = 268,                     /* SET  */
    DO = 269,                      /* DO  */
    WHILE = 270,                   /* WHILE  */
    FOR = 271,                     /* FOR  */
    CONTINUE = 272,                /* CONTINUE  */
    BREAK = 273,                   /* BREAK  */
    SWITCH = 274,                  /* SWITCH  */
    CASE = 275,                    /* CASE  */
    DEFAULT = 276,                 /* DEFAULT  */
    RETURN = 277,                  /* RETURN  */
    SUPER = 278,                   /* SUPER  */
    THIS = 279,                    /* THIS  */
    NEW = 280,                     /* NEW  */
    ELLIPSIS = 281,                /* ELLIPSIS  */
    OF = 282,                      /* OF  */
    ARROW_FUNCTION = 283,          /* ARROW_FUNCTION  */
    PUBLIC = 284,                  /* PUBLIC  */
    PRIVATE = 285,                 /* PRIVATE  */
    PROTECTED = 286,               /* PROTECTED  */
    ASYNC = 287,                   /* ASYNC  */
    AS = 288,                      /* AS  */
    FROM = 289,                    /* FROM  */
    YIELD = 290,                   /* YIELD  */
    KEYOF = 291,                   /* KEYOF  */
    CONSTRUCTOR = 292,             /* CONSTRUCTOR  */
    NAMESPACE = 293,               /* NAMESPACE  */
    ABSTRACT = 294,                /* ABSTRACT  */
    REQUIRE = 295,                 /* REQUIRE  */
    ANY = 296,                     /* ANY  */
    NUMBER = 297,                  /* NUMBER  */
    BOOLEAN = 298,                 /* BOOLEAN  */
    STRING = 299,                  /* STRING  */
    NEVER = 300,                   /* NEVER  */
    UNDEFINED = 301,               /* UNDEFINED  */
    UNIQUE = 302,                  /* UNIQUE  */
    SYMBOL = 303,                  /* SYMBOL  */
    OBJECT = 304,                  /* OBJECT  */
    VOID = 305,                    /* VOID  */
    UNKNOWN = 306,                 /* UNKNOWN  */
    STRING_LIT = 307,              /* STRING_LIT  */
    INT_LIT = 308,                 /* INT_LIT  */
    FLOAT_LIT = 309,               /* FLOAT_LIT  */
    NULL_KW = 310,                 /* NULL_KW  */
    TRUE_KW = 311,                 /* TRUE_KW  */
    FALSE_KW = 312,                /* FALSE_KW  */
    ID = 313,                      /* ID  */
    ENDL = 314,                    /* ENDL  */
    TEMPLATE_LITERAL = 315,        /* TEMPLATE_LITERAL  */
    OPERATOR_INCREMENT = 316,      /* OPERATOR_INCREMENT  */
    OPERATOR_DECREMENT = 317,      /* OPERATOR_DECREMENT  */
    ENDL_OPERATOR_INCREMENT = 318, /* ENDL_OPERATOR_INCREMENT  */
    ENDL_OPERATOR_DECREMENT = 319, /* ENDL_OPERATOR_DECREMENT  */
    IF_ONLY_PREC = 320,            /* IF_ONLY_PREC  */
    OPERATOR_ASSIGN_PLUS = 321,    /* OPERATOR_ASSIGN_PLUS  */
    OPERATOR_ASSIGN_MINUS = 322,   /* OPERATOR_ASSIGN_MINUS  */
    OPERATOR_ASSIGN_POWER = 323,   /* OPERATOR_ASSIGN_POWER  */
    OPERATOR_ASSIGN_MULTIPLY = 324, /* OPERATOR_ASSIGN_MULTIPLY  */
    OPERATOR_ASSIGN_DIVIDE = 325,  /* OPERATOR_ASSIGN_DIVIDE  */
    OPERATOR_ASSIGN_MOD = 326,     /* OPERATOR_ASSIGN_MOD  */
    OPERATOR_ASSIGN_SHIFT_LEFT = 327, /* OPERATOR_ASSIGN_SHIFT_LEFT  */
    OPERATOR_ASSIGN_SHIFT_RIGHT = 328, /* OPERATOR_ASSIGN_SHIFT_RIGHT  */
    OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT = 329, /* OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT  */
    OPERATOR_ASSIGN_BITWISE_AND = 330, /* OPERATOR_ASSIGN_BITWISE_AND  */
    OPERATOR_ASSIGN_BITWISE_XOR = 331, /* OPERATOR_ASSIGN_BITWISE_XOR  */
    OPERATOR_ASSIGN_BITWISE_OR = 332, /* OPERATOR_ASSIGN_BITWISE_OR  */
    OPERATOR_ASSIGN_LOGICAL_AND = 333, /* OPERATOR_ASSIGN_LOGICAL_AND  */
    OPERATOR_ASSIGN_LOGICAL_OR = 334, /* OPERATOR_ASSIGN_LOGICAL_OR  */
    OPERATOR_ASSIGN_NULLISH_COALESCING = 335, /* OPERATOR_ASSIGN_NULLISH_COALESCING  */
    COND = 336,                    /* COND  */
    OPERATOR_NULLISH_COALESCING = 337, /* OPERATOR_NULLISH_COALESCING  */
    OPERATOR_LOGICAL_OR = 338,     /* OPERATOR_LOGICAL_OR  */
    OPERATOR_LOGICAL_AND = 339,    /* OPERATOR_LOGICAL_AND  */
    OPERATOR_EQUAL = 340,          /* OPERATOR_EQUAL  */
    OPERATOR_NOT_EQUAL = 341,      /* OPERATOR_NOT_EQUAL  */
    OPERATOR_STRICT_EQUAL = 342,   /* OPERATOR_STRICT_EQUAL  */
    OPERATOR_STRICT_NOT_EQUAL = 343, /* OPERATOR_STRICT_NOT_EQUAL  */
    OPERATOR_GREATER_THAN_EQUAL = 344, /* OPERATOR_GREATER_THAN_EQUAL  */
    OPERATOR_LESS_THAN_EQUAL = 345, /* OPERATOR_LESS_THAN_EQUAL  */
    INSTANCEOF = 346,              /* INSTANCEOF  */
    IN = 347,                      /* IN  */
    OPERATOR_SHIFT_LEFT = 348,     /* OPERATOR_SHIFT_LEFT  */
    OPERATOR_SHIFT_RIGHT = 349,    /* OPERATOR_SHIFT_RIGHT  */
    OPERATOR_UNSIGNED_SHIFT_RIGHT = 350, /* OPERATOR_UNSIGNED_SHIFT_RIGHT  */
    OPERATOR_POWER = 351,          /* OPERATOR_POWER  */
    UMINUS = 352,                  /* UMINUS  */
    UPLUS = 353,                   /* UPLUS  */
    PREF_INCREMENT = 354,          /* PREF_INCREMENT  */
    PREF_DECREMENT = 355,          /* PREF_DECREMENT  */
    DELETE = 356,                  /* DELETE  */
    TYPEOF = 357,                  /* TYPEOF  */
    POST_INCREMENT = 358,          /* POST_INCREMENT  */
    POST_DECREMENT = 359,          /* POST_DECREMENT  */
    ENDL_BRACKET_OPEN = 360,       /* ENDL_BRACKET_OPEN  */
    FUNC_CALL = 361,               /* FUNC_CALL  */
    OPTIONAL_CHAINING_OPERATOR = 362, /* OPTIONAL_CHAINING_OPERATOR  */
    MEMBER_ACCESS = 363            /* MEMBER_ACCESS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 ".\\parser.y"

    int _integer;
    char* _string;
    char* _id;
    double _floatingPoint;

#line 253 "parser.tab.c"

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
  YYSYMBOL_typeReference = 142,            /* typeReference  */
  YYSYMBOL_predefinedType = 143,           /* predefinedType  */
  YYSYMBOL_typeAnnotation = 144,           /* typeAnnotation  */
  YYSYMBOL_arrayLiteral = 145,             /* arrayLiteral  */
  YYSYMBOL_elementList = 146,              /* elementList  */
  YYSYMBOL_arrayElement = 147,             /* arrayElement  */
  YYSYMBOL_expressionListOpt = 148,        /* expressionListOpt  */
  YYSYMBOL_expressionList = 149,           /* expressionList  */
  YYSYMBOL_singleExpression = 150,         /* singleExpression  */
  YYSYMBOL_arguments = 151,                /* arguments  */
  YYSYMBOL_argumentList = 152,             /* argumentList  */
  YYSYMBOL_argument = 153,                 /* argument  */
  YYSYMBOL_varStatement = 154,             /* varStatement  */
  YYSYMBOL_varDeclarationList = 155,       /* varDeclarationList  */
  YYSYMBOL_varDeclaration = 156,           /* varDeclaration  */
  YYSYMBOL_varModifier = 157,              /* varModifier  */
  YYSYMBOL_ifStatement = 158,              /* ifStatement  */
  YYSYMBOL_iterationStatement = 159,       /* iterationStatement  */
  YYSYMBOL_160_1 = 160,                    /* $@1  */
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
  YYSYMBOL_callSignature = 172,            /* callSignature  */
  YYSYMBOL_parameterList = 173,            /* parameterList  */
  YYSYMBOL_parameter = 174,                /* parameter  */
  YYSYMBOL_requiredParameter = 175,        /* requiredParameter  */
  YYSYMBOL_optionalParameter = 176,        /* optionalParameter  */
  YYSYMBOL_restParameter = 177,            /* restParameter  */
  YYSYMBOL_accessibilityModifier = 178,    /* accessibilityModifier  */
  YYSYMBOL_classDeclaration = 179,         /* classDeclaration  */
  YYSYMBOL_classHeritage = 180,            /* classHeritage  */
  YYSYMBOL_classTail = 181,                /* classTail  */
  YYSYMBOL_classElementList = 182,         /* classElementList  */
  YYSYMBOL_classElement = 183,             /* classElement  */
  YYSYMBOL_constructorDeclaration = 184,   /* constructorDeclaration  */
  YYSYMBOL_identifier = 185                /* identifier  */
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
#define YYLAST   1748

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  133
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  223
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  391

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
      97,    98,    99,   100,   101,   102,   103,   104,   109,   113,
     119,   120,   121,   125,   126,   127,   131,   132,   133,   134,
     135,   139,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   163,   168,   169,   173,   174,   175,   179,   180,   186,
     187,   191,   192,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   255,   256,   258,   259,   261,   263,   264,   266,   267,
     268,   270,   274,   275,   276,   280,   281,   285,   286,   292,
     296,   297,   301,   302,   303,   304,   308,   309,   310,   316,
     317,   321,   321,   322,   323,   324,   325,   326,   330,   331,
     335,   336,   340,   341,   345,   349,   350,   354,   355,   356,
     357,   361,   362,   366,   367,   371,   372,   378,   382,   383,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     400,   401,   405,   406,   410,   411,   415,   416,   417,   418,
     422,   423,   429,   430,   431,   435,   439,   443,   444,   448,
     449,   453,   457,   458,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491
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
  "unionOrIntersectionOrPrimaryType", "primaryType", "typeReference",
  "predefinedType", "typeAnnotation", "arrayLiteral", "elementList",
  "arrayElement", "expressionListOpt", "expressionList",
  "singleExpression", "arguments", "argumentList", "argument",
  "varStatement", "varDeclarationList", "varDeclaration", "varModifier",
  "ifStatement", "iterationStatement", "$@1", "continueStatement",
  "breakStatement", "returnStatement", "labelledStatement",
  "blockStatement", "switchStatement", "caseClauseList", "caseClause",
  "defaultClause", "functionDeclaration", "functionBody", "callSignature",
  "parameterList", "parameter", "requiredParameter", "optionalParameter",
  "restParameter", "accessibilityModifier", "classDeclaration",
  "classHeritage", "classTail", "classElementList", "classElement",
  "constructorDeclaration", "identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-299)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     770,  -299,  -299,  -299,   -77,  1690,  1690,   770,   -66,   -63,
    1690,  1690,   -35,  1195,  -299,  -299,  1195,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  1195,  1195,  1195,  1195,  1195,  1195,
    1195,  1195,  1093,  1093,  1195,  -299,   508,    85,   770,  -299,
    -299,   -46,  1390,   -30,  1690,  -299,  -299,   -30,   -30,   -30,
    -299,  -299,  -299,  -299,  -299,    17,  1195,    -8,    77,    91,
    1195,   880,  -299,  -299,  1195,  1390,  -299,    30,    30,    30,
      30,    30,    30,    30,    30,    30,  1195,   -43,  -299,  1390,
     -21,   -41,  -299,   640,  -299,  -299,  1195,  -299,  -299,  -299,
    -299,  -299,  1195,  1195,  1195,  1195,  1195,  1195,  1195,  1195,
    1195,  1195,  1195,  1195,  1195,  1195,  1195,  1195,  1195,  1195,
    1195,  1195,  1195,  1195,  1195,  1195,  1195,  1195,  1195,  1195,
    1195,  1195,  1195,  1195,  1195,  1195,  1195,  1195,  1195,  1195,
    1195,  1195,  1195,  1690,  1195,  1195,   986,  -299,  -299,    43,
    -299,    10,  -299,  -299,  -299,   770,   -39,   146,   -12,  1690,
     -10,    -5,   -38,     4,    56,  1455,  1690,   -37,  1390,  1093,
    -299,  -299,  -299,  -299,  1390,  1517,  1517,  1517,  1517,  1517,
    1517,  1517,  1517,  1517,  1517,  1517,  1517,  1517,  1517,  1517,
    1517,  1260,   619,   965,  1181,  1555,  1592,   494,   494,   494,
     494,    40,    40,    40,    40,    40,    40,   119,   119,   119,
     143,   143,   -49,   -49,   -49,   -49,  -299,    -9,    -6,  1195,
    -299,  1390,   -34,  -299,  1690,  1195,   925,    57,  -299,   770,
    1195,    41,   -33,  -299,  -299,  -299,    -3,   -13,   770,  -299,
    -299,     6,  -299,  1195,   770,  1195,  1195,   -44,    28,     8,
    -299,  1195,  -299,  -299,  1390,   -31,  -299,  -299,  1390,    87,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,   811,   811,
     925,  -299,   -15,    14,  -299,  -299,  1195,   130,  1325,  -299,
     174,    41,    41,  1195,    41,  -299,    73,   770,    23,  -299,
    -299,  -299,    -8,  -299,   120,     9,  -299,  -299,   -22,  -299,
      26,   231,  1195,  1195,    -2,   316,  -299,  -299,  -299,   -15,
     -15,    31,   811,   811,  1137,  1390,   770,  -299,    41,  -299,
      34,  -299,  -299,  1390,  -299,  -299,  -299,    35,    -8,  -299,
    -299,  -299,  1195,   770,    29,   -19,  1195,  -299,    -4,  -299,
    -299,    80,  -299,  -299,    -7,  -299,  -299,    41,   770,    44,
     -30,    45,  -299,  1195,   770,   -18,    93,  -299,  -299,    -1,
    -299,  -299,    64,   770,  -299,   770,    68,  -299,   770,   770,
    -299,     1,  -299,    66,  -299,   770,   770,   770,  -299,  -299,
    -299
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   136,   137,   138,     0,     0,     0,     0,     0,     0,
     148,   150,     0,   152,    55,    54,     0,   209,   205,   206,
     207,   208,   219,   220,   221,   222,   223,   210,   211,   212,
     213,   216,   217,   214,   215,   218,    58,    56,    57,    62,
      60,    61,   204,    59,     0,     0,     0,     0,     0,     0,
       0,     0,    44,    44,     0,     5,     0,     0,     2,     3,
     118,     0,    51,     0,     0,     8,    10,     0,     0,     0,
      14,    15,     9,    16,    17,    53,     0,     0,     0,     0,
       0,    49,   149,   151,     0,   153,    53,   121,    71,    72,
      69,    70,    64,    63,    65,    66,     0,     0,    45,    47,
       0,     0,   155,     0,     1,     4,     0,    18,     6,   113,
      67,    68,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   116,     7,   129,
     130,   132,    11,    12,    13,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,    51,     0,     0,    48,    44,
      42,    43,   115,   156,    52,    87,    91,    92,    98,    88,
      89,    90,    93,    94,   102,    95,    96,    97,    99,   100,
     101,     0,   103,   104,   105,   106,   107,    81,    82,    83,
      84,    79,    78,    86,    85,   111,   112,   108,   109,   110,
      73,    74,    75,    76,    77,    80,   117,     0,     0,     0,
     122,   127,     0,   125,     0,     0,     0,   133,   154,     0,
       0,   170,     0,   180,   182,   183,     0,   184,   168,   196,
      31,     0,   195,     0,     0,    49,     0,     0,   130,     0,
      46,     0,   119,   120,   128,     0,   123,   131,   134,   214,
      40,    39,    37,    33,    34,    32,    35,    36,     0,     0,
       0,    41,    20,    25,    28,    27,     0,   139,   190,   171,
       0,   174,   172,     0,   186,   188,   185,   169,     0,   192,
     193,   194,     0,   197,     0,     0,   199,   201,     0,   143,
       0,   112,    49,     0,     0,   114,   124,   126,    38,    21,
      22,     0,     0,     0,     0,   135,     0,   191,   178,   181,
       0,   175,   173,    19,   187,   189,   167,     0,     0,   198,
     200,   141,    49,     0,     0,     0,     0,   157,     0,   161,
      26,    23,    24,    29,     0,   140,   179,   176,   168,     0,
       0,     0,   146,    49,     0,     0,     0,   158,   162,     0,
      30,   177,     0,   168,   142,     0,     0,   147,   163,   165,
     159,     0,   202,     0,   144,     0,   164,   166,   160,   203,
     145
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -299,  -299,     3,     5,   -54,   -97,   -78,  -210,   -94,    62,
    -299,  -239,  -299,   -52,  -299,  -231,   -50,   349,   -32,  -299,
    -299,  -299,    59,  -135,   156,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -131,  -298,  -299,  -299,  -291,  -260,
    -299,   -48,  -299,  -299,   -45,  -299,  -299,  -299,  -299,  -299,
     -59,  -299,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    57,   297,    59,   108,   295,   281,   282,   283,   284,
     285,   237,    60,    97,    98,   173,    61,    62,   157,   232,
     233,    63,   159,   160,    64,    65,    66,   360,    67,    68,
      69,    70,    71,    72,   348,   349,   369,    73,   298,   168,
     242,   243,   244,   245,   246,   304,    74,   170,   252,   305,
     306,   307,    86
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      75,   100,   289,    58,   101,    77,    78,    75,   296,   158,
      82,    83,    79,   162,   163,   164,   346,   366,   346,   346,
     106,   346,   234,   179,   310,   106,   166,   106,   106,   106,
     172,   174,   265,   290,   177,   299,   300,   301,   299,   300,
     301,   258,   337,   302,   106,   179,   302,   106,   106,   327,
     368,    76,   331,   332,   293,   334,    75,   106,    75,   103,
     106,   152,    80,   105,   161,    81,   378,   372,   319,   320,
     294,   236,   153,   154,   322,   155,   323,   235,   359,   156,
     180,   344,   383,   368,   107,   104,   312,   169,   182,   356,
     239,   254,   259,    84,   236,   266,   291,   156,   316,   267,
     107,   165,   181,    75,   227,   228,   171,   341,   105,   234,
     364,   361,   351,   352,   262,   324,   370,   263,   371,   248,
     167,   251,   106,   253,   286,   236,   292,   260,   367,   313,
     347,   380,   376,   388,   255,   318,   324,   326,   303,   314,
     293,   339,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   226,   155,   336,   342,   338,   156,   363,
     350,   153,   154,   357,   155,    75,   358,   247,   156,   250,
     238,   323,   240,    17,   375,   373,   161,   379,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,   382,   385,   389,   335,
     240,    17,   321,   308,    42,   174,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,   147,   148,   149,   150,   151,   152,
     354,   249,    42,   317,   161,   257,   250,   176,   381,    75,
     153,   154,   329,   155,   287,   330,   340,   156,    75,     0,
     149,   150,   151,   152,    75,     0,     0,     0,     0,   309,
       0,     0,   174,   345,   153,   154,     0,   155,     0,     0,
       0,   156,     0,     0,     0,   241,     0,     0,   250,   250,
     250,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     247,     0,   174,     0,     0,     0,   365,    75,     0,     0,
       0,     0,   105,   328,     0,     0,   374,     0,     0,     0,
       0,     0,     0,   174,     0,     0,     0,     0,     0,     0,
       0,     0,   250,   250,   250,     0,    75,     0,     0,     0,
       0,   355,     0,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,    75,     0,     0,     0,     0,   362,     0,
       0,     0,   153,   154,     0,   155,     0,     0,    75,   156,
     343,     0,    85,     0,    75,    87,     0,     0,     0,   377,
       0,     0,     0,    75,     0,    75,     0,     0,    75,    75,
     384,   386,   387,     0,     0,    75,    75,    75,     0,     0,
     390,   105,   105,    88,    89,    90,    91,    92,    93,    94,
      95,    99,    99,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,     0,     0,     0,
     175,     0,     0,     0,     0,     0,     0,   153,   154,     0,
     155,     0,     0,     0,   156,   178,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   184,     0,     0,     0,     0,
       0,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,     0,     0,     0,   231,     0,     0,     0,     0,
       0,     1,     2,     3,     4,     0,     5,     6,     0,     0,
       0,     0,     7,     8,     9,    10,    11,    12,    99,     0,
      13,    14,    15,    16,     0,    17,     0,     0,     0,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     0,     0,
      36,    37,    38,    39,    40,    41,    42,     0,    43,    44,
      45,    46,    47,     0,     0,     0,     0,     0,   264,     0,
       0,     0,     0,     0,   268,     0,     0,     0,     0,   288,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   311,     0,     0,     0,     0,
     315,     0,     0,    48,    49,   153,   154,     0,   155,    50,
      51,     0,   156,     0,     0,     0,     0,     0,     0,     0,
      52,     0,    53,     0,     0,   325,    54,     0,    55,    56,
     102,     0,   333,     1,     2,     3,     4,     0,     5,     6,
       0,     0,     0,     0,     7,     8,     9,    10,    11,    12,
       0,     0,    13,    14,    15,    16,     0,    17,     0,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,    36,    37,    38,    39,    40,    41,    42,     0,
      43,    44,    45,    46,    47,     0,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     153,   154,     0,   155,     0,    48,    49,   156,     0,     0,
       0,    50,    51,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,     0,    53,     0,     0,     0,    54,     0,
      55,    56,   183,     1,     2,     3,     4,     0,     5,     6,
       0,     0,     0,     0,     7,     8,     9,    10,    11,    12,
       0,     0,    13,    14,    15,    16,     0,    17,     0,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,    36,    37,    38,    39,    40,    41,    42,     0,
      43,    44,    45,    46,    47,     0,     0,     0,    17,     0,
       0,     0,     0,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,   269,    34,
      35,   270,   271,   272,   273,   274,   275,   276,   277,    42,
       0,     0,     0,     0,     0,    48,    49,     0,     0,     0,
       0,    50,    51,     1,     2,     3,     0,     0,     0,     0,
       0,     0,    52,     0,    53,     0,     0,     0,    54,     0,
      55,    56,     0,    14,    15,    16,     0,    17,     0,     0,
       0,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,    36,    37,    38,    39,    40,    41,    42,   280,
      43,    44,    45,    46,    47,     0,     0,     0,     0,     0,
       0,     0,    17,     0,     0,     0,     0,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,   269,    34,    35,   270,   271,   272,   273,   274,
     275,   276,   277,    42,     0,    48,    49,     0,     0,     0,
       0,    50,    51,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,     0,    53,     0,     0,     0,    54,    14,
      15,    16,   229,    17,   278,     0,   279,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,     0,    36,    37,
      38,    39,    40,    41,    42,     0,    43,    44,    45,    46,
      47,     0,     0,   280,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   153,   154,     0,   155,
       0,    48,    49,   156,     0,     0,     0,    50,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,     0,
      53,     0,     0,     0,    54,   230,    14,    15,    16,    96,
      17,     0,     0,     0,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,    36,    37,    38,    39,    40,
      41,    42,     0,    43,    44,    45,    46,    47,     0,     0,
       0,     0,     0,     0,    17,     0,     0,     0,     0,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,   269,    34,    35,   270,   271,   272,
     273,   274,   275,   276,   277,    42,     0,     0,    48,    49,
       0,     0,     0,     0,    50,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,     0,    53,    14,    15,
      16,    54,    17,     0,     0,     0,     0,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,     0,    36,    37,    38,
      39,    40,    41,    42,     0,    43,    44,    45,    46,    47,
     353,     0,     0,     0,     0,   280,     0,     0,     0,     0,
       0,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,     0,     0,     0,     0,     0,     0,     0,
      48,    49,   153,   154,     0,   155,    50,    51,     0,   156,
       0,     0,     0,     0,     0,     0,     0,    52,     0,    53,
     109,   110,   111,    54,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   261,     0,     0,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   153,   154,     0,   155,   109,   110,   111,   156,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   236,
       0,     0,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   153,   154,     0,   155,
     109,   110,   111,   156,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,     0,     0,     0,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   153,   154,     0,   155,   109,   110,   111,   156,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,     0,
       0,     0,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   256,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   153,   154,     0,   155,
       0,     0,     0,   156,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,     0,     0,     0,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   153,   154,
       0,   155,     0,     0,     0,   156,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   153,   154,     0,   155,
       0,     0,     0,   156,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   153,   154,     0,   155,    17,     0,     0,
     156,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,    42
};

static const yytype_int16 yycheck[] =
{
       0,    53,   241,     0,    54,     5,     6,     7,   247,    63,
      10,    11,     7,    67,    68,    69,    20,    21,    20,    20,
      66,    20,    66,    66,   255,    66,    76,    66,    66,    66,
      80,    81,    66,    66,    84,    29,    30,    31,    29,    30,
      31,   176,   302,    37,    66,    66,    37,    66,    66,   288,
     348,   128,   291,   292,    67,   294,    56,    66,    58,    56,
      66,   110,   128,    58,    64,   128,    84,   358,   278,   279,
      83,    84,   121,   122,    89,   124,    91,    67,   338,   128,
     123,   312,   373,   381,   130,     0,   130,    10,   129,   328,
     129,   129,   129,   128,    84,   129,   129,   128,   129,   234,
     130,    84,   123,   103,   154,   155,    15,   129,   103,    66,
     129,   342,   322,   323,   123,   122,   123,   123,   357,   131,
     128,   131,    66,   128,    67,    84,   129,   179,   132,   101,
     132,   132,   363,   132,   130,    48,   122,     7,   132,   131,
      67,   132,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   121,   122,   153,   124,   132,   130,    37,   128,   130,
     129,   121,   122,   129,   124,   165,   131,   167,   128,   169,
     165,    91,    26,    27,   129,   131,   176,    84,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,   132,   129,   132,   296,
      26,    27,   280,   253,    58,   255,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,   105,   106,   107,   108,   109,   110,
     324,   169,    58,   265,   234,   176,   236,    81,   369,   239,
     121,   122,   290,   124,   239,   290,   305,   128,   248,    -1,
     107,   108,   109,   110,   254,    -1,    -1,    -1,    -1,   254,
      -1,    -1,   312,   313,   121,   122,    -1,   124,    -1,    -1,
      -1,   128,    -1,    -1,    -1,   129,    -1,    -1,   278,   279,
     280,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     290,    -1,   342,    -1,    -1,    -1,   346,   297,    -1,    -1,
      -1,    -1,   297,   129,    -1,    -1,   360,    -1,    -1,    -1,
      -1,    -1,    -1,   363,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   322,   323,   324,    -1,   326,    -1,    -1,    -1,
      -1,   326,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    -1,   343,    -1,    -1,    -1,    -1,   343,    -1,
      -1,    -1,   121,   122,    -1,   124,    -1,    -1,   358,   128,
     129,    -1,    13,    -1,   364,    16,    -1,    -1,    -1,   364,
      -1,    -1,    -1,   373,    -1,   375,    -1,    -1,   378,   379,
     375,   378,   379,    -1,    -1,   385,   386,   387,    -1,    -1,
     385,   386,   387,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,    -1,
     124,    -1,    -1,    -1,   128,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    14,    15,    16,    17,    18,    19,   179,    -1,
      22,    23,    24,    25,    -1,    27,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      52,    53,    54,    55,    56,    57,    58,    -1,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,   240,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   256,    -1,    -1,    -1,    -1,
     261,    -1,    -1,   105,   106,   121,   122,    -1,   124,   111,
     112,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     122,    -1,   124,    -1,    -1,   286,   128,    -1,   130,   131,
     132,    -1,   293,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,    19,
      -1,    -1,    22,    23,    24,    25,    -1,    27,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    61,    62,    63,    64,    -1,    -1,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,   122,    -1,   124,    -1,   105,   106,   128,    -1,    -1,
      -1,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   122,    -1,   124,    -1,    -1,    -1,   128,    -1,
     130,   131,   132,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,    19,
      -1,    -1,    22,    23,    24,    25,    -1,    27,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,
      -1,   111,   112,     3,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,   122,    -1,   124,    -1,    -1,    -1,   128,    -1,
     130,   131,    -1,    23,    24,    25,    -1,    27,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    52,    53,    54,    55,    56,    57,    58,   128,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,   105,   106,    -1,    -1,    -1,
      -1,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   122,    -1,   124,    -1,    -1,    -1,   128,    23,
      24,    25,    26,    27,    89,    -1,    91,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    52,    53,
      54,    55,    56,    57,    58,    -1,    60,    61,    62,    63,
      64,    -1,    -1,   128,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,    -1,   124,
      -1,   105,   106,   128,    -1,    -1,    -1,   111,   112,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,
     124,    -1,    -1,    -1,   128,   129,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    52,    53,    54,    55,    56,
      57,    58,    -1,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,    -1,   105,   106,
      -1,    -1,    -1,    -1,   111,   112,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   122,    -1,   124,    23,    24,
      25,   128,    27,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    52,    53,    54,
      55,    56,    57,    58,    -1,    60,    61,    62,    63,    64,
     123,    -1,    -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     105,   106,   121,   122,    -1,   124,   111,   112,    -1,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,   124,
      60,    61,    62,   128,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    -1,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,    -1,   124,    60,    61,    62,   128,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      -1,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,    -1,   124,
      60,    61,    62,   128,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,    -1,   124,    60,    61,    62,   128,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    -1,
      -1,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,    -1,   124,
      -1,    -1,    -1,   128,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
      -1,   124,    -1,    -1,    -1,   128,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,    -1,   124,
      -1,    -1,    -1,   128,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,    -1,   124,    27,    -1,    -1,
     128,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     8,     9,    14,    15,    16,
      17,    18,    19,    22,    23,    24,    25,    27,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    52,    53,    54,    55,
      56,    57,    58,    60,    61,    62,    63,    64,   105,   106,
     111,   112,   122,   124,   128,   130,   131,   134,   135,   136,
     145,   149,   150,   154,   157,   158,   159,   161,   162,   163,
     164,   165,   166,   170,   179,   185,   128,   185,   185,   136,
     128,   128,   185,   185,   128,   150,   185,   150,   150,   150,
     150,   150,   150,   150,   150,   150,    26,   146,   147,   150,
     146,   149,   132,   135,     0,   136,    66,   130,   137,    60,
      61,    62,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   121,   122,   124,   128,   151,   137,   155,
     156,   185,   137,   137,   137,    84,   149,   128,   172,    10,
     180,    15,   149,   148,   149,   150,   157,   149,   150,    66,
     123,   123,   129,   132,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   185,   149,   149,    26,
     129,   150,   152,   153,    66,    67,    84,   144,   136,   129,
      26,   129,   173,   174,   175,   176,   177,   185,   131,   142,
     185,   131,   181,   128,   129,   130,   101,   155,   156,   129,
     146,    84,   123,   123,   150,    66,   129,   156,   150,    47,
      50,    51,    52,    53,    54,    55,    56,    57,    89,    91,
     128,   139,   140,   141,   142,   143,    67,   136,   150,   144,
      66,   129,   129,    67,    83,   138,   144,   135,   171,    29,
      30,    31,    37,   132,   178,   182,   183,   184,   149,   136,
     148,   150,   130,   101,   131,   150,   129,   151,    48,   140,
     140,   139,    89,    91,   122,   150,     7,   144,   129,   174,
     177,   144,   144,   150,   144,   138,   132,   172,    37,   132,
     183,   129,   130,   129,   148,   149,    20,   132,   167,   168,
     129,   140,   140,   123,   141,   136,   144,   129,   131,   172,
     160,   148,   136,   130,   129,   149,    21,   132,   168,   169,
     123,   144,   171,   131,   137,   129,   148,   136,    84,    84,
     132,   167,   132,   171,   136,   129,   135,   135,   132,   132,
     136
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   133,   134,   135,   135,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   137,   138,
     139,   139,   139,   140,   140,   140,   141,   141,   141,   141,
     141,   142,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   144,   145,   145,   146,   146,   146,   147,   147,   148,
     148,   149,   149,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   151,   151,   151,   152,   152,   153,   153,   154,
     155,   155,   156,   156,   156,   156,   157,   157,   157,   158,
     158,   160,   159,   159,   159,   159,   159,   159,   161,   161,
     162,   162,   163,   163,   164,   165,   165,   166,   166,   166,
     166,   167,   167,   168,   168,   169,   169,   170,   171,   171,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     173,   173,   174,   174,   175,   175,   176,   176,   176,   176,
     177,   177,   178,   178,   178,   179,   180,   181,   181,   182,
     182,   183,   184,   184,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     2,     1,     1,
       1,     2,     2,     2,     1,     1,     1,     1,     1,     2,
       1,     2,     2,     3,     3,     1,     3,     1,     1,     3,
       4,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     2,     3,     3,     0,     1,     3,     1,     2,     0,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     5,     3,     2,     3,     1,     4,
       4,     2,     2,     3,     4,     1,     3,     1,     2,     2,
       1,     3,     1,     2,     3,     4,     1,     1,     1,     5,
       7,     0,     8,     5,     9,    10,     7,     8,     1,     2,
       1,     2,     1,     2,     3,     2,     3,     6,     7,     8,
       9,     1,     2,     3,     4,     2,     3,     6,     0,     1,
       2,     3,     3,     4,     3,     4,     5,     6,     4,     5,
       1,     3,     1,     1,     1,     2,     2,     3,     2,     3,
       2,     3,     1,     1,     1,     4,     2,     2,     3,     1,
       2,     1,     5,     6,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
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
#line 83 ".\\parser.y"
                    { Print("- R: statementList -> script"); }
#line 2398 "parser.tab.c"
    break;

  case 3: /* statementList: statementListItem  */
#line 87 ".\\parser.y"
                        { Print("- R: statementListItem -> statementList"); }
#line 2404 "parser.tab.c"
    break;

  case 4: /* statementList: statementList statementListItem  */
#line 88 ".\\parser.y"
                                      { Print("- R: statementList statementListItem -> statementList"); }
#line 2410 "parser.tab.c"
    break;

  case 5: /* statementListItem: ';'  */
#line 92 ".\\parser.y"
          { Print("- R: ';' -> statementListItem"); }
#line 2416 "parser.tab.c"
    break;

  case 6: /* statementListItem: expressionList statementSep  */
#line 93 ".\\parser.y"
                                  { Print("- R: expressionList statementSep -> statementListItem"); }
#line 2422 "parser.tab.c"
    break;

  case 11: /* statementListItem: continueStatement statementSep  */
#line 98 ".\\parser.y"
                                     { Print("- R: continueStatement statementSep -> statementListItem");  }
#line 2428 "parser.tab.c"
    break;

  case 12: /* statementListItem: breakStatement statementSep  */
#line 99 ".\\parser.y"
                                  { Print("- R: breakStatement statementSep -> statementListItem"); }
#line 2434 "parser.tab.c"
    break;

  case 13: /* statementListItem: returnStatement statementSep  */
#line 100 ".\\parser.y"
                                   { Print("- R: returnStatement statementSep -> statementListItem"); }
#line 2440 "parser.tab.c"
    break;

  case 18: /* statementSep: ';'  */
#line 109 ".\\parser.y"
          { Print("- R: ';' -> statementSep"); }
#line 2446 "parser.tab.c"
    break;

  case 19: /* initializer: '=' singleExpression  */
#line 113 ".\\parser.y"
                           { Print("- R: '=' singleExpression -> initializer"); }
#line 2452 "parser.tab.c"
    break;

  case 20: /* type: unionOrIntersectionOrPrimaryType  */
#line 119 ".\\parser.y"
                                       { Print("- R: unionOrIntersectionOrPrimaryType -> type"); }
#line 2458 "parser.tab.c"
    break;

  case 21: /* type: '|' unionOrIntersectionOrPrimaryType  */
#line 120 ".\\parser.y"
                                           { Print("- R: '|' unionOrIntersectionOrPrimaryType -> type"); }
#line 2464 "parser.tab.c"
    break;

  case 22: /* type: '&' unionOrIntersectionOrPrimaryType  */
#line 121 ".\\parser.y"
                                           { Print("- R: '&' unionOrIntersectionOrPrimaryType -> type"); }
#line 2470 "parser.tab.c"
    break;

  case 23: /* unionOrIntersectionOrPrimaryType: unionOrIntersectionOrPrimaryType '|' unionOrIntersectionOrPrimaryType  */
#line 125 ".\\parser.y"
                                                                            { Print("- R: unionOrIntersectionOrPrimaryType '|' unionOrIntersectionOrPrimaryType -> unionOrIntersectionOrPrimaryType"); }
#line 2476 "parser.tab.c"
    break;

  case 24: /* unionOrIntersectionOrPrimaryType: unionOrIntersectionOrPrimaryType '&' unionOrIntersectionOrPrimaryType  */
#line 126 ".\\parser.y"
                                                                            { Print("- R: unionOrIntersectionOrPrimaryType '&' unionOrIntersectionOrPrimaryType -> unionOrIntersectionOrPrimaryType"); }
#line 2482 "parser.tab.c"
    break;

  case 25: /* unionOrIntersectionOrPrimaryType: primaryType  */
#line 127 ".\\parser.y"
                  { Print("- R: primaryType -> argument"); }
#line 2488 "parser.tab.c"
    break;

  case 26: /* primaryType: '(' type ')'  */
#line 131 ".\\parser.y"
                   { Print("- R: '(' type ')' -> primaryType"); }
#line 2494 "parser.tab.c"
    break;

  case 27: /* primaryType: predefinedType  */
#line 132 ".\\parser.y"
                     { Print("- R: predefinedType -> primaryType"); }
#line 2500 "parser.tab.c"
    break;

  case 28: /* primaryType: typeReference  */
#line 133 ".\\parser.y"
                    { Print("- R: typeReference -> primaryType"); }
#line 2506 "parser.tab.c"
    break;

  case 29: /* primaryType: primaryType '[' ']'  */
#line 134 ".\\parser.y"
                          { Print("- R: primaryType ENDL_BRACKET_OPEN ']' -> primaryType"); }
#line 2512 "parser.tab.c"
    break;

  case 30: /* primaryType: primaryType '[' primaryType ']'  */
#line 135 ".\\parser.y"
                                      { Print("- R: primaryType ENDL_BRACKET_OPEN primaryType ']' -> primaryType"); }
#line 2518 "parser.tab.c"
    break;

  case 31: /* typeReference: identifier  */
#line 139 ".\\parser.y"
                 { Print("- R: identifier -> typeReference"); }
#line 2524 "parser.tab.c"
    break;

  case 32: /* predefinedType: NULL_KW  */
#line 143 ".\\parser.y"
              { Print("- R: NULL_LITERAL -> predefinedType"); }
#line 2530 "parser.tab.c"
    break;

  case 33: /* predefinedType: INT_LIT  */
#line 144 ".\\parser.y"
              { Print("- R: INT_LIT -> predefinedType"); }
#line 2536 "parser.tab.c"
    break;

  case 34: /* predefinedType: FLOAT_LIT  */
#line 145 ".\\parser.y"
                { Print("- R: FLOAT_LIT -> predefinedType"); }
#line 2542 "parser.tab.c"
    break;

  case 35: /* predefinedType: TRUE_KW  */
#line 146 ".\\parser.y"
              { Print("- R: TRUE_LITERAL -> predefinedType"); }
#line 2548 "parser.tab.c"
    break;

  case 36: /* predefinedType: FALSE_KW  */
#line 147 ".\\parser.y"
               { Print("- R: FALSE_LITERAL -> predefinedType"); }
#line 2554 "parser.tab.c"
    break;

  case 37: /* predefinedType: STRING_LIT  */
#line 148 ".\\parser.y"
                 { Print("- R: STRING_LIT -> predefinedType"); }
#line 2560 "parser.tab.c"
    break;

  case 38: /* predefinedType: UNIQUE SYMBOL  */
#line 149 ".\\parser.y"
                    { Print("- R: UNIQUE SYMBOL -> predefinedType"); }
#line 2566 "parser.tab.c"
    break;

  case 39: /* predefinedType: UNKNOWN  */
#line 150 ".\\parser.y"
              { Print("- R: UNKNOWN -> predefinedType"); }
#line 2572 "parser.tab.c"
    break;

  case 40: /* predefinedType: VOID  */
#line 151 ".\\parser.y"
           { Print("- R: VOID -> predefinedType"); }
#line 2578 "parser.tab.c"
    break;

  case 41: /* typeAnnotation: ':' type  */
#line 163 ".\\parser.y"
               { Print("- R: ':' type -> typeAnnotation"); }
#line 2584 "parser.tab.c"
    break;

  case 42: /* arrayLiteral: '[' elementList ']'  */
#line 168 ".\\parser.y"
                          { Print("- R: [ elementList ']' -> arrayLiteral"); }
#line 2590 "parser.tab.c"
    break;

  case 43: /* arrayLiteral: ENDL_BRACKET_OPEN elementList ']'  */
#line 169 ".\\parser.y"
                                        { Print("- R: ENDL_BRACKET_OPEN elementList ']' -> arrayLiteral"); }
#line 2596 "parser.tab.c"
    break;

  case 44: /* elementList: %empty  */
#line 173 ".\\parser.y"
                  { Print("- R: #empty# -> elementList"); }
#line 2602 "parser.tab.c"
    break;

  case 45: /* elementList: arrayElement  */
#line 174 ".\\parser.y"
                   { Print("- R: arrayElement -> elementList"); }
#line 2608 "parser.tab.c"
    break;

  case 46: /* elementList: elementList ',' elementList  */
#line 175 ".\\parser.y"
                                  { Print("- R: elementList ',' elementList -> elementList"); }
#line 2614 "parser.tab.c"
    break;

  case 47: /* arrayElement: singleExpression  */
#line 179 ".\\parser.y"
                       { Print("- R: singleExpression -> arrayElement"); }
#line 2620 "parser.tab.c"
    break;

  case 48: /* arrayElement: ELLIPSIS singleExpression  */
#line 180 ".\\parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> arrayElement"); }
#line 2626 "parser.tab.c"
    break;

  case 49: /* expressionListOpt: %empty  */
#line 186 ".\\parser.y"
                  { Print("- R: #empty# -> expressionListOpt"); }
#line 2632 "parser.tab.c"
    break;

  case 50: /* expressionListOpt: expressionList  */
#line 187 ".\\parser.y"
                     { Print("- R: expressionList -> expressionListOpt"); }
#line 2638 "parser.tab.c"
    break;

  case 51: /* expressionList: singleExpression  */
#line 191 ".\\parser.y"
                       { Print("- R: singleExpression -> expressionList"); }
#line 2644 "parser.tab.c"
    break;

  case 52: /* expressionList: expressionList ',' singleExpression  */
#line 192 ".\\parser.y"
                                          { Print("- R: expressionList ',' singleExpression -> expressionList"); }
#line 2650 "parser.tab.c"
    break;

  case 53: /* singleExpression: identifier  */
#line 196 ".\\parser.y"
                 { Print("- R: identifier -> singleExpression"); }
#line 2656 "parser.tab.c"
    break;

  case 54: /* singleExpression: THIS  */
#line 197 ".\\parser.y"
           { Print("- R: THIS -> singleExpression"); }
#line 2662 "parser.tab.c"
    break;

  case 55: /* singleExpression: SUPER  */
#line 198 ".\\parser.y"
            { Print("- R: SUPER -> singleExpression"); }
#line 2668 "parser.tab.c"
    break;

  case 56: /* singleExpression: INT_LIT  */
#line 199 ".\\parser.y"
              { Print("- R: INT_LIT -> singleExpression"); }
#line 2674 "parser.tab.c"
    break;

  case 57: /* singleExpression: FLOAT_LIT  */
#line 200 ".\\parser.y"
                { Print("- R: FLOAT_LIT -> singleExpression"); }
#line 2680 "parser.tab.c"
    break;

  case 58: /* singleExpression: STRING_LIT  */
#line 201 ".\\parser.y"
                 { Print("- R: STRING_LIT -> singleExpression"); }
#line 2686 "parser.tab.c"
    break;

  case 59: /* singleExpression: TEMPLATE_LITERAL  */
#line 202 ".\\parser.y"
                       { Print("- R: TEMPLATE_LITERAL -> singleExpression"); }
#line 2692 "parser.tab.c"
    break;

  case 60: /* singleExpression: TRUE_KW  */
#line 203 ".\\parser.y"
              { Print("- R: TRUE_LITERAL -> singleExpression"); }
#line 2698 "parser.tab.c"
    break;

  case 61: /* singleExpression: FALSE_KW  */
#line 204 ".\\parser.y"
               { Print("- R: FALSE_LITERAL -> singleExpression"); }
#line 2704 "parser.tab.c"
    break;

  case 62: /* singleExpression: NULL_KW  */
#line 205 ".\\parser.y"
              { Print("- R: NULL_LITERAL -> singleExpression"); }
#line 2710 "parser.tab.c"
    break;

  case 63: /* singleExpression: '-' singleExpression  */
#line 206 ".\\parser.y"
                                        { Print("- R: '-' singleExpression -> singleExpression"); }
#line 2716 "parser.tab.c"
    break;

  case 64: /* singleExpression: '+' singleExpression  */
#line 207 ".\\parser.y"
                                       { Print("- R: '+'s singleExpression -> singleExpression"); }
#line 2722 "parser.tab.c"
    break;

  case 65: /* singleExpression: '!' singleExpression  */
#line 208 ".\\parser.y"
                           { Print("- R: '!' singleExpression -> singleExpression"); }
#line 2728 "parser.tab.c"
    break;

  case 66: /* singleExpression: '~' singleExpression  */
#line 209 ".\\parser.y"
                           { Print("- R: '~' singleExpression -> singleExpression"); }
#line 2734 "parser.tab.c"
    break;

  case 67: /* singleExpression: singleExpression OPERATOR_INCREMENT  */
#line 210 ".\\parser.y"
                                                               { Print("- R: singleExpression OPERATOR_INCREMENT -> singleExpression"); }
#line 2740 "parser.tab.c"
    break;

  case 68: /* singleExpression: singleExpression OPERATOR_DECREMENT  */
#line 211 ".\\parser.y"
                                                               { Print("- R: singleExpression OPERATOR_DECREMENT -> singleExpression"); }
#line 2746 "parser.tab.c"
    break;

  case 69: /* singleExpression: ENDL_OPERATOR_INCREMENT singleExpression  */
#line 212 ".\\parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 2752 "parser.tab.c"
    break;

  case 70: /* singleExpression: ENDL_OPERATOR_DECREMENT singleExpression  */
#line 213 ".\\parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 2758 "parser.tab.c"
    break;

  case 71: /* singleExpression: OPERATOR_INCREMENT singleExpression  */
#line 214 ".\\parser.y"
                                                               { Print("- R: OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 2764 "parser.tab.c"
    break;

  case 72: /* singleExpression: OPERATOR_DECREMENT singleExpression  */
#line 215 ".\\parser.y"
                                                               { Print("- R: OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 2770 "parser.tab.c"
    break;

  case 73: /* singleExpression: singleExpression '+' singleExpression  */
#line 216 ".\\parser.y"
                                            { Print("- R: singleExpression '+' singleExpression -> singleExpression"); }
#line 2776 "parser.tab.c"
    break;

  case 74: /* singleExpression: singleExpression '-' singleExpression  */
#line 217 ".\\parser.y"
                                            { Print("- R: singleExpression '-' singleExpression -> singleExpression"); }
#line 2782 "parser.tab.c"
    break;

  case 75: /* singleExpression: singleExpression '*' singleExpression  */
#line 218 ".\\parser.y"
                                            { Print("- R: singleExpression '*' singleExpression -> singleExpression"); }
#line 2788 "parser.tab.c"
    break;

  case 76: /* singleExpression: singleExpression '/' singleExpression  */
#line 219 ".\\parser.y"
                                            { Print("- R: singleExpression '/' singleExpression -> singleExpression"); }
#line 2794 "parser.tab.c"
    break;

  case 77: /* singleExpression: singleExpression '%' singleExpression  */
#line 220 ".\\parser.y"
                                            { Print("- R: singleExpression '%' singleExpression -> singleExpression"); }
#line 2800 "parser.tab.c"
    break;

  case 78: /* singleExpression: singleExpression '<' singleExpression  */
#line 221 ".\\parser.y"
                                            { Print("- R: singleExpression '<' singleExpression -> singleExpression"); }
#line 2806 "parser.tab.c"
    break;

  case 79: /* singleExpression: singleExpression '>' singleExpression  */
#line 222 ".\\parser.y"
                                            { Print("- R: singleExpression '>' singleExpression -> singleExpression"); }
#line 2812 "parser.tab.c"
    break;

  case 80: /* singleExpression: singleExpression OPERATOR_POWER singleExpression  */
#line 223 ".\\parser.y"
                                                       { Print("- R: singleExpression OPERATOR_POWER singleExpression -> singleExpression"); }
#line 2818 "parser.tab.c"
    break;

  case 81: /* singleExpression: singleExpression OPERATOR_EQUAL singleExpression  */
#line 224 ".\\parser.y"
                                                       { Print("- R: singleExpression OPERATOR_EQUAL singleExpression -> singleExpression"); }
#line 2824 "parser.tab.c"
    break;

  case 82: /* singleExpression: singleExpression OPERATOR_NOT_EQUAL singleExpression  */
#line 225 ".\\parser.y"
                                                           { Print("- R: singleExpression OPERATOR_NOT_EQUAL singleExpression -> singleExpression"); }
#line 2830 "parser.tab.c"
    break;

  case 83: /* singleExpression: singleExpression OPERATOR_STRICT_EQUAL singleExpression  */
#line 226 ".\\parser.y"
                                                              { Print("- R: singleExpression OPERATOR_STRICT_EQUAL singleExpression -> singleExpression"); }
#line 2836 "parser.tab.c"
    break;

  case 84: /* singleExpression: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression  */
#line 227 ".\\parser.y"
                                                                  { Print("- R: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression -> singleExpression"); }
#line 2842 "parser.tab.c"
    break;

  case 85: /* singleExpression: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression  */
#line 228 ".\\parser.y"
                                                                 { Print("- R: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression -> singleExpression"); }
#line 2848 "parser.tab.c"
    break;

  case 86: /* singleExpression: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression  */
#line 229 ".\\parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression -> singleExpression"); }
#line 2854 "parser.tab.c"
    break;

  case 87: /* singleExpression: singleExpression '=' singleExpression  */
#line 230 ".\\parser.y"
                                            { Print("- R: singleExpression '=' singleExpression -> singleExpression"); }
#line 2860 "parser.tab.c"
    break;

  case 88: /* singleExpression: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression  */
#line 231 ".\\parser.y"
                                                                 { Print("- R: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression -> singleExpression"); }
#line 2866 "parser.tab.c"
    break;

  case 89: /* singleExpression: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression  */
#line 232 ".\\parser.y"
                                                               { Print("- R: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression -> singleExpression"); }
#line 2872 "parser.tab.c"
    break;

  case 90: /* singleExpression: singleExpression OPERATOR_ASSIGN_MOD singleExpression  */
#line 233 ".\\parser.y"
                                                            { Print("- R: singleExpression OPERATOR_ASSIGN_MOD singleExpression -> singleExpression"); }
#line 2878 "parser.tab.c"
    break;

  case 91: /* singleExpression: singleExpression OPERATOR_ASSIGN_PLUS singleExpression  */
#line 234 ".\\parser.y"
                                                             { Print("- R: singleExpression OPERATOR_ASSIGN_PLUS singleExpression -> singleExpression"); }
#line 2884 "parser.tab.c"
    break;

  case 92: /* singleExpression: singleExpression OPERATOR_ASSIGN_MINUS singleExpression  */
#line 235 ".\\parser.y"
                                                              { Print("- R: singleExpression OPERATOR_ASSIGN_MINUS singleExpression -> singleExpression"); }
#line 2890 "parser.tab.c"
    break;

  case 93: /* singleExpression: singleExpression OPERATOR_ASSIGN_SHIFT_LEFT singleExpression  */
#line 236 ".\\parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_SHIFT_LEFT singleExpression -> singleExpression"); }
#line 2896 "parser.tab.c"
    break;

  case 94: /* singleExpression: singleExpression OPERATOR_ASSIGN_SHIFT_RIGHT singleExpression  */
#line 237 ".\\parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 2902 "parser.tab.c"
    break;

  case 95: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_AND singleExpression  */
#line 238 ".\\parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_AND singleExpression -> singleExpression"); }
#line 2908 "parser.tab.c"
    break;

  case 96: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_XOR singleExpression  */
#line 239 ".\\parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_XOR singleExpression -> singleExpression"); }
#line 2914 "parser.tab.c"
    break;

  case 97: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_OR singleExpression  */
#line 240 ".\\parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_OR singleExpression -> singleExpression"); }
#line 2920 "parser.tab.c"
    break;

  case 98: /* singleExpression: singleExpression OPERATOR_ASSIGN_POWER singleExpression  */
#line 241 ".\\parser.y"
                                                              { Print("- R: singleExpression OPERATOR_ASSIGN_POWER singleExpression -> singleExpression"); }
#line 2926 "parser.tab.c"
    break;

  case 99: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression  */
#line 242 ".\\parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression -> singleExpression"); }
#line 2932 "parser.tab.c"
    break;

  case 100: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression  */
#line 243 ".\\parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression -> singleExpression"); }
#line 2938 "parser.tab.c"
    break;

  case 101: /* singleExpression: singleExpression OPERATOR_ASSIGN_NULLISH_COALESCING singleExpression  */
#line 244 ".\\parser.y"
                                                                           { Print("- R: singleExpression OPERATOR_ASSIGN_NULLISH_COALESCING singleExpression -> singleExpression"); }
#line 2944 "parser.tab.c"
    break;

  case 102: /* singleExpression: singleExpression OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT singleExpression  */
#line 245 ".\\parser.y"
                                                                             { Print("- R: singleExpression OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 2950 "parser.tab.c"
    break;

  case 103: /* singleExpression: singleExpression OPERATOR_LOGICAL_OR singleExpression  */
#line 246 ".\\parser.y"
                                                            { Print("- R: singleExpression OPERATOR_LOGICAL_OR singleExpression -> singleExpression"); }
#line 2956 "parser.tab.c"
    break;

  case 104: /* singleExpression: singleExpression OPERATOR_LOGICAL_AND singleExpression  */
#line 247 ".\\parser.y"
                                                             { Print("- R: singleExpression OPERATOR_LOGICAL_AND singleExpression -> singleExpression"); }
#line 2962 "parser.tab.c"
    break;

  case 105: /* singleExpression: singleExpression '|' singleExpression  */
#line 248 ".\\parser.y"
                                            { Print("- R: singleExpression '|' singleExpression -> singleExpression"); }
#line 2968 "parser.tab.c"
    break;

  case 106: /* singleExpression: singleExpression '^' singleExpression  */
#line 249 ".\\parser.y"
                                            { Print("- R: singleExpression '^' singleExpression -> singleExpression"); }
#line 2974 "parser.tab.c"
    break;

  case 107: /* singleExpression: singleExpression '&' singleExpression  */
#line 250 ".\\parser.y"
                                            { Print("- R: singleExpression '&' singleExpression -> singleExpression"); }
#line 2980 "parser.tab.c"
    break;

  case 108: /* singleExpression: singleExpression OPERATOR_SHIFT_LEFT singleExpression  */
#line 251 ".\\parser.y"
                                                            { Print("- R: singleExpression OPERATOR_SHIFT_LEFT singleExpression -> singleExpression"); }
#line 2986 "parser.tab.c"
    break;

  case 109: /* singleExpression: singleExpression OPERATOR_SHIFT_RIGHT singleExpression  */
#line 252 ".\\parser.y"
                                                             { Print("- R: singleExpression OPERATOR_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 2992 "parser.tab.c"
    break;

  case 110: /* singleExpression: singleExpression OPERATOR_UNSIGNED_SHIFT_RIGHT singleExpression  */
#line 253 ".\\parser.y"
                                                                      { Print("- R: singleExpression OPERATOR_UNSIGNED_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 2998 "parser.tab.c"
    break;

  case 111: /* singleExpression: singleExpression INSTANCEOF singleExpression  */
#line 255 ".\\parser.y"
                                                   { Print("- R: singleExpression INSTANCEOF singleExpression -> singleExpression"); }
#line 3004 "parser.tab.c"
    break;

  case 112: /* singleExpression: singleExpression IN singleExpression  */
#line 256 ".\\parser.y"
                                           { Print("- R: singleExpression IN singleExpression -> singleExpression"); }
#line 3010 "parser.tab.c"
    break;

  case 113: /* singleExpression: singleExpression TEMPLATE_LITERAL  */
#line 258 ".\\parser.y"
                                        { Print("- R: singleExpression TEMPLATE_LITERAL -> singleExpression"); }
#line 3016 "parser.tab.c"
    break;

  case 114: /* singleExpression: singleExpression '?' singleExpression ':' singleExpression  */
#line 259 ".\\parser.y"
                                                                 { Print("- R: singleExpression '?' singleExpression ':' singleExpression -> singleExpression"); }
#line 3022 "parser.tab.c"
    break;

  case 115: /* singleExpression: '(' expressionList ')'  */
#line 261 ".\\parser.y"
                             { Print("- R: '(' expressionList ')' -> singleExpression"); }
#line 3028 "parser.tab.c"
    break;

  case 116: /* singleExpression: singleExpression arguments  */
#line 263 ".\\parser.y"
                                 { Print("- R: singleExpression arguments -> singleExpression"); }
#line 3034 "parser.tab.c"
    break;

  case 117: /* singleExpression: singleExpression '.' identifier  */
#line 264 ".\\parser.y"
                                      { Print("- R: singleExpression '.' ID -> singleExpression"); }
#line 3040 "parser.tab.c"
    break;

  case 118: /* singleExpression: arrayLiteral  */
#line 266 ".\\parser.y"
                   { Print("- R: arrayLiteral -> singleExpression"); }
#line 3046 "parser.tab.c"
    break;

  case 119: /* singleExpression: singleExpression '[' expressionList ']'  */
#line 267 ".\\parser.y"
                                              { Print("- R: singleExpression '[' singleExpression ']' -> singleExpression"); }
#line 3052 "parser.tab.c"
    break;

  case 120: /* singleExpression: singleExpression ENDL_BRACKET_OPEN expressionList ']'  */
#line 268 ".\\parser.y"
                                                            { Print("- R: singleExpression ENDL_BRACKET_OPEN singleExpression ']' -> singleExpression"); }
#line 3058 "parser.tab.c"
    break;

  case 121: /* singleExpression: NEW singleExpression  */
#line 270 ".\\parser.y"
                           { Print("- R: NEW singleExpression -> singleExpression"); }
#line 3064 "parser.tab.c"
    break;

  case 122: /* arguments: '(' ')'  */
#line 274 ".\\parser.y"
              { Print("- R: '(' ')' -> arguments"); }
#line 3070 "parser.tab.c"
    break;

  case 123: /* arguments: '(' argumentList ')'  */
#line 275 ".\\parser.y"
                           { Print("- R: '(' argumentList ')' -> arguments"); }
#line 3076 "parser.tab.c"
    break;

  case 124: /* arguments: '(' argumentList ',' ')'  */
#line 276 ".\\parser.y"
                               { Print("- R: '(' argumentList ',' ') -> arguments"); }
#line 3082 "parser.tab.c"
    break;

  case 125: /* argumentList: argument  */
#line 280 ".\\parser.y"
               { Print("- R: argument -> argumentList"); }
#line 3088 "parser.tab.c"
    break;

  case 126: /* argumentList: argumentList ',' arguments  */
#line 281 ".\\parser.y"
                                 { Print("- R: argumentList ',' arguments -> argumentList"); }
#line 3094 "parser.tab.c"
    break;

  case 127: /* argument: singleExpression  */
#line 285 ".\\parser.y"
                       { Print("- R: singleExpression -> argument"); }
#line 3100 "parser.tab.c"
    break;

  case 128: /* argument: ELLIPSIS singleExpression  */
#line 286 ".\\parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> argument"); }
#line 3106 "parser.tab.c"
    break;

  case 129: /* varStatement: varModifier varDeclarationList  */
#line 292 ".\\parser.y"
                                     { Print("- R: varModifier varDeclarationList -> varStatement"); }
#line 3112 "parser.tab.c"
    break;

  case 130: /* varDeclarationList: varDeclaration  */
#line 296 ".\\parser.y"
                     { Print("- R: varDeclaration -> argument"); }
#line 3118 "parser.tab.c"
    break;

  case 131: /* varDeclarationList: varDeclarationList ',' varDeclaration  */
#line 297 ".\\parser.y"
                                            { Print("- R: varDeclarationList ',' varDeclaration -> varDeclarationList"); }
#line 3124 "parser.tab.c"
    break;

  case 132: /* varDeclaration: identifier  */
#line 301 ".\\parser.y"
                 { Print("- R: identifier -> varDeclaration"); }
#line 3130 "parser.tab.c"
    break;

  case 133: /* varDeclaration: identifier typeAnnotation  */
#line 302 ".\\parser.y"
                                { Print("- R: identifier typeAnnotation -> varDeclaration"); }
#line 3136 "parser.tab.c"
    break;

  case 134: /* varDeclaration: identifier '=' singleExpression  */
#line 303 ".\\parser.y"
                                      { Print("- R: identifier '=' singleExpression -> varDeclaration"); }
#line 3142 "parser.tab.c"
    break;

  case 135: /* varDeclaration: identifier typeAnnotation '=' singleExpression  */
#line 304 ".\\parser.y"
                                                     { Print("- R: identifier typeAnnotation '=' singleExpression -> varDeclaration"); }
#line 3148 "parser.tab.c"
    break;

  case 136: /* varModifier: VAR  */
#line 308 ".\\parser.y"
          { Print("- R: VAR -> varModifier"); }
#line 3154 "parser.tab.c"
    break;

  case 137: /* varModifier: LET  */
#line 309 ".\\parser.y"
          { Print("- R: LET -> varModifier"); }
#line 3160 "parser.tab.c"
    break;

  case 138: /* varModifier: CONST  */
#line 310 ".\\parser.y"
            { Print("- R: CONST -> varModifier"); }
#line 3166 "parser.tab.c"
    break;

  case 139: /* ifStatement: IF '(' expressionList ')' statementListItem  */
#line 316 ".\\parser.y"
                                                                     { Print("- R:  IF '(' expressionList ')' statementListItem -> ifStatement"); }
#line 3172 "parser.tab.c"
    break;

  case 140: /* ifStatement: IF '(' expressionList ')' statementListItem ELSE statementListItem  */
#line 317 ".\\parser.y"
                                                                         { Print("- R: IF '(' expressionList ')' statementListItem ELSE statementListItem -> ifStatement"); }
#line 3178 "parser.tab.c"
    break;

  case 141: /* $@1: %empty  */
#line 321 ".\\parser.y"
                                                        { doWhileASI(); }
#line 3184 "parser.tab.c"
    break;

  case 142: /* iterationStatement: DO statementListItem WHILE '(' expressionList ')' $@1 statementSep  */
#line 321 ".\\parser.y"
                                                                                       { Print("- R: DO statementListItem WHILE '(' expressionList ')' statementSep -> iterationStatement"); }
#line 3190 "parser.tab.c"
    break;

  case 143: /* iterationStatement: WHILE '(' expressionList ')' statementListItem  */
#line 322 ".\\parser.y"
                                                     { Print("- R: WHILE '(' expressionList ')' statementListItem -> iterationStatement"); }
#line 3196 "parser.tab.c"
    break;

  case 144: /* iterationStatement: FOR '(' expressionListOpt ';' expressionListOpt ';' expressionListOpt ')' statementListItem  */
#line 323 ".\\parser.y"
                                                                                                  { Print("- R: FOR '(' expressionListOpt ';' expressionListOpt ';' expressionListOpt ')' statementListItem -> iterationStatement"); }
#line 3202 "parser.tab.c"
    break;

  case 145: /* iterationStatement: FOR '(' varModifier varDeclarationList ';' expressionListOpt ';' expressionListOpt ')' statementListItem  */
#line 324 ".\\parser.y"
                                                                                                               { Print("- R: FOR '(' varModifier varDeclarationList ';' expressionListOpt ';' expressionListOpt ')' statementListItem -> iterationStatement"); }
#line 3208 "parser.tab.c"
    break;

  case 146: /* iterationStatement: FOR '(' singleExpression IN singleExpression ')' statementListItem  */
#line 325 ".\\parser.y"
                                                                         { Print("- R: FOR '(' singleExpression IN singleExpression ')' statementListItem -> iterationStatement"); }
#line 3214 "parser.tab.c"
    break;

  case 147: /* iterationStatement: FOR '(' varModifier varDeclaration IN expressionList ')' statementListItem  */
#line 326 ".\\parser.y"
                                                                                 { Print("- R: FOR '(' varModifier varDeclaration IN expressionList ')' statementListItem -> iterationStatement"); }
#line 3220 "parser.tab.c"
    break;

  case 148: /* continueStatement: CONTINUE  */
#line 330 ".\\parser.y"
               { Print("- R: CONTINUE -> returnStatement"); }
#line 3226 "parser.tab.c"
    break;

  case 149: /* continueStatement: CONTINUE identifier  */
#line 331 ".\\parser.y"
                          { Print("- R: CONTINUE identifier -> returnStatement"); }
#line 3232 "parser.tab.c"
    break;

  case 150: /* breakStatement: BREAK  */
#line 335 ".\\parser.y"
             { Print("- R: BREAK -> returnStatement"); }
#line 3238 "parser.tab.c"
    break;

  case 151: /* breakStatement: BREAK identifier  */
#line 336 ".\\parser.y"
                       { Print("- R: BREAK identifier -> returnStatement"); }
#line 3244 "parser.tab.c"
    break;

  case 152: /* returnStatement: RETURN  */
#line 340 ".\\parser.y"
             { Print("- R: RETURN -> returnStatement"); }
#line 3250 "parser.tab.c"
    break;

  case 153: /* returnStatement: RETURN singleExpression  */
#line 341 ".\\parser.y"
                              { Print("- R: RETURN singleExpression -> returnStatement"); }
#line 3256 "parser.tab.c"
    break;

  case 154: /* labelledStatement: identifier ':' statementListItem  */
#line 345 ".\\parser.y"
                                       { Print("- R: identifier ':' statementListItem -> labelledStatement"); }
#line 3262 "parser.tab.c"
    break;

  case 155: /* blockStatement: '{' '}'  */
#line 349 ".\\parser.y"
              { Print("- R: '{' '}' -> blockStatement"); }
#line 3268 "parser.tab.c"
    break;

  case 156: /* blockStatement: '{' statementList '}'  */
#line 350 ".\\parser.y"
                            { Print("- R: '{' statementList '}' -> blockStatement"); }
#line 3274 "parser.tab.c"
    break;

  case 157: /* switchStatement: SWITCH '(' expressionList ')' '{' '}'  */
#line 354 ".\\parser.y"
                                            { Print("- R: SWITCH '(' expressionList ')' '{' '}' -> switchStatement"); }
#line 3280 "parser.tab.c"
    break;

  case 158: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList '}'  */
#line 355 ".\\parser.y"
                                                           { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList '}' -> switchStatement"); }
#line 3286 "parser.tab.c"
    break;

  case 159: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause '}'  */
#line 356 ".\\parser.y"
                                                                         { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause '}' -> switchStatement"); }
#line 3292 "parser.tab.c"
    break;

  case 160: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause caseClauseList '}'  */
#line 357 ".\\parser.y"
                                                                                        { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause caseClauseList '}' -> switchStatement"); }
#line 3298 "parser.tab.c"
    break;

  case 161: /* caseClauseList: caseClause  */
#line 361 ".\\parser.y"
                 { Print("- R: caseClause -> caseClauseList"); }
#line 3304 "parser.tab.c"
    break;

  case 162: /* caseClauseList: caseClauseList caseClause  */
#line 362 ".\\parser.y"
                                { Print("- R: caseClauseList caseClause -> caseClauseList"); }
#line 3310 "parser.tab.c"
    break;

  case 163: /* caseClause: CASE expressionList ':'  */
#line 366 ".\\parser.y"
                              { Print("- R: CASE expressionList ':' -> caseClause"); }
#line 3316 "parser.tab.c"
    break;

  case 164: /* caseClause: CASE expressionList ':' statementList  */
#line 367 ".\\parser.y"
                                            { Print("- R: CASE expressionList ':' statementList -> caseClause"); }
#line 3322 "parser.tab.c"
    break;

  case 165: /* defaultClause: DEFAULT ':'  */
#line 371 ".\\parser.y"
                  { Print("- R: DEFAULT ':' -> defaultClause"); }
#line 3328 "parser.tab.c"
    break;

  case 166: /* defaultClause: DEFAULT ':' statementList  */
#line 372 ".\\parser.y"
                                { Print("- R: DEFAULT ':' statementList -> defaultClause"); }
#line 3334 "parser.tab.c"
    break;

  case 167: /* functionDeclaration: FUNCTION identifier callSignature '{' functionBody '}'  */
#line 378 ".\\parser.y"
                                                             { Print("- R: FUNCTION ID callSignature '{' functionBody '}' -> functionDeclaration"); }
#line 3340 "parser.tab.c"
    break;

  case 168: /* functionBody: %empty  */
#line 382 ".\\parser.y"
                  { Print("- R: #empty# -> functionBody"); }
#line 3346 "parser.tab.c"
    break;

  case 169: /* functionBody: statementList  */
#line 383 ".\\parser.y"
                    { Print("- R: statementList -> returnStatement"); }
#line 3352 "parser.tab.c"
    break;

  case 170: /* callSignature: '(' ')'  */
#line 387 ".\\parser.y"
              { Print("- R: '(' ')' -> callSignature"); }
#line 3358 "parser.tab.c"
    break;

  case 171: /* callSignature: '(' ')' typeAnnotation  */
#line 388 ".\\parser.y"
                             { Print("- R: '(' ')' typeAnnotation -> callSignature"); }
#line 3364 "parser.tab.c"
    break;

  case 172: /* callSignature: '(' restParameter ')'  */
#line 389 ".\\parser.y"
                            { Print("- R: '(' restParameter ')' -> callSignature"); }
#line 3370 "parser.tab.c"
    break;

  case 173: /* callSignature: '(' restParameter ')' typeAnnotation  */
#line 390 ".\\parser.y"
                                           { Print("- R: '(' restParameter ')' typeAnnotation -> callSignature"); }
#line 3376 "parser.tab.c"
    break;

  case 174: /* callSignature: '(' parameterList ')'  */
#line 391 ".\\parser.y"
                            { Print("- R: '(' parameterList ')' -> callSignature"); }
#line 3382 "parser.tab.c"
    break;

  case 175: /* callSignature: '(' parameterList ')' typeAnnotation  */
#line 392 ".\\parser.y"
                                           { Print("- R: '(' parameterList ')' typeAnnotation -> callSignature"); }
#line 3388 "parser.tab.c"
    break;

  case 176: /* callSignature: '(' parameterList ',' restParameter ')'  */
#line 393 ".\\parser.y"
                                              { Print("- R: '(' parameterList ',' restParameter ')' -> callSignature"); }
#line 3394 "parser.tab.c"
    break;

  case 177: /* callSignature: '(' parameterList ',' restParameter ')' typeAnnotation  */
#line 394 ".\\parser.y"
                                                             { Print("- R: '(' parameterList ',' restParameter ')' typeAnnotation -> callSignature"); }
#line 3400 "parser.tab.c"
    break;

  case 178: /* callSignature: '(' parameterList ',' ')'  */
#line 395 ".\\parser.y"
                                { Print("- R: '(' parameterList ',' ')' -> callSignature"); }
#line 3406 "parser.tab.c"
    break;

  case 179: /* callSignature: '(' parameterList ',' ')' typeAnnotation  */
#line 396 ".\\parser.y"
                                               { Print("- R: '(' parameterList ',' ')' typeAnnotation -> callSignature"); }
#line 3412 "parser.tab.c"
    break;

  case 180: /* parameterList: parameter  */
#line 400 ".\\parser.y"
                { Print("- R: parameter -> parameterList"); }
#line 3418 "parser.tab.c"
    break;

  case 181: /* parameterList: parameterList ',' parameter  */
#line 401 ".\\parser.y"
                                  { Print("- R: parameterList ',' parameter -> parameterList"); }
#line 3424 "parser.tab.c"
    break;

  case 182: /* parameter: requiredParameter  */
#line 405 ".\\parser.y"
                        { Print("- R: requiredParameter -> parameter"); }
#line 3430 "parser.tab.c"
    break;

  case 183: /* parameter: optionalParameter  */
#line 406 ".\\parser.y"
                        { Print("- R: optionalParameter -> parameter"); }
#line 3436 "parser.tab.c"
    break;

  case 184: /* requiredParameter: identifier  */
#line 410 ".\\parser.y"
                 { Print("- R: ID -> requiredParameter"); }
#line 3442 "parser.tab.c"
    break;

  case 185: /* requiredParameter: identifier typeAnnotation  */
#line 411 ".\\parser.y"
                                { Print("- R: ID typeAnnotation -> requiredParameter"); }
#line 3448 "parser.tab.c"
    break;

  case 186: /* optionalParameter: identifier '?'  */
#line 415 ".\\parser.y"
                     { Print("- R: ID '?' -> optionalParameter"); }
#line 3454 "parser.tab.c"
    break;

  case 187: /* optionalParameter: identifier '?' typeAnnotation  */
#line 416 ".\\parser.y"
                                    { Print("- R: ID '?' typeAnnotation -> optionalParameter"); }
#line 3460 "parser.tab.c"
    break;

  case 188: /* optionalParameter: identifier initializer  */
#line 417 ".\\parser.y"
                             { Print("- R: ID initializer -> optionalParameter"); }
#line 3466 "parser.tab.c"
    break;

  case 189: /* optionalParameter: identifier typeAnnotation initializer  */
#line 418 ".\\parser.y"
                                            { Print("- R: ID typeAnnotation initializer -> optionalParameter"); }
#line 3472 "parser.tab.c"
    break;

  case 190: /* restParameter: ELLIPSIS singleExpression  */
#line 422 ".\\parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> restParameter"); }
#line 3478 "parser.tab.c"
    break;

  case 191: /* restParameter: ELLIPSIS singleExpression typeAnnotation  */
#line 423 ".\\parser.y"
                                               { Print("- R: ELLIPSIS singleExpression typeAnnotation -> restParameter"); }
#line 3484 "parser.tab.c"
    break;


#line 3488 "parser.tab.c"

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

#line 494 ".\\parser.y"



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
