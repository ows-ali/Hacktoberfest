let isPalindrome = function(x) {
    var r, temp, final = 0;
    temp = x;
    while (x>0){
        r = x % 10;
        x = parseInt(x / 10);
        final = final * 10 + r;
    }
    if(final == temp){
        return true;
    }else {
        return false;
    }
}