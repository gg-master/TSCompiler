/* Special case: However, there is an additional overriding condition on the 
preceding rules: a semicolon is never inserted automatically if the semicolon 
would then be parsed as an empty statement or if that semicolon would become 
one of the two semicolons in the header of a for statement 
*/

// Example 1. 
for (a; b
    c
)
