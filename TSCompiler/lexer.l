%option noyywrap
%option never-interactive

%{
    #include <stdio.h>
    #include <string.h>
    #include <typeinfo>
    #include <iostream>

    using namespace std;

    char* removeUnderline(const char* str);

%}

%x STR_DOUBLE_Q
%x STR_SINGLE_Q
%x STR_BACK_Q

%x COMMENT
%x COMMENTONE

DIGIT [0-9]

%%

%{
    std::string currentString;
    std::string currentComment;
%}

abstract    { printf("Found KW_ABSTRACT: %s\n", yytext); } 
any         { printf("Found TYPE_ANY: %s\n", yytext); } 
as          { printf("Found KW_AS: %s\n", yytext); } 
boolean     { printf("Found TYPE_BOOLEAN: %s\n", yytext); } 
break       { printf("Found KW_BREAK: %s\n", yytext); } 
case        { printf("Found KW_CASE: %s\n", yytext); } 
catch       { printf("Found KW_CATCH: %s\n", yytext); } 
class       { printf("Found KW_CLASS: %s\n", yytext); } 
continue    { printf("Found KW_CONTINUE: %s\n", yytext); } 
const       { printf("Found KW_CONST: %s\n", yytext); } 
constructor { printf("Found KW_CONSTRUCTOR: %s\n", yytext); } 
debugger    { printf("Found KW_DEBUGGER: %s\n", yytext); } 
declare     { printf("Found KW_DECLARE: %s\n", yytext); } 
default     { printf("Found KW_DEFAULT: %s\n", yytext); } 
delete      { printf("Found KW_DELETE: %s\n", yytext); } 
do          { printf("Found KW_DO: %s\n", yytext); } 
else        { printf("Found KW_ELSE: %s\n", yytext); } 
enum        { printf("Found KW_ENUM: %s\n", yytext); } 
export      { printf("Found KW_EXPORT: %s\n", yytext); } 
extends     { printf("Found KW_EXTENDS: %s\n", yytext); } 
false       { printf("Found KW_FALSE: %s\n", yytext); } 
finally     { printf("Found KW_FINALLY: %s\n", yytext); } 
for         { printf("Found KW_FOR: %s\n", yytext); } 
from        { printf("Found KW_FROM: %s\n", yytext); } 
function    { printf("Found KW_FUNCTION: %s\n", yytext); } 
get         { printf("Found KW_GET: %s\n", yytext); } 
if          { printf("Found KW_IF: %s\n", yytext); } 
implements  { printf("Found KW_IMPLEMENTS: %s\n", yytext); } 
import      { printf("Found KW_IMPORT: %s\n", yytext); } 
in          { printf("Found KW_IN: %s\n", yytext); } 
infer       { printf("Found KW_INFER: %s\n", yytext); } 
instanceof  { printf("Found KW_INSTANCEOF: %s\n", yytext); } 
interface   { printf("Found KW_INTARFACE: %s\n", yytext); } 
is          { printf("Found KW_IS: %s\n", yytext); } 
keyof       { printf("Found KW_KEYOF: %s\n", yytext); } 
let         { printf("Found KW_LET: %s\n", yytext); } 
module      { printf("Found KW_MODULE: %s\n", yytext); } 
namespace   { printf("Found KW_NAMESPACE: %s\n", yytext); } 
never       { printf("Found TYPE_NEVER: %s\n", yytext); } 
new         { printf("Found KW_NEW: %s\n", yytext); } 
null        { printf("Found KW_NULL: %s\n", yytext); } 
number      { printf("Found TYPE_NUMBER: %s\n", yytext); } 
object      { printf("Found TYPE_OBJECT: %s\n", yytext); } 
of          { printf("Found KW_OF: %s\n", yytext); } 
package     { printf("Found KW_PACKAGE: %s\n", yytext); } 
private     { printf("Found KW_PRIVATE: %s\n", yytext); } 
protected   { printf("Found KW_PROTECTED: %s\n", yytext); } 
public      { printf("Found KW_PUBLIC: %s\n", yytext); } 
readonly    { printf("Found KW_READONLY: %s\n", yytext); } 
require     { printf("Found KW_REQUIRE: %s\n", yytext); } 
return      { printf("Found KW_RETURN: %s\n", yytext); } 
set         { printf("Found KW_SET: %s\n", yytext); } 
static      { printf("Found KW_STATIC: %s\n", yytext); } 
string      { printf("Found TYPE_STRING: %s\n", yytext); } 
super       { printf("Found KW_SUPER: %s\n", yytext); } 
switch      { printf("Found KW_SWITCH: %s\n", yytext); }
symbol      { printf("Found TYPE_SYMBOL: %s\n", yytext); }
this        { printf("Found KW_THIS: %s\n", yytext); }
throw       { printf("Found KW_THROW: %s\n", yytext); }
true        { printf("Found KW_TRUE: %s\n", yytext); }
try         { printf("Found KW_TRY: %s\n", yytext); }
type        { printf("Found KW_TYPE: %s\n", yytext); }
typeof      { printf("Found KW_TYPEOF: %s\n", yytext); }
unique      { printf("Found KW_UNIQUE: %s\n", yytext); } 
unknown     { printf("Found TYPE_UNKNOWN: %s\n", yytext); } 
var         { printf("Found KW_VAR: %s\n", yytext); }
while       { printf("Found KW_WHILE: %s\n", yytext); }
undefined   { printf("Found KW_UNDEFINED: %s\n", yytext); }

