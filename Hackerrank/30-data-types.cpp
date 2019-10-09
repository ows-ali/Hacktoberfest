#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    
    // Declare second integer, double, and String variables.
    int ii;
    double dd;
    string ds;
    // Read and save an integer, double, and String to your variables.
    cin >> ii;
    cin >> dd;
    cin.ignore();
    getline(cin, ds);
    // Note: If you have trouble reading the entire string, please go back and review the Tutorial closely.
    
    // Print the sum of both integer variables on a new line.
    cout << i+ii << endl;
    

    // Print the sum of the double variables on a new line.
    d+=dd;
    cout << fixed;
    cout << setprecision(1) << d << endl;    
    // Concatenate and print the String variables on a new line
    ds= s + ds;
    cout << ds  << endl;
    // The 's' variable above should be printed first.

    return 0;
}