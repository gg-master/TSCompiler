%option noyywrap
%option never-interactive
%option yylineno
%option stack

%{

#include <algorithm>
#include <charconv>
#include <iostream>
#include <string>

#include "utils.h"
#include "parser.tab.h"

void rescanTokenString(const char *s);
void doWhileASI();

extern int debug;
int endlSemicolonInsertion;

%}

DEC_DIGIT [0-9]
NON_ZERO_DIGIT [1-9]

DEC_DIGITS  {DEC_DIGIT}(_?{DEC_DIGIT})*
INVALID_UNDERLINE_DEC_DIGITS {DEC_DIGIT}((_?|_{2,}){DEC_DIGIT})*(_+|_?)

DEC_INT_LIT {DEC_DIGIT}|({NON_ZERO_DIGIT}_?{DEC_DIGITS})
INVALID_UNDERLINE_DEC_INT_LIT ({DEC_DIGIT}(_*))|({NON_ZERO_DIGIT}(_?|_{2,}){INVALID_UNDERLINE_DEC_DIGITS})

EXPONENT_PART [eE][+-]?{DEC_DIGITS}
INVALID_UNDERLINE_EXPONENT_PART (_*)[eE](_*)([+-](_*))?{INVALID_UNDERLINE_DEC_DIGITS}

BIN_DIGIT [01]
BIN_DIGITS  {BIN_DIGIT}(_?{BIN_DIGIT})*
INVALID_UNDERLINE_BIN_DIGITS {BIN_DIGIT}((_?|_{2,}){BIN_DIGIT})*(_*)

OCTAL_DIGIT [0-7]
OCTAL_DIGITS {OCTAL_DIGIT}(_?{OCTAL_DIGIT})*
INVALID_UNDERLINE_OCTAL_DIGITS {OCTAL_DIGIT}((_?|_{2,}){OCTAL_DIGIT})*(_*)

HEX_DIGIT [0-9a-fA-F]
HEX_DIGITS {HEX_DIGIT}(_?{HEX_DIGIT})*
INVALID_UNDERLINE_HEX_DIGITS {HEX_DIGIT}((_?|_{2,}){HEX_DIGIT})*(_*)

SINGLE_ESCAPE_CHAR [\'\"\\\b\f\n\r\t\v]
ESCAPE_CHAR ({SINGLE_ESCAPE_CHAR}|{DEC_DIGIT}|x|u)

%x DOUBLE_STR
%x SINGLE_STR
%x TEMPLATE_STR

%x MULTILINE_COMMENT

%x ENDL_OPERATOR
%x DO_WHILE_ASI

%%

%{

std::string currentString;
std::string currentComment;

int currentInteger;
double currentFloatingPoint;

char buffer[10];    

%}

module      {
    PrintError("Unsupported KW_MODULE in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_MODULE: " + std::string{yytext});
    }
    return -1;
} 
package     {
    PrintError("Unsupported KW_PACKAGE in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_PACKAGE: " + std::string{yytext});
    }
    return -1;
} 
import      {
    PrintError("Unsupported KW_IMPORT in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_IMPORT: " + std::string{yytext});
    }
    return -1;
} 
export      {
    PrintError("Unsupported KW_EXPORT in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_EXPORT: " + std::string{yytext});
    }
    return -1;
} 
from        {
    PrintWarn("Unsupported KW_FROM in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_FROM: " + std::string{yytext});
    }
    return FROM;
} 
require     {
    PrintWarn("Unsupported KW_REQUIRE in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_REQUIRE: " + std::string{yytext});
    }
    return REQUIRE;
}

namespace   {
    PrintWarn("Unsupported KW_NAMESPACE in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_NAMESPACE: " + std::string{yytext});
    }
    return NAMESPACE;
} 

delete      {
    PrintError("Unsupported KW_DELETE in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_DELETE: " + std::string{yytext});
    }
    return -1;
} 
debugger    {
    PrintError("Unsupported KW_DEBUGGER in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_DEBUGGER: " + std::string{yytext});
    }
    return -1;
} 
declare     {
    PrintError("Unsupported KW_DECLARE in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_DECLARE: " + std::string{yytext});
    }
    return -1;
} 
with        {
    PrintError("Unsupported KW_WITH in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_WITH: " + std::string{yytext});
    }
    return -1;
}
await       {
    PrintError("Unsupported KW_AWAIT in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_AWAIT: " + std::string{yytext});
    }
    return -1;
}
async       {
    PrintError("Unsupported KW_ASYNC in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_ASYNC: " + std::string{yytext});
    }
    return ASYNC;
}

