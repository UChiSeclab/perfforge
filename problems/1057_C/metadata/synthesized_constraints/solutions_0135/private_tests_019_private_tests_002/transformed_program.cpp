#include <bits/stdc++.h>
using namespace std;

int read() {
    char ch = getchar();
    int x = 0, f = 1;
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

const int N = 55;
struct edge {
    int from, val;
};
vector<edge> G[N];
int r[N];
char c[N];
bool vis[N][2505];
int f[N][2505];
int n, s, k;
int ans = 2e9;

int ABS(int x) {
    if (x > 0) return x;
    return -x;
}

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 2500; j++) {
            f[i][j] = 2e9;
        }
        f[i][r[i]] = ABS(i - s);
    }
    f[s][0] = 0;
}

// Checker functions for invariants
void check_dfs_invariant(int recursionDepth, int branchingFactor) {
    if (recursionDepth > 50 && branchingFactor > 10) {
        cerr << "Warning: dfs_invariant triggered - high recursion depth or branching factor" << endl;
        abort();
    }
}

void check_memoization_invariant(int valUsage, int n) {
    if (valUsage > n * 10) {
        cerr << "Warning: memoization_invariant triggered - excessive memoization usage" << endl;
        abort();
    }
}

void check_backtracking_invariant(int stateReevaluations) {
    if (stateReevaluations > 1000) {
        cerr << "Warning: backtracking_invariant triggered - too many state reevaluations" << endl;
        abort();
    }
}

int dfs(int x, int y, int depth) {
    // Check for excessive depth and branching during recursion
    check_dfs_invariant(depth, G[x].size());

    if (y >= k) ans = min(ans, f[x][y]);
    if (f[x][y] != 2e9 || vis[x][y]) {
        vis[x][y] = true;
        return f[x][y];
    }

    int stateReevaluations = 0;

    for (int i = 0; i < int(G[x].size()); i++) {
        int from = G[x][i].from;
        if (y - r[x] < 0) continue;
        f[x][y] = min(f[x][y], dfs(from, y - r[x], depth + 1) + G[x][i].val);
        stateReevaluations++;
    }

    // Check for excessive state reevaluations
    check_backtracking_invariant(stateReevaluations);

    if (y >= k) ans = min(ans, f[x][y]);
    vis[x][y] = true;
    return f[x][y];
}

int main() {
    n = read(), s = read(), k = read();
    for (int i = 1; i <= n; i++) r[i] = read();
    init();
    scanf("%s", c + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (c[i] == c[j] || r[i] >= r[j]) continue;
            G[j].push_back((edge){i, ABS(i - j)});
        }
    }

    int valUsage = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = k; j <= 2500; j++) {
            valUsage++;
            dfs(i, j, 0);
        }
    }

    // Check for excessive memoization usage
    check_memoization_invariant(valUsage, n);

    printf("%d\n", ans == 2e9 ? -1 : ans);
    return 0;
}