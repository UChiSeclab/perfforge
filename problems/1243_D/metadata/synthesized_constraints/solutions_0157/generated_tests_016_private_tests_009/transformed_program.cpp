#include <bits/stdc++.h>
using namespace std;

unordered_map<int, unordered_map<int, bool> > m;
int n, ma;
set<int> visited;

// Checker functions for performance bottlenecks
void check_sparse_graph_invariant(int n, int m) {
    if (m == 0 && n > 10000) { // Arbitrary threshold for "large" n
        cerr << "Warning: Performance bottleneck - sparse graph with large n. Excessive DFS expected." << endl;
        abort();
    }
}

void check_visited_set_invariant(int n, int m) {
    if (n > 50000 && m < n / 10) { // Threshold for large n and sparse edges
        cerr << "Warning: Performance bottleneck - inefficient operations on visited set due to large n and sparse edges." << endl;
        abort();
    }
}

void DFS(int v) {
    if (visited.find(v) != visited.end()) visited.erase(visited.find(v));
    int cur = -1;
    while (1) {
        auto itx = visited.upper_bound(cur);
        if (itx == visited.end()) break;
        cur = *itx;
        if (m[v][*itx] == 1) continue;
        DFS(*itx);
    }
}

int main() {
    cin >> n >> ma;
    
    // Insert performance checkers
    check_sparse_graph_invariant(n, ma); // Check for sparse graph performance bottleneck
    check_visited_set_invariant(n, ma); // Check for inefficiencies in visited set operations

    for (int i = 1; i <= ma; i++) {
        int a, b;
        cin >> a >> b;
        m[a][b] = 1;
        m[b][a] = 1;
    }
    
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        visited.insert(i);
    }
    
    int cur = -1;
    while (1) {
        auto itr = visited.upper_bound(cur);
        if (itr == visited.end()) break;
        DFS(*itr);
        cnt++;
    }
    
    cout << max(cnt - 1, 0);
}