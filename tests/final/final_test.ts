
var float_number: number = 1.2;
var float_number2: number = 0.5;
var int_number: number = 1;

Console.log(int_number + float_number);
Console.log(int_number - float_number);
Console.log(int_number * float_number);
Console.log(int_number / float_number);

Console.log("\n");

var var1: number = 1;
var var2: number = 0;

var or_result1: any = true || false || true;
Console.log(or_result1)
var or_result2: any = false || ++var2;
Console.log(or_result2)
Console.log("var2:" + var2);

Console.log("\n");

var and_result1: any = true && var1++;
Console.log(and_result1)
Console.log("var1: " + var1);

var and_result2: any = false && ++var2;
Console.log(and_result2)
Console.log("var2: " + var2)


Console.log("\n");

var int_number: number = 1;
var str: string = "asd";
var arr: number[] = [1, 2, 3];
function f(i: number, s: string, arr: number[]): void {
    Console.log("f_i: " + i);
    Console.log("f_s: " + s);
    Console.log("f_arr: " + arr);

    Console.log("f_i_changed: " + ++i)

    s += "123"
    Console.log("f_s_changed: " + s);

    arr[0] = 4;
    Console.log("f_arr_changed: " + arr);

}
Console.log("i before f(): " + int_number);
Console.log("s before f(): " + str);
Console.log("arr before f(): " + arr);
Console.log("------");
f(int_number, str, arr);
Console.log("------");
Console.log("i after f(): " + int_number);
Console.log("s after f(): " + str);
Console.log("arr after f(): " + arr);

function fibonacci(n: number): number {
    if (n < 0) {
        Console.log("Input must be a non-negative integer.");
        return 0;
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

for (var i: number = 0; i < 10; i++) {
    Console.log(`Fibonacci(` + i + `)  = ` + fibonacci(i));
}
