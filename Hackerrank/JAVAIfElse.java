import java.util.Scanner;

class Wierd
{
static Scanner sc = new Scanner(System.in);
  public static void main(String[] args)
  {
  int n;
  n=sc.nextInt();
    if(n%2==1)
    {
      System.out.println("Wierd");
    }
    else if(n>=6 && n<=20)
    {
      System.out.println("Wierd");
    }
    else
    {
      System.out.println("Not Wierd");
    }
  }
}
