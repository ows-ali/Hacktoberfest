import java.util.Scanner;

/*
 * You can run this program on your ide/terminal without getting IOException,
 * but if you'd like to check this implementation, 
 * you should paste only the handshake method on hackerrank
 * 
 * link to the problem: https://www.hackerrank.com/challenges/handshake/problem
 */

public class Handshake {
	
    /*
     * Complete the handshake function below.
     */
    static int handshake(int n) {
        int result = 0;
        while (n >= 1){
            n--;
            result = result + n;
        }
        return result;
    }

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		int numberOfTests = input.nextInt();
		for(int i = 0; i < numberOfTests; i++) {
			
			int numberOfPeople = input.nextInt();
			
			int numberofHandshakes = handshake(numberOfPeople);
			System.out.println(numberofHandshakes);
		}
		

	}

}
