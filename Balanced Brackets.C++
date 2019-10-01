#include <bits/stdc++.h>
#include <stack>
using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
  stack <char> x;
  string res="YES";
  string no="NO";
  for(int i=0;i<s.size();i++){
      if(s[i]=='{'||s[i]=='['||s[i]=='('){
          x.push(s[i]);
      }
      if(x.empty()){
          res="NO";
      }
      else if(s[i]=='}' && !x.empty()){
          if(x.top()!='{'){
              res="NO";
          }
          x.pop();
      }
       else if(s[i]==']' && !x.empty()){
          if(x.top()!='['){
              res="NO";
          }
          x.pop();
      }
       else if(s[i]==')' && !x.empty()){
          if(x.top()!='('){
              res="NO";
          }
          x.pop();
      }
  }
  if(x.empty()){
      return res;
  }
  return no;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