const       {
    if ( debug ) {
        Print("Found KW_CONST: " + std::string{yytext});
    }
    return CONST;
}
var         {
    if ( debug ) {
        Print("Found KW_VAR: " + std::string{yytext});
    }
    return VAR;
}
let         {
    if ( debug ) {
        Print("Found KW_LET: " + std::string{yytext});
    }
    return LET;
} 

as          {
    PrintWarn("Unsupported KW_AS in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_AS: " + std::string{yytext});
    }
    return AS;
}

any         {
    if ( debug ) {
        Print("Found TYPE_ANY: " + std::string{yytext});
    }
    return ANY; 
} 

boolean     {
    if ( debug ) {
        Print("Found TYPE_BOOLEAN: " + std::string{yytext}); 
    }
    return BOOLEAN; 
}
never       {
    if ( debug ) {
        Print("Found TYPE_NEVER: " + std::string{yytext});
    }
    return NEVER;
} 
symbol      {
    if ( debug ) {
        Print("Found TYPE_SYMBOL: " + std::string{yytext});
    }
    return SYMBOL;
}
number      {
    if ( debug ) {
        Print("Found TYPE_NUMBER: " + std::string{yytext});
    }
    return NUMBER;
}
string      {
    if ( debug ) {
        Print("Found TYPE_STRING: " + std::string{yytext});
    }
    return STRING;
}
object      {
    if ( debug ) {
        Print("Found TYPE_OBJECT: " + std::string{yytext});
    }
    return OBJECT;
}
unknown     {
    if ( debug ) {
        Print("Found TYPE_UNKNOWN: " + std::string{yytext});
    }
    return UNKNOWN;
}
undefined   {
    if ( debug ) {
        Print("Found TYPE_UNDEFINED: " + std::string{yytext});
    }
    return UNDEFINED;
}
void        {
    if ( debug ) {
        Print("Found VOID_OPERATOR: " + std::string{yytext});
    }
    return VOID;
}
null        {
    if ( debug ) {
        Print("Found KW_NULL: " + std::string{yytext});
    }
    return NULL_KW;
}
unique      {
    if ( debug ) {
        Print("Found KW_UNIQUE: " + std::string{yytext});
    }
    return UNIQUE;
}

true        {
    if ( debug ) {
        Print("Found KW_TRUE: " + std::string{yytext});
    }
    return TRUE_KW;
}
false       {
    if ( debug ) {
        Print("Found KW_FALSE: " + std::string{yytext});
    }
    return FALSE_KW;
}

enum        {
    PrintError("Unsupported KW_ENUM in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_ENUM: " + std::string{yytext});
    }
    return -1;
}
type        {
    PrintError("Unsupported KW_TYPE in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_TYPE: " + std::string{yytext});
    }
    return -1;
}
typeof      {
    PrintError("Unsupported KW_TYPEOF in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_TYPEOF: " + std::string{yytext});
    }
    return -1;
}
keyof       {
    PrintWarn("Unsupported KW_KEYOF in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_KEYOF: " + std::string{yytext});
    }
    return KEYOF;
} 
infer       {
    PrintError("Unsupported KW_INFER in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_INFER: " + std::string{yytext});
    }
    return -1;
}
is          {
    PrintError("Unsupported KW_IS in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_IS: " + std::string{yytext});
    }
    return -1;
} 

in          {
    if ( debug ) {
        Print("Found KW_IN: " + std::string{yytext});
    }
    return IN;
} 

try         {
    PrintError("Unsupported KW_TRY in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_TRY: " + std::string{yytext});
    }
    return -1;
}
catch       {
    PrintError("Unsupported KW_CATCH in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_CATCH: " + std::string{yytext});
    }
    return -1;
}
finally     {
    PrintError("Unsupported KW_FINALLY in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_FINALLY: " + std::string{yytext});
    }
    return -1;    
} 
throw       {
    PrintError("Unsupported KW_THROW in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_THROW: " + std::string{yytext});
    }
    return -1;
}

if          {
    if ( debug ) {
        Print("Found KW_IF: " + std::string{yytext});
    }
    return IF;
}
else        { 
    if ( debug ) {
        Print("Found KW_ELSE: " + std::string{yytext});
    }
    return ELSE;
}

