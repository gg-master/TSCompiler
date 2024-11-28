%{
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
%}

/* added the yyfilter funtion call */
%skeleton "./bison.m4"

%locations 
%define parse.error verbose

%union {
    int _integer;
    char* _string;
    char* _id;
    double _floatingPoint;
}

%token VAR LET CONST IF ELSE FUNCTION CLASS EXTENDS GET SET DO WHILE FOR CONTINUE BREAK SWITCH CASE DEFAULT RETURN SUPER THIS NEW ELLIPSIS OF
%token ASYNC AS FROM YIELD KEYOF CONSTRUCTOR NAMESPACE ABSTRACT REQUIRE

%token ANY NUMBER BOOLEAN STRING NEVER UNDEFINED UNIQUE SYMBOL OBJECT VOID UNKNOWN

%token STRING_LIT INT_LIT FLOAT_LIT NULL_KW TRUE_KW FALSE_KW ID

%nonassoc ENDL
%nonassoc TEMPLATE_LITERAL
%nonassoc OPERATOR_INCREMENT OPERATOR_DECREMENT ENDL_OPERATOR_INCREMENT ENDL_OPERATOR_DECREMENT

%precedence IF_ONLY_PREC
%left IF ELSE

%left ','

%right '=' OPERATOR_ASSIGN_PLUS OPERATOR_ASSIGN_MINUS OPERATOR_ASSIGN_POWER OPERATOR_ASSIGN_MULTIPLY OPERATOR_ASSIGN_DIVIDE OPERATOR_ASSIGN_MOD OPERATOR_ASSIGN_SHIFT_LEFT OPERATOR_ASSIGN_SHIFT_RIGHT OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT OPERATOR_ASSIGN_BITWISE_AND OPERATOR_ASSIGN_BITWISE_XOR OPERATOR_ASSIGN_BITWISE_OR OPERATOR_ASSIGN_LOGICAL_AND OPERATOR_ASSIGN_LOGICAL_OR OPERATOR_ASSIGN_NULLISH_COALESCING

%left '?' ':' // expr ? expr : expr
%left OPERATOR_NULLISH_COALESCING
%left OPERATOR_LOGICAL_OR
%left OPERATOR_LOGICAL_AND
%left '|'
%left '^'
%left '&'
%left OPERATOR_EQUAL OPERATOR_NOT_EQUAL OPERATOR_STRICT_EQUAL OPERATOR_STRICT_NOT_EQUAL
%left  '>' '<' OPERATOR_GREATER_THAN_EQUAL OPERATOR_LESS_THAN_EQUAL INSTANCEOF IN
%left OPERATOR_SHIFT_LEFT OPERATOR_SHIFT_RIGHT OPERATOR_UNSIGNED_SHIFT_RIGHT

%left '+' '-'
%left '*' '/' '%'

%right OPERATOR_POWER
%right '!' '~' UMINUS UPLUS PREF_INCREMENT PREF_DECREMENT VOID

%nonassoc POST_INCREMENT POST_DECREMENT

%right NEW

%left '.' '[' ']' ENDL_BRACKET_OPEN OPTIONAL_CHAINING_OPERATOR

%nonassoc '(' ')'

%start script

%%

script
    : statementList 
        { 
            if ( syntaxErrorCounter > 0 ) {
                PrintError("Found " + std::to_string(syntaxErrorCounter) + " syntax errors. Fix them and rerun.");
                exit(1);
            }
            Print("- R: statementList -> script"); 
        }
    ;

statementList
    : statementListItem { Print("- R: statementListItem -> statementList"); }
    | statementList statementListItem { Print("- R: statementList statementListItem -> statementList"); }
    ;

