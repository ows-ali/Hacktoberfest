#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int count = 0, ans = 0;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        if(s[i] == 'U')
        {
            count++;
        }
        else
        {
            count--;
        }
        arr[i] = count;       
    }
    for(int i=1; i<n; i++)
    {
        if(arr[i] == 0 && arr[i-1] < 0)
        {
            ans++;
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result;

    fout.close();

    return 0;
}
