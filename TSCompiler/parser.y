%{
#include <cstdio>
#include <iostream>

#include "Utils/utils.h"
#include "Tree/ts_script.h"

int debug = 1;
extern FILE* yyin;
extern TSScriptNode* root;

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
    int integerValue;
    char* stringValue;
    char* identName;
    double floatingPointValue;

    struct TSScriptNode* tsscriptNode;
    struct TSElementListNode* tsscriptElementListNode;
    struct TSElementNode* tsscriptElementNode;

    struct ClassDeclarationNode* classDeclNode;
    struct ClassElementListNode* classElementListNode;
    struct ClassElementNode* classElementNode;

    struct RequiredParameterListNode* requiredParameterListNode;
    struct RequiredParameterNode* requiredParameterNode;
    struct CallSignatureNode* callSignatureNode;
    struct FunctionDeclarationNode* funcDeclarationNode;

    struct StatementListNode* stmtListNode;
    struct StatementNode* stmtNode;

    struct ExpressionListNode* exprListNode;
    struct ExpressionNode* exprNode;

    struct TypeNode* typeNode;

    enum class VarModifierType varModifierType;

    struct VarDeclarationNode* varDeclNode;
    struct VarDeclarationListNode* varDeclListNode;
}

%token ENDL VAR LET CONST IF ELSE FUNCTION CLASS EXTENDS GET SET DO WHILE FOR RETURN SUPER THIS NEW
%token ASYNC AS FROM YIELD KEYOF CONSTRUCTOR NAMESPACE ABSTRACT REQUIRE

%token ANY NUMBER BOOLEAN STRING NEVER UNDEFINED UNIQUE SYMBOL OBJECT VOID

%token NULL_KW TRUE_KW FALSE_KW 
%token <stringValue> TEMPLATE_LIT
%token <stringValue> STRING_LIT
%token <integerValue> INT_LIT
%token <floatingPointValue> FLOAT_LIT 
%token <identName> ID

%nonassoc TEMPLATE_LIT
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
%left OPERATOR_EQUAL OPERATOR_NOT_EQUAL
%left  '>' '<' OPERATOR_GREATER_THAN_EQUAL OPERATOR_LESS_THAN_EQUAL INSTANCEOF IN

%left '+' '-'
%left '*' '/' '%'

%right '!' '~' UMINUS UPLUS PREF_INCREMENT PREF_DECREMENT VOID

%nonassoc POST_INCREMENT POST_DECREMENT

%right NEW

%left '.' '[' ']' ENDL_BRACKET_OPEN

%nonassoc '(' ')'
  
%start script

%type <classDeclNode>classDeclaration
%type <classElementListNode>classTail
%type <classElementListNode>classElementList
%type <classElementNode>classElement

%type <requiredParameterListNode>requiredParameterList
%type <requiredParameterNode>requiredParameter
%type <requiredParameterListNode>parameterList

%type <funcDeclarationNode>functionDeclaration

%type <stmtListNode>functionBody
%type <stmtListNode>statementList

%type <stmtNode>statementListItem
%type <stmtNode>statementListItemWithoutEmptyStatement

%type <stmtNode>expressionStatement
%type <stmtNode>varStatement
%type <stmtNode>emptyStatement
%type <stmtNode>returnStatement
%type <stmtNode>blockStatement
%type <stmtNode>ifStatement
%type <stmtNode>iterationStatement

%type <exprNode>singleExpression
%type <exprNode>singleExpressionOpt
%type <exprNode>elementListItem
%type <exprNode>arrayLiteral

%type <exprListNode>elementList

%type <typeNode>type
%type <typeNode>predefinedType
%type <typeNode>typeAnnotation
%type <typeNode>typeAnnotationOpt

%type <varModifierType>varModifier
%type <varDeclNode>varDeclaration
%type <varDeclListNode>varDeclarationList

%type <identName>identifier
%type <identName>propertyName
%type <identName>classHeritage

%%

script
    : scriptElementList 
        { 
            if ( syntaxErrorCounter > 0 ) {
                PrintError("Found " + std::to_string(syntaxErrorCounter) + " syntax errors. Fix them and rerun.");
                exit(1);
            }
            Print("- R: scriptElementList -> script"); 
        }
    ;

