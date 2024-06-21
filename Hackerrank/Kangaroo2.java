
import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Solution {

    // Complete the kangaroo function below.
    static String kangaroo(int x1, int v1, int x2, int v2) {

        //SECOND AHEAD FASTER
        if (v2 > v1) return "NO";
        //SECOND AHEAD SLOWER
        Set<Integer> set1 = Stream.iterate(x1, y -> y + v1).limit(10000).collect(Collectors.toCollection(HashSet::new));
        int[] seq1 = getSeq(set1);
        Set<Integer> set2 = Stream.iterate(x2, y -> y + v2).limit(10000).collect(Collectors.toCollection(HashSet::new));
        int[] seq2 = getSeq(set2);
        if (set1.retainAll(set2))
        {
            int[] matches = set1.stream().sorted().mapToInt(n -> n).toArray();
            OptionalInt x = Arrays.stream(matches).filter(n -> indexMatches(n, seq1, seq2)).findAny();
            if (x.isPresent())
            {
                return "YES";
            }
        }
        return "NO";

    }/Users/jacthomas/Documents/work/PortfolioProject/Hacktoberfest/Hackerrank/Kangaroo2.java

    private static boolean indexMatches(int x, int[] s1, int[] s2) {
        return Arrays.binarySearch(s1, x) == Arrays.binarySearch(s2, x);
    }


    private static int[] getSeq(Set<Integer> set)
    {
        return set.stream().sorted().mapToInt(n->n).toArray();
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] x1V1X2V2 = scanner.nextLine().split(" ");

        int x1 = Integer.parseInt(x1V1X2V2[0]);

        int v1 = Integer.parseInt(x1V1X2V2[1]);

        int x2 = Integer.parseInt(x1V1X2V2[2]);

        int v2 = Integer.parseInt(x1V1X2V2[3]);

        String result = kangaroo(x1, v1, x2, v2);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}

