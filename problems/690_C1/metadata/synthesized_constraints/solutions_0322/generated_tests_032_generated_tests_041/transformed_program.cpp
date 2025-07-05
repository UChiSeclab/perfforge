#include <bits/stdc++.h>
using namespace std;

// Checker function for matrix initialization invariants
void check_matrix_initialization_invariant(int n, int m) {
    if (n > 500 && m < n / 2) {  // Example condition: n is large and m is significantly smaller
        cerr << "Warning: Potential bottleneck due to large matrix initialization for sparse graph" << endl;
        abort();
    }
}

// Checker function for tree property invariant
void check_tree_property_invariant(int n, int m) {
    if (m != n - 1) {
        cerr << "Warning: Graph is not a tree, unnecessary operations may follow" << endl;
        abort();
    }
}

// Checker function for graph representation invariants
void check_graph_representation_invariant(int n, int m) {
    if (n > 500 && m < n) {  // Example threshold suggesting sparse graph
        cerr << "Warning: Inefficient graph representation for sparse graph" << endl;
        abort();
    }
}

bool cycle = false;
void DFS(int** matrix, int n, int sv, bool* visited) {
    visited[sv] = true;
    for (int i = 0; i < n; i++) {
        if (i == sv) continue;
        if (matrix[sv][i] == 1) {
            if (visited[i]) {
                continue;
            }
            DFS(matrix, n, i, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Integrate checker functions after reading input
    check_matrix_initialization_invariant(n, m);
    check_tree_property_invariant(n, m);
    check_graph_representation_invariant(n, m);

    int** matrix = new int*[n];
    int x, y;
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
    bool visited[n];
    for (int i = 0; i < n; i++) visited[i] = false;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        matrix[x - 1][y - 1] = 1;
        matrix[y - 1][x - 1] = 1;
    }
    if (m != n - 1) {
        cout << "no";
    } else {
        DFS(matrix, n, 0, visited);
        if (cycle == false) {
            for (int i = 0; i < n; i++) {
                if (visited[i] == false) {
                    cout << "no";
                    return 0;
                }
            }
            cout << "yes";
        }
    }
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}