#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int n, m, c;
vector<int> adj[N], temp, b[N];
bool vis[N], mk[N];
vector<pair<int, int> > v, ans;

void dfs(int nd) {
    vis[nd] = 1;
    for (auto u : adj[nd]) {
        if (!vis[u]) dfs(u);
    }
}

void check_dfs_call_frequency(int dfsCallCount, int cityCount) {
    if (dfsCallCount > cityCount * 10) {
        cerr << "Warning: Performance bottleneck triggered - excessive DFS calls due to sparse connections!" << endl;
        abort();
    }
}

void check_visited_reset_frequency(int resetCount, int cityCount) {
    if (resetCount > cityCount * 5) {
        cerr << "Warning: Performance bottleneck triggered - excessive resets of visited array!" << endl;
        abort();
    }
}

void check_unreachable_cities(int unreachableCount, int cityCount) {
    if (unreachableCount > cityCount / 2) {
        cerr << "Warning: Performance bottleneck triggered - many cities are initially unreachable!" << endl;
        abort();
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, c;
    cin >> n >> m >> c;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // Initial DFS call from the capital
    int dfsCallCount = 0;
    dfs(c);
    dfsCallCount++;

    // Check for the first invariant after initial DFS
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) temp.push_back(i);
    }

    // Check for many initially unreachable cities
    check_unreachable_cities(temp.size(), n);

    // Iterate over unreachable cities and perform DFS
    int resetCount = 0;
    for (auto u : temp) {
        fill(vis, vis + n + 1, false);
        resetCount++;
        dfs(u);
        dfsCallCount++;
        mk[u] = 1;
        for (int i = 1; i <= n; i++) {
            if (vis[i])
                b[u].push_back(i);
        }
    }

    // Check for the second invariant about visited array resets
    check_visited_reset_frequency(resetCount, n);

    // Check for the first invariant about DFS call frequency
    check_dfs_call_frequency(dfsCallCount, n);

    for (int i = 1; i <= n; i++) {
        if (!mk[i]) continue;
        ans.push_back({b[i].size(), i});
    }
    sort(ans.begin(), ans.end(), greater<pair<int, int> >());
    fill(vis, vis + n + 1, false);
    dfs(c);

    int cnt = 0;
    for (auto u : ans) {
        if (vis[u.second]) continue;
        cnt++;
        for (auto nd : b[u.second]) {
            vis[nd] = 1;
        }
    }

    cout << cnt << endl;
    return 0;
}