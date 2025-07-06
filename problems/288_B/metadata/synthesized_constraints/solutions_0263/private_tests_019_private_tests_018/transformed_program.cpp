#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int v[10];
int pos[8];
int k;
long long ans;
vector<int> adj[8];
int qtd = 0;
bool visi[10];

// Checkers for performance bottlenecks
void check_large_k_invariant(int k) {
    if (k == 8) {
        cerr << "Warning: Performance bottleneck condition triggered - high permutation count due to large k!" << endl;
        abort();
    }
}

void check_dfs_depth_invariant(int currentDepth, int maxDepth) {
    if (currentDepth > maxDepth) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive DFS recursion depth!" << endl;
        abort();
    }
}

void check_frequent_operations_invariant(int operationCount, int threshold) {
    if (operationCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent adjacency list operations!" << endl;
        abort();
    }
}

void dfs(int src, int currentDepth) {
    visi[src] = true;
    ++qtd;
    check_dfs_depth_invariant(currentDepth, 50); // Example threshold for DFS depth
    for (__typeof((adj[src]).begin()) it = (adj[src]).begin(); it != (adj[src]).end(); ++it)
        if (!visi[*it]) dfs(*it, currentDepth + 1);
}

bool ok() {
    int operationCount = 0; // Count the number of operations
    for (int i = 0; i < (k); ++i) {
        adj[i].clear();
        operationCount++;
    }
    for (int i = 0; i < (k); ++i) {
        adj[v[i]].push_back(i);
        operationCount++;
    }
    check_frequent_operations_invariant(operationCount, 100); // Example threshold for operations

    memset(visi, 0, sizeof(visi));
    qtd = 0;
    dfs(0, 0);
    return (qtd == k);
}

void solve(int p) {
    if (p == k) {
        if (ok()) ans = (ans + 1) % MOD;
    } else {
        for (int i = 0; i < (k); ++i) {
            v[p] = i;
            solve(p + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n >> k;
    check_large_k_invariant(k); // Check invariant for large k
    solve(0);
    long long pans = 1;
    for (int i = 0; i < (n - k); ++i) pans = (pans * (n - k)) % MOD;
    ans = (ans * pans) % MOD;
    cout << ans << endl;
    return 0;
}