statementListItem
    : emptyStatement                { Print("- R: emptyStatement -> statementListItem"); }
    | expressionStatement           { Print("- R: expressionStatement -> statementListItem"); }
    | varStatement                  { Print("- R: varStatement -> statementListItem"); }
    | ifStatement                   { Print("- R: ifStatement -> statementListItem"); }
    | switchStatement               { Print("- R: switchStatement -> statementListItem"); }
    | iterationStatement            { Print("- R: iterationStatement -> statementListItem"); }
    | continueStatement 
        {
            if ( !isInIterationBody ) { 
                yyerror("illegal continue statement."); YYERROR;
            } 
            Print("- R: continueStatement -> statementListItem");  
        }
    | breakStatement 
        {
            if ( !isInIterationBody ) { 
                yyerror("illegal break statement."); YYERROR;
            } 
            Print("- R: breakStatement -> statementListItem");
        }
    | returnStatement 
        { 
            if ( !isInFunctionBody ) { 
                yyerror("illegal return statement."); YYERROR;
            } 
            Print("- R: returnStatement -> statementListItem"); 
        }
    | labelledStatement             { Print("- R: labelledStatement -> statementListItem"); }
    | blockStatement                { Print("- R: blockStatement -> statementListItem"); }
    | functionDeclaration           { Print("- R: functionDeclaration -> statementListItem"); }
    | classDeclaration              { Print("- R: classDeclaration -> statementListItem"); }
    ;

statementListItemWithoutEmptyStatement
    : expressionStatement           { Print("- R: expressionStatement -> statementListItem"); }
    | varStatement                  { Print("- R: varStatement -> statementListItem"); }
    | ifStatement                   { Print("- R: ifStatement -> statementListItem"); }
    | switchStatement               { Print("- R: switchStatement -> statementListItem"); }
    | iterationStatement            { Print("- R: iterationStatement -> statementListItem"); }
    | continueStatement
        {
            if ( !isInIterationBody ) { 
                yyerror("illegal continue statement."); YYERROR;
            } 
            Print("- R: continueStatement -> statementListItem");
        }
    | breakStatement
        {
            if ( !isInIterationBody ) { 
                yyerror("illegal break statement."); YYERROR;
            } 
            Print("- R: breakStatement -> statementListItem");
        }
    | returnStatement
        { 
            if ( !isInFunctionBody ) { 
                yyerror("illegal return statement."); YYERROR;
            } 
            Print("- R: returnStatement -> statementListItem"); 
        }
    | labelledStatement             { Print("- R: labelledStatement -> statementListItem"); }
    | blockStatement                { Print("- R: blockStatement -> statementListItem"); }
    | functionDeclaration           { Print("- R: functionDeclaration -> statementListItem"); }
    | classDeclaration              { Print("- R: classDeclaration -> statementListItem"); }
    ;

emptyStatement
    : ';' 
        { 
            if ( isASIActivated ) {
                std::string text(yytext_ptr, yyleng);
                yyerror(("syntax error on token: " + text).c_str()); YYERROR;
            }
            Print("- R: ';' -> emptyStatement"); 
        }
    ;

initializer
    : '=' singleExpression { Print("- R: '=' singleExpression -> initializer"); }
    ;

    /* ====== TYPES ====== */

type
    : unionOrIntersectionOrPrimaryType { Print("- R: unionOrIntersectionOrPrimaryType -> type"); }
    | '|' unionOrIntersectionOrPrimaryType { Print("- R: '|' unionOrIntersectionOrPrimaryType -> type"); }
    | '&' unionOrIntersectionOrPrimaryType { Print("- R: '&' unionOrIntersectionOrPrimaryType -> type"); }
    ;

unionOrIntersectionOrPrimaryType
    : unionOrIntersectionOrPrimaryType '|' unionOrIntersectionOrPrimaryType { Print("- R: unionOrIntersectionOrPrimaryType '|' unionOrIntersectionOrPrimaryType -> unionOrIntersectionOrPrimaryType"); }
    | unionOrIntersectionOrPrimaryType '&' unionOrIntersectionOrPrimaryType { Print("- R: unionOrIntersectionOrPrimaryType '&' unionOrIntersectionOrPrimaryType -> unionOrIntersectionOrPrimaryType"); }
    | primaryType { Print("- R: primaryType -> argument"); }
    ;

