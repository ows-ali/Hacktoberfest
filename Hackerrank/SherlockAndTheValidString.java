import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class SherlockAndTheValidString {

    // Complete the isValid function below.
    static String isValid(String s) {
        Map<String, Integer> stringNumberMap = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            String currentKey = String.valueOf(s.charAt(i));
            if (stringNumberMap.containsKey(currentKey))
                stringNumberMap.put(currentKey, stringNumberMap.get(currentKey) + 1);
            else stringNumberMap.put(currentKey, 1);
        }
        Integer num = stringNumberMap.get(String.valueOf(s.charAt(0)));
        int threshold = 0;
        ArrayList<Integer> values = new ArrayList<>(stringNumberMap.values());
        for (Integer v : values) {
            if (Math.abs(num - v) >= 1) {
                if (threshold >= 1)
                    return "NO";
                threshold++;
            }
        }
        return "YES";
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scanner.nextLine();

        String result = isValid(s);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
