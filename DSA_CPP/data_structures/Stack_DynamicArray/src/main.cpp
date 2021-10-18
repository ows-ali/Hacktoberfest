#include <iostream>
#include <cstring>
#include "Stack.hpp"
#include "Stack.cpp"

using namespace std;

int main (void)
{
	Stack<char> p, q;
	char value;

	cout << "Type a sentence" << endl;
	while((value=cin.get())!='\n')
		p.push(value);

	cout << "Reversed sentence" << endl;
	while(!p.empty()){
		cout << p.limit();
		q.push(p.limit());
		p.pop();
	}

	cout << endl << "The original sentence was" << endl;
	while(!q.empty()){
		cout << q.limit();
		q.pop();
	}
	cout << endl;

	return (0);
}
