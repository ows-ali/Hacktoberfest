function palindrome(str) {
  // Good luck!
 
  //assign a front and a back pointer
  var front = 0;
  var back = str.length - 1;

  //back and front pointers won't always meet in the middle, so use (back > front)
  while (back > front) {
    //increments front pointer if current character doesn't meet criteria
    while ( str[front].match(/[\W_]/) ) {
      front++;
      continue;
    }
    //decrements back pointer if current character doesn't meet criteria
    while ( str[back].match(/[\W_]/) ) {
      back--;
      continue;
    }
    //finally does the comparison on the current character
    if ( str[front].toLowerCase() !== str[back].toLowerCase() ) 
      return false;
    front++;
    back--;
    
  }
  
  //if the whole string has been compared without returning false, it's a palindrome!
  return true;

}


palindrome("eye");