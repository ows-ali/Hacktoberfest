#include<iostream>
#include<string>
#include<cmath>

using namespace std;

void makeEqual(string &num1,string &num2){

  int len1 = num1.size();
  int len2 = num2.size();

  if(len1 > len2){
    string prefix("0",len1-len2);
    num2 = prefix + num2;
  }
  else {
    string prefix("0",len2-len1);
    num1 = prefix + num1;
  }

  //cout<<"--"<<num1<<"--"<<num2<<endl;
}

long int add(string num1,string num2){

  long int n1 = stoi(num1);
  long int n2 = stoi(num2);

  long int sum =  n1+n2;
  return sum;

}

long int karatsuba(string num1,string num2){

  long int result;
  makeEqual(num1,num2);
  int length = num1.size();

  // base case
  if(length == 0)
    return 0;

  if(length == 1){
    int n1 = num1[0] - 48;
    int n2 = num2[0] - 48;
    // cout<<"--"<<n1<<"--"<<n2<<endl;

    return n1*n2;
  }

  // cout<<"Hola";

  int high = length/2;
  int low = length - high;

  string xh = num1.substr(0,high);
  string xl = num1.substr(high,low);

  string yh = num2.substr(0,high);
  string yl = num2.substr(high,low);

  long int a = karatsuba(xh,yh);
  long int d = karatsuba(xl,yl);
  long int e = karatsuba(to_string(add(xh,xl)),to_string(add(yh,yl))) - a - d;

  result = pow(10,length)*a + pow(10,high)*e + d;

  return result;
}

int main(){

  int n1,n2;
  cout<<"Enter the first number :"<<endl;
  cin>>n1;

  cout<<"Enter the second number :"<<endl;
  cin>>n2;

  string num1 = to_string(n1);
  string num2 = to_string(n2);

  cout<<"The result is : "<<karatsuba(num1,num2)<<endl;

  return 0;
}
