import java.io.IOException;
import java.util.Scanner;

//Original problem url: https://www.beecrowd.com.br/judge/en/problems/view/2483
public class MerryChristmaaas {

    public static void main(String[] args) throws IOException {

        Scanner in = new Scanner(System.in);
        int casosDeTeste = in.nextInt();
        in.close();

        System.out.println("Feliz nat" + new String(new char[casosDeTeste]).replace("\0", "a") + "l!");
    }

}