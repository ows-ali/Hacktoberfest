//https://www.hackerrank.com/challenges/30-operators/problem
//Just give the input of meal cost, tip and tax and the program will give the desired output
//Note: Tip and tax should be in integer only
import java.util.Scanner;
public class Main {
	
        static int solve(double meal_cost, int tip_percent, int tax_percent) {

            double totalCost;
            double tip;
            double tax;


            tip=(tip_percent*(meal_cost/100));
            
            tax=(tax_percent*(meal_cost/100));
            
            totalCost=meal_cost+tip+tax;
            totalCost=Math.abs(totalCost);
            
            return (int) totalCost;


        }

        static final Scanner scanner = new Scanner(System.in);

        public static void main(String[] args) {
            double meal_cost = scanner.nextDouble();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            int tip_percent = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            int tax_percent = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");



            System.out.println(solve(meal_cost, tip_percent, tax_percent));

            scanner.close();
        }
}