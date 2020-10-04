#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    vector<int> sum(16);
    int r = 0 ;
    int max;
    for(int i=0;  i<4; i++){
        for(int j = 0; j<4 ; j++){
            sum[r] = arr[i][j]+arr[i+2][j]+arr[i][j+1]+arr[i+2][j+1]+arr[i][j+2]+arr[i+2][j+2]+arr[i+1][j+1];
       r++;
        }
    }
    max = sum[0];
for(int i = 0 ; i < 16 ; i++){
if(sum[i]>max)
max = sum[i];
}
return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
