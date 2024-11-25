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
#line 27 ".\\parser.y"

    int _integer;
    char* _string;
    char* _id;
    double _floatingPoint;

#line 243 "parser.tab.c"

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
  YYSYMBOL_statementSep = 127,             /* statementSep  */
  YYSYMBOL_initializer = 128,              /* initializer  */
  YYSYMBOL_type = 129,                     /* type  */
  YYSYMBOL_unionOrIntersectionOrPrimaryType = 130, /* unionOrIntersectionOrPrimaryType  */
  YYSYMBOL_primaryType = 131,              /* primaryType  */
  YYSYMBOL_typeReference = 132,            /* typeReference  */
  YYSYMBOL_predefinedType = 133,           /* predefinedType  */
  YYSYMBOL_typeAnnotation = 134,           /* typeAnnotation  */
  YYSYMBOL_arrayLiteral = 135,             /* arrayLiteral  */
  YYSYMBOL_elementList = 136,              /* elementList  */
  YYSYMBOL_arrayElement = 137,             /* arrayElement  */
  YYSYMBOL_expressionListOpt = 138,        /* expressionListOpt  */
  YYSYMBOL_expressionList = 139,           /* expressionList  */
  YYSYMBOL_singleExpression = 140,         /* singleExpression  */
  YYSYMBOL_arguments = 141,                /* arguments  */
  YYSYMBOL_argumentList = 142,             /* argumentList  */
  YYSYMBOL_argument = 143,                 /* argument  */
  YYSYMBOL_varStatement = 144,             /* varStatement  */
  YYSYMBOL_varDeclarationList = 145,       /* varDeclarationList  */
  YYSYMBOL_varDeclaration = 146,           /* varDeclaration  */
  YYSYMBOL_varModifier = 147,              /* varModifier  */
  YYSYMBOL_ifStatement = 148,              /* ifStatement  */
  YYSYMBOL_iterationStatement = 149,       /* iterationStatement  */
  YYSYMBOL_150_1 = 150,                    /* $@1  */
  YYSYMBOL_continueStatement = 151,        /* continueStatement  */
  YYSYMBOL_breakStatement = 152,           /* breakStatement  */
  YYSYMBOL_returnStatement = 153,          /* returnStatement  */
  YYSYMBOL_labelledStatement = 154,        /* labelledStatement  */
  YYSYMBOL_blockStatement = 155,           /* blockStatement  */
  YYSYMBOL_switchStatement = 156,          /* switchStatement  */
  YYSYMBOL_caseClauseList = 157,           /* caseClauseList  */
  YYSYMBOL_caseClause = 158,               /* caseClause  */
  YYSYMBOL_defaultClause = 159,            /* defaultClause  */
  YYSYMBOL_functionDeclaration = 160,      /* functionDeclaration  */
  YYSYMBOL_functionBody = 161,             /* functionBody  */
  YYSYMBOL_callSignature = 162,            /* callSignature  */
  YYSYMBOL_parameterList = 163,            /* parameterList  */
  YYSYMBOL_parameter = 164,                /* parameter  */
  YYSYMBOL_requiredParameter = 165,        /* requiredParameter  */
  YYSYMBOL_optionalParameter = 166,        /* optionalParameter  */
  YYSYMBOL_restParameter = 167,            /* restParameter  */
  YYSYMBOL_classDeclaration = 168,         /* classDeclaration  */
  YYSYMBOL_classHeritage = 169,            /* classHeritage  */
  YYSYMBOL_classTail = 170,                /* classTail  */
  YYSYMBOL_classElementList = 171,         /* classElementList  */
  YYSYMBOL_classElement = 172,             /* classElement  */
  YYSYMBOL_propertyName = 173,             /* propertyName  */
  YYSYMBOL_identifier = 174                /* identifier  */
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
#define YYLAST   2014

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  123
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  234
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  424

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
     133,   137,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   161,   166,   167,   171,   172,   173,   177,   178,   184,
     185,   189,   190,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   254,   255,   257,   258,   260,   262,   264,   265,
     267,   268,   269,   271,   275,   276,   277,   281,   282,   286,
     287,   293,   297,   298,   302,   303,   304,   305,   309,   310,
     311,   317,   318,   322,   322,   323,   324,   325,   326,   327,
     331,   332,   336,   337,   341,   342,   346,   350,   351,   355,
     356,   357,   358,   362,   363,   367,   368,   372,   373,   379,
     383,   384,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   401,   402,   406,   407,   411,   412,   416,   417,
     418,   419,   423,   424,   430,   431,   435,   439,   440,   444,
     445,   449,   452,   453,   454,   455,   458,   461,   462,   463,
     467,   468,   469,   470,   471,   472,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494
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
  "restParameter", "classDeclaration", "classHeritage", "classTail",
  "classElementList", "classElement", "propertyName", "identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-311)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     795,  -311,  -311,  -311,   -53,   992,   992,   795,   -39,   -32,
     992,   992,   -22,  1169,  -311,  -311,  1169,  -311,  -311,  -311,
    -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,
    -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,
    -311,  -311,  -311,  1169,  1169,  1169,  1169,  1169,  1169,  1169,
    1169,  1072,  1072,  1169,  -311,   554,   108,   795,  -311,  -311,
     -36,  1523,     2,   992,  -311,  -311,     2,     2,     2,  -311,
    -311,  -311,  -311,  -311,    39,  1169,    24,    -7,   116,  1169,
     899,  -311,  -311,  1169,  1523,  -311,    64,    64,    64,    64,
      64,    64,    64,    64,    64,  1169,    -8,  -311,  1523,    22,
      -3,  -311,   675,  -311,  -311,  1169,  -311,  -311,  -311,  -311,
    -311,  1169,  1169,  1169,  1169,  1169,  1169,  1169,  1169,  1169,
    1169,  1169,  1169,  1169,  1169,  1169,  1169,  1169,  1169,  1169,
    1169,  1169,  1169,  1169,  1169,  1169,  1169,  1169,  1169,  1169,
    1169,  1169,  1169,  1169,  1169,  1169,  1169,  1169,  1169,  1169,
    1169,  1169,  1169,   992,  1169,  1169,  1169,  1034,  -311,  -311,
      89,  -311,    -6,  -311,  -311,  -311,   795,    -2,     8,    33,
     992,   163,    43,  -311,    45,     5,    37,   104,  1587,   992,
       9,  1523,  1072,  -311,  -311,  -311,  -311,  1523,  1644,  1644,
    1644,  1644,  1644,  1644,  1644,  1644,  1644,  1644,  1644,  1644,
    1644,  1644,  1644,  1644,  1267,  1721,  1758,  1794,  1829,  1863,
    1896,   132,   132,   132,   132,   233,   233,   233,   233,   233,
     233,   187,   187,   187,   209,   209,    42,    42,    42,    42,
    -311,    26,    32,    49,  1169,  -311,  1523,    16,  -311,   992,
    1169,   709,   107,  -311,   795,  1169,    93,    17,  -311,  -311,
    -311,    57,    70,   795,  -311,  -311,  1262,  1262,    24,  -311,
    -311,  -311,  1169,  1169,  -311,   933,  -311,    13,  -311,  -311,
    1169,   795,  1169,  1169,   -35,    88,    63,  -311,  1169,  -311,
    -311,  1523,   -20,  -311,  -311,  1523,   142,  -311,  -311,  -311,
    -311,  -311,  -311,  -311,  -311,   835,   835,   709,  -311,     6,
      72,  -311,  -311,  1169,   180,  1331,  -311,   418,    93,    93,
    1169,    93,  -311,   126,   795,    86,    91,    24,    92,  1395,
    1459,  -311,  -311,  -311,    94,    18,    96,    20,  -311,    95,
     669,  1169,  1169,   -11,  1683,  -311,  -311,  -311,     6,     6,
      99,   835,   835,  1203,  1523,   795,  -311,    93,  -311,   101,
    -311,  -311,  1523,  -311,  -311,  -311,   118,   117,   795,  -311,
    -311,  -311,  -311,   120,   795,  -311,  1169,   795,   122,    21,
    1169,  -311,     1,  -311,  -311,   158,  -311,  -311,    47,  -311,
    -311,    93,   -52,   795,   125,  -311,   130,     2,   135,  -311,
    1169,   795,    36,   176,  -311,  -311,     3,  -311,  -311,   795,
     137,   138,  -311,  -311,  -311,   795,   140,  -311,   795,   795,
    -311,     4,   139,   795,  -311,  -311,   795,   795,   795,  -311,
    -311,   141,  -311,  -311
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   138,   139,   140,     0,     0,     0,     0,     0,     0,
     150,   152,     0,   154,    55,    54,     0,   221,   217,   218,
     219,   220,   231,   232,   233,   234,   222,   223,   224,   225,
     228,   229,   226,   227,   230,    58,    56,    57,    62,    60,
      61,   216,    59,     0,     0,     0,     0,     0,     0,     0,
       0,    44,    44,     0,     5,     0,     0,     2,     3,   120,
       0,    51,     0,     0,     8,    10,     0,     0,     0,    14,
      15,     9,    16,    17,    53,     0,     0,     0,     0,     0,
      49,   151,   153,     0,   155,    53,   123,    71,    72,    69,
      70,    64,    63,    65,    66,     0,     0,    45,    47,     0,
       0,   157,     0,     1,     4,     0,    18,     6,   114,    67,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   117,     7,
     131,   132,   134,    11,    12,    13,     0,     0,     0,     0,
       0,     0,     0,   194,     0,     0,     0,    50,    51,     0,
       0,    48,    44,    42,    43,   116,   158,    52,    87,    91,
      92,    98,    88,    89,    90,    93,    94,   102,    95,    96,
      97,    99,   100,   101,     0,   111,   103,   104,   105,   106,
     107,    81,    82,    83,    84,    79,    78,    86,    85,   112,
     113,   108,   109,   110,    73,    74,    75,    76,    77,    80,
     119,     0,     0,   118,     0,   124,   129,     0,   127,     0,
       0,     0,   135,   156,     0,     0,   172,     0,   182,   184,
     185,     0,   186,   170,   196,    31,     0,     0,     0,   211,
     212,   213,     0,     0,   197,     0,   199,     0,   210,   195,
       0,     0,    49,     0,     0,   132,     0,    46,     0,   121,
     122,   130,     0,   125,   133,   136,   226,    40,    39,    37,
      33,    34,    32,    35,    36,     0,     0,     0,    41,    20,
      25,    28,    27,     0,   141,   192,   173,     0,   176,   174,
       0,   188,   190,   187,   171,     0,     0,     0,     0,     0,
       0,   198,   200,   202,     0,     0,     0,     0,   145,     0,
     113,    49,     0,     0,   115,   126,   128,    38,    21,    22,
       0,     0,     0,     0,   137,     0,   193,   180,   183,     0,
     177,   175,    19,   189,   191,   169,     0,     0,   170,   214,
     215,   204,   203,     0,   170,   143,    49,     0,     0,     0,
       0,   159,     0,   163,    26,    23,    24,    29,     0,   142,
     181,   178,     0,   170,     0,   205,     0,     0,     0,   148,
      49,     0,     0,     0,   160,   164,     0,    30,   179,   170,
       0,     0,   201,   206,   144,     0,     0,   149,   165,   167,
     161,     0,     0,   170,   209,   146,     0,   166,   168,   162,
     207,     0,   147,   208
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -311,  -311,    12,     7,   -49,  -213,   -33,  -190,   -81,    97,
    -311,  -237,  -311,   -48,  -311,  -271,   -51,   384,   -16,  -311,
    -311,  -311,    90,  -163,   188,  -311,  -311,  -311,  -311,  -311,
    -311,  -311,  -311,  -311,  -126,  -310,  -311,  -311,  -270,  -227,
    -311,   -34,  -311,  -311,   -31,  -311,  -311,   100,  -311,    10,
    -136,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    56,   314,    58,   107,   312,   298,   299,   300,   301,
     302,   242,    59,    96,    97,   176,    60,    61,   158,   237,
     238,    62,   160,   161,    63,    64,    65,   387,    66,    67,
      68,    69,    70,    71,   372,   373,   396,    72,   315,   169,
     247,   248,   249,   250,   251,    73,   172,   173,   265,   266,
     267,    85
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      74,   329,   100,   170,    99,    76,    77,    74,   370,   306,
      81,    82,    57,   159,    78,   313,   275,   163,   164,   165,
     370,   393,   370,   370,   167,   105,   239,   241,   175,   177,
     325,   318,   180,   245,    17,    18,    19,    20,    21,    22,
     326,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,   182,   324,    74,   240,    74,   105,   105,
     368,    41,   395,   162,   104,    75,   105,   102,   346,   399,
     105,   350,   351,   241,   353,   310,   284,   282,   307,    79,
     310,   105,   105,   182,   106,   331,    80,   105,   384,   341,
     357,   342,   241,   105,   386,   388,    83,   105,   157,   335,
     354,   395,    74,   231,   232,   338,   339,   183,   103,   104,
     380,   371,   363,   401,   171,   408,   185,   244,   166,   406,
     316,   317,   106,   394,   271,   410,   419,   246,   276,   412,
     174,   168,   310,   323,   277,   283,   308,   184,   362,   365,
     391,   279,   168,   421,   398,   400,   152,   280,   311,   241,
     239,   375,   376,   230,   253,   153,   154,   272,   155,   156,
     157,   343,   397,   270,   171,   105,    74,   157,   252,   303,
     255,   268,   241,   243,   256,   257,   309,   153,   154,   162,
     155,   156,   157,   332,   333,   337,   343,   345,   310,    17,
      18,    19,    20,    21,    22,   258,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,   355,   356,
     259,   260,   261,   358,   361,   366,    41,   364,   374,   327,
     381,   177,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   382,   383,   162,
     385,   255,   390,   342,    74,   153,   154,   402,   155,   156,
     157,   304,   403,    74,   405,   409,   268,   268,   413,   416,
     414,   420,   378,   423,   340,   268,   336,   254,   179,   274,
     411,    74,   269,   348,     0,   322,   349,   262,   328,   263,
     177,   369,     0,     0,     0,   264,   147,   148,   149,   150,
     151,   152,     0,     0,     0,   255,   255,   255,     0,     0,
     153,   154,     0,   155,   156,   157,     0,   252,     0,     0,
     149,   150,   151,   152,    74,   177,     0,     0,     0,   392,
       0,   104,   153,   154,     0,   155,   156,   157,     0,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   404,   177,
       0,   255,   255,   255,     0,    74,   153,   154,     0,   155,
     156,   157,   379,     0,     0,     0,     0,     0,    74,     0,
       0,     0,     0,     0,    74,     0,     0,    74,     0,     0,
       0,     0,     0,     0,   389,     0,     0,     0,     0,     0,
       0,     0,     0,    74,     0,     0,     0,     0,     0,     0,
       0,    74,     0,     0,     0,     0,     0,    84,   407,    74,
      86,     0,     0,     0,     0,    74,     0,     0,    74,    74,
       0,     0,   415,    74,     0,     0,    74,    74,    74,     0,
     417,   418,     0,   422,   104,   104,     0,    87,    88,    89,
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
     223,   224,   225,   226,   227,   228,   229,   347,     0,     0,
     233,   236,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       4,     0,     5,     6,     0,     0,    98,     7,     8,     9,
      10,    11,    12,     0,     0,    13,    14,    15,    16,     0,
      17,    18,    19,    20,    21,    22,     0,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     0,
       0,    35,    36,    37,    38,    39,    40,    41,     0,    42,
      43,    44,    45,    46,     0,     0,     0,     0,   281,     0,
       0,     0,     0,     0,   285,     0,     0,     0,     0,   305,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   319,   320,     0,     0,
       0,     0,     0,    47,    48,     0,     0,   330,     0,    49,
      50,     0,   334,     0,     0,     0,     0,     0,    51,     0,
      52,     0,    53,     0,    54,    55,   101,     0,     1,     2,
       3,     4,     0,     5,     6,     0,     0,   344,     7,     8,
       9,    10,    11,    12,   352,     0,    13,    14,    15,    16,
       0,    17,    18,    19,    20,    21,    22,     0,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       0,     0,    35,    36,    37,    38,    39,    40,    41,     0,
      42,    43,    44,    45,    46,    17,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      31,   286,    33,    34,   287,   288,   289,   290,   291,   292,
     293,   294,    41,     0,     0,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    47,    48,     0,     0,     0,     0,
      49,    50,   153,   154,     0,   155,   156,   157,   367,    51,
       0,    52,   295,    53,   296,    54,    55,   186,     1,     2,
       3,     4,     0,     5,     6,     0,     0,     0,     7,     8,
       9,    10,    11,    12,     0,     0,    13,    14,    15,    16,
       0,    17,    18,    19,    20,    21,    22,   297,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       0,     0,    35,    36,    37,    38,    39,    40,    41,     0,
      42,    43,    44,    45,    46,     0,     0,     0,     0,     0,
       0,    17,    18,    19,    20,    21,    22,     0,    23,    24,
      25,    26,    27,    28,    29,    30,    31,   286,    33,    34,
     287,   288,   289,   290,   291,   292,   293,   294,    41,     0,
       0,     0,     0,     0,    47,    48,     0,     0,     0,     0,
      49,    50,     1,     2,     3,     0,     0,     0,     0,    51,
       0,    52,     0,    53,     0,    54,    55,     0,     0,     0,
       0,    14,    15,    16,     0,    17,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,   256,   257,    35,    36,    37,    38,
      39,    40,    41,   297,    42,    43,    44,    45,    46,    17,
      18,    19,    20,    21,    22,   258,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,     0,     0,
     259,   260,   261,     0,     0,     0,    41,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,    48,
       0,     0,     0,     0,    49,    50,     0,     0,     0,     0,
       0,     0,     0,    51,     0,    52,     0,    53,    17,    18,
      19,    20,    21,    22,     0,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     0,     0,     0,
       0,     0,     0,     0,     0,    41,     0,   262,     0,   263,
       0,     0,     0,     0,     0,   321,    14,    15,    16,   234,
      17,    18,    19,    20,    21,    22,     0,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     0,
       0,    35,    36,    37,    38,    39,    40,    41,     0,    42,
      43,    44,    45,    46,    14,    15,    16,    95,    17,    18,
      19,    20,    21,    22,     0,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     0,     0,    35,
      36,    37,    38,    39,    40,    41,     0,    42,    43,    44,
      45,    46,     0,    47,    48,     0,     0,     0,     0,    49,
      50,     0,     0,     0,     0,     0,     0,     0,    51,     0,
      52,     0,    53,   235,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,    48,     0,     0,     0,     0,    49,    50,     0,
       0,     0,     0,     0,     0,     0,    51,     0,    52,     0,
      53,    14,    15,    16,     0,    17,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,     0,    35,    36,    37,    38,
      39,    40,    41,     0,    42,    43,    44,    45,    46,    17,
      18,    19,    20,    21,    22,     0,    23,    24,    25,    26,
      27,    28,    29,    30,    31,   286,    33,    34,   287,   288,
     289,   290,   291,   292,   293,   294,    41,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,    48,
       0,     0,     0,     0,    49,    50,     0,     0,     0,     0,
       0,     0,     0,    51,     0,    52,     0,    53,    17,    18,
      19,    20,    21,    22,     0,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     0,     0,   259,
     260,   261,     0,     0,     0,    41,     0,     0,   377,     0,
       0,   297,   108,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   278,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,     0,     0,     0,   262,     0,   263,     0,
     153,   154,     0,   155,   156,   157,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     241,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     0,     0,     0,     0,
       0,     0,     0,     0,   153,   154,     0,   155,   156,   157,
     108,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,     0,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
       0,     0,     0,     0,     0,     0,     0,     0,   153,   154,
     359,   155,   156,   157,   108,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,     0,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,     0,     0,     0,     0,     0,
       0,     0,   153,   154,   360,   155,   156,   157,   108,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,     0,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,     0,
       0,     0,     0,     0,     0,     0,   153,   154,     0,   155,
     156,   157,   108,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,     0,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   273,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,     0,     0,     0,     0,     0,     0,     0,
     153,   154,     0,   155,   156,   157,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,     0,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,     0,
       0,     0,     0,     0,     0,     0,     0,   153,   154,     0,
     155,   156,   157,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,     0,
       0,     0,     0,     0,     0,     0,   153,   154,     0,   155,
     156,   157,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     0,     0,     0,     0,
       0,     0,     0,     0,   153,   154,     0,   155,   156,   157,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,     0,     0,     0,     0,     0,     0,     0,
       0,   153,   154,     0,   155,   156,   157,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,     0,
       0,     0,     0,     0,     0,     0,     0,   153,   154,     0,
     155,   156,   157,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,     0,     0,     0,     0,     0,
       0,     0,   153,   154,     0,   155,   156,   157,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,     0,
       0,     0,     0,     0,     0,     0,   153,   154,     0,   155,
     156,   157,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     0,     0,     0,     0,     0,     0,     0,     0,   153,
     154,     0,   155,   156,   157
};

