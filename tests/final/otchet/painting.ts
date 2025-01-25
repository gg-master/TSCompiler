Console.log("row: ")
var row: number = Number(Console.readLine());
Console.log("col: ")
var col: number = Number(Console.readLine());
Console.log("color: ")
var color: number = Number(Console.readLine());

var matrix: number[][] = [
    [0,0,0,0,0,0,0,0,0,0],
    [0,1,0,1,1,1,1,1,1,0],
    [0,1,0,1,0,0,0,0,1,0],
    [0,1,0,1,0,1,1,0,1,0],
    [0,1,0,1,0,0,1,0,1,0],
    [0,1,0,1,0,0,1,0,1,0],
    [0,1,0,1,1,1,1,0,1,0],
    [0,1,0,0,0,0,0,0,1,0],
    [0,1,1,1,1,1,1,1,1,0],
    [0,0,0,0,0,0,0,0,0,0]
]

for (let i: number = 0; i < matrix.length; i++) {
    Console.log(matrix[i]);
}
Console.log("")

paint(row, col, color);

function paint(row: number, col: number, value: number): void {
    if (matrix[row][col] == 0) {
        matrix[row][col] = value;

        paint(row - 1, col, value);
        paint(row, col - 1, value);
        paint(row + 1, col, value);
        paint(row, col + 1, value);
    }
}

for (let i: number = 0; i < matrix.length; i++) {
    Console.log(matrix[i]);
}