#include <bits/stdc++.h>
using namespace std;

int a[7];

// Check for high edge count relative to number of vertices
void check_high_edge_count(int n, int m) {
    if (m > (n * (n - 1)) / 4) {  // Arbitrary threshold for a high edge count
        cerr << "Warning: Performance bottleneck - High edge count relative to vertices!" << endl;
        abort();
    }
}

// Check for combinatorial explosion when the graph is highly connected
void check_combinatorial_explosion(int n, int m) {
    if ((m > 5) && (n == 7)) {  // Condition based on observed slowdowns
        cerr << "Warning: Performance bottleneck - Combinatorial explosion due to high connectivity!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;

    // Insert performance checks after reading inputs
    check_high_edge_count(n, m);
    check_combinatorial_explosion(n, m);

    set<pair<int, int>> e;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        e.emplace(u, v);
    }

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