#include <bits/stdc++.h>

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define mx 200000
int s[mx + 1];
int rank[mx + 1];
int a[mx + 1];
void build_rank(int n){
    for (int i=0;i<n;i++) {
        if (i==0) {
            rank[i] = 1;
        }
        else {
            if (s[i] == s[i-1]) {
                rank[i] = rank[i - 1];
            }
            else {
                rank[i] = rank[i - 1] + 1 ;
            }
        }
    }
}

int main(){

    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    build_rank(n);
    

    int m;
    int point = n;
    cin >> m;
    for (int j = 0; j < m; j++) {
        cin >> a[j];
    }
    
    for(int j = 0; j < m; j++) {
        
        int current_rank;
    
        while (point >= 0 and a[j] > s[point]) {
            point--;
        }
        
        if (point == -1) {
            current_rank = 1;
        }
        else if (a[j] == s[point]) {
            current_rank = rank[point];
        }
        else if (a[j] < s[point]) {
            current_rank = rank[point] + 1;
        }
        
        cout << current_rank << endl;
    }
    
    return 0;
}