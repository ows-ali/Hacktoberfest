#https://www.hackerrank.com/challenges/sparse-arrays/problem

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    map<string,int> m;
    for(auto const& str:strings){
        m[str]++;
    }
    vector<int> v;
    for(auto const& x:queries){
        v.push_back(m[x]);
    }
    return v;
}