import java.util.Scanner;
public class TempConversion {
    public static void main(String args[]){
        Scanner in = new Scanner(System.in);
        System.out.print("Please enter Temperature in celcius:");   //this will allow user to input any temperature in celcius
        
        float tempC = in.nextFloat();

        float tempF = (tempC * 9/5)+32;                           //this will convert temperature in celcius to fahrenheit


        System.out.println("Temperature in Fahrenheit is:" + tempF);      //this will give the required output
    }
}
