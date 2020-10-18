import java.util.*;
public class FLOW015
{
   public static void main(String[] args)
   {
      Scanner input = new Scanner(System.in);
      System.out.println("How many entries?");
      int numItems = input.nextInt();
      System.out.println("List the years:");
      ArrayList<Integer> results = new ArrayList();
      for(int a=0; a<numItems; a++) {
         results.add(input.nextInt());
      }
      for(int a=0; a<numItems; a++) {
         calculate(results.get(a));
      }
   }
   public static void calculate(int x)
   {
      String[] day = {"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};
      int counter;
      int difference = x-2001;
      if(difference==0) {
         System.out.println("monday");
         return;
      }
      counter=0;
      if(difference>0) {
         for(int a=1; a<=difference; a++) {
            if(counter==6) {
               counter=0;
            }
            else {
               counter++;
            }
            if((2001+a)%4==0 && ((2001+a)%100!=0 || (2001+a)%400==0)) {
               if(counter==6) {
                  counter=0;
               }
               else {
                  counter++;
               }
            }
         }
         System.out.println(day[counter]);
      }
      counter=6;
      if(difference<0) {
         difference=Math.abs(difference);
         for(int a=0; a<difference; a++) {
            if(counter==0) {
               counter=6;
            }
            else {
               counter--;
            }
            if(a%4==0) {
               if(counter==0) {
                  counter=6;
               }
               else {
                  counter--;
               }
            }
         }
         System.out.println(day[counter]);
      }
   }
}
