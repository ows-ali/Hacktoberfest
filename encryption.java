import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the encryption function below.
    static String encryption(String s) {
       
        String newString = "";
        for(int i=0;i<s.length();i++){
            if(s.charAt(i) == ' '){
                continue;
            }
            newString += s.charAt(i);
        }

         int l = newString.length();
         double sqrt = Math.sqrt(l);
         int x = (int)Math.floor(sqrt);
         int y = (int)Math.ceil(sqrt);

         if(x*y >= l){
             x = x;
         }   
         else{
            while(x*y < l){
                x++;
            }
         }
         Character ans[][] = new Character[x][y];
         int index =  0;
         for(int i=0;i<x;i++){
             for(int j=0;j<y;j++){
                 ans[i][j] = newString.charAt(index);
                 if(index + 1 < l)
                     index++;
                 else {
                     break;
                 }
             }
         }

         String newAns = "";
         for(int i=0;i<y;i++){
                for(int j=0;j<x;j++){
                    if(ans[j][i] != null)
                        newAns += ans[j][i];
                }
                newAns += " ";
             }
            return newAns;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scanner.nextLine();

        String result = encryption(s);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
