#include <bits/stdc++.h>
using namespace std;

int n, m;
int mp[14][14], res[14];
int ans;
int go[54][54], lk[54];
bool vis[54];
int dfsCallCount = 0;  // To count DFS calls

void check_combinatorial_complexity(int n) {
    if (n == 7) {
        cerr << "Warning: Combinatorial complexity triggered - maximum recursion depth in reCov" << endl;
        abort();
    }
}

void check_dfs_calls(int dfsCallCount) {
    if (dfsCallCount > 5000000) {
        cerr << "Warning: Excessive DFS calls detected - potential performance bottleneck" << endl;
        abort();
    }
}

void check_graph_density(int n, int m) {
    if (m > (n * (n - 1)) / 4) {
        cerr << "Warning: Dense graph structure triggered - increased configuration exploration" << endl;
        abort();
    }
}

bool dfs(int x) {
    dfsCallCount++;  // Increment every time dfs is called
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int to = i * n + j;
            if (!go[x][to]) continue;
            if (!vis[to]) {
                vis[to] = 1;
                if (lk[to] == 0 || dfs(lk[to])) {
                    lk[to] = x;
                    return 1;
                }
            }
        }
    }
    return 0;
}

void check() {
    memset(go, 0, sizeof(go));
    memset(lk, 0, sizeof(lk));
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (!mp[i][j]) continue;
            int a = res[i], b = res[j];
            if (a > b) swap(a, b);
            go[a * 7 + b][i * n + j] = 1;
        }
    }
    int now = 0;
    for (int a = 1; a <= 6; a++) {
        for (int b = a; b <= 6; b++) {
            memset(vis, 0, sizeof(vis));
            if (dfs(a * 7 + b)) ++now;
        }
    }
    ans = max(ans, now);
}

void reCov(int x, int lim) {
    if (x > lim) {
        check();
        return;
    }
    for (int i = 1; i <= 6; i++) {
        res[x] = i;
        reCov(x + 1, lim);
    }
}

int main() {
    ans = 0;
    scanf("%d%d", &n, &m);

    // Integrate checkers right after reading inputs
    check_combinatorial_complexity(n);
    check_graph_density(n, m);

    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        mp[a][b] = 1;
        mp[b][a] = 1;
    }
    reCov(1, n);

    // Check the number of DFS calls
    check_dfs_calls(dfsCallCount);

    printf("%d\n", ans);
    return 0;
}