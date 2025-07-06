#include <bits/stdc++.h>
using namespace std;

long long n, m, x, y, cnt;
set<long long> s;
map<pair<long long, long long>, bool> mp;

void dfs(int u) {
    if (s.empty()) return;
    vector<int> tmp;
    for (int v : s)
        if (!mp[{u, v}]) tmp.push_back(v);
    for (int v : tmp) s.erase(v);
    for (int v : tmp) dfs(v);
}

// Invariant check function to detect potential performance bottlenecks
void check_large_sparse_graph_invariant(long long n, long long m) {
    if (n > 50000 && m == 0) {  // Threshold for large n, sparse m
        cerr << "Warning: Performance bottleneck condition triggered due to large, sparse graph!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    // Check invariants after reading input
    check_large_sparse_graph_invariant(n, m);

    for (int i = 1; i <= n; i++) s.insert(i);
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        mp[{x, y}] = 1;
        mp[{y, x}] = 1;
    }

    while (!s.empty()) {
        cnt++;
        int u = *s.begin();
        s.erase(u);
        dfs(u);
    }
    cout << cnt - 1;
    return 0;
}