scriptElementList
    : scriptElement
        { Print("- R: scriptElement -> scriptElementList"); }
    | scriptElementList scriptElement
        { Print("- R: scriptElementList scriptElement -> scriptElementList"); }
    ;

scriptElement
    : statementListItem     { Print("- R: statementListItem -> scriptElement"); root -> add($1); }
    | functionDeclaration   { Print("- R: functionDeclaration -> scriptElement"); root -> add($1); }
    | classDeclaration      { Print("- R: classDeclaration -> scriptElement"); root -> add($1); }
    | error
    ;

statementList
    : statementListItem                 { Print("- R: statementListItem -> statementList"); $$ = new StatementListNode($1); }
    | statementList statementListItem   { Print("- R: statementList statementListItem -> statementList"); $$ -> add($2); }
    ;

statementListItem
    : emptyStatement        { Print("- R: emptyStatement -> statementListItem"); }
    | expressionStatement   { Print("- R: expressionStatement -> statementListItem"); }
    | varStatement          { Print("- R: varStatement -> statementListItem"); }
    | ifStatement           { Print("- R: ifStatement -> statementListItem"); }
    | iterationStatement    { Print("- R: iterationStatement -> statementListItem"); }
    | returnStatement 
        { 
            if ( !isInFunctionBody ) { 
                yyerror("illegal return statement."); YYERROR;
            } 
            Print("- R: returnStatement -> statementListItem");
        }
    | blockStatement        { Print("- R: blockStatement -> statementListItem"); }
    ;

statementListItemWithoutEmptyStatement
    : expressionStatement   { Print("- R: expressionStatement -> statementListItemWithoutEmptyStatement"); }
    | varStatement          { Print("- R: varStatement -> statementListItemWithoutEmptyStatement"); }
    | ifStatement           { Print("- R: ifStatement -> statementListItemWithoutEmptyStatement"); }
    | iterationStatement    { Print("- R: iterationStatement -> statementListItemWithoutEmptyStatement"); }
    | returnStatement
        { 
            if ( !isInFunctionBody ) { 
                yyerror("illegal return statement."); YYERROR;
            } 
            Print("- R: returnStatement -> statementListItemWithoutEmptyStatement");
        }
    | blockStatement        { Print("- R: blockStatement -> statementListItemWithoutEmptyStatement"); }

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
            $$ = StatementNode::fromEmptyStmt();
        }
    ;

blockStatement
    : '{' '}'               { Print("- R: '{' '}' -> blockStatement"); $$ = StatementNode::fromBlockStmt(nullptr); }
    | '{' statementList '}' { Print("- R: '{' statementList '}' -> blockStatement"); $$ = StatementNode::fromBlockStmt($2); }
    ;

    // ====== TYPES ======

type
    : predefinedType { Print("- R: predefinedType -> type"); $$ = $1; }
    | type '[' ']'   { Print("- R: type '[' ']' -> type"); $$ -> arrayArity++; }
    ;

predefinedType
    : NUMBER        { Print("- R: NUMBER -> predefinedType"); $$ = new TypeNode(TypeNode::Type::_NUMBER); }
    | STRING        { Print("- R: STRING -> predefinedType"); $$ = new TypeNode(TypeNode::Type::_STRING); }
    | BOOLEAN       { Print("- R: BOOLEAN -> predefinedType"); $$ = new TypeNode(TypeNode::Type::_BOOLEAN); }
    | UNDEFINED     { Print("- R: UNDEFINED -> predefinedType"); $$ = new TypeNode(TypeNode::Type::_UNDEFINED); }
    | VOID          { Print("- R: VOID -> predefinedType"); $$ = new TypeNode(TypeNode::Type::_VOID); }
    | NULL_KW       { Print("- R: NULL_KW -> predefinedType"); $$ = new TypeNode(TypeNode::Type::_NULL); }
    | ID            { Print("- R: ID -> predefinedType"); $$ = new TypeNode($1); }
    ;

typeAnnotationOpt
    : /* empty */       { Print("- R: # empty # -> typeAnnotationOpt"); $$ = new TypeNode(TypeNode::Type::_ANY);; }
    | typeAnnotation    { Print("- R: typeAnnotation -> typeAnnotationOpt"); $$ = $1; }
    ;

