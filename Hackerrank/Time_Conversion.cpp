#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    int n = s.size();
    if(!(s[0] == '1' && s[1] == '2') && s[n-2] == 'P')
    {
        string s2 = s.substr(0,2);
        int chtime = stoi(s2) + 12;
        string s3 = to_string(chtime);
        s[0] = s3[0];
        s[1] = s3[1];
    }
    else if(s[n-2] == 'A' && (s[0] == '1' && s[1] == '2'))
    {
        s[0] = s[1] = '0';
    }
    s.erase(s.end() - 2, s.end());
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

