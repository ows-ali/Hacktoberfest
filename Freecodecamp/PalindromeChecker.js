function palindrome(str) {
    str = str.replace(/[^a-zA-Z0-9]/g, '').toLowerCase();
  
    for(let i = 0; i < Math.floor(str.length / 2); i++) {
        if(str[i] !== str[str.length - (i+1)]) {
            return false;
        }
    }
  
    return true;
  }