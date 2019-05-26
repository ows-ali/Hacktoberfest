/*
	https://www.hackerrank.com/challenges/java-anagrams/problem
*/

import java.util.*;

public class Solution {


    static boolean isAnagram(String a, String b) {
        HashMap<Character, Integer> anagramMap_a = new HashMap<>();
        HashMap<Character, Integer> anagramMap_b = new HashMap<>();

        a = a.toLowerCase();
        b = b.toLowerCase();

        anagramMap_a = createHashMap(a);
        anagramMap_b = createHashMap(b);

        if(anagramMap_a.equals(anagramMap_b))
			return(true);
        else
			return(false);
    }

    public static HashMap<Character, Integer> createHashMap(String str){
        HashMap<Character, Integer> anagramMap = new HashMap<>();
		
		char[] charArray = str.toCharArray();
        for (char ch : charArray) {
            if (anagramMap.containsKey(ch)){
                anagramMap.put(ch, anagramMap.get(ch) + 1);
            }else{
                anagramMap.put(ch, 1);
            }
        }
        return(anagramMap);
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