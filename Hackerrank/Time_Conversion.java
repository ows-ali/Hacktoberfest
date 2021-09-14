import java.io.*;
import java.util.*;

public class Time_Conversion {
public static void main(String[] args)
{
Scanner scan = new Scanner(System.in);
String a = scan.nextLine();
int n = Character.getNumericValue(a.charAt(0));
int n1 = Character.getNumericValue(a.charAt(1));
int r = n*10+n1+12;
if(a.charAt(8) == 'A')
{
if(r == 24)
System.out.print("00"+a.substring(2,8));
else
System.out.print(a.substring(0,8));

}
else
{
if(r==24)
System.out.print(a.substring(0,8));
else
System.out.print(Integer.toString(r)+a.substring(2,8));
}
scan.close();
}
}