switch      {
    PrintError("Unsupported KW_SWITCH in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_SWITCH: " + std::string{yytext});
    }
    return -1;
}
case        {
    PrintError("Unsupported KW_CASE in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_CASE: " + std::string{yytext}); 
    }
    return -1;
}
default     {
    PrintError("Unsupported KW_DEFAULT in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_DEFAULT: " + std::string{yytext});
    }
    return -1;
}

for         {
    if ( debug ) {
        Print("Found KW_FOR: " + std::string{yytext}); 
    }
    return FOR;
}
do          {
    if ( debug ) {
        Print("Found KW_DO: " + std::string{yytext}); 
    }
    return DO;
}
while       {
    if ( debug ) {
        Print("Found KW_WHILE: " + std::string{yytext});
    }
    return WHILE;
}

break       { 
    PrintError("Unsupported KW_BREAK in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_BREAK: " + std::string{yytext});
    }
    return -1;
}

break/[[:space:]]*[\r\n]+ {
    PrintError("Unsupported KW_BREAK in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_BREAK: " + std::string{yytext});
    }
    endlSemicolonInsertion = 1;
    return -1;
}

continue    {
    PrintError("Unsupported KW_CONTINUE in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_CONTINUE: " + std::string{yytext}); 
    }
    return -1;
}

continue/[[:space:]]*[\r\n]+ {
    PrintError("Unsupported KW_CONTINUE in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_CONTINUE: " + std::string{yytext}); 
    }
    endlSemicolonInsertion = 1;
    return -1;
}

function    {
    if ( debug ) {
        Print("Found KW_FUNCTION: " + std::string{yytext}); 
    }
    return FUNCTION;
}

yield       {
    PrintWarn("Unsupported KW_YIELD in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_YIELD: " + std::string{yytext});
    }
    return YIELD;
}

return {
    if ( debug ) {
        Print("Found KW_RETURN: " + std::string{yytext}); 
    }
    return RETURN;
}

return/[[:space:]]*[\r\n]+ { 
    if ( debug ) {
        Print("Found KW_RETURN: " + std::string{yytext}); 
    }
    endlSemicolonInsertion = 1;
    return RETURN;
}

interface   {
    PrintError("Unsupported KW_INTARFACE in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_INTARFACE: " + std::string{yytext});
    }
    return -1;
}

abstract    {
    PrintWarn("Unsupported KW_ABSTRACT in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_ABSTRACT: " + std::string{yytext}, yylineno);
    }
    return ABSTRACT;
}
class       { 
    if ( debug ) {
        Print("Found KW_CLASS: " + std::string{yytext});
    }
    return CLASS;
}
implements  {
    PrintError("Unsupported KW_IMPLEMENTS in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_IMPLEMENTS: " + std::string{yytext});
    }
    return -1;
} 
extends     {
    if ( debug ) {
        Print("Found KW_EXTENDS: " + std::string{yytext});
    }
    return EXTENDS;
}

constructor {
    if ( debug ) {
        Print("Found KW_CONSTRUCTOR: " + std::string{yytext});
    }
    return CONSTRUCTOR;
}
private     {
    PrintError("Unsupported KW_PRIVATE in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_PRIVATE: " + std::string{yytext});
    }
    return -1;
} 
protected   {
    PrintError("Unsupported KW_PROTECTED in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_PROTECTED: " + std::string{yytext});
    }
    return -1;
} 
public      {
    PrintError("Unsupported KW_PUBLIC in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_PUBLIC: " + std::string{yytext});
    }
    return -1;
}
get         {
    if ( debug ) {
        Print("Found KW_GET: " + std::string{yytext});
    }
    return GET;
} 
set         {
    if ( debug ) {
        Print("Found KW_SET: " + std::string{yytext});
    }
    return SET;
}
static      {
    PrintError("Unsupported KW_STATIC in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_STATIC: " + std::string{yytext});
    }
    return -1;
} 
super       {
    if ( debug ) {
        Print("Found KW_SUPER: " + std::string{yytext});
    }
    return SUPER;
}
this        {
    if ( debug ) {
        Print("Found KW_THIS: " + std::string{yytext});
    }
    return THIS;
}
readonly    {
    PrintError("Unsupported KW_READONLY in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found KW_READONLY: " + std::string{yytext});
    }
    return -1;
}

