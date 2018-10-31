import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class CPCOMP {
    static class Graph {
        int nVertices;
        List<List<Integer>> edges = new ArrayList<>();

        public Graph(int nVertices) {
            this.nVertices = nVertices;
            for (int i = 0; i < nVertices; i++) edges.add(new ArrayList<>());
        }

        public void addEdge(int a, int b) {
            edges.get(a).add(b);
            edges.get(b).add(a);
        }

        public int getConnectedComponents() {
            boolean[] visited = new boolean[nVertices];
            int total = 0;
            for (int i = 0; i < nVertices; i++) {
                if (!visited[i]) {
                    total++;
                    dfs(i, visited);
                }
            }
            return total;
        }

        private void dfs(int vertex, boolean[] visited) {
            visited[vertex] = true;
            for (int neighbor : edges.get(vertex)) {
                if (!visited[neighbor]) dfs(neighbor, visited);
            }
        }
    }

    static int gcd(int a, int b) {
        if (a == 0) return b;
        return gcd(b%a, a);
    }

    static boolean isCoprime(int a, int b) {
        return gcd(a,b) == 1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(reader.readLine());
        int[] A = new int[N];
        Graph g = new Graph(N);
        String[] s = reader.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(s[i]);
        }
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                if (isCoprime(A[i], A[j])) {
                    g.addEdge(i, j);
                }
            }
        }
        System.out.println(g.getConnectedComponents());
    }
}
















