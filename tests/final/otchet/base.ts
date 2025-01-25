var a: string = Console.readLine();

function f(): boolean {
    Console.log("function f call");
    return true    
}

if (Number(a) < 25 && f())
{
    Console.log("here&&true");
}
Console.log("---");

if (Number(a) > 40 || f())
{
    Console.log("here||true");
}