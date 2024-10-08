%option noyywrap
%option never-interactive
%option yylineno

%{

#include <algorithm>
#include <charconv>
#include <cstdio>
#include <iostream>
#include <string>


void Print(const std::string& message) {
    std::cout << message << std::endl;
}

void PrintError(const std::string& errorMessage, const int line = -1) {
    std::cerr << "error: " << errorMessage << std::endl;
    if (line >= 0)
        std::cerr << "error line: " << line << std::endl;
    std::cerr << std::endl;
}

void PrintIntegerLiteral(const std::string& type, const int integer) {
    Print("Found " + type + " integer literal: " + std::to_string(integer));
}

void PrintFloatingPointLiteral(const double floatingPoint) {
    Print("Found floating point literal: " + std::to_string(floatingPoint));
}

void PrintStringLiteral(const std::string& literal) {
    Print("Found string literal: \"" + literal + "\"");
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

%%

%{

std::string currentString;
std::string currentComment;

int currentInteger;
double currentFloatingPoint;

char buffer[10];    

%}

abstract    { Print("Found KW_ABSTRACT: " + std::string{yytext}); } 
any         { Print("Found TYPE_ANY: " + std::string{yytext}); } 
as          { Print("Found KW_AS: " + std::string{yytext}); }
await       { Print("Found KW_AWAIT: " + std::string{yytext}); }
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
undefined   { Print("Found KW_UNDEFINED: " + std::string{yytext}); }
unique      { Print("Found KW_UNIQUE: " + std::string{yytext}); } 
unknown     { Print("Found TYPE_UNKNOWN: " + std::string{yytext}); } 
var         { Print("Found KW_VAR: " + std::string{yytext}); }
void        { Print("Found VOID_OPERATOR: " + std::string{yytext}); }
while       { Print("Found KW_WHILE: " + std::string{yytext}); }
with        { Print("Found KW_WITH: " + std::string{yytext}); }
yield       { Print("Found KW_YIELD: " + std::string{yytext}); }

"?"     { Print("Found QUESTION_MARK: " + std::string{yytext}); }
"?."    { Print("Found OPTIONAL_CHAINING_OPERATOR: " + std::string{yytext}); }
"??"    { Print("Found OPERATOR_NULLISH_COALESCING: " + std::string{yytext}); }
"??="   { Print("Found OPERATOR_ASSIGN_NULLISH_COALESCING: " + std::string{yytext}); }

"%"     { Print("Found OPERATOR_MOD: " + std::string{yytext}); }
"%="    { Print("Found OPERATOR_ASSIGN_MOD: " + std::string{yytext}); }

"+"     { Print("Found OPERATOR_PLUS: " + std::string{yytext}); }
"+="    { Print("Found OPERATOR_ASSIGN_PLUS: " + std::string{yytext}); }
"++"    { Print("Found OPERATOR_INCREMENT: " + std::string{yytext}); }

"-"     { Print("Found OPERATOR_MINUS: " + std::string{yytext}); }
"-="    { Print("Found OPERATOR_ASSIGN_MINUS: " + std::string{yytext}); }
"--"    { Print("Found OPERATOR_DECREMENT: " + std::string{yytext}); }

"*"     { Print("Found OPERATOR_MULTIPLY: " + std::string{yytext}); }
"**"    { Print("Found OPERATOR_POWER: " + std::string{yytext}); }
"*="    { Print("Found OPERATOR_ASSIGN_MULTIPLY: " + std::string{yytext}); }
"**="   { Print("Found OPERATOR_ASSIGN_POWER: " + std::string{yytext}); }

"="     { Print("Found OPERATOR_ASSIGN: " + std::string{yytext}); }
"=="    { Print("Found OPERATOR_EQUAL: " + std::string{yytext}); }
"==="   { Print("Found OPERATOR_STRICT_EQUAL: " + std::string{yytext}); }

"!"     { Print("Found OPERATOR_NOT: " + std::string{yytext}); }
"!="    { Print("Found OPERATOR_NOT_EQUAL: " + std::string{yytext}); }
"!=="   { Print("Found OPERATOR_STRICT_NOT_EQUAL: " + std::string{yytext}); }

"=>"    { Print("Found ARROW_FUNCTION: " + std::string{yytext}); }

">"     { Print("Found OPERATOR_GREATER_THAN: " + std::string{yytext}); }
">="    { Print("Found OPERATOR_GREATER_THAN_EQUAL: " + std::string{yytext}); }
">>"    { Print("Found OPERATOR_SHIFT_RIGHT: " + std::string{yytext}); }
">>="   { Print("Found OPERATOR_ASSIGN_SHIFT_RIGHT: " + std::string{yytext}); }
">>>"   { Print("Found OPERATOR_UNSIGNED_SHIFT_RIGHT: " + std::string{yytext}); }
">>>="  { Print("Found OPERATOR_ASSIGN_UNSIGNED_SHIFT_RIGHT: " + std::string{yytext}); }

"<"     { Print("Found OPERATOR_LESS_THAN: " + std::string{yytext}); }
"<="    { Print("Found OPERATOR_LESS_THAN_EQUAL: " + std::string{yytext}); }
"<<"    { Print("Found OPERATOR_SHIFT_LEFT: " + std::string{yytext}); }
"<<="   { Print("Found OPERATOR_ASSIGN_SHIFT_LEFT: " + std::string{yytext}); }

"/"     { Print("Found OPERATOR_DIVIDE: " + std::string{yytext}); }
"/="    { Print("Found OPERATOR_ASSIGN_DIVIDE: " + std::string{yytext}); }

"^"     { Print("Found OPERATOR_BITWISE_XOR: " + std::string{yytext}); }
"^="    { Print("Found OPERATOR_ASSIGN_BITWISE_XOR: " + std::string{yytext}); }

"~"     { Print("Found OPERATOR_BITWISE_NOT: " + std::string{yytext}); }

"&"     { Print("Found OPERATOR_BITWISE_AND: " + std::string{yytext}); }
"&="    { Print("Found OPERATOR_ASSIGN_BITWISE_AND: " + std::string{yytext}); }
"&&"    { Print("Found OPERATOR_LOGICAL_AND: " + std::string{yytext}); }
"&&="   { Print("Found OPERATOR_ASSIGN_LOGICAL_AND: " + std::string{yytext}); }

"|"     { Print("Found OPERATOR_BITWISE_OR: " + std::string{yytext}); }
"|="    { Print("Found OPERATOR_ASSIGN_BITWISE_OR: " + std::string{yytext}); }
"||"    { Print("Found OPERATOR_LOGICAL_OR: " + std::string{yytext}); }
"||="   { Print("Found OPERATOR_ASSIGN_LOGICAL_OR: " + std::string{yytext}); }

"["     { Print("Found BRACKET_OPEN: " + std::string{yytext}); }
"]"     { Print("Found BRACKET_CLOSE: " + std::string{yytext}); }
"("     { Print("Found PARENTHESIS_OPEN: " + std::string{yytext}); }
")"     { Print("Found PARENTHESIS_CLOSE: " + std::string{yytext}); }
"{"     { Print("Found BRACE_OPEN: " + std::string{yytext}); }
"}"     { Print("Found BRACE_CLOSE: " + std::string{yytext}); }

":"     { Print("Found COLON: " + std::string{yytext}); }
","     { Print("Found COMMA: " + std::string{yytext}); }
"."     { Print("Found DOT: " + std::string{yytext}); }
"..."   { Print("Found DOTS_ELLIPSIS: " + std::string{yytext}); }
";"     { Print("Found SEMICOLON: " + std::string{yytext}); }

"@"     { Print("Found DECORATOR_AT: " + std::string{yytext}); }


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
    std::sscanf(buffer + 2, "%x", &currentInteger);
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
    BEGIN(INITIAL);
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
    BEGIN(INITIAL);
}

\` {
    currentString.clear();
    BEGIN(TEMPLATE_STR);
}
<TEMPLATE_STR>[^\`\\]+ {
    currentString += yytext;
}
<TEMPLATE_STR>\\\` {
    currentString += "\`";
}
<TEMPLATE_STR>\` {
    PrintStringLiteral(currentString);
    BEGIN(INITIAL);
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
}
{INVALID_UNDERLINE_DEC_INT_LIT} {
    PrintError("illegal underscore in decimal number", yylineno);
}

{DEC_INT_LIT}(\.|(\.?{EXPONENT_PART})) { /* Decimal literal */
    std::string number_string = yytext;
    RemoveCharacterFromString(number_string, '_');
    std::from_chars(number_string.c_str(), number_string.c_str() + number_string.size(), currentFloatingPoint);
    PrintFloatingPointLiteral(currentFloatingPoint);
}
{INVALID_UNDERLINE_DEC_INT_LIT}(_*)(\.|(\.?{INVALID_UNDERLINE_EXPONENT_PART})) {
    PrintError("illegal underscore in decimal number", yylineno);
}

({DEC_INT_LIT})?\.{DEC_DIGITS}({EXPONENT_PART})? {
    std::string number_string = yytext;
    RemoveCharacterFromString(number_string, '_');
    std::from_chars(number_string.c_str(), number_string.c_str() + number_string.size(), currentFloatingPoint);
    PrintFloatingPointLiteral(currentFloatingPoint);
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
}
0(_*)[xX](_*){INVALID_UNDERLINE_HEX_DIGITS} {
    PrintError("illegal underscore in hexadecimal number", yylineno);
}
0[xX][^1-9a-fA-F[:space:]]+ {
    PrintError("hexadecimal digit expected", yylineno);
}


[[:alpha:]_$][[:alnum:]_$]* { Print("Found identifier: " + std::string{yytext}); }


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
