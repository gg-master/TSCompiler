/* __________________________________________________ Варианты стандартного написания __________________________________________________ */

var variables = 100.77;
const value = 0.5, double = 100;
let mix = 100, plus = 0, minus = 0, multiply = 0, divide = 0, mod = 0, incremented = 0, decremented = 0;
let mix_1 = 0, mix_2 = 0, mix_3 = 0, mix_4 = 0, mix_5 = 0, mix_6 = 0, mix_7 = 0, mix_8 = 0, mix_9 = 0, mix_10 = 0;
let logical: boolean = true, comparison: boolean = true;


// 1 — Выражения присваивания с арифметическими операциями
plus = 5.66 + 0.75;
minus = 5.66 - 0.75;
multiply = 5.66 * 0.75;
divide = 5.66 / 0.75;
mod = 5.66 % 0.75;
// Проверка выполнения 
// console.log(plus, minus, multiply, divide, mod);

plus = 5.66 + double;
minus = 5.66 - double;
multiply = 5.66 * double;
divide = 5.66 / double;
mod = 5.66 % double;
// Проверка выполнения 
// console.log(plus, minus, multiply, divide, mod);

plus = multiply + value;
minus = multiply - value;
multiply = multiply * value;
divide = multiply / value;
mod = multiply % value;
// Проверка выполнения 
// console.log(plus, minus, multiply, divide, mod);

plus += 0.75 + value;
minus -= 0.75 - value;
multiply *= 0.75 * value;
divide /= 0.75 / value;
mod %= 0.75 % value;
// Проверка выполнения 
// console.log(plus, minus, multiply, divide, mod);

plus += double + value;
minus -= double - value;
multiply *= double * value;
divide /= double / value;
// Проверка выполнения 
// console.log(plus, minus, multiply, divide, mod);

plus += mix_1 += ++mix_2;
minus -= mix_1 -= --mix_2;
multiply *= mix_1 *= ++mix_2;
divide /= mix_1 /= --mix_2;
mod = multiply = value;
// Проверка выполнения 
// console.log(plus, minus, multiply, divide, mod);

mix_1 += (5.66 + 0.75) - ((5.66 * 0.75) + (5.66 % 0.75));
mix_2 -= (5.66 + double) - ((5.66 * double) - (5.66 % double));
mix_3 *= (multiply + value) - ((multiply * value) * (multiply % value));
mix_4 /= (5.66 + 0.75) - ((5.66 * double) / (multiply % value));
mix_5 %= (multiply + value) - ((5.66 * double) % (5.66 % 0.75));
// Проверка выполнения 
// console.log(mix_1, mix_2, mix_3, mix_4, mix_5);


// 2 — Выражения инкремента и декремента
incremented = ++variables;
decremented = --variables;
incremented = variables++;
decremented = variables--;
// Проверка выполнения
// console.log(incremented, decremented);

incremented = 500.66 + ++variables / 100.66;
incremented = 500.66 * variables++ + 100.66;
incremented = value + ++variables % value;
incremented = value % variables++ + value;

decremented = 500.66 - --variables / 100.66;
decremented = 500.66 * variables-- - 100.66;
decremented = value - --variables % value;
decremented = value % variables-- - value;
// Проверка выполнения 
// console.log(incremented, decremented);

variables += ++plus;
variables -= --minus;
variables /= ++divide;
variables *= --multiply;
variables %= ++mod;
// Проверка выполнения 
// console.log(variables);

variables += plus++;
variables -= minus--;
variables /= divide++;
variables *= multiply--;
variables %= mod++;
// Проверка выполнения 
// console.log(variables);

mix_6 += ++variables - ((500.66 + ++variables / 100.66) + ++plus);
mix_7 -= --variables - ((500.66 - --variables / 100.66) - --minus);
mix_8 *= 500.66 * variables-- - ((500.66 * variables-- - 100.66) * --multiply);
mix_9 /= 500.66 * variables++ + ((5.66 * mod) / ++divide);
mix_10 %= value % variables-- - --minus % ((5.66 * mod) % ++mod);
// Проверка выполнения 
// console.log(mix_6, mix_7, mix_8, mix_9, mix_10);


// 3 — Выражения присваивания с логическими операторами
logical = true; logical = !true;
logical = false; logical = !false; 

logical = true && false;
logical = true || false;
logical = !true && !false;
logical = !true || !false;
logical = true && !true;
logical = true || !true;
logical = !false && false;
logical = !false || false;
// Проверка выполнения 
// console.log(logical);

logical = value && !plus;
logical = !value || !plus;
logical = value && !value;
logical = !value || !value;
logical = !plus && !plus;
logical = !plus || !plus;
// Проверка выполнения 
// console.log(logical);

logical = (!value && !plus) || !(!value && !plus);
logical = !(!value || !plus) && (!value || !plus);
logical = (value && !value) || !(value && !value);
logical = !(value || !value) && (value || !value);
logical = (!value && plus) || !(value && 5.66);
logical = !(value || plus) && (value || 5.66);
logical = !(!plus || 5.66) && (!plus || plus);
// Проверка выполнения 
// console.log(logical);


// 4 — Выражения присваивания при операции сравнения
comparison = !value > (!plus >= !(!value < !plus));
comparison = !!value < (!plus <= (!value > !plus));
comparison = value > value >= !(value < value);
comparison = value < value <= (value > value);
comparison = value > plus >= !(value < 5.66);
comparison = value < plus <= (value > 5.66);
comparison = !(plus > 5.66 <= !(plus < plus));
comparison = !(plus > 5.66 <= (plus > plus));
// Проверка выполнения 
// console.log(comparison);

comparison = !value != (!plus === !(!value !== !plus));
comparison = !!value != (!plus === (!value !== !plus));
comparison = value != value === !(value !== value);
comparison = value != value === (value !== value);
comparison = value != plus === !(value == plus);
comparison = value != plus === (plus == value);
comparison = !(plus != 5.66 === !(plus !== plus));
comparison = !(plus != 5.66 === (plus !== plus));
// Проверка выполнения
// console.log(comparison);


// 5 — Выражения присваивания с побитовыми операциями
let bit_1 = value & ~++variables << 100.66;
let bit_2 = value >> ~variables++ | 100.66;
let bit_3 = value ^ ~++variables % 100.66;

let bit_4 = value & ~--variables << 100.66;
let bit_5 = value >> ~variables-- | 100.66;
let bit_6 = value ^ ~--variables * 100.66;

let bit_7 = ~++variables << 100.66;
let bit_8 = ~--variables >> 100.66;
let bit_9 = ~variables-- & value;
let bit_10 = value | ~variables++;
let bit_11 = value ^ variables++ & 100.66;

let mix_bit_1 = ~++variables + ++minus + ((value & ~--variables << ~100.66) + ++plus);
let mix_bit_2 = ~--variables - --minus - ((value >> ~variables-- | 100.66) - --minus);
let mix_bit_3 = ((variables-- * --minus) * value) >> ~100.66;
let mix_bit_4 = ((variables-- % --minus) % value) << 100.66;
// Проверка выполнения 
// console.log(bit_1, bit_2, bit_3, bit_4, bit_5, bit_6, bit_7, bit_8, bit_9, bit_10, bit_11);
// console.log(mix_bit_1, mix_bit_2, mix_bit_3, mix_bit_4);