typeAnnotation
    : ':' type { Print("- R: ':' type -> typeAnnotation"); $$ = $2; }
    ;

// JavaScript supports arrasys like [,,1,2,,].
arrayLiteral
    : '[' elementList ']'               
        { Print("- R: '[' elementList ']' -> arrayLiteral"); $$ = ExpressionNode::fromArrayLiteral($2); }
    | ENDL_BRACKET_OPEN elementList ']' 
        { Print("- R: ENDL_BRACKET_OPEN elementList ']' -> arrayLiteral"); $$ = ExpressionNode::fromArrayLiteral($2); }
    ;

elementList
    : elementListItem 
        { Print("- R: elementListItem -> elementList"); $$ = ExpressionListNode::fromExpression($1); }
    | elementList ',' elementListItem %prec COMMA_SEPARATOR 
        { Print("- R: elementList ',' elementListItem -> elementList"); $$ -> merge(ExpressionListNode::fromExpression($3)); }
    ;

elementListItem
    : /* empty */ { Print("- R: #empty# -> elementListItem"); $$ = ExpressionNode::fromEmptyArrayElementExpr(); }
    | singleExpression { Print("- R: singleExpression -> elementListItem"); $$ = $1; }
    | singleExpression ',' 
        { 
            Print("- R: singleExpression ',' -> elementListItem");
            ExpressionNode *node = ExpressionNode::fromEmptyArrayElementExpr();
            $$ = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_COMMA, $1, node);
        }
    ;

    // ====== EXPRESSIONS ======

expressionStatement
    : singleExpression ';' { Print("- R: expressionList ';' -> expressionStatement"); $$ = StatementNode::fromExprStmt($1); }
    ;

singleExpressionOpt
    : /* empty */       { Print("- R: #empty# -> singleExpressionOpt"); $$ = nullptr; }
    | singleExpression  { Print("- R: singleExpression -> singleExpressionOpt"); $$ = $1; }
    ;

