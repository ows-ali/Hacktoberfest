public class Solution {

    static void countApplesAndOranges(int s, int t, int a, int b, int[] apples, int[] oranges) {

        int appleCounter = 0;
        int orangeCounter = 0;

        for (int i = 0; i < apples.length; i++) {
            if (apples[i] + a >= s && apples[i] + a <= t)
                appleCounter++;
        }

        for (int i = 0; i < oranges.length; i++) {
            if (oranges[i] + b >= s && oranges[i] + b <= t)
                orangeCounter++;
        }

        System.out.println(appleCounter);
        System.out.println(orangeCounter);
    }
}
