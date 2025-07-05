#include <bits/stdc++.h>
using namespace std;

void check_disconnected_components_invariant(long long n, long long m, long long cn) {
    if (m < n - 1) {
        cerr << "Warning: Disconnected components detected - high DFS calls!" << endl;
        abort();
    }
}

void check_sparse_connections_invariant(long long n, long long m) {
    if (n > 500 && m < n - 1) {
        cerr << "Warning: Sparse connections in large graph - potential slow DFS!" << endl;
        abort();
    }
}

void check_isolated_nodes_invariant(const vector<long long>& degrees, long long n) {
    long long isolated_nodes = count(degrees.begin(), degrees.end(), 0);
    if (isolated_nodes > n / 2) {
        cerr << "Warning: Many isolated nodes - excessive DFS initializations!" << endl;
        abort();
    }
}

long long n, m;
unordered_map<long long, vector<long long>> adj;
vector<long long> vis;
vector<long long> degrees;

void dfs(long long src) {
    vis[src] = 1;
    for (auto x : adj[src]) {
        if (vis[x] == -1) {
            dfs(x);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vis.resize(n + 1, -1);
    degrees.resize(n + 1, 0);
    
    for (long long i = 1; i <= m; i++) {
        long long a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        degrees[a]++;
        degrees[b]++;
    }
    
    long long cn = 0;
    for (long long i = 1; i <= n; i++) {
        if (vis[i] == -1) {
            dfs(i);
            cn++;
        }
    }

    // Insert checks after DFS has processed the graph
    check_disconnected_components_invariant(n, m, cn);
    check_sparse_connections_invariant(n, m);
    check_isolated_nodes_invariant(degrees, n);

    if (m == n - 1 && cn == 1) {
        cout << "yes";
    } else {
        cout << "no";
    }
    
    return 0;
}