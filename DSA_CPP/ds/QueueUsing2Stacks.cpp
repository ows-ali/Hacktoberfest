#include<bits/stdc++.h>
#include <stack>

using namespace std;

int main() {
	stack <int> s1;
	stack <int> s2;
	int n;
	cin>>n;
	while (n--) {
		int ch,x;
		cin>>ch;
		if(ch == 1) {
			cin>>x;
			s1.push(x);
		}
		else {
			if(s2.empty()) {
				while(!s1.empty()) {
					x = s1.top();
					s1.pop();
					s2.push(x);
				}
			}
			if( ch == 2) {
				s2.pop();
			}
			else {
				cout<<s2.top()<<endl;
			}
		}
	}
    return 0;
}
