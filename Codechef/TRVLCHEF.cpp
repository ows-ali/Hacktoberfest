/*
	Author: @kkothuri
	Karthik Kothuri, NITW
*/
#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define pb push_back
#define all(t) t.begin(), t.end()
#define mii map<int, int>
#define pii pair<int, int>

using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n, d;
        cin >> n >> d;
        vector<int> c(n);
        for(int i = 0; i < n; i++)
            cin >> c[i];
        int st = c[0];
        sort(all(c));
        int si = find(all(c), st) - c.begin();
        if(si == 0 || si == n - 1 || c[n - 1] == st)
        {
            bool valid = true;
            for(int i = 0; i < n - 1; i++)
            {
                if(c[i + 1] - c[i] > d)
                {
                    valid = false;
                    break;
                }
            }
            valid ? cout << "YES\n" : cout << "NO\n";
        }
        else
        {
            bool valid = true;
            if(c[si + 1] - c[si - 1] > d)
                valid = false;
            bool fs, fd, bs, bd;
            fs = fd = bs = bd = true;
            for(int i = si + 1; i < n - 1; i++)
            {
                if(c[i + 1] - c[i] > d)
                {
                    fs = false;
                    break;
                }
            }
            for(int i = 0; i < si - 1; i++)
            {
                if(c[i + 1] - c[i] > d)
                {
                    bs = false;
                    break;
                }
            }
            for(int i = 0; i < si - 1; i++)
            {
                if(c[i + 2] - c[i] > d)
                {
                    bd = false;
                    break;
                }
            }
            for(int i = si; i < n - 2; i++)
            {
                if(c[i + 2] - c[i] > d)
                {
                    fd = false;
                    break;
                }
            }
            if(valid && ((fd && bs) || (fs && bd)))
                cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}