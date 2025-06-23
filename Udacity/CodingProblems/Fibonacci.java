public class Fibonacci {
    // Recursive method
    public static int fibonacci(int n) {
        if (n <= 1) {
            return n;
        }
        return fibonacci(n - 1) + fibonacci(n - 2);
    }

    public static void main(String[] args) {
        int terms = 10; // Print first 10 Fibonacci numbers
        System.out.println("First " + terms + " Fibonacci numbers:");
        for (int i = 0; i < terms; i++) {
            System.out.print(fibonacci(i) + " ");
        }
    }
}
