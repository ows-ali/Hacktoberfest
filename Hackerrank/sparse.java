import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    public static void main(String args[]) {
     
     Scanner sc = new Scanner(System.in);   

        int stringsCount = sc.nextInt();

        String[] strings = new String[stringsCount];

        for (int i = 0; i < stringsCount; i++) {
             strings[i] = sc.next();
        }

        int queriesCount = sc.nextInt();
        
            String[] queries = new String[queriesCount];

        for (int i = 0; i < queriesCount; i++) {
             queries[i] = sc.next();
        }

        //matchingStrings(strings, queries,stringsCount,queriesCount);

        int a=0;
        for(int i =0; i< queriesCount ; ++i){
            a =0;
            for(int j =0; j< stringsCount ; ++j){
            if(queries[i].equals(strings[j]) ){
                a = a + 1;
            }
        }
        System.out.println(a);
        }
    }
}