instanceof  {
    if ( debug ) {
        Print("Found KW_INSTANCEOF: " + std::string{yytext});
    }
    return INSTANCEOF;
}

new         { 
    if ( debug ) {
        Print("Found KW_NEW: " + std::string{yytext});
    }
    return NEW;
}

"?"     {
    if ( debug ) {
        Print("Found QUESTION_MARK: " + std::string{yytext}); 
    }
    return '?';
}
"?."    {
    if ( debug ) {
        Print("Found OPTIONAL_CHAINING_OPERATOR: " + std::string{yytext});
    }
    return OPTIONAL_CHAINING_OPERATOR;
}
"??"    {
    PrintError("Unsupported OPERATOR_NULLISH_COALESCING in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found OPERATOR_NULLISH_COALESCING: " + std::string{yytext});
    }
    return -1;
}
"??="   {
    PrintError("Unsupported OPERATOR_ASSIGN_NULLISH_COALESCING in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found OPERATOR_ASSIGN_NULLISH_COALESCING: " + std::string{yytext});
    }
    return -1;
}

"%"     {
    if ( debug ) {
        Print("Found OPERATOR_MOD: " + std::string{yytext});
    }
    return '%';
}
"%="    {
    PrintError("Unsupported OPERATOR_ASSIGN_MOD in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found OPERATOR_ASSIGN_MOD: " + std::string{yytext});
    }
    return -1;
}

"+"     {
    if ( debug ) {
        Print("Found OPERATOR_PLUS: " + std::string{yytext});
    }
    return '+'; 
}
"+="    {
    if ( debug ) {
        Print("Found OPERATOR_ASSIGN_PLUS: " + std::string{yytext});
    }
}
"++"    { 
    if ( debug ) {
        Print("Found OPERATOR_INCREMENT: " + std::string{yytext}); 
    }
    return OPERATOR_INCREMENT; 
}

"-"     {
    if ( debug ) {
        Print("Found OPERATOR_MINUS: " + std::string{yytext});
    }
    return '-';
}
"-="    {
    if ( debug ) {
        Print("Found OPERATOR_ASSIGN_MINUS: " + std::string{yytext});
    }
    return OPERATOR_ASSIGN_MINUS;
}
"--"    {
    if ( debug ) {
        Print("Found OPERATOR_DECREMENT: " + std::string{yytext});
    }
    return OPERATOR_DECREMENT;
}

<ENDL_OPERATOR>"++" {
    yy_pop_state();

    if ( debug ) {
        Print("Found ENDL_OPERATOR_INCREMENT");
    }
    return ENDL_OPERATOR_INCREMENT;
}
<ENDL_OPERATOR>"--" {
    yy_pop_state();

    if ( debug ) {
        Print("Found ENDL_OPERATOR_DECREMENT");
    }
    return ENDL_OPERATOR_DECREMENT;
}
[\n\r]+[[:space:]]*/"++" |
[\n\r]+[[:space:]]*/"--" {
    yy_push_state(ENDL_OPERATOR);

    if ( debug ) {
        Print("Found ENDL of ENDL_OPERATOR");
    }
    return ENDL;
}

"*"     {
    if ( debug ) {
        Print("Found OPERATOR_MULTIPLY: " + std::string{yytext});
    }
    return '*';
}
"**"    {
    PrintError("Unsupported OPERATOR_POWER in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found OPERATOR_POWER: " + std::string{yytext});
    }
    return -1;
}
"*="    {
    if ( debug ) {
        Print("Found OPERATOR_ASSIGN_MULTIPLY: " + std::string{yytext});
    }
    return OPERATOR_ASSIGN_MULTIPLY;
}
"**="   {
    PrintError("Unsupported OPERATOR_ASSIGN_POWER in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found OPERATOR_ASSIGN_POWER: " + std::string{yytext});
    }
    return -1;
}

"="     { 
    if ( debug ) {
        Print("Found OPERATOR_ASSIGN: " + std::string{yytext}); 
    }
    return '=';
}
"=="    {
    if ( debug ) {
        Print("Found OPERATOR_EQUAL: " + std::string{yytext});
    }
    return OPERATOR_EQUAL;
}
"==="   {
    if ( debug ) {
        Print("Found OPERATOR_STRICT_EQUAL: " + std::string{yytext});
    }
    return OPERATOR_STRICT_EQUAL;
}

