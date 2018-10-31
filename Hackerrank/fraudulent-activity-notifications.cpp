import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int d = input.nextInt();
        int notifications = 0;
        Queue<Integer> queue = new LinkedList<>();
        int[] pastActivity = new int[201];

        for(int i = 0; i < d; i++)
        {
            int transaction = input.nextInt();
            queue.offer(transaction);
            pastActivity[transaction] = pastActivity[transaction]+1;
        }
            
        for(int i = 0; i < n-d; i++)
        {
            int newTransaction = input.nextInt();

            if(newTransaction >= (2* median(pastActivity, d)))
                notifications++;

            int oldestTransaction = queue.poll();
            pastActivity[oldestTransaction] = pastActivity[oldestTransaction]-1;
            queue.offer(newTransaction);
            pastActivity[newTransaction] = pastActivity[newTransaction]+1;
        }
        
        System.out.println(notifications);
    }
    
    static double median(int[] array, int elements)
    {
        int index = 0;
        
        if(elements % 2 == 0)
        {
            int counter = (elements / 2);

            while(counter > 0)
            {                
                counter -= array[index];
                index++;
            }
            index--;
            if(counter <= -1)
                return index;
            else
            {
                int firstIndex = index;
                int secondIndex = index+1;
                while(array[secondIndex] == 0)
                {
                    secondIndex++;
                }
                return (double) (firstIndex + secondIndex) / 2.0;
            }
        }
        else//Find median of odd # of elements
        {
            int counter = (elements / 2);

            while(counter >= 0)
            {
                counter -= array[index]; index++;
            }
            return (double) index-1;
        }
    }
    
    
    static void printArray(int[] array)
    {
        System.out.println("Array");
        for(int i = 0; i < array.length; i++)
        {
            if(array[i] > 0)
                System.out.println(i+" : "+array[i]);
        }
    }
}
