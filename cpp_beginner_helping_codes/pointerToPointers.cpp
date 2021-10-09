#include <iostream>
using namespace std;


int main(){
	int array[5][5], i, j;
	for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++){
			array[i][j] = j+1;
		}
	}
	for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++){
			cout << array[i][j]<< "\t";
		}
		cout << endl<< endl;
	}
	cout << *(*(array+3)+3);
	int *arrayptr, **multiptr;
	arrayptr = &*array[0];
	cout <<*arrayptr<<endl;
	cout << *&*array[0]<<endl;
	multiptr = arrayptr;
	cout << multiptr;
	return 0;
}
