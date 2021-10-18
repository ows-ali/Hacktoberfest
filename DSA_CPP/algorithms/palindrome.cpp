#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int main()
{
	cout<<"enter a string : ";
	string arr,h;
	getline(cin,arr);
	h=arr;
	reverse(arr.begin(),arr.end());
	if(h==arr)
		cout<<"pali \n";
	else
		cout<<"not pali \n";
	
	 return 0;
}