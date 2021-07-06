var reverse = function(x) {
   //first I have to turn the number to a string to index it '123'
    //then split the '123' into '1','2','3' 
    // reverse and we have '3','2','1'
    // join the digits back to 1 string to make a number because they are now separted by ''; we have '321'
    const max = Math.pow(2,31) - 1;
    reversedNum =Math.sign(x) * parseFloat(x.toString().split('').reverse().join(''));
    const min = -1*Math.pow(2,31);
    if(reversedNum > max || reversedNum < min ) { //conditions for overflows
        return 0;
    }
    else {
        return  reversedNum;
    } 
};