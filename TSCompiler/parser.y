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

    struct TSScriptNode* tsscript;
    struct TSElementListNode* tsscriptElementList;
    struct TSElementNode* tsscriptElement;

    struct StatementListNode* stmtList;
    struct StatementNode* stmt;

    struct ExpressionNode* exprStmt;

}

%token VAR LET CONST IF ELSE FUNCTION CLASS EXTENDS GET SET DO WHILE FOR RETURN SUPER THIS NEW
%token ASYNC AS FROM YIELD KEYOF CONSTRUCTOR NAMESPACE ABSTRACT REQUIRE

%token ANY NUMBER BOOLEAN STRING NEVER UNDEFINED UNIQUE SYMBOL OBJECT VOID UNKNOWN

%token STRING_LIT
%token INT_LIT
%token FLOAT_LIT NULL_KW TRUE_KW FALSE_KW 
%token <_id> ID

%nonassoc ENDL
%nonassoc TEMPLATE_LITERAL
%nonassoc OPERATOR_INCREMENT OPERATOR_DECREMENT ENDL_OPERATOR_INCREMENT ENDL_OPERATOR_DECREMENT

%precedence IF_ONLY_PREC
%left IF ELSE

%left ',' COMMA_OPERATOR COMMA_SEPARATOR

%right '=' OPERATOR_ASSIGN_PLUS OPERATOR_ASSIGN_MINUS OPERATOR_ASSIGN_MULTIPLY OPERATOR_ASSIGN_DIVIDE OPERATOR_ASSIGN_LOGICAL_AND OPERATOR_ASSIGN_LOGICAL_OR

%left '?' ':' // expr ? expr : expr
%left OPERATOR_LOGICAL_OR
%left OPERATOR_LOGICAL_AND
%left '|'
%left '^'
%left '&'
%left OPERATOR_EQUAL OPERATOR_NOT_EQUAL OPERATOR_STRICT_EQUAL OPERATOR_STRICT_NOT_EQUAL
%left  '>' '<' OPERATOR_GREATER_THAN_EQUAL OPERATOR_LESS_THAN_EQUAL INSTANCEOF IN

%left '+' '-'
%left '*' '/' '%'

%right '!' '~' UMINUS UPLUS PREF_INCREMENT PREF_DECREMENT VOID

%nonassoc POST_INCREMENT POST_DECREMENT

%right NEW

%left '.' '[' ']' ENDL_BRACKET_OPEN OPTIONAL_CHAINING_OPERATOR

%nonassoc '(' ')'

%start script

%type <tsscript>script
%type <tsscriptElementList>scriptElementList
%type <tsscriptElement>scriptElement

%type <stmtList>statementList
%type <stmt>statementListItem

%type <exprStmt>expressionStatement

%%

script
    : scriptElementList 
        { 
            if ( syntaxErrorCounter > 0 ) {
                PrintError("Found " + std::to_string(syntaxErrorCounter) + " syntax errors. Fix them and rerun.");
                exit(1);
            }
            Print("- R: scriptElementList -> script"); 
        
            $$ = root = createTSScriptNode($1);
        }
    ;

scriptElementList
    : scriptElement                     { Print("- R: scriptElement -> scriptElementList"); $$ = createTSElementListNode($1); }
    | scriptElementList scriptElement   { Print("- R: scriptElementList scriptElement -> scriptElementList"); $$ = createTSElementListNode($1); }

    | error
    | scriptElementList error
    ;

scriptElement
    : statementListItem     { Print("- R: statementListItem -> scriptElement"); }
    | functionDeclaration   { Print("- R: functionDeclaration -> scriptElement"); }
    | classDeclaration      { Print("- R: classDeclaration -> scriptElement"); }
    ;

statementList
    : statementListItem                 { Print("- R: statementListItem -> statementList"); }
    | statementList statementListItem   { Print("- R: statementList statementListItem -> statementList"); }
    ;

statementListItem
    : emptyStatement                { Print("- R: emptyStatement -> statementListItem"); }
    | expressionStatement           { Print("- R: expressionStatement -> statementListItem"); }
    | varStatement                  { Print("- R: varStatement -> statementListItem"); }
    | ifStatement                   { Print("- R: ifStatement -> statementListItem"); }
    | iterationStatement            { Print("- R: iterationStatement -> statementListItem"); }
    | returnStatement 
        { 
            if ( !isInFunctionBody ) { 
                yyerror("illegal return statement."); YYERROR;
            } 
            Print("- R: returnStatement -> statementListItem"); 
        }
    | blockStatement                { Print("- R: blockStatement -> statementListItem"); }
    ;

