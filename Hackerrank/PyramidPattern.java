package ProblemSolvingBasic;

/*Right Pyramid*/

public class PyramidPattern {
    public static void main(String[] args) {
        System.out.println("Pyramid Pattern!");

        int n = 5;

        for (int i = n; i > 0; i--) {
            int space = i - 1;
            for (int j = 0; j < n; j++) {
                if (j < space) {
                    System.out.print(" ");
                } else {
                    System.out.print("#");
                }
            }
            System.out.println();
        }
    }
}