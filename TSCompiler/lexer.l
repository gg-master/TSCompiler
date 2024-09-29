%option noyywrap
%option never-interactive
%option yylineno

%{

#include <string>
#include <algorithm>
#include <charconv>
#include <iostream>
#include <cstdio>


void Print(const std::string& message)
{
    std::cout << message << std::endl;
}

void PrintError(const std::string& errorMessage, const int line = -1) 
{
    std::cerr << errorMessage << std::endl;
    if (line >= 0)
        std::cerr << "Line: " << line << std::endl;
    std::cerr << std::endl;
}

void PrintIntegerLiteral(const std::string& type, const int integer) {
    Print("Found " + type + " integer literal: " + std::to_string(integer));
}

void PrintFloatingPointLiteral(const double floatingPoint) {
    Print("Found floating point literal: " + std::to_string(floatingPoint));
}

void RemoveCharacterFromString(std::string& str, char ch) {
    const auto newLast = std::remove(str.begin(), str.end(), ch);
    str.erase(newLast, str.end());
}

void RemoveUnderline(std::string& str) {
    RemoveCharacterFromString(str, '_');
}

%}

DEC_DIGIT [0-9]
NON_ZERO_DIGIT [1-9]

DEC_DIGITS  {DEC_DIGIT}(_?{DEC_DIGIT})*

DEC_INT_LIT 0|{NON_ZERO_DIGIT}_?{DEC_DIGITS}

EXPONENT_PART [eE][+-]?{DEC_DIGITS}

BIN_DIGIT [01]
BIN_DIGITS  {BIN_DIGIT}(_?{BIN_DIGIT})*

OCTAL_DIGIT [0-7]
OCTAL_DIGITS {OCTAL_DIGIT}(_?{OCTAL_DIGIT})*

HEX_DIGIT [0-9a-fA-F]
HEX_DIGITS {HEX_DIGIT}(_?{HEX_DIGIT})*


%x STR_DOUBLE_Q
%x STR_SINGLE_Q
%x STR_BACK_Q

%x MULTILINE_COMMENT

%x COMMENT
%x COMMENTONE

%%

%{

std::string currentString;
std::string currentComment;

int currentInteger;
char currentCharacter;
double currentFloatingPoint;
char buffer[10];    
char bufferString[1000];

%}

