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
//My code begins from here
class Result {

   public static List<Integer> gradingStudents(List<Integer> grades) {

       int i,j;
       List<Integer> marks=new ArrayList<Integer>();
       for(i=0;i<grades.size();i++)
       {
           if(grades.get(i)>=38)
           {
               for(j=40;j<=100;j=j+5)
               {
                   if(j>=grades.get(i))
                   {
                       if(j-grades.get(i)<3)
                       {
                           marks.add(j);
                           break;
                       }
                       else
                       {
                           marks.add(grades.get(i));
                           break;
                       }
                       
                   }
               }
           }
           else
           {
               marks.add(grades.get(i));
           }
       }
       return marks;

    }

}
//My code ends here

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int gradesCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> grades = IntStream.range(0, gradesCount).mapToObj(i -> {
            try {
                return bufferedReader.readLine().replaceAll("\\s+$", "");
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
            .map(String::trim)
            .map(Integer::parseInt)
            .collect(toList());

        List<Integer> result = Result.gradingStudents(grades);

        bufferedWriter.write(
            result.stream()
                .map(Object::toString)
                .collect(joining("\n"))
            + "\n"
        );

        bufferedReader.close();
        bufferedWriter.close();
    }
}
