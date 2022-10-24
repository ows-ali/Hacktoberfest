// https://www.hackerrank.com/challenges/vector-sort/copy-from/292346469

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    int a;

    vector<int> vec;
    // enter vector
    for(int i=0;i<n;i++){
        cin>>a;
        vec.push_back(a);
    }
    
    // sorting algorithm
    sort(vec.begin(),vec.end());
    
    for(int i=0;i<n;i++)
        cout<<vec[i]<<" ";
    return 0;
}
