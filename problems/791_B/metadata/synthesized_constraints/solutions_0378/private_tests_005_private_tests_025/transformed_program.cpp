#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance invariants
void check_initialization_and_sorting_invariant(int n, int m) {
    if (n > 10000 && m == 0) {
        cerr << "Warning: Performance bottleneck condition triggered - unnecessary initialization and sorting with no friendships." << endl;
        abort();
    }
}

void check_redundant_equality_checks(int m) {
    if (m == 0) {
        cerr << "Warning: Performance bottleneck condition triggered - redundant equality checks with no friendships." << endl;
        abort();
    }
}

void check_inefficient_sorting(int n, const vector<int>* v) {
    for (int i = 1; i <= n; ++i) {
        if (v[i].size() <= 1) {
            cerr << "Warning: Performance bottleneck condition triggered - inefficient sorting on small vectors." << endl;
            abort();
        }
    }
}

int main() {
    int i, j, a, b, n, m;
    cin >> n >> m;
    
    // Check for initialization and sorting invariant
    check_initialization_and_sorting_invariant(n, m);
    
    vector<int> v[n + 1];
    for (i = 1; i <= n; i++) {
        v[i].push_back(i);
    }
    for (i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    // Check for inefficient sorting invariant
    check_inefficient_sorting(n, v);
    
    for (i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
    }
    
    // Check for redundant equality checks invariant
    check_redundant_equality_checks(m);
    
    int flag = 1;
    for (i = 1; i <= n; i++) {
        for (j = 0; j < v[i].size(); j++) {
            if (!equal(v[i].begin(), v[i].end(), v[v[i][j]].begin())) {
                flag = 0;
                break;
            }
        }
        if (flag == 0) {
            cout << "NO";
            break;
        }
    }
    if (flag == 1) {
        cout << "YES";
    }
}