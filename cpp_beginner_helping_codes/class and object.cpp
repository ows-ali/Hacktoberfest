#include <iostream>
using namespace std;

int main(){
	class newclass{
		private:
			bool atend;
		public:
			string name;
			string presence;
			int age;
			int rollNum;
			int setAttendance(int x){
				if(x){
					atend = true;
				}
				else{
					atend = false;
				}
				return 0;
			}
			int getAttendance(){
				return atend;
			}
	};
	class teacher: public newclass{
	};
	int i, attend, num;
	teacher maths;
	cout << "Name of Maths Teacher:" << endl;
	cin >> maths.name;
	cout << "is the teacher present?" << endl;
	cin >> attend;
	maths.setAttendance(attend);
	if(maths.getAttendance()){
		maths.presence = "present";
	} else{
		maths.presence = "absent";
	}
	cout << "The Teacher is " << maths.presence << endl;
	cout << "Enter the number of students in class:" << endl;
	cin >> num;
	string attendance[num];
	newclass stud[num];
	for(i = 0; i < num; i++){
		cout << "Enter the name of student number " << i+1 << endl;
		cin >> stud[i].name;
		cout << "Enter the age of student number " << i+1 << endl;
		cin >> stud[i].age;
		stud[i].rollNum = i+1;
	}
	for(i = 0; i < num; i++){
		cout << "is " << stud[i].name << " present?" << endl;
		cin >> attend;
		stud[i].setAttendance(attend);
		if(stud[i].getAttendance()){
			stud[i].presence = "present";
		} else{
			stud[i].presence = "absent";
		}
	}
	for(i = 0; i < num; i++){
			cout << "Roll Number " << stud[i].rollNum << " " << stud[i].name << " of age " << stud[i].age << " is " << stud[i].presence;
			
	}
}
