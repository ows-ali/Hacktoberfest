#include <iostream>
using namespace std;

int main(){
	int array[5] = {1,2,3,4,5}, i;
	int *arrayptr;
	arrayptr = array;
	cout<< "first element of array = "<< array[0]<< endl;
	cout << "address of first element = "<< arrayptr<<endl;
	cout << "value at address =" << *arrayptr<<endl;
	for(i = 1; i <= 5; i++){
		cout << *(arrayptr+i)<<endl;
	}
	char name[] = "haris";
	char *nameptr = "haris";
	cout << nameptr;
	return 0;
}
