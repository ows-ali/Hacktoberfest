/*
    Prakhar Gupta
    prakhar17252 on competitive programming sites
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;                     // Maximum size
vector<int> tree[N];                        
int data[N];

void build(int node, int start, int end) {
    if(start == end) {
        tree[node].push_back(data[start]);
        return;
    }

    int mid = (start + end) / 2;
    int left_child = 2 * node;
    int right_child = 2 * node + 1;

    build(left_child, start, mid);
    build(right_child, mid + 1, end);
    merge(tree[left_child].begin(), tree[left_child].end(), tree[right_child].begin(), tree[right_child].end(), back_inserter(tree[node]));
}

int query(int node, int start, int end, int l, int r, int k) {
    if(start > end || end < l || r < start) return 0;
    if(l <= start && end <= r) {
        // Replace lower_bound by upper bound for number of elements <= k in range [l, r]
        return lower_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();       // Number of elements < k in range [l, r]
    }

    int mid = (start + end) / 2;
    int left_child = 2 * node;
    int right_child = 2 * node + 1;

    return query(left_child, start, mid, l, r, k) + query(right_child, mid + 1, end, l, r, k);
}

int main()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> data[i];

    int start = 1;
    int end = n;

    build(1, start, end);                           // build merge sort tree for range [start, end]                                

    int l, r, k;
    cin >> l >> r >> k;

    cout << query(1, start, end, l, r, k);          // number of elements in [l, r] less than k

    return 0;
}