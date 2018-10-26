

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class ServiceLane {
	
	// Complete the serviceLane function below.
    // static int[] serviceLane(int n, int[][] cases) {
	static int[] serviceLane(int[] width, int[][] cases) {
    	// n = number of width
    	// cases = list of test cases start index and end index
    	// e.g cases[i][j] = for test case i, start index is j0 and end index j1 
    	
    	int t = cases.length;    	
    	
    	int[] result = new int[t];
    	
    	for (int i = 0; i < t; i++) {
    		int min = 0;
    		
    		int start = cases[i][0];
    		
    		int end = cases[i][1];
    		
    		for (int j = start; j < end + 1; j++) {
    			if (j == start) {
    				min = width[j];
    			} else {
    				if (min > width[j]) {
    					min = width[j];
    				}
    			}
    		}
    		
    		result[i] = min;
    	}
    	
    	return result;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nt = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nt[0]);

        int t = Integer.parseInt(nt[1]);

        int[] width = new int[n];

        String[] widthItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int widthItem = Integer.parseInt(widthItems[i]);
            width[i] = widthItem;
        }

        int[][] cases = new int[t][2];

        for (int i = 0; i < t; i++) {
            String[] casesRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 2; j++) {
                int casesItem = Integer.parseInt(casesRowItems[j]);
                cases[i][j] = casesItem;
            }
        }

        // int[] result = serviceLane(n, cases);
        int[] result = serviceLane(width, cases);

        for (int i = 0; i < result.length; i++) {
            bufferedWriter.write(String.valueOf(result[i]));

            if (i != result.length - 1) {
                bufferedWriter.write("\n");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }

}
