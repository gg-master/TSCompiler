let a: number[] = [1, 2, 3, 4];
// a = [1,2,3,,] // semantic error;

a[0] = 4; Console.log("a = " + a);
// a[0] = "asd" // semantic error;

let b: string[] = ["1", "2", "3"];
let c: undefined[] = [,,,];
let d: any[] = [1,,,2,,,3,,"asd", undefined, null];

Console.log("a (l: " + a.length + ") = " + a)
Console.log("b (l: " + b.length + ") = " + b)
Console.log("c (l: " + c.length + ") = " + c)
Console.log("d (l: " + d.length + ") = " + d)

