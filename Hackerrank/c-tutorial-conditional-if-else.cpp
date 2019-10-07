#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    map<int, string> word;
    word[1] = "one";
    word[2] = "two";
    word[3] = "three";
    word[4] = "four";
    word[5] = "five";
    word[6] = "six";
    word[7] = "seven";
    word[8] = "eight";
    word[9] = "nine";

    if (n <= 9) {
        cout << word[n] << "\n";
    } else {
        cout << "Greater than 9\n";
    }

    return 0;
}
