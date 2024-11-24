%error-verbose

%token VAR LET CONST IF ELSE FUNCTION CLASS EXTENDS STATIC GET SET DO WHILE FOR CONTINUE BREAK SWITCH CASE DEFAULT RETURN SUPER THIS NEW ELLIPSIS OF ARROW_FUNCTION 
%token PUBLIC PRIVATE PROTECTED
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

%left '?' ':' COND // expr ? expr : expr
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
%right '!' '~' UMINUS UPLUS PREF_INCREMENT PREF_DECREMENT VOID DELETE TYPEOF

%nonassoc POST_INCREMENT POST_DECREMENT

%right NEW

%left '.' '[' ']' ENDL_BRACKET_OPEN FUNC_CALL OPTIONAL_CHAINING_OPERATOR MEMBER_ACCESS

%nonassoc '(' ')'

%start script

%%

script
    : statementList
    ;

statementList
    : statementListItem
    | statementList statementListItem
    ;

endlListOpt
    : /* empty */
    | endlList
    ;

endlList
    : ENDL
    | endlList ENDL
    ;

statementListItem
    : ';' endlListOpt
    | singleExpression statementSep
    ;

statementSep
    : ';' endlListOpt
    | endlList
    ;

singleExpression 
    : ID
    | THIS
    | SUPER
    | INT_LIT
    | FLOAT_LIT
    | STRING_LIT
    | TEMPLATE_LITERAL
    | TRUE_KW
    | FALSE_KW
    | NULL_KW
    | '-' endlListOpt singleExpression %prec UMINUS
    | '+' endlListOpt singleExpression %prec UPLUS
    | '!' endlListOpt singleExpression
    | '~' endlListOpt singleExpression
    | singleExpression OPERATOR_INCREMENT %prec POST_INCREMENT
    | singleExpression OPERATOR_DECREMENT %prec POST_DECREMENT
    | OPERATOR_INCREMENT endlListOpt singleExpression %prec PREF_INCREMENT
    | OPERATOR_DECREMENT endlListOpt singleExpression %prec PREF_DECREMENT
    | singleExpression '+' endlListOpt singleExpression
    | singleExpression endlList '+' endlListOpt singleExpression
    /* | singleExpression ',' endlListOpt singleExpression
    | singleExpression endlList ',' endlListOpt singleExpression */
    ;

/* expressionListOpt
    : /* empty
    | expressionList
    ;

expressionList
    : singleExpression
    | expressionList endlListOpt ',' endlListOpt singleExpression
    ; */