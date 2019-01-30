/**
* https://www.hackerrank.com/challenges/java-string-compare/problem
**/
import java.util.Scanner;

public class Solution {

    public static String getSmallestAndLargest(String s, int k) {
        String smallest = "";
        String largest = "";

        if (k <= 0)
            return smallest + "\n" + largest;

        smallest = s.substring(0, k);
        largest = s.substring(0, k);

        for (int i = 0; i + k <= s.length(); i++){
                    String stringToAdd = s.substring(i, i+k);
                    // Check if our ordered word is smaller than current smallest
                    for (int letter = 0; letter < k; letter++){
                        if (stringToAdd.charAt(letter) == smallest.charAt(letter))
                            continue;
                        else if (stringToAdd.charAt(letter) < smallest.charAt(letter)){
                            smallest = stringToAdd;
                            break;
                        }
                        else break;
                    }
                    // Check if our ordered word is larger than current largest
                      for (int letter = 0; letter < k; letter++){
                        if (stringToAdd.charAt(letter) == largest.charAt(letter))
                            continue;
                        else if (stringToAdd.charAt(letter) > largest.charAt(letter)){
                            largest = stringToAdd;
                            break;
                        }
                        else break;
                    }
        }
        return smallest + "\n" + largest;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.next();
        int k = scan.nextInt();
        scan.close();
      
        System.out.println(getSmallestAndLargest(s, k));
    }
}
