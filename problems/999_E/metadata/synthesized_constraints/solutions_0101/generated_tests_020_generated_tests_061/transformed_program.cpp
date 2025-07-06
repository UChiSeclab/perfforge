#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const ll mod = 1e9 + 7;
const int N = 4005;
int n, m, s, c, c1;
vector<vector<int>> gp;
vector<bool> vis;
vector<int> tmp;

void check_disconnected_cities(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck - too many disconnected cities!" << endl;
        abort();
    }
}

void check_sparse_graph(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck - sparse graph, potentially excessive DFS!" << endl;
        abort();
    }
}

void dfs(int u) {
    vis[u] = 1;
    tmp.push_back(u);
    c++;
    c1++;
    for (int& v : gp[u])
        if (!vis[v]) dfs(v);
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    s--;
    gp = vector<vector<int>>(n);
    vis = vector<bool>(n);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        gp[--u].push_back(--v);
    }
    c = 0, c1 = 0;
    dfs(s);

    // Check for performance bottlenecks
    check_disconnected_cities(c < n / 2);  // If less than half the cities are reachable, alert
    check_sparse_graph(m < n / 4);         // If the number of roads is much less than cities, alert

    int ans = 0;
    while (c != n) {
        ans++;
        int mx = -1, u = -1;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                c1 = 0;
                tmp.clear();
                dfs(i);
                if (c1 > mx) mx = c1, u = i;
                for (int& j : tmp) vis[j] = 0, c--;
            }
        }
        dfs(u);
    }
    printf("%d", ans);
    return 0;
}