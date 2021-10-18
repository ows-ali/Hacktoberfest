#include<bits/stdc++.h>
using namespace std;

int adj[10][10];
int visited[10];
void create_graph(int n,int m)
{
    int i,j,k,src,dest;

      for(j=0;j<n;j++)
     {
         for(k=0;k<n;k++)
         {
             adj[j][k]=0;
         }
     }

     for(i=0;i<m;i++)
     {
         cout<<"Enter the source and destination \n";
         cin>>src>>dest;

         if(src<0||src>=n||dest<0||dest>=n)
         {
             cout<<"invalid vertex \n";
             i--;
         }

         adj[src][dest]=1;
     }

     for(j=0;j<n;j++)
     {
         for(k=0;k<n;k++)
         {
             cout<<adj[j][k]<<"\t";
         }
         cout<<endl;
     }
}
void DFS(int s,int d,int n,int& index,int* path)
{
    path[index++]=s;
    visited[s]=true;

    if(s==d)
    {
      for(int i=0;i<index;i++)
        cout<<path[i]<<" ";

        cout<<endl;
    }
    else
    {
         for(int i=0;i<n;i++)
        {
            if(adj[s][i]==1&&visited[i]==false)
                DFS(i,d,n,index,path);
        }
    }
    index--;
    visited[s]=false;
}
int main()
{
    int n,m,z,s,d,index=0,ch=1;
    int path[10];
    cout<<"Enter the no of vertices \n";
    cin>>n;
    cout<<"Enter the number of edges\n";
    cin>>m;
    create_graph(n,m);

    cout<<"\nEnter the source and destination of path to be found\n";
    cin>>s>>d;
    for(int i=0;i<10;i++)
    {
        visited[i]=false;
    }
    cout<<"Paths are: \n";
    DFS(s,d,n,index,path);
    //will continue if u want paths for multiple source and destination of the same graph :p
    do {
    cout<<"\nEnter '1' to continue \n";
    cin>>ch;
    if(ch==1)
   {
       cout<<"\nEnter the source and destination of path to be found\n";
    cin>>s>>d;
    for(int i=0;i<10;i++)
    {
        visited[i]=false;
    }
cout<<"Paths are:\n";
    DFS(s,d,n,index,path);

    }
    else
    return 0;
    }while(ch==1);


}