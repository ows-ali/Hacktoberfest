#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */
class Rectangle{
    public:
    int l,b;
    void display(){
        cout<<l<<"\t"<<b<<endl;
    }
};

class RectangleArea:public Rectangle{
    public:
    void read_input(){
        cin>>l>>b;
        
        
    }
    void display(){
        cout<<l*b<<endl;
    }
};