singleExpression
    : identifier    { Print("- R: identifier -> singleExpression"); $$ = ExpressionNode::fromId($1); }
    | THIS          { Print("- R: THIS -> singleExpression"); $$ = ExpressionNode::fromThis(); }
    | TRUE_KW       { Print("- R: TRUE_LITERAL -> singleExpression"); $$ = ExpressionNode::fromTrueLit(); }
    | FALSE_KW      { Print("- R: FALSE_LITERAL -> singleExpression"); $$ = ExpressionNode::fromFalseLit(); }
    | NULL_KW       { Print("- R: NULL_LITERAL -> singleExpression"); $$ = ExpressionNode::fromNullLit(); }
    | UNDEFINED     { Print("- R: NULL_LITERAL -> singleExpression"); $$ = ExpressionNode::fromUndefinedLit(); }

    | STRING_LIT    { Print("- R: STRING_LIT -> singleExpression"); $$ = ExpressionNode::fromStringLit($1); }
    | TEMPLATE_LIT  { Print("- R: TEMPLATE_LIT -> singleExpression"); $$ = ExpressionNode::fromStringLit($1); }
    | INT_LIT       { Print("- R: INT_LIT -> singleExpression"); $$ = ExpressionNode::fromIntLit($1); }
    | FLOAT_LIT     { Print("- R: FLOAT_LIT -> singleExpression"); $$ = ExpressionNode::fromFloatLit($1); }

    | '-' singleExpression %prec UMINUS 
        { Print("- R: '-' singleExpression -> singleExpression"); $$ = ExpressionNode::fromUnaryExpr(ExpressionNode::Type::_UMINUS, $2); }
    | '+' singleExpression %prec UPLUS  
        { Print("- R: '+' singleExpression -> singleExpression"); $$ = ExpressionNode::fromUnaryExpr(ExpressionNode::Type::_UPLUS, $2); }

    | '!' singleExpression 
        { Print("- R: '!' singleExpression -> singleExpression"); $$ = ExpressionNode::fromUnaryExpr(ExpressionNode::Type::_NOT, $2); }

    | singleExpression OPERATOR_INCREMENT %prec POST_INCREMENT
        { Print("- R: singleExpression OPERATOR_INCREMENT -> singleExpression"); $$ = ExpressionNode::fromUnaryExpr(ExpressionNode::Type::_POST_INCREMENT, $1); }
    | singleExpression OPERATOR_DECREMENT %prec POST_DECREMENT
        { Print("- R: singleExpression OPERATOR_DECREMENT -> singleExpression"); $$ = ExpressionNode::fromUnaryExpr(ExpressionNode::Type::_POST_DECREMENT, $1); }

    | ENDL_OPERATOR_INCREMENT singleExpression %prec PREF_INCREMENT
        { Print("- R: ENDL_OPERATOR_INCREMENT singleExpression -> singleExpression"); $$ = ExpressionNode::fromUnaryExpr(ExpressionNode::Type::_PREF_INCREMENT, $2); }
    | ENDL_OPERATOR_DECREMENT singleExpression %prec PREF_DECREMENT
        { Print("- R: ENDL_OPERATOR_DECREMENT singleExpression -> singleExpression"); $$ = ExpressionNode::fromUnaryExpr(ExpressionNode::Type::_PREF_DECREMENT, $2); }
    | OPERATOR_INCREMENT singleExpression %prec PREF_INCREMENT
        { Print("- R: OPERATOR_INCREMENT singleExpression -> singleExpression"); $$ = ExpressionNode::fromUnaryExpr(ExpressionNode::Type::_PREF_INCREMENT, $2); }
    | OPERATOR_DECREMENT singleExpression %prec PREF_DECREMENT
        { Print("- R: OPERATOR_DECREMENT singleExpression -> singleExpression"); $$ = ExpressionNode::fromUnaryExpr(ExpressionNode::Type::_PREF_DECREMENT, $2); }

    | singleExpression '+' singleExpression
        { Print("- R: singleExpression '+' singleExpression -> singleExpression"); $$ = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_PLUS, $1, $3); }
    | singleExpression '-' singleExpression
        { Print("- R: singleExpression '-' singleExpression -> singleExpression"); $$ = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_MINUS, $1, $3); }
    | singleExpression '*' singleExpression
        { Print("- R: singleExpression '*' singleExpression -> singleExpression"); $$ = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_MUL, $1, $3); }
    | singleExpression '/' singleExpression
        { Print("- R: singleExpression '/' singleExpression -> singleExpression"); $$ = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_DIV, $1, $3); }
    | singleExpression '<' singleExpression
        { Print("- R: singleExpression '<' singleExpression -> singleExpression"); $$ = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_LESS, $1, $3); }
    | singleExpression '>' singleExpression
        { Print("- R: singleExpression '>' singleExpression -> singleExpression"); $$ = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_GREAT, $1, $3); }

    | singleExpression OPERATOR_EQUAL singleExpression
        { Print("- R: singleExpression OPERATOR_EQUAL singleExpression -> singleExpression"); $$ = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_EQUAL, $1, $3); }
    | singleExpression OPERATOR_NOT_EQUAL singleExpression
        { Print("- R: singleExpression OPERATOR_NOT_EQUAL singleExpression -> singleExpression"); $$ = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_NOT_EQUAL, $1, $3); }
    | singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression
        { Print("- R: singleExpression OPERATOR_LESS_THAN_EQUAL singleExpression -> singleExpression"); $$ = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_LESS_EQUAL, $1, $3); }
    | singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression
        { Print("- R: singleExpression OPERATOR_GREATER_THAN_EQUAL singleExpression -> singleExpression"); $$ = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_GREAT_EQUAL, $1, $3); }

    | singleExpression '=' singleExpression
        { Print("- R: singleExpression '=' singleExpression -> singleExpression"); $$ = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_ASSIGN, $1, $3); }
    | singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression
        { Print("- R: singleExpression OPERATOR_ASSIGN_MULTIPLY singleExpression -> singleExpression"); $$ = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_ASSIGN_MUL, $1, $3); }
    | singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression
        { Print("- R: singleExpression OPERATOR_ASSIGN_DIVIDE singleExpression -> singleExpression"); $$ = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_ASSIGN_DIV, $1, $3); }
    | singleExpression OPERATOR_ASSIGN_PLUS singleExpression
        { Print("- R: singleExpression OPERATOR_ASSIGN_PLUS singleExpression -> singleExpression"); $$ = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_ASSIGN_PLUS, $1, $3); }
    | singleExpression OPERATOR_ASSIGN_MINUS singleExpression
        { Print("- R: singleExpression OPERATOR_ASSIGN_MINUS singleExpression -> singleExpression"); $$ = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_ASSIGN_MINUS, $1, $3); }
    | singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression
        { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_AND singleExpression -> singleExpression"); $$ = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_ASSIGN_LOGICAL_AND, $1, $3); }
    | singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression
        { Print("- R: singleExpression OPERATOR_ASSIGN_LOGICAL_OR singleExpression -> singleExpression"); $$ = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_ASSIGN_LOGICAL_OR, $1, $3); }

    | singleExpression OPERATOR_LOGICAL_OR singleExpression
        { Print("- R: singleExpression OPERATOR_LOGICAL_OR singleExpression -> singleExpression"); $$ = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_LOGICAL_OR, $1, $3); }
    | singleExpression OPERATOR_LOGICAL_AND singleExpression
        { Print("- R: singleExpression OPERATOR_LOGICAL_AND singleExpression -> singleExpression"); $$ = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_LOGICAL_AND, $1, $3); }

    | singleExpression INSTANCEOF singleExpression  
        { Print("- R: singleExpression INSTANCEOF singleExpression -> singleExpression"); $$ = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_INSTANCEOF, $1, $3); }
    | singleExpression IN singleExpression          
        { Print("- R: singleExpression IN singleExpression -> singleExpression"); $$ = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_IN, $1, $3); }

    | singleExpression '?' singleExpression ':' singleExpression 
        { Print("- R: singleExpression '?' singleExpression ':' singleExpression -> singleExpression"); $$ = ExpressionNode::fromTernaryExpr($1, $3, $5); }

    | singleExpression ',' singleExpression %prec COMMA_OPERATOR
        { Print("- R: singleExpression ',' singleExpressionn -> singleExpression"); $$ = ExpressionNode::fromBinaryExpr(ExpressionNode::Type::_COMMA, $1, $3); }

    | '(' singleExpression ')' 
        { Print("- R: '(' singleExpression ')' -> singleExpression"); $$ = $2; }

    | SUPER
        { Print("- R: SUPER -> singleExpression"); $$ = ExpressionNode::fromSuper(); }
    | SUPER '(' ')'
        { Print("- R: SUPER '(' ')' -> singleExpression"); $$ = ExpressionNode::fromSuperCall(ExpressionListNode::makeEmpty()); }
    | SUPER '(' singleExpression ')'
        { Print("- R: SUPER '(' singleExpression ')' -> singleExpression"); $$ = ExpressionNode::fromSuperCall(ExpressionListNode::fromExpression($3)); }
    | SUPER '(' singleExpression ',' ')'
        { Print("- R: SUPER '(' singleExpression ',' ')' -> singleExpression"); $$ = ExpressionNode::fromSuperCall(ExpressionListNode::fromExpression($3)); } 

    // XXX: dissallow syntax exrp '(' optParams ')' cause this grammar dont have func types
    | identifier '(' ')' 
        { Print("- R: identifier '(' ')' -> singleExpression"); $$ = ExpressionNode::fromFuncCall($1, ExpressionListNode::makeEmpty()); }
    | identifier '(' singleExpression ')' 
        { Print("- R: identifier '(' singleExpression ')' -> singleExpression"); $$ = ExpressionNode::fromFuncCall($1, ExpressionListNode::fromExpression($3)); }

    | identifier '(' singleExpression ',' ')' 
        { Print("- R: identifier '(' singleExpression ',' ')' -> singleExpression"); $$ = ExpressionNode::fromFuncCall($1, ExpressionListNode::fromExpression($3)); }

    // XXX: dissallow syntax expr.exrp with '(' optParams ')' cause this grammar dont have func types
    | singleExpression '.' identifier 
        { Print("- R: singleExpression '.' identifier -> singleExpression"); $$ = ExpressionNode::fromFieldAccess($1, $3); }
    | singleExpression '.' identifier '(' ')' 
        { Print("- R: singleExpression '.' identifier '(' ')' -> singleExpression"); $$ = ExpressionNode::fromMethodCall($1, $3, ExpressionListNode::makeEmpty()); }
    | singleExpression '.' identifier '(' singleExpression ')' 
        { Print("- R: singleExpression '.' identifier '(' singleExpression ')' -> singleExpression"); $$ = ExpressionNode::fromMethodCall($1, $3, ExpressionListNode::fromExpression($5)); }
    | singleExpression '.' identifier '(' singleExpression ',' ')' 
        { Print("- R: singleExpression '.' identifier '(' singleExpression ',' ')' -> singleExpression"); $$ = ExpressionNode::fromMethodCall($1, $3, ExpressionListNode::fromExpression($5)); }

    | arrayLiteral { Print("- R: arrayLiteral -> singleExpression"); $$ = $1; }

    | singleExpression '[' singleExpression ']'
        { Print("- R: singleExpression '[' singleExpression ']' -> singleExpression"); $$ = ExpressionNode::fromArrayAccessExpr($1, $3); }
    | singleExpression ENDL_BRACKET_OPEN singleExpression ']' 
        { Print("- R: singleExpression ENDL_BRACKET_OPEN singleExpression ']' -> singleExpression"); $$ = ExpressionNode::fromArrayAccessExpr($1, $3); }

    | NEW identifier
        { Print("- R: NEW singleExpression -> singleExpression"); $$ = ExpressionNode::fromNew($2, ExpressionListNode::makeEmpty()); }
    | NEW identifier '(' ')'
        { Print("- R: NEW singleExpression '(' ')' -> singleExpression"); $$ = ExpressionNode::fromNew($2, ExpressionListNode::makeEmpty()); }
    | NEW identifier '(' singleExpression ')'
        { Print("- R: NEW singleExpression '(' singleExpression ')' -> singleExpression"); $$ = ExpressionNode::fromNew($2, ExpressionListNode::fromExpression($4)); }
    ;

    // ====== Variables ======

