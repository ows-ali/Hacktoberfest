import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Result {

    public static void staircase(int n) {
    // Write your code here
      for(int i=1; i<=n; i++){
          for(int j=1; j<=n; j++){
              if(j >= 7-i)
              System.out.printf("#");
              
              else
                  System.out.printf(" ");
              
          }
          System.out.println();
      }
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        Result.staircase(n);

        bufferedReader.close();
    }
}
