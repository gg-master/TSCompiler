function basicOperations(a: any, b: any): any {
    Console.log("\t---- TEST ----");
    Console.log("a = " + a + "; b = " + b + ";\n");
    Console.log("a + b = " + (a + b));
    Console.log("a - b = " + (a - b));
    Console.log("a * b = " + (a * b));
    Console.log("a / b = " + (a / b));
}

basicOperations(1, 2)
basicOperations(1, 2.23)
basicOperations(2.3, 2.23)
basicOperations(2.3, 1)
basicOperations(1, 0)
basicOperations(1.3, 0)
