import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/*
 *
 * The first line contains a single integer , the number of test cases.
 * The following  pairs of lines are as follows:
 * The first line contains string .
 * The second line contains string .
 * s1 and s2 consist of characters in the range ascii[a-z].
 * https://www.hackerrank.com/challenges/two-strings/problem
 */
public class TWO_STRINGS {

    private final static String RANGE = "abcdefghijklmnopqrstuvwxyz";

    public String solveTwoStringsProblem(String s1, String s2) {
        String result = "NO";
        for (char symbol : RANGE.toCharArray()) {
            if (s1.indexOf(symbol) != -1 && s2.indexOf(symbol) != -1) {
                result = "YES";
                break;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        TWO_STRINGS twoStrings = new TWO_STRINGS();
        Scanner scanner = new Scanner(System.in);
        int p = Integer.parseInt(scanner.nextLine());

        List<String> results = new ArrayList<>();
        for (int i = 0; i < p; i++) {
            results.add(twoStrings.solveTwoStringsProblem(scanner.nextLine(), scanner.nextLine()));
        }

        for (String result : results) {
            System.out.println(result);
        }
    }
}