statementListItemWithoutEmptyStatement
    : expressionStatement           { Print("- R: expressionStatement -> statementListItemWithoutEmptyStatement"); }
    | varStatement                  { Print("- R: varStatement -> statementListItemWithoutEmptyStatement"); }
    | ifStatement                   { Print("- R: ifStatement -> statementListItemWithoutEmptyStatement"); }
    | iterationStatement            { Print("- R: iterationStatement -> statementListItemWithoutEmptyStatement"); }
    | returnStatement
        { 
            if ( !isInFunctionBody ) { 
                yyerror("illegal return statement."); YYERROR;
            } 
            Print("- R: returnStatement -> statementListItemWithoutEmptyStatement"); 
        }
    | blockStatement                { Print("- R: blockStatement -> statementListItemWithoutEmptyStatement"); }

    | error
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

blockStatement
    : '{' '}' { Print("- R: '{' '}' -> blockStatement"); }
    | '{' statementList '}' { Print("- R: '{' statementList '}' -> blockStatement"); }
    ;

initializer
    : '=' singleExpression { Print("- R: '=' singleExpression -> initializer"); }
    ;

    // ====== TYPES ======

type
    : primaryType { Print("- R: primaryType -> type"); }
    ;

primaryType
    : '(' type ')'                              { Print("- R: '(' type ')' -> primaryType"); }
    | predefinedType                            { Print("- R: predefinedType -> primaryType"); }
    | primaryType '[' ']'                       { Print("- R: primaryType '[' ']' -> primaryType"); }
    | '[' tupleTypeElements ']'                 { Print("- R: '[' tupleTypeElements ']' -> primaryType"); }
    | ENDL_BRACKET_OPEN tupleTypeElements ']'   { Print("- R: '[' tupleTypeElements ']' -> primaryType"); }
    ;

tupleTypeElements
    : /* empty */                   { Print("- R: #empty# -> tupleTypeElements"); }
    | type                          { Print("- R: type -> tupleTypeElements"); }
    | tupleTypeElements ',' type    { Print("- R: tupleTypeElements ',' type -> tupleTypeElements"); }
    ;

predefinedType
    : ANY           { Print("- R: ANY -> predefinedType"); }
    | NUMBER        { Print("- R: NUMBER -> predefinedType"); }
    | STRING        { Print("- R: STRING -> predefinedType"); }
    | BOOLEAN       { Print("- R: BOOLEAN -> predefinedType"); }
    | NEVER         { Print("- R: NEVER -> predefinedType"); }
    | UNKNOWN       { Print("- R: UNKNOWN -> predefinedType"); }
    | UNDEFINED     { Print("- R: UNDEFINED -> predefinedType"); }
    | VOID          { Print("- R: VOID -> predefinedType"); }
    | NULL_KW       { Print("- R: NULL_KW -> predefinedType"); }
    | TRUE_KW       { Print("- R: TRUE_WD -> predefinedType"); }
    | FALSE_KW      { Print("- R: FALSE_KW -> predefinedType"); }
    | simpleLiteral { Print("- R: simpleLiteral -> predefinedType"); }
    ;

typeAnnotationOpt
    : /* empty */       { Print("- R: # empty # -> typeAnnotationOpt"); }
    | typeAnnotation    { Print("- R: typeAnnotation -> typeAnnotationOpt"); }
    ;

typeAnnotation
    : ':' type { Print("- R: ':' type -> typeAnnotation"); }
    ;

simpleLiteral
    : STRING_LIT        { Print("- R: STRING_LIT -> simpleLiteral"); }
    | INT_LIT           { Print("- R: INT_LIT -> simpleLiteral"); }
    | FLOAT_LIT         { Print("- R: FLOAT_LIT -> simpleLiteral"); }
    | TEMPLATE_LITERAL  { Print("- R: TEMPLATE_LITERAL -> simpleLiteral"); }
    ;

// JavaScript supports arrasys like [,,1,2,,].
arrayLiteral
    : '[' elementList ']'               { Print("- R: [ elementList ']' -> arrayLiteral"); }
    | ENDL_BRACKET_OPEN elementList ']' { Print("- R: ENDL_BRACKET_OPEN elementList ']' -> arrayLiteral"); }
    ;

elementList
    : elementListItem { Print("- R: elementListItem -> elementList"); }
    | elementList ',' elementListItem %prec COMMA_SEPARATOR { Print("- R: elementList ',' elementListItem -> elementList"); }
    ;

