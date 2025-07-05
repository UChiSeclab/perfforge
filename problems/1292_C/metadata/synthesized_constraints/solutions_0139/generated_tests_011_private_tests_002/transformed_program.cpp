#include <bits/stdc++.h>
using namespace std;

long long dp[(3000 + 4)][(3000 + 4)], size[(3000 + 4)],
    contri[(3000 + 4)][(3000 + 4)], n;
long long head[(3000 + 4)], tot;

struct edge {
    long long node, next;
} h[(3000 + 4) << 1];

void check_dfs_depth_invariant(int depth, int max_depth) {
    if (depth > max_depth) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive DFS recursion depth!" << endl;
        abort();
    }
}

void check_dense_connectivity_invariant(int degree, int max_degree) {
    if (degree > max_degree) {
        cerr << "Warning: Performance bottleneck condition triggered - node with high connectivity degree!" << endl;
        abort();
    }
}

void check_path_calculation_invariant(int pairwise_paths, int threshold) {
    if (pairwise_paths > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive pairwise path calculations!" << endl;
        abort();
    }
}

void check_queue_operations_invariant(int queue_size, int max_queue_size) {
    if (queue_size > max_queue_size) {
        cerr << "Warning: Performance bottleneck condition triggered - large queue operations!" << endl;
        abort();
    }
}

void addedge(long long u, long long v) {
    h[++tot].next = head[u];
    head[u] = tot;
    h[tot].node = v;
}

void dfs(long long x, long long f, int depth = 0) {
    size[x] = 1;
    check_dfs_depth_invariant(depth, 100);  // Check for excessive recursion depth
    for (long long i = head[x], d; i; i = h[i].next) {
        if ((d = h[i].node) == f) continue;
        dfs(d, x, depth + 1), size[x] += size[d];
    }
}

void dfs2(long long x, long long f, long long root, long long w) {
    contri[root][x] = w * size[x];
    for (long long i = head[x], d; i; i = h[i].next) {
        if ((d = h[i].node) == f) continue;
        dfs2(d, x, root, w);
    }
}

void GetAns() {
    long long Ans = 0;
    queue<long long> U, V;
    check_queue_operations_invariant(U.size(), 5000);  // Check for large queue operations
    for (long long i = 1; i <= n; ++i) {
        dp[i][i] = -1e18;
        for (long long j = head[i]; j; j = h[j].next) {
            check_dense_connectivity_invariant(1, 50);  // Check for high connectivity degree
            U.push(i), V.push(h[j].node);
            dp[i][h[j].node] = contri[i][h[j].node];
        }
    }
    int path_count = 0;
    while (!U.empty()) {
        long long u = U.front(), v = V.front();
        U.pop(), V.pop(), (Ans = max(Ans, dp[u][v]));
        path_count++;
        check_path_calculation_invariant(path_count, 10000);  // Check for excessive path calculations
        for (long long i = head[u], d; i; i = h[i].next) {
            if (!dp[d = h[i].node][v]) U.push(d), V.push(v);
            if (d == v) continue;
            (dp[d][v] = max(dp[d][v], dp[u][v] + contri[d][v]));
        }
        for (long long i = head[v], d; i; i = h[i].next) {
            if (!dp[u][d = h[i].node]) U.push(u), V.push(d);
            if (d == u) continue;
            (dp[u][d] = max(dp[u][d], dp[u][v] + contri[u][d]));
        }
    }
    cout << Ans << endl;
}

signed main() {
    cin >> n;
    for (long long i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        addedge(u, v);
        addedge(v, u);
    }
    for (long long i = 1; i <= n; ++i) {
        dfs(i, 0);
        for (long long j = head[i]; j; j = h[j].next) {
            dfs2(h[j].node, i, i, n - size[h[j].node]);
        }
    }
    GetAns();
    return 0;
}