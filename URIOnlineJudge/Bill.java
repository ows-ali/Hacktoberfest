import java.io.IOException;
import java.util.Scanner;

//Original problem url: https://www.beecrowd.com.br/judge/en/problems/view/1866
public class Bill {

    static int bill(int n) {
        if (n % 2 == 0) {
            return 0;
        }
        return 1;
    }

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        int c = in.nextInt();

        for (int i = 0; i < c; i++) {
            System.out.println(bill(in.nextInt()));
        }

        in.close();
    }

}