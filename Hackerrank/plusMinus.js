'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.replace(/\s*$/, '')
        .split('\n')
        .map(str => str.replace(/\s*$/, ''));

    main();
});

function readLine() {
    return inputString[currentLine++];
}

// Complete the plusMinus function below.
function plusMinus(arr) {
    let sz = arr.length;
    let p = 0, n = 0, z = 0;

    for(let i = 0; i <= sz; i++){
        if(arr[i] === 0) z++;
        else if(arr[i] > 0) p++;
        else if(arr[i] < 0) n++;
    }
    console.log(Number.parseFloat(p/sz).toFixed(6));
    console.log(Number.parseFloat(n/sz).toFixed(6));
    console.log(Number.parseFloat(z/sz).toFixed(6));
}

function main() {
    const n = parseInt(readLine(), 10);

    const arr = readLine().split(' ').map(arrTemp => parseInt(arrTemp, 10));

    plusMinus(arr);
}
