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
#line 27 "parser.y"

    int _integer;
    char* _string;
    char* _id;
    double _floatingPoint;

#line 179 "parser.tab.h"

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
