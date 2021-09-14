function fiboEvenSum(n) {
    //Initiating the variables
    var first = 1, second = 2, sum = 2;

    //for loop to compute each next fibonacci in the series
    for (var i=2; i <= n; i++) {
        var nextFibo = first + second;
        //Check to see if the new fibonacci number is even
        if (nextFibo % 2 == 0) {
            sum = sum + nextFibo;
        }

        //sets the new values of the parameters to prepare for next iteration of the loop
        first = second;
        second = nextFibo;
    }

    //returns the largest even fibonacci after n iterations
    return sum;
}