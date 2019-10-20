package hackerrank;

//link for this question- https://www.hackerrank.com/challenges/lowest-triangle/problem

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class lowest_triangle {

    static int lowestTriangle(int base, int area){
        int h;
        if (2*area % base == 0)
        {
            h= 2*area/base;
        }
        else
        h=(2*area/base)+1;

        return h;

    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int base = in.nextInt();
        int area = in.nextInt();
        int height = lowestTriangle(base, area);
        System.out.println(height);
    }
}

