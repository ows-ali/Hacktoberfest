import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
class Edge{
    int x;
    int y;
    @Override
    public String toString() {
        return x+" "+y+" "+w;
    }
    long w;
}
class Pair{
    long first;
    int second;
    Pair(long first,int second){
        this.first = first;
        this.second = second;
    }

    @Override
    public String toString() {
        return first+" "+second;
    }
}
class DDIMMST {
    public static void main(String[] args)throws IOException {
        try {
            BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
            String x[] = bf.readLine().split(" ");
            int n = Integer.parseInt(x[0]);
            int d = Integer.parseInt(x[1]);
            List<List<Long>> pts = new ArrayList(n);
            for(int i=0;i<n;i++){
                pts.add(new ArrayList(d));
                x = bf.readLine().split(" ");
                for(int j=0;j<d;j++){
                    pts.get(i).add(Long.parseLong(x[j]));
                }
            }
            List<Edge> edgeList = new ArrayList(d*n);
            Set<Integer> st = new HashSet();
            if(d == 5){
                int m[][] = {{1,1,1,1,1},{1,1,1,1,-1},{1,1,1,-1,1},{1,1,1,-1,-1},{1,1,-1,1,1},{1,1,-1,1,-1},{1,1,-1,-1,1},{1,1,-1,-1,-1},{1,-1,1,1,1},{1,-1,1,1,-1},{1,-1,1,-1,1},{1,-1,1,-1,-1},{1,-1,-1,1,1},{1,-1,-1,1,-1},{1,-1,-1,-1,1},{1,-1,-1,-1,-1},{-1,1,1,1,1},{-1,1,1,1,-1},{-1,1,1,-1,1},{-1,1,1,-1,-1},{-1,1,-1,1,1},{-1,1,-1,1,-1},{-1,1,-1,-1,1},{-1,1,-1,-1,-1},{-1,-1,1,1,1},{-1,-1,1,1,-1},{-1,-1,1,-1,1},{-1,-1,1,-1,-1},{-1,-1,-1,1,1},{-1,-1,-1,1,-1},{-1,-1,-1,-1,1},{-1,-1,-1,-1,-1}};
                List<Pair>[] values = new List[32];
                for(int i=0;i<32;i++)
                    values[i] = new ArrayList(n);
                for(int i=0;i<n;i++){
                    for(int i1=0;i1<=31;i1++){
                        long count = 0;
                        for(int j1=0;j1<=4;j1++)
                            count += pts.get(i).get(j1) * m[i1][j1];
                        values[i1].add(new Pair(count,i));
                    }
                }
                for(int i=0;i<=31;i++) {
                    int min = 0;
                    int max = 0;
                    for(int j=0;j<values[i].size();j++){
                        if(values[i].get(j).first > values[i].get(max).first )
                            max = j;
                        if(values[i].get(j).first < values[i].get(min).first)
                            min = j;
                    }
                    st.add(values[i].get(min).second);
                    st.add(values[i].get(max).second);
                }
            }else if(d == 3){
                int m[][] = {{1,1,1},{1,1,-1},{1,-1,1},{1,-1,-1},{-1,1,1},{-1,1,-1},{-1,-1,1},{-1,-1,-1}};
                List<Pair>[] values = new List[8];
                for(int i=0;i<8;i++)
                    values[i] = new ArrayList(n);
                for(int i=0;i<n;i++){
                    for(int i1=0;i1<=7;i1++){
                        long count = 0;
                        for(int j1=0;j1<=2;j1++)
                            count += pts.get(i).get(j1) * m[i1][j1];
                        values[i1].add(new Pair(count,i));
                    }
                }
                for(int i=0;i<=7;i++) {
                    //Collections.sort(values[i], (a, b) -> Long.compare(a.first, b.first));
                    int min = 0;
                    int max = 0;
                    for(int j=0;j<values[i].size();j++){
                        if(values[i].get(j).first > values[i].get(max).first )
                            max = j;
                        if(values[i].get(j).first < values[i].get(min).first)
                            min = j;
                    }
                    st.add(values[i].get(min).second);
                    st.add(values[i].get(max).second);
                }
            }else if(d == 1){
                int m[][] = {{1},{-1}};
                List<Pair>[] values = new List[2];
                for(int i=0;i<2;i++)
                    values[i] = new ArrayList(n);
                for(int i=0;i<n;i++){
                    for(int i1=0;i1<=1;i1++){
                        long count = 0;
                        for(int j1=0;j1<=0;j1++)
                            count += pts.get(i).get(j1) * m[i1][j1];
                        values[i1].add(new Pair(count,i));
                    }
                }
                for(int i=0;i<=1;i++) {
                    //Collections.sort(values[i], (a, b) -> Long.compare(a.first, b.first));
                    int min = 0;
                    int max = 0;
                    for(int j=0;j<values[i].size();j++){
                        if(values[i].get(j).first > values[i].get(max).first )
                            max = j;
                        if(values[i].get(j).first < values[i].get(min).first)
                            min = j;
                    }
                    st.add(values[i].get(min).second);
                    st.add(values[i].get(max).second);
                }
            }else if(d == 2){
                int m[][] = {{1,1},{1,-1},{-1,1},{-1,-1}};
                List<Pair>[] values = new List[4];
                for(int i=0;i<4;i++)
                    values[i] = new ArrayList(n);
                for(int i=0;i<n;i++){
                    for(int i1=0;i1<=3;i1++){
                        long count = 0;
                        for(int j1=0;j1<=1;j1++)
                            count += pts.get(i).get(j1) * m[i1][j1];
                        values[i1].add(new Pair(count,i));
                    }
                }
                for(int i=0;i<=3;i++) {
                    //Collections.sort(values[i], (a, b) -> Long.compare(a.first, b.first));
                    int min = 0;
                    int max = 0;
                    for(int j=0;j<values[i].size();j++){
                        if(values[i].get(j).first > values[i].get(max).first )
                            max = j;
                        if(values[i].get(j).first < values[i].get(min).first)
                            min = j;
                    }
                    st.add(values[i].get(min).second);
                    st.add(values[i].get(max).second);
                }
            }else{
                //D == 4
                int m[][] = {{1,1,1,1},{1,1,1,-1},{1,1,-1,1},{1,1,-1,-1},{1,-1,1,1},{1,-1,1,-1},{1,-1,-1,1},{1,-1,-1,-1},{-1,1,1,1},{-1,1,1,-1},{-1,1,-1,1},{-1,1,-1,-1},{-1,-1,1,1},{-1,-1,1,-1},{-1,-1,-1,1},{-1,-1,-1,-1}};
                List<Pair>[] values = new List[16];
                for(int i=0;i<16;i++)
                    values[i] = new ArrayList(n);
                for(int i=0;i<n;i++){
                    for(int i1=0;i1<=15;i1++){
                        long count = 0;
                        for(int j1=0;j1<=3;j1++)
                            count += (pts.get(i).get(j1) * m[i1][j1]);
                        values[i1].add(new Pair(count,i));
                    }
                }
                for(int i=0;i<=15;i++) {
                    int min = 0;
                    int max = 0;
                    for(int j=0;j<values[i].size();j++){
                        if(values[i].get(j).first > values[i].get(max).first )
                            max = j;
                        if(values[i].get(j).first < values[i].get(min).first)
                            min = j;
                    }
                    st.add(values[i].get(min).second);
                    st.add(values[i].get(max).second);
                }
            }
            PriorityQueue<Edge> pq = new PriorityQueue<Edge>((a,b)->Long.compare(b.w,a.w));
            for(int i=0;i<n;i++){
                for(int m:st){
                    long distance = 0;
                    if(i == m)
                        continue;
                    Edge ob = new Edge();
                    for(int j=0;j<d;j++)
                        distance += Math.abs(pts.get(i).get(j) - pts.get((int)m).get(j));
                    ob.x = i;
                    ob.y = (int)m;
                    ob.w = distance;
                    pq.add(ob);
                }
            }
            long ans = 0;
            int count = 0;
            DSU2 dsu = new DSU2(n+1);
            while(count!=n-1){
                Edge e = pq.poll();
                if(dsu.union(e.x,e.y)){
                    ans += e.w;
                    count++;
                }
            }
            System.out.println(ans);
        }catch (Exception e){
            System.err.println(e);
        }
    }
}
class DSU2 {
    int[] parent;
    int[] size;
    int count;
    public DSU2(int N) {
        parent = new int[N];
        count = N;
        size = new int[N];
        for (int i = 0; i < N; ++i){
            parent[i] = i;
            size[i] = 1;
        }
    }
    public int find(int x) {
        while(parent[x] != x){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    public boolean union(int x, int y) {
        int a = find(x);
        int b = find(y);
        if(a == b)
            return false;
        if(size[a] < size[b]){
            parent[a] = parent[b];
            size[b] += size[a];
        }else{
            parent[b] = parent[a];
            size[a] += size[b];
        }
        count--;
        return true;
    }
}