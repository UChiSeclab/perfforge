#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const long long MAXN = 1e4 + 200;
long long n, ans;
vector<long long> adj[MAXN];
bool mark[MAXN];

// Check if a node has a high degree, indicating potential slowdowns due to high branching factor
void check_high_branching_factor(int degree, int threshold) {
    if (degree > threshold) {
        cerr << "Warning: High branching factor detected at a node!" << endl;
        abort();
    }
}

// Check if a node is part of a densely connected region, which can cause repeated traversals
void check_dense_connectivity(int degree, int n) {
    if (degree > n / 2) {  // Arbitrary threshold, could be adjusted
        cerr << "Warning: Dense connectivity detected at a node!" << endl;
        abort();
    }
}

// Function to detect if the tree structure suggests repeated exploration of sub-paths
void check_repeated_subpaths(int degree) {
    if (degree > 5) {  // Arbitrary threshold for repeated sub-paths
        cerr << "Warning: Potential for repeated sub-paths detected!" << endl;
        abort();
    }
}

void dfs(long long x, long long cnt) {
    if (cnt == 2) {
        ans++;
        return;
    }
    mark[x] = 1;
    for (int i = 0; i < (long long)adj[x].size(); i++) {
        if (mark[adj[x][i]] == 0) {
            dfs(adj[x][i], cnt + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (long long i = 0; i < n - 1; i++) {
        long long x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // Check for high branching factor and dense connectivity
    for (long long i = 1; i <= n; i++) {
        int degree = adj[i].size();
        check_high_branching_factor(degree, 10);  // Example threshold
        check_dense_connectivity(degree, n);
        check_repeated_subpaths(degree);
    }

    for (long long i = 1; i <= n; i++) {
        dfs(i, 0);
        fill(mark, mark + MAXN, 0);
    }
    cout << ans / 2 << endl;
}