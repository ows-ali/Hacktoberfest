// https://www.hackerrank.com/challenges/attribute-parser/problem

#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;
map<string, string> attrData;
vector<string> stk;

void analyze(string s){
    if(s[1] == '/') //check for closing tag
        stk.pop_back();
    else{
        //opening tag
        string tagname="", attrname="", attrvalue= "";
        int j;
        for (j = 1; s[j] != ' ' && s[j] != '>'; j++)   
        {
            tagname.push_back(s[j]);   
        }  //read the complete tag name
        stk.push_back(tagname);
        if(s[j] == '>') return;

        for(; s[j]!='>'; j++){
            attrname="", attrvalue= "";
            j++; //skip the space
            int k;
            for (k = j; s[k]!=' '; k++){
                attrname.push_back(s[k]);
            }
            k += 4;
            for (; s[k]!='"'; k++){
                attrvalue.push_back(s[k]);
            }
            j = k;
            string key = "", value = attrvalue;
            for(auto it: stk){
                key.append(it);
                key.push_back('.');
            }
            key.pop_back();// remove the last .
            key.push_back('~');
            key.append(attrname);
            attrData.insert({key, value});
        }
        
    }
}

int main() {
    fastio;
    int n, q;
    cin >> n >> q;
    cin.ignore();
    string s;
    for(int i = 0; i<n; i++){
        getline(cin, s);
        analyze(s);
    }
    for (int i = 0; i < q; i++)
    {
        getline(cin, s);
        auto it = attrData.find(s);
        if(it != attrData.end()){
            cout << it->second << endl;
        }else cout<< "Not Found!"<< endl;
    }
    
    return 0;
}
