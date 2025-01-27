var arr: number[] = []

Console.log("Input array length:")
let arr_length: number = Number(Console.readLine());

for (let a: number = 0; a < arr_length; a++)
{
    Console.log("Value[" + a + "]:")
    arr[a] = Number(Console.readLine());
}

Console.log(arr);
for (var i: number = 0; i < arr.length; i++) {
    for (var k: number = i + 1; k < arr.length; k++) {
        if (arr[i] > arr[k]) {
            var temp: any = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
        }
    }
}
Console.log(arr);
