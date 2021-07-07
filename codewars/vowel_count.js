function getCount(str) {
    let vowelsCount = 0;
    
    str.split('').forEach(letter => {
      ['a','e','i','o','u'].forEach(vowel => {
        if (letter == vowel) vowelsCount++
      })
    })
    return vowelsCount;
  }