varStatement
    : varModifier varDeclarationList ';' { Print("- R: varModifier varDeclarationList ';' -> varStatement"); $$ = StatementNode::fromVarStmt($1, $2); }
    | varModifier error ';'
    ;

varDeclarationList
    : varDeclaration                       
        { Print("- R: varDeclaration -> varDeclarationList"); $$ = new VarDeclarationListNode($1); }
    | varDeclarationList ',' varDeclaration 
        { Print("- R: varDeclarationList ',' varDeclaration -> varDeclarationList"); $$ -> add($3); }
    ;

varDeclaration
    : identifier typeAnnotationOpt                         
        { Print("- R: identifier typeAnnotationOpt -> varDeclaration"); $$ = new VarDeclarationNode($1, $2, nullptr); }
    | identifier typeAnnotationOpt '=' singleExpression    
        { Print("- R: identifier typeAnnotationOpt '=' singleExpression -> varDeclaration"); $$ = new VarDeclarationNode($1, $2, $4); }
    ;

varModifier
    : VAR   { Print("- R: VAR -> varModifier"); $$ = VarModifierType::_VAR; }
    | LET   { Print("- R: LET -> varModifier"); $$ = VarModifierType::_LET; }
    | CONST { Print("- R: CONST -> varModifier"); $$ = VarModifierType::_CONST; }
    ;

    // ====== Conditions ====== 

