#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100005];
int par[100005];

int fnd(int u) {
    return par[u] = par[u] == u ? u : fnd(par[u]);
}

void unn(int u, int v) {
    u = fnd(u), v = fnd(v);
    par[u] = v;
}

void check_union_find_invariant(int n, int m, int numFindCalls) {
    if (n > 50000 && m < 1000 && numFindCalls > 10000000) {
        cerr << "Warning: Union-Find performance bottleneck condition triggered!" << endl;
        abort();
    }
}

void check_loop_invariant(int n, size_t totalConnections) {
    if (n > 50000 && totalConnections > 100000000) {
        cerr << "Warning: Loop performance bottleneck condition triggered!" << endl;
        abort();
    }
}

void check_sparse_graph_invariant(int n, int m) {
    if (n > 50000 && m < n / 10) {
        cerr << "Warning: Sparse graph performance inefficiency condition triggered!" << endl;
        abort();
    }
}

int main() {
    srand(time(0));
    scanf("%d%d", &n, &m);
    iota(par, par + n + 1, 0);
    for (int a, b, i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int numFindCalls = 0;
    size_t totalConnections = 0;

    for (int i = 1; i <= n; i++) {
        vector<int> conn;
        adj[i].push_back(0);
        adj[i].push_back(i);
        adj[i].push_back(n + 1);
        sort(adj[i].begin(), adj[i].end());

        if (n - adj[i].size() + 2 <= 100) {
            int nt = 1;
            for (int j : adj[i]) {
                while (nt < j) conn.push_back(nt++);
                if (nt == j) nt++;
            }
        } else {
            vector<pair<int, int>> rngs;
            for (int j = 1; j < adj[i].size(); j++)
                if (adj[i][j] - adj[i][j - 1] > 1)
                    rngs.push_back({adj[i][j] - adj[i][j - 1] - 1, adj[i][j - 1] + 1});
            for (int j = 1; j < rngs.size(); j++) rngs[j].first += rngs[j - 1].first;
            while (conn.size() < min(100, n - 1)) {
                int tk = rand() % rngs.back().first + 1;
                int st = 0, en = rngs.size() - 1, mid;
                while (st <= en) {
                    mid = (st + en) >> 1;
                    if (rngs[mid].first < tk)
                        st = mid + 1;
                    else
                        en = mid - 1;
                }
                int ad = tk - (st ? rngs[st - 1].first : 0) + rngs[st].second - 1;
                conn.push_back(ad);
            }
        }
        totalConnections += conn.size();
        for (int j : conn) {
            unn(i, j);
            numFindCalls++;
        }
    }

    check_union_find_invariant(n, m, numFindCalls);
    check_loop_invariant(n, totalConnections);
    check_sparse_graph_invariant(n, m);

    int ans = -1;
    for (int i = 1; i <= n; i++) ans += (i == fnd(i));
    printf("%d\n", ans);
}