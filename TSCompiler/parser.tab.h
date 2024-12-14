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
    ENDL_BRACKET_OPEN = 332,       /* ENDL_BRACKET_OPEN  */
    OPTIONAL_CHAINING_OPERATOR = 333 /* OPTIONAL_CHAINING_OPERATOR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 36 "parser.y"

    int integerValue;
    char* stringValue;
    char* identName;
    double floatingPointValue;

    struct TSScriptNode* tsscriptNode;
    struct TSElementListNode* tsscriptElementListNode;
    struct TSElementNode* tsscriptElementNode;

    struct StatementListNode* stmtListNode;
    struct StatementNode* stmtNode;

    struct ExpressionListNode* exprListNode;
    struct ExpressionNode* exprNode;

    struct TypeNode* typeNode;
    struct TupleTypeNode* tupleTypeNode;

    enum class VarModifierType varModifierType;

    struct VarDeclarationNode* varDeclNode;
    struct VarDeclarationListNode* varDeclListNode;

#line 167 "parser.tab.h"

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
