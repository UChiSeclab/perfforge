#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
const int MAXN = 8;
const int MAXC = 7;
int used[MAXC][MAXC];

void check_high_edge_count_invariant(int n, int m) {
    if (m > n * (n-1) / 2 * 0.8) { // 80% of maximum edges possible
        cerr << "Warning: Performance bottleneck condition triggered - high edge count relative to vertices!" << endl;
        abort();
    }
}

void check_dense_graph_invariant(int n, int m) {
    if (m > n) { // If the number of edges exceeds the number of vertices, graph may be dense
        cerr << "Warning: Performance bottleneck condition triggered - dense graph!" << endl;
        abort();
    }
}

void check_edge_dominated_iterations(int n, int m) {
    if (n > 5 && m > 10) { // Arbitrary threshold for large edge-to-vertex ratio
        cerr << "Warning: Performance bottleneck condition triggered - large edge-to-vertex ratio!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    // Insert checks after reading inputs
    check_high_edge_count_invariant(n, m);
    check_dense_graph_invariant(n, m);
    check_edge_dominated_iterations(n, m);

    vector<pair<int, int> > e;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        e.emplace_back(a, b);
    }

    vector<int> b(7);
    int ans = 0;
    for (int a0 = 0; a0 < 7; ++a0) {
        for (int a1 = 0; a1 < 7; ++a1) {
            for (int a2 = 0; a2 < 7; ++a2) {
                for (int a3 = 0; a3 < 7; ++a3) {
                    for (int a4 = 0; a4 < 7; ++a4) {
                        for (int a5 = 0; a5 < 7; ++a5) {
                            for (int a6 = 0; a6 < 7; ++a6) {
                                b[0] = a0;
                                b[1] = a1;
                                b[2] = a2;
                                b[3] = a3;
                                b[4] = a4;
                                b[5] = a5;
                                b[6] = a6;
                                int res = 0;
                                memset(used, false, sizeof used);
                                for (auto &ee : e) {
                                    if (b[ee.first] == 0 || b[ee.second] == 0) continue;
                                    if (!used[b[ee.first]][b[ee.second]]) {
                                        ++res;
                                        used[b[ee.first]][b[ee.second]] = 1;
                                        used[b[ee.second]][b[ee.first]] = 1;
                                    }
                                }
                                ans = max(ans, res);
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}