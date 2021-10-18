#include <iostream>
#include <string>
#include <vector>
#include <climits>

#define loop(i,a,n) for (int i = a; i < n; i++)

using namespace std;

string random_function(vector <string> input,int minLength){

     int n = input.size();
     loop(i,0,minLength){
          loop(j,0,n-1){
               //cout << input.at(j) << " ";
               if(input.at(j).at(i) == input.at(j+1).at(i)){
                    continue;
               }
               else {
                    //cout << "here:\n";
                    //cout << input.at(j).at(i) << " " << input.at(j+1).at(i) << endl;
                    return input.at(0).substr(0,i);
               }
          }
          //cout << endl;
     }
}

int main(){
     int t = 0;
     cin >> t;
     loop(j,0,t){
          int n = 0;
          cin >> n;
          vector <string> input(n);
          int minn = INT_MAX;
          loop(i,0,n){
               string temp;
               cin >> temp;
               input.at(i) = temp;
               minn = minn > temp.length()?temp.length():minn;
          }
          //cout << minn << endl;
          cout << random_function(input,minn) << endl;
     }
     return 0;
}

