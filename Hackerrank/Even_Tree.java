
/**
 * Date: 25 May, 2018
 * Link: https://www.hackerrank.com/challenges/even-tree/problem
 *
 * @author Prasad-Chaudhari
 * @email prasadc8897@gmail.com
 */
import java.util.*;

public class Even_Tree {

    private static final Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        int n = in.nextInt();
        int m = in.nextInt();
        if (n % 2 == 1) {
            System.out.println(-1);
            return;
        }
        ArrayList<LinkedList<Integer>> a = new ArrayList<LinkedList<Integer>>();
        for (int i = 0; i <= n; i++) {
            a.add(new LinkedList<Integer>());
        }
        for (int i = 0; i < n - 1; i++) {
            int x = in.nextInt();
            int y = in.nextInt();
            a.get(x).add(y);
            a.get(y).add(x);
        }
        int subtreesize[] = new int[n + 1];
        Stack<Integer> st = new Stack<>();
        st.push(1);
        boolean c[] = new boolean[n + 1];
        int parent[] = new int[n + 1];
        Stack<Integer> st2 = new Stack<>();
        st2.push(1);
        while (!st.isEmpty()) {
            int root = st.pop();
            c[root] = true;
            for (int i : a.get(root)) {
                if (!c[i]) {
                    c[i] = true;
                    parent[i] = root;
                    st.push(i);
                    st2.push(i);
                }
            }
        }
        Arrays.fill(subtreesize, 1);
        int k = 0;
        while (!st2.isEmpty()) {
            int node = st2.pop();
            if (subtreesize[node] % 2 == 1) {
                subtreesize[parent[node]] += subtreesize[node];
            } else {
                k++;
            }
        }
        System.out.println(k - 1);
        in.close();
    }
}
