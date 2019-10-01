function fibonacciEvenSum(n) {
    var first = 1, second = 2, sum = 2;

    for (var i=2; i <= n; i++)
    {
        var nextFibonum = first + second;
        if (nextFibonum % 2 == 0)
        {
            sum = sum + nextFibonum;
         }
        first = second;
        second = nextFibonum;
    }

    return sum;
}
