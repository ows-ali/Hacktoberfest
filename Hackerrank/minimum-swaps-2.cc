#include<bits/stdc++.h>
using namespace std;

int a[100005];
bool visited[100005];

int solve(int n)
{
    pair<int, int> p[n];
    
    for (int i = 0; i < n; i++)
    {
        p[i].first = a[i];
        
        // Storing the original position of a[i]
        p[i].second = i;
    }
    
    sort(p, p+n);
    int ans = 0;
    
    for (int i = 0; i < n; i++)
    {    
        //visited[i]=true indicates that index i belongs to a cycle that is already counted
        
        //p[i].second = i denotes that the ith element was at its correct position
        
        if (visited[i] || p[i].second == i)
            continue;
            
        int cycle_size = 0;
        int j = i;
        
        //Counting the size of the cycle
        while (!visited[j])
        {
            visited[j] = 1;
            j = p[j].second;
            cycle_size++;
        }
        
        ans += (cycle_size - 1);
    }
    
    return ans;
    
}

int main()
{

    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    int ans = solve(n);
    printf("%d\n", ans);
    return 0;
    
}
