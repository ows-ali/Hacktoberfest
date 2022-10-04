//https://www.codechef.com/SEP221D/problems/SPEEDTEST/

#include <bits/stdc++.h>
#include<cmath>
#include<climits>
#define loop(x,n) for(int i=x;i<n;i++) 
#define pb push_back

using namespace std;

int main() {
    int tt1ttt1;
    cin >> tt1ttt1;
    while(tt1ttt1--)
    {
        int w,x,y,z;
        cin >> w >> x >> y >> z;
        if((float)w/x > (float)y/z)   cout << "Alice" << "\n";
        else if((float)w/x < (float)y/z)   cout << "Bob" << "\n";
        else    cout << "Equal" << "\n";
    }
	return 0;
}