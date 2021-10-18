#include<iostream>
using namespace std;

int n;
int ans =0, DONE;
///rowmask denote which positions(colms) in all rows are filled
/// ld, rd denotes unsafe positions along diagonals for the current row
/// done is vector of all 11111 ( n times 1 )
/// safe denotes the cols which are safe in the current row

/// Most optimisized n queen code !
void solve(int rowMask,int ld,int rd){

    if(rowMask==DONE){ ans++; return; }

    int safe = DONE&(~(rowMask|ld|rd));
    while(safe){
        int p = safe &(-safe);
        safe = safe - p;
        solve(rowMask|p, (ld|p)<<1, (rd|p)>>1);
    }
}


int main()
{
    cin>>n;
    DONE = ((1<<n) - 1);
    solve(0,0,0);
    cout<<ans<<endl;

}
