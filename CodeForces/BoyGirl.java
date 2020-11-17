import java.util.Scanner;
import java.util.HashSet;
//Refers to the Problem 236A of CodeForces
public class BoyGirl{

 public static void main(String[] args) {
    Scanner sc =new Scanner(System.in);
    HashSet<Character> hs=new HashSet<>();
    String s=sc.nextLine();
    
    for(int i=0;i<s.length();i=i+1){
        hs.add(s.charAt(i));
    }
    
    
    if(hs.size()%2==0){
        System.out.println("CHAT WITH HER!");
    }
    else System.out.println("IGNORE HIM!");

    sc.close();

} 
    
}