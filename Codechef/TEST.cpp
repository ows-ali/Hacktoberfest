// Used C++ 14
//Your program is to use the brute-force approach in order to find the Answer to Life, the Universe, and Everything. More precisely... rewrite small numbers from input to output. Stop processing input after reading in the number 42. All numbers at input are integers of one or two digits.
#include <iostream>
#include <vector>
// using namespace std;
int main() {
    std::vector<int> array;
    int temp;
    while (std::cin >> temp){
        if (temp == 42){
            for (auto i = array.begin(); i != array.end(); ++i){
                std::cout << *i <<std::endl; 
            }
            break;
        }
        array.push_back(temp);
    }
}