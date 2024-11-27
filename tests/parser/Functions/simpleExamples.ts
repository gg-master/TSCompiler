// 1
function f() {}
// 2
function f(a, b, c) {}
// 3
function f(a: number,): void {}
// 4
function f(a: number, b: string,): number { return 1 }
// 5
function f(a: number[], b: [1, 2, 3]): (undefined) {}
// 6
function f(...a) {}
// 7
function f(...a: number[]): [] { return []}
// 8 
function f(a, b, ...c) {}
// 9
function

f

(

a
    :
        (
        [
            number
            ,
            string
        ]
        )
)
:
number

{
return 1;
}
