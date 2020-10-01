#include <iostream>
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long int T;
	cin>>T;
	while(T--)
	{
	    long int Pc,Pr;
	    cin>>Pc>>Pr;
	    long int countC=0,countR=0;
	    if(Pc%9!=0)
	    {
	        countC=Pc/9+1;
	    }
	    else
	    {
	        countC=Pc/9;
	    }
	    if(Pr%9!=0)
	    {
	        countR=Pr/9+1;
	    }
	    else
	    {
	        countR=Pr/9;
	    }
	    if(countC<countR)
	    {
	        cout<<0<<" "<<countC<<endl;
	    }
	    else
	    {
	        cout<<1<<" "<<countR<<endl;
	    }
	}
	return 0;
}
