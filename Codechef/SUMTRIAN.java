import java.util.Scanner;

public class SumTrain {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int notc = scanner.nextInt();
        int nol;
        short[][] arr;
        for (int i = 0; i < notc; i++) {

            nol = scanner.nextInt();
            arr = new short[nol][nol];
            for (int j = 0; j < nol; j++)
                for (int k = 0; k <= j; k++)
                    arr[j][k] = scanner.nextByte();

            for (int j = 1; j < nol; j++)
                for (int k = 0; k <= j; k++)
                    if (k == 0)
                        arr[j][k] += arr[j - 1][k];
                    else if (j == k)
                        arr[j][k] += arr[j - 1][k - 1];
                    else
                        arr[j][k] += max(arr[j - 1][k], arr[j - 1][k - 1]);

            long maxNum = arr[nol - 1][0];
            for (int j = 1; j < nol; j++)
                if (maxNum < arr[nol - 1][j])
                    maxNum = arr[nol - 1][j];
            System.out.println(maxNum);
        }
    }

    public static short max(short a, short b) {

        return a > b ? a : b;
    }
}
