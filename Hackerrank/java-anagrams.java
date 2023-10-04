import java.util.Scanner;

public class Solution {
    static boolean isAnagram(String a, String b) {
        final String s = a.toLowerCase();
        final String t = b.toLowerCase();
        int[] alphabets=new int[26];
        for (char c : s.toCharArray()){
            alphabets[c - 'a']++;
        }
        for (char c : t.toCharArray()) {
            alphabets[c - 'a']--;
            if (alphabets[c - 'a'] == -1)  return false;
        }
        for (int count : alphabets) {
            if (count!=0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        String a = scan.next();
        String b = scan.next();
        scan.close();
        boolean ret = isAnagram(a, b);
        System.out.println( (ret) ? "Anagrams" : "Not Anagrams" );
    }
}
