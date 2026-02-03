import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;
import java.util.stream.IntStream;

import static java.util.stream.Collectors.toList;

/**
 * Solution class for the HackerRank "Count Response Time Regressions" problem.
 * 
 * This class analyzes a series of response times and counts how many times
 * a response time is greater than the average of all previous response times.
 * 
 * @author HackerRank Challenge
 */
class Solution {
    /**
     * Main method that reads input, processes response times, and outputs the result.
     * 
     * Reads:
     * - First line: the number of response times
     * - Following lines: individual response times (integers)
     * 
     * Outputs: the count of response time regressions
     * 
     * @param args command line arguments (not used)
     * @throws IOException if an I/O error occurs during reading
     */
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int responseTimesCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> responseTimes = IntStream.range(0, responseTimesCount).mapToObj(i -> {
                    try {
                        return bufferedReader.readLine().replaceAll("\\s+$", "");
                    } catch (IOException ex) {
                        throw new RuntimeException(ex);
                    }
                })
                .map(String::trim)
                .map(Integer::parseInt)
                .collect(toList());

        int result = countResponseTimeRegressions(responseTimes);

        System.out.println(result);

        bufferedReader.close();
    }

    /**
     * Counts the number of response time regressions in the given list.
     * 
     * A regression occurs when a response time is greater than the average of
     * all previous response times (including the first one).
     * 
     * Algorithm:
     * 1. Start with the first response time as the initial average
     * 2. For each subsequent response time:
     *    - Calculate the average of all previous response times
     *    - If current time exceeds the average, increment the regression count
     *    - Add current time to the running sum
     * 
     * @param responseTimes a list of integer response times to analyze
     * @return the count of response time regressions
     */
    public static int countResponseTimeRegressions(List<Integer> responseTimes) {
        long sum = responseTimes.getFirst();
        int count = 1;
        int result = 0;

        for (int i = 1; i < responseTimes.size(); i++) {
            int current = responseTimes.get(i);

            long avg = sum / count;
            if (current > avg) {
                result++;
            }

            sum += current;
            count++;
        }
        return result;
    }
}
