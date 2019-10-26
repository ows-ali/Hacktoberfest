
import java.util.Arrays;
import java.util.List;

// https://www.hackerrank.com/challenges/the-birthday-bar/
public class TheBirthdayBar {

  public static void main(String[] args) {
    birthday(Arrays.asList(1, 2, 1, 3, 2), 3, 2);
    birthday(Arrays.asList(1, 1, 1, 1, 1, 1), 3, 2);
  }

  static int birthday(List<Integer> s, int d, int m) {
    int count = 0;
    int tmpSum=0;
    for (int i=0; i<s.size(); i++){
      for(int j=i; j<i+m; j++){
        tmpSum+=s.get(j);
        if(i+m>s.size())break;
      }
      if(tmpSum == d) count++;
      tmpSum = 0;
    }
    System.out.println(count);
    return count;
  }
}