"?"     { printf("Found OPERATOR_OPT_PARAM: %s\n", yytext); }
"%"     { printf("Found OPERATOR_MOD: %s\n", yytext); }
"%="    { printf("Found OPERATOR_MOD_ASSIGNMENT: %s\n", yytext); }
"+"     { printf("Found OPERATOR_PLUS: %s\n", yytext); }
"+="    { printf("Found OPERATOR_PLUS_ASSIGNMENT: %s\n", yytext); }
"++"    { printf("Found OPERATOR_INCREMENT: %s\n", yytext); }
"-"     { printf("Found OPERATOR_MINUS: %s\n", yytext); }
"-="    { printf("Found OPERATOR_MINUS_ASSIGNMENT: %s\n", yytext); }
"--"    { printf("Found OPERATOR_DICREMENT: %s\n", yytext); }
"*"     { printf("Found OPERATOR_MUL: %s\n", yytext); }
"*="    { printf("Found OPERATOR_MUL_ASSIGNMENT: %s\n", yytext); }
"="     { printf("Found OPERATOR_ASSIGNMENT: %s\n", yytext); }
"=="    { printf("Found OPERATOR_EQUAL: %s\n", yytext); }
"==="   { printf("Found OPERATOR_EQUAL_BY_TYPE_AND_VALUE: %s\n", yytext); }
"!"     { printf("Found OPERATOR_BIT_NOT: %s\n", yytext); }
"!="    { printf("Found OPERATOR_NOT_EQUAL: %s\n", yytext); }
"!=="   { printf("Found OPERATOR_NOT_EQUAL_BY_TYPE_AND_VALUE: %s\n", yytext); }
">"     { printf("Found OPERATOR_MORE: %s\n", yytext); }
">="    { printf("Found OPERATOR_MORE_OR_EQUAL: %s\n", yytext); }
"<"     { printf("Found OPERATOR_LESS: %s\n", yytext); }
"<="    { printf("Found OPERATOR_LESS_OR_EQUA: %s\n", yytext); }
"/"     { printf("Found OPERATOR_DIV: %s\n", yytext); }
"/="    { printf("Found OPERATOR_DIV_ASSIGNMENT: %s\n", yytext); }
"^"     { printf("Found OPERATOR_BIT_XOR: %s\n", yytext); }
"~"     { printf("Found UNARY_BITWISE_NOT: %s\n", yytext); }
"&"     { printf("Found OPERATOR_AMPERSAND: %s\n", yytext); }
"&&"    { printf("Found OPERATOR_AND: %s\n", yytext); }
"|"     { printf("Found OPERATOR_BIT_OR: %s\n", yytext); }
"||"    { printf("Found OPERATOR_OR: %s\n", yytext); }
"["     { printf("Found LEFT_SQUARE_BRACKET: %s\n", yytext); }
"]"     { printf("Found RIGHT_SQUARE_BRACKET: %s\n", yytext); }
"("     { printf("Found LEFT_ROUND_BRACKET: %s\n", yytext); }
")"     { printf("Found RIGHT_ROUND_BRACKET: %s\n", yytext); }
"{"     { printf("Found LEFT_FIGURE_BRACKET: %s\n", yytext); }
"}"     { printf("Found RIGHT_FIGURE_BRACKET: %s\n", yytext); }
":"     { printf("Found COLON: %s\n", yytext); }
","     { printf("Found COMMA: %s\n", yytext); }
"."     { printf("Found DOT: %s\n", yytext); }
";"     { printf("Found SEMICOLON: %s\n", yytext); }
"n"     { printf("Found OPERATOR_ENTER: \\n\n", yytext); }

