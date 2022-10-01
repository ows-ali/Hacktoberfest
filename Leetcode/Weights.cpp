#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int w,x,y,z;
	    cin>>w>>x>>y>>z;
        int tot=x+y+z;
        if(tot==w)
        cout<<"YES"<<endl;
        else if(w>tot)
        cout<<"NO"<<endl;
        else if(tot>w)
        {
            if(w==x || w==y || w==z)
            cout<<"YES"<<endl;
            else if(w==x+y || w==x+z || w==y+z)
            cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;
        }
	}
	return 0;
}
