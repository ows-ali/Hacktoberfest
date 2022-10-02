import java.util.*;

public class ass3_conditional {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        do {
            System.out.println("1area of circle ");
            System.out.println("2Area Of Triangle ");
            System.out.println("3Area Of Rectangle Program ");
            System.out.println("4Area Of Isosceles Triangle ");
            System.out.println("5Area Of Parallelogram ");
            System.out.println("6Area Of Rhombus ");
            System.out.println("7Fibonacci Series In Java Programs ");
            System.out.println("8Subtract the Product and Sum of Digits of an Integer ");
            System.out.println("9Input a number and print all the factors of that number (use loops). ");
            System.out.println("10Take integer inputs till the user enters 0 and print the sum of all numbers ");
            System.out.println("Take integer inputs till the user enters 0 and print the largest number from all ");
            System.out.println("Intermidiate programs now on ");
            System.out.println(" Factorial Program In Java");
            System.out.println("Calculate Electricity Bill ");
            System.out.println("Calculate Average Of N Numbers ");
            System.out.println(" Calculate Discount Of Product");
            System.out.println("Calculate Distance Between Two Points ");
            System.out.println("Calculate Commission Percentage ");
            System.out.println("Power In Java ");
            System.out.println(" Calculate Depreciation of Value");
            System.out.println(" Calculate Batting Average");
            System.out.println(" Calculate CGPA Java Program");
            System.out.println(" Compound Interest Java Program");
            System.out.println(" Sum Of N Numbers");
            System.out.println("Armstrong Number In Java ");
            System.out.println(" Find Ncr & Npr");
            System.out.println("Future Investment Value ");
            System.out.println(" Perfect Number In Java");
            System.out.println(" Kunal is allowed to go out with his friends only on the even days of a given month. Write a program to count the number of days he can go out in the month of August.");
            System.out.println("enter your choice ");
            int ch = sc.nextInt();

            switch (ch) {

                case 1:
                    System.out.println("1area of circle ");
                    int r = sc.nextInt();
                    double area = 3.14 * r * r;
                    System.out.println("area of circle is " + area);
                    break;
                case 2:
                    System.out.println("2Area Of Triangle ");
                    int a = sc.nextInt();
                    int b = sc.nextInt();
                    int c = sc.nextInt();
                    double s = (a + b + c) / 2;
                    double area1 = Math.sqrt(s * (s - a) * (s - b) * (s - c));
                    System.out.println("area of triangle is " + area1);
                    break;
                case 3:
                    System.out.println("3Area Of Rectangle Program ");
                    int l = sc.nextInt();
                    int b1 = sc.nextInt();
                    int area2 = l * b1;
                    System.out.println("area of rectangle is " + area2);

                    break;
                case 4:
                    System.out.println("4Area Of Isosceles Triangle ");
                    int a1 = sc.nextInt();
                    int b2 = sc.nextInt();
                    int area3 = (a1 * b2) / 2;
                    System.out.println("area of isosceles triangle is " + area3);
                    break;
                case 5:
                    System.out.println("5Area Of Parallelogram ");
                    int l1 = sc.nextInt();
                    int b3 = sc.nextInt();
                    int area4 = l1 * b3;
                    System.out.println("area of parallelogram is " + area4);
                    break;
                case 6:
                    System.out.println("6Area Of Rhombus ");
                    int a2 = sc.nextInt();
                    int b4 = sc.nextInt();
                    int area5 = (a2 * b4) / 2;
                    System.out.println("area of rhombus is " + area5);
                    break;
                case 7:
                    System.out.println("7Fibonacci Series In Java Programs ");
                    int n = sc.nextInt();
                    int m = sc.nextInt();
                    int p = 0;
                    int d;
                    for (int i = 1; i <= n; i++) {

                        d = p + m;
                        System.out.println("fibonacci series is " + d);
                        p = m;
                        m = d;
                    }

                    break;
                case 8:
                    System.out.println("8Subtract the Product and Sum of Digits of an Integer ");
                    int n1 = sc.nextInt();
                    int sum = 0;
                    int product = 1;
                    while (n1 != 0) {
                        int r1 = n1 % 10;
                        sum = sum + r1;
                        product = product * r1;
                        n1 = n1 / 10;
                    }
                    int sub = product - sum;
                    System.out.println("subtract of product and sum of digits is " + sub);
                    break;
                case 9:
                    System.out.println("9Input a number and print all the factors of that number (use loops). ");
                    int n2 = sc.nextInt();
                    for (int j = 1; j < n2; j++) {
                        if (n2 % j == 0) {
                            System.out.println("factors of " + n2 + " are " + j);
                        }
                    }
                    break;
                case 10:
                    System.out
                            .println("10.Take integer inputs till the user enters 0 and print the sum of all numbers ");
                    int n3;
                    int summ = 0;
                    do {
                        n3 = sc.nextInt();
                        summ = summ + n3;

                    } while (n3 != 0);
                    System.out.println("sum of all numbers is " + summ);
                    break;
                case 11:
                    System.out.println(
                            "11Take integer inputs till the user enters 0 and print the largest number from all ");
                    int n4;
                    int largest = 0;
                    do {
                        n4 = sc.nextInt();
                        if (n4 > largest) {
                            largest = n4;
                        }
                    } while (n4 != 0);
                    System.out.println("largest number is " + largest);
                    break;
                case 12:
                System.out.println("factorial program ");
                int n5 = sc.nextInt();
                int fact = 1;
                for (int i = 1; i<=n5 ; i++){

                    fact *= i;
                }

                System.out.println(fact);
                case 13:
                System.out.println("electricity bill ");
                 System.out.println("units of electricity consumed ");
                 double n6 = sc.nextDouble();
                 System.out.println("electricity bill for this month"+ n6*10);
                 
                
                default:
                    System.out.println("enter valid choice ");
            }
            System.out.println("do u want to continue ");
        } while (sc.nextInt() == 1);
    }
}