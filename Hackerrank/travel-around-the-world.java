import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

/**
 * @author michael.malevannyy@gmail.com, (c)2019
 */
public class Solution {

    /*
     * Complete the travelAroundTheWorld function below.
     */
    private static int travelAroundTheWorld(final int[] a, final int[] b, final long c) {
        final int N = a.length;

        // предрассчитанные дельты
        int[] d = new int[N];
        // возможные = 0, невозможные -1
        int[] imp = new int[N];

        // размечаем дельты и сразу считаем баланс
        boolean chocolate = true;
        long sigma = 0;
        for (int i = 0; i < N; i++) {
            int di = d[i] = ((int) (a[i] < c ? a[i] : c) - b[i]);  // delta(a[i], b[i], c);
            sigma += di;
            if(chocolate && di<0)
                chocolate = false;
        }

        // шоколад
        if (chocolate)
            return N;

        // абзац
        if(sigma<0)
            return 0;

        // долг <=0 by design
        int borrow = 0;

        // бежим по дельтам в обратную сторону в поисках дырок,
        // p дополнительно ускоренно сдвигается на самую младшую пройденную дырку
        // если есть непогашенный долг тогда можно пойти на второй круг, но не третий
        for (int p = N-1; (borrow < 0 || p >=0) && p > -N; --p) {
            // цикический индекс
            int i = p >= 0 ? p : p + N;

            // текущая дельта
            int di = d[i];

            if (borrow >= 0 && di >= 0)
                continue;

            // это долг не сможет перейти через эту точку ибо её проход занимает весь безнобак
            if(borrow < 0 && b[i] == c)
                return 0;
    

            // если долга не было он может как появиться так и погасться так и не измениться, но точно borrow <=0
            borrow += di;

            // by design borrow <=0
            if(borrow > 0)
                borrow = 0;

            // вычёркиваем
            if(borrow < 0)
                imp[i] = 1;
        }

        int qu = 0;
        for (int i = 0; i < N; i++) {
            if(imp[i] == 0)
                qu++;
        }

        return qu;
    }
    
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nc = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nc[0].trim());

        long c = Long.parseLong(nc[1].trim());

        int[] a = new int[n];

        String[] aItems = scanner.nextLine().split(" ");

        for (int aItr = 0; aItr < n; aItr++) {
            int aItem = Integer.parseInt(aItems[aItr].trim());
            a[aItr] = aItem;
        }

        int[] b = new int[n];

        String[] bItems = scanner.nextLine().split(" ");

        for (int bItr = 0; bItr < n; bItr++) {
            int bItem = Integer.parseInt(bItems[bItr].trim());
            b[bItr] = bItem;
        }

        int result = travelAroundTheWorld(a, b, c);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();
    }
}
