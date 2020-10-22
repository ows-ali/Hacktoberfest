import java.util.*;
class Solution {
    public static void main(String args[] ) throws Exception {
Scanner s = new Scanner(System.in);
String[] str=s.nextLine().split(" ");
String str1="";
for(int i=0;i<str.length-1;i++){
    str1=str1+str[i].charAt(0)+". ";
}
System.out.println(str1+str[str.length-1]);
    }
}