elementListItem
    : /* empty */ { Print("- R: #empty# -> elementListItem"); }
    | singleExpression { Print("- R: singleExpression -> elementListItem"); }
    | singleExpression ',' { Print("- R: singleExpression ',' -> elementListItem"); }
    ;

    // ====== EXPRESSIONS ======

expressionStatement
    : singleExpression ';' { Print("- R: expressionList ';' -> expressionStatement"); }
    ;

singleExpressionOpt
    : /* empty */       { Print("- R: #empty# -> singleExpressionOpt"); }
    | singleExpression    { Print("- R: singleExpression -> singleExpressionOpt"); }
    ;

singleExpression
    : identifier    { Print("- R: identifier -> singleExpression"); }
    | simpleLiteral { Print("- R: simpleLiteral -> singleExpression"); }
    | THIS          { Print("- R: THIS -> singleExpression"); }
    | SUPER         { Print("- R: SUPER -> singleExpression"); }
    | TRUE_KW       { Print("- R: TRUE_LITERAL -> singleExpression"); }
    | FALSE_KW      { Print("- R: FALSE_LITERAL -> singleExpression"); }
    | NULL_KW       { Print("- R: NULL_LITERAL -> singleExpression"); }

    | '-' singleExpression %prec UMINUS { Print("- R: '-' singleExpression -> singleExpression"); }
    | '+' singleExpression %prec UPLUS  { Print("- R: '+' singleExpression -> singleExpression"); }

    | '!' singleExpression { Print("- R: '!' singleExpression -> singleExpression"); }

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
    | singleExpression '<' singleExpression { Print("- R: singleExpression '<' singleExpression -> singleExpression"); }
    | singleExpression '>' singleExpression { Print("- R: singleExpression '>' singleExpression -> singleExpression"); }

    | singleExpression OPERATOR_EQUAL singleExpression
        { Print("- R: singleExpression OPERATOR_EQUAL singleExpression -> singleExpression"); }

    | singleExpression OPERATOR_NOT_EQUAL singleExpression
        { Print("- R: singleExpression OPERATOR_NOT_EQUAL singleExpression -> singleExpression"); }

    | singleExpression OPERATOR_STRICT_EQUAL singleExpression
        { Print("- R: singleExpression OPERATOR_STRICT_EQUAL singleExpression -> singleExpression"); }

    | singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression
        { Print("- R: singleExpression OPERATOR_STRICT_NOT_EQUAL singleExpression -> singleExpression"); }

    | singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression
        { Print("- R: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression -> singleExpression"); }

    | singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression
        { Print("- R: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression -> singleExpression"); }

    | singleExpression '=' singleExpression
        { Print("- R: singleExpression '=' singleExpression -> singleExpression"); }

    | singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression
        { Print("- R: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression -> singleExpression"); }

    | singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression
        { Print("- R: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression -> singleExpression"); }

    | singleExpression OPERATOR_ASSIGN_PLUS singleExpression
        { Print("- R: singleExpression OPERATOR_ASSIGN_PLUS singleExpression -> singleExpression"); }

    | singleExpression OPERATOR_ASSIGN_MINUS singleExpression
        { Print("- R: singleExpression OPERATOR_ASSIGN_MINUS singleExpression -> singleExpression"); }

    | singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression
        { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression -> singleExpression"); }

    | singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression
        { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression -> singleExpression"); }

    | singleExpression OPERATOR_LOGICAL_OR singleExpression
        { Print("- R: singleExpression OPERATOR_LOGICAL_OR singleExpression -> singleExpression"); }

    | singleExpression OPERATOR_LOGICAL_AND singleExpression
        { Print("- R: singleExpression OPERATOR_LOGICAL_AND singleExpression -> singleExpression"); }

    | singleExpression INSTANCEOF singleExpression  { Print("- R: singleExpression INSTANCEOF singleExpression -> singleExpression"); }
    | singleExpression IN singleExpression          { Print("- R: singleExpression IN singleExpression -> singleExpression"); }

    | singleExpression TEMPLATE_LITERAL
        { Print("- R: singleExpression TEMPLATE_LITERAL -> singleExpression"); }

    | singleExpression '?' singleExpression ':' singleExpression 
        { Print("- R: singleExpression '?' singleExpression ':' singleExpression -> singleExpression"); }

    | singleExpression ',' singleExpression %prec COMMA_OPERATOR 
        { Print("- R: singleExpression ',' singleExpressionn -> singleExpression"); }

    | '(' singleExpression ')' { Print("- R: '(' expressionList ')' -> singleExpression"); }

    | singleExpression '(' ')' { Print("- R: singleExpression '(' ')' -> singleExpression"); }
    | singleExpression '(' singleExpression ')' { Print("- R: singleExpression '(' singleExpression ')' -> singleExpression"); }
    | singleExpression '(' singleExpression ',' ')' { Print("- R: singleExpression '(' singleExpression ',' ')' -> singleExpression"); }

    | singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression 
        { Print("- R: singleExpression OPTIONAL_CHAINING_OPERATOR singleExpression -> singleExpression"); }

    | singleExpression '.' identifier { Print("- R: singleExpression '.' identifier -> singleExpression"); }

    | arrayLiteral                                            { Print("- R: arrayLiteral -> singleExpression"); }
    | singleExpression '[' singleExpression ']'               { Print("- R: singleExpression '[' expressionList ']' -> singleExpression"); }
    | singleExpression ENDL_BRACKET_OPEN singleExpression ']' { Print("- R: singleExpression ENDL_BRACKET_OPEN expressionList ']' -> singleExpression"); }

    | NEW singleExpression { Print("- R: NEW singleExpression -> singleExpression"); }
    ;

    // ====== Variables ======

varStatement
    : varModifier varDeclarationList ';' { Print("- R: varModifier varDeclarationList ';' -> varStatement"); }
    | varModifier error ';'
    ;

varDeclarationList
    : varDeclaration                        { Print("- R: varDeclaration -> varDeclarationList"); }
    | varDeclarationList ',' varDeclaration { Print("- R: varDeclarationList ',' varDeclaration -> varDeclarationList"); }
    ;

varDeclaration
    : identifier typeAnnotationOpt                         { Print("- R: identifier typeAnnotationOpt -> varDeclaration"); }
    | identifier typeAnnotationOpt '=' singleExpression    { Print("- R: identifier typeAnnotationOpt '=' singleExpression -> varDeclaration"); }
    ;

varModifier
    : VAR   { Print("- R: VAR -> varModifier"); }
    | LET   { Print("- R: LET -> varModifier"); }
    | CONST { Print("- R: CONST -> varModifier"); }
    ;

    // ====== Conditions ====== 

ifStatement
    : IF '(' singleExpression ')' statementListItemWithoutEmptyStatement %prec IF_ONLY_PREC 
        { Print("- R: IF '(' expressionList ')' statementListItem -> ifStatement"); }

    | IF '(' singleExpression ')' statementListItemWithoutEmptyStatement ELSE statementListItem 
        { Print("- R: IF '(' expressionList ')' statementListItem ELSE statementListItem -> ifStatement"); }
    ;

    // ====== Iterations ======

iterationStatement
    : DO statementListItem WHILE '(' singleExpression ')' { doWhileASI(); } ';'                           
        { Print("- R: DO statementListItem WHILE '(' expressionList ')' ';' -> iterationStatement"); }

    | WHILE '(' singleExpression ')' statementListItem                                                             
        { Print("- R: WHILE '(' expressionList ')' statementListItem -> iterationStatement"); }

    | forHeader singleExpressionOpt ';' singleExpressionOpt ';' singleExpressionOpt ')' { isInForHeader = 0; } statementListItem                
        { Print("- R: FOR '(' singleExpressionOpt ';' singleExpressionOpt ';' singleExpressionOpt ')' statementListItem -> iterationStatement"); }

    | forHeader varModifier varDeclarationList ';' singleExpressionOpt ';' singleExpressionOpt ')' { isInForHeader = 0; } statementListItem   
        { Print("- R: FOR '(' varModifier varDeclarationList ';' singleExpressionOpt ';' singleExpressionOpt ')' statementListItem -> iterationStatement"); }

    | forHeader singleExpression IN singleExpression ')' { isInForHeader = 0; } statementListItem                                         
        { Print("- R: FOR '(' singleExpression IN singleExpression ')' statementListItem -> iterationStatement"); }

    | forHeader varModifier varDeclaration IN singleExpression ')' { isInForHeader = 0; } statementListItem                                 
        { Print("- R: FOR '(' varModifier varDeclaration IN expressionList ')' statementListItem -> iterationStatement"); }
    ;

forHeader
    :  FOR '(' { isInForHeader = 1; }
    ;

    // === Functions ===

returnStatement
    : RETURN ';'                    { Print("- R: RETURN ';' -> returnStatement"); }
    | RETURN singleExpression ';'   { Print("- R: RETURN singleExpression ';' -> returnStatement"); }
    ;

functionDeclaration
    : FUNCTION identifier callSignature functionBody { Print("- R: FUNCTION ID callSignature functionBody -> functionDeclaration"); }
    ;

functionBody
    : '{' '}'                                           { Print("- R: '{' '}' -> functionBody"); }
    | '{' { isInFunctionBody = 1; } statementList '}'   { isInFunctionBody = 0; Print("- R: '{' statementList '}' -> functionBody"); }
    ;

callSignature
    : '(' parameterList ')' typeAnnotationOpt  { Print("- R : '(' parameterList ')' typeAnnotation -> callSignature"); }
    ;

parameterList
    : /* empty */        { Print("- R: #empty# -> parameterList"); }
    | requiredParameterList { Print("- R: requiredParameterList -> parameterList"); }
    | requiredParameterList ',' { Print("- R: requiredParameterList ',' -> parameterList"); }
    ;

requiredParameterList
    : requiredParameter                             { Print("- R: requiredParameter -> requiredParameterList"); }
    | requiredParameterList ',' requiredParameter   { Print("- R: requiredParameterList ',' requiredParameter -> requiredParameterList"); }
    ;

requiredParameter
    : identifier typeAnnotationOpt { Print("- R: ID typeAnnotationOpt -> requiredParameter"); }
    ;

    // === Classes ===

classDeclaration
    : CLASS identifier classTail                { Print("- R: CLASS identifier classTail -> classDeclaration"); }
    | CLASS identifier classHeritage classTail  { Print("- R: CLASS identifier classHeritage classTail -> classDeclaration"); }
    ;

classHeritage
    : EXTENDS identifier { Print("- R: EXTENDS identifier -> classHeritage"); }
    ; 

classTail
    : '{' '}'                   { Print("- R: '{' '}' -> classTail"); }
    | '{' classElementList '}'  { Print("- R: '{' classElementList '}' -> classTail"); }
    ;

classElementList
    : classElement { Print("- R: classElement -> classElementList"); }
    | classElementList classElement { Print("- R: classElementList classElement -> classElementList"); }
    ;

classElement
    : CONSTRUCTOR constructorCallSignature functionBody { Print("- R: CONSTRUCTOR callSignature functionBody -> classElement"); }

    // PropertyDeclarationExpression 
    | propertyName typeAnnotationOpt ';'               { Print("- R: propertyName typeAnnotationOpt ';' -> classElement"); }
    | propertyName typeAnnotationOpt initializer ';'   { Print("- R: propertyName typeAnnotationOpt initializer ';' -> classElement"); }

    // MethodDeclarationExpression 
    | propertyName callSignature functionBody { Print("- R: propertyName callSignature functionBody -> classElement"); }

    // GetterSetterDeclarationExpression 
    | GET propertyName '(' ')' typeAnnotationOpt functionBody  { Print("- R: GET propertyName '(' ')' typeAnnotationOpt functionBody -> classElement"); }
    | SET propertyName callSignature functionBody           { Print("- R: SET propertyName callSignature functionBody -> classElement"); }
    ;

constructorCallSignature
    : '(' parameterList ')' { Print("- R: '(' parameterList ')' -> constructorCallSignature"); }
    ;

propertyName
    : identifier                            { Print("- R: identifier -> propertyName"); }
    ;

identifier
    : ID        { Print("- R: ID -> identifier"); }
    | ASYNC     { Print("- R: ASYNC -> identifier"); }
    | AS        { Print("- R: AS -> identifier"); }
    | FROM      { Print("- R: FROM -> identifier"); }
    | YIELD     { Print("- R: YIELD -> identifier"); }
    | ANY       { Print("- R: ANY -> identifier"); }
    | NUMBER    { Print("- R: NUMBER -> identifier"); }
    | BOOLEAN   { Print("- R: BOOLEAN -> identifier"); }
    | STRING    { Print("- R: STRING -> identifier"); }
    | UNIQUE    { Print("- R: UNIQUE -> identifier"); }
    | SYMBOL    { Print("- R: SYMBOL -> identifier"); }
    | NEVER     { Print("- R: NEVER -> identifier"); }
    | UNDEFINED { Print("- R: UNDEFINED -> identifier"); }
    | OBJECT    { Print("- R: OBJECT -> identifier"); }
    | KEYOF     { Print("- R: KEYOF -> identifier"); }
    | NAMESPACE { Print("- R: NAMESPACE -> identifier"); }
    | ABSTRACT  { Print("- R: ABSTRACT -> identifier"); }
    | REQUIRE   { Print("- R: REQUIRE -> identifier"); }
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
    if (yychar == '}' && !isASIActivated) {
        return simpleASI(yychar, yyn, yystate, yyssp);
    }
    if (yychar == YYEOF && !isASIActivated) {
        return simpleASI(yychar, yyn, yystate, yyssp);
    }
    isASIActivated = 0;

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


