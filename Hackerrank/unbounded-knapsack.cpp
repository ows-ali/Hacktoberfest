
/*
https://www.hackerrank.com/challenges/unbounded-knapsack/problem
*/

/*
Note : You only need to complete the unbounded Knapsack function
But there is also an error from hackerrank end in taking input. So refer the main function

*/




#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'unboundedKnapsack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY arr
 */


int unboundedKnapsack(int k, vector<int> arr) {
    
    int n = arr.size();
    vector<vector<int>>dp(n+1,vector<int>(k+1,0));
   
    
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(j-arr[i-1] >= 0)
                dp[i][j] = max(arr[i-1] + dp[i][j-arr[i-1]] , dp[i-1][j]);
               
            else  
                dp[i][j] = dp[i-1][j];
        }
    }
    
    return dp[n][k];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));
    while(t--){
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = unboundedKnapsack(k, arr);

    fout << result << "\n";
    }
    fout.close();
    
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