static const yytype_int16 yycheck[] =
{
       0,   272,    53,    10,    52,     5,     6,     7,    19,   246,
      10,    11,     0,    62,     7,   252,   179,    66,    67,    68,
      19,    20,    19,    19,    75,    61,    61,    79,    79,    80,
     267,   258,    83,    25,    26,    27,    28,    29,    30,    31,
     267,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    61,   267,    55,    62,    57,    61,    61,
     331,    53,   372,    63,    57,   118,    61,    55,   305,   121,
      61,   308,   309,    79,   311,    62,   239,    61,    61,   118,
      62,    61,    61,    61,   120,   120,   118,    61,   358,    83,
     317,    85,    79,    61,   364,   366,   118,    61,   118,   119,
     313,   411,   102,   154,   155,   295,   296,   115,     0,   102,
     347,   122,   325,   383,   121,    79,   119,   119,    79,   390,
     256,   257,   120,   122,   119,   122,   122,   119,   119,   399,
      14,   118,    62,   120,   182,   119,   119,   115,   120,   119,
     119,   115,   118,   413,   381,   382,   104,   115,    78,    79,
      61,   341,   342,   153,   121,   113,   114,   120,   116,   117,
     118,   114,   115,   118,   121,    61,   166,   118,   168,    62,
     170,   171,    79,   166,    11,    12,   119,   113,   114,   179,
     116,   117,   118,    95,   121,    43,   114,     7,    62,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,   122,   118,
      47,    48,    49,   121,   120,   120,    53,   121,   119,   270,
     119,   272,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   119,   121,   239,
     120,   241,   120,    85,   244,   113,   114,   122,   116,   117,
     118,   244,   122,   253,   119,    79,   256,   257,   121,   119,
     122,   122,   343,   122,   297,   265,   282,   170,    80,   179,
     396,   271,   172,   307,    -1,   265,   307,   114,   271,   116,
     331,   332,    -1,    -1,    -1,   122,    99,   100,   101,   102,
     103,   104,    -1,    -1,    -1,   295,   296,   297,    -1,    -1,
     113,   114,    -1,   116,   117,   118,    -1,   307,    -1,    -1,
     101,   102,   103,   104,   314,   366,    -1,    -1,    -1,   370,
      -1,   314,   113,   114,    -1,   116,   117,   118,    -1,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   387,   390,
      -1,   341,   342,   343,    -1,   345,   113,   114,    -1,   116,
     117,   118,   345,    -1,    -1,    -1,    -1,    -1,   358,    -1,
      -1,    -1,    -1,    -1,   364,    -1,    -1,   367,    -1,    -1,
      -1,    -1,    -1,    -1,   367,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   383,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   391,    -1,    -1,    -1,    -1,    -1,    13,   391,   399,
      16,    -1,    -1,    -1,    -1,   405,    -1,    -1,   408,   409,
      -1,    -1,   405,   413,    -1,    -1,   416,   417,   418,    -1,
     408,   409,    -1,   416,   417,   418,    -1,    43,    44,    45,
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
     116,    -1,   118,    -1,   120,   121,   122,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,   303,    13,    14,
      15,    16,    17,    18,   310,    -1,    21,    22,    23,    24,
      -1,    26,    27,    28,    29,    30,    31,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    26,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    99,   100,    -1,    -1,    -1,    -1,
     105,   106,   113,   114,    -1,   116,   117,   118,   119,   114,
      -1,   116,    83,   118,    85,   120,   121,   122,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    13,    14,
      15,    16,    17,    18,    -1,    -1,    21,    22,    23,    24,
      -1,    26,    27,    28,    29,    30,    31,   118,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,
     105,   106,     3,     4,     5,    -1,    -1,    -1,    -1,   114,
      -1,   116,    -1,   118,    -1,   120,   121,    -1,    -1,    -1,
      -1,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    11,    12,    47,    48,    49,    50,
      51,    52,    53,   118,    55,    56,    57,    58,    59,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      47,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
      -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,   116,    -1,   118,    26,    27,
      28,    29,    30,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,   114,    -1,   116,
      -1,    -1,    -1,    -1,    -1,   122,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    -1,    99,   100,    -1,    -1,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,
     116,    -1,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,    -1,    -1,    -1,    -1,   105,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,   116,    -1,
     118,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    26,
      27,    28,    29,    30,    31,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
      -1,    -1,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,   116,    -1,   118,    26,    27,
      28,    29,    30,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    47,
      48,    49,    -1,    -1,    -1,    53,    -1,    -1,   115,    -1,
      -1,   118,    55,    56,    57,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    -1,    -1,    -1,    -1,   114,    -1,   116,    -1,
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
     116,   117,   118,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,
     117,   118,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,   114,    -1,   116,   117,   118,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,   114,    -1,   116,   117,   118,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,
     116,   117,   118,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,   114,    -1,   116,   117,   118,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,   116,
     117,   118,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
     114,    -1,   116,   117,   118
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
     106,   114,   116,   118,   120,   121,   124,   125,   126,   135,
     139,   140,   144,   147,   148,   149,   151,   152,   153,   154,
     155,   156,   160,   168,   174,   118,   174,   174,   126,   118,
     118,   174,   174,   118,   140,   174,   140,   140,   140,   140,
     140,   140,   140,   140,   140,    25,   136,   137,   140,   136,
     139,   122,   125,     0,   126,    61,   120,   127,    55,    56,
      57,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   113,   114,   116,   117,   118,   141,   127,
     145,   146,   174,   127,   127,   127,    79,   139,   118,   162,
      10,   121,   169,   170,    14,   139,   138,   139,   140,   147,
     139,   140,    61,   115,   115,   119,   122,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     174,   139,   139,   140,    25,   119,   140,   142,   143,    61,
      62,    79,   134,   126,   119,    25,   119,   163,   164,   165,
     166,   167,   174,   121,   132,   174,    11,    12,    32,    47,
      48,    49,   114,   116,   122,   171,   172,   173,   174,   170,
     118,   119,   120,    95,   145,   146,   119,   136,    79,   115,
     115,   140,    61,   119,   146,   140,    42,    45,    46,    47,
      48,    49,    50,    51,    52,    83,    85,   118,   129,   130,
     131,   132,   133,    62,   126,   140,   134,    61,   119,   119,
      62,    78,   128,   134,   125,   161,   173,   173,   162,   140,
     140,   122,   172,   120,   128,   134,   162,   139,   126,   138,
     140,   120,    95,   121,   140,   119,   141,    43,   130,   130,
     129,    83,    85,   114,   140,     7,   134,   119,   164,   167,
     134,   134,   140,   134,   128,   122,   118,   162,   121,   115,
     115,   120,   120,   128,   121,   119,   120,   119,   138,   139,
      19,   122,   157,   158,   119,   130,   130,   115,   131,   126,
     134,   119,   119,   121,   161,   120,   161,   150,   138,   126,
     120,   119,   139,    20,   122,   158,   159,   115,   134,   121,
     134,   161,   122,   122,   127,   119,   138,   126,    79,    79,
     122,   157,   161,   121,   122,   126,   119,   125,   125,   122,
     122,   161,   126,   122
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   123,   124,   125,   125,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   127,   128,
     129,   129,   129,   130,   130,   130,   131,   131,   131,   131,
     131,   132,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   134,   135,   135,   136,   136,   136,   137,   137,   138,
     138,   139,   139,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   141,   141,   141,   142,   142,   143,
     143,   144,   145,   145,   146,   146,   146,   146,   147,   147,
     147,   148,   148,   150,   149,   149,   149,   149,   149,   149,
     151,   151,   152,   152,   153,   153,   154,   155,   155,   156,
     156,   156,   156,   157,   157,   158,   158,   159,   159,   160,
     161,   161,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   163,   163,   164,   164,   165,   165,   166,   166,
     166,   166,   167,   167,   168,   168,   169,   170,   170,   171,
     171,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     173,   173,   173,   173,   173,   173,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174
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
       3,     3,     3,     3,     2,     5,     3,     2,     3,     3,
       1,     4,     4,     2,     2,     3,     4,     1,     3,     1,
       2,     2,     1,     3,     1,     2,     3,     4,     1,     1,
       1,     5,     7,     0,     8,     5,     9,    10,     7,     8,
       1,     2,     1,     2,     1,     2,     3,     2,     3,     6,
       7,     8,     9,     1,     2,     3,     4,     2,     3,     6,
       0,     1,     2,     3,     3,     4,     3,     4,     5,     6,
       4,     5,     1,     3,     1,     1,     1,     2,     2,     3,
       2,     3,     2,     3,     3,     4,     2,     2,     3,     1,
       2,     5,     2,     3,     3,     4,     5,     7,     8,     6,
       1,     1,     1,     1,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
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
#line 82 ".\\parser.y"
                    { Print("- R: statementList -> script"); }
#line 2440 "parser.tab.c"
    break;

  case 3: /* statementList: statementListItem  */
#line 86 ".\\parser.y"
                        { Print("- R: statementListItem -> statementList"); }
#line 2446 "parser.tab.c"
    break;

  case 4: /* statementList: statementList statementListItem  */
#line 87 ".\\parser.y"
                                      { Print("- R: statementList statementListItem -> statementList"); }
#line 2452 "parser.tab.c"
    break;

  case 5: /* statementListItem: ';'  */
#line 91 ".\\parser.y"
          { Print("- R: ';' -> statementListItem"); }
#line 2458 "parser.tab.c"
    break;

  case 6: /* statementListItem: expressionList statementSep  */
#line 92 ".\\parser.y"
                                  { Print("- R: expressionList statementSep -> statementListItem"); }
#line 2464 "parser.tab.c"
    break;

  case 11: /* statementListItem: continueStatement statementSep  */
#line 97 ".\\parser.y"
                                     { Print("- R: continueStatement statementSep -> statementListItem");  }
#line 2470 "parser.tab.c"
    break;

  case 12: /* statementListItem: breakStatement statementSep  */
#line 98 ".\\parser.y"
                                  { Print("- R: breakStatement statementSep -> statementListItem"); }
#line 2476 "parser.tab.c"
    break;

  case 13: /* statementListItem: returnStatement statementSep  */
#line 99 ".\\parser.y"
                                   { Print("- R: returnStatement statementSep -> statementListItem"); }
#line 2482 "parser.tab.c"
    break;

  case 18: /* statementSep: ';'  */
#line 107 ".\\parser.y"
          { Print("- R: ';' -> statementSep"); }
#line 2488 "parser.tab.c"
    break;

  case 19: /* initializer: '=' singleExpression  */
#line 111 ".\\parser.y"
                           { Print("- R: '=' singleExpression -> initializer"); }
#line 2494 "parser.tab.c"
    break;

  case 20: /* type: unionOrIntersectionOrPrimaryType  */
#line 117 ".\\parser.y"
                                       { Print("- R: unionOrIntersectionOrPrimaryType -> type"); }
#line 2500 "parser.tab.c"
    break;

  case 21: /* type: '|' unionOrIntersectionOrPrimaryType  */
#line 118 ".\\parser.y"
                                           { Print("- R: '|' unionOrIntersectionOrPrimaryType -> type"); }
#line 2506 "parser.tab.c"
    break;

  case 22: /* type: '&' unionOrIntersectionOrPrimaryType  */
#line 119 ".\\parser.y"
                                           { Print("- R: '&' unionOrIntersectionOrPrimaryType -> type"); }
#line 2512 "parser.tab.c"
    break;

  case 23: /* unionOrIntersectionOrPrimaryType: unionOrIntersectionOrPrimaryType '|' unionOrIntersectionOrPrimaryType  */
#line 123 ".\\parser.y"
                                                                            { Print("- R: unionOrIntersectionOrPrimaryType '|' unionOrIntersectionOrPrimaryType -> unionOrIntersectionOrPrimaryType"); }
#line 2518 "parser.tab.c"
    break;

  case 24: /* unionOrIntersectionOrPrimaryType: unionOrIntersectionOrPrimaryType '&' unionOrIntersectionOrPrimaryType  */
#line 124 ".\\parser.y"
                                                                            { Print("- R: unionOrIntersectionOrPrimaryType '&' unionOrIntersectionOrPrimaryType -> unionOrIntersectionOrPrimaryType"); }
#line 2524 "parser.tab.c"
    break;

  case 25: /* unionOrIntersectionOrPrimaryType: primaryType  */
#line 125 ".\\parser.y"
                  { Print("- R: primaryType -> argument"); }
#line 2530 "parser.tab.c"
    break;

  case 26: /* primaryType: '(' type ')'  */
#line 129 ".\\parser.y"
                   { Print("- R: '(' type ')' -> primaryType"); }
#line 2536 "parser.tab.c"
    break;

  case 27: /* primaryType: predefinedType  */
#line 130 ".\\parser.y"
                     { Print("- R: predefinedType -> primaryType"); }
#line 2542 "parser.tab.c"
    break;

  case 28: /* primaryType: typeReference  */
#line 131 ".\\parser.y"
                    { Print("- R: typeReference -> primaryType"); }
#line 2548 "parser.tab.c"
    break;

  case 29: /* primaryType: primaryType '[' ']'  */
#line 132 ".\\parser.y"
                          { Print("- R: primaryType ENDL_BRACKET_OPEN ']' -> primaryType"); }
#line 2554 "parser.tab.c"
    break;

  case 30: /* primaryType: primaryType '[' primaryType ']'  */
#line 133 ".\\parser.y"
                                      { Print("- R: primaryType ENDL_BRACKET_OPEN primaryType ']' -> primaryType"); }
#line 2560 "parser.tab.c"
    break;

  case 31: /* typeReference: identifier  */
#line 137 ".\\parser.y"
                 { Print("- R: identifier -> typeReference"); }
#line 2566 "parser.tab.c"
    break;

  case 32: /* predefinedType: NULL_KW  */
#line 141 ".\\parser.y"
              { Print("- R: NULL_LITERAL -> predefinedType"); }
#line 2572 "parser.tab.c"
    break;

  case 33: /* predefinedType: INT_LIT  */
#line 142 ".\\parser.y"
              { Print("- R: INT_LIT -> predefinedType"); }
#line 2578 "parser.tab.c"
    break;

  case 34: /* predefinedType: FLOAT_LIT  */
#line 143 ".\\parser.y"
                { Print("- R: FLOAT_LIT -> predefinedType"); }
#line 2584 "parser.tab.c"
    break;

  case 35: /* predefinedType: TRUE_KW  */
#line 144 ".\\parser.y"
              { Print("- R: TRUE_LITERAL -> predefinedType"); }
#line 2590 "parser.tab.c"
    break;

  case 36: /* predefinedType: FALSE_KW  */
#line 145 ".\\parser.y"
               { Print("- R: FALSE_LITERAL -> predefinedType"); }
#line 2596 "parser.tab.c"
    break;

  case 37: /* predefinedType: STRING_LIT  */
#line 146 ".\\parser.y"
                 { Print("- R: STRING_LIT -> predefinedType"); }
#line 2602 "parser.tab.c"
    break;

  case 38: /* predefinedType: UNIQUE SYMBOL  */
#line 147 ".\\parser.y"
                    { Print("- R: UNIQUE SYMBOL -> predefinedType"); }
#line 2608 "parser.tab.c"
    break;

  case 39: /* predefinedType: UNKNOWN  */
#line 148 ".\\parser.y"
              { Print("- R: UNKNOWN -> predefinedType"); }
#line 2614 "parser.tab.c"
    break;

  case 40: /* predefinedType: VOID  */
#line 149 ".\\parser.y"
           { Print("- R: VOID -> predefinedType"); }
#line 2620 "parser.tab.c"
    break;

  case 41: /* typeAnnotation: ':' type  */
#line 161 ".\\parser.y"
               { Print("- R: ':' type -> typeAnnotation"); }
#line 2626 "parser.tab.c"
    break;

  case 42: /* arrayLiteral: '[' elementList ']'  */
#line 166 ".\\parser.y"
                          { Print("- R: [ elementList ']' -> arrayLiteral"); }
#line 2632 "parser.tab.c"
    break;

  case 43: /* arrayLiteral: ENDL_BRACKET_OPEN elementList ']'  */
#line 167 ".\\parser.y"
                                        { Print("- R: ENDL_BRACKET_OPEN elementList ']' -> arrayLiteral"); }
#line 2638 "parser.tab.c"
    break;

  case 44: /* elementList: %empty  */
#line 171 ".\\parser.y"
                  { Print("- R: #empty# -> elementList"); }
#line 2644 "parser.tab.c"
    break;

  case 45: /* elementList: arrayElement  */
#line 172 ".\\parser.y"
                   { Print("- R: arrayElement -> elementList"); }
#line 2650 "parser.tab.c"
    break;

  case 46: /* elementList: elementList ',' elementList  */
#line 173 ".\\parser.y"
                                  { Print("- R: elementList ',' elementList -> elementList"); }
#line 2656 "parser.tab.c"
    break;

  case 47: /* arrayElement: singleExpression  */
#line 177 ".\\parser.y"
                       { Print("- R: singleExpression -> arrayElement"); }
#line 2662 "parser.tab.c"
    break;

  case 48: /* arrayElement: ELLIPSIS singleExpression  */
#line 178 ".\\parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> arrayElement"); }
#line 2668 "parser.tab.c"
    break;

  case 49: /* expressionListOpt: %empty  */
#line 184 ".\\parser.y"
                  { Print("- R: #empty# -> expressionListOpt"); }
#line 2674 "parser.tab.c"
    break;

  case 50: /* expressionListOpt: expressionList  */
#line 185 ".\\parser.y"
                     { Print("- R: expressionList -> expressionListOpt"); }
#line 2680 "parser.tab.c"
    break;

  case 51: /* expressionList: singleExpression  */
#line 189 ".\\parser.y"
                       { Print("- R: singleExpression -> expressionList"); }
#line 2686 "parser.tab.c"
    break;

  case 52: /* expressionList: expressionList ',' singleExpression  */
#line 190 ".\\parser.y"
                                          { Print("- R: expressionList ',' singleExpression -> expressionList"); }
#line 2692 "parser.tab.c"
    break;

  case 53: /* singleExpression: identifier  */
#line 194 ".\\parser.y"
                 { Print("- R: identifier -> singleExpression"); }
#line 2698 "parser.tab.c"
    break;

  case 54: /* singleExpression: THIS  */
#line 195 ".\\parser.y"
           { Print("- R: THIS -> singleExpression"); }
#line 2704 "parser.tab.c"
    break;

  case 55: /* singleExpression: SUPER  */
#line 196 ".\\parser.y"
            { Print("- R: SUPER -> singleExpression"); }
#line 2710 "parser.tab.c"
    break;

  case 56: /* singleExpression: INT_LIT  */
#line 197 ".\\parser.y"
              { Print("- R: INT_LIT -> singleExpression"); }
#line 2716 "parser.tab.c"
    break;

  case 57: /* singleExpression: FLOAT_LIT  */
#line 198 ".\\parser.y"
                { Print("- R: FLOAT_LIT -> singleExpression"); }
#line 2722 "parser.tab.c"
    break;

  case 58: /* singleExpression: STRING_LIT  */
#line 199 ".\\parser.y"
                 { Print("- R: STRING_LIT -> singleExpression"); }
#line 2728 "parser.tab.c"
    break;

  case 59: /* singleExpression: TEMPLATE_LITERAL  */
#line 200 ".\\parser.y"
                       { Print("- R: TEMPLATE_LITERAL -> singleExpression"); }
#line 2734 "parser.tab.c"
    break;

  case 60: /* singleExpression: TRUE_KW  */
#line 201 ".\\parser.y"
              { Print("- R: TRUE_LITERAL -> singleExpression"); }
#line 2740 "parser.tab.c"
    break;

  case 61: /* singleExpression: FALSE_KW  */
#line 202 ".\\parser.y"
               { Print("- R: FALSE_LITERAL -> singleExpression"); }
#line 2746 "parser.tab.c"
    break;

  case 62: /* singleExpression: NULL_KW  */
#line 203 ".\\parser.y"
              { Print("- R: NULL_LITERAL -> singleExpression"); }
#line 2752 "parser.tab.c"
    break;

  case 63: /* singleExpression: '-' singleExpression  */
#line 204 ".\\parser.y"
                                        { Print("- R: '-' singleExpression -> singleExpression"); }
#line 2758 "parser.tab.c"
    break;

  case 64: /* singleExpression: '+' singleExpression  */
#line 205 ".\\parser.y"
                                       { Print("- R: '+'s singleExpression -> singleExpression"); }
#line 2764 "parser.tab.c"
    break;

  case 65: /* singleExpression: '!' singleExpression  */
#line 206 ".\\parser.y"
                           { Print("- R: '!' singleExpression -> singleExpression"); }
#line 2770 "parser.tab.c"
    break;

  case 66: /* singleExpression: '~' singleExpression  */
#line 207 ".\\parser.y"
                           { Print("- R: '~' singleExpression -> singleExpression"); }
#line 2776 "parser.tab.c"
    break;

  case 67: /* singleExpression: singleExpression OPERATOR_INCREMENT  */
#line 208 ".\\parser.y"
                                                               { Print("- R: singleExpression OPERATOR_INCREMENT -> singleExpression"); }
#line 2782 "parser.tab.c"
    break;

  case 68: /* singleExpression: singleExpression OPERATOR_DECREMENT  */
#line 209 ".\\parser.y"
                                                               { Print("- R: singleExpression OPERATOR_DECREMENT -> singleExpression"); }
#line 2788 "parser.tab.c"
    break;

  case 69: /* singleExpression: ENDL_OPERATOR_INCREMENT singleExpression  */
#line 210 ".\\parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 2794 "parser.tab.c"
    break;

  case 70: /* singleExpression: ENDL_OPERATOR_DECREMENT singleExpression  */
#line 211 ".\\parser.y"
                                                                    { Print("- R: ENDL_OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 2800 "parser.tab.c"
    break;

  case 71: /* singleExpression: OPERATOR_INCREMENT singleExpression  */
#line 212 ".\\parser.y"
                                                               { Print("- R: OPERATOR_INCREMENT singleExpression -> singleExpression"); }
#line 2806 "parser.tab.c"
    break;

  case 72: /* singleExpression: OPERATOR_DECREMENT singleExpression  */
#line 213 ".\\parser.y"
                                                               { Print("- R: OPERATOR_DECREMENT singleExpression -> singleExpression"); }
#line 2812 "parser.tab.c"
    break;

  case 73: /* singleExpression: singleExpression '+' singleExpression  */
#line 214 ".\\parser.y"
                                            { Print("- R: singleExpression '+' singleExpression -> singleExpression"); }
#line 2818 "parser.tab.c"
    break;

  case 74: /* singleExpression: singleExpression '-' singleExpression  */
#line 215 ".\\parser.y"
                                            { Print("- R: singleExpression '-' singleExpression -> singleExpression"); }
#line 2824 "parser.tab.c"
    break;

  case 75: /* singleExpression: singleExpression '*' singleExpression  */
#line 216 ".\\parser.y"
                                            { Print("- R: singleExpression '*' singleExpression -> singleExpression"); }
#line 2830 "parser.tab.c"
    break;

  case 76: /* singleExpression: singleExpression '/' singleExpression  */
#line 217 ".\\parser.y"
                                            { Print("- R: singleExpression '/' singleExpression -> singleExpression"); }
#line 2836 "parser.tab.c"
    break;

  case 77: /* singleExpression: singleExpression '%' singleExpression  */
#line 218 ".\\parser.y"
                                            { Print("- R: singleExpression '%' singleExpression -> singleExpression"); }
#line 2842 "parser.tab.c"
    break;

  case 78: /* singleExpression: singleExpression '<' singleExpression  */
#line 219 ".\\parser.y"
                                            { Print("- R: singleExpression '<' singleExpression -> singleExpression"); }
#line 2848 "parser.tab.c"
    break;

  case 79: /* singleExpression: singleExpression '>' singleExpression  */
#line 220 ".\\parser.y"
                                            { Print("- R: singleExpression '>' singleExpression -> singleExpression"); }
#line 2854 "parser.tab.c"
    break;

  case 80: /* singleExpression: singleExpression OPERATOR_POWER singleExpression  */
#line 221 ".\\parser.y"
                                                       { Print("- R: singleExpression OPERATOR_POWER singleExpression -> singleExpression"); }
#line 2860 "parser.tab.c"
    break;

  case 81: /* singleExpression: singleExpression OPERATOR_EQUAL singleExpression  */
#line 222 ".\\parser.y"
                                                       { Print("- R: singleExpression OPERATOR_EQUAL singleExpression -> singleExpression"); }
#line 2866 "parser.tab.c"
    break;

  case 82: /* singleExpression: singleExpression OPERATOR_NOT_EQUAL singleExpression  */
#line 223 ".\\parser.y"
                                                           { Print("- R: singleExpression OPERATOR_NOT_EQUAL singleExpression -> singleExpression"); }
#line 2872 "parser.tab.c"
    break;

  case 83: /* singleExpression: singleExpression OPERATOR_STRICT_EQUAL singleExpression  */
#line 224 ".\\parser.y"
                                                              { Print("- R: singleExpression OPERATOR_STRICT_EQUAL singleExpression -> singleExpression"); }
#line 2878 "parser.tab.c"
    break;

  case 84: /* singleExpression: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression  */
#line 225 ".\\parser.y"
                                                                  { Print("- R: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression -> singleExpression"); }
#line 2884 "parser.tab.c"
    break;

  case 85: /* singleExpression: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression  */
#line 226 ".\\parser.y"
                                                                 { Print("- R: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression -> singleExpression"); }
#line 2890 "parser.tab.c"
    break;

  case 86: /* singleExpression: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression  */
#line 227 ".\\parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression -> singleExpression"); }
#line 2896 "parser.tab.c"
    break;

  case 87: /* singleExpression: singleExpression '=' singleExpression  */
#line 228 ".\\parser.y"
                                            { Print("- R: singleExpression '=' singleExpression -> singleExpression"); }
#line 2902 "parser.tab.c"
    break;

  case 88: /* singleExpression: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression  */
#line 229 ".\\parser.y"
                                                                 { Print("- R: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression -> singleExpression"); }
#line 2908 "parser.tab.c"
    break;

  case 89: /* singleExpression: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression  */
#line 230 ".\\parser.y"
                                                               { Print("- R: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression -> singleExpression"); }
#line 2914 "parser.tab.c"
    break;

  case 90: /* singleExpression: singleExpression OPERATOR_ASSIGN_MOD singleExpression  */
#line 231 ".\\parser.y"
                                                            { Print("- R: singleExpression OPERATOR_ASSIGN_MOD singleExpression -> singleExpression"); }
#line 2920 "parser.tab.c"
    break;

  case 91: /* singleExpression: singleExpression OPERATOR_ASSIGN_PLUS singleExpression  */
#line 232 ".\\parser.y"
                                                             { Print("- R: singleExpression OPERATOR_ASSIGN_PLUS singleExpression -> singleExpression"); }
#line 2926 "parser.tab.c"
    break;

  case 92: /* singleExpression: singleExpression OPERATOR_ASSIGN_MINUS singleExpression  */
#line 233 ".\\parser.y"
                                                              { Print("- R: singleExpression OPERATOR_ASSIGN_MINUS singleExpression -> singleExpression"); }
#line 2932 "parser.tab.c"
    break;

  case 93: /* singleExpression: singleExpression OPERATOR_ASSIGN_SHIFT_LEFT singleExpression  */
#line 234 ".\\parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_SHIFT_LEFT singleExpression -> singleExpression"); }
#line 2938 "parser.tab.c"
    break;

  case 94: /* singleExpression: singleExpression OPERATOR_ASSIGN_SHIFT_RIGHT singleExpression  */
#line 235 ".\\parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 2944 "parser.tab.c"
    break;

  case 95: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_AND singleExpression  */
#line 236 ".\\parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_AND singleExpression -> singleExpression"); }
#line 2950 "parser.tab.c"
    break;

  case 96: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_XOR singleExpression  */
#line 237 ".\\parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_XOR singleExpression -> singleExpression"); }
#line 2956 "parser.tab.c"
    break;

  case 97: /* singleExpression: singleExpression OPERATOR_ASSIGN_BITWISE_OR singleExpression  */
#line 238 ".\\parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_OR singleExpression -> singleExpression"); }
#line 2962 "parser.tab.c"
    break;

  case 98: /* singleExpression: singleExpression OPERATOR_ASSIGN_POWER singleExpression  */
#line 239 ".\\parser.y"
                                                              { Print("- R: singleExpression OPERATOR_ASSIGN_POWER singleExpression -> singleExpression"); }
#line 2968 "parser.tab.c"
    break;

  case 99: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression  */
#line 240 ".\\parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression -> singleExpression"); }
#line 2974 "parser.tab.c"
    break;

  case 100: /* singleExpression: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression  */
#line 241 ".\\parser.y"
                                                                   { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression -> singleExpression"); }
#line 2980 "parser.tab.c"
    break;

  case 101: /* singleExpression: singleExpression OPERATOR_ASSIGN_NULLISH_COALESCING singleExpression  */
#line 242 ".\\parser.y"
                                                                           { Print("- R: singleExpression OPERATOR_ASSIGN_NULLISH_COALESCING singleExpression -> singleExpression"); }
#line 2986 "parser.tab.c"
    break;

  case 102: /* singleExpression: singleExpression OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT singleExpression  */
#line 243 ".\\parser.y"
                                                                             { Print("- R: singleExpression OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 2992 "parser.tab.c"
    break;

  case 103: /* singleExpression: singleExpression OPERATOR_LOGICAL_OR singleExpression  */
#line 244 ".\\parser.y"
                                                            { Print("- R: singleExpression OPERATOR_LOGICAL_OR singleExpression -> singleExpression"); }
#line 2998 "parser.tab.c"
    break;

  case 104: /* singleExpression: singleExpression OPERATOR_LOGICAL_AND singleExpression  */
#line 245 ".\\parser.y"
                                                             { Print("- R: singleExpression OPERATOR_LOGICAL_AND singleExpression -> singleExpression"); }
#line 3004 "parser.tab.c"
    break;

  case 105: /* singleExpression: singleExpression '|' singleExpression  */
#line 246 ".\\parser.y"
                                            { Print("- R: singleExpression '|' singleExpression -> singleExpression"); }
#line 3010 "parser.tab.c"
    break;

  case 106: /* singleExpression: singleExpression '^' singleExpression  */
#line 247 ".\\parser.y"
                                            { Print("- R: singleExpression '^' singleExpression -> singleExpression"); }
#line 3016 "parser.tab.c"
    break;

  case 107: /* singleExpression: singleExpression '&' singleExpression  */
#line 248 ".\\parser.y"
                                            { Print("- R: singleExpression '&' singleExpression -> singleExpression"); }
#line 3022 "parser.tab.c"
    break;

  case 108: /* singleExpression: singleExpression OPERATOR_SHIFT_LEFT singleExpression  */
#line 249 ".\\parser.y"
                                                            { Print("- R: singleExpression OPERATOR_SHIFT_LEFT singleExpression -> singleExpression"); }
#line 3028 "parser.tab.c"
    break;

  case 109: /* singleExpression: singleExpression OPERATOR_SHIFT_RIGHT singleExpression  */
#line 250 ".\\parser.y"
                                                             { Print("- R: singleExpression OPERATOR_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3034 "parser.tab.c"
    break;

  case 110: /* singleExpression: singleExpression OPERATOR_UNSIGNED_SHIFT_RIGHT singleExpression  */
#line 251 ".\\parser.y"
                                                                      { Print("- R: singleExpression OPERATOR_UNSIGNED_SHIFT_RIGHT singleExpression -> singleExpression"); }
#line 3040 "parser.tab.c"
    break;

  case 111: /* singleExpression: singleExpression OPERATOR_NULLISH_COALESCING singleExpression  */
#line 252 ".\\parser.y"
                                                                    { Print("- R: singleExpression OPERATOR_NULLISH_COALESCING singleExpression -> singleExpression"); }
#line 3046 "parser.tab.c"
    break;

  case 112: /* singleExpression: singleExpression INSTANCEOF singleExpression  */
#line 254 ".\\parser.y"
                                                   { Print("- R: singleExpression INSTANCEOF singleExpression -> singleExpression"); }
#line 3052 "parser.tab.c"
    break;

  case 113: /* singleExpression: singleExpression IN singleExpression  */
#line 255 ".\\parser.y"
                                           { Print("- R: singleExpression IN singleExpression -> singleExpression"); }
#line 3058 "parser.tab.c"
    break;

  case 114: /* singleExpression: singleExpression TEMPLATE_LITERAL  */
#line 257 ".\\parser.y"
                                        { Print("- R: singleExpression TEMPLATE_LITERAL -> singleExpression"); }
#line 3064 "parser.tab.c"
    break;

  case 115: /* singleExpression: singleExpression '?' singleExpression ':' singleExpression  */
#line 258 ".\\parser.y"
                                                                 { Print("- R: singleExpression '?' singleExpression ':' singleExpression -> singleExpression"); }
#line 3070 "parser.tab.c"
    break;

  case 116: /* singleExpression: '(' expressionList ')'  */
#line 260 ".\\parser.y"
                             { Print("- R: '(' expressionList ')' -> singleExpression"); }
#line 3076 "parser.tab.c"
    break;

  case 117: /* singleExpression: singleExpression arguments  */
#line 262 ".\\parser.y"
                                 { Print("- R: singleExpression arguments -> singleExpression"); }
#line 3082 "parser.tab.c"
    break;

  case 118: /* singleExpression: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression  */
#line 264 ".\\parser.y"
                                                                   { Print("- R: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression -> singleExpression"); }
#line 3088 "parser.tab.c"
    break;

  case 119: /* singleExpression: singleExpression '.' identifier  */
#line 265 ".\\parser.y"
                                      { Print("- R: singleExpression '.' identifier -> singleExpression"); }
#line 3094 "parser.tab.c"
    break;

  case 120: /* singleExpression: arrayLiteral  */
#line 267 ".\\parser.y"
                   { Print("- R: arrayLiteral -> singleExpression"); }
#line 3100 "parser.tab.c"
    break;

  case 121: /* singleExpression: singleExpression '[' expressionList ']'  */
#line 268 ".\\parser.y"
                                              { Print("- R: singleExpression '[' singleExpression ']' -> singleExpression"); }
#line 3106 "parser.tab.c"
    break;

  case 122: /* singleExpression: singleExpression ENDL_BRACKET_OPEN expressionList ']'  */
#line 269 ".\\parser.y"
                                                            { Print("- R: singleExpression ENDL_BRACKET_OPEN singleExpression ']' -> singleExpression"); }
#line 3112 "parser.tab.c"
    break;

  case 123: /* singleExpression: NEW singleExpression  */
#line 271 ".\\parser.y"
                           { Print("- R: NEW singleExpression -> singleExpression"); }
#line 3118 "parser.tab.c"
    break;

  case 124: /* arguments: '(' ')'  */
#line 275 ".\\parser.y"
              { Print("- R: '(' ')' -> arguments"); }
#line 3124 "parser.tab.c"
    break;

  case 125: /* arguments: '(' argumentList ')'  */
#line 276 ".\\parser.y"
                           { Print("- R: '(' argumentList ')' -> arguments"); }
#line 3130 "parser.tab.c"
    break;

  case 126: /* arguments: '(' argumentList ',' ')'  */
#line 277 ".\\parser.y"
                               { Print("- R: '(' argumentList ',' ') -> arguments"); }
#line 3136 "parser.tab.c"
    break;

  case 127: /* argumentList: argument  */
#line 281 ".\\parser.y"
               { Print("- R: argument -> argumentList"); }
#line 3142 "parser.tab.c"
    break;

  case 128: /* argumentList: argumentList ',' arguments  */
#line 282 ".\\parser.y"
                                 { Print("- R: argumentList ',' arguments -> argumentList"); }
#line 3148 "parser.tab.c"
    break;

  case 129: /* argument: singleExpression  */
#line 286 ".\\parser.y"
                       { Print("- R: singleExpression -> argument"); }
#line 3154 "parser.tab.c"
    break;

  case 130: /* argument: ELLIPSIS singleExpression  */
#line 287 ".\\parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> argument"); }
#line 3160 "parser.tab.c"
    break;

  case 131: /* varStatement: varModifier varDeclarationList  */
#line 293 ".\\parser.y"
                                     { Print("- R: varModifier varDeclarationList -> varStatement"); }
#line 3166 "parser.tab.c"
    break;

  case 132: /* varDeclarationList: varDeclaration  */
#line 297 ".\\parser.y"
                     { Print("- R: varDeclaration -> argument"); }
#line 3172 "parser.tab.c"
    break;

  case 133: /* varDeclarationList: varDeclarationList ',' varDeclaration  */
#line 298 ".\\parser.y"
                                            { Print("- R: varDeclarationList ',' varDeclaration -> varDeclarationList"); }
#line 3178 "parser.tab.c"
    break;

  case 134: /* varDeclaration: identifier  */
#line 302 ".\\parser.y"
                 { Print("- R: identifier -> varDeclaration"); }
#line 3184 "parser.tab.c"
    break;

  case 135: /* varDeclaration: identifier typeAnnotation  */
#line 303 ".\\parser.y"
                                { Print("- R: identifier typeAnnotation -> varDeclaration"); }
#line 3190 "parser.tab.c"
    break;

  case 136: /* varDeclaration: identifier '=' singleExpression  */
#line 304 ".\\parser.y"
                                      { Print("- R: identifier '=' singleExpression -> varDeclaration"); }
#line 3196 "parser.tab.c"
    break;

  case 137: /* varDeclaration: identifier typeAnnotation '=' singleExpression  */
#line 305 ".\\parser.y"
                                                     { Print("- R: identifier typeAnnotation '=' singleExpression -> varDeclaration"); }
#line 3202 "parser.tab.c"
    break;

  case 138: /* varModifier: VAR  */
#line 309 ".\\parser.y"
          { Print("- R: VAR -> varModifier"); }
#line 3208 "parser.tab.c"
    break;

  case 139: /* varModifier: LET  */
#line 310 ".\\parser.y"
          { Print("- R: LET -> varModifier"); }
#line 3214 "parser.tab.c"
    break;

  case 140: /* varModifier: CONST  */
#line 311 ".\\parser.y"
            { Print("- R: CONST -> varModifier"); }
#line 3220 "parser.tab.c"
    break;

  case 141: /* ifStatement: IF '(' expressionList ')' statementListItem  */
#line 317 ".\\parser.y"
                                                                     { Print("- R:  IF '(' expressionList ')' statementListItem -> ifStatement"); }
#line 3226 "parser.tab.c"
    break;

  case 142: /* ifStatement: IF '(' expressionList ')' statementListItem ELSE statementListItem  */
#line 318 ".\\parser.y"
                                                                         { Print("- R: IF '(' expressionList ')' statementListItem ELSE statementListItem -> ifStatement"); }
#line 3232 "parser.tab.c"
    break;

  case 143: /* $@1: %empty  */
#line 322 ".\\parser.y"
                                                        { doWhileASI(); }
#line 3238 "parser.tab.c"
    break;

  case 144: /* iterationStatement: DO statementListItem WHILE '(' expressionList ')' $@1 statementSep  */
#line 322 ".\\parser.y"
                                                                                       { Print("- R: DO statementListItem WHILE '(' expressionList ')' statementSep -> iterationStatement"); }
#line 3244 "parser.tab.c"
    break;

  case 145: /* iterationStatement: WHILE '(' expressionList ')' statementListItem  */
#line 323 ".\\parser.y"
                                                     { Print("- R: WHILE '(' expressionList ')' statementListItem -> iterationStatement"); }
#line 3250 "parser.tab.c"
    break;

  case 146: /* iterationStatement: FOR '(' expressionListOpt ';' expressionListOpt ';' expressionListOpt ')' statementListItem  */
#line 324 ".\\parser.y"
                                                                                                  { Print("- R: FOR '(' expressionListOpt ';' expressionListOpt ';' expressionListOpt ')' statementListItem -> iterationStatement"); }
#line 3256 "parser.tab.c"
    break;

  case 147: /* iterationStatement: FOR '(' varModifier varDeclarationList ';' expressionListOpt ';' expressionListOpt ')' statementListItem  */
#line 325 ".\\parser.y"
                                                                                                               { Print("- R: FOR '(' varModifier varDeclarationList ';' expressionListOpt ';' expressionListOpt ')' statementListItem -> iterationStatement"); }
#line 3262 "parser.tab.c"
    break;

  case 148: /* iterationStatement: FOR '(' singleExpression IN singleExpression ')' statementListItem  */
#line 326 ".\\parser.y"
                                                                         { Print("- R: FOR '(' singleExpression IN singleExpression ')' statementListItem -> iterationStatement"); }
#line 3268 "parser.tab.c"
    break;

  case 149: /* iterationStatement: FOR '(' varModifier varDeclaration IN expressionList ')' statementListItem  */
#line 327 ".\\parser.y"
                                                                                 { Print("- R: FOR '(' varModifier varDeclaration IN expressionList ')' statementListItem -> iterationStatement"); }
#line 3274 "parser.tab.c"
    break;

  case 150: /* continueStatement: CONTINUE  */
#line 331 ".\\parser.y"
               { Print("- R: CONTINUE -> returnStatement"); }
#line 3280 "parser.tab.c"
    break;

  case 151: /* continueStatement: CONTINUE identifier  */
#line 332 ".\\parser.y"
                          { Print("- R: CONTINUE identifier -> returnStatement"); }
#line 3286 "parser.tab.c"
    break;

  case 152: /* breakStatement: BREAK  */
#line 336 ".\\parser.y"
             { Print("- R: BREAK -> returnStatement"); }
#line 3292 "parser.tab.c"
    break;

  case 153: /* breakStatement: BREAK identifier  */
#line 337 ".\\parser.y"
                       { Print("- R: BREAK identifier -> returnStatement"); }
#line 3298 "parser.tab.c"
    break;

  case 154: /* returnStatement: RETURN  */
#line 341 ".\\parser.y"
             { Print("- R: RETURN -> returnStatement"); }
#line 3304 "parser.tab.c"
    break;

  case 155: /* returnStatement: RETURN singleExpression  */
#line 342 ".\\parser.y"
                              { Print("- R: RETURN singleExpression -> returnStatement"); }
#line 3310 "parser.tab.c"
    break;

  case 156: /* labelledStatement: identifier ':' statementListItem  */
#line 346 ".\\parser.y"
                                       { Print("- R: identifier ':' statementListItem -> labelledStatement"); }
#line 3316 "parser.tab.c"
    break;

  case 157: /* blockStatement: '{' '}'  */
#line 350 ".\\parser.y"
              { Print("- R: '{' '}' -> blockStatement"); }
#line 3322 "parser.tab.c"
    break;

  case 158: /* blockStatement: '{' statementList '}'  */
#line 351 ".\\parser.y"
                            { Print("- R: '{' statementList '}' -> blockStatement"); }
#line 3328 "parser.tab.c"
    break;

  case 159: /* switchStatement: SWITCH '(' expressionList ')' '{' '}'  */
#line 355 ".\\parser.y"
                                            { Print("- R: SWITCH '(' expressionList ')' '{' '}' -> switchStatement"); }
#line 3334 "parser.tab.c"
    break;

  case 160: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList '}'  */
#line 356 ".\\parser.y"
                                                           { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList '}' -> switchStatement"); }
#line 3340 "parser.tab.c"
    break;

  case 161: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause '}'  */
#line 357 ".\\parser.y"
                                                                         { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause '}' -> switchStatement"); }
#line 3346 "parser.tab.c"
    break;

  case 162: /* switchStatement: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause caseClauseList '}'  */
#line 358 ".\\parser.y"
                                                                                        { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause caseClauseList '}' -> switchStatement"); }
#line 3352 "parser.tab.c"
    break;

  case 163: /* caseClauseList: caseClause  */
#line 362 ".\\parser.y"
                 { Print("- R: caseClause -> caseClauseList"); }
#line 3358 "parser.tab.c"
    break;

  case 164: /* caseClauseList: caseClauseList caseClause  */
#line 363 ".\\parser.y"
                                { Print("- R: caseClauseList caseClause -> caseClauseList"); }
#line 3364 "parser.tab.c"
    break;

  case 165: /* caseClause: CASE expressionList ':'  */
#line 367 ".\\parser.y"
                              { Print("- R: CASE expressionList ':' -> caseClause"); }
#line 3370 "parser.tab.c"
    break;

  case 166: /* caseClause: CASE expressionList ':' statementList  */
#line 368 ".\\parser.y"
                                            { Print("- R: CASE expressionList ':' statementList -> caseClause"); }
#line 3376 "parser.tab.c"
    break;

  case 167: /* defaultClause: DEFAULT ':'  */
#line 372 ".\\parser.y"
                  { Print("- R: DEFAULT ':' -> defaultClause"); }
#line 3382 "parser.tab.c"
    break;

  case 168: /* defaultClause: DEFAULT ':' statementList  */
#line 373 ".\\parser.y"
                                { Print("- R: DEFAULT ':' statementList -> defaultClause"); }
#line 3388 "parser.tab.c"
    break;

  case 169: /* functionDeclaration: FUNCTION identifier callSignature '{' functionBody '}'  */
#line 379 ".\\parser.y"
                                                             { Print("- R: FUNCTION ID callSignature '{' functionBody '}' -> functionDeclaration"); }
#line 3394 "parser.tab.c"
    break;

  case 170: /* functionBody: %empty  */
#line 383 ".\\parser.y"
                  { Print("- R: #empty# -> functionBody"); }
#line 3400 "parser.tab.c"
    break;

  case 171: /* functionBody: statementList  */
#line 384 ".\\parser.y"
                    { Print("- R: statementList -> returnStatement"); }
#line 3406 "parser.tab.c"
    break;

  case 172: /* callSignature: '(' ')'  */
#line 388 ".\\parser.y"
              { Print("- R: '(' ')' -> callSignature"); }
#line 3412 "parser.tab.c"
    break;

  case 173: /* callSignature: '(' ')' typeAnnotation  */
#line 389 ".\\parser.y"
                             { Print("- R: '(' ')' typeAnnotation -> callSignature"); }
#line 3418 "parser.tab.c"
    break;

  case 174: /* callSignature: '(' restParameter ')'  */
#line 390 ".\\parser.y"
                            { Print("- R: '(' restParameter ')' -> callSignature"); }
#line 3424 "parser.tab.c"
    break;

  case 175: /* callSignature: '(' restParameter ')' typeAnnotation  */
#line 391 ".\\parser.y"
                                           { Print("- R: '(' restParameter ')' typeAnnotation -> callSignature"); }
#line 3430 "parser.tab.c"
    break;

  case 176: /* callSignature: '(' parameterList ')'  */
#line 392 ".\\parser.y"
                            { Print("- R: '(' parameterList ')' -> callSignature"); }
#line 3436 "parser.tab.c"
    break;

  case 177: /* callSignature: '(' parameterList ')' typeAnnotation  */
#line 393 ".\\parser.y"
                                           { Print("- R: '(' parameterList ')' typeAnnotation -> callSignature"); }
#line 3442 "parser.tab.c"
    break;

  case 178: /* callSignature: '(' parameterList ',' restParameter ')'  */
#line 394 ".\\parser.y"
                                              { Print("- R: '(' parameterList ',' restParameter ')' -> callSignature"); }
#line 3448 "parser.tab.c"
    break;

  case 179: /* callSignature: '(' parameterList ',' restParameter ')' typeAnnotation  */
#line 395 ".\\parser.y"
                                                             { Print("- R: '(' parameterList ',' restParameter ')' typeAnnotation -> callSignature"); }
#line 3454 "parser.tab.c"
    break;

  case 180: /* callSignature: '(' parameterList ',' ')'  */
#line 396 ".\\parser.y"
                                { Print("- R: '(' parameterList ',' ')' -> callSignature"); }
#line 3460 "parser.tab.c"
    break;

  case 181: /* callSignature: '(' parameterList ',' ')' typeAnnotation  */
#line 397 ".\\parser.y"
                                               { Print("- R: '(' parameterList ',' ')' typeAnnotation -> callSignature"); }
#line 3466 "parser.tab.c"
    break;

  case 182: /* parameterList: parameter  */
#line 401 ".\\parser.y"
                { Print("- R: parameter -> parameterList"); }
#line 3472 "parser.tab.c"
    break;

  case 183: /* parameterList: parameterList ',' parameter  */
#line 402 ".\\parser.y"
                                  { Print("- R: parameterList ',' parameter -> parameterList"); }
#line 3478 "parser.tab.c"
    break;

  case 184: /* parameter: requiredParameter  */
#line 406 ".\\parser.y"
                        { Print("- R: requiredParameter -> parameter"); }
#line 3484 "parser.tab.c"
    break;

  case 185: /* parameter: optionalParameter  */
#line 407 ".\\parser.y"
                        { Print("- R: optionalParameter -> parameter"); }
#line 3490 "parser.tab.c"
    break;

  case 186: /* requiredParameter: identifier  */
#line 411 ".\\parser.y"
                 { Print("- R: ID -> requiredParameter"); }
#line 3496 "parser.tab.c"
    break;

  case 187: /* requiredParameter: identifier typeAnnotation  */
#line 412 ".\\parser.y"
                                { Print("- R: ID typeAnnotation -> requiredParameter"); }
#line 3502 "parser.tab.c"
    break;

  case 188: /* optionalParameter: identifier '?'  */
#line 416 ".\\parser.y"
                     { Print("- R: ID '?' -> optionalParameter"); }
#line 3508 "parser.tab.c"
    break;

  case 189: /* optionalParameter: identifier '?' typeAnnotation  */
#line 417 ".\\parser.y"
                                    { Print("- R: ID '?' typeAnnotation -> optionalParameter"); }
#line 3514 "parser.tab.c"
    break;

  case 190: /* optionalParameter: identifier initializer  */
#line 418 ".\\parser.y"
                             { Print("- R: ID initializer -> optionalParameter"); }
#line 3520 "parser.tab.c"
    break;

  case 191: /* optionalParameter: identifier typeAnnotation initializer  */
#line 419 ".\\parser.y"
                                            { Print("- R: ID typeAnnotation initializer -> optionalParameter"); }
#line 3526 "parser.tab.c"
    break;

  case 192: /* restParameter: ELLIPSIS singleExpression  */
#line 423 ".\\parser.y"
                                { Print("- R: ELLIPSIS singleExpression -> restParameter"); }
#line 3532 "parser.tab.c"
    break;

  case 193: /* restParameter: ELLIPSIS singleExpression typeAnnotation  */
#line 424 ".\\parser.y"
                                               { Print("- R: ELLIPSIS singleExpression typeAnnotation -> restParameter"); }
#line 3538 "parser.tab.c"
    break;

  case 194: /* classDeclaration: CLASS identifier classTail  */
#line 430 ".\\parser.y"
                                 { Print("- R: CLASS identifier classTail -> classDeclaration"); }
#line 3544 "parser.tab.c"
    break;

  case 195: /* classDeclaration: CLASS identifier classHeritage classTail  */
#line 431 ".\\parser.y"
                                               { Print("- R: CLASS identifier classHeritage classTail -> classDeclaration"); }
#line 3550 "parser.tab.c"
    break;

  case 196: /* classHeritage: EXTENDS typeReference  */
#line 435 ".\\parser.y"
                            { Print("- R: EXTENDS typeReference -> classHeritage"); }
#line 3556 "parser.tab.c"
    break;

  case 197: /* classTail: '{' '}'  */
#line 439 ".\\parser.y"
              { Print("- R: '{' '}' -> classTail"); }
#line 3562 "parser.tab.c"
    break;

  case 198: /* classTail: '{' classElementList '}'  */
#line 440 ".\\parser.y"
                               { Print("- R: '{' classElementList '}' -> classTail"); }
#line 3568 "parser.tab.c"
    break;

  case 199: /* classElementList: classElement  */
#line 444 ".\\parser.y"
                   { Print("- R: classElement -> classElementList"); }
#line 3574 "parser.tab.c"
    break;

  case 200: /* classElementList: classElementList classElement  */
#line 445 ".\\parser.y"
                                    { Print("- R: classElementList classElement -> classElementList"); }
#line 3580 "parser.tab.c"
    break;

  case 201: /* classElement: CONSTRUCTOR callSignature '{' functionBody '}'  */
#line 449 ".\\parser.y"
                                                     { Print("- R: CONSTRUCTOR callSignature '{' functionBody '}' -> classElement"); }
#line 3586 "parser.tab.c"
    break;

  case 202: /* classElement: propertyName ';'  */
#line 452 ".\\parser.y"
                       { Print("- R: propertyName ';' -> classElement"); }
#line 3592 "parser.tab.c"
    break;

  case 203: /* classElement: propertyName typeAnnotation ';'  */
#line 453 ".\\parser.y"
                                      { Print("- R: propertyName typeAnnotation ';' -> classElement"); }
#line 3598 "parser.tab.c"
    break;

  case 204: /* classElement: propertyName initializer ';'  */
#line 454 ".\\parser.y"
                                   { Print("- R: propertyName initializer ';' -> classElement"); }
#line 3604 "parser.tab.c"
    break;

  case 205: /* classElement: propertyName typeAnnotation initializer ';'  */
#line 455 ".\\parser.y"
                                                  { Print("- R: propertyName typeAnnotation initializer ';' -> classElement"); }
#line 3610 "parser.tab.c"
    break;

  case 206: /* classElement: propertyName callSignature '{' functionBody '}'  */
#line 458 ".\\parser.y"
                                                      { Print("- R: propertyName callSignature '{' functionBody '}' -> classElement"); }
#line 3616 "parser.tab.c"
    break;

  case 207: /* classElement: GET propertyName '(' ')' '{' functionBody '}'  */
#line 461 ".\\parser.y"
                                                    { Print("- R: GET propertyName '(' ')' '{' functionBody '}' -> classElement"); }
#line 3622 "parser.tab.c"
    break;

  case 208: /* classElement: GET propertyName '(' ')' typeAnnotation '{' functionBody '}'  */
#line 462 ".\\parser.y"
                                                                   { Print("- R: GET propertyName '(' ')' typeAnnotation '{' functionBody '}' -> classElement"); }
#line 3628 "parser.tab.c"
    break;

  case 209: /* classElement: SET propertyName callSignature '{' functionBody '}'  */
#line 463 ".\\parser.y"
                                                          { Print("- R: SET propertyName callSignature '{' functionBody '}' -> classElement"); }
#line 3634 "parser.tab.c"
    break;

  case 210: /* propertyName: identifier  */
#line 467 ".\\parser.y"
                 { Print("- R: identifier -> propertyName"); }
#line 3640 "parser.tab.c"
    break;

  case 211: /* propertyName: STRING_LIT  */
#line 468 ".\\parser.y"
                 { Print("- R: STRING_LIT -> propertyName"); }
#line 3646 "parser.tab.c"
    break;

  case 212: /* propertyName: INT_LIT  */
#line 469 ".\\parser.y"
              { Print("- R: INT_LIT -> propertyName"); }
#line 3652 "parser.tab.c"
    break;

  case 213: /* propertyName: FLOAT_LIT  */
#line 470 ".\\parser.y"
                { Print("- R: FLOAT_LIT -> propertyName"); }
#line 3658 "parser.tab.c"
    break;

  case 214: /* propertyName: '[' singleExpression ']'  */
#line 471 ".\\parser.y"
                               { Print("- R: '[' singleExpression ']' -> propertyName"); }
#line 3664 "parser.tab.c"
    break;

  case 215: /* propertyName: ENDL_BRACKET_OPEN singleExpression ']'  */
#line 472 ".\\parser.y"
                                             { Print("- R: ENDL_BRACKET_OPEN singleExpression ']' -> propertyName"); }
#line 3670 "parser.tab.c"
    break;

  case 216: /* identifier: ID  */
#line 476 ".\\parser.y"
         { Print("- R: ID -> identifier"); }
#line 3676 "parser.tab.c"
    break;

  case 217: /* identifier: ASYNC  */
#line 477 ".\\parser.y"
            { Print("- R: ASYNC -> identifier"); }
#line 3682 "parser.tab.c"
    break;

  case 218: /* identifier: AS  */
#line 478 ".\\parser.y"
         { Print("- R: AS -> identifier"); }
#line 3688 "parser.tab.c"
    break;

  case 219: /* identifier: FROM  */
#line 479 ".\\parser.y"
           { Print("- R: FROM -> identifier"); }
#line 3694 "parser.tab.c"
    break;

  case 220: /* identifier: YIELD  */
#line 480 ".\\parser.y"
            { Print("- R: YIELD -> identifier"); }
#line 3700 "parser.tab.c"
    break;

  case 221: /* identifier: OF  */
#line 481 ".\\parser.y"
         { Print("- R: OF -> identifier"); }
#line 3706 "parser.tab.c"
    break;

  case 222: /* identifier: ANY  */
#line 482 ".\\parser.y"
          { Print("- R: ANY -> identifier"); }
#line 3712 "parser.tab.c"
    break;

  case 223: /* identifier: NUMBER  */
#line 483 ".\\parser.y"
             { Print("- R: NUMBER -> identifier"); }
#line 3718 "parser.tab.c"
    break;

  case 224: /* identifier: BOOLEAN  */
#line 484 ".\\parser.y"
              { Print("- R: BOOLEAN -> identifier"); }
#line 3724 "parser.tab.c"
    break;

  case 225: /* identifier: STRING  */
#line 485 ".\\parser.y"
             { Print("- R: STRING -> identifier"); }
#line 3730 "parser.tab.c"
    break;

  case 226: /* identifier: UNIQUE  */
#line 486 ".\\parser.y"
             { Print("- R: UNIQUE -> identifier"); }
#line 3736 "parser.tab.c"
    break;

  case 227: /* identifier: SYMBOL  */
#line 487 ".\\parser.y"
             { Print("- R: SYMBOL -> identifier"); }
#line 3742 "parser.tab.c"
    break;

  case 228: /* identifier: NEVER  */
#line 488 ".\\parser.y"
            { Print("- R: NEVER -> identifier"); }
#line 3748 "parser.tab.c"
    break;

  case 229: /* identifier: UNDEFINED  */
#line 489 ".\\parser.y"
                { Print("- R: UNDEFINED -> identifier"); }
#line 3754 "parser.tab.c"
    break;

  case 230: /* identifier: OBJECT  */
#line 490 ".\\parser.y"
             { Print("- R: OBJECT -> identifier"); }
#line 3760 "parser.tab.c"
    break;

  case 231: /* identifier: KEYOF  */
#line 491 ".\\parser.y"
            { Print("- R: KEYOF -> identifier"); }
#line 3766 "parser.tab.c"
    break;

  case 232: /* identifier: NAMESPACE  */
#line 492 ".\\parser.y"
                { Print("- R: NAMESPACE -> identifier"); }
#line 3772 "parser.tab.c"
    break;

  case 233: /* identifier: ABSTRACT  */
#line 493 ".\\parser.y"
               { Print("- R: ABSTRACT -> identifier"); }
#line 3778 "parser.tab.c"
    break;

  case 234: /* identifier: REQUIRE  */
#line 494 ".\\parser.y"
              { Print("- R: REQUIRE -> identifier"); }
#line 3784 "parser.tab.c"
    break;


#line 3788 "parser.tab.c"

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

#line 497 ".\\parser.y"



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
