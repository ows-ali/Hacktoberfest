function fiboEvenSum(n) {
    var first = 1, second = 2, sum = 2;

    for (var i=2; i <= n; i++) {
        var nextFibo = first + second;
        if (nextFibo % 2 == 0) {
            sum = sum + nextFibo;
        }
        first = second;
        second = nextFibo;
    }

    return sum;
}