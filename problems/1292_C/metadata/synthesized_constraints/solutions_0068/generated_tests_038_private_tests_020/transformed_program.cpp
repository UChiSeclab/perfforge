#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
int n;
vector<int> g[3002];
int d[3002][3002], save[3002][3002];
long long dp[3002][3002];
bool visit[3002][3002];

// Checkers
void check_complex_tree_structure(int recursionDepth) {
    if (recursionDepth > 100) {
        cerr << "Warning: Performance bottleneck condition triggered - complex tree structure with deep recursion!" << endl;
        abort();
    }
}

void check_high_branching_factor(int nodeDegree) {
    if (nodeDegree > 50) {
        cerr << "Warning: Performance bottleneck condition triggered - high branching factor!" << endl;
        abort();
    }
}

void check_dense_connectivity(int connections) {
    if (connections > 100) {
        cerr << "Warning: Performance bottleneck condition triggered - dense connectivity!" << endl;
        abort();
    }
}

void check_large_subtree_calculation(int subtreeSize) {
    if (subtreeSize > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - large subtree calculations!" << endl;
        abort();
    }
}

void check_dp_state_explosion(int dpStates) {
    if (dpStates > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - dynamic programming state explosion!" << endl;
        abort();
    }
}

void go(int root, int u, int p, int cur = 0) {
    check_complex_tree_structure(cur);  // Check for recursion depth
    d[root][u] = cur;
    save[root][u] = 1;
    check_high_branching_factor(g[u].size());  // Check for high branching factor
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == p) continue;
        go(root, v, u, cur + 1);
        save[root][u] += save[root][v];
    }
    check_large_subtree_calculation(save[root][u]);  // Check for large subtree
}

void prework() {
    for (int u = 1; u <= n; u++) go(u, u, u);
}

long long get_cost(int x, int y) { 
    return (long long)save[x][y] * save[y][x]; 
}

long long F(int x, int y) {
    if (visit[x][y]) return dp[x][y];
    long long ret = 0;
    check_dense_connectivity(g[x].size());  // Check for dense connectivity
    for (int i = 0; i < g[x].size(); i++) {
        int nxt = g[x][i];
        if (d[y][nxt] > d[y][x]) ret = max(ret, get_cost(y, nxt) + F(nxt, y));
    }
    for (int i = 0; i < g[y].size(); i++) {
        int nxt = g[y][i];
        if (d[x][nxt] > d[x][y]) ret = max(ret, get_cost(x, nxt) + F(x, nxt));
    }
    visit[x][y] = true;
    return dp[x][y] = ret;
}

long long solve() {
    prework();
    long long ret = 0;
    check_dp_state_explosion(n * n);  // Check for large DP state space
    for (int u = 1; u <= n; u++) {
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            ret = max(ret, get_cost(u, v) + F(u, v));
        }
    }
    return ret;
}

int main() {
    int i, x, y;
    scanf("%d", &n);
    for (i = 1; i <= n - 1; i++) {
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    long long ret = solve();
    printf("%lld\n", ret);
    return 0;
}