#include <iostream>
using namespace std;

int main(){
	int x[100] , input, i = 0, j = 0;
	cout << "enter array elements (-1 will terminate)\n";
	while(input != -1){
		cin >> input;
		x[i] = input;
		i++;
	}	
	cout << "Entered Elements are:\n";
	while(x[j] != -1){
		cout << x[j] << "\n";
		j++;
	}
	return 0;
}