abstract    { Print("Found KW_ABSTRACT: " + std::string{yytext}); } 
any         { Print("Found TYPE_ANY: " + std::string{yytext}); } 
as          { Print("Found KW_AS: " + std::string{yytext}); } 
boolean     { Print("Found TYPE_BOOLEAN: " + std::string{yytext}); } 
break       { Print("Found KW_BREAK: " + std::string{yytext}); } 
case        { Print("Found KW_CASE: " + std::string{yytext}); } 
catch       { Print("Found KW_CATCH: " + std::string{yytext}); } 
class       { Print("Found KW_CLASS: " + std::string{yytext}); } 
continue    { Print("Found KW_CONTINUE: " + std::string{yytext}); } 
const       { Print("Found KW_CONST: " + std::string{yytext}); } 
constructor { Print("Found KW_CONSTRUCTOR: " + std::string{yytext}); } 
debugger    { Print("Found KW_DEBUGGER: " + std::string{yytext}); } 
declare     { Print("Found KW_DECLARE: " + std::string{yytext}); } 
default     { Print("Found KW_DEFAULT: " + std::string{yytext}); } 
delete      { Print("Found KW_DELETE: " + std::string{yytext}); } 
do          { Print("Found KW_DO: " + std::string{yytext}); } 
else        { Print("Found KW_ELSE: " + std::string{yytext}); } 
enum        { Print("Found KW_ENUM: " + std::string{yytext}); } 
export      { Print("Found KW_EXPORT: " + std::string{yytext}); } 
extends     { Print("Found KW_EXTENDS: " + std::string{yytext}); } 
false       { Print("Found KW_FALSE: " + std::string{yytext}); } 
finally     { Print("Found KW_FINALLY: " + std::string{yytext}); } 
for         { Print("Found KW_FOR: " + std::string{yytext}); } 
from        { Print("Found KW_FROM: " + std::string{yytext}); } 
function    { Print("Found KW_FUNCTION: " + std::string{yytext}); } 
get         { Print("Found KW_GET: " + std::string{yytext}); } 
if          { Print("Found KW_IF: " + std::string{yytext}); } 
implements  { Print("Found KW_IMPLEMENTS: " + std::string{yytext}); } 
import      { Print("Found KW_IMPORT: " + std::string{yytext}); } 
in          { Print("Found KW_IN: " + std::string{yytext}); } 
infer       { Print("Found KW_INFER: " + std::string{yytext}); } 
instanceof  { Print("Found KW_INSTANCEOF: " + std::string{yytext}); } 
interface   { Print("Found KW_INTARFACE: " + std::string{yytext}); } 
is          { Print("Found KW_IS: " + std::string{yytext}); } 
keyof       { Print("Found KW_KEYOF: " + std::string{yytext}); } 
let         { Print("Found KW_LET: " + std::string{yytext}); } 
module      { Print("Found KW_MODULE: " + std::string{yytext}); } 
namespace   { Print("Found KW_NAMESPACE: " + std::string{yytext}); } 
never       { Print("Found TYPE_NEVER: " + std::string{yytext}); } 
new         { Print("Found KW_NEW: " + std::string{yytext}); } 
null        { Print("Found KW_NULL: " + std::string{yytext}); } 
number      { Print("Found TYPE_NUMBER: " + std::string{yytext}); } 
object      { Print("Found TYPE_OBJECT: " + std::string{yytext}); } 
of          { Print("Found KW_OF: " + std::string{yytext}); } 
package     { Print("Found KW_PACKAGE: " + std::string{yytext}); } 
private     { Print("Found KW_PRIVATE: " + std::string{yytext}); } 
protected   { Print("Found KW_PROTECTED: " + std::string{yytext}); } 
public      { Print("Found KW_PUBLIC: " + std::string{yytext}); } 
readonly    { Print("Found KW_READONLY: " + std::string{yytext}); } 
require     { Print("Found KW_REQUIRE: " + std::string{yytext}); } 
return      { Print("Found KW_RETURN: " + std::string{yytext}); } 
set         { Print("Found KW_SET: " + std::string{yytext}); } 
static      { Print("Found KW_STATIC: " + std::string{yytext}); } 
string      { Print("Found TYPE_STRING: " + std::string{yytext}); } 
super       { Print("Found KW_SUPER: " + std::string{yytext}); } 
switch      { Print("Found KW_SWITCH: " + std::string{yytext}); }
symbol      { Print("Found TYPE_SYMBOL: " + std::string{yytext}); }
this        { Print("Found KW_THIS: " + std::string{yytext}); }
throw       { Print("Found KW_THROW: " + std::string{yytext}); }
true        { Print("Found KW_TRUE: " + std::string{yytext}); }
try         { Print("Found KW_TRY: " + std::string{yytext}); }
type        { Print("Found KW_TYPE: " + std::string{yytext}); }
typeof      { Print("Found KW_TYPEOF: " + std::string{yytext}); }
unique      { Print("Found KW_UNIQUE: " + std::string{yytext}); } 
unknown     { Print("Found TYPE_UNKNOWN: " + std::string{yytext}); } 
var         { Print("Found KW_VAR: " + std::string{yytext}); }
while       { Print("Found KW_WHILE: " + std::string{yytext}); }
undefined   { Print("Found KW_UNDEFINED: " + std::string{yytext}); }

"?"     { Print("Found OPERATOR_OPT_PARAM: " + std::string{yytext}); }
"%"     { Print("Found OPERATOR_MOD: " + std::string{yytext}); }
"%="    { Print("Found OPERATOR_MOD_ASSIGNMENT: " + std::string{yytext}); }
"+"     { Print("Found OPERATOR_PLUS: " + std::string{yytext}); }
"+="    { Print("Found OPERATOR_PLUS_ASSIGNMENT: " + std::string{yytext}); }
"++"    { Print("Found OPERATOR_INCREMENT: " + std::string{yytext}); }
"-"     { Print("Found OPERATOR_MINUS: " + std::string{yytext}); }
"-="    { Print("Found OPERATOR_MINUS_ASSIGNMENT: " + std::string{yytext}); }
"--"    { Print("Found OPERATOR_DICREMENT: " + std::string{yytext}); }
"*"     { Print("Found OPERATOR_MUL: " + std::string{yytext}); }
"*="    { Print("Found OPERATOR_MUL_ASSIGNMENT: " + std::string{yytext}); }
"="     { Print("Found OPERATOR_ASSIGNMENT: " + std::string{yytext}); }
"=="    { Print("Found OPERATOR_EQUAL: " + std::string{yytext}); }
"==="   { Print("Found OPERATOR_EQUAL_BY_TYPE_AND_VALUE: " + std::string{yytext}); }
"!"     { Print("Found OPERATOR_BIT_NOT: " + std::string{yytext}); }
"!="    { Print("Found OPERATOR_NOT_EQUAL: " + std::string{yytext}); }
"!=="   { Print("Found OPERATOR_NOT_EQUAL_BY_TYPE_AND_VALUE: " + std::string{yytext}); }
">"     { Print("Found OPERATOR_MORE: " + std::string{yytext}); }
">="    { Print("Found OPERATOR_MORE_OR_EQUAL: " + std::string{yytext}); }
"<"     { Print("Found OPERATOR_LESS: " + std::string{yytext}); }
"<="    { Print("Found OPERATOR_LESS_OR_EQUA: " + std::string{yytext}); }
"/"     { Print("Found OPERATOR_DIV: " + std::string{yytext}); }
"/="    { Print("Found OPERATOR_DIV_ASSIGNMENT: " + std::string{yytext}); }
"^"     { Print("Found OPERATOR_BIT_XOR: " + std::string{yytext}); }
"~"     { Print("Found UNARY_BITWISE_NOT: " + std::string{yytext}); }
"&"     { Print("Found OPERATOR_AMPERSAND: " + std::string{yytext}); }
"&&"    { Print("Found OPERATOR_AND: " + std::string{yytext}); }
"|"     { Print("Found OPERATOR_BIT_OR: " + std::string{yytext}); }
"||"    { Print("Found OPERATOR_OR: " + std::string{yytext}); }
"["     { Print("Found LEFT_SQUARE_BRACKET: " + std::string{yytext}); }
"]"     { Print("Found RIGHT_SQUARE_BRACKET: " + std::string{yytext}); }
"("     { Print("Found LEFT_ROUND_BRACKET: " + std::string{yytext}); }
")"     { Print("Found RIGHT_ROUND_BRACKET: " + std::string{yytext}); }
"{"     { Print("Found LEFT_FIGURE_BRACKET: " + std::string{yytext}); }
"}"     { Print("Found RIGHT_FIGURE_BRACKET: " + std::string{yytext}); }
":"     { Print("Found COLON: " + std::string{yytext}); }
","     { Print("Found COMMA: " + std::string{yytext}); }
"."     { Print("Found DOT: " + std::string{yytext}); }
";"     { Print("Found SEMICOLON: " + std::string{yytext}); }
"n"     { Print("Found OPERATOR_ENTER: \\n" + std::string{yytext}); }



