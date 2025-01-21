function f(): void {}
// function f(): void {} // semantic error (dublicate)

function f1(): void { return undefined }
function f2(): void { return }
// function f3(): void { return 1 } // semantic error

function f4(): undefined {}
function f5(): undefined { return }
// function f6(): undefined { return "asd" } // semantic error

// function f_undef(): undefined { return f(); } // semantic error

function f_any(a: any): any {
    if (a) {
        return 1;
    }
    if (a > 10) {
        return "a > 10"
    }
    if (!a) {
        return true;
    }
    return;
}

// semantic error - lack return;
function f_lack_return(a: any): number {
    if (a) { return 1; } 
}

// semantic error
function f_no_return_w_emty_body(): number {}
function f_no_return(): string { var a: number = 2; }

function f_number_return(): number
{
    if (false) {
        return 2;
    } 
    if (!false)
    {
        return 3;
    }
    // return "asd" //semantic error
    // return // semantic error
    return 0;
}

function multiple_return(): any {
    return 1;
    return "asd";
    return;
}