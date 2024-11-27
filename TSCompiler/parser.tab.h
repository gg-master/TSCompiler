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
#line 34 "parser.y"

    int _integer;
    char* _string;
    char* _id;
    double _floatingPoint;

#line 169 "parser.tab.h"

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
