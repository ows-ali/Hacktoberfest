/*Check if string is rotated by two places
Given two strings, the task is to find if a string ('a') can be obtained by rotating another string ('b') by two places.
Examples:

Input : a = "amazon"
      b = "azonam"  // rotated anti-clockwise
Output : 1

Input : a = "amazon"
      b = "onamaz"  // rotated clockwise
Output : 1


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. In the next two line are two string a and b.

Output:
For each test case in a new line print 1 if the string 'a' can be obtained by rotating string 'b' by two places else print 0.

Constraints:
1<=T<=50
1<=length of a, b <100

Example:
Input:
2
amazon
azonam
geeksforgeeks
geeksgeeksfor
Output:
1
0*/

#include <iostream>
#include <string>

using namespace std;

int random_function(string input,string output){
    int n = input.length();
    string a = input.substr(0,n-2);
    string b = input.substr(n-2,2);
    if(b+a == output) return 1;
    else{
        a = input.substr(0,2);
        b = input.substr(2,n-1);
        if(b+a == output) return 1;
        else return 0;
    }
}

int main(){
  int t = 0;
  cin >> t;
  for(int i =0;i < t;i++){
    string input;
    string output;
    cin >> input >> output;
    cout << random_function(input,output) << endl;
  }
}

