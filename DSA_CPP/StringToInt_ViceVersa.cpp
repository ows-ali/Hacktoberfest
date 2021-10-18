#include <iostream>
#include <String>
#include <iomanip>
#include <locale>
#include <sstream>

using namespace std;

int StringToInt(string n)
{   int x;
    x=atoi(n.c_str());
   return x;
}
string IntToString(int x){
    string n;
    ostringstream kz;
    kz << x;
    n=kz.str();
    return n;
}

int main()
{
    int x=6;
    string n="64";
    cout << x + StringToInt(n) << endl << IntToString(x)+ n;
   return 0;
}
