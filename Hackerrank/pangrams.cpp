#include <bits/stdc++.h>
using namespace std;

int main() {
    string st;
    getline(cin,st);
    transform(st.begin(), st.end(), st.begin(), ::tolower);
    set<char> total_letter;
    
    for (auto i = 0; i < st.size(); i++){
        if (isalpha(st[i])) {
            total_letter.insert(st[i]);
        }
    }
    total_letter.size() == 26 ? cout<<"pangram\n" : cout<<"not pangram\n";
    return 0;
}
