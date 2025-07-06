#include <bits/stdc++.h>
using namespace std;
const int N = 3030, L = 17;
int n, p[N][L], dep[N];
vector<int> adj[N];
int sz[N];

// Checker function implementations
void check_recursive_calls_invariant(int recursionDepth, int callCount) {
    if (recursionDepth > 50 || callCount > 10000) {
        cerr << "Warning: Recursive calls invariant triggered - excessive depth or calls!" << endl;
        abort();
    }
}

void check_lca_queries_invariant(int lcaCallCount) {
    if (lcaCallCount > 5000) {
        cerr << "Warning: LCA queries invariant triggered - excessive ancestor queries!" << endl;
        abort();
    }
}

void check_dp_cache_invariant(int uniqueStatesCount) {
    if (uniqueStatesCount > 10000) {
        cerr << "Warning: DP cache invariant triggered - excessive unique states!" << endl;
        abort();
    }
}

void check_graph_traversal_invariant(int traversalDepth, int nodeCount) {
    if (traversalDepth > 100 || nodeCount > 1000) {
        cerr << "Warning: Graph traversal invariant triggered - excessive traversal depth or nodes!" << endl;
        abort();
    }
}

void check_subtree_size_invariant(int subtreeSize) {
    if (subtreeSize > 500) {
        cerr << "Warning: Subtree size invariant triggered - large subtree size!" << endl;
        abort();
    }
}

// DFS function with subtree size checker
void DFS(int u, int par) {
    p[u][0] = par;
    dep[u] = 1 + dep[par];
    sz[u] = 1;
    for (auto v : adj[u])
        if (v != par) {
            DFS(v, u);
            sz[u] += sz[v];
            // Check subtree size during DFS
            check_subtree_size_invariant(sz[u]);
        }
}

// Function to count LCA queries (simple counter)
int lcaQueryCount = 0;
int LCA(int u, int v) {
    lcaQueryCount++;
    check_lca_queries_invariant(lcaQueryCount);

    if (u == v) return u;
    if (dep[u] < dep[v]) swap(u, v);
    int dif = dep[u] - dep[v];
    u = jump(u, dif);
    if (u == v) return u;
    for (int i = L - 1; i >= 0; i--)
        if (p[u][i] != p[v][i]) {
            u = p[u][i];
            v = p[v][i];
        }
    return p[u][0];
}

// Jump function with traversal check
int jump(int u, int k) {
    int depth = 0;
    for (int i = 0; i < L; i++) {
        if (k & (1 << i)) {
            u = p[u][i];
            depth++;
        }
    }
    check_graph_traversal_invariant(depth, n);
    return u;
}

vector<pair<int, int> > v;
long long mem[N][N];

// DP function with recursion depth and cache usage checks
int dpRecursionDepth = 0;
long long dp(int u, int v, int pu, int pv) {
    dpRecursionDepth++;
    check_recursive_calls_invariant(dpRecursionDepth, lcaQueryCount);

    long long &ret = mem[u][v];
    if (ret != -1) return ret;
    ret = 0;
    for (auto x : adj[u]) {
        if (x == pu) continue;
        ret = max(ret, dp(x, v, u, pv) + f(x, v));
    }
    for (auto x : adj[v]) {
        if (x == pv) continue;
        ret = max(ret, dp(u, x, pu, v) + f(x, u));
    }
    dpRecursionDepth--;
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        v.push_back({a, b});
    }
    DFS(1, 0);
    for (int j = 1; j < L; j++)
        for (int i = 1; i <= n; i++) p[i][j] = p[p[i][j - 1]][j - 1];
    long long ans = 0;
    memset(mem, -1, sizeof mem);
    for (auto p : v)
        ans = max(ans,
                  dp(p.first, p.second, p.second, p.first) + f(p.first, p.second));
    printf("%lld", ans);
}