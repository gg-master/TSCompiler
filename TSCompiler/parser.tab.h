/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    SWITCH = 271,                  /* SWITCH  */
    CASE = 272,                    /* CASE  */
    DEFAULT = 273,                 /* DEFAULT  */
    RETURN = 274,                  /* RETURN  */
    SUPER = 275,                   /* SUPER  */
    THIS = 276,                    /* THIS  */
    NEW = 277,                     /* NEW  */
    ASYNC = 278,                   /* ASYNC  */
    AS = 279,                      /* AS  */
    FROM = 280,                    /* FROM  */
    YIELD = 281,                   /* YIELD  */
    KEYOF = 282,                   /* KEYOF  */
    CONSTRUCTOR = 283,             /* CONSTRUCTOR  */
    NAMESPACE = 284,               /* NAMESPACE  */
    ABSTRACT = 285,                /* ABSTRACT  */
    REQUIRE = 286,                 /* REQUIRE  */
    ANY = 287,                     /* ANY  */
    NUMBER = 288,                  /* NUMBER  */
    BOOLEAN = 289,                 /* BOOLEAN  */
    STRING = 290,                  /* STRING  */
    NEVER = 291,                   /* NEVER  */
    UNDEFINED = 292,               /* UNDEFINED  */
    UNIQUE = 293,                  /* UNIQUE  */
    SYMBOL = 294,                  /* SYMBOL  */
    OBJECT = 295,                  /* OBJECT  */
    VOID = 296,                    /* VOID  */
    UNKNOWN = 297,                 /* UNKNOWN  */
    STRING_LIT = 298,              /* STRING_LIT  */
    INT_LIT = 299,                 /* INT_LIT  */
    FLOAT_LIT = 300,               /* FLOAT_LIT  */
    NULL_KW = 301,                 /* NULL_KW  */
    TRUE_KW = 302,                 /* TRUE_KW  */
    FALSE_KW = 303,                /* FALSE_KW  */
    ID = 304,                      /* ID  */
    ENDL = 305,                    /* ENDL  */
    TEMPLATE_LITERAL = 306,        /* TEMPLATE_LITERAL  */
    OPERATOR_INCREMENT = 307,      /* OPERATOR_INCREMENT  */
    OPERATOR_DECREMENT = 308,      /* OPERATOR_DECREMENT  */
    ENDL_OPERATOR_INCREMENT = 309, /* ENDL_OPERATOR_INCREMENT  */
    ENDL_OPERATOR_DECREMENT = 310, /* ENDL_OPERATOR_DECREMENT  */
    IF_ONLY_PREC = 311,            /* IF_ONLY_PREC  */
    COMMA_OPERATOR = 312,          /* COMMA_OPERATOR  */
    COMMA_SEPARATOR = 313,         /* COMMA_SEPARATOR  */
    OPERATOR_ASSIGN_PLUS = 314,    /* OPERATOR_ASSIGN_PLUS  */
    OPERATOR_ASSIGN_MINUS = 315,   /* OPERATOR_ASSIGN_MINUS  */
    OPERATOR_ASSIGN_MULTIPLY = 316, /* OPERATOR_ASSIGN_MULTIPLY  */
    OPERATOR_ASSIGN_DIVIDE = 317,  /* OPERATOR_ASSIGN_DIVIDE  */
    OPERATOR_ASSIGN_LOGICAL_AND = 318, /* OPERATOR_ASSIGN_LOGICAL_AND  */
    OPERATOR_ASSIGN_LOGICAL_OR = 319, /* OPERATOR_ASSIGN_LOGICAL_OR  */
    OPERATOR_LOGICAL_OR = 320,     /* OPERATOR_LOGICAL_OR  */
    OPERATOR_LOGICAL_AND = 321,    /* OPERATOR_LOGICAL_AND  */
    OPERATOR_EQUAL = 322,          /* OPERATOR_EQUAL  */
    OPERATOR_NOT_EQUAL = 323,      /* OPERATOR_NOT_EQUAL  */
    OPERATOR_STRICT_EQUAL = 324,   /* OPERATOR_STRICT_EQUAL  */
    OPERATOR_STRICT_NOT_EQUAL = 325, /* OPERATOR_STRICT_NOT_EQUAL  */
    OPERATOR_GREATER_THAN_EQUAL = 326, /* OPERATOR_GREATER_THAN_EQUAL  */
    OPERATOR_LESS_THAN_EQUAL = 327, /* OPERATOR_LESS_THAN_EQUAL  */
    INSTANCEOF = 328,              /* INSTANCEOF  */
    IN = 329,                      /* IN  */
    UMINUS = 330,                  /* UMINUS  */
    UPLUS = 331,                   /* UPLUS  */
    PREF_INCREMENT = 332,          /* PREF_INCREMENT  */
    PREF_DECREMENT = 333,          /* PREF_DECREMENT  */
    POST_INCREMENT = 334,          /* POST_INCREMENT  */
    POST_DECREMENT = 335,          /* POST_DECREMENT  */
    ENDL_BRACKET_OPEN = 336,       /* ENDL_BRACKET_OPEN  */
    OPTIONAL_CHAINING_OPERATOR = 337 /* OPTIONAL_CHAINING_OPERATOR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 33 "parser.y"

    int _integer;
    char* _string;
    char* _id;
    double _floatingPoint;

#line 153 "parser.tab.h"

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


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
