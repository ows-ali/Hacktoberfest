/*
Problem Link
https://www.hackerrank.com/contests/hackerrank-hackfest-2020/challenges/rbg
*/

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'mixColors' function below.
     *
     * The function is expected to return a STRING_ARRAY.
     * The function accepts following parameters:
     *  1. 2D_INTEGER_ARRAY colors
     *  2. 2D_INTEGER_ARRAY queries
     */

    public static List<String> mixColors(List<List<Integer>> colors, List<List<Integer>> queries) {
    // Write your code here

        Map<Integer, Set<List<Integer>>> rmap = new HashMap<>();
        Map<Integer, Set<List<Integer>>> bmap = new HashMap<>();
        Map<Integer, Set<List<Integer>>> gmap = new HashMap<>();
         
        for(List<Integer> color : colors) {
            int r = color.get(0);
            int b = color.get(1);
            int g = color.get(2);
            Set<List<Integer>> rs = rmap.getOrDefault(r, new HashSet<>());
            rs.add(new ArrayList<Integer>(Arrays.asList(b,g)));
            Set<List<Integer>> bs = bmap.getOrDefault(b, new HashSet<>());
            bs.add(new ArrayList<Integer>(Arrays.asList(r,g)));
            Set<List<Integer>> gs = gmap.getOrDefault(g, new HashSet<>());
            gs.add(new ArrayList<Integer>(Arrays.asList(r,b)));
             
            rmap.put(r, rs);
            bmap.put(b, bs);
            gmap.put(g, gs);
        }
         
        List<String> result = new ArrayList<>();
        for(List<Integer> q : queries) {
            int r = q.get(0);
            int b = q.get(1);
            int g = q.get(2);
 
            if(rmap.containsKey(r) && bmap.containsKey(b) && gmap.containsKey(g)) {
                Set<List<Integer>> rs = rmap.get(r);
                Set<List<Integer>> bs = bmap.get(b);
                Set<List<Integer>> gs = gmap.get(g);
                boolean flag = false;                            
                for(List<Integer> col : rs) {
                    if(col.get(0) <= b && col.get(1) <= g){
                        flag = true;
                        break;
                    }
                }
                if(flag) {
                    flag = false; 
                    for(List<Integer> col : bs) {
                        if(col.get(0) <= r && col.get(1) <= g){
                            flag = true;
                            break;
                        }
                    }
                }      
                if(flag) {
                    flag = false; 
                    for(List<Integer> col : gs) {
                        if(col.get(0) <= r && col.get(1) <= b){
                            flag = true;
                            break;
                        }
                    }
                } 
                if(flag)
                    result.add("YES");
                else
                    result.add("NO"); 
            }
            else{
                result.add("NO");
            }
        }
        return result;
    
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int n = Integer.parseInt(firstMultipleInput[0]);

        int q = Integer.parseInt(firstMultipleInput[1]);

        List<List<Integer>> colors = new ArrayList<>();

        IntStream.range(0, n).forEach(i -> {
            try {
                colors.add(
                    Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                        .map(Integer::parseInt)
                        .collect(toList())
                );
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        List<List<Integer>> queries = new ArrayList<>();

        IntStream.range(0, q).forEach(i -> {
            try {
                queries.add(
                    Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                        .map(Integer::parseInt)
                        .collect(toList())
                );
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        List<String> result = Result.mixColors(colors, queries);

        bufferedWriter.write(
            result.stream()
                .collect(joining("\n"))
            + "\n"
        );

        bufferedReader.close();
        bufferedWriter.close();
    }
}
