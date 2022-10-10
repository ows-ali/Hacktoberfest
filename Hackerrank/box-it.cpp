/*
    Problem Solution
*/

#include<bits/stdc++.h>

using namespace std;
//Implement the class Box
class Box{
//l,b,h are integers representing the dimensions of the box
private:
    int l, b, h;

// The class should have the following functions :
public:
// Constructors:

// Box();
    Box(){
        l = 0, b = 0, h = 0;
    }

// Box(int,int,int);
    Box(int length, int breadth, int height){
        this->l = length;
        this->b = breadth;
        this->h = height;
    }
// Box(Box);
    Box(Box &B){
        this->l = B.l;
        this->b = B.b;
        this->h = B.h;
    }

// int getLength(); // Return box's length
    int getLegth(){
        return this->l;
    }
// int getBreadth (); // Return box's breadth
    int getBreadth(){
        return this->b;
    }
// int getHeight ();  //Return box's height
    int getHeight(){
        return this->h;
    }
// long long CalculateVolume(); // Return the volume of the box
    long long CalculateVolume(){
        return ((this->l * 1LL) * (this->b * 1LL) * (this->h * 1LL));
    }

//Overload operator < as specified

//bool operator<(Box& b)
    bool operator<(Box& b){
        return this->l < b.l || (this->b < b.b && this->l == b.l) || (this->h < b.h && this->b == b.b && this->l == b.l);
    }
};
//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)
ostream& operator<<(ostream& out, Box& B){
    out << B.getLegth() << " " << B.getBreadth() << " " << B.getHeight();
    return out;
}



/*
    hackerRank generated code
*/

// void check2()
// {
//     int n;
//     cin>>n;
//     Box temp;
//     for(int i=0;i<n;i++)
//     {
//         int type;
//         cin>>type;
//         if(type ==1)
//         {
//             cout<<temp<<endl;
//         }
//         if(type == 2)
//         {
//             int l,b,h;
//             cin>>l>>b>>h;
//             Box NewBox(l,b,h);
//             temp=NewBox;
//             cout<<temp<<endl;
//         }
//         if(type==3)
//         {
//             int l,b,h;
//             cin>>l>>b>>h;
//             Box NewBox(l,b,h);
//             if(NewBox<temp)
//             {
//                 cout<<"Lesser\n";
//             }
//             else
//             {
//                 cout<<"Greater\n";
//             }
//         }
//         if(type==4)
//         {
//             cout<<temp.CalculateVolume()<<endl;
//         }
//         if(type==5)
//         {
//             Box NewBox(temp);
//             cout<<NewBox<<endl;
//         }

//     }
// }

// int main()
// {
//     check2();
// }

