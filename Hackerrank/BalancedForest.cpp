#include <bits/stdc++.h>
using namespace std;


map <long long, int> Map1, Map2;
long long ctot;
vector <int> ve[110000];
long long sum[1100000],ans;
int n,q,c[110000];

void test(long long x) {
    long long y = ctot - 2 * x;
    if (y > 0 && y <= x)
        ans = min(ans, x - y);
}

void dfs1(int x, int f) {
    sum[x] = c[x];
    for (int i = 0; i < (int) ve[x].size(); i++)
        if (ve[x][i] != f) {
            dfs1(ve[x][i], x);
            sum[x] += sum[ve[x][i]];
        }
    Map1[sum[x]] += 1;
}



void dfs2(int x, int f) {
if (Map2[2 * sum[x]])
        test(sum[x]);
    if (Map2[ctot - sum[x]])
        test(sum[x]);
    if ((ctot - sum[x]) % 2 == 0 && Map2[ctot - (ctot - sum[x]) / 2])
        test((ctot - sum[x]) / 2);

    Map2[sum[x]] += 1;

    if (Map1[sum[x]] > Map2[sum[x]])
        test(sum[x]);

    if (ctot - 2 * sum[x] >= sum[x] && Map1[ctot - 2 * sum[x]] > Map2[ctot - 2 * sum[x]])
        test(sum[x]);

    if ((ctot - sum[x]) % 2 == 0 && (ctot - sum[x]) / 2 >= sum[x] && Map1[(ctot - sum[x]) / 2] > Map2[(ctot - sum[x]) / 2])
        test((ctot - sum[x]) / 2);

    if (sum[x] * 2 == ctot)
        ans = min(ans, sum[x]);
    
    for (int i = 0; i < (int) ve[x].size(); i++)
        if (ve[x][i] != f) {
            dfs2(ve[x][i], x);
        }

    Map2[sum[x]] -= 1;
}

int main() {
    scanf("%d", &q);
    while (q--) {
        Map1.clear();
        Map2.clear();
        ans = 1e18;
        scanf("%d", &n);
        ctot = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &c[i]);
            ctot += c[i];
        }
        for (int i = 1; i <= n; i++)
            ve[i].clear();
        for (int i = 1; i < n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            ve[x].push_back(y);
            ve[y].push_back(x);
        }
        dfs1(1, 0);
        dfs2(1, 0);
        if (ans == 1e18)
            printf("-1\n");
        else
            printf("%lld\n", ans);
    }
}
