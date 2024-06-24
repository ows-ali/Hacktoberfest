import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

public class Solution {

    // Complete the migratoryBirds function below.
    static int migratoryBirds(List<Integer> arr) {

        int[] numbersList = new int[arr.size()];
        int numbersListSize = arr.size(); 
        int counter = 0;

        for(int i = 0; i < arr.size();i++ )
        {
            if(!intArrayContains(arr.get(i), numbersList, numbersListSize))
            {
                numbersList[counter] = arr.get(i);
                counter++;
            }
        }

        int mode = 0;
        int highestOccurence= 0;
        for(int j = 0; j < numbersListSize; j++)
        {   
            int occurence = 0;
            if((occurence = countOccurences(numbersList[j],arr, arr.size())) > highestOccurence)
            {
                highestOccurence = occurence;
                mode = numbersList[j];
            }
        }
    //   printIntArray(numbersList, numbersListSize);
    //   System.out.println(mode);
    return mode;

    } 


    private static int countOccurences( int value, List<Integer> array, int size)
    {   
        int occurences = 0;
        for(int i = 0; i< size;i++)
        {
            if(value == array.get(i))
            {
                occurences++;
            }
          
        }
          return occurences;
    }

    //Testing Only
    private static void printIntArray(int[] array, int size)
    {
        for(int i =0; i< size; i++)
        {
            System.out.println(array[i]);
        }
    }
    private static boolean intArrayContains(int value, int[] array, int sizeOfArray)
    {   
        boolean result = false;
        for(int i = 0; i< sizeOfArray;i++)
        {
            if(value == array[i])
            {
                result = true;
            }
        }

        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int arrCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> arr = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        int result = migratoryBirds(arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
