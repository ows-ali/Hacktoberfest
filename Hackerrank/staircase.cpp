#include<iostream>

using namespace std;

int main () {
    int height;
    cin >> height;

    for (int i = 1; i <= height; i++) {
        for (int j = 0; j < i; j++) {
            if(j==0) {		
                //Printing spaces 
                for(int t = 0; t < height - i; t++) cout << " ";
            }
            //Print hashes
            cout << "#";
        }
        cout << endl;
    }
    return 0;
}