ifStatement
    : IF '(' singleExpression ')' statementListItemWithoutEmptyStatement %prec IF_ONLY_PREC 
        { 
            Print("- R: IF '(' expressionList ')' statementListItem -> ifStatement");
            $$ = StatementNode::fromIfElseStmt($3, $5, nullptr);
        }

    | IF '(' singleExpression ')' statementListItemWithoutEmptyStatement ELSE statementListItem 
        { 
            Print("- R: IF '(' expressionList ')' statementListItem ELSE statementListItem -> ifStatement");
            $$ = StatementNode::fromIfElseStmt($3, $5, $7);
        }
    ;

    // ====== Iterations ======

iterationStatement
    : DO statementListItem WHILE '(' singleExpression ')' { doWhileASI(); } ';'                           
        { 
            Print("- R: DO statementListItem WHILE '(' expressionList ')' ';' -> iterationStatement");
            $$ = StatementNode::fromDoWhileStmt($2, $5);
        }

    | WHILE '(' singleExpression ')' statementListItem                                                             
        { 
            Print("- R: WHILE '(' expressionList ')' statementListItem -> iterationStatement");
            $$ = StatementNode::fromWhileStmt($3, $5);
        }

    | forHeader singleExpressionOpt ';' singleExpressionOpt ';' singleExpressionOpt ')' { isInForHeader = 0; } statementListItem                
        { 
            Print("- R: FOR '(' singleExpressionOpt ';' singleExpressionOpt ';' singleExpressionOpt ')' statementListItem -> iterationStatement");
            $$ = StatementNode::fromClassicForStmt($2, $4, $6, $9);
        }

    | forHeader varModifier varDeclarationList ';' singleExpressionOpt ';' singleExpressionOpt ')' { isInForHeader = 0; } statementListItem   
        {
            Print("- R: FOR '(' varModifier varDeclarationList ';' singleExpressionOpt ';' singleExpressionOpt ')' statementListItem -> iterationStatement");
            $$ = StatementNode::fromClassicForWithVarDeclStmt($2, $3, $5, $7, $10);
        }

    | forHeader singleExpression IN singleExpression ')' { isInForHeader = 0; } statementListItem                                         
        {
            Print("- R: FOR '(' singleExpression IN singleExpression ')' statementListItem -> iterationStatement");
            $$ = StatementNode::fromForExprInExprStmt($2, $4, $7);
        }

    | forHeader varModifier varDeclaration IN singleExpression ')' { isInForHeader = 0; } statementListItem                                 
        {
            Print("- R: FOR '(' varModifier varDeclaration IN expressionList ')' statementListItem -> iterationStatement");
            $$ = StatementNode::fromForVarDeclInExprStmt($2, $3, $5, $8);
        }
    ;

