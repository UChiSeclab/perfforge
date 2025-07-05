#include <bits/stdc++.h>
using namespace std;

vector<bool> used;
vector<vector<int>> a;
int n, m;

// Checker functions
void check_initialization_invariant(int n, int m) {
    if (n > 10 * m) { // Arbitrary threshold: nodes significantly larger than edges
        cerr << "Warning: Initialization invariant triggered - n is significantly larger than m!" << endl;
        abort();
    }
}

void check_tree_condition_invariant(int n, int m) {
    if (n != m + 1) {
        cerr << "Warning: Tree condition invariant triggered - input does not form a tree structure!" << endl;
        abort();
    }
}

void check_sparse_graph_invariant(int n, int m) {
    if (n > 900 && m < n / 2) { // Arbitrary sparse threshold
        cerr << "Warning: Sparse graph invariant triggered - high n with low m!" << endl;
        abort();
    }
}

void dfs(int start) {
    int i;
    used[start] = true;
    for (i = 0; i < n; i++) {
        if ((a[start][i]) && (!used[i])) dfs(i);
    }
}

int main() {
    int i, j, f, s;
    vector<int> q;
    cin >> n >> m;

    // Inserting invariant checks
    check_initialization_invariant(n, m);
    check_tree_condition_invariant(n, m);
    check_sparse_graph_invariant(n, m);

    for (i = 0; i < n; i++) q.push_back(0);
    for (i = 0; i < n; i++) a.push_back(q);
    for (i = 0; i < n; i++) used.push_back(false);
    for (i = 0; i < m; i++) {
        cin >> f >> s;
        a[f - 1][s - 1] = 1;
        a[s - 1][f - 1] = 1;
    }

    if (n != m + 1) {
        cout << "no";
        return 0;
    }

    dfs(1);
    for (i = 0; i < n; i++) {
        if (!used[i]) {
            cout << "no";
            return 0;
        }
    }
    cout << "yes";
    return 0;
}