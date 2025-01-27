var my_any: any;
var my_any: any; // other type create semantic error
// var my_any: string // semantic error

my_any = 2;
my_any = "asd";

if_true_var = 4;
if_false_var = "before_if_false";

if (my_any) 
{
    var if_true_var: number = 2;
}
else
{
    var if_false_var: string = "string_if_false_var";
}

if_true_var = 10;
if_false_var = "after_if_false";

function f(fa: any) {
    var fa: any; // other type create semantic error
}

// fa = 2; // semantic error - cant find fa;