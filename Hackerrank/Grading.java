/**
* https://www.hackerrank.com/challenges/grading/copy-from/70633081
**/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Grading {

    static int[] solve(int[] grades){
        for(int i = 0;i<grades.length; i++){
            
            if(grades[i]>40){
                int difference = 5 - grades[i]%5;
                if(difference <3)
                grades[i] += difference; 
            }else 
            if(grades[i]>=38)
                grades[i] = 40;
            
        }
        return grades;
    }


    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] grades = new int[n];
        for(int grades_i=0; grades_i < n; grades_i++){
            grades[grades_i] = in.nextInt();
        }
        int[] result = solve(grades);
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i] + (i != result.length - 1 ? "\n" : ""));
        }
        System.out.println("");
        

    }
}
