let a: number[] = [1, 2, 3, 4];
// a = [1,2,3,,] // semantic error;

a[0] = 4; Console.log("a = " + a);
Console.log("a[0]++ = " + a[0]++); Console.log("a = " + a);
Console.log("a[0]-- = " + a[0]--); Console.log("a = " + a);
Console.log("++a[0] = " + ++a[0]); Console.log("a = " + a);
Console.log("--a[0] = " + --a[0]); Console.log("a = " + a);
// a[0] = "asd" // semantic error;
// a["asd"] = 1; // semantic error;
// a["asd"]; // semantic error;
// a[true]; // semantic error;
// a[null]; // semantic error;

let b: string[] = ["1", "2", "3"];
let c: undefined[] = [, , ,];
let d: any[] = [1, , , 2, , , 3, , "asd", undefined, null];

Console.log("a (l: " + a.length + ") = " + a)
Console.log("b (l: " + b.length + ") = " + b)
Console.log("c (l: " + c.length + ") = " + c)
Console.log("d (l: " + d.length + ") = " + d)

// auto increment size
var a1: any = [1, 2];
Console.log(a1);
a1[2]; // undefined
Console.log(a1);
a1[2] = 3; // 3
Console.log(a1);

a1[5]; // undefined
Console.log(a1);
a1[6] = 3; // 3
Console.log(a1);

f([])
function f(a: any): any {
    Console.log(a[0]);
    Console.log(a[0] = 12);
    Console.log(++a[0]);
}

var a: any = [1, 2, 3];
f(a);
Console.log(a);


// --- index element is any type
{
    {
        let a: number = 1;//"1";
        let arr: any[] = [1, 2, 3];
        Console.log(arr);
        arr[a] = 3;
        Console.log(arr);
        Console.log(++arr[a]);
        Console.log(arr);
    }
}
// other test
var a: any = true;//"1";
var arr: any = [1, 2, 3];
Console.log(arr);
arr[a] = 3;
Console.log(arr);
Console.log(++arr[a]);
Console.log(arr);


// multidimensional experiment

var a: any[] = []
var b: any = []

a[0] = b;
a[1] = "a_array"

a[0][0] = "Hello"
a[0][1] = "World"

Console.log(a);
Console.log(b);
