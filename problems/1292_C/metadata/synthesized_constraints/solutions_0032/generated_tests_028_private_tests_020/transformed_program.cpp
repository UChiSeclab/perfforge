#include <bits/stdc++.h>
using namespace std;
const int N = 3001;
int n, p[N][N], sz[N][N];
long long dp[N][N];
vector<int> v[N];
vector<pair<int, pair<int, int>>> all;

// Check for deep recursion or high branching factor in DFS
void check_dfs_invariant(int depth, int branchingFactor) {
    if (depth > 50 && branchingFactor > 10) {
        cerr << "Warning: dfs_invariant triggered - high recursion depth or branching factor" << endl;
        abort();
    }
}

// Check for large subtree sizes which may slow down size calculations
void check_subtree_size_invariant(int subtreeSize) {
    if (subtreeSize > 1000) {  // Arbitrary threshold based on problem constraints
        cerr << "Warning: subtree_size_invariant triggered - large subtree size calculations" << endl;
        abort();
    }
}

// Check for large number of path combinations to sort
void check_path_sort_invariant(int pathCount) {
    if (pathCount > 10000) {  // Arbitrary threshold based on possible path combinations
        cerr << "Warning: path_sort_invariant triggered - large number of paths to sort" << endl;
        abort();
    }
}

// Check for frequent dynamic programming table accesses
void check_dp_access_invariant(int dpAccessCount, int n) {
    if (dpAccessCount > n * n) {  // Threshold based on potential high access frequency
        cerr << "Warning: dp_access_invariant triggered - frequent DP table accesses" << endl;
        abort();
    }
}

void dfs(int node, int pnode, int dep, int root) {
    p[root][node] = pnode;
    sz[root][node] = 1;
    if (dep) all.push_back({dep, {root, node}});
    for (auto &i : v[node]) {
        if (i == pnode) continue;
        dfs(i, node, dep + 1, root);
        sz[root][node] += sz[root][i];
    }
    // Check subtree size invariant for current node
    check_subtree_size_invariant(sz[root][node]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        dfs(i, 0, 0, i);
        // Check DFS invariant for each root
        check_dfs_invariant(sz[i][i], v[i].size());
    }
    sort(all.begin(), all.end());
    // Check path sorting invariant after sorting
    check_path_sort_invariant(all.size());

    long long ans = 0;
    int dpAccessCount = 0;
    for (auto &i : all) {
        int x = i.second.first;
        int y = i.second.second;
        dp[x][y] = sz[x][y] * sz[y][x] + max(dp[p[y][x]][y], dp[p[x][y]][x]);
        ans = max(ans, dp[x][y]);
        dpAccessCount++;
    }
    // Check DP access invariant
    check_dp_access_invariant(dpAccessCount, n);

    cout << ans << endl;
}