import java.io.IOException;
import java.util.Scanner;

//Original problem url: https://www.beecrowd.com.br/judge/en/problems/view/1865
public class Mjolnir {

    static final String THOR = "Thor";
    static char mjolnir(String name) {
        return THOR.equals(name) ? 'Y' : 'N';
    }

    public static void main(String[] args) throws IOException {

        Scanner in = new Scanner(System.in);
        int casosDeTeste = in.nextInt();

        String name;
        int force;
        for (int i = 0; i < casosDeTeste; i++) {
            name = in.next();
            force = in.nextInt();
            System.out.println(mjolnir(name));
        }

        in.close();
    }

}