\"  {
        currentString.clear();
        BEGIN(STR_DOUBLE_Q);
    }
<STR_DOUBLE_Q,STR_SINGLE_Q,STR_BACK_Q>\\[xX][^0-9a-fA-F] { printf("invalid hexadecimal escape sequence. \n"); }
<STR_DOUBLE_Q,STR_SINGLE_Q,STR_BACK_Q>\\[xX][0-9a-fA-F]{1,2} {
    char* end;
    long int num = strtol(yytext+2, &end, 16);
    char asciiChar = static_cast<char>(num);
    currentString.push_back(asciiChar);
    }
<STR_DOUBLE_Q,STR_SINGLE_Q>\\[0-7]{1,2} {
    char* end;
    long int num = strtol(yytext+1, &end, 8);
    char asciiChar = static_cast<char>(num);
    currentString.push_back(asciiChar);
    }
<STR_DOUBLE_Q,STR_SINGLE_Q>[^\\\"\'\n]+     { currentString += yytext; }
<STR_DOUBLE_Q,STR_SINGLE_Q,STR_BACK_Q>\\n   { currentString += "\n"; }
<STR_DOUBLE_Q,STR_SINGLE_Q,STR_BACK_Q>\\t   { currentString += "\t"; }
<STR_DOUBLE_Q,STR_SINGLE_Q,STR_BACK_Q>\\\\  { currentString += "\\"; }
<STR_DOUBLE_Q,STR_SINGLE_Q,STR_BACK_Q>\\\"  { currentString += "\""; }
<STR_DOUBLE_Q,STR_SINGLE_Q,STR_BACK_Q>\\\'  { currentString += "\'"; }
<STR_DOUBLE_Q>\" {
    printf("Detected string literal: %s\n", str);
    BEGIN(INITIAL);
    }
<STR_DOUBLE_Q,STR_SINGLE_Q>\n {
    printf(invalid line break inside string literal.\n");
    exit(1);
    }
<STR_DOUBLE_Q,STR_SINGLE_Q,STRINGB><<EOF>> {
    printf("unterminated string literal.\n");
    exit(1);
    }


\' {
    BEGIN(STR_SINGLE_Q);
    str[0] = 0;
    }
<STR_SINGLE_Q>\' {
    printf("Detected string literal : %s\n", str);
    BEGIN(INITIAL);
    }

// One-line comment
\/\/ {BEGIN(ONELINECOMMENT);}
<ONELINECOMMENT>[^\n]* {}
<ONELINECOMMENT>\n {BEGIN(INITIAL);}
<ONELINECOMMENT><<EOF>> {BEGIN(INITIAL);}

// Multi-line comment
"/*" {BEGIN(MULTILINECOMMENT);}
<MULTILINECOMMENT>[^*]+ {}
<MULTILINECOMMENT>"*"+[^*/] {}
<MULTILINECOMMENT>"*"+"/" {BEGIN(INITIAL);}
<MULTILINECOMMENT><<EOF>> {
    printf("ERROR! No closing comment at the end. \n");
    exit(1);
    }


%%

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }
    
	FILE* output_file = fopen("output.txt", "w");
	if (!output_file) {
		printf("Error: could not create output file\n");
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
