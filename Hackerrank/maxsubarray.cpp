#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

//function for calculating max sum of a subsequence
int msub(vector<int>arr)
{
	//arr is the giver sequence to us
    int n = arr.size() ;
    int smax = arr[0] ;
    //smax is the maximum sum of of a subsequence initialized with arr[0]
    for(int i=1;i<n;i++)
    {
        if(arr[i] > 0 && smax > 0) smax += arr[i];
        else if(smax < 0 && arr[i]>smax) smax = arr[i] ;
        
    }
    return smax ;
}

// Complete the maxSubarray function below.
vector<int> maxSubarray(vector<int> arr) {
    // arr is the given sequence to us
    int s = arr.size();
    //code for finding max sum of any subarray
    int su[s]; //su is acting as a dp table where su[i] signifies the max sum of the subarray ending at index i
    su[0] = arr[0];
    int res = su[0];
    for(int i=1;i<s;i++)
    {
       if((su[i-1] + arr[i]) >= arr[i])	su[i] = su[i-1] + arr[i];
       else su[i] = arr[i];

       res = max(res , su[i]);
    }
    
    int seq=msub(arr);//calling function for calculating max sum of a subsequence
    
    //creating vector to return
    vector<int> v;
    v.push_back(res);
    v.push_back(seq);
    return v;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        vector<int> result = maxSubarray(arr);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

