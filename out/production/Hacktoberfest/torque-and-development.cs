using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApplication
{
    public class Graph
    {
        public List<List<int>> g;
        public bool[] visited;
        public int vertices;
        public static long cr = 0;
        public static long cl = 0;
        public static long total = 0;
        public static long temp = 0;
        
        public Graph(int n)
        {
            this.g = new List<List<int>>();
            for(int i =0; i < n; i++)
            {
                g.Add(new List<int>());
            }
            visited = new bool[n];
            this.vertices = n;
            Graph.total = 0;
        }

        public void MinCost()
        {
            for(int i = 0; i < this.vertices; i++)
            {
                if(this.visited[i] == false)
                {
                    util(i);
                    total += Math.Min(cl + (temp - 1) * cr, temp * cl);
                    temp = 0;
                }
            }
        }

        private void util(int v)
        {
            visited[v] = true;
            ++temp;
            foreach(int i in g[v])
            {
                if(visited[i] == false)
                {
                    util(i);
                }
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            int q = int.Parse(Console.ReadLine());
            while(q != 0)
            {
                int[] ar = Array.ConvertAll<string, int>(Console.ReadLine().Split(' '), e => int.Parse(e));
                int m = ar[1];
                Graph city = new Graph(ar[0]);
                Graph.cl = ar[2];
                Graph.cr = ar[3];

                for (int i = 0; i < m; i++)
                {
                    int[] l = Array.ConvertAll<string, int>(Console.ReadLine().Split(' '), e => int.Parse(e));
                    city.g[l[0] - 1].Add(l[1] - 1);
                    city.g[l[1] - 1].Add(l[0] - 1);
                }
                city.MinCost();
                Console.WriteLine(Graph.total);
                q--;
            }
        }
    }
}
