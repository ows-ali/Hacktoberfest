/**
 * https://leetcode.com/problems/hamming-distance/
 *
 * The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 *
 * Example:
 *
 * input: x = 1, y = 4
 * output: 2
 *
 * Explanation:
 * 1  (0 0 0 1)
 * 4  (0 1 0 0)
 *       ↑   ↑
 * The above arrows point to positions where the corresponding bits are different.
 */
public class HammingDistance
{
    private int solution(int x, int y)
    {
        int xor = x ^ y;
        int count = 0;

        for (int i = 0; i < 32; i++)
        {
            count += (xor >> i) & 1;
        }

        return count;
    }

    public static void main(String[] args)
    {
        HammingDistance example = new HammingDistance();
        System.out.println(example.solution(1, 4));
    }
}
