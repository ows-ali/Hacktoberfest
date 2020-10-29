#include <bits/stdc++.h>

using namespace std;

// complete the compareTriplets function below.
vector<int> compareTriplets(vector<int> a, vector<int> b){

    vector<int> a_b_scores(2,0);

    for(int i = 0; i < a.size(); ++i)
    {
        if(a[i] > b[i])
        {
            a_b_scores[0] = ++ a_b_scores[0];
        }
        if(a[i] < b[i])
        {
            a_b_scores[1] = ++ a_b_scores[1];
        }

        return a_b_scores;
    }

}