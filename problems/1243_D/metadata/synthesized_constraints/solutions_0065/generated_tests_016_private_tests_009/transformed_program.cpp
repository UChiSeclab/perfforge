#include <bits/stdc++.h>
using namespace std;

// Checkers for performance bottleneck conditions
void check_sparse_graph_invariant(int n, int m) {
    if (m < n / 10) {
        cerr << "Warning: Performance bottleneck condition triggered - graph is too sparse with many vertices!" << endl;
        abort();
    }
}

void check_vertex_pair_invariant(int n, int m) {
    if (m < n / 100) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient vertex pair checking!" << endl;
        abort();
    }
}

void check_iteration_invariant(int n, int m) {
    if (m == 0 && n > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - high iteration count due to large set size!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, ans = 0;
    cin >> n >> m;

    // Insert checks after reading n and m
    check_sparse_graph_invariant(n, m);
    check_vertex_pair_invariant(n, m);
    check_iteration_invariant(n, m);

    map<pair<int, int>, bool> vis;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        vis[{u, v}] = 1;
        vis[{v, u}] = 1;
    }

    set<int> st;
    for (int i = 1; i <= n; i++) st.insert(i);
    vector<int> cur, New;
    while (!st.empty()) {
        if (New.empty()) {
            ans++;
            New.push_back(*st.begin());
        }
        for (auto v : New) st.erase(v);
        cur.swap(New);
        New.clear();
        for (auto v : st) {
            for (auto u : cur) {
                if (vis[{u, v}]) continue;
                New.push_back(v);
                break;
            }
        }
    }
    cout << ans - 1 << endl;
    return 0;
}