"!"     {
    if ( debug ) {
        Print("Found OPERATOR_NOT: " + std::string{yytext});
    }
    return '!';
}
"!="    {
    if ( debug ) {
        Print("Found OPERATOR_NOT_EQUAL: " + std::string{yytext});
    }
    return OPERATOR_NOT_EQUAL;
}
"!=="   {
    if ( debug ) {
        Print("Found OPERATOR_STRICT_NOT_EQUAL: " + std::string{yytext});
    }
    return OPERATOR_STRICT_NOT_EQUAL;
}

"=>"    {
    PrintError("Unsupported ARROW_FUNCTION in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found ARROW_FUNCTION: " + std::string{yytext});
    }
    return -1;
}

">"     {
    if ( debug ) {
        Print("Found OPERATOR_GREATER_THAN: " + std::string{yytext});
    }
    return '>';
}
">="    {
    PrintError("Unsupported OPERATOR_GREATER_THAN_EQUAL in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found OPERATOR_GREATER_THAN_EQUAL: " + std::string{yytext});
    }
    return -1;
}
">>"    {
    PrintError("Unsupported OPERATOR_SHIFT_RIGHT in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found OPERATOR_SHIFT_RIGHT: " + std::string{yytext});
    }
    return -1;
}
">>="   {
    PrintError("Unsupported OPERATOR_ASSIGN_SHIFT_RIGHT in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found OPERATOR_ASSIGN_SHIFT_RIGHT: " + std::string{yytext});
    }
    return -1;
}
">>>"   {
    PrintError("Unsupported OPERATOR_UNSIGNED_SHIFT_RIGHT in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found OPERATOR_UNSIGNED_SHIFT_RIGHT: " + std::string{yytext});
    }
    return -1;
}
">>>="  {
    PrintError("Unsupported OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT: " + std::string{yytext});
    }
    return -1;
}

"<"     {
    if ( debug ) {
        Print("Found OPERATOR_LESS_THAN: " + std::string{yytext});
    }
    return '<';
}
"<="    {
    PrintError("Unsupported OPERATOR_LESS_THAN_EQUAL in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found OPERATOR_LESS_THAN_EQUAL: " + std::string{yytext});
    }
    return -1;
}
"<<"    {
    PrintError("Unsupported OPERATOR_SHIFT_LEFT in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found OPERATOR_SHIFT_LEFT: " + std::string{yytext});
    }
    return -1;
}
"<<="   {
    PrintError("Unsupported OPERATOR_ASSIGN_SHIFT_LEFT in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found OPERATOR_ASSIGN_SHIFT_LEFT: " + std::string{yytext});
    }
    return -1;
}

"/"     {
    if ( debug ) {
        Print("Found OPERATOR_DIVIDE: " + std::string{yytext});
    }
    return '/';
}
"/="    {
    if ( debug ) {
        Print("Found OPERATOR_ASSIGN_DIVIDE: " + std::string{yytext});
    }
    return OPERATOR_ASSIGN_DIVIDE;
}

"^"     {
    if ( debug ) {
        Print("Found OPERATOR_BITWISE_XOR: " + std::string{yytext});
    }
    return '^';
}
"^="    {
    PrintError("Unsupported OPERATOR_ASSIGN_BITWISE_XOR in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found OPERATOR_ASSIGN_BITWISE_XOR: " + std::string{yytext});
    }
    return -1;
}

"~"     {
    if ( debug ) {
        Print("Found OPERATOR_BITWISE_NOT: " + std::string{yytext});
    }
    return '~';
}

"&"     {
    if ( debug ) {
        Print("Found OPERATOR_BITWISE_AND: " + std::string{yytext});
    }
    return '&';
}
"&="    {
    PrintError("Unsupported OPERATOR_ASSIGN_BITWISE_AND in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found OPERATOR_ASSIGN_BITWISE_AND: " + std::string{yytext}); 
    }
    return -1;
}
"&&"    {
    if ( debug ) {
        Print("Found OPERATOR_LOGICAL_AND: " + std::string{yytext});
    }
    return OPERATOR_LOGICAL_AND;
}
"&&="   {
    if ( debug ) {
        Print("Found OPERATOR_ASSIGN_LOGICAL_AND: " + std::string{yytext});
    }
    return OPERATOR_ASSIGN_LOGICAL_AND;
}

