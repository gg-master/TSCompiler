function typed_f(a: string, b: number[]): void {
    Console.log(
        "> typed_f print: " + a + 
        "; b (" + b.length + "): " + b
    );
}

function any_f(a: any, b: any): any {
    Console.log("> any_f print: a: " + a + "; b: " + b);
    typed_f(a, b);
}

// typed_f("asd", [1, 2, 3,])
// // typed_f(1, [1, 2, 3,]) // semantic error

// let a: any, b: any;
// typed_f(a, b);

any_f(1, 2);
any_f("asd", "asd");
any_f([,,,], "3 undefined");

// not_found_func() // semantic error
// any_f() // semantic error
// any_f(1, 2, 3) // semantic error