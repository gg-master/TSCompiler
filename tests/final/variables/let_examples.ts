let let_a: number;

// let let_b: number = let_a; // semantic error 
// let let_a: number; semantic error

let_a = 123;
let_a = .121;

// let_a = "asd" // semantic error

{
    let block_scp_a: number = let_a;
}

// block_scp_a = 2; // semantc error - cant find

let let1: number, let2: string = "asd", let3: boolean = true;