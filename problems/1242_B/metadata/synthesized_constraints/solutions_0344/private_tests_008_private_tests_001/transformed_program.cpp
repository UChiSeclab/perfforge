#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, INF = 1e9;
int n, m, dis[N], vis[N], ans;
vector<set<int> > g;
set<int> e;
set<pair<int, int> > q;

// Checker for large input size with sparse graph
void check_large_sparse_graph(int n, int m) {
    if (n > 50000 && m < 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - large input size with sparse graph!" << endl;
        abort();
    }
}

// Checker for high iteration count with minimal updates
void check_high_iteration_no_update(int n, int m) {
    if (n > 90000 && m == 0) {
        cerr << "Warning: Performance bottleneck condition triggered - high iteration count with minimal updates!" << endl;
        abort();
    }
}

// Checker for dense set operations in loop
void check_dense_set_operations(int n) {
    if (n > 80000) {
        cerr << "Warning: Performance bottleneck condition triggered - dense set operations in loop!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    
    // Run checkers after reading inputs
    check_large_sparse_graph(n, m);
    check_high_iteration_no_update(n, m);
    check_dense_set_operations(n);
    
    g.resize(n);
    
    // Reading edges of weight 1
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].insert(v);
        g[v].insert(u);
    }
    
    // Initialize distances and set of vertices
    for (int i = 0; i < n; i++) {
        dis[i] = INF;
        e.insert(i);
    }
    
    dis[0] = 0;
    q.insert({0, 0});
    e.erase(0);
    
    // Main loop for processing vertices
    while (!q.empty()) {
        int w = (*q.begin()).first;
        int u = (*q.begin()).second;
        q.erase(q.begin());
        if (vis[u] == 1) {
            continue;
        }
        vis[u] = 1;
        e.erase(u);
        ans += w;
        set<int> t = e;
        for (auto x : t) {
            if (g[u].find(x) == g[u].end()) {
                e.erase(x);
                q.insert({0, x});
            }
        }
        for (auto v : g[u]) {
            if (!vis[v] && e.find(v) != e.end()) {
                q.insert({1, v});
            }
        }
    }
    cout << ans << "\n";
}