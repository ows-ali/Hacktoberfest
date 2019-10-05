#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    string sen;
    getline(cin,sen);
    transform(sen.begin(), sen.end(), sen.begin(), ::tolower);
    set<char> letters;
    
    for (size_t i = 0; i < sen.size(); i++){
        if (isalpha(sen[i])) {
            letters.insert(sen[i]);
        }
    }
    if (letters.size() == 26) {
        cout << "pangram" << endl;
    } else {
        cout << "not pangram" << endl;
    }
    return 0;
}
