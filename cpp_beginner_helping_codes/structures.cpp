#include <iostream>
using namespace std;

struct student
{
	char name[20];
	int age;
	float gpa;
};

int main(){
	student s1;
	cin >> s1.name;
	cout << s1.name;
}
