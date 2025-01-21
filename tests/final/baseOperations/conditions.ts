var true_var: boolean = true;
var false_var: boolean = false;

var a: number = 2;
var b: number = 3;

var c1: string = "123";
var c2: string = "123asd";

if (true_var) { Console.log("true condition"); }
else { /* never executed */}

if (a > b) { } else if (a != b) { Console.log(" a != b"); } else {};

if (c2 > c1) { Console.log("c2 > c1"); } else Console.log("c2 < c1");