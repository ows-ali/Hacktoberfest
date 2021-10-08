#include <iostream>
#include <fstream>
using namespace std;

int main(){
	string myText;
	ifstream MyFile("newfile.txt");
	while(getline(MyFile, myText)){
	cout << myText;	
	}
	
	MyFile.close();
	return 0;
}