forHeader
    :  FOR '(' { isInForHeader = 1; }
    ;

    // === Functions ===

returnStatement
    : RETURN ';'                    { Print("- R: RETURN ';' -> returnStatement"); $$ = StatementNode::fromReturnStmt(nullptr); }
    | RETURN singleExpression ';'   { Print("- R: RETURN singleExpression ';' -> returnStatement"); $$ = StatementNode::fromReturnStmt($2); }
    ;

functionDeclaration
    : FUNCTION identifier '(' parameterList ')' typeAnnotationOpt functionBody 
        {
            Print("- R: FUNCTION ID '(' parameterList ')' typeAnnotation functionBody -> functionDeclaration");
            $$ = new FunctionDeclarationNode($2, $4, $6, $7);
        }
    ;

functionBody
    : '{' '}' { Print("- R: '{' '}' -> functionBody"); $$ = StatementListNode::makeEmpty(); }
    | '{' { isInFunctionBody = 1; } statementList '}'   
        { 
            isInFunctionBody = 0; 
            Print("- R: '{' statementList '}' -> functionBody");
            $$ = $3;
        }
    ;

parameterList
    : /* empty */               { Print("- R: #empty# -> parameterList"); $$ = RequiredParameterListNode::makeEmpty(); }
    | requiredParameterList     { Print("- R: requiredParameterList -> parameterList"); $$ = $1; }
    | requiredParameterList ',' { Print("- R: requiredParameterList ',' -> parameterList"); $$ = $1; }
    ;

requiredParameterList
    : requiredParameter                             
        {
            Print("- R: requiredParameter -> requiredParameterList");
            $$ = new RequiredParameterListNode($1);
        }
    | requiredParameterList ',' requiredParameter   
        {
            Print("- R: requiredParameterList ',' requiredParameter -> requiredParameterList");
            $$ -> add($3);
        }
    ;

requiredParameter
    : identifier typeAnnotationOpt 
        { 
            Print("- R: ID typeAnnotationOpt -> requiredParameter");
            $$ = new RequiredParameterNode($1, $2);
        }
    ;

    // === Classes ===

classDeclaration
    : CLASS identifier classTail                
        {
            Print("- R: CLASS identifier classTail -> classDeclaration");
            $$ = new ClassDeclarationNode($2, $3);
        }
    | CLASS identifier classHeritage classTail  
        {
            Print("- R: CLASS identifier classHeritage classTail -> classDeclaration");
            $$ = new ClassDeclarationNode($2, $3, $4);
        }
    ;

