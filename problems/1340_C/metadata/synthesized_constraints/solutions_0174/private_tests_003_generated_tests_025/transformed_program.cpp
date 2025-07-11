#include <bits/stdc++.h>
using namespace std;

long long f[10001][1001];
int n, m, r, g;
int a[10001];
vector<pair<long long, pair<int, int> > > q[10011];
set<int> w;

// Check performance invariants
void check_path_invariant(size_t queueSize) {
    if (queueSize > 10000) {  // Arbitrary threshold for excessive path exploration
        cerr << "Warning: Performance bottleneck condition triggered - excessive path exploration!" << endl;
        abort();
    }
}

void check_light_cycle_invariant(int g, int r, int maxIslandDistance) {
    if (g < maxIslandDistance) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient light cycle!" << endl;
        abort();
    }
}

void check_state_reexploration_invariant(int stateCount) {
    if (stateCount > 5000) {  // Example threshold for excessive state exploration
        cerr << "Warning: Performance bottleneck condition triggered - excessive state re-exploration!" << endl;
        abort();
    }
}

// Helper function to update queue and state
void update(long long v, int x, int y) {
    if (x == 1 && !y) return;
    if (!f[x][y] || f[x][y] > v) {
        f[x][y] = v;
        int tmp = y + ((v / (r + g)) % 4) * (r + g);
        if (q[tmp].empty()) w.insert(tmp);
        q[tmp].push_back({v, {x, y}});
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
    sort(a + 1, a + m + 1);
    q[0].push_back({0, {1, 0}});
    scanf("%d %d", &g, &r);

    // Check light cycle invariant
    int maxIslandDistance = 0;
    for (int i = 1; i < m; ++i) {
        maxIslandDistance = max(maxIslandDistance, a[i + 1] - a[i]);
    }
    check_light_cycle_invariant(g, r, maxIslandDistance);

    int i = 0;
    w.insert(0);
    while (1) {
        check_state_reexploration_invariant(w.size());

        for (auto v : q[i]) {
            auto u = v;
            if (u.first != f[u.second.first][u.second.second]) continue;
            if (u.second.first == m) {
                printf("%lld\n", u.first);
                return 0;
            }
            if (u.second.second == g) u.second.second = 0, u.first += r;
            if (u.second.first > 1) {
                if (u.second.second + a[u.second.first] - a[u.second.first - 1] <= g)
                    update(u.first + a[u.second.first] - a[u.second.first - 1],
                           u.second.first - 1,
                           u.second.second + a[u.second.first] - a[u.second.first - 1]);
            }
            if (u.second.second + a[u.second.first + 1] - a[u.second.first] <= g)
                update(u.first + a[u.second.first + 1] - a[u.second.first],
                       u.second.first + 1,
                       u.second.second + a[u.second.first + 1] - a[u.second.first]);
        }
        q[i].clear();
        w.erase(i);
        
        check_path_invariant(w.size());

        if (w.empty()) break;
        auto u = w.upper_bound(i);
        if (u == w.end()) {
            i = *(w.begin());
        } else {
            i = *u;
        }
    }
    puts("-1");
    return 0;
}