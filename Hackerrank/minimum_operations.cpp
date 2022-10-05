#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <algorithm> 
#include <vector> 
#include <cmath> 
#include <iostream> 
#include <map> 
using namespace std; 

int dp[110][1<<3];

int min_operations(vector <int> red, vector <int> green, vector <int> blue) {

    int n = (int)red.size(), i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j < 8; j++) {
            dp[i][j] = 1<<30;
        }
    }

    dp[0][0] = 0;
    for (i = 0; i < n; i++){
        for (j = 0; j < 8; j++){
            dp[i + 1][j | 1] = min(dp[i + 1][j | 1], dp[i][j] + green[i] + blue[i]);
            dp[i + 1][j | 2] = min(dp[i + 1][j | 2], dp[i][j] + red[i] + blue[i]);
            dp[i + 1][j | 4] = min(dp[i + 1][j | 4], dp[i][j] + red[i] + green[i]);
        }
    }
    j = 0;
    for (i = 0; i < n; i++){
        if (green[i]) j |= 2;
        if (red[i]) j |= 1;
        if (blue[i]) j |= 4;
    }

    if (dp[n][j] >= (1<<30))
        dp[n][j] = -1;

    return dp[n][j];
}

int main() {

    int n, r, g, b;
    cin >> n;
    vector<int> red, blue, green;

    for(int i = 0; i < n; i++){

        cin >> r >> g >> b;
        red.push_back(r);
        green.push_back(g);
        blue.push_back(b);
    }

    cout << min_operations(red, green, blue) << "\n";
    return 0;
}



