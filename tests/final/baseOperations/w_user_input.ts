Console.log("Write a: "); var a = Number(Console.readLine());
Console.log("Write b: "); var b = Number(Console.readLine());

Console.log("a = " + a + "; b = " + b + ";");
Console.log("\n\tArithmetic operations: ");
Console.log("a + b = " + (a + b));
Console.log("a - b = " + (a - b));
Console.log("a * b = " + (a * b));
Console.log("a / b = " + (a / b));

Console.log("b++ = " + b++);
Console.log("b-- = " + b--);
Console.log("++b = " + ++b);
Console.log("--b = " + --b);

Console.log("a += b " + (a += b));
Console.log("a -= b " + (a -= b));
Console.log("a *= b " + (a *= b));
Console.log("a /= b " + (a /= b));

Console.log("\n\tComprasion operations: ");
Console.log("a < b = " + (a < b));
Console.log("a > b = " + (a > b));
Console.log("a == b = " + (a == b));
Console.log("a != b = " + (a != b));
Console.log("a <= b = " + (a <= b));
Console.log("a >= b = " + (a >= b));

Console.log("\n\tLogical operations: ");
Console.log("!a = " + !a);
Console.log("!b = " + !b);
Console.log("a || b = " + (a || b));
Console.log("a && b = " + (a && b));
Console.log("a > b ? a : b = " + (a > b ? a : b));
