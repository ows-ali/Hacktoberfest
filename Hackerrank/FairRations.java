

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class FairRations {
	
	// Complete the fairRations function below.
    static int fairRations(int[] B) {
    	int N = B.length;
    	
    	// Check if not possible
    	int checkIfNotPossible = 0;
    	for (int i = 0; i < N; i++) {
    		checkIfNotPossible += B[i];
    	}
    	
    	if (checkIfNotPossible % 2 != 0) {
    		return -1;
    	}
    	
    	// Count bread
    	int countBread = 0;
    	boolean allEven = false;
    	
    	while (!allEven) {
            int countEven = 0;
            
            for (int i = 0; i < N; i++) {
                if (B[i] % 2 != 0) {
                    countBread += 2;
                    
                    B[i] += 1;
                    if (i == N - 1) {
                        B[i - 1] += 1;
                    } else {
                        B[i + 1] += 1;    
                    }
                } else {
                    countEven++;
                }
            }
            
            if (countEven == N) {
                allEven = true;
            }
        }
    	
    	return countBread;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int N = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] B = new int[N];

        String[] BItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < N; i++) {
            int BItem = Integer.parseInt(BItems[i]);
            B[i] = BItem;
        }

        int result = fairRations(B);

        if (result == -1) {
        	bufferedWriter.write("NO");
        } else {
        	bufferedWriter.write(String.valueOf(result));
        }
        
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }

}
