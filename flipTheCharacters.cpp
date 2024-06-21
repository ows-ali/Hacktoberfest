#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word;
    cin >> word;

    for(int i = 0; i < word.size(); i++)
    {
        word[i] += ('a' <= word[i] && word[i] <= 'z' ? 'A' - 'a' : 'a' - 'A');
    }

    cout << word;
    return 0;
}
