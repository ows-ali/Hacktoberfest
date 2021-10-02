/*
 * Apple and orange problem from Hackerrank
 * in Javascript (Node.js)
 * written by PHATTARAPOL L.
 * 02/10/2021
 */

"use strict";

process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;

process.stdin.on("data", function (inputStdin) {
  inputString += inputStdin;
});

process.stdin.on("end", function () {
  inputString = inputString.split("\n");

  main();
});

function readLine() {
  return inputString[currentLine++];
}

/*
 * Complete the 'countApplesAndOranges' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER s
 *  2. INTEGER t
 *  3. INTEGER a
 *  4. INTEGER b
 *  5. INTEGER_ARRAY apples
 *  6. INTEGER_ARRAY oranges
 */

function countApplesAndOranges(s, t, a, b, apples, oranges) {
  // Write your code here

  // Verification using given constraints
  if (
    s < 1 ||
    s > 100000 ||
    t < 1 ||
    t > 100000 ||
    a < 1 ||
    a > 100000 ||
    b < 1 ||
    b > 100000
  ) {
    return console.error("invalid input");
  }

  apples.map((distance) => {
    if (distance < -100000 || distance > 100000) {
      return console.error("invalid distance at apple" + distance);
    }
  });
  oranges.map((distance) => {
    if (distance < -100000 || distance > 100000) {
      return console.error("invalid distance at orange" + distance);
    }
  });

  // Add to apples and oranges array

  const whereAppleFalls = apples.map((distance) => {
    return distance + a;
  });

  const whereOrangeFalls = oranges.map((distance) => {
    return distance + b;
  });

  let appleHit = 0;
  let orangeHit = 0;

  // Check if it falls on the house

  whereAppleFalls.map((p) => {
    if (p >= s && p <= t) {
      appleHit++;
    }
  });
  whereOrangeFalls.map((p) => {
    if (p >= s && p <= t) {
      orangeHit++;
    }
  });

  console.log(appleHit);
  console.log(orangeHit);
}

function main() {
  const firstMultipleInput = readLine().replace(/\s+$/g, "").split(" ");

  const s = parseInt(firstMultipleInput[0], 10);

  const t = parseInt(firstMultipleInput[1], 10);

  const secondMultipleInput = readLine().replace(/\s+$/g, "").split(" ");

  const a = parseInt(secondMultipleInput[0], 10);

  const b = parseInt(secondMultipleInput[1], 10);

  const thirdMultipleInput = readLine().replace(/\s+$/g, "").split(" ");

  const m = parseInt(thirdMultipleInput[0], 10);

  const n = parseInt(thirdMultipleInput[1], 10);

  const apples = readLine()
    .replace(/\s+$/g, "")
    .split(" ")
    .map((applesTemp) => parseInt(applesTemp, 10));

  const oranges = readLine()
    .replace(/\s+$/g, "")
    .split(" ")
    .map((orangesTemp) => parseInt(orangesTemp, 10));

  countApplesAndOranges(s, t, a, b, apples, oranges);
}
