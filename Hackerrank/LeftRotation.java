/*
Question Link : https://www.hackerrank.com/challenges/array-left-rotation/problem
*/
import java.util.*;
import java.lang.*;
import java.io.*;
class LeftRotation{
	public static void main (String[] args){
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int d = scn.nextInt();
		List<Integer> al = new ArrayList<>();
		for(int i=0;i<n;i++){
			al.add(scn.nextInt());
		}
		System.out.println(rotateLeft(d,al));
	}
    public static List<Integer> rotateLeft(int d, List<Integer> arr) {
           if(d>arr.size()){
               d = d%arr.size();
           }
           List<Integer> al = new ArrayList<>();
           for(int j=d;j<arr.size();j++){
               al.add(arr.get(j));
           }
           for(int j=0;j<d;j++){
               al.add(arr.get(j));
           }
           return al;
    }
}
