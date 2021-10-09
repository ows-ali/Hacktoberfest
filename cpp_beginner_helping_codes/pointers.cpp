#include <iostream>
using namespace std;
int main(){
	int x = 5;
	int *xptr;
	xptr = &x;
	cout << "x = " << x	<<endl << "address of x = " << xptr << endl;
	cout << "adress of next memory location = " << xptr+2<< endl;
	cout << "data at next memory location = "<< *(xptr+2)<< endl;
	return 0;
}
