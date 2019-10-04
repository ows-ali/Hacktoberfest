
// Problem from project euler: 2
// https://www.projecteuler.net/problem=2

"use strict";

const MAXIMUM_VALUE = 4000000
const EXPECTED_SOLUTION = 4613732;

function Even_Fibonacci_Numbers() {
    let sum = 0;

    let f = 0;
    let i = 1;

    while (i < MAXIMUM_VALUE) {
        if (Is_Even(i)) {
            sum += i;
        }

        i = i + f;
        f = i - f;
    }

    return sum;
}

function Is_Even(i) {
    return i % 2 !== 0;
}

console.log(Even_Fibonacci_Numbers());
console.log(Even_Fibonacci_Numbers() === EXPECTED_SOLUTION);
