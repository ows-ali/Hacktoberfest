// example input -> 5, 47
// example output -> thirteen minutes to six

function timeInWords(h, m) {
  const incNums = ["", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "quarter", "sixteen", "seventeen", "eighteen", "nineteen"];
  const tens = ["", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"];
  let sayHour = incNums[h];
  let sayMinute, sayTens, sayIncNums, relation, minutes;
  if (m === 0) {
    return sayHour + " o' clock"
  } else if (m === 30) {
    return "half past " + sayHour;
  } else if (m < 30) {
    relation = "past"
  } else if (m > 30){
    relation = "to";
    sayHour = incNums[h + 1]
  }

  if (m === 45 || m === 15) {
    minutes = "quarter";
  } else if (m < 20) {
    sayMinute = incNums[m];
  } else if (m > 40){
    minutes = incNums[60 - m];
  } else {
    if (m < 30) {
      sayTens = tens[parseInt(m.toString().split('')[0])];
    } else {
      sayTens = tens[parseInt(m.toString().split('')[0]) - 1];
    }
    sayIncNums = incNums[parseInt(m.toString().split('')[1])];
    minutes = sayIncNums ? sayTens + " " + sayIncNums : sayTens;
  }
  minutes = minutes || sayMinute;

  if (minutes === "quarter") {
    return `${minutes} ${relation} ${sayHour}`
  } else if (minutes === "one") {
    return `${minutes} minute ${relation} ${sayHour}`
  }
  return `${minutes} minutes ${relation} ${sayHour}`
}
