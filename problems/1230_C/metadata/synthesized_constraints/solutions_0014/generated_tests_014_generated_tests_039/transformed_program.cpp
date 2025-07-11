#include <bits/stdc++.h>
using namespace std;

// Checker for high edge count impact
void check_edge_count_invariant(int n, int m) {
    int maxEdges = (n * (n - 1)) / 2;
    if (m > maxEdges * 0.9) { // Example threshold: 90% of maximum
        cerr << "Warning: edge_count_invariant triggered - high number of edges" << endl;
        abort();
    }
}

// Checker for permutation and edge interaction complexity
void check_permutation_edge_invariant(int n, int m) {
    if (m > 10) { // Threshold chosen based on maximum potential complexity
        cerr << "Warning: permutation_edge_invariant triggered - complex interactions" << endl;
        abort();
    }
}

// Checker for set insertion overhead
void check_set_insertion_invariant(int setSize) {
    if (setSize > 15) { // Threshold near the upper limit of possible unique dominoes
        cerr << "Warning: set_insertion_invariant triggered - large set of configurations" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    // Check high edge count invariant
    check_edge_count_invariant(n, m);
    
    vector<vector<int> > graph(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> p(7);
    iota(p.begin(), p.end(), 0);
    int ans = 0;

    do {
        for (int x = 1; x <= 6; x++) {
            set<pair<int, int> > se;
            for (int i = 0; i < n; i++) {
                if (p[i] == 0) {
                    p[i] = x;
                    break;
                }
            }
            for (int u = 0; u < n; u++) {
                for (int v : graph[u]) {
                    if (p[u] && p[v]) {
                        se.insert(make_pair(min(p[u], p[v]), max(p[u], p[v])));
                    }
                }
            }
            // Check set insertion overhead
            check_set_insertion_invariant(se.size());
            ans = max(ans, (int)se.size());
        }
    } while (next_permutation(p.begin(), p.end()));

    cout << ans << '\n';
    return 0;
}