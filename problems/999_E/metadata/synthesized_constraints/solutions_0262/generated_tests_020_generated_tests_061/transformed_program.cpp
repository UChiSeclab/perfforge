#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const ll mod = 1e9 + 7;
const int N = 4005;
int n, m, s, c, c1;
vector<vector<int>> gp;
vector<bool> vis;
vector<int> tmp;

void dfs(int u) {
    vis[u] = 1;
    tmp.push_back(u);
    c++;
    c1++;
    for (int& v : gp[u])
        if (!vis[v]) dfs(v);
}

void check_dfs_calls(int dfsCallCount, int threshold) {
    if (dfsCallCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive DFS calls!" << endl;
        abort();
    }
}

void check_graph_traversal(int traversalCount, int n) {
    if (traversalCount > 10 * n) { // Assuming a threshold of 10 times the number of cities
        cerr << "Warning: Performance bottleneck condition triggered - excessive graph traversals!" << endl;
        abort();
    }
}

void check_sparse_connections(int n, int m) {
    if (m < n / 10) { // Assuming sparse if roads are less than 10% of cities
        cerr << "Warning: Performance bottleneck condition triggered - sparse connections!" << endl;
        abort();
    }
}

void check_connectivity_attempts(int attempts, int n) {
    if (attempts > n * n) { // Assuming inefficient if attempts exceed n^2
        cerr << "Warning: Performance bottleneck condition triggered - inefficient connectivity checking!" << endl;
        abort();
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    s--;
    gp = vector<vector<int>>(n);
    vis = vector<bool>(n);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        gp[--u].push_back(--v);
    }

    // Check for sparse connections at the start
    check_sparse_connections(n, m);

    c = 0, c1 = 0;
    dfs(s);

    int totalDfsCalls = 0; // Counter for DFS calls
    int traversalCount = 0; // Counter for total graph traversals
    int connectivityAttempts = 0; // Counter for connectivity attempts

    int ans = 0;
    while (c != n) {
        ans++;
        int mx = -1, u = -1;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                c1 = 0;
                tmp.clear();
                dfs(i);
                totalDfsCalls++;
                connectivityAttempts++;
                if (c1 > mx) mx = c1, u = i;
                for (int& j : tmp) vis[j] = 0, c--;
            }
        }
        dfs(u);
        totalDfsCalls++;
        traversalCount++;
        gp[s].push_back(u);
    }

    // Check for performance bottlenecks
    check_dfs_calls(totalDfsCalls, 10000); // Example threshold
    check_graph_traversal(traversalCount, n);
    check_connectivity_attempts(connectivityAttempts, n);

    printf("%d", ans);
    return 0;
}