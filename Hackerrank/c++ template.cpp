#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

/*Write the class AddElements here*/
template <class T>
class AddElements {
T element;
public:
AddElements (T arg) {element = arg;}
T add(T element2){
    return element+element2;
}

T concatenate(T element2){
    return element+element2;
}
};
// class template specialization:
template <>
class AddElements <string> {
string element;
public:
AddElements (string arg) {element=arg;}
string concatenate(string element2){
    return element+element2;
}
};


int main () {
