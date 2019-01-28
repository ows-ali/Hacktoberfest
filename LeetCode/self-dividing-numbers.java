/**
 * https://leetcode.com/problems/self-dividing-numbers/
 *
 * A self-dividing number is a number that is divisible by every digit it contains.
 *
 * For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
 *
 * Also, a self-dividing number is not allowed to contain the digit zero.
 *
 *
 * Exercise: Given a lower and upper number bound, output a list of every possible self dividing number,
 * including the bounds if possible.
 */
import java.util.ArrayList;
import java.util.List;

public class SelfDividingNumbers
{
    private List<Integer> solution(int left, int right)
    {
        List<Integer> ans = new ArrayList<>();

        for (int i = left; i <= right; i++)
        {
            if (selfDividing(i))
                ans.add(i);
        }

        return ans;
    }

    private boolean selfDividing(int n)
    {
        for (char c : String.valueOf(n).toCharArray())
        {
            if (c == '0' || (n % (c - '0') > 0))
                return false;
        }

        return true;
    }

    public static void main(String[] args)
    {
        List<Integer> test = new ArrayList<>();
        SelfDividingNumbers example = new SelfDividingNumbers();

        test = example.solution(1, 22);

        for (Integer x : test)
            System.out.println(x);

    }
}
