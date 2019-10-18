#include "stdafx.h"
#include <iostream>
#include <string>
#include <numeric>
#include <vector>

using namespace std;

class Person {
protected:
        string name;
        uint16_t age;
        const uint32_t cur_id;
        Person(const uint32_t&);
        virtual ~Person();
public:
        virtual void getData() = 0;
        virtual void putData() = 0;
};
Person::Person(const uint32_t& CUR_ID_COUNTER) :cur_id(CUR_ID_COUNTER) {

}
Person::~Person() {

}


class Professor : public Person {
private:
        uint32_t publications;
        static uint32_t CUR_ID_COUNTER;
public:
        Professor();
        ~Professor();
        void getData();
        void putData();
};
uint32_t Professor::CUR_ID_COUNTER = 0;
Professor::Professor() : Person(++Professor::CUR_ID_COUNTER) {

}
Professor::~Professor() {

}
void Professor::getData() {
        //get the name
        this->name.reserve(100U);
        do {
                cout << "Type the Name of the professor!" << endl;
                cin >> this->name;
        } while (this->name.empty());
        //get the Age
        do {
                cout << "Type the Age of the professor!" << endl;
                cin >> this->age;
        } while (!(this->age >= 1 && this->age <= 80));
        //get the Publications
        do {
                cout << "Type the Publications of the professor!" << endl;
                cin >> this->publications;
        } while (!(this->publications >= 1 && this->publications <= 1000));

}
void Professor::putData() {
        cout << this->name << " " << this->age << " " << this->publications << endl << this->cur_id << endl;
}


class Student : public Person {
private:
        uint16_t marks[6];
        static uint32_t CUR_ID_COUNTER;
public:
        Student();
        ~Student();
        void getData();
        void putData();
};
uint32_t Student::CUR_ID_COUNTER = 0;
Student::Student() : Person(++Student::CUR_ID_COUNTER) {

}
Student::~Student() {

}
void Student::getData() {
        //get the name
        this->name.reserve(100U);
        do {
                cout << "Type the Name of the student!" << endl;
                cin >> this->name;
        } while (this->name.empty());
        //get the Age
        do {
                cout << "Type the Age of the student!" << endl;
                cin >> this->age;
                cout << this->age << endl;
        } while (!(this->age >= 1 && this->age <= 80));

        for (uint8_t offset(0); offset < (sizeof(this->marks) / sizeof(uint16_t)); offset++)
                do {
                        printf("Type the %d mark", offset + 1);
                        cin >> *(this->marks + offset);
                }
                while (!(*(this->marks + offset) >= 1 && *(this->marks + offset) <= 100));
}
void Student::putData() {
        cout << this->name << " " << this->age << " " << accumulate(this->marks, this->marks + (sizeof(this->marks) / sizeof(uint16_t)), int(0), [&](int sum, int number) {return sum += number;}) << endl << this->cur_id << endl;

}

void showObjects(const vector<Person*>& members) {
        for (vector<Person*>::const_iterator iter = members.begin(); iter != members.end(); iter++)
                (*iter)->putData();
}
void createObjects() {

        vector<Person*> members;
        uint16_t objects, counter(0), index;
        cout << "How many objects do you want to create?" << endl;
        cin >> objects;
        members.reserve(objects);
        while (++counter <= objects)
        {
                while (true)
                {
                        cout << "1.Create Professor | 2. Create Student" << endl;
                        cin >> index;
                        if (index == 1) {
                                members.push_back(reinterpret_cast<Person*>(new Professor()));
                                members.back()->getData();
                                break;
                        }
                        else if (index == 2) {
                                members.push_back(reinterpret_cast<Person*>(new Student()));
                                members.back()->getData();
                                break;
                        }
                }
        }
        showObjects(members);
}

int main()
{
        createObjects();
        system("pause");
        return 0;
}
