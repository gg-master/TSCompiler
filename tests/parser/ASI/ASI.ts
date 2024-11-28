// ECMA rules see here: https://262.ecma-international.org/14.0/#sec-automatic-semicolon-insertion

/*
1. When, as the source text is parsed from left to right, a token 
(called the offending token) is encountered that is not allowed by any 
production of the grammar, then a semicolon is automatically inserted before 
the offending token if one or more of the following conditions is true:
*/


// 1.1. The offending token is separated from the previous token by at least one LineTerminator. 
1 + 1
2

// 1.2. The offending token is }
if (true) { 1 + 1 }
{ } // simplified ASI logic here insert ';' anyway

// 1.3. The previous token is ) and the inserted semicolon would then be parsed 
// as the terminating semicolon of a do-while statement (14.7.2).

do 1; while (true)
do 1 + 1; while (true) 1
do 1 + 1; while (true) 1 + 2;
do 1 + 2; while (true); // no ASI here

/*
2. When, as the source text is parsed from left to right, a token is encountered 
that is allowed by some production of the grammar, but the production is a 
restricted production and the token would be the first token for a terminal 
or nonterminal immediately following the annotation “[no LineTerminator here]” 
within the restricted production (and therefore such a token is called a 
restricted token), and the restricted token is separated from the previous 
token by at least one LineTerminator, then a semicolon is automatically 
inserted before the restricted token.
*/

// 2.1. Post increments & decrements

// will be interpreted as "1; ++2;"" (without syntax erorr)
1
++2;

// 1; --2;
1

    --2;

// 2.2. continue [no LineTerminator here] LabelIdentifier

a: while(true) {
    // no ASI here
    continue  a;
}

a: while(true) {
    // will be parsed as "continue; a;" 
    continue 
    a;
}

// 2.3. break [no LineTerminator here] LabelIdentifier

a: while(true) {
    // no ASI here
    break a;
}

a: while(true) {
    // will be parsed as "break; a;" 
    break 
    a;
}

// 2.4. return [no LineTerminator here] Expression

function f() { return 1; } // ok

function f() {
    // will be parsed as "return; 1;" 
    return 
    1; 
}

/* Special case: However, there is an additional overriding condition on the 
preceding rules: a semicolon is never inserted automatically if the semicolon 
would then be parsed as an empty statement or if that semicolon would become 
one of the two semicolons in the header of a for statement 
*/

// Example 1. 
// for (a; b
//     c
// )

// Example 2. 
// if (a > b)
// else c = d;

/*
3. When, as the source text is parsed from left to right, the end of the input 
stream of tokens is encountered and the parser is unable to parse the input 
token stream as a single instance of the goal nonterminal, then a semicolon is 
automatically inserted at the end of the input stream.
*/

end_of_file