primaryType
    : '(' type ')' { Print("- R: '(' type ')' -> primaryType"); }
    | predefinedType { Print("- R: predefinedType -> primaryType"); }
    | primaryType '[' ']' { Print("- R: primaryType '[' ']' -> primaryType"); }
    | primaryType '[' primaryType ']' { Print("- R: primaryType '[' primaryType ']' -> primaryType"); }
    | '[' tupleTypeElements ']' { Print("- R: '[' tupleTypeElements ']' -> primaryType"); }
    | ENDL_BRACKET_OPEN tupleTypeElements ']' { Print("- R: '[' tupleTypeElements ']' -> primaryType"); }
    ;

tupleTypeElements
    : /* empty */ { Print("- R: #empty# -> tupleTypeElements"); }
    | type { Print("- R: type -> tupleTypeElements"); }
    | tupleTypeElements ',' type { Print("- R: tupleTypeElements ',' type -> tupleTypeElements"); }
    ;

predefinedType
    : ANY { Print("- R: ANY -> predefinedType"); }
    | NUMBER { Print("- R: NUMBER -> predefinedType"); }
    | STRING { Print("- R: STRING -> predefinedType"); }
    | BOOLEAN { Print("- R: BOOLEAN -> predefinedType"); }
    | NEVER { Print("- R: NEVER -> predefinedType"); }
    | UNKNOWN { Print("- R: UNKNOWN -> predefinedType"); }
    | UNDEFINED { Print("- R: UNDEFINED -> predefinedType"); }
    | VOID { Print("- R: VOID -> predefinedType"); }
    | NULL_KW { Print("- R: NULL_KW -> predefinedType"); }
    | TRUE_KW { Print("- R: TRUE_WD -> predefinedType"); }
    | FALSE_KW { Print("- R: FALSE_KW -> predefinedType"); }
    | simpleLiteral { Print("- R: simpleLiteral -> predefinedType"); }
    ;

typeAnnotation
    : ':' type { Print("- R: ':' type -> typeAnnotation"); }
    ;

simpleLiteral
    : STRING_LIT { Print("- R: STRING_LIT -> simpleLiteral"); }
    | INT_LIT { Print("- R: INT_LIT -> simpleLiteral"); }
    | FLOAT_LIT { Print("- R: FLOAT_LIT -> simpleLiteral"); }
    | TEMPLATE_LITERAL { Print("- R: TEMPLATE_LITERAL -> simpleLiteral"); }
    ;

// JavaScript supports arrasys like [,,1,2,,].
arrayLiteral
    : '[' elementList ']' { Print("- R: [ elementList ']' -> arrayLiteral"); }
    | ENDL_BRACKET_OPEN elementList ']' { Print("- R: ENDL_BRACKET_OPEN elementList ']' -> arrayLiteral"); }
    ;

elementList
    : /* empty */ { Print("- R: #empty# -> elementList"); }
    | arrayElement { Print("- R: arrayElement -> elementList"); }
    | elementList ',' elementList { Print("- R: elementList ',' elementList -> elementList"); }
    ;

arrayElement
    : singleExpression { Print("- R: singleExpression -> arrayElement"); }
    | ELLIPSIS singleExpression { Print("- R: ELLIPSIS singleExpression -> arrayElement"); }
    ;

    /* ====== EXPRESSIONS ====== */

expressionStatement
    : expressionList ';' { Print("- R: expressionList ';' -> expressionStatement"); }
    ;

expressionListOpt
    : /* empty */ { Print("- R: #empty# -> expressionListOpt"); }
    | expressionList { Print("- R: expressionList -> expressionListOpt"); }
    ;

expressionList
    : singleExpression { Print("- R: singleExpression -> expressionList"); }
    | expressionList ',' singleExpression { Print("- R: expressionList ',' singleExpression -> expressionList"); }
    ;

