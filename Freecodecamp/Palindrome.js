function palindrome(str) {
  let regex = /[\_\W]/g;
  let strReverse = Array.from(str)
    .reverse()
    .join("")
    .toLocaleLowerCase()
    .replace(regex, "")
    .trim();

  let string = str.toLocaleLowerCase().replace(regex, "").trim();

  return string === strReverse ? true : false;
}
