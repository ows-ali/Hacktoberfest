
/**
 * Date: 20 Jun, 2018
 * Link: https://www.hackerrank.com/contests/w38/challenges/a-time-saving-affair/problem
 *
 * @author Prasad-Chaudhari
 * @email prasadc8897@gmail.com
 */
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;

public class A_Time_saving_Affair {

    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        FastIO in = new FastIO();
        int n = in.ni();
        int k = in.ni();
        int m = in.ni();
        PriorityQueue<Data> pq = new PriorityQueue<Data>();
        int count[] = new int[n + 1];
        int from[] = new int[m + 1];
        int to[] = new int[m + 1];
        int time[] = new int[m + 1];
        int edgecount = 0;
        for (int i = 0; i < m; i++) {
            int x = in.ni();
            int y = in.ni();
            int t = in.ni();
            if (x != y) {
                from[edgecount] = x;
                to[edgecount] = y;
                time[edgecount] = t;
                count[from[edgecount]]++;
                count[to[edgecount]]++;
                edgecount++;
            }
        }
        int[][] adjaMat = new int[n + 1][];
        long[][] timeMat = new long[n + 1][];
        for (int i = 1; i <= n; i++) {
            adjaMat[i] = new int[count[i]];
            timeMat[i] = new long[count[i]];
        }
        for (int i = 0; i < edgecount; i++) {
            int u = from[i];
            int v = to[i];
            int tt = time[i];
            adjaMat[u][count[u] - 1] = v;
            timeMat[u][count[u] - 1] = tt;
            adjaMat[v][count[v] - 1] = u;
            timeMat[v][count[v] - 1] = tt;
            count[u]--;
            count[v]--;
        }
        long dist[] = new long[n + 1];
        boolean visi[] = new boolean[n + 1];
        for (int i = 0; i <= n; i++) {
            dist[i] = 1000000000000l;
        }
        dist[1] = 0;
        pq.add(new Data(0, 1));

        while (!pq.isEmpty()) {
            Data d = pq.remove();
            int u = d.v;
            System.out.println(u);
            if (!visi[u]) {
                visi[u] = true;
                for (int i = 0; i < adjaMat[u].length; i++) {
                    int v = adjaMat[u][i];
                    if (!visi[v]) {
                        long distsv = dist[u] + timeMat[u][i];
                        if ((dist[u] / k) % 2 == 1) {
                            distsv = (dist[u] / k + 1) * k + timeMat[u][i];
                        }
                        if (distsv < dist[v]) {
                            System.out.println(u + " " + v + " " + distsv);
                            dist[v] = distsv;
                            pq.add(new Data(distsv, v));
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            System.out.println(i + " " + dist[i]);
        }
        System.out.println(dist[n]);
    }

    static private class Data implements Comparable<Data> {

        long time;
        int v;

        public Data(long time, int v) {
            this.time = time;
            this.v = v;
        }

        @Override
        public int compareTo(Data d) {
            return Long.compare(time, d.time);
        }
    }

    static class FastIO {

        private final BufferedReader br;
        private final BufferedWriter bw;
        private String s[];
        private int index;

        public FastIO() throws IOException {
            br = new BufferedReader(new InputStreamReader(System.in));
            bw = new BufferedWriter(new OutputStreamWriter(System.out, "UTF-8"));
            s = br.readLine().split(" ");
            index = 0;
        }

        public int ni() throws IOException {
            return Integer.parseInt(nextToken());
        }

        public double nd() throws IOException {
            return Double.parseDouble(nextToken());
        }

        public long nl() throws IOException {
            return Long.parseLong(nextToken());
        }

        public String next() throws IOException {
            return nextToken();
        }

        public String nli() throws IOException {
            try {
                return br.readLine();
            } catch (IOException ex) {

            }
            return null;
        }

        public int[] gia(int n) throws IOException {
            int a[] = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = ni();
            }
            return a;
        }

        public int[] gia(int n, int start, int end) throws IOException {
            validate(n, start, end);
            int a[] = new int[n];
            for (int i = start; i < end; i++) {
                a[i] = ni();
            }
            return a;
        }

        public double[] gda(int n) throws IOException {
            double a[] = new double[n];
            for (int i = 0; i < n; i++) {
                a[i] = nd();
            }
            return a;
        }

        public double[] gda(int n, int start, int end) throws IOException {
            validate(n, start, end);
            double a[] = new double[n];
            for (int i = start; i < end; i++) {
                a[i] = nd();
            }
            return a;
        }

        public long[] gla(int n) throws IOException {
            long a[] = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = ni();
            }
            return a;
        }

        public long[] gla(int n, int start, int end) throws IOException {
            validate(n, start, end);
            long a[] = new long[n];
            for (int i = start; i < end; i++) {
                a[i] = ni();
            }
            return a;
        }

        public int[][] gg(int n, int m) throws IOException {
            int adja[][] = new int[n + 1][];
            int from[] = new int[m];
            int to[] = new int[m];
            int count[] = new int[n + 1];
            for (int i = 0; i < m; i++) {
                from[i] = ni();
                to[i] = ni();
                count[from[i]]++;
                count[to[i]]++;
            }
            for (int i = 0; i <= n; i++) {
                adja[i] = new int[count[i]];
            }
            for (int i = 0; i < m; i++) {
                adja[from[i]][--count[from[i]]] = to[i];
                adja[to[i]][--count[to[i]]] = from[i];
            }
            return adja;
        }

        public void print(String s) throws IOException {
            bw.write(s);
            bw.flush();
        }

        public void println(String s) throws IOException {
            bw.write(s);
            bw.newLine();
            bw.flush();
        }

        private String nextToken() throws IndexOutOfBoundsException, IOException {
            if (index == s.length) {
                s = br.readLine().split(" ");
                index = 0;
            }
            return s[index++];
        }

        private void validate(int n, int start, int end) {
            if (start < 0 || end >= n) {
                throw new IllegalArgumentException();
            }
        }
    }
}
