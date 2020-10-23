#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	
	bool fascinating(int n) {
	    // code here
	    int freq[] = {0,0,0,0,0,0,0,0,0};
        int i;
        bool flag=true;
        int m2n = n*2;
        int m3n = n*3;
        string s = to_string(n);
        string m2s = to_string(m2n);
        string m3s = to_string(m3n);
        string sans = s+m2s+m3s;
        stringstream ss(sans);
        int ans = 0;
        ss>>ans;
        while (ans>0)  {
            i=ans%10;
            freq[i-1]++;
            ans = ans/10;
        }
        for (i=0;i<9;i++) {
            if (freq[i] != 1){
                flag = false;
                break;
            }
        }
        if (flag) {
            return true;
        }
        else {
            return false;
        }
	}
};

int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        Solution ob;
        auto ans = ob.fascinating(n);
        if (ans) {
            cout<<"Fascinating\n";
        }
        else {
            cout<<"Not Fascinating\n";
        }
    }
    return 0;
}