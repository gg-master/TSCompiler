Console.log("--- DO-WHILE ---")
do {
    Console.log("Type passwd: ")
    var a: string = Console.readLine();
} while (a != "secret")

Console.log("--- WHILE ---")
let counter: number = 10;
while(counter > 0) 
{
    Console.log("counter: " + counter--);   
}

Console.log("--- FOR v1 ---")
for (counter = 10; counter < 20; counter += 2)
{
    Console.log("counter: " + counter)
}

Console.log("--- FOR v2 ---")
for (let a: number = counter; a > 0; a -= 3)
{
    Console.log("a: " + a)
}