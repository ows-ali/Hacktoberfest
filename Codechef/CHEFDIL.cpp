/*
https://www.codechef.com/AUG19B/problems/CHEFDIL
*/

// AC on all test cases

#include <iostream>
#include <string>

using namespace std;

int main(){

    int t{0};
    cin >> t;

    while(t--){

        string s;
        cin >> s;

        int n = s.size();

        int count_one{0};

        for(int i=0; i<n; i++){
            if((s[i]-'0') == 1)
                count_one++;
        }

        if(count_one%2 == 0)
            cout << "LOSE" << endl;
        else
            cout << "WIN" << endl;
    }

}
