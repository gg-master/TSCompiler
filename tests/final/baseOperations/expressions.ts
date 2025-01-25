// basicOperations(100_000, 999_999_999);
// basicOperations(12.5, 0.5);
// basicOperations(-100, -0.5);
// basicOperations(100, "asd");
// basicOperations(101, "80");
// basicOperations(101, "80.89");
// basicOperations(102, true);
// basicOperations(103, false);
// basicOperations(0, null);
// basicOperations(104, null);
// basicOperations(105, undefined);
// basicOperations("106", "000");
// basicOperations("107", "asd");
// basicOperations("qwerty", "asd");
// basicOperations("qwerty", "asd");
// basicOperations("100", true);
// basicOperations("asd", false);
// basicOperations("123", null);
// basicOperations("", null);
// basicOperations("0", null);
// basicOperations("100.102", null);
// basicOperations("qwerty", undefined);
// basicOperations(true, true);
// basicOperations(true, false);
// basicOperations(false, false);
// basicOperations(false, -213.312);
// basicOperations(true, -213.312);
// basicOperations(true, null);
// basicOperations(true, undefined);
// basicOperations(true, "123");
// basicOperations(true, "asdqwerty");
// basicOperations(null, undefined);
// basicOperations(null, null);
// basicOperations(null, 0);
// basicOperations(null, "");
// basicOperations(null, 23);
// basicOperations(null, "asd");
// basicOperations(null, "123");
// basicOperations(null, false);
// basicOperations(null, true);
// basicOperations(null, true);
// basicOperations(undefined, undefined);
// basicOperations(undefined, null);
// basicOperations(undefined, true);
// basicOperations(undefined, "asd");
// basicOperations(undefined, "123");
// basicOperations(undefined, 123);
// basicOperations(undefined, 123.32);
// basicOperations(0, [1, 2, 3])
// basicOperations(123, [1, 2, 3])
// basicOperations("123", [1, 2, 3])
// basicOperations("0", [1, 2, 3])
// basicOperations(true, [1, 2, 3])
// basicOperations(false, [1, 2, 3])
// basicOperations(null, [1, 2, 3])
// basicOperations(undefined, [1, 2, 3])
// basicOperations([1, 2, 3], [1, 2, 3])
// basicOperations([], [1, 2, 3])
// basicOperations([3, 2, 1], [1, 2, 3])
// basicOperations([3, 2], [1, 2, 3])
// basicOperations([3, 2, 2, 0], [1, 2, 3])
basicOperations(1, 2)
basicOperations(1, 2)



function basicOperations(a: any, b: any): any {
    Console.log("\t---- TEST ----");
    Console.log("a = " + a + "; b = " + b + ";\n");
    Console.log("a + b = " + (a + b));
    Console.log("a - b = " + (a - b));
    Console.log("a * b = " + (a * b));
    Console.log("a / b = " + (a / b));

    Console.log("a < b = " + (a < b));
    Console.log("a > b = " + (a > b));
    Console.log("a == b = " + (a == b));
    Console.log("a != b = " + (a != b));
    Console.log("a <= b = " + (a <= b));
    Console.log("a >= b = " + (a >= b));

    Console.log("!a = " + !a);
    Console.log("!b = " + !b);
    Console.log("!0 = " + !0);

    Console.log("a || b = " + (a || b));
    Console.log("a && b = " + (a && b));
    Console.log("a > b ? a : b = " + (a > b ? a : b));

    Console.log("a, b = " + (a, b));

    Console.log("b++ = " + b++);
    Console.log("b-- = " + b--);
    Console.log("++b = " + ++b);
    Console.log("--b = " + --b);

    Console.log("a += 2 " + (a += 2));
    Console.log("a -= 2 " + (a -= 2));
    Console.log("a *= 2 " + (a *= 2));
    Console.log("a /= 2 " + (a /= 2));
}
