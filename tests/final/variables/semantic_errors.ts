// Used before assigned error
// Ex. 1
var a: number;
var b: any = a;

// Ex. 2
a1 = a1;
var a1: string; 

// Ex. 3
let a2: boolean;
a2 = a2;

// Ex. 4
var a3: number = a3;


// Block-scoped variable used before declaration
// Ex. 1
let bs_a: any = bs_a;

// Ex. 2 (cant find variable - it`s ok)
function f(): void { let bs_a: any = bs_a; }

// Ex. 3 

bs_b = 2;
let bs_b: number = 2;

// Cannot redeclare block-scoped variable
let da: number;
let da: string;

// Subsequent variable declarations must have the same type. 
var va: any;
var va: string;

// TODO: Write headers of semantic error

var var1: number = "asd"; // types is not assignable
