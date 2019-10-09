'use strict';

const fs = require('fs');

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

// Complete the surfaceArea function below.
function surfaceArea(A) {

    // Bottom view
    let _sum = A.length * A[0].length;
    // Top view
    _sum += _sum;
    // console.log("bottomAndTop", _sum); 
    for (let row_ind in A) {
        let _row = A[row_ind];
        for (let col_ind in _row) {
            // Sum across width
            // Side view
            if (col_ind == 0)
                _sum += _row[col_ind];
            else {
                let diff = _row[col_ind - 1] - _row[col_ind];
                _sum += diff < 0 ? diff * -1 : diff;
            }
            if (col_ind == _row.length - 1)
                _sum += _row[col_ind];
            // console.log("side", _sum); 

            // Front View
            if (row_ind == 0)
                _sum += _row[col_ind];
            else {
                let diff = A[row_ind - 1][col_ind] - _row[col_ind];
                _sum += diff < 0 ? diff * -1 : diff;
            }
            if (row_ind == A.length - 1)
                _sum += _row[col_ind];
            // console.log("front", _sum); 
        }
    }
    return _sum;

}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const HW = readLine().split(' ');

    const H = parseInt(HW[0], 10);

    const W = parseInt(HW[1], 10);

    let A = Array(H);

    for (let i = 0; i < H; i++) {
        A[i] = readLine().split(' ').map(ATemp => parseInt(ATemp, 10));
    }

    let result = surfaceArea(A);

    ws.write(result + "\n");

    ws.end();
}

