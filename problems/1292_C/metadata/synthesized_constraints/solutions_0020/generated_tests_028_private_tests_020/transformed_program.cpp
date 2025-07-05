#include <bits/stdc++.h>
using namespace std;

const int MN = 3e3 + 7;
long long dp[MN][MN];
int mx = 1, st[MN][MN], par[MN][MN], mark[MN];
vector<int> g[MN];

void dfs(int now, int z) {
    st[now][z] = 1;
    for (int i = 0; i < g[now].size(); i++) {
        if (!st[g[now][i]][z]) {
            dfs(g[now][i], z);
            par[g[now][i]][z] = now;
            st[now][z] += st[g[now][i]][z];
        }
    }
}

void dfs_(int now, int dis) {
    mark[now] = dis;
    for (int i = 0; i < g[now].size(); i++) {
        if (!mark[g[now][i]]) {
            dfs_(g[now][i], dis + 1);
        }
    }
}

void check_dfs_invariant(int n) {
    if (n > 2500) {  // Arbitrary, but close to the upper limit
        cerr << "Warning: dfs_invariant triggered - high node count may lead to excessive DFS traversals" << endl;
        abort();
    }
}

void check_interaction_invariant(int n) {
    if (n > 2500) {  // Checking if n is large, close to maximum
        cerr << "Warning: interaction_invariant triggered - high number of nodes may cause excessive nested loops" << endl;
        abort();
    }
}

void check_sort_invariant(int n, int pairCount) {
    if (pairCount > n * (n - 1) / 2 * 0.8) {  // Arbitrary threshold, e.g., 80% of maximum pairs
        cerr << "Warning: sort_invariant triggered - large number of pairs being sorted" << endl;
        abort();
    }
}

signed main() {
    int n;
    cin >> n;

    check_dfs_invariant(n);  // Check for DFS-related bottleneck
    check_interaction_invariant(n);  // Check for interaction-related bottleneck

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 0; i < n; i++) {
        dfs(i, i);
    }

    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < n; i++) {
        dfs_(i, 1);
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            v.push_back({mark[j], {i, j}});
        }
        memset(mark, 0, sizeof mark);
    }

    check_sort_invariant(n, v.size());  // Check before sorting

    sort(v.begin(), v.end());

    long long mx = 1;
    for (int i = 0; i < v.size(); i++) {
        int s = v[i].second.second, f = v[i].second.first;
        dp[f][s] = dp[s][f] =
            0ll + st[s][f] * st[f][s] + max(dp[s][par[f][s]], dp[f][par[s][f]]);
        mx = max(mx, dp[f][s]);
    }
    cout << mx << endl;
}