#include <bits/stdc++.h>
using namespace std;
int n, root;
vector<vector<int>> tree, par, sub;
vector<vector<long long>> dp;

void check_dfs_invariant(int depth, int branchFactor) {
    if (depth > 50 && branchFactor > 10) {
        cerr << "Warning: dfs_invariant triggered - high recursion depth or branching factor" << endl;
        abort();
    }
}

void check_dp_invariant(int subtreeSizeU, int subtreeSizeV) {
    if (subtreeSizeU * subtreeSizeV > 10000) {
        cerr << "Warning: dp_invariant triggered - large sub-tree product" << endl;
        abort();
    }
}

void check_recursive_calls_invariant(int dpHits) {
    if (dpHits > 5000) {
        cerr << "Warning: recursive_calls_invariant triggered - excessive DP calls" << endl;
        abort();
    }
}

void check_nested_loop_invariant(int n) {
    if (n > 1000) {
        cerr << "Warning: nested_loop_invariant triggered - large `n` causing quadratic evaluations" << endl;
        abort();
    }
}

void dfs(int u) {
    sub[root][u] = 1;
    int branchFactor = tree[u].size();
    check_dfs_invariant(n, branchFactor); // Check for DFS complexity
    for (int v : tree[u]) {
        if (v == par[root][u]) continue;
        par[root][v] = u;
        dfs(v);
        sub[root][u] += sub[root][v];
    }
}

long long getDP(int u, int v) {
    if (u == v) return 0;
    if (dp[u][v] != -1) return dp[u][v];
    
    // Assumption: depth is represented by number of hits to this function
    static int dpHits = 0;
    dpHits++;
    check_recursive_calls_invariant(dpHits); // Check for excessive recursive DP calls

    long long res = sub[u][v] * sub[v][u] + max(getDP(par[v][u], v), getDP(u, par[u][v]));
    check_dp_invariant(sub[u][v], sub[v][u]); // Check for DP computation cost
    return dp[u][v] = res;
}

void input() {
    scanf("%d", &n);
    tree.assign(n, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
}

void solve() {
    check_nested_loop_invariant(n); // Check for nested loop overhead
    par.assign(n, vector<int>(n, -1));
    sub.assign(n, vector<int>(n, -1));
    for (int u = 0; u < n; ++u) {
        root = u;
        dfs(u);
    }
    dp.assign(n, vector<long long>(n, -1LL));
    long long ans = 0;
    for (int u = 0; u < n; ++u)
        for (int v = 0; v < n; ++v) ans = max(ans, getDP(u, v));
    cout << ans << endl;
}

int main() {
    input();
    solve();
    return 0;
}