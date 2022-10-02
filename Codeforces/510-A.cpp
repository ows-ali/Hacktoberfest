#include<iostream>
using namespace std;

int main()
{
    int r,c;
    cin>>r>>c;
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(!(i%2))
                cout<<"#";
            else{
                if(j==0 && i%4==3)
                    cout<<"#";
                else if(j==c-1 && i%4==1)
                    cout<<"#";
                else cout<<".";
            }
        }
        cout<<endl;
    }
    return 0;
}