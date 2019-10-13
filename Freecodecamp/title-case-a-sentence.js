// modifying replaceAt function using prototype to facilitate the use of the program
String.prototype.replaceAt = function(index, character) {
  return (
    this.substr(0, index) + character + this.substr(index + character.length)
  );
};

function titleCase(str) {
  // split the string by white spaces
  let newTitle = str.split(" ");
  // create a variable to track the updated title
  let updatedTitle = [];
  // looping to turn turn the first character of the word to uppercase and the rest to lowercase
  for (let st in newTitle) {
    // creating concatenated string composed of the whole word in lowercase with the first character replaced by it’s uppercase
    updatedTitle[st] = newTitle[st]
      .toLowerCase()
      .replaceAt(0, newTitle[st].charAt(0).toUpperCase());
  }
  // returning the updatedTitle by joining with empty spaces
  return updatedTitle.join(" ");
}

console.log(titleCase("I'm a little tea pot"));
