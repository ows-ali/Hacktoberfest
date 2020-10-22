
/**
 * Date: 24 Feb, 2018
 * Link : https://www.hackerrank.com/contests/university-codesprint-4/challenges/summer-lesson
 *
 * @author Prasad-Chaudhari
 * @email prasadc8897@gmail.com
 */
import java.io.*;
import java.util.*;

public class Summer_Lesson {

    static int[] howManyStudents(int m, int[] c) {
        // Return an array denoting the number of students taking each class.
        int s[] = new int[m];
        for (int i = 0; i < c.length; i++) {
            s[c[i]]++;
        }
        return s;
    }

    private static final Scanner scan = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nm = scan.nextLine().split(" ");

        int n = Integer.parseInt(nm[0].trim());

        int m = Integer.parseInt(nm[1].trim());

        int[] c = new int[n];

        String[] cItems = scan.nextLine().split(" ");

        for (int cItr = 0; cItr < n; cItr++) {
            int cItem = Integer.parseInt(cItems[cItr].trim());
            c[cItr] = cItem;
        }

        int[] result = howManyStudents(m, c);

        for (int resultItr = 0; resultItr < result.length; resultItr++) {
            bw.write(String.valueOf(result[resultItr]));

            if (resultItr != result.length - 1) {
                bw.write(" ");
            }
        }

        bw.newLine();

        bw.close();
    }
}
