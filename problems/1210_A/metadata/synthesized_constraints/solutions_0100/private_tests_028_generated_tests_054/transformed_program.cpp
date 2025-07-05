#include <bits/stdc++.h>
using namespace std;

vector<string> v;
vector<pair<int, int> > adj;
int n, m;

void f(int i, string str) {
    if (i == 7) {
        v.push_back(str);
        return;
    }
    for (int j = i; j < 7; j++) {
        swap(str[i], str[j]);
        f(i + 1, str);
        swap(str[i], str[j]);
    }
}

// Checker functions based on performance-characterizing invariants
void check_edge_permutation_invariant(int n, int m, size_t v_size) {
    if (m > n * (n - 1) / 4 && v_size > 30000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive edge combinations!" << endl;
        abort();
    }
}

void check_permutation_overhead_invariant(int m, size_t v_size) {
    if (m > 10 && v_size > 30000) {
        cerr << "Warning: Performance bottleneck condition triggered - permutation overhead!" << endl;
        abort();
    }
}

void check_graph_density_invariant(int m, int n) {
    if (m == n * (n - 1) / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - high graph density!" << endl;
        abort();
    }
}

void check_redundant_checks_invariant(int m, size_t v_size) {
    if (m > 15 && v_size > 30000) {
        cerr << "Warning: Performance bottleneck condition triggered - redundant checks in dense graphs!" << endl;
        abort();
    }
}

int main() {
    string abc = "0123456";
    for (int i = 1; i <= 6; i++) {
        abc[0] = 48 + i;
        f(0, abc);
    }

    cin >> n >> m;
    int i, j, a, b;
    for (i = 0; i < m; i++) {
        cin >> a >> b;
        adj.push_back({a, b});
    }

    // Place the checkers after input and permutation generation
    check_edge_permutation_invariant(n, m, v.size());
    check_permutation_overhead_invariant(m, v.size());
    check_graph_density_invariant(m, n);
    check_redundant_checks_invariant(m, v.size());

    int ans = 0;
    for (i = 0; i < v.size(); i++) {
        map<int, map<int, int> > vis;
        int an = 0;
        int arr[8] = {0};
        for (int k = 1; k < 8; k++) {
            arr[k] = v[i][k - 1] - '0';
        }
        for (j = 0; j < m; j++) {
            int a = arr[adj[j].first];
            int b = arr[adj[j].second];
            int A = min(a, b);
            int B = max(a, b);
            if (vis[A][B] == 0) {
                an++;
                vis[A][B] = 1;
            }
        }
        ans = max(an, ans);
    }
    cout << ans;
    return 0;
}