singleExpression
    : identifier { Print("- R: identifier -> singleExpression"); }
    | simpleLiteral { Print("- R: simpleLiteral -> singleExpression"); }
    | THIS { Print("- R: THIS -> singleExpression"); }
    | SUPER { Print("- R: SUPER -> singleExpression"); }
    | TRUE_KW { Print("- R: TRUE_LITERAL -> singleExpression"); }
    | FALSE_KW { Print("- R: FALSE_LITERAL -> singleExpression"); }
    | NULL_KW { Print("- R: NULL_LITERAL -> singleExpression"); }
    | '-' singleExpression %prec UMINUS { Print("- R: '-' singleExpression -> singleExpression"); }
    | '+' singleExpression %prec UPLUS { Print("- R: '+' singleExpression -> singleExpression"); }
    | '!' singleExpression { Print("- R: '!' singleExpression -> singleExpression"); }
    | '~' singleExpression { Print("- R: '~' singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_INCREMENT %prec POST_INCREMENT { Print("- R: singleExpression OPERATOR_INCREMENT -> singleExpression"); }
    | singleExpression OPERATOR_DECREMENT %prec POST_DECREMENT { Print("- R: singleExpression OPERATOR_DECREMENT -> singleExpression"); }
    | ENDL_OPERATOR_INCREMENT singleExpression %prec PREF_INCREMENT { Print("- R: ENDL_OPERATOR_INCREMENT singleExpression -> singleExpression"); }
    | ENDL_OPERATOR_DECREMENT singleExpression %prec PREF_DECREMENT { Print("- R: ENDL_OPERATOR_DECREMENT singleExpression -> singleExpression"); }
    | OPERATOR_INCREMENT singleExpression %prec PREF_INCREMENT { Print("- R: OPERATOR_INCREMENT singleExpression -> singleExpression"); }
    | OPERATOR_DECREMENT singleExpression %prec PREF_DECREMENT { Print("- R: OPERATOR_DECREMENT singleExpression -> singleExpression"); }
    | singleExpression '+' singleExpression { Print("- R: singleExpression '+' singleExpression -> singleExpression"); }
    | singleExpression '-' singleExpression { Print("- R: singleExpression '-' singleExpression -> singleExpression"); }
    | singleExpression '*' singleExpression { Print("- R: singleExpression '*' singleExpression -> singleExpression"); }
    | singleExpression '/' singleExpression { Print("- R: singleExpression '/' singleExpression -> singleExpression"); }
    | singleExpression '%' singleExpression { Print("- R: singleExpression '%' singleExpression -> singleExpression"); }
    | singleExpression '<' singleExpression { Print("- R: singleExpression '<' singleExpression -> singleExpression"); }
    | singleExpression '>' singleExpression { Print("- R: singleExpression '>' singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_POWER singleExpression { Print("- R: singleExpression OPERATOR_POWER singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_EQUAL singleExpression { Print("- R: singleExpression OPERATOR_EQUAL singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_NOT_EQUAL singleExpression { Print("- R: singleExpression OPERATOR_NOT_EQUAL singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_STRICT_EQUAL singleExpression { Print("- R: singleExpression OPERATOR_STRICT_EQUAL singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression { Print("- R: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression { Print("- R: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression { Print("- R: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression -> singleExpression"); }
    | singleExpression '=' singleExpression { Print("- R: singleExpression '=' singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression { Print("- R: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression { Print("- R: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_ASSIGN_MOD singleExpression { Print("- R: singleExpression OPERATOR_ASSIGN_MOD singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_ASSIGN_PLUS singleExpression { Print("- R: singleExpression OPERATOR_ASSIGN_PLUS singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_ASSIGN_MINUS singleExpression { Print("- R: singleExpression OPERATOR_ASSIGN_MINUS singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_ASSIGN_SHIFT_LEFT singleExpression { Print("- R: singleExpression OPERATOR_ASSIGN_SHIFT_LEFT singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_ASSIGN_SHIFT_RIGHT singleExpression { Print("- R: singleExpression OPERATOR_ASSIGN_SHIFT_RIGHT singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_ASSIGN_BITWISE_AND singleExpression { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_AND singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_ASSIGN_BITWISE_XOR singleExpression { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_XOR singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_ASSIGN_BITWISE_OR singleExpression { Print("- R: singleExpression OPERATOR_ASSIGN_BITWISE_OR singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_ASSIGN_POWER singleExpression { Print("- R: singleExpression OPERATOR_ASSIGN_POWER singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_ASSIGN_NULLISH_COALESCING singleExpression { Print("- R: singleExpression OPERATOR_ASSIGN_NULLISH_COALESCING singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT singleExpression { Print("- R: singleExpression OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_LOGICAL_OR singleExpression { Print("- R: singleExpression OPERATOR_LOGICAL_OR singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_LOGICAL_AND singleExpression { Print("- R: singleExpression OPERATOR_LOGICAL_AND singleExpression -> singleExpression"); }
    | singleExpression '|' singleExpression { Print("- R: singleExpression '|' singleExpression -> singleExpression"); }
    | singleExpression '^' singleExpression { Print("- R: singleExpression '^' singleExpression -> singleExpression"); }
    | singleExpression '&' singleExpression { Print("- R: singleExpression '&' singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_SHIFT_LEFT singleExpression { Print("- R: singleExpression OPERATOR_SHIFT_LEFT singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_SHIFT_RIGHT singleExpression { Print("- R: singleExpression OPERATOR_SHIFT_RIGHT singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_UNSIGNED_SHIFT_RIGHT singleExpression { Print("- R: singleExpression OPERATOR_UNSIGNED_SHIFT_RIGHT singleExpression -> singleExpression"); }
    | singleExpression OPERATOR_NULLISH_COALESCING singleExpression { Print("- R: singleExpression OPERATOR_NULLISH_COALESCING singleExpression -> singleExpression"); }

    | singleExpression INSTANCEOF singleExpression { Print("- R: singleExpression INSTANCEOF singleExpression -> singleExpression"); }
    | singleExpression IN singleExpression { Print("- R: singleExpression IN singleExpression -> singleExpression"); }

    | singleExpression TEMPLATE_LITERAL { Print("- R: singleExpression TEMPLATE_LITERAL -> singleExpression"); }
    | singleExpression '?' singleExpression ':' singleExpression { Print("- R: singleExpression '?' singleExpression ':' singleExpression -> singleExpression"); }

    | '(' expressionList ')' { Print("- R: '(' expressionList ')' -> singleExpression"); }

    | singleExpression arguments { Print("- R: singleExpression arguments -> singleExpression"); }
    
    | singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression { Print("- R: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression -> singleExpression"); }
    | singleExpression '.' identifier { Print("- R: singleExpression '.' identifier -> singleExpression"); }

    | arrayLiteral { Print("- R: arrayLiteral -> singleExpression"); }
    | singleExpression '[' expressionList ']' { Print("- R: singleExpression '[' expressionList ']' -> singleExpression"); }
    | singleExpression ENDL_BRACKET_OPEN expressionList ']' { Print("- R: singleExpression ENDL_BRACKET_OPEN expressionList ']' -> singleExpression"); }

    | NEW singleExpression { Print("- R: NEW singleExpression -> singleExpression"); }
    ;

arguments
    : '(' ')' { Print("- R: '(' ')' -> arguments"); }
    | '(' argumentList ')' { Print("- R: '(' argumentList ')' -> arguments"); }
    | '(' argumentList ',' ')' { Print("- R: '(' argumentList ',' ') -> arguments"); }
    ;

argumentList
    : argument { Print("- R: argument -> argumentList"); }
    | argumentList ',' arguments { Print("- R: argumentList ',' arguments -> argumentList"); }
    ;

argument
    : singleExpression { Print("- R: singleExpression -> argument"); }
    | ELLIPSIS singleExpression { Print("- R: ELLIPSIS singleExpression -> argument"); }
    ;

    /* ====== varStatement ====== */

varStatement
    : varModifier varDeclarationList ';' { Print("- R: varModifier varDeclarationList ';' -> varStatement"); }
    ;

varDeclarationList
    : varDeclaration { Print("- R: varDeclaration -> argument"); }
    | varDeclarationList ',' varDeclaration { Print("- R: varDeclarationList ',' varDeclaration -> varDeclarationList"); }
    ;

varDeclaration
    : identifier { Print("- R: identifier -> varDeclaration"); }
    | identifier typeAnnotation { Print("- R: identifier typeAnnotation -> varDeclaration"); }
    | identifier '=' singleExpression { Print("- R: identifier '=' singleExpression -> varDeclaration"); }
    | identifier typeAnnotation '=' singleExpression { Print("- R: identifier typeAnnotation '=' singleExpression -> varDeclaration"); }
    ;

varModifier
    : VAR { Print("- R: VAR -> varModifier"); }
    | LET { Print("- R: LET -> varModifier"); }
    | CONST { Print("- R: CONST -> varModifier"); }
    ;

    /* ====== ifStatement ====== */

ifStatement
    : IF '(' expressionList ')' statementListItemWithoutEmptyStatement %prec IF_ONLY_PREC { Print("- R: IF '(' expressionList ')' statementListItem -> ifStatement"); }
    | IF '(' expressionList ')' statementListItemWithoutEmptyStatement ELSE statementListItem { Print("- R: IF '(' expressionList ')' statementListItem ELSE statementListItem -> ifStatement"); }
    ;

iterationStatement
    : DO { isInIterationBody = 1; } statementListItem WHILE '(' expressionList ')' { doWhileASI(); } ';'                           { isInIterationBody = 0; Print("- R: DO statementListItem WHILE '(' expressionList ')' ';' -> iterationStatement"); }
    | WHILE '(' expressionList ')' { isInIterationBody = 1; } statementListItem                                                             { isInIterationBody = 0; Print("- R: WHILE '(' expressionList ')' statementListItem -> iterationStatement"); }
    | forHeader expressionListOpt ';' expressionListOpt ';' expressionListOpt ')' { isInForHeader = 0; isInIterationBody = 1; } statementListItem                { isInIterationBody = 0; Print("- R: FOR '(' expressionListOpt ';' expressionListOpt ';' expressionListOpt ')' statementListItem -> iterationStatement"); }
    | forHeader varModifier varDeclarationList ';' expressionListOpt ';' expressionListOpt ')' { isInForHeader = 0; isInIterationBody = 1; } statementListItem   { isInIterationBody = 0; Print("- R: FOR '(' varModifier varDeclarationList ';' expressionListOpt ';' expressionListOpt ')' statementListItem -> iterationStatement"); }
    | forHeader singleExpression IN singleExpression ')' { isInForHeader = 0; isInIterationBody = 1; } statementListItem                                         { isInIterationBody = 0; Print("- R: FOR '(' singleExpression IN singleExpression ')' statementListItem -> iterationStatement"); }
    | forHeader varModifier varDeclaration IN expressionList ')' { isInForHeader = 0; isInIterationBody = 1; } statementListItem                                 { isInIterationBody = 0; Print("- R: FOR '(' varModifier varDeclaration IN expressionList ')' statementListItem -> iterationStatement"); }
    ;

forHeader
    :  FOR '(' { isInForHeader = 1; }
    ;

continueStatement
    : CONTINUE ';' { Print("- R: CONTINUE ';' -> returnStatement"); }
    | CONTINUE identifier ';' { Print("- R: CONTINUE identifier ';' -> returnStatement"); }
    ;

breakStatement
    : BREAK  ';' { Print("- R: BREAK ';' -> returnStatement"); }
    | BREAK identifier ';' { Print("- R: BREAK identifier ';' -> returnStatement"); }
    ;

returnStatement
    : RETURN ';' { Print("- R: RETURN ';' -> returnStatement"); }
    | RETURN singleExpression ';' { Print("- R: RETURN singleExpression ';' -> returnStatement"); }
    ;

labelledStatement
    : identifier ':' statementListItem { Print("- R: identifier ':' statementListItem -> labelledStatement"); }
    ;

blockStatement
    : '{' '}' { Print("- R: '{' '}' -> blockStatement"); }
    | '{' statementList '}' { Print("- R: '{' statementList '}' -> blockStatement"); }
    ;

switchStatement
    : SWITCH '(' expressionList ')' '{' '}' { Print("- R: SWITCH '(' expressionList ')' '{' '}' -> switchStatement"); }
    | SWITCH '(' expressionList ')' '{' caseClauseList '}' { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList '}' -> switchStatement"); }
    | SWITCH '(' expressionList ')' '{' caseClauseList defaultClause '}' { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause '}' -> switchStatement"); }
    | SWITCH '(' expressionList ')' '{' caseClauseList defaultClause caseClauseList '}' { Print("- R: SWITCH '(' expressionList ')' '{' caseClauseList defaultClause caseClauseList '}' -> switchStatement"); }
    ;

caseClauseList
    : caseClause { Print("- R: caseClause -> caseClauseList"); }
    | caseClauseList caseClause { Print("- R: caseClauseList caseClause -> caseClauseList"); }
    ;

caseClause
    : CASE expressionList ':' { Print("- R: CASE expressionList ':' -> caseClause"); }
    | CASE expressionList ':' statementList { Print("- R: CASE expressionList ':' statementList -> caseClause"); }
    ;

defaultClause
    : DEFAULT ':' { Print("- R: DEFAULT ':' -> defaultClause"); }
    | DEFAULT ':' statementList { Print("- R: DEFAULT ':' statementList -> defaultClause"); }
    ;

    /* === Functions === */

functionDeclaration
    : FUNCTION identifier callSignature functionBody { Print("- R: FUNCTION ID callSignature functionBody -> functionDeclaration"); }
    ;

functionBody
    : '{' '}' { Print("- R: '{' '}' -> functionBody"); }
    | '{' { isInFunctionBody = 1; } statementList '}' { isInFunctionBody = 0; Print("- R: '{' statementList '}' -> functionBody"); }
    ;

callSignature
    : '(' ')' { Print("- R: '(' ')' -> callSignature"); }
    | '(' ')' typeAnnotation { Print("- R: '(' ')' typeAnnotation -> callSignature"); }
    | '(' restParameter ')' { Print("- R: '(' restParameter ')' -> callSignature"); }
    | '(' restParameter ')' typeAnnotation { Print("- R: '(' restParameter ')' typeAnnotation -> callSignature"); }
    | '(' parameterList ')' { Print("- R: '(' parameterList ')' -> callSignature"); }
    | '(' parameterList ')' typeAnnotation { Print("- R: '(' parameterList ')' typeAnnotation -> callSignature"); }
    | '(' parameterList ',' restParameter ')' { Print("- R: '(' parameterList ',' restParameter ')' -> callSignature"); }
    | '(' parameterList ',' restParameter ')' typeAnnotation { Print("- R: '(' parameterList ',' restParameter ')' typeAnnotation -> callSignature"); }
    | '(' parameterList ',' ')' { Print("- R: '(' parameterList ',' ')' -> callSignature"); }
    | '(' parameterList ',' ')' typeAnnotation { Print("- R: '(' parameterList ',' ')' typeAnnotation -> callSignature"); }
    ;

parameterList
    : parameter { Print("- R: parameter -> parameterList"); }
    | parameterList ',' parameter { Print("- R: parameterList ',' parameter -> parameterList"); }
    ;

parameter
    : requiredParameter { Print("- R: requiredParameter -> parameter"); }
    | optionalParameter { Print("- R: optionalParameter -> parameter"); }
    ;

requiredParameter
    : identifier { Print("- R: ID -> requiredParameter"); }
    | identifier typeAnnotation { Print("- R: ID typeAnnotation -> requiredParameter"); }
    ;

optionalParameter
    : identifier '?' { Print("- R: ID '?' -> optionalParameter"); }
    | identifier '?' typeAnnotation { Print("- R: ID '?' typeAnnotation -> optionalParameter"); }
    | identifier initializer { Print("- R: ID initializer -> optionalParameter"); }
    | identifier typeAnnotation initializer { Print("- R: ID typeAnnotation initializer -> optionalParameter"); }
    ;

restParameter
    : ELLIPSIS singleExpression { Print("- R: ELLIPSIS singleExpression -> restParameter"); }
    | ELLIPSIS singleExpression typeAnnotation { Print("- R: ELLIPSIS singleExpression typeAnnotation -> restParameter"); }
    ;

    /* === Classes === */

classDeclaration
    : CLASS identifier classTail { Print("- R: CLASS identifier classTail -> classDeclaration"); }
    | CLASS identifier classHeritage classTail { Print("- R: CLASS identifier classHeritage classTail -> classDeclaration"); }
    ;

classHeritage
    : EXTENDS identifier { Print("- R: EXTENDS identifier -> classHeritage"); }
    ; 

classTail
    : '{' '}' { Print("- R: '{' '}' -> classTail"); }
    | '{' classElementList '}' { Print("- R: '{' classElementList '}' -> classTail"); }
    ;

classElementList
    : classElement { Print("- R: classElement -> classElementList"); }
    | classElementList classElement { Print("- R: classElementList classElement -> classElementList"); }
    ;

classElement
    : CONSTRUCTOR constructorCallSignature functionBody { Print("- R: CONSTRUCTOR callSignature functionBody -> classElement"); }

    /* PropertyDeclarationExpression */
    | propertyName ';' { Print("- R: propertyName ';' -> classElement"); }
    | propertyName typeAnnotation ';' { Print("- R: propertyName typeAnnotation ';' -> classElement"); }
    | propertyName initializer ';' { Print("- R: propertyName initializer ';' -> classElement"); }
    | propertyName typeAnnotation initializer ';' { Print("- R: propertyName typeAnnotation initializer ';' -> classElement"); }

    /* MethodDeclarationExpression */
    | propertyName callSignature functionBody { Print("- R: propertyName callSignature functionBody -> classElement"); }

    /* GetterSetterDeclarationExpression */
    | GET propertyName '(' ')' functionBody { Print("- R: GET propertyName '(' ')' functionBody -> classElement"); }
    | GET propertyName '(' ')' typeAnnotation functionBody { Print("- R: GET propertyName '(' ')' typeAnnotation functionBody -> classElement"); }
    | SET propertyName callSignature functionBody { Print("- R: SET propertyName callSignature functionBody -> classElement"); }
    ;

constructorCallSignature
    : '(' ')' { Print("- R: '(' ')' -> constructorCallSignature"); }
    | '(' restParameter ')' { Print("- R: '(' restParameter ')' -> constructorCallSignature"); }
    | '(' parameterList ')' { Print("- R: '(' parameterList ')' -> constructorCallSignature"); }
    | '(' parameterList ',' restParameter ')' { Print("- R: '(' parameterList ',' restParameter ')' -> constructorCallSignature"); }
    | '(' parameterList ',' ')' { Print("- R: '(' parameterList ',' ')' -> constructorCallSignature"); }
    ;

propertyName
    : identifier { Print("- R: identifier -> propertyName"); }
    | simpleLiteral { Print("- R: STRING_LIT -> propertyName"); }
    | '[' simpleLiteral ']' { Print("- R: '[' simpleLiteral ']' -> propertyName"); }
    | ENDL_BRACKET_OPEN simpleLiteral ']' { Print("- R: ENDL_BRACKET_OPEN simpleLiteral ']' -> propertyName"); }
    ;

identifier
    : ID { Print("- R: ID -> identifier"); }
    | ASYNC { Print("- R: ASYNC -> identifier"); }
    | AS { Print("- R: AS -> identifier"); }
    | FROM { Print("- R: FROM -> identifier"); }
    | YIELD { Print("- R: YIELD -> identifier"); }
    | ANY { Print("- R: ANY -> identifier"); }
    | NUMBER { Print("- R: NUMBER -> identifier"); }
    | BOOLEAN { Print("- R: BOOLEAN -> identifier"); }
    | STRING { Print("- R: STRING -> identifier"); }
    | UNIQUE { Print("- R: UNIQUE -> identifier"); }
    | SYMBOL { Print("- R: SYMBOL -> identifier"); }
    | NEVER { Print("- R: NEVER -> identifier"); }
    | UNDEFINED { Print("- R: UNDEFINED -> identifier"); }
    | OBJECT { Print("- R: OBJECT -> identifier"); }
    | KEYOF { Print("- R: KEYOF -> identifier"); }
    | NAMESPACE { Print("- R: NAMESPACE -> identifier"); }
    | ABSTRACT { Print("- R: ABSTRACT -> identifier"); }
    | REQUIRE { Print("- R: REQUIRE -> identifier"); }
    ;

%%


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


