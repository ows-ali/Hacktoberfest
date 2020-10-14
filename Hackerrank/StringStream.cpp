#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    int a;
    char ch;
    vector<int> myNumber;
    stringstream ss(str);
    while(ss>>a)
    {
        myNumber.push_back(a);
        ss>>ch;
    }
    return myNumber;
    

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
