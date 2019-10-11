#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

vector<int> graph[100001];//adjacency list for the graph
bool visited[100001];//boolean matrix used in dfs to keep track of visited nodes
// Complete the journeyToMoon function below.

//function to help with dfs of the graph
int dfshelper(int source){
    visited[source] = true;
    int total = 1;
    for(int i = 0 ; i < graph[source].size() ; i++){
        int currver = graph[source][i];
        if(!visited[currver]){
            total += dfshelper(currver);
        }
    }
    return total;
}

long long dfs(int n){
    vector<int> numbers;
    for(int i = 0 ; i < n ; i++){
        if(!visited[i]){
            numbers.push_back(dfshelper(i));
        }
    }
    int k = numbers.size();
    vector<int> cumulative(k);
    cumulative[0] = numbers[0];
    for(int i = 1  ; i < k ; i++){
        cumulative[i] = cumulative[i - 1] + numbers[i];
    }

    long long ans = 0;
    for(int i = 0 ; i < k - 1; i++){
        ans += numbers[i] * (cumulative[k - 1] - cumulative[i]); 
    }
    return ans;
}

long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    //making adjacency list for the graph
    for(int i = 0 ; i < astronaut.size() ; i++){
        int x = astronaut[i][0];
        int y = astronaut[i][1];
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    return dfs(n);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    int n = stoi(np[0]);

    int p = stoi(np[1]);

    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long long result = journeyToMoon(n, astronaut);

    fout << result << "\n";

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

