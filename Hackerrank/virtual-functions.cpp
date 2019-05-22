#solution by Terezie Schaller
#PR to this project completed for CS 464
#Open Source Software, final project

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
    public:
        int age;
        string name;

    virtual void getdata(){
        cin >> name >> age;
    }

    virtual void putdata(){
        cout << name << " " << age;
    }
};

class Professor : public Person {
    public:
    Professor(){
        cur_id = ++id;
    }

    int cur_id, publications;
    static int id;

    void getdata(){
        cin >> name >> age >> publications;
    }

    void putdata(){
        cout << name << " " << age << " " << publications << " " << cur_id << endl;
    }
};
int Professor::id = 0;

class Student : public Person {
    public:
    Student(){
        cur_id = ++id;
    }
        int cur_id;
        int marks[6];
        static int id;

    void getdata(){
        cin >> name >> age;
        for(int i = 0; i < 6; i++){
            cin >> marks[i];
        }
    }

    void putdata(){
        int marks_sum = 0;
        for (int i = 0; i < 6; i++){
            marks_sum += marks[i];
        }
        cout << name << " " << age << " " << marks_sum << " " << cur_id << endl;
    }

};
int Student::id = 0;
