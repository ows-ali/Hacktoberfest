#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) 
{
    vector<int> vec;
    stringstream ss(str);
    char c;
    int temp;
    while(ss>>temp)
    {
        vec.push_back(temp);
        ss>>c;
    }
    return vec;
}
int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }   
    return 0;
}
