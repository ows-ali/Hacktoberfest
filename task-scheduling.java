import java.util.*;
import java.io.*;

class Solution
{
    BufferedReader input;
    BufferedWriter out;
    StringTokenizer token;

    int[] ST;
    int[] add;

    void update(int s,int e,int x,int a,int b,int v)
    {
        if(s > b || e < a)return;
        if(s >= a && e <= b)
        {
            add[x] += v;
            return;
        }
        add[2*x+1] += add[x];
        add[2*x+2] += add[x];
        add[x] = 0;
        update(s,(s+e)/2,2*x+1,a,b,v);
        update((s+e)/2+1,e,2*x+2,a,b,v);
        ST[x] = Math.max(ST[2*x+1]+add[2*x+1],ST[2*x+2]+add[2*x+2]);
    }

    void build(int s,int e,int x)
    {
        if(s==e)
        {
            ST[x] = -s;
            return;
        }
        build(s,(s+e)/2,2*x+1);
        build((s+e)/2+1,e,2*x+2);
        ST[x] = Math.max(ST[2*x+1],ST[2*x+2]);
    }

    int query(int s,int e,int x,int a,int b)
    {
        if(s > b || e < a)return 0;
        if(s >= a && e <= b)
        {
            return ST[x]+add[x];
        }
        add[2*x+1] += add[x];
        add[2*x+2] += add[x];
        add[x] = 0;
        ST[x] = Math.max(ST[2*x+1]+add[2*x+1],ST[2*x+2]+add[2*x+2]);
        int first = query(s,(s+e)/2,2*x+1,a,b);
        int second = query((s+e)/2+1,e,2*x+2,a,b);
        return Math.max(first,second);
    }

    void solve() throws IOException
    {
        input = new BufferedReader(new InputStreamReader(System.in));
        out = new BufferedWriter(new OutputStreamWriter(System.out));
        int T = nextInt();
        int maxD = 4*(100000+3);
        ST = new int[maxD];
        add = new int[maxD];
        build(0,100000,0);
        for(int t = 0; t < T; t++)
        {
            int D = nextInt();
            int M = nextInt();
            update(0,100000,0,D,100000,M);
            out.write(""+query(0,100000,0,0,100000));
            out.newLine();
        }
        out.flush();
    }

    int nextInt() throws IOException
    {
        if(token == null || !token.hasMoreTokens())
            token = new StringTokenizer(input.readLine());
        return Integer.parseInt(token.nextToken());
    }

    Long nextLong() throws IOException
    {
        if(token == null || !token.hasMoreTokens())
            token = new StringTokenizer(input.readLine());
        return Long.parseLong(token.nextToken());
    }

    String next() throws IOException
    {
        if(token == null || !token.hasMoreTokens())
            token = new StringTokenizer(input.readLine());
        return token.nextToken();
    }

    public static void main(String[] args) throws Exception
    {
        new Solution().solve();
    }
}
