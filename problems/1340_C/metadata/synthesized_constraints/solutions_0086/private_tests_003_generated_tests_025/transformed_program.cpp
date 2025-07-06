#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7, M = 1009;
const long long INF = LLONG_MAX;
int arr[N + 2], n, m, G, R;
long long dis[N][M];
bitset<M> vis[N];

void check_large_green_light(int G, int m) {
    if (G > (m / 2)) { // arbitrary threshold: G is larger than half the number of islands
        cerr << "Warning: Large green light duration relative to safety islands!" << endl;
        abort();
    }
}

void check_large_island_gaps(int G, const vector<int>& islands) {
    for (size_t i = 1; i < islands.size(); ++i) {
        if ((islands[i] - islands[i - 1]) > (G / 2)) { // arbitrary: gap larger than half of G
            cerr << "Warning: Large gap between safety islands detected!" << endl;
            abort();
        }
    }
}

void check_excessive_queue_operations(int queueLength, int threshold) {
    if (queueLength > threshold) { // arbitrary threshold for queue length
        cerr << "Warning: Excessive queue operations detected!" << endl;
        abort();
    }
}

long long getit() {
    for (int i = 0; i < (int)m; i++)
        for (int j = 0; j < (int)G + 1; j++) dis[i][j] = INF;
    queue<pair<int, int> > q[G + 1];
    int cur = 0;
    q[cur].push({0, G});
    vis[0][G] = 1;
    dis[0][G] = 0;
    set<int> st = {cur};
    auto check = [&](long long w, int idx, int g, int edge_weight) {
        if (idx < 0 or idx >= m or g < 0) return false;
        pair<int, int> nxt = {idx, g};
        int ndis = w + edge_weight;
        if (dis[nxt.first][nxt.second] > ndis) {
            vis[nxt.first][nxt.second] = 1;
            dis[nxt.first][nxt.second] = ndis;
            int y = (cur + edge_weight) % (G + 1);
            st.insert(y);
            q[y].push(nxt);
            check_excessive_queue_operations(q[y].size(), 1000); // Check queue length
        }
        return true;
    };
    long long ans = INF;
    while (st.size()) {
        auto x = st.lower_bound(cur);
        if (x == st.end()) x = st.begin();
        cur = *x;
        pair<int, int> f = q[cur].front();
        q[cur].pop();
        long long id = f.first, g = f.second, w = dis[f.first][f.second];
        int edge_weight = R;
        int nx = arr[id + 1], pr = -1, cr = arr[id];
        if (id) pr = arr[id - 1];
        if (id == m - 1) ans = min(ans, w);
        edge_weight = abs(cr - nx);
        check(w, id + 1, g - edge_weight, edge_weight);
        edge_weight = abs(cr - pr);
        check(w, id - 1, g - edge_weight, edge_weight);
        if (!g) check(w, id, G, R);
        if (q[cur].empty()) st.erase(cur);
    }
    if (ans == INF) ans = -1;
    return ans;
}

void solve() {
    cin >> n >> m;
    vector<int> islands(m);
    for (int i = 0; i < (int)m; i++) {
        cin >> arr[i];
        islands[i] = arr[i];
    }
    sort(arr, arr + m);
    sort(islands.begin(), islands.end());
    cin >> G >> R;
    check_large_green_light(G, m); // Check 1: Large green light duration
    check_large_island_gaps(G, islands); // Check 2: Large gap between safety islands
    cout << getit();
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test = 1;
    while (test--) solve();
}