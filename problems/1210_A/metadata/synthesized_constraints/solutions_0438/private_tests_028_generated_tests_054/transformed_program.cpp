#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_graph_density(int n, int m) {
    if (m > (n * (n - 1)) / 2 * 0.8) {
        cerr << "Warning: Performance bottleneck condition triggered - graph is too dense!" << endl;
        abort();
    }
}

void check_unique_configurations(size_t config_count) {
    if (config_count > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered - too many unique domino configurations!" << endl;
        abort();
    }
}

void check_exhaustive_exploration(int n, int m) {
    if (n == 7 && m > 15) {
        cerr << "Warning: Performance bottleneck condition triggered - exhaustive exploration due to max vertices and edges near limit!" << endl;
        abort();
    }
}

// Original code
const long long mod = 1e9 + 7;
vector<vector<int>> v(8);
int val[10];
map<pair<int, int>, int> cnt;
bool ok = 1;
int vis[10];

bool dfs(int src) {
    vis[src] = 1;
    for (auto i : v[src]) {
        if (val[src] != 0 && val[i] != 0) {
            pair<int, int> p = make_pair(val[src], val[i]);
            if (p.first > p.second) swap(p.first, p.second);
            if (!cnt.count(p)) cnt[p]++;
        }
        if (vis[i] != 1) {
            bool ok1 = dfs(i);
            if (!ok1) return false;
        }
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;

    // Perform density check after reading inputs
    check_graph_density(n, m);

    for (int i = 0; i < m; i++) {
        int u, va;
        cin >> u >> va;
        v[u].push_back(va);
    }
    
    int ans = 0;
    for (int i1 = 0; i1 < 7; i1++) {
        val[1] = i1;
        for (int i2 = 0; i2 < 7; i2++) {
            val[2] = i2;
            for (int i3 = 0; i3 < 7; i3++) {
                val[3] = i3;
                for (int i4 = 0; i4 < 7; i4++) {
                    val[4] = i4;
                    for (int i5 = 0; i5 < 7; i5++) {
                        val[5] = i5;
                        for (int i6 = 0; i6 < 7; i6++) {
                            val[6] = i6;
                            for (int i7 = 0; i7 < 7; i7++) {
                                val[7] = i7;
                                memset(vis, -1, sizeof(vis));
                                for (int i = 1; i < 8; i++) {
                                    if (vis[i] != 1) ok = dfs(i);
                                }
                                if (ok) {
                                    ans = max(ans, (int)cnt.size());
                                    // Check unique configurations size
                                    check_unique_configurations(cnt.size());
                                }
                                ok = 1;
                                cnt.clear();
                            }
                        }
                    }
                }
            }
        }
    }

    // Perform exhaustive exploration check before output
    check_exhaustive_exploration(n, m);

    cout << ans;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long t = 1;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}