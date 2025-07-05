#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using namespace std;

int dg[20];
int a[7];

void check_loop_invariant(int m, int n) {
    if (m > n * (n - 1) / 4) { // Arbitrary threshold, considering high edge density
        cerr << "Warning: Performance bottleneck due to high edge-to-vertex ratio." << endl;
        abort();
    }
}

void check_edges_invariant(const set<pair<int, int>>& e) {
    if (e.size() > 15) { // Assuming a threshold based on experimental observation and input constraints
        cerr << "Warning: Edge set size leads to excessive processing." << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> e;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        e.emplace(u, v);
    }

    check_loop_invariant(m, n); // Checking potential bottleneck due to high edge-to-vertex ratio
    check_edges_invariant(e);    // Checking potential bottleneck due to large edge set

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