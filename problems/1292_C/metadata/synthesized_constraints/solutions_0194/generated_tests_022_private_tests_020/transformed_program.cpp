#include <bits/stdc++.h>
using namespace std;

vector<int> adj[3005];
int subTreeSz[3005][3005];
int dist[3005][3005];
long long dp[3005][3005];

// Phase 3: Implemented checkers
void check_dfs_invariant(int n) {
    if (n > 2500) { // Arbitrary threshold, close to upper constraint
        cerr << "Warning: DFS invariant triggered - high number of nodes leading to deep recursion" << endl;
        abort();
    }
}

void check_dp_invariant(int n) {
    if (n * (n - 1) > 4000000) { // Arbitrary large product suggesting many state explorations
        cerr << "Warning: DP invariant triggered - excessive state exploration" << endl;
        abort();
    }
}

void check_tree_density(int branchingFactor) {
    if (branchingFactor > 50) { // Arbitrary threshold suggesting high density
        cerr << "Warning: Tree density invariant triggered - high branching factor" << endl;
        abort();
    }
}

void dfs(int anc, int node, int par) {
    subTreeSz[anc][node] = 1;
    int branchingFactor = adj[node].size();
    check_tree_density(branchingFactor); // Phase 4: Insert check for tree density

    for (int i = 0; i < adj[node].size(); ++i) {
        int ch = adj[node][i];
        if (ch == par) {
            continue;
        }
        dist[anc][ch] = dist[anc][node] + 1;
        dfs(anc, ch, node);
        subTreeSz[anc][node] += subTreeSz[anc][ch];
    }
}

long long solveDp(int a, int b) {
    long long &ret = dp[a][b];
    if (ret != -1) {
        return ret;
    }
    ret = 0;
    for (int i = 0; i < adj[a].size(); ++i) {
        int node = adj[a][i];
        if (dist[node][b] == dist[a][b] + 1) {
            long long tmp = (long long)subTreeSz[node][b] * subTreeSz[b][node];
            ret = max(ret, tmp + solveDp(node, b));
        }
    }
    for (int i = 0; i < adj[b].size(); ++i) {
        int node = adj[b][i];
        if (dist[a][node] == dist[a][b] + 1) {
            long long tmp = (long long)subTreeSz[a][node] * subTreeSz[node][a];
            ret = max(ret, tmp + solveDp(a, node));
        }
    }
    return ret;
}

void solve() {
    int n;
    scanf("%d", &n);

    // Phase 4: Insert check for DFS invariant
    check_dfs_invariant(n);

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        dfs(i, i, 0);
    }

    memset(dp, -1, sizeof(dp));
    long long ret = 0;

    // Phase 4: Insert check for DP invariant
    check_dp_invariant(n);

    for (int i = 1; i <= n; ++i) {
        ret = max(ret, solveDp(i, i));
    }

    printf("%lld\n", ret);
}

int main() {
    solve();
    return 0;
}