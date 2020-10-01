//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
#define mp make_pair
#define MODULO 1000000007
#define INF 1000000000000000

/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;


/*-------------------------------------------------------- */

ll gcd(ll a, ll b)
{
	if(b == 0)
	{
		return a;
	}
	return gcd(b, a%b);
}

ll lcm(ll a, ll b)
{
	return ((a*b)/gcd(a,b));
}

long long int read_int(){
	char r;
	bool start=false,neg=false;
	long long int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}
/*-------------------------------------------------------- */
struct Trie{
    ll counter;
    Trie *next[26];
    Trie()
    {
        counter = 0;
        rep(i,0,26)
        {
            next[i] = nullptr;
        }
    }
};

Trie *root = new Trie();
void insertQuery(string s)
{
    Trie *current;
    current = root;
    ll len = s.length();
    rep(i,0,len)
    {
        if(current->next[s[i] - 'a'] == nullptr)
        {
            current->next[s[i] - 'a'] = new Trie();
        }
        ++current->counter;
        current = current->next[s[i] - 'a'];
    }
}

ll searchQuery(string s)
{
    Trie *current;
    current = root;
    ll len = s.length();
    rep(i,0,len)
    {
        if(current->next[s[i] - 'a'] == nullptr)
        {
            return -1;
        }
        current = current->next[s[i] - 'a'];
    }
    return current->counter;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<string> ans;
    ll n;
    cin>>n;
    char c;
    string s;
    vector<string> v;
    rep(i,0,n)
    {
        cin>>c;
        cin>>s;
        if(c == '-')
        {
            v.pb(s);
        }
        else
        {
            insertQuery(s);
        }
    }
    rep(i,0,v.size())
    {
        bool isAdded = false;
        rep(j,0,v[i].length())
        {
            ll value = searchQuery(v[i].substr(0ll, j+1));
            if(value == -1)
            {
                ans.insert(v[i].substr(0ll, j+1));
                isAdded = true;
                break;
            }
        }
        if(isAdded == false)
        {
            cout<<"-1";
            return 0;
        }
    }
    cout<<ans.size()<<"\n";
    for(auto i : ans)
    {
        cout<<i<<"\n";
    }
	return 0;
}

