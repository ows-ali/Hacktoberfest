/*
  Problem Name: Queen's Attack II
  Problem link: https://www.hackerrank.com/challenges/queens-attack-2/problem
*/

'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.split('\n');
    main();
});

function readLine() {
    return inputString[currentLine++];
}

function sameDiag1(x1, y1, x2, y2) {
    return y1-x1 === y2-x2;
}

function sameDiag2(x1, y1, x2, y2) {
    return y1+x1 === y2+x2;
}

function sameRow(y1, y2) {
    return y1 === y2;
}

function sameCol(x1, x2) {
    return x1 === x2;
}

function dist(x1, y1, x2, y2) {
    return Math.floor(Math.sqrt((x1-x2)**2 + (y1-y2)**2)*Math.SQRT1_2);
}

function queensAttack(n, k, r_q, c_q, obstacles) {
    if(n === 0) return 0;
    const x = c_q - 1, y = r_q - 1;
    const minD = {
        a: Math.min(x, n-y-1),
        b: n-1-y,
        c: Math.min(n-x-1, n-y-1),
        d: x,
        e: n-1-x,
        f: Math.min(x, y),
        g: y,
        h: Math.min(n-x-1, y),
    }
    obstacles.forEach(([y1, x1]) => {
        x1 = x1 - 1;
        y1 = y1 - 1;
        const distance = dist(x1, y1, x, y) - 1;
        if(sameRow(y, y1)) {
            x1 < x ? minD.d = Math.min(minD.d, x-x1-1) : minD.e = Math.min(minD.e, x1-x-1);
        } else if(sameCol(x, x1)) {
            y1 < y ? minD.g = Math.min(minD.g, y-y1-1) : minD.b = Math.min(minD.b, y1-y-1);
        } else if(sameDiag1(x, y, x1, y1)) {
            y1 < y ? minD.f = Math.min(minD.f, distance) : minD.c = Math.min(minD.c, distance);
        } else if(sameDiag2(x, y, x1, y1)) {
            y1 < y ? minD.h = Math.min(minD.h, distance) : minD.a = Math.min(minD.a, distance);
        }
    });
    return Object.values(minD).reduce((acc, next) => acc + next);
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);
    const firstMultipleInput = readLine().replace(/\s+$/g, '').split(' ');
    const n = parseInt(firstMultipleInput[0], 10);
    const k = parseInt(firstMultipleInput[1], 10);
    const secondMultipleInput = readLine().replace(/\s+$/g, '').split(' ');
    const r_q = parseInt(secondMultipleInput[0], 10);
    const c_q = parseInt(secondMultipleInput[1], 10);
    let obstacles = Array(k);
    for (let i = 0; i < k; i++) {
        obstacles[i] = readLine().replace(/\s+$/g, '').split(' ').map(obstaclesTemp => parseInt(obstaclesTemp, 10));
    }
    const result = queensAttack(n, k, r_q, c_q, obstacles);
    ws.write(result + '\n');
    ws.end();
}