classHeritage
    : EXTENDS identifier { Print("- R: EXTENDS identifier -> classHeritage"); $$ = $2; }
    ; 

classTail
    : '{' '}'                   { Print("- R: '{' '}' -> classTail"); $$ = ClassElementListNode::makeEmpty(); }
    | '{' classElementList '}'  { Print("- R: '{' classElementList '}' -> classTail"); $$ = $2; }
    ;

classElementList
    : classElement                  { Print("- R: classElement -> classElementList"); $$ = new ClassElementListNode($1); }
    | classElementList classElement { Print("- R: classElementList classElement -> classElementList"); $$ ->add($2); }
    ;

classElement
    : CONSTRUCTOR '(' parameterList ')' functionBody 
        {
            Print("- R: CONSTRUCTOR '(' parameterList ')' functionBody -> classElement");
            $$ = new ClassElementNode($3, $5);
        }

    // PropertyDeclarationExpression 
    | propertyName typeAnnotationOpt ';'
        {
            Print("- R: propertyName typeAnnotationOpt ';' -> classElement");
            $$ = new ClassElementNode($1, $2, nullptr);
        }
    | propertyName typeAnnotationOpt '=' singleExpression ';' 
        {
            Print("- R: propertyName typeAnnotationOpt '=' singleExpression ';' -> classElement");
            $$ = new ClassElementNode($1, $2, $4);
        }

    // MethodDeclarationExpression 
    | propertyName '(' parameterList ')' typeAnnotationOpt functionBody
        {
            Print("- R: propertyName '(' parameterList ')' typeAnnotationOpt functionBody -> classElement");
            $$ = new ClassElementNode($1, $3, $5, $6);
        }

    // GetterSetterDeclarationExpression 
    | GET propertyName '(' ')' typeAnnotationOpt functionBody
        {
            Print("- R: GET propertyName '(' ')' typeAnnotationOpt functionBody -> classElement");
            $$ = new ClassElementNode($2, nullptr, $5, $6);
        }
    | SET propertyName '(' parameterList ')' functionBody
        {
            Print("- R: SET propertyName callSignature functionBody -> classElement");
            $$ = new ClassElementNode($2, $4, nullptr, $6);
        }
    ;

propertyName
    : identifier { Print("- R: identifier -> propertyName"); }
    ;

identifier
    : ID        { Print("- R: ID -> identifier"); $$ = $1; }
    | ASYNC     { Print("- R: ASYNC -> identifier"); $$ = _strdup("async"); }
    | AS        { Print("- R: AS -> identifier"); $$ = _strdup("as"); }
    | FROM      { Print("- R: FROM -> identifier"); $$ = _strdup("from"); }
    | YIELD     { Print("- R: YIELD -> identifier"); $$ = _strdup("yield"); }
    | ANY       { Print("- R: ANY -> identifier"); $$ = _strdup("any"); }
    | NUMBER    { Print("- R: NUMBER -> identifier"); $$ = _strdup("number"); }
    | BOOLEAN   { Print("- R: BOOLEAN -> identifier"); $$ = _strdup("boolean"); }
    | STRING    { Print("- R: STRING -> identifier"); $$ = _strdup("string"); }
    | UNIQUE    { Print("- R: UNIQUE -> identifier"); $$ = _strdup("unique"); }
    | SYMBOL    { Print("- R: SYMBOL -> identifier"); $$ = _strdup("symbol"); }
    | NEVER     { Print("- R: NEVER -> identifier"); $$ = _strdup("never"); }
    | OBJECT    { Print("- R: OBJECT -> identifier"); $$ = _strdup("object"); }
    | KEYOF     { Print("- R: KEYOF -> identifier"); $$ = _strdup("keyof"); }
    | NAMESPACE { Print("- R: NAMESPACE -> identifier"); $$ = _strdup("namespace"); }
    | ABSTRACT  { Print("- R: ABSTRACT -> identifier"); $$ = _strdup("abstract"); }
    | REQUIRE   { Print("- R: REQUIRE -> identifier"); $$ = _strdup("require"); }
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


