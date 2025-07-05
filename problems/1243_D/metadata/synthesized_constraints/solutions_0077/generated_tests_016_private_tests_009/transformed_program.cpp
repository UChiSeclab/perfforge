#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> mp;
set<int> s;

// Function to check for sparse edge case
void check_sparse_edge_case_invariant(int n, int m) {
    if (n > 90000 && m < 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - large graph with few edges of weight 1!" << endl;
        abort();
    }
}

// Function to check for high recursion depth
void check_high_recursion_invariant(int n, int recursionDepth) {
    if (n > 50000 && recursionDepth > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - high recursion depth!" << endl;
        abort();
    }
}

// Function to check for set operations with large vertex count
void check_set_operations_invariant(int n, const set<int>& s) {
    if (n > 80000 && s.size() > 70000) {
        cerr << "Warning: Performance bottleneck condition triggered - extensive set operations with large vertex count!" << endl;
        abort();
    }
}

// Global variable to keep track of recursion depth
int currentRecursionDepth = 0;

void dfs(int x) {
    currentRecursionDepth++;
    vector<int> vec;
    for (int i : s) {
        if (mp[{x, i}] == 0) {
            vec.push_back(i);
        }
    }
    for (int i : vec) {
        s.erase(i);
    }
    for (int i : vec) {
        dfs(i);
    }
    currentRecursionDepth--;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    // Invariant check for sparse edge case
    check_sparse_edge_case_invariant(n, m);

    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }

    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        mp[{u, v}] = 1;
        mp[{v, u}] = 1;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s.size()) {
            v = *s.begin();
            ans++;
            s.erase(v);

            // Invariant check for set operations
            check_set_operations_invariant(n, s);

            dfs(v);

            // Invariant check for high recursion depth
            check_high_recursion_invariant(n, currentRecursionDepth);
        } else
            break;
    }

    cout << ans - 1 << "\n";
    return 0;
}