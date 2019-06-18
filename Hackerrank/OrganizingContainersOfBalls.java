import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class OrganizingContainersOfBalls {

    // Complete the organizingContainers function below.
    static String organizingContainers(int[][] containers) {
        int[] types = new int[containers[0].length];    // number of balls of each type across all containers
        int[] containerSums = new int[containers.length]; // number of balls in each container; they remain constant throughout althought their types might change
        if(containers.length != containers[0].length) return "Impossible";
        
        for(int i = 0; i < containers.length; i++) {
            int totalForContainer = 0;
            for(int j = 0; j < containers[0].length; j++) {
                totalForContainer += containers[i][j];
                types[j] += containers[i][j];
            }
            containerSums[i] = totalForContainer;
        }
        
        // if there does not exist a container which can accumulate all balls of a single type, then it is impossible, else it is possible
        for(int i = 0; i < types.length; i++) {
            boolean flag = false;
            for(int j = 0; j < containerSums.length; j++) {
                if(containerSums[j] == types[i]) {
                    flag = true;
                    break;
                }
            }
            if(!flag) return "Impossible";
        }
        
        return "Possible";

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            int n = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            int[][] container = new int[n][n];

            for (int i = 0; i < n; i++) {
                String[] containerRowItems = scanner.nextLine().split(" ");
                scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

                for (int j = 0; j < n; j++) {
                    int containerItem = Integer.parseInt(containerRowItems[j]);
                    container[i][j] = containerItem;
                }
            }

            String result = organizingContainers(container);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
