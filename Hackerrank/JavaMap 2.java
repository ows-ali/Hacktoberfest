//Complete this code or write your own from scratch
import java.util.*;
import java.io.*;

class Solution{
    public static void main(String []argh)
    {
        Map<String,Integer> phoneBook = new HashMap<String,Integer>();
    
        Scanner in = new Scanner(System.in);
        int n=in.nextInt();
        in.nextLine();
        for(int i=0;i<n;i++)
        {    
            String name=in.nextLine();
            int phone=in.nextInt();
            in.nextLine();
            phoneBook.put(name,phone);
        }
        while(in.hasNext())
        {
            String s=in.nextLine();
            try{
            int value = phoneBook.get(s);
                System.out.println(s+"="+value);
            }catch(NullPointerException e){
System.out.println("Not found");
            }
            
        }
    }
}



