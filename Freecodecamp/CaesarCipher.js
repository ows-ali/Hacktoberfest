function rot13(str) {
  var newStr = "";
  for (var i = 0; i < str.length; i++) {
    newStr += shiftLetter(str[i], 13);
  }
  return newStr;
}
function shiftLetter(l, s) {
  l = l.toUpperCase();
  const alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  var newInd = (alphabet.indexOf(l) + s) % 26;
  return alphabet.includes(l) ? alphabet[newInd] : l;
}