"|"     {
    if ( debug ) {
        Print("Found OPERATOR_BITWISE_OR: " + std::string{yytext});
    }
    return '|';
}
"|="    {
    PrintError("Unsupported OPERATOR_ASSIGN_BITWISE_OR in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found OPERATOR_ASSIGN_BITWISE_OR: " + std::string{yytext});
    }
    return -1;
}
"||"    {
    if ( debug ) {
        Print("Found OPERATOR_LOGICAL_OR: " + std::string{yytext});
    }
    return OPERATOR_LOGICAL_OR;
}
"||="   {
    if ( debug ) {
        Print("Found OPERATOR_ASSIGN_LOGICAL_OR: " + std::string{yytext});
    }
    return OPERATOR_ASSIGN_LOGICAL_OR;
}

"["     { 
    if ( debug ) {
        Print("Found BRACKET_OPEN: " + std::string{yytext}); 
    }
    return '['; 
}
<ENDL_OPERATOR>"[" {
    yy_pop_state();

    if ( debug ) {
        Print("Found ENDL_BRACKET_OPEN");
    }
    return ENDL_BRACKET_OPEN;
}
[\n\r]+[[:space:]]*/"[" {
    yy_push_state(ENDL_OPERATOR);

    if ( debug ) {
        Print("Found ENDL of ENDL_OPERATOR");
    }
    return ENDL;
}

"]"     { 
    if ( debug ) {
        Print("Found BRACKET_CLOSE: " + std::string{yytext}); 
    }
    return ']'; 
}
"("     { 
    if ( debug ) {
        Print("Found PARENTHESIS_OPEN: " + std::string{yytext}); 
    }
    return '('; 
}
")"     { 
    if ( debug ) {
        Print("Found PARENTHESIS_CLOSE: " + std::string{yytext}); 
    }
    return ')';
}
"{"     { 
    if ( debug ) {
        Print("Found BRACE_OPEN: " + std::string{yytext}); 
    }
    return '{'; 
}
"}" {
    if ( debug ) {
        Print("Found BRACE_CLOSE: " + std::string{yytext}); 
    }
    return '}';
}

":"     { 
    if ( debug ) {
        Print("Found COLON: " + std::string{yytext});
    }
    return ':'; 
}

","     { 
    if ( debug ) {
        Print("Found COMMA: " + std::string{yytext}); 
    }
    return ','; 
}

"."     {
    if ( debug ) {
        Print("Found DOT: " + std::string{yytext}); 
    }
    return '.';
}

"..."   {
    PrintError("Unsupported DOTS_ELLIPSIS in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found DOTS_ELLIPSIS: " + std::string{yytext}); 
    }
    return -1;
}

";"     {
    if ( debug ) {
        Print("Found SEMICOLON: " + std::string{yytext});
    }
    return ';';
}

"@"     {
    PrintError("Unsupported DECORATOR_AT in this version: " + std::string{yytext});
    if ( debug ) {
        Print("Found DECORATOR_AT: " + std::string{yytext});
    }
    return -1;
}


