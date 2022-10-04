function convertToRoman(num) {
  let result = "",
    decimals = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1],
    roman = [
      "M",
      "CM",
      "D",
      "CD",
      "C",
      "XC",
      "L",
      "XL",
      "X",
      "IX",
      "V",
      "IV",
      "I",
    ];

  decimals.map((value, index) => {
    while (num >= value) {
      result += roman[index];
      num -= value;
    }
  });

  return result;
}

console.log(convertToRoman(36));
