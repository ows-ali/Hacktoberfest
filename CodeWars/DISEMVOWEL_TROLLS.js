//link for solution: https://www.codewars.com/kata/52fba66badcd10859f00097e/train/javascript

function disemvowel(str) {
    return str.replace(/[aeiou]/gi, '');
}
let statementWithoutVowels = disemvowel('This site is for losers!');
console.log(statementWithoutVowels);