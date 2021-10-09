#include <iostream>
using namespace std;

int main(){
	int x[100] , input, i = 0, j = 0, searchNum;
	cout << "Linear Search\nEnter array elements:\n";
	while(input != -1){
		cin >> input;
		x[i] = input;
		i++;
	}
	while(x[j] != -1){
		cout << x[j] << "\n";
		j++;
	}
	cout << "Enter the number to be searched: ";
	cin >> searchNum;
	for(i = 0; i <j; i++){
		if(x[i] == searchNum){
			cout << "\nNumber "<<searchNum<< " is at index " << i << " of the array";
		}
	}
	return 0;
}
