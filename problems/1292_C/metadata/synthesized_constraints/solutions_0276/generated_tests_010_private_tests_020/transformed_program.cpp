#include <bits/stdc++.h>
using namespace std;

const long long modn = 1000000007;
inline long long mod(long long x) { return x % modn; }
const int MAXN = 3123;
int n, m, k;
int s[MAXN];
long long dp[MAXN][MAXN];
vector<int> adj[MAXN];
vector<int> sz[MAXN];

// Checker functions
void check_dfs_invariant(int depth, int maxDepth) {
    if (depth > maxDepth) {
        cerr << "Warning: dfs_invariant triggered - recursion depth exceeded!" << endl;
        abort();
    }
}

void check_dp_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: dp_invariant triggered - excessive recomputations detected!" << endl;
        abort();
    }
}

void check_branching_invariant(int branchingFactor, int threshold) {
    if (branchingFactor > threshold) {
        cerr << "Warning: branching_invariant triggered - high branching factor!" << endl;
        abort();
    }
}

// Modified dfs function with depth check
int dfs(int u, int p, int depth) {
    check_dfs_invariant(depth, 100); // Example threshold for depth
    int size = 1;
    for (int nxt : adj[u]) {
        if (nxt == p) continue;
        size += dfs(nxt, u, depth + 1);
    }
    return size;
}

// Reuse the existing go function and add check for branching
long long go(int u, int v, int bu, int bv) {
    long long &r = dp[u][v];
    if (r != -1) return r;
    r = 0;
    long long totu = 0, totv = 0;
    check_branching_invariant(adj[u].size(), 50); // Check branching factor

    for (int i = 0; i < adj[u].size(); i++) {
        int nxt = adj[u][i];
        int tam = sz[u][i];
        if (bu == nxt || v == nxt) continue;
        totu += tam;
    }
    for (int i = 0; i < adj[v].size(); i++) {
        int nxt = adj[v][i];
        int tam = sz[v][i];
        if (bv == nxt || u == nxt) continue;
        totv += tam;
    }
    for (int i = 0; i < adj[u].size(); i++) {
        int nxt = adj[u][i];
        int tam = sz[u][i];
        if (bu == nxt || v == nxt) continue;
        r = max(r, go(nxt, v, u, bv) + ((long long)tam) * (1ll + totv));
    }
    for (int i = 0; i < adj[v].size(); i++) {
        int nxt = adj[v][i];
        int tam = sz[v][i];
        if (bv == nxt || u == nxt) continue;
        r = max(r, go(u, nxt, bu, v) + ((long long)tam) * (1ll + totu));
    }
    check_dp_invariant(r > 1000000000); // Example condition for DP recomputation
    return r;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for (int a = 1; a < n; a++) {
        int i, j;
        scanf("%d%d", &i, &j);
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    for (int a = 1; a <= n; a++) {
        for (int i = 0; i < adj[a].size(); i++) {
            int nxt = adj[a][i];
            sz[a].push_back(dfs(nxt, a, 1));
        }
    }
    long long ans = 0;
    for (int a = 1; a <= n; a++) {
        long long tot = 0;
        for (int i = 0; i < adj[a].size(); i++) tot += sz[a][i];
        for (int i = 0; i < adj[a].size(); i++) {
            int nxt = adj[a][i];
            ans = max(ans, go(a, nxt, nxt, a) +
                             (1ll + tot - sz[a][i]) * ((long long)sz[a][i]));
        }
    }
    printf("%lld\n", ans);
}