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
#line 33 "parser.y"

    int _integer;
    char* _string;
    char* _id;
    double _floatingPoint;

#line 150 "parser.tab.h"

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
