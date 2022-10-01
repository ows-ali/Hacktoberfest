//Fibonacci numbers are the numbers in the following integer sequence. 
//0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 ...
//where any number in sequence is given by: 
// FiboNum = sum of the first and second fibonacci numbers 
// and
// the first number is sequence is 0 
// the second number in the sequence  is 1.

// The even number Fibonacci sequence is:
// 0, 2, 8, 34, 144, 610, 2584…. 

// In the logic, given a number, we find the sum of all even fibonacci numbers
// only the next EVEN fibonacci number is added to the SUM
// Keep looping for given number until reaching the end of the given number
// then return the SUM
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