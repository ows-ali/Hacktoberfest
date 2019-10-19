// link to the problem:
// https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/seating-arrangement-1/


// accepted solution :
#include <iostream>
using namespace std;
int main(){
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        
        n = n + 2 * (6 - (n - 1) % 12) - 1; //facing seat
        cout<<n<<" ";
        
        //type of seat
        if (n % 6 < 2) 
            cout<<"WS"<<endl;
        else if (n % 6 == 2 || n % 6 == 5)
            cout<<"MS"<<endl;
        else
            cout<<"AS"<<endl;
    }
    return 0;
}