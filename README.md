# TSCompiler 

The project can compile simple TypeScript programs to Java bytecode.

In fact, the capabilities of this compiler are extremely limited and this 
project is not a full-fledged TypeScript compiler and contains many 
simplifications and limitations.

Lexical analysis is implemented using Flex. Parsing is implemented using Bison.
Although the grammar rules are similar to TypeScript, they have their own limitations in this project. 

* Automatic semicolon insertion is implemented.

Opportunities:
1) Data types: number, string, boolean, null, undefined;
2) Type annotations are required and, in addition to data types, you can use any and void;
3) Variable declarations var, let, const;
4) Arithmetic operations + (unary and binary), \ - (unary and binary), *, /, ++ (post and pref), -- (post and pref);
4) Comparison operations==, !=, >, <, >=, <=;
5) Assignment operations=, +=, -=, *=, /=;
6) Logical operations !, &&, ||;
7) IfElse and ternary operations;
8) do-while, while, for loops;
9) Arrays;
10) Functions;
11) Special statistical input / output functions from the Console class (not available in TypeScript)

Some examples you can find [here](https://github.com/gg-master/TSCompiler/tree/compiler-impl/tests/final).

__Attention, there may be bugs ! :)__