{DEC_INT_LIT}(\.|(\.?{EXPONENT_PART})) { /* Decimal literal */
    std::string number_string = yytext;
    RemoveCharacterFromString(number_string, '_');
    std::from_chars(number_string.c_str(), number_string.c_str() + number_string.size(), currentFloatingPoint);
    PrintFloatingPointLiteral(currentFloatingPoint);
}

({DEC_INT_LIT}?\.{DEC_DIGITS}){EXPONENT_PART}? {
    std::string number_string = yytext;
    RemoveCharacterFromString(number_string, '_');
    std::from_chars(number_string.c_str(), number_string.c_str() + number_string.size(), currentFloatingPoint);
    PrintFloatingPointLiteral(currentFloatingPoint);
}

{DEC_INT_LIT} {
    std::string number_string = yytext;
    RemoveCharacterFromString(number_string, '_');
    std::from_chars(number_string.c_str(), number_string.c_str() + number_string.size(), currentInteger);
    PrintIntegerLiteral("decimal", currentInteger); 
}


0[bB]{BIN_DIGITS} { /* Binary integer literal */
    currentInteger = 0;
    std::string number_string = yytext;
    RemoveCharacterFromString(number_string, '_');
    std::from_chars(number_string.c_str() + 2, number_string.c_str() + number_string.size(), currentInteger, 2);
    PrintIntegerLiteral("binary", currentInteger); 
}


0[oO]{OCTAL_DIGITS} {  /* Octal integer literal */
    currentInteger = 0;
    std::string number_string = yytext;
    RemoveCharacterFromString(number_string, '_');
    std::from_chars(number_string.c_str() + 2, number_string.c_str() + number_string.size(), currentInteger, 8);
    PrintIntegerLiteral("octal", currentInteger); 
}


0[xX]{HEX_DIGITS} {  /* Hexadecimal integer literal */
    currentInteger = 0;
    std::string number_string = yytext;
    RemoveCharacterFromString(number_string, '_');
    std::from_chars(number_string.c_str() + 2, number_string.c_str() + number_string.size(), currentInteger, 16);
    PrintIntegerLiteral("hexadecimal", currentInteger); 
}


[[:alpha:]_][[:alnum:]_]*   { Print("Found identifier: " + std::string{yytext}); }


[[:space:]]+    { /* ignoring */ }

%%

int main(int argc, char *argv[]) {
    if (argc < 2) {
        Print("Usage: %s <input_file>\n" + std::string{argv[0]});
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        PrintError("could not open file: " + std::string{argv[1]});
        return 1;
    }
    
	FILE* output_file = fopen("output.txt", "w");
	if (!output_file) {
		PrintError("could not create output file\n");
		fclose(input_file);
		return 1;
	}

    yyin = input_file;
    yyout = output_file;
    yylex();        

	fclose(input_file);
	fclose(output_file);
    return 0;
}
