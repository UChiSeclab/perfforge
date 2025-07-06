#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_high_degree_invariant(const vector<vector<int>>& graph, int n) {
    for (int i = 1; i <= n; ++i) {
        if (graph[i].size() > 4) {  // Consider a high degree to be greater than 4 for n ≤ 7
            cerr << "Warning: Performance bottleneck condition triggered - high degree of vertices!" << endl;
            abort();
        }
    }
}

void check_dense_graph_invariant(int n, int m) {
    // A dense graph for n vertices would have close to n*(n-1)/2 edges
    if (m > (n * (n - 1)) / 3) {  // Use a fraction of the complete graph edges as a threshold
        cerr << "Warning: Performance bottleneck condition triggered - dense graph structure!" << endl;
        abort();
    }
}

void check_symmetrical_configurations_invariant(const vector<vector<int>>& graph, int n) {
    // Check for symmetrical configurations, e.g., multiple identical subgraphs
    // This is a simplistic check; for illustration, assume symmetry if each vertex connects to the same number of other vertices
    int common_degree = graph[1].size();
    for (int i = 2; i <= n; ++i) {
        if (graph[i].size() != common_degree) {
            return;  // Not symmetrical, skip further check
        }
    }
    cerr << "Warning: Performance bottleneck condition triggered - symmetrical configurations!" << endl;
    abort();
}

int n, m;
int node[8];
vector<vector<int>> gr;

int countDom() {
    int dom[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) dom[i][j] = 0;
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int v : gr[i]) {
            if (!dom[node[i]][node[v]]) {
                dom[node[i]][node[v]] = dom[node[v]][node[i]] = 1;
                ans++;
            }
        }
    }
    if (ans == 21) {
        for (int i = 0; i < n; i++) {
            cout << node[i] << " ";
        }
        cout << "\n";
    }
    return ans;
}

int solve() {
    int ans = 0;
    while (node[1] != 2) {
        int i = 7;
        ans = max(ans, countDom());
        while (++node[i] == 7) {
            node[i--] = 1;
        }
    }
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < 8; i++) node[i] = 1;
    gr.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    
    // Insert checks after graph construction
    check_high_degree_invariant(gr, n);  // Check for high degree vertices
    check_dense_graph_invariant(n, m);   // Check for dense graph structure
    check_symmetrical_configurations_invariant(gr, n);  // Check for symmetrical configurations
    
    cout << solve();
    cin >> n;
    return 0;
}