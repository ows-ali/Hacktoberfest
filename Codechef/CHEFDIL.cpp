/*
https://www.codechef.com/AUG19B/problems/CHEFDIL
*/

#include <iostream>
#include <vector>

using namespace std;

const long int modulo_value = 1000000007;

unsigned long long int get_10_raise_to_power(int e){
    unsigned long long int ans{1};
    if(e == 0)
        return 1;

    for(int i=0; i<e; i++){
        ans *= 10;
    }

    return ans;
}

vector<int> number_to_vector(long long int x){

    vector<int> ans;

    while(x > 0){
        ans.push_back(x%10);
        x /= 10;
    }

    return ans;
}

long int f(long long int x){

    int e{0};
    int last_one{-1};

    long int value{0};

    vector<int> number = number_to_vector(x);
    number.push_back(-1); // dummy value

    for(int e=0; e<number.size()-1; e++)
        if(number.at(e) != number.at(e+1))
            value = (value + number.at(e)*get_10_raise_to_power(e))%modulo_value;

    return value;

}

int main(){

    int t{0};
    cin >> t;

    while(t--){

        int nl{0};
        long long int l{0};
        cin >> nl >> l;

        int nr{0};
        long long int r{0};
        cin >> nr >> r;


        long int password_value{0};

        for(long long int x=l%modulo_value; x<=r%modulo_value; x++){
            password_value = (password_value+f(x))%modulo_value;
        }

        cout << password_value << endl;

    }

}
