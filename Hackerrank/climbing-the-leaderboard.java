import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        List<Integer> scores = new ArrayList<Integer>();
        for (int i = 0; i < n; i++){
            int score = in.nextInt();
            if (scores.size() == 0 || scores.get(scores.size() - 1) != score)
                scores.add(score);
        }
        int m = in.nextInt();
        for (int i = 0; i < m; i++){
            int score = in.nextInt();
            int min = 0;
            int max = scores.size();
            while (max > min){
                int mid = (min + max) / 2;
                if (scores.get(mid) <= score)
                    max = mid;
                else
                    min = mid + 1;
            }
            System.out.println(min + 1);
        }
    }
}
