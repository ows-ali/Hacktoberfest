import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class TagContentExtractor{
   public static void main(String[] args){
      
      Scanner in = new Scanner(System.in);
      int testCases = Integer.parseInt(in.nextLine());
      while(testCases>0){
         String line = in.nextLine();
         
             		String input = "<SA premium>Imtiaz has a secret crush</SA premium>";
		
		Pattern p = Pattern.compile("<(.+?)>([^<>]+)</\\1>");
		
		Matcher m = p.matcher(line);
		
		boolean notFound = true;
		
		while (m.find()) {
			
			if (m.group(2).length() != 0) {
				System.out.println(m.group(2));
				notFound = false;
			}
			
		}
		
		if (notFound) {
			System.out.println("None");
		}
         
         testCases--;
      }
   }
}