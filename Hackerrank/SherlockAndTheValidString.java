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
        Map <Character, Integer> charList = new HashMap<Character, Integer>();
        for(int i = 0; i < s.length(); i++) {
            Character ch = new Character(s.charAt(i));
            if(!charList.containsKey(ch)) charList.put(ch, new Integer(1));
            else charList.put(ch, new Integer(1 + charList.get(ch)));
        }
        boolean thresholdBroken = false;
        boolean valid = true;
        int commonFreq = getCommonFreq(charList);
        
        for(Map.Entry<Character,Integer> entry : charList.entrySet()) {
            int value = entry.getValue(); 
            if(value != commonFreq) {
                if(value == 1 || value == commonFreq + 1) {
                    if(thresholdBroken) {
                        valid = false;
                        break;
                    }
                    thresholdBroken = true;
                } else {
                    valid = false;
                    break;
                }
            }
        }
        
        return valid ? "YES" : "NO";
        
    }
    
    static int getCommonFreq(Map<Character, Integer> charList) {
        Map<Integer, Integer> freqs = new HashMap<Integer, Integer>();
        int comparisionNumber = 0, commonFreq = 0;
        for(Map.Entry<Character, Integer> charEntry : charList.entrySet()) {
            int freq = charEntry.getValue();
            if(!freqs.containsKey(freq)) freqs.put(freq, new Integer(1));
            else freqs.put(freq, new Integer(1 + freqs.get(freq)));
            if(comparisionNumber < freqs.get(freq)) {
                comparisionNumber = freqs.get(freq);
                commonFreq = freq;
            } 
        }
        return commonFreq;
        
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
