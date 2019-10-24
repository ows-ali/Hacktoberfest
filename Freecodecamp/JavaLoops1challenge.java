import java.util.Scanner;

public class Main
{
	public static void main(String[] args) {
	Scanner scan = new Scanner(System.in);
    System.out.println("please enter the number: ");
    int userinput = scan.nextInt();
    for(int i = 1; i < 10; i ++){
      System.out.println(userinput + " * " + i + " = " + (userinput * i));
    }
	}
}
