// can exist semantic errors here

simpleIndent; 
this;
super;
1;
1.1;
"double quoted string";
'single quoted string';
`template string`;
`template string ${1, 2, 3} template string`;
true;
false;
null;

// unary minus
-1;
    - 

        1;

// unary plus
+ 2;
+

2;

// not operator
!3; !


3;

// bitwise not
~4;

~    4;

// post increment & decrement (endl between operand is invalid)
5++; 5      ++;

6--; 6              --;

// pref increment & decrement
++7; ++

    7;

--      8; --


    8;

// binary operations
1 +         1;
1

    +   

    2;

1 - 2, 2 * 2; 3 / 3; 10 % 5

1   < 2, 2 > 3

// TODO add more exaples
