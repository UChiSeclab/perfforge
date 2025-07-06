#include <bits/stdc++.h>
#pragma GCC optimize "-O3"
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using namespace std;
int dg[20];
int a[7];

// Function to check graph density
void check_graph_density(int n, int m) {
    int maxEdges = n * (n - 1) / 2;
    if (m > 0.9 * maxEdges) {
        cerr << "Warning: Performance bottleneck due to high graph density!" << endl;
        abort();
    }
}

// Function to check edge connections
void check_edge_connections(int m, int n) {
    if (m > n * (n - 1) / 4) { // Arbitrarily using a quarter of the maximum edges as a threshold
        cerr << "Warning: Performance bottleneck due to dense edge connections!" << endl;
        abort();
    }
}

// Function to check vertex degree
void check_vertex_degree(const vector<int>& degrees, int n) {
    for (int degree : degrees) {
        if (degree > n - 1) { // If any vertex has degree close to n-1
            cerr << "Warning: Performance bottleneck due to high vertex degree!" << endl;
            abort();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;

    // Check graph density and edge connections early
    check_graph_density(n, m);
    check_edge_connections(m, n);

    set<pair<int, int>> e;
    vector<int> degrees(n, 0); // Track vertex degrees
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        e.emplace(u, v);
        degrees[u]++;
        degrees[v]++;
    }

    // Check vertex degree after reading all edges
    check_vertex_degree(degrees, n);

    int ans = 0;
    for (a[0] = 0; a[0] < 6; a[0]++) {
        for (a[1] = 0; a[1] < 6; a[1]++) {
            for (a[2] = 0; a[2] < 6; a[2]++) {
                for (a[3] = 0; a[3] < 6; a[3]++) {
                    for (a[4] = 0; a[4] < 6; a[4]++) {
                        for (a[5] = 0; a[5] < 6; a[5]++) {
                            for (a[6] = 0; a[6] < 6; a[6]++) {
                                set<pair<int, int>> gao;
                                for (auto ed : e) {
                                    int u = a[ed.first], v = a[ed.second];
                                    if (u > v) {
                                        swap(u, v);
                                    }
                                    gao.emplace(u, v);
                                    ans = max(ans, (int)gao.size());
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}