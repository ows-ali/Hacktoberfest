#include <iostream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string change (int num){
  int quarters=0;
  int dimes=0;
  int nickels=0;
  int pennies=0;
  string ans = "The required number of quarters is ";
  while (num > 100){
    num -= 100;
  }
  while (num > 25){
    quarters++;
    num-=25;
  }
  while (num > 10){
    dimes++;
    num-=10;
  }
  while (num > 5){
    nickels++;
    num-=5;
  }
  while (num > 0){
    pennies++;
    num-=1;
  }
  string ans1 = "\nThe required number of dimes is ";
  string ans2 = "\nThe required number of nickels is ";
  string ans3 = "\nThe required number of pennies is ";
  std::stringstream s;
  s << ans << quarters << ans1 << dimes << ans2 << nickels << ans3 << pennies;
  return s.str();
}


int main (){
  int num;
  cin >> num;
  cout << change(num) << endl;
}
