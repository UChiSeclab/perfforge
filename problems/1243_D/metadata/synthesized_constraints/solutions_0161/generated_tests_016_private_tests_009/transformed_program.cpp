#include <bits/stdc++.h>
using namespace std;

// Check for large vertex count with no weight-1 edges
void check_large_vertex_no_weight_one_invariant(int n, int m) {
    if (n > 10000 && m == 0) { // Using a threshold for 'large' based on problem constraints
        cerr << "Warning: Performance bottleneck condition triggered - High vertex count with no weight-1 edges!" << endl;
        abort();
    }
}

// Check for inefficient set operations due to low weight-1 edge count
void check_inefficient_set_operations_invariant(int n, int m) {
    if (n > 10000 && m < n / 10) { // Assuming inefficiency when m is much smaller than n
        cerr << "Warning: Performance bottleneck condition triggered - Inefficient set operations due to low weight-1 edge count!" << endl;
        abort();
    }
}

unordered_map<int, unordered_map<int, bool> > m;
int n, ma;
set<int> visited;

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
    
    // Perform invariant checks after reading inputs
    check_large_vertex_no_weight_one_invariant(n, ma);
    check_inefficient_set_operations_invariant(n, ma);

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