\" {
    currentString.clear();
    BEGIN(DOUBLE_STR);
}
<DOUBLE_STR>[^\"\\\n\r]+ {
    currentString += yytext;
}
<DOUBLE_STR,SINGLE_STR,TEMPLATE_STR>\\x {
    PrintError("invalid hexadecimal escape sequence", yylineno);
}
<DOUBLE_STR,SINGLE_STR,TEMPLATE_STR>\\x({HEX_DIGIT}{2}) {
    std::fill(std::begin(buffer), std::end(buffer), 0);
    std::copy(yytext, yytext + yyleng, buffer);
    sscanf_s(buffer + 2, "%x", &currentInteger);
    currentString += static_cast<char>(currentInteger);
}
<DOUBLE_STR,SINGLE_STR,TEMPLATE_STR>\\0 {
    currentString += "\0";
}
<DOUBLE_STR,SINGLE_STR,TEMPLATE_STR>\\({OCTAL_DIGIT}{1,3}) {
    PrintError("octal escape sequence not allowed", yylineno);
}
<DOUBLE_STR,SINGLE_STR,TEMPLATE_STR>\\u[({HEX_DIGIT}{0,4})(\{{HEX_DIGITS}\})] {
    PrintError("unicode escape sequence is not supported yet", yylineno);
}
<DOUBLE_STR,SINGLE_STR,TEMPLATE_STR>\\\' {
    currentString += "\'";
}
<DOUBLE_STR,SINGLE_STR,TEMPLATE_STR>\\\" {
    currentString += "\"";
}
<DOUBLE_STR,SINGLE_STR,TEMPLATE_STR>\\\\ {
    currentString += "\\";
}
<DOUBLE_STR,SINGLE_STR,TEMPLATE_STR>\\b {
    currentString += "\b";
}
<DOUBLE_STR,SINGLE_STR,TEMPLATE_STR>\\f {
    currentString += "\f";
}
<DOUBLE_STR,SINGLE_STR,TEMPLATE_STR>\\n {
    currentString += "\n";
}
<DOUBLE_STR,SINGLE_STR,TEMPLATE_STR>\\r {
    currentString += "\r";
}
<DOUBLE_STR,SINGLE_STR,TEMPLATE_STR>\\t {
    currentString += "\t";
}
<DOUBLE_STR,SINGLE_STR,TEMPLATE_STR>\\v {
    currentString += "\v";
}
<DOUBLE_STR,SINGLE_STR,TEMPLATE_STR>\\{ESCAPE_CHAR} {
    PrintError("invalid escape character", yylineno);
}
<DOUBLE_STR,SINGLE_STR>\n {
    PrintError("unexpected appearing \n in end of a line", yylineno);
    BEGIN(INITIAL);
}
<DOUBLE_STR,SINGLE_STR,TEMPLATE_STR><<EOF>> {
    PrintError("unexpected appearing <<EOF>> in string literal", yylineno);
    BEGIN(INITIAL);
}
<DOUBLE_STR>\" {
    PrintStringLiteral(currentString);
    yylval._string = Dublicate(currentString.c_str());
    BEGIN(INITIAL);
    return STRING_LIT;
}

\' {
    currentString.clear();
    BEGIN(SINGLE_STR);
}
<SINGLE_STR>[^\'\\\n\r]+ {
    currentString += yytext;
}
<SINGLE_STR>\' {
    PrintStringLiteral(currentString);
    yylval._string = Dublicate(currentString.c_str());
    BEGIN(INITIAL);
    return STRING_LIT;
}

