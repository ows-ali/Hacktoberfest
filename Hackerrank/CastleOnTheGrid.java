import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        scanner.useDelimiter("\n");
        int n = scanner.nextInt();

        char[][] grid = new char[n][n];

        for (int i = 0; i < n; i++) {
            String str = scanner.next();
            grid[i] = str.toCharArray();
        }

        String coords = scanner.next();
        String[] split = coords.split(" ");
        XY start = new XY(Integer.parseInt(split[0]), Integer.parseInt(split[1]));
        XY end = new XY(Integer.parseInt(split[2]), Integer.parseInt(split[3]));

        Set<XY> visited = new HashSet<XY>();

        System.out.println(minSteps(grid, start, end, visited));
    }

    private static int minSteps(char[][] grid, XY curr, XY end, Set<XY> visited) {
        Queue<XY> queue = new LinkedList<XY>();
        queue.add(curr);
        visited.add(curr);

        Queue<Integer> step = new LinkedList<Integer>();
        step.add(0);

        while (!queue.isEmpty()) {
            XY nextXY = queue.remove();
            int hop = step.remove();

            if (nextXY.equals(end)) return hop;

            List<XY> next = getNext(grid, nextXY, visited);
            visited.addAll(next);
            queue.addAll(next);

            for (int i = 0; i < next.size(); i++) {
                step.add(hop + 1);
            }
        }

        return Integer.MAX_VALUE;
    }

    private static List<XY> getNext(char[][] grid, XY curr, Set<XY> visited) {
        List<XY> next = new ArrayList<XY>();

        if (curr.dir == null || curr.dir == Dir.Y) {
            int x = curr.x;
            for (int i = x - 1; i >= 0; i--) {
                if (grid[i][curr.y] == 'X') break;

                final XY xy = new XY(i, curr.y, Dir.X);
                if (!visited.contains(xy)) next.add(xy);
            }

            for (int i = x + 1; i < grid.length; i++) {
                if (grid[i][curr.y] == 'X') break;

                final XY xy = new XY(i, curr.y, Dir.X);
                if (!visited.contains(xy)) next.add(xy);
            }
        }

        if (curr.dir == null || curr.dir == Dir.X) {
            int y = curr.y;

            for (int i = y - 1; i >= 0; i--) {
                if (grid[curr.x][i] == 'X') break;

                final XY xy = new XY(curr.x, i, Dir.Y);
                if (!visited.contains(xy)) next.add(xy);
            }

            for (int i = y + 1; i < grid.length; i++) {
                if (grid[curr.x][i] == 'X') break;

                final XY xy = new XY(curr.x, i, Dir.Y);
                if (!visited.contains(xy)) next.add(xy);
            }
        }

        return next;
    }


    private static class XY {
        int x, y;
        Dir dir;


        public XY(int x, int y) {
            this.x = x;
            this.y = y;
            dir = null;
        }

        public XY(int x, int y, Dir dir) {
            this.x = x;
            this.y = y;
            this.dir = dir;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            XY xy = (XY) o;
            return x == xy.x && y == xy.y;

        }

        @Override
        public int hashCode() {
            return 31 * x + y;
        }

        @Override
        public String toString() {
            return "XY{" +
                    "x=" + x +
                    ", y=" + y +
                    ", dir=" + dir +
                    '}';
        }
    }

    private enum Dir {
        X, Y;
    }
}