\` {
    currentString.clear();
    BEGIN(TEMPLATE_STR);
}
<TEMPLATE_STR>[^\`\\]+ {
    currentString += yytext;
}
<TEMPLATE_STR>\\\` {
    currentString += "`";
}
<TEMPLATE_STR>\` {
    PrintStringLiteral(currentString);
    yylval._string = Dublicate(currentString.c_str());
    BEGIN(INITIAL);
    return STRING_LIT;
}


"/*" {
    currentComment.clear();
    BEGIN(MULTILINE_COMMENT);
}
<MULTILINE_COMMENT>[^*]+ {
    currentComment += yytext;
}
<MULTILINE_COMMENT>\*+[^*/]+ {
    currentComment += yytext;
}
<MULTILINE_COMMENT>\*+\/ {
    Print("Found multiline comment: \n" + currentComment);
    BEGIN(INITIAL);
}
<MULTILINE_COMMENT><<EOF>> {
    PrintError("no closing */ of multiline comment", yylineno);
    BEGIN(INITIAL);
}

\/\/.*  { 
    Print("Found singleline comment: " + std::string{yytext + 2}); 
}

{DEC_INT_LIT} { 
    std::string number_string = yytext;
    RemoveCharacterFromString(number_string, '_');
    std::from_chars(number_string.c_str(), number_string.c_str() + number_string.size(), currentInteger);
    PrintIntegerLiteral("decimal", currentInteger); 
    yylval._integer = currentInteger;
    return INT_LIT;
}
{INVALID_UNDERLINE_DEC_INT_LIT} {
    PrintError("illegal underscore in decimal number", yylineno);
}

({DEC_INT_LIT})(\.|(\.?{EXPONENT_PART})) { /* Decimal literal */
    std::string number_string = yytext;
    RemoveCharacterFromString(number_string, '_');
    std::from_chars(number_string.c_str(), number_string.c_str() + number_string.size(), currentFloatingPoint);
    PrintFloatingPointLiteral(currentFloatingPoint);
    yylval._floatingPoint = currentFloatingPoint;
    return FLOAT_LIT;
}
{INVALID_UNDERLINE_DEC_INT_LIT}(_*)(\.|(\.?{INVALID_UNDERLINE_EXPONENT_PART})) {
    PrintError("illegal underscore in decimal number", yylineno);
}

({DEC_INT_LIT})?\.{DEC_DIGITS}({EXPONENT_PART})? {
    std::string number_string = yytext;
    RemoveCharacterFromString(number_string, '_');
    std::from_chars(number_string.c_str(), number_string.c_str() + number_string.size(), currentFloatingPoint);
    PrintFloatingPointLiteral(currentFloatingPoint);
    yylval._floatingPoint = currentFloatingPoint;
    return FLOAT_LIT;
}
({INVALID_UNDERLINE_DEC_INT_LIT})?(_*)\.{INVALID_UNDERLINE_DEC_DIGITS}({INVALID_UNDERLINE_EXPONENT_PART})? {
    PrintError("illegal underscore in decimal number", yylineno);
}


0[bB]{BIN_DIGITS} { /* Binary integer literal */
    currentInteger = 0;
    std::string number_string = yytext;
    RemoveCharacterFromString(number_string, '_');
    std::from_chars(number_string.c_str() + 2, number_string.c_str() + number_string.size(), currentInteger, 2);
    PrintIntegerLiteral("binary", currentInteger); 
    yylval._integer = currentInteger;
    return INT_LIT;
}
0(_*)[bB](_*){INVALID_UNDERLINE_BIN_DIGITS} {
    PrintError("illegal underscore in binary number", yylineno);
}
0[bB][^01[:space:]]+ {
    PrintError("binary digit expected", yylineno);
}


0[oO]{OCTAL_DIGITS} {  /* Octal integer literal */
    currentInteger = 0;
    std::string number_string = yytext;
    RemoveCharacterFromString(number_string, '_');
    std::from_chars(number_string.c_str() + 2, number_string.c_str() + number_string.size(), currentInteger, 8);
    PrintIntegerLiteral("octal", currentInteger); 
    yylval._integer = currentInteger;
    return INT_LIT;
}
0(_*)[oO](_*){INVALID_UNDERLINE_OCTAL_DIGITS} {
    PrintError("illegal underscore in octal number", yylineno);
}
0[oO][^0-7[:space:]]+ {
    PrintError("octal digit expected", yylineno);
}


0[xX]{HEX_DIGITS} {  /* Hexadecimal integer literal */
    currentInteger = 0;
    std::string number_string = yytext;
    RemoveCharacterFromString(number_string, '_');
    std::from_chars(number_string.c_str() + 2, number_string.c_str() + number_string.size(), currentInteger, 16);
    PrintIntegerLiteral("hexadecimal", currentInteger);
    yylval._integer = currentInteger;
    return INT_LIT;
}
0(_*)[xX](_*){INVALID_UNDERLINE_HEX_DIGITS} {
    PrintError("illegal underscore in hexadecimal number", yylineno);
}
0[xX][^1-9a-fA-F[:space:]]+ {
    PrintError("hexadecimal digit expected", yylineno);
}


[[:alpha:]_$][[:alnum:]_$]* { 
    Print("Found identifier: " + std::string{yytext}); 
    yylval.ident = Dublicate(yytext);
    return ID;
}

[ \t]+    { /* ignoring spaces and tabs */ }

[\r\n] {
    Print("Found ENDL", yylineno);
    if (endlSemicolonInsertion) {
        Print("ASI Replace ENDL -> ';'", yylineno);
        endlSemicolonInsertion = 0;
        return ';';
    }
    return ENDL;
}

<DO_WHILE_ASI>. {
    yy_pop_state();
    if ( debug ) {
        Print("ASI inserted ';' after do-while: " + std::string{yytext}); 
    }
    if (*yytext != ';') {
        rescanTokenString(yytext);
    }
    return ';';
}

. {
    Print("Found UNRECOGNIZED TOKEN: " + std::string{yytext}, yylineno);
    return -1;
}

<DO_WHILE_ASI><<EOF>> |
<INITIAL><<EOF>> {
    yyterminate();
}

%%

void rescanTokenString(const char * s) {
    char *yycopy = _strdup( yytext );
    for (int i = yyleng - 1; i >= 0; --i ) {
        unput( yycopy[i] ); 
    }
    free( yycopy );
}

void doWhileASI() {
    if ( debug ) {
        Print("activated do-while ASI state"); 
    }
    yy_push_state(DO_